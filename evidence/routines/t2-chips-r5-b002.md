# Reading round 5, batch 2 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: loads and stores, calls, branches and return values. Every role here is inferred. Where the facts leave the meaning open, the entry says so.

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** Role (from name): it arms the hub error counter on a timer. It loads a halfword at 0x1c0e8 [@0x1c0e8] and a doubleword from the error log at 0x1c100 [@0x1c100]. A negative a0 takes the branch at 0x1c0d0 to 0x1c120 [@0x1c0d0 taken]. When the word tested at 0x1c10c is zero, the branch goes to 0x1c130 [@0x1c10c taken zero], where it calls `bzero` [call 1, @0x1c130] and then `timeout` at 0x1c150 [call 2, @0x1c150], and it stores a word at 0x1c154 [@0x1c154] in the delay slot of that call. Its return at 0x1c118 has v0 one of -0x1, 0x0 [@0x1c118]. The facts do not show which counter it arms or how often the timer fires.
  Reviewed: 2026-11-12

- `err_int_unblock_mask` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c4c8
  **Inferred.** Role (from name): it clears a mask so that error interrupts can be delivered again. A zero a1 takes the branch at 0x1c4e0 to 0x1c4f0 [@0x1c4e0 taken zero], skipping the doubleword store to the fixed address 0x9200000001000400 at 0x1c4ec [@0x1c4ec], which runs only when a1 is nonzero. On both paths it loads a doubleword at 0x1c504 [@0x1c504] and stores a doubleword at 0x1c510 [@0x1c510] at the same address, one built from the byte loaded at 0x1c4dc [@0x1c4dc] and the base 0x9200000001000000. Its return at 0x1c50c returns an unknown value [@0x1c50c]. The facts do not show what value reaches the register, so the meaning of the mask is open.
  Reviewed: 2026-11-12

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** Role (from name): it decides whether a logged hub error can be recovered from. It calls `klerror_global_check` at 0x1c678 [call 1, @0x1c670 fall nonzero] and `error_check_part_page` at 0x1c708 [@0x1c708]. It loads a doubleword from 0x9200000001030100 at 0x1c6b0 [@0x1c6b0]. When the register tested at 0x1c624 is zero, the branch goes to 0x1c744 [@0x1c624 taken zero]. It calls `cmn_err_tag` at 0x1c758 [@0x1c758]. It calls `assfail` at 0x1c76c [call 4, @0x1c63c taken zero]. Its return at 0x1c69c has v0 one of -0x1, 0x0 [@0x1c69c]. The facts do not show what the threshold comparisons in the error record select.
  Reviewed: 2026-11-12

- `handle_io_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d5cc
  **Inferred.** Role (from name): it handles an I/O bus error reported through the hub. It calls `get_matching_spool_addr` at 0x1d628 [@0x1d628]. When that call returns zero, the branch at 0x1d630 goes to 0x1d70c [@0x1d630 taken zero]. It calls `kl_ioerror_handler` three times, at 0x1d6c8 [call 2, @0x1d6c8], 0x1d73c [call 3, @0x1d630 taken zero] and 0x1d7f4 [call 6, @0x1d7f4]. It loads a doubleword at offset 0x110 of a0 [@0x1d6b8]. Its return at 0x1d670 has v0 one of 0x1, 0x2 [@0x1d670]. The facts do not show which error class each of these paths handles.
  Reviewed: 2026-11-12

- `handle_uncac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1d818
  **Inferred.** Role (from name): it handles an uncached bus error on the hub. It calls `get_matching_spool_addr` at 0x1d84c [@0x1d84c]. When the result is zero, the branch at 0x1d854 goes to 0x1d934 [@0x1d854 taken zero]. It calls `partition_handle_error` at 0x1d924 [@0x1d924] and `error_page_discard` at 0x1db94 [@0x1db94]. It calls `error_check_poisoned_state` at 0x1dc34 [@0x1dc34]. Its return at 0x1d8d4 gives one of several values [@0x1d8d4]. The facts do not show what each error code means.
  Reviewed: 2026-11-12

