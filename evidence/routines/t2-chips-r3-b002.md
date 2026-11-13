# Tier-2 reading, round 3 batch 2 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: branches, loads and stores, calls and constants. Where a role is a guess from the routine's callees or name, the entry says so.

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** Reads a halfword from the fixed address 0xffffffffffffc420 (0x2067c) and a per-CPU record reached through `pdaindr`. It calls `debug` at 0x206b4 with a string from `.rodata` (+32520) and the address 0x9200000001000090 as its third argument. It also stores a doubleword at 0x206ac and loads one at 0x206b8, but the facts do not show the addresses of that store and load. It returns the result of `debug`. Role (from name): a debug-interrupt hook. The facts do not settle what the fields mean.
  Reviewed: 2026-11-12

- `bte_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21994
  **Inferred.** Takes a pointer to a per-device record. It reads a halfword at +0x10 of that record, and reads a pointer at +0x8 and fields through it at offsets +0x40, +0x4c and +0x54 (it also stores a word at +0x4c at 0x219ac). It calls `hubiio_crb_error_handler` (0x219f0), and brackets some stores (0x21a4c to 0x21a8c) with `mutex_spinlock_spl` (0x21a0c) and `mutex_spinunlock` (0x21a94); `splerr` is the second argument of the lock call, and the facts do not resolve its first argument. A 16-bit code at +0x10 selects a branch chain, and one path reports through `cmn_err` at 0x21b58 with level 0xc. The routine returns a code from 0x2 to 0x7. The facts do not show what each code means.
  Reviewed: 2026-11-12

- `hub_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x229d8
  **Inferred.** Reads a word at +0xc of its first argument (0x229dc) and calls `kern_free` (0x229ec) with all four argument registers unchanged. It stores a word at +0xc at 0x229f0; the facts do not show the stored value. It returns what `kern_free` returns. The facts do not settle the field's purpose.
  Reviewed: 2026-11-12

- `hub_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a5c
  **Inferred.** Tests bit 0x2 of the word at +0xc of its first argument (branch at 0x22a74). On one path it calls `cmn_err` (0x22aa4) at level 4 with a format from `.rodata` (+34128) and the word at +0x0. It returns the second argument (0x22a88). The facts do not settle what the bit or the report means.
  Reviewed: 2026-11-12

- `hub_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ab8
  **Inferred.** Resembles `hub_dmamap_list` in part: it tests bit 0x2 of the word at +0xc (branch at 0x22ad0), stores a word at +0xc (0x22ad8), and calls `cmn_err` at level 4 (0x22af8) on one path. One return (0x22adc) is either an unresolved value or the `cmn_err` result. Unlike `hub_dmamap_list`, the facts show no return of the second argument. The facts do not settle what the bit or the report means.
  Reviewed: 2026-11-12

- `hub_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e3c
  **Established.** Calls `do_hub_intr_alloc` (0x22e44) with its first three argument registers unchanged and the fourth set to zero, and returns that call's result.
  Reviewed: 2026-11-12

- `hub_intr_disconnect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22f74
  **Inferred.** Reads a halfword at +0x24, a doubleword at +0x18 and a word at +0x28 of its first argument. If the doubleword at +0x18 is non-zero, it branches (0x22f94) to an indirect call (0x22fc8) whose target the facts do not name. Otherwise it calls `intr_disconnect_level` (0x22f9c) with the halfword and the word at +0x28, loads and stores the word at +0x2c (0x22fa4, 0x22fb8) and returns -5 at 0x22fc0. The facts do not settle what the fields mean.
  Reviewed: 2026-11-12

- `hub_intr_cpu_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22fd8
  **Inferred.** Reads a halfword at +0x24 of its first argument, uses it as an index into the per-CPU records through `pdaindr` (shift by 4), and returns the word at offset 0x734 of the record found there. The facts show a per-CPU lookup but not what the returned value is.
  Reviewed: 2026-11-12

- `hub_provider_startup` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ffc
  **Inferred.** Calls three initialisation routines in order: `hub_pio_init` (0x23008), `hub_dma_init` (0x23010) and `hub_intr_init` (0x23018). It passes its arguments to the first and the first argument to the other two, and returns the result of `hub_intr_init` (0x23028). The facts do not settle what the startup is for beyond these calls.
  Reviewed: 2026-11-12

- `hub_provider_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23030
  **Established.** Calls `xtalk_provider_unregister` (0x23038) with its four argument registers unchanged and returns that call's result.
  Reviewed: 2026-11-12

