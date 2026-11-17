# Readings: `IP27/usr/cpu/sysgen/IP27boot/if_eg.o`

One entry per routine, filed here from the reading batches by binary.

- `eg_intr` in `IP27/usr/cpu/sysgen/IP27boot/if_eg.o` at 0x2c08
  **Inferred.** The interrupt handler for the `if_eg` network device, working on the device record in `a0`. It takes `mutex_spinlock_spl` on the record at offset 0x370 (call at 0x2c24) and releases it at 0x2c78 and 0x2f34. It tests the status word at 0x344 with masks 0x10 (0x2c64) and 0x8000 (0x2cd4), tests a word at 0x4cc with mask 0x8 (0x2dbc, 0x2e84), and calls `eg_transmit` at 0x2d28, `eg_recv` at 0x2ed4, `eg_reclaim` at 0x2ee4, `eg_errupdate` at 0x2ec4 and `eg_linkstate` at 0x2efc. It logs through `printf` at 0x2dec and 0x2e00 and `cmn_err` at 0x2f5c and 0x2f7c.
  Reviewed: 2026-11-12
