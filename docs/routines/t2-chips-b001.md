# Tier-2 routine roles, chips batch 1

Role statements for batch 1 of the tier-2 reading round, targets 26 to 50 of the ranked list. Each statement comes only from the rendered facts for that routine: registers, calls, constants and branch structure in the named binary. Routine names and the purposes they suggest come from symbol names, and each entry says where the reading is a guess.

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510
  **Inferred.** The routine is 20 bytes with one 8-byte load from the fixed address 0x9200000001600000 at 0x4514 and a return with v0 at 0x451c. The facts show no call and no branch, so the value read is returned in some form. The name suggests a directory-mode predicate, but which bit or field of the word is tested is not shown.
  Reviewed: 2026-11-12 (sonnet)

- `ni_reset_port` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x45e0
  **Inferred.** The routine stores one 8-byte word to 0x9200000001600008 at 0x45ec and returns that same address in v0 at 0x45e8. It is a 16-byte leaf with no calls. The name suggests a port reset, but the stored value is not in the facts, so whether it asserts or clears a reset is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `update_ust` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xa520
  **Inferred.** The routine loads an 8-byte value from the fixed address 0x9200000001030100 at 0xa538, stores 8 bytes with sd at 0xa540 and returns the loaded value in v0 at 0xa53c. The facts show no branch or call. The facts do not name or place the store destination, so that it is a kernel variable is not established. The name suggests a time update, but the meaning of the source word is not shown.
  Reviewed: 2026-11-12 (sonnet)

- `xswitch_vertex_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xaf44
  **Inferred.** The routine allocates a 0x20-byte zeroed block with kmem_zalloc at 0xaf58, initialises a mutex inside it with init_mutex at 0xaf74, and registers the block under a label with hwgraph_info_add_LBL at 0xaf84, returning that call's result at 0xaf94. The label string is at .rodata+4400. The name suggests a switch vertex, but the layout of the block is not shown.
  Reviewed: 2026-11-12 (sonnet)

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8
  **Inferred.** The routine masks interrupts with splhi at 0xe004, gets a NASID with get_nasid at 0xe00c, and looks up its CPU record with nasid_slice_to_cpuinfo at 0xe020, using a slice value loaded from 0x9200000001000020 at 0xe018. It returns the halfword at record offset 0x1e (0xe040 to 0xe048) and restores interrupts with splx at 0xe02c. A null record reaches assfail with line constant 0x535 at 0xe05c. The returned field is most likely a CPU id, judging from the name, but the field's meaning is not in the facts.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe668
  **Inferred.** The routine finds a widget's info through xwidget_info_get (0xe674), xwidget_info_id_get (0xe680) and xwidget_info_master_get (0xe68c), then looks up a name with hwgraph_info_get_LBL at 0xe6a8. It masks a word loaded from table address 0x9200000001c00118 (0xe6d8) with a register value at 0xe6ec, and returns 0 or 1 at 0xe6f8. The 0 or 1 result probably reports whether a DMA enable bit is set, but the bit tested and the mask value are not shown. cmn_err at 0xe71c (level 6) is called on the path taken when the masked word is zero.
  Reviewed: 2026-11-12 (sonnet)

- `hub_widgetdev_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe72c
  **Inferred.** The routine looks up the widget and its master through xwidget_info_get (0xe73c), xwidget_info_id_get (0xe74c) and xwidget_info_master_get (0xe758), then calls hwgraph_info_get_LBL at 0xe76c. It calls hubiio_crb_free at 0xe850 only on a path guarded by several branches (for example 0xe840 and 0xe848 compare registers that the facts do not resolve); the name suggests this releases a CRB. It loads from a table-relative address at 0xe7cc and stores at 0xe7dc, and the facts do not show that both use the same address. It tests the sign of a word loaded from 0x9200000001c00400 at 0xe808 after shifts. A register is compared with 0xf at 0xe7f4, which may be a bounded loop over slots. Two cmn_err calls at level 6 (0xe8cc and 0xe8e8) are present; what they report is not shown, and neither is the value stored.
  Reviewed: 2026-11-12 (sonnet)