- `handle_cac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1dcd0
  **Inferred.** Role (from name): it handles a cached bus error. It calls `get_matching_spool_addr` at 0x1dd08 [@0x1dd08]. When that result is zero, the branch at 0x1dd24 goes to 0x1de44 [@0x1dd24 taken zero]. A nonzero a1 takes the branch at 0x1dd40 to 0x1ddb4 [@0x1dd40 taken nonzero], where it calls `kl_panic` [@0x1ddb4]. It calls `partition_handle_error` at 0x1de34 [@0x1de34] and `error_page_discard` at 0x1df78 [@0x1df78]. It loads a doubleword from the fixed address 0x9200000001000018 [@0x1de60]. Its return at 0x1ddac gives one of several values [@0x1ddac]. The facts do not show which of these paths a cached error takes.
  Reviewed: 2026-11-12

- `intr_disconnect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f508
  **Inferred.** Role (from name): it removes a handler from an interrupt level. It calls `intr_get_ptrs` at 0x1f52c [@0x1f52c], then `mutex_spinlock_spl` at 0x1f540 [@0x1f540], and releases the lock with `mutex_spinunlock` at 0x1f578 [@0x1f578]. The branch at 0x1f570 goes to 0x1f594 when a2 equals 3 [@0x1f570 taken], and only that path loads the `pdaindr` doubleword at 0x1f638 [@0x1f638]; both paths reach the unlock at 0x1f578. Its return at 0x1f58c has v0 one of -0x1, 0x0 [@0x1f58c]. The facts do not show which handler slot is cleared.
  Reviewed: 2026-11-12

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** Role (from name): it services pending hub interrupts. It loads a doubleword from 0x9200000001000098 [@0x1ff2c] and stores a word through a pointer at offset 0xd0 [@0x1ff80]. Its return at 0x2004c returns either the doubleword at 0x9200000001000098 or an unknown value [@0x2004c]. The facts do not show which bits the tests at 0x1ff4c and 0x20014 select.
  Reviewed: 2026-11-12

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** Role (from name): it is the debug interrupt entry, and it passes control to the debugger. It stores a doubleword to 0x9200000001000090 [@0x206ac] and loads one from 0x9200000001000098 [@0x206b8]. It calls `debug` at 0x206b4 [@0x206b4]. Its return at 0x206c0 returns the value that `debug` returns [@0x206c0]. The facts do not show what the debugger does with the stored value.
  Reviewed: 2026-11-12

- `hub_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23d60
  **Inferred.** Role (from name): it returns the slot number of the current hub. It calls `get_my_slotid` at 0x23d68 [@0x23d68]. Its return at 0x23d7c returns a value the facts leave unknown [@0x23d7c], so whether that value is the slot `get_my_slotid` returns is open.
  Reviewed: 2026-11-12

- `llp_pfail_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4
  **Inferred.** Role (from name): it handles a power-fail interrupt on the link layer. It loads doublewords from 0x9200000001608088 [@0x25390]. The branch at 0x2530c goes back to 0x252dc when the value in s1 differs from the result of `msc_owner_cpu` [@0x2530c taken]. It stores a doubleword to 0x9200000001600110 [@0x25488] and to 0x9200000001600008 [@0x25498]. Its return at 0x25400 returns what `us_delay` returns [@0x25400]. The facts do not show what the link registers hold, so the meaning of each write is open.
  Reviewed: 2026-11-12

- `syssgi_pfshow` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x256b8
  **Inferred.** Role (from name): it prints the power-fail state for a system call selector. It calls `printf` at nine sites, the first at 0x256cc [call 1, @0x256cc] and the last at 0x25878 [call 11, @0x25878], with `vector_read` calls between them. It loads a doubleword from 0x9200000001600000 [@0x25858] and passes it to the `printf` at 0x25860 [call 10, @0x25860]. Its return at 0x25894 returns the result of `printf` [@0x25894]. The facts do not show which fields the printed values come from.
  Reviewed: 2026-11-12

