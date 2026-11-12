# Tier-2 reading, round 3, batch 0 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: loads and stores, calls, constants and branch shapes. Every role here is inferred. Where the facts leave the meaning open, the entry says so.

- `spinunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xf80
  **Inferred.** Role (from name): a debug variant of a spin lock release. It compares a halfword at `a1+0x2a` with a halfword global at `-0x3be0`. A mismatch at 0xfb0 leads to `cmn_err` at 0x1074 (level 4), and a mismatch at 0xfcc leads to `cmn_err` at 0x108c (level 4). A third `cmn_err` at 0x10a4 has level 0 and an argument of -1; the facts do not show what reaches it. The routine also stores halfwords, words and doublewords at offsets such as `+0x2a`, `+0x40`, `+0x58`, `+0x60`, `+0x64`, `+0x68`, `+0x78` and `+0x80`; the stored values and the field meanings are not shown by these facts.
  Reviewed: 2026-11-12

- `i2c_probe` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x88
  **Inferred.** A polling loop: a backward branch at 0x12c repeats while an unsigned count is below a bound, and the branch at 0xf0 leaves it when the count reaches the bound. It loads doublewords at 0x8c, 0xb8, 0xbc, 0xf8 and 0x108, two of them at the constant offset -0x6dfffffffe5e0000; the base registers are not shown. It returns 0 at 0x138 and 1 at 0x140, so it is a yes/no probe. The loop bound, the compared values and the register meanings are not shown by the facts.
  Reviewed: 2026-11-12

- `i2c_arb` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x148
  **Inferred.** Role (from name): an arbitration routine for a shared bus. It first calls `node_can_talk_to_elsc` at 0x194 and branches to 0x334 when that call yields zero. It then loops on loaded doubleword values, testing bit 0 of values loaded at constant offset -0x6dfffffffe5dfff8 and comparing a value loaded at 0x1c4, 0x21c and 0x2dc with the constants 0xe0 and 0xe8 at 0x1cc, 0x1d4, 0x224 and 0x22c. The return at 0x350 yields one of -0xb or an unknown value, so the meaning of the return value is open.
  Reviewed: 2026-11-12

- `ftrc_event` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xf630
  **Inferred.** Role (from name): a trace event recorder. If the global `ftrc_initialized` is zero it branches at 0xf660 to a call to `ftrc_init` at 0xf764 with its own arguments. Otherwise, when `a0`, `a2` and `[a0+16]` are all nonzero, it calls `mutex_spinlock` at 0xf684 on `[a0+16]+64`, stores into a buffer found through `[a0+16]+48` with an unsigned comparison at 0xf6b8, and calls `mutex_spinunlock` at 0xf6d8. It returns -1 or 0.
  Reviewed: 2026-11-12

- `numalinkstats_up2date` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f7c
  **Inferred.** When the global `numnodes` is zero or less, the branch at 0x1f90 goes to 0x2004, which skips the loop. Otherwise it loops, doubleword loads whose addresses these facts do not show feed zero tests at 0x1fbc and 0x1fc8 and an unsigned comparison at 0x1fd8, and the loop repeats at 0x1ffc while a counter is below `numnodes`. The routine name suggests a freshness check on per-node statistics, but the return value is unknown in these facts.
  Reviewed: 2026-11-12

- `capture_router_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cb0
  **Inferred.** Role (from name): a router statistics sampler. It calls `router_acquire_info` at 0x2cc0 and reads the byte flag at `a0+0x191`. A zero there goes to 0x2d64, which continues at 0x2cdc only if `router_acquire_info` returned nonzero. At 0x2cdc it stores the byte at `a0+0x191`, and it calls `router_check_errors` at 0x2cec only when the byte flag at `a0+0x190` is nonzero. It stores bytes at `a0+0x190` (0x2d00, 0x2d30) and a doubleword at `a0+0x188` (0x2d08), and compares against the global `router_print_usecs` at 0x2d28. The return value is the value of the global `router_poll_ticks` or is unknown.
  Reviewed: 2026-11-12

- `hub_widget_id` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44cc
  **Inferred.** It loads one doubleword at 0x44d8 at the constant offset -0x6dfffffffe3fffe0 from a base register that the facts do not show, then returns at 0x44dc. The return value `v0` is not shown in the facts, so whether it is the loaded value, and how a caller uses it as a widget id, are open.
  Reviewed: 2026-11-12

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510
  **Inferred.** It loads one doubleword at 0x4514 and returns at 0x451c. The facts show neither the address loaded nor any comparison, and the return value is unknown. Role (from name): a test of a directory mode, which the facts do not confirm.
  Reviewed: 2026-11-12

