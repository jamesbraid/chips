# Tier-2 reading, batch 0 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts for that routine: registers, loads and stores, calls, branches and constants. Every grade is inferred, because the facts show what the code does but not what the author meant by it. Names of callees are the symbols in the same binary, cited as call targets only.

- `spinlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xcbc
  **Inferred.** The debug form of a spin-lock acquire on the lock record in `a1`. It calls `try_spinlock` at 0xd20 and 0xe44 inside a retry loop, and on the retry path it calls `splx` at 0xe30 and an indirect callee at 0xe38. Load-linked and store-conditional pairs at 0xd00/0xd0c, 0xd64/0xd70 and 0xe64/0xe70 update record fields at offsets 0xa8 through 0xbc, and `cmn_err` at 0xf04 reports the failure.

- `tryspinlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xf14
  **Inferred.** The single-attempt form of the debug lock acquire. It calls `try_spinlock` at 0xf24 with the caller's four arguments, then branches on the result at 0xf2c: a zero result goes to 0xf6c, and the rest of the body writes record fields at offsets 0x2a, 0x2c, 0x38, 0x40 and 0x50 (stores from 0xf44 to 0xf7c). The routine returns 0 or 1 at 0xf64. Which return value means "acquired" is not settled by the facts.

- `spinunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xf80
  **Inferred.** The debug release of a spin lock, working on the record in `a1`. It compares a halfword at offset 0x2a with a halfword global at -0x3be0 (branch at 0xfb0 and 0xfcc), updates fields at offsets 0x40, 0x48, 0x58, 0x60, 0x68 and 0x80, and calls `cmn_err` at 0x1074, 0x108c and 0x10a4 with message strings from `.rodata` on the mismatch paths. The return value at 0x1054 is not derived.

- `bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1668
  **Inferred.** The debug form of a bit-lock acquire on the record in `a2`, the bit-lock counterpart of `spinlockdebug`. It calls `try_bitlock` at 0x16cc and 0x17f8, with `splx` at 0x17e0 and an indirect callee at 0x17e8 between attempts. The load-linked and store-conditional pairs at 0x16b4/0x16c0, 0x1710/0x171c, 0x1818/0x1824 and 0x1850/0x185c use the same record offsets 0xa8 through 0xbc as the spin-lock form.

- `trybitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x18cc
  **Inferred.** The single-attempt bit-lock acquire. It calls `try_bitlock` at 0x18dc and branches on its result at 0x18e4: a zero result goes to 0x1924. The body writes record fields at offsets 0x2a, 0x2c, 0x38, 0x40 and 0x50 (stores from 0x18fc to 0x1934) and returns 0 or 1 at 0x191c. This mirrors `tryspinlockdebug`, and the mapping of return values to acquired or not is not settled by the facts.

- `bitunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1938
  **Inferred.** The debug release of a bit lock on the record in `a2`. It compares the halfword at offset 0x2a with the global at -0x3be0 (branch at 0x1970), then rewrites record fields at offsets 0x40, 0x48, 0x58, 0x60, 0x64, 0x68, 0x78 and 0x80 (stores from 0x19a8 to 0x1a24). `cmn_err` at 0x1a28 and 0x1a40 reports the failure paths with `.rodata` strings.

- `i2c_probe` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x88
  **Inferred.** Probes whether an I2C port answers. It reads through a window computed from `a0` with a fixed offset (loads at 0xb8 and 0xf8) and runs a loop bounded by a comparison at 0xf0 and 0x12c, returning 0 at 0x138 or 1 at 0x140. The device-level meaning comes only from the offsets and the loop shape, so it is a guess from the register window.

- `i2c_arb` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x148
  **Inferred.** Arbitrates bus ownership before a transfer. It calls `node_can_talk_to_elsc` at 0x194 and bails out on a zero result at 0x19c. It tests bit 0 of a register read at 0x1bc and 0x214, compares `a0` against the constants 0xe0 and 0xe8 at 0x1cc, 0x1d4, 0x224 and 0x22c, and stores a doubleword to `a2+0` at 0x208. The return at 0x350 is either -11 or not derived.

- `i2c_master_xmit` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x358
  **Inferred.** The master transmit half of an I2C transfer. It calls `i2c_arb` at 0x3b0, branches on a negative result at 0x3c0 and a zero result at 0x3d4, then runs a byte loop bounded by the length in `a3` (test at 0x4a4). Register accesses go through the computed window at `a0` (stores at 0x410, 0x4b8 and 0x548), and status masks 0x16, 0x80 and 0x8 pick the acknowledge and error paths. The count is written through `a4` at 0x3ac and 0x528.