- `nmi_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a730
  **Inferred.** Role (from name): it dumps machine state on a non-maskable interrupt. It loads a doubleword from the fixed address 0xffffffffffffc400 [@0x2a738]. It calls `atomicAddInt` at 0x2a744 [@0x2a744]. When that result is not 1, the branch at 0x2a750 goes to 0x2a790 [@0x2a750 taken]. It stores a word at 0x2a7c8 [@0x2a7c8]. The facts do not show which CPU the dump is for, beyond the comparison at 0x2a81c.
  Reviewed: 2026-11-12

- `set_timer_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d4c8
  **Inferred.** Role (from name): it arms the timer interrupt for a CPU or node. It calls `timepoke` at 0x2d594 [@0x2d594] and `cpuaction` at 0x2d5b0 [@0x2d5b0]. When the flag byte is zero, the branch at 0x2d508 goes to 0x2d574 [@0x2d508 taken zero]. It loads a doubleword from 0x9200000001030100 at 0x2d4e4 [@0x2d4e4] and stores a doubleword at 0x2d510 [@0x2d510]. Its return at 0x2d550 has v0 one of 0x0, 0x1 [@0x2d550]. Both stores write the value in a1, so the timer value is whatever the caller passes in a1, which the facts do not show.
  Reviewed: 2026-11-12

- `callout_time_to_hz` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2da70
  **Inferred.** Role (from name): it converts a callout time into a tick count. The facts show one doubleword load from 0x9200000001030100 [@0x2da74] and an unknown return value [@0x2da98]. The facts show no conversion, so the role is only the name's suggestion and the unit is open.
  Reviewed: 2026-11-12

- `get_realtime_ticks` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e828
  **Inferred.** Role (from name): it reads the real-time count. It loads a doubleword from the fixed address 0x9200000001030100 [@0x2e830] and returns an unknown value [@0x2e848]. The facts show neither a conversion nor a unit for the count, so the unit is open.
  Reviewed: 2026-11-12

- `tvtoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e89c
  **Inferred.** Role (from name): it converts a time value with seconds and microseconds fields into clock ticks. It loads a word at offset 0x4 of a0 [@0x2e89c] and a doubleword at offset 0x8 of a0 [@0x2e8ac]. It loads a doubleword from 0x9200000001030100 [@0x2e8f0]. The branch at 0x2e8dc goes to 0x2e8ec when a1 equals 1 [@0x2e8dc taken]. Its returns at 0x2e8e4 and 0x2e8f4 both give unknown values [@0x2e8e4] [@0x2e8f4]. The facts do not show how the count is computed.
  Reviewed: 2026-11-12

- `us_delay` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea8c
  **Inferred.** Role (from name): it busy-waits for a number of microseconds. It loads a doubleword from 0x9200000001030100 at 0x2ead8 [@0x2ead8]. The branch at 0x2ead0 leaves for the return at 0x2eb28 when the value has reached a3 (unsigned) [@0x2ead0 taken]. The branch at 0x2eb20 goes back to 0x2ead8 while the value is below a3 (unsigned) [@0x2eb20 taken], so the routine loops on the hub timer. Its return at 0x2eb28 gives an unknown value [@0x2eb28]. The facts do not show what a3 holds at entry.
  Reviewed: 2026-11-12

- `hub_rtc_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f378
  **Inferred.** Role (from name): it sets up the real-time clock registers for a node. It calls `get_compact_nodeid` at 0x2f384 [@0x2f384]. The branch at 0x2f38c goes to 0x2f3c4 when the node id differs from the result [@0x2f38c taken]. It loads a halfword through `compact_to_nasid_node` at 0x2f3a0 [@0x2f3a0]. It stores doublewords at 0x2f3b4 [@0x2f3b4], 0x2f3b8 [@0x2f3b8], 0x2f3bc [@0x2f3bc] and 0x2f3c0 [@0x2f3c0]. Its return at 0x2f3c8 returns either the result of `get_compact_nodeid` or 1 [@0x2f3c8]. The facts do not show what the registers at those addresses do.
  Reviewed: 2026-11-12

