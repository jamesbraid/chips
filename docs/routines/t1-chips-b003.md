# IP32 and IP35 routines read in batch 3

These are role statements for 25 routines from the IP32 and IP35 kernel objects and from two archive members of the chips binaries. Each statement comes from the rendered facts: the addresses a routine reads and writes, the calls it makes and its return value. Every grade is inferred, because no rendered fact settles a role by itself. Addresses use the 64-bit forms the facts use. `0xffffffffb4000000` is the uncached view of physical `0x14000000`, which `docs/coverage-crime.md` uses for CRIME. `-0x3bd8` appears to hold the processor number, since the lookup tables index by it, and `-0x5fe8` is a per-processor word I have not identified.

## IP32 probes

- `badaddr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14270
  Probes one address with a 1, 2, 4 or 8 byte load chosen by the size in a1: `lb` at 0x142dc, `lh` at 0x142f4, `lw` at 0x1430c and `ld` at 0x14324 all read through a0. Any other size reaches the `cmn_err` call at 0x14338. The normal return at 0x143a0 gives v0 = 0, and the facts do not show how a faulting load is caught here, though the probe shape suggests it reports whether the address is readable. A mask test of the doubleword at 0xffffffffb4000028 at 0x14374 sends control to 0x149a8 when a bit is set, and that path is not rendered.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `badaddr_val` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x143a8
  It uses the same size dispatch as `badaddr`, but the loaded value is also stored through a2 at 0x1442c, 0x1444c, 0x1446c or 0x1448c, which suggests the value is handed back to the caller. The word at -0x5fe8 is tested at 0x14400 and again at 0x144e8. When it is zero, the halfword store through it at +0xc2 (0x14408, 0x144f0) is skipped, and the word store to 0xffffffffffffa1d8 at 0x14414 (and 0x144fc) is reached either way. The normal return at 0x1451c gives v0 = 0, and an unrecognised size reaches `cmn_err` at 0x144a0.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `wbadaddr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14524
  It writes a value of the size in a1 to a0, using `sb` at 0x14590, `sh` at 0x145a8, `sw` at 0x145c0 or `sd` at 0x145d8, and an unrecognised size reaches `cmn_err` at 0x145ec. The facts do not name the register holding the stored value, so what gets written stays open. On the way out it reads the doubleword at 0xffffffffb4000008 and the word at 0xffffffffa0000000, which is the uncached start of physical memory, and returns v0 = 0 at 0x14680. The store-only shape suggests a write probe, but the fault handling is not rendered.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `earlybadaddr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14808
  It probes with 1, 2 or 4 byte loads chosen by a1 (`lb` at 0x14878, `lh` at 0x14890, `lw` at 0x148a8), and sizes 8 and anything else reach `cmn_err` at 0x148bc. It stores 4 bytes to the `nofault` symbol at 0x14868 and again at 0x14908, which suggests it arms and clears a fault catch around the access, though the handler is not rendered. The name suggests a probe used before normal memory setup, which the facts neither confirm nor rule out.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

## IP32 meter records

- `_mraccess` in `IP32/usr/cpu/sysgen/IP32boot/ksync_metered.a(sema.o)` at 0x35b8
  It calls `wchanmeter` with `mrinfolist` and branches on the nonzero return. A nonzero return goes to `_get_timestamp` and then `mrmeter_entry` with tag 5, and a zero return goes through `mr_access`. The record's words at +0x138 through +0x170 are read and updated, with an `ll`/`sc` pair on +0x138, and `mrmeter_getentry` is called with a value read from +356 of that record. The name suggests metering of an access to a wait channel, but the facts do not show what is counted or what tag 5 means.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_mrupdate` in `IP32/usr/cpu/sysgen/IP32boot/ksync_metered.a(sema.o)` at 0x36e0
  It makes the same `wchanmeter` call as `_mraccess` and branches on the return. A zero return falls through to `mr_update` at 0x3708. A nonzero return goes to 0x3790, which calls `mrmeter_entry` with tag 6 at 0x379c and `_get_timestamp` at 0x37a4. `_get_timestamp` is also called at 0x3718. It stores into the record at +0x140, +0x148 through +0x158 and +0x178, and a test on bit 0x4 at 0x3768 picks one of two branches, while the `lhu` and `sh` through an unresolved register are not identified.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

## IP35 lock debug wrappers

