# Tier-2 reading, round 3, batch 0 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: loads and stores, calls, constants and branch shapes. Every role here is inferred. Where the facts leave the meaning open, the entry says so.

- `spinunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xf80
  **Inferred.** It looks like a debug release of a spin lock. It compares a halfword at `a1+0x2a` with a halfword global at `-0x3be0`, and on a mismatch it reports through `cmn_err` at 0x1074 (level 4) and 0x108c, and at 0x10a4 with level 0 when the wait loop gives up. The stores at `a1+0x40`, `+0x58`, `+0x78` and `+0x80` and at `a0+0` look like clearing the owner fields on release; the field names are not settled by these facts.

- `i2c_probe` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x88
  **Inferred.** A bounded polling loop over an address computed from `a0`, with doubleword loads from the fixed address 0x9200000001030100 at 0x8c, 0xbc and 0x108. It returns 0 at 0x138 and 1 at 0x140, so it is a yes/no probe. The loop bound and the register meanings are not shown by the facts.

- `i2c_arb` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x148
  **Inferred.** An arbitration routine for a bus that is shared with another node. It first calls `node_can_talk_to_elsc` at 0x194 and returns early when that call yields zero, then compares `a0` with the constants 0xe0 and 0xe8 at 0x1cc, 0x1d4, 0x224 and 0x22c to pick between two register offsets. Its failure return at 0x350 is one of -0xb or an unknown value, so the error meaning is open.

- `ftrc_event` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xf630
  **Inferred.** A trace event recorder. If the global `ftrc_initialized` is zero it tail-calls `ftrc_init` at 0xf764. Otherwise it takes `mutex_spinlock` at 0xf684 on a lock at `[a0+16]+64`, writes a record into a buffer found through `[a0+16]+48` with a bounds check at 0xf6b8, and releases the lock with `mutex_spinunlock` at 0xf6d8. It returns -1 or 0.

- `numalinkstats_up2date` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f7c
  **Inferred.** It returns early at 0x2004 when the global `numnodes` is zero or less. Otherwise it walks the nodes, reading the hub-local window at abs 0xffffffffffffc400 and a pointer at `-0x3c00`, and compares a counter with `numnodes` at 0x1ffc. The routine name suggests a freshness check on per-node statistics, but the return value is unknown in these facts.

- `capture_router_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cb0
  **Inferred.** A periodic sampler for a router. It calls `router_acquire_info` at 0x2cc0 and, when the flag at `a0+0x191` is set, `router_check_errors` at 0x2cec. It then reads and writes byte flags at `a0+0x190` and `a0+0x191`, stores a doubleword at `a0+0x188`, and compares against the global `router_print_usecs` at 0x2d28. The return value comes from `router_poll_ticks` or is unknown.

- `hub_widget_id` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44cc
  **Inferred.** It loads one doubleword from a widget register address computed from `a0` at 0x44d8 and returns it. The facts do not show how the caller uses the value, so the id interpretation is open.

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510
  **Inferred.** It loads the doubleword at the fixed address 0x9200000001600000 at 0x4514 and returns. The name suggests a directory-mode test, but the facts show no comparison, so the return is unknown.

- `update_ust` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xa520
  **Inferred.** It loads the doubleword at 0x9200000001030100 at 0xa538, stores it into the global `ust_val` at 0xa540, and returns the same value. The name suggests a timestamp update, which the facts do not confirm.

- `xswitch_vertex_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xaf44
  **Inferred.** It allocates a 0x20-byte zeroed block with `kmem_zalloc` at 0xaf58, initializes a mutex in it with `init_mutex` at 0xaf74, and attaches the block to its argument with `hwgraph_info_add_LBL` at 0xaf84, using the label at `.rodata+4400`. It returns the result of that last call.

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8
  **Inferred.** It blocks interrupts with `splhi` at 0xe004, finds the node with `get_nasid` at 0xe00c, and looks up the CPU record for the slice held at the fixed address 0x9200000001000020 with `nasid_slice_to_cpuinfo` at 0xe020. It restores the level with `splx` at 0xe02c and returns the 16-bit field at `+0x1e` of that record at 0xe048. A zero record reaches `assfail` at 0xe05c with line 0x535.

- `hub_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe668
  **Inferred.** It resolves a widget through `xwidget_info_get`, `xwidget_info_id_get`, `xwidget_info_master_get` and `hwgraph_info_get_LBL` at 0xe674 to 0xe6a8. It then tests a mask from the table word at 0x9200000001c00118 and returns 0 or 1 at 0xe6f8. The error path reports with `cmn_err` at 0xe71c, level 6. The mask bit it tests is not identified.

