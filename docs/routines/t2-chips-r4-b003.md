# Tier-2 reading, batch 3 of chips (round 4): routine role statements

Each entry names a routine in the IP27 boot-set objects and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Grades are inferred, because the rendered facts do not fully settle any of these roles.

- `ktimer_readticks` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x50
  **Inferred.** The 4-byte word at a0+0x2e0 is compared with a1 at 0x70 (the `bne`). When they differ, the routine returns at 0xac the 8-byte value at (a0 + (a1 << 3)) + 0x280. On the other side it goes on to an 8-byte load at 0x78 whose address the facts do not resolve. A retry `bne` at 0x94 goes back to 0x64 while the 8-byte word at a0+0x2d8 differs from t1 (t1 is not resolved). The return at 0xa4 has no constant value in these facts. Role (from name): a tick-count read; the facts do not show what the load at 0x78 reads.
  Reviewed: 2026-11-12

- `ktimer_read` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0xb4
  **Inferred.** The same shape as `ktimer_readticks`: 8-byte loads at +0x2d8 (0xd4, 0xec) and +0x280 (0xd8), a 4-byte word at +0x2e0 compared with a1 at 0xe0 (the `bne` goes to 0x148 when they differ), an 8-byte load at 0xe8 whose address is not resolved, and a retry `bne` at 0x104 back to 0xd4 while the 8-byte word at a0+0x2d8 differs from t8 (not resolved). It stores a 4-byte word at offset +0x0 (the `sw` at 0x138) and an 8-byte word at offset +0x8 (the `sd` at 0x144); the facts do not name the base register of these stores. The return at 0x140 has no constant value. Role (from name): a timer read.
  Reviewed: 2026-11-12

- `ktimer_slptime` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x150
  **Inferred.** Reads the 4-byte state word at a0+0x2e0 (the `lw` at 0x150) and returns 0 at 0x190 when it equals 0, 1 or 2 (the `beq` branches at 0x15c, 0x164 and 0x16c all go to 0x190). Otherwise it loads the 8-byte word at a0+0x2d8 (the `ld` at 0x174) and an 8-byte word at offset 0 of an address the facts do not resolve (the `ld` at 0x178), and returns through 0x188 with no constant value in these facts. Role (from name): a sleep-time query; the branch structure is compatible with that but does not establish it.
  Reviewed: 2026-11-12

- `log_tstamp_event` in `IP27/usr/cpu/sysgen/IP27boot/os.a(tstamp.o)` at 0x2fc
  **Inferred.** Reads the halfword at 0xffffffffffffc420 (the `lh` at 0x304), uses it to index `sym(pdaindr)` in 16-byte steps and loads a pointer at +8 (the `ld` at 0x320). It stores doublewords at +0x300 (0x374), +0x8, +0x28, +0x20, +0x18 and +0x10 (0x378 to 0x388) and a word at +0x0 (0x38c); the facts do not name the base register of these stores. `atomicIncWithWrap` at 0x400 is reached only on the side of the `beq` at 0x3bc where the doubleword at +0x288 of the per-CPU record is nonzero. `getsr` (0x538), `issplprof` (0x540), `splhi` (0x550), `compare_and_dec_int_gt` (0x590), `sv_signal` (0x5a0) and `splx` (0x5a8) sit behind further tests: the `beq` at 0x524, the `bne` at 0x530, the `bne` at 0x548 (taken when `issplprof` returns nonzero) and the tests at 0x55c, 0x568, 0x57c and 0x588; `sv_signal` runs only when `compare_and_dec_int_gt` returns nonzero (the `beq` at 0x598). The return at 0x3b0 is one of an unresolved value, `ret(atomicIncWithWrap)`, `ret(issplprof)` and `ret(splx)`. Role (from name): appends a timestamp event to a per-CPU log; the facts do not show the log layout.
  Reviewed: 2026-11-12

- `log_tstamp_vevent` in `IP27/usr/cpu/sysgen/IP27boot/os.a(tstamp.o)` at 0x5c8
  **Inferred.** Role (from name): the variable-length form of `log_tstamp_event` at 0x2fc. It makes the same `sym(pdaindr)` lookup (the `lh` at 0x5d0 and the `ld` at 0x5ec). It loads 8-byte words at +0x0, +0x8, +0x10 and +0x18 (0x67c to 0x69c) and stores a word at +0x0 and doublewords at +0x10, +0x18, +0x20, +0x8 and +0x28 (0x678 to 0x6ac); the facts do not name the base registers, so a copy from a1 is not shown. The `bne` at 0x6a8 goes to 0x710 when a2 is below 0x28, and the `beq` at 0x710 goes to 0x748 when a2 is zero. On the nonzero side `bcopy` is called at 0x73c, with further `bcopy` calls at 0x8c8, 0x8dc and 0x8f0. It calls `atomicAddWithWrap` at 0x814 where the event routine calls `atomicIncWithWrap`. `getsr` (0x9d8), `issplprof` (0x9e0), `splhi` (0x9f0), `compare_and_dec_int_gt` (0xa30), `sv_signal` (0xa40) and `splx` (0xa48) sit behind the same kind of tests as in the event routine.
  Reviewed: 2026-11-12

