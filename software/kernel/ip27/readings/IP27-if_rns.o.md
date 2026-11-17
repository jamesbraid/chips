# Readings: `IP27/usr/cpu/sysgen/IP27boot/if_rns.o`

One entry per routine, filed here from the reading batches by binary.

- `if_rnsintr` in `IP27/usr/cpu/sysgen/IP27boot/if_rns.o` at 0x563c
  **Inferred.** The interrupt handler for the `if_rns` network device, working on the record in `a0`. It calls `mutex_lock` on the record at offset 0xd0 (call at 0x5654) and `mutex_unlock` at 0x5758. It calls `fcr_fet` and `fcr_sto` with constant second arguments such as 0x78000000, 0x4000000, 0x50860000 and 0x50840000, calls `us_delay` with 4 at 0x5710, 0x594c and 0x59b0, and calls `rns_elm_int`, `rns_mac_int`, `rns_fin_in` and `rns_fin_out`. `cmn_err_tag` is called with code 0xb5 at 0x5750, code 0xb4 at 0x5984 and code 0xb6 at 0x59e8. What the codes mean is not derived.
  Reviewed: 2026-11-12