- `bitlockdebug` in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)` at 0x1668
  It reads the doubleword at 0x9200000001030100 twice and calls `try_bitlock` at 0x16cc with its own arguments. The `ll`/`sc` pairs on the words at a2+0xb8 and a2+0xbc update the lock record. A second path calls `splx`, makes an indirect call at 0x17e8 whose target is not resolved, retries `try_bitlock` at 0x17f8, and reports through `cmn_err` at 0x18bc with the doubleword at 0x9200000001030100 as an argument.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_64bitlockdebug` in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c
  It has the same calls as `bitlockdebug`, with `try_64bitlock` at 0x1f70 and 0x209c in place of `try_bitlock`, `splx` at 0x2084, an indirect call at 0x208c, and a `cmn_err` report at 0x2160. The lock fields it updates are known only by their offsets from a2. The name suggests the 64-bit form of the debug lock acquire, which matches the call pattern.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_64bitunlockdebug` in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)` at 0x21d0
  It compares the halfword at a2+0x2a with the processor number at -0x3bd8 (branch at 0x2208), and on a mismatch goes to 0x22a8. There the value at a2+0x40 is read, a store to a2+0x40 follows (the stored value is not shown), and `cmn_err` at 0x22c0 reports the value plus one. The match path updates fields at a2+0x2a and a2+0x48 through a2+0x80, and a second `cmn_err` at 0x22d8 is reached from the branch at 0x2244. The name suggests the unlock side of the debug lock, but the facts do not show what the field offsets mean.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

## IP35 hub and node helpers

- `get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12b4
  It reads one doubleword at the fixed address 0x9200000001600000 and returns it, and the return value is unresolved in the facts. Callers such as `getcpuid`, `hubpi_eint_handler` and `klsave_spool_registers` pass the result on as an argument to other node routines. The facts do not show the register at that address or how the value is decoded.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `get_slice` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12d0
  It loads the doubleword at 0x9200000001000020 and returns it unchanged. `getcpuid` passes the same doubleword as the second argument to `nasid_slice_to_cpuinfo`, which fits a slice number, but the value's layout is not shown. The facts establish the load and the return only.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `ni_reset_port` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13b4
  It stores two doublewords, at 0x9200000001680010 and 0x9200000001680008, and returns the second address. The stored values are not shown, so the facts do not say whether the stores assert or clear a reset. The name points at a network-interface port reset in the hub register window, which the facts neither confirm nor rule out.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `mlreset` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xd7cc
  Role (from name): the machine-level reset path for the IP35 kernel. The facts list the calls by address, and they are not one path. It calls `r1nkperf_control_register_set` and `r1nkperf_data_register_set` with selectors 0 and 1 at 0xd7e0 to 0xd804, then `get_cpu_irr`. Two more pairs with selectors 2 and 3 (0xd864 to 0xd888) are reached when the branch at 0xd81c or 0xd834 is taken. When s3 (a copy of a0) is nonzero at 0xd83c, it calls `flush_tlb` and `flush_cache` and returns the `flush_cache` result at 0xd858. When s3 is zero it continues at 0xd898 with `get_nasid`, `set_master_bridge_base`, `ioc3_mlreset`, `ioc4_mlreset`, `l1_mlreset`, `nvram_baseinit` and `cpu_node_probe`, and then `mem_init`, `hubdev_init` and `intrgroup_init` among others. Three `assfail` calls (0xdc04, 0xdc20, 0xdc3c) sit on checks along the way. What each callee does is not in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `getcpuid` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xe718
  Role (from name): returns the caller's CPU id. It raises the interrupt level with `splhi`, maps the node from `get_nasid` and the slice doubleword at 0x9200000001000020 to a CPU info record through `nasid_slice_to_cpuinfo`, and restores the level with `splx`. It returns the halfword at +30 of that record, and a zero lookup result reaches `assfail` at 0xe77c. The meaning of the +30 field is not in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `save_cache_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12888
  Role (from name): saves cache-error state for the calling node. The facts do not show what is saved. It loads a doubleword from a table at 0x9000000034000000 and the doubleword at offset 0x48 of (0x9600000000000000 | 0x2000), and the branch at 0x128d4 compares an unresolved value with 0xc000 and goes to the `chk_for_pebrick` call when they are equal. It compares another value against 0x10 at 0x12938 among byte and word loads from unresolved addresses, and stores doublewords, a word and a byte to addresses the facts leave unresolved. `get_nasid` is called at entry, and `chk_for_pebrick` is called at 0x12a18 with a4 = 0xffffffffff.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

## IP35 hub error handling

