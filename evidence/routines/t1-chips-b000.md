# Tier-1 reading, batch 0 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Grades are inferred unless the facts fully establish the role. Where the facts leave something open, the entry says so.

- `bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1668 (612 bytes). Grade: inferred.
  Role (from name): a debug variant of a bit-lock acquire. It takes a lock record in `a2` and calls `try_bitlock` at 0x16cc and again at 0x17f8 inside a loop, passing `a0` and `a1` through. It uses `ll`/`sc` pairs on the record offsets 0xa8, 0xac, 0xb0, 0xb8 and 0xbc. Inside the retry loop it calls `splx` (0x17e0) and then an unresolved callee (0x17e8) only when `a5` is nonzero. It calls `cmn_err` (0x18bc) with level 0 and a constant format string. What the record fields mean, and which `try_bitlock` result is success, is not established by these facts.
  Reviewed: 2026-11-12

- `_64bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c (612 bytes). Grade: inferred.
  The same control shape as `bitlockdebug`, at the same record offsets, with `try_64bitlock` (0x1f70, 0x209c) in place of `try_bitlock`. The `ll`/`sc` accesses at 0xa8, 0xac, 0xb0, 0xb8 and 0xbc are the same width as in the 32-bit routine, so these facts show no 64-bit access in this routine itself; any 64-bit difference is outside what this read covers. Role (from name): the 64-bit counterpart of `bitlockdebug`.
  Reviewed: 2026-11-12

- `_64bitunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x21d0 (280 bytes). Grade: inferred.
  Role (from name): the release side of the debug lock. It compares the halfword at `-0x3be0` with the halfword at `a2+0x2a`. When they are equal it stores to offsets 0x2a, 0x48, 0x60, 0x68, 0x80, 0x78, 0x64 and 0x58 and a doubleword at +0x0, then returns. When they differ it loads and stores a doubleword at +0x40 (the stored value is not shown), then calls `cmn_err` at 0x22c0 with level 4 and at 0x22d8 with level 0. The branch at 0x2244 compares two unresolved registers unsigned and goes to 0x22d0 when the first is below the second. The facts show no backward branch in this routine. The reason for the mismatch is open.
  Reviewed: 2026-11-12

- `get_myid` in `IP27/usr/cpu/sysgen/IP27boot/elsc.o` at 0x0 (16 bytes). Grade: inferred.
  It loads the doubleword at the fixed address 0x9200000001000020 and returns it unchanged in `v0`. Role (from name): an id read. Callers are not visible in this read, so the value's meaning stays open.
  Reviewed: 2026-11-12

- `start` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15d0 (544 bytes). Grade: inferred.
  Role (from name): an early entry of the kernel object. It performs one doubleword load (the address is not resolved in the facts), calls `mapped_kernel_setup_tlb` (0x1618), then makes a tail call through a relocated target at `.text+5696` (0x1638). The facts do not describe the bytes after 0x1640.
  Reviewed: 2026-11-12

- `get_nasid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44e4 (28 bytes). Grade: inferred.
  It performs one doubleword load and returns a value in `v0` that the rendering leaves unresolved, so the address read and which bits of that word form a node id are open. Its callers in this file (for example `getcpuid`) pass the result as the first argument of `nasid_slice_to_cpuinfo`, which suggests a node id; that is an inference from the callee name.
  Reviewed: 2026-11-12

- `get_slice` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4500 (16 bytes). Grade: inferred.
  It loads the same word as `get_myid`, from 0x9200000001000020, and returns it as the whole value with no mask. The name suggests a slice field, but the body shows no field extraction. The slice meaning is therefore an inference from the name alone.
  Reviewed: 2026-11-12

- `is_fine_dirmode` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4510 (20 bytes). Grade: inferred.
  It performs one doubleword load and returns a value in `v0` that the rendering leaves unresolved. No compare or branch appears in the facts. Role (from name): a directory-mode predicate; the body shows no test.
  Reviewed: 2026-11-12

- `ni_reset_port` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x45e0 (16 bytes). Grade: inferred.
  It stores a doubleword at offset 0x0 of a base register the facts do not name, and returns the constant 0x9200000001600008 in `v0`. Role (from name): a port reset; the facts show no more than the store and the returned constant.
  Reviewed: 2026-11-12

