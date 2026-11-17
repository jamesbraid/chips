# Readings: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`

One entry per routine, filed here from the reading batches by binary.

- `start` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15d0 (544 bytes). Grade: inferred.
  Role (from name): an early entry of the kernel object. It performs one doubleword load (the address is not resolved in the facts), calls `mapped_kernel_setup_tlb` (0x1618), then makes a tail call through a relocated target at `.text+5696` (0x1638). The facts do not describe the bytes after 0x1640.
  Reviewed: 2026-11-12

- `start` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15d0
  **Inferred.** Role (from facts): loads a doubleword from the fixed address 0x9200000001600000 [@0x1600], then calls mapped_kernel_setup_tlb with the caller's a2 and a3 [call 1]. It then jumps through a relocated target [@0x1638].
  Reviewed: 2026-11-12

- `numalinkstats_up2date` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f7c
  **Inferred.** Role (from name): checks whether the NUMA link statistics are current. It branches at 0x1f90 on `numnodes` being at most zero and loops back at 0x1ffc. It loads a doubleword from the fixed address 0xffffffffffffc400 (0x1f98), dereferences that value (0x1fa0), and loads five more doublewords through computed addresses (0x1fb4, 0x1fb8, 0x1fc4, 0x1fd0 and 0x1fe4). The return value at 0x2018 is not derived. The role rests on the name and these loads alone.
  Reviewed: 2026-11-12

- `numalinkstats_up2date` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f7c
  **Inferred.** When the global `numnodes` is zero or less, the branch at 0x1f90 goes to 0x2004, which skips the loop. Otherwise it loops, doubleword loads whose addresses these facts do not show feed zero tests at 0x1fbc and 0x1fc8 and an unsigned comparison at 0x1fd8, and the loop repeats at 0x1ffc while a counter is below `numnodes`. The routine name suggests a freshness check on per-node statistics, but the return value is unknown in these facts.
  Reviewed: 2026-11-12

- `router_reg_read` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21c4
  **Inferred.** Reads one router register. It takes a halfword at offset 0x2 and a doubleword at 0x18 and a word at 0x20 of the router handle in `a0`, and calls `hub_vector_read` at 0x21e0 with them as arguments. It returns the result of that call.
  Reviewed: 2026-11-12

- `router_reg_write` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21f4
  **Inferred.** Writes one router register, the mirror of `router_reg_read`. It takes the same halfword at offset 0x2, doubleword at 0x18 and word at 0x20 from the router handle in `a0`, and calls `hub_vector_write` at 0x2210 with them. It returns the result of that call.
  Reviewed: 2026-11-12

- `router_nic_access` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2224 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2224-0x22d4 (176 bytes).
  It occupies 176 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x0, including `ld` at 0x2254, `ld` at 0x2278, `ld` at 0x229c.
  The `sd` at 0x2268 stores 8 bytes to a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x228c, `ld` at 0x22c0.
  The `jal` at 0x2240 calls nic_get_phase_bits with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2264 calls router_reg_write with a0=[a0]:8, a1=0x38, a2=(ret(nic_get_phase_bits) | ((a1 << 0xa) | (a2 << 0x2))), a3=(a2 << 0x2).
  The `jal` at 0x227c calls router_reg_read with a0=[a0]:8, a1=0x38, a2=a0+8, a3=?.
  The `jal` at 0x22a4 calls router_reg_read with a0=[a0]:8, a1=0x38, a2=a0+8, a3=?.
  The `jal` at 0x22b4 calls us_delay with a0=a3 at entry (arg3), a1=?, a2=?, a3=?.
  The `bltz` branch at 0x2284 targets 0x22b4, is taken when v0(=ret(router_reg_read)) < 0 (signed), and falls through when v0(=ret(router_reg_read)) >= 0 (signed).
  The `bne` branch at 0x2294 targets 0x22b4, is taken when (a4(=[a0+8]:8) & 0x2) != 0, and falls through when (a4(=[a0+8]:8) & 0x2) == 0.
  The `bgez` branch at 0x22ac targets 0x228c, is taken when v0(=ret(router_reg_read)) >= 0 (signed), and falls through when v0(=ret(router_reg_read)) < 0 (signed).
  The return at 0x22cc has v0 = ?.

- `router_set_leds` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x22d4-0x2328 (84 bytes).
  It occupies 84 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7, including `lbu` at 0x22d4, `lbu` at 0x22f8.
  The `lbu` at 0x22d8 loads 1 byte from a0 (arg0 at entry) +0x6.
  The `ld` at 0x22fc loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `sb` at 0x2310 stores 1 byte to a0 (arg0 at entry) +0x6.
  The `jal` at 0x2314 calls router_reg_write with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `bne` branch at 0x22e0 targets 0x22f8, is taken when at(=[a0+6]:1) != v0(=[a0+7]:1), and falls through when at(=[a0+6]:1) == v0(=[a0+7]:1).
  The `beq` branch at 0x2320 targets 0x22ec and is always taken.
  The return at 0x22f0 has v0 = one of 0x0, ret(router_reg_write).

- `router_decode_port_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2328 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2328-0x2394 (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0x2328 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x232c loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `sw` at 0x2344 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `lw` at 0x234c loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x2354 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sw` at 0x2364 stores 4 bytes to a0 (arg0 at entry) +0x14.
  The `sw` at 0x2374 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `lw` at 0x2378 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `sw` at 0x2380 stores 4 bytes to a0 (arg0 at entry) +0x1c.
  The `beq` branch at 0x2358 targets 0x238c, is taken when t0(=0xff) == a5(?), and falls through when t0(=0xff) != a5(?).
  The `beq` branch at 0x2370 targets 0x2384, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x238c targets 0x2360 and is always taken.
  The return at 0x2384 has v0 = ?.

- `router_acquire_port_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2394 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2394-0x2584 (496 bytes).
  It occupies 496 bytes.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x23cc, `lw` at 0x24a0.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7, including `lbu` at 0x23dc, `lbu` at 0x2560.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7, including `sb` at 0x23ec, `sb` at 0x24c0, `sb` at 0x2570.
  The `lbu` at 0x240c loads 1 byte from a0 (arg0 at entry) +0x180.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2424, `ld` at 0x24cc.
  5 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2448, `sh` at 0x24d8, `sh` at 0x2524.
  The `lbu` at 0x24a4 loads 1 byte from a0 (arg0 at entry) +0x6.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2540, `lhu` at 0x2550.
  The `jal` at 0x246c calls router_reg_read with a0=a0 at entry (arg0), a1=((a1 << 0x10) | 0x10), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x2480 calls router_reg_read with a0=a0 at entry (arg0), a1=((a1 << 0x10) | 0x88), a2=?, a3=?.
  The `jal` at 0x2488 calls mutex_spinlock with a0=a0+404, a1=?, a2=?, a3=?.
  The `jal` at 0x2494 calls router_decode_port_errors with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x24bc calls mutex_spinunlock with a0=a0+404, a1=?, a2=?, a3=?, a5=[a0+7]:1.
  The `jal` at 0x2574 calls mutex_spinunlock with a0=a0+404, a1=?, a2=?, a3=?.
  The `beq` branch at 0x23c4 targets 0x245c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x23d4 targets 0x240c, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x23e0 targets 0x24a4, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x2414 targets 0x24cc, is taken when v0(=0x1) == ra(=[a0+384]:1), and falls through when v0(=0x1) != ra(=[a0+384]:1).
  The `bne` branch at 0x2444 targets 0x2420, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0x244c targets 0x2574, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x2454 targets 0x23f0 and is always taken.
  The `beq` branch at 0x249c targets 0x23d0 and is always taken.
  The `beq` branch at 0x24c4 targets 0x23f0 and is always taken.
  The `beq` branch at 0x24d4 targets 0x2540, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2548 targets 0x2560, is taken when t2(?) >= 0x14 (signed), and falls through when t2(?) < 0x14 (signed).
  The `bne` branch at 0x2558 targets 0x244c, is taken when t3(?) < 0x14 (signed), and falls through when t3(?) >= 0x14 (signed).
  The `beq` branch at 0x256c targets 0x244c and is always taken.
  The `beq` branch at 0x257c targets 0x2454 and is always taken.
  The return at 0x2404 has v0 = one of 0x0, 0x1.

- `router_acquire_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2584
  **Inferred.** Role (from name): gathers information for one router. It calls `mutex_spinlock` on the lock at offset 0x194 (call at 0x25a8) and `mutex_spinunlock` at 0x2604 and 0x2698. Between the unlock at 0x2604 and a second `mutex_spinlock` at 0x2620 it calls `router_acquire_port_info` at 0x2614, so that call is made without the lock. It reads flag bytes at offsets 0x7, 0x8 and 0x191 and a doubleword at 0x160, and stores to 0x7, 0x160 and 0x30. It calls `router_set_leds` at 0x264c, and `router_reg_write` at 0x2704 and 0x271c with register offset 0x18.
  Reviewed: 2026-11-12

- `router_print_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2774 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2774-0x284c (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0x2774 loads 8 bytes from a0 (arg0 at entry) +0x178.
  The `lbu` at 0x27d8 loads 1 byte from (a4 + a0) +0x1af.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1a8, including `ld` at 0x2804, `ld` at 0x2838.
  The `sb` at 0x2818 stores 1 byte to (a4 + a0) +0x1af.
  The `jal` at 0x27e8 calls error_flag_to_type [0x272c] with a0=a3 at entry (arg3), a1=a1 at entry (arg1), a2=(a3 | [(a4 + a0)+431]:1), a3=a3 at entry (arg3), a4=(a4 + a0).
  The `jal` at 0x2808 calls cmn_err with a0=0x4, a1=sym(.rodata)+432, a2=ret(error_flag_to_type), a3=?, a4=[a0+424]:8, a5=a4 at entry (arg4).
  The `jal` at 0x281c calls error_flag_to_type [0x272c] with a0=a3 at entry (arg3), a1=a1 at entry (arg1), a2=(a3 | [(a4 + a0)+431]:1), a3=a3 at entry (arg3), a4=(a4 + a0).
  The `jal` at 0x283c calls cmn_err with a0=0x404, a1=sym(.rodata)+432, a2=ret(error_flag_to_type), a3=?, a4=[a0+424]:8, a5=a4 at entry (arg4).
  The `beq` branch at 0x27b0 targets 0x27d4, is taken when s2(?) >= 0x1f5 (signed), and falls through when s2(?) < 0x1f5 (signed).
  The `beq` branch at 0x27e0 targets 0x2818, is taken when (a3 & v0(=[(a4 + a0)+431]:1)) == 0, and falls through when (a3 & v0(=[(a4 + a0)+431]:1)) != 0.
  The `beq` branch at 0x2810 targets 0x2844 and is always taken.
  The `beq` branch at 0x2844 targets 0x27bc and is always taken.
  The return at 0x27cc has v0 = one of 0x0, 0x1.

- `router_check_port` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x284c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x284c-0x2898 (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x2858 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0x2864 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x2880 loads 4 bytes from ?.
  The `sw` at 0x2888 stores 4 bytes to ?.
  The `jal` at 0x287c calls router_print_error [0x2774] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x4, a4=a1 at entry (arg1), a5=[a0+40]:8.
  The return at 0x2890 has v0 = ret(router_print_error).

- `router_check_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2898 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2898-0x28f0 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x28bc calls router_check_port with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x28cc targets 0x28b8, is taken when s0(?) < 0x7 (signed), and falls through when s0(?) >= 0x7 (signed).
  The return at 0x28e8 has v0 = ?.

- `router_port_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28f0-0x29b4 (196 bytes).
  It occupies 196 bytes.
  The `lh` at 0x294c loads 2 bytes from a0 (arg0 at entry) +0x158.
  The `jal` at 0x2910 calls router_reg_read with a0=a0 at entry (arg0), a1=(a1 << 0x10), a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x2970 calls router_reg_write with a0=a0 at entry (arg0), a1=(a1 << 0x10), a2=?, a3=0x40000, a4=a1 at entry (arg1).
  The `jal` at 0x2984 calls router_reg_write with a0=a0 at entry (arg0), a1=((a1 << 0x10) | 0x10), a2=0x0, a3=?.
  The `jal` at 0x2994 calls router_reg_read with a0=a0 at entry (arg0), a1=((a1 << 0x10) | 0x88), a2=sp-48, a3=?.
  The `beq` branch at 0x293c targets 0x296c, is taken when v1(=[sym(hasmetarouter)]) == 0, and falls through when v1(=[sym(hasmetarouter)]) != 0.
  The `bne` branch at 0x2944 targets 0x2970, is taken when a4(=a1) != v0(=0x2), and falls through when a4(=a1) == v0(=0x2).
  The `beq` branch at 0x2958 targets 0x296c, is taken when a5(=[a0+344]:2) >= 0x50 (signed), and falls through when a5(=[a0+344]:2) < 0x50 (signed).
  The return at 0x29ac has v0 = ?.

- `router_port_hist_reselect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x29b4-0x2a94 (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x29b4 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x29b8 loads 2 bytes from a0 (arg0 at entry) +0x2.
  The `ld` at 0x29bc loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x29cc loads 8 bytes from ([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3)) +0x0.
  The `lh` at 0x29d4 loads 2 bytes from [([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8 +0x4956.
  The `jal` at 0x29f8 calls setnoderun with a0=[a0+2]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[a0+2]:2.
  The `jal` at 0x2a28 calls router_reg_read with a0=a0 at entry (arg0), a1=(a1 << 0x10), a2=sp-64, a3=?.
  The `jal` at 0x2a54 calls router_reg_write with a0=a0 at entry (arg0), a1=(a1 << 0x10), a2=?, a3=(a2 << 0x12).
  The `jal` at 0x2a68 calls router_reg_write with a0=a0 at entry (arg0), a1=((a1 << 0x10) | 0x10), a2=0x0, a3=?.
  The `jal` at 0x2a78 calls restorenoderun with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x29ec targets 0x2a88, is taken when at(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+18774]:2) == v1(=-0x1), and falls through when at(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+18774]:2) != v1(=-0x1).
  The return at 0x2a8c has v0 = one of 0x16, ?.

- `router_hist_reselect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2a94-0x2b9c (264 bytes).
  It occupies 264 bytes.
  The `lbu` at 0x2a98 loads 1 byte from a0 (arg0 at entry) +0x180.
  The `sb` at 0x2aec stores 1 byte to a0 (arg0 at entry) +0x180.
  The `ld` at 0x2af0 loads 8 bytes from abs 0xffffffffffffc400.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x2, including `lh` at 0x2af4, `lh` at 0x2b88.
  The `ld` at 0x2af8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x2b04 loads 8 bytes from ([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3)) +0x0.
  The `lh` at 0x2b08 loads 2 bytes from [([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8 +0x4956.
  The `ld` at 0x2b7c loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `jal` at 0x2acc calls router_port_hist_reselect with a0=a0 at entry (arg0), a1=?, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x2b18 calls setnoderun with a0=[a0+2]:2, a1=-0x1, a2=?, a3=?.
  The `jal` at 0x2b38 calls router_acquire_info with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2b40 calls restorenoderun with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2b68 calls net_errmsg with a0=ret(router_port_hist_reselect), a1=?, a2=?, a3=?.
  The `jal` at 0x2b8c calls cmn_err with a0=0x4, a1=sym(.rodata)+432, a2=[a0+2]:2, a3=[a0+424]:8, a5=ret(router_port_hist_reselect), a6=ret(net_errmsg).
  The `beq` branch at 0x2ab4 targets 0x2b54, is taken when a1 == at(=[a0+384]:1), and falls through when a1 != at(=[a0+384]:1).
  The `bne` branch at 0x2ad4 targets 0x2b68, is taken when v0(=ret(router_port_hist_reselect)) != 0, and falls through when v0(=ret(router_port_hist_reselect)) == 0.
  The `bne` branch at 0x2ae4 targets 0x2ac8, is taken when s0(?) < 0x7 (signed), and falls through when s0(?) >= 0x7 (signed).
  The `beq` branch at 0x2b10 targets 0x2b4c, is taken when v1(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+18774]:2) == a1(=-0x1), and falls through when v1(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+18774]:2) != a1(=-0x1).
  The `beq` branch at 0x2b94 targets 0x2ae0 and is always taken.
  The return at 0x2b60 has v0 = 0x0.

- `router_set_fences` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2b9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2b9c-0x2cb0 (276 bytes).
  It occupies 276 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x8, including `lbu` at 0x2bf4, `lbu` at 0x2c30.
  The `sd` at 0x2c80 stores 8 bytes to a0 (arg0 at entry) +0x170.
  The `jal` at 0x2bbc calls router_reg_read with a0=a0 at entry (arg0), a1=0x10, a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x2c1c calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-56, a3=?.
  The `jal` at 0x2c54 calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2c88 calls router_reg_write with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `beq` branch at 0x2bd0 targets 0x2bf4 and is always taken.
  The `beq` branch at 0x2bec targets 0x2c78, is taken when s3(?) >= 0x7 (signed), and falls through when s3(?) < 0x7 (signed).
  The `beq` branch at 0x2c04 targets 0x2bd8, is taken when (v1(=[a0+8]:1) & a0(?)) == 0, and falls through when (v1(=[a0+8]:1) & a0(?)) != 0.
  The `beq` branch at 0x2c40 targets 0x2c64, is taken when (t8(=[a0+8]:1) & t9(?)) == 0, and falls through when (t8(=[a0+8]:1) & t9(?)) != 0.
  The `bne` branch at 0x2c48 targets 0x2c30, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x2c5c targets 0x2be8 and is always taken.
  The `beq` branch at 0x2c70 targets 0x2c48 and is always taken.
  The return at 0x2ca8 has v0 = ret(router_reg_write).

- `capture_router_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cb0
  **Inferred.** Role (from name): records one sample of router statistics. It calls `router_acquire_info` at 0x2cc0 first, then reads and updates the byte fields at offsets 0x190 and 0x191 and the doubleword at 0x188 (store at 0x2d08, load at 0x2d14). On the path where the byte at 0x190 is nonzero it calls `router_check_errors`, shown at address 0x2898 (call at 0x2cec). The return value is either the global `router_poll_ticks` or not derived. The sample's destination is not settled by the facts.
  Reviewed: 2026-11-12

- `capture_router_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cb0
  **Inferred.** Role (from name): a router statistics sampler. It calls `router_acquire_info` at 0x2cc0 and reads the byte flag at `a0+0x191`. A zero there goes to 0x2d64, which continues at 0x2cdc only if `router_acquire_info` returned nonzero. At 0x2cdc it stores the byte at `a0+0x191`, and it calls `router_check_errors` at 0x2cec only when the byte flag at `a0+0x190` is nonzero. It stores bytes at `a0+0x190` (0x2d00, 0x2d30) and a doubleword at `a0+0x188` (0x2d08), and compares against the global `router_print_usecs` at 0x2d28. The return value is the value of the global `router_poll_ticks` or is unknown.
  Reviewed: 2026-11-12

- `router_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f04
  **Inferred.** Role (from name): builds one router record. It allocates a 0x1b8-byte record with `kmem_zalloc_node` at 0x2f40, initializes its lock at 0x2f74 and registers its info at 0x2f60. It calls `router_reg_read` at 0x2ff0 and 0x3008 and `router_reg_write` at 0x3078, then `router_port_init` at 0x31d0, `router_set_fences` at 0x3200 and `build_router_invent_info` at 0x3234. A separate path calls `kmem_free` on the record at 0x3334. `assfail` at 0x334c and 0x3364 is passed line numbers 0x46b and 0x470. That this runs at boot is not derived.
  Reviewed: 2026-11-12

- `router_get_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x33b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x33b0-0x3434 (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0x33dc calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+432, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x33e8 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x340c calls bcopy with a0=?, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x1b8.
  The `jal` at 0x341c calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x33c4 targets 0x33d4, is taken when a0 != at(=-0x1), and falls through when a0 == at(=-0x1).
  The `beq` branch at 0x33cc targets 0x342c and is always taken.
  The return at 0x342c has v0 = one of 0x0, 0x13.

- `router_state_empty` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x34bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x34bc-0x35dc (288 bytes).
  It occupies 288 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x8, including `lbu` at 0x3510, `lbu` at 0x355c.
  The `jal` at 0x34ec calls router_reg_read with a0=a0 at entry (arg0), a1=0x0, a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x3590 calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-64, a3=[a0+8]:1.
  The `beq` branch at 0x3534 targets 0x3540, is taken when (a3(=[a0+8]:1) & at(?)) == 0, and falls through when (a3(=[a0+8]:1) & at(?)) != 0.
  The `bne` branch at 0x3540 targets 0x351c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x3558 targets 0x356c and is always taken.
  The `beq` branch at 0x3564 targets 0x35b4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3578 targets 0x3560, is taken when (a3(=[a0+8]:1) & t8(?)) == 0, and falls through when (a3(=[a0+8]:1) & t8(?)) != 0.
  The `bne` branch at 0x35ac targets 0x3558, is taken when s1(?) < 0x7 (signed), and falls through when s1(?) >= 0x7 (signed).
  The return at 0x35d4 has v0 = one of 0x0, 0x1.

- `router_print_state_specific` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x35dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x35dc-0x37b8 (476 bytes).
  It occupies 476 bytes.
  The `lbu` at 0x3614 loads 1 byte from a0 (arg0 at entry) +0x190.
  The `sb` at 0x3654 stores 1 byte to a0 (arg0 at entry) +0x190.
  The `ld` at 0x3660 loads 8 bytes from abs 0xffffffffffffc400.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x2, including `lh` at 0x3664, `lh` at 0x36a0.
  The `ld` at 0x3668 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x3674 loads 8 bytes from ([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3)) +0x0.
  The `lbu` at 0x3678 loads 1 byte from [([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8 +0x4954.
  The `lh` at 0x36c8 loads 2 bytes from (sym(compact_to_nasid_node) + ([a0+2]:2 + [a0+2]:2)) +0x0.
  The `sb` at 0x36cc stores 1 byte to [([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8 +0x4954.
  The `lbu` at 0x36f4 loads 1 byte from a0 (arg0 at entry) +0x15a.
  The `lh` at 0x3700 loads 2 bytes from a0 (arg0 at entry) +0x158.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x8, including `lbu` at 0x3724, `lbu` at 0x3740.
  The `jal` at 0x360c calls mutex_spinlock with a0=a0+404, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3628 calls mutex_spinunlock with a0=a0+404, a1=ret(mutex_spinlock), a2=[a0+400]:1, a3=?.
  The `jal` at 0x3658 calls mutex_spinunlock with a0=a0+404, a1=ret(mutex_spinlock), a2=[a0+400]:1, a3=?.
  The `jalr` at 0x3688 calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+432, a2=[a0+2]:2, a3=?.
  The `jal` at 0x3694 calls max with a0=0x100, a1=0x100, a2=?, a3=?.
  The `jal` at 0x36c4 calls timeout_poll with a0=[(sym(compact_to_nasid_node) + ([a0+2]:2 + [a0+2]:2))]:2, a1=0x600300, a2=0x8000000000000000, a3=ret(max), a4=0x1, a5=([a0+2]:2 + [a0+2]:2).
  The `jal` at 0x36d4 calls router_state_empty [0x34bc] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x36e4 calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+432, a2=?, a3=?.
  The `jal` at 0x36f0 calls get_slotname with a0=[a0+346]:1, a1=sp-160, a2=?, a3=?.
  The `jalr` at 0x3704 calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+432, a2=[a0+344]:2, a3=sp-160.
  The `jal` at 0x3714 calls router_reg_read with a0=a0 at entry (arg0), a1=0x0, a2=sp-56, a3=?.
  The `jal` at 0x3728 calls show_rr_status_rev_id with a0=?, a1=[a0+8]:1, a2=a1 at entry (arg1), a3=a2 at entry (arg2).
  The `jal` at 0x3770 calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-56, a3=?.
  The `jal` at 0x3794 calls show_rr_error_status with a0=?, a1=?, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `beq` branch at 0x361c targets 0x3650, is taken when (s3(=a3) & a2(=[a0+400]:1)) == 0, and falls through when (s3(=a3) & a2(=[a0+400]:1)) != 0.
  The `beq` branch at 0x367c targets 0x36d0, is taken when a0(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+18772]:1) == 0, and falls through when a0(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+18772]:1) != 0.
  The `bne` branch at 0x36dc targets 0x3630, is taken when v0(=ret(router_state_empty)) != 0, and falls through when v0(=ret(router_state_empty)) == 0.
  The `beq` branch at 0x373c targets 0x3750 and is always taken.
  The `beq` branch at 0x3748 targets 0x3630, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x375c targets 0x3744, is taken when (a1(=[a0+8]:1) & a6(?)) == 0, and falls through when (a1(=[a0+8]:1) & a6(?)) != 0.
  The `bne` branch at 0x37a8 targets 0x373c, is taken when s3(?) < 0x7 (signed), and falls through when s3(?) >= 0x7 (signed).
  The `beq` branch at 0x37b0 targets 0x3634 and is always taken.
  The return at 0x3648 has v0 = one of ?, ret(show_rr_error_status).

- `router_print_state` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x37b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x37b8-0x3884 (204 bytes).
  It occupies 204 bytes.
  The `ld` at 0x37e0 loads 8 bytes from abs 0xffffffffffffc400.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc422, including `lh` at 0x37e4, `lh` at 0x381c.
  The `ld` at 0x37e8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x37f4 loads 8 bytes from ([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3)) +0x0.
  The `ld` at 0x37f8 loads 8 bytes from [([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8 +0x4978.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3808, `ld` at 0x384c.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x3820, `sh` at 0x3848.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x3824, `lh` at 0x3830.
  The `sw` at 0x383c stores 4 bytes to ?.
  The `jal` at 0x3844 calls router_print_state_specific with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=sym(compact_to_nasid_node).
  The `jal` at 0x3874 calls router_print_state_specific with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x37d8 targets 0x3874, is taken when a0 != 0, and falls through when a0 == 0.
  The `beq` branch at 0x37fc targets 0x3858, is taken when s0(=[[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+18808]:8) == 0, and falls through when s0(=[[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+18808]:8) != 0.
  The `beq` branch at 0x3804 targets 0x3814 and is always taken.
  The `beq` branch at 0x380c targets 0x3858, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3814 targets 0x380c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x3850 targets 0x3804, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x387c targets 0x385c and is always taken.
  The return at 0x386c has v0 = one of ?, ret(router_print_state_specific).

- `router_nic_probe` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3884 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x3884-0x393c (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x38a0 calls nic_get_phase_bits with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x38c8 calls vector_write with a0=a0 at entry (arg0), a1=0x0, a2=0x38, a3=(ret(nic_get_phase_bits) | ((a1 << 0xa) | (a2 << 0x2))), a4=(a2 << 0x2).
  The `jal` at 0x38e0 calls vector_read with a0=a0 at entry (arg0), a1=0x0, a2=0x38, a3=sp-48.
  The `jal` at 0x3908 calls vector_read with a0=a0 at entry (arg0), a1=0x0, a2=0x38, a3=sp-48.
  The `jal` at 0x391c calls us_delay with a0=a3 at entry (arg3), a1=?, a2=?, a3=?.
  The `bltz` branch at 0x38e8 targets 0x3918, is taken when v0(=ret(vector_read)) < 0 (signed), and falls through when v0(=ret(vector_read)) >= 0 (signed).
  The `bne` branch at 0x38f8 targets 0x3918, is taken when (a5(?) & 0x2) != 0, and falls through when (a5(?) & 0x2) == 0.
  The `bgez` branch at 0x3910 targets 0x38f4, is taken when v0(=ret(vector_read)) >= 0 (signed), and falls through when v0(=ret(vector_read)) < 0 (signed).
  The return at 0x3934 has v0 = ?.

- `router_nic_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x393c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x393c-0x3990 (84 bytes).
  It occupies 84 bytes.
  The `sd` at 0x3970 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x3950 calls nic_setup with a0=sp-112, a1=sym(router_nic_probe), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x3974 calls nic_next with a0=sp-112, a1=a1+2, a2=0x0, a3=0x0.
  The `bltz` branch at 0x3958 targets 0x3980, is taken when v0(=ret(nic_setup)) < 0 (signed), and falls through when v0(=ret(nic_setup)) >= 0 (signed).
  The return at 0x3988 has v0 = one of ret(nic_setup), ret(nic_next).

- `hub_vector_read` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x430c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x430c-0x43ec (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x432c loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x433c loads 8 bytes from [-0x3c00]:8 +0x0.
  The `lh` at 0x4344 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `ld` at 0x435c loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x4368 loads 2 bytes from abs 0xffffffffffffc422.
  2 such `sb` accesses store 1 byte to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4954, including `sb` at 0x43a0, `sb` at 0x43c4.
  The `jal` at 0x4358 calls in_panic_mode with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4374 calls in_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x43b4 calls vector_read_node with a0=a1 at entry (arg1), a1=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x43cc calls mutex_spinunlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18768, a1=?, a2=?, a3=?.
  The `jal` at 0x43dc calls mutex_spinlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18768, a1=?, a2=?, a3=?.
  The `beq` branch at 0x4360 targets 0x43dc, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x436c targets 0x439c, is taken when s1(=[-0x3bde]:2) == s3(=a0), and falls through when s1(=[-0x3bde]:2) != s3(=a0).
  The `beq` branch at 0x437c targets 0x43c8, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x43c0 targets 0x4374 and is always taken.
  The `beq` branch at 0x43d4 targets 0x4384 and is always taken.
  The `beq` branch at 0x43e4 targets 0x4368 and is always taken.
  The return at 0x4394 has v0 = ?.

- `hub_vector_write` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x43ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x43ec-0x44cc (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x440c loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x441c loads 8 bytes from [-0x3c00]:8 +0x0.
  The `lh` at 0x4424 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `ld` at 0x443c loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x4448 loads 2 bytes from abs 0xffffffffffffc422.
  2 such `sb` accesses store 1 byte to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4954, including `sb` at 0x4484, `sb` at 0x44a8.
  The `jal` at 0x4438 calls in_panic_mode with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4454 calls in_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4498 calls vector_write_node with a0=a1 at entry (arg1), a1=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x44ac calls mutex_spinunlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18768, a1=?, a2=?, a3=?.
  The `jal` at 0x44bc calls mutex_spinlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18768, a1=?, a2=?, a3=?.
  The `beq` branch at 0x4440 targets 0x44bc, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x444c targets 0x4480, is taken when s1(=[-0x3bde]:2) == s3(=a0), and falls through when s1(=[-0x3bde]:2) != s3(=a0).
  The `beq` branch at 0x445c targets 0x44ac, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x44a4 targets 0x4454 and is always taken.
  The `beq` branch at 0x44b4 targets 0x4468 and is always taken.
  The `beq` branch at 0x44c4 targets 0x4448 and is always taken.
  The return at 0x4478 has v0 = ?.

- `hub_widget_id` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44cc
  **Inferred.** A leaf that loads one doubleword from the address formed by `a0` shifted by 32 plus a fixed offset (load at 0x44d8) and returns its low four bits: the delay slot of the return at 0x44dc is `andi v0,v0,0xf`. What the loaded word holds is not derived, so the widget-id meaning rests on the name.
  Reviewed: 2026-11-12

- `hub_widget_id` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44cc
  **Inferred.** It loads one doubleword at 0x44d8 at the constant offset -0x6dfffffffe3fffe0 from a base register that the facts do not show, then returns at 0x44dc. The return value `v0` is not shown in the facts, so whether it is the loaded value, and how a caller uses it as a widget id, are open.
  Reviewed: 2026-11-12

- `get_nasid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44e4 (28 bytes). Grade: inferred.
  It performs one doubleword load and returns a value in `v0` that the rendering leaves unresolved, so the address read and which bits of that word form a node id are open. Its callers in this file (for example `getcpuid`) pass the result as the first argument of `nasid_slice_to_cpuinfo`, which suggests a node id; that is an inference from the callee name.
  Reviewed: 2026-11-12

- `get_slice` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4500 (16 bytes). Grade: inferred.
  It loads the same word as `get_myid`, from 0x9200000001000020, and returns it as the whole value with no mask. The name suggests a slice field, but the body shows no field extraction. The slice meaning is therefore an inference from the name alone.
  Reviewed: 2026-11-12

- `get_slice` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4500
  **Inferred.** A leaf that loads one doubleword from the fixed global at 0x9200000001000020 (load at 0x4504) and returns it unchanged (return at 0x4508). The slice meaning rests on the name and the single load.
  Reviewed: 2026-11-12

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510 (20 bytes). Grade: inferred.
  It performs one doubleword load and returns a value in `v0` that the rendering leaves unresolved. No compare or branch appears in the facts. Role (from name): a directory-mode predicate; the body shows no test.
  Reviewed: 2026-11-12

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510
  **Inferred.** The routine is 20 bytes with one 8-byte load from the fixed address 0x9200000001600000 at 0x4514 and a return with v0 at 0x451c. The facts show no call and no branch, so the value read is returned in some form. The name suggests a directory-mode predicate, but which bit or field of the word is tested is not shown.
  Reviewed: 2026-11-12

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510
  **Inferred.** It loads one doubleword at 0x4514 and returns at 0x451c. The facts show neither the address loaded nor any comparison, and the return value is unknown. Role (from name): a test of a directory mode, which the facts do not confirm.
  Reviewed: 2026-11-12

- `ni_reset_port` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x45e0 (16 bytes). Grade: inferred.
  It stores a doubleword at offset 0x0 of a base register the facts do not name, and returns the constant 0x9200000001600008 in `v0`. Role (from name): a port reset; the facts show no more than the store and the returned constant.
  Reviewed: 2026-11-12

- `ni_reset_port` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x45e0
  **Inferred.** The routine stores one 8-byte word to 0x9200000001600008 at 0x45ec and returns that same address in v0 at 0x45e8. It is a 16-byte leaf with no calls. The name suggests a port reset, but the stored value is not in the facts, so whether it asserts or clears a reset is unknown.
  Reviewed: 2026-11-12

- `nic_name_convert` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4b7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x4b7c-0x4d60 (484 bytes).
  It occupies 484 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x0, including `lbu` at 0x4b88, `lbu` at 0x4d5c.
  The `lbu` at 0x4ba4 loads 1 byte from a0 (arg0 at entry) +0x1.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x4bd0, `sb` at 0x4c28, `sb` at 0x4c34.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x4bf0, `lbu` at 0x4bf8.
  The `lbu` at 0x4cbc loads 1 byte from sym(.rodata) +0x704.
  The `lw` at 0x4cc0 loads 4 bytes from sym(.rodata) +0x700.
  2 such `swl` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `swl` at 0x4cc4, `swl` at 0x4ce8.
  2 such `swr` accesses store 4 bytes to a1 (arg1 at entry) +0x3, including `swr` at 0x4cc8, `swr` at 0x4cec.
  2 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x4, including `sb` at 0x4cd0, `sb` at 0x4cf8.
  The `lbu` at 0x4cd8 loads 1 byte from sym(.rodata) +0x6f6.
  The `lw` at 0x4cdc loads 4 bytes from sym(.rodata) +0x6f0.
  The `lbu` at 0x4ce0 loads 1 byte from sym(.rodata) +0x6f5.
  The `lbu` at 0x4ce4 loads 1 byte from sym(.rodata) +0x6f4.
  The `sb` at 0x4cf0 stores 1 byte to a1 (arg1 at entry) +0x6.
  The `sb` at 0x4cf4 stores 1 byte to a1 (arg1 at entry) +0x5.
  The `ld` at 0x4d14 loads 8 bytes from sym(.rodata) +0x6e0.
  2 such `sdl` accesses store 8 bytes to a1 (arg1 at entry) +0x0, including `sdl` at 0x4d18, `sdl` at 0x4d34.
  2 such `sdr` accesses store 8 bytes to a1 (arg1 at entry) +0x7, including `sdr` at 0x4d20, `sdr` at 0x4d38.
  The `lw` at 0x4d2c loads 4 bytes from sym(.rodata) +0x6d8.
  The `ld` at 0x4d30 loads 8 bytes from sym(.rodata) +0x6d0.
  The `swl` at 0x4d3c stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `swr` at 0x4d44 stores 4 bytes to a1 (arg1 at entry) +0xb.
  The `jal` at 0x4bb0 calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sym(.rodata)+1688.
  The `jal` at 0x4bd8 calls strlen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4c44 calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1688, a2=0x3, a3=?.
  The `jal` at 0x4c60 calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1688, a2=0x3, a3=?, a4=sym(.rodata)+1688.
  The `jal` at 0x4c7c calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1688, a2=0x8, a3=?, a4=sym(.rodata)+1688.
  The `jal` at 0x4c94 calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1688, a2=0x4, a3=?.
  The `jal` at 0x4cac calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1688, a2=0x4, a3=?.
  The `beq` branch at 0x4b9c targets 0x4d14, is taken when at(=[a0]:1) == 0, and falls through when at(=[a0]:1) != 0.
  The `beq` branch at 0x4ba8 targets 0x4d14, is taken when v0(=[a0+1]:1) == 0, and falls through when v0(=[a0+1]:1) != 0.
  The `beq` branch at 0x4bbc targets 0x4d48, is taken when v0(=ret(strlen)) == 0, and falls through when v0(=ret(strlen)) != 0.
  The `beq` branch at 0x4bc8 targets 0x4d50 and is always taken.
  The `beq` branch at 0x4be8 targets 0x4c2c, is taken when s0(?) >= v0(=ret(strlen)) (unsigned), and falls through when s0(?) < v0(=ret(strlen)) (unsigned).
  The `beq` branch at 0x4c04 targets 0x4c1c, is taken when (a3(?) & 0x4003) == 0, and falls through when (a3(?) & 0x4003) != 0.
  The `bne` branch at 0x4c0c targets 0x4bd0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x4c14 targets 0x4bd0 and is always taken.
  The `beq` branch at 0x4c1c targets 0x4d24, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x4c24 targets 0x4bd4 and is always taken.
  The `beq` branch at 0x4c4c targets 0x4cd8, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `beq` branch at 0x4c68 targets 0x4cd8, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `beq` branch at 0x4c84 targets 0x4cd4, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `beq` branch at 0x4c9c targets 0x4d2c, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `bne` branch at 0x4cb4 targets 0x4cfc, is taken when v0(=ret(strncmp)) != 0, and falls through when v0(=ret(strncmp)) == 0.
  The `beq` branch at 0x4ccc targets 0x4cfc and is always taken.
  The `beq` branch at 0x4d1c targets 0x4c38 and is always taken.
  The `beq` branch at 0x4d24 targets 0x4bd4 and is always taken.
  The `beq` branch at 0x4d40 targets 0x4cfc and is always taken.
  The `beq` branch at 0x4d48 targets 0x4c30 and is always taken.
  The `beq` branch at 0x4d58 targets 0x4bf4 and is always taken.
  The return at 0x4d0c has v0 = ret(strncmp).

- `xbow_port_io_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x53f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x53f4-0x54b8 (196 bytes).
  It occupies 196 bytes.
  The `ld` at 0x540c loads 8 bytes from ((a0 << 0x20)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x541c loads 4 bytes from ?.
  The `lbu` at 0x547c loads 1 byte from (ret(find_component) + (a1 << 0x3)) -0x6.
  The `jal` at 0x5440 calls find_lboard with a0=?, a1=0x41, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x9600000000000000.
  The `jal` at 0x5464 calls find_component with a0=ret(find_lboard), a1=0x0, a2=0x4, a3=?.
  The `beq` branch at 0x5434 targets 0x54a0, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x5448 targets 0x5460, is taken when v0(=ret(find_lboard)) != 0, and falls through when v0(=ret(find_lboard)) == 0.
  The `beq` branch at 0x5470 targets 0x54a8, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `beq` branch at 0x5488 targets 0x54b0, is taken when (a1(=[(ret(find_component) + (a1 << 0x3))-6]:1) & 0x1) == 0, and falls through when (a1(=[(ret(find_component) + (a1 << 0x3))-6]:1) & 0x1) != 0.
  The `beq` branch at 0x5490 targets 0x54b0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x5498 targets 0x5458 and is always taken.
  The `beq` branch at 0x54a0 targets 0x5440 and is always taken.
  The `beq` branch at 0x54a8 targets 0x5454 and is always taken.
  The `beq` branch at 0x54b0 targets 0x5454 and is always taken.
  The return at 0x5458 has v0 = one of 0x0, 0x1.

- `update_ust` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xa520
  **Inferred.** The routine loads an 8-byte value from the fixed address 0x9200000001030100 at 0xa538, stores 8 bytes with sd at 0xa540 and returns the loaded value in v0 at 0xa53c. The facts show no branch or call. The facts do not name or place the store destination, so that it is a kernel variable is not established. The name suggests a time update, but the meaning of the source word is not shown.
  Reviewed: 2026-11-12

- `update_ust` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xa520
  **Inferred.** It loads the doubleword at 0x9200000001030100 at 0xa538 and returns that value at 0xa53c. It also stores a doubleword at offset +0x0 at 0xa540; the facts do not show the destination or the stored value. The name suggests a timestamp update, which the facts do not confirm.
  Reviewed: 2026-11-12

- `xswitch_vertex_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xaf44
  **Inferred.** The routine allocates a 0x20-byte zeroed block with kmem_zalloc at 0xaf58, initialises a mutex inside it with init_mutex at 0xaf74, and registers the block under a label with hwgraph_info_add_LBL at 0xaf84, returning that call's result at 0xaf94. The label string is at .rodata+4400. The name suggests a switch vertex, but the layout of the block is not shown.
  Reviewed: 2026-11-12

- `xswitch_vertex_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xaf44
  **Inferred.** It allocates a 0x20-byte zeroed block with `kmem_zalloc` at 0xaf58, initializes a mutex in it with `init_mutex` at 0xaf74, and attaches the block to its argument with `hwgraph_info_add_LBL` at 0xaf84, using the label at `.rodata+4400`. It returns the result of that last call.
  Reviewed: 2026-11-12

- `xswitch_volunteer_delete` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xaf9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xaf9c-0xafc8 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xafa8 calls hwgraph_info_remove_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4400, a2=sp-16, a3=a3 at entry (arg3).
  The `jal` at 0xafb4 calls kmem_free with a0=?, a1=0x20, a2=?, a3=?.
  The return at 0xafc0 has v0 = ret(kmem_free).

- `early_probe_for_widget` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xb59c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xb59c-0xb62c (144 bytes).
  It occupies 144 bytes.
  The `lh` at 0xb5c0 loads 2 bytes from ?.
  The `ld` at 0xb5d0 loads 8 bytes from table(0x9200000001c00128) +0x0.
  The `lw` at 0xb5e8 loads 4 bytes from table(0x92000000e0000004) +0x0.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x4, including `sw` at 0xb5f0, `sw` at 0xb620.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0xb600, `sw` at 0xb628.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0xb608, `sw` at 0xb61c.
  The `jal` at 0xb5b4 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4400, a2=sp-32, a3=a3 at entry (arg3).
  The `beq` branch at 0xb5e0 targets 0xb618, is taken when (a3(=entry(0x9200000001c00128)) & 0x2000) == 0, and falls through when (a3(=entry(0x9200000001c00128)) & 0x2000) != 0.
  The `beq` branch at 0xb624 targets 0xb60c and is always taken.
  The return at 0xb610 has v0 = ret(hwgraph_info_get_LBL).

- `xwidget_inventory_add` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xb62c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xb62c-0xb690 (100 bytes).
  It occupies 100 bytes.
  The `lbu` at 0xb64c loads 1 byte from a1 (arg1 at entry) +0xa.
  The `lw` at 0xb650 loads 4 bytes from abs 0x9000000010000090.
  The `lbu` at 0xb670 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lh` at 0xb674 loads 2 bytes from a1 (arg1 at entry) +0xe.
  The `jal` at 0xb67c calls device_inventory_add with a0=a0 at entry (arg0), a1=0xb, a2=[a1+5]:1, a3=[a1+14]:2, a6=0x20, a7=a1 at entry (arg1).
  The `beq` branch at 0xb644 targets 0xb684, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xb658 targets 0xb670, is taken when at(=[0x9000000010000090]) == 0, and falls through when at(=[0x9000000010000090]) != 0.
  The `bne` branch at 0xb660 targets 0xb670, is taken when a4(?) != a5(=0x1), and falls through when a4(?) == a5(=0x1).
  The `beq` branch at 0xb668 targets 0xb688, is taken when a1(?) == a6(=0x20), and falls through when a1(?) != a6(=0x20).
  The return at 0xb688 has v0 = ?.

- `do_io_init_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xbdd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xbdd8-0xc11c (836 bytes).
  It occupies 836 bytes.
  5 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0xbde0, `ld` at 0xbfc4, `ld` at 0xc01c.
  5 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0xbde4, `ld` at 0xbfd0, `ld` at 0xc020.
  The `ld` at 0xbdf8 loads 8 bytes from ((a0 << 0x3) + [[-0x3c00]:8]:8) +0x0.
  The `ld` at 0xbe00 loads 8 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4978.
  The `lw` at 0xbe14 loads 4 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x5150.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0xbe2c, `ld` at 0xbe38, `ld` at 0xbe44.
  The `lh` at 0xbeac loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `lw` at 0xbebc loads 4 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x20) -0x6dffffff1ffffffc.
  3 such `sb` accesses store 1 byte to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49dc, including `sb` at 0xbf00, `sb` at 0xc0d0, `sb` at 0xc110.
  The `sw` at 0xbf28 stores 4 bytes to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49e0.
  2 such `lbu` accesses load 1 byte from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49dc, including `lbu` at 0xbf84, `lbu` at 0xc118.
  The `lbu` at 0xbf98 loads 1 byte from ?.
  The `lh` at 0xbfac loads 2 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4990.
  The `lh` at 0xbfcc loads 2 bytes from (sym(nasid_to_compact_node) + ([[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18832]:2 + [[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18832]:2)) +0x0.
  The `lw` at 0xbfe4 loads 4 bytes from ?.
  3 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0, including `ld` at 0xc028, `ld` at 0xc048, `ld` at 0xc060.
  The `sw` at 0xc050 stores 4 bytes to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4b6c.
  The `sw` at 0xc064 stores 4 bytes to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4c78.
  2 such `lw` accesses load 4 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x20) -0x6dffffff1fffffdc, including `lw` at 0xc0c0, `lw` at 0xc0f4.
  The `jal` at 0xbe24 calls router_init with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xbe50 calls hubdev_docallouts with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a1=?, a2=?, a3=?.
  The `jal` at 0xbe58 calls nic_hub_vertex_info with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a1=?, a2=?, a3=?.
  The `jal` at 0xbe64 calls early_probe_for_widget [0xb59c] with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a1=sp-112, a2=?, a3=?.
  The `jal` at 0xbe84 calls hwgraph_path_add with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a1=sym(.rodata)+4400, a2=sp-96, a3=-0x1.
  The `jal` at 0xbe98 calls hwgraph_edge_add with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a1=?, a2=sym(.rodata)+4400, a3=?.
  The `jal` at 0xbf0c calls sprintf with a0=sp-88, a1=sym(.rodata)+4400, a2=?, a3=?.
  The `jal` at 0xbf1c calls hwgraph_path_add with a0=?, a1=sp-88, a2=sp-72, a3=?.
  The `jal` at 0xbf58 calls device_master_set with a0=?, a1=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a2=?, a3=0xd000.
  The `jal` at 0xbf74 calls hwgraph_info_get_LBL with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a1=sym(.rodata)+4400, a2=sp-64, a3=?.
  The `jal` at 0xbf94 calls xwidget_register with a0=sp-112, a1=?, a2=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18908]:1, a3=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a5=0x0.
  The `jal` at 0xbfa4 calls volunteer_for_widgets [0xafc8] with a0=?, a1=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a2=?, a3=?.
  The `jal` at 0xbfe8 calls volunteer_for_widgets [0xafc8] with a0=?, a1=?, a2=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18832]:2, a3=?, a5=-0x1.
  The `jal` at 0xbff8 calls psema with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18840, a1=0x19, a2=?, a3=?.
  The `jal` at 0xc004 calls io_init_xswitch_widgets [0xb9f0] with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xc010 calls io_link_xswitch_widgets [0xba88] with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xc034 calls xbow_get_bridge_pointers with a0=a0 at entry (arg0), a1=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+19320, a2=sp-56, a3=?.
  The `jal` at 0xc08c calls assign_widgets_to_volunteers [0xb0ac] with a0=?, a1=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a2=?, a3=?.
  The `jal` at 0xc09c calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc0e4 calls io_link_direct_widget [0xbcbc] with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xc10c calls cmn_err with a0=0x0, a1=sym(.rodata)+4400, a2=?, a3=?, a4=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+20816], a6=([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x20)+0x92000000e0000000, a7=0x92000000e0000000.
  The `bne` branch at 0xbe10 targets 0xbe38, is taken when s0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18808]:8) != 0, and falls through when s0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18808]:8) == 0.
  The `beq` branch at 0xbe18 targets 0xbe50 and is always taken.
  The `beq` branch at 0xbe30 targets 0xbe50, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xbe3c targets 0xbe20, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0xbe48 targets 0xbe38, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xbe74 targets 0xc068, is taken when t9(?) == a3(=-0x1), and falls through when t9(?) != a3(=-0x1).
  The `beq` branch at 0xbed0 targets 0xc0c0, is taken when a2(?) == a3(=0xc002), and falls through when a2(?) != a3(=0xc002).
  The `beq` branch at 0xbedc targets 0xc0c0, is taken when a2(?) == t0(=0xd002), and falls through when a2(?) != t0(=0xd002).
  The `beq` branch at 0xbee4 targets 0xbefc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xbeec targets 0xbefc, is taken when a2(?) == a0(=0xd000), and falls through when a2(?) != a0(=0xd000).
  The `bne` branch at 0xbef4 targets 0xc0f4, is taken when a2(?) != a1(=0xd100), and falls through when a2(?) == a1(=0xd100).
  The `beq` branch at 0xbf30 targets 0xc0d4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xbf3c targets 0xc0b0, is taken when a0(?) == a3(=0xd000), and falls through when a0(?) != a3(=0xd000).
  The `beq` branch at 0xbf48 targets 0xc0b0, is taken when a0(?) == a4(=0xd100), and falls through when a0(?) != a4(=0xd100).
  The `bne` branch at 0xbf60 targets 0xbff8, is taken when v0(=ret(device_master_set)) != 0, and falls through when v0(=ret(device_master_set)) == 0.
  The `beq` branch at 0xbf9c targets 0xc0e4, is taken when s0(=one of 0x0, 0x1) == 0, and falls through when s0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xbfb4 targets 0xc088, is taken when a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18832]:2) == a5(=-0x1), and falls through when a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18832]:2) != a5(=-0x1).
  The `beq` branch at 0xbff0 targets 0xc08c and is always taken.
  The `beq` branch at 0xc094 targets 0xc004, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xc0a4 targets 0xc004 and is always taken.
  The `bne` branch at 0xc0b0 targets 0xbf54, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xc0b8 targets 0xbf54 and is always taken.
  The `beq` branch at 0xc0cc targets 0xbf04 and is always taken.
  The `bne` branch at 0xc0d4 targets 0xbf3c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xc0dc targets 0xc0b8 and is always taken.
  The `beq` branch at 0xc0ec targets 0xc06c and is always taken.
  The `beq` branch at 0xc114 targets 0xbf04 and is always taken.
  The return at 0xc080 has v0 = one of ?, ret(io_link_direct_widget).
  The instructions from 0xc0ac to 0xc0ac are not reached by any path from the entry, and their branches are not listed.

- `sn00_vmc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xc818 (200 bytes). Grade: inferred.
  It indexes a table through the halfword at `-0x3bde`. It calls `device_inventory_add` (0xc850) with `a1` = 0xb and `a2` = 0x3, then `pcibr_hints_dualslot` (`a1` = 0x2, `a2` = 0x3), `pcibr_hints_subdevs` (`a1` = 0x2, `a2` = 0xff), `pcibr_hints_fix_rrbs` and `pcibr_set_rrb_callback` with `sn00_rrb_alloc` in `a1`. It then calls `splprof`, `get_my_slotid` and `splx` (0xc8bc, with 0x9200000001220050 in `a3`). Two doubleword stores follow the `get_my_slotid` result compare on each side of the branch at 0xc8ac; their targets are not resolved. Role (from name): per-board PCI hint setup; the meaning of the constants and table fields is open.
  Reviewed: 2026-11-12

- `sn00_vmc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xc818
  **Inferred.** Role (from facts): calls device_inventory_add [call 1] and sets PCI bridge hints with pcibr_hints_dualslot [call 2], pcibr_hints_subdevs [call 3] and pcibr_hints_fix_rrbs [call 4]. It installs sn00_rrb_alloc as the bridge's RRB callback [call 5]. It brackets a call to get_my_slotid [call 7] with splprof [call 6] and splx [call 8]. The branch at 0xc8ac compares a4, which holds the constant 1, with a6 [@0xc8ac taken].
  Reviewed: 2026-11-12

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8 (116 bytes). Grade: inferred.
  It raises the priority with `splhi`, calls `get_nasid`, and calls `nasid_slice_to_cpuinfo` with that result in `a0` and the doubleword at 0x9200000001000020 (the word `get_slice` returns) in `a1`. It restores the priority with `splx`. When the returned record pointer is nonzero it returns the halfword at offset 0x1e of the record. When it is null it reaches `assfail` (0xe05c) with 0x535 in `a2`. Role (from name): the current CPU id; the id's encoding is not shown.
  Reviewed: 2026-11-12

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8
  **Inferred.** The routine masks interrupts with splhi at 0xe004, gets a NASID with get_nasid at 0xe00c, and looks up its CPU record with nasid_slice_to_cpuinfo at 0xe020, using a slice value loaded from 0x9200000001000020 at 0xe018. It returns the halfword at record offset 0x1e (0xe040 to 0xe048) and restores interrupts with splx at 0xe02c. A null record reaches assfail with line constant 0x535 at 0xe05c. The returned field is most likely a CPU id, judging from the name, but the field's meaning is not in the facts.
  Reviewed: 2026-11-12

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8
  **Inferred.** It blocks interrupts with `splhi` at 0xe004, finds the node with `get_nasid` at 0xe00c, and looks up the CPU record for the slice held at the fixed address 0x9200000001000020 with `nasid_slice_to_cpuinfo` at 0xe020. It restores the level with `splx` at 0xe02c and returns the 16-bit field at `+0x1e` of that record at 0xe048. A zero record reaches `assfail` at 0xe05c with line 0x535.
  Reviewed: 2026-11-12

- `hub_ioerror_local` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe4f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xe4f0-0xe5ec (252 bytes).
  It occupies 252 bytes.
  The `lw` at 0xe52c loads 4 bytes from a3 (arg3 at entry) +0x0.
  2 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0xc, including `lh` at 0xe530, `lh` at 0xe5b4.
  2 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0xe, including `lh` at 0xe538, `lh` at 0xe5b8.
  The `lh` at 0xe54c loads 2 bytes from (sym(compact_to_nasid_node) + ([a3+12]:2 + [a3+12]:2)) +0x0.
  The `lh` at 0xe558 loads 2 bytes from (sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2)) +0x0.
  2 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x10, including `ld` at 0xe560, `ld` at 0xe5bc.
  The `ld` at 0xe578 loads 8 bytes from ([(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2 << 0x20) -0x6dfffffffe800000.
  The `jal` at 0xe5a0 calls cmn_err with a0=0x4, a1=sym(.rodata)+5944, a2=?, a3=[(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2, a4=[a3+14]:2, a5=[(sym(compact_to_nasid_node) + ([a3+12]:2 + [a3+12]:2))]:2, a6=[a3+12]:2.
  The `jal` at 0xe5ac calls kl_panic with a0=sym(.rodata)+5944, a1=?, a2=?, a3=?.
  The `jal` at 0xe5d0 calls cmn_err with a0=0x4, a1=sym(.rodata)+5944, a2=[a3+16]:8, a3=[(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2, a4=[a3+14]:2, a5=[(sym(compact_to_nasid_node) + ([a3+12]:2 + [a3+12]:2))]:2, a6=[a3+12]:2.
  The `jal` at 0xe5dc calls kl_panic with a0=sym(.rodata)+5944, a1=?, a2=?, a3=?.
  The `beq` branch at 0xe4fc targets 0xe524, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xe508 targets 0xe524, is taken when a2 == at(=0x2), and falls through when a2 != at(=0x2).
  The `bne` branch at 0xe510 targets 0xe52c, is taken when a2 != v0(=0x3), and falls through when a2 == v0(=0x3).
  The `beq` branch at 0xe524 targets 0xe518 and is always taken.
  The `bgez` branch at 0xe554 targets 0xe564, is taken when a2(=([a3] << 0x6)) >= 0 (signed), and falls through when a2(=([a3] << 0x6)) < 0 (signed).
  The `beq` branch at 0xe55c targets 0xe568 and is always taken.
  The `beq` branch at 0xe58c targets 0xe5bc, is taken when (a3(=[([(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2 << 0x20)-7926335344146907136]:8) & a5(?)) == 0, and falls through when (a3(=[([(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2 << 0x20)-7926335344146907136]:8) & a5(?)) != 0.
  The `beq` branch at 0xe5e4 targets 0xe518 and is always taken.
  The return at 0xe51c has v0 = one of 0x0, ret(kl_panic).

- `hub_xp_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe5ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xe5ec-0xe668 (124 bytes).
  It occupies 124 bytes.
  The `ld` at 0xe5f8 loads 8 bytes from (a1 << 0x20) -0x6dfffffffe3ffe18.
  The `ld` at 0xe624 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0xe62c loads 2 bytes from (sym(nasid_to_compact_node) + (a1 + a1)) +0x0.
  The `ld` at 0xe630 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0xe63c loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3)) +0x0.
  The `lw` at 0xe650 loads 4 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8 +0x49e0.
  The `jal` at 0xe64c calls xtalk_error_handler with a0=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8+18912], a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=a4 at entry (arg4), a6=0x7, a7=a2 at entry (arg2).
  The `beq` branch at 0xe614 targets 0xe65c, is taken when (at(=[(a1 << 0x20)-7926335344142712344]:8) & 0x11) == 0, and falls through when (at(=[(a1 << 0x20)-7926335344142712344]:8) & 0x11) != 0.
  The return at 0xe660 has v0 = one of 0x7, ret(xtalk_error_handler).

- `hub_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe668
  **Inferred.** The routine finds a widget's info through xwidget_info_get (0xe674), xwidget_info_id_get (0xe680) and xwidget_info_master_get (0xe68c), then looks up a name with hwgraph_info_get_LBL at 0xe6a8. It masks a word loaded from table address 0x9200000001c00118 (0xe6d8) with a register value at 0xe6ec, and returns 0 or 1 at 0xe6f8. The 0 or 1 result probably reports whether a DMA enable bit is set, but the bit tested and the mask value are not shown. cmn_err at 0xe71c (level 6) is called on the path taken when the masked word is zero.
  Reviewed: 2026-11-12

- `hub_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe668
  **Inferred.** It resolves a widget through `xwidget_info_get`, `xwidget_info_id_get`, `xwidget_info_master_get` and `hwgraph_info_get_LBL` at 0xe674 to 0xe6a8. It then tests a mask from the table word at 0x9200000001c00118 and returns 0 or 1 at 0xe6f8. The error path reports with `cmn_err` at 0xe71c, level 6. The mask bit it tests is not identified.
  Reviewed: 2026-11-12

- `hub_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe668
  **Inferred.** Calls xwidget_info_get at 0xe674 with its four arguments, then passes that result to xwidget_info_id_get at 0xe680 and xwidget_info_master_get at 0xe68c. It passes the master to hwgraph_info_get_LBL at 0xe6a8. It tests the result of an AND with t2 at 0xe6ec against zero, where the doubleword loaded at 0xe6d8 comes from a table based at 0x9200000001c00118 whose index the facts do not resolve, and returns 0 or 1 (0xe6f8). cmn_err is called at 0xe71c with the constant 0x6 as its first argument; what condition leads there is not shown. The bit that means DMA is enabled is unknown.
  Reviewed: 2026-11-12

- `hub_widgetdev_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe72c
  **Inferred.** The routine looks up the widget and its master through xwidget_info_get (0xe73c), xwidget_info_id_get (0xe74c) and xwidget_info_master_get (0xe758), then calls hwgraph_info_get_LBL at 0xe76c. It calls hubiio_crb_free at 0xe850 only on a path guarded by several branches (for example 0xe840 and 0xe848 compare registers that the facts do not resolve); the name suggests this releases a CRB. It loads from a table-relative address at 0xe7cc and stores at 0xe7dc, and the facts do not show that both use the same address. It tests the sign of a word loaded from 0x9200000001c00400 at 0xe808 after shifts. A register is compared with 0xf at 0xe7f4, which may be a bounded loop over slots. Two cmn_err calls at level 6 (0xe8cc and 0xe8e8) are present; what they report is not shown, and neither is the value stored.
  Reviewed: 2026-11-12

- `hub_widgetdev_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe72c
  **Inferred.** Role (from name): shutting down a widget device. It resolves the widget the same way as `hub_dma_enabled` (four calls at 0xe73c to 0xe76c), then stores a doubleword at offset +0x0 at 0xe7dc; the facts show neither the address nor the value. A loop tests an index against 0xf at 0xe7f4, tests `free_error_crbs` at 0xe804, and calls `hubiio_crb_free` at 0xe850; the arguments are not shown. It tests `free_error_crbs_print` at 0xe85c and 0xe870, and reports through `cmn_err` at 0xe8cc and 0xe8e8, level 6. What the loop frees is not settled by these facts.
  Reviewed: 2026-11-12

- `hub_widgetdev_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe904 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xe904-0xe9a4 (160 bytes).
  It occupies 160 bytes.
  The `lh` at 0xe968 loads 2 bytes from ?.
  The `ld` at 0xe980 loads 8 bytes from table(0x9200000001c00120) +0x0.
  The `sd` at 0xe9a0 stores 8 bytes to table(0x9200000001c00120) +0x0.
  The `jal` at 0xe910 calls xwidget_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe91c calls xwidget_info_id_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xe928 calls xwidget_info_master_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xe940 calls hwgraph_info_get_LBL with a0=ret(xwidget_info_master_get), a1=sym(.rodata)+5944, a2=sp-48, a3=?.
  The `beq` branch at 0xe960 targets 0xe994, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xe98c targets 0xe99c, is taken when (a6(?) & a7(=entry(0x9200000001c00120))) == 0, and falls through when (a6(?) & a7(=entry(0x9200000001c00120))) != 0.
  The `beq` branch at 0xe99c targets 0xe994 and is always taken.
  The return at 0xe994 has v0 = one of ret(hwgraph_info_get_LBL), table(0x9200000001c00000).

- `hub_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe9a4
  **Inferred.** The routine looks up a widget and its master through xwidget_info_get (0xe9b4), xwidget_info_id_get (0xe9c0) and xwidget_info_master_get (0xe9cc), and gets a name with hwgraph_info_get_LBL at 0xe9e4. It compares its third argument with 5 and 6 at 0xe9fc and 0xea04, and returns 0 at 0xea10 when it is neither. It reads the table word at 0x9200000001c002c8 (0xea34) and tests its sign after a shift by 7 at 0xea3c. It also stores a doubleword at 0xea64; the facts do not give that store address. The meaning of the source word and of the stored value is not shown.
  Reviewed: 2026-11-12

- `hub_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe9a4
  **Inferred.** It resolves the widget through the same four calls (0xe9b4 to 0xe9e4). It compares a value with 5 at 0xe9fc and 6 at 0xea04, and returns 0 at 0xea10. It loads the table word at 0x9200000001c002c8 at 0xea34, tests bit 56 of it at 0xea3c, and stores a doubleword at offset +0x0 at 0xea64; the destination address and the stored value are not shown by these facts. The name suggests enabling error reporting for a device, which the facts do not confirm.
  Reviewed: 2026-11-12

- `hub_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe9a4
  **Inferred.** Role (from facts): calls xwidget_info_get [call 1], then xwidget_info_id_get [call 2] and xwidget_info_master_get [call 3] on its result, and hwgraph_info_get_LBL on the master [call 4]. It compares a2 with 5 [@0xe9fc taken] and with 6 [@0xea04 taken]. Its return is the constant 0 [@0xea10].
  Reviewed: 2026-11-12

- `hub_ioerror_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xead0
  **Inferred.** The routine appears to work on a structure passed in its fourth argument a3, with loads at offsets 0x30, 0x10 and 0x6 and stores at 0x18 and 0x6 (some other loads and stores at +0x0 have bases the facts do not resolve). The routine is 1028 bytes. It calls is_widget_pio_enabled at 0xec1c and 0xecdc; the name suggests a PIO-state check. It calls hub_xp_error_handler at 0xec38, 0xecf8 and 0xed24, passing its own arguments on, and calls hub_ioerror_local, error_state_get, xtalk_pio_target_get, xtalk_pio_xtalk_addr_get, printf and ioerror_dump on other paths. It reads the table word at 0x9200000001c00160 (0xec8c) and calls hwgraph_info_get_LBL at 0xeb00. The name suggests an I/O error handler, which fits these calls, but the structure's field layout is not established.
  Reviewed: 2026-11-12

- `hub_ioerror_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xead0
  **Inferred.** Role (from name): an I/O error handler. It loads the address `[a3+48]` and compares it, as unsigned ranges, with the constants 0x92000000e0000000, 0x920000000a000000, 0x9200000020000000 and 0x9200000100000000 to choose a path. The paths call `is_widget_pio_enabled` at 0xec1c and 0xecdc, `hub_xp_error_handler` at 0xec38, 0xecf8 and 0xed24, `hub_ioerror_local` at 0xee08 and 0xee44, and `ioerror_dump` at 0xeea8 and 0xeec4; other calls include `error_state_get`, `printf`, `xtalk_pio_target_get` and `xtalk_pio_xtalk_addr_get`. The per-path meanings are only partly settled.
  Reviewed: 2026-11-12

- `crbx` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xeed4
  **Inferred.** The routine is 3312 bytes and makes 12 indirect calls through jalr from 0xef18 onward, and six calls to sprintf. All twelve pass the same .rodata string at +5944 as the first argument. The dispatch targets are not in the facts, so the routine's purpose is not derived here. The name suggests CRB register access, and that is only a guess from the name.
  Reviewed: 2026-11-12

- `crbx` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xeed4
  **Inferred.** It makes six `sprintf` calls (0xef98, 0xefe4, 0xf37c, 0xf53c, 0xf56c, 0xf5b8) and twelve calls whose callee the facts do not resolve (0xef18 to 0xef60, 0xf070, 0xf0c8, 0xf110, 0xf190), and it loads halfword and word values at offsets such as `+0x2cd4` at 0xf21c from a base the facts do not show. The field layout and the tables are not identified by these facts, so the role stays at building formatted strings.
  Reviewed: 2026-11-12

- `crbx` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xeed4
  **Inferred.** A formatter with many sprintf calls (0xef98, 0xefe4, 0xf37c, 0xf53c, 0xf56c, 0xf5b8) that write into stack buffers at sp-112, sp-120 and sp-136. It makes 12 indirect calls through registers (0xef18 to 0xef60, 0xf070, 0xf0c8, 0xf110 and 0xf190) whose targets the facts do not resolve. The branches compare the register `a2` with 1, 2, 3, 4, 5, 8, 0x12, 0x41 and 0x100, and `a1` with 0x6, 0x7, 0x8, 0x20, 0x21, 0x22, 0x81, 0x83 and 0xa2; the facts do not resolve which routine arguments those registers hold. The field each path prints is unknown.
  Reviewed: 2026-11-12

- `hub_merge_clean` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfbc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xfbc4-0xfc50 (140 bytes).
  It occupies 140 bytes.
  The `ld` at 0xfbe4 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe3ffc58.
  The `ld` at 0xfc1c loads 8 bytes from ?.
  The `lw` at 0xfc3c loads 4 bytes from ?.
  The `beq` branch at 0xfc14 targets 0xfc40, is taken when (t3(?) & 0x7fff) == 0, and falls through when (t3(?) & 0x7fff) != 0.
  The `bne` branch at 0xfc40 targets 0xfbfc, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The return at 0xfc48 has v0 = ?.

- `hub_init_ifdr_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfc50
  **Inferred.** The routine indexes a pointer table at -0x3c00 by the node number scaled by 8 and writes a halfword at record offset 0x4c82 (0xfc74), a halfword at 0x4c84 (0xfc8c) and a word at 0x4c7c (0xfca4). It compares a value with a second value at 0xfcd8 and reports through cmn_err at level 5 at 0xfd1c. The name suggests a workaround initialisation, but the meaning of the stored values is not shown.
  Reviewed: 2026-11-12

- `hub_init_ifdr_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfc50
  **Inferred.** It indexes the node table `compact_to_nasid_node` with `a0`, stores halfwords at `+0x4c82` and `+0x4c84` and a word at `+0x4c7c`, and compares a halfword loaded at 0xfccc with a value at 0xfcd8. A branch at 0xfcd8 can return at 0xfd0c; a doubleword store at constant offset -0x6dfffffffe3ffc68 occurs at 0xfd08. It reports through `cmn_err` at 0xfd1c with level 5 and the node's fields. The conditions that select the store and the report are not settled by these facts. The name suggests a workaround setup, but the workaround itself is not visible in these facts.
  Reviewed: 2026-11-12

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** The routine tests the global hubio_ifdr_skip at 0xfd50 and returns 0 at once (0xfd58) when that flag is nonzero. Otherwise it reads a halfword from the node record at offset 0x4c84 (0xfd94) and compares it unsigned with a value at 0xfda4. It returns 1 at 0xfdac when the comparison falls short and 0 at 0xfdb4 otherwise. The name suggests a check of an IFDR value, which matches this compare, but the threshold it uses is not shown.
  Reviewed: 2026-11-12

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** It tests the global `hubio_ifdr_skip` at 0xfd50; nonzero ends at the return of 0 at 0xfd58. Otherwise it loads values and compares a halfword at offset 19588 of a loaded pointer with another value at 0xfda4, returning 1 at 0xfdac or 0 at 0xfdb4. It is a yes/no check, and what exactly is compared is not identified by these facts.
  Reviewed: 2026-11-12

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** Returns 0 at once when the flag hubio_ifdr_skip is set (0xfd50, 0xfd58). Otherwise it loads a halfword from compact_to_nasid_node indexed by a0 (`lh` at 0xfd74) and a doubleword from a pointer table indexed by a0 (0xfd88), then reads a halfword at offset 19588 of that doubleword's target (0xfd94). It returns 1 when that halfword is below the value in v1 and 0 otherwise (0xfda4 to 0xfdb4). A further load at 0xfd90 is built from the nasid halfword, but the facts do not show that it feeds v1. The meaning of the halfword and of v1 is unknown.
  Reviewed: 2026-11-12

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** A 112-byte routine. When the word `hubio_ifdr_skip` is nonzero, the branch at 0xfd50 falls through to the return at 0xfd58 [@0xfd50 fall nonzero] [@0xfd58], which returns 0. When that word is zero the branch is taken to 0xfd60 [@0xfd50 taken zero]. There the routine loads a halfword through the table index `a0` [@0xfd74] and compares an unsigned value at 0xfda4 [@0xfda4]. The returns at 0xfdac and 0xfdb4 yield 1 [@0xfdac] and 0 [@0xfdb4]. Role (from name): an IFDR value check. The facts do not show what the compared value means.
  Reviewed: 2026-11-12

- `hub_ifdr_fix_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfdbc
  **Inferred.** The routine reads halfwords at record offsets 0x4c82 and 0x4c84 (0xfe0c, 0xfe80), compares a value with 0x41 at 0xfde8, and runs bit-mask tests with 0x7f at 0xfe3c and 0xfe4c. It writes the halfword at 0x4c82 at 0xfe20 and a doubleword at 0xfe9c. It returns -1 or 1 at 0xfea0. The name suggests a repair of an IFDR value, but the failure condition and the meaning of the masks are not settled by the facts.
  Reviewed: 2026-11-12

- `hub_setup_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfea8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0xfea8-0xff44 (156 bytes).
  It occupies 156 bytes.
  3 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0xfec0, `ld` at 0xfee4, `ld` at 0xfefc.
  3 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0xfec4, `ld` at 0xfee8, `ld` at 0xff00.
  3 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0, including `ld` at 0xfed4, `ld` at 0xfef0, `ld` at 0xff0c.
  The `sw` at 0xfef8 stores 4 bytes to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4b6c.
  The `sw` at 0xff1c stores 4 bytes to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4b68.
  The `jal` at 0xfedc calls spinlock_init with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+19312, a1=sym(.rodata)+5944, a2=?, a3=a0 at entry (arg0).
  The `jal` at 0xff28 calls spinlock_init with a0=sym(global_kick_lock), a1=sym(.rodata)+5944, a2=a2 at entry (arg2), a3=a0 at entry (arg0).
  The `jal` at 0xff34 calls spinlock_init with a0=sym(kick_mask_lock), a1=sym(.rodata)+5944, a2=?, a3=?.
  The `beq` branch at 0xfeb8 targets 0xff20, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0xff3c targets 0xfec0 and is always taken.
  The return at 0xff18 has v0 = ret(spinlock_init).

- `hub_dmatimeout_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xffc4
  **Inferred.** The routine branches on its second argument a1 at 0xfff8. When a1 is nonzero it takes global_kick_lock with mutex_spinlock at 0x10000. When a1 is zero it calls mutex_spintrylock on the same lock at 0x1036c and continues at 0x1000c only if that call returns nonzero. It asks a CPU to run kick_action through cpuaction at 0x100ec, in a loop bounded by maxcpus (0x10108), and calls bte_wait_for_xfer_completion at 0x10114. On a later path it calls us_delay with 5 at 0x1026c, hub_merge_clean at 0x10274, us_delay with 2 at 0x1027c and hub_ifdr_fix_value at 0x10298, then us_delay with 2 again at 0x10310, splx at 0x10320 and mutex_spinunlock at 0x1032c. The name says DMA timeout, which fits this kick-and-retry sequence, but the trigger condition is not established.
  Reviewed: 2026-11-12

- `hub_dmatimeout_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xffc4
  **Inferred.** Role (from name): a recovery routine for a stalled DMA. When `a1` is nonzero it calls `mutex_spinlock` on `global_kick_lock` at 0x10000; when `a1` is zero it calls `mutex_spintrylock` at 0x1036c and continues only on a nonzero result. It runs `cpuaction` with `kick_action` at 0x100ec, calls `bte_wait_for_xfer_completion` at 0x10114, `splerr` at 0x101b8, `us_delay` with 5 at 0x1026c, `hub_merge_clean` at 0x10274, `us_delay` with 2 at 0x1027c, `hub_ifdr_fix_value` at 0x10298 and `us_delay` with 2 at 0x10310. It then calls `splx` and `mutex_spinunlock` on `global_kick_lock` (0x10320, 0x1032c) and later `cmn_err` calls at 0x10460 to 0x104c0. The order of recovery steps is taken from the call sequence only.
  Reviewed: 2026-11-12

- `hub_dmatimeout_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xffc4
  **Inferred.** A 1308-byte routine. When `a1` is nonzero it takes `global_kick_lock` with `mutex_spinlock` [call 1, @0xfff8 fall]; when `a1` is zero it uses `mutex_spintrylock` on the same lock [call 12, @0xfff8 taken zero]. It reads a halfword from `sym(compact_to_nasid_node)` indexed by `a0` [@0xfffc]. It stores to `sym(entermask)` [@0x10048] and to the doubleword after it [@0x10054]. Role (from name): a DMA timeout kick across the hub nodes. The facts do not show what the kick action does to the hardware.
  Reviewed: 2026-11-12

- `hub_widget_reset` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x104e0
  **Inferred.** The routine gets the master node with master_node_get at 0x104ec and masks interrupts with splhi at 0x10528. It calls hub_setup_prb at 0x105e8 with constants 0x3 and 0x2 as its third and fourth arguments, restores interrupts with splx at 0x105f0, and calls assfail with line 0x562 at 0x1065c and 0x10678 on its failure paths. It stores doublewords at 0x105bc and 0x105c0 and at 0x10638 and 0x1063c, reloads from the same displacement at 0x105c4 and 0x10640, and tests bit 0x10 of a loaded word at 0x105cc and 0x10648. The name suggests a widget reset, but the facts do not show what the stored values or addresses are, so the reset sequence is not derived.
  Reviewed: 2026-11-12

- `hub_widget_reset` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x104e0
  **Inferred.** It finds the master node with `master_node_get` at 0x104ec, raises the interrupt level with `splhi` at 0x10528, and calls `hub_setup_prb` at 0x105e8 with the constants 3 and 2. It restores the level with `splx` at 0x105f0. The `assfail` calls at 0x1065c and 0x10678 use line 0x562. The meaning of the PRB setup arguments is not identified.
  Reviewed: 2026-11-12

- `hub_widget_reset` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x104e0
  **Inferred.** Brackets its work with splhi at 0x10528 and splx at 0x105f0, and gets the master node from master_node_get at 0x104ec. A loop counts s1 up to 8 (0x1055c, 0x10584) and tests mask 0x10 of a doubleword loaded at 0x105c4 and 0x10640 through an address built from a compact-to-nasid index shifted left by 0x20 (branches at 0x105cc and 0x10648). It calls hub_setup_prb once, at 0x105e8, with the constants 3 and 2 as its third and fourth arguments. Two assfail calls at 0x1065c and 0x10678 pass the constant 0x562 as their third argument. The registers the loop writes are unknown.
  Reviewed: 2026-11-12

- `restart` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x10694 (356 bytes). Grade: inferred.
  Role (from name): a restart path. It has a loop bounded by `maxnodes` (back branch at 0x1070c) that loads halfwords and stores doublewords. A second loop (0x10744 to 0x10774) calls `sysctlr_power_off` and `us_delay` (0x2dc6c0) when `power_off_flag` is nonzero. `ni_reset_port` is called once at 0x10784, outside both loops. The path then calls `get_nasid`, `elsc_init` and `elsc_system_reset`, and calls `printf` when the reset returns a negative value. There are three `us_delay` calls: 0xf4240 (0x10720), 0x2dc6c0 (0x10754) and 0xf4240 (0x107d4). If the unit is microseconds these are one, three and one seconds, but the unit is not shown.
  Reviewed: 2026-11-12

- `restart` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x10694
  **Inferred.** The routine waits with us_delay for 0xf4240 (1000000) at 0x10720. At 0x10734 it skips ahead to get_nasid (0x1079c) when reboot_on_panic equals 2. Otherwise, when power_off_flag is nonzero it calls sysctlr_power_off at 0x1074c and then us_delay for 0x2dc6c0 (3000000) at 0x10754, looping back to the flag test under conditions the facts only partly resolve; when power_off_flag is zero it calls ni_reset_port at 0x10784. It then gets a NASID at 0x1079c and initialises the ELSC controller with elsc_init at 0x107a8 before elsc_system_reset at 0x107b0. When that call returns a negative value it prints a message with printf at 0x107cc and calls us_delay for 1000000 at 0x107d4. The delay units are taken as microseconds from the us_delay name, and the flag-based choice is an inference.
  Reviewed: 2026-11-12

- `mdir_pstate` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11734 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x11734-0x1186c (312 bytes).
  It occupies 312 bytes.
  The `ld` at 0x1181c loads 8 bytes from table(sym(dir_state_str)) +0x0.
  The `ld` at 0x1182c loads 8 bytes from table(sym(dir_owner_str)) +0x0.
  The `jal` at 0x117d4 calls get_dir_ent with a0=?, a1=sp-112, a2=sp-104, a3=sp-96.
  The `jalr` at 0x11828 calls (unknown callee) with a0=sym(.rodata)+11944, a1=?, a2=?, a3=?, a4=entry(sym(dir_owner_str)), a5=entry(sym(dir_state_str)).
  The `beq` branch at 0x1177c targets 0x11838, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x1178c targets 0x117a8 and is always taken.
  The `bne` branch at 0x117a0 targets 0x11838, is taken when t8(?) < s8(?) (unsigned), and falls through when t8(?) >= s8(?) (unsigned).
  The `beq` branch at 0x117b0 targets 0x117c4 and is always taken.
  The `beq` branch at 0x117c0 targets 0x11794, is taken when s0(?) >= 0x1000 (signed), and falls through when s0(?) < 0x1000 (signed).
  The `beq` branch at 0x117dc targets 0x117e8, is taken when s1(=a0) == s4(=-0x1), and falls through when s1(=a0) != s4(=-0x1).
  The `bne` branch at 0x117e4 targets 0x117b8, is taken when s1(=a0) != t0(?), and falls through when s1(=a0) == t0(?).
  The `beq` branch at 0x11830 targets 0x117bc and is always taken.
  The return at 0x11864 has v0 = 0x0.

- `mdir_sstate` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1186c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1186c-0x119ac (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x11958 loads 8 bytes from table(sym(dir_state_str)) +0x0.
  The `ld` at 0x1196c loads 8 bytes from table(sym(dir_owner_str)) +0x0.
  The `jal` at 0x11918 calls get_dir_ent with a0=?, a1=sp-112, a2=sp-104, a3=sp-96.
  The `jalr` at 0x11968 calls (unknown callee) with a0=sym(.rodata)+11944, a1=?, a2=?, a3=?, a4=entry(sym(dir_owner_str)), a5=entry(sym(dir_state_str)).
  The `beq` branch at 0x118b4 targets 0x11978, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x118d0 targets 0x118ec and is always taken.
  The `bne` branch at 0x118e4 targets 0x11978, is taken when t8(?) < s8(?) (unsigned), and falls through when t8(?) >= s8(?) (unsigned).
  The `beq` branch at 0x118f4 targets 0x11908 and is always taken.
  The `beq` branch at 0x11904 targets 0x118d8, is taken when s0(?) >= 0x1000 (signed), and falls through when s0(?) < 0x1000 (signed).
  The `beq` branch at 0x11920 targets 0x1192c, is taken when s1(?) == s4(=-0x1), and falls through when s1(?) != s4(=-0x1).
  The `bne` branch at 0x11928 targets 0x118fc, is taken when s1(?) != t0(?), and falls through when s1(?) == t0(?).
  The `beq` branch at 0x11970 targets 0x11900 and is always taken.
  The return at 0x119a4 has v0 = 0x0.

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28 (64 bytes). Grade: inferred.
  It reads the doubleword at 0x9200000001000028 and, when that word is nonzero, compares `v1` with `a1` as unsigned values. It returns 0 or 1. Role (from name): a predicate on an alias state; the field the word holds is not established.
  Reviewed: 2026-11-12

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28
  **Inferred.** The routine reads the word at 0x9200000001000028 (0x11f30), branches on whether it is zero at 0x11f40, and compares v1 with a1 unsigned at 0x11f54. It returns 0 or 1 at 0x11f60. The name suggests an alias test between two addresses, which the range-style compare fits, but the rule that decides an alias is not established by these facts.
  Reviewed: 2026-11-12

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28
  **Inferred.** It loads the doubleword at the fixed address 0x9200000001000028 at 0x11f30 and returns 0 or 1 at 0x11f60. It looks like a yes/no test on that word. The alias condition the name refers to is not visible in the facts.
  Reviewed: 2026-11-12

- `page_local_calias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f88 (60 bytes). Grade: inferred.
  The same shape as `memory_iscalias`, reading 0x9200000001000028 and returning 0 or 1 after an unsigned compare of `a3` and `v1` when the word is nonzero. Role (from name): a page-local form of the same check. The relation to `memory_iscalias` is inferred from the matching structure.
  Reviewed: 2026-11-12

- `page_local_calias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f88
  **Inferred.** A 60-byte routine. It loads the doubleword at the fixed address 0x9200000001000028 [@0x11f8c]. The branch at 0x11f9c goes to 0x11fb8 when that word is zero [@0x11f9c taken zero] and falls through when it is nonzero [@0x11f9c fall nonzero]. The branch at 0x11fb0 compares `a3` with `v1`, and the return at 0x11fbc yields 0 or 1 [@0x11fbc]. Role (from name): a local alias check for a page. The facts do not show which alias it tests.
  Reviewed: 2026-11-12

- `bte_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12ddc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x12ddc-0x12ec4 (232 bytes).
  It occupies 232 bytes.
  The `sd` at 0x12e24 stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `sd` at 0x12e28 stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `lh` at 0x12e30 loads 2 bytes from abs 0xffffffffffffc422.
  The `sh` at 0x12e34 stores 2 bytes to a0 (arg0 at entry) +0x40.
  The `sd` at 0x12e44 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x12e54 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `lh` at 0x12e5c loads 2 bytes from (sym(compact_to_nasid_node) + ([-0x3bde]:2 + [-0x3bde]:2)) +0x0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x0, including `sd` at 0x12e88, `sd` at 0x12e90.
  2 such `sd` accesses store 8 bytes to abs 0x92000000014001f8, including `sd` at 0x12e94, `sd` at 0x12eb8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x54, including `sw` at 0x12e98, `sw` at 0x12ec0.
  The `sw` at 0x12ea0 stores 4 bytes to a0 (arg0 at entry) +0x70.
  The `jal` at 0x12e18 calls spinlock_init with a0=a0+68, a1=sym(.rodata)+12296, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[sym(scache_linemask)].
  The `beq` branch at 0x12e04 targets 0x12e14, is taken when (a5(=[sym(scache_linemask)]) & a1) == 0, and falls through when (a5(=[sym(scache_linemask)]) & a1) != 0.
  The `beq` branch at 0x12e84 targets 0x12eb4, is taken when s8(=a2) == 0, and falls through when s8(=a2) != 0.
  The `beq` branch at 0x12ebc targets 0x12e9c and is always taken.
  The return at 0x12eac has v0 = a0.

- `bte_init_buffers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12ec4
  **Inferred.** The routine loops over the node count in the symbol maxnodes (0x12ee0 and 0x12f54). Inside it an inner loop, whose index is compared with 2 at 0x12f24, allocates a 0x4000-byte block per iteration with kmem_zalloc_node using flags 0x901 at 0x12efc. It initialises a lock with spinlock_init at 0x12f38 and reports a null allocation with cmn_err at level 4 (0x12f8c). The comparison with 2 suggests two buffers per node, but this is only a constant in the facts.
  Reviewed: 2026-11-12

- `bte_avail` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12f9c
  **Inferred.** The routine is 12 bytes. The facts show a single return at 0x12fa0 with v0 unresolved, and no call, branch, load or store. The name suggests a block transfer engine availability check, but the facts do not show what v0 holds, so the role is not derived here.
  Reviewed: 2026-11-12

- `bte_avail` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12f9c
  **Inferred.** A routine with no loads, stores or calls in the rendered facts. It returns a value in `v0` at 0x12fa0 that the facts do not show. The name suggests a query for whether the block transfer engine is usable, but nothing here confirms that.
  Reviewed: 2026-11-12

- `bte_lateinit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12fa8
  **Inferred.** The routine allocates blocks of 0x78, 0x400, 0x4000 (zeroed), 0x4000 (with kmem_alloc_node) and 0x4 bytes with kmem_zalloc_node and kmem_alloc_node at 0x13078 through 0x131ac. It calls bte_init at 0x130d0 on the 0x400-byte block, initialises a lock with spinlock_init at 0x131c4, and has four assfail calls (line constants 0x14c, 0x156, 0x12d and 0x134) and two cmn_err calls at level 8. The name suggests a late setup step, which fits the allocation order, but the sizes are only constants in the facts.
  Reviewed: 2026-11-12

- `bte_pbcopy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13274
  **Inferred.** The routine calls bte_copy at 0x132cc with 0x10 as its fourth argument, and calls bcopy at 0x132ec and 0x13324 with both addresses ORed with 0xa800000000000000. The branch at 0x1329c tests disable_bte_pbcopy against zero, the branch at 0x132a8 compares maxcpus with that value, the branch at 0x132b0 tests disable_bte against zero, and the branch at 0x132b8 tests a register the facts do not resolve. The branch at 0x132d4 tests the return of bte_copy. The only return the facts list is 0 at 0x13308. The name suggests a copy through the engine with a software fallback, which the branch structure fits.
  Reviewed: 2026-11-12

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Role (from name):** the zero-fill counterpart of bte_pbcopy. **Inferred.** The routine calls bzero with addresses ORed with 0xa800000000000000 at 0x133b8 and 0x134c8. It calls get_hub_chiprev at 0x13410 with a value from a node-table lookup, and calls bte_copy at 0x13448 with a0 = 0 and a3 = 0x10. The facts show no comparison of the get_hub_chiprev result, so which path the hub revision selects is not shown, and only 0x10 appears as the fourth argument of bte_copy.
  Reviewed: 2026-11-12

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Inferred.** Role (from name): zeroing a block through the block transfer engine. It ORs 0xa800000000000000 into the address before the `bzero` calls at 0x133b8 and 0x134c8. It tests `disable_bte_pbzero` and `disable_bte`, calls `get_hub_chiprev` at 0x13410 (its result use is not shown), and calls `bte_copy` at 0x13448 with `a0` 0 and a mode of 0x10 on at least one path. It returns 0 or the `bte_copy` result at 0x133f0. The meaning of the revision call and the full set of modes are not identified.
  Reviewed: 2026-11-12

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Inferred.** Role (from name): zeroes a range through the block transfer engine. It calls bzero on a0 | 0xa800000000000000 at 0x133b8 and 0x134c8, and calls bte_copy at 0x13448 with a0 = 0 and a3 either 0x10 or 0x11. A branch at 0x13464 compares s0 unsigned with 0x4001 and goes back to 0x13438 when s0 is below it. Branches at 0x13368 and 0x13378 test the flags disable_bte_pbzero and disable_bte, and get_hub_chiprev is called at 0x13410, but the facts do not show that its result decides a branch. Which flag or revision picks which path is unknown.
  Reviewed: 2026-11-12

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Inferred.** A 472-byte routine with two paths. When `disable_bte_pbzero` is zero the branch at 0x13368 is taken [@0x13368 taken zero] to the test of `disable_bte` at 0x13378, and a zero there [@0x13378 taken zero] leads to the path that reads the hub chip revision with `get_hub_chiprev` [call 2] and copies with `bte_copy` [call 3]. The other path zeroes the buffer with `bzero` [call 1]. The copy path also calls `bzero` [call 4] when `bte_copy` returned 1 [@0x13488 fall]. Role (from name): a block-transfer page zeroing routine. The facts do not show the target address.
  Reviewed: 2026-11-12

- `bte_free_interfaces` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1350c
  **Inferred.** The routine loops with an index compared with the constant 2 at 0x13538, and skips the iteration where the index equals its argument a1 at 0x13540. It loads from offset 0x68 of a record (0x13548) and calls nested_spinunlock at 0x13558. The name suggests it frees the interfaces, but the facts show only the loop and the unlock, not the free itself.
  Reviewed: 2026-11-12

- `bte_get_all_interfaces` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13584
  **Inferred.** The routine takes locks with nested_spintrylock at 0x135d8 and 0x13728 under splhi and splx interrupt masking (0x136ac, 0x1369c, 0x1371c, 0x1370c). It waits one microsecond with us_delay at 0x136a4 and 0x13714 between attempts, which suggests a retry loop. The facts list one return of 0 at 0x13704. The name suggests it gathers every interface, but the facts do not show what it hands back.
  Reviewed: 2026-11-12

- `bte_oneline_xfer` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13754 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x13754-0x13904 (432 bytes).
  It occupies 432 bytes.
  The `ld` at 0x13774 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x137a0 loads 8 bytes from [a0]:8 +0x18.
  The `sd` at 0x137b4 stores 8 bytes to ?.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc018, including `ld` at 0x137f4, `ld` at 0x13894.
  2 such `ld` accesses load 8 bytes from [-0x3fe8]:8 +0x3f0, including `ld` at 0x137f8, `ld` at 0x13898.
  The `sd` at 0x1381c stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `ld` at 0x1382c loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `sd` at 0x13834 stores 8 bytes to [a0]:8 +0x8.
  The `ld` at 0x13840 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `sd` at 0x1384c stores 8 bytes to [a0]:8 +0x10.
  The `sd` at 0x13858 stores 8 bytes to [a0]:8 +0x0.
  The `sd` at 0x138b4 stores 8 bytes to [a0]:8 +0x20.
  The `sd` at 0x138b8 stores 8 bytes to [a0]:8 +0x18.
  The `ld` at 0x138c0 loads 8 bytes from ?.
  The `jal` at 0x13818 calls __dcache_wb_inval with a0=?, a1=0x80, a2=?, a3=?, a6=0xffffff.
  The `jal` at 0x13824 calls __prefetch_load with a0=?, a1=0x80, a2=?, a3=?.
  The `jal` at 0x138d0 calls us_delay with a0=0x1, a1=?, a2=-0x1, a3=?.
  The `bne` branch at 0x137b8 targets 0x137cc, is taken when s0(?) < a5(=0xa800000000000000) (unsigned), and falls through when s0(?) >= a5(=0xa800000000000000) (unsigned).
  The `bne` branch at 0x137c8 targets 0x137ec, is taken when s0(?) < t8(=0xa800010000000000) (unsigned), and falls through when s0(?) >= t8(=0xa800010000000000) (unsigned).
  The `bne` branch at 0x137dc targets 0x137f4, is taken when a2(?) < a1(=0x9000000000000000) (unsigned), and falls through when a2(?) >= a1(=0x9000000000000000) (unsigned).
  The `beq` branch at 0x137e4 targets 0x137f4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x137ec targets 0x1380c and is always taken.
  The `beq` branch at 0x13854 targets 0x13868, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `bne` branch at 0x13864 targets 0x13888, is taken when s0(?) < t1(=0xa800010000000000) (unsigned), and falls through when s0(?) >= t1(=0xa800010000000000) (unsigned).
  The `bne` branch at 0x13878 targets 0x13894, is taken when a2(?) < a5(=0x9000000000000000) (unsigned), and falls through when a2(?) >= a5(=0x9000000000000000) (unsigned).
  The `beq` branch at 0x13880 targets 0x13894, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1388c targets 0x138b4 and is always taken.
  The `bne` branch at 0x138c8 targets 0x138e8, is taken when a2(=-0x1) != a3(?), and falls through when a2(=-0x1) == a3(?).
  The `bne` branch at 0x138e0 targets 0x138c0, is taken when s1(?) < 0xa (signed), and falls through when s1(?) >= 0xa (signed).
  The return at 0x138fc has v0 = one of ?, ret(us_delay).

- `bte_notification_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13904 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x13904-0x13a5c (344 bytes).
  It occupies 344 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x60, including `ld` at 0x13920, `ld` at 0x1398c, `ld` at 0x139b4.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x0, including `ld` at 0x1393c, `ld` at 0x13a58.
  The `ld` at 0x13940 loads 8 bytes from [a0]:8 +0x18.
  The `ld` at 0x13950 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `ld` at 0x13958 loads 8 bytes from ?.
  The `lw` at 0x13984 loads 4 bytes from a0 (arg0 at entry) +0x54.
  The `lw` at 0x13990 loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `sw` at 0x13998 stores 4 bytes to a0 (arg0 at entry) +0x50.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x139e4, `lw` at 0x13a18.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x139f8, `sw` at 0x13a2c.
  The `jal` at 0x1391c calls nested_spintrylock with a0=[a0+96]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1392c calls bte_get_all_interfaces with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x13964 calls bte_oneline_xfer [0x13754] with a0=?, a1=[a0+104]:8, a2=?, a3=?.
  The `jal` at 0x13980 calls bte_free_interfaces with a0=a0 at entry (arg0), a1=[a0+84], a2=?, a3=?.
  The `jal` at 0x13988 calls nested_spinunlock with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x139b0 calls nested_spintrylock with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x139c0 calls nested_spintrylock with a0=a0+68, a1=?, a2=?, a3=?.
  The `jal` at 0x139d0 calls nested_spinunlock with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x139e0 calls splx with a0=[a1], a1=?, a2=?, a3=?.
  The `jal` at 0x139e8 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x139f0 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x139fc calls nested_spintrylock with a0=a0+68, a1=?, a2=?, a3=?.
  The `jal` at 0x13a14 calls splx with a0=[a1], a1=?, a2=?, a3=?.
  The `jal` at 0x13a1c calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x13a24 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13a30 calls nested_spintrylock with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x13a4c calls cmn_err with a0=0xc, a1=sym(.rodata)+12296, a2=?, a3=?.
  The `beq` branch at 0x13924 targets 0x139b0, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `bne` branch at 0x13934 targets 0x13a48, is taken when v0(=ret(bte_get_all_interfaces)) != 0, and falls through when v0(=ret(bte_get_all_interfaces)) == 0.
  The `beq` branch at 0x1395c targets 0x1396c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x13974 targets 0x13950, is taken when s1(?) < 0x2 (signed), and falls through when s1(?) >= 0x2 (signed).
  The `beq` branch at 0x139b8 targets 0x13a14, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x139c8 targets 0x139e0, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x139d8 targets 0x139a0 and is always taken.
  The `beq` branch at 0x13a04 targets 0x139e0, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x13a0c targets 0x139d0 and is always taken.
  The `beq` branch at 0x13a38 targets 0x13a14, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x13a40 targets 0x139c0 and is always taken.
  The `beq` branch at 0x13a54 targets 0x13940 and is always taken.
  The return at 0x139a8 has v0 = ret(nested_spinunlock).

- `bte_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13a5c
  **Inferred.** The routine reads the global disable_bte at entry (0x13a74) and calls splhi at 0x13b00, tests the interface bit lock with bitlock_islocked at 0x13b9c, and takes and releases nested spinlocks with nested_spintrylock at 0x13bc0 and nested_spinunlock at 0x13be4 and 0x13d08. It restores interrupts with splx at 0x13b58 and 0x13c0c. About 20 further calls are not listed here. The lock handling is clear from the calls, but the transfer sequence itself is not derived from these facts.
  Reviewed: 2026-11-12

- `bte_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13a5c
  **Inferred.** Role (from name): the block transfer engine copy. It tests the global `disable_bte` at 0x13aa0, calls `splhi` at 0x13b00, tests a bit lock with `bitlock_islocked` at 0x13b9c and takes a lock with `nested_spintrylock` at 0x13bc0. Later calls include `nested_spinunlock`, `splx`, `bte_error_handler`, `poison_state_clear`, `bte_notification_war` and `cmn_err`. It reads the fixed address 0x9200000001030100. The transfer programming is too long to settle from these facts.
  Reviewed: 2026-11-12

- `bte_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13a5c
  **Inferred.** A 1532-byte block-transfer copy. The branch at 0x13aa0 is taken when `disable_bte` is zero [@0x13aa0 taken zero]. It calls `splhi` [call 1, @0x13ac8 taken] when `a2` is nonzero [@0x13ab8 fall nonzero] and not above 0x7fff80. It tries a nested spin lock with `nested_spintrylock` [call 5] and releases one with `nested_spinunlock` [call 6], then restores the level with `splx` [call 7]. It also calls `bte_error_handler` [call 13] and `poison_state_clear` [call 14]. Role (from name): the block-transfer copy. The facts do not show the source or destination.
  Reviewed: 2026-11-12

- `bte_acquire_buffer` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14058 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x14058-0x141bc (356 bytes).
  It occupies 356 bytes.
  The `lh` at 0x1408c loads 2 bytes from table(sym(nasid_to_compact_node)) +0x0.
  The `lbu` at 0x140d4 loads 1 byte from ((entry(sym(nasid_to_compact_node)) + entry(sym(nasid_to_compact_node))) + sym(.bss)+15920) +0x400.
  The `lbu` at 0x140f0 loads 1 byte from ?.
  The `ld` at 0x1410c loads 8 bytes from ?.
  The `ld` at 0x14184 loads 8 bytes from table(sym(.bss)+15920) +0x0.
  The `sb` at 0x141a0 stores 1 byte to ?.
  The `ld` at 0x141a8 loads 8 bytes from (sym(.bss)+15920 + ((entry(sym(nasid_to_compact_node)) + entry(sym(nasid_to_compact_node))) << 0x3)) +0x0.
  The `jal` at 0x140cc calls mutex_spinlock with a0=((entry(sym(nasid_to_compact_node)) << 0x2) + sym(.bss)+15920)+1152, a1=?, a2=?, a3=?.
  The `jal` at 0x1411c calls mutex_spinunlock with a0=((entry(sym(nasid_to_compact_node)) << 0x2) + sym(.bss)+15920)+1152, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `beq` branch at 0x140dc targets 0x141a4, is taken when t8(=[((entry(sym(nasid_to_compact_node)) + entry(sym(nasid_to_compact_node))) + sym(.bss)+15920)+1024]:1) == 0, and falls through when t8(=[((entry(sym(nasid_to_compact_node)) + entry(sym(nasid_to_compact_node))) + sym(.bss)+15920)+1024]:1) != 0.
  The `beq` branch at 0x140e4 targets 0x140fc and is always taken.
  The `beq` branch at 0x140f4 targets 0x14180, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x14114 targets 0x140ec, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `beq` branch at 0x14124 targets 0x14170, is taken when s7(=a1) == 0, and falls through when s7(=a1) != 0.
  The `bne` branch at 0x14130 targets 0x14170, is taken when s0(?) != at(=0x2), and falls through when s0(?) == at(=0x2).
  The `bne` branch at 0x14138 targets 0x140cc, is taken when s1(=one of 0x0, 0x1) != 0, and falls through when s1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x14170 targets 0x14140, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x14178 targets 0x14140 and is always taken.
  The `beq` branch at 0x14188 targets 0x140fc, is taken when v1(=entry(sym(.bss)+15920)) == 0, and falls through when v1(=entry(sym(.bss)+15920)) != 0.
  The `beq` branch at 0x14190 targets 0x1411c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x1419c targets 0x1411c and is always taken.
  The `beq` branch at 0x141ac targets 0x140e4, is taken when a2(=[(sym(.bss)+15920 + ((entry(sym(nasid_to_compact_node)) + entry(sym(nasid_to_compact_node))) << 0x3))]:8) == 0, and falls through when a2(=[(sym(.bss)+15920 + ((entry(sym(nasid_to_compact_node)) + entry(sym(nasid_to_compact_node))) << 0x3))]:8) != 0.
  The `beq` branch at 0x141b4 targets 0x14198 and is always taken.
  The return at 0x14164 has v0 = one of -0x1, ?.
  The instructions from 0x1416c to 0x1416c are not reached by any path from the entry, and their branches are not listed.

- `bte_release_buffer` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x141bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x141bc-0x14218 (92 bytes).
  It occupies 92 bytes.
  The `sb` at 0x14204 stores 1 byte to (a0 + sym(.bss)+15920) +0x400.
  The `jal` at 0x141e8 calls mutex_spinlock with a0=table(sym(.bss)+15920)+1152, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14200 calls mutex_spinunlock with a0=table(sym(.bss)+15920)+1152, a1=ret(mutex_spinlock), a2=(a0 + sym(.bss)+15920), a3=?.
  The return at 0x14210 has v0 = ret(mutex_spinunlock).

- `bte_pull` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14218 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x14218-0x144a0 (648 bytes).
  It occupies 648 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc018, including `ld` at 0x142d0, `ld` at 0x1446c.
  2 such `ld` accesses load 8 bytes from [-0x3fe8]:8 +0x3f0, including `ld` at 0x142d4, `ld` at 0x14470.
  The `ld` at 0x14414 loads 8 bytes from (sym(.bss)+15920 + (ret(bte_acquire_buffer) << 0x3)) +0x0.
  The `jal` at 0x14330 calls bte_copy with a0=?, a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x143a8 calls bcopy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x143d4 calls bte_release_buffer [0x141bc] with a0=?, a1=?, a2=?, a3=?, a6=-0x1.
  The `jal` at 0x143e8 calls bte_acquire_buffer [0x14058] with a0=a1 at entry (arg1), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x9000000000000000, a7=0xa800010000000000.
  The `bne` branch at 0x14274 targets 0x14280, is taken when a2 < 0x401 (unsigned), and falls through when a2 >= 0x401 (unsigned).
  The `beq` branch at 0x1427c targets 0x143e4, is taken when v0(=[sym(.sdata)+196]:1) == 0, and falls through when v0(=[sym(.sdata)+196]:1) != 0.
  The `bne` branch at 0x142a4 targets 0x142b4, is taken when a3(?) < a1(=0xa800000000000000) (unsigned), and falls through when a3(?) >= a1(=0xa800000000000000) (unsigned).
  The `bne` branch at 0x142ac targets 0x142c4, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x142b4 targets 0x142d0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x142bc targets 0x142d0, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x142c4 targets 0x142f0 and is always taken.
  The `beq` branch at 0x14310 targets 0x143c8, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x14338 targets 0x14370, is taken when v0(=ret(bte_copy)) == 0, and falls through when v0(=ret(bte_copy)) != 0.
  The `bne` branch at 0x143c0 targets 0x14318, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x143cc targets 0x143dc, is taken when s6(?) == a6(=-0x1), and falls through when s6(?) != a6(=-0x1).
  The `beq` branch at 0x143dc targets 0x14340 and is always taken.
  The `beq` branch at 0x14404 targets 0x14418, is taken when v0(=ret(bte_acquire_buffer)) == a2(=-0x1), and falls through when v0(=ret(bte_acquire_buffer)) != a2(=-0x1).
  The `beq` branch at 0x14410 targets 0x142f8 and is always taken.
  The `bne` branch at 0x1442c targets 0x1443c, is taken when a0(?) < a1(=0xa800000000000000) (unsigned), and falls through when a0(?) >= a1(=0xa800000000000000) (unsigned).
  The `bne` branch at 0x14438 targets 0x14460, is taken when a0(?) < a2(=0xa800010000000000) (unsigned), and falls through when a0(?) >= a2(=0xa800010000000000) (unsigned).
  The `bne` branch at 0x14450 targets 0x1446c, is taken when a2(?) < a3(=0x9000000000000000) (unsigned), and falls through when a2(?) >= a3(=0x9000000000000000) (unsigned).
  The `beq` branch at 0x1445c targets 0x1446c, is taken when a2(?) >= a3(=0x9000010000000000) (unsigned), and falls through when a2(?) < a3(=0x9000010000000000) (unsigned).
  The `beq` branch at 0x14464 targets 0x14490 and is always taken.
  The `beq` branch at 0x14498 targets 0x142f8 and is always taken.
  The return at 0x14368 has v0 = one of ret(bte_copy), 0x0.
  The instructions from 0x142cc to 0x142cc are not reached by any path from the entry, and their branches are not listed.

- `bte_unaligned_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x144a0
  **Inferred.** Role (from name): a block copy that chooses between the BTE path and plain `bcopy`. It reads the `disable_bte` and `maxcpus` globals (0x144cc, 0x144dc), calls `bte_pull` (0x1452c, 0x14560, 0x145fc) and `bte_copy` (0x14650, 0x146a4), and calls `bcopy` (0x145ac, 0x1461c, 0x1467c). It compares `a2` against 0x80 (0x14664) and a value against 0x7fff80 (0x14640); the other operand of the 0x7fff80 compare is not resolved. Which pieces count as unaligned, and what the 0x7fff80 limit means, are not settled by these facts.
  Reviewed: 2026-11-12

- `bte_unaligned_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x144a0
  **Inferred.** A 596-byte copy for transfers that are not aligned. When `disable_bte` is zero the branch at 0x144cc goes to the BTE path at 0x144e4 [@0x144cc taken zero]. The routine calls `bte_pull` [call 1], `bcopy` [call 3] and `bte_copy` [call 6]. Role (from name): an unaligned copy built from BTE and `bcopy` calls. The facts do not show the alignment rule.
  Reviewed: 2026-11-12

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** A wrapper around `bte_copy` (0x14708) that passes the fixed value 0x110 as its fourth argument. A non-zero result from `bte_copy` branches to the `cmn_err` report at 0x14738 with level 0xc and the copy result as an argument. The meaning of 0x110 is not established.
  Reviewed: 2026-11-12

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** When `a2` is nonzero it calls `bte_copy` at 0x14708 with its own first three arguments and the constant 0x110 as the fourth; a zero `a2` branches at 0x14700 to 0x1471c. A nonzero `bte_copy` result branches at 0x14710 to 0x1472c, and `cmn_err` at 0x14738 (level 0xc) takes that result as an argument. It returns 0 or the `bte_copy` result at 0x14724. The meaning of the 0x110 mode value is not identified.
  Reviewed: 2026-11-12

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** Returns 0 without copying when a2 is zero (0x14700). Otherwise it calls bte_copy at 0x14708 with a0, a1 and a2 passed through and the constant 0x110 as the fourth argument. A nonzero result (0x14710) is reported through cmn_err at 0x14738 with the constant 0xc and the result. The return value is 0 or the bte_copy result. The meaning of the constant 0x110 is unknown.
  Reviewed: 2026-11-12

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** An 84-byte wrapper. When `a2` is nonzero, the branch at 0x14700 falls through [@0x14700 fall nonzero] to a call of `bte_copy` with 0x110 in a3 [call 1, @0x14700 fall]. The return at 0x14724 yields 0 or the copy result [@0x14724]. Role (from name): a poison-aware copy wrapper. The facts do not show what the poison flag does.
  Reviewed: 2026-11-12

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** Works over a range by calling `poison_state_alter_range` (0x14798, 0x14840) and `bte_copy` (0x147e8, passing the constants 0x110 in `a3` and 0x4000 in `a4`). The globals `disable_bte_poison_range` and `disable_bte` are tested before the copy path (0x14768, 0x14778). The branch at 0x147fc goes back to the test at 0x147b8 when `bte_copy` returns zero, so the call sits in a loop that continues on a zero result, and a non-zero result leaves the loop. What the poison state is, and the meaning of 0x110 and 0x4000, are not established.
  Reviewed: 2026-11-12

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** A branch at 0x14758 on a1 == 0 goes to 0x14824; the facts do not show that target as a return. Otherwise the routine branches on the symbols disable_bte_poison_range and disable_bte and on maxcpus (0x14768, 0x14778, 0x14784). On the path through 0x14798 it calls poison_state_alter_range with a0 OR'd with 0xa800000000000000 and a2 = 0x1, and calls bte_copy at 0x147e8 with a1 = 0x0, a3 = 0x110 and a4 = 0x4000. A second call to poison_state_alter_range at 0x14840 has a2 = 0x1; which path reaches it is not derived. The routine returns 0 or the bte_copy result (0x1481c). The meaning of the 0xa8 tag and the copy's purpose are not in the facts.
  Reviewed: 2026-11-12

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** A 272-byte routine. When `a1` is zero the branch at 0x14758 goes to the return [@0x14758 taken zero] at 0x1481c [@0x1481c]. One path calls `poison_state_alter_range` with a2 = 1 [call 1] and returns. The other path calls `bte_copy` with `a3` = 0x110 and `a4` = 0x4000 [call 2], again while the result is zero [@0x147fc taken zero]. When the copy result equals 1 [@0x14808 taken] it calls `poison_state_alter_range` with a2 = 1 [call 3]. Role (from name): a poison-state update over a range. The facts do not show what the range arguments select.
  Reviewed: 2026-11-12

- `bte_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14858
  **Inferred.** Role (from name): disables use of the BTE. The rendered facts show only a return at 0x1485c, with no call, load or store visible in them, and the return value is not computed from anything in the facts. The facts are too thin to say whether the routine is a stub, and which disable it performs is not established.
  Reviewed: 2026-11-12

- `bte_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14858
  **Inferred.** A 12-byte routine whose return at 0x1485c yields a value the facts do not resolve [@0x1485c]. The facts list omits the store in the delay slot of that return [@0x1485c]: the disassembly shows a `sw` at 0x14860 that writes the constant 1 to the word `disable_bte`, the word that `bte_copy` and `bte_pbzero` test, so the routine sets that flag. Role (from name): disables the block-transfer engine.
  Reviewed: 2026-11-12

- `bte_wait_for_xfer_completion` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14864
  **Inferred.** A bounded poll of a BTE control record passed in `a0`. It reads the 8-byte word at `a0` and the 8-byte word that one points to (0x14868, 0x14870), tests the low 16 bits of the latter for zero (0x1487c, 0x1488c), and reads the hub register at 0x9200000001030100 twice (0x1486c, 0x14898). The first value plus 500 is compared with the second read, and the loop branches back to the zero test (0x148a0 to 0x1488c) while that sum is at least the second read (unsigned). The timeout report at 0x148c8 passes 0x1f4 (500) to `cmn_err` at level 0x14. The exact completion bit and what the register counts are not established.
  Reviewed: 2026-11-12

- `bte_wait_for_xfer_completion` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14864
  **Inferred.** The routine loads a pointer from a0 and then the 16-bit field at the low end of the word it points to, branching on whether that field is zero (beq at 0x1487c). It spins in a loop (beq at 0x148a0 back to 0x1488c) whose bound is read from the global block at 0x9200000001030100, using the constant 500 (0x1f4) as an offset. On exhaustion it reports through cmn_err at 0x148c8 with level 0x14 and the constant 0x1f4. The name suggests a transfer wait; which field is polled is inferred from the load shape alone.
  Reviewed: 2026-11-12

- `router_map_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15060 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x15060-0x1520c (428 bytes).
  It occupies 428 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5138, including `sw` at 0x1507c, `sw` at 0x15184.
  The `lh` at 0x150e8 loads 2 bytes from ?.
  The `ld` at 0x150f8 loads 8 bytes from ?.
  The `lw` at 0x15104 loads 4 bytes from ?.
  2 such `lbu` accesses load 1 byte from ret(find_lboard_class) +0x9, including `lbu` at 0x15130, `lbu` at 0x1514c.
  The `lw` at 0x15168 loads 4 bytes from ret(find_lboard_class) +0x0.
  The `lw` at 0x1517c loads 4 bytes from a0 (arg0 at entry) +0x5138.
  The `lh` at 0x1518c loads 2 bytes from ret(find_lboard_class) +0xe.
  The `ld` at 0x15194 loads 8 bytes from (a0 + ([a0+20792]+1 << 0x3)) +0x4d30.
  3 such `sd` accesses store 8 bytes to (a0 + ([a0+20792]+1 << 0x3)) +0x4d30, including `sd` at 0x151a4, `sd` at 0x151b8, `sd` at 0x151cc.
  The `lbu` at 0x151a8 loads 1 byte from ret(find_lboard_class) +0xa.
  The `ld` at 0x151bc loads 8 bytes from ret(find_lboard_class) +0x18.
  The `lh` at 0x15208 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x1511c calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x1513c calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=ret(find_lboard_class).
  The `blez` branch at 0x1509c targets 0x151d0, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x150c0 targets 0x151fc and is always taken.
  The `beq` branch at 0x150e0 targets 0x151d0, is taken when s2(?) >= t8(=[sym(maxnodes)]) (signed), and falls through when s2(?) < t8(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x15110 targets 0x1511c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x15124 targets 0x150c8, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x1512c targets 0x15150 and is always taken.
  The `beq` branch at 0x15144 targets 0x150c8, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x15160 targets 0x1517c, is taken when (a1(=[ret(find_lboard_class)+9]:1) & 0x4) == 0, and falls through when (a1(=[ret(find_lboard_class)+9]:1) & 0x4) != 0.
  The `bne` branch at 0x1516c targets 0x15134, is taken when a4(=[ret(find_lboard_class)]) != 0, and falls through when a4(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x15174 targets 0x1513c and is always taken.
  The `beq` branch at 0x151c8 targets 0x15168 and is always taken.
  The `beq` branch at 0x15204 targets 0x150ec and is always taken.
  The return at 0x151f4 has v0 = one of ?, ret(find_lboard_class).

- `router_map_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1520c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1520c-0x1527c (112 bytes).
  It occupies 112 bytes.
  The `ld` at 0x1520c loads 8 bytes from abs 0xffffffffffffc400.
  The `lw` at 0x15210 loads 4 bytes from [-0x3c00]:8 +0x5138.
  2 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x0, including `sh` at 0x1521c, `sh` at 0x15264.
  2 such `sb` accesses store 1 byte to a2 (arg2 at entry) +0x0, including `sb` at 0x15220, `sb` at 0x15270.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1523c, `ld` at 0x15268.
  The `blez` branch at 0x15224 targets 0x15274, is taken when t0(=[[-0x3c00]:8+20792]) <= 0 (signed), and falls through when t0(=[[-0x3c00]:8+20792]) > 0 (signed).
  The `beq` branch at 0x15248 targets 0x15260, is taken when a0 == t3(?), and falls through when a0 != t3(?).
  The `bne` branch at 0x15250 targets 0x15238, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x15258 targets 0x15274 and is always taken.
  The return at 0x15274 has v0 = ?.

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c (20 bytes). Grade: inferred.
  It performs one doubleword load and returns a value in `v0` that the rendering leaves unresolved. No mask or compare appears in the facts. Role (from name): a link-state probe.
  Reviewed: 2026-11-12

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** Reads one 8-byte word at the fixed address 0x9200000001600000 (0x15410); the facts leave its return value unresolved. `check_ni_errors` reads the same address (0x19dec), which suggests a network-interface status register. The bit that means link up, and how the return value is derived from the word, are not established.
  Reviewed: 2026-11-12

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** The routine is a 20-byte leaf: one 8-byte load at 0x15410, then a return at 0x15418 whose v0 the facts do not tie to that load. It makes no call and no branch. The facts do not give the load's address. Role (from name): reading a link state; the facts show only a raw doubleword load, so the bit meaning is not derived.
  Reviewed: 2026-11-12

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** A 20-byte routine that loads one doubleword at the fixed address 0x9200000001600000 [@0x15410] and returns a value the facts do not resolve [@0x15418]. Role (from name): reports whether the network link is up. The facts do not show which bit of the loaded word means link up.
  Reviewed: 2026-11-12

- `router_queue_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15420 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x15420-0x154b4 (148 bytes).
  It occupies 148 bytes.
  The `sd` at 0x1544c stores 8 bytes to a0 (arg0 at entry) +0x4d28.
  The `sd` at 0x15468 stores 8 bytes to a0 (arg0 at entry) +0x4d30.
  The `jal` at 0x15440 calls kmem_zalloc_node with a0=0x1008, a1=0x1, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x15458 calls kmem_zalloc_node with a0=0x1008, a1=0x1, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x15488 calls assfail with a0=sym(.rodata)+12840, a1=sym(.rodata)+12840, a2=0x2da, a3=?.
  The `jal` at 0x154a4 calls assfail with a0=sym(.rodata)+12840, a1=sym(.rodata)+12840, a2=0x2de, a3=?.
  The `beq` branch at 0x15448 targets 0x1547c, is taken when v0(=ret(kmem_zalloc_node)) == 0, and falls through when v0(=ret(kmem_zalloc_node)) != 0.
  The `beq` branch at 0x15464 targets 0x15498, is taken when v0(=ret(kmem_zalloc_node)) == 0, and falls through when v0(=ret(kmem_zalloc_node)) != 0.
  The `beq` branch at 0x15490 targets 0x15454 and is always taken.
  The `beq` branch at 0x154ac targets 0x15470 and is always taken.
  The return at 0x15474 has v0 = one of ret(kmem_zalloc_node), ret(assfail).

- `router_link_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1558c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1558c-0x15618 (140 bytes).
  It occupies 140 bytes.
  The `jal` at 0x155c8 calls sprintf with a0=sp-64, a1=sym(.rodata)+12840, a2=?, a3=?.
  The `jal` at 0x155d8 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-64, a2=sp-48, a3=?.
  The `beq` branch at 0x155a8 targets 0x155bc and is always taken.
  The `beq` branch at 0x155b8 targets 0x155f8, is taken when s0(?) >= 0x7 (signed), and falls through when s0(?) < 0x7 (signed).
  The `bne` branch at 0x155e0 targets 0x155b0, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x155e8 targets 0x155b0, is taken when a2(?) != s2(=a1), and falls through when a2(?) == s2(=a1).
  The `beq` branch at 0x155f0 targets 0x15600 and is always taken.
  The return at 0x15610 has v0 = one of ?, 0x0.

- `router_guardian_search` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15618 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x15618-0x1588c (628 bytes).
  It occupies 628 bytes.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x15748, `lw` at 0x157e0, `lw` at 0x157e4.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x0, including `sd` at 0x15790, `sd` at 0x157f8, `sd` at 0x15848.
  The `ld` at 0x157c4 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x157c8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x157d8 loads 8 bytes from ?.
  The `jal` at 0x15668 calls kmem_alloc with a0=0x1008, a1=0x0, a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x15678 calls queue_init [0x148d8] with a0=ret(kmem_alloc), a1=0x2, a2=?, a3=?.
  The `jal` at 0x15688 calls kmem_alloc with a0=0x1008, a1=0x0, a2=?, a3=?.
  The `jal` at 0x15698 calls queue_init [0x148d8] with a0=ret(kmem_alloc), a1=0x2, a2=?, a3=?.
  The `jal` at 0x156b4 calls queue_push [0x14920] with a0=ret(kmem_alloc), a1=sp-184, a2=?, a3=-0x1.
  The `jal` at 0x156bc calls queue_empty [0x1490c] with a0=ret(kmem_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x156d4 calls kmem_free with a0=ret(kmem_alloc), a1=0x1008, a2=?, a3=?.
  The `jal` at 0x156e4 calls kmem_free with a0=ret(kmem_alloc), a1=0x1008, a2=?, a3=?.
  The `jal` at 0x15718 calls queue_pop [0x149a4] with a0=ret(kmem_alloc), a1=sp-184, a2=?, a3=?.
  The `jal` at 0x15724 calls queue_find [0x149f8] with a0=ret(kmem_alloc), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1574c calls sprintf with a0=sp-136, a1=sym(.rodata)+12840, a2=?, a3=?.
  The `jal` at 0x1575c calls hwgraph_traverse with a0=a1 at entry (arg1), a1=sp-136, a2=sp-120, a3=?.
  The `jal` at 0x15794 calls nodevertex_to_cnodeid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x157ac calls cnodetocpu with a0=?, a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0x15808 calls queue_push [0x14920] with a0=ret(kmem_alloc), a1=sp-184, a2=?, a3=?.
  The `jal` at 0x15810 calls queue_empty [0x1490c] with a0=ret(kmem_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1585c calls router_link_get with a0=?, a1=a1 at entry (arg1), a2=?, a3=?, a7=-0x1.
  The `jal` at 0x1586c calls vector_concat with a0=ret(router_link_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1587c calls queue_push [0x14920] with a0=ret(kmem_alloc), a1=sp-112, a2=?, a3=?.
  The `beq` branch at 0x156c4 targets 0x15704, is taken when v0(=ret(queue_empty)) == 0, and falls through when v0(=ret(queue_empty)) != 0.
  The `bne` branch at 0x1572c targets 0x15810, is taken when v0(=ret(queue_find)) != 0, and falls through when v0(=ret(queue_find)) == 0.
  The `beq` branch at 0x15764 targets 0x15794, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `bne` branch at 0x15774 targets 0x15738, is taken when s1(?) < 0x6 (signed), and falls through when s1(?) >= 0x6 (signed).
  The `beq` branch at 0x1577c targets 0x15808, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x1578c targets 0x156cc and is always taken.
  The `beq` branch at 0x157a0 targets 0x1584c, is taken when v0(=ret(nodevertex_to_cnodeid)) == a7(=-0x1), and falls through when v0(=ret(nodevertex_to_cnodeid)) != a7(=-0x1).
  The `beq` branch at 0x157b8 targets 0x1576c, is taken when v0(=ret(cnodetocpu)) == a1(=-0x1), and falls through when v0(=ret(cnodetocpu)) != a1(=-0x1).
  The `beq` branch at 0x157d4 targets 0x15828, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x157ec targets 0x15840, is taken when a4(?) >= a5(?) (signed), and falls through when a4(?) < a5(?) (signed).
  The `beq` branch at 0x15800 targets 0x156cc and is always taken.
  The `beq` branch at 0x15818 targets 0x15718, is taken when v0(=ret(queue_empty)) == 0, and falls through when v0(=ret(queue_empty)) != 0.
  The `beq` branch at 0x15820 targets 0x156cc and is always taken.
  The `beq` branch at 0x15838 targets 0x1576c and is always taken.
  The `beq` branch at 0x15844 targets 0x156cc and is always taken.
  The `beq` branch at 0x15864 targets 0x1576c, is taken when v0(=ret(router_link_get)) == 0, and falls through when v0(=ret(router_link_get)) != 0.
  The `beq` branch at 0x15884 targets 0x15770 and is always taken.
  The return at 0x156fc has v0 = ?.

- `router_guardian_set` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15958 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x15958-0x15a28 (208 bytes).
  It occupies 208 bytes.
  The `lbu` at 0x15960 loads 1 byte from a1 (arg1 at entry) +0x9.
  The `lbu` at 0x159bc loads 1 byte from a1 (arg1 at entry) +0x17.
  The `jal` at 0x15980 calls board_to_path with a0=a1 at entry (arg1), a1=sp-88, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1599c calls board_to_path with a0=a1 at entry (arg1), a1=sp-88, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x159ac calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-88, a2=sp-32, a3=?.
  The `jal` at 0x159d0 calls router_guardian_search [0x15618] with a0=sp-96, a1=?, a2=[a1+23]:1, a3=?.
  The `jal` at 0x159ec calls guardian_nodepda_update [0x1588c] with a0=ret(router_guardian_search), a1=?, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x15a04 calls cmn_err with a0=0x4, a1=sym(.rodata)+12840, a2=sp-88, a3=?.
  The `jal` at 0x15a18 calls cmn_err with a0=0x0, a1=sym(.rodata)+12840, a2=[a1+23]:1, a3=?.
  The `beq` branch at 0x15974 targets 0x15998, is taken when (at(=[a1+9]:1) & 0x4) == 0, and falls through when (at(=[a1+9]:1) & 0x4) != 0.
  The `bne` branch at 0x159b4 targets 0x159fc, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x159c4 targets 0x15a14, is taken when a2(=[a1+23]:1) != v0(=0x1), and falls through when a2(=[a1+23]:1) == v0(=0x1).
  The `beq` branch at 0x159dc targets 0x15988, is taken when v0(=ret(router_guardian_search)) == v1(=-0x1), and falls through when v0(=ret(router_guardian_search)) != v1(=-0x1).
  The `beq` branch at 0x159f4 targets 0x1598c and is always taken.
  The `beq` branch at 0x15a0c targets 0x1598c and is always taken.
  The `beq` branch at 0x15a20 targets 0x1598c and is always taken.
  The return at 0x15990 has v0 = one of ?, ret(guardian_nodepda_update), ret(cmn_err).

- `router_guardians_set` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15a28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x15a28-0x15b58 (304 bytes).
  It occupies 304 bytes.
  The `lh` at 0x15a90 loads 2 bytes from ?.
  The `ld` at 0x15aa0 loads 8 bytes from ?.
  The `lw` at 0x15aac loads 4 bytes from ?.
  The `lw` at 0x15b00 loads 4 bytes from ret(find_lboard_class) +0x0.
  The `lh` at 0x15b54 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x15ac4 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x15ae4 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x15af8 calls router_guardian_set [0x15958] with a0=a0 at entry (arg0), a1=ret(find_lboard_class), a2=?, a3=?.
  The `blez` branch at 0x15a58 targets 0x15b24, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x15a68 targets 0x15b48 and is always taken.
  The `beq` branch at 0x15a88 targets 0x15b24, is taken when s4(?) >= t8(=[sym(maxnodes)]) (signed), and falls through when s4(?) < t8(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x15ab8 targets 0x15ac4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x15acc targets 0x15a70, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x15ad4 targets 0x15af8 and is always taken.
  The `beq` branch at 0x15aec targets 0x15a70, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `bne` branch at 0x15b14 targets 0x15adc, is taken when a1(=[ret(find_lboard_class)]) != 0, and falls through when a1(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x15b1c targets 0x15ae4 and is always taken.
  The `beq` branch at 0x15b50 targets 0x15a94 and is always taken.
  The return at 0x15b40 has v0 = one of ?, ret(find_lboard_class).

- `kl_perr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15b58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x15b58-0x15de4 (652 bytes).
  It occupies 652 bytes.
  The `sb` at 0x15bf8 stores 1 byte to table(sym(err_buf)) +0x4038.
  The `sb` at 0x15c08 stores 1 byte to table(sym(err_buf)) +0x4039.
  7 such `sb` accesses store 1 byte to ?, including `sb` at 0x15c20, `sb` at 0x15c34, `sb` at 0x15c48.
  The `sd` at 0x15cc8 stores 8 bytes to table(sym(err_buf)) +0x4008.
  3 such `lw` accesses load 4 bytes from sym(nasid_to_compact_node) +0x43b0, including `lw` at 0x15cf0, `lw` at 0x15d30, `lw` at 0x15d40.
  The `sw` at 0x15cf8 stores 4 bytes to sym(nasid_to_compact_node) +0x43b0.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x15d3c, `sd` at 0x15d94, `sd` at 0x15db8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x15d78, `ld` at 0x15d9c.
  The `jal` at 0x15b98 calls vsprintf with a0=sym(err_buf), a1=a1 at entry (arg1), a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x15c58 calls strlen with a0=table(sym(err_buf))+16440, a1=table(sym(err_buf)), a2=?, a3=?, a5=0x20.
  The `jal` at 0x15c64 calls strlen with a0=sym(err_buf), a1=?, a2=?, a3=?.
  The `jal` at 0x15c7c calls strlen with a0=sym(err_buf), a1=?, a2=?, a3=?.
  The `jal` at 0x15c8c calls strlen with a0=table(sym(err_buf))+16440, a1=?, a2=?, a3=?.
  The `jal` at 0x15ca8 calls strncpy with a0=?, a1=sym(err_buf), a2=?, a3=?.
  The `jal` at 0x15ce8 calls bcopy with a0=?, a1=([sym(err_buf)] + sym(err_buf))+4, a2=?, a3=?.
  The `jal` at 0x15d20 calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x15bac targets 0x15bb8, is taken when (s2(=a0) & 0x10) == 0, and falls through when (s2(=a0) & 0x10) != 0.
  The `beq` branch at 0x15bd4 targets 0x15be0, is taken when (s2(?) & 0x20) == 0, and falls through when (s2(?) & 0x20) != 0.
  The `beq` branch at 0x15c00 targets 0x15c54, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0x15c0c targets 0x15c54, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `beq` branch at 0x15c28 targets 0x15c54, is taken when v0(?) >= a2(?) (signed), and falls through when v0(?) < a2(?) (signed).
  The `beq` branch at 0x15c3c targets 0x15c54, is taken when v0(?) >= a2(?) (signed), and falls through when v0(?) < a2(?) (signed).
  The `bne` branch at 0x15c4c targets 0x15c18, is taken when v0(?) < a2(?) (signed), and falls through when v0(?) >= a2(?) (signed).
  The `beq` branch at 0x15c74 targets 0x15c8c, is taken when a7(=(ret(strlen) + ret(strlen))) >= 0xff (unsigned), and falls through when a7(=(ret(strlen) + ret(strlen))) < 0xff (unsigned).
  The `beq` branch at 0x15c84 targets 0x15c9c and is always taken.
  The `beq` branch at 0x15cc4 targets 0x15dbc, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bltz` branch at 0x15ccc targets 0x15d64, is taken when s2(?) < 0 (signed), and falls through when s2(?) >= 0 (signed).
  The `beq` branch at 0x15cd4 targets 0x15d10 and is always taken.
  The `bne` branch at 0x15d08 targets 0x15d60, is taken when s2(?) < s0(?) (signed), and falls through when s2(?) >= s0(?) (signed).
  The `beq` branch at 0x15d2c targets 0x15d00, is taken when s3(=(ret(strlen) << 0x0)) == 0, and falls through when s3(=(ret(strlen) << 0x0)) != 0.
  The `bne` branch at 0x15d4c targets 0x15cdc, is taken when t8(=((ret(strlen) << 0x0) + [sym(err_buf)])) < 0x3fff (signed), and falls through when t8(=((ret(strlen) << 0x0) + [sym(err_buf)])) >= 0x3fff (signed).
  The `beq` branch at 0x15d58 targets 0x15cdc and is always taken.
  The `bne` branch at 0x15d64 targets 0x15dbc, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x15d84 targets 0x15d90, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x15da0 targets 0x15dbc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x15da8 targets 0x15db4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x15db4 targets 0x15d70, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The return at 0x15ddc has v0 = one of ret(strncpy), 0x0, ?.

- `kl_perr_dumpbuf` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15de4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x15de4-0x15edc (248 bytes).
  It occupies 248 bytes.
  2 such `lbu` accesses load 1 byte from sym(nasid_to_compact_node) +0x43b4, including `lbu` at 0x15e00, `lbu` at 0x15e20.
  2 such `lw` accesses load 4 bytes from sym(nasid_to_compact_node) +0x43b0, including `lw` at 0x15e24, `lw` at 0x15e74.
  4 such `lbu` accesses load 1 byte from sym(nasid_to_compact_node) +0x43b0, including `lbu` at 0x15e38, `lbu` at 0x15e44, `lbu` at 0x15e50.
  2 such `sb` accesses store 1 byte to sym(nasid_to_compact_node) +0x43b0, including `sb` at 0x15e5c, `sb` at 0x15e70.
  The `sw` at 0x15ecc stores 4 bytes to sym(nasid_to_compact_node) +0x43b0.
  The `jalr` at 0x15e60 calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(err_buf), a2=?, a3=?.
  The `jalr` at 0x15ea4 calls (unknown callee) with a0=sym(err_buf), a1=sym(err_buf), a2=0x21, a3=?.
  The `beq` branch at 0x15e1c targets 0x15eb4, is taken when at(=[sym(err_buf+4)]:1) == 0, and falls through when at(=[sym(err_buf+4)]:1) != 0.
  The `bgtz` branch at 0x15e28 targets 0x15e8c, is taken when v0(=[sym(err_buf)]) > 0 (signed), and falls through when v0(=[sym(err_buf)]) <= 0 (signed).
  The `beq` branch at 0x15e30 targets 0x15eb8 and is always taken.
  The `beq` branch at 0x15e3c targets 0x15e58, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x15e48 targets 0x15e38, is taken when s1(=0xa) != v1(=[sym(err_buf)]:1), and falls through when s1(=0xa) == v1(=[sym(err_buf)]:1).
  The `beq` branch at 0x15e58 targets 0x15e94, is taken when s2(=a1) == 0, and falls through when s2(=a1) != 0.
  The `beq` branch at 0x15e6c targets 0x15eb4, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x15e84 targets 0x15eb4, is taken when s0(=sym(err_buf)) >= a0(=([sym(err_buf)] + sym(err_buf))+4) (unsigned), and falls through when s0(=sym(err_buf)) < a0(=([sym(err_buf)] + sym(err_buf))+4) (unsigned).
  The `beq` branch at 0x15e8c targets 0x15e3c and is always taken.
  The `beq` branch at 0x15e9c targets 0x15e6c, is taken when a2(=0x21) == a3(=[sym(err_buf)]:1), and falls through when a2(=0x21) != a3(=[sym(err_buf)]:1).
  The `beq` branch at 0x15eac targets 0x15e6c and is always taken.
  The return at 0x15ed4 has v0 = one of [sym(err_buf)], ?.

- `save_cache_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15f60 (360 bytes). Grade: inferred.
  It calls `get_nasid`, loads a doubleword at +0x48 from an unresolved base, and has two loops with back branches at 0x16000 and 0x16064 that read bytes and words. One compare tests a loaded byte against the doubleword at 0x9200000001000020. It stores three doublewords, a word and a byte at 0x1609c to 0x160b0 into targets the rendering cannot resolve. Role (from name): recording cache error state into a save area; the table base and destination addresses are open.
  Reviewed: 2026-11-12

- `save_cache_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15f60
  **Inferred.** A 360-byte routine that calls `get_nasid` [call 1] and reads the doubleword at the fixed address 0x9200000001000020 [@0x1606c]. It stores doublewords into a record with `sd` at 0x1609c, 0x160a0 and 0x160b0 [@0x1609c]. The branch at 0x16064 goes back to 0x16040 while its condition holds [@0x16064 taken]. Role (from name): saves cache error state. The facts do not show what the records hold.
  Reviewed: 2026-11-12

- `kl_save_hw_state_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x160c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x160c8-0x162a8 (480 bytes).
  It occupies 480 bytes.
  The `ld` at 0x1610c loads 8 bytes from ?.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1611c, `lw` at 0x16178, `lw` at 0x16194.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x16150, `lbu` at 0x16168, `lbu` at 0x161b4.
  The `jal` at 0x16248 calls save_err_node_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x30, a7=0x40.
  The `jal` at 0x1625c calls save_err_io_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x30, a7=0x40.
  The `jal` at 0x1626c calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16284 calls save_err_router_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x30, a7=0x40.
  The `jal` at 0x16298 calls save_err_xbow_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x30, a7=0x40.
  The `beq` branch at 0x160ec targets 0x1626c, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x16124 targets 0x16238, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x16130 targets 0x16210, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x16138 targets 0x16150 and is always taken.
  The `beq` branch at 0x16148 targets 0x16210, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x16160 targets 0x16194, is taken when (t8(?) & 0x1) == 0, and falls through when (t8(?) & 0x1) != 0.
  The `beq` branch at 0x16170 targets 0x161b4, is taken when (t9(?) & 0x4) == 0, and falls through when (t9(?) & 0x4) != 0.
  The `bne` branch at 0x16184 targets 0x16140, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x1618c targets 0x16144 and is always taken.
  The `beq` branch at 0x1619c targets 0x161ac, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x161ac targets 0x16148 and is always taken.
  The `beq` branch at 0x161c4 targets 0x16240, is taken when a4(?) == a2(=0x10), and falls through when a4(?) != a2(=0x10).
  The `beq` branch at 0x161cc targets 0x16258, is taken when a4(?) == a5(=0x20), and falls through when a4(?) != a5(=0x20).
  The `beq` branch at 0x161d4 targets 0x16280, is taken when a4(?) == a6(=0x30), and falls through when a4(?) != a6(=0x30).
  The `beq` branch at 0x161dc targets 0x16294, is taken when a4(?) == a7(=0x40), and falls through when a4(?) != a7(=0x40).
  The `beq` branch at 0x161f8 targets 0x16230, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x16208 targets 0x16148 and is always taken.
  The `beq` branch at 0x16230 targets 0x16208 and is always taken.
  The `beq` branch at 0x16238 targets 0x16130 and is always taken.
  The `beq` branch at 0x16250 targets 0x161e8 and is always taken.
  The `beq` branch at 0x16264 targets 0x161e8 and is always taken.
  The `beq` branch at 0x16278 targets 0x160f4 and is always taken.
  The `beq` branch at 0x1628c targets 0x161e8 and is always taken.
  The `beq` branch at 0x162a0 targets 0x161e8 and is always taken.
  The return at 0x16228 has v0 = ?.

- `kl_save_hw_state_all` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x162a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x162a8-0x16310 (104 bytes).
  It occupies 104 bytes.
  The `lh` at 0x162e0 loads 2 bytes from ?.
  The `jal` at 0x162dc calls kl_save_hw_state_node with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `blez` branch at 0x162c4 targets 0x162f8, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x162f0 targets 0x162d4, is taken when s0(?) < a1(=[sym(numnodes)]) (signed), and falls through when s0(?) >= a1(=[sym(numnodes)]) (signed).
  The return at 0x16308 has v0 = one of ?, ret(kl_save_hw_state_node).

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** Moves fields inside the error record passed in `a0`. It loads a flag byte at +0x38 and, when that is zero, returns at once (0x16318 to 0x16358) with no store. Otherwise it loads two words (0x16324, 0x16328) and compares a value against 0x55d4a80 (0x16334). When that value is below the bound it stores a byte at +0x39 (0x1633c), loads the words at +0x18, +0x10 and +0x8, and stores to +0x20, +0x28 and +0x30 (0x16340 to 0x16354). Otherwise it stores a byte at +0x39 (0x16364) and returns without the word stores. The stored byte values are not shown. Whether this restores or saves CPU error state is not established.
  Reviewed: 2026-11-12

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** The routine tests the byte at +0x38 of the record at a0 (lbu at 0x16310); when it is zero the branch at 0x16318 goes to a return at 0x16358. When it is set, the routine loads two doublewords (ld at 0x16324, 0x16328) and compares one unsigned against the constant 0x55d4a80 (beq at 0x16334); when that value is at or above the constant it goes to a return at 0x16360. Only when it is below the constant does it store a byte at +0x39 (sb at 0x1633c) and copy three doublewords from +0x18, +0x10 and +0x8 into +0x30, +0x28 and +0x20 (sd at 0x1634c, 0x16350, 0x16354). A second sb at +0x39 sits at 0x16364. Role (from name): restoring a saved CPU error record; what the loaded value is and the purpose of the copy are not derived.
  Reviewed: 2026-11-12

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** An 88-byte routine on a saved record at `a0`. It loads the byte at `a0+0x38` [@0x16310]. The branch at 0x16318 goes to the return at 0x16358 when that byte is zero [@0x16318 taken zero]. When the byte is nonzero [@0x16318 fall nonzero] the routine tests an unsigned difference against 0x55d4a80 at 0x16334. When the difference is below it [@0x16334 fall] the routine stores a byte to `a0+0x39` [@0x1633c], loads doublewords from `a0+0x18`, `+0x10` and `+0x8`, and stores doublewords at `a0+0x20`, `+0x28` and `+0x30` [@0x1634c]. Otherwise [@0x16334 taken] it takes the return at 0x16360 [@0x16360] and stores a byte to `a0+0x39` [@0x16364]. Role (from name): restores CPU error state. The facts do not show what the copied values are.
  Reviewed: 2026-11-12

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** Works over the record at `a0` in four similar steps, with a loop (0x163b8 branches back to 0x163a4). It tests the words at +0x1f8, +0x1e8, +0x208 and +0x218, and the words at +0x70, +0x60, +0x80 and +0x90, for zero. It also loads the words at +0x68, +0x58, +0x78 and +0x88 and compares a loaded value against the 0x55d4a80 bound (0x163e4 to 0x164a4), and it stores to +0x1f8, +0x1e8, +0x208 and +0x218 (0x1642c, 0x16458, 0x16484, 0x164b0). The stored values are not shown. The value returned is the word at +0x1e8 (0x163c0). The meaning of each field, and whether this restores or saves, are not established.
  Reviewed: 2026-11-12

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** Role (from name): restoring a saved hub error record at a0. Four doublewords at +0x1f8, +0x1e8, +0x208 and +0x218 are each tested against zero (beq at 0x16370, 0x16380, 0x1638c, 0x16398). When one is zero the branch goes to a block (0x163fc, 0x16430, 0x1645c, 0x16488); when it is nonzero control continues to the next test. Each block loads a pointer field (+0x70, +0x60, +0x80 or +0x90) and skips when it is zero (beq at 0x16408, 0x16434, 0x16460, 0x1648c). Otherwise it loads a second field (+0x68, +0x58, +0x78 or +0x88) and a doubleword through it, compares that unsigned against the constant 0x55d4a80 (beq at 0x16420, 0x1644c, 0x16478, 0x164a4), and stores a doubleword into the tested word only when the value is below the constant (sd at 0x1642c, 0x16458, 0x16484, 0x164b0). A loop around 0x163a4 to 0x163cc and a return of the doubleword at +0x1e8 (0x163c0) are not derived further. Which saved word pairs with which block is read from the branch order.
  Reviewed: 2026-11-12

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** A 332-byte routine on a record at `a0`. It loads the doubleword at `a0+0x1f8` [@0x16368]. When that is zero the branch at 0x16370 goes to 0x163fc [@0x16370 taken zero], which loads `a0+0x70` [@0x163fc] and stores to `a0+0x1f8` [@0x1642c] only when that doubleword is nonzero [@0x16408 fall nonzero] and an unsigned difference is below 0x55d4a80 [@0x16420 fall]. The stores to `a0+0x1e8` [@0x16458], `a0+0x208` [@0x16484] and `a0+0x218` [@0x164b0] sit behind the same kind of test. It returns the doubleword at `a0+488` [@0x163c0]. Role (from name): restores hub error state. The facts do not show what the restored values are.
  Reviewed: 2026-11-12

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** A loop (0x164fc branches back to 0x164c8). Each pass loads a word (0x164cc) and tests it for zero (0x164d4), loads two more words (0x164dc, 0x164e0) and compares a value against 0x55d4a80 (0x164ec). When both tests pass it stores to two 8-byte fields (0x164f4, 0x164f8). The stored values and the return value are not shown by the facts. The name suggests it clears PI error state, but which error fields it clears is not established.
  Reviewed: 2026-11-12

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** The routine loads doublewords through two pointers (ld at 0x164cc, 0x164dc) and a third doubleword at 0x164e0, and stores two doublewords (sd at 0x164f4, 0x164f8). The stores are skipped when a7 is zero (beq at 0x164d4) or when a7 is at or below the constant 0x55d4a80 unsigned (beq at 0x164ec). The routine loops back to 0x164c8 while a4 is nonzero (bne at 0x164fc). The stored values are not in the facts, so the name's claim of clearing the PI error is not shown directly.
  Reviewed: 2026-11-12

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** Role (from name): clears hub PI error state. It runs a loop. Each pass loads doublewords through pointers the facts do not resolve (0x164cc, 0x164dc) and the fixed address 0x9200000001030100 (0x164e0), and stores two doublewords (0x164f4, 0x164f8). The branch at 0x164ec skips those two stores when the constant 0x55d4a80 is at least a7, unsigned. The loop continues while a4 is nonzero (0x164fc). The stored values and store addresses are unknown.
  Reviewed: 2026-11-12

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** An 88-byte routine over a record at `a0`. The branch at 0x164fc goes back to 0x164c8 while `a4` is nonzero [@0x164fc taken nonzero]. Each pass loads a doubleword [@0x164cc]; when it is zero the branch at 0x164d4 skips the stores [@0x164d4 taken zero]. Otherwise an unsigned difference is tested against 0x55d4a80 and, when the branch at 0x164ec falls through [@0x164ec fall], the routine stores doublewords through a pointer built from `a0` plus a per-pass offset [@0x164f4] [@0x164f8]. Role (from name): clears hub PI error entries. The facts do not show what the record holds, and the stores are relative to `a0`, not to a fixed register address.
  Reviewed: 2026-11-12

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** Handles four slots of the record at `a0` (+0x8, +0x18, +0x28, +0x38). For each it tests the word at that offset for zero (0x16524, 0x16550, 0x1657c, 0x165a8), loads the word 8 below it and a second word, compares a value against 0x55d4a80, and stores to the slot (0x16544, 0x16570, 0x1659c, 0x165c8) when both tests pass. The stored values are not shown by the facts. The name suggests it clears memory-directory error latches, but the register meanings are not established.
  Reviewed: 2026-11-12

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** The routine handles four fields of the record at a0 in turn, at +0x18, +0x8, +0x28 and +0x38. Each is tested against zero (beq at 0x16524, 0x16550, 0x1657c, 0x165a8) and skipped when zero. When nonzero, the routine loads a doubleword through a neighbouring field (+0x10, +0x0, +0x20 or +0x30), compares it unsigned against the constant 0x55d4a80 (beq at 0x1653c, 0x16568, 0x16594, 0x165c0), and stores a doubleword back into the tested field only when the loaded value is above the constant (sd at 0x16544, 0x16570, 0x1659c, 0x165c8). Role (from name): clearing MD error state; the stored value is not derived.
  Reviewed: 2026-11-12

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** Works on one error record passed in a0. It tests the fields at offsets 0x8, 0x18, 0x28 and 0x38, and writes back to those slots at 0x16570, 0x16544, 0x1659c and 0x165c8 when the test allows it. Each write is guarded by a bound check against the constant 0x55d4a80, compared unsigned (0x1653c, 0x16568, 0x16594, 0x165c0). It also reads the fixed address 0x9200000001030100 at 0x16530, the same location the PI-error clear routine reads. The values written are unknown.
  Reviewed: 2026-11-12

- `save_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1690c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1690c-0x16a0c (256 bytes).
  It occupies 256 bytes.
  The `ld` at 0x1690c loads 8 bytes from a0 (arg0 at entry) +0x400.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x10, including `sd` at 0x16910, `sd` at 0x169f8, `sd` at 0x16a08.
  The `ld` at 0x16914 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `ld` at 0x16924 loads 8 bytes from a0 (arg0 at entry) +0x58.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x430, including `ld` at 0x16948, `ld` at 0x1698c.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc524, including `lh` at 0x16964, `lh` at 0x169b0.
  The `sd` at 0x16990 stores 8 bytes to a1 (arg1 at entry) +0x28.
  The `ld` at 0x16994 loads 8 bytes from a0 (arg0 at entry) +0x440.
  The `sd` at 0x16998 stores 8 bytes to a1 (arg1 at entry) +0x38.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x450, including `ld` at 0x1699c, `ld` at 0x169d4.
  The `sd` at 0x169d8 stores 8 bytes to a1 (arg1 at entry) +0x30.
  The `ld` at 0x169dc loads 8 bytes from a0 (arg0 at entry) +0x460.
  The `sd` at 0x169e0 stores 8 bytes to a1 (arg1 at entry) +0x40.
  The `beq` branch at 0x16918 targets 0x169ec, is taken when at(=[a0+80]:8) == 0, and falls through when at(=[a0+80]:8) != 0.
  The `beq` branch at 0x1693c targets 0x169fc, is taken when v0(=[a0+88]:8) == 0, and falls through when v0(=[a0+88]:8) != 0.
  The `beq` branch at 0x1695c targets 0x1699c, is taken when (a4(=0x8000000000000000) & a6(=[a0+1072]:8)) == 0, and falls through when (a4(=0x8000000000000000) & a6(=[a0+1072]:8)) != 0.
  The `beq` branch at 0x1696c targets 0x1699c, is taken when (a2(=[-0x3adc]:2) & 0x2) == 0, and falls through when (a2(=[-0x3adc]:2) & 0x2) != 0.
  The `beq` branch at 0x1697c targets 0x1699c, is taken when t8(?) == at(=0x480041), and falls through when t8(?) != at(=0x480041).
  The `beq` branch at 0x16984 targets 0x1699c, is taken when t8(?) == t9(=0x1fffffe0), and falls through when t8(?) != t9(=0x1fffffe0).
  The `beq` branch at 0x169a8 targets 0x169e4, is taken when (a4(=0x8000000000000000) & a6(=[a0+1104]:8)) == 0, and falls through when (a4(=0x8000000000000000) & a6(=[a0+1104]:8)) != 0.
  The `beq` branch at 0x169b8 targets 0x169e4, is taken when (v1(=[-0x3adc]:2) & 0x2) == 0, and falls through when (v1(=[-0x3adc]:2) & 0x2) != 0.
  The `beq` branch at 0x169c4 targets 0x169e4, is taken when a2(?) == a5(=0x480041), and falls through when a2(?) != a5(=0x480041).
  The `beq` branch at 0x169cc targets 0x169e4, is taken when a5(?) == a4(=0x1fffffe0), and falls through when a5(?) != a4(=0x1fffffe0).
  The `beq` branch at 0x169f4 targets 0x1691c and is always taken.
  The `beq` branch at 0x16a04 targets 0x16944 and is always taken.
  The return at 0x169e4 has v0 = ?.

- `save_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16a0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16a0c-0x16a78 (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0x16a14 loads 8 bytes from a0 (arg0 at entry) +0x200050.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x8, including `sd` at 0x16a24, `sd` at 0x16a74.
  The `ld` at 0x16a28 loads 8 bytes from a0 (arg0 at entry) +0x200070.
  The `sd` at 0x16a38 stores 8 bytes to a1 (arg1 at entry) +0x18.
  The `ld` at 0x16a3c loads 8 bytes from a0 (arg0 at entry) +0x200060.
  The `sd` at 0x16a4c stores 8 bytes to a1 (arg1 at entry) +0x28.
  The `ld` at 0x16a50 loads 8 bytes from a0 (arg0 at entry) +0x200080.
  The `sd` at 0x16a5c stores 8 bytes to a1 (arg1 at entry) +0x38.
  The `beq` branch at 0x16a1c targets 0x16a68, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x16a30 targets 0x16a3c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x16a44 targets 0x16a50, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x16a54 targets 0x16a60, is taken when a2(=[a0+2097280]:8) == 0, and falls through when a2(=[a0+2097280]:8) != 0.
  The `bgez` branch at 0x16a68 targets 0x16a28, is taken when a5(=([a0+2097232]:8 << 0x1)) >= 0 (signed), and falls through when a5(=([a0+2097232]:8 << 0x1)) < 0 (signed).
  The `beq` branch at 0x16a70 targets 0x16a28 and is always taken.
  The return at 0x16a60 has v0 = ?.

- `save_hub_io_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16a78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16a78-0x16b50 (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0x16aac loads 8 bytes from a0 (arg0 at entry) +0x400008.
  The `sd` at 0x16ab4 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `ld` at 0x16ab8 loads 8 bytes from a0 (arg0 at entry) +0x410000.
  The `sd` at 0x16abc stores 8 bytes to a1 (arg1 at entry) +0x88.
  The `ld` at 0x16ac0 loads 8 bytes from a0 (arg0 at entry) +0x410008.
  The `sd` at 0x16ac4 stores 8 bytes to a1 (arg1 at entry) +0x98.
  The `ld` at 0x16acc loads 8 bytes from a0 (arg0 at entry) +0x410010.
  The `sd` at 0x16ad4 stores 8 bytes to a1 (arg1 at entry) +0xa8.
  The `ld` at 0x16ad8 loads 8 bytes from a0 (arg0 at entry) +0x420000.
  The `sd` at 0x16adc stores 8 bytes to a1 (arg1 at entry) +0x90.
  The `ld` at 0x16ae0 loads 8 bytes from a0 (arg0 at entry) +0x420008.
  The `sd` at 0x16ae4 stores 8 bytes to a1 (arg1 at entry) +0xa0.
  The `ld` at 0x16aec loads 8 bytes from a0 (arg0 at entry) +0x420010.
  The `sd` at 0x16af8 stores 8 bytes to a1 (arg1 at entry) +0xb0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x16b10, `ld` at 0x16b18.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x16b14, `sd` at 0x16b3c.
  The `jal` at 0x16a94 calls bzero with a0=a1 at entry (arg1), a1=0xc0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x16b38 targets 0x16afc, is taken when a1(?) < 0xf (signed), and falls through when a1(?) >= 0xf (signed).
  The return at 0x16b48 has v0 = [a0+4325384]:8.

- `save_hub_err_ext` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16b50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16b50-0x16c08 (184 bytes).
  It occupies 184 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x16b9c, `ld` at 0x16bc4, `ld` at 0x16bec.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x16ba0, `sd` at 0x16bcc, `sd` at 0x16bf4.
  The `jal` at 0x16b6c calls bzero with a0=a1 at entry (arg1), a1=0xc0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x16ba4 targets 0x16bd0, is taken when a2(?) >= 0xf (signed), and falls through when a2(?) < 0xf (signed).
  The `bne` branch at 0x16bc8 targets 0x16b80, is taken when a2(?) < 0xf (signed), and falls through when a2(?) >= 0xf (signed).
  The `bne` branch at 0x16bf0 targets 0x16bd4, is taken when a2(?) < 0x9 (signed), and falls through when a2(?) >= 0x9 (signed).
  The return at 0x16c00 has v0 = ?.

- `save_hub_ni_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16c08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16c08-0x16c60 (88 bytes).
  It occupies 88 bytes.
  The `ld` at 0x16c48 loads 8 bytes from a0 (arg0 at entry) +0x600300.
  The `sd` at 0x16c4c stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `ld` at 0x16c50 loads 8 bytes from a0 (arg0 at entry) +0x608008.
  The `sd` at 0x16c5c stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `jal` at 0x16c20 calls bzero with a0=a1 at entry (arg1), a1=0x20, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x16c58 has v0 = a1.

- `save_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16c60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16c60-0x16d88 (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0x16c64 loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `lw` at 0x16d34 loads 4 bytes from a1 (arg1 at entry) +0x314.
  The `jal` at 0x16cb8 calls save_hub_pi_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16cc8 calls save_hub_md_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16cd8 calls save_hub_io_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16ce4 calls save_hub_ni_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16d04 calls brd_sversion [0x15edc] with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x16d50 calls save_hub_err_ext with a0=?, a1=?, a2=0x9600000000000000, a3=0xffffffffff.
  The `jal` at 0x16d70 calls clear_hub_pi_error with a0=?, a1=0x2, a2=a2 at entry (arg2), a3=0x9200000001800000, a4=-0x1, a5=[a2+12], a6=(a0 << 0x20).
  The `jal` at 0x16d78 calls clear_hub_md_error with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x16c84 targets 0x16d68, is taken when (a5(=[a2+12]) & 0x1) == 0, and falls through when (a5(=[a2+12]) & 0x1) != 0.
  The `beq` branch at 0x16c98 targets 0x16d60, is taken when a0 == a4(=-0x1), and falls through when a0 != a4(=-0x1).
  The `beq` branch at 0x16cac targets 0x16d70, is taken when a5(=[a2+12]) == a1(=0x2), and falls through when a5(=[a2+12]) != a1(=0x2).
  The `beq` branch at 0x16d10 targets 0x16d2c, is taken when v0(=ret(brd_sversion)) >= 0x3 (signed), and falls through when v0(=ret(brd_sversion)) < 0x3 (signed).
  The `beq` branch at 0x16d58 targets 0x16d1c and is always taken.
  The `beq` branch at 0x16d60 targets 0x16ca4 and is always taken.
  The `beq` branch at 0x16d68 targets 0x16c90 and is always taken.
  The `beq` branch at 0x16d80 targets 0x16cb8 and is always taken.
  The return at 0x16d24 has v0 = one of ret(brd_sversion), ret(save_hub_err_ext).

- `save_bridge_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16d88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16d88-0x16e48 (192 bytes).
  It occupies 192 bytes.
  The `lw` at 0x16d88 loads 4 bytes from a3 (arg3 at entry) +0xc.
  10 such `lw` accesses load 4 bytes from ?, including `lw` at 0x16ddc, `lw` at 0x16de4, `lw` at 0x16dec.
  The `sw` at 0x16de0 stores 4 bytes to (a1 + one of 0x8, 0x30) +0x0.
  The `sw` at 0x16de8 stores 4 bytes to (a1 + one of 0xc, 0x34) +0x0.
  The `sw` at 0x16df0 stores 4 bytes to (a1 + one of 0x10, 0x38) +0x0.
  The `sw` at 0x16df8 stores 4 bytes to (a1 + one of 0x14, 0x3c) +0x0.
  The `sw` at 0x16e00 stores 4 bytes to (a1 + one of 0x18, 0x40) +0x0.
  The `sw` at 0x16e08 stores 4 bytes to (a1 + one of 0x1c, 0x44) +0x0.
  The `sw` at 0x16e10 stores 4 bytes to (a1 + one of 0x20, 0x48) +0x0.
  The `sw` at 0x16e18 stores 4 bytes to (a1 + one of 0x24, 0x4c) +0x0.
  The `sw` at 0x16e20 stores 4 bytes to (a1 + one of 0x28, 0x50) +0x0.
  The `sw` at 0x16e2c stores 4 bytes to (a1 + one of 0x2c, 0x54) +0x0.
  The `jal` at 0x16dd0 calls bzero with a0=(a1 + one of 0x8, 0x30), a1=0x28, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=(a0 << 0x20), a6=[a3+12], a7=-0x37.
  The `beq` branch at 0x16da0 targets 0x16e3c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x16dc0 targets 0x16dcc, is taken when (a6(=[a3+12]) & 0x1) == 0, and falls through when (a6(=[a3+12]) & 0x1) != 0.
  The `beq` branch at 0x16e40 targets 0x16db8 and is always taken.
  The return at 0x16e34 has v0 = ?.

- `save_xbow_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16e48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16e48-0x16efc (180 bytes).
  It occupies 180 bytes.
  The `lw` at 0x16e48 loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `lw` at 0x16e90 loads 4 bytes from (a0 << 0x20) -0x6dffffff1ffffff4.
  The `sw` at 0x16e94 stores 4 bytes to (a1 + one of 0x8, 0x58) +0x0.
  The `lw` at 0x16e98 loads 4 bytes from (a0 << 0x20) -0x6dffffff1fffffec.
  The `sw` at 0x16e9c stores 4 bytes to (a1 + one of 0xc, 0x5c) +0x0.
  The `lw` at 0x16ea0 loads 4 bytes from (a0 << 0x20) -0x6dffffff1fffffe4.
  The `sw` at 0x16ea4 stores 4 bytes to (a1 + one of 0x10, 0x60) +0x0.
  The `lw` at 0x16ea8 loads 4 bytes from (a0 << 0x20) -0x6dffffff1fffffbc.
  The `sw` at 0x16eb4 stores 4 bytes to (a1 + one of 0x14, 0x64) +0x0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x16ed4, `lw` at 0x16ee0.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x16edc, `sw` at 0x16eec.
  The `jal` at 0x16e74 calls bzero with a0=(a1 + one of 0x8, 0x58), a1=0x50, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x16e64 targets 0x16e70, is taken when (at(=[a2+12]) & 0x1) == 0, and falls through when (at(=[a2+12]) & 0x1) != 0.
  The `bne` branch at 0x16ee8 targets 0x16eb8, is taken when a1(?) < 0x8 (signed), and falls through when a1(?) >= 0x8 (signed).
  The return at 0x16ef4 has v0 = [(a0 << 0x20)-7926335340413976508].

- `kl_error_show_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16efc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x16efc-0x170ec (496 bytes).
  It occupies 496 bytes.
  The `ld` at 0x16f50 loads 8 bytes from ?.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x16f60, `lw` at 0x16fc4, `lw` at 0x16fe0.
  4 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x16f88, `lbu` at 0x16f9c, `lbu` at 0x16fb4.
  The `lw` at 0x17068 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `ld` at 0x17070 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `jal` at 0x16f30 calls kl_perr with a0=0x1, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x1706c calls kl_perr_dumpbuf with a0=[a1]:8, a1=[a1+8], a2=?, a3=?, a6=0x10.
  The `jal` at 0x17090 calls show_err_node_comp with a0=?, a1=a1 at entry (arg1), a2=0x30, a3=0x40, a6=0x10.
  The `jal` at 0x170a4 calls show_err_io_comp with a0=?, a1=a1 at entry (arg1), a2=0x30, a3=0x40, a6=0x10.
  The `jal` at 0x170b4 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x170cc calls show_err_router_comp with a0=?, a1=a1 at entry (arg1), a2=0x30, a3=0x40, a6=0x10.
  The `jal` at 0x170dc calls show_err_xbow_comp with a0=?, a1=a1 at entry (arg1), a2=0x30, a3=0x40, a6=0x10.
  The `beq` branch at 0x16f14 targets 0x170b4, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x16f70 targets 0x16f7c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x16f7c targets 0x1705c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x16f84 targets 0x16fa0 and is always taken.
  The `beq` branch at 0x16f94 targets 0x1705c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x16fac targets 0x16fe0, is taken when (t8(?) & 0x1) == 0, and falls through when (t8(?) & 0x1) != 0.
  The `beq` branch at 0x16fbc targets 0x16ffc, is taken when (t9(?) & 0x4) == 0, and falls through when (t9(?) & 0x4) != 0.
  The `bne` branch at 0x16fd0 targets 0x16f8c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x16fd8 targets 0x16f90 and is always taken.
  The `beq` branch at 0x16fe4 targets 0x17084, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x16ff4 targets 0x16f94 and is always taken.
  The `beq` branch at 0x1700c targets 0x1708c, is taken when a0(?) == a6(=0x10), and falls through when a0(?) != a6(=0x10).
  The `beq` branch at 0x17014 targets 0x170a0, is taken when a0(?) == a1(=0x20), and falls through when a0(?) != a1(=0x20).
  The `beq` branch at 0x1701c targets 0x170c8, is taken when a0(?) == a2(=0x30), and falls through when a0(?) != a2(=0x30).
  The `beq` branch at 0x17024 targets 0x170dc, is taken when a0(?) == a3(=0x40), and falls through when a0(?) != a3(=0x40).
  The `beq` branch at 0x17044 targets 0x17054, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x17054 targets 0x16f94 and is always taken.
  The `beq` branch at 0x17084 targets 0x16ff4 and is always taken.
  The `beq` branch at 0x17098 targets 0x17030 and is always taken.
  The `beq` branch at 0x170ac targets 0x17030 and is always taken.
  The `beq` branch at 0x170c0 targets 0x16f1c and is always taken.
  The `beq` branch at 0x170d4 targets 0x17030 and is always taken.
  The `beq` branch at 0x170e4 targets 0x17030 and is always taken.
  The return at 0x1707c has v0 = ret(kl_perr_dumpbuf).

- `kl_error_show` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x170ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x170ec-0x1718c (160 bytes).
  It occupies 160 bytes.
  The `lh` at 0x17140 loads 2 bytes from ?.
  The `lw` at 0x17170 loads 4 bytes from a2 (arg2 at entry) +0x8.
  The `ld` at 0x17178 loads 8 bytes from a2 (arg2 at entry) +0x0.
  The `jal` at 0x17114 calls kl_perr with a0=0x10, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1713c calls kl_error_show_node with a0=?, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x17164 calls kl_perr with a0=0x10, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x17174 calls kl_perr_dumpbuf with a0=[a2]:8, a1=[a2+8], a2=?, a3=?.
  The `blez` branch at 0x17124 targets 0x17158, is taken when v0(=[sym(numnodes)]) <= 0 (signed), and falls through when v0(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x17150 targets 0x17134, is taken when s0(?) < a1(=[sym(numnodes)]) (signed), and falls through when s0(?) >= a1(=[sym(numnodes)]) (signed).
  The return at 0x17184 has v0 = ret(kl_perr_dumpbuf).

- `kl_dump_hw_state` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1718c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1718c-0x171bc (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x171a8 calls kl_save_hw_state_all with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x171b4 has v0 = ret(kl_save_hw_state_all).

- `kl_log_hw_state` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x171bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x171bc-0x171ec (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x171d8 calls kl_save_hw_state_all with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x171e4 has v0 = ret(kl_save_hw_state_all).

- `kl_error_show_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x171ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x171ec-0x17220 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x1720c calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x17218 has v0 = ret(kl_error_show).

- `kl_error_show_log` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x17220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x17220-0x17250 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x1723c calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x17248 has v0 = ret(kl_error_show).

- `kl_error_show_idbg` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x17250 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x17250-0x17280 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x1726c calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x17278 has v0 = ret(kl_error_show).

- `kl_error_show_reset_ste` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x17280 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x17280-0x172ac (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x17298 calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x172a4 has v0 = ret(kl_error_show).

- `show_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x17824 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x17824-0x178a8 (132 bytes).
  It occupies 132 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0xc, including `lw` at 0x1782c, `lw` at 0x17878.
  The `jal` at 0x17860 calls kl_perr with a0=0x3, a1=sym(.rodata)+13640, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x17868 calls show_hub_pi_err with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x17870 calls show_hub_md_err with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x17880 calls show_hub_io_err with a0=a0 at entry (arg0), a1=[a1+12], a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x17890 calls show_hub_ni_err with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1784c targets 0x17858, is taken when (at(=[a1+12]) & 0x1) == 0, and falls through when (at(=[a1+12]) & 0x1) != 0.
  The return at 0x178a0 has v0 = ret(show_hub_ni_err).

- `show_hub_pi_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x178a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x178a8-0x17b40 (664 bytes).
  It occupies 664 bytes.
  The `ld` at 0x178c8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1791c, `ld` at 0x17968, `ld` at 0x17994.
  The `jal` at 0x178ec calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=[a0+16]:8, a3=a3 at entry (arg3).
  The `jal` at 0x17920 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x1796c calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=one of 0x41, 0x42, a3=?.
  The `jal` at 0x17990 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x179a4 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x179b8 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x179cc calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x179ec calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17a04 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17a18 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=one of 0x41, 0x42, a3=?.
  The `jal` at 0x17a30 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17a44 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17a58 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17a70 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17a84 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17a94 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17b0c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17b20 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17b30 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `beq` branch at 0x178d8 targets 0x1793c, is taken when s1(=[a0+16]:8) == 0, and falls through when s1(=[a0+16]:8) != 0.
  The `beq` branch at 0x17910 targets 0x17928, is taken when (s1(=[a0+16]:8) & a2(?)) == 0, and falls through when (s1(=[a0+16]:8) & a2(?)) != 0.
  The `bne` branch at 0x17934 targets 0x17908, is taken when s0(?) < 0x19 (unsigned), and falls through when s0(?) >= 0x19 (unsigned).
  The `beq` branch at 0x1794c targets 0x17aa8 and is always taken.
  The `bltz` branch at 0x1797c targets 0x17b00, is taken when s8(?) < 0 (signed), and falls through when s8(?) >= 0 (signed).
  The `bltz` branch at 0x179f8 targets 0x17b30, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `beq` branch at 0x17a24 targets 0x17a3c, is taken when (s7(=0x1fffff) & s2(?)) == 0, and falls through when (s7(=0x1fffff) & s2(?)) != 0.
  The `bltz` branch at 0x17a64 targets 0x17b1c, is taken when s8(?) < 0 (signed), and falls through when s8(?) >= 0 (signed).
  The `beq` branch at 0x17aa4 targets 0x17ad0, is taken when s3(?) >= 0x2 (signed), and falls through when s3(?) < 0x2 (signed).
  The `bne` branch at 0x17ab8 targets 0x17954, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x17ac8 targets 0x17aac, is taken when s3(?) < 0x2 (signed), and falls through when s3(?) >= 0x2 (signed).
  The `beq` branch at 0x17b14 targets 0x179b0 and is always taken.
  The `beq` branch at 0x17b28 targets 0x17a7c and is always taken.
  The `beq` branch at 0x17b38 targets 0x17a04 and is always taken.
  The return at 0x17af8 has v0 = one of ret(kl_perr), ?.

- `show_hub_md_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x17b40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x17b40-0x17fc8 (1160 bytes).
  It occupies 1160 bytes.
  The `ld` at 0x17b50 loads 8 bytes from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x17c64, `ld` at 0x17f5c.
  The `ld` at 0x17d00 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0x17d98 loads 8 bytes from table(sym(ps_cache_error)) +0x190.
  The `ld` at 0x17e20 loads 8 bytes from table(sym(ps_cache_error)) +0x1d0.
  The `ld` at 0x17e30 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `ld` at 0x17e9c loads 8 bytes from ?.
  The `jal` at 0x17b84 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `jal` at 0x17c14 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17c28 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17c3c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17c4c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17c7c calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=[a0+24]:8, a3=?.
  The `jal` at 0x17c94 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?, a5=([a0+24]:8 << 0x3e).
  The `jal` at 0x17cc4 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17ce0 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=([a0+24]:8 << 0x1).
  The `jal` at 0x17cf8 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17d14 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=[a0+40]:8, a3=?.
  The `jal` at 0x17d28 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17d4c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17d64 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?, a4=([a0+40]:8 << 0x1f).
  The `jal` at 0x17d94 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=[table(sym(ps_cache_error))+400]:8, a3=?.
  The `jal` at 0x17db8 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17dd4 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17de8 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17e1c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=[table(sym(ps_cache_error))+464]:8.
  The `jal` at 0x17e28 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17e48 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17e68 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17ea8 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17f00 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17f18 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=([a0+8]:8 << 0x3e).
  The `jal` at 0x17f28 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?, a4=([a0+40]:8 << 0x1f).
  The `jal` at 0x17f40 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17f50 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17f64 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x17f74 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?, a5=([a0+24]:8 << 0x3e).
  The `jal` at 0x17f84 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=([a0+24]:8 << 0x1).
  The `jal` at 0x17fa0 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?, a4=([a0+40]:8 << 0x1a).
  The `beq` branch at 0x17b6c targets 0x17edc, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bltz` branch at 0x17b8c targets 0x17ef8, is taken when s2(=([a0+8]:8 << 0x2)) < 0 (signed), and falls through when s2(=([a0+8]:8 << 0x2)) >= 0 (signed).
  The `bltz` branch at 0x17b94 targets 0x17f10, is taken when s4(=([a0+8]:8 << 0x1)) < 0 (signed), and falls through when s4(=([a0+8]:8 << 0x1)) >= 0 (signed).
  The `beq` branch at 0x17b9c targets 0x17bb0, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bltz` branch at 0x17ba8 targets 0x17f60, is taken when at(=([a0+8]:8 << 0x3d)) < 0 (signed), and falls through when at(=([a0+8]:8 << 0x3d)) >= 0 (signed).
  The `bne` branch at 0x17bd0 targets 0x17c14, is taken when v0(?) != v1(=0x30000000), and falls through when v0(?) == v1(=0x30000000).
  The `beq` branch at 0x17bf8 targets 0x17f38, is taken when (a3(?) & 0x200) == 0, and falls through when (a3(?) & 0x200) != 0.
  The `beq` branch at 0x17c44 targets 0x17c54, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bltz` branch at 0x17c54 targets 0x17f40, is taken when s4(=([a0+8]:8 << 0x1)) < 0 (signed), and falls through when s4(=([a0+8]:8 << 0x1)) >= 0 (signed).
  The `bltz` branch at 0x17c5c targets 0x17f50, is taken when s2(=([a0+8]:8 << 0x2)) < 0 (signed), and falls through when s2(=([a0+8]:8 << 0x2)) >= 0 (signed).
  The `beq` branch at 0x17c6c targets 0x17d00, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x17c88 targets 0x17ca0, is taken when (s1(=[a0+24]:8) & 0x1) == 0, and falls through when (s1(=[a0+24]:8) & 0x1) != 0.
  The `bltz` branch at 0x17ca0 targets 0x17f74, is taken when a5(=([a0+24]:8 << 0x3e)) < 0 (signed), and falls through when a5(=([a0+24]:8 << 0x3e)) >= 0 (signed).
  The `beq` branch at 0x17cb8 targets 0x17ccc, is taken when (a2(?) & a3(=0x1fffffff)) == 0, and falls through when (a2(?) & a3(=0x1fffffff)) != 0.
  The `beq` branch at 0x17cd4 targets 0x17cec, is taken when (a2(?) & 0xff) == 0, and falls through when (a2(?) & 0xff) != 0.
  The `bltz` branch at 0x17cec targets 0x17f84, is taken when a3(=([a0+24]:8 << 0x1)) < 0 (signed), and falls through when a3(=([a0+24]:8 << 0x1)) >= 0 (signed).
  The `beq` branch at 0x17d08 targets 0x17e30, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x17d20 targets 0x17d30, is taken when (s1(=[a0+40]:8) & 0x1) == 0, and falls through when (s1(=[a0+40]:8) & 0x1) != 0.
  The `beq` branch at 0x17d40 targets 0x17d54, is taken when (a2(?) & a3(=0x1fffffff)) == 0, and falls through when (a2(?) & a3(=0x1fffffff)) != 0.
  The `bltz` branch at 0x17d58 targets 0x17f28, is taken when a4(=([a0+40]:8 << 0x1f)) < 0 (signed), and falls through when a4(=([a0+40]:8 << 0x1f)) >= 0 (signed).
  The `beq` branch at 0x17d74 targets 0x17d9c, is taken when (a5(?) & 0xf) == 0, and falls through when (a5(?) & 0xf) != 0.
  The `bltz` branch at 0x17da0 targets 0x17f94, is taken when a4(=([a0+40]:8 << 0x1a)) < 0 (signed), and falls through when a4(=([a0+40]:8 << 0x1a)) >= 0 (signed).
  The `beq` branch at 0x17db0 targets 0x17dc0, is taken when (a2(?) & 0x3) == 0, and falls through when (a2(?) & 0x3) != 0.
  The `beq` branch at 0x17dc8 targets 0x17df4, is taken when (a2(?) & 0xff) == 0, and falls through when (a2(?) & 0xff) != 0.
  The `beq` branch at 0x17df8 targets 0x17e28, is taken when (a5(?) & 0x7ff) == 0, and falls through when (a5(?) & 0x7ff) != 0.
  The `beq` branch at 0x17e38 targets 0x17eb8, is taken when (s1(=[a0+56]:8) & 0x3ff) == 0, and falls through when (s1(=[a0+56]:8) & 0x3ff) != 0.
  The `beq` branch at 0x17e58 targets 0x17fb0 and is always taken.
  The `beq` branch at 0x17e84 targets 0x17eb8, is taken when s0(?) >= 0xa (unsigned), and falls through when s0(?) < 0xa (unsigned).
  The `beq` branch at 0x17e90 targets 0x17e70, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x17e98 targets 0x17e60, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x17eb0 targets 0x17e74 and is always taken.
  The `bltz` branch at 0x17ee0 targets 0x17b7c, is taken when s4(=([a0+8]:8 << 0x1)) < 0 (signed), and falls through when s4(=([a0+8]:8 << 0x1)) >= 0 (signed).
  The `bgez` branch at 0x17ee8 targets 0x17c64, is taken when s2(=([a0+8]:8 << 0x2)) >= 0 (signed), and falls through when s2(=([a0+8]:8 << 0x2)) < 0 (signed).
  The `beq` branch at 0x17ef0 targets 0x17b7c and is always taken.
  The `beq` branch at 0x17ef8 targets 0x17b94, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x17f08 targets 0x17b94 and is always taken.
  The `bgez` branch at 0x17f10 targets 0x17b9c, is taken when a3(=([a0+8]:8 << 0x3e)) >= 0 (signed), and falls through when a3(=([a0+8]:8 << 0x3e)) < 0 (signed).
  The `beq` branch at 0x17f20 targets 0x17b9c and is always taken.
  The `beq` branch at 0x17f30 targets 0x17d70 and is always taken.
  The `beq` branch at 0x17f38 targets 0x17c0c and is always taken.
  The `beq` branch at 0x17f48 targets 0x17c5c and is always taken.
  The `beq` branch at 0x17f58 targets 0x17c68 and is always taken.
  The `beq` branch at 0x17f6c targets 0x17bb0 and is always taken.
  The `beq` branch at 0x17f7c targets 0x17cac and is always taken.
  The `beq` branch at 0x17f8c targets 0x17cf8 and is always taken.
  The `beq` branch at 0x17fa8 targets 0x17dac and is always taken.
  The `beq` branch at 0x17fc0 targets 0x17e90 and is always taken.
  The return at 0x17ed4 has v0 = one of ?, ret(kl_perr).

- `show_hub_io_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x17fc8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x17fc8-0x18358 (912 bytes).
  It occupies 912 bytes.
  10 such `ld` accesses load 8 bytes from ?, including `ld` at 0x18000, `ld` at 0x1805c, `ld` at 0x18080.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x314, including `lw` at 0x18140, `lw` at 0x18294.
  The `ld` at 0x1834c loads 8 bytes from table(sym(ps_cache_error)) +0x240.
  The `jal` at 0x18018 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=?, a3=a3 at entry (arg3), a4=0x100000000, a5=0x1.
  The `jal` at 0x18024 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18094 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x180a4 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x180b0 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x180c0 calls kl_perr with a0=0x34, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x180d0 calls kl_perr with a0=0x34, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x180fc calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x1810c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18118 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18128 calls kl_perr with a0=0x34, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18138 calls kl_perr with a0=0x34, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18178 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x181d4 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x181ec calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18214 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18228 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x1823c calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18274 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18280 calls brd_sversion [0x15edc] with a0=a2 at entry (arg2), a1=0x11, a2=?, a3=?.
  The `jal` at 0x182c8 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=?, a3=?, a5=[a0+788].
  The `jal` at 0x182d8 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x182e8 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x182f8 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x1830c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18320 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18348 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=[table(sym(ps_cache_error))+576]:8.
  The `beq` branch at 0x17ff4 targets 0x18000, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0x18008 targets 0x1802c, is taken when (a2(?) & a4(=0x100000000)) == 0, and falls through when (a2(?) & a4(=0x100000000)) != 0.
  The `bltz` branch at 0x18064 targets 0x181c4, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `bne` branch at 0x18078 targets 0x1805c, is taken when s0(?) < 0xf (signed), and falls through when s0(?) >= 0xf (signed).
  The `bgez` branch at 0x18088 targets 0x180d8, is taken when t9(?) >= 0 (signed), and falls through when t9(?) < 0 (signed).
  The `beq` branch at 0x180ec targets 0x18140, is taken when (ra(=0x10000) & s0(?)) == 0, and falls through when (ra(=0x10000) & s0(?)) != 0.
  The `beq` branch at 0x18150 targets 0x1819c, is taken when a1(=[a0+788]) == a2(=-0x1), and falls through when a1(=[a0+788]) != a2(=-0x1).
  The `bltz` branch at 0x18184 targets 0x182d8, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `bne` branch at 0x18194 targets 0x18160, is taken when s0(?) < 0x9 (signed), and falls through when s0(?) >= 0x9 (signed).
  The `beq` branch at 0x181e0 targets 0x181f8, is taken when (s1(?) & 0x1) == 0, and falls through when (s1(?) & 0x1) != 0.
  The `bltz` branch at 0x181f8 targets 0x182e8, is taken when a5(?) < 0 (signed), and falls through when a5(?) >= 0 (signed).
  The `bltz` branch at 0x18248 targets 0x182f8, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `bltz` branch at 0x18254 targets 0x18308, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `bltz` branch at 0x18260 targets 0x1831c, is taken when a5(?) < 0 (signed), and falls through when a5(?) >= 0 (signed).
  The `bltz` branch at 0x18268 targets 0x18330, is taken when a6(?) < 0 (signed), and falls through when a6(?) >= 0 (signed).
  The `bne` branch at 0x1828c targets 0x1806c, is taken when v0(=ret(brd_sversion)) < 0x3 (signed), and falls through when v0(=ret(brd_sversion)) >= 0x3 (signed).
  The `beq` branch at 0x1829c targets 0x1806c, is taken when a5(=[a0+788]) == t0(=-0x1), and falls through when a5(=[a0+788]) != t0(=-0x1).
  The `beq` branch at 0x182d0 targets 0x18070 and is always taken.
  The `beq` branch at 0x182e0 targets 0x18190 and is always taken.
  The `beq` branch at 0x182f0 targets 0x18204 and is always taken.
  The `beq` branch at 0x18300 targets 0x18254 and is always taken.
  The `beq` branch at 0x18314 targets 0x18260 and is always taken.
  The `beq` branch at 0x18328 targets 0x18268 and is always taken.
  The `beq` branch at 0x18350 targets 0x18274 and is always taken.
  The return at 0x181bc has v0 = one of ?, ret(kl_perr).

- `show_hub_ni_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1848c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1848c-0x185cc (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x18498 loads 8 bytes from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x184b8, `ld` at 0x185c8.
  The `ld` at 0x185a4 loads 8 bytes from ?.
  The `jal` at 0x184e4 calls kl_perr with a0=one of 0x4, 0x24, a1=sym(.rodata)+13640, a2=[a0+16]:8, a3=?.
  The `jal` at 0x184f8 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18510 calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x1852c calls kl_perr with a0=0x25, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18544 calls show_ni_port_error with a0=[a0+16]:8, a1=one of 0x5, 0x25, a2=sym(kl_perr), a3=0x25.
  The `jal` at 0x18570 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `jal` at 0x185a8 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `beq` branch at 0x184b0 targets 0x18564, is taken when at(=0x8000000000000004) == v0(?), and falls through when at(=0x8000000000000004) != v0(?).
  The `beq` branch at 0x184bc targets 0x1854c, is taken when s0(=[a0+16]:8) == 0, and falls through when s0(=[a0+16]:8) != 0.
  The `beq` branch at 0x184f0 targets 0x18500, is taken when (s0(=[a0+16]:8) & 0xff) == 0, and falls through when (s0(=[a0+16]:8) & 0xff) != 0.
  The `beq` branch at 0x18508 targets 0x18518, is taken when (a2(?) & 0xff) == 0, and falls through when (a2(?) & 0xff) != 0.
  The `beq` branch at 0x18520 targets 0x18538, is taken when (a2(?) & 0xff) == 0, and falls through when (a2(?) & 0xff) != 0.
  The `beq` branch at 0x18598 targets 0x185b0, is taken when (a2(=[a0+8]:8) & a3(?)) == 0, and falls through when (a2(=[a0+8]:8) & a3(?)) != 0.
  The `bne` branch at 0x185bc targets 0x18588, is taken when s0(?) < 0x4 (unsigned), and falls through when s0(?) >= 0x4 (unsigned).
  The `beq` branch at 0x185c4 targets 0x184bc and is always taken.
  The return at 0x1855c has v0 = one of ?, ret(show_ni_port_error).

- `show_bridge_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x18718 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x18718-0x18af0 (984 bytes).
  It occupies 984 bytes.
  The `lw` at 0x1872c loads 4 bytes from a1 (arg1 at entry) +0xc.
  The `lwu` at 0x18754 loads 4 bytes from (a0 + one of 0x2c, 0x54) +0x0.
  The `lw` at 0x18778 loads 4 bytes from (a0 + one of 0x2c, 0x54) +0x0.
  The `lw` at 0x187d4 loads 4 bytes from (a0 + one of 0x24, 0x4c) +0x0.
  The `lw` at 0x187e4 loads 4 bytes from (a0 + one of 0x28, 0x50) +0x0.
  The `ld` at 0x18828 loads 8 bytes from ?.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x20, 0x48) +0x0, including `lw` at 0x188d0, `lw` at 0x18914.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x18, 0x40) +0x0, including `lw` at 0x18980, `lw` at 0x18a44.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x1c, 0x44) +0x0, including `lw` at 0x18994, `lw` at 0x18a58.
  3 such `lw` accesses load 4 bytes from (a0 + one of 0x10, 0x38) +0x0, including `lw` at 0x189ec, `lw` at 0x18a8c, `lw` at 0x18acc.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x8, 0x30) +0x0, including `lw` at 0x18a00, `lw` at 0x18aa0.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0xc, 0x34) +0x0, including `lw` at 0x18a14, `lw` at 0x18ab4.
  The `jal` at 0x18770 calls kl_perr with a0=0x3, a1=sym(.rodata)+13640, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1878c calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x2c, 0x54)], a3=?.
  The `jal` at 0x1879c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x187d8 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x24, 0x4c)], a3=?.
  The `jal` at 0x187e8 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x28, 0x50)], a3=?.
  The `jal` at 0x1882c calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x188d4 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x20, 0x48)], a3=0x10000000.
  The `jal` at 0x18918 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x20, 0x48)], a3=?.
  The `jal` at 0x18984 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x18, 0x40)], a3=?.
  The `jal` at 0x18998 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x1c, 0x44)], a3=?.
  The `jal` at 0x189f0 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x10, 0x38)], a3=?.
  The `jal` at 0x18a04 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x8, 0x30)], a3=?.
  The `jal` at 0x18a18 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0xc, 0x34)], a3=?.
  The `jal` at 0x18a48 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x18, 0x40)], a3=one of 0x4000000, 0x10000000.
  The `jal` at 0x18a5c calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x1c, 0x44)], a3=?.
  The `jal` at 0x18a90 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x10, 0x38)], a3=0x800000.
  The `jal` at 0x18aa4 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x8, 0x30)], a3=?.
  The `jal` at 0x18ab8 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0xc, 0x34)], a3=?.
  The `jal` at 0x18ad0 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x10, 0x38)], a3=0x10000000.
  The `beq` branch at 0x18744 targets 0x18750, is taken when (at(=[a1+12]) & 0x1) == 0, and falls through when (at(=[a1+12]) & 0x1) != 0.
  The `beq` branch at 0x18760 targets 0x189a8, is taken when (v0(=[(a0 + one of 0x2c, 0x54)]) & v1(=0xffffffff7fffff00)) == 0, and falls through when (v0(=[(a0 + one of 0x2c, 0x54)]) & v1(=0xffffffff7fffff00)) != 0.
  The `beq` branch at 0x1877c targets 0x189ac, is taken when s3(=[(a0 + one of 0x2c, 0x54)]) == 0, and falls through when s3(=[(a0 + one of 0x2c, 0x54)]) != 0.
  The `beq` branch at 0x187b8 targets 0x18ae0 and is always taken.
  The `bne` branch at 0x187c0 targets 0x18a6c, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `beq` branch at 0x187c8 targets 0x187f0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x187fc targets 0x189a8, is taken when s0(?) >= 0x20 (signed), and falls through when s0(?) < 0x20 (signed).
  The `beq` branch at 0x18818 targets 0x187f0, is taken when (s3(=[(a0 + one of 0x2c, 0x54)]) & s1(?)) == 0, and falls through when (s3(=[(a0 + one of 0x2c, 0x54)]) & s1(?)) != 0.
  The `bne` branch at 0x1888c targets 0x188e4, is taken when s1(?) < s5(=0x400000) (unsigned), and falls through when s1(?) >= s5(=0x400000) (unsigned).
  The `beq` branch at 0x18898 targets 0x187f0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x188a0 targets 0x18948, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x188a8 targets 0x189e8, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x188b0 targets 0x18a38, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x188b8 targets 0x18ac8, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x188c4 targets 0x187f0, is taken when a0(=0x40000000) != s1(?), and falls through when a0(=0x40000000) == s1(?).
  The `beq` branch at 0x188dc targets 0x187f4 and is always taken.
  The `bne` branch at 0x188e8 targets 0x18928, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x188f0 targets 0x187cc, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x188f8 targets 0x187c0, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x18900 targets 0x187cc, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0x18908 targets 0x187f0, is taken when a2(=0x10000) != s1(?), and falls through when a2(=0x10000) == s1(?).
  The `beq` branch at 0x18920 targets 0x187f4 and is always taken.
  The `bne` branch at 0x18928 targets 0x1896c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x18930 targets 0x187cc, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0x18938 targets 0x187f0, is taken when a2(=0x800) != s1(?), and falls through when a2(=0x800) == s1(?).
  The `beq` branch at 0x18940 targets 0x187d0 and is always taken.
  The `bne` branch at 0x18948 targets 0x189d8, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x18950 targets 0x189e8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1895c targets 0x187f0, is taken when a3(=0x4000000) != s1(?), and falls through when a3(=0x4000000) == s1(?).
  The `beq` branch at 0x18964 targets 0x18a40 and is always taken.
  The `bne` branch at 0x1896c targets 0x18a28, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x18974 targets 0x187f0, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0x189a0 targets 0x187f4 and is always taken.
  The `bne` branch at 0x189d8 targets 0x18a7c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x189e0 targets 0x187f0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x18a20 targets 0x187f4 and is always taken.
  The `bne` branch at 0x18a28 targets 0x187f0, is taken when a2(=0x100) != s1(?), and falls through when a2(=0x100) == s1(?).
  The `beq` branch at 0x18a30 targets 0x187d0 and is always taken.
  The `bne` branch at 0x18a38 targets 0x187f0, is taken when a3(=0x10000000) != s1(?), and falls through when a3(=0x10000000) == s1(?).
  The `beq` branch at 0x18a64 targets 0x187f4 and is always taken.
  The `bne` branch at 0x18a6c targets 0x187f0, is taken when a2(=0x2000) != s1(?), and falls through when a2(=0x2000) == s1(?).
  The `beq` branch at 0x18a74 targets 0x187d0 and is always taken.
  The `bne` branch at 0x18a80 targets 0x187f0, is taken when a3(=0x800000) != s1(?), and falls through when a3(=0x800000) == s1(?).
  The `beq` branch at 0x18ac0 targets 0x187f4 and is always taken.
  The `beq` branch at 0x18ad8 targets 0x187f4 and is always taken.
  The `beq` branch at 0x18ae8 targets 0x18808 and is always taken.
  The return at 0x189d0 has v0 = one of ret(kl_perr), ?.

- `show_xbow_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x18bec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x18bec-0x18e30 (580 bytes).
  It occupies 580 bytes.
  The `lw` at 0x18bfc loads 4 bytes from a1 (arg1 at entry) +0xc.
  The `lw` at 0x18c3c loads 4 bytes from (a0 + one of 0x8, 0x58) +0x0.
  The `ld` at 0x18c94 loads 8 bytes from ?.
  The `ld` at 0x18ce0 loads 8 bytes from table(sym(ps_cache_error)) +0x510.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x18d30, `lw` at 0x18d40.
  The `lw` at 0x18d84 loads 4 bytes from (a0 + one of 0x14, 0x64) +0x0.
  The `lw` at 0x18db4 loads 4 bytes from (a0 + one of 0xc, 0x5c) +0x0.
  The `lw` at 0x18dc8 loads 4 bytes from (a0 + one of 0x10, 0x60) +0x0.
  The `lw` at 0x18e2c loads 4 bytes from (a0 + one of 0x38, 0x88) +0x0.
  The `jal` at 0x18c34 calls kl_perr with a0=0x3, a1=sym(.rodata)+13640, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18c5c calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x8, 0x58)], a3=?.
  The `jal` at 0x18c98 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18ce4 calls kl_perr with a0=0x5, a1=sym(.rodata)+13640, a2=[table(sym(ps_cache_error))+1296]:8, a3=?.
  The `jal` at 0x18d74 calls kl_perr with a0=0x4, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `jal` at 0x18da4 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x14, 0x64)], a3=?.
  The `jal` at 0x18db8 calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0xc, 0x5c)], a3=?.
  The `jal` at 0x18dcc calls kl_perr with a0=0x14, a1=sym(.rodata)+13640, a2=[(a0 + one of 0x10, 0x60)], a3=?.
  The `jal` at 0x18e10 calls kl_perr with a0=0x34, a1=sym(.rodata)+13640, a2=?, a3=?.
  The `beq` branch at 0x18c14 targets 0x18c20, is taken when (at(=[a1+12]) & 0x1) == 0, and falls through when (at(=[a1+12]) & 0x1) != 0.
  The `beq` branch at 0x18c48 targets 0x18cc4, is taken when s1(=[(a0 + one of 0x8, 0x58)]) == 0, and falls through when s1(=[(a0 + one of 0x8, 0x58)]) != 0.
  The `beq` branch at 0x18c88 targets 0x18ca0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x18cb4 targets 0x18c88, is taken when s0(?) < 0x20 (unsigned), and falls through when s0(?) >= 0x20 (unsigned).
  The `beq` branch at 0x18cbc targets 0x18cc8 and is always taken.
  The `beq` branch at 0x18ccc targets 0x18e20 and is always taken.
  The `beq` branch at 0x18cf4 targets 0x18d18, is taken when s0(?) >= 0x13 (unsigned), and falls through when s0(?) < 0x13 (unsigned).
  The `bne` branch at 0x18d00 targets 0x18cd4, is taken when (s1(?) & a4(?)) != 0, and falls through when (s1(?) & a4(?)) == 0.
  The `bne` branch at 0x18d10 targets 0x18cfc, is taken when s0(?) < 0x13 (unsigned), and falls through when s0(?) >= 0x13 (unsigned).
  The `beq` branch at 0x18d28 targets 0x18d84, is taken when s3(?) >= 0x8 (signed), and falls through when s3(?) < 0x8 (signed).
  The `beq` branch at 0x18d38 targets 0x18d18, is taken when (a7(?) & 0x20) == 0, and falls through when (a7(?) & 0x20) != 0.
  The `beq` branch at 0x18d48 targets 0x18d18, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x18d50 targets 0x18d5c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x18d5c targets 0x18e04, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x18d7c targets 0x18cf8 and is always taken.
  The `bne` branch at 0x18d8c targets 0x18da0, is taken when (a2(=[(a0 + one of 0x14, 0x64)]) & 0x200) != 0, and falls through when (a2(=[(a0 + one of 0x14, 0x64)]) & 0x200) == 0.
  The `beq` branch at 0x18d94 targets 0x18dd8, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x18e18 targets 0x18d1c and is always taken.
  The `beq` branch at 0x18e28 targets 0x18d34 and is always taken.
  The return at 0x18dfc has v0 = ret(kl_perr).

- `hub_error_clear` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19314 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x19314-0x19374 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0x19330 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe1f7f78.
  The `ld` at 0x19334 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe5fff88.
  The `ld` at 0x19338 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe5fffa8.
  The `ld` at 0x1933c loads 8 bytes from (a0 << 0x20) -0x6dfffffffe5fff78.
  The `ld` at 0x19348 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe5fff98.
  The `sd` at 0x19354 stores 8 bytes to (a0 << 0x20) -0x6dfffffffe7ffc00.
  The `sd` at 0x19358 stores 8 bytes to (a0 << 0x20) -0x6dfffffffe3ffe08.
  The `ld` at 0x19360 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe3ffec8.
  The `sd` at 0x19370 stores 8 bytes to (a0 << 0x20) -0x6dfffffffe3ffec8.
  The return at 0x1936c has v0 = (a0 << 0x20)+0x9200000001c00000.

- `hub_error_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19374 (928 bytes). Grade: inferred.
  Role (from name): per-node hub error setup. It calls `hub_error_clear` first, calls `get_compact_nodeid`, and indexes the per-node pointer table `kl_error_log` by shifting a node register left by 3. It calls `recover_error_init` twice and calls `cause_intr_connect` with 0x6 in `a0` and `hubpi_eint_handler` in `a1`, on a path that depends on the tested words at 0x9200000001000050 and 0x9200000001000058. It also calls `hubii_eint_init`, `hubni_eint_init` and `spinlock_init`. A loop bounded by `numnodes` (guard at 0x195dc, back branch at 0x19644) holds the two `kmem_zalloc_node` calls (sizes 0x1938 and 0x40). `assfail` is called with 0x9b, 0xa4 and 0xa5 in `a2`.
  Reviewed: 2026-11-12

- `hub_error_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19374
  **Inferred.** Role (from facts): a boot-time set-up for the hub error log [call 1, call 8, call 9]. It calls `hub_error_clear` for the node [call 1]. When `a0` is zero the branch at 0x193a0 goes to 0x195c8 [@0x193a0 taken zero], which allocates two buffers per node with `kmem_zalloc_node` [call 8, @0x193a0 taken] [call 9, @0x193a0 taken] while the index is below `numnodes` [@0x19644 taken]. It calls `hubii_eint_init` on the taken side of the branch at 0x19568 [call 6, @0x19568 taken].
  Reviewed: 2026-11-12

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** Role (from name): sets up the hub II error interrupt for one node. It loads halfwords at 0x197fc and 0x19804, calls `hwgraph_info_get_LBL` (0x19754) and `intr_heuristic` (0x197a0), and calls `intr_connect_level` (0x197d0) with `hubii_eint_handler` as its fourth argument. Failure paths call `cmn_err` (0x1986c) and `assfail`, which receives 0x135 (0x19854) and 0x153 (0x19888) as its third argument. Two 8-byte stores (0x19824, 0x19844) write to addresses the facts do not resolve, and what they hold is not established.
  Reviewed: 2026-11-12

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** The routine calls hwgraph_info_get_LBL at 0x19754, then intr_heuristic at 0x197a0 (a1 = 0x0, a2 = -0x1, a3 = 0x4), then intr_connect_level at 0x197d0 with hubii_eint_handler in a3. The facts do not show the label result being passed to intr_heuristic. When the intr_heuristic result equals -1 the branch at 0x197b4 goes to 0x19864, where the cmn_err call at 0x1986c (level 0x14) sits. When intr_connect_level returns a negative value the branch at 0x197d8 goes to 0x1987c; the facts do not show what is there. It stores two doublewords (sd at 0x19824, 0x19844), and calls assfail at 0x19854 and 0x19888 with the constants 0x135 and 0x153. Role (from name): HUB II error interrupt setup; the facts show the call sequence but not the target addresses of the stores.
  Reviewed: 2026-11-12

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** Role (from facts): interrupt connection for the hub II error handler [call 1, call 3]. It looks up a hwgraph label [call 1], runs `intr_heuristic` [call 2, @0x1977c fall] and connects the handler `hubii_eint_handler` in a3 with `intr_connect_level` [call 3, @0x197b4 fall]. The branch at 0x197d8 goes to 0x1987c when the connect result is negative [@0x197d8 taken].
  Reviewed: 2026-11-12

- `hubni_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19898 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x19898-0x199a8 (272 bytes).
  It occupies 272 bytes.
  The `jal` at 0x198a4 calls cnodetocpu with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x198d8 calls intr_connect_level with a0=?, a1=0x7e, a2=0x0, a3=sym(hubni_eint_handler), a4=0x0, a5=0x0.
  The `jal` at 0x19904 calls cnode_slice_to_cpuid with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x19928 calls cpu_enabled with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x19948 calls intr_connect_level with a0=?, a1=?, a2=0x0, a3=sym(hubni_rmteint_handler), a4=0x0, a5=0x0.
  The `jal` at 0x19984 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=?, a3=?.
  The `jal` at 0x19998 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=?, a3=?.
  The `beq` branch at 0x198b8 targets 0x19960, is taken when v0(=ret(cnodetocpu)) == at(=-0x1), and falls through when v0(=ret(cnodetocpu)) != at(=-0x1).
  The `bne` branch at 0x198e0 targets 0x1997c, is taken when v0(=ret(intr_connect_level)) != 0, and falls through when v0(=ret(intr_connect_level)) == 0.
  The `beq` branch at 0x198e8 targets 0x19900 and is always taken.
  The `beq` branch at 0x198f8 targets 0x19960, is taken when s0(?) >= 0x2 (signed), and falls through when s0(?) < 0x2 (signed).
  The `bltz` branch at 0x19918 targets 0x198f0, is taken when s2(?) < 0 (signed), and falls through when s2(?) >= 0 (signed).
  The `beq` branch at 0x19920 targets 0x198f0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x19930 targets 0x198f0, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beql` branch at 0x19950 targets 0x198f4, is taken when v0(=ret(intr_connect_level)) == 0, and falls through when v0(=ret(intr_connect_level)) != 0; its branch-likely delay slot `addiu s0,s0,1` at 0x19954 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x19958 targets 0x19994 and is always taken.
  The `beq` branch at 0x1998c targets 0x198e8 and is always taken.
  The `beq` branch at 0x199a0 targets 0x198f4 and is always taken.
  The return at 0x19974 has v0 = one of ret(cnodetocpu), ?.

- `hubpi_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x199a8 (728 bytes). Grade: inferred.
  Role (from name): a processor-interface error interrupt handler. It calls `check_ni_errors` first and calls `hubni_error_handler` when that returns nonzero. It then loads a halfword, a doubleword at +0x8 and a byte at +0x520, and tests the loaded word against masks 0xcfff00, 0x1 or 0x2, 0x40 or 0x80, 0x10 or 0x20, 0x100000 or 0x200000 and 0x4 or 0x8. It calls `log_md_errors` when a signed value tested at 0x19a24 is negative and `process_error_spool` three times under mask tests. When the 0xcfff00 mask matches it calls `enter_panic_mode`, `cmn_err` (level 0x14) and `kl_panic`. The meaning of each mask is not established.
  Reviewed: 2026-11-12

- `hubpi_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x199a8
  **Inferred.** A 728-byte handler for the hub PI error interrupt. It calls `check_ni_errors` [call 1]. When that result is nonzero, the branch at 0x199c0 falls through [@0x199c0 fall nonzero] to `hubni_error_handler` [call 2]. When the status word masked with 0xcfff00 is nonzero the branch at 0x19a1c goes to `enter_panic_mode` [call 8, @0x19a1c taken nonzero]. Role (from name): the hub PI error interrupt handler. The facts do not show the meaning of each mask bit.
  Reviewed: 2026-11-12

- `hubni_print_state` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19c80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x19c80-0x19dc0 (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x19c94 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x19c98 loads 2 bytes from abs 0xffffffffffffc422.
  The `ld` at 0x19ca0 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x19cc4 loads 8 bytes from ([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3)) +0x0.
  The `ll` at 0x19ccc loads 4 bytes from [([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8 +0x53d8.
  The `sc` at 0x19cd4 stores 4 bytes to [([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8 +0x53d8.
  The `lbu` at 0x19d50 loads 1 byte from [([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8 +0x49a8.
  The `lh` at 0x19d6c loads 2 bytes from [([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8 +0x49aa.
  The `ld` at 0x19d94 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe1f7ff8.
  The `jal` at 0x19d24 calls mutex_spintrylock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x19d3c calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x19d4c calls get_slotname with a0=[[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+18856]:1, a1=sp-184, a2=?, a3=?.
  The `jalr` at 0x19d5c calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+24888, a2=?, a3=?.
  The `jalr` at 0x19d70 calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+24888, a2=[[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+18858]:2, a3=sp-184.
  The `jal` at 0x19d90 calls show_ni_port_error with a0=[(a0 << 0x20)-7926335344140582904]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x19da0 calls us_delay with a0=0x1, a1=ret(mutex_spintrylock), a2=?, a3=?.
  The `beq` branch at 0x19cc0 targets 0x19d08, is taken when a3 == at(=0x2), and falls through when a3 != at(=0x2).
  The `beql` branch at 0x19cd8 targets 0x19ccc, is taken when ra(=([[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+21464] | a3)) == 0, and falls through when ra(=([[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+21464] | a3)) != 0; its branch-likely delay slot `nop` at 0x19cdc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x19ce4 targets 0x19d4c, is taken when (t8(=[[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+21464]) & s7(=a3)) == 0, and falls through when (t8(=[[([[-0x3c00]:8]:8 + ([-0x3bde]:2 << 0x3))]:8+21464]) & s7(=a3)) != 0.
  The `beq` branch at 0x19d1c targets 0x19d3c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x19d30 targets 0x19da0, is taken when v0(=ret(mutex_spintrylock)) == 0, and falls through when v0(=ret(mutex_spintrylock)) != 0.
  The `beq` branch at 0x19d44 targets 0x19ccc and is always taken.
  The `beq` branch at 0x19d98 targets 0x19cf0 and is always taken.
  The `bne` branch at 0x19db0 targets 0x19d24, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x19db8 targets 0x19d38 and is always taken.
  The return at 0x19d00 has v0 = one of ?, ret(show_ni_port_error).

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0 (604 bytes). Grade: inferred.
  It reads the status doubleword at 0x9200000001608008 and the doublewords at 0x9200000001600000, 0x9200000001600010 and 0x92000000010000a0. It tests a long list of bit masks, from 0x30000000 up to 0x10000000000, and reports the set ones with `cmn_err`. It calls `protected_broadcast` with codes 0x67 and 0x68, and returns 0 or 1. Which hardware bit each mask stands for is not established here. Role (from name): a network-interface error check.
  Reviewed: 2026-11-12

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** Role (from name): scans network-interface status words. The facts show loads from fixed addresses 0x9200000001608008 (0x19dd0), 0x9200000001600000 (0x19dec), 0x9200000001600010 (0x19e60, 0x19f48) and 0x92000000010000a0 (0x19e14, 0x19e24), tested against bit masks, and further loads at 0x19e88 and 0x19f70 whose addresses are not resolved. Several mask hits call `cmn_err` (levels 0x14 and 0x15, 0x19e7c to 0x1a00c). `protected_broadcast` is called twice in a row, with 0x67 and then 0x68 (0x19f2c, 0x19f34), reached by falling through the last mask test at 0x19f24. The bit each mask stands for, such as 0x3eff000000 or 0xf0000000, is not established.
  Reviewed: 2026-11-12

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** The routine loads from 0x9200000001608008, 0x9200000001600000, 0x92000000010000a0 and 0x9200000001600010. It tests bit masks from the constants 0x3eff000000, 0x30000000, 0x8000000000, 0x10000000000, 0x2000000000, 0x1000000000, 0x800000000, 0x400000000, 0x200000000, 0xf0000000 and 0xf000000 (bne and beq at 0x19de8 through 0x19f24), and calls cmn_err at twelve sites, several of them on a set mask bit. It calls protected_broadcast with 0x67 and 0x68 at 0x19f2c and 0x19f34. Role (from name): an NI error scan; which register is which is inferred from the addresses.
  Reviewed: 2026-11-12

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** A 604-byte routine that reads the doubleword at the fixed address 0x9200000001608008 [@0x19dd0] and the doubleword at 0x9200000001600000 [@0x19dec]. When the first, masked with 0x3eff000000, is nonzero the branch at 0x19de8 goes to 0x19e48 [@0x19de8 taken nonzero]. The return at 0x19e40 yields one of two constants [@0x19e40]. It calls `cmn_err` [call 1]. Role (from name): an NI error check. The facts do not show what each reported bit means.
  Reviewed: 2026-11-12

- `hubni_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a01c (392 bytes). Grade: inferred.
  It reads the status doubleword at 0x9200000001608008 and the doubleword at 0x9200000001600010. It calls `splerr`, then `set_node_panic_flag` only when the byte at `-0x3add` is nonzero, `hubni_print_state`, `router_print_state`, `ip27log_printf` and `enter_panic_mode`. It also calls `enter_promlog_mode` and `panicspin` on some paths. Its stores (at 0x1a0c0 and 0x1a170) have unresolved targets. Which branch is the panic path and which only logs is inferred from the callee names.
  Reviewed: 2026-11-12

- `hubni_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1a4
  **Inferred.** A thin interrupt entry that calls `hubni_error_handler` (0x1a1b4) with flag 1, passes its own a2 and a3 through, and returns the callee's result. The flag is probably the local-versus-remote choice, which the twin entry below suggests but the facts do not show.
  Reviewed: 2026-11-12

- `hubni_rmteint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1c8
  **Inferred.** Role (from name): the remote-interrupt twin of `hubni_eint_handler`. It calls `hubni_error_handler` (0x1a1d8) with flag 0 and returns its result. The two entries differ only in that flag.
  Reviewed: 2026-11-12

- `hubni_rmteint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1c8
  **Inferred.** Role (from facts): a forwarder to `hubni_error_handler` [call 1] that returns the value that call gives back [@0x1a1e4]. The routine adds no logic of its own in the facts.
  Reviewed: 2026-11-12

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** Calls `find_lboard` (type 0x11, 0x1a24c), then `find_first_component` (class 2, 0x1a260) on its result. It loads a word at +0x48 (0x1a20c) and passes its own `a2` through to `find_lboard`. It then compares `a1` with 2, 1, 3 and 4 (0x1a2a4 to 0x1a2c0) and stores 8-byte words on the path each match selects (0x1a2e4 to 0x1a324). The stored register set and the meaning of those four values are not established.
  Reviewed: 2026-11-12

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** The routine calls find_lboard at 0x1a24c (a1 = 0x11) and, when that returns nonzero, find_first_component at 0x1a260 (a1 = 0x2); a zero result from either, or a zero at 0x1a29c, goes to 0x1a2c8 (beq at 0x1a254, 0x1a274, 0x1a29c). It then compares a1 with 0x2, 0x1, 0x3 and 0x4 in that order (beq at 0x1a2a4 through 0x1a2c0) to pick a path. The facts show eight sd stores (0x1a2e4 and later) and four doubleword loads (ld at 0x1a2e8, 0x1a2fc, 0x1a30c, 0x1a31c) spread over those paths, not all taken on one call. Role (from name): saving MD registers; the mapping of a1 values to paths is inferred from the comparisons.
  Reviewed: 2026-11-12

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** A 316-byte routine that finds a board record with `find_lboard` [call 1] and a component in it with `find_first_component` [call 2, @0x1a254 fall]. When either lookup returns zero the branches at 0x1a254 and 0x1a274 go to 0x1a2c8 [@0x1a254 taken zero] [@0x1a274 taken zero]. It then compares `a1` with 2, 1, 3 and 4 in turn [@0x1a2a4] [@0x1a2ac] [@0x1a2b8] [@0x1a2c0], and stores to memory at 0x1a2e4 [@0x1a2e4] only when `a1` equals 4 [@0x1a2c0 taken]. Role (from name): saves machine-dependent registers. The facts do not show which registers, or the record layout.
  Reviewed: 2026-11-12

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** Role (from name): walks memory-directory error entries for one node, starting from the `kl_error_log` slot selected through `nasid_to_compact_node` (0x1a63c, 0x1a654). It calls `md_err_log_prev` (0x1a688, and 0x1a73c in a loop closed by the branch at 0x1a74c) and `md_err_log_last` (0x1a84c), and calls `kl_panic` (0x1a730) on one path. The four type values it compares against (0x1a70c to 0x1a724) and the panic condition are not established.
  Reviewed: 2026-11-12

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** The routine indexes the per-node error log through nasid_to_compact_node and kl_error_log (lh at 0x1a63c, ld at 0x1a654), then calls md_err_log_prev at 0x1a688 and, in a loop closed by the bne at 0x1a74c, at 0x1a73c. It calls md_err_log_last at 0x1a84c. It loads a word at 0x1a708 and compares it with 2, 1, 3 and 4 in that order (beq at 0x1a70c through 0x1a724); a value matching none of them falls through to kl_panic at 0x1a730. It returns 0, 1, 2 or 3 (return at 0x1a784). Role (from name): an MD error check; the classes are inferred from the constants.
  Reviewed: 2026-11-12

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** Looks up a compact node index in nasid_to_compact_node (`lh` at 0x1a63c) and takes that node's pointer from kl_error_log (0x1a654). When the record pointer is nonzero (0x1a674), it calls md_err_log_prev at 0x1a688, and calls it again at 0x1a73c, looping back to 0x1a6e4 while that second call returns nonzero (0x1a74c). It also calls md_err_log_last at 0x1a84c. A word loaded at 0x1a708 is compared with 2, 1, 3 and 4 (0x1a70c to 0x1a724), and falling through all four reaches kl_panic at 0x1a730. The meaning of each case is unknown.
  Reviewed: 2026-11-12

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** A 588-byte routine over the per-node error log. It calls `md_err_log_prev` [call 1] and again [call 3]; the branch at 0x1a74c goes back to 0x1a6e4 while the result of the second call is nonzero [@0x1a74c taken nonzero]. After the compares with four constants fall through [@0x1a724 fall] the next call is `kl_panic` [call 2]. It calls `md_err_log_last` [call 4] when the doubleword at `a3` is zero [call 4, @0x1a680 taken zero]. The return at 0x1a784 yields a small code [@0x1a784]. Role (from name): the machine-dependent error check. The facts do not show what the walk reads.
  Reviewed: 2026-11-12

- `md_err_log_first` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a864 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1a864-0x1a8a4 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x1a864 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x1a87c loads 4 bytes from ?.
  The `lw` at 0x1a898 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `beq` branch at 0x1a880 targets 0x1a898, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1a89c targets 0x1a888 and is always taken.
  The return at 0x1a890 has v0 = ?.

- `md_err_log_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a8a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1a8a4-0x1a94c (168 bytes).
  It occupies 168 bytes.
  The `lw` at 0x1a8f0 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x1a93c calls assfail with a0=sym(.rodata)+24888, a1=sym(.rodata)+24888, a2=0x3fe, a3=a3 at entry (arg3).
  The `bltz` branch at 0x1a8d0 targets 0x1a930, is taken when at(?) < 0 (signed), and falls through when at(?) >= 0 (signed).
  The `beq` branch at 0x1a8d8 targets 0x1a930, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1a910 targets 0x1a924, is taken when a1(?) == a2(?), and falls through when a1(?) != a2(?).
  The `beq` branch at 0x1a944 targets 0x1a8e0 and is always taken.
  The return at 0x1a928 has v0 = one of 0x0, ?.

- `md_err_log_last` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a94c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1a94c-0x1a984 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x1a94c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x1a970 loads 4 bytes from ?.
  The return at 0x1a97c has v0 = ?.

- `md_err_log_prev` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a984 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1a984-0x1aa3c (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x1a9cc loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x1aa04 loads 4 bytes from ?.
  The `jal` at 0x1aa2c calls assfail with a0=sym(.rodata)+24888, a1=sym(.rodata)+24888, a2=0x420, a3=a3 at entry (arg3).
  The `bltz` branch at 0x1a9b0 targets 0x1aa20, is taken when at(?) < 0 (signed), and falls through when at(?) >= 0 (signed).
  The `beq` branch at 0x1a9b8 targets 0x1aa20, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1a9f4 targets 0x1aa14, is taken when a1(?) == a2(?), and falls through when a1(?) != a2(?).
  The `beq` branch at 0x1aa34 targets 0x1a9c0 and is always taken.
  The return at 0x1aa18 has v0 = one of 0x0, ?.

- `md_err_log_new` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aa3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1aa3c-0x1aac4 (136 bytes).
  It occupies 136 bytes.
  The `ll` at 0x1aa40 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sc` at 0x1aa4c stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x1aa70 loads 4 bytes from ?.
  The `ld` at 0x1aa80 loads 8 bytes from abs 0x9200000001030100.
  The `ld` at 0x1aa8c loads 8 bytes from ?.
  The `sd` at 0x1aaa8 stores 8 bytes to ?.
  The `beql` branch at 0x1aa50 targets 0x1aa40, is taken when a2(=[a0]+1) == 0, and falls through when a2(=[a0]+1) != 0; its branch-likely delay slot `nop` at 0x1aa54 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1aa84 targets 0x1aab4, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1aaa0 targets 0x1aaac, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1aab4 targets 0x1aaa8, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x1aabc targets 0x1aaac and is always taken.
  The return at 0x1aaac has v0 = ?.

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4 (360 bytes). Grade: inferred.
  It calls `get_nasid` five times, then `find_lboard` with 0x11 in `a1` and, when that returns nonzero, `find_first_component` with 0x2 in `a1`. It reads a word at the `find_first_component` result +0x30, and stores three doublewords to targets the rendering leaves open. Role (from name): saving CPU register state into a spool; the unresolved targets leave that unconfirmed.
  Reviewed: 2026-11-12

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** Role (from name): saves a spool-register set. It calls `get_nasid` five times (0x1aae8 to 0x1ab4c) and does the same board and component lookup as `klsave_md_registers` (`find_lboard` with type 0x11 at 0x1ab8c, `find_first_component` with class 2 at 0x1aba0). It reads a word at +0x48 of an address the facts do not resolve (0x1ab1c, 0x1ab64) and writes three 8-byte words (0x1abf0 to 0x1ac00). The contents of those words, how the `get_nasid` results are used, and the flag tested at 0x1abd4 are not established.
  Reviewed: 2026-11-12

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** The routine makes five get_nasid calls (0x1aae8, 0x1aaf8, 0x1ab3c, 0x1ab44, 0x1ab4c), then calls find_lboard at 0x1ab8c (a1 = 0x11) and, when that returns nonzero, find_first_component at 0x1aba0 (a1 = 0x2). A zero result from either goes to 0x1ac04 (beq at 0x1ab94, 0x1abb8). When bit 0x1 of a2 is clear the branch at 0x1abd4 goes to 0x1ac1c; when it is set the routine tests a value at 0x1abe0 and may store three doublewords (sd at 0x1abf0, 0x1abf8, 0x1ac00) with a doubleword load at 0x1abfc between them. Role (from name): saving spool registers; the save layout is inferred from the stores.
  Reviewed: 2026-11-12

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** A 360-byte routine that calls `get_nasid` [call 1] and looks up a board record with `find_lboard` [call 6]. It calls `find_first_component` [call 7, @0x1ab94 fall] when the board lookup is nonzero. When either lookup returns zero, the branches at 0x1ab94 and 0x1abb8 skip to 0x1ac04 [@0x1ab94 taken zero] [@0x1abb8 taken zero]. It stores to memory from 0x1abf0 to 0x1ac00 [@0x1abf0]. Role (from name): saves spool registers. The facts do not show what they save.
  Reviewed: 2026-11-12

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** Role (from name): fetches the next pending spool entry for a node. It loads fields at +0x1910, +0x1920 and +0x1930 of the node's `kl_error_log` record, stores to +0x1920 and +0x1910 (0x1ad44, 0x1add8), and stores 8-byte words through pointers whose base the facts do not resolve (0x1accc, 0x1acf8, 0x1ada0, 0x1ae7c). It brackets the work with `splerr` and `splx` (0x1ac48, 0x1ae20 to 0x1aec4) and calls `klsave_spool_registers` with `a2` = 2 on one path (0x1aeb4). The ring layout and the flag bytes read at +0x520 are not established.
  Reviewed: 2026-11-12

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** The routine indexes per-CPU data through pdaindr (scaled by 16, with a byte at +0x520) and the node's error log through kl_error_log. It calls splerr at 0x1ac48 and splx on several exits (0x1ae20, 0x1ae80, 0x1ae90, 0x1aea0 and 0x1aec4). It calls klsave_spool_registers at 0x1aeb4 with a2 = 0x2. It compares the doublewords at +6416 and +6432 of the log record the per-CPU byte selects (beq at 0x1acc0 and 0x1ad8c). The address constants 0x9200000001000418, 0x9200000001000420, 0x9200000001000430, 0x9200000001000440, 0x9200000001000448, 0x9200000001000460 and 0x9200000001000468 appear in registers at the splx calls; the facts show no loads from them. Role (from name): returning the next spooled PI error record; what the two compared fields are is not derived.
  Reviewed: 2026-11-12

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** A 680-byte routine on the hub PI error spool. It calls `get_nasid` [call 1] and `splerr` [call 2]. When the doubleword in `a7`, loaded from the `kl_error_log` entry for this node, is zero the branch at 0x1ac80 goes to 0x1ae90 [@0x1ac80 taken zero]. The return at 0x1ae38 yields a small status code [@0x1ae38]. Role (from name): gets the next hub PI spool entry. The facts do not show the entry layout.
  Reviewed: 2026-11-12

- `huberror_process_rrb_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aed4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1aed4-0x1b12c (600 bytes).
  It occupies 600 bytes.
  The `jal` at 0x1af10 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1af18 calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1af2c calls error_check_part_page with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1af40 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0xa, a3=?.
  The `jal` at 0x1af74 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0xa, a3=?.
  The `jal` at 0x1af9c calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1afa4 calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1afb8 calls error_check_part_page with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1afcc calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x1, a3=?.
  The `jal` at 0x1aff4 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1affc calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b010 calls page_isdiscarded with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1b020 calls error_check_part_page with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1b038 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x4, a3=?.
  The `jal` at 0x1b060 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x1, a3=?.
  The `jal` at 0x1b078 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x4, a3=?.
  The `jal` at 0x1b09c calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1b0b8 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1b0d4 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1b0e4 calls membank_pathname_get with a0=a1 at entry (arg1), a1=sp-304, a2=?, a3=?.
  The `jal` at 0x1b0fc calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a1 at entry (arg1), a3=sp-304.
  The `jal` at 0x1b10c calls error_page_discard with a0=a1 at entry (arg1), a1=0x1, a2=0x1, a3=?.
  The `beq` branch at 0x1aeec targets 0x1af90, is taken when a0 == s1(=0x3), and falls through when a0 != s1(=0x3).
  The `beq` branch at 0x1aef8 targets 0x1afe8, is taken when a0 == at(=0x2), and falls through when a0 != at(=0x2).
  The `bne` branch at 0x1af00 targets 0x1b094, is taken when a0 != v0(=0x1), and falls through when a0 == v0(=0x1).
  The `bne` branch at 0x1af24 targets 0x1af70, is taken when a1(?) != v0(=ret(part_id)), and falls through when a1(?) == v0(=ret(part_id)).
  The `beq` branch at 0x1af34 targets 0x1b0ac, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1af88 targets 0x1af58 and is always taken.
  The `bne` branch at 0x1afb0 targets 0x1b05c, is taken when a1(?) != v0(=ret(part_id)), and falls through when a1(?) == v0(=ret(part_id)).
  The `beq` branch at 0x1afc0 targets 0x1b0c8, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1afe0 targets 0x1af58 and is always taken.
  The `bne` branch at 0x1b008 targets 0x1b074, is taken when a1(?) != v0(=ret(part_id)), and falls through when a1(?) == v0(=ret(part_id)).
  The `beq` branch at 0x1b018 targets 0x1b0e4, is taken when v0(=ret(page_isdiscarded)) == 0, and falls through when v0(=ret(page_isdiscarded)) != 0.
  The `beq` branch at 0x1b028 targets 0x1b054, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1b04c targets 0x1af58 and is always taken.
  The `beq` branch at 0x1b054 targets 0x1af5c and is always taken.
  The `beq` branch at 0x1b06c targets 0x1af58 and is always taken.
  The `beq` branch at 0x1b08c targets 0x1af58 and is always taken.
  The `beq` branch at 0x1b0a4 targets 0x1b054 and is always taken.
  The `beq` branch at 0x1b0c0 targets 0x1b054 and is always taken.
  The `beq` branch at 0x1b0dc targets 0x1b054 and is always taken.
  The `beq` branch at 0x1b114 targets 0x1b020, is taken when v0(=ret(error_page_discard)) == 0, and falls through when v0(=ret(error_page_discard)) != 0.
  The `beq` branch at 0x1b11c targets 0x1b020, is taken when v0(=ret(error_page_discard)) == a2(=0x1), and falls through when v0(=ret(error_page_discard)) != a2(=0x1).
  The `beq` branch at 0x1b124 targets 0x1b054 and is always taken.
  The return at 0x1af68 has v0 = ?.

- `huberror_process_wrb_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b12c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1b12c-0x1b358 (556 bytes).
  It occupies 556 bytes.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc422, including `lh` at 0x1b164, `lh` at 0x1b310.
  The `jal` at 0x1b170 calls kl_ioerror_handler with a0=[-0x3bde]:2, a1=[-0x3bde]:2, a2=-0x1, a3=0x6, a4=a1 at entry (arg1), a5=0x0, a6=0x1, a7=0x0.
  The `jal` at 0x1b1a4 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1b1ac calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b1c0 calls error_check_part_page with a0=a1 at entry (arg1), a1=ret(nasid_to_partid), a2=?, a3=?.
  The `jal` at 0x1b1d8 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1b204 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1b20c calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b220 calls error_check_part_page with a0=a1 at entry (arg1), a1=ret(nasid_to_partid), a2=?, a3=?.
  The `jal` at 0x1b238 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1b25c calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1b280 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1b2a4 calls error_check_poisoned_state with a0=a1 at entry (arg1), a1=0x0, a2=0x1, a3=?.
  The `jal` at 0x1b2c4 calls error_check_memory_access with a0=a1 at entry (arg1), a1=0x1, a2=0x0, a3=?.
  The `jal` at 0x1b2f4 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a0 at entry (arg0), a3=a3 at entry (arg3), a6=0x1.
  The `jal` at 0x1b314 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a1 at entry (arg1), a3=[-0x3bde]:2.
  The `jal` at 0x1b32c calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a1 at entry (arg1), a3=?, a5=0x3.
  The `jal` at 0x1b348 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a1 at entry (arg1), a3=?.
  The `beq` branch at 0x1b140 targets 0x1b198, is taken when a0 == v0(=0x3), and falls through when a0 != v0(=0x3).
  The `beq` branch at 0x1b148 targets 0x1b1f8, is taken when a0 == 0, and falls through when a0 != 0.
  The `bne` branch at 0x1b150 targets 0x1b2ec, is taken when a0 != at(=0x1), and falls through when a0 == at(=0x1).
  The `bne` branch at 0x1b178 targets 0x1b304, is taken when v0(=ret(kl_ioerror_handler)) != 0, and falls through when v0(=ret(kl_ioerror_handler)) == 0.
  The `bne` branch at 0x1b1b8 targets 0x1b258, is taken when a1(=ret(nasid_to_partid)) != v0(=ret(part_id)), and falls through when a1(=ret(nasid_to_partid)) == v0(=ret(part_id)).
  The `beq` branch at 0x1b1c8 targets 0x1b2a0, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1b1f0 targets 0x1b184 and is always taken.
  The `bne` branch at 0x1b218 targets 0x1b27c, is taken when a1(=ret(nasid_to_partid)) != v0(=ret(part_id)), and falls through when a1(=ret(nasid_to_partid)) == v0(=ret(part_id)).
  The `beq` branch at 0x1b228 targets 0x1b2c0, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1b250 targets 0x1b184 and is always taken.
  The `beq` branch at 0x1b274 targets 0x1b184 and is always taken.
  The `beq` branch at 0x1b298 targets 0x1b184 and is always taken.
  The `beq` branch at 0x1b2b0 targets 0x1b324, is taken when v0(=ret(error_check_poisoned_state)) == a5(=0x3), and falls through when v0(=ret(error_check_poisoned_state)) != a5(=0x3).
  The `beq` branch at 0x1b2b8 targets 0x1b180 and is always taken.
  The `beq` branch at 0x1b2cc targets 0x1b33c, is taken when v0(=ret(error_check_memory_access)) == 0, and falls through when v0(=ret(error_check_memory_access)) != 0.
  The `beq` branch at 0x1b2e4 targets 0x1b180 and is always taken.
  The `beq` branch at 0x1b2fc targets 0x1b180 and is always taken.
  The `beq` branch at 0x1b31c targets 0x1b180 and is always taken.
  The `beq` branch at 0x1b334 targets 0x1b180 and is always taken.
  The `beq` branch at 0x1b350 targets 0x1b180 and is always taken.
  The return at 0x1b190 has v0 = one of ?, 0x0, 0xc, 0xf, 0xb, 0xe.

- `huberror_process_stack_entry` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b358 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1b358-0x1b418 (192 bytes).
  It occupies 192 bytes.
  The `sd` at 0x1b3b8 stores 8 bytes to a3 (arg3 at entry) +0x0.
  The `jal` at 0x1b3a8 calls huberror_process_wrb_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b3e8 calls huberror_process_rrb_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b400 calls cmn_err with a0=0x14, a1=sym(.rodata)+24888, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x2.
  The `beq` branch at 0x1b374 targets 0x1b3d0, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `bne` branch at 0x1b37c targets 0x1b3f8, is taken when a2 != a6(=0x2), and falls through when a2 == a6(=0x2).
  The `beq` branch at 0x1b3a0 targets 0x1b3e8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x1b3e0 targets 0x1b3a8, is taken when (t8(?) & 0x1) != 0, and falls through when (t8(?) & 0x1) == 0.
  The `beq` branch at 0x1b3f0 targets 0x1b3b4 and is always taken.
  The `beq` branch at 0x1b410 targets 0x1b3a0 and is always taken.
  The return at 0x1b3c8 has v0 = one of ret(huberror_process_wrb_error), ret(huberror_process_rrb_error).

- `hubiio_crb_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b810 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1b810-0x1b8b0 (160 bytes).
  It occupies 160 bytes.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0xa, including `lh` at 0x1b814, `lh` at 0x1b840, `lh` at 0x1b854.
  The `ld` at 0x1b834 loads 8 bytes from ((a1 << 0x5) + ([a0+10]:2 << 0x20)) -0x6dfffffffe3ffc00.
  The `sd` at 0x1b83c stores 8 bytes to ((a1 << 0x5) + ([a0+10]:2 << 0x20)) -0x6dfffffffe3ffc00.
  The `sd` at 0x1b850 stores 8 bytes to ([a0+10]:2 << 0x20) -0x6dfffffffe3ffc70.
  2 such `ld` accesses load 8 bytes from ([a0+10]:2 << 0x20) -0x6dfffffffe3ffc70, including `ld` at 0x1b860, `ld` at 0x1b88c.
  The `jal` at 0x1b878 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1b870 targets 0x1b89c, is taken when (at(=[([a0+10]:2 << 0x20)-7926335344142711920]:8) & 0x10) == 0, and falls through when (at(=[([a0+10]:2 << 0x20)-7926335344142711920]:8) & 0x10) != 0.
  The `bne` branch at 0x1b894 targets 0x1b878, is taken when (a5(=[([a0+10]:2 << 0x20)-7926335344142711920]:8) & 0x10) != 0, and falls through when (a5(=[([a0+10]:2 << 0x20)-7926335344142711920]:8) & 0x10) == 0.
  The return at 0x1b8a8 has v0 = one of (a1 | 0x10), ret(us_delay).

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** Role (from name): an error handler for a hub I/O CRB error. It takes the lock at `a1+796` with `mutex_spinlock_spl` (0x1b8fc), then compares unresolved values with 1, 5, 1 and 2 (0x1ba08 to 0x1ba28). After a bound check on a value below 8 (0x1bac4) it makes a table load (0x1bacc) whose use the facts do not resolve. It calls `bte_crb_error_handler` (0x1ba4c), `hubiio_crb_free` (0x1ba58), `mutex_spinunlock` (0x1ba7c) and `sn0_error_dump` (0x1bb08), and calls `cmn_err` and `assfail` (0x70c as its third argument). Which comparison reaches which handler is not established.
  Reviewed: 2026-11-12

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** The routine takes a spinlock on a1+796 with mutex_spinlock_spl at 0x1b8fc and releases it with mutex_spinunlock at 0x1ba7c. It calls bte_crb_error_handler at 0x1ba4c and hubiio_crb_free at 0x1ba58, calls sn0_error_dump at 0x1bb08 with a1 = 0x20000000, and calls cmn_err at 0x1bb1c, 0x1bbd0 and 0x1bbf0 and assfail at 0x1bbac (a2 = 0x70c). It compares a6 with 0x1, 0x5, 0x1 and 0x2 (beq and bne at 0x1ba08 through 0x1ba28). A branch at 0x1bac4 sends an unsigned s8 of 0x8 or more to 0x1bb04, and the sn0_error_dump call carries a table reference in a6. The facts show no indirect jump; the per-case roles are not derived, and the locking and cleanup sequence is inferred from the calls.
  Reviewed: 2026-11-12

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** Takes a spinlock at offset 796 of the structure in a1 (mutex_spinlock_spl at 0x1b8fc) and releases it with mutex_spinunlock at 0x1ba7c. It compares values with 1, 2 and 5 (0x1ba08, 0x1ba10, 0x1ba20, 0x1ba28) and with a loop bound of 0xf (0x1b994). On one path it calls bte_crb_error_handler (0x1ba4c) and hubiio_crb_free (0x1ba58). It calls sn0_error_dump at 0x1bb08 and cmn_err at 0x1bb1c, 0x1bbd0 and 0x1bbf0. An assfail call at 0x1bbac passes 0x70c as its third argument. The jump table at 0x1bad0 has unresolved targets, so the full set of cases is unknown.
  Reviewed: 2026-11-12

- `hubii_prb_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1bc30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1bc30-0x1bc88 (88 bytes).
  It occupies 88 bytes.
  The `lh` at 0x1bc48 loads 2 bytes from a1 (arg1 at entry) +0xa.
  The `sd` at 0x1bc84 stores 8 bytes to ([a1+10]:2 << 0x20) -0x6dfffffffe3ffe08.
  The `jal` at 0x1bc54 calls cmn_err with a0=0x4, a1=sym(.rodata)+24888, a2=[a1+10]:2, a3=a2 at entry (arg2).
  The return at 0x1bc80 has v0 = ?.

- `hubiio_prb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1bc88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1bc88-0x1bd54 (204 bytes).
  It occupies 204 bytes.
  The `lh` at 0x1bc94 loads 2 bytes from a1 (arg1 at entry) +0xa.
  The `ld` at 0x1bcac loads 8 bytes from ([a1+10]:2 << 0x20) -0x6dfffffffe3ffe68.
  The `ld` at 0x1bce0 loads 8 bytes from ?.
  The `jal` at 0x1bd30 calls hubii_prb_handler [0x1bc30] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1bd44 calls hubii_prb_handler [0x1bc30] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `bltz` branch at 0x1bcc0 targets 0x1bd40, is taken when at(=([([a1+10]:2 << 0x20)-7926335344142712424]:8 << 0xf)) < 0 (signed), and falls through when at(=([([a1+10]:2 << 0x20)-7926335344142712424]:8 << 0xf)) >= 0 (signed).
  The `bltz` branch at 0x1bce8 targets 0x1bd24, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `bne` branch at 0x1bcf8 targets 0x1bcd4, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `beq` branch at 0x1bd38 targets 0x1bcf4 and is always taken.
  The `beq` branch at 0x1bd4c targets 0x1bccc and is always taken.
  The return at 0x1bd1c has v0 = ?.

- `hubii_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1bd54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1bd54-0x1beb4 (352 bytes).
  It occupies 352 bytes.
  4 such `lh` accesses load 2 bytes from ?, including `lh` at 0x1bda4, `lh` at 0x1bde0, `lh` at 0x1be00.
  The `ld` at 0x1bdb4 loads 8 bytes from table(0x9200000001c00008) +0x0.
  The `sd` at 0x1bdf8 stores 8 bytes to table(0x9200000001c001f8) +0x0.
  The `ld` at 0x1be14 loads 8 bytes from table(0x9200000001c00138) +0x0.
  The `sd` at 0x1be2c stores 8 bytes to table(0x9200000001c00138) +0x0.
  The `ld` at 0x1be74 loads 8 bytes from table(0x9200000001c001e8) +0x0.
  The `jal` at 0x1bd60 calls check_ni_errors with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1bd78 calls hubni_error_handler with a0=sym(.rodata)+24888, a1=0x1, a2=?, a3=?.
  The `jal` at 0x1bd94 calls hwgraph_info_get_LBL with a0=(a0 << 0x0), a1=sym(.rodata)+24888, a2=sp-32, a3=?.
  The `jal` at 0x1bdc8 calls hubiio_crb_error_handler with a0=(a0 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x1bdd4 calls hubiio_prb_error_handler with a0=(a0 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x1be40 calls cmn_err with a0=0x0, a1=sym(.rodata)+24888, a2=?, a3=sym(.rodata)+24888, a6=sym(.rodata)+24888.
  The `beq` branch at 0x1bd68 targets 0x1bd80, is taken when v0(=ret(check_ni_errors)) == 0, and falls through when v0(=ret(check_ni_errors)) != 0.
  The `bltz` branch at 0x1bdbc targets 0x1be30, is taken when t8(=(entry(0x9200000001c00008) << 0x1f)) < 0 (signed), and falls through when t8(=(entry(0x9200000001c00008) << 0x1f)) >= 0 (signed).
  The `bgez` branch at 0x1be30 targets 0x1be50, is taken when t0(=(entry(0x9200000001c00008) << 0x36)) >= 0 (signed), and falls through when t0(=(entry(0x9200000001c00008) << 0x36)) < 0 (signed).
  The `beq` branch at 0x1be48 targets 0x1bdc4 and is always taken.
  The `bgez` branch at 0x1be54 targets 0x1be64, is taken when t1(=(entry(0x9200000001c00008) << 0x39)) >= 0 (signed), and falls through when t1(=(entry(0x9200000001c00008) << 0x39)) < 0 (signed).
  The `beq` branch at 0x1be5c targets 0x1be38 and is always taken.
  The `bgez` branch at 0x1be64 targets 0x1be74, is taken when t2(=(entry(0x9200000001c00008) << 0x3a)) >= 0 (signed), and falls through when t2(=(entry(0x9200000001c00008) << 0x3a)) < 0 (signed).
  The `beq` branch at 0x1be6c targets 0x1be38 and is always taken.
  The `beq` branch at 0x1be7c targets 0x1be8c, is taken when (a0(=entry(0x9200000001c001e8)) & 0x1) == 0, and falls through when (a0(=entry(0x9200000001c001e8)) & 0x1) != 0.
  The `beq` branch at 0x1be84 targets 0x1be38 and is always taken.
  The `beq` branch at 0x1be8c targets 0x1be9c, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x1be94 targets 0x1be38 and is always taken.
  The `beq` branch at 0x1be9c targets 0x1beac, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x1bea4 targets 0x1be38 and is always taken.
  The `beq` branch at 0x1beac targets 0x1be38 and is always taken.
  The return at 0x1be28 has v0 = ret(hubiio_prb_error_handler).

- `hub_error_status_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1beb4 (96 bytes). Grade: inferred.
  It reads the doubleword at 0x9200000001000020 (a zero test skips one path), then the doublewords at 0x9200000001000450 and 0x9200000001000430, each tested against bit 63. On one path it calls `_badaddr_val` with 0x9200000002400208 in `a0` and 8 in `a1`. It returns either the `_badaddr_val` result or a value the rendering leaves unresolved. Role (from name): a workaround for a hub status quirk, with the quirk not shown.
  Reviewed: 2026-11-12

- `hub_error_status_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1beb4
  **Inferred.** A 96-byte routine that loads the doubleword at the fixed address 0x9200000001000020 [@0x1beb8]. When it is zero the branch at 0x1bec4 goes to 0x1bee8 [@0x1bec4 taken zero], where it loads the doubleword at 0x9200000001000430 [@0x1beec]; when it is nonzero it loads the doubleword at 0x9200000001000450 [@0x1bed0]. Each path tests bit 63 of the second doubleword [@0x1bed8] [@0x1bef4]. When that bit is clear the routine calls `_badaddr_val` on the address 0x9200000002400208 [call 1, @0x1bef4 fall]. Role (from name): a status check that works around a hardware erratum. The facts do not show the workaround.
  Reviewed: 2026-11-12

- `ii_llp_error_monitor` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1bf14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1bf14-0x1bf7c (104 bytes).
  It occupies 104 bytes.
  The `ld` at 0x1bf18 loads 8 bytes from abs 0x9200000001400130.
  The `sd` at 0x1bf28 stores 8 bytes to abs 0x9200000001400130.
  The `ld` at 0x1bf34 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x1bf3c stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `ld` at 0x1bf48 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0x1bf50 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `lbu` at 0x1bf5c loads 1 byte from a0 (arg0 at entry) +0x10.
  The `sb` at 0x1bf68 stores 1 byte to a0 (arg0 at entry) +0x10.
  The `lbu` at 0x1bf6c loads 1 byte from a0 (arg0 at entry) +0x11.
  The `sb` at 0x1bf78 stores 1 byte to a0 (arg0 at entry) +0x11.
  The `beq` branch at 0x1bf2c targets 0x1bf5c, is taken when a4(=0xffff) == a3(?), and falls through when a4(=0xffff) != a3(?).
  The `beq` branch at 0x1bf40 targets 0x1bf6c, is taken when a4(=0xffff) == a2(?), and falls through when a4(=0xffff) != a2(?).
  The `beq` branch at 0x1bf64 targets 0x1bf40 and is always taken.
  The return at 0x1bf54 has v0 = ?.
  The return at 0x1bf74 has v0 = ?.

- `ni_llp_error_monitor` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1bf7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1bf7c-0x1c040 (196 bytes).
  It occupies 196 bytes.
  The `ld` at 0x1bf84 loads 8 bytes from abs 0x9200000001608008.
  The `ld` at 0x1bfa0 loads 8 bytes from abs 0x9200000001608088.
  The `ld` at 0x1bfbc loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x1bfc4 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `ld` at 0x1bfd0 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0x1bfd8 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `ld` at 0x1bfe4 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `sd` at 0x1bfec stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `lbu` at 0x1bff8 loads 1 byte from a0 (arg0 at entry) +0x18.
  The `sb` at 0x1c004 stores 1 byte to a0 (arg0 at entry) +0x18.
  The `lbu` at 0x1c008 loads 1 byte from a0 (arg0 at entry) +0x19.
  The `sb` at 0x1c014 stores 1 byte to a0 (arg0 at entry) +0x19.
  The `lbu` at 0x1c018 loads 1 byte from a0 (arg0 at entry) +0x1a.
  The `sb` at 0x1c024 stores 1 byte to a0 (arg0 at entry) +0x1a.
  The `jal` at 0x1c030 calls cmn_err with a0=0x4, a1=sym(.rodata)+24888, a2=[0x9200000001608008]:8, a3=a3 at entry (arg3), a5=0x9200000001608088.
  The `bne` branch at 0x1bf98 targets 0x1c028, is taken when (a2(=[0x9200000001608008]:8) & at(=0x3e00000000)) != 0, and falls through when (a2(=[0x9200000001608008]:8) & at(=0x3e00000000)) == 0.
  The `beq` branch at 0x1bfb4 targets 0x1bff8, is taken when a6(=0xff) == a4(?), and falls through when a6(=0xff) != a4(?).
  The `beq` branch at 0x1bfc8 targets 0x1c008, is taken when a6(=0xff) == a3(?), and falls through when a6(=0xff) != a3(?).
  The `beq` branch at 0x1bfdc targets 0x1c018, is taken when a6(=0xff) == a4(?), and falls through when a6(=0xff) != a4(?).
  The `beq` branch at 0x1c000 targets 0x1bfc8 and is always taken.
  The `beq` branch at 0x1c010 targets 0x1bfdc and is always taken.
  The `beq` branch at 0x1c020 targets 0x1bff0 and is always taken.
  The `beq` branch at 0x1c038 targets 0x1bff0 and is always taken.
  The return at 0x1bff0 has v0 = one of ?, ret(cmn_err).

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** A periodic monitor for one node. It reads the node's `kl_error_log` record (0x1c058 to 0x1c08c), calls `ii_llp_error_monitor` on the record at +8 (0x1c074) and `ni_llp_error_monitor` on the record at +32 (0x1c080), and re-arms itself with `timeout` at 0x64 (0x1c0a0) when a word it loaded is non-zero (0x1c090). The unit of the 0x64 interval is not established.
  Reviewed: 2026-11-12

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** The routine finds the node's error record through nasid_to_compact_node and kl_error_log (lh at 0x1c058, ld at 0x1c06c). It calls ii_llp_error_monitor at 0x1c074 on the record at +8 and ni_llp_error_monitor at 0x1c080 on the record at +32. It calls timeout at 0x1c0a0 with hub_error_count_update itself and the constant 0x64 in a2, but only when the first word of the record is nonzero (beq at 0x1c090). Role (from name): a periodic error monitor; the unit of the timeout is not derived.
  Reviewed: 2026-11-12

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** A 120-byte periodic routine. It calls `ii_llp_error_monitor` [call 1] and `ni_llp_error_monitor` [call 2] for the node in the error log. It re-arms itself through `timeout` [call 3, @0x1c090 fall] with 0x64 as the third argument, only when the word at the error-log record is nonzero [@0x1c090 fall nonzero]. Role (from name): counts hub error events on a timer. The facts do not show what the counters hold.
  Reviewed: 2026-11-12

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** Role (from name): turns on the error count for one node. It reaches a return of -1 for a negative node index (0x1c0d0), reads the node's `kl_error_log` slot (0x1c0e8 to 0x1c10c), calls `bzero` with 0x40 as its second argument on one branch (0x1c130), stores a 4-byte word (0x1c154), and calls `timeout` with `hub_error_count_update` as its first argument and 0x64 as its third (0x1c150). The value stored and the other `timeout` arguments are not established.
  Reviewed: 2026-11-12

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** A branch at 0x1c0d0 (a0 negative) goes to 0x1c120, one at 0x1c0e0 (a6 zero) goes to 0x1c120, and one at 0x1c0ec (compact ID equals -1) goes to 0x1c128; the facts do not show those targets. The only return the facts show is at 0x1c118, with v0 of -1 or 0, reached when the record's first word is nonzero (beq at 0x1c10c not taken). When that word is zero it clears 0x40 bytes of the record with bzero at 0x1c130 and calls timeout at 0x1c150 with hub_error_count_update, a2 = 0x64 and a3 = 0x1, with a 32-bit store at +0x0 (sw at 0x1c154). Role (from name): enabling per-node error counting; the cleared size and the rescheduling are read from the calls.
  Reviewed: 2026-11-12

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** Role (from name): it arms the hub error counter on a timer. It loads a halfword at 0x1c0e8 [@0x1c0e8] and a doubleword from the error log at 0x1c100 [@0x1c100]. A negative a0 takes the branch at 0x1c0d0 to 0x1c120 [@0x1c0d0 taken]. When the word tested at 0x1c10c is zero, the branch goes to 0x1c130 [@0x1c10c taken zero], where it calls `bzero` [call 1, @0x1c130] and then `timeout` at 0x1c150 [call 2, @0x1c150], and it stores a word at 0x1c154 [@0x1c154] in the delay slot of that call. Its return at 0x1c118 has v0 one of -0x1, 0x0 [@0x1c118]. The facts do not show which counter it arms or how often the timer fires.
  Reviewed: 2026-11-12

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** The disable side of the same per-node counter. It goes to a return of -1 for a negative index (0x1c16c) and at a second early exit whose condition the facts show only as `v1 == 0` (0x1c17c). When the slot word equals -1 (0x1c18c) it skips the store and goes to the return at 0x1c1a8, which the facts show yielding -1 or 0 without saying which belongs to this path. Otherwise it stores a 4-byte word (0x1c1a4). The stored value is not shown, and nothing here cancels the armed `timeout`, so whether it is cancelled elsewhere is not established.
  Reviewed: 2026-11-12

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** The routine returns -1 when a0 is negative (bltz at 0x1c16c) or when v1 is zero (beq at 0x1c17c). Otherwise it stores a 32-bit word at +0x0 of the node's record (sw at 0x1c1a4) and returns from 0x1c1a8 with -1 or 0, or returns -1 from 0x1c1b0 (beq at 0x1c18c picks the first). The routine makes no call, so it does not cancel the timeout that hub_error_count_enable scheduled; the stored word's meaning is not derived.
  Reviewed: 2026-11-12

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** Maps the nasid in a0 to a compact node index through nasid_to_compact_node (`lh` at 0x1c184), then loads that node's record pointer from kl_error_log (0x1c19c). It returns -1 when a0 is negative (0x1c16c) or when v1 is zero (0x1c17c). When the compact index is -1 (0x1c18c) it skips the store. Otherwise it stores a 4-byte word at the start of the record (0x1c1a4). The return at 0x1c1a8 is -1 or 0 and the facts do not say which path gives which. The value stored is unknown.
  Reviewed: 2026-11-12

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** Role (from name): reads the node's error count. It returns 0 for a negative index and for an index of 0x100 or more (0x1c1c0, 0x1c1d4), stores a 4-byte word (0x1c1ec), and returns the 8-byte value from the node's `kl_error_log` slot (0x1c1f8). What the 0x100 bound limits and the meaning of the returned value are not established.
  Reviewed: 2026-11-12

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** The routine returns 0 at 0x1c200 when a0 is negative (bltz at 0x1c1c0) or a0 is 0x100 or more (beq at 0x1c1d4). It returns 0 at 0x1c208 when the compact ID is -1 (beq at 0x1c1e0). Otherwise it stores a 32-bit word (sw at 0x1c1ec; the facts do not show its base register) and returns the kl_error_log table entry for the node (the doubleword loaded at 0x1c1f4, returned at 0x1c1f8), not a field read through it. Role (from name): reading the error count; whether the returned value is the count is not derived.
  Reviewed: 2026-11-12

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** Maps the nasid in a0 to a compact node through nasid_to_compact_node (0x1c1dc). It writes a 4-byte word through the a1 pointer (0x1c1ec) and returns the doubleword in that node's kl_error_log slot (0x1c1f4, 0x1c1f8). It returns 0 when a0 is negative or at least 0x100 (0x1c1c0, 0x1c1d4), and when the compact index is -1 (0x1c1e0). The word written through a1 is unknown.
  Reviewed: 2026-11-12

- `err_int_unblock_mask` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c4c8 (76 bytes). Grade: inferred.
  It loads a halfword, a doubleword at +0x8 and a byte at +0x520, then skips a doubleword store (0x1c4ec) when `a1` is zero. It later loads a doubleword at 0x1c504 and stores a doubleword at 0x1c510 with the same offset (printed as -0x6dffffffff000000) from a base the rendering does not resolve. Role (from name): clearing a mask on an error interrupt; the target addresses are open.
  Reviewed: 2026-11-12

- `err_int_unblock_mask` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c4c8
  **Inferred.** Role (from name): it clears a mask so that error interrupts can be delivered again. A zero a1 takes the branch at 0x1c4e0 to 0x1c4f0 [@0x1c4e0 taken zero], skipping the doubleword store to the fixed address 0x9200000001000400 at 0x1c4ec [@0x1c4ec], which runs only when a1 is nonzero. On both paths it loads a doubleword at 0x1c504 [@0x1c504] and stores a doubleword at 0x1c510 [@0x1c510] at the same address, one built from the byte loaded at 0x1c4dc [@0x1c4dc] and the base 0x9200000001000000. Its return at 0x1c50c returns an unknown value [@0x1c50c]. The facts do not show what value reaches the register, so the meaning of the mask is open.
  Reviewed: 2026-11-12

- `klerror_global_check` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c580 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1c580-0x1c5ec (108 bytes).
  It occupies 108 bytes.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x1c598, `ld` at 0x1c5d8.
  The `ll` at 0x1c5ac loads 4 bytes from sym(_prom_cleared) +0xd8.
  The `sc` at 0x1c5b8 stores 4 bytes to sym(_prom_cleared) +0xd8.
  The `beq` branch at 0x1c58c targets 0x1c5d8, is taken when v0(=[sym(.sdata)+208]:8) == 0, and falls through when v0(=[sym(.sdata)+208]:8) != 0.
  The `beq` branch at 0x1c5a4 targets 0x1c5d8, is taken when at(?) >= v1(=0x1000000) (unsigned), and falls through when at(?) < v1(=0x1000000) (unsigned).
  The `beql` branch at 0x1c5bc targets 0x1c5ac, is taken when a0(=[sym(.sdata)+216]+1) == 0, and falls through when a0(=[sym(.sdata)+216]+1) != 0; its branch-likely delay slot `nop` at 0x1c5c0 runs only when taken and is annulled on fall-through.
  The return at 0x1c5d0 has v0 = one of -0x1, 0x0.
  The return at 0x1c5e4 has v0 = 0x0.

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** Role (from name): decides whether a saved error record for the current processor can be recovered. It reads the per-processor data area through `pdaindr` (0x1c654, flag byte at +0x520 read at 0x1c658) and the node's `kl_error_log` slot (0x1c608). It calls `klerror_global_check` (0x1c678) and `error_check_part_page` (0x1c708). It reads the byte at +0x1810 of the selected record, and stores to +0x1811, +0x1818, +0x1820 and +0x1828 in that record (0x1c704 to 0x1c738). It also calls `cmn_err_tag` (0x1c758, with 0xb54 and 0x14 as its first two arguments) and `assfail` (0x1c76c, with 0xbe as its third). The meaning of the fields and of the flag is not established.
  Reviewed: 2026-11-12

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** The routine reads the error-log entry for the node through kl_error_log (ld at 0x1c608) and the per-CPU record through pdaindr (ld at 0x1c654, lbu at 0x1c658). It calls klerror_global_check at 0x1c678 and error_check_part_page at 0x1c708. Records are indexed by a0 scaled by 32 in the loaded addresses. When register a0 is zero at 0x1c63c it goes to 0x1c768, followed by assfail at 0x1c76c with 0xbe. It calls cmn_err_tag at 0x1c758 with 0xb54 in a0. It returns -1 or 0 at 0x1c69c. Role (from name): a recoverability check; the checks themselves are only partly derived.
  Reviewed: 2026-11-12

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** Role (from name): it decides whether a logged hub error can be recovered from. It calls `klerror_global_check` at 0x1c678 [call 1, @0x1c670 fall nonzero] and `error_check_part_page` at 0x1c708 [@0x1c708]. It loads a doubleword from 0x9200000001030100 at 0x1c6b0 [@0x1c6b0]. When the register tested at 0x1c624 is zero, the branch goes to 0x1c744 [@0x1c624 taken zero]. It calls `cmn_err_tag` at 0x1c758 [@0x1c758]. It calls `assfail` at 0x1c76c [call 4, @0x1c63c taken zero]. Its return at 0x1c69c has v0 one of -0x1, 0x0 [@0x1c69c]. The facts do not show what the threshold comparisons in the error record select.
  Reviewed: 2026-11-12

- `sn0_skip_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c78c
  **Inferred.** Calls `dumptlb` (0x1c794) with the halfword at -0x3be0 as its argument, the same halfword that indexes `pdaindr` in `hubpi_spool_get_next` and `klerror_check_recoverable`, and then branches to itself at 0x1c79c with no exit. The facts show no return after the call, so this is either an intentional halt after the TLB dump or a gap in the rendered facts. Which of the two it is, is not established.
  Reviewed: 2026-11-12

- `sn0_skip_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c78c
  **Inferred.** The routine calls dumptlb at 0x1c794 with a0 loaded from the halfword at the address shown as -0x3be0 and a1, a2 and a3 passed through unchanged; another halfword load sits at 0x1c798. The facts show no return and no further call after the dump. Whether the routine falls off the end of its 24 bytes is not settled by the facts; confirm before relying on it.
  Reviewed: 2026-11-12

- `sn0_error_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c7a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1c7a4-0x1c964 (448 bytes).
  It occupies 448 bytes.
  The `lh` at 0x1c7d8 loads 2 bytes from sym(error_consistency_check) +0x4.
  The `lh` at 0x1c7e8 loads 2 bytes from abs 0xffffffffffffc420.
  The `sh` at 0x1c80c stores 2 bytes to sym(error_consistency_check) +0x4.
  6 such `lw` accesses load 4 bytes from sym(error_consistency_check) +0x0, including `lw` at 0x1c83c, `lw` at 0x1c864, `lw` at 0x1c8b4.
  6 such `sw` accesses store 4 bytes to sym(error_consistency_check) +0x0, including `sw` at 0x1c8a8, `sw` at 0x1c8c0, `sw` at 0x1c8fc.
  The `jal` at 0x1c7ac calls probe_routers with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c7c0 calls printf with a0=sym(.rodata)+28472, a1=?, a2=?, a3=?.
  The `jal` at 0x1c7d0 calls mutex_spinlock with a0=sym(error_consistency_check), a1=?, a2=?, a3=?.
  The `jal` at 0x1c7f4 calls mutex_spinunlock with a0=sym(error_consistency_check), a1=ret(mutex_spinlock), a2=?, a3=?, a4=[-0x3be0]:2, a5=[sym(error_consistency_check)+4]:2.
  The `jal` at 0x1c7fc calls sn0_skip_dump with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c810 calls mutex_spinunlock with a0=sym(error_consistency_check), a1=ret(mutex_spinlock), a2=?, a3=?, a4=[-0x3be0]:2, a5=[sym(error_consistency_check)+4]:2.
  The `jal` at 0x1c818 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c820 calls enter_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c828 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c834 calls kf_hint_set with a0=ret(get_nasid), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1c87c calls exit_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c884 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x1c8ac calls sn0_fru_entry with a0=sym(printf), a1=?, a2=?, a3=?.
  The `jal` at 0x1c8cc calls cmn_err_tag with a0=0xb56, a1=0x14, a2=sym(.rodata)+28472, a3=?.
  The `jal` at 0x1c8e4 calls cmn_err_tag with a0=0xb57, a1=0x14, a2=sym(.rodata)+28472, a3=?.
  The `jal` at 0x1c8f8 calls kl_dump_hw_state with a0=?, a1=?, a2=?, a3=([sym(error_consistency_check)] | 0x1), a4=[sym(error_consistency_check)].
  The `jal` at 0x1c920 calls kl_error_show_dump with a0=sym(.rodata)+28472, a1=sym(.rodata)+28472, a2=?, a3=?.
  The `jal` at 0x1c944 calls cmn_err_tag with a0=0xb55, a1=0x14, a2=sym(.rodata)+28472, a3=?, a4=[sym(error_consistency_check)].
  The `jal` at 0x1c94c calls exit_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c954 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1c7b4 targets 0x1c7c8, is taken when v0(=ret(probe_routers)) == 0, and falls through when v0(=ret(probe_routers)) != 0.
  The `beq` branch at 0x1c7e4 targets 0x1c80c, is taken when a5(=[sym(error_consistency_check)+4]:2) == a1(=-0x1), and falls through when a5(=[sym(error_consistency_check)+4]:2) != a1(=-0x1).
  The `beq` branch at 0x1c7ec targets 0x1c80c, is taken when a4(=[-0x3be0]:2) == a5(=[sym(error_consistency_check)+4]:2), and falls through when a4(=[-0x3be0]:2) != a5(=[sym(error_consistency_check)+4]:2).
  The `beq` branch at 0x1c804 targets 0x1c890 and is always taken.
  The `beq` branch at 0x1c844 targets 0x1c8f4, is taken when (a4(=[sym(error_consistency_check)]) & 0x1) == 0, and falls through when (a4(=[sym(error_consistency_check)]) & 0x1) != 0.
  The `beq` branch at 0x1c84c targets 0x1c938, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1c854 targets 0x1c910, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1c85c targets 0x1c8c4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x1c86c targets 0x1c89c, is taken when (a4(?) & 0x4) == 0, and falls through when (a4(?) & 0x4) != 0.
  The `beq` branch at 0x1c874 targets 0x1c8dc, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1c8a4 targets 0x1c8b8, is taken when t0(=[sym(sn0_fru_enabled)]) == 0, and falls through when t0(=[sym(sn0_fru_enabled)]) != 0.
  The `beq` branch at 0x1c8bc targets 0x1c87c and is always taken.
  The `beq` branch at 0x1c8d4 targets 0x1c868 and is always taken.
  The `beq` branch at 0x1c8ec targets 0x1c87c and is always taken.
  The `beq` branch at 0x1c908 targets 0x1c850 and is always taken.
  The `beq` branch at 0x1c930 targets 0x1c868 and is always taken.
  The `beq` branch at 0x1c95c targets 0x1c890 and is always taken.
  The return at 0x1c894 has v0 = one of ret(sn0_skip_dump), ret(splx).

- `sn0_error_state` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c964 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1c964-0x1c990 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x1c96c calls kl_dump_hw_state with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c97c calls kl_error_show_dump with a0=sym(.rodata)+28472, a1=sym(.rodata)+28472, a2=?, a3=?.
  The return at 0x1c988 has v0 = ret(kl_error_show_dump).

- `handle_io_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d5cc (588 bytes). Grade: inferred.
  Role (from name): a bus-error handler for I/O-space errors. It calls `get_matching_spool_addr` and branches on its result (0, -1, 1, 2). It calls `kl_ioerror_handler` three times with the same argument pattern, and calls `cmn_err_tag` with 0xb6c and 0xb6d in `a0`. It tests the doubleword at 0x9200000001000400 against masks 0x100000 and 0x200000. It also calls `get_nasid`, performs a store with an unresolved target at 0x1d7a8 and returns 1 or 2. The decision tree between those outcomes is not read in full here.
  Reviewed: 2026-11-12

- `handle_io_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d5cc
  **Inferred.** Role (from name): it handles an I/O bus error reported through the hub. It calls `get_matching_spool_addr` at 0x1d628 [@0x1d628]. When that call returns zero, the branch at 0x1d630 goes to 0x1d70c [@0x1d630 taken zero]. It calls `kl_ioerror_handler` three times, at 0x1d6c8 [call 2, @0x1d6c8], 0x1d73c [call 3, @0x1d630 taken zero] and 0x1d7f4 [call 6, @0x1d7f4]. It loads a doubleword at offset 0x110 of a0 [@0x1d6b8]. Its return at 0x1d670 has v0 one of 0x1, 0x2 [@0x1d670]. The facts do not show which error class each of these paths handles.
  Reviewed: 2026-11-12

- `handle_uncac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d818 (1208 bytes). Grade: inferred.
  Role (from name): a bus-error handler for uncached accesses. It calls `get_matching_spool_addr`, `nasid_to_partid` and `part_id`, and it calls `partition_handle_error` with 0x1, 0x5, 0x6, 0x9 and 0xa in `a2`. It also calls `error_check_memory_access`, `error_check_part_page`, `error_check_poisoned_state` and `error_page_discard`, and calls `cmn_err_tag` with codes 0xb6e to 0xb79 in `a0`. The routine appears to classify an uncached bus error as a partition, page or poisoned-memory event. The full decision tree is not read in this batch.
  Reviewed: 2026-11-12

- `handle_uncac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d818
  **Inferred.** Role (from name): it handles an uncached bus error on the hub. It calls `get_matching_spool_addr` at 0x1d84c [@0x1d84c]. When the result is zero, the branch at 0x1d854 goes to 0x1d934 [@0x1d854 taken zero]. It calls `partition_handle_error` at 0x1d924 [@0x1d924] and `error_page_discard` at 0x1db94 [@0x1db94]. It calls `error_check_poisoned_state` at 0x1dc34 [@0x1dc34]. Its return at 0x1d8d4 gives one of several values [@0x1d8d4]. The facts do not show what each error code means.
  Reviewed: 2026-11-12

- `handle_cac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1dcd0.
  Role (from name): handler for a cached-access bus error. It finds the matching spool record (get_matching_spool_addr, 0x1dd08), compares node partitions (nasid_to_partid, part_id) and calls nasid_to_region, and runs checks (error_check_part_page, error_check_memory_access, error_check_poisoned_state, memory_iscalias). Its outcomes are partition_handle_error calls with codes 0x1, 0x2, 0x4, 0x5, 0x6 and 0x9, a page discard (error_page_discard, 0x1df78), a CRB dump (dump_crb, 0x1e320), or kl_panic at 0x1ddb4. What the codes mean is not stated in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12

- `handle_cac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1dcd0
  **Inferred.** Role (from name): it handles a cached bus error. It calls `get_matching_spool_addr` at 0x1dd08 [@0x1dd08]. When that result is zero, the branch at 0x1dd24 goes to 0x1de44 [@0x1dd24 taken zero]. A nonzero a1 takes the branch at 0x1dd40 to 0x1ddb4 [@0x1dd40 taken nonzero], where it calls `kl_panic` [@0x1ddb4]. It calls `partition_handle_error` at 0x1de34 [@0x1de34] and `error_page_discard` at 0x1df78 [@0x1df78]. It loads a doubleword from the fixed address 0x9200000001000018 [@0x1de60]. Its return at 0x1ddac gives one of several values [@0x1ddac]. The facts do not show which of these paths a cached error takes.
  Reviewed: 2026-11-12

- `kl_ioerror_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1e474 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1e474-0x1e5f0 (380 bytes).
  It occupies 380 bytes.
  The `ld` at 0x1e4b0 loads 8 bytes from a7 (arg7 at entry) +0x120.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x1e524, `ld` at 0x1e5ec.
  The `ld` at 0x1e528 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x1e534 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lw` at 0x1e548 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x5150.
  The `jal` at 0x1e544 calls hub_ioerror_handler with a0=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+20816], a1=a3 at entry (arg3), a2=a6 at entry (arg6), a3=sp-128.
  The `jal` at 0x1e57c calls ioerror_dump with a0=sym(.rodata)+28472, a1=a3 at entry (arg3), a2=0x1, a3=sp-128.
  The `beq` branch at 0x1e4a8 targets 0x1e4c4, is taken when a7 == 0, and falls through when a7 != 0.
  The `beq` branch at 0x1e4c4 targets 0x1e5a0, is taken when a1 == t8(=-0x1), and falls through when a1 != t8(=-0x1).
  The `beq` branch at 0x1e4d4 targets 0x1e4e8, is taken when a2 == t8(=-0x1), and falls through when a2 != t8(=-0x1).
  The `beq` branch at 0x1e4fc targets 0x1e510, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1e508 targets 0x1e5b8, is taken when (a1(?) & 0x7) == 0, and falls through when (a1(?) & 0x7) != 0.
  The `beq` branch at 0x1e510 targets 0x1e524, is taken when a5 == 0, and falls through when a5 != 0.
  The `beq` branch at 0x1e550 targets 0x1e5b0, is taken when s0(=a6) == 0, and falls through when s0(=a6) != 0.
  The `beq` branch at 0x1e558 targets 0x1e5b0, is taken when s0(=a6) == a0(=0x2), and falls through when s0(=a6) != a0(=0x2).
  The `bne` branch at 0x1e560 targets 0x1e570, is taken when v0(=ret(hub_ioerror_handler)) != 0, and falls through when v0(=ret(hub_ioerror_handler)) == 0.
  The `beq` branch at 0x1e568 targets 0x1e588 and is always taken.
  The `bne` branch at 0x1e5a0 targets 0x1e4dc, is taken when a2 != t8(=-0x1), and falls through when a2 == t8(=-0x1).
  The `beq` branch at 0x1e5a8 targets 0x1e4ec and is always taken.
  The `beq` branch at 0x1e5b0 targets 0x1e588 and is always taken.
  The `bne` branch at 0x1e5e0 targets 0x1e518, is taken when a5 != 0, and falls through when a5 == 0.
  The `beq` branch at 0x1e5e8 targets 0x1e528 and is always taken.
  The return at 0x1e598 has v0 = ret(hub_ioerror_handler).

- `kl_panic_setup` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1e5f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1e5f0-0x1e634 (68 bytes).
  It occupies 68 bytes.
  The `jal` at 0x1e5f8 calls enter_panic_mode with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e600 calls check_ni_errors with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1e614 calls hubni_error_handler with a0=sym(.rodata)+28472, a1=0x1, a2=?, a3=?.
  The `jal` at 0x1e620 calls sn0_error_dump with a0=sym(.rodata)+28472, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1e608 targets 0x1e61c, is taken when v0(=ret(check_ni_errors)) == 0, and falls through when v0(=ret(check_ni_errors)) != 0.
  The return at 0x1e62c has v0 = ret(sn0_error_dump).

- `kl_panic` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1e634 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1e634-0x1e664 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x1e640 calls kl_panic_setup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e64c calls cmn_err with a0=0x12, a1=a0 at entry (arg0), a2=?, a3=?.
  The return at 0x1e65c has v0 = ret(cmn_err).

- `sn0_error_mark_page` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1eb64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1eb64-0x1eb80 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1eb6c calls poison_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1eb78 has v0 = ret(poison_page).

- `sn0_error_reclaim_page` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1eb80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1eb80-0x1ebd8 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x1ebb8 calls set_dir_state_UNOWNED with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1eb8c targets 0x1ebac, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x1ebc8 targets 0x1ebb8, is taken when s0(?) < 0x4000 (unsigned), and falls through when s0(?) >= 0x4000 (unsigned).
  The `beq` branch at 0x1ebd0 targets 0x1eb98 and is always taken.
  The return at 0x1eba4 has v0 = one of 0x0, 0x1.

- `intr_stray` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1edb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1edb0-0x1edd8 (40 bytes).
  It occupies 40 bytes.
  The `lh` at 0x1edc8 loads 2 bytes from abs 0xffffffffffffc420.
  The `jal` at 0x1edc4 calls cmn_err with a0=0x4, a1=sym(.rodata)+32520, a2=a0 at entry (arg0), a3=[-0x3be0]:2.
  The return at 0x1edd0 has v0 = ret(cmn_err).

- `intr_init_vecblk` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1edd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1edd8-0x1ef8c (436 bytes).
  It occupies 436 bytes.
  The `lbu` at 0x1ee64 loads 1 byte from sym(.rodata) +0x7f34.
  The `lw` at 0x1ee6c loads 4 bytes from sym(.rodata) +0x7f30.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1ee7c, `sd` at 0x1ee84, `sd` at 0x1ee8c.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1ee90, `sw` at 0x1eeb8, `sw` at 0x1eec8.
  The `swl` at 0x1ee94 stores 4 bytes to ?.
  The `swr` at 0x1ee98 stores 4 bytes to ?.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x1ee9c, `sb` at 0x1eea4, `sb` at 0x1eeb0.
  The `lbu` at 0x1eea0 loads 1 byte from sym(.rodata) +0x7f35.
  The `lbu` at 0x1eea8 loads 1 byte from sym(.rodata) +0x7f36.
  The `sh` at 0x1eebc stores 2 bytes to ?.
  The `sw` at 0x1ef14 stores 4 bytes to table(0x1e18) +0x0.
  The `sw` at 0x1ef30 stores 4 bytes to table(0x1e1c) +0x0.
  The `jal` at 0x1eee4 calls init_spinlock with a0=?, a1=sym(.rodata)+32520, a2=?, a3=?.
  The `beq` branch at 0x1ee48 targets 0x1ef3c and is always taken.
  The `bne` branch at 0x1eec4 targets 0x1ee58, is taken when a3(?) < 0x40 (signed), and falls through when a3(?) >= 0x40 (signed).
  The `beq` branch at 0x1eecc targets 0x1ef50, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x1ef18 targets 0x1ef34 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `bne` branch at 0x1ef2c targets 0x1ef04 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1ef34 targets 0x1ef5c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x1ef3c targets 0x1ee50, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0x1ef48 targets 0x1ee50 and is always taken.
  The `beq` branch at 0x1ef54 targets 0x1eed4 and is always taken.
  The return at 0x1ef84 has v0 = ret(init_spinlock).

- `intr_reserve_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f1c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1f1c0-0x1f1e8 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x1f1d4 calls do_intr_reserve_level [0x1ef8c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=a3 at entry (arg3), a5=a4 at entry (arg4).
  The return at 0x1f1e0 has v0 = ret(do_intr_reserve_level).

- `intr_unreserve_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f1e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1f1e8-0x1f210 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x1f1fc calls do_intr_reserve_level [0x1ef8c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=0x0, a4=0x0, a5=0x0.
  The return at 0x1f208 has v0 = ret(do_intr_reserve_level).

- `intr_get_ptrs` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f210 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1f210-0x1f26c (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0x1f220 loads 8 bytes from (sym(pdaindr) + (a0 << 0x4)) +0x8.
  2 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x0, including `sd` at 0x1f234, `sd` at 0x1f250.
  The `ld` at 0x1f238 loads 8 bytes from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x5a8.
  2 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0x1f23c, `sd` at 0x1f258.
  2 such `sw` accesses store 4 bytes to a5 (arg5 at entry) +0x0, including `sw` at 0x1f240, `sw` at 0x1f25c.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x1f248, `sw` at 0x1f260.
  The `ld` at 0x1f254 loads 8 bytes from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x5b0.
  The `beq` branch at 0x1f22c targets 0x1f24c, is taken when a1 >= 0x40 (signed), and falls through when a1 < 0x40 (signed).
  The return at 0x1f244 has v0 = [(sym(pdaindr) + (a0 << 0x4))+8]:8+1432.
  The return at 0x1f264 has v0 = [(sym(pdaindr) + (a0 << 0x4))+8]:8+1432.

- `intr_connect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f26c
  **Inferred.** It calls `intr_get_ptrs` (0x1f210, from 0x1f2a0) and then `mutex_spinlock_spl` (0x1f2b4). A branch on bit 0x2 of a1 (0x1f2e4) and one on a1 being zero (0x1f30c) lead to `mutex_spinunlock` (0x1f2f0) and a return of -1 or 0. Later it does an `ll`/`sc` loop on a word (0x1f47c, 0x1f484), reached only when bit 0x100 of a loaded word is set (0x1f474). It calls `intr_thread_setup` with a4 = 0x200 (0x1f4e0) when a loaded word is nonzero (0x1f4bc); that call's a1 is built from `pdaindr` indexed by `a0 << 4`. The facts do not show where the lock is released after the `ll`/`sc` update, what the word holds, or what the level number means.
  Reviewed: 2026-11-12

- `intr_connect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f26c
  **Inferred.** The routine reads per-CPU data through pdaindr (ld at 0x1f3bc, lh at 0x1f3c0 at +0x422) and does a halfword table load at 0x1f3d4 whose table the facts do not name. It calls intr_get_ptrs (the routine at 0x1f210, jal at 0x1f2a0), holds a spinlock with mutex_spinlock_spl at 0x1f2b4 and releases it at 0x1f2f0. It updates a shared word with an ll/sc pair (ll at 0x1f47c, sc at 0x1f484). It calls intr_thread_setup (the routine at 0x21368, jal at 0x1f4e0) with a4 = 0x200 when bit 0x100 of the word loaded at 0x1f468 is set (beq at 0x1f474) and a further nonzero test at 0x1f4bc passes. It returns -1 or 0 at 0x1f304. Role (from name): connecting an interrupt at a level; the level-to-table mapping is inferred.
  Reviewed: 2026-11-12

- `intr_disconnect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f508
  **Inferred.** It follows the same opening as `intr_connect_level`: `intr_get_ptrs` (0x1f52c), then `mutex_spinlock_spl` (0x1f540). It compares a2 against the constant 0x3 at 0x1f570 and, when they differ, calls `mutex_spinunlock` (0x1f578) and returns -1 or 0. Further on it does a series of stores and loads, ending in a doubleword store at 0x1f6a4. The facts do not give that store's target address, and show no loop around it. Which entry the routine clears is not established.
  Reviewed: 2026-11-12

- `intr_disconnect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f508
  **Inferred.** Role (from name): it removes a handler from an interrupt level. It calls `intr_get_ptrs` at 0x1f52c [@0x1f52c], then `mutex_spinlock_spl` at 0x1f540 [@0x1f540], and releases the lock with `mutex_spinunlock` at 0x1f578 [@0x1f578]. The branch at 0x1f570 goes to 0x1f594 when a2 equals 3 [@0x1f570 taken], and only that path loads the `pdaindr` doubleword at 0x1f638 [@0x1f638]; both paths reach the unlock at 0x1f578. Its return at 0x1f58c has v0 one of -0x1, 0x0 [@0x1f58c]. The facts do not show which handler slot is cleared.
  Reviewed: 2026-11-12

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** A 28-byte wrapper that passes its arguments to `do_intr_block_bit` (0x1f828) with a2 set to the constant 0x1, and returns that result. The flag value is read as "block" from the name, not from the callee.
  Reviewed: 2026-11-12

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** The routine is a 28-byte wrapper: it calls do_intr_block_bit at 0x1f828 with a2 = 0x1 and returns that call's result at 0x1f834. The argument a1 and a3 pass through unchanged. The name suggests blocking an interrupt bit, and the constant 0x1 supports a set-versus-clear flag, but the meaning of the flag is inferred from the name.
  Reviewed: 2026-11-12

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** A one-call wrapper. It calls do_intr_block_bit at 0x1f828 with its first two arguments and its fourth argument passed through, and the constant 0x1 as the third argument. It returns that call's value. What the constant 1 selects is unknown.
  Reviewed: 2026-11-12

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The sibling of `intr_block_bit`: the same 28-byte wrapper around `do_intr_block_bit` (0x1f844), with the constant 0x0 in place of 0x1. The pairing with the block routine is inferred from the names and the flag values.
  Reviewed: 2026-11-12

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The routine is a 28-byte wrapper: it calls do_intr_block_bit at 0x1f844 with a2 = 0x0 and returns that call's result at 0x1f850. It is the same call as intr_block_bit at 0x1f820 with the flag cleared, so the pair differs only in the constant passed. The name suggests unblocking an interrupt bit; the flag meaning is inferred from the name.
  Reviewed: 2026-11-12

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The same one-call wrapper as its neighbour at 0x1f820. It calls do_intr_block_bit at 0x1f844 with the first two and the fourth arguments passed through, and the constant 0x0 as the third argument. It returns that call's value. What the constant 0 selects is unknown.
  Reviewed: 2026-11-12

- `intr_cpu_choose_from_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f980 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1f980-0x1f99c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1f988 calls do_intr_cpu_choose [0x1f858] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1f994 has v0 = ret(do_intr_cpu_choose).

- `intr_target_from_desc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1fa98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1fa98-0x1fb50 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x1faa8 calls device_desc_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fac0 calls cpuvertex_to_cpuid with a0=ret(device_desc_intr_target_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1faf8 calls subnodevertex_to_subnode [0x1f99c] with a0=ret(device_desc_intr_target_get), a1=sp-48, a2=sp-44, a3=?.
  The `jal` at 0x1fb08 calls master_node_get with a0=ret(device_desc_intr_target_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1fb28 calls intr_cpu_choose_from_node [0x1f980] with a0=?, a1=a1 at entry (arg1), a2=?, a3=?, a4=ret(master_node_get).
  The `jal` at 0x1fb3c calls intr_cpu_choose_from_node [0x1f980] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1fab8 targets 0x1fadc, is taken when at(=-0x1) == v0(=ret(device_desc_intr_target_get)), and falls through when at(=-0x1) != v0(=ret(device_desc_intr_target_get)).
  The `beq` branch at 0x1fad4 targets 0x1faf4, is taken when v0(=-0x1) == s0(?), and falls through when v0(=-0x1) != s0(?).
  The `beq` branch at 0x1fb00 targets 0x1fb3c, is taken when v0(=ret(subnodevertex_to_subnode)) == 0, and falls through when v0(=ret(subnodevertex_to_subnode)) != 0.
  The `beq` branch at 0x1fb1c targets 0x1fadc, is taken when a0(?) == t8(=-0x1), and falls through when a0(?) != t8(=-0x1).
  The `beq` branch at 0x1fb34 targets 0x1fadc and is always taken.
  The `beq` branch at 0x1fb48 targets 0x1fadc and is always taken.
  The return at 0x1faec has v0 = one of -0x1, ?.

- `intr_cnode_seen` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1fb50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1fb50-0x1fb90 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x1fb50 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lh` at 0x1fb68 loads 2 bytes from ?.
  The `blez` branch at 0x1fb58 targets 0x1fb80, is taken when a6(=[a2]) <= 0 (signed), and falls through when a6(=[a2]) > 0 (signed).
  The `beq` branch at 0x1fb70 targets 0x1fb88, is taken when at(?) == a0, and falls through when at(?) != a0.
  The `bne` branch at 0x1fb78 targets 0x1fb64, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The return at 0x1fb80 has v0 = a1.
  The return at 0x1fb88 has v0 = 0x0.

- `intr_bit_reserve_test` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1fb90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1fb90-0x1fc38 (168 bytes).
  It occupies 168 bytes.
  The `sw` at 0x1fc14 stores 4 bytes to a7 (arg7 at entry) +0x0.
  The `jal` at 0x1fbc8 calls intr_cpu_choose_from_node [0x1f980] with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fc04 calls do_intr_reserve_level [0x1ef8c] with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=0x1, a4=a5 at entry (arg5), a5=a6 at entry (arg6).
  The `beq` branch at 0x1fbc0 targets 0x1fbec, is taken when a2 == t9(=-0x1), and falls through when a2 != t9(=-0x1).
  The `beq` branch at 0x1fbec targets 0x1fc20, is taken when s0(?) == t9(=-0x1), and falls through when s0(?) != t9(=-0x1).
  The `bltz` branch at 0x1fc10 targets 0x1fc20, is taken when v0(=ret(do_intr_reserve_level)) < 0 (signed), and falls through when v0(=ret(do_intr_reserve_level)) >= 0 (signed).
  The `beq` branch at 0x1fc18 targets 0x1fc28 and is always taken.
  The return at 0x1fc30 has v0 = one of ?, -0x1.

- `intr_heuristic` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1fc38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x1fc38-0x1fe74 (572 bytes).
  It occupies 572 bytes.
  The `lh` at 0x1fd58 loads 2 bytes from abs 0xffffffffffffc422.
  The `sh` at 0x1fdcc stores 2 bytes to ?.
  The `ld` at 0x1fe28 loads 8 bytes from (sym(pdaindr) + ([sym(master_procid)]:2 << 0x4)) +0x8.
  The `lh` at 0x1fe3c loads 2 bytes from [(sym(pdaindr) + ([sym(master_procid)]:2 << 0x4))+8]:8 +0x422.
  The `jal` at 0x1fc78 calls physmem_maxradius with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fc90 calls intr_target_from_desc with a0=a1 at entry (arg1), a1=-0x1, a2=?, a3=?.
  The `jal` at 0x1fcb4 calls intr_bit_reserve_test [0x1fb90] with a0=ret(intr_target_from_desc), a1=-0x1, a2=-0x1, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x1fcf4 calls master_node_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1fd18 calls intr_bit_reserve_test [0x1fb90] with a0=-0x1, a1=-0x1, a2=ret(master_node_get), a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x1fd48 calls cmn_err with a0=0x4, a1=sym(.rodata)+32520, a2=a4 at entry (arg4), a3=a4 at entry (arg4).
  The `jal` at 0x1fd8c calls physmem_select_neighbor_node with a0=?, a1=?, a2=sp-104, a3=sym(intr_cnode_seen), a4=sp-616, a5=sp-624.
  The `jal` at 0x1fdd0 calls intr_bit_reserve_test [0x1fb90] with a0=-0x1, a1=-0x1, a2=?, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x1fe00 calls cmn_err with a0=0x4, a1=sym(.rodata)+32520, a2=a4 at entry (arg4), a3=a4 at entry (arg4).
  The `jal` at 0x1fe38 calls intr_bit_reserve_test [0x1fb90] with a0=-0x1, a1=-0x1, a2=[[(sym(pdaindr) + ([sym(master_procid)]:2 << 0x4))+8]:8+1058]:2, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x1fe64 calls cmn_err with a0=0x4, a1=sym(.rodata)+32520, a2=a4 at entry (arg4), a3=a4 at entry (arg4).
  The `beq` branch at 0x1fc84 targets 0x1fcf4, is taken when s5(=a1) == 0, and falls through when s5(=a1) != 0.
  The `beq` branch at 0x1fcc4 targets 0x1fcf4, is taken when a1(?) == s6(=-0x1), and falls through when a1(?) != s6(=-0x1).
  The `beq` branch at 0x1fd28 targets 0x1fd38, is taken when a1(?) == s6(=-0x1), and falls through when a1(?) != s6(=-0x1).
  The `beq` branch at 0x1fd30 targets 0x1fcd0 and is always taken.
  The `blez` branch at 0x1fd54 targets 0x1fdf0, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x1fd60 targets 0x1fd78 and is always taken.
  The `bne` branch at 0x1fd74 targets 0x1fdf0, is taken when a3(?) < s5(?) (signed), and falls through when a3(?) >= s5(?) (signed).
  The `beq` branch at 0x1fd94 targets 0x1fd68, is taken when v0(=ret(physmem_select_neighbor_node)) == 0, and falls through when v0(=ret(physmem_select_neighbor_node)) != 0.
  The `beq` branch at 0x1fde0 targets 0x1fd70, is taken when a1(?) == s6(=-0x1), and falls through when a1(?) != s6(=-0x1).
  The `beq` branch at 0x1fde8 targets 0x1fccc and is always taken.
  The `beq` branch at 0x1fe48 targets 0x1fe58, is taken when a1(?) == s6(=-0x1), and falls through when a1(?) != s6(=-0x1).
  The `beq` branch at 0x1fe50 targets 0x1fccc and is always taken.
  The `beq` branch at 0x1fe6c targets 0x1fccc and is always taken.
  The return at 0x1fcec has v0 = ?.

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c.
  It tests a bit word at 0x9200000001000098 against a mask (and at 0x1ff4c and 0x20014). It picks a table record with ms1bit and works on the semaphore at record +32 (cvsema, valusema, vsema). The loop at 0x1fff0 compares the semaphore value with hub_intr_wakeup_cnt, and two indirect calls through record +16 (0x1ffc8, 0x2005c) do the per-record work. The dispatch rule that decides which record runs is not established.
  Grade: inferred.
  Reviewed: 2026-11-12

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** It reads a hub pending word at the fixed address 0x9200000001000098 and loops while the result ANDed with a stored mask is nonzero (0x20014). It finds a set bit through `ms1bit` (0x1ff84), which by its name returns the most significant one, indexes a 72-byte record table by that bit number (the `x * 9 * 8` scaling at 0x1ffa4), and calls the semaphore routines `cvsema`, `valusema` and `vsema` on the record at +32 (0x1ff5c, 0x1ffd8, 0x1fff8). It calls through a function pointer stored at record +16 (0x1ffc8, 0x2005c) on conditional paths: the call at 0x1ffc8 requires the word at record +8 to be nonzero, and the branch at 0x1ffb0 sends the case where bit 0x1000 of the word at record +24 is clear to the call at 0x2005c. Which bit is taken first and what the record fields mean is not established here.
  Reviewed: 2026-11-12

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** The routine loads the doubleword at 0x9200000001000098 (ld at 0x1ff2c) and masks it with the value at [-0x3a68]:8 (beq at 0x1ff4c). It calls ms1bit at 0x1ff84 and uses its result to index a table of 72-byte records. It calls cvsema, valusema and vsema on the address of record +0x20 (calls at 0x1ff5c, 0x1ffd8 and 0x1fff8) and compares the valusema result against hub_intr_wakeup_cnt (beq at 0x1fff0). A word at +0x18 of the record is tested for bit 0x1000 (beq at 0x1ffb0); a doubleword at +0x8 is tested for zero (beq at 0x1ffbc). Calls through an unresolved target at 0x1ffc8 and 0x2005c receive the doubleword at +0x10 as a0 and the entry a0 as a1, so +0x10 is passed as an argument, and the facts do not show which field holds the callee. Role (from name): pending-interrupt dispatch; the table layout is inferred from the scale and offsets.
  Reviewed: 2026-11-12

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** Role (from name): it services pending hub interrupts. It loads a doubleword from 0x9200000001000098 [@0x1ff2c] and stores a word through a pointer at offset 0xd0 [@0x1ff80]. Its return at 0x2004c returns either the doubleword at 0x9200000001000098 or an unknown value [@0x2004c]. The facts do not show which bits the tests at 0x1ff4c and 0x20014 select.
  Reviewed: 2026-11-12

- `intpend1` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2006c.
  It has a similar shape to intpend0 but reads a different bit word, at 0x92000000010000a0, masked against s2 (0x200a0). It uses a second record table selected by ms1bit (0x200b8) and makes an indirect call through record +16 (0x200f0). A cmn_err report at 0x20148 sits on a path whose condition the facts do not establish.
  Grade: inferred.
  Reviewed: 2026-11-12

- `cpuintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20508.
  It indexes pdaindr with a 16-bit value from 0xffffffffffffc420 (16-byte entries), follows the pointer at entry +8 and reads a flag byte at offset 0x520 from it. It branches on bit 0x20 of the word at -0x3d80. It calls bcopy with length 0x168 only when the byte at -0x3f80 and the word nmied are both nonzero (0x20554, 0x2055c), then calls doacvec and doactions (0x205b4, 0x205bc). When bit 0x20 of -0x3d80 is set it also calls log_tstamp_event with 0x71 (0x205f0) and again with 0x65 and 0x71 as its second argument (0x2060c). The facts do not say what the events mean.
  Grade: inferred.
  Reviewed: 2026-11-12

- `cpuintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20508
  **Inferred.** It loads a halfword (0x20524) and then record fields at +0x8 and +0x520 (0x20534, 0x2053c); the facts do not name the source of the halfword. Unless the branches at 0x20554 or 0x2055c skip it, it copies 0x168 bytes with `bcopy` (0x205ac). It then runs `doacvec` and `doactions` (0x205b4, 0x205bc). When bit 0x20 of a loaded word is clear (0x205cc) it returns `doactions`'s result; otherwise it logs timestamp events 0x71 and 0x65 with `log_tstamp_event` (0x205f0, 0x2060c). It also does a doubleword store (0x20548); the facts give neither its address nor the address of the load at 0x205c4. The vector and action callees may be the dispatch step, which is a guess from their names. The exact dispatch order is open.
  Reviewed: 2026-11-12

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c.
  It reads the same per-CPU block as cpuintr: the 16-bit CPU id, the pdaindr entry, and the flag byte at +0x520. It makes one store (0x206ac; its target is not resolved in the facts) and calls debug (0x206b4) with a format string from .rodata+32520, the flag byte plus 118, and the constant 0x9200000001000090, then returns the result of debug. The meaning of that byte is not established.
  Grade: inferred.
  Reviewed: 2026-11-12

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** It loads the halfword at `-0x3be0` and a record through `pdaindr` (the facts show the index in the argument expression for `debug`), does a doubleword store (0x206ac), and does a load (0x206b8). The facts give neither address; 0x9200000001000090 appears as the third argument to `debug`. It calls `debug` (0x206b4) with a constant string address (`.rodata+32520`), a byte from the record at +1312 plus 118, and 0x9200000001000090, and returns its result. Its role as a debug entry follows from the name and the `debug` callee, not from any body in this read.
  Reviewed: 2026-11-12

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** Reads a halfword from the fixed address 0xffffffffffffc420 (0x2067c) and a per-CPU record reached through `pdaindr`. It calls `debug` at 0x206b4 with a string from `.rodata` (+32520) and the address 0x9200000001000090 as its third argument. It also stores a doubleword at 0x206ac and loads one at 0x206b8, but the facts do not show the addresses of that store and load. It returns the result of `debug`. Role (from name): a debug-interrupt hook. The facts do not settle what the fields mean.
  Reviewed: 2026-11-12

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** Role (from name): it is the debug interrupt entry, and it passes control to the debugger. It stores a doubleword to 0x9200000001000090 [@0x206ac] and loads one from 0x9200000001000098 [@0x206b8]. It calls `debug` at 0x206b4 [@0x206b4]. Its return at 0x206c0 returns the value that `debug` returns [@0x206c0]. The facts do not show what the debugger does with the stored value.
  Reviewed: 2026-11-12

- `tlbintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20778
  **Inferred.** It follows the `dbgintr` shape: a halfword load (0x20778), record loads at +0x8 and +0x520 (0x20790, 0x20798), a doubleword store (0x207a4) and a load (0x207ac); the facts give no addresses for them. It calls `tlbflush_rand` (0x207a8) with its own four arguments and returns that result. The name suggests a TLB-flush handler, but the facts show only the call, not the flush itself.
  Reviewed: 2026-11-12

- `chkdebug` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20974.
  It appears to gate the debug entry. It reads the CPU id, the per-CPU flag byte at +0x520, and the word at 0x92000000010000a0, then calls dbgintr (0x209b0) only when a bit test at 0x209a8 is nonzero. The value tested against is listed as unknown in the facts, so the gating condition is only partly understood.
  Grade: inferred.
  Reviewed: 2026-11-12

- `chkdebug` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20974
  **Inferred.** It does a halfword load (0x20974), record loads at +0x8 and +0x520, and loads the doubleword at 0x92000000010000a0. It calls `dbgintr` (0x209b0) with a0 = 0 only when that word ANDed with a loaded value is nonzero (the branch at 0x209a8); the facts do not resolve where that value comes from. Otherwise it returns without the call. The word at 0x92000000010000a0 is a flag by name, which the facts do not confirm.
  Reviewed: 2026-11-12

- `hub_migrintr_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20a2c
  **Inferred.** It calls `cnodetocpu` (0x20a34) and then `intr_connect_level` (0x20a68) with a1 = 3, a2 = 0, `migr_intr_handler` in a3 and `migr_intr_prologue_handler` in a5. It skips that connect when `numnodes` is 1 (0x20a4c) or when a0 equals -1 (0x20a54); the facts do not show that a0 holds the `cnodetocpu` result. When `intr_connect_level` returns nonzero it calls `cmn_err` (0x20a88). That the routine sets up the migration interrupt is inferred from the handler names.
  Reviewed: 2026-11-12

- `intr_reserve_hardwired` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20b84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x20b84-0x20ca8 (292 bytes).
  It occupies 292 bytes.
  The `lw` at 0x20bc4 loads 4 bytes from ?.
  The `ld` at 0x20bd0 loads 8 bytes from ?.
  The `lb` at 0x20be8 loads 1 byte from ?.
  The `ld` at 0x20c30 loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lh` at 0x20c34 loads 2 bytes from [table(sym(pdaindr))+8]:8 +0x422.
  The `lb` at 0x20c4c loads 1 byte from sym(.data) +0x948.
  The `jal` at 0x20b94 calls cnodetocpu with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20bcc calls intr_reserve_level with a0=?, a1=?, a2=?, a3=0x0.
  The `jal` at 0x20c18 calls cpu_enabled with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x20c8c calls cmn_err with a0=0x0, a1=sym(.rodata)+32520, a2=?, a3=?, a6=sym(cause_intr_tbl).
  The `beq` branch at 0x20bac targets 0x20c64, is taken when at(=-0x1) == s0(?), and falls through when at(=-0x1) != s0(?).
  The `beq` branch at 0x20bb4 targets 0x20c9c and is always taken.
  The `bne` branch at 0x20bd4 targets 0x20c80, is taken when v0(=ret(intr_reserve_level)) != s2(?), and falls through when v0(=ret(intr_reserve_level)) == s2(?).
  The `bne` branch at 0x20bf0 targets 0x20bbc, is taken when a1(?) != a7(=-0x1), and falls through when a1(?) == a7(=-0x1).
  The `beq` branch at 0x20c10 targets 0x20c64, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x20c20 targets 0x20c64, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `bne` branch at 0x20c38 targets 0x20c64, is taken when t9(=[[table(sym(pdaindr))+8]:8+1058]:2) != s3(=a0), and falls through when t9(=[[table(sym(pdaindr))+8]:8+1058]:2) == s3(=a0).
  The `bne` branch at 0x20c40 targets 0x20bfc, is taken when s1(=one of 0x0, 0x1) != 0, and falls through when s1(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x20c54 targets 0x20bbc, is taken when a1(=[sym(hardwired_intr)]:1) != at(=-0x1), and falls through when a1(=[sym(hardwired_intr)]:1) == at(=-0x1).
  The `beq` branch at 0x20c5c targets 0x20bf8 and is always taken.
  The `beq` branch at 0x20c94 targets 0x20bdc and is always taken.
  The `beq` branch at 0x20ca0 targets 0x20c10 and is always taken.
  The return at 0x20c78 has v0 = one of ret(cnodetocpu), ?, ret(cpu_enabled).

- `intr_clear_bits` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20ca8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x20ca8-0x20d20 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x20ca8 loads 8 bytes from a1 (arg1 at entry) +0x0.
  2 such `sd` accesses store 8 bytes to abs 0x9200000001000090, including `sd` at 0x20ce4, `sd` at 0x20d08.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001000098, including `ld` at 0x20ce8, `ld` at 0x20d0c.
  The `beq` branch at 0x20cc0 targets 0x20d18, is taken when at(=[a1]:8) == 0, and falls through when at(=[a1]:8) != 0.
  The `beq` branch at 0x20cdc targets 0x20cec, is taken when (v0(=[a1]:8) & v1(?)) == 0, and falls through when (v0(=[a1]:8) & v1(?)) != 0.
  The `beq` branch at 0x20cec targets 0x20d18, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x20d00 targets 0x20d10, is taken when (a5(=[a1]:8) & a7(?)) == 0, and falls through when (a5(=[a1]:8) & a7(?)) != 0.
  The `bne` branch at 0x20d10 targets 0x20cc8, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The return at 0x20d18 has v0 = ?.

- `intr_clear_all` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20d20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x20d20-0x20d98 (120 bytes).
  It occupies 120 bytes.
  The `sd` at 0x20d44 stores 8 bytes to (a0 << 0x20) -0x6dfffffffe7fff58.
  The `sd` at 0x20d4c stores 8 bytes to (a0 << 0x20) -0x6dfffffffe7fff48.
  The `sd` at 0x20d58 stores 8 bytes to (a0 << 0x20) -0x6dfffffffe7fff50.
  The `sd` at 0x20d64 stores 8 bytes to (a0 << 0x20) -0x6dfffffffe7fff40.
  The `jal` at 0x20d60 calls intr_clear_bits [0x20ca8] with a0=a0 at entry (arg0), a1=(a0 << 0x20)+0x9200000001800098, a2=0x0, a3=sym(.rodata)+32520, a4=0x9200000001800098.
  The `jal` at 0x20d80 calls intr_clear_bits [0x20ca8] with a0=a0 at entry (arg0), a1=(a0 << 0x20)+0x92000000018000a0, a2=0x40, a3=sym(.rodata)+32520, a4=0x92000000018000a0.
  The return at 0x20d90 has v0 = ret(intr_clear_bits).

- `intr_dumpvec` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20f58
  **Inferred.** It checks its a0 argument against 0 and against `numnodes` (0x20f90, 0x20fa8) and goes to a separate path when a0 is out of range. It also goes to a separate path when the `compact_to_nasid_node` entry for a0 is -1 (0x20fb4); that path makes the unresolved indirect calls at 0x211a8 and 0x21190 with the table symbol or entry as arguments, and the routine does not silently skip it. On the in-range path it reads words through the table pointed to by `-0x3c00` (loads at 0x21058 to 0x21088), calls `dump_vector` (0x210d0), and loops with counters compared against 0x2 (0x21134) and 0x40 (0x210e0). It makes several indirect calls with a constant format string at `.rodata+32520` (0x21050 to 0x211a8). The printed field names are open, because the indirect callees are not resolved here.
  Reviewed: 2026-11-12

- `intr_thread_setup` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21368 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x21368-0x213c4 (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0x21394 calls sprintf with a0=sp-64, a1=sym(.rodata)+32520, a2=a1 at entry (arg1), a3=a2 at entry (arg2).
  The `jal` at 0x213ac calls xthread_setup with a0=sp-64, a1=a3 at entry (arg3), a2=a0+24, a3=sym(intpend0_intrd_start), a4=a0 at entry (arg0).
  The return at 0x213bc has v0 = ret(xthread_setup).

- `bte_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21994
  **Inferred.** It takes an error record in a0, reads its node-table pointer at +8, and branches on the halfword at +16 against the cases 1, 2, 3, 6 and 7 (0x21ad0 to 0x21af0), then against 0 (0x21af8). It calls `hubiio_crb_error_handler` (0x219f0) for the node and `mutex_spinlock_spl` (0x21a0c, with `splerr` in an argument slot) and `mutex_spinunlock` (0x21a94). Between them it does doubleword stores; the facts name only the addresses 0x9200000001c00000 and 0x9200000001c001f8 as arguments to the unlock. A path for a halfword value outside the listed cases calls `cmn_err` at level 12 (0x21b58). It returns one of 2 to 7. The meaning of each error code is not established by these facts.
  Reviewed: 2026-11-12

- `bte_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21994
  **Inferred.** Takes a pointer to a per-device record. It reads a halfword at +0x10 of that record, and reads a pointer at +0x8 and fields through it at offsets +0x40, +0x4c and +0x54 (it also stores a word at +0x4c at 0x219ac). It calls `hubiio_crb_error_handler` (0x219f0), and brackets some stores (0x21a4c to 0x21a8c) with `mutex_spinlock_spl` (0x21a0c) and `mutex_spinunlock` (0x21a94); `splerr` is the second argument of the lock call, and the facts do not resolve its first argument. A 16-bit code at +0x10 selects a branch chain, and one path reports through `cmn_err` at 0x21b58 with level 0xc. The routine returns a code from 0x2 to 0x7. The facts do not show what each code means.
  Reviewed: 2026-11-12

- `bte_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21b68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x21b68-0x21c9c (308 bytes).
  It occupies 308 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x21b98, `ld` at 0x21bac, `ld` at 0x21bbc.
  The `lh` at 0x21bd4 loads 2 bytes from a3 (arg3 at entry) +0x4.
  The `sh` at 0x21be0 stores 2 bytes to ?.
  The `sd` at 0x21be4 stores 8 bytes to ?.
  The `lh` at 0x21bec loads 2 bytes from ?.
  The `ld` at 0x21c08 loads 8 bytes from table(0x9200000001c00400) +0x0.
  The `sd` at 0x21c2c stores 8 bytes to table(0x9200000001c00400) +0x0.
  The `sd` at 0x21c30 stores 8 bytes to table(0x9200000001c003b0) +0x0.
  6 such `ld` accesses load 8 bytes from table(0x9200000001c003b0) +0x0, including `ld` at 0x21c34, `ld` at 0x21c44, `ld` at 0x21c54.
  The `jal` at 0x21b88 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+34088, a2=sp-48, a3=a3 at entry (arg3).
  The `beq` branch at 0x21bdc targets 0x21be8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x21c3c targets 0x21c94, is taken when (a1(=0x10000) & a6(=entry(0x9200000001c003b0))) == 0, and falls through when (a1(=0x10000) & a6(=entry(0x9200000001c003b0))) != 0.
  The `beq` branch at 0x21c4c targets 0x21c94, is taken when (a1(=0x10000) & a4(=entry(0x9200000001c003b0))) == 0, and falls through when (a1(=0x10000) & a4(=entry(0x9200000001c003b0))) != 0.
  The `beq` branch at 0x21c5c targets 0x21c94, is taken when (a1(=0x10000) & a5(=entry(0x9200000001c003b0))) == 0, and falls through when (a1(=0x10000) & a5(=entry(0x9200000001c003b0))) != 0.
  The `beq` branch at 0x21c6c targets 0x21c94, is taken when (a1(=0x10000) & a6(=entry(0x9200000001c003b0))) == 0, and falls through when (a1(=0x10000) & a6(=entry(0x9200000001c003b0))) != 0.
  The `beq` branch at 0x21c7c targets 0x21c94, is taken when (a1(=0x10000) & a7(=entry(0x9200000001c003b0))) == 0, and falls through when (a1(=0x10000) & a7(=entry(0x9200000001c003b0))) != 0.
  The `bne` branch at 0x21c8c targets 0x21c44, is taken when (a1(=0x10000) & t0(=entry(0x9200000001c003b0))) != 0, and falls through when (a1(=0x10000) & t0(=entry(0x9200000001c003b0))) == 0.
  The return at 0x21c94 has v0 = ret(hwgraph_info_get_LBL).

- `bte_stall_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21c9c
  **Inferred.** It calls `verify_snchip_rev` and branches on its result against 5 (0x21cbc); when it is 5 or more it goes to 0x21cf0. It does an `lld`/`scd` loop (0x21cd4, 0x21cdc) and tests `bte_stall_node_mask` ANDed with a value (0x21cec); the facts do not give the loop's target address and one early path returns. It allocates with `kmem_alloc_node` (0x21d14, a0 = 0x200, so likely a 512-byte buffer) and frees it with `kmem_free` (0x22030, size 0x200). It calls `us_delay` with 1 (0x21de4, in a loop), 10 (0x21dfc) and 1 (0x21e48, in a loop), and on one path calls `bte_error_handler` (0x21fd0) inside a loop. The facts do not identify the registers it programs and reads; the intent of the stall is open.
  Reviewed: 2026-11-12

- `bte_bpush_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2204c
  **Inferred.** It does nothing further when `bpush_war_enable` is zero (the branch at 0x22068 goes to 0x22078) and otherwise calls `get_hub_chiprev` (0x22098) with a halfword loaded from `compact_to_nasid_node`. It branches on the result against 5 (0x220b0; 5 or more goes to 0x220cc). The branch at 0x220bc jumps to `rt_pin_thread` (0x220d4) when `bte_stall_node_mask` ANDed with a value is zero, so the pin call is on the bit-clear path, not the bit-set path. After `rt_pin_thread` a chain of comparisons (0x220fc to 0x22148) can jump straight to `bte_stall_node` (0x22160); the fall-through path reaches `rt_unpin_thread` (0x22150) first, and `bte_stall_node` (0x22160) follows it. The hardware problem the workaround addresses is not in these facts, so the name is the only hint.
  Reviewed: 2026-11-12

- `hubio_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x222b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x222b8-0x222c0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x222b8 has v0 = ?.

- `hub_pio_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x222c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x222c0-0x22420 (352 bytes).
  It occupies 352 bytes.
  The `lh` at 0x222f8 loads 2 bytes from ?.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x22320, `sw` at 0x22328, `sw` at 0x22398.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x22334, `sd` at 0x22354, `sd` at 0x2235c.
  The `sb` at 0x22368 stores 1 byte to ?.
  The `sh` at 0x223a4 stores 2 bytes to ?.
  The `sd` at 0x223b8 stores 8 bytes to table(0x9200000001c00160) +0x0.
  The `jal` at 0x222d8 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+34128, a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0x223c0 calls hub_set_piomode with a0=?, a1=0x2, a2=?, a3=?, a5=table(0x9200000001c00000).
  The `jal` at 0x223e0 calls init_sv with a0=?, a1=0x0, a2=sym(.rodata)+34128, a3=-0x1.
  The `jal` at 0x223f4 calls spinlock_init with a0=?, a1=sym(.rodata)+34128, a2=?, a3=?.
  The `beq` branch at 0x22314 targets 0x22408 and is always taken.
  The `beq` branch at 0x22340 targets 0x22374, is taken when a2(?) >= 0x10 (signed), and falls through when a2(?) < 0x10 (signed).
  The `bne` branch at 0x22364 targets 0x2231c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x2236c targets 0x22320 and is always taken.
  The `bne` branch at 0x223b4 targets 0x2237c, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `beq` branch at 0x22418 targets 0x2234c and is always taken.
  The return at 0x22400 has v0 = ret(spinlock_init).

- `hub_piomap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22420
  **Inferred.** It finds the widget's id and master through `xwidget_info_get`, `xwidget_info_id_get` and `xwidget_info_master_get` (0x22450 to 0x2246c), and it searches a mapping table under `mutex_spinlock` (0x22548, released at 0x225c8, 0x2262c and 0x226f4). It checks the request against the limits 0x1000000 (0x224d0) and 0x20000000 (0x2252c), and it waits on a sync object with `sv_wait` (0x2270c, argument 0x19) on one path. The table layout and the wait condition are open here.
  Reviewed: 2026-11-12

- `hub_piomap_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22738 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x22738-0x22824 (236 bytes).
  It occupies 236 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x22738, `lw` at 0x227d4.
  The `lw` at 0x22760 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lh` at 0x2276c loads 2 bytes from ?.
  The `lh` at 0x22778 loads 2 bytes from a0 (arg0 at entry) +0x24.
  The `sh` at 0x2278c stores 2 bytes to a0 (arg0 at entry) +0x24.
  The `lbu` at 0x227b4 loads 1 byte from a0 (arg0 at entry) +0x26.
  The `sd` at 0x227d0 stores 8 bytes to table(0x9200000001c00160) +0x0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x28, including `sw` at 0x227ec, `sw` at 0x22820.
  The `lw` at 0x227f4 loads 4 bytes from ?.
  The `sw` at 0x227fc stores 4 bytes to ?.
  The `jal` at 0x2275c calls hwgraph_info_get_LBL with a0=[a0+32], a1=sym(.rodata)+34128, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x22770 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22798 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22804 calls sv_signal with a0=?, a1=?, a2=table(0x9200000001c00000), a3=?.
  The `beq` branch at 0x2274c targets 0x227a0, is taken when (at(=[a0+40]) & 0x2) == 0, and falls through when (at(=[a0+40]) & 0x2) != 0.
  The `beq` branch at 0x22788 targets 0x227b0, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x227e4 targets 0x22814, is taken when (a4(=[a0+40]) & 0x4) == 0, and falls through when (a4(=[a0+40]) & 0x4) != 0.
  The `beq` branch at 0x2280c targets 0x22790 and is always taken.
  The `beq` branch at 0x2281c targets 0x22800 and is always taken.
  The return at 0x227a8 has v0 = one of ?, ret(mutex_spinunlock).

- `hub_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2288c
  **Inferred.** It looks up the same widget records as `hub_piomap_alloc` (0x228a8 to 0x228d0) and then calls `hub_piomap_addr` (0x22914). It checks whether the request's end, a2 plus a3, is above 0x1000000 (0x228e4) and tests bit 0x8 of a4 (0x22928) to choose the path. The translation rule itself is in `hub_piomap_addr`, which this read does not cover.
  Reviewed: 2026-11-12

- `hub_dma_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22950 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x22950-0x22958 (8 bytes).
  It occupies 8 bytes.
  The return at 0x22950 has v0 = ?.

- `hub_dmamap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22958
  **Inferred.** It looks up the widget through `xwidget_info_get`, `xwidget_info_id_get` and `xwidget_info_master_get` (0x22968 to 0x22980). It allocates a 16-byte record with `kern_malloc` (0x22990) and stores words at +0x0, +0xc and +0x8 (0x2299c to 0x229b0). When bit 0x1 of a3 is set (the branch at 0x229c0) it also stores a byte at +0x4 and a word at +0xc again (0x229c4, 0x229c8). It returns the record pointer. The field meanings are not named by the facts.
  Reviewed: 2026-11-12

- `hub_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x229d8
  **Inferred.** It loads the word at +0xc of its argument (0x229dc), stores a word at +0xc (0x229f0) and calls `kern_free` with the same arguments (0x229ec), returning its result. The pairing with `hub_dmamap_alloc`, which allocates a 16-byte record, is from the names and the shared +0xc field. The value stored at +0xc is not derived here.
  Reviewed: 2026-11-12

- `hub_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x229d8
  **Inferred.** Reads a word at +0xc of its first argument (0x229dc) and calls `kern_free` (0x229ec) with all four argument registers unchanged. It stores a word at +0xc at 0x229f0; the facts do not show the stored value. It returns what `kern_free` returns. The facts do not settle the field's purpose.
  Reviewed: 2026-11-12

- `hub_dmamap_addr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a00
  **Inferred.** It reads and writes the word at +0xc of its argument record and tests bit 0x2 of that word (0x22a18). On one path it reports through `cmn_err` at level 4 with the word at +0 and the word at +12 ORed with 0x2 (0x22a48), and it returns its second argument. The address computation is not in this routine's facts.
  Reviewed: 2026-11-12

- `hub_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a5c
  **Inferred.** It has the same shape as `hub_dmamap_addr`: the same +0xc read-modify-write, the bit 0x2 test (0x22a74) and the level-4 `cmn_err` report (0x22aa4), with the same format-string address (`.rodata+34128`). It returns its second argument on the path that returns without the report. Whether it lists or copies map entries is not established by these facts.
  Reviewed: 2026-11-12

- `hub_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a5c
  **Inferred.** Tests bit 0x2 of the word at +0xc of its first argument (branch at 0x22a74). On one path it calls `cmn_err` (0x22aa4) at level 4 with a format from `.rodata` (+34128) and the word at +0x0. It returns the second argument (0x22a88). The facts do not settle what the bit or the report means.
  Reviewed: 2026-11-12

- `hub_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ab8
  **Inferred.** It reads and writes the +0xc word of its argument and tests bit 0x2 of that word (0x22ad0). It tests a3 and, on one path, reports through `cmn_err` at level 4 with a constant -3 (0x22af8). The completion meaning follows from the name and the shared shape, not from the body.
  Reviewed: 2026-11-12

- `hub_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ab8
  **Inferred.** Resembles `hub_dmamap_list` in part: it tests bit 0x2 of the word at +0xc (branch at 0x22ad0), stores a word at +0xc (0x22ad8), and calls `cmn_err` at level 4 (0x22af8) on one path. One return (0x22adc) is either an unresolved value or the `cmn_err` result. Unlike `hub_dmamap_list`, the facts show no return of the second argument. The facts do not settle what the bit or the report means.
  Reviewed: 2026-11-12

- `hub_intr_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22b30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x22b30-0x22b38 (8 bytes).
  It occupies 8 bytes.
  The return at 0x22b30 has v0 = ?.

- `hub_device_desc_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22b38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x22b38-0x22b8c (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0x22b48 calls device_desc_intr_swlevel_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x22b5c calls sprintf with a0=sp-64, a1=sym(.rodata)+34128, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x22b68 calls hwgraph_path_to_dev with a0=sp-64, a1=?, a2=?, a3=?.
  The `jal` at 0x22b74 calls device_desc_intr_target_set with a0=a0 at entry (arg0), a1=ret(hwgraph_path_to_dev), a2=?, a3=?.
  The return at 0x22b84 has v0 = ret(device_desc_intr_target_set).

- `do_hub_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22b8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x22b8c-0x22e3c (688 bytes).
  It occupies 688 bytes.
  The `lw` at 0x22c0c loads 4 bytes from ?.
  The `ld` at 0x22c78 loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lh` at 0x22c7c loads 2 bytes from [table(sym(pdaindr))+8]:8 +0x422.
  The `lh` at 0x22c98 loads 2 bytes from (sym(compact_to_nasid_node) + ([[table(sym(pdaindr))+8]:8+1058]:2 + [[table(sym(pdaindr))+8]:8+1058]:2)) +0x0.
  2 such `sw` accesses store 4 bytes to ret(kmem_alloc_node) +0x0, including `sw` at 0x22ca4, `sw` at 0x22e1c.
  The `sb` at 0x22cb8 stores 1 byte to ret(kmem_alloc_node) +0x5.
  The `sd` at 0x22cc4 stores 8 bytes to ret(kmem_alloc_node) +0x8.
  The `sb` at 0x22cd8 stores 1 byte to ret(kmem_alloc_node) +0x4.
  The `sh` at 0x22cdc stores 2 bytes to ret(kmem_alloc_node) +0x24.
  The `sw` at 0x22ce0 stores 4 bytes to ret(kmem_alloc_node) +0x20.
  The `sw` at 0x22cec stores 4 bytes to ret(kmem_alloc_node) +0x2c.
  The `sw` at 0x22d00 stores 4 bytes to ret(kmem_alloc_node) +0x28.
  The `lw` at 0x22d48 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x78.
  The `ld` at 0x22d54 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x828.
  The `ld` at 0x22d90 loads 8 bytes from ?.
  The `lh` at 0x22d94 loads 2 bytes from ?.
  The `jal` at 0x22bc4 calls device_desc_default_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x22bf8 calls device_desc_intr_name_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22c04 calls device_desc_intr_swlevel_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22c30 calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata)+34128, a2=sp-92, a3=?.
  The `jal` at 0x22c54 calls intr_heuristic with a0=a0 at entry (arg0), a1=?, a2=[sym(allocate_my_bit)], a3=?, a4=a2 at entry (arg2), a6=sp-88.
  The `jal` at 0x22c94 calls kmem_alloc_node with a0=0x30, a1=0x1, a2=[[table(sym(pdaindr))+8]:8+1058]:2, a3=?.
  The `jal` at 0x22cc0 calls xwidget_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=([(sym(compact_to_nasid_node) + ([[table(sym(pdaindr))+8]:8+1058]:2 + [[table(sym(pdaindr))+8]:8+1058]:2))]:2 << 0x26)+0x800001800090, a5=0x800001800090.
  The `jal` at 0x22cd0 calls xwidget_info_masterid_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x22cfc calls hub_device_desc_update [0x22b38] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22d30 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?, a6=sp-88.
  The `jal` at 0x22d7c calls strcmp with a0=?, a1=sym(.rodata)+34128, a2=?, a3=?, a6=sp-88.
  The `jal` at 0x22db0 calls intr_reserve_level with a0=?, a1=[sym(allocate_my_bit)], a2=?, a3=a2 at entry (arg2), a6=sp-88.
  The `jal` at 0x22df4 calls cmn_err with a0=0x4, a1=sym(.rodata)+34128, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x22e10 calls assfail with a0=sym(.rodata)+34128, a1=sym(.rodata)+34128, a2=0x314, a3=?.
  The `jal` at 0x22e2c calls cmn_err with a0=0x4, a1=sym(.rodata)+34128, a2=?, a3=a2 at entry (arg2).
  The `bne` branch at 0x22bbc targets 0x22bf8, is taken when a1 != 0, and falls through when a1 == 0.
  The `bne` branch at 0x22bd4 targets 0x22bf8, is taken when v0(=ret(device_desc_default_get)) != 0, and falls through when v0(=ret(device_desc_default_get)) == 0.
  The `beq` branch at 0x22bf0 targets 0x22c24 and is always taken.
  The `beq` branch at 0x22c18 targets 0x22dc8, is taken when (a0(?) & 0x1) == 0, and falls through when (a0(?) & 0x1) != 0.
  The `beq` branch at 0x22c38 targets 0x22d30, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x22c68 targets 0x22de8, is taken when s3(?) == a2(=-0x1), and falls through when s3(?) != a2(=-0x1).
  The `beq` branch at 0x22c9c targets 0x22e04, is taken when v0(=ret(kmem_alloc_node)) == 0, and falls through when v0(=ret(kmem_alloc_node)) != 0.
  The `beq` branch at 0x22cc8 targets 0x22cdc, is taken when v0(=ret(xwidget_info_get)) == 0, and falls through when v0(=ret(xwidget_info_get)) != 0.
  The `beq` branch at 0x22d3c targets 0x22c3c, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0x22d4c targets 0x22c40, is taken when t1(=[ret(hwgraph_fastinfo_get)+120]) != t2(=0xc0022), and falls through when t1(=[ret(hwgraph_fastinfo_get)+120]) == t2(=0xc0022).
  The `beq` branch at 0x22d58 targets 0x22c40, is taken when t3(=[ret(hwgraph_fastinfo_get)+2088]:8) == 0, and falls through when t3(=[ret(hwgraph_fastinfo_get)+2088]:8) != 0.
  The `bne` branch at 0x22d60 targets 0x22c40, is taken when a0(=[sym(bridge_rev_b_data_check_disable)]) != 0, and falls through when a0(=[sym(bridge_rev_b_data_check_disable)]) == 0.
  The `beq` branch at 0x22d68 targets 0x22c40, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x22d84 targets 0x22c40, is taken when v0(=ret(strcmp)) != 0, and falls through when v0(=ret(strcmp)) == 0.
  The `beq` branch at 0x22d9c targets 0x22de8, is taken when s3(?) == t8(=-0x1), and falls through when s3(?) != t8(=-0x1).
  The `bgez` branch at 0x22db8 targets 0x22c6c, is taken when v0(=ret(intr_reserve_level)) >= 0 (signed), and falls through when v0(=ret(intr_reserve_level)) < 0 (signed).
  The `beq` branch at 0x22dc0 targets 0x22e20 and is always taken.
  The `beq` branch at 0x22dc8 targets 0x22dd8, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x22dd0 targets 0x22c24 and is always taken.
  The `bne` branch at 0x22dd8 targets 0x22dd0, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x22de0 targets 0x22c24 and is always taken.
  The `beq` branch at 0x22dfc targets 0x22d04 and is always taken.
  The `beq` branch at 0x22e18 targets 0x22ca8 and is always taken.
  The `beq` branch at 0x22e34 targets 0x22d04 and is always taken.
  The return at 0x22d28 has v0 = one of ret(kmem_alloc_node), 0x0.

- `hub_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e3c
  **Inferred.** A 28-byte wrapper that calls `do_hub_intr_alloc` (entry at 0x22b8c, called from 0x22e44) with a3 set to the constant 0x0, and returns its result. Its counterpart `hub_intr_alloc_nothd` passes 0x1 instead, so the flag is read as a thread-related choice from the name.
  Reviewed: 2026-11-12

- `hub_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e3c
  **Established.** Calls `do_hub_intr_alloc` (0x22e44) with its first three argument registers unchanged and the fourth set to zero, and returns that call's result.
  Reviewed: 2026-11-12

- `hub_intr_alloc_nothd` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e58
  **Inferred.** The same 28-byte wrapper as `hub_intr_alloc`, calling `do_hub_intr_alloc` (entry at 0x22b8c, called from 0x22e60) with the constant 0x1 in a3. The name suggests the no-thread variant of interrupt allocation, but the facts show only the flag value.
  Reviewed: 2026-11-12

- `hub_intr_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e74
  **Inferred.** It reads the record fields at +0x24, +0x28 and +0x2c, clears the byte at +0x5, and writes +0x0 and +0x8 (0x22ea0 to 0x22eac). It calls `hub_intr_disconnect` (0x22eb0), frees the 48-byte record with `kmem_free` (0x22ec8, size 0x30), and calls `intr_unreserve_level` with the halfword at +36 and the word at +40 (0x22ed8). Bits 0x4 and 0x1 of the word at +44 select the paths (0x22e98, 0x22ec0).
  Reviewed: 2026-11-12

- `hub_intr_connect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22eec
  **Inferred.** It reads the halfword at +0x24 and the words at +0x20 and +0x28, and calls `intr_connect_level` (0x22f24) with those fields and a5 set to 0. A negative result branches to 0x22f50 (0x22f2c); otherwise the routine stores at +0x18 and +0x10 and a word at +0x2c (0x22f4c). The facts do not show what is stored at +0x2c. It returns either the `intr_connect_level` result or 0. When a3 is nonzero it makes an indirect call (0x22f64) whose target is not resolved here.
  Reviewed: 2026-11-12

- `hub_intr_disconnect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22f74
  **Inferred.** Reads a halfword at +0x24, a doubleword at +0x18 and a word at +0x28 of its first argument. If the doubleword at +0x18 is non-zero, it branches (0x22f94) to an indirect call (0x22fc8) whose target the facts do not name. Otherwise it calls `intr_disconnect_level` (0x22f9c) with the halfword and the word at +0x28, loads and stores the word at +0x2c (0x22fa4, 0x22fb8) and returns -5 at 0x22fc0. The facts do not settle what the fields mean.
  Reviewed: 2026-11-12

- `hub_intr_cpu_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22fd8
  **Inferred.** Reads a halfword at +0x24 of its first argument, uses it as an index into the per-CPU records through `pdaindr` (shift by 4), and returns the word at offset 0x734 of the record found there. The facts show a per-CPU lookup but not what the returned value is.
  Reviewed: 2026-11-12

- `hub_provider_startup` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ffc
  **Inferred.** Calls three initialisation routines in order: `hub_pio_init` (0x23008), `hub_dma_init` (0x23010) and `hub_intr_init` (0x23018). It passes its arguments to the first and the first argument to the other two, and returns the result of `hub_intr_init` (0x23028). The facts do not settle what the startup is for beyond these calls.
  Reviewed: 2026-11-12

- `hub_provider_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23030
  **Established.** Calls `xtalk_provider_unregister` (0x23038) with its four argument registers unchanged and returns that call's result.
  Reviewed: 2026-11-12

- `hub_check_is_widget0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2304c
  **Inferred.** Returns 0 or 1. It compares its first argument with the constant 0x9200000000000000 (unsigned branch at 0x23094), then branches on three registers that the facts do not resolve (0x2309c, 0x230a4, 0x230ac). It returns 1 directly on one path at 0x230b8 and one of 0 or 1 at 0x230c0. The facts do not settle what the check decides.
  Reviewed: 2026-11-12

- `hub_check_window_equiv` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x230c8
  **Inferred.** Calls `hub_check_is_widget0` (0x230d8) with its argument registers unchanged and branches on the result (0x230e0). Only when that result is non-zero does it call `hub_check_is_widget0` again (0x230e8) with its second argument, and it branches on that result (0x230f0). It returns 0 or 1. A later comparison at 0x23114 compares two values the facts do not resolve.
  Reviewed: 2026-11-12

- `hub_check_pci_equiv` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23130
  **Inferred.** Calls `hub_check_window_equiv` (0x23144) and branches on its result at 0x2314c (zero goes to the return at 0x231ac). Another branch at 0x23164 compares two values the facts do not resolve. `check_nasid_equiv` is called at 0x2319c with its third argument set to zero. The routine returns 0 or the result of `check_nasid_equiv`. The facts do not settle what the checks mean.
  Reviewed: 2026-11-12

- `hub_setup_prb` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x231b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x231b8-0x2324c (148 bytes).
  It occupies 148 bytes.
  The `ld` at 0x23208 loads 8 bytes from table(0x9200000001c00198) +0x0.
  The `sd` at 0x23248 stores 8 bytes to table(0x9200000001c00198) +0x0.
  The `beq` branch at 0x231c0 targets 0x231e4, is taken when at(=[sym(force_fire_and_forget)]) == 0, and falls through when at(=[sym(force_fire_and_forget)]) != 0.
  The `beq` branch at 0x231e4 targets 0x231f0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0x23244 has v0 = ?.

- `hub_set_piomode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2324c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2324c-0x2333c (240 bytes).
  It occupies 240 bytes.
  2 such `ld` accesses load 8 bytes from (a0 << 0x20) -0x6dfffffffe3ffef0, including `ld` at 0x23288, `ld` at 0x232e4.
  2 such `sd` accesses store 8 bytes to (a0 << 0x20) -0x6dfffffffe3ffef0, including `sd` at 0x2328c, `sd` at 0x232dc.
  The `ld` at 0x23290 loads 8 bytes from (a0 << 0x20) -0x6dfffffffe3fffe0.
  The `jal` at 0x23260 calls get_console_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x232ac calls hub_setup_prb with a0=a0 at entry (arg0), a1=0x0, a2=0x1, a3=0x2.
  The `jal` at 0x232c4 calls hub_setup_prb with a0=a0 at entry (arg0), a1=?, a2=0x3, a3=a1 at entry (arg1).
  The `jal` at 0x232e8 calls putbuf_unlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x23310 calls putbuf_lock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2332c calls hub_setup_prb with a0=a0 at entry (arg0), a1=0x0, a2=0x3, a3=a1 at entry (arg1).
  The `beq` branch at 0x23274 targets 0x23310, is taken when s1(=a0) == v0(=ret(get_console_nasid)), and falls through when s1(=a0) != v0(=ret(get_console_nasid)).
  The `bltz` branch at 0x23298 targets 0x23320, is taken when at(=([(a0 << 0x20)-7926335344142712800]:8 << 0x2e)) < 0 (signed), and falls through when at(=([(a0 << 0x20)-7926335344142712800]:8 << 0x2e)) >= 0 (signed).
  The `bne` branch at 0x232d4 targets 0x232b8, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The `beq` branch at 0x232e0 targets 0x232f0, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x23318 targets 0x2327c and is always taken.
  The `beq` branch at 0x23334 targets 0x232b8 and is always taken.
  The return at 0x23308 has v0 = one of [(a0 << 0x20)-7926335344142712560]:8, ret(putbuf_unlock).

- `hub_widget_flags_set` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2333c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2333c-0x23388 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x23354 calls hub_setup_prb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x3, a3=0x1.
  The `jal` at 0x23370 calls hub_setup_prb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x3, a3=0x2.
  The `beq` branch at 0x23348 targets 0x23364, is taken when (a2 & 0x1) == 0, and falls through when (a2 & 0x1) != 0.
  The `beq` branch at 0x2335c targets 0x2337c and is always taken.
  The `beq` branch at 0x23364 targets 0x2337c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The return at 0x23380 has v0 = 0x1.

- `hub_device_flags_set` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23388
  **Inferred.** Looks up widget info with `xwidget_info_get` (0x23394), then the widget's id and master through `xwidget_info_id_get` (0x233a0) and `xwidget_info_master_get` (0x233ac). It calls `hwgraph_info_get_LBL` (0x233c0) with the master result and a `.rodata` string (+34128). It calls `hub_widget_flags_set` (0x233ec) with its second argument as the third, between `mutex_spinlock` (0x233d0) and `mutex_spinunlock` (0x23400), and returns that call's result.
  Reviewed: 2026-11-12

- `hub_device_inquiry` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2341c
  **Inferred.** Builds a string with `sprintf` (0x2343c), calls `hwgraph_traverse` (0x2344c) on it, and looks up a device master with `device_master_get` (0x23468). It calls `hwgraph_info_get_LBL` (0x23484) on the result. It makes six `cmn_err` calls at level 6 (0x234cc to 0x235b4). A backward branch at 0x2352c tests a register against 8, and later branches test it against masks (0x23570, 0x2359c). The facts do not resolve those registers or say what the bits represent.
  Reviewed: 2026-11-12

- `xbwidget_to_xtslot` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23898 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x23898-0x2396c (212 bytes).
  It occupies 212 bytes.
  The `lw` at 0x238ec loads 4 bytes from abs 0x9000000010000090.
  4 such `lbu` accesses load 1 byte from (sym(.data)+2928 + (a1 << 0x2)) -0x1d, including `lbu` at 0x238f8, `lbu` at 0x23948, `lbu` at 0x23958.
  The `jal` at 0x238c8 calls get_my_slotid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x23934 calls printf with a0=sym(.rodata)+34576, a1=a0 at entry (arg0), a2=?, a3=?, a4=0x9000000010000090, a5=sym(.data)+2928, a6=sym(.data)+2928.
  The `bne` branch at 0x238b8 targets 0x238fc, is taken when a1 < 0x8 (signed), and falls through when a1 >= 0x8 (signed).
  The `beq` branch at 0x238c0 targets 0x238fc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x238e4 targets 0x23928, is taken when v0(?) == v1(=0x50), and falls through when v0(?) != v1(=0x50).
  The `beq` branch at 0x238f0 targets 0x23910, is taken when a1(=[0x9000000010000090]) == 0, and falls through when a1(=[0x9000000010000090]) != 0.
  The `beq` branch at 0x23910 targets 0x2395c, is taken when s1(=a0) == 0, and falls through when s1(=a0) != 0.
  The `beq` branch at 0x23918 targets 0x2394c, is taken when s1(=a0) == a2(=0x1), and falls through when s1(=a0) != a2(=0x1).
  The `beq` branch at 0x23920 targets 0x23900 and is always taken.
  The `beq` branch at 0x23928 targets 0x23944, is taken when s1(=a0) == 0, and falls through when s1(=a0) != 0.
  The `beq` branch at 0x2393c targets 0x238fc and is always taken.
  The `beq` branch at 0x23944 targets 0x238fc and is always taken.
  The `beq` branch at 0x23954 targets 0x238fc and is always taken.
  The `beq` branch at 0x23964 targets 0x238fc and is always taken.
  The return at 0x23908 has v0 = one of ?, 0xf0.

- `hub_slotbits_to_slot` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2396c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2396c-0x239d8 (108 bytes).
  It occupies 108 bytes.
  The `lbu` at 0x2396c loads 1 byte from abs 0xffffffffffffc523.
  The `lw` at 0x239ac loads 4 bytes from abs 0x90000000100000a8.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x239c4, `lbu` at 0x239d4.
  The `beq` branch at 0x23974 targets 0x23990, is taken when at(=[-0x3add]:1) == 0, and falls through when at(=[-0x3add]:1) != 0.
  The `beq` branch at 0x239a4 targets 0x23988, is taken when a3(?) >= 0x8 (signed), and falls through when a3(?) < 0x8 (signed).
  The `beq` branch at 0x239b4 targets 0x239c8, is taken when (a0(=[0x90000000100000a8]) & 0x1) == 0, and falls through when (a0(=[0x90000000100000a8]) & 0x1) != 0.
  The return at 0x23988 has v0 = one of ?, 0xf0.
  The return at 0x239c0 has v0 = ?.
  The return at 0x239d0 has v0 = ?.

- `hub_slot_to_widget` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x239d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x239d8-0x23a40 (104 bytes).
  It occupies 104 bytes.
  The `lw` at 0x239f0 loads 4 bytes from abs 0x9000000010000090.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x23a10, `lbu` at 0x23a28, `lbu` at 0x23a3c.
  The `beq` branch at 0x239ec targets 0x23a14, is taken when a4(?) >= 0x8 (signed), and falls through when a4(?) < 0x8 (signed).
  The `beq` branch at 0x23a00 targets 0x23a2c, is taken when v0(?) == v1(=0x50), and falls through when v0(?) != v1(=0x50).
  The `beq` branch at 0x23a08 targets 0x23a1c, is taken when a5(=[0x9000000010000090]) == 0, and falls through when a5(=[0x9000000010000090]) != 0.
  The return at 0x23a14 has v0 = one of 0xff, ?.
  The return at 0x23a24 has v0 = ?.
  The return at 0x23a38 has v0 = ?.

- `router_slotbits_to_slot` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23a64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x23a64-0x23a8c (40 bytes).
  It occupies 40 bytes.
  The `lbu` at 0x23a80 loads 1 byte from (sym(.data)+2928 + (a0 << 0x2)) +0x3.
  The `beq` branch at 0x23a74 targets 0x23a84, is taken when a0 >= 0x10 (signed), and falls through when a0 < 0x10 (signed).
  The return at 0x23a84 has v0 = one of 0xf0, [(sym(.data)+2928 + (a0 << 0x2))+3]:1.

- `get_my_slotid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23be4.
  This is a thin wrapper. It does one 64-bit load (0x23be8; the address is not resolved in the facts) and passes the incoming a1 through a3 to hub_slotbits_to_slot (0x23bf4), returning that result. The facts do not show the loaded word as an argument, so its role in the slot lookup is open.
  Grade: inferred.
  Reviewed: 2026-11-12

- `router_slotbits_to_slotname` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23ca8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x23ca8-0x23cdc (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x23cb8 calls router_slotbits_to_slot with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x23cc4 calls get_slotname with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The return at 0x23cd4 has v0 = ret(get_slotname).

- `hub_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23d60
  **Inferred.** Calls `get_my_slotid` (0x23d68) with its four argument registers unchanged and returns at 0x23d7c with a value the facts do not resolve, so they do not show whether the call's result is returned as is. Role (from name): a slot lookup.
  Reviewed: 2026-11-12

- `hub_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23d60
  **Inferred.** Role (from name): it returns the slot number of the current hub. It calls `get_my_slotid` at 0x23d68 [@0x23d68]. Its return at 0x23d7c returns a value the facts leave unknown [@0x23d7c], so whether that value is the slot `get_my_slotid` returns is open.
  Reviewed: 2026-11-12

- `is_xbox_config` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23dc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x23dc4-0x23e04 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x23dc8 loads 4 bytes from abs 0x9000000010000090.
  The `lw` at 0x23ddc loads 4 bytes from (a0 << 0x20) -0x6dffffff1ffffffc.
  The `beq` branch at 0x23dd0 targets 0x23dfc, is taken when at(=[0x9000000010000090]) == 0, and falls through when at(=[0x9000000010000090]) != 0.
  The `beq` branch at 0x23de8 targets 0x23df4, is taken when (v1(?) & 0xffff) == 0, and falls through when (v1(?) & 0xffff) != 0.
  The return at 0x23df4 has v0 = one of 0x0, 0x1.
  The return at 0x23dfc has v0 = 0x0.

- `llp_pfail_barrier` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x25078
  **Inferred.** Works on two words in `.sbss` (+0xa4 and +0xa8) with load-linked and store-conditional loops (0x250a4, 0x25144). A loop compares a count against the constant 0x7a120 (unsigned, branch at 0x25138). It reports through `cmn_err` at level 4 (0x251d8), passing the CPU count (`numcpus`) and the constant 0x3e8. That pattern suggests a bounded wait across CPUs that reports when it expires, but the facts do not settle it.
  Reviewed: 2026-11-12

- `llp_pfail_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4.
  Role (from name): link-level power-failure interrupt. It calls msc_owner_cpu (callee at 0x24fd0) and compares the result with a 16-bit value (0x2530c), calls llp_pfail_barrier (0x25344), and runs vector_read and vector_write calls (a0 of 0x0 or 0x6, a2 of 0x0, 0x30, 0x8 or 0x600110) with us_delay waits of 0x64 and 0x12c units. It tests the bit 0x2000000000 repeatedly in the word at 0x9200000001608088 (0x253a8 to 0x253f8). A link retrain or quiesce is a guess from the call pattern; the register meanings and the unit of us_delay are not stated.
  Grade: inferred.
  Reviewed: 2026-11-12

- `llp_pfail_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4
  **Inferred.** Role (from name): a link power-fail interrupt handler. It calls `msc_owner_cpu` (0x25304) and compares the result with a halfword loaded from 0xffffffffffffc420, calls `llp_pfail_barrier` (0x25344), and makes repeated `vector_read` / `vector_write` calls with fixed offsets such as 0x600110, 0x30 and 0x8 (0x2532c to 0x255a0). It calls `us_delay` with 100 and 300 (0x64 and 0x12c). It tests bit 0x2000000000 of the doubleword at 0x9200000001608088 in a loop (0x253a8 to 0x253f8). The facts do not say which hardware bits or vectors these are.
  Reviewed: 2026-11-12

- `llp_pfail_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4
  **Inferred.** Role (from name): it handles a power-fail interrupt on the link layer. It loads doublewords from 0x9200000001608088 [@0x25390]. The branch at 0x2530c goes back to 0x252dc when the value in s1 differs from the result of `msc_owner_cpu` [@0x2530c taken]. It stores a doubleword to 0x9200000001600110 [@0x25488] and to 0x9200000001600008 [@0x25498]. Its return at 0x25400 returns what `us_delay` returns [@0x25400]. The facts do not show what the link registers hold, so the meaning of each write is open.
  Reviewed: 2026-11-12

- `syssgi_pfshow` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x256b8
  **Inferred.** Prints through `printf` (0x256cc to 0x25878) and calls `vector_read` at 0x256ec and 0x257c4 (first arguments 0 and 6). It passes a doubleword loaded from 0x9200000001600000 to `printf` (0x25860) and reads a halfword from 0xffffffffffffc420 at 0x256c4; the facts do not say what that halfword is. It returns the result of `printf`. Role (from name): a view of power-fail state. The facts do not link it to `llp_pfail_intr` and do not show the caller.
  Reviewed: 2026-11-12

- `syssgi_pfshow` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x256b8
  **Inferred.** Role (from name): it prints the power-fail state for a system call selector. It calls `printf` at nine sites, the first at 0x256cc [call 1, @0x256cc] and the last at 0x25878 [call 11, @0x25878], with `vector_read` calls between them. It loads a doubleword from 0x9200000001600000 [@0x25858] and passes it to the `printf` at 0x25860 [call 10, @0x25860]. Its return at 0x25894 returns the result of `printf` [@0x25894]. The facts do not show which fields the printed values come from.
  Reviewed: 2026-11-12

- `sysctlr_keepalive` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2686c
  **Inferred.** Branches on the global `heartbeat_enable` (0x268bc). It calls `_elsc_hbt` (0x26914, 0x26978, 0x2699c), with arguments 0x1e and 0x14 at the first call site and 0, 0 and 0, 1 at the others, and calls `mutex_spinlock_spl` (0x268fc) with `spl7` as its second argument and `mutex_spinunlock` (0x26930). It calls `cmn_err` (0x26a04 to 0x26ac4) at several sites and `elsc_errmsg` (0x26a3c), whose result is passed to one `cmn_err` call. The facts show the heartbeat calls but not what the remote end is.
  Reviewed: 2026-11-12

- `force_system_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x26ad4.
  It logs a message through cmn_err (0x26ae4), waits 0x7a120 units with us_delay (0x26af0), and calls elsc_system_reset (0x26af8). If that call returns a negative value, it prints through printf (0x26b14) and waits 0xf4240 units (0x26b20), then makes one store (0x26b34); otherwise it returns at 0x26b08. The branch at 0x26b30 goes to the return sequence at 0x26b04, so it is not a loop around the reset call. What the store writes is not resolved in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12

- `klhwg_invent_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x278d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x278d8-0x2794c (116 bytes).
  It occupies 116 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x27904, `ld` at 0x27920.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x27908, `ld` at 0x27924.
  2 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0, including `ld` at 0x27914, `ld` at 0x2792c.
  The `lh` at 0x27918 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49aa.
  The `sh` at 0x2791c stores 2 bytes to ret(kern_malloc) +0x0.
  The `lbu` at 0x27934 loads 1 byte from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49a8.
  The `sw` at 0x27938 stores 4 bytes to ret(kern_malloc) +0x8.
  The `sh` at 0x27940 stores 2 bytes to ret(kern_malloc) +0x2.
  The `jal` at 0x278e8 calls kern_malloc with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x278f0 targets 0x27900, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x278f8 targets 0x27944 and is always taken.
  The return at 0x27944 has v0 = one of 0x0, ret(kern_malloc).

- `klhwg_cpu_invent_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2794c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2794c-0x27acc (384 bytes).
  It occupies 384 bytes.
  The `lbu` at 0x27988 loads 1 byte from a2 (arg2 at entry) +0x2.
  2 such `sb` accesses store 1 byte to ret(klhwg_invent_alloc) +0x4, including `sb` at 0x27998, `sb` at 0x27a7c.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x38, including `lhu` at 0x2799c, `lhu` at 0x27a2c.
  The `sw` at 0x279a0 stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  3 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x3c, including `lhu` at 0x279a4, `lhu` at 0x279b8, `lhu` at 0x27a80.
  The `sw` at 0x279a8 stores 4 bytes to ret(klhwg_invent_alloc) +0x10.
  The `lhu` at 0x279ac loads 2 bytes from a2 (arg2 at entry) +0x40.
  The `sw` at 0x279b4 stores 4 bytes to ret(klhwg_invent_alloc) +0x18.
  The `lh` at 0x279ec loads 2 bytes from (sym(compact_to_nasid_node) + (a1 + a1)) +0x0.
  3 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x3e, including `lhu` at 0x279f8, `lhu` at 0x27a88, `lhu` at 0x27ac8.
  The `sw` at 0x279fc stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  3 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lw` at 0x27a00, `lw` at 0x27a9c, `lw` at 0x27ab8.
  The `sh` at 0x27a04 stores 2 bytes to ret(klhwg_invent_alloc) +0x1c.
  The `lwu` at 0x27a08 loads 4 bytes from a2 (arg2 at entry) +0x1c.
  The `ld` at 0x27a18 loads 8 bytes from (sym(pdaindr) + ([a2+28] << 0x4)) +0x8.
  The `lbu` at 0x27a1c loads 1 byte from [(sym(pdaindr) + ([a2+28] << 0x4))+8]:8 +0x520.
  The `sh` at 0x27a20 stores 2 bytes to ret(klhwg_invent_alloc) +0x1e.
  The `lhu` at 0x27a24 loads 2 bytes from a2 (arg2 at entry) +0x3a.
  The `sh` at 0x27a28 stores 2 bytes to ret(klhwg_invent_alloc) +0x20.
  The `jal` at 0x27974 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x1, a2=0x24, a3=a3 at entry (arg3).
  The `jal` at 0x279e8 calls ip27log_getenv with a0=[(sym(compact_to_nasid_node) + (a1 + a1))]:2, a1=sym(.rodata)+37384, a2=sp-48, a3=sym(.rodata)+37384, a4=0x0.
  The `jal` at 0x27a48 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x27a58 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=0x24, a3=?.
  The `jal` at 0x27aa0 calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=[a2+28], a3=a0 at entry (arg0), a4=[a2+56]:2, a5=([a2+28] << 0x4), a6=[a2+28], a7=[a2+62]:2.
  The `jal` at 0x27abc calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=[a2+28], a3=a0 at entry (arg0), a4=[a2+60]:2, a5=[sym(.sdata)+260].
  The `beq` branch at 0x27980 targets 0x27a60, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x27990 targets 0x27a78, is taken when (at(=[a2+2]:1) & 0x1) == 0, and falls through when (at(=[a2+2]:1) & 0x1) != 0.
  The `bne` branch at 0x279b0 targets 0x279c4, is taken when v0(=[sym(.sdata)+260]) != 0, and falls through when v0(=[sym(.sdata)+260]) == 0.
  The `beq` branch at 0x279bc targets 0x279f8 and is always taken.
  The `bltz` branch at 0x279f0 targets 0x27a80, is taken when v0(=ret(ip27log_getenv)) < 0 (signed), and falls through when v0(=ret(ip27log_getenv)) >= 0 (signed).
  The `bne` branch at 0x27a34 targets 0x27a94, is taken when a4(=[a2+56]:2) < 0x926 (signed), and falls through when a4(=[a2+56]:2) >= 0x926 (signed).
  The `beq` branch at 0x27a78 targets 0x2799c and is always taken.
  The `beql` branch at 0x27a84 targets 0x279fc, is taken when a5(=[sym(.sdata)+260]) == a4(=[a2+60]:2), and falls through when a5(=[sym(.sdata)+260]) != a4(=[a2+60]:2); its branch-likely delay slot `lhu a7,62(s0)` at 0x27a88 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x27a8c targets 0x27ab0 and is always taken.
  The `beq` branch at 0x27aa8 targets 0x27a40 and is always taken.
  The `beq` branch at 0x27ac4 targets 0x279fc and is always taken.
  The return at 0x27a70 has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_disabled_cpu_invent_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x27acc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x27acc-0x27c24 (344 bytes).
  It occupies 344 bytes.
  The `sb` at 0x27b24 stores 1 byte to ret(klhwg_invent_alloc) +0x4.
  The `sh` at 0x27b2c stores 2 bytes to ret(klhwg_invent_alloc) +0x2.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x38, including `lhu` at 0x27b30, `lhu` at 0x27b98.
  The `sw` at 0x27b34 stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  The `lhu` at 0x27b38 loads 2 bytes from a2 (arg2 at entry) +0x3c.
  The `sw` at 0x27b3c stores 4 bytes to ret(klhwg_invent_alloc) +0x10.
  The `lhu` at 0x27b40 loads 2 bytes from a2 (arg2 at entry) +0x40.
  The `sw` at 0x27b44 stores 4 bytes to ret(klhwg_invent_alloc) +0x18.
  The `lhu` at 0x27b48 loads 2 bytes from a2 (arg2 at entry) +0x4.
  The `sw` at 0x27b50 stores 4 bytes to ret(klhwg_invent_alloc) +0x50.
  3 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lw` at 0x27b68, `lw` at 0x27b80, `lw` at 0x27c10.
  The `sw` at 0x27b6c stores 4 bytes to ret(klhwg_invent_alloc) +0x58.
  2 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x18, including `lbu` at 0x27b70, `lbu` at 0x27b88.
  The `sw` at 0x27b74 stores 4 bytes to ret(klhwg_invent_alloc) +0x54.
  The `lhu` at 0x27b78 loads 2 bytes from a2 (arg2 at entry) +0x3e.
  The `sw` at 0x27b7c stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  The `sh` at 0x27b84 stores 2 bytes to ret(klhwg_invent_alloc) +0x1c.
  The `sh` at 0x27b8c stores 2 bytes to ret(klhwg_invent_alloc) +0x1e.
  The `lhu` at 0x27b90 loads 2 bytes from a2 (arg2 at entry) +0x3a.
  The `sh` at 0x27b94 stores 2 bytes to ret(klhwg_invent_alloc) +0x20.
  The `jal` at 0x27af8 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x1, a2=0x24, a3=a3 at entry (arg3).
  The `jal` at 0x27b14 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x46, a2=0x5c, a3=?.
  The `jal` at 0x27b4c calls get_diag_string [0x27894] with a0=[a2+4]:2, a1=?, a2=?, a3=?.
  The `jal` at 0x27b60 calls sprintf with a0=ret(klhwg_invent_alloc), a1=sym(.rodata)+37384, a2=ret(get_diag_string), a3=?.
  The `jal` at 0x27bb4 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x27bc4 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=0x24, a3=?.
  The `jal` at 0x27bd4 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x27be4 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=0x5c, a3=?.
  The `jal` at 0x27c14 calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=[a2+28], a3=a0 at entry (arg0), a4=[a2+56]:2, a5=[a2+28], a6=[a2+62]:2, a7=[a2+24]:1.
  The `beq` branch at 0x27b04 targets 0x27bec, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x27b1c targets 0x27bec, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `bne` branch at 0x27ba0 targets 0x27c08, is taken when a4(=[a2+56]:2) < 0x926 (signed), and falls through when a4(=[a2+56]:2) >= 0x926 (signed).
  The `beq` branch at 0x27c1c targets 0x27bac and is always taken.
  The return at 0x27c00 has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_baseio_inventory_add` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x27c24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x27c24-0x27cb0 (140 bytes).
  It occupies 140 bytes.
  The `sw` at 0x27c58 stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  The `sw` at 0x27c6c stores 4 bytes to ret(klhwg_invent_alloc) +0x10.
  The `sw` at 0x27c7c stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  The `jal` at 0x27c48 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x15, a2=0x20, a3=a3 at entry (arg3).
  The `jal` at 0x27c5c calls nvram_prom_version_get with a0=sp-32, a1=sp-31, a2=?, a3=?.
  The `jal` at 0x27c80 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x27c98 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=0x20, a3=?.
  The return at 0x27ca8 has v0 = ret(hwgraph_info_export_LBL).

- `klhwg_hub_invent_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x27cb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x27cb0-0x27dbc (268 bytes).
  It occupies 268 bytes.
  The `lbu` at 0x27cec loads 1 byte from a2 (arg2 at entry) +0x2.
  The `sb` at 0x27cfc stores 1 byte to ret(klhwg_invent_alloc) +0x4.
  The `sw` at 0x27d00 stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  The `lbu` at 0x27d04 loads 1 byte from a2 (arg2 at entry) +0x3.
  The `sw` at 0x27d08 stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  The `ld` at 0x27d10 loads 8 bytes from a2 (arg2 at entry) +0x58.
  The `sd` at 0x27d18 stores 8 bytes to ret(klhwg_invent_alloc) +0x18.
  The `ld` at 0x27d90 loads 8 bytes from (sym(generic_enet_fail_str) + ([a2+3]:1 << 0x3)) +0xa10.
  The `lw` at 0x27d98 loads 4 bytes from ret(klhwg_invent_alloc) +0xc.
  The `ld` at 0x27db0 loads 8 bytes from ?.
  The `jal` at 0x27cd4 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0xe, a2=0x20, a3=a3 at entry (arg3).
  The `jal` at 0x27d44 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x27d54 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=0x20, a3=?.
  The `jal` at 0x27d8c calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=[(sym(generic_enet_fail_str) + ([a2+3]:1 << 0x3))+2576]:8, a3=[a2+3]:1, a4=a0 at entry (arg0).
  The `jal` at 0x27dac calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=?, a3=?, a4=a0 at entry (arg0), a7=sym(generic_enet_fail_str).
  The `beq` branch at 0x27ce4 targets 0x27d5c, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x27cf4 targets 0x27d00, is taken when (at(=[a2+2]:1) & 0x1) == 0, and falls through when (at(=[a2+2]:1) & 0x1) != 0.
  The `bne` branch at 0x27d14 targets 0x27d74, is taken when a3(=[a2+3]:1) < 0x3 (signed), and falls through when a3(=[a2+3]:1) >= 0x3 (signed).
  The `beq` branch at 0x27d28 targets 0x27d3c, is taken when a3(?) >= 0x5 (signed), and falls through when a3(?) < 0x5 (signed).
  The `beq` branch at 0x27d34 targets 0x27d9c, is taken when v0(=[sym(maxcpus)]) >= 0x21 (signed), and falls through when v0(=[sym(maxcpus)]) < 0x21 (signed).
  The `beq` branch at 0x27d94 targets 0x27d1c and is always taken.
  The `beq` branch at 0x27db4 targets 0x27d40 and is always taken.
  The return at 0x27d6c has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_mem_invent_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x27dbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x27dbc-0x28094 (728 bytes).
  It occupies 728 bytes.
  The `sh` at 0x27e14 stores 2 bytes to ret(klhwg_invent_alloc) +0x2.
  2 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x2, including `lbu` at 0x27e18, `lbu` at 0x27f5c.
  2 such `sb` accesses store 1 byte to ret(klhwg_invent_alloc) +0x4, including `sb` at 0x27e28, `sb` at 0x28050.
  The `ld` at 0x27e7c loads 8 bytes from (a4 << 0x20) -0x6fffffffcfffff90.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x27ec4, `lw` at 0x27fbc.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x27ecc, `sw` at 0x27ef4, `sw` at 0x27fc8.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x27eec, `lh` at 0x27f00, `lh` at 0x2807c.
  5 such `sh` accesses store 2 bytes to ?, including `sh` at 0x27ef8, `sh` at 0x27efc, `sh` at 0x27f44.
  4 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x1, including `lbu` at 0x27f10, `lbu` at 0x27f48, `lbu` at 0x27f78.
  The `lh` at 0x27f14 loads 2 bytes from a2 (arg2 at entry) +0x4c.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x27f3c, `lhu` at 0x27f68.
  The `lbu` at 0x27f9c loads 1 byte from ?.
  The `sh` at 0x27fd8 stores 2 bytes to ret(klhwg_invent_alloc) +0xe.
  The `sh` at 0x27fe0 stores 2 bytes to ret(klhwg_invent_alloc) +0xc.
  The `lhu` at 0x2805c loads 2 bytes from ret(klhwg_invent_alloc) +0x0.
  The `lh` at 0x28090 loads 2 bytes from a2 (arg2 at entry) +0x3c.
  The `jal` at 0x27df0 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x3, a2=0x50, a3=a3 at entry (arg3).
  The `jal` at 0x27e40 calls ip27log_getenv with a0=a4 at entry (arg4), a1=sym(.rodata)+37384, a2=sp-144, a3=0x0, a4=0x0.
  The `jal` at 0x27e64 calls ip27log_getenv with a0=a4 at entry (arg4), a1=sym(.rodata)+37384, a2=sp-128, a3=0x0, a4=0x0.
  The `jal` at 0x27f84 calls strchr with a0=sp-144, a1=?, a2=?, a3=0x100, a7=[a2+1]:1.
  The `jal` at 0x27fe4 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=0x100.
  The `jal` at 0x27ff8 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=0x50, a3=?.
  The `jal` at 0x28068 calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=?, a3=[ret(klhwg_invent_alloc)]:2, a4=a3 at entry (arg3), a5=0xc3.
  The `beq` branch at 0x27e0c targets 0x28000, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x27e20 targets 0x2804c, is taken when (at(=[a2+2]:1) & 0x1) == 0, and falls through when (at(=[a2+2]:1) & 0x1) != 0.
  The `bltz` branch at 0x27e48 targets 0x27e6c, is taken when v0(=ret(ip27log_getenv)) < 0 (signed), and falls through when v0(=ret(ip27log_getenv)) >= 0 (signed).
  The `beq` branch at 0x27eb0 targets 0x28080 and is always taken.
  The `beq` branch at 0x27ebc targets 0x27ed0, is taken when (a1(=[a2+2]:1) & 0x1) == 0, and falls through when (a1(=[a2+2]:1) & 0x1) != 0.
  The `beq` branch at 0x27ee4 targets 0x27fcc, is taken when s0(?) >= 0x8 (signed), and falls through when s0(?) < 0x8 (signed).
  The `beq` branch at 0x27f08 targets 0x28030, is taken when a1(?) == a3(=0x100), and falls through when a1(?) != a3(=0x100).
  The `bne` branch at 0x27f28 targets 0x27f60, is taken when a7(=[a2+1]:1) < 0x2 (signed), and falls through when a7(=[a2+1]:1) >= 0x2 (signed).
  The `beq` branch at 0x27f34 targets 0x27f50, is taken when (t0(=[a2+76]:2) & a2(?)) == 0, and falls through when (t0(=[a2+76]:2) & a2(?)) != 0.
  The `beq` branch at 0x27f50 targets 0x27f7c, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x27f58 targets 0x27eb8 and is always taken.
  The `beq` branch at 0x27f60 targets 0x27f50, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x27f74 targets 0x27f4c and is always taken.
  The `bltz` branch at 0x27f7c targets 0x27fbc, is taken when a0(?) < 0 (signed), and falls through when a0(?) >= 0 (signed).
  The `beq` branch at 0x27f94 targets 0x27fbc, is taken when v0(=ret(strchr)) == 0, and falls through when v0(=ret(strchr)) != 0.
  The `beq` branch at 0x27fa4 targets 0x27fb4, is taken when a4(=0x30) == a2(?), and falls through when a4(=0x30) != a2(?).
  The `beq` branch at 0x27fb4 targets 0x27ed0 and is always taken.
  The `beq` branch at 0x27fc4 targets 0x27ed0 and is always taken.
  The `beq` branch at 0x28034 targets 0x28054, is taken when a2(=0xb4) == a4(?), and falls through when a2(=0xb4) != a4(?).
  The `bnel` branch at 0x2803c targets 0x27f14, is taken when a5(=0xc3) != a4(?), and falls through when a5(=0xc3) == a4(?); its branch-likely delay slot `lbu a7,1(s1)` at 0x28040 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x28044 targets 0x28058 and is always taken.
  The `beq` branch at 0x2804c targets 0x27e2c and is always taken.
  The `beq` branch at 0x28078 targets 0x27f10 and is always taken.
  The `beq` branch at 0x2808c targets 0x27ef0 and is always taken.
  The return at 0x28028 has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_add_hub` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28094 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28094-0x28164 (208 bytes).
  It occupies 208 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x280cc, `ld` at 0x28114.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x280d0, `ld` at 0x2811c.
  The `ld` at 0x280e4 loads 8 bytes from ([[-0x3c00]:8]:8 + (a2 << 0x3)) +0x0.
  The `ld` at 0x2812c loads 8 bytes from ?.
  The `jal` at 0x280b8 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x280c4 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x280f4 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+37384, a2=[([[-0x3c00]:8]:8 + (a2 << 0x3))]:8+19608, a3=(a2 << 0x3).
  The `jal` at 0x2810c calls klhwg_hub_invent_info with a0=?, a1=a2 at entry (arg2), a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x28128 calls init_hub_stats with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0x28134 calls sndrv_attach with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x28154 calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=?, a3=ret(hwgraph_info_add_LBL).
  The `bne` branch at 0x280fc targets 0x28148, is taken when v0(=ret(hwgraph_info_add_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) == 0.
  The `beq` branch at 0x2815c targets 0x28108 and is always taken.
  The return at 0x28140 has v0 = ret(sndrv_attach).

- `klhwg_add_disabled_cpu` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28164 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28164-0x28204 (160 bytes).
  It occupies 160 bytes.
  The `lh` at 0x28170 loads 2 bytes from a2 (arg2 at entry) +0x1e.
  The `lbu` at 0x28194 loads 1 byte from a2 (arg2 at entry) +0x18.
  The `jal` at 0x281ac calls sprintf with a0=sp-176, a1=sym(.rodata)+37384, a2=sym(.rodata)+37384, a3=sym(.rodata)+37384, a4=[a2+24]:1+97.
  The `jal` at 0x281bc calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-176, a2=sp-56, a3=?.
  The `jal` at 0x281c8 calls mark_cpuvertex_as_cpu with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x281d4 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x281e8 calls klhwg_disabled_cpu_invent_info with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x2818c targets 0x281f0, is taken when at(=[a2+30]:2) == v0(=-0x1), and falls through when at(=[a2+30]:2) != v0(=-0x1).
  The return at 0x281fc has v0 = one of -0x1, ret(klhwg_disabled_cpu_invent_info).

- `klhwg_add_cpu` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28204 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28204-0x283bc (440 bytes).
  It occupies 440 bytes.
  2 such `lh` accesses load 2 bytes from a2 (arg2 at entry) +0x1e, including `lh` at 0x28210, `lh` at 0x28270.
  The `ld` at 0x28230 loads 8 bytes from (sym(pdaindr) + ([a2+30]:2 << 0x4)) +0x8.
  The `lbu` at 0x28248 loads 1 byte from [(sym(pdaindr) + ([a2+30]:2 << 0x4))+8]:8 +0x520.
  2 such `lwu` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lwu` at 0x2827c, `lwu` at 0x28304.
  2 such `ld` accesses load 8 bytes from (sym(pdaindr) + ([a2+28] << 0x4)) +0x8, including `ld` at 0x2828c, `ld` at 0x28310.
  The `ld` at 0x2829c loads 8 bytes from [(sym(pdaindr) + ([a2+28] << 0x4))+8]:8 +0x738.
  The `sd` at 0x28314 stores 8 bytes to [(sym(pdaindr) + ([a2+28] << 0x4))+8]:8 +0x690.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lw` at 0x28318, `lw` at 0x283b8.
  2 such `ld` accesses load 8 bytes from table(sym(pdaindr)) +0x8, including `ld` at 0x28328, `ld` at 0x28344.
  2 such `ld` accesses load 8 bytes from [table(sym(pdaindr))+8]:8 +0x690, including `ld` at 0x2832c, `ld` at 0x28354.
  The `ld` at 0x2836c loads 8 bytes from ?.
  The `lbu` at 0x28374 loads 1 byte from ?.
  The `jal` at 0x28258 calls sprintf with a0=sp-176, a1=sym(.rodata)+37384, a2=sym(.rodata)+37384, a3=0x0, a4=[[(sym(pdaindr) + ([a2+30]:2 << 0x4))+8]:8+1312]:1+97.
  The `jal` at 0x28268 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-176, a2=sp-56, a3=?.
  The `jal` at 0x28274 calls mark_cpuvertex_as_cpu with a0=?, a1=[a2+30]:2, a2=?, a3=?.
  The `jal` at 0x28298 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+37384, a2=[[(sym(pdaindr) + ([a2+28] << 0x4))+8]:8+1848]:8, a3=?.
  The `jal` at 0x282a4 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x282b8 calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=sp-52, a3=?.
  The `jal` at 0x282d0 calls klhwg_cpu_invent_info with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x282e4 calls sprintf with a0=sp-176, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x282ec calls strlen with a0=sp-176, a1=?, a2=?, a3=?.
  The `jal` at 0x282fc calls kmem_alloc_node with a0=ret(strlen)+1, a1=0x101, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x28350 calls strcpy with a0=[[table(sym(pdaindr))+8]:8+1680]:8, a1=sp-176, a2=[a2+28], a3=?.
  The `jal` at 0x28380 calls sprintf with a0=sp-176, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x28390 calls hwgraph_edge_add with a0=?, a1=?, a2=sp-176, a3=?.
  The `jal` at 0x283ac calls assfail with a0=sym(.rodata)+37384, a1=sym(.rodata)+37384, a2=0x222, a3=[[table(sym(pdaindr))+8]:8+1680]:8, a4=[(sym(pdaindr) + ([a2+28] << 0x4))+8]:8.
  The `beq` branch at 0x282c0 targets 0x28368, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x28330 targets 0x283a0, is taken when a3(=[[table(sym(pdaindr))+8]:8+1680]:8) == 0, and falls through when a3(=[[table(sym(pdaindr))+8]:8+1680]:8) != 0.
  The `beq` branch at 0x28398 targets 0x282cc and is always taken.
  The `beq` branch at 0x283b4 targets 0x28338 and is always taken.
  The return at 0x28360 has v0 = ret(strcpy).

- `klhwg_add_rps` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x283bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x283bc-0x28468 (172 bytes).
  It occupies 172 bytes.
  The `sw` at 0x2842c stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  2 such `sb` accesses store 1 byte to ret(klhwg_invent_alloc) +0x4, including `sb` at 0x28430, `sb` at 0x28464.
  The `jal` at 0x283e4 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x28404 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x28414 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x17, a2=0x10, a3=?.
  The `jal` at 0x28440 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x28450 calls hwgraph_info_export_LBL with a0=?, a1=sym(.rodata)+37384, a2=0x10, a3=?.
  The `beq` branch at 0x283d4 targets 0x283f0, is taken when a1 == at(=-0x1), and falls through when a1 != at(=-0x1).
  The `beq` branch at 0x283ec targets 0x28400, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x28420 targets 0x283f0, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x28428 targets 0x28460, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x28458 targets 0x283f4 and is always taken.
  The `beq` branch at 0x28460 targets 0x28434 and is always taken.
  The return at 0x283f8 has v0 = one of ret(hwgraph_path_add), ?, ret(hwgraph_info_export_LBL).

- `klhwg_update_rps` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28468 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28468-0x284f4 (140 bytes).
  It occupies 140 bytes.
  The `ld` at 0x28480 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x28484 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x28494 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lw` at 0x284a4 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x5150.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x284e8, `sb` at 0x284f0.
  The `jal` at 0x284a0 calls hwgraph_edge_get with a0=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+20816], a1=sym(.rodata)+37384, a2=sp-32, a3=a3 at entry (arg3), a4=a0 at entry (arg0).
  The `jal` at 0x284c4 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+37384, a2=sp-24, a3=?.
  The `beq` branch at 0x28478 targets 0x284ac, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x284a8 targets 0x284b8, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `bne` branch at 0x284cc targets 0x284b0, is taken when v0(=ret(hwgraph_info_get_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) == 0.
  The `beq` branch at 0x284dc targets 0x284ec, is taken when a2(=a1) == 0, and falls through when a2(=a1) != 0.
  The `beq` branch at 0x284e4 targets 0x284ac and is always taken.
  The `beq` branch at 0x284ec targets 0x284ac and is always taken.
  The return at 0x284b0 has v0 = one of ret(hwgraph_edge_get), ?, ret(hwgraph_info_get_LBL).

- `klhwg_add_xbox_rps` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x284f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x284f4-0x285a0 (172 bytes).
  It occupies 172 bytes.
  The `sw` at 0x28564 stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  2 such `sb` accesses store 1 byte to ret(klhwg_invent_alloc) +0x4, including `sb` at 0x28568, `sb` at 0x2859c.
  The `jal` at 0x2851c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x2853c calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2854c calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x17, a2=0x10, a3=?.
  The `jal` at 0x28578 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+37384, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x28588 calls hwgraph_info_export_LBL with a0=?, a1=sym(.rodata)+37384, a2=0x10, a3=?.
  The `beq` branch at 0x2850c targets 0x28528, is taken when a1 == at(=-0x1), and falls through when a1 != at(=-0x1).
  The `beq` branch at 0x28524 targets 0x28538, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x28558 targets 0x28528, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x28560 targets 0x28598, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x28590 targets 0x2852c and is always taken.
  The `beq` branch at 0x28598 targets 0x2856c and is always taken.
  The return at 0x28530 has v0 = one of ret(hwgraph_path_add), ?, ret(hwgraph_info_export_LBL).

- `klhwg_update_xbox_rps` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x285a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x285a0-0x28628 (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x285b8 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x285bc loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x285cc loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lw` at 0x285dc loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x5150.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x2861c, `sb` at 0x28624.
  The `jal` at 0x285d8 calls hwgraph_edge_get with a0=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+20816], a1=sym(.rodata)+37384, a2=sp-32, a3=a3 at entry (arg3), a4=a0 at entry (arg0).
  The `jal` at 0x285fc calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+37384, a2=sp-24, a3=?.
  The `beq` branch at 0x285b0 targets 0x285e8, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x285e0 targets 0x285f4, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `bne` branch at 0x28604 targets 0x285e8, is taken when v0(=ret(hwgraph_info_get_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) == 0.
  The `beq` branch at 0x28610 targets 0x28620, is taken when a2(=a1) == 0, and falls through when a2(=a1) != 0.
  The `beq` branch at 0x28618 targets 0x285e8 and is always taken.
  The `beq` branch at 0x28620 targets 0x285e8 and is always taken.
  The return at 0x285ec has v0 = one of ?, ret(hwgraph_edge_get), ret(hwgraph_info_get_LBL).

- `klhwg_add_mem` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28628 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28628-0x28690 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0x2864c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata)+37384, a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x28668 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x28680 calls klhwg_mem_invent_info with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x28654 targets 0x28664, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x28688 targets 0x2865c and is always taken.
  The return at 0x2865c has v0 = one of ret(hwgraph_path_add), ret(klhwg_mem_invent_info).

- `klhwg_add_xbow` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28690 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28690-0x288a4 (532 bytes).
  It occupies 532 bytes.
  The `lbu` at 0x28698 loads 1 byte from a2 (arg2 at entry) +0x9.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x28754, `lbu` at 0x28788.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x28764, `lh` at 0x287b4, `lh` at 0x28814.
  4 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x28770, `ld` at 0x287d4, `ld` at 0x287fc.
  4 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x28778, `ld` at 0x287d8, `ld` at 0x28800.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x28780, `ld` at 0x287e4, `ld` at 0x28808.
  The `sw` at 0x287e8 stores 4 bytes to ?.
  The `lw` at 0x287ec loads 4 bytes from ?.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2880c, `sh` at 0x2882c.
  The `jal` at 0x286dc calls find_component with a0=a2 at entry (arg2), a1=0x0, a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x286ec calls hwgraph_vertex_create with a0=sp-96, a1=?, a2=?, a3=?.
  The `jal` at 0x286f4 calls xswitch_vertex_init with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2872c calls hwgraph_edge_add with a0=?, a1=?, a2=sym(.rodata)+37384, a3=?, a4=-0x1.
  The `jal` at 0x28784 calls hub_slot_to_crossbow with a0=?, a1=?, a2=?, a3=-0x1.
  The `jal` at 0x2879c calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x287b8 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=?, a3=?.
  The `jal` at 0x2883c calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=?, a3=-0x1.
  The `jal` at 0x2885c calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=0x1, a3=?.
  The `jal` at 0x28888 calls cmn_err with a0=one of 0x0, 0x4, a1=sym(.rodata)+37384, a2=?, a3=?, a6=ret(hwgraph_edge_add).
  The `beq` branch at 0x286b4 targets 0x286d4, is taken when (at(=[a2+9]:1) & 0x4) == 0, and falls through when (at(=[a2+9]:1) & 0x4) != 0.
  The `beq` branch at 0x286e4 targets 0x286bc, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `beq` branch at 0x28718 targets 0x28898 and is always taken.
  The `bne` branch at 0x28734 targets 0x2884c, is taken when v0(=ret(hwgraph_edge_add)) != 0, and falls through when v0(=ret(hwgraph_edge_add)) == 0.
  The `beq` branch at 0x28744 targets 0x28830, is taken when s0(?) >= 0x10 (signed), and falls through when s0(?) < 0x10 (signed).
  The `beq` branch at 0x2875c targets 0x2873c, is taken when (a4(?) & 0x2) == 0, and falls through when (a4(?) & 0x2) != 0.
  The `beq` branch at 0x28768 targets 0x28838, is taken when s2(?) == a3(=-0x1), and falls through when s2(?) != a3(=-0x1).
  The `beq` branch at 0x287c4 targets 0x287d0, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x287cc targets 0x2873c, is taken when a1(?) == a4(=-0x1), and falls through when a1(?) != a4(=-0x1).
  The `beq` branch at 0x287f0 targets 0x28720, is taken when s1(=a1) == s2(?), and falls through when s1(=a1) != s2(?).
  The `beq` branch at 0x28828 targets 0x28720 and is always taken.
  The `beq` branch at 0x28830 targets 0x286c0 and is always taken.
  The `beq` branch at 0x28844 targets 0x28740 and is always taken.
  The `bne` branch at 0x28850 targets 0x2886c, is taken when v0(=ret(hwgraph_edge_add)) != a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) == a2(=0x1).
  The `beq` branch at 0x28864 targets 0x28870 and is always taken.
  The `beq` branch at 0x28890 targets 0x28740 and is always taken.
  The `beq` branch at 0x2889c targets 0x28750 and is always taken.
  The return at 0x286cc has v0 = ?.

- `klhwg_add_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x288ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x288ac-0x28c80 (980 bytes).
  It occupies 980 bytes.
  The `lh` at 0x288c4 loads 2 bytes from (sym(compact_to_nasid_node) + (a1 + a1)) +0x0.
  The `ld` at 0x288f0 loads 8 bytes from (([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x2890c loads 4 bytes from ?.
  The `lbu` at 0x2896c loads 1 byte from ret(find_first_component) +0x18.
  3 such `lbu` accesses load 1 byte from ret(find_lboard) +0xa, including `lbu` at 0x2897c, `lbu` at 0x28b18, `lbu` at 0x28bc0.
  2 such `lw` accesses load 4 bytes from ret(find_lboard) +0x0, including `lw` at 0x28a08, `lw` at 0x28c0c.
  2 such `lbu` accesses load 1 byte from ret(find_first_component) +0x2, including `lbu` at 0x28a64, `lbu` at 0x28b7c.
  7 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x28aac, `ld` at 0x28ac0, `ld` at 0x28ae4.
  7 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x28ab0, `ld` at 0x28ac4, `ld` at 0x28ae8.
  5 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + (a1 << 0x3)) +0x0, including `ld` at 0x28ab8, `ld` at 0x28af4, `ld` at 0x28b14.
  The `sd` at 0x28abc stores 8 bytes to [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x5140.
  2 such `ld` accesses load 8 bytes from ((a1 << 0x3) + [[-0x3c00]:8]:8) +0x0, including `ld` at 0x28acc, `ld` at 0x28c60.
  2 such `ld` accesses load 8 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x5140, including `ld` at 0x28ad0, `ld` at 0x28c68.
  The `ld` at 0x28b04 loads 8 bytes from [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x5158.
  The `sb` at 0x28b1c stores 1 byte to [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x49a8.
  2 such `lh` accesses load 2 bytes from ret(find_lboard) +0xe, including `lh` at 0x28b30, `lh` at 0x28b3c.
  The `sh` at 0x28b34 stores 2 bytes to [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x49aa.
  The `sd` at 0x28b58 stores 8 bytes to [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x49b0.
  The `lbu` at 0x28ba4 loads 1 byte from ret(find_component) +0x2.
  The `jal` at 0x28934 calls find_lboard with a0=?, a1=0x11, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x28958 calls find_first_component with a0=ret(find_lboard), a1=0x3, a2=?, a3=?.
  The `jal` at 0x28978 calls klhwg_add_mem with a0=?, a1=a1 at entry (arg1), a2=ret(find_first_component), a3=[ret(find_lboard)+10]:1.
  The `jal` at 0x2898c calls hwgraph_path_add with a0=?, a1=sym(.rodata)+37384, a2=sp-116, a3=?.
  The `jal` at 0x289a4 calls cnode_subnode_to_cpu with a0=a1 at entry (arg1), a1=0x0, a2=?, a3=?.
  The `jal` at 0x289bc calls sprintf with a0=sp-112, a1=sym(.rodata)+37384, a2=0x0, a3=?.
  The `jal` at 0x289cc calls hwgraph_path_add with a0=?, a1=sp-112, a2=sp-108, a3=?.
  The `jal` at 0x289d8 calls mark_subnodevertex_as_subnode with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x289e4 calls pimm_bearing_node [0x288a4] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x289f0 calls find_first_component with a0=ret(find_lboard), a1=0x1, a2=?, a3=?.
  The `jal` at 0x28a28 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x28a3c calls board_to_path with a0=ret(find_lboard), a1=sp-224, a2=?, a3=?.
  The `jal` at 0x28a4c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-224, a2=sp-120, a3=?.
  The `jal` at 0x28a5c calls find_first_component with a0=ret(find_lboard), a1=0x2, a2=?, a3=?.
  The `jal` at 0x28a7c calls mark_nodevertex_as_node with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x28a8c calls dev_to_name with a0=?, a1=sp-224, a2=0x64, a3=?.
  The `jal` at 0x28a98 calls strlen with a0=ret(dev_to_name), a1=?, a2=?, a3=?.
  The `jal` at 0x28aa4 calls kmem_alloc with a0=ret(strlen)+1, a1=0x1, a2=?, a3=?.
  The `jal` at 0x28adc calls strcpy with a0=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+20800]:8, a1=ret(dev_to_name), a2=?, a3=?.
  The `jal` at 0x28b00 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+37384, a2=[[([[-0x3c00]:8]:8 + (a1 << 0x3))]:8+20824]:8, a3=?.
  The `jal` at 0x28b38 calls module_lookup with a0=[ret(find_lboard)+14]:2, a1=?, a2=?, a3=[ret(find_lboard)+14]:2, a4=[([[-0x3c00]:8]:8 + (a1 << 0x3))]:8, a5=[ret(find_lboard)+10]:1, a6=[([[-0x3c00]:8]:8 + (a1 << 0x3))]:8.
  The `jal` at 0x28b68 calls hwgraph_path_add with a0=?, a1=sym(.rodata)+37384, a2=sp-104, a3=?.
  The `jal` at 0x28b84 calls klhwg_add_cpu with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x28b94 calls find_component with a0=ret(find_lboard), a1=?, a2=0x1, a3=?.
  The `jal` at 0x28bbc calls klhwg_add_disabled_cpu with a0=?, a1=a1 at entry (arg1), a2=?, a3=[ret(find_lboard)+10]:1.
  The `jal` at 0x28c00 calls klhwg_add_hub with a0=?, a1=ret(find_first_component), a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x28c1c calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=sp-224, a3=?.
  The `jal` at 0x28c30 calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x28c4c calls assfail with a0=sym(.rodata)+37384, a1=sym(.rodata)+37384, a2=0x415, a3=?.
  The `jal` at 0x28c70 calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `beq` branch at 0x28928 targets 0x28934, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x2894c targets 0x28a38 and is always taken.
  The `beq` branch at 0x28964 targets 0x28970, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x28994 targets 0x28c2c, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x289ac targets 0x289ec, is taken when v0(=ret(cnode_subnode_to_cpu)) == s1(=-0x1), and falls through when v0(=ret(cnode_subnode_to_cpu)) != s1(=-0x1).
  The `bne` branch at 0x289f8 targets 0x28b5c, is taken when v0(=ret(find_first_component)) != 0, and falls through when v0(=ret(find_first_component)) == 0.
  The `beq` branch at 0x28a00 targets 0x28bfc, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x28a0c targets 0x28bcc, is taken when v0(=[ret(find_lboard)]) == 0, and falls through when v0(=[ret(find_lboard)]) != 0.
  The `beq` branch at 0x28a30 targets 0x28bcc, is taken when v0(=ret(find_lboard)) == 0, and falls through when v0(=ret(find_lboard)) != 0.
  The `bne` branch at 0x28a54 targets 0x28c10, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x28a70 targets 0x28954, is taken when (a1(=[ret(find_first_component)+2]:1) & 0x1) == 0, and falls through when (a1(=[ret(find_first_component)+2]:1) & 0x1) != 0.
  The `beq` branch at 0x28ad4 targets 0x28c40, is taken when a0(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+20800]:8) == 0, and falls through when a0(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+20800]:8) != 0.
  The `beq` branch at 0x28b54 targets 0x28954 and is always taken.
  The `bne` branch at 0x28b70 targets 0x28c6c, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x28b78 targets 0x28ba8 and is always taken.
  The `beq` branch at 0x28b9c targets 0x28a00, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `bne` branch at 0x28bac targets 0x28b80, is taken when (a2(?) & 0x1) != 0, and falls through when (a2(?) & 0x1) == 0.
  The `beq` branch at 0x28bc4 targets 0x28b90 and is always taken.
  The `beq` branch at 0x28c08 targets 0x28a0c and is always taken.
  The `beq` branch at 0x28c24 targets 0x28a5c and is always taken.
  The `beq` branch at 0x28c38 targets 0x289a0 and is always taken.
  The `beq` branch at 0x28c64 targets 0x28adc and is always taken.
  The `beq` branch at 0x28c78 targets 0x28b78 and is always taken.
  The return at 0x28bf4 has v0 = one of [ret(find_lboard)], ret(find_lboard).

- `klhwg_add_all_xbows` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28c80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28c80-0x28d78 (248 bytes).
  It occupies 248 bytes.
  The `lh` at 0x28c98 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `ld` at 0x28cbc loads 8 bytes from (([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x20)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x28ccc loads 4 bytes from ?.
  2 such `lw` accesses load 4 bytes from ret(find_lboard) +0x0, including `lw` at 0x28cfc, `lw` at 0x28d50.
  The `lh` at 0x28d40 loads 2 bytes from ret(find_lboard) +0x20.
  The `jal` at 0x28cec calls find_lboard with a0=?, a1=0x11, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x28d1c calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x28d30 calls find_lboard with a0=ret(find_lboard), a1=0x41, a2=?, a3=?.
  The `jal` at 0x28d44 calls klhwg_add_xbow with a0=a0 at entry (arg0), a1=[ret(find_lboard)+32]:2, a2=ret(find_lboard), a3=?.
  The `beq` branch at 0x28ce0 targets 0x28d70, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x28cf4 targets 0x28d2c and is always taken.
  The `beq` branch at 0x28d00 targets 0x28d54, is taken when v0(=[ret(find_lboard)]) == 0, and falls through when v0(=[ret(find_lboard)]) != 0.
  The `beq` branch at 0x28d24 targets 0x28d54, is taken when v0(=ret(find_lboard)) == 0, and falls through when v0(=ret(find_lboard)) != 0.
  The `beq` branch at 0x28d38 targets 0x28cfc, is taken when v0(=ret(find_lboard)) == 0, and falls through when v0(=ret(find_lboard)) != 0.
  The `beq` branch at 0x28d4c targets 0x28d00 and is always taken.
  The `beq` branch at 0x28d70 targets 0x28cec and is always taken.
  The return at 0x28d68 has v0 = one of [ret(find_lboard)], ret(find_lboard).

- `klhwg_add_all_routers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x28d78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x28d78-0x29078 (768 bytes).
  It occupies 768 bytes.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x28df0, `lh` at 0x28e94, `lh` at 0x28f18.
  The `ld` at 0x28e00 loads 8 bytes from ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x28e0c, `lw` at 0x28f24.
  2 such `lbu` accesses load 1 byte from ret(find_lboard_class) +0x9, including `lbu` at 0x28e38, `lbu` at 0x28e54.
  3 such `lw` accesses load 4 bytes from ret(find_lboard_class) +0x0, including `lw` at 0x28e64, `lw` at 0x28fa8, `lw` at 0x2903c.
  The `lw` at 0x28ea8 loads 4 bytes from ret(find_component) +0x80.
  The `lbu` at 0x28f3c loads 1 byte from ?.
  The `lbu` at 0x28f58 loads 1 byte from ret(find_first_component) +0x2.
  The `ld` at 0x28f68 loads 8 bytes from ret(find_first_component) +0x58.
  2 such `lbu` accesses load 1 byte from ret(find_lboard_class) +0xa, including `lbu` at 0x29004, `lbu` at 0x29044.
  2 such `lh` accesses load 2 bytes from ret(find_lboard_class) +0xe, including `lh` at 0x29010, `lh` at 0x29054.
  The `lh` at 0x29074 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x28e24 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x28e44 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x28e90 calls find_component with a0=ret(find_lboard_class), a1=0x0, a2=0x9, a3=?.
  The `jal` at 0x28ec8 calls strstr with a0=?, a1=sym(.rodata)+37384, a2=?, a3=0x3, a5=0x11.
  The `jal` at 0x28ee0 calls strstr with a0=ret(strstr), a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x28f48 calls find_first_component with a0=?, a1=0x2, a2=?, a3=?, a5=0x11.
  The `jal` at 0x28f8c calls board_to_path with a0=ret(find_lboard_class), a1=sp-208, a2=?, a3=?, a5=0x11.
  The `jal` at 0x28f9c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-208, a2=sp-104, a3=?.
  The `jal` at 0x28fb4 calls atoi with a0=ret(strstr)+14, a1=?, a2=?, a3=?, a5=0x11.
  The `jal` at 0x29014 calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=[ret(find_lboard_class)+14]:2, a3=?.
  The `jal` at 0x29030 calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=sp-208, a3=?.
  The `jal` at 0x29040 calls get_slotname with a0=[ret(find_lboard_class)+10]:1, a1=sp-240, a2=?, a3=?, a4=0x5f5e100, a5=0x11.
  The `jal` at 0x29058 calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=[ret(find_lboard_class)+14]:2, a3=sp-240.
  The `blez` branch at 0x28da8 targets 0x28fd0, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x28dc8 targets 0x29068 and is always taken.
  The `beq` branch at 0x28de8 targets 0x28fd0, is taken when s4(?) >= t8(=[sym(maxnodes)]) (signed), and falls through when s4(?) < t8(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x28e18 targets 0x28e24, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x28e2c targets 0x28dd0, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x28e34 targets 0x28e58 and is always taken.
  The `beq` branch at 0x28e4c targets 0x28dd0, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x28e5c targets 0x28e88, is taken when (a1(=[ret(find_lboard_class)+9]:1) & 0x4) == 0, and falls through when (a1(=[ret(find_lboard_class)+9]:1) & 0x4) != 0.
  The `bne` branch at 0x28e78 targets 0x28e3c, is taken when v0(=[ret(find_lboard_class)]) != 0, and falls through when v0(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x28e80 targets 0x28e44 and is always taken.
  The `beq` branch at 0x28ea0 targets 0x28f88, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `beq` branch at 0x28eb0 targets 0x28fc8, is taken when v0(=[ret(find_component)+128]) == 0, and falls through when v0(=[ret(find_component)+128]) != 0.
  The `beq` branch at 0x28ec0 targets 0x29000, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x28ed0 targets 0x29000, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `bne` branch at 0x28ee8 targets 0x28fb4, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x28efc targets 0x28f10 and is always taken.
  The `beq` branch at 0x28f0c targets 0x28f88, is taken when s3(?) >= 0x7 (signed), and falls through when s3(?) < 0x7 (signed).
  The `beq` branch at 0x28f1c targets 0x28f04, is taken when a4(?) == s6(=-0x1), and falls through when a4(?) != s6(=-0x1).
  The `beq` branch at 0x28f34 targets 0x28f04, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x28f40 targets 0x28f04, is taken when a5(=0x11) != a2(?), and falls through when a5(=0x11) == a2(?).
  The `beq` branch at 0x28f50 targets 0x28f04, is taken when v0(=ret(find_first_component)) == 0, and falls through when v0(=ret(find_first_component)) != 0.
  The `beq` branch at 0x28f60 targets 0x28f04, is taken when (a3(=[ret(find_first_component)+2]:1) & 0x1) == 0, and falls through when (a3(=[ret(find_first_component)+2]:1) & 0x1) != 0.
  The `bne` branch at 0x28f70 targets 0x28f04, is taken when a4(=0x5f5e100) != a6(=[ret(find_first_component)+88]:8), and falls through when a4(=0x5f5e100) == a6(=[ret(find_first_component)+88]:8).
  The `beql` branch at 0x28f78 targets 0x28f08, is taken when a6(?) == 0, and falls through when a6(?) != 0; its branch-likely delay slot `addiu s3,s3,1` at 0x28f7c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x28f80 targets 0x29040 and is always taken.
  The `beql` branch at 0x28fa4 targets 0x28e68, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0; its branch-likely delay slot `lw v0,0(s0)` at 0x28fa8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x28fac targets 0x29028 and is always taken.
  The `beq` branch at 0x28fc0 targets 0x28ef4 and is always taken.
  The `beq` branch at 0x28fc8 targets 0x28ef8 and is always taken.
  The `beq` branch at 0x29020 targets 0x28ef4 and is always taken.
  The `beq` branch at 0x29038 targets 0x28e68 and is always taken.
  The `beq` branch at 0x29060 targets 0x28f04 and is always taken.
  The `beq` branch at 0x29070 targets 0x28df4 and is always taken.
  The return at 0x28ff8 has v0 = one of ?, ret(find_lboard_class).

- `klhwg_connect_one_router` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29078 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x29078-0x292fc (644 bytes).
  It occupies 644 bytes.
  The `lbu` at 0x29094 loads 1 byte from a1 (arg1 at entry) +0x9.
  The `lbu` at 0x29128 loads 1 byte from a1 (arg1 at entry) +0x17.
  The `lw` at 0x2914c loads 4 bytes from a1 (arg1 at entry) +0x24.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x2918c, `lh` at 0x291a4, `lh` at 0x291b4.
  The `lw` at 0x291c0 loads 4 bytes from ?.
  The `lbu` at 0x29208 loads 1 byte from ?.
  The `lh` at 0x292f8 loads 2 bytes from table(0x50) +0x0.
  The `jal` at 0x290ec calls board_to_path with a0=a1 at entry (arg1), a1=sp-208, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x290fc calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-208, a2=sp-152, a3=?.
  The `jal` at 0x2910c calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=?, a3=?.
  The `jal` at 0x29198 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=?, a3=?.
  The `jal` at 0x291d8 calls board_to_path with a0=?, a1=sp-144, a2=?, a3=?.
  The `jal` at 0x291e8 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-144, a2=sp-88, a3=?.
  The `jal` at 0x291f8 calls is_specified with a0=sym(arg_maxnodes), a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x2922c calls sprintf with a0=sp-144, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x2923c calls hwgraph_edge_add with a0=?, a1=?, a2=sp-144, a3=?.
  The `jal` at 0x29258 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=0x1, a3=?.
  The `jal` at 0x29280 calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=sp-144, a3=?.
  The `jal` at 0x292ac calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=sp-208, a3=sp-144, a5=ret(hwgraph_edge_add).
  The `jal` at 0x292c8 calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=sp-208, a3=?.
  The `jal` at 0x292dc calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=[a1+23]:1, a3=?.
  The `beq` branch at 0x290b0 targets 0x290e8, is taken when (at(=[a1+9]:1) & 0x4) == 0, and falls through when (at(=[a1+9]:1) & 0x4) != 0.
  The `beq` branch at 0x29104 targets 0x2911c, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `bne` branch at 0x29114 targets 0x290bc, is taken when v0(=ret(is_specified)) != 0, and falls through when v0(=ret(is_specified)) == 0.
  The `bne` branch at 0x2911c targets 0x292bc, is taken when s0(=ret(hwgraph_traverse)) != 0, and falls through when s0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x29140 targets 0x292d8, is taken when v1(=0x1) != a2(=[a1+23]:1), and falls through when v1(=0x1) == a2(=[a1+23]:1).
  The `beq` branch at 0x29164 targets 0x292ec and is always taken.
  The `bne` branch at 0x29170 targets 0x29278, is taken when v0(=one of 0x0, 0x1) < 0x1 (unsigned), and falls through when v0(=one of 0x0, 0x1) >= 0x1 (unsigned).
  The `beq` branch at 0x29184 targets 0x29270, is taken when s0(?) >= 0x7 (signed), and falls through when s0(?) < 0x7 (signed).
  The `beq` branch at 0x29190 targets 0x29178, is taken when ra(?) == s2(=-0x1), and falls through when ra(?) != s2(=-0x1).
  The `beq` branch at 0x291a0 targets 0x291c0, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x291b8 targets 0x29178, is taken when t8(?) == s2(=-0x1), and falls through when t8(?) != s2(=-0x1).
  The `beq` branch at 0x291f0 targets 0x29224, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x29200 targets 0x29218, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `bne` branch at 0x29210 targets 0x2916c, is taken when (t9(?) & 0x4) != 0, and falls through when (t9(?) & 0x4) == 0.
  The `beq` branch at 0x29218 targets 0x2916c and is always taken.
  The `beq` branch at 0x29248 targets 0x29178, is taken when v0(=ret(hwgraph_edge_add)) == a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) != a2(=0x1).
  The `beq` branch at 0x29250 targets 0x29178, is taken when v0(=ret(hwgraph_edge_add)) == 0, and falls through when v0(=ret(hwgraph_edge_add)) != 0.
  The `bnel` branch at 0x29260 targets 0x2917c, is taken when v0(=ret(is_specified)) != 0, and falls through when v0(=ret(is_specified)) == 0; its branch-likely delay slot `addiu s0,s0,1` at 0x29264 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x29268 targets 0x29298 and is always taken.
  The `beq` branch at 0x29270 targets 0x290bc and is always taken.
  The `beq` branch at 0x29288 targets 0x29178, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x29290 targets 0x29224 and is always taken.
  The `beq` branch at 0x292b4 targets 0x2917c and is always taken.
  The `beq` branch at 0x292d0 targets 0x29128 and is always taken.
  The `beq` branch at 0x292e4 targets 0x290bc and is always taken.
  The `beq` branch at 0x292f4 targets 0x29190 and is always taken.
  The return at 0x290e0 has v0 = one of ?, ret(is_specified), ret(cmn_err).
  The instructions from 0x29220 to 0x29220 are not reached by any path from the entry, and their branches are not listed.

- `klhwg_connect_routers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x292fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x292fc-0x2943c (320 bytes).
  It occupies 320 bytes.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x29368, `lh` at 0x293dc.
  The `ld` at 0x29378 loads 8 bytes from ?.
  The `lw` at 0x29384 loads 4 bytes from ?.
  The `lw` at 0x293e0 loads 4 bytes from ret(find_lboard_class) +0x0.
  The `lh` at 0x29438 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x2939c calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x293bc calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x293d8 calls klhwg_connect_one_router with a0=a0 at entry (arg0), a1=ret(find_lboard_class), a2=?, a3=?.
  The `blez` branch at 0x29330 targets 0x29404, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x29340 targets 0x2942c and is always taken.
  The `beq` branch at 0x29360 targets 0x29404, is taken when s3(?) >= t8(=[sym(maxnodes)]) (signed), and falls through when s3(?) < t8(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x29390 targets 0x2939c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x293a4 targets 0x29348, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x293ac targets 0x293d0 and is always taken.
  The `beq` branch at 0x293c4 targets 0x29348, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `bne` branch at 0x293f4 targets 0x293b4, is taken when a1(=[ret(find_lboard_class)]) != 0, and falls through when a1(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x293fc targets 0x293bc and is always taken.
  The `beq` branch at 0x29434 targets 0x2936c and is always taken.
  The return at 0x29424 has v0 = one of ?, ret(find_lboard_class).

- `klhwg_connect_hubs` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2943c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2943c-0x29670 (564 bytes).
  It occupies 564 bytes.
  The `lbu` at 0x294a8 loads 1 byte from ?.
  The `lh` at 0x294d8 loads 2 bytes from ?.
  The `ld` at 0x294e8 loads 8 bytes from ?.
  The `lw` at 0x294f4 loads 4 bytes from ?.
  4 such `lh` accesses load 2 bytes from ret(find_first_component) +0x3c, including `lh` at 0x29524, `lh` at 0x29544, `lh` at 0x2957c.
  The `lh` at 0x29550 loads 2 bytes from (sym(nasid_to_compact_node) + ([ret(find_first_component)+60]:2 + [ret(find_first_component)+60]:2)) +0x0.
  The `lw` at 0x29580 loads 4 bytes from ret(find_first_component) +0x40.
  The `lh` at 0x2966c loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x29498 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=sym(.rodata)+37384, a3=?.
  The `jal` at 0x2950c calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x2951c calls find_first_component with a0=ret(find_lboard), a1=0x2, a2=?, a3=?.
  The `jal` at 0x29530 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=?, a3=?.
  The `jal` at 0x2955c calls board_to_path with a0=ret(find_lboard), a1=sp-208, a2=?, a3=?.
  The `jal` at 0x2956c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-208, a2=sp-152, a3=?.
  The `jal` at 0x29598 calls board_to_path with a0=?, a1=sp-144, a2=?, a3=?.
  The `jal` at 0x295a8 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-144, a2=sp-88, a3=?.
  The `jal` at 0x295c0 calls hwgraph_edge_add with a0=?, a1=?, a2=sym(.rodata)+37384, a3=?.
  The `jal` at 0x29614 calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=sp-144, a3=?.
  The `jal` at 0x2962c calls cmn_err with a0=0x4, a1=sym(.rodata)+37384, a2=sp-208, a3=?.
  The `jal` at 0x29650 calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=sp-208, a3=sp-144, a5=ret(hwgraph_edge_add).
  The `blez` branch at 0x29480 targets 0x295d8, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x29490 targets 0x29660 and is always taken.
  The `beq` branch at 0x294a0 targets 0x2960c, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x294b0 targets 0x2960c, is taken when (t8(?) & 0x4) == 0, and falls through when (t8(?) & 0x4) != 0.
  The `beq` branch at 0x294d0 targets 0x295d8, is taken when s1(?) >= t9(=[sym(maxnodes)]) (signed), and falls through when s1(?) < t9(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x29500 targets 0x2950c, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x29528 targets 0x294b8, is taken when v1(=[ret(find_first_component)+60]:2) == s5(=-0x1), and falls through when v1(=[ret(find_first_component)+60]:2) != s5(=-0x1).
  The `beq` branch at 0x29538 targets 0x2955c, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x29554 targets 0x294b8, is taken when a0(=[(sym(nasid_to_compact_node) + ([ret(find_first_component)+60]:2 + [ret(find_first_component)+60]:2))]:2) == s5(=-0x1), and falls through when a0(=[(sym(nasid_to_compact_node) + ([ret(find_first_component)+60]:2 + [ret(find_first_component)+60]:2))]:2) != s5(=-0x1).
  The `bne` branch at 0x29574 targets 0x29624, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x295b0 targets 0x29498, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beql` branch at 0x295c8 targets 0x294bc, is taken when v0(=ret(hwgraph_edge_add)) == 0, and falls through when v0(=ret(hwgraph_edge_add)) != 0; its branch-likely delay slot `addiu s1,s1,1` at 0x295cc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x295d0 targets 0x2963c and is always taken.
  The `beq` branch at 0x2961c targets 0x294bc and is always taken.
  The `beq` branch at 0x29634 targets 0x29580 and is always taken.
  The `beq` branch at 0x29658 targets 0x294bc and is always taken.
  The `beq` branch at 0x29668 targets 0x294dc and is always taken.
  The return at 0x29600 has v0 = one of ?, table(sym(compact_to_nasid_node)).
  The instructions from 0x29608 to 0x29608 are not reached by any path from the entry, and their branches are not listed.

- `klhwg_device_disable_hints_add` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29670 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x29670-0x29868 (504 bytes).
  It occupies 504 bytes.
  The `lh` at 0x296e4 loads 2 bytes from ?.
  The `ld` at 0x296f4 loads 8 bytes from ?.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x29700, `lw` at 0x29750, `lw` at 0x29794.
  6 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x29724, `lbu` at 0x29738, `lbu` at 0x2976c.
  The `lh` at 0x29864 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x29678 calls device_admin_table_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x297f4 calls device_component_canonical_name_get with a0=?, a1=?, a2=sp-336, a3=?.
  The `jal` at 0x29808 calls device_admin_table_update with a0=sp-336, a1=sym(.rodata)+37384, a2=sym(.rodata)+37384, a3=?.
  The `blez` branch at 0x296a0 targets 0x2982c, is taken when a1(=[sym(numnodes)]) <= 0 (signed), and falls through when a1(=[sym(numnodes)]) > 0 (signed).
  The `beq` branch at 0x296c0 targets 0x29858 and is always taken.
  The `beq` branch at 0x296dc targets 0x2982c, is taken when s4(?) >= a1(=[sym(numnodes)]) (signed), and falls through when s4(?) < a1(=[sym(numnodes)]) (signed).
  The `beq` branch at 0x2970c targets 0x29718, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x29718 targets 0x296c8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x29720 targets 0x2973c and is always taken.
  The `beq` branch at 0x29730 targets 0x296c8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x29748 targets 0x2976c, is taken when (a1(?) & 0x4) == 0, and falls through when (a1(?) & 0x4) != 0.
  The `bne` branch at 0x2975c targets 0x29728, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x29764 targets 0x2972c and is always taken.
  The `bne` branch at 0x29774 targets 0x29750, is taken when s6(=0x20) != a5(?), and falls through when s6(=0x20) == a5(?).
  The `blez` branch at 0x29784 targets 0x297c4, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `beq` branch at 0x297ac targets 0x297f0, is taken when (t8(?) & 0x1) == 0, and falls through when (t8(?) & 0x1) != 0.
  The `bne` branch at 0x297bc targets 0x29790, is taken when s3(?) < a0(?) (signed), and falls through when s3(?) >= a0(?) (signed).
  The `beq` branch at 0x297d8 targets 0x29730, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x297e8 targets 0x29730 and is always taken.
  The `bne` branch at 0x2981c targets 0x29790, is taken when s3(?) < a0(?) (signed), and falls through when s3(?) >= a0(?) (signed).
  The `beq` branch at 0x29824 targets 0x297c8 and is always taken.
  The `beq` branch at 0x29860 targets 0x296e8 and is always taken.
  The return at 0x29850 has v0 = one of ret(device_admin_table_init), ?.

- `klhwg_dimm_flavor_info_print` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29868 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x29868-0x29a34 (460 bytes).
  It occupies 460 bytes.
  4 such `lh` accesses load 2 bytes from ?, including `lh` at 0x298b4, `lh` at 0x29930, `lh` at 0x29998.
  The `lh` at 0x298e0 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x299c4 loads 8 bytes from ?.
  The `lw` at 0x299d0 loads 4 bytes from ?.
  The `jal` at 0x298d8 calls cmn_err with a0=0x6, a1=sym(.rodata)+37384, a2=sym(.rodata)+37384, a3=?.
  The `jal` at 0x29900 calls cmn_err with a0=0x6, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x29954 calls cmn_err with a0=0x6, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x29970 calls cmn_err with a0=0x6, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x2998c calls cmn_err with a0=0x6, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x299ec calls find_lboard with a0=?, a1=0x11, a2=0x9600000000000000, a3=?.
  The `jal` at 0x299f8 calls board_to_path with a0=ret(find_lboard), a1=sp-176, a2=?, a3=?.
  The `jal` at 0x29a08 calls cmn_err with a0=0x6, a1=sym(.rodata)+37384, a2=sp-176, a3=?.
  The `blez` branch at 0x2988c targets 0x298f8, is taken when a0 <= 0 (signed), and falls through when a0 > 0 (signed).
  The `bne` branch at 0x298b8 targets 0x2992c, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x298c0 targets 0x298d0, is taken when t8(=a2) == 0, and falls through when t8(=a2) != 0.
  The `bne` branch at 0x298f0 targets 0x298a8, is taken when s0(?) < s1(=a0) (signed), and falls through when s0(?) >= s1(=a0) (signed).
  The `bgtz` branch at 0x29908 targets 0x2999c, is taken when s1(=a0) > 0 (signed), and falls through when s1(=a0) <= 0 (signed).
  The `bne` branch at 0x29938 targets 0x29964, is taken when a3(?) != a4(?), and falls through when a3(?) == a4(?).
  The `bne` branch at 0x29940 targets 0x298e4, is taken when a6(?) != s0(?), and falls through when a6(?) == s0(?).
  The `beq` branch at 0x2995c targets 0x298e4 and is always taken.
  The `beq` branch at 0x29964 targets 0x29980, is taken when a2(?) == a5(?), and falls through when a2(?) != a5(?).
  The `beq` branch at 0x29978 targets 0x29994 and is always taken.
  The `beq` branch at 0x29994 targets 0x298e4 and is always taken.
  The `beq` branch at 0x299d8 targets 0x299ec, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x29a24 targets 0x299ac, is taken when s0(?) < s1(=a0) (signed), and falls through when s0(?) >= s1(=a0) (signed).
  The `beq` branch at 0x29a2c targets 0x29914 and is always taken.
  The return at 0x29924 has v0 = ret(cmn_err).

- `klhwg_premium_std_dimm_mix_check` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29a34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x29a34-0x29c44 (528 bytes).
  It occupies 528 bytes.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0x29ad4, `sh` at 0x29b80, `sh` at 0x29bb0.
  The `lh` at 0x29ae4 loads 2 bytes from ?.
  The `ld` at 0x29af4 loads 8 bytes from ?.
  The `lw` at 0x29b00 loads 4 bytes from ?.
  The `lh` at 0x29b2c loads 2 bytes from ret(find_first_component) +0x4c.
  The `lbu` at 0x29b44 loads 1 byte from ret(find_first_component) +0x1.
  The `lh` at 0x29c40 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x29b18 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x29b24 calls find_first_component with a0=ret(find_lboard), a1=0x3, a2=?, a3=?.
  The `jal` at 0x29bdc calls klhwg_dimm_flavor_info_print with a0=?, a1=sp-576, a2=0x0, a3=?.
  The `jal` at 0x29bec calls cmn_err with a0=0x0, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x29c00 calls cmn_err with a0=0x204, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x29c10 calls klhwg_dimm_flavor_info_print with a0=?, a1=sp-576, a2=0x0, a3=?.
  The `jal` at 0x29c20 calls klhwg_dimm_flavor_info_print with a0=?, a1=sp-1088, a2=0x1, a3=?.
  The `bne` branch at 0x29a44 targets 0x29a7c, is taken when v0(=[sym(.sdata)+264]:1) != at(=0xff), and falls through when v0(=[sym(.sdata)+264]:1) == at(=0xff).
  The `beq` branch at 0x29a4c targets 0x29a84 and is always taken.
  The `blez` branch at 0x29ab4 targets 0x29a54, is taken when a0(=[sym(numnodes)]) <= 0 (signed), and falls through when a0(=[sym(numnodes)]) > 0 (signed).
  The `beq` branch at 0x29ac0 targets 0x29c34 and is always taken.
  The `beq` branch at 0x29ac8 targets 0x29bb4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x29adc targets 0x29b84, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x29b0c targets 0x29b18, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x29b68 targets 0x29ac8, is taken when at(=[ret(find_first_component)+1]:1) < 0x2 (signed), and falls through when at(=[ret(find_first_component)+1]:1) >= 0x2 (signed).
  The `beq` branch at 0x29b70 targets 0x29b9c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x29b7c targets 0x29ad8 and is always taken.
  The `beq` branch at 0x29b84 targets 0x29a58, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `bne` branch at 0x29b8c targets 0x29bcc, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x29b94 targets 0x29a5c and is always taken.
  The `beq` branch at 0x29bac targets 0x29ad8 and is always taken.
  The `beq` branch at 0x29bc4 targets 0x29ad8 and is always taken.
  The `bne` branch at 0x29bcc targets 0x29bfc, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x29bf4 targets 0x29c2c and is always taken.
  The `beq` branch at 0x29c2c targets 0x29a60 and is always taken.
  The `beq` branch at 0x29c3c targets 0x29ae8 and is always taken.
  The return at 0x29a7c has v0 = one of [sym(.sdata)+264]:1, ?.

- `klhwg_add_all_modules` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29c44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x29c44-0x29d48 (260 bytes).
  It occupies 260 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x29c80, `ld` at 0x29ca4, `ld` at 0x29cb0.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x29c90, `lh` at 0x29cc0.
  The `jal` at 0x29c8c calls sprintf with a0=sp-192, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x29c9c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-192, a2=sp-64, a3=?.
  The `jal` at 0x29ca8 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x29cbc calls sprintf with a0=sp-192, a1=sym(.rodata)+37384, a2=?, a3=?.
  The `jal` at 0x29ccc calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-192, a2=sp-64, a3=?.
  The `jal` at 0x29ce8 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+37384, a2=0x1, a3=?.
  The `jal` at 0x29cf0 calls sndrv_attach with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x29d38 calls assfail with a0=sym(.rodata)+37384, a1=sym(.rodata)+37384, a2=0x6f0, a3=?.
  The `blez` branch at 0x29c6c targets 0x29d14, is taken when at(=[sym(nummodules)]) <= 0 (signed), and falls through when at(=[sym(nummodules)]) > 0 (signed).
  The `bne` branch at 0x29cd4 targets 0x29d34, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `bne` branch at 0x29d0c targets 0x29c7c, is taken when s0(?) < a2(=[sym(nummodules)]) (signed), and falls through when s0(?) >= a2(=[sym(nummodules)]) (signed).
  The `beq` branch at 0x29d40 targets 0x29ce0 and is always taken.
  The return at 0x29d2c has v0 = one of ?, ret(sndrv_attach).

- `klhwg_add_all_nodes` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29d48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x29d48-0x29e20 (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0x29d84 loads 8 bytes from ((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000) +0xd0.
  The `jal` at 0x29d58 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x29d90 calls klhwg_add_node with a0=a0 at entry (arg0), a1=?, a2=[((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8, a3=?.
  The `jal` at 0x29dc0 calls klhwg_add_all_xbows with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x29dec calls klhwg_add_all_routers with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x29df4 calls klhwg_connect_routers with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x29dfc calls klhwg_connect_hubs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x29e04 calls router_guardians_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x29e0c calls klhwg_device_disable_hints_add with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x29d80 targets 0x29de4, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `bnel` branch at 0x29dac targets 0x29d8c, is taken when s0(?) < a0(=[sym(numnodes)]) (signed), and falls through when s0(?) >= a0(=[sym(numnodes)]) (signed); its branch-likely delay slot `or a0,s1,zero` at 0x29db0 runs only when taken and is annulled on fall-through.
  The `blez` branch at 0x29db4 targets 0x29de8, is taken when a0(=[sym(numnodes)]) <= 0 (signed), and falls through when a0(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x29ddc targets 0x29dc0, is taken when s0(?) < t8(=[sym(numnodes)]) (signed), and falls through when s0(?) >= t8(=[sym(numnodes)]) (signed).
  The return at 0x29e18 has v0 = ret(klhwg_device_disable_hints_add).

- `hub_xtalk_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29e20
  **Inferred.** Loads a doubleword from an address computed from its first argument and returns 0 or 1 according to bit 0x2000 of that value (branch at 0x29e34). The facts do not show what the bit signifies.
  Reviewed: 2026-11-12

- `capture_hub_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a01c
  **Inferred.** Loads and stores a set of doublewords and words in a block passed as its second argument (stores at +0x4ca8 to +0x4d18), with one address indexed through `compact_to_nasid_node`. It calls `hubni_error_handler` (0x2a0e8) and `check_hub_error_rates` (0x2a140). A branch on the byte at +0x4d00 (0x2a138) and a comparison with `hub_print_usecs` (0x2a190) steer the path. The facts do not settle which counters these are.
  Reviewed: 2026-11-12

- `init_hub_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a1c0
  **Inferred.** Clears a 0x80-byte block at +19608 of its second argument with `bzero` (0x2a1f0), then stores several fields. It allocates a 0x50-byte block with `kmem_alloc_node` (0x2a25c) and, if the result is non-zero, calls `get_slotname` (0x2a274) and `sprintf` (0x2a28c) and returns the `sprintf` result at 0x2a2b0. The facts show no loop. A constant 0x116 is passed to `assfail` (0x2a2c4). The facts do not settle the meaning of the stored fields.
  Reviewed: 2026-11-12

- `bootstrap` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a5b8.
  This is a short early-boot routine. It does one 64-bit load (0x2a5e4; the address is not resolved in the facts), calls mapped_kernel_setup_tlb (0x2a60c) with its incoming a2 and a3, and then tail-jumps to .text+173620 (0x2a62c). The name and the TLB call suggest a handoff into the mapped kernel. The jump target is not named in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12

- `bootstrap` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a5b8
  **Inferred.** Role (from name): early boot code. It loads a doubleword (0x2a5e4) and two halfwords (0x2a604, 0x2a608), calls `mapped_kernel_setup_tlb` (0x2a60c) with its last two argument registers unchanged, and ends with a tail jump to `.text`+173620 (0x2a62c). The facts do not say what is at that target.
  Reviewed: 2026-11-12

- `nmi_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a730
  **Inferred.** Role (from name): a non-maskable interrupt dump. An atomic add on a counter (`atomicAddInt`, 0x2a744) is compared with 1 (0x2a750); on the equal path the code calls `cont_nmi_dump` (0x2a780). A loop calls `tlbgetent` (0x2a7e4) until a value equals 0x40 (0x2a7f4). A branch at 0x2a81c loops back while the CPU id differs from `nmi_helper_cpu`, and `dumpsys_helper` is called at 0x2a85c with the CPU id and `nmi_helper_cpu`. The facts show the sequence but not its full protocol.
  Reviewed: 2026-11-12

- `nmi_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a730
  **Inferred.** Role (from name): it dumps machine state on a non-maskable interrupt. It loads a doubleword from the fixed address 0xffffffffffffc400 [@0x2a738]. It calls `atomicAddInt` at 0x2a744 [@0x2a744]. When that result is not 1, the branch at 0x2a750 goes to 0x2a790 [@0x2a750 taken]. It stores a word at 0x2a7c8 [@0x2a7c8]. The facts do not show which CPU the dump is for, beyond the comparison at 0x2a81c.
  Reviewed: 2026-11-12

- `nmi_cpu_eframe_save` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ba8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2ba8c-0x2bb28 (156 bytes).
  It occupies 156 bytes.
  The `lw` at 0x2baec loads 4 bytes from ?.
  The `ld` at 0x2bb04 loads 8 bytes from ?.
  The `sd` at 0x2bb08 stores 8 bytes to ?.
  The `beq` branch at 0x2baf8 targets 0x2bb0c, is taken when a3(?) == a7(=-0x1), and falls through when a3(?) != a7(=-0x1).
  The `bne` branch at 0x2bb18 targets 0x2baec, is taken when a4(?) < 0x27 (signed), and falls through when a4(?) >= 0x27 (signed).
  The return at 0x2bb20 has v0 = ?.

- `nmi_node_eframe_save` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2bb28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2bb28-0x2bbc0 (152 bytes).
  It occupies 152 bytes.
  The `lh` at 0x2bb50 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x2bb5c, `ld` at 0x2bb84.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x2bb60, `ld` at 0x2bb88.
  2 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0, including `ld` at 0x2bb68, `ld` at 0x2bb90.
  2 such `lhu` accesses load 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4958, including `lhu` at 0x2bb6c, `lhu` at 0x2bb94.
  The `jal` at 0x2bb7c calls nmi_cpu_eframe_save with a0=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2bb44 targets 0x2bba8, is taken when a0 == a4(=-0x1), and falls through when a0 != a4(=-0x1).
  The `beq` branch at 0x2bb54 targets 0x2bba8, is taken when s1(=[(sym(compact_to_nasid_node) + (a0 + a0))]:2) == a4(=-0x1), and falls through when s1(=[(sym(compact_to_nasid_node) + (a0 + a0))]:2) != a4(=-0x1).
  The `blez` branch at 0x2bb70 targets 0x2bba8, is taken when t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18776]:2) <= 0 (signed), and falls through when t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18776]:2) > 0 (signed).
  The `bne` branch at 0x2bba0 targets 0x2bb7c, is taken when s0(?) < t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18776]:2) (signed), and falls through when s0(?) >= t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18776]:2) (signed).
  The return at 0x2bbb8 has v0 = one of ?, ret(nmi_cpu_eframe_save).

- `nmi_eframes_save` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2bbc0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x2bbc0-0x2bc0c (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x2bbd8 calls nmi_node_eframe_save with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x2bbcc targets 0x2bbfc, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x2bbf4 targets 0x2bbd8, is taken when s0(?) < v0(=[sym(numnodes)]) (signed), and falls through when s0(?) >= v0(=[sym(numnodes)]) (signed).
  The return at 0x2bc04 has v0 = ?.

- `counter_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2c620
  **Inferred.** The interrupt handler for the processor's count-compare timer. It reads the count with `_get_count` (0x2c7b8), rearms it with `resetcounter` (0x2c6c4, 0x2c7a0) against a stored value compared with 0xf0000000 (0x2c780), and calls `clock` (0x2c7a8) for the tick. It also dispatches to `frs_handle_counter_intr` (0x2c648), `hwperf_overflowed_intr` (0x2c670), `l2_sbe_intr` (0x2c68c) and `hwperf_intr` (0x2c6a4) on flags read from globals, and logs through `log_tstamp_event` (0x2c834, 0x2c850). Which flag selects each dispatch, and the exact condition for the `cmn_err` warning at 0x2c8d8, are not settled by these facts.
  Reviewed: 2026-11-12

- `init_timebase` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cae8
  **Inferred.** Sets up the boot time base from the time-of-day clock. It calls `rtodc` at 0x2caf0 with its own arguments, then spins reading the 64-bit counter at 0x9200000001030100 until it passes a base plus the constant 0x2625a0 (branches 0x2cb3c to 0x2cb84), and calls `rtodc` again at 0x2cb8c with that constant. The branch at 0x2cb98 compares the result with the global `time`, and one of its paths reports through `cmn_err` at 0x2cbb0 at level 4. The meaning of 0x2625a0 is not settled.
  Reviewed: 2026-11-12

- `tick_maint` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cce8
  **Inferred.** A per-tick helper that counts down a counter at `sym(.sbss)+240` and returns the new value. When the decremented count is zero (branch at 0x2cd04), it calls `__nanotime` (0x2cd34), and the return on that path is `__nanotime`'s result. The call's second argument is the counter's value and the third is 1; what `__nanotime` does with them is not settled. It also tests the global `lbolt` against 1 (0x2ccf4) and a processor index at -0x3be0 (0x2cd18). The name suggests a clock refresh, which the countdown and the call together only partly bear out.
  Reviewed: 2026-11-12

- `tick_actions` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d060
  **Inferred.** The per-clock-tick housekeeping for hardware errors and processor checks. When the byte tested at 0x2d088 is non-zero it calls `ecc_log` (0x2d090). It then calls `tlb_tick_actions` (0x2d098), and `kick_the_hub` and `hub_error_status_war` (0x2d0b0, 0x2d0c8) only when the branches at 0x2d0a8 and 0x2d0c0 do not skip them. It calls `sysctlr_check_reenable` (0x2d10c). Single-bit error polling runs through `capture_hub_stats` (0x2d364), `probe_md_errors` (0x2d37c) and `memerror_sbe_intr` (0x2d288). The path to `memerror_sbe_intr` needs `disable_sbe_polling` clear (branches 0x2d104 and 0x2d274), but the branch at 0x2d0fc also reaches `capture_hub_stats` and `probe_md_errors` without testing it. Progress checks on globals named `r10k_intervene`, `r10k_progress_nmi` and `r10k_progress_diff` report through `cmn_err` at levels 0xc (0x2d3a8) and 0xd (0x2d408).
  Reviewed: 2026-11-12

- `rtc_read` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d45c
  **Inferred.** Returns the 64-bit value at the fixed address 0x9200000001030100 with no other work. Other routines in this object load the same address directly. Treating it as the real-time clock comes from that use, not from a register map.
  Reviewed: 2026-11-12

- `set_timer_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d4c8
  **Inferred.** Role (from name): arms the next timer interrupt for the processor index in `a0`. It reads that processor's record through `pdaindr` at `a0 << 4` and then the record's pointer at +8 (fields at offsets 0x424 and 0x520). `timepoke` is called at 0x2d564 and 0x2d594, and a call for another processor is handed to `cpuaction` with `timepoke` as the action (0x2d584, 0x2d5b0). What `timepoke` writes is not shown by these facts. It returns 0 or 1 at 0x2d550, and the meaning of each value is not settled.
  Reviewed: 2026-11-12

- `set_timer_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d4c8
  **Inferred.** Role (from name): it arms the timer interrupt for a CPU or node. It calls `timepoke` at 0x2d594 [@0x2d594] and `cpuaction` at 0x2d5b0 [@0x2d5b0]. When the flag byte is zero, the branch at 0x2d508 goes to 0x2d574 [@0x2d508 taken zero]. It loads a doubleword from 0x9200000001030100 at 0x2d4e4 [@0x2d4e4] and stores a doubleword at 0x2d510 [@0x2d510]. Its return at 0x2d550 has v0 one of 0x0, 0x1 [@0x2d550]. Both stores write the value in a1, so the timer value is whatever the caller passes in a1, which the facts do not show.
  Reviewed: 2026-11-12

- `timeout_get_queuehead` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d5c0
  **Inferred.** The name says it returns a queue head, but the body does more. It works on the per-processor timeout state reached through `pdaindr` at offsets 0x5e8, 0x5f0, 0x648 and 0x678, and on the record in `a1` (fields at +0 and +0x10). It calls `normalize_RTC_value` with the counter at 0x9200000001030100 (0x2d75c, 0x2d7cc); the two calls differ in `a7` (1 and 3), and what `a7` means to the callee is not settled. The return at 0x2d738 is the address of the per-processor field at offset 1504, not a loaded value, which is consistent with the queue-head reading only if that field is a queue head.
  Reviewed: 2026-11-12

- `chktimeout_tick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d804
  **Inferred.** Runs the timeout expiry check for each processor. It calls `do_chktimeout_tick` for the current processor's list (0x2d864), then walks processor numbers up to `maxcpus` (loop ending at 0x2d974), testing `cpu_enabled` (0x2d888) and calling `do_chktimeout_tick` again (0x2d8c0). A state value in `s2` is compared with 0, 1, 3 and 4 (0x2d8e4 to 0x2d8fc), selecting actions the render does not name. The return at 0x2d958 is unresolved.
  Reviewed: 2026-11-12

- `callout_time_to_hz` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2da70
  **Inferred.** From the name, it converts a callout time to a count in clock ticks. The body loads the counter at 0x9200000001030100 once and returns a value the render does not resolve (the return at 0x2da98 has `v0 = ?`). The conversion itself is not shown, so the meaning rests on the name.
  Reviewed: 2026-11-12

- `callout_time_to_hz` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2da70
  **Inferred.** Role (from name): it converts a callout time into a tick count. The facts show one doubleword load from 0x9200000001030100 [@0x2da74] and an unknown return value [@0x2da98]. The facts show no conversion, so the role is only the name's suggestion and the unit is open.
  Reviewed: 2026-11-12

- `timein_body` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2daa0
  **Inferred.** The body of the timer-expiry delivery path for the object in `a0`. It takes the lock at `a0+8` (`mutex_spinlock_spl` at 0x2db40 and 0x2dc30, `mutex_spinunlock` at 0x2db1c, 0x2db80, 0x2dbc8, 0x2dc48). It claims a flag at `a0+88` with `test_and_set_int64` (0x2db30). It calls `timein_entry` with the record at `a0+24` (0x2db24) or `timein_entry_ithrd` with `a0` and that record (0x2dc04), and calls `set_timer_intr` (0x2db70) on one path chosen by the counter test at 0x2db60. It wakes waiters with `sv_broadcast` on `a0+112` (0x2dc3c). The names of the lock and the claimed flag are not settled.
  Reviewed: 2026-11-12

- `migrate_timeouts` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2dd28
  **Inferred.** Moves one processor's timeout list to another, judging by the two identifiers in `a0` and `a1`. When they are equal (branch at 0x2dd58), the routine goes straight to its return. Otherwise it calls `clock_prtimeout_nothrd` (0x2ddd4), allocates a record with `allocate_migrate_timeout` (0x2ddec), and only then locks the per-processor list at offset 1496 with `mutex_spinlock_spl` (0x2de04). It calls `add_migrated_timeout` (0x2de74) and `free_migrate_timeout` (0x2ded4), with `callout_free` (0x2de54) on one path. It returns `a0` or the free's result (0x2df04).
  Reviewed: 2026-11-12

- `__nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e194.
  It takes the timelock spinlock (mutex_spinlock_spl at 0x2e1a0) and reads a 64-bit counter at 0x9200000001030100. It combines that with the adjtime_delta, adjtime_RTC and adjtime_nanos values, and normalizes the result with loops that compare against 0x3b9aca00. The lock is released at 0x2e340 or 0x2e3c0. Reading 0x3b9aca00 as a count of nanoseconds per second is an inference from the constant alone.
  Grade: inferred.
  Reviewed: 2026-11-12

- `__nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e194
  **Inferred.** Computes the current time as seconds and nanoseconds from the counter at 0x9200000001030100, under `timelock` (`mutex_spinlock_spl` at 0x2e1a0, `mutex_spinunlock` at 0x2e340 and 0x2e3c0). It adds the adjustment fields `adjtime_delta` and `adjtime_RTC` (0x2e1f0), checks `adjtime_nanos` (0x2e228), and carries nanoseconds into seconds against the constant 0x3b9aca00, one billion (0x2e2b8, 0x2e2f8). It updates the stored time words reached at 0x2e318 and 0x2e3ac. The exact time base is not settled.
  Reviewed: 2026-11-12

- `nanotime_syscall` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e3d0
  **Inferred.** The syscall-facing version of the time read. It raises the interrupt level with `splprof` (0x2e3dc) and computes the time the same way as `__nanotime`, with the adjustment fields and the constant 0x3b9aca00 (0x2e4b4 to 0x2e4e4). It takes `timelock` (0x2e508) only when the branch at 0x2e500 does not skip it, and unlocks at 0x2e528 on that path. It restores the level with `splx` (0x2e530) and returns the result of `splx`. It writes a word at the caller's buffer offset 0 (0x2e4f4) and a doubleword at offset 8 (0x2e4ec), which suggests a seconds and nanoseconds pair.
  Reviewed: 2026-11-12

- `nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e548
  **Inferred.** Writes the current time into the caller's buffer at `a0`: a word at offset 0 (0x2e608, 0x2e638) and a doubleword at offset 8 (0x2e604, 0x2e640). It computes from the counter at 0x9200000001030100 and the constant 0x3b9aca00 (0x2e5b0, 0x2e5ec), and a branch on `sym(.sbss)+208` (0x2e54c) picks between two paths. The render shows no lock call, unlike `__nanotime`, so whether this path is safe without `timelock` is not settled.
  Reviewed: 2026-11-12

- `local_settime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e6cc
  **Inferred.** Sets the local time base under `timelock`: it locks with `mutex_spinlock_spl` (0x2e6e8), then carries the value in `a1` into whole seconds against the constant 0xf4240, one million (branches 0x2e704, 0x2e718, 0x2e728). It reads the counter at 0x9200000001030100 (0x2e748), stores the new base as a word and a doubleword (0x2e760, 0x2e76c), and unlocks with `mutex_spinunlock` (0x2e788), returning its value. The argument meanings are inferred from these uses.
  Reviewed: 2026-11-12

- `get_realtime_ticks` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e828
  **Inferred.** Role (from name): returns a real-time tick count. It loads the 64-bit counter at 0x9200000001030100 (0x2e830), and the return at 0x2e848 has `v0 = ?`, so the render does not show what is returned. Whether the counter is scaled or offset before the return is not shown by these facts.
  Reviewed: 2026-11-12

- `get_realtime_ticks` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e828
  **Inferred.** Role (from name): it reads the real-time count. It loads a doubleword from the fixed address 0x9200000001030100 [@0x2e830] and returns an unknown value [@0x2e848]. The facts show neither a conversion nor a unit for the count, so the unit is open.
  Reviewed: 2026-11-12

- `tstoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e850
  **Inferred.** Converts a timestamp record at `a0` to a clock value. It reads a 32-bit word at offset 0 and a doubleword at offset 8 (0x2e850, 0x2e860). When `a1` equals 1 (branch at 0x2e87c), it also loads the counter at 0x9200000001030100 (0x2e890). The two returns (0x2e884, 0x2e894) yield values the render does not resolve, so the output is not settled.
  Reviewed: 2026-11-12

- `tvtoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e89c
  **Inferred.** The same shape as `tstoclock` for a different record: a 32-bit word at `a0+4` and a doubleword at `a0+8` (0x2e89c, 0x2e8ac). When `a1` equals 1 (branch at 0x2e8dc), it loads the counter at 0x9200000001030100 (0x2e8f0). The returns (0x2e8e4, 0x2e8f4) are unresolved, and whether the record is a timeval is inferred from the name.
  Reviewed: 2026-11-12

- `tvtoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e89c
  **Inferred.** Reads a 4-byte field at offset 0x4 and an 8-byte field at offset 0x8 of its a0 argument (0x2e89c, 0x2e8ac). An equality test of a1 against 1 at 0x2e8dc picks one of two return points (0x2e8e4, 0x2e8f4). Only when a1 equals 1 does it read the fixed address 0x9200000001030100 (0x2e8f0). Role (from name): converts a time value to a clock counter. The returned values are unknown.
  Reviewed: 2026-11-12

- `tvtoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e89c
  **Inferred.** Role (from name): it converts a time value with seconds and microseconds fields into clock ticks. It loads a word at offset 0x4 of a0 [@0x2e89c] and a doubleword at offset 0x8 of a0 [@0x2e8ac]. It loads a doubleword from 0x9200000001030100 [@0x2e8f0]. The branch at 0x2e8dc goes to 0x2e8ec when a1 equals 1 [@0x2e8dc taken]. Its returns at 0x2e8e4 and 0x2e8f4 both give unknown values [@0x2e8e4] [@0x2e8f4]. The facts do not show how the count is computed.
  Reviewed: 2026-11-12

- `findcpufreq_cycles` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e924
  **Inferred.** Measures the processor clock against the counter. It reads a flag word at 0xffffffffffffc744 at entry; when it is non-zero the routine returns at once (0x2e934) with that word. Otherwise it disables interrupts with `splhi` (0x2e93c), zeroes the cycle count with `_set_count` (0x2e954), and spins reading the counter at 0x9200000001030100 until it has advanced by 0x1312d0, which is 1,250,000 ticks (branches 0x2e974 to 0x2e9c4). It then reads the cycle count with `_get_count` (0x2e9cc), passes it to `cpu_cycles_adjust` (0x2e9d4), rewrites the flag word at 0x2e9e0 and restores the level with `splx` (0x2e9e4). The meaning of the flag word is not settled.
  Reviewed: 2026-11-12

- `early_counter_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea34
  **Inferred.** A short early counter interrupt entry. It calls `resetcounter` (0x2ea3c) with the constant 0xfffffffff0000000 and returns that call's result (0x2ea48). The name suggests it runs before the full counter handler is installed, but nothing in this 28-byte body shows that.
  Reviewed: 2026-11-12

- `us_delay` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea8c
  **Inferred.** A busy-wait. It polls the counter at 0x9200000001030100 in an unrolled loop of seven loads (0x2eabc to 0x2eb20) and leaves when the counter reaches the deadline held in `a3` (branches 0x2ead0 to 0x2eb10). How `a3` is derived is not shown by these facts, so the unit it counts is not settled from them.
  Reviewed: 2026-11-12

- `us_delay` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea8c
  **Inferred.** Role (from name): it busy-waits for a number of microseconds. It loads a doubleword from 0x9200000001030100 at 0x2ead8 [@0x2ead8]. The branch at 0x2ead0 leaves for the return at 0x2eb28 when the value has reached a3 (unsigned) [@0x2ead0 taken]. The branch at 0x2eb20 goes back to 0x2ead8 while the value is below a3 (unsigned) [@0x2eb20 taken], so the routine loops on the hub timer. Its return at 0x2eb28 gives an unknown value [@0x2eb28]. The facts do not show what a3 holds at entry.
  Reviewed: 2026-11-12

- `hub_rtc_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f378
  **Inferred.** Role (from name): initialises clock registers of one node's hub; the facts do not show what they are. It calls `get_compact_nodeid` (0x2f384) with its argument and compares the answer with `a0` (branch at 0x2f38c). On a match it writes four doublewords into a block reached through a halfword table indexed by `a0*2` (0x2f3b4 to 0x2f3c0); the facts do not name that table. It returns the compact id or 1 (0x2f3c8). What the four registers hold is not settled.
  Reviewed: 2026-11-12

- `hub_rtc_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f378
  **Inferred.** Role (from name): it sets up the real-time clock registers for a node. It calls `get_compact_nodeid` at 0x2f384 [@0x2f384]. The branch at 0x2f38c goes to 0x2f3c4 when the node id differs from the result [@0x2f38c taken]. It loads a halfword through `compact_to_nasid_node` at 0x2f3a0 [@0x2f3a0]. It stores doublewords at 0x2f3b4 [@0x2f3b4], 0x2f3b8 [@0x2f3b8], 0x2f3bc [@0x2f3bc] and 0x2f3c0 [@0x2f3c0]. Its return at 0x2f3c8 returns either the result of `get_compact_nodeid` or 1 [@0x2f3c8]. The facts do not show what the registers at those addresses do.
  Reviewed: 2026-11-12

- `acktmoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0.
  It reads the 16-bit CPU id from 0xffffffffffffc420, follows the pdaindr entry and tests the flag byte at +0x520. A nonzero flag leads to one store (0x2f3f4) and a zero flag to another (0x2f404); the store addresses are not resolved in the facts. Both paths return a value derived from the CPU index (id << 4). The name suggests a timer acknowledge, but the facts do not show the timeout semantics.
  Grade: inferred.
  Reviewed: 2026-11-12

- `acktmoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0
  **Inferred.** Role (from name): acknowledges the timer interrupt for the current processor. It reads the processor index at -0x3be0 and takes that processor's record from `pdaindr` at index times 16. It tests a byte at offset 0x520 of the structure at the record's +8 (branch at 0x2f3ec). Each path stores one doubleword: one at 0x2f404 when the byte is clear and the other at 0x2f3f4 when it is set. The facts do not show the target addresses. The return is index times 16, and the meaning of the stores is inferred from the name.
  Reviewed: 2026-11-12

- `acktmoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0
  **Inferred.** Reads a halfword from the fixed address 0xffffffffffffc420 (0x2f3d0) and uses it as a per-CPU index into the pda table (sym(pdaindr), shifted by 4). It checks a flag byte at offset 0x520 of that per-CPU record (0x2f3e4, 0x2f3ec). Depending on that test it writes one doubleword, to 0x9200000001000128 (0x2f3f4) or to 0x9200000001000120 (0x2f404), and returns the shifted index. Which device registers those writes reach is unknown.
  Reviewed: 2026-11-12

- `ackkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408.
  This is a close sibling of acktmoclock. It reads the same CPU id and per-CPU flag byte; a nonzero flag leads to one store (0x2f42c) and a zero flag to another (0x2f43c), and the store addresses are not resolved in the facts. It returns a value derived from the CPU index. Its use as the clock acknowledge is inferred from the name and from the call in slowkgclock (0x2f5fc).
  Grade: inferred.
  Reviewed: 2026-11-12

- `ackkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408
  **Inferred.** Role (from name): the same shape as `acktmoclock` for the profiling clock. It reads the same processor index and per-processor record and tests the same byte at offset 0x520 (branch at 0x2f424). Each path stores one doubleword, at 0x2f43c when the byte is clear and at 0x2f42c when it is set. The facts do not show the target addresses. The name suggests acknowledging a profiling tick, which only the name supports.
  Reviewed: 2026-11-12

- `ackkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408
  **Inferred.** Role (from name): it acknowledges a clock interrupt for the current CPU. It loads a halfword from the fixed address 0xffffffffffffc420 [@0x2f408]. It stores doublewords to 0x9200000001000138 [@0x2f42c] and to 0x9200000001000130 [@0x2f43c]. When a byte flag is zero, the branch at 0x2f424 goes to 0x2f438 [@0x2f424 taken zero]. Both returns, at 0x2f430 and 0x2f438, give the same halfword value at -0x3be0 shifted left 4 bits [@0x2f430] [@0x2f438]. The facts do not show what the registers at those addresses do.
  Reviewed: 2026-11-12

- `startkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440.
  It runs under the spinlock at sym(.sbss)+288 (mutex_spinlock_spl at 0x2f44c, unlocks at 0x2f50c and 0x2f548). When the word at sym(.sdata)+392 is zero, it jumps to a setkgvector call (0x2f52c) with prof_intr as its first argument. When the word at -0x3acc equals 0x4e2 it skips ahead to the unlock at 0x2f548. Otherwise it tests the per-CPU flag byte at +0x520, does a series of loads and stores, and on one path calls cnodetocpu (0x2f4c4). The store targets are not resolved in the facts, and the 0x4e2 comparisons and the role of the flag are not established.
  Grade: inferred.
  Reviewed: 2026-11-12

- `startkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440
  **Inferred.** Role (from name): starts the profiling clock, under the lock at `sym(.sbss)+288` (`mutex_spinlock_spl` at 0x2f44c, `mutex_spinunlock` at 0x2f50c and 0x2f548). On the path that does not skip it (branch at 0x2f4bc) it picks a processor with `cnodetocpu` (0x2f4c4), and it stores doublewords at 0x2f4b0 and 0x2f528 (the facts do not show the target addresses). It installs `prof_intr` with `setkgvector` (0x2f52c) when the global at `sdata+392` is zero (branch at 0x2f45c). The constant 0x4e2 appears in the compare at 0x2f470 and as an argument at the unlock at 0x2f548; these facts do not explain it.
  Reviewed: 2026-11-12

- `startkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440
  **Inferred.** Takes the lock at offset 288 of sym(.sbss) with mutex_spinlock_spl (0x2f44c) and releases it with mutex_spinunlock (0x2f50c, 0x2f548). Under the lock it reads a word at the fixed address 0xffffffffffffc534 (0x2f464), loads doublewords from 0xffffffffffffc400, and stores a doubleword at 0x9200000001000158 (0x2f4b0). It calls cnodetocpu at 0x2f4c4 and compares its result with a halfword loaded from 0xffffffffffffc420 (0x2f4d0). When the flag at sym(.sdata)+392 is zero (0x2f45c), it calls setkgvector with prof_intr at 0x2f52c. The registers involved and the arithmetic on the counter at 0x2f4bc are unknown.
  Reviewed: 2026-11-12

- `slowkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f558.
  It takes the same spinlock as startkgclock and compares the master_procid value with the current CPU index (0x2f588). It calls ackkgclock (0x2f5fc) on one path and calls spinlock_init (0x2f61c) on the path taken when the word at sym(.sdata)+400 is zero. The name "slow" is a label only; the facts do not show a rate.
  Grade: inferred.
  Reviewed: 2026-11-12

- `slowkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f558
  **Inferred.** Role (from name): the slow clock tick. It takes the lock at offset 288 of sym(.sbss), the same one as startkgclock (mutex_spinlock_spl at 0x2f56c, mutex_spinunlock at 0x2f59c and 0x2f5f4). It reads the per-CPU record through the same pda lookup and stores doublewords at 0x9200000001000158 and 0x9200000001000150 (0x2f5c4, 0x2f614). It calls ackkgclock at 0x2f5fc. A zero flag at sym(.sdata)+400 leads to a spinlock_init call at 0x2f61c, and the audioclock global is tested at 0x2f590 before the store at 0x2f5c4. The meaning of the writes is unknown.
  Reviewed: 2026-11-12

- `prof_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x301e0.
  Role (from name): profiling clock interrupt. It calls fastick_maint (0x301f8), calls cnode_subnode_to_cpu (0x30248) on one path, and compares the counter at 0x9200000001030100 with a stored value at [[-0x3c00]+18728] (0x30284). It tests bit 0x20 of the word at -0x3d80, the same test cpuintr makes, and when it is set logs timestamp events: log_tstamp_event with 0x6e at 0x302b0, then with 0x65 and a1 of 0x6e at 0x302cc.
  Grade: inferred.
  Reviewed: 2026-11-12

- `prof_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x301e0
  **Inferred.** Role (from name): it handles the profiling clock interrupt. It calls `fastick_maint` at 0x301f8 [@0x301f8]. It stores a doubleword to 0x9200000001000118 [@0x3029c]. When the masked bit tested at 0x301f0 is set, the branch goes to 0x302a0 [@0x301f0 taken nonzero]. Its return at 0x30224 gives an unknown value or the result of `log_tstamp_event` [@0x30224].
  Reviewed: 2026-11-12

- `kl_compute_parity` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x303d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x303d8-0x30480 (168 bytes).
  It occupies 168 bytes.
  The `jal` at 0x3042c calls ecc_bitcount with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x30410 targets 0x30454, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x30440 targets 0x3044c, is taken when (v0(=ret(ecc_bitcount)) & 0x1) == 0, and falls through when (v0(=ret(ecc_bitcount)) & 0x1) != 0.
  The `bne` branch at 0x3044c targets 0x3042c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The return at 0x30478 has v0 = one of 0x0, ?.

- `kl_compute_dir_ecc_cb` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x30480 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x30480-0x30540 (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0x304d4 loads 8 bytes from ?.
  The `jal` at 0x304dc calls ecc_bitcount with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x304a8 targets 0x3052c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x304f0 targets 0x304fc, is taken when (v0(=ret(ecc_bitcount)) & 0x1) == 0, and falls through when (v0(=ret(ecc_bitcount)) & 0x1) != 0.
  The `beq` branch at 0x304fc targets 0x304d0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x30538 targets 0x304bc and is always taken.
  The return at 0x30524 has v0 = ?.

- `kl_compute_mem_ecc_cb` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x30540 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x30540-0x305b4 (116 bytes).
  It occupies 116 bytes.
  The `ld` at 0x30570 loads 8 bytes from ?.
  The `jal` at 0x30574 calls ecc_bitcount with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x3058c targets 0x30568, is taken when s0(?) < 0x8 (signed), and falls through when s0(?) >= 0x8 (signed).
  The return at 0x305ac has v0 = ?.

- `mdir_xlate_syndrome` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x305b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x305b4-0x307f4 (576 bytes).
  It occupies 576 bytes.
  The `lbu` at 0x30600 loads 1 byte from a0 (arg0 at entry) +0x0.
  8 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3060c, `lbu` at 0x3061c, `lbu` at 0x3062c.
  The `lbu` at 0x306fc loads 1 byte from sym(.rodata) +0xacbc.
  The `lw` at 0x30700 loads 4 bytes from sym(.rodata) +0xacb8.
  The `ld` at 0x30704 loads 8 bytes from sym(.rodata) +0xacb0.
  The `sdl` at 0x30708 stores 8 bytes to ?.
  The `sdr` at 0x3070c stores 8 bytes to ?.
  3 such `swl` accesses store 4 bytes to ?, including `swl` at 0x30710, `swl` at 0x30754, `swl` at 0x30798.
  3 such `swr` accesses store 4 bytes to ?, including `swr` at 0x30714, `swr` at 0x30758, `swr` at 0x3079c.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x30720, `sb` at 0x30764, `sb` at 0x307a0.
  The `lbu` at 0x3074c loads 1 byte from sym(.rodata) +0xace4.
  The `lw` at 0x30750 loads 4 bytes from sym(.rodata) +0xace0.
  The `lbu` at 0x3078c loads 1 byte from sym(.rodata) +0xaced.
  The `lw` at 0x30790 loads 4 bytes from sym(.rodata) +0xace8.
  The `lbu` at 0x30794 loads 1 byte from sym(.rodata) +0xacec.
  The `jal` at 0x305f8 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x306c4 calls sprintf with a0=?, a1=sym(.rodata)+44192, a2=?, a3=?, a4=0x7f, a7=sym(.rodata)+44192.
  The `jal` at 0x306d8 calls strcat with a0=?, a1=sym(.rodata)+44192, a2=?, a3=?.
  The `jal` at 0x307e4 calls sprintf with a0=?, a1=sym(.rodata)+44192, a2=?, a3=?, a4=0x7f, a7=sym(.rodata)+44192.
  The `beq` branch at 0x305d4 targets 0x30724, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x305e0 targets 0x30768, is taken when a1 == at(=0x2), and falls through when a1 != at(=0x2).
  The `beq` branch at 0x305e8 targets 0x307b0, is taken when a1 == v0(=0x1), and falls through when a1 != v0(=0x1).
  The `beq` branch at 0x30604 targets 0x30658, is taken when v0(=[a0]:1) == 0, and falls through when v0(=[a0]:1) != 0.
  The `beq` branch at 0x30614 targets 0x30658, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x30624 targets 0x30658, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x30634 targets 0x30658, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x30644 targets 0x30658, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x30650 targets 0x3060c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x30658 targets 0x30748, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x30664 targets 0x306f8, is taken when s1(=a2) == a4(=0x7f), and falls through when s1(=a2) != a4(=0x7f).
  The `bne` branch at 0x30670 targets 0x30698, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x30678 targets 0x306a4 and is always taken.
  The `beq` branch at 0x30690 targets 0x306a4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x30698 targets 0x30680, is taken when v0(?) != s1(=a2), and falls through when v0(?) == s1(=a2).
  The `beq` branch at 0x306a4 targets 0x30788, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x306b0 targets 0x307d0, is taken when (a6(?) & 0x80) == 0, and falls through when (a6(?) & 0x80) != 0.
  The `bne` branch at 0x306f8 targets 0x30668, is taken when s2(=a1) != 0, and falls through when s2(=a1) == 0.
  The `beq` branch at 0x3071c targets 0x306cc and is always taken.
  The `beq` branch at 0x30740 targets 0x305f0 and is always taken.
  The `beq` branch at 0x30760 targets 0x306cc and is always taken.
  The `beq` branch at 0x30780 targets 0x305f0 and is always taken.
  The `beq` branch at 0x307a8 targets 0x306cc and is always taken.
  The `beq` branch at 0x307c8 targets 0x305f0 and is always taken.
  The `beq` branch at 0x307ec targets 0x306d0 and is always taken.
  The return at 0x306f0 has v0 = ?.

- `mdir_xlate_addr_mem` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x307f4.
  It formats text into a0 with sprintf, at four call sites (0x30890 to 0x3095c) that share one format string (.rodata+44192). It does a 64-bit load at 0x30810 (address not resolved in the facts) and tests a word at 0x9000000010000090 against zero (0x30834). It also tests the incoming a2 for negative and against 0x36. The argument values 0x48 and 0x58 appear in the sprintf calls; the facts do not show what is printed, so a role as a memory-directory translation rendering comes from the name only.
  Grade: inferred.
  Reviewed: 2026-11-12

- `mdir_xlate_addr_mem` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x307f4
  **Inferred.** Role (from name): it formats a memory address for a directory translation message. It loads a doubleword from 0x9200000001200018 [@0x30810] and a word from 0x9000000010000090 [@0x3081c]. When the value at 0x9000000010000090 is zero, the branch at 0x30834 goes to 0x308ac [@0x30834 taken zero]. Its return at 0x3089c gives the result of `sprintf` [@0x3089c].
  Reviewed: 2026-11-12

- `mdir_xlate_addr_pdir` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3096c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x3096c-0x30a70 (260 bytes).
  It occupies 260 bytes.
  The `ld` at 0x30994 loads 8 bytes from abs 0x9200000001200018.
  The `jal` at 0x309f0 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=one of 0x58, 0x59, a3=one of 0x48, 0x4c, a5=a2 at entry (arg2).
  The `jal` at 0x30a14 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=one of 0x58, 0x59, a3=?, a4=a2-16, a5=a2 at entry (arg2).
  The `jal` at 0x30a60 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=one of 0x58, 0x59, a3=one of 0x48, 0x4c, a5=one of 0x58, 0x59.
  The `bltz` branch at 0x309ac targets 0x30a24, is taken when a2 < 0 (signed), and falls through when a2 >= 0 (signed).
  The `beq` branch at 0x309b4 targets 0x30a04, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x30a1c targets 0x309fc and is always taken.
  The `beq` branch at 0x30a68 targets 0x309fc and is always taken.
  The return at 0x309fc has v0 = ret(sprintf).

- `mdir_xlate_addr_sdir` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x30a70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x30a70-0x30b50 (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x30a7c loads 8 bytes from abs 0x9200000001200018.
  The `lw` at 0x30aa0 loads 4 bytes from abs 0x9000000010000090.
  The `jal` at 0x30ad8 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=?, a3=a2 at entry (arg2), a5=a2 at entry (arg2).
  The `jal` at 0x30b18 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=one of 0x58, 0x59, a3=one of 0x48, 0x4c, a5=a2 at entry (arg2).
  The `jal` at 0x30b2c calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=?, a3=?, a5=a2 at entry (arg2).
  The `jal` at 0x30b40 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+44192, a2=one of 0x58, 0x59, a3=one of 0x48, 0x4c, a5=a2 at entry (arg2).
  The `beq` branch at 0x30abc targets 0x30aec, is taken when at(=[0x9000000010000090]) == 0, and falls through when at(=[0x9000000010000090]) != 0.
  The `bltz` branch at 0x30ac8 targets 0x30b28, is taken when a5(=a2) < 0 (signed), and falls through when a5(=a2) >= 0 (signed).
  The `bltz` branch at 0x30b0c targets 0x30b3c, is taken when a5(=a2) < 0 (signed), and falls through when a5(=a2) >= 0 (signed).
  The `beq` branch at 0x30b20 targets 0x30ae4 and is always taken.
  The `beq` branch at 0x30b34 targets 0x30ae4 and is always taken.
  The `beq` branch at 0x30b48 targets 0x30ae4 and is always taken.
  The return at 0x30ae4 has v0 = ret(sprintf).

- `intrgroup_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x317d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x317d0-0x31840 (112 bytes).
  It occupies 112 bytes.
  The `sd` at 0x317e8 stores 8 bytes to sym(nasid_to_compact_node) +0x9ca0.
  The `sd` at 0x317f4 stores 8 bytes to sym(nasid_to_compact_node) +0x9ca8.
  The `sw` at 0x31808 stores 4 bytes to ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x31810, `sd` at 0x3181c.
  The `jal` at 0x317f0 calls spinlock_init with a0=sym(.bss)+39584, a1=sym(.rodata)+45480, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x31818 calls spinlock_init with a0=?, a1=sym(.rodata)+45480, a2=?, a3=?.
  The `bne` branch at 0x31828 targets 0x317fc, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The return at 0x31838 has v0 = ?.

- `intrgroup_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x31840 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x31840-0x3190c (204 bytes).
  It occupies 204 bytes.
  The `ld` at 0x31878 loads 8 bytes from ?.
  The `sd` at 0x318b4 stores 8 bytes to ?.
  The `sd` at 0x318c8 stores 8 bytes to table(sym(.bss)+39584) +0x0.
  The `sd` at 0x318d4 stores 8 bytes to table(sym(.bss)+39584) +0x8.
  The `sd` at 0x318ec stores 8 bytes to table(sym(.bss)+39584) +0x18.
  The `jal` at 0x31858 calls mutex_spinlock with a0=sym(.bss)+39584, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x318a4 calls mutex_spinunlock with a0=sym(.bss)+39584, a1=ret(mutex_spinlock), a2=?, a3=?, a7=table(sym(.bss)+39584).
  The `jal` at 0x318d0 calls mutex_spinunlock with a0=sym(.bss)+39584, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x318e4 calls kmem_zalloc with a0=([sym(maxcpus)] << 0x2), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x31880 targets 0x318b4, is taken when (a5(?) & a6(?)) == 0, and falls through when (a5(?) & a6(?)) != 0.
  The `bne` branch at 0x31898 targets 0x31874, is taken when a4(?) < 0x10 (signed), and falls through when a4(?) >= 0x10 (signed).
  The `beq` branch at 0x318ac targets 0x318f4 and is always taken.
  The return at 0x31904 has v0 = one of 0x0, table(sym(.bss)+39584).

- `intrgroup_join` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3190c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x3190c-0x31a70 (356 bytes).
  It occupies 356 bytes.
  The `ld` at 0x31948 loads 8 bytes from ?.
  The `sd` at 0x31990 stores 8 bytes to ?.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x31994, `lw` at 0x319d8, `lw` at 0x31a40.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x319f0, `ld` at 0x31a10, `ld` at 0x31a6c.
  The `sb` at 0x31a08 stores 1 byte to ([a0+24]:8 + (a1 << 0x2)) +0x0.
  The `ld` at 0x31a0c loads 8 bytes from (sym(pdaindr) + (a1 << 0x4)) +0x8.
  The `lh` at 0x31a1c loads 2 bytes from [(sym(pdaindr) + (a1 << 0x4))+8]:8 +0x424.
  The `sh` at 0x31a28 stores 2 bytes to ([a0+24]:8 + (a1 << 0x2)) +0x2.
  The `jal` at 0x31930 calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x31960 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x31998 calls sprintf with a0=sp-64, a1=sym(.rodata)+45480, a2=[a0+16], a3=?.
  The `jal` at 0x319b4 calls intr_reserve_level with a0=a1 at entry (arg1), a1=-0x1, a2=0x0, a3=-0x1, a4=sp-64.
  The `jal` at 0x319dc calls intr_connect_level with a0=a1 at entry (arg1), a1=ret(intr_reserve_level), a2=0x0, a3=sym(groupintr), a4=[a0+16], a5=0x0.
  The `jal` at 0x31a24 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?, a5=[[(sym(pdaindr) + (a1 << 0x4))+8]:8+1060]:2, a6=([a0+24]:8 + (a1 << 0x2)), a7=(a1 << 0x2).
  The `jal` at 0x31a44 calls cmn_err with a0=0x0, a1=sym(.rodata)+45480, a2=ret(intr_reserve_level), a3=[a0+16].
  The `jal` at 0x31a60 calls cmn_err with a0=0x0, a1=sym(.rodata)+45480, a2=ret(intr_reserve_level), a3=[a0+16], a4=-0x1.
  The `beq` branch at 0x31954 targets 0x31984, is taken when (a5(?) & a7(?)) == 0, and falls through when (a5(?) & a7(?)) != 0.
  The `beq` branch at 0x319c0 targets 0x31a34, is taken when v0(=ret(intr_reserve_level)) == a3(=-0x1), and falls through when v0(=ret(intr_reserve_level)) != a3(=-0x1).
  The `beq` branch at 0x319e8 targets 0x31a54, is taken when v0(=ret(intr_connect_level)) == a4(=-0x1), and falls through when v0(=ret(intr_connect_level)) != a4(=-0x1).
  The `beq` branch at 0x31a2c targets 0x31968 and is always taken.
  The `beq` branch at 0x31a4c targets 0x319cc and is always taken.
  The `beq` branch at 0x31a68 targets 0x319f4 and is always taken.
  The return at 0x3197c has v0 = ret(mutex_spinunlock).

- `intrgroup_unjoin` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x31a70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x31a70-0x31b84 (276 bytes).
  It occupies 276 bytes.
  The `ld` at 0x31aac loads 8 bytes from ?.
  The `sd` at 0x31acc stores 8 bytes to ?.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x31ad0, `ld` at 0x31af8, `ld` at 0x31b0c.
  2 such `lbu` accesses load 1 byte from ([a0+24]:8 + (a1 << 0x2)) +0x0, including `lbu` at 0x31adc, `lbu` at 0x31b08.
  The `sb` at 0x31b14 stores 1 byte to ([a0+24]:8 + (a1 << 0x2)) +0x0.
  The `sh` at 0x31b30 stores 2 bytes to ([a0+24]:8 + (a1 << 0x2)) +0x2.
  The `lw` at 0x31b70 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `jal` at 0x31a94 calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x31ae4 calls intr_disconnect_level with a0=a1 at entry (arg1), a1=[([a0+24]:8 + (a1 << 0x2))]:1, a2=?, a3=?.
  The `jal` at 0x31b04 calls intr_unreserve_level with a0=a1 at entry (arg1), a1=[([a0+24]:8 + (a1 << 0x2))]:1, a2=?, a3=?.
  The `jal` at 0x31b2c calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=-0x1, a3=([a0+24]:8 + (a1 << 0x2)), a4=([a0+24]:8 + (a1 << 0x2)).
  The `jal` at 0x31b58 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x31b74 calls cmn_err with a0=0x0, a1=sym(.rodata)+45480, a2=[([a0+24]:8 + (a1 << 0x2))]:1, a3=[a0+16].
  The `beq` branch at 0x31abc targets 0x31b54, is taken when (a5(?) & a7(?)) == 0, and falls through when (a5(?) & a7(?)) != 0.
  The `beq` branch at 0x31af0 targets 0x31b68, is taken when v0(=ret(intr_disconnect_level)) == a3(=-0x1), and falls through when v0(=ret(intr_disconnect_level)) != a3(=-0x1).
  The `beq` branch at 0x31b60 targets 0x31b38 and is always taken.
  The `beq` branch at 0x31b7c targets 0x31afc and is always taken.
  The return at 0x31b4c has v0 = ret(mutex_spinunlock).

- `intrgroup_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x31b84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x31b84-0x31c6c (232 bytes).
  It occupies 232 bytes.
  The `ld` at 0x31bdc loads 8 bytes from ?.
  The `ld` at 0x31c04 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x31c1c loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x31c34 loads 8 bytes from table(sym(.bss)+39584) +0x200.
  The `sd` at 0x31c4c stores 8 bytes to table(sym(.bss)+39584) +0x200.
  The `jal` at 0x31bb4 calls intrgroup_unjoin with a0=a0 at entry (arg0), a1=?, a2=?, a3=[sym(maxcpus)].
  The `jal` at 0x31c00 calls kmem_free with a0=[a0+24]:8, a1=([sym(maxcpus)] << 0x2), a2=?, a3=[sym(maxcpus)].
  The `jal` at 0x31c14 calls mutex_spinlock with a0=sym(.bss)+39584, a1=?, a2=?, a3=?.
  The `jal` at 0x31c48 calls mutex_spinunlock with a0=sym(.bss)+39584, a1=ret(mutex_spinlock), a2=?, a3=table(sym(.bss)+39584).
  The `blez` branch at 0x31b9c targets 0x31c64, is taken when a3(=[sym(maxcpus)]) <= 0 (signed), and falls through when a3(=[sym(maxcpus)]) > 0 (signed).
  The `beq` branch at 0x31ba8 targets 0x31bd0 and is always taken.
  The `beq` branch at 0x31bc8 targets 0x31c00, is taken when s0(?) >= a3(=[sym(maxcpus)]) (signed), and falls through when s0(?) < a3(=[sym(maxcpus)]) (signed).
  The `bne` branch at 0x31be8 targets 0x31bb0, is taken when (a4(?) & a5(?)) != 0, and falls through when (a4(?) & a5(?)) == 0.
  The `bne` branch at 0x31bf8 targets 0x31bd0, is taken when s0(?) < a3(=[sym(maxcpus)]) (signed), and falls through when s0(?) >= a3(=[sym(maxcpus)]) (signed).
  The `beq` branch at 0x31c64 targets 0x31bfc and is always taken.
  The return at 0x31c5c has v0 = ret(mutex_spinunlock).

- `hubdev_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x32ec0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x32ec0-0x32eec (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x32ed4 calls init_mutex with a0=sym(hubdev_callout_mutex), a1=0x0, a2=sym(.rodata)+46016, a3=-0x1.
  The return at 0x32ee4 has v0 = ret(init_mutex).

- `hubdev_register` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x32eec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x32eec-0x32f44 (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0x32f24 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x32f30 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `jal` at 0x32f00 calls kmem_zalloc with a0=0x10, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x32f10 calls mutex_lock with a0=sym(hubdev_callout_mutex), a1=0x19, a2=?, a3=?.
  The `jal` at 0x32f2c calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The return at 0x32f3c has v0 = ret(mutex_unlock).

- `hubdev_unregister` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x32f44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x32f44-0x32fc4 (128 bytes).
  It occupies 128 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x32f6c, `ld` at 0x32f7c, `ld` at 0x32fa4.
  The `sd` at 0x32fb0 stores 8 bytes to ?.
  The `jal` at 0x32f58 calls mutex_lock with a0=sym(hubdev_callout_mutex), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x32f88 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `jal` at 0x32fac calls kmem_free with a0=?, a1=0x10, a2=?, a3=?.
  The `jal` at 0x32fb4 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `beq` branch at 0x32f64 targets 0x32f88, is taken when a0(=[sym(hubdev_callout_list)]:8) == 0, and falls through when a0(=[sym(hubdev_callout_list)]:8) != 0.
  The `beq` branch at 0x32f70 targets 0x32fa4, is taken when at(?) == s0(=a0), and falls through when at(?) != s0(=a0).
  The `bne` branch at 0x32f80 targets 0x32f6c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x32fbc targets 0x32f94 and is always taken.
  The return at 0x32f9c has v0 = one of 0x0, 0x2.

- `hubdev_docallouts` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x32fc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x32fc4-0x33050 (140 bytes).
  It occupies 140 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x32ff8, `ld` at 0x3300c.
  The `jal` at 0x32fe4 calls mutex_lock with a0=sym(hubdev_callout_mutex), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x32ffc calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x33018 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `jal` at 0x33040 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `beq` branch at 0x32ff0 targets 0x33018, is taken when at(=[sym(hubdev_callout_list)]:8) == 0, and falls through when at(=[sym(hubdev_callout_list)]:8) != 0.
  The `bne` branch at 0x33004 targets 0x33040, is taken when v0(=ret(?)) != 0, and falls through when v0(=ret(?)) == 0.
  The `bne` branch at 0x33010 targets 0x32ff8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x33048 targets 0x33028 and is always taken.
  The return at 0x33038 has v0 = one of 0x0, ret(?).

- `hubdev_prombase_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x33050
  **Inferred.** Makes one hwgraph_info_get_LBL call (0x33064) on its a0 argument with the label string at .rodata+46016 and a stack buffer at sp-16. It reads a halfword (0x33074) whose source is unknown. It then returns a value loaded from a table based at 0x9000000030000000 (0x33084); the facts do not resolve the index. What the routine is for is unknown: the facts do not show the lookup result feeding that return value, and the callers that use the return value would settle it.
  Reviewed: 2026-11-12

- `hubdev_prombase_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x33050
  **Inferred.** Role (from name): it returns the PROM base address for a hub device. It calls `hwgraph_info_get_LBL` at 0x33064 [@0x33064]. It loads a halfword at displacement 0xa from a base the facts do not resolve [@0x33074]. Its return at 0x33084 gives v0 as 0x9000000030000000 plus a variable term [@0x33084], an address sum and not a load from that address. The facts do not show how the label lookup selects that entry.
  Reviewed: 2026-11-12

- `hubdev_cnodeid_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3308c
  **Inferred.** Makes the same hwgraph_info_get_LBL call as its neighbour at 0x33050, with the same label string and a stack buffer at sp-16 (0x330a0). It then reads a halfword (0x330b0) and returns (0x330b4). Role (from name): returns a compute-node id. The return value and the halfword's source are unknown.
  Reviewed: 2026-11-12

- `hubdev_cnodeid_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3308c
  **Inferred.** Role (from name): it returns the compact node id for a hub device. It calls `hwgraph_info_get_LBL` at 0x330a0 [@0x330a0] and loads a halfword from an address the facts do not show [@0x330b0]. Its return at 0x330b4 gives an unknown value [@0x330b4]. The facts do not show how the label result becomes a node id.
  Reviewed: 2026-11-12

- `eccf_recoverable_threshold` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3ce18
  **Inferred.** A 188-byte routine that takes a record in `a1` and returns 0 or 1. It loads the 64-bit word at `a1+0x2c0` (`ld` at 0x3ce70, 0x3cec0, 0x3cec8) and stores a 64-bit word back to it (`sd` at 0x3ceac). It also loads one doubleword through a register base the facts do not resolve (0x3ce48). The branches at 0x3ce78 and 0x3ce84 test the word at `a1+704` for zero and a value the facts do not resolve, derived from it and that doubleword, against the constant 0x3938700 (unsigned). It loads a halfword at `a1+0x2c8`, `0x2ca`, `0x2cc` or `0x2ce` (`lhu` at 0x3ce8c, the offset picked by the branches at 0x3ce50 to 0x3ce60) and stores a halfword back (`sh` at 0x3ce9c, 0x3ceb8). The return at 0x3cea4 yields 0 or 1 and the return at 0x3ceb4 yields 1. Role (from name): a threshold test for a recoverable error; the facts do not show what the counted events are.
  Reviewed: 2026-11-12

- `eccf_recoverable_threshold` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3ce18
  **Inferred.** Role (from name): it sets the threshold for recoverable ECC faults. It loads a doubleword from 0x9200000001030100 [@0x3ce48] and loads doublewords from offset 0x2c0 of a1 [@0x3ce70]. When the value at offset 0x2c0 of a1 is zero, the branch at 0x3ce78 goes to 0x3ceac [@0x3ce78 taken zero]. It stores a halfword at one of the offsets 0x2c8, 0x2ca, 0x2cc or 0x2ce of a1 [@0x3ce9c], and stores a doubleword at offset 0x2c0 of a1 [@0x3ceac]. Its return at 0x3cea4 has v0 one of 0x0, 0x1 [@0x3cea4], and its return at 0x3ceb4 has v0 = 0x1 [@0x3ceb4].
  Reviewed: 2026-11-12

- `ecc_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3cfcc.
  It works on a structure passed in a1, reading fields from offset 0x0 up to 0x2bc and writing several of them back. It passes the error word at a1+24 to cer_to_hex (0x3d028), tests its top bits and several field masks, and calls eccf_recoverable_threshold (0x3d0cc); when that returns zero it goes to failsoft_panic_check (0x3d558). It calls ecc_cacheOp (callee at 0x3c820) with codes 0, 1, 3, 4, 5 and 7, calls ecc_force_cache_line_invalid, calls save_cache_error (0x3d298) and memerror_handle_uce (0x3d63c), and ends with a cmn_err_tag call at 0x3d720. The mapping from mask bits to error classes is not established.
  Grade: inferred.
  Reviewed: 2026-11-12

- `ecc_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3cfcc
  **Inferred.** A 2008-byte routine that takes a record in `a1`. It reads the record fields at `+0x18`, `+0x2b8` and `+0x2bc` among others, and calls `eccf_recoverable_threshold` (0x3d0cc) with the word at `+0x18` in `a2`. It calls `ecc_cacheOp` with first-argument values 0x4, 0x0, 0x1, 0x5, 0x3 and 0x7 (calls at 0x3d144 to 0x3d654) and `ecc_force_cache_line_invalid` (0x3d1b8, 0x3d1c8, 0x3d664). It also calls `save_cache_error` (0x3d298), `memerror_handle_uce` (0x3d63c), `failsoft_panic_check` (0x3d558) and `cmn_err_tag` (0x3d720) with message id 0xb96. Near 0x3d6c4 to 0x3d6e8 it loads from addresses based on `nasid_to_compact_node`; the facts do not show what is mapped. Role (from name): an error handler for cache and memory errors. The meaning of each `ecc_cacheOp` value is not shown by the facts.
  Reviewed: 2026-11-12

- `md_perf_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x41ce4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x41ce4-0x41db4 (208 bytes).
  It occupies 208 bytes.
  The `sh` at 0x41d2c stores 2 bytes to sym(nasid_to_compact_node) +0xa952.
  The `sw` at 0x41d34 stores 4 bytes to sym(nasid_to_compact_node) +0xa96c.
  The `sh` at 0x41d40 stores 2 bytes to sym(nasid_to_compact_node) +0xa954.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x41d44, `ld` at 0x41d9c.
  The `ld` at 0x41d48 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x41d60 loads 8 bytes from ?.
  The `lh` at 0x41d64 loads 2 bytes from ?.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0x41d68, `sh` at 0x41d7c, `sh` at 0x41d80.
  The `sw` at 0x41d70 stores 4 bytes to ?.
  The `jal` at 0x41cf0 calls spinlock_init with a0=sym(mdp_lock), a1=sym(.rodata)+52312, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x41d14 calls init_mutex with a0=sym(global_mdp_mon), a1=0x0, a2=sym(.rodata)+52312, a3=0x0.
  The `jal` at 0x41d84 calls init_mutex with a0=?, a1=0x0, a2=sym(.rodata)+52312, a3=?.
  The `blez` branch at 0x41d3c targets 0x41da0, is taken when a1(=[sym(maxnodes)]) <= 0 (signed), and falls through when a1(=[sym(maxnodes)]) > 0 (signed).
  The `bnel` branch at 0x41d98 targets 0x41d48, is taken when s0(?) < a5(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a5(=[sym(maxnodes)]) (signed); its branch-likely delay slot `ld a4,-15360(zero)` at 0x41d9c runs only when taken and is annulled on fall-through.
  The return at 0x41dac has v0 = ret(init_mutex).

- `md_perf_turnon_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x41db4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x41db4-0x42008 (596 bytes).
  It occupies 596 bytes.
  The `ld` at 0x41dec loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x41df0 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x41dfc loads 8 bytes from ((a1 << 0x3) + [[-0x3c00]:8]:8) +0x0.
  The `lh` at 0x41e00 loads 2 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4956.
  4 such `lh` accesses load 2 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49f2, including `lh` at 0x41e2c, `lh` at 0x41ed8, `lh` at 0x41ef0.
  2 such `sh` accesses store 2 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49f0, including `sh` at 0x41e60, `sh` at 0x41e98.
  3 such `sh` accesses store 2 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49f2, including `sh` at 0x41e6c, `sh` at 0x41eec, `sh` at 0x41f98.
  2 such `sh` accesses store 2 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49f4, including `sh` at 0x41e74, `sh` at 0x41ecc.
  The `lw` at 0x41e80 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x41e8c stores 4 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4b60.
  The `lh` at 0x41e90 loads 2 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49f0.
  The `lw` at 0x41f20 loads 4 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4a0c.
  The `sw` at 0x41f28 stores 4 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4a0c.
  The `ld` at 0x41f70 loads 8 bytes from ?.
  The `sd` at 0x41f7c stores 8 bytes to ?.
  The `ld` at 0x41fb4 loads 8 bytes from (sym(pdaindr) + ([[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2 << 0x4)) +0x8.
  The `sb` at 0x41fc4 stores 1 byte to [(sym(pdaindr) + ([[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2 << 0x4))+8]:8 +0x522.
  The `jal` at 0x41e24 calls mutex_lock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8, a6=[[-0x3c00]:8]:8.
  The `jal` at 0x41e3c calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=0x150, a2=?, a3=?.
  The `jal` at 0x41e68 calls bzero with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18960, a1=0x150, a2=?, a3=?.
  The `jal` at 0x41ee8 calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?, a5=[a0], a6=0x1.
  The `jal` at 0x41f30 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=[sym(mdp_mode)]:2, a3=?, a5=[sym(mdp_cnt)]+1, a6=0x4.
  The `jal` at 0x41f94 calls md_perf_start_count with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18928, a1=0x7fffffffffffffff, a2=?, a3=?, a5=([[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2 | 0x1).
  The `jal` at 0x41f9c calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=?, a2=?, a3=?.
  The `jal` at 0x41fd0 calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=?, a2=?, a3=a2 at entry (arg2), a5=[a0], a6=0x1.
  The `jal` at 0x41fe0 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=[sym(mdp_mode)]:2, a3=?, a5=[sym(mdp_cnt)]+1, a6=0x4.
  The `jal` at 0x41fe8 calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=?, a2=?, a3=?.
  The `beq` branch at 0x41dd4 targets 0x41e48, is taken when a1 >= at(=[sym(maxnodes)]) (signed), and falls through when a1 < at(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x41ddc targets 0x41e48, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0x41de4 targets 0x41e48, is taken when a1 == s1(=-0x1), and falls through when a1 != s1(=-0x1).
  The `beq` branch at 0x41e10 targets 0x41fc8, is taken when v1(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2) == s1(=-0x1), and falls through when v1(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2) != s1(=-0x1).
  The `beq` branch at 0x41e34 targets 0x41e60, is taken when (a7(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x1) == 0, and falls through when (a7(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x1) != 0.
  The `beq` branch at 0x41e88 targets 0x41ff8 and is always taken.
  The `beq` branch at 0x41ea8 targets 0x41ed0, is taken when v0(?) >= 0x6 (signed), and falls through when v0(?) < 0x6 (signed).
  The `beq` branch at 0x41eb0 targets 0x41e9c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x41eb8 targets 0x41e90, is taken when a1(?) != s1(=-0x1), and falls through when a1(?) == s1(=-0x1).
  The `beq` branch at 0x41ec8 targets 0x41e9c and is always taken.
  The `beq` branch at 0x41ed0 targets 0x41fd0, is taken when a1(?) == s1(=-0x1), and falls through when a1(?) != s1(=-0x1).
  The `beq` branch at 0x41f08 targets 0x41f2c, is taken when (a4(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x4) == 0, and falls through when (a4(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x4) != 0.
  The `beq` branch at 0x41f10 targets 0x41fe0, is taken when a2(=[sym(mdp_mode)]:2) == a1(=0x2), and falls through when a2(=[sym(mdp_mode)]:2) != a1(=0x2).
  The `bne` branch at 0x41f78 targets 0x41f5c, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `bne` branch at 0x41f80 targets 0x41f48, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x41fc0 targets 0x41e48 and is always taken.
  The `beq` branch at 0x41fc8 targets 0x41e4c and is always taken.
  The `beq` branch at 0x41fd8 targets 0x41e48 and is always taken.
  The `beq` branch at 0x41ff0 targets 0x41e48 and is always taken.
  The `beq` branch at 0x42000 targets 0x41eb0 and is always taken.
  The return at 0x41e58 has v0 = one of 0x0, 0x10, 0x16.

- `md_perf_turnoff_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42008 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42008-0x42154 (332 bytes).
  It occupies 332 bytes.
  The `ld` at 0x42038 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x4203c loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x42048 loads 8 bytes from ((a0 << 0x3) + [[-0x3c00]:8]:8) +0x0.
  The `lh` at 0x4204c loads 2 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4956.
  3 such `lh` accesses load 2 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49f2, including `lh` at 0x42070, `lh` at 0x42094, `lh` at 0x420d8.
  The `lw` at 0x420c4 loads 4 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4a0c.
  The `sw` at 0x420cc stores 4 bytes to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x4a0c.
  The `sh` at 0x420ec stores 2 bytes to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49f2.
  The `ld` at 0x42110 loads 8 bytes from (sym(pdaindr) + ([[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2 << 0x4)) +0x8.
  The `sb` at 0x42118 stores 1 byte to [(sym(pdaindr) + ([[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2 << 0x4))+8]:8 +0x522.
  The `jal` at 0x42068 calls mutex_lock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=-0x1.
  The `jal` at 0x4208c calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?.
  The `jal` at 0x420d0 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=?, a4=[sym(mdp_cnt)], a5=[sym(mdp_mode)]:2.
  The `jal` at 0x420e8 calls md_perf_stop_count with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18928, a1=?, a2=?, a3=?.
  The `jal` at 0x420f0 calls md_perf_update_count with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18928, a1=?, a2=?, a3=?.
  The `jal` at 0x420f8 calls mutex_unlock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=?, a2=?, a3=?.
  The `jal` at 0x4212c calls mutex_unlock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=?, a2=?, a3=?.
  The `jal` at 0x42144 calls mutex_unlock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18936, a1=?, a2=?, a3=?.
  The `beq` branch at 0x42020 targets 0x4211c, is taken when a0 >= at(=[sym(maxnodes)]) (signed), and falls through when a0 < at(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x42028 targets 0x4211c, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x42030 targets 0x4211c, is taken when a0 == a4(=-0x1), and falls through when a0 != a4(=-0x1).
  The `beq` branch at 0x42054 targets 0x4213c, is taken when v1(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2) == a4(=-0x1), and falls through when v1(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18774]:2) != a4(=-0x1).
  The `beq` branch at 0x4207c targets 0x42144, is taken when (v0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x1) == 0, and falls through when (v0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x1) != 0.
  The `bne` branch at 0x42084 targets 0x4212c, is taken when a0(=a1) != v0(?), and falls through when a0(=a1) == v0(?).
  The `beq` branch at 0x420a8 targets 0x420d0, is taken when (a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x4) == 0, and falls through when (a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+18930]:2) & 0x4) != 0.
  The `beq` branch at 0x42134 targets 0x4211c and is always taken.
  The `beq` branch at 0x4213c targets 0x4211c and is always taken.
  The `beq` branch at 0x4214c targets 0x4211c and is always taken.
  The return at 0x42124 has v0 = one of -0x1, 0x0, 0x16.

- `md_perf_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42154 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42154-0x42288 (308 bytes).
  It occupies 308 bytes.
  2 such `lw` accesses load 4 bytes from sym(nasid_to_compact_node) +0xa96c, including `lw` at 0x42224, `lw` at 0x42258.
  The `lh` at 0x42228 loads 2 bytes from sym(nasid_to_compact_node) +0xa952.
  The `sw` at 0x42230 stores 4 bytes to sym(nasid_to_compact_node) +0xa96c.
  The `lw` at 0x42234 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sh` at 0x4223c stores 2 bytes to sym(nasid_to_compact_node) +0xa952.
  The `sw` at 0x42248 stores 4 bytes to sym(nasid_to_compact_node) +0xaac0.
  The `sw` at 0x42264 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x4216c calls cap_able with a0=0x2000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x42188 calls mutex_lock with a0=sym(global_mdp_mon), a1=0x19, a2=?, a3=?.
  The `jal` at 0x42190 calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?.
  The `jal` at 0x421a4 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x421ac calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x421d8 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x421fc calls md_perf_turnon_node with a0=a0 at entry (arg0), a1=?, a2=0x2, a3=?.
  The `jal` at 0x42244 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?, a4=[a0], a5=sym(global_mdp_mon), a6=([sym(global_mdp_mon+2)]:2 | 0x1), a7=[sym(global_mdp_mon+28)]+1.
  The `jal` at 0x42270 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x42278 calls md_perf_disable with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x42174 targets 0x42268, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x4219c targets 0x421cc, is taken when t8(=[sym(mdp_mode)]:2) == 0, and falls through when t8(=[sym(mdp_mode)]:2) != 0.
  The `blez` branch at 0x421e4 targets 0x42220, is taken when ra(=[sym(maxnodes)]) <= 0 (signed), and falls through when ra(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x42208 targets 0x42270, is taken when v0(=ret(md_perf_turnon_node)) != 0, and falls through when v0(=ret(md_perf_turnon_node)) == 0.
  The `bne` branch at 0x42218 targets 0x421f4, is taken when s0(?) < a0(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a0(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x42260 targets 0x421b8 and is always taken.
  The `beq` branch at 0x42268 targets 0x421b8 and is always taken.
  The `beq` branch at 0x42280 targets 0x421b8 and is always taken.
  The return at 0x421c4 has v0 = one of 0x10, 0x0, 0x1, ret(md_perf_turnon_node).

- `md_perf_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42288 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42288-0x4238c (260 bytes).
  It occupies 260 bytes.
  The `lh` at 0x42320 loads 2 bytes from sym(nasid_to_compact_node) +0xa952.
  The `sh` at 0x42338 stores 2 bytes to sym(nasid_to_compact_node) +0xa952.
  The `lw` at 0x42340 loads 4 bytes from sym(nasid_to_compact_node) +0xa96c.
  The `sw` at 0x42350 stores 4 bytes to sym(nasid_to_compact_node) +0xa96c.
  The `jal` at 0x42294 calls cap_able with a0=0x2000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x422b0 calls mutex_lock with a0=sym(global_mdp_mon), a1=0x19, a2=?, a3=?.
  The `jal` at 0x422c8 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x422ec calls md_perf_turnoff_node with a0=?, a1=0x2, a2=?, a3=?.
  The `jal` at 0x42310 calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?.
  The `jal` at 0x42334 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=sym(global_mdp_mon), a4=-0x2.
  The `jal` at 0x4234c calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?, a5=[sym(global_mdp_mon+28)]+1, a6=sym(global_mdp_mon).
  The `jal` at 0x4237c calls assfail with a0=sym(.rodata)+52312, a1=sym(.rodata)+52312, a2=0x178, a3=?.
  The `beq` branch at 0x4229c targets 0x42368, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x422c0 targets 0x422d8, is taken when t8(=[sym(mdp_mode)]:2) == t9(=0x2), and falls through when t8(=[sym(mdp_mode)]:2) != t9(=0x2).
  The `beq` branch at 0x422d0 targets 0x42358 and is always taken.
  The `blez` branch at 0x422d8 targets 0x4230c, is taken when v0(=[sym(maxnodes)]) <= 0 (signed), and falls through when v0(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x422f4 targets 0x42370, is taken when v0(=ret(md_perf_turnoff_node)) != 0, and falls through when v0(=ret(md_perf_turnoff_node)) == 0.
  The `bne` branch at 0x42304 targets 0x422e8, is taken when s0(?) < a1(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a1(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x42368 targets 0x42358 and is always taken.
  The `beq` branch at 0x42384 targets 0x422fc and is always taken.
  The return at 0x42360 has v0 = one of 0x0, 0x1, 0x16.

- `md_perf_node_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4238c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x4238c-0x42408 (124 bytes).
  It occupies 124 bytes.
  The `ld` at 0x423d0 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x423d4 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x423e0 loads 8 bytes from ([[-0x3c00]:8]:8 + (a1 << 0x3)) +0x0.
  The `lw` at 0x423e8 loads 4 bytes from [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x4a0c.
  The `sw` at 0x423f4 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x423ac calls md_perf_turnon_node with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x423f8 calls md_perf_enable with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x423a4 targets 0x423f8, is taken when a1 == at(=-0x1), and falls through when a1 != at(=-0x1).
  The `beq` branch at 0x423b4 targets 0x423d0, is taken when v0(=ret(md_perf_turnon_node)) == 0, and falls through when v0(=ret(md_perf_turnon_node)) != 0.
  The `beq` branch at 0x423f0 targets 0x423bc and is always taken.
  The `beq` branch at 0x42400 targets 0x423bc and is always taken.
  The return at 0x423c8 has v0 = one of ret(md_perf_turnon_node), 0x0, ret(md_perf_enable).

- `md_perf_node_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42408 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42408-0x42444 (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0x42418 calls md_perf_turnoff_node with a0=a0 at entry (arg0), a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x42434 calls md_perf_disable with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x42410 targets 0x42434, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x4243c targets 0x42424 and is always taken.
  The return at 0x4242c has v0 = one of ret(md_perf_turnoff_node), ret(md_perf_disable).

- `md_perf_transfer_values` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42444 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42444-0x42504 (192 bytes).
  It occupies 192 bytes.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x42470, `ld` at 0x42490, `ld` at 0x42494.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x4247c, `sd` at 0x424b0, `sd` at 0x424c8.
  The `beq` branch at 0x424dc targets 0x424e8, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0x424e8 targets 0x42484, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x424f4 targets 0x4245c, is taken when t2(?) < 0x6 (signed), and falls through when t2(?) >= 0x6 (signed).
  The return at 0x424fc has v0 = ?.

- `md_perf_get_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42504 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42504-0x425a8 (164 bytes).
  It occupies 164 bytes.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x4253c, `sw` at 0x42590.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x4254c, `ld` at 0x4257c.
  The `ld` at 0x42550 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x4255c loads 8 bytes from ?.
  The `lw` at 0x42588 loads 4 bytes from sym(nasid_to_compact_node) +0xa96c.
  The `jal` at 0x4251c calls bzero with a0=a0 at entry (arg0), a1=0x150, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x42564 calls md_perf_transfer_values with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x42530 targets 0x42540, is taken when at(=[sym(mdp_mode)]:2) == v0(=0x2), and falls through when at(=[sym(mdp_mode)]:2) != v0(=0x2).
  The `beq` branch at 0x42538 targets 0x42594 and is always taken.
  The `blez` branch at 0x42540 targets 0x42580, is taken when a0(=[sym(maxnodes)]) <= 0 (signed), and falls through when a0(=[sym(maxnodes)]) > 0 (signed).
  The `bnel` branch at 0x42578 targets 0x42550, is taken when s0(?) < a2(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a2(=[sym(maxnodes)]) (signed); its branch-likely delay slot `ld a1,-15360(zero)` at 0x4257c runs only when taken and is annulled on fall-through.
  The return at 0x425a0 has v0 = one of -0x1, 0x0.

- `md_perf_get_node_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x425a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x425a8-0x42684 (220 bytes).
  It occupies 220 bytes.
  The `ld` at 0x425f4 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x425f8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x42604 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x42620 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49f2.
  The `lw` at 0x42634 loads 4 bytes from sym(nasid_to_compact_node) +0xa96c.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x42638, `sw` at 0x4266c.
  The `lw` at 0x42664 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4a0c.
  The `jal` at 0x425d4 calls bzero with a0=a1 at entry (arg1), a1=0x150, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x42614 calls md_perf_transfer_values with a0=a1 at entry (arg1), a1=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18960, a2=?, a3=?.
  The `jal` at 0x42674 calls md_perf_get_count with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x425c8 targets 0x42670, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x425e4 targets 0x4265c, is taken when s0(=a0) >= v0(=[sym(maxnodes)]) (signed), and falls through when s0(=a0) < v0(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x425ec targets 0x4265c, is taken when s0(=a0) < 0 (signed), and falls through when s0(=a0) >= 0 (signed).
  The `beq` branch at 0x42630 targets 0x42664, is taken when a1(?) == a2(=0x4), and falls through when a1(?) != a2(=0x4).
  The `beq` branch at 0x4265c targets 0x42644 and is always taken.
  The `beq` branch at 0x42668 targets 0x4263c and is always taken.
  The `beq` branch at 0x4267c targets 0x42640 and is always taken.
  The return at 0x42654 has v0 = one of ?, 0x16.

- `md_perf_get_ctrl` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42684 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42684-0x42700 (124 bytes).
  It occupies 124 bytes.
  The `lh` at 0x426b0 loads 2 bytes from sym(nasid_to_compact_node) +0xa952.
  The `lw` at 0x426c4 loads 4 bytes from sym(nasid_to_compact_node) +0xaac0.
  The `sw` at 0x426c8 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x426cc loads 4 bytes from sym(nasid_to_compact_node) +0xa96c.
  The `sw` at 0x426d0 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x426a4 calls mutex_lock with a0=sym(global_mdp_mon), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x426d4 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x426f0 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `beq` branch at 0x426b8 targets 0x426f0, is taken when (t8(=[sym(global_mdp_mon+2)]:2) & 0x1) == 0, and falls through when (t8(=[sym(global_mdp_mon+2)]:2) & 0x1) != 0.
  The `beq` branch at 0x426f8 targets 0x426e0 and is always taken.
  The return at 0x426e8 has v0 = one of 0x0, 0x16.

- `md_perf_get_node_ctrl` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42700 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42700-0x42800 (256 bytes).
  It occupies 256 bytes.
  The `ld` at 0x42744 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x42748 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x42754 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  2 such `lh` accesses load 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49f2, including `lh` at 0x4276c, `lh` at 0x42788.
  The `lw` at 0x42780 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4b60.
  The `sw` at 0x42784 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0x42798 loads 4 bytes from sym(nasid_to_compact_node) +0xa96c.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x4279c, `sw` at 0x427d8.
  The `lw` at 0x427d0 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4a0c.
  The `jal` at 0x42764 calls mutex_lock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18936, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a0 at entry (arg0), a6=0x16.
  The `jal` at 0x427a0 calls mutex_unlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18936, a1=[sym(global_mdp_mon+28)], a2=?, a3=0x4.
  The `jal` at 0x427e0 calls md_perf_get_ctrl with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a0 at entry (arg0), a6=0x16.
  The `jal` at 0x427f0 calls mutex_unlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18936, a1=?, a2=?, a3=?.
  The `beq` branch at 0x42728 targets 0x427dc, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x42734 targets 0x427c8, is taken when a0 >= v0(=[sym(maxnodes)]) (signed), and falls through when a0 < v0(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x4273c targets 0x427c8, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x42778 targets 0x427f0, is taken when (a1(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18930]:2) & 0x1) == 0, and falls through when (a1(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18930]:2) & 0x1) != 0.
  The `beq` branch at 0x42794 targets 0x427d0, is taken when a2(?) == a3(=0x4), and falls through when a2(?) != a3(=0x4).
  The `beq` branch at 0x427c8 targets 0x427b0 and is always taken.
  The `beq` branch at 0x427d4 targets 0x427a0 and is always taken.
  The `beq` branch at 0x427e8 targets 0x427ac and is always taken.
  The `beq` branch at 0x427f8 targets 0x427ac and is always taken.
  The return at 0x427c0 has v0 = one of ?, 0x16.

- `md_perf_start_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42800 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42800-0x42858 (88 bytes).
  It occupies 88 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0x42814, `lh` at 0x42838.
  The `sd` at 0x42834 stores 8 bytes to ?.
  The `lh` at 0x4283c loads 2 bytes from a0 (arg0 at entry) +0x4.
  The `sd` at 0x42854 stores 8 bytes to ([a0+26]:2 << 0x20) -0x6dfffffffe5f0000.
  The `bne` branch at 0x42830 targets 0x42814, is taken when a2(?) < 0x6 (signed), and falls through when a2(?) >= 0x6 (signed).
  The return at 0x42850 has v0 = ?.

- `md_perf_stop_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42858
  **Inferred.** A 24-byte routine that reads the halfword at `a0+0x1a` (`lh` at 0x42858), stores a 64-bit value (`sd` at 0x4286c) at an address the facts do not resolve, and returns the constant 0x9200000001a10000 in `v0` (0x42868). The stored value is not derived in the facts, so what the store does is an open sub-fact.
  Reviewed: 2026-11-12

- `md_perf_stop_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42858
  **Inferred.** It loads the halfword at a0+0x1a [@0x42858]. It stores a doubleword to an address built from that halfword [@0x4286c]. Its return value is the constant 0x9200000001a10000 [@0x42868].
  Role (from facts): a halfword read [@0x42858] feeding a doubleword store address [@0x4286c], with a fixed return value [@0x42868].
  Reviewed: 2026-11-12

- `md_perf_update_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42870 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42870-0x42944 (212 bytes).
  It occupies 212 bytes.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x4, including `lh` at 0x4287c, `lh` at 0x428ac, `lh` at 0x42918.
  The `sd` at 0x428a8 stores 8 bytes to (a0 + ([a0+4]:2 << 0x3)) +0x140.
  The `lh` at 0x428b4 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x428d8, `ld` at 0x428dc, `ld` at 0x42934.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x428fc, `sd` at 0x42940.
  The `beq` branch at 0x428f8 targets 0x42918, is taken when a7(=0xfffff) == t2(?), and falls through when a7(=0xfffff) != t2(?).
  The `bne` branch at 0x42908 targets 0x428ac, is taken when a2(?) < 0x6 (signed), and falls through when a2(?) >= 0x6 (signed).
  The `beq` branch at 0x4293c targets 0x42900 and is always taken.
  The return at 0x42910 has v0 = ?.

- `md_perf_multiplex` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42944 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/kernel.o`.
  Range: 0x42944-0x42a14 (208 bytes).
  It occupies 208 bytes.
  The `ld` at 0x4294c loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x42950 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x4295c loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x42978 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49f2.
  The `lh` at 0x4298c loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49f0.
  The `lh` at 0x42998 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49f4.
  The `lw` at 0x4299c loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x4b60.
  The `sh` at 0x429f8 stores 2 bytes to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x49f4.
  The `jal` at 0x42968 calls md_perf_stop_count with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18928, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x42970 calls md_perf_update_count with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18928, a1=?, a2=?, a3=?.
  The `jal` at 0x429fc calls md_perf_start_count with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18928, a1=?, a2=?, a3=?, a6=0x1, a7=0x5.
  The `beq` branch at 0x42984 targets 0x42a04, is taken when (t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18930]:2) & 0x1) == 0, and falls through when (t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18930]:2) & 0x1) != 0.
  The `beq` branch at 0x42990 targets 0x429fc, is taken when t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18928]:2) == 0, and falls through when t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18928]:2) != 0.
  The `bne` branch at 0x429c4 targets 0x429f8, is taken when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+19296]) & ra(?)) != 0, and falls through when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+19296]) & ra(?)) == 0.
  The `beq` branch at 0x429cc targets 0x429f8, is taken when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18932]:2) == a0(?), and falls through when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18932]:2) != a0(?).
  The `bne` branch at 0x429e8 targets 0x429f8, is taken when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+19296]) & v0(?)) != 0, and falls through when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+19296]) & v0(?)) == 0.
  The `bne` branch at 0x429f0 targets 0x429a8, is taken when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18932]:2) != a0(?), and falls through when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+18932]:2) == a0(?).
  The return at 0x42a0c has v0 = one of ret(md_perf_update_count), ret(md_perf_start_count).
