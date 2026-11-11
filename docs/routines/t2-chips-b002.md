# Tier-2 reading, batch 2 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: branches, loads and stores, calls and constants. No role here is settled outright by the facts, so each is inferred, and the open points are stated.

- `bte_unaligned_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x144a0
  **Inferred.** A block copy that chooses between the BTE path and plain `bcopy`. It reads the `disable_bte` and `maxcpus` globals (0x144cc, 0x144dc), copies pieces with `bte_pull` (0x1452c, 0x14560) and `bte_copy` (0x14650, 0x146a4), and falls back to `bcopy` (0x145ac, 0x1461c, 0x1467c). It compares lengths against 0x80 (0x14664) and 0x7fff80 (0x14640). Which pieces count as unaligned, and what the 0x7fff80 limit means, are not settled by these facts.

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** A wrapper around `bte_copy` (0x14708) that passes the fixed value 0x110 as its fourth argument. A non-zero result from `bte_copy` branches to the `cmn_err` report at 0x14738 with level 0xc and the copy result as an argument. The meaning of 0x110 is not established.

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** Works over a range by calling `poison_state_alter_range` (0x14798, 0x14840) and `bte_copy` (0x147e8, flag 0x110, length 0x4000). The globals `disable_bte_poison_range` and `disable_bte` gate the copy, and `bte_copy` is retried on a zero result (0x147fc). What the poison state is, and the meaning of 0x4000, are not established.

- `bte_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14858
  **Inferred.** The body is three instructions with no loads, stores or calls, and its return value is not computed from anything in the facts. It is probably a stub. Which disable it performs is not established by these facts.

- `bte_wait_for_xfer_completion` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14864
  **Inferred.** A bounded poll of the BTE control record passed in `a0`. It reads two 8-byte fields of that record, tests a masked halfword (0x1487c), and loops on a count kept at offset +500 of the hub register at 0x9200000001030100 (0x148a0). The timeout report at 0x148c8 passes 0x1f4 (500) to `cmn_err` at level 0x14. The exact completion bit and the loop bound are not established.

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** Reads one 8-byte word at the fixed address 0x9200000001600000 (0x15410) and returns with no computed value. `check_ni_errors` reads the same address (0x19dec), which suggests a network-interface status register. The bit that means link up is not established.

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** Moves fields inside the error record passed in `a0`: it reads 8-byte words at +0x0, +0x8, +0x10 and +0x18 and writes +0x20, +0x28 and +0x30. It branches on a flag byte at +0x38 and sets the byte at +0x39 on its returns, and it reads the hub register at 0x9200000001030100 (0x16328). Whether this restores or saves CPU error state is not established.

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** A long copy over the record at `a0`. It tests fields at offsets +0x58 to +0x90 and +0x1e8 to +0x218 for zero and copies the paired 8-byte words, looping against the 0x55d4a80 bound. The value returned is the word at +0x1e8 (0x163c0). The meaning of each field, and whether this restores or saves, are not established.

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** Reads two pointer-sized fields and the hub register at 0x9200000001030100 (0x164e0), then stores two 8-byte words (0x164f4, 0x164f8) under a bound check against 0x55d4a80. It returns with no computed value. The name suggests it clears PI error state, but the stored values are not shown, so the clear is not established.

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** Walks the error record at `a0` and writes four 8-byte slots (+0x8, +0x18, +0x28, +0x38), each gated on a zero test and the 0x55d4a80 bound. The hub register at 0x9200000001030100 is read four times (from 0x16530). The name suggests it clears memory-directory error latches, but the stored values and the register meanings are not established.

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** Sets up the hub II error interrupt for one node. It maps the node index through `compact_to_nasid_node` (0x197fc), looks up the target with `hwgraph_info_get_LBL` (0x19754), picks a level with `intr_heuristic` (0x197a0), and connects `hubii_eint_handler` with `intr_connect_level` (0x197d0). Failure paths report through `cmn_err` (0x1986c) and `assfail`, which receives 0x135 and 0x153 as its line argument. The two table words stored at 0x9200000001c00128 and 0x9200000001c00138 (0x19824, 0x19844) are not established.

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** Scans five network-interface status words at fixed addresses (0x9200000001608008, 0x9200000001600000, 0x9200000001600010, 0x92000000010000a0, 0x9200000001608088) against bit masks. Each set condition reports through `cmn_err` (levels 0x14 and 0x15, 0x19e7c to 0x1a00c), and two of the conditions call `protected_broadcast` with codes 0x67 and 0x68 (0x19f2c, 0x19f34). The bit each mask stands for, such as 0x3eff000000 or 0xf0000000, is not established.