- `sn00_vmc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xc818 (200 bytes). Grade: inferred.
  It indexes a table through the halfword at `-0x3bde`. It calls `device_inventory_add` (0xc850) with `a1` = 0xb and `a2` = 0x3, then `pcibr_hints_dualslot` (`a1` = 0x2, `a2` = 0x3), `pcibr_hints_subdevs` (`a1` = 0x2, `a2` = 0xff), `pcibr_hints_fix_rrbs` and `pcibr_set_rrb_callback` with `sn00_rrb_alloc` in `a1`. It then calls `splprof`, `get_my_slotid` and `splx` (0xc8bc, with 0x9200000001220050 in `a3`). Two doubleword stores follow the `get_my_slotid` result compare on each side of the branch at 0xc8ac; their targets are not resolved. Role (from name): per-board PCI hint setup; the meaning of the constants and table fields is open.
  Reviewed: 2026-11-12

- `getcpuid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xdff8 (116 bytes). Grade: inferred.
  It raises the priority with `splhi`, calls `get_nasid`, and calls `nasid_slice_to_cpuinfo` with that result in `a0` and the doubleword at 0x9200000001000020 (the word `get_slice` returns) in `a1`. It restores the priority with `splx`. When the returned record pointer is nonzero it returns the halfword at offset 0x1e of the record. When it is null it reaches `assfail` (0xe05c) with 0x535 in `a2`. Role (from name): the current CPU id; the id's encoding is not shown.
  Reviewed: 2026-11-12

- `restart` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x10694 (356 bytes). Grade: inferred.
  Role (from name): a restart path. It has a loop bounded by `maxnodes` (back branch at 0x1070c) that loads halfwords and stores doublewords. A second loop (0x10744 to 0x10774) calls `sysctlr_power_off` and `us_delay` (0x2dc6c0) when `power_off_flag` is nonzero. `ni_reset_port` is called once at 0x10784, outside both loops. The path then calls `get_nasid`, `elsc_init` and `elsc_system_reset`, and calls `printf` when the reset returns a negative value. There are three `us_delay` calls: 0xf4240 (0x10720), 0x2dc6c0 (0x10754) and 0xf4240 (0x107d4). If the unit is microseconds these are one, three and one seconds, but the unit is not shown.
  Reviewed: 2026-11-12

- `memory_iscalias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f28 (64 bytes). Grade: inferred.
  It reads the doubleword at 0x9200000001000028 and, when that word is nonzero, compares `v1` with `a1` as unsigned values. It returns 0 or 1. Role (from name): a predicate on an alias state; the field the word holds is not established.
  Reviewed: 2026-11-12

- `page_local_calias` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x11f88 (60 bytes). Grade: inferred.
  The same shape as `memory_iscalias`, reading 0x9200000001000028 and returning 0 or 1 after an unsigned compare of `a3` and `v1` when the word is nonzero. Role (from name): a page-local form of the same check. The relation to `memory_iscalias` is inferred from the matching structure.
  Reviewed: 2026-11-12

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c (20 bytes). Grade: inferred.
  It performs one doubleword load and returns a value in `v0` that the rendering leaves unresolved. No mask or compare appears in the facts. Role (from name): a link-state probe.
  Reviewed: 2026-11-12

- `save_cache_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15f60 (360 bytes). Grade: inferred.
  It calls `get_nasid`, loads a doubleword at +0x48 from an unresolved base, and has two loops with back branches at 0x16000 and 0x16064 that read bytes and words. One compare tests a loaded byte against the doubleword at 0x9200000001000020. It stores three doublewords, a word and a byte at 0x1609c to 0x160b0 into targets the rendering cannot resolve. Role (from name): recording cache error state into a save area; the table base and destination addresses are open.
  Reviewed: 2026-11-12