- `hub_widgetdev_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe72c
  **Inferred.** It resolves the widget the same way as `hub_dma_enabled`, then clears the table word at 0x9200000001c00120 (store at 0xe7dc). It walks up to 16 entries, bounded by the comparison at 0xe7f4, and calls `hubiio_crb_free` at 0xe850 on the error entries listed in `free_error_crbs`. It reports through `cmn_err` at 0xe8cc and 0xe8e8, level 6. The teardown reading is inferred from the call set and the stores.

- `hub_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe9a4
  **Inferred.** It resolves the widget through the same four calls, loads the table word at 0x9200000001c002c8 at 0xea34, and stores it to the table word at 0x9200000001c00388 at 0xea64. It then returns 0 at 0xea10. The name suggests enabling error reporting for a device, but the facts show only a copy between two table slots.

- `hub_ioerror_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xead0
  **Inferred.** An I/O error dispatcher. It takes the faulting address from `[a3+48]` and compares it with the constants 0x92000000e0000000, 0x920000000a000000, 0x9200000020000000 and 0x9200000100000000 to choose a path. The paths call `is_widget_pio_enabled` at 0xec1c and 0xecdc, `hub_xp_error_handler` at 0xec38, 0xecf8 and 0xed24, `hub_ioerror_local` at 0xee08 and 0xee44, and `ioerror_dump` at 0xeea8 and 0xeec4. The per-path meanings are only partly settled.

- `crbx` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xeed4
  **Inferred.** A large formatter for error register records. It calls `sprintf` six times and makes twelve calls through computed targets, and it reads many halfword and word fields from `.rodata` tables such as `.rodata+0x2cd4` at 0xf21c. The field layout and the tables are not identified by these facts, so the role stays at the level of formatting error state.

- `hub_init_ifdr_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfc50
  **Inferred.** It indexes the node table `compact_to_nasid_node` with `a0` at 0xfc70 and writes a doubleword at the computed hub address at 0xfd08. It reports through `cmn_err` at 0xfd1c with level 5 and the node's fields. The name suggests a workaround setup, but the workaround itself is not visible in these facts.

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** It loads the hub-local doubleword at abs 0xffffffffffffc400 at 0xfd60 and returns 0 or 1 at 0xfd58, 0xfdac and 0xfdb4. It is a yes/no check on a hub register value. The condition that selects 1 is not identified.

- `hub_dmatimeout_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xffc4
  **Inferred.** A recovery routine for a stalled DMA. It takes `global_kick_lock` with `mutex_spinlock` at 0x10000, runs `cpuaction` with `kick_action` at 0x100ec, and waits for a transfer with `bte_wait_for_xfer_completion` at 0x10114. It then delays with `us_delay` at 0x1026c, 0x1027c and 0x10310, calls `hub_merge_clean` at 0x10274, and calls `hub_ifdr_fix_value` at 0x10298. The order of recovery steps is taken from the call sequence only.

- `hub_widget_reset` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x104e0
  **Inferred.** It finds the master node with `master_node_get` at 0x104ec, raises the interrupt level with `splhi` at 0x10528, and calls `hub_setup_prb` at 0x105e8 with the constants 3 and 2. It restores the level with `splx` at 0x105f0. The `assfail` calls at 0x1065c and 0x10678 use line 0x562. The meaning of the PRB setup arguments is not identified.

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28
  **Inferred.** It loads the doubleword at the fixed address 0x9200000001000028 at 0x11f30 and returns 0 or 1 at 0x11f60. It is a yes/no test on a boot-time register value. The alias condition the name refers to is not visible in the facts.

- `bte_avail` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12f9c
  **Inferred.** A 12-byte routine with no loads, stores or calls in the rendered facts. It returns a value in `v0` at 0x12fa0 that the facts do not show. The name suggests a query for whether the block transfer engine is usable, but nothing here confirms that.

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Inferred.** It zeroes a block through the uncached alias, OR-ing in 0xa800000000000000 before the `bzero` calls at 0x133b8 and 0x134c8. It checks the hub revision with `get_hub_chiprev` at 0x13410 and, on one branch, copies through `bte_copy` at 0x13448 with a mode of 0x10 or 0x11. It returns 0 or the `bte_copy` result at 0x133f0. The meaning of the revision test is not identified.

- `bte_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13a5c
  **Inferred.** The block transfer engine copy. It loads the global `disable_bte` and passes it to the `splhi` call at 0x13b00, then tests a bit lock with `bitlock_islocked` at 0x13b9c and takes a lock with `nested_spintrylock` at 0x13bc0. The facts do not show where `disable_bte` is tested. It reads the hub-local windows at abs 0xffffffffffffc400 and 0xffffffffffffc420 and the fixed address 0x9200000001030100. The transfer programming is too long to settle from these facts.

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** It calls `bte_copy` at 0x14708 with its own three arguments and the constant 0x110 as the fourth. It returns 0 or the `bte_copy` result at 0x14724. On the other path it reports through `cmn_err` at 0x14738 with level 0xc. The meaning of the 0x110 mode value is not identified.
