# Tier-2 reading, round 3 batch 2 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: branches, loads and stores, calls and constants. Where a role is a guess from the routine's callees or name, the entry says so.

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** Reads a halfword from the fixed address 0xffffffffffffc420 and a per-CPU record reached through `pdaindr`. It stores to 0x9200000001000090, reads 0x9200000001000098, and calls `debug` at 0x206b4 with a string from `.rodata` (+32520) and the address 0x9200000001000090. It looks like a debug-interrupt hook that logs per-CPU state, but the facts do not settle what the fields mean.

- `bte_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21994
  **Inferred.** Takes a pointer to a per-device record. It reads a halfword at +0x10 of that record, and it reads a pointer at +0x8 and fields through it at offsets +0x40, +0x4c and +0x54. It takes the `splerr` spinlock around a table update (0x21a0c, 0x21a94), calls `hubiio_crb_error_handler` (0x219f0), and reports through `cmn_err` at 0x21b58 with level 0xc. A 16-bit code at +0x10 selects a branch chain, and the routine returns a code from 0x2 to 0x7. The facts do not show what each code means.

- `hub_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x229d8
  **Inferred.** Reads a word at +0xc of its first argument, stores it back at the same place, and calls `kern_free` (0x229ec) with all four argument registers unchanged. It returns what `kern_free` returns. The store writes the value it loaded, so the field's purpose is not settled.

- `hub_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a5c
  **Inferred.** Tests bit 0x2 of the word at +0xc of its first argument (branch at 0x22a74). On one path it calls `cmn_err` (0x22aa4) at level 4 with a format from `.rodata` (+34128) and the word at +0x0. It returns the second argument (0x22a88). The facts do not settle what the bit or the report means.

- `hub_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ab8
  **Inferred.** Has the same shape as `hub_dmamap_list`: it tests bit 0x2 of the word at +0xc (branch at 0x22ad0), updates that word (0x22ad8), and calls `cmn_err` at level 4 (0x22af8) on one path before returning. The facts do not settle what the bit or the report means.

- `hub_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e3c
  **Established.** Calls `do_hub_intr_alloc` (0x22e44) with its first three argument registers unchanged and the fourth set to zero, and returns that call's result.

- `hub_intr_disconnect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22f74
  **Inferred.** Reads a halfword at +0x24, a doubleword at +0x18 and a word at +0x28 of its first argument. It calls `intr_disconnect_level` (0x22f9c) with the halfword and the word at +0x28. If the doubleword at +0x18 is non-zero it calls an indirect target (0x22fc8). The word at +0x2c is written at 0x22fb8. The routine returns -5 at 0x22fc0. The facts do not name the indirect target.

- `hub_intr_cpu_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22fd8
  **Inferred.** Reads a halfword at +0x24 of its first argument, uses it as an index into the per-CPU records through `pdaindr` (shift by 4), and returns the word at offset 0x734 of the record found there. The facts show a per-CPU lookup but not what the returned value is.

- `hub_provider_startup` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ffc
  **Inferred.** Calls three initialisation routines in order: `hub_pio_init` (0x23008), `hub_dma_init` (0x23010) and `hub_intr_init` (0x23018). It passes its arguments to the first and the first argument to the other two, and returns the result of `hub_intr_init` (0x23028). The facts do not settle what the startup is for beyond these calls.

- `hub_provider_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23030
  **Established.** Calls `xtalk_provider_unregister` (0x23038) with its four argument registers unchanged and returns that call's result.

- `hub_check_is_widget0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2304c
  **Inferred.** Returns 0 or 1. It compares its first argument with the constant 0x9200000000000000 (unsigned branch at 0x23094), then tests the flags in two registers that the facts do not resolve (0x2309c, 0x230a4, 0x230ac). Returns 1 directly on one path at 0x230b8. The facts do not settle what the check decides.

- `hub_check_window_equiv` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x230c8
  **Inferred.** Calls `hub_check_is_widget0` (0x230d8) on its first argument set and again (0x230e8) on its second argument, and returns 0 or 1. Each result is tested with a branch (0x230e0, 0x230f0). A later comparison at 0x23114 compares two values the facts do not resolve.

- `hub_check_pci_equiv` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23130
  **Inferred.** Calls `hub_check_window_equiv` (0x23144) first and, if that passes, `check_nasid_equiv` (0x2319c) with its third argument set to zero. It returns 0 or the result of `check_nasid_equiv`. The facts do not settle what the two checks mean.

- `hub_device_flags_set` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23388
  **Inferred.** Looks up widget info with `xwidget_info_get` (0x23394), then the widget's id and master through `xwidget_info_id_get` (0x233a0) and `xwidget_info_master_get` (0x233ac). It reports through `hwgraph_info_get_LBL` (0x233c0). It calls `hub_widget_flags_set` (0x233ec) inside a `mutex_spinlock` / `mutex_spinunlock` pair (0x233d0, 0x23400) and returns that call's result.

- `hub_device_inquiry` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2341c
  **Inferred.** Builds a string with `sprintf` (0x2343c), walks the hardware graph with `hwgraph_traverse` (0x2344c), and looks up a device master with `device_master_get` (0x23468). It reads a label with `hwgraph_info_get_LBL` (0x23484). It reports findings through `cmn_err` at level 6 at several points (0x234cc to 0x235b4). A loop tests bits of a counter against 8 and walks a mask. The facts do not name what the bits represent.

- `hub_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23d60
  **Inferred.** Calls `get_my_slotid` (0x23d68) with its four argument registers unchanged and returns what it leaves in v0. The rendered return value is unresolved, so the facts show a slot lookup but not the value it returns.