- `hub_check_is_widget0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2304c
  **Inferred.** Returns 0 or 1. It compares its first argument with the constant 0x9200000000000000 (unsigned branch at 0x23094), then branches on three registers that the facts do not resolve (0x2309c, 0x230a4, 0x230ac). It returns 1 directly on one path at 0x230b8 and one of 0 or 1 at 0x230c0. The facts do not settle what the check decides.
  Reviewed: 2026-11-12

- `hub_check_window_equiv` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x230c8
  **Inferred.** Calls `hub_check_is_widget0` (0x230d8) with its argument registers unchanged and branches on the result (0x230e0). Only when that result is non-zero does it call `hub_check_is_widget0` again (0x230e8) with its second argument, and it branches on that result (0x230f0). It returns 0 or 1. A later comparison at 0x23114 compares two values the facts do not resolve.
  Reviewed: 2026-11-12

- `hub_check_pci_equiv` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23130
  **Inferred.** Calls `hub_check_window_equiv` (0x23144) and branches on its result at 0x2314c (zero goes to the return at 0x231ac). Another branch at 0x23164 compares two values the facts do not resolve. `check_nasid_equiv` is called at 0x2319c with its third argument set to zero. The routine returns 0 or the result of `check_nasid_equiv`. The facts do not settle what the checks mean.
  Reviewed: 2026-11-12

- `hub_device_flags_set` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23388
  **Inferred.** Looks up widget info with `xwidget_info_get` (0x23394), then the widget's id and master through `xwidget_info_id_get` (0x233a0) and `xwidget_info_master_get` (0x233ac). It calls `hwgraph_info_get_LBL` (0x233c0) with the master result and a `.rodata` string (+34128). It calls `hub_widget_flags_set` (0x233ec) with its second argument as the third, between `mutex_spinlock` (0x233d0) and `mutex_spinunlock` (0x23400), and returns that call's result.
  Reviewed: 2026-11-12

- `hub_device_inquiry` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2341c
  **Inferred.** Builds a string with `sprintf` (0x2343c), calls `hwgraph_traverse` (0x2344c) on it, and looks up a device master with `device_master_get` (0x23468). It calls `hwgraph_info_get_LBL` (0x23484) on the result. It makes six `cmn_err` calls at level 6 (0x234cc to 0x235b4). A backward branch at 0x2352c tests a register against 8, and later branches test it against masks (0x23570, 0x2359c). The facts do not resolve those registers or say what the bits represent.
  Reviewed: 2026-11-12

- `hub_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23d60
  **Inferred.** Calls `get_my_slotid` (0x23d68) with its four argument registers unchanged and returns at 0x23d7c with a value the facts do not resolve, so they do not show whether the call's result is returned as is. Role (from name): a slot lookup.
  Reviewed: 2026-11-12

- `llp_pfail_barrier` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x25078
  **Inferred.** Works on two words in `.sbss` (+0xa4 and +0xa8) with load-linked and store-conditional loops (0x250a4, 0x25144). A loop compares a count against the constant 0x7a120 (unsigned, branch at 0x25138). It reports through `cmn_err` at level 4 (0x251d8), passing the CPU count (`numcpus`) and the constant 0x3e8. That pattern suggests a bounded wait across CPUs that reports when it expires, but the facts do not settle it.
  Reviewed: 2026-11-12