- `uuid_create` in `IP27/usr/cpu/sysgen/IP27boot/os.a(uuid.o)` at 0x28
  **Inferred.** Calls `mutex_lock` at 0x44 (a0 = sym(.bss), a1 = 0x19) and `mutex_unlock` at 0x8c or 0xf4. It stores a halfword at +0x8 (0x5c), a word at +0x0 (0x64), and halfwords at +0x4 (0x78) and +0x6 (0x88); the facts do not name the base register. The byte at sym(.sbss) is tested at 0x54: when it is zero the `beq` goes to 0x104, which calls `nanotime` (a2 = the halfword at sym(.sbss)+16, a3 = the doubleword at sym(.sbss)+8). `get_eaddr` at 0xd4 (a0 = sym(.sbss)+2) is reached from the `beq` at 0x84 when the byte at sym(.sbss)+1 is zero, and a nonzero low byte of its result (the `bne` at 0xe0) goes to the `mutex_unlock` at 0x8c. Role (from name): builds a UUID; the stores at +0x0, +0x4, +0x6 and +0x8 resemble time and clock-sequence fields but the facts do not establish that.
  Reviewed: 2026-11-12

- `real_dumpsys` in `IP27/usr/cpu/sysgen/IP27boot/os.a(vmdump.o)` at 0x268
  **Inferred.** Role (from name): the top-level crash-dump routine. After `spl7` at 0x270 it tests dumpdev against -1 at 0x280, tests dump_level for negative at 0x288 and dumpsize for zero at 0x290. The first two branch to 0x484, where the next call is `mdboot` at 0x488, and a zero dumpsize goes to 0x5e0, where the call is `panic` at 0x5e4. It compares MAJOR with bdevcnt at 0x2cc and with bdevmax at 0x2d8. It then calls `enter_dump_mode` at 0x320 (a4 = 1), `bdrv` at 0x358 (a1 = 8, a2 = dumpdev, a3 = 1), `compression_init` at 0x3cc (a2 = 0x8000), `dumpvmcore` at 0x3e4, `exit_dump_mode` at 0x3ec and `mdboot` at 0x404 (a0 = 0, a1 = 0). A loop between 0x498 and 0x4e8 calls `cpu_enabled` at 0x4b8. `panic` is called at 0x5d0, 0x5e4, 0x5fc and 0x614, and `dumperror` at 0x5f4 and 0x60c.
  Reviewed: 2026-11-12

- `xthread_periodic_timeout` in `IP27/usr/cpu/sysgen/IP27boot/os.a(xthread.o)` at 0x72c
  **Inferred.** Role (from name): sets up a periodic timeout. The word at a4 is tested against 0x800 at 0x74c; the `beq` goes to 0x760 when the bit is clear. The code from 0x760 stores at +0x0 (0x764), +0x28 (0x768), +0x30 (0x76c) and +0x38 (0x774), then calls `xthread_table_name_get_property` at 0x778 with a1 = 2; the facts do not name the base register of those stores. After that it stores halfwords at +0x4a (0x78c) and +0x48 (0x798, 0x7b8, 0x80c), tests a word at +0x48 of the per-CPU record from `sym(pdaindr)` against 0x800 (the `beq` at 0x7b0) and a word at +0x6a0 (the `bne` at 0x7f4). `xthread_setup` is called at 0x7cc (a2 = a4, a3 = sym(xpt_init), a5 = sym(pdaindr)) and `xpt_timeout` at 0x7e0 (a0 = a4, followed by a store at +0x40). The return at 0x758 is one of an unresolved value and `ret(xpt_timeout)`. The facts do not settle which test chooses between `xthread_setup` and `xpt_timeout`.
  Reviewed: 2026-11-12

