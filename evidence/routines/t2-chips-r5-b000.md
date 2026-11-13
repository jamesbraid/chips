# Tier-2 reading, batch 0 of round r5 of chips: routine role entries

Each entry names a routine in an IP27 boot-set object or kernel and its address. The statements come only from the rendered instruction facts: addresses, loads and stores, calls and constants. Every entry is inferred. Where the facts leave something open, the entry says so.

- `get_myid` in `IP27/usr/cpu/sysgen/IP27boot/elsc.o` at 0x0
  **Inferred.** Role (from facts): returns the doubleword at the fixed address 0x9200000001000020 [@0x4] as its result [@0x8].
  Reviewed: 2026-11-12

- `ftrc_event` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xf630
  **Inferred.** Role (from facts): when the flag ftrc_initialized is zero it first calls ftrc_init with its four arguments [call 3, @0xf660 taken zero] and then carries on with the checks below. When the flag is nonzero [@0xf660 fall nonzero] it goes straight to them. It returns -1 without logging when a0 is zero [@0xf668 taken zero], when a2 is zero [@0xf670 taken zero], or when the pointer loaded from [a0+16] is zero [@0xf67c taken zero]. It then takes mutex_spinlock on the word at [a0+16]+64 [call 1], advances the doubleword at offset 0x30 of the record at [a0+16] [@0xf6ac] and releases the lock with mutex_spinunlock at 0xf6d8 [call 2]. When the advanced value is not below the doubleword at offset 0x28 [@0xf6b8 fall] it reloads offset 0x30 from offset 0x20 [@0xf6cc]. Its return is 0 after the logging path and -1 on the early exits [@0xf750].
  Reviewed: 2026-11-12

- `start` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x15d0
  **Inferred.** Role (from facts): loads a doubleword from the fixed address 0x9200000001600000 [@0x1600], then calls mapped_kernel_setup_tlb with the caller's a2 and a3 [call 1]. It then jumps through a relocated target [@0x1638].
  Reviewed: 2026-11-12

- `sn00_vmc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xc818
  **Inferred.** Role (from facts): calls device_inventory_add [call 1] and sets PCI bridge hints with pcibr_hints_dualslot [call 2], pcibr_hints_subdevs [call 3] and pcibr_hints_fix_rrbs [call 4]. It installs sn00_rrb_alloc as the bridge's RRB callback [call 5]. It brackets a call to get_my_slotid [call 7] with splprof [call 6] and splx [call 8]. The branch at 0xc8ac compares a4, which holds the constant 1, with a6 [@0xc8ac taken].
  Reviewed: 2026-11-12

- `hub_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe9a4
  **Inferred.** Role (from facts): calls xwidget_info_get [call 1], then xwidget_info_id_get [call 2] and xwidget_info_master_get [call 3] on its result, and hwgraph_info_get_LBL on the master [call 4]. It compares a2 with 5 [@0xe9fc taken] and with 6 [@0xea04 taken]. Its return is the constant 0 [@0xea10].
  Reviewed: 2026-11-12