- `hubni_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1a4
  **Inferred.** A thin interrupt entry that calls `hubni_error_handler` (0x1a1b4) with flag 1, passes its own a2 and a3 through, and returns the callee's result. The flag is probably the local-versus-remote choice, which the twin entry below suggests but the facts do not show.

- `hubni_rmteint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1c8
  **Inferred.** The remote-interrupt twin of `hubni_eint_handler`. It calls `hubni_error_handler` (0x1a1d8) with flag 0 and returns its result. The two entries differ only in that flag.

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** Finds a board record with `find_lboard` (type 0x11, 0x1a24c), then a component under it with `find_first_component` (class 2, 0x1a260). It reads a register window keyed by argument a2 (0x1a20c, offset +0x48) and stores 8-byte words on paths chosen by the argument compared with 1, 2, 3 and 4 (0x1a2a4 to 0x1a2c0). The stored register set and the meaning of those four values are not established.

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** Walks memory-directory error entries for one node, starting from the `kl_error_log` slot selected by `nasid_to_compact_node` (0x1a63c, 0x1a654). It reports entries through `md_err_log_prev` (0x1a688, looping at 0x1a74c) and `md_err_log_last` (0x1a84c), and calls `kl_panic` (0x1a730) on one path. The four type values it compares against (0x1a70c to 0x1a724) and the panic condition are not established.

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** Saves a spool-register set for the node that `get_nasid` identifies (0x1aae8 to 0x1ab4c), with the same board and component lookup as `klsave_md_registers`. It reads a register window keyed by that node (0x1ab1c, 0x1ab64) and writes three 8-byte words (0x1abf0 to 0x1ac00). The contents of those words and the flag tested at 0x1abd4 are not established.

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** Fetches the next pending spool entry for a node from fields at +0x1910, +0x1920 and +0x1930 of the node's `kl_error_log` record, and copies 8-byte words from that entry into the caller's buffers. It brackets the work with `splerr` and `splx` (0x1ac48, 0x1ae20 to 0x1aec4) and calls `klsave_spool_registers` with class 2 on one path (0x1aeb4). The ring layout and the flag bytes read at +0x520 are not established.

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** An error handler for a hub I/O CRB error. It takes the lock at `a1+796` with `mutex_spinlock_spl` (0x1b8fc), then dispatches on a code compared with 1, 2 and 5 (0x1ba08 to 0x1ba28) and through an indirect jump at 0x1bad0 whose targets are unresolved. It calls `bte_crb_error_handler` (0x1ba4c), `hubiio_crb_free` (0x1ba58) and `sn0_error_dump` (0x1bb08), and reports through `cmn_err` and `assfail` (line 0x70c). Which code reaches which handler is not established.

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** A periodic monitor for one node. It reads the node's `kl_error_log` record (0x1c058 to 0x1c08c), calls `ii_llp_error_monitor` on the record at +8 (0x1c074) and `ni_llp_error_monitor` on the record at +32 (0x1c080), and re-arms itself with `timeout` at 0x64 (0x1c0a0) when a word it loaded is non-zero (0x1c090). The unit of the 0x64 interval is not established.

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** Turns on the error count for one node. It returns -1 for a negative node index, reads the node's `kl_error_log` slot (0x1c0e8 to 0x1c10c), clears a 64-byte block with `bzero` on one branch (0x1c130), stores a 4-byte word into the record (0x1c154), and arms `hub_error_count_update` with `timeout` at 0x64 (0x1c150). The value stored and the flag passed to `timeout` are not established.

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** The disable side of the same per-node counter. It returns -1 for a negative index or an empty record (0x1c16c, 0x1c17c), and for a slot whose word equals -1 it returns 0 (0x1c18c). Otherwise it stores a 4-byte word into the node's record (0x1c1a4). The stored value is not shown, and nothing here cancels the armed `timeout`, so whether it is cancelled elsewhere is not established.

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** Reads the node's error count. It rejects negative indexes and indexes of 0x100 or more (0x1c1c0, 0x1c1d4), writes a 4-byte word through the pointer in `a1` (0x1c1ec), and returns the 8-byte value from the node's `kl_error_log` slot (0x1c1f8). The 0x100 bound is a fixed table limit in the code, and the meaning of the returned value is not established.

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** Decides whether a saved error record for the current processor can be recovered. It reads the per-processor data area through `pdaindr` (0x1c654, flag byte at +0x520 read at 0x1c658) and the node's `kl_error_log` slot (0x1c608). It calls `klerror_global_check` (0x1c678) and `error_check_part_page` (0x1c708), writes status fields at +0x1810 to +0x1828 in the selected record (0x1c704 to 0x1c738), and reports an unexpected path through `cmn_err_tag` (line 0xb54) and `assfail` (line 0xbe). The meaning of the fields and of the flag is not established.

- `sn0_skip_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c78c
  **Inferred.** Calls `dumptlb` (0x1c794) with the processor index read from `pdaindr` (the halfword at -0x3be0) and then branches to itself at 0x1c79c with no exit. The facts show no return after the call, so this is either an intentional halt after the TLB dump or a gap in the rendered facts. Which of the two it is, is not established.