- `hub_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe9a4
  **Inferred.** The routine looks up a widget and its master through xwidget_info_get (0xe9b4), xwidget_info_id_get (0xe9c0) and xwidget_info_master_get (0xe9cc), and gets a name with hwgraph_info_get_LBL at 0xe9e4. It compares its third argument with 5 and 6 at 0xe9fc and 0xea04, and returns 0 at 0xea10 when it is neither. It reads the table word at 0x9200000001c002c8 (0xea34) and tests its sign after a shift by 7 at 0xea3c. It also stores a doubleword at 0xea64; the facts do not give that store address. The meaning of the source word and of the stored value is not shown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_ioerror_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xead0
  **Inferred.** The routine appears to work on a structure passed in its fourth argument a3, with loads at offsets 0x30, 0x10 and 0x6 and stores at 0x18 and 0x6 (some other loads and stores at +0x0 have bases the facts do not resolve). The routine is 1028 bytes. It calls is_widget_pio_enabled at 0xec1c and 0xecdc; the name suggests a PIO-state check. It calls hub_xp_error_handler at 0xec38, 0xecf8 and 0xed24, passing its own arguments on, and calls hub_ioerror_local, error_state_get, xtalk_pio_target_get, xtalk_pio_xtalk_addr_get, printf and ioerror_dump on other paths. It reads the table word at 0x9200000001c00160 (0xec8c) and calls hwgraph_info_get_LBL at 0xeb00. The name suggests an I/O error handler, which fits these calls, but the structure's field layout is not established.
  Reviewed: 2026-11-12 (sonnet)

- `crbx` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xeed4
  **Inferred.** The routine is 3312 bytes and makes 12 indirect calls through jalr from 0xef18 onward, and six calls to sprintf. All twelve pass the same .rodata string at +5944 as the first argument. The dispatch targets are not in the facts, so the routine's purpose is not derived here. The name suggests CRB register access, and that is only a guess from the name.
  Reviewed: 2026-11-12 (sonnet)

- `hub_init_ifdr_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfc50
  **Inferred.** The routine indexes a pointer table at -0x3c00 by the node number scaled by 8 and writes a halfword at record offset 0x4c82 (0xfc74), a halfword at 0x4c84 (0xfc8c) and a word at 0x4c7c (0xfca4). It compares a value with a second value at 0xfcd8 and reports through cmn_err at level 5 at 0xfd1c. The name suggests a workaround initialisation, but the meaning of the stored values is not shown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** The routine tests the global hubio_ifdr_skip at 0xfd50 and returns 0 at once (0xfd58) when that flag is nonzero. Otherwise it reads a halfword from the node record at offset 0x4c84 (0xfd94) and compares it unsigned with a value at 0xfda4. It returns 1 at 0xfdac when the comparison falls short and 0 at 0xfdb4 otherwise. The name suggests a check of an IFDR value, which matches this compare, but the threshold it uses is not shown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_ifdr_fix_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfdbc
  **Inferred.** The routine reads halfwords at record offsets 0x4c82 and 0x4c84 (0xfe0c, 0xfe80), compares a value with 0x41 at 0xfde8, and runs bit-mask tests with 0x7f at 0xfe3c and 0xfe4c. It writes the halfword at 0x4c82 at 0xfe20 and a doubleword at 0xfe9c. It returns -1 or 1 at 0xfea0. The name suggests a repair of an IFDR value, but the failure condition and the meaning of the masks are not settled by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dmatimeout_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xffc4
  **Inferred.** The routine branches on its second argument a1 at 0xfff8. When a1 is nonzero it takes global_kick_lock with mutex_spinlock at 0x10000. When a1 is zero it calls mutex_spintrylock on the same lock at 0x1036c and continues at 0x1000c only if that call returns nonzero. It asks a CPU to run kick_action through cpuaction at 0x100ec, in a loop bounded by maxcpus (0x10108), and calls bte_wait_for_xfer_completion at 0x10114. On a later path it calls us_delay with 5 at 0x1026c, hub_merge_clean at 0x10274, us_delay with 2 at 0x1027c and hub_ifdr_fix_value at 0x10298, then us_delay with 2 again at 0x10310, splx at 0x10320 and mutex_spinunlock at 0x1032c. The name says DMA timeout, which fits this kick-and-retry sequence, but the trigger condition is not established.
  Reviewed: 2026-11-12 (sonnet)

- `hub_widget_reset` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x104e0
  **Inferred.** The routine gets the master node with master_node_get at 0x104ec and masks interrupts with splhi at 0x10528. It calls hub_setup_prb at 0x105e8 with constants 0x3 and 0x2 as its third and fourth arguments, restores interrupts with splx at 0x105f0, and calls assfail with line 0x562 at 0x1065c and 0x10678 on its failure paths. It stores doublewords at 0x105bc and 0x105c0 and at 0x10638 and 0x1063c, reloads from the same displacement at 0x105c4 and 0x10640, and tests bit 0x10 of a loaded word at 0x105cc and 0x10648. The name suggests a widget reset, but the facts do not show what the stored values or addresses are, so the reset sequence is not derived.
  Reviewed: 2026-11-12 (sonnet)

- `restart` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x10694
  **Inferred.** The routine waits with us_delay for 0xf4240 (1000000) at 0x10720. At 0x10734 it skips ahead to get_nasid (0x1079c) when reboot_on_panic equals 2. Otherwise, when power_off_flag is nonzero it calls sysctlr_power_off at 0x1074c and then us_delay for 0x2dc6c0 (3000000) at 0x10754, looping back to the flag test under conditions the facts only partly resolve; when power_off_flag is zero it calls ni_reset_port at 0x10784. It then gets a NASID at 0x1079c and initialises the ELSC controller with elsc_init at 0x107a8 before elsc_system_reset at 0x107b0. When that call returns a negative value it prints a message with printf at 0x107cc and calls us_delay for 1000000 at 0x107d4. The delay units are taken as microseconds from the us_delay name, and the flag-based choice is an inference.
  Reviewed: 2026-11-12 (sonnet)

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28
  **Inferred.** The routine reads the word at 0x9200000001000028 (0x11f30), branches on whether it is zero at 0x11f40, and compares v1 with a1 unsigned at 0x11f54. It returns 0 or 1 at 0x11f60. The name suggests an alias test between two addresses, which the range-style compare fits, but the rule that decides an alias is not established by these facts.
  Reviewed: 2026-11-12 (sonnet)