- `hub_error_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x17950
  Role (from name): sets up hub error handling for one node. Several of these calls sit behind branches. It calls `hub_error_clear` first, with a nasid looked up in `compact_to_nasid_node`, then `hubii_eint_init` and `hubni_eint_init`. It calls `recover_error_init` four times, with a0 equal to a pointer loaded from the `kl_error_log` entry plus 8208, 8336, 8464 and 8592. It calls `kmem_zalloc_node` with sizes 0x2258 and 0x40, connects `hubpi_eint_handler` through `cause_intr_connect` (a0 = 6), and calls `spinlock_init` on `kl_error_log`. Three `assfail` calls and one `cmn_err` (level 0x14) are on other paths. The return at 0x17a4c is a doubleword loaded from -0x3c00 plus 34892, which the facts do not resolve further.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `hubpi_eint_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x181d0
  Role (from name): the handler for hub processor-interface errors. It calls `check_ni_errors` first and, when that returns nonzero, `hubni_error_handler` with a1 = 1. Under a sign test at 0x182f0 it calls `get_nasid`, passes the result to `log_md_errors`, and then calls `md_int_block`. `process_error_spool` is called three times, each under a mask test. It has 21 `cmn_err` call sites at levels 0x10, 0x12, 0x14 and 0x15, and one path calls `kl_panic_setup`. The format strings are not rendered, so the report contents are unknown.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `hubni_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x18ee4
  It is a short wrapper. It gets the node id from `get_nasid`, calls `hubni_error_handler_nasid` with its first argument, that node id and its second argument, and returns the result. The name suggests it handles network-interface errors for one node, which the facts fit but do not prove.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `klsave_spool_registers` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1994c
  It reads the doubleword at 0x9200000001000020 and calls `get_nasid` several times. It reads the per-node register block at 0x9600000000000000 offset by the node id, then finds the board and component records with `find_lboard` (argument 0x11) and `find_first_component` (argument 0x2). It writes six doublewords to addresses the facts leave unresolved, and it calls `chk_for_pebrick` on one path. The name suggests saving hub registers into the error spool, but the destinations are unresolved.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `err_int_unblock_mask` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1b980
  It reads the halfword at -0x3bd8 and uses it to index the per-processor table, then reads a byte at +0x528 of that entry. It stores to the register at 0x9200000001000400 (0x1b9b4), and loads and stores one of 0x9200000001000408 or 0x9200000001000410 (0x1b9bc, 0x1b9c8); the facts do not say which. The branch at 0x1b9a8 is taken when a1 == 0. The name suggests unblocking an error interrupt mask, but the bit changed and the stored values are not shown.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

## IP35 bus error handlers

- `handle_io_buserr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1cd5c
  Role (from name): handles an I/O bus error for the calling node. It calls `get_matching_spool_addr`, and its result is compared with 0, -1, 1 and 2 by the branches at 0x1cdc0 to 0x1cddc. `kl_ioerror_handler` is called at three sites (0x1ce58, 0x1cecc, 0x1cf88) with a3 = 5. `cmn_err_tag` is called with ids 0xb6c (0x1cf2c) and 0xb6d (0x1cf48). The return at 0x1ce00 is 1 or 2. The callee behaviour is not rendered, so the role rests on the names.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `handle_uncac_buserr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1cfac
  Role (from name): handles an error from an uncached access. It calls `get_matching_spool_addr`, then `nasid_to_partid` and `part_id`, and compares their results at 0x1d4d0. `cmn_err_tag` is called at seven sites with ids 0xb6f, 0xb79, 0xb72, 0xb6e, 0xb70, 0xb71 and 0xb73. `partition_handle_error` is called at 0x1d0e8 and 0x1d588 with a2 = 9, and `error_page_discard` and `error_check_part_page` are called in the block from 0x1d528 to 0x1d564. The return is 0, 2 or 3, or the result of `partition_handle_error` or `error_page_discard`. What each callee does is not rendered.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `handle_cac_buserr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1d8b0
  Role (from name): handles an error from a cached access. It calls `get_matching_spool_addr` first. Behind branches it calls `error_check_memory_access` (0x1da34), `error_check_poisoned_state` (0x1dd88), `memory_iscalias` (0x1e028) and `klerror_check_recoverable` (a0 = 3, 0x1e04c). `partition_handle_error` is called at 0x1da58, 0x1dd68, 0x1ddac and 0x1e194 with a2 = 6, 9, 5 and 2. There are eight `cmn_err_tag` call sites, and `kl_panic` is reached at 0x1d964 on one path. The facts give the call sites, not a single execution order, and what each callee decides rests on its name.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

## IP35 debug hooks

- `chkdebug` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20bb4
  It reads the halfword at -0x3bd8, uses it to index the per-processor table, and reads the byte at +0x528 of that entry. It loads the doubleword at 0x92000000010000a0 and ANDs it with an unresolved value at 0x20bec. When the result is nonzero it calls `dbgintr` (at 0x20884) with a0 = 0 and the caller's a1 to a3, and the return is that call's result or an unresolved value. The debug-enable reading comes from the name and the mask test, which the facts do not confirm.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `debug_stop_all_cpus` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20c74
  It loops over CPU numbers below `maxcpus`, calling `get_cpu_slice` at 0x20ca4 and `cpu_enabled` at 0x20d14, and it skips the caller by comparing the halfword at -0x3bd8 with the loop counter at 0x20d08. The store at 0x20cec goes to an address the facts leave unresolved. The stop mechanism is not in the facts, so the role rests on the name.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)