- `llp_pfail_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4
  **Inferred.** Role (from name): a link power-fail interrupt handler. It calls `msc_owner_cpu` (0x25304) and compares the result with a halfword loaded from 0xffffffffffffc420, calls `llp_pfail_barrier` (0x25344), and makes repeated `vector_read` / `vector_write` calls with fixed offsets such as 0x600110, 0x30 and 0x8 (0x2532c to 0x255a0). It calls `us_delay` with 100 and 300 (0x64 and 0x12c). It tests bit 0x2000000000 of the doubleword at 0x9200000001608088 in a loop (0x253a8 to 0x253f8). The facts do not say which hardware bits or vectors these are.
  Reviewed: 2026-11-12

- `syssgi_pfshow` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x256b8
  **Inferred.** Prints through `printf` (0x256cc to 0x25878) and calls `vector_read` at 0x256ec and 0x257c4 (first arguments 0 and 6). It passes a doubleword loaded from 0x9200000001600000 to `printf` (0x25860) and reads a halfword from 0xffffffffffffc420 at 0x256c4; the facts do not say what that halfword is. It returns the result of `printf`. Role (from name): a view of power-fail state. The facts do not link it to `llp_pfail_intr` and do not show the caller.
  Reviewed: 2026-11-12

- `sysctlr_keepalive` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2686c
  **Inferred.** Branches on the global `heartbeat_enable` (0x268bc). It calls `_elsc_hbt` (0x26914, 0x26978, 0x2699c), with arguments 0x1e and 0x14 at the first call site and 0, 0 and 0, 1 at the others, and calls `mutex_spinlock_spl` (0x268fc) with `spl7` as its second argument and `mutex_spinunlock` (0x26930). It calls `cmn_err` (0x26a04 to 0x26ac4) at several sites and `elsc_errmsg` (0x26a3c), whose result is passed to one `cmn_err` call. The facts show the heartbeat calls but not what the remote end is.
  Reviewed: 2026-11-12

- `hub_xtalk_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29e20
  **Inferred.** Loads a doubleword from an address computed from its first argument and returns 0 or 1 according to bit 0x2000 of that value (branch at 0x29e34). The facts do not show what the bit signifies.
  Reviewed: 2026-11-12

- `capture_hub_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a01c
  **Inferred.** Loads and stores a set of doublewords and words in a block passed as its second argument (stores at +0x4ca8 to +0x4d18), with one address indexed through `compact_to_nasid_node`. It calls `hubni_error_handler` (0x2a0e8) and `check_hub_error_rates` (0x2a140). A branch on the byte at +0x4d00 (0x2a138) and a comparison with `hub_print_usecs` (0x2a190) steer the path. The facts do not settle which counters these are.
  Reviewed: 2026-11-12

- `init_hub_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a1c0
  **Inferred.** Clears a 0x80-byte block at +19608 of its second argument with `bzero` (0x2a1f0), then stores several fields. It allocates a 0x50-byte block with `kmem_alloc_node` (0x2a25c) and, if the result is non-zero, calls `get_slotname` (0x2a274) and `sprintf` (0x2a28c) and returns the `sprintf` result at 0x2a2b0. The facts show no loop. A constant 0x116 is passed to `assfail` (0x2a2c4). The facts do not settle the meaning of the stored fields.
  Reviewed: 2026-11-12

- `bootstrap` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a5b8
  **Inferred.** Role (from name): early boot code. It loads a doubleword (0x2a5e4) and two halfwords (0x2a604, 0x2a608), calls `mapped_kernel_setup_tlb` (0x2a60c) with its last two argument registers unchanged, and ends with a tail jump to `.text`+173620 (0x2a62c). The facts do not say what is at that target.
  Reviewed: 2026-11-12

- `nmi_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a730
  **Inferred.** Role (from name): a non-maskable interrupt dump. An atomic add on a counter (`atomicAddInt`, 0x2a744) is compared with 1 (0x2a750); on the equal path the code calls `cont_nmi_dump` (0x2a780). A loop calls `tlbgetent` (0x2a7e4) until a value equals 0x40 (0x2a7f4). A branch at 0x2a81c loops back while the CPU id differs from `nmi_helper_cpu`, and `dumpsys_helper` is called at 0x2a85c with the CPU id and `nmi_helper_cpu`. The facts show the sequence but not its full protocol.
  Reviewed: 2026-11-12