- `i2c_master_recv` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x5b0
  **Inferred.** The master receive half of an I2C transfer, the read counterpart of `i2c_master_xmit`. It calls `i2c_arb` at 0x610, branches on its result at 0x620 and 0x634, then loops over the receive length, tested at 0x70c and 0x714. Bytes move through the computed window at `a0` (stores at 0x678 and 0x794, byte store at 0x768), and status masks 0x16 and 0x80 select the acknowledge and stop paths, as in the transmit routine.

- `i2c_master_xmit_recv` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x858
  **Inferred.** A combined write-then-read on the I2C bus, built from the same pieces as `i2c_master_xmit` and `i2c_master_recv`. It calls `i2c_arb` at 0x8c4 and then runs a transmit loop and a receive loop in one body, with the two lengths tested at 0x9bc and 0xad8 and 0xae0. Result counts are stored through `a4` and `a7` at 0x8b8, 0x8c0, 0xa44 and 0xb54, and the status masks follow the single-direction routines.

- `idbg_callo` in `IP27/usr/cpu/sysgen/IP27boot/idbg.o` at 0x165a8
  **Inferred.** A debugger command that dumps per-CPU callout state for the CPU number in `a0`. It indexes the table at `pdaindr` with `a0` shifted by 4, reads fields at offsets 0x5d0, 0x5e8 and 0x630 of the entry, and prints them with `qprintf` at 0x1661c, 0x16690, 0x166d0, 0x16724 and 0x167b0. It raises the priority with `splprof` at 0x165cc, dumps through a `.text` callee at 0x16770 and 0x167fc, and restores with `splx` at 0x16820. A `-1` argument takes a separate path at 0x165e0.

- `eg_intr` in `IP27/usr/cpu/sysgen/IP27boot/if_eg.o` at 0x2c08
  **Inferred.** The interrupt handler for the `if_eg` network device, working on the device record in `a0`. It takes `mutex_spinlock_spl` on the record at offset 0x370 (call at 0x2c24) and releases it at 0x2c78 and 0x2f34. It tests the status word at 0x344 with masks 0x10 (0x2c64) and 0x8000 (0x2cd4), tests a word at 0x4cc with mask 0x8 (0x2dbc, 0x2e84), and calls `eg_transmit` at 0x2d28, `eg_recv` at 0x2ed4, `eg_reclaim` at 0x2ee4, `eg_errupdate` at 0x2ec4 and `eg_linkstate` at 0x2efc. It logs through `printf` at 0x2dec and 0x2e00 and `cmn_err` at 0x2f5c and 0x2f7c.

- `if_rnsintr` in `IP27/usr/cpu/sysgen/IP27boot/if_rns.o` at 0x563c
  **Inferred.** The interrupt handler for the `if_rns` network device, working on the record in `a0`. It takes `mutex_lock` on the record at offset 0xd0 (call at 0x5654) and releases it at 0x5758. It reads and writes device registers through `fcr_fet` and `fcr_sto` at constant addresses such as 0x78000000, 0x4000000, 0x50860000 and 0x50840000, waits with `us_delay` at 0x5710, 0x594c and 0x59b0, and calls the receive and transmit helpers `rns_elm_int`, `rns_mac_int`, `rns_fin_in` and `rns_fin_out`. Failure codes 0xb4, 0xb5 and 0xb6 are reported through `cmn_err_tag` at 0x5750, 0x5984 and 0x59e8.

- `tg_intr` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xbd1c
  **Inferred.** The interrupt handler for the `if_tg` network device, working on the device record in `a0`. It takes `mutex_spinlock_spl` on the record at offset 0xa8 (call at 0xbd5c) and reads and writes many fields at offsets 0x18, 0x50, 0x74, 0x88, 0x8a, 0x138, 0x258 and 0x320, plus a region reached through the pointer at offset 0x18. It calls `tg_recv` at 0xbec4, `tg_fill` at 0xbee8, `tg_send` at 0xc010, `tg_set_coal` at 0xc13c, and the PHY helpers at 0xc4d0 to 0xc4e0. It writes trace records through `ftrc_event` at about a dozen sites from 0xc170 to 0xc5d4.

