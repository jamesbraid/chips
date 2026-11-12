# Tier-2 reading, round r5 batch 1 of chips: routine role entries

Each entry names a routine in an IP27 boot-set object by its install path and address. The statements
come only from the rendered instruction facts: registers, loads and stores, calls and constants. Entries
are inferred unless the facts settle the role. Where the facts leave a sub-fact open, the entry says so.

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** A 112-byte routine. When the word `hubio_ifdr_skip` is nonzero, the branch at 0xfd50 falls through to the return at 0xfd58 [@0xfd50 fall nonzero] [@0xfd58], which returns 0. When that word is zero the branch is taken to 0xfd60 [@0xfd50 taken zero]. There the routine loads a halfword through the table index `a0` [@0xfd74] and compares an unsigned value at 0xfda4 [@0xfda4]. The returns at 0xfdac and 0xfdb4 yield 1 [@0xfdac] and 0 [@0xfdb4]. Role (from name): an IFDR value check. The facts do not show what the compared value means.
  Reviewed: 2026-11-12

- `hub_dmatimeout_kick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xffc4
  **Inferred.** A 1308-byte routine. When `a1` is nonzero it takes `global_kick_lock` with `mutex_spinlock` [call 1, @0xfff8 fall]; when `a1` is zero it uses `mutex_spintrylock` on the same lock [call 12, @0xfff8 taken zero]. It reads a halfword from `sym(compact_to_nasid_node)` indexed by `a0` [@0xfffc]. It stores to `sym(entermask)` [@0x10048] and to the doubleword after it [@0x10054]. Role (from name): a DMA timeout kick across the hub nodes. The facts do not show what the kick action does to the hardware.
  Reviewed: 2026-11-12

- `page_local_calias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f88
  **Inferred.** A 60-byte routine. It loads the doubleword at the fixed address 0x9200000001000028 [@0x11f8c]. The branch at 0x11f9c goes to 0x11fb8 when that word is zero [@0x11f9c taken zero] and falls through when it is nonzero [@0x11f9c fall nonzero]. The branch at 0x11fb0 compares `a3` with `v1`, and the return at 0x11fbc yields 0 or 1 [@0x11fbc]. Role (from name): a local alias check for a page. The facts do not show which alias it tests.
  Reviewed: 2026-11-12

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Inferred.** A 472-byte routine with two paths. When `disable_bte_pbzero` is zero the branch at 0x13368 is taken [@0x13368 taken zero] to the test of `disable_bte` at 0x13378, and a zero there [@0x13378 taken zero] leads to the path that reads the hub chip revision with `get_hub_chiprev` [call 2] and copies with `bte_copy` [call 3]. The other path zeroes the buffer with `bzero` [call 1]. The copy path also calls `bzero` [call 4] when `bte_copy` returned 1 [@0x13488 fall]. Role (from name): a block-transfer page zeroing routine. The facts do not show the target address.
  Reviewed: 2026-11-12

- `bte_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13a5c
  **Inferred.** A 1532-byte block-transfer copy. The branch at 0x13aa0 is taken when `disable_bte` is zero [@0x13aa0 taken zero]. It calls `splhi` [call 1, @0x13ac8 taken] when `a2` is nonzero [@0x13ab8 fall nonzero] and not above 0x7fff80. It tries a nested spin lock with `nested_spintrylock` [call 5] and releases one with `nested_spinunlock` [call 6], then restores the level with `splx` [call 7]. It also calls `bte_error_handler` [call 13] and `poison_state_clear` [call 14]. Role (from name): the block-transfer copy. The facts do not show the source or destination.
  Reviewed: 2026-11-12

- `bte_unaligned_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x144a0
  **Inferred.** A 596-byte copy for transfers that are not aligned. When `disable_bte` is zero the branch at 0x144cc goes to the BTE path at 0x144e4 [@0x144cc taken zero]. The routine calls `bte_pull` [call 1], `bcopy` [call 3] and `bte_copy` [call 6]. Role (from name): an unaligned copy built from BTE and `bcopy` calls. The facts do not show the alignment rule.
  Reviewed: 2026-11-12

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** An 84-byte wrapper. When `a2` is nonzero, the branch at 0x14700 falls through [@0x14700 fall nonzero] to a call of `bte_copy` with 0x110 in a3 [call 1, @0x14700 fall]. The return at 0x14724 yields 0 or the copy result [@0x14724]. Role (from name): a poison-aware copy wrapper. The facts do not show what the poison flag does.
  Reviewed: 2026-11-12

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** A 272-byte routine. When `a1` is zero the branch at 0x14758 goes to the return [@0x14758 taken zero] at 0x1481c [@0x1481c]. One path calls `poison_state_alter_range` with a2 = 1 [call 1] and returns. The other path calls `bte_copy` with `a3` = 0x110 and `a4` = 0x4000 [call 2], again while the result is zero [@0x147fc taken zero]. When the copy result equals 1 [@0x14808 taken] it calls `poison_state_alter_range` with a2 = 1 [call 3]. Role (from name): a poison-state update over a range. The facts do not show what the range arguments select.
  Reviewed: 2026-11-12

