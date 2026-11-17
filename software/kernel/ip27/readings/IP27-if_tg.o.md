# Readings: `IP27/usr/cpu/sysgen/IP27boot/if_tg.o`

One entry per routine, filed here from the reading batches by binary.

- `tg_intr` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xbd1c
  **Inferred.** The interrupt handler for the `if_tg` network device, working on the device record in `a0`. It calls `mutex_spinlock_spl` on the record at offset 0xa8 (call at 0xbd5c) and reads and writes many fields at offsets 0x18, 0x50, 0x74, 0x88, 0x8a, 0x138, 0x258 and 0x320, plus a region reached through the pointer at offset 0x18. It calls `tg_recv` at 0xbec4, `tg_fill` at 0xbee8, `tg_send` at 0xc010, `tg_set_coal` at 0xc13c, and `tg_init_phy`, `tg_get_link_state` and `tg_report_link_state` at 0xc4d0, 0xc4d8 and 0xc4e0. It calls `ftrc_event` at 16 sites between 0xc170 and 0xc5d4.
  Reviewed: 2026-11-12

- `ftrc_event` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xf630
  **Inferred.** Role (from name): writes one trace record. The branch at 0xf660 jumps to the `ftrc_init` call at 0xf764 when the global `ftrc_initialized` is zero; the branches at 0xf668 and 0xf670 jump to 0xf758 when `a0` or `a2` is zero. When `[a0+16]` is nonzero it calls `mutex_spinlock` on the lock at `[a0+16]+64` (call at 0xf684) and reads fields at offsets 0x20, 0x28 and 0x30 of `[a0+16]`. It calls `mutex_spinunlock` at 0xf6d8, then stores bytes, a word, a halfword and doublewords at offsets 0x0 through 0x38 of a record from 0xf6dc to 0xf72c. The record layout is inferred from the store offsets alone, and a ring is not shown by the facts.
  Reviewed: 2026-11-12

- `ftrc_event` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xf630
  **Inferred.** Role (from name): a trace event recorder. If the global `ftrc_initialized` is zero it branches at 0xf660 to a call to `ftrc_init` at 0xf764 with its own arguments. Otherwise, when `a0`, `a2` and `[a0+16]` are all nonzero, it calls `mutex_spinlock` at 0xf684 on `[a0+16]+64`, stores into a buffer found through `[a0+16]+48` with an unsigned comparison at 0xf6b8, and calls `mutex_spinunlock` at 0xf6d8. It returns -1 or 0.
  Reviewed: 2026-11-12

- `ftrc_event` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xf630
  **Inferred.** Role (from facts): when the flag ftrc_initialized is zero it first calls ftrc_init with its four arguments [call 3, @0xf660 taken zero] and then carries on with the checks below. When the flag is nonzero [@0xf660 fall nonzero] it goes straight to them. It returns -1 without logging when a0 is zero [@0xf668 taken zero], when a2 is zero [@0xf670 taken zero], or when the pointer loaded from [a0+16] is zero [@0xf67c taken zero]. It then takes mutex_spinlock on the word at [a0+16]+64 [call 1], advances the doubleword at offset 0x30 of the record at [a0+16] [@0xf6ac] and releases the lock with mutex_spinunlock at 0xf6d8 [call 2]. When the advanced value is not below the doubleword at offset 0x28 [@0xf6b8 fall] it reloads offset 0x30 from offset 0x20 [@0xf6cc]. Its return is 0 after the logging path and -1 on the early exits [@0xf750].
  Reviewed: 2026-11-12
