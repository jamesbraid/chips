# Tier-1 reading, batch 0 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Grades are inferred unless the facts fully establish the role. Where the facts leave something open, the entry says so.

- `bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1668 (612 bytes). Grade: inferred.
  A debug variant of a bit-lock acquire on a lock record passed in `a2`. It retries `try_bitlock` (called at 0x16cc and 0x17f8) and uses `ll`/`sc` pairs on the record offsets 0xa8, 0xac, 0xb0, 0xb8 and 0xbc. On the failure path it calls `splx` (0x17e0) and an indirect callee (0x17e8), and it reports through `cmn_err` (0x18bc) with a constant format string. What the record fields mean is not established by these facts.

- `_64bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c (612 bytes). Grade: inferred.
  The same control shape as `bitlockdebug`, at the same offsets, with `try_64bitlock` (0x1f70, 0x209c) in place of `try_bitlock`. The loads and `ll`/`sc` widths match the 32-bit routine, so the 64-bit difference must sit inside `try_64bitlock`, which this read does not cover. The two are probably the 32-bit and 64-bit faces of one debug lock.

- `_64bitunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x21d0 (280 bytes). Grade: inferred.
  The release side of the debug lock. It compares a halfword global at `-0x3be0` with the halfword at `a2+0x2a` and, on a mismatch, stores zeros into the record at `a2+0x40` and `a0+0` and reports with `cmn_err` at 0x22c0 (level 4) and 0x22d8 (level 0). A loop at 0x2244 to 0x2264 walks a range of values before the report. The reason for the mismatch and the loop's bounds are open from these facts.

- `get_myid` in `IP27/usr/cpu/sysgen/IP27boot/elsc.o` at 0x0 (16 bytes). Grade: inferred.
  It loads the doubleword at the fixed address 0x9200000001000020 and returns it unchanged in `v0`. The routine looks like a plain id read from a boot-time record. Callers are not visible in this read, so the value's meaning stays open.

- `start` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15d0 (544 bytes). Grade: inferred.
  The early entry of the kernel object. It reads the doubleword at 0x9200000001600000, calls `mapped_kernel_setup_tlb` (0x1618), then jumps through a relocated target at `.text+5696` (0x1638). The tail from 0x1640 to 0x17ec is not reached from the entry, so it is not described here.

- `get_nasid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44e4 (28 bytes). Grade: inferred.
  It loads the doubleword at 0x9200000001600000 and returns a value in `v0`. The rendering leaves the returned register unresolved, so which bits of that word form the node id is open. Its callers in this file (for example `getcpuid`, `klsave_spool_registers`) treat the result as a node number.

- `get_slice` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4500 (16 bytes). Grade: inferred.
  It loads the same word as `get_myid`, from 0x9200000001000020, and returns it as the whole value with no mask. The name suggests a slice field, but the body shows no field extraction. The slice meaning is therefore an inference from the name alone.

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510 (20 bytes). Grade: inferred.
  It reads the doubleword at 0x9200000001600000 (the word `get_nasid` also reads) and returns it raw. The name suggests a directory-mode test, but no comparison appears in the body. The predicate reading is an inference from the name.

- `ni_reset_port` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x45e0 (16 bytes). Grade: inferred.
  It stores a doubleword to 0x9200000001600008 and returns that same address in `v0`. It reads as a write into the second word of the block at 0x9200000001600000. Whether the write resets a port is inferred from the name only.

- `sn00_vmc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xc818 (200 bytes). Grade: inferred.
  It reads low I/O aliases at 0xffffffffffffc400 and 0xffffffffffffc422, then walks a table through the halfword at `-0x3bde`. It calls `device_inventory_add` (0xc850) with constants 0xb and 0x3, then `pcibr_hints_dualslot`, `pcibr_hints_subdevs`, `pcibr_hints_fix_rrbs` and `pcibr_set_rrb_callback` with `sn00_rrb_alloc`. It stores four doublewords to 0x9200000001220050 under a `splprof`/`splx` pair. The routine looks like per-board PCI hint setup, but the meaning of the constants and of the table fields is open.

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8 (116 bytes). Grade: inferred.
  It raises the priority with `splhi`, gets the node with `get_nasid`, and calls `nasid_slice_to_cpuinfo` with that node and the slice word. It returns the halfword at offset 0x1e of the returned record, and it calls `assfail` (0x535) when the record pointer is null. The name and the call chain point to the current CPU id, but the id's encoding is not shown.

- `restart` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x10694 (356 bytes). Grade: inferred.
  A restart path that loops over nodes up to `maxnodes`, calls `ni_reset_port` per port, optionally powers off through `sysctlr_power_off`, then resets through `elsc_init` and `elsc_system_reset`. It falls back to `printf` when the reset returns a negative value. The two `us_delay` calls use constants 0xf4240 and 0x2dc6c0; if the unit is microseconds these are one and three seconds, but the unit is not shown.

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28 (64 bytes). Grade: inferred.
  It reads the doubleword at 0x9200000001000028 and, when that word is zero, compares `v1` with `a1` as unsigned values. It returns 0 or 1. It looks like a predicate on an alias state, but the field the word holds is not established.

- `page_local_calias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f88 (60 bytes). Grade: inferred.
  The same shape as `memory_iscalias`, reading 0x9200000001000028 and returning 0 or 1 from an unsigned compare of `a3` and `v1`. It is most likely the page-local form of the same check. That relation is inferred from the matching structure.

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c (20 bytes). Grade: inferred.
  It reads the doubleword at 0x9200000001600000 and returns it raw. The name suggests a link-state probe, but no mask or compare is applied. The reading is an inference from the name.