- `ftrc_event` in `IP27/usr/cpu/sysgen/IP27boot/if_tg.o` at 0xf630
  **Inferred.** Writes one trace record into a ring. It takes `mutex_spinlock` on the lock at `[a0+16]+64` (call at 0xf684) and reads fields at offsets 0x20, 0x28 and 0x30 of `[a0+16]`. It calls `mutex_spinunlock` at 0xf6d8, then stores bytes, a word, a halfword and doublewords at offsets 0x0 through 0x38 of the entry from 0xf6dc to 0xf72c. It calls `ftrc_init` at 0xf764 on another path, and the condition for that call is not derived. The record layout is inferred from the store offsets alone.

- `pckm_attach` in `IP27/usr/cpu/sysgen/IP27boot/ioc3_pckm.o` at 0x5c
  **Inferred.** The attach routine for the IOC3 keyboard and mouse controller. It allocates a 0x68-byte block (call at 0xf0) and two 0x58-byte blocks (calls at 0x110 and 0x120) with `kmem_zalloc`, and it initializes a mutex at 0x13c. It registers character devices and inventory entries (`hwgraph_char_device_add` at 0x1b8 and 0x310, `device_inventory_add` at 0x20c and 0x350), sends controller commands 0xf5, 0xf4 and 0xf6 through `pckm_pollcmd` and checks each acknowledge 0xfa with `data_check`, and connects the handler `pckm_intr` at 0x450 with `ioc3_intr_connect`. Failure paths report through `cmn_err` at 0x534 to 0x580.

- `numalinkstats_up2date` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f7c
  **Inferred.** Checks whether the NUMA link statistics are current. It loads a doubleword from the fixed address 0xffffffffffffc400 (0x1f98), a doubleword through the global pointer at -0x3c00 (0x1fa0), and five more doublewords from indirect addresses (0x1fb4 to 0x1fc4). The return value at 0x2018 is not derived. The role rests on the name and these loads alone.

- `router_reg_read` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21c4
  **Inferred.** Reads one router register. It takes a halfword at offset 0x2 and a doubleword at 0x18 and a word at 0x20 of the router handle in `a0`, and calls `hub_vector_read` at 0x21e0 with them as arguments. It returns the result of that call.

- `router_reg_write` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21f4
  **Inferred.** Writes one router register, the mirror of `router_reg_read`. It takes the same halfword at offset 0x2, doubleword at 0x18 and word at 0x20 from the router handle in `a0`, and calls `hub_vector_write` at 0x2210 with them. It returns the result of that call.

- `router_acquire_info` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2584
  **Inferred.** Gathers information for one router under its lock. It takes `mutex_spinlock` on the lock at offset 0x194 (call at 0x25a8) and releases it at 0x2604 and 0x2698, reads flag bytes at offsets 0x7, 0x8 and 0x191 and a doubleword at 0x160, and stores to 0x7, 0x160 and 0x30. It calls `router_acquire_port_info` at 0x2614, `router_set_leds` at 0x264c, and `router_reg_write` at 0x2704 and 0x271c with register offset 0x18.

- `capture_router_stats` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cb0
  **Inferred.** Records one sample of router statistics. It calls `router_acquire_info` at 0x2cc0 first, then reads and updates the byte fields at offsets 0x190 and 0x191 and the doubleword at 0x188 (store at 0x2d08, load at 0x2d14). It calls `router_check_errors` through a function-pointer slot at 0x2898 (call at 0x2cec) and its return value is either the global `router_poll_ticks` or not derived. The sample's destination is not settled by the facts.

- `router_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f04
  **Inferred.** Builds one router record at boot. It allocates a 0x1b8-byte record with `kmem_zalloc_node` at 0x2f40 and frees it with `kmem_free` at 0x3334, initializes its lock at 0x2f74, and registers its info at 0x2f60. It reads and writes router registers with `router_reg_read` at 0x2ff0 and 0x3008 and `router_reg_write` at 0x3078, then calls `router_port_init` at 0x31d0, `router_set_fences` at 0x3200 and `build_router_invent_info` at 0x3234. Assertions `assfail` at 0x334c and 0x3364 report line numbers 0x46b and 0x470.

- `hub_widget_id` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x44cc
  **Inferred.** A leaf that loads one doubleword from the address formed by `a0` shifted by 32 plus a fixed offset (load at 0x44d8) and returns the loaded value at 0x44dc. The return is not derived beyond the load, so the widget-id meaning rests on the name.

- `get_slice` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x4500
  **Inferred.** A leaf that loads one doubleword from the fixed global at 0x9200000001000020 (load at 0x4504) and returns it unchanged (return at 0x4508). The slice meaning rests on the name and the single load.