- `bte_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14858
  **Inferred.** A 12-byte routine whose return at 0x1485c yields a value the facts do not resolve [@0x1485c]. The facts list omits the store in the delay slot of that return [@0x1485c]: the disassembly shows a `sw` at 0x14860 that writes the constant 1 to the word `disable_bte`, the word that `bte_copy` and `bte_pbzero` test, so the routine sets that flag. Role (from name): disables the block-transfer engine.
  Reviewed: 2026-11-12

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** A 20-byte routine that loads one doubleword at the fixed address 0x9200000001600000 [@0x15410] and returns a value the facts do not resolve [@0x15418]. Role (from name): reports whether the network link is up. The facts do not show which bit of the loaded word means link up.
  Reviewed: 2026-11-12

- `save_cache_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15f60
  **Inferred.** A 360-byte routine that calls `get_nasid` [call 1] and reads the doubleword at the fixed address 0x9200000001000020 [@0x1606c]. It stores doublewords into a record with `sd` at 0x1609c, 0x160a0 and 0x160b0 [@0x1609c]. The branch at 0x16064 goes back to 0x16040 while its condition holds [@0x16064 taken]. Role (from name): saves cache error state. The facts do not show what the records hold.
  Reviewed: 2026-11-12

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** An 88-byte routine on a saved record at `a0`. It loads the byte at `a0+0x38` [@0x16310]. The branch at 0x16318 goes to the return at 0x16358 when that byte is zero [@0x16318 taken zero]. When the byte is nonzero [@0x16318 fall nonzero] the routine tests an unsigned difference against 0x55d4a80 at 0x16334. When the difference is below it [@0x16334 fall] the routine stores a byte to `a0+0x39` [@0x1633c], loads doublewords from `a0+0x18`, `+0x10` and `+0x8`, and stores doublewords at `a0+0x20`, `+0x28` and `+0x30` [@0x1634c]. Otherwise [@0x16334 taken] it takes the return at 0x16360 [@0x16360] and stores a byte to `a0+0x39` [@0x16364]. Role (from name): restores CPU error state. The facts do not show what the copied values are.
  Reviewed: 2026-11-12

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** A 332-byte routine on a record at `a0`. It loads the doubleword at `a0+0x1f8` [@0x16368]. When that is zero the branch at 0x16370 goes to 0x163fc [@0x16370 taken zero], which loads `a0+0x70` [@0x163fc] and stores to `a0+0x1f8` [@0x1642c] only when that doubleword is nonzero [@0x16408 fall nonzero] and an unsigned difference is below 0x55d4a80 [@0x16420 fall]. The stores to `a0+0x1e8` [@0x16458], `a0+0x208` [@0x16484] and `a0+0x218` [@0x164b0] sit behind the same kind of test. It returns the doubleword at `a0+488` [@0x163c0]. Role (from name): restores hub error state. The facts do not show what the restored values are.
  Reviewed: 2026-11-12

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** An 88-byte routine over a record at `a0`. The branch at 0x164fc goes back to 0x164c8 while `a4` is nonzero [@0x164fc taken nonzero]. Each pass loads a doubleword [@0x164cc]; when it is zero the branch at 0x164d4 skips the stores [@0x164d4 taken zero]. Otherwise an unsigned difference is tested against 0x55d4a80 and, when the branch at 0x164ec falls through [@0x164ec fall], the routine stores doublewords through a pointer built from `a0` plus a per-pass offset [@0x164f4] [@0x164f8]. Role (from name): clears hub PI error entries. The facts do not show what the record holds, and the stores are relative to `a0`, not to a fixed register address.
  Reviewed: 2026-11-12

- `hub_error_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19374
  **Inferred.** Role (from facts): a boot-time set-up for the hub error log [call 1, call 8, call 9]. It calls `hub_error_clear` for the node [call 1]. When `a0` is zero the branch at 0x193a0 goes to 0x195c8 [@0x193a0 taken zero], which allocates two buffers per node with `kmem_zalloc_node` [call 8, @0x193a0 taken] [call 9, @0x193a0 taken] while the index is below `numnodes` [@0x19644 taken]. It calls `hubii_eint_init` on the taken side of the branch at 0x19568 [call 6, @0x19568 taken].
  Reviewed: 2026-11-12

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** Role (from facts): interrupt connection for the hub II error handler [call 1, call 3]. It looks up a hwgraph label [call 1], runs `intr_heuristic` [call 2, @0x1977c fall] and connects the handler `hubii_eint_handler` in a3 with `intr_connect_level` [call 3, @0x197b4 fall]. The branch at 0x197d8 goes to 0x1987c when the connect result is negative [@0x197d8 taken].
  Reviewed: 2026-11-12

- `hubpi_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x199a8
  **Inferred.** A 728-byte handler for the hub PI error interrupt. It calls `check_ni_errors` [call 1]. When that result is nonzero, the branch at 0x199c0 falls through [@0x199c0 fall nonzero] to `hubni_error_handler` [call 2]. When the status word masked with 0xcfff00 is nonzero the branch at 0x19a1c goes to `enter_panic_mode` [call 8, @0x19a1c taken nonzero]. Role (from name): the hub PI error interrupt handler. The facts do not show the meaning of each mask bit.
  Reviewed: 2026-11-12

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** A 604-byte routine that reads the doubleword at the fixed address 0x9200000001608008 [@0x19dd0] and the doubleword at 0x9200000001600000 [@0x19dec]. When the first, masked with 0x3eff000000, is nonzero the branch at 0x19de8 goes to 0x19e48 [@0x19de8 taken nonzero]. The return at 0x19e40 yields one of two constants [@0x19e40]. It calls `cmn_err` [call 1]. Role (from name): an NI error check. The facts do not show what each reported bit means.
  Reviewed: 2026-11-12