- `update_ust` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xa520
  **Inferred.** It loads the doubleword at 0x9200000001030100 at 0xa538 and returns that value at 0xa53c. It also stores a doubleword at offset +0x0 at 0xa540; the facts do not show the destination or the stored value. The name suggests a timestamp update, which the facts do not confirm.
  Reviewed: 2026-11-12

- `xswitch_vertex_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xaf44
  **Inferred.** It allocates a 0x20-byte zeroed block with `kmem_zalloc` at 0xaf58, initializes a mutex in it with `init_mutex` at 0xaf74, and attaches the block to its argument with `hwgraph_info_add_LBL` at 0xaf84, using the label at `.rodata+4400`. It returns the result of that last call.
  Reviewed: 2026-11-12

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8
  **Inferred.** It blocks interrupts with `splhi` at 0xe004, finds the node with `get_nasid` at 0xe00c, and looks up the CPU record for the slice held at the fixed address 0x9200000001000020 with `nasid_slice_to_cpuinfo` at 0xe020. It restores the level with `splx` at 0xe02c and returns the 16-bit field at `+0x1e` of that record at 0xe048. A zero record reaches `assfail` at 0xe05c with line 0x535.
  Reviewed: 2026-11-12

- `hub_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe668
  **Inferred.** It resolves a widget through `xwidget_info_get`, `xwidget_info_id_get`, `xwidget_info_master_get` and `hwgraph_info_get_LBL` at 0xe674 to 0xe6a8. It then tests a mask from the table word at 0x9200000001c00118 and returns 0 or 1 at 0xe6f8. The error path reports with `cmn_err` at 0xe71c, level 6. The mask bit it tests is not identified.
  Reviewed: 2026-11-12

- `hub_widgetdev_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe72c
  **Inferred.** Role (from name): shutting down a widget device. It resolves the widget the same way as `hub_dma_enabled` (four calls at 0xe73c to 0xe76c), then stores a doubleword at offset +0x0 at 0xe7dc; the facts show neither the address nor the value. A loop tests an index against 0xf at 0xe7f4, tests `free_error_crbs` at 0xe804, and calls `hubiio_crb_free` at 0xe850; the arguments are not shown. It tests `free_error_crbs_print` at 0xe85c and 0xe870, and reports through `cmn_err` at 0xe8cc and 0xe8e8, level 6. What the loop frees is not settled by these facts.
  Reviewed: 2026-11-12

- `hub_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe9a4
  **Inferred.** It resolves the widget through the same four calls (0xe9b4 to 0xe9e4). It compares a value with 5 at 0xe9fc and 6 at 0xea04, and returns 0 at 0xea10. It loads the table word at 0x9200000001c002c8 at 0xea34, tests bit 56 of it at 0xea3c, and stores a doubleword at offset +0x0 at 0xea64; the destination address and the stored value are not shown by these facts. The name suggests enabling error reporting for a device, which the facts do not confirm.
  Reviewed: 2026-11-12

- `hub_ioerror_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xead0
  **Inferred.** Role (from name): an I/O error handler. It loads the address `[a3+48]` and compares it, as unsigned ranges, with the constants 0x92000000e0000000, 0x920000000a000000, 0x9200000020000000 and 0x9200000100000000 to choose a path. The paths call `is_widget_pio_enabled` at 0xec1c and 0xecdc, `hub_xp_error_handler` at 0xec38, 0xecf8 and 0xed24, `hub_ioerror_local` at 0xee08 and 0xee44, and `ioerror_dump` at 0xeea8 and 0xeec4; other calls include `error_state_get`, `printf`, `xtalk_pio_target_get` and `xtalk_pio_xtalk_addr_get`. The per-path meanings are only partly settled.
  Reviewed: 2026-11-12

- `crbx` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xeed4
  **Inferred.** It makes six `sprintf` calls (0xef98, 0xefe4, 0xf37c, 0xf53c, 0xf56c, 0xf5b8) and twelve calls whose callee the facts do not resolve (0xef18 to 0xef60, 0xf070, 0xf0c8, 0xf110, 0xf190), and it loads halfword and word values at offsets such as `+0x2cd4` at 0xf21c from a base the facts do not show. The field layout and the tables are not identified by these facts, so the role stays at building formatted strings.
  Reviewed: 2026-11-12

- `hub_init_ifdr_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfc50
  **Inferred.** It indexes the node table `compact_to_nasid_node` with `a0`, stores halfwords at `+0x4c82` and `+0x4c84` and a word at `+0x4c7c`, and compares a halfword loaded at 0xfccc with a value at 0xfcd8. A branch at 0xfcd8 can return at 0xfd0c; a doubleword store at constant offset -0x6dfffffffe3ffc68 occurs at 0xfd08. It reports through `cmn_err` at 0xfd1c with level 5 and the node's fields. The conditions that select the store and the report are not settled by these facts. The name suggests a workaround setup, but the workaround itself is not visible in these facts.
  Reviewed: 2026-11-12

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** It tests the global `hubio_ifdr_skip` at 0xfd50; nonzero ends at the return of 0 at 0xfd58. Otherwise it loads values and compares a halfword at offset 19588 of a loaded pointer with another value at 0xfda4, returning 1 at 0xfdac or 0 at 0xfdb4. It is a yes/no check, and what exactly is compared is not identified by these facts.
  Reviewed: 2026-11-12