- `ackkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408
  **Inferred.** Role (from name): it acknowledges a clock interrupt for the current CPU. It loads a halfword from the fixed address 0xffffffffffffc420 [@0x2f408]. It stores doublewords to 0x9200000001000138 [@0x2f42c] and to 0x9200000001000130 [@0x2f43c]. When a byte flag is zero, the branch at 0x2f424 goes to 0x2f438 [@0x2f424 taken zero]. Both returns, at 0x2f430 and 0x2f438, give the same halfword value at -0x3be0 shifted left 4 bits [@0x2f430] [@0x2f438]. The facts do not show what the registers at those addresses do.
  Reviewed: 2026-11-12

- `prof_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x301e0
  **Inferred.** Role (from name): it handles the profiling clock interrupt. It calls `fastick_maint` at 0x301f8 [@0x301f8]. It stores a doubleword to 0x9200000001000118 [@0x3029c]. When the masked bit tested at 0x301f0 is set, the branch goes to 0x302a0 [@0x301f0 taken nonzero]. Its return at 0x30224 gives an unknown value or the result of `log_tstamp_event` [@0x30224].
  Reviewed: 2026-11-12

- `mdir_xlate_addr_mem` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x307f4
  **Inferred.** Role (from name): it formats a memory address for a directory translation message. It loads a doubleword from 0x9200000001200018 [@0x30810] and a word from 0x9000000010000090 [@0x3081c]. When the value at 0x9000000010000090 is zero, the branch at 0x30834 goes to 0x308ac [@0x30834 taken zero]. Its return at 0x3089c gives the result of `sprintf` [@0x3089c].
  Reviewed: 2026-11-12

- `hubdev_prombase_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x33050
  **Inferred.** Role (from name): it returns the PROM base address for a hub device. It calls `hwgraph_info_get_LBL` at 0x33064 [@0x33064]. It loads a halfword at displacement 0xa from a base the facts do not resolve [@0x33074]. Its return at 0x33084 gives v0 as 0x9000000030000000 plus a variable term [@0x33084], an address sum and not a load from that address. The facts do not show how the label lookup selects that entry.
  Reviewed: 2026-11-12

- `hubdev_cnodeid_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3308c
  **Inferred.** Role (from name): it returns the compact node id for a hub device. It calls `hwgraph_info_get_LBL` at 0x330a0 [@0x330a0] and loads a halfword from an address the facts do not show [@0x330b0]. Its return at 0x330b4 gives an unknown value [@0x330b4]. The facts do not show how the label result becomes a node id.
  Reviewed: 2026-11-12

- `eccf_recoverable_threshold` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3ce18
  **Inferred.** Role (from name): it sets the threshold for recoverable ECC faults. It loads a doubleword from 0x9200000001030100 [@0x3ce48] and loads doublewords from offset 0x2c0 of a1 [@0x3ce70]. When the value at offset 0x2c0 of a1 is zero, the branch at 0x3ce78 goes to 0x3ceac [@0x3ce78 taken zero]. It stores a halfword at one of the offsets 0x2c8, 0x2ca, 0x2cc or 0x2ce of a1 [@0x3ce9c], and stores a doubleword at offset 0x2c0 of a1 [@0x3ceac]. Its return at 0x3cea4 has v0 one of 0x0, 0x1 [@0x3cea4], and its return at 0x3ceb4 has v0 = 0x1 [@0x3ceb4].
  Reviewed: 2026-11-12