- `hubni_rmteint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1c8
  **Inferred.** Role (from facts): a forwarder to `hubni_error_handler` [call 1] that returns the value that call gives back [@0x1a1e4]. The routine adds no logic of its own in the facts.
  Reviewed: 2026-11-12

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** A 316-byte routine that finds a board record with `find_lboard` [call 1] and a component in it with `find_first_component` [call 2, @0x1a254 fall]. When either lookup returns zero the branches at 0x1a254 and 0x1a274 go to 0x1a2c8 [@0x1a254 taken zero] [@0x1a274 taken zero]. It then compares `a1` with 2, 1, 3 and 4 in turn [@0x1a2a4] [@0x1a2ac] [@0x1a2b8] [@0x1a2c0], and stores to memory at 0x1a2e4 [@0x1a2e4] only when `a1` equals 4 [@0x1a2c0 taken]. Role (from name): saves machine-dependent registers. The facts do not show which registers, or the record layout.
  Reviewed: 2026-11-12

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** A 588-byte routine over the per-node error log. It calls `md_err_log_prev` [call 1] and again [call 3]; the branch at 0x1a74c goes back to 0x1a6e4 while the result of the second call is nonzero [@0x1a74c taken nonzero]. After the compares with four constants fall through [@0x1a724 fall] the next call is `kl_panic` [call 2]. It calls `md_err_log_last` [call 4] when the doubleword at `a3` is zero [call 4, @0x1a680 taken zero]. The return at 0x1a784 yields a small code [@0x1a784]. Role (from name): the machine-dependent error check. The facts do not show what the walk reads.
  Reviewed: 2026-11-12

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** A 360-byte routine that calls `get_nasid` [call 1] and looks up a board record with `find_lboard` [call 6]. It calls `find_first_component` [call 7, @0x1ab94 fall] when the board lookup is nonzero. When either lookup returns zero, the branches at 0x1ab94 and 0x1abb8 skip to 0x1ac04 [@0x1ab94 taken zero] [@0x1abb8 taken zero]. It stores to memory from 0x1abf0 to 0x1ac00 [@0x1abf0]. Role (from name): saves spool registers. The facts do not show what they save.
  Reviewed: 2026-11-12

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** A 680-byte routine on the hub PI error spool. It calls `get_nasid` [call 1] and `splerr` [call 2]. When the doubleword in `a7`, loaded from the `kl_error_log` entry for this node, is zero the branch at 0x1ac80 goes to 0x1ae90 [@0x1ac80 taken zero]. The return at 0x1ae38 yields a small status code [@0x1ae38]. Role (from name): gets the next hub PI spool entry. The facts do not show the entry layout.
  Reviewed: 2026-11-12

- `hub_error_status_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1beb4
  **Inferred.** A 96-byte routine that loads the doubleword at the fixed address 0x9200000001000020 [@0x1beb8]. When it is zero the branch at 0x1bec4 goes to 0x1bee8 [@0x1bec4 taken zero], where it loads the doubleword at 0x9200000001000430 [@0x1beec]; when it is nonzero it loads the doubleword at 0x9200000001000450 [@0x1bed0]. Each path tests bit 63 of the second doubleword [@0x1bed8] [@0x1bef4]. When that bit is clear the routine calls `_badaddr_val` on the address 0x9200000002400208 [call 1, @0x1bef4 fall]. Role (from name): a status check that works around a hardware erratum. The facts do not show the workaround.
  Reviewed: 2026-11-12

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** A 120-byte periodic routine. It calls `ii_llp_error_monitor` [call 1] and `ni_llp_error_monitor` [call 2] for the node in the error log. It re-arms itself through `timeout` [call 3, @0x1c090 fall] with 0x64 as the third argument, only when the word at the error-log record is nonzero [@0x1c090 fall nonzero]. Role (from name): counts hub error events on a timer. The facts do not show what the counters hold.
  Reviewed: 2026-11-12