- `hub_dmatimeout_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xffc4
  **Inferred.** Role (from name): a recovery routine for a stalled DMA. When `a1` is nonzero it calls `mutex_spinlock` on `global_kick_lock` at 0x10000; when `a1` is zero it calls `mutex_spintrylock` at 0x1036c and continues only on a nonzero result. It runs `cpuaction` with `kick_action` at 0x100ec, calls `bte_wait_for_xfer_completion` at 0x10114, `splerr` at 0x101b8, `us_delay` with 5 at 0x1026c, `hub_merge_clean` at 0x10274, `us_delay` with 2 at 0x1027c, `hub_ifdr_fix_value` at 0x10298 and `us_delay` with 2 at 0x10310. It then calls `splx` and `mutex_spinunlock` on `global_kick_lock` (0x10320, 0x1032c) and later `cmn_err` calls at 0x10460 to 0x104c0. The order of recovery steps is taken from the call sequence only.
  Reviewed: 2026-11-12

- `hub_widget_reset` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x104e0
  **Inferred.** It finds the master node with `master_node_get` at 0x104ec, raises the interrupt level with `splhi` at 0x10528, and calls `hub_setup_prb` at 0x105e8 with the constants 3 and 2. It restores the level with `splx` at 0x105f0. The `assfail` calls at 0x1065c and 0x10678 use line 0x562. The meaning of the PRB setup arguments is not identified.
  Reviewed: 2026-11-12

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28
  **Inferred.** It loads the doubleword at the fixed address 0x9200000001000028 at 0x11f30 and returns 0 or 1 at 0x11f60. It looks like a yes/no test on that word. The alias condition the name refers to is not visible in the facts.
  Reviewed: 2026-11-12

- `bte_avail` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12f9c
  **Inferred.** A routine with no loads, stores or calls in the rendered facts. It returns a value in `v0` at 0x12fa0 that the facts do not show. The name suggests a query for whether the block transfer engine is usable, but nothing here confirms that.
  Reviewed: 2026-11-12

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Inferred.** Role (from name): zeroing a block through the block transfer engine. It ORs 0xa800000000000000 into the address before the `bzero` calls at 0x133b8 and 0x134c8. It tests `disable_bte_pbzero` and `disable_bte`, calls `get_hub_chiprev` at 0x13410 (its result use is not shown), and calls `bte_copy` at 0x13448 with `a0` 0 and a mode of 0x10 on at least one path. It returns 0 or the `bte_copy` result at 0x133f0. The meaning of the revision call and the full set of modes are not identified.
  Reviewed: 2026-11-12

- `bte_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13a5c
  **Inferred.** Role (from name): the block transfer engine copy. It tests the global `disable_bte` at 0x13aa0, calls `splhi` at 0x13b00, tests a bit lock with `bitlock_islocked` at 0x13b9c and takes a lock with `nested_spintrylock` at 0x13bc0. Later calls include `nested_spinunlock`, `splx`, `bte_error_handler`, `poison_state_clear`, `bte_notification_war` and `cmn_err`. It reads the fixed address 0x9200000001030100. The transfer programming is too long to settle from these facts.
  Reviewed: 2026-11-12

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** When `a2` is nonzero it calls `bte_copy` at 0x14708 with its own first three arguments and the constant 0x110 as the fourth; a zero `a2` branches at 0x14700 to 0x1471c. A nonzero `bte_copy` result branches at 0x14710 to 0x1472c, and `cmn_err` at 0x14738 (level 0xc) takes that result as an argument. It returns 0 or the `bte_copy` result at 0x14724. The meaning of the 0x110 mode value is not identified.
  Reviewed: 2026-11-12