- `bte_init_buffers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12ec4
  **Inferred.** The routine loops over the node count in the symbol maxnodes (0x12ee0 and 0x12f54). Inside it an inner loop, whose index is compared with 2 at 0x12f24, allocates a 0x4000-byte block per iteration with kmem_zalloc_node using flags 0x901 at 0x12efc. It initialises a lock with spinlock_init at 0x12f38 and reports a null allocation with cmn_err at level 4 (0x12f8c). The comparison with 2 suggests two buffers per node, but this is only a constant in the facts.
  Reviewed: 2026-11-12 (sonnet)

- `bte_avail` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12f9c
  **Inferred.** The routine is 12 bytes. The facts show a single return at 0x12fa0 with v0 unresolved, and no call, branch, load or store. The name suggests a block transfer engine availability check, but the facts do not show what v0 holds, so the role is not derived here.
  Reviewed: 2026-11-12 (sonnet)

- `bte_lateinit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x12fa8
  **Inferred.** The routine allocates blocks of 0x78, 0x400, 0x4000 (zeroed), 0x4000 (with kmem_alloc_node) and 0x4 bytes with kmem_zalloc_node and kmem_alloc_node at 0x13078 through 0x131ac. It calls bte_init at 0x130d0 on the 0x400-byte block, initialises a lock with spinlock_init at 0x131c4, and has four assfail calls (line constants 0x14c, 0x156, 0x12d and 0x134) and two cmn_err calls at level 8. The name suggests a late setup step, which fits the allocation order, but the sizes are only constants in the facts.
  Reviewed: 2026-11-12 (sonnet)

- `bte_pbcopy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13274
  **Inferred.** The routine calls bte_copy at 0x132cc with 0x10 as its fourth argument, and calls bcopy at 0x132ec and 0x13324 with both addresses ORed with 0xa800000000000000. The branch at 0x1329c tests disable_bte_pbcopy against zero, the branch at 0x132a8 compares maxcpus with that value, the branch at 0x132b0 tests disable_bte against zero, and the branch at 0x132b8 tests a register the facts do not resolve. The branch at 0x132d4 tests the return of bte_copy. The only return the facts list is 0 at 0x13308. The name suggests a copy through the engine with a software fallback, which the branch structure fits.
  Reviewed: 2026-11-12 (sonnet)

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Role (from name):** the zero-fill counterpart of bte_pbcopy. **Inferred.** The routine calls bzero with addresses ORed with 0xa800000000000000 at 0x133b8 and 0x134c8. It calls get_hub_chiprev at 0x13410 with a value from a node-table lookup, and calls bte_copy at 0x13448 with a0 = 0 and a3 = 0x10. The facts show no comparison of the get_hub_chiprev result, so which path the hub revision selects is not shown, and only 0x10 appears as the fourth argument of bte_copy.
  Reviewed: 2026-11-12 (sonnet)

- `bte_free_interfaces` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1350c
  **Inferred.** The routine loops with an index compared with the constant 2 at 0x13538, and skips the iteration where the index equals its argument a1 at 0x13540. It loads from offset 0x68 of a record (0x13548) and calls nested_spinunlock at 0x13558. The name suggests it frees the interfaces, but the facts show only the loop and the unlock, not the free itself.
  Reviewed: 2026-11-12 (sonnet)

- `bte_get_all_interfaces` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13584
  **Inferred.** The routine takes locks with nested_spintrylock at 0x135d8 and 0x13728 under splhi and splx interrupt masking (0x136ac, 0x1369c, 0x1371c, 0x1370c). It waits one microsecond with us_delay at 0x136a4 and 0x13714 between attempts, which suggests a retry loop. The facts list one return of 0 at 0x13704. The name suggests it gathers every interface, but the facts do not show what it hands back.
  Reviewed: 2026-11-12 (sonnet)

- `bte_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13a5c
  **Inferred.** The routine reads the global disable_bte at entry (0x13a74) and calls splhi at 0x13b00, tests the interface bit lock with bitlock_islocked at 0x13b9c, and takes and releases nested spinlocks with nested_spintrylock at 0x13bc0 and nested_spinunlock at 0x13be4 and 0x13d08. It restores interrupts with splx at 0x13b58 and 0x13c0c. About 20 further calls are not listed here. The lock handling is clear from the calls, but the transfer sequence itself is not derived from these facts.
  Reviewed: 2026-11-12 (sonnet)