- `llp_pfail_barrier` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x25078
  **Inferred.** Works on two counters in `p_routertick` (+0xa4 and +0xa8) with load-linked and store-conditional loops (0x250a4, 0x25144). A loop compares a count against the constant 0x7a120 (unsigned, branch at 0x25138). It reports through `cmn_err` at level 4 (0x251d8), passing the CPU count and the constant 0x3e8. That pattern suggests a bounded wait across CPUs that reports when it expires, but the facts do not settle it.

- `llp_pfail_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4
  **Inferred.** Handles a link power-fail interrupt. It takes ownership through `msc_owner_cpu` (0x25304), calls `llp_pfail_barrier` (0x25344), and makes repeated `vector_read` / `vector_write` calls with fixed offsets such as 0x600110, 0x30 and 0x8 (0x2532c to 0x255a0). It inserts microsecond waits of 100 and 300 through `us_delay`. It tests bit 0x2000000000 of the doubleword at 0x9200000001608088 on several paths. The facts do not say which hardware bits or vectors these are.

- `syssgi_pfshow` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x256b8
  **Inferred.** Prints a diagnostic report with `printf` (0x256cc to 0x25878) and reads state through `vector_read` at 0x256ec and 0x257c4 (offset values 0 and 6). It prints a doubleword from 0x9200000001600000 (0x25860) and reads a halfword from the hub-local address 0xffffffffffffc420 at 0x256c4; the facts do not say what that halfword is. Its name suggests a shell or system-call view of the same power-fail state that `llp_pfail_intr` handles. The facts do not confirm the caller.

- `sysctlr_keepalive` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2686c
  **Inferred.** Runs a periodic heartbeat gated by the global `heartbeat_enable`. It sends heartbeats with `_elsc_hbt` (0x26914, 0x26978, 0x2699c), with arguments 0x1e and 0x14 at one call site, and it takes a spinlock at spl7 (0x268fc) around its state. It reports failures through `cmn_err` (0x26a04 to 0x26ac4) and `elsc_errmsg` (0x26a3c). The facts show the heartbeat path but not what the remote end is.

- `hub_xtalk_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x29e20
  **Inferred.** Loads a doubleword from an address computed from its first argument and returns 0 or 1 according to bit 0x2000 of that value (branch at 0x29e34). The facts do not show what the bit signifies.

- `capture_hub_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a01c
  **Inferred.** Copies per-node hub counters into a statistics block passed as its second argument (fields at +0x4ca8 to +0x4d18), indexed through `compact_to_nasid_node`. It reports errors through `hubni_error_handler` (0x2a0e8) and `check_hub_error_rates` (0x2a140). A test of the byte at +0x4d00 and a counter compared with `hub_print_usecs` (0x2a190) controls the path. The facts do not settle which counters these are.

- `init_hub_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a1c0
  **Inferred.** Clears a 0x80-byte block at +19608 of its second argument with `bzero` (0x2a1f0), then fills several fields, one of them a halfword taken from `compact_to_nasid_node`. It allocates a 0x50-byte block with `kmem_alloc_node` (0x2a25c). If that succeeds, it loops over slots, calling `get_slotname` (0x2a274) and `sprintf` (0x2a28c) to build a name for each. A constant 0x116 is passed to `assfail` (0x2a2c4). The facts do not settle the meaning of the stored fields.

- `bootstrap` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a5b8
  **Inferred.** Early boot code. It reads a doubleword at 0x9200000001600000 (0x2a5e4) and two halfwords, calls `mapped_kernel_setup_tlb` (0x2a60c) with its last two argument registers unchanged, and then jumps through a relocated pointer (`jr` at 0x2a62c). The facts do not name the jump target. The instructions from 0x2a634 to 0x2a684 are not reached from the entry.

- `nmi_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a730
  **Inferred.** Handles a non-maskable interrupt dump. An atomic add on a counter (`atomicAddInt`, 0x2a744) decides whether the CPU continues to `cont_nmi_dump` (0x2a780). A loop calls `tlbgetent` (0x2a7e4) for TLB indices up to 0x40, and the CPU whose id matches `nmi_helper_cpu` calls `dumpsys_helper` (0x2a85c). The facts show the sequence but not its full protocol.
