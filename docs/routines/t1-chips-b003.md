# IP32 and IP35 routines read in batch 3

These are role statements for 25 routines from the IP32 and IP35 kernel objects and from two archive members of the chips binaries. Each statement comes from the rendered facts: the addresses a routine reads and writes, the calls it makes and its return value. Every grade is inferred, because no rendered fact settles a role by itself. Addresses use the 64-bit forms the facts use. `0xffffffffb4000000` is the uncached view of physical `0x14000000`, which `docs/coverage-crime.md` uses for CRIME. `-0x3bd8` appears to hold the processor number, since the lookup tables index by it, and `-0x5fe8` is a per-processor word I have not identified.

## IP32 probes

- `badaddr` at 0x14270 in `IP32/usr/cpu/sysgen/IP32boot/kernel.o`
  Probes one address with a 1, 2, 4 or 8 byte load chosen by the size in a1: `lb` at 0x142dc, `lh` at 0x142f4, `lw` at 0x1430c and `ld` at 0x14324 all read through a0. Any other size reaches the `cmn_err` call at 0x14338. The normal return at 0x143a0 gives v0 = 0, and the facts do not show how a faulting load is caught here, though the probe shape suggests it reports whether the address is readable. A mask test of the doubleword at 0xffffffffb4000028 at 0x14374 sends control to 0x149a8 when a bit is set, and that path is not rendered.
  Grade: inferred.

- `badaddr_val` at 0x143a8 in `IP32/usr/cpu/sysgen/IP32boot/kernel.o`
  It uses the same size dispatch as `badaddr`, but the loaded value is also stored through a2 at 0x1442c, 0x1444c, 0x1446c or 0x1448c, so the value is handed back to the caller. A store to the word at 0xffffffffffffa1d8 at 0x14414 sits on the path taken when the word at -0x5fe8 is zero, and the test at 0x14400 chooses that path. The normal return at 0x1451c gives v0 = 0, and an unrecognised size reaches `cmn_err` at 0x144a0.
  Grade: inferred.

- `wbadaddr` at 0x14524 in `IP32/usr/cpu/sysgen/IP32boot/kernel.o`
  It writes a value of the size in a1 to a0, using `sb` at 0x14590, `sh` at 0x145a8, `sw` at 0x145c0 or `sd` at 0x145d8, and an unrecognised size reaches `cmn_err` at 0x145ec. The facts do not name the register holding the stored value, so what gets written stays open. On the way out it reads the doubleword at 0xffffffffb4000008 and the word at 0xffffffffa0000000, which is the uncached start of physical memory, and returns v0 = 0 at 0x14680. The store-only shape suggests a write probe, but the fault handling is not rendered.
  Grade: inferred.

- `earlybadaddr` at 0x14808 in `IP32/usr/cpu/sysgen/IP32boot/kernel.o`
  It probes with 1, 2 or 4 byte loads chosen by a1 (`lb` at 0x14878, `lh` at 0x14890, `lw` at 0x148a8), and sizes 8 and anything else reach `cmn_err` at 0x148bc. It stores 4 bytes to the `nofault` symbol at 0x14868 and again at 0x14908, which suggests it arms and clears a fault catch around the access, though the handler is not rendered. The name suggests a probe used before normal memory setup, which the facts neither confirm nor rule out.
  Grade: inferred.

## IP32 meter records

- `_mraccess` at 0x35b8 in `IP32/usr/cpu/sysgen/IP32boot/ksync_metered.a(sema.o)`
  It calls `wchanmeter` with `mrinfolist` and branches on the nonzero return. A nonzero record goes to `_get_timestamp` and then `mrmeter_entry` with tag 5, and a zero return goes through `mr_access`. The record's words at +0x138 through +0x170 are read and updated, with an `ll`/`sc` pair on +0x138, and `mrmeter_getentry` is called with a value read from +356 of that record. The name suggests metering of an access to a wait channel, but the facts do not show what is counted or what tags 5 and 6 mean.
  Grade: inferred.

- `_mrupdate` at 0x36e0 in `IP32/usr/cpu/sysgen/IP32boot/ksync_metered.a(sema.o)`
  It makes the same `wchanmeter` call as `_mraccess` and branches on the nonzero return. That path calls `mr_update` at 0x3708 or goes to `_get_timestamp` and `mrmeter_entry` with tag 6. It stores into the record at +0x140 through +0x178, and a test on bit 0x4 at 0x3768 picks one of two branches, while the `lhu` and `sh` through an unresolved register are not identified.
  Grade: inferred.