- `pcibr_open` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x570
  **Inferred.** Calls `cap_able_cred` at 0x580 with a0 = a3, a1 = 0x2000000000, a2 = a2 and a3 = a3. The `beq` at 0x588 goes to 0x59c when the result is zero; otherwise the routine falls into the return at 0x594, whose value is one of 0x0 and 0x1 (the facts do not say which side gives which). The routine has no other calls. Role (from name): a capability check on opening a PCI bridge device.
  Reviewed: 2026-11-12

- `pcibr_bridge_ptr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x42ec
  **Inferred.** Role (from name): computes a PIO address for a bridge register window. It calls `xtalk_piotrans_addr` at 0x4304 with a0 = a0, a1 0, a2 0, a3 8 and a4 0. It then compares a word loaded from +0x4 with 0xd102 (the `beq` at 0x4324) and with 0xd112 (the `bne` at 0x4338), and a second word with 0x24 (the `bne` at 0x4350). The return at 0x4368 is either the result of `xtalk_piotrans_addr` or that result plus 0x800000.
  Reviewed: 2026-11-12

- `pcibr_alloc_all_rrbs` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6234
  **Inferred.** Role (from name): allocates read-response buffers for the bridge. It calls `hwgraph_traverse` at 0x627c (a zero result goes to 0x657c, which calls `hwgraph_fastinfo_get`), `xtalk_piotrans_addr` at 0x62a0 (a1 0, a2 0, a3 8, a4 0), `mutex_spinlock` at 0x649c, `pcireg_rrb_set` at 0x64b8, `mutex_io_spinunlock` at 0x654c and `hwgraph_vertex_unref` at 0x6594. The `mutex_spinlock` call is skipped when the `beq` at 0x6494 finds a value zero. Words loaded in the routine are compared with 0xc002 (the `beq` at 0x62e0 and 0x63ac) and 0xd002 (the `beq` at 0x62f8 and 0x63c4), and with 0x36 and 0x24; a run of word stores follows at 0x64ec to 0x6550. The facts do not show a loop over slots.
  Reviewed: 2026-11-12

- `pcibr_error_dump` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x8690
  **Inferred.** Role (from name): the bridge error-interrupt handler. It calls `pcireg_intr_status_get` at 0x86a0, then `test_and_set_long` at 0x86c4 on a0+2112 (0x840) when the status ANDed with -0x100 is nonzero (the `beq` at 0x86b8 goes to 0x86d0 when it is zero). The routine compares values with 0x80000000, 0x10000, 0x100 and 0x800000 (the branches at 0x878c to 0x879c and 0x8820) and an unresolved value with 0x40 (the `beq` at 0x8760). It makes many `pcireg_*` getter calls (for example `pcireg_intr_multiple_get` at 0x889c) and `cmn_err` calls at 0x8718, 0x88e0 and further sites; the facts do not tie each getter to one status bit. The return at 0x86e4 is one of the `test_and_set_long` result, an unresolved value, `ret(pcireg_intr_multiple_get)` and `ret(cmn_err)`.
  Reviewed: 2026-11-12

- `pcireg_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xddec
  **Inferred.** Role (from name): reads a bridge register, for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xddf4) and a selector of -1 (the `beq` at 0xde3c) both branch to the `panic` at 0xdf3c. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xde78 to 0xde98) and with 0xc002 (the next `bne`, which goes to the panic when it differs). The return at 0xde48 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_stat_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdf4c
  **Inferred.** Role (from name): reads a bridge register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xdf54) and a selector of -1 (the `beq` at 0xdf9c) both branch to the `panic` at 0xe0a0. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xdfd8 to 0xdff8) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xe000. The return at 0xdfa8 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_bus_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe0b0
  **Inferred.** Role (from name): reads a bus-error register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xe0b8) and a selector of -1 (the `beq` at 0xe100) both branch to the `panic` at 0xe210. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xe13c to 0xe15c) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xe164. The return at 0xe10c is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_control_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe220
  **Inferred.** Role (from name): reads a control register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xe228) and a selector of -1 (the `beq` at 0xe270) both branch to the `panic` at 0xe378. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xe2b0 to 0xe2d0) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xe2d8. The return at 0xe280 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_control_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe388
  **Inferred.** Role (from name): writes a control register. It calls `splhi` at 0xe39c and `splx` at 0xe400 and returns at 0xe40c the result of `splx`. The null test is the `beq` at 0xe3a8 (it goes to 0xe4fc) and the selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xe3cc to 0xe3e8) and with -1 (the `beq` at 0xe3f0, which goes to the `panic` at 0xe500). A word loaded from +0x4 is compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (0xe43c to 0xe45c) and with 0xc002 (the `bne` at 0xe464, which goes to the panic when it differs). The stores are a `sw` at 0xe474 and `sd` at 0xe490 and 0xe4ac.
  Reviewed: 2026-11-12