- `save_cache_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15f60 (360 bytes). Grade: inferred.
  It calls `get_nasid`, then loops over a per-node table at 0x9600000000000000 with a 0x2000 offset, reading words and bytes from it. It stores several doublewords and a word and a byte into targets the rendering cannot resolve. The routine looks like it records cache error state into a save area, but the destination addresses are open.

- `hub_error_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19374 (928 bytes). Grade: inferred.
  It sets up hub error handling per node. It indexes the per-node error log `kl_error_log` by a compact node id from `get_compact_nodeid`, calls `hub_error_clear`, `recover_error_init` twice, and connects `hubpi_eint_handler` at interrupt level 6 with `cause_intr_connect`. It also calls `hubii_eint_init`, `hubni_eint_init`, two `kmem_zalloc_node` allocations and `spinlock_init`, and it asserts with `assfail` at lines 0x9b, 0xa4 and 0xa5. The loop over `numnodes` (0x195dc) covers every node.

- `hubpi_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x199a8 (728 bytes). Grade: inferred.
  The processor-interface error interrupt handler. It calls `check_ni_errors` first and runs `hubni_error_handler` when that returns nonzero. It then reads a per-CPU record through `pdaindr` indexed by the halfword at `-0x3be0` and reads error bits at 0x9200000001000400, 0x408 and 0x410. It calls `log_md_errors` and `process_error_spool` under masks, and it enters `enter_panic_mode` and calls `kl_panic` when a panic-class mask is set. The exact mask meanings are inferred from the callee names.

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0 (604 bytes). Grade: inferred.
  It reads the NI status doubleword at 0x9200000001608008 and the words at 0x9200000001600000, 0x9200000001600010 and 0x92000000010000a0. It tests a long list of bit masks, from 0x30000000 up to 0x10000000000, and reports the set ones with `cmn_err`. It calls `protected_broadcast` with codes 0x67 and 0x68, and returns 0 or 1. Which hardware bit each mask stands for is not established here.

- `hubni_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a01c (392 bytes). Grade: inferred.
  It reads NI status from 0x9200000001608008 and the state word at 0x9200000001600010, and it writes 0x9200000001600008. It calls `splerr`, `set_node_panic_flag` (the byte at `-0x3add` gates it), `hubni_print_state`, `router_print_state`, `ip27log_printf` and `enter_panic_mode`. It also calls `enter_promlog_mode` and `panicspin` on some paths. Which branch is the panic path and which only logs is inferred from the callee names.

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4 (360 bytes). Grade: inferred.
  It calls `get_nasid` several times, then `find_lboard` with class 0x11 and `find_first_component` with class 0x2. It reads a per-node table at the same 0x9600000000000000 base used by `save_cache_error`, reads a word at `find_first_component`'s result +0x30, and stores three doublewords to targets the rendering leaves open. The name suggests it saves CPU register state into a spool, but the targets make that unconfirmed.

- `hub_error_status_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1beb4 (96 bytes). Grade: inferred.
  It reads 0x9200000001000020, then the words at 0x9200000001000450 and 0x9200000001000430, masks them with bit 63, and calls `_badaddr_val` at 0x9200000002400208 with size 8 as a probe. It returns the probe result or zero. The "war" in the name suggests a workaround for a hub status quirk, but the facts do not say which quirk.

- `err_int_unblock_mask` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c4c8 (76 bytes). Grade: inferred.
  It reads the low I/O alias at 0xffffffffffffc420 and a per-CPU record through `pdaindr`, then stores to 0x9200000001000400. It reads and writes a doubleword at an address computed from a table pointer, and skips the write when `a1` is zero. The name suggests it clears a mask on an error interrupt, but the computed address is not resolved.

- `handle_io_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d5cc (588 bytes). Grade: inferred.
  The bus-error handler for I/O-space errors. It calls `get_matching_spool_addr` and branches on its result (-1, 0, 1 or 2), calls `kl_ioerror_handler` three times with the same argument pattern, and reports through `cmn_err_tag` with message codes 0xb6c and 0xb6d. It stores to 0x9200000001000400 and returns 1 or 2. The decision tree between those outcomes is not read in full here.

- `handle_uncac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d818 (1208 bytes). Grade: inferred.
  The bus-error handler for uncached accesses. It calls `get_matching_spool_addr`, `nasid_to_partid` and `part_id`, and it calls `partition_handle_error` with codes 0x1, 0x5, 0x6, 0x9 and 0xa. It also calls `error_check_memory_access`, `error_check_part_page`, `error_check_poisoned_state` and `error_page_discard`, and it reports through `cmn_err_tag` with codes 0xb6c to 0xb79. The routine appears to classify an uncached bus error as a partition, page or poisoned-memory event. The full decision tree is not read in this batch.