- `hub_error_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19374 (928 bytes). Grade: inferred.
  Role (from name): per-node hub error setup. It calls `hub_error_clear` first, calls `get_compact_nodeid`, and indexes the per-node pointer table `kl_error_log` by shifting a node register left by 3. It calls `recover_error_init` twice and calls `cause_intr_connect` with 0x6 in `a0` and `hubpi_eint_handler` in `a1`, on a path that depends on the tested words at 0x9200000001000050 and 0x9200000001000058. It also calls `hubii_eint_init`, `hubni_eint_init` and `spinlock_init`. A loop bounded by `numnodes` (guard at 0x195dc, back branch at 0x19644) holds the two `kmem_zalloc_node` calls (sizes 0x1938 and 0x40). `assfail` is called with 0x9b, 0xa4 and 0xa5 in `a2`.
  Reviewed: 2026-11-12

- `hubpi_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x199a8 (728 bytes). Grade: inferred.
  Role (from name): a processor-interface error interrupt handler. It calls `check_ni_errors` first and calls `hubni_error_handler` when that returns nonzero. It then loads a halfword, a doubleword at +0x8 and a byte at +0x520, and tests the loaded word against masks 0xcfff00, 0x1 or 0x2, 0x40 or 0x80, 0x10 or 0x20, 0x100000 or 0x200000 and 0x4 or 0x8. It calls `log_md_errors` when a signed value tested at 0x19a24 is negative and `process_error_spool` three times under mask tests. When the 0xcfff00 mask matches it calls `enter_panic_mode`, `cmn_err` (level 0x14) and `kl_panic`. The meaning of each mask is not established.
  Reviewed: 2026-11-12

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0 (604 bytes). Grade: inferred.
  It reads the status doubleword at 0x9200000001608008 and the doublewords at 0x9200000001600000, 0x9200000001600010 and 0x92000000010000a0. It tests a long list of bit masks, from 0x30000000 up to 0x10000000000, and reports the set ones with `cmn_err`. It calls `protected_broadcast` with codes 0x67 and 0x68, and returns 0 or 1. Which hardware bit each mask stands for is not established here. Role (from name): a network-interface error check.
  Reviewed: 2026-11-12

- `hubni_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a01c (392 bytes). Grade: inferred.
  It reads the status doubleword at 0x9200000001608008 and the doubleword at 0x9200000001600010. It calls `splerr`, then `set_node_panic_flag` only when the byte at `-0x3add` is nonzero, `hubni_print_state`, `router_print_state`, `ip27log_printf` and `enter_panic_mode`. It also calls `enter_promlog_mode` and `panicspin` on some paths. Its stores (at 0x1a0c0 and 0x1a170) have unresolved targets. Which branch is the panic path and which only logs is inferred from the callee names.
  Reviewed: 2026-11-12

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4 (360 bytes). Grade: inferred.
  It calls `get_nasid` five times, then `find_lboard` with 0x11 in `a1` and, when that returns nonzero, `find_first_component` with 0x2 in `a1`. It reads a word at the `find_first_component` result +0x30, and stores three doublewords to targets the rendering leaves open. Role (from name): saving CPU register state into a spool; the unresolved targets leave that unconfirmed.
  Reviewed: 2026-11-12

- `hub_error_status_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1beb4 (96 bytes). Grade: inferred.
  It reads the doubleword at 0x9200000001000020 (a zero test skips one path), then the doublewords at 0x9200000001000450 and 0x9200000001000430, each tested against bit 63. On one path it calls `_badaddr_val` with 0x9200000002400208 in `a0` and 8 in `a1`. It returns either the `_badaddr_val` result or a value the rendering leaves unresolved. Role (from name): a workaround for a hub status quirk, with the quirk not shown.
  Reviewed: 2026-11-12

- `err_int_unblock_mask` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c4c8 (76 bytes). Grade: inferred.
  It loads a halfword, a doubleword at +0x8 and a byte at +0x520, then skips a doubleword store (0x1c4ec) when `a1` is zero. It later loads a doubleword at 0x1c504 and stores a doubleword at 0x1c510 with the same offset (printed as -0x6dffffffff000000) from a base the rendering does not resolve. Role (from name): clearing a mask on an error interrupt; the target addresses are open.
  Reviewed: 2026-11-12

- `handle_io_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d5cc (588 bytes). Grade: inferred.
  Role (from name): a bus-error handler for I/O-space errors. It calls `get_matching_spool_addr` and branches on its result (0, -1, 1, 2). It calls `kl_ioerror_handler` three times with the same argument pattern, and calls `cmn_err_tag` with 0xb6c and 0xb6d in `a0`. It tests the doubleword at 0x9200000001000400 against masks 0x100000 and 0x200000. It also calls `get_nasid`, performs a store with an unresolved target at 0x1d7a8 and returns 1 or 2. The decision tree between those outcomes is not read in full here.
  Reviewed: 2026-11-12

- `handle_uncac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d818 (1208 bytes). Grade: inferred.
  Role (from name): a bus-error handler for uncached accesses. It calls `get_matching_spool_addr`, `nasid_to_partid` and `part_id`, and it calls `partition_handle_error` with 0x1, 0x5, 0x6, 0x9 and 0xa in `a2`. It also calls `error_check_memory_access`, `error_check_part_page`, `error_check_poisoned_state` and `error_page_discard`, and calls `cmn_err_tag` with codes 0xb6e to 0xb79 in `a0`. The routine appears to classify an uncached bus error as a partition, page or poisoned-memory event. The full decision tree is not read in this batch.
  Reviewed: 2026-11-12