- `pcireg_control_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe510
  **Inferred.** Role (from name): clears bits in a control register. It calls `splhi` at 0xe524 and `splx` at 0xe584 and returns at 0xe590 the result of `splx`. It loads a word at 0xe5fc and 0xe610 with a `sw` at 0xe608 between them, and has `ld`/`sd` variants at 0xe624 to 0xe660; which value is written is not shown. The selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xe554 to 0xe570) and with -1 (0xe578); a null a0 (0xe530) and -1 both go to 0xe6a8, and the `panic` is at 0xe6ac. A word loaded from +0x4 is compared with the constants 0xe000 to 0xd002 (0xe5c0 to 0xe5e0) and with 0xc002 (the `bne` at 0xe5e8).
  Reviewed: 2026-11-12

- `pcireg_control_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe6bc
  **Inferred.** Role (from name): sets bits in a control register. It calls `splhi` at 0xe6d0 and `splx` at 0xe730 and returns at 0xe73c the result of `splx`. It loads a word at 0xe7a4 and 0xe7b4 with a `sw` at 0xe7ac between them, and has `ld`/`sd` variants at 0xe7c8 to 0xe7fc; which value is written is not shown. The selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xe700 to 0xe71c) and with -1 (0xe724); a null a0 (0xe6dc) and -1 both go to 0xe844, and the `panic` is at 0xe848. A word loaded from +0x4 is compared with the constants 0xe000 to 0xd002 (0xe76c to 0xe78c) and with 0xc002 (the `bne` at 0xe794).
  Reviewed: 2026-11-12

- `pcireg_ssram_size_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe858
  **Inferred.** Role (from name): sets an SSRAM size field. It calls `splhi` at 0xe86c first and `splx` at 0xe8d4, and returns at 0xe8e0 the result of `splx`. The size check comes later and only on the side of the selector test where the halfword at a0+0x72 is 0 (the `beq` at 0xe8bc goes to 0xe94c): `bltz` on a1 at 0xe94c and the `beq` at 0xe958 (taken when a1 is at least 4) both go to 0xea20, and `assfail` at 0xea28 has a2 = 0x158. The selectors 1, 2 and 3 are compared at 0xe89c to 0xe8b4 and -1 at 0xe8c4; `panic` is called at 0xe9fc and 0xea10. A word loaded from +0x4 is compared with 0xe000 to 0xd002 (0xe910 to 0xe934) and with 0xc002 (the `bne` at 0xe93c). The `sw` stores are at 0xe96c and 0xe97c.
  Reviewed: 2026-11-12

- `pcireg_speed_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xea48
  **Inferred.** Role (from name): reads a bus-speed field (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xea50) and a selector of -1 (the `beq` at 0xea98) both branch to the `panic` at 0xebb0. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xead8 to 0xeaf8) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xeb00. The return at 0xeaa8 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_mode_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xebc0
  **Inferred.** Role (from name): reads a bus-mode field (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xebc8) and a selector of -1 (the `beq` at 0xec10) both branch to the `panic` at 0xed1c. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xec4c to 0xec6c) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xec74. The return at 0xec1c is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_req_timeout_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xed2c
  **Inferred.** Role (from name): reads a request-timeout field (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xed34) and a selector of -1 (the `beq` at 0xed7c) both branch to the `panic` at 0xee80. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xedb8 to 0xedd8) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xede0. The return at 0xed88 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_req_timeout_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xee90
  **Inferred.** Role (from name): writes a request-timeout field. The null test is the `beq` at 0xee98 (it goes to 0xefd8). The selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xeebc to 0xeed8) and with -1 (the `beq` at 0xeee0, which goes to the `panic` at 0xefdc with a1 passed as its argument). A word loaded from +0x4 is compared with 0xe000 to 0xd002 (0xef1c to 0xef3c) and with 0xc002 (the `bne` at 0xef44). The stores are a `sw` at 0xef58 and `sd` at 0xef74 and 0xef90; the facts do not show the stored value. The return at 0xeeec is one of an unresolved value and `ret(panic)`.
  Reviewed: 2026-11-12

- `pcireg_intr_dst_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xefec
  **Inferred.** Role (from name): reads an interrupt-destination register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xeff4) and a selector of -1 (the `beq` at 0xf03c) both branch to the `panic` at 0xf150. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xf07c to 0xf09c) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xf0a4. The return at 0xf04c is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12