## IP35 lock debug wrappers

- `bitlockdebug` at 0x1668 in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)`
  It reads the doubleword at 0x9200000001030100 twice and calls `try_bitlock` at 0x16cc with its own arguments. The `ll`/`sc` pairs on the words at a2+0xb8 and a2+0xbc update the lock record. A second path calls `splx`, makes an indirect call at 0x17e8 whose target is not resolved, retries `try_bitlock` at 0x17f8, and reports through `cmn_err` at 0x18bc with the doubleword at 0x9200000001030100 as an argument.
  Grade: inferred.

- `_64bitlockdebug` at 0x1f0c in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)`
  It has the same calls as `bitlockdebug`, with `try_64bitlock` at 0x1f70 and 0x209c in place of `try_bitlock`, `splx` at 0x2084, an indirect call at 0x208c, and a `cmn_err` report at 0x2160. The lock fields it updates are known only by their offsets from a2. The name suggests the 64-bit form of the debug lock acquire, which matches the call pattern.
  Grade: inferred.

- `_64bitunlockdebug` at 0x21d0 in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)`
  It compares the halfword at a2+0x2a with the processor number at -0x3bd8 (branch at 0x2208), and on a mismatch goes to 0x22a8. There the value at a2+0x40 is read and written back, and `cmn_err` at 0x22c0 reports it with one added. The match path updates fields at a2+0x48 through a2+0x80, and a second `cmn_err` at 0x22d8 reports another case. The name suggests the unlock side of the debug lock, but the facts do not show what the field offsets mean.
  Grade: inferred.

## IP35 hub and node helpers

- `get_nasid` at 0x12b4 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It reads one doubleword at the fixed address 0x9200000001600000 and returns it, and the return value is unresolved in the facts. Callers such as `getcpuid`, `hubpi_eint_handler` and `klsave_spool_registers` pass the result on as an argument to other node routines. The facts do not show the register at that address or how the value is decoded.
  Grade: inferred.

- `get_slice` at 0x12d0 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It loads the doubleword at 0x9200000001000020 and returns it unchanged. `getcpuid` passes the same doubleword as the second argument to `nasid_slice_to_cpuinfo`, which fits a slice number, but the value's layout is not shown. The facts establish the load and the return only.
  Grade: inferred.

- `ni_reset_port` at 0x13b4 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It stores two doublewords, at 0x9200000001680010 and 0x9200000001680008, and returns the second address. The stored values are not shown, so the facts do not say whether the stores assert or clear a reset. The name points at a network-interface port reset in the hub register window, which the facts neither confirm nor rule out.
  Grade: inferred.

- `mlreset` at 0xd7cc in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  This is the machine-level reset path for the IP35 kernel, and the name matches the call order. It resets the hub performance counters through `r1nkperf_control_register_set` and `r1nkperf_data_register_set`, flushes the TLB and the cache, probes the node and CPU layout, and then calls the subsystem initializers in order, including `mem_init`, `hubdev_init` and `intrgroup_init`. Three `assfail` calls guard checks along the way, and one return at 0xd858 passes back the result of `flush_cache`. The call order is established by the facts, but what each callee does is not.
  Grade: inferred.

- `getcpuid` at 0xe718 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  By its name it returns the caller's CPU id. It raises the interrupt level with `splhi`, maps the node from `get_nasid` and the slice doubleword at 0x9200000001000020 to a CPU info record through `nasid_slice_to_cpuinfo`, and restores the level with `splx`. It returns the halfword at +30 of that record, and a failed lookup reaches `assfail` at 0xe77c. The meaning of the +30 field is not in the facts.
  Grade: inferred.

- `save_cache_error` at 0x12888 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It saves cache-error state for the calling node. It reads a table at 0x9000000034000000, reads the doubleword at offset 0x48 of 0x9600000000000000 | 0x2000, and compares a counter against 0x10 while it runs byte and word loads. It stores doublewords to addresses the facts leave unresolved, and it calls `get_nasid` and then `chk_for_pebrick` with a mask of 0xffffffffff. The registers it saves are not shown, so the role rests on the name.
  Grade: inferred.

## IP35 hub error handling

- `hub_error_init` at 0x17950 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It sets up hub error handling for one node. It clears the node's hub errors with `hub_error_clear`, initializes the II and NI interrupt endpoints with `hubii_eint_init` and `hubni_eint_init`, and makes four `recover_error_init` calls on entries of the `kl_error_log` table at 8208, 8336, 8464 and 8592 bytes. It allocates storage with `kmem_zalloc_node` (sizes 0x2258 and 0x40), connects `hubpi_eint_handler` through `cause_intr_connect`, and initializes a spinlock. The return value is read from memory and is unresolved.
  Grade: inferred.

- `hubpi_eint_handler` at 0x181d0 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  By its name it is the handler for hub processor-interface errors. It checks network-interface errors through `check_ni_errors` and `hubni_error_handler`, logs metadata errors with `log_md_errors` on the node id from `get_nasid`, and masks the interrupt block with `md_int_block`. It drains the error spool with three `process_error_spool` calls, reports with many `cmn_err` calls at levels 0x10 through 0x15, and has a path through `kl_panic_setup`. The format strings are not rendered, so the report contents are unknown.
  Grade: inferred.

- `hubni_error_handler` at 0x18ee4 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It is a short wrapper. It gets the node id from `get_nasid`, calls `hubni_error_handler_nasid` with its first argument, that node id and its second argument, and returns the result. The name suggests it handles network-interface errors for one node, which the facts fit but do not prove.
  Grade: inferred.

- `klsave_spool_registers` at 0x1994c in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It reads the doubleword at 0x9200000001000020 and calls `get_nasid` several times. It reads the per-node register block at 0x9600000000000000 offset by the node id, then finds the board and component records with `find_lboard` (argument 0x11) and `find_first_component` (argument 0x2). It writes six doublewords to addresses the facts leave unresolved, and it calls `chk_for_pebrick` on one path. The name suggests saving hub registers into the error spool, but the destinations are unresolved.
  Grade: inferred.

- `err_int_unblock_mask` at 0x1b980 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It reads the halfword at -0x3bd8 and uses it to index the per-processor table, then reads a byte at +0x528 of that entry. It updates the registers at 0x9200000001000400 and at 0x9200000001000408 or 0x9200000001000410, with a branch at 0x1b9a8 on its argument being zero that the facts do not resolve. The name suggests unblocking an error interrupt mask, but the bit changed and the stored values are not shown.
  Grade: inferred.

## IP35 bus error handlers

- `handle_io_buserr` at 0x1cd5c in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It handles an I/O bus error for the calling node. It finds a matching spool entry with `get_matching_spool_addr`, dispatches to `kl_ioerror_handler` on up to three paths, and reports through `cmn_err_tag` with message IDs 0xb6c and 0xb6d. The return at 0x1ce00 is 1 or 2. The callee behaviour is not rendered, so the role rests on the names.
  Grade: inferred.

- `handle_uncac_buserr` at 0x1cfac in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It handles an error from an uncached access. It finds the matching spool entry with `get_matching_spool_addr`, looks up the partition with `nasid_to_partid` and `part_id`, and reports seven message IDs through `cmn_err_tag`. Partition-level errors go to `partition_handle_error` with argument 9, and page-level cases go to `error_page_discard` and `error_check_part_page`. The return is 0, 2 or 3, or a callee result.
  Grade: inferred.

- `handle_cac_buserr` at 0x1d8b0 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It handles an error from a cached access. It checks the memory access through `error_check_memory_access`, the poisoned state through `error_check_poisoned_state`, and aliasing through `memory_iscalias`, and asks `klerror_check_recoverable` whether the error can be recovered. It calls `partition_handle_error` at several points, reports through eight `cmn_err_tag` calls, and reaches `kl_panic` on one path. The order of these checks is what the facts establish; their meaning rests on the names.
  Grade: inferred.

## IP35 debug hooks

- `chkdebug` at 0x20bb4 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It reads the halfword at -0x3bd8, uses it to index the per-processor table, and reads the byte at +0x528 of that entry. It then tests the doubleword at 0x92000000010000a0 against a value, and when the test passes it calls the function pointer at 0x20884 (`dbgintr`) with a0 = 0 and the caller's a1 to a3. The debug-enable reading comes from the name and the mask test, which the facts do not confirm.
  Grade: inferred.

- `debug_stop_all_cpus` at 0x20c74 in `IP35/usr/cpu/sysgen/IP35boot/kernel.o`
  It loops over CPU numbers below `maxcpus`, checking each with `get_cpu_slice` and `cpu_enabled`, and it skips the caller by comparing against the processor number at -0x3bd8. Its per-CPU stores at 0x20cec go to addresses the facts leave unresolved. The stop mechanism is not in the facts, so the role rests on the name.
  Grade: inferred.
