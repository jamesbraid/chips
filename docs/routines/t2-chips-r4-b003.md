# Tier-2 reading, batch 3 of chips (round 4): routine role statements

Each entry names a routine in the IP27 boot-set objects and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Grades are inferred, because the rendered facts do not fully settle any of these roles.

- `ktimer_readticks` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x50
  **Inferred.** Reads a 64-bit tick count for the CPU index in a1 from the table at a0+0x280 (the `ld` at 0x68 indexes it by a1 times 8). It retries at 0x64 while the 8-byte word at a0+0x2d8 differs from t1 (the `bne` at 0x94), and the fixed address 0x9200000001030100 read at 0x78 looks like the hardware counter. The return at 0xac hands back the 8-byte value at (a0 + a1<<3) + 640, and the return at 0xa4 has no constant value in these facts.

- `ktimer_read` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0xb4
  **Inferred.** The same retry loop as `ktimer_readticks`, with the per-CPU table read at 0xd8 and the counter at 0xe8. It stores its result through a2: a 4-byte word at a2+0 (the `sw` at 0x138) and an 8-byte word at a2+8 (the `sd` at 0x144). The retry branch at 0x104 goes back to 0xd4 while the word at a0+0x2d8 differs from t8.

- `ktimer_slptime` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x150
  **Inferred.** Reads the 4-byte state word at a0+0x2e0 (the `lw` at 0x150) and returns 0 at 0x190 when it equals 0, 1 or 2 (the `beq` branches at 0x15c, 0x164 and 0x16c all go to 0x190). Otherwise it reads the 8-byte word at a0+0x2d8 (the `ld` at 0x174) and the counter at 0x9200000001030100 (the `ld` at 0x178), and returns through 0x188 with no constant value in these facts. The name suggests a sleep-time query, and the branch structure fits that.

- `log_tstamp_event` in `IP27/usr/cpu/sysgen/IP27boot/os.a(tstamp.o)` at 0x2fc
  **Inferred.** Appends one timestamp event to a per-CPU log. It reads the CPU index from the halfword at 0xffffffffffffc420 (the `lh` at 0x304), finds the per-CPU record through sym(pdaindr) (the `ld` at 0x320), and reserves a slot with `atomicIncWithWrap` at 0x400. It stores the slot fields at +0x0 through +0x28 (the `sd` run from 0x374 to 0x388), and runs the update between `getsr` at 0x538, `splhi` at 0x550 and `splx` at 0x5a8. The `sv_signal` at 0x5a0 and `compare_and_dec_int_gt` at 0x590 calls handle a waiter once the count passes its threshold.

- `log_tstamp_vevent` in `IP27/usr/cpu/sysgen/IP27boot/os.a(tstamp.o)` at 0x5c8
  **Inferred.** The variable-record form of `log_tstamp_event` at 0x2fc. It copies the caller's record from a1 (the 8-byte loads at 0x67c to 0x69c) into the slot at +0x0 through +0x28 (the stores at 0x678 to 0x6ac). It compares the length in a2 with 0x28 at 0x6a8 before copying any extra payload with `bcopy` at 0x73c, 0x8c8, 0x8dc and 0x8f0. The per-CPU lookup, the `atomicAddWithWrap` at 0x814 and the `getsr`, `splhi` and `splx` protection at 0x9d8, 0x9f0 and 0xa48 mirror the event routine.

- `uuid_create` in `IP27/usr/cpu/sysgen/IP27boot/os.a(uuid.o)` at 0x28
  **Inferred.** Fills a 16-byte UUID into the buffer at a0. It stores fields at a0+0x0 (the `sw` at 0x64), a0+0x4 (the `sh` at 0x78), a0+0x6 (the `sh` at 0x88) and a0+0x8 (the `sh` at 0x5c), which look like the UUID time and clock fields. The update runs under `mutex_lock` at 0x44 and is released by `mutex_unlock` at 0x8c or 0xf4. The node part comes from `get_eaddr` at 0xd4 when the cached flag at sym(.sbss) is clear (the `beq` at 0x54), and the timestamp comes from `nanotime` at 0x104.

- `real_dumpsys` in `IP27/usr/cpu/sysgen/IP27boot/os.a(vmdump.o)` at 0x268
  **Inferred.** The top-level crash-dump routine. It checks the dump device and level first: dumpdev against -1 at 0x280, dump_level at 0x288, and dumpsize at 0x290. It finds the block-switch entry by major number (MAJOR checked against bdevcnt at 0x2cc and bdevmax at 0x2d8), then runs the dump with `enter_dump_mode` at 0x320, `compression_init` at 0x3cc with a 0x8000 buffer, `dumpvmcore` at 0x3e4 and `exit_dump_mode` at 0x3ec. It writes through `bdrv` at 0x358, walks the CPUs with `cpu_enabled` at 0x4b8, and ends in `mdboot` at 0x404 or 0x488, or `panic` at 0x5d0 to 0x614.

- `xthread_periodic_timeout` in `IP27/usr/cpu/sysgen/IP27boot/os.a(xthread.o)` at 0x72c
  **Inferred.** Fills a timeout record at a4: stores at +0x0, +0x28, +0x30, +0x38 and +0x40, and halfwords at +0x48 to +0x4a. It first calls `xthread_table_name_get_property` at 0x778 with a1 set to 2. The flag word at a4 is tested against 0x800 (the `beq` at 0x74c), and that choice leads either to `xthread_setup` at 0x7cc with sym(xpt_init) and sym(pdaindr), or to `xpt_timeout` at 0x7e0. The per-CPU field at +0x48 is also checked against 0x800 (the `beq` at 0x7b0).

- `pcibr_open` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x570
  **Inferred.** A capability gate for opening a PCI bridge device. It calls `cap_able_cred` at 0x580 with the constant 0x2000000000 and the caller's a2 and a3, then returns 0 or 1 from v0 at 0x594 depending on whether that check returned zero (the `beq` at 0x588). The routine has no other calls.

- `pcibr_bridge_ptr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x42ec
  **Inferred.** Computes a PIO address for a bridge register window. It calls `xtalk_piotrans_addr` at 0x4304 with fixed arguments (a1 0, a2 0, a3 8, a4 0), then compares a device ID with 0xd102 and 0xd112 (the `beq` at 0x4324 and the `bne` at 0x4338) and a second value with 0x24 (the `bne` at 0x4350). It returns the translated address or that address plus 0x800000 at 0x4368.

- `pcibr_alloc_all_rrbs` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6234
  **Inferred.** Allocates read-response buffers for the bridge's slots. It looks up the bridge vertex with `hwgraph_traverse` at 0x627c, translates addresses with `xtalk_piotrans_addr` at 0x62a0, and takes the bridge lock with `mutex_spinlock` at 0x649c. It programs each allocation with `pcireg_rrb_set` at 0x64b8, releases the lock at 0x654c, and drops the vertex reference with `hwgraph_vertex_unref` at 0x6594. The loop tests the device IDs 0xc002 and 0xd002 (the `beq` at 0x62e0 and 0x62f8).

- `pcibr_error_dump` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x8690
  **Inferred.** The bridge error-interrupt handler. It takes a lock with `test_and_set_long` at 0x86c4 on the bridge state at a0+2112 (0x840), and reads the interrupt status with `pcireg_intr_status_get` at 0x86a0. It then tests the status bits against 0x80000000, 0x10000, 0x100, 0x800000 and many others, and for each set bit calls the matching `pcireg_*` getters and reports them with `cmn_err` at 0x8718, 0x88e0 and similar sites. The result returns through 0x86e4.

- `pcireg_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xddec
  **Inferred.** Reads one bridge register chosen by the halfword at a0+0x72. It panics at 0xdf3c when a0 is null (the `beq` at 0xddf4) or when the selector is -1 (the `beq` at 0xde3c). Otherwise it compares the selector with 3, 2, 0 and 1 (the `beq` at 0xde18 to 0xde34), then picks a register address from 0xe000, 0xe010, 0xd102, 0xd112, 0xd002 or 0xc002 (the `beq` at 0xde78 to 0xde98 and the `bne` at 0xdea0). The normal return at 0xde48 is 0x0.

- `pcireg_stat_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdf4c
  **Inferred.** Same shape as `pcireg_id_get`: a bridge register chosen by the halfword at a0+0x72, with the null check at 0xdf54 and the -1 check at 0xdf9c leading to `panic` at 0xe0a0. The address ladder runs from 0xdfd8 to 0xdff8 and ends in the `bne` at 0xe000 against 0xc002, and the normal return at 0xdfa8 is 0x0.

- `pcireg_bus_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe0b0
  **Inferred.** Same shape again, reading a bus-error register selected by the halfword at a0+0x72. The null check is at 0xe0b8 and the -1 check at 0xe100, both leading to `panic` at 0xe210. The address ladder runs from 0xe13c to 0xe15c, and the normal return at 0xe10c is 0x0.

- `pcireg_control_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe220
  **Inferred.** Reads a control register selected by the halfword at a0+0x72, with the null check at 0xe228 and the -1 check at 0xe270 leading to `panic` at 0xe378. The address ladder runs from 0xe2b0 to 0xe2d0, and the normal return at 0xe280 is 0x0.

- `pcireg_control_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe388
  **Inferred.** Writes a control register. It raises the interrupt level with `splhi` at 0xe39c and restores it with `splx` at 0xe400, and the store is a `sw` at 0xe474 or `sd` at 0xe490 or 0xe4ac, selected through the same address ladder (0xe43c to 0xe464). The selector checks are the null test at 0xe3a8, the -1 test at 0xe3f0 that goes to `panic` at 0xe500, and the value tests at 0xe3cc to 0xe3e8. The return at 0xe40c is `ret(splx)`.

- `pcireg_control_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe510
  **Inferred.** A read-modify-write that clears bits in a control register. It brackets the update with `splhi` at 0xe524 and `splx` at 0xe584, reads the register (`lw` at 0xe5fc and 0xe610), and writes it back with the `sw` at 0xe608. The address ladder runs from 0xe5c0 to 0xe5e8, the null and -1 checks go to 0xe6a8 and the panic at 0xe6ac, and the return at 0xe590 is `ret(splx)`.

- `pcireg_control_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe6bc
  **Inferred.** The bit-set counterpart of `pcireg_control_bit_clr`: `splhi` at 0xe6d0, `splx` at 0xe730, a read at 0xe7a4 and 0xe7b4, and a write with the `sw` at 0xe7ac. The address ladder runs from 0xe76c to 0xe794, the null and -1 checks go to 0xe844, and the panic is at 0xe848. The return at 0xe73c is `ret(splx)`.

- `pcireg_ssram_size_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe858
  **Inferred.** Sets the SSRAM size field of the bridge. It checks the size argument in a1 first, with `bltz` at 0xe94c and the `beq` at 0xe958 (a1 at least 4) leading to `assfail` at 0xea28 with line 0x158. It then raises the interrupt level with `splhi` at 0xe86c, writes the field with the `sw` at 0xe96c and 0xe97c, and restores it with `splx` at 0xe8d4. The address ladder runs from 0xe910 to 0xe93c, and the normal return at 0xe8e0 is `ret(splx)`.

- `pcireg_speed_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xea48
  **Inferred.** Reads the bus speed field selected by the halfword at a0+0x72. The null check is at 0xea50, the -1 check at 0xea98, and both lead to `panic` at 0xebb0. The address ladder runs from 0xead8 to 0xeaf8, with the `bne` at 0xeb00 against 0xc002, and the normal return at 0xeaa8 is 0x0.

- `pcireg_mode_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xebc0
  **Inferred.** Reads the bus mode field selected by the halfword at a0+0x72. The null check is at 0xebc8 and the -1 check at 0xec10, both leading to `panic` at 0xed1c. The address ladder runs from 0xec4c to 0xec6c, and the normal return at 0xec1c is 0x0.

- `pcireg_req_timeout_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xed2c
  **Inferred.** Reads the request-timeout field selected by the halfword at a0+0x72. The null check is at 0xed34 and the -1 check at 0xed7c, both leading to `panic` at 0xee80. The address ladder runs from 0xedb8 to 0xedd8, and the normal return at 0xed88 is 0x0.

- `pcireg_req_timeout_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xee90
  **Inferred.** Writes the request-timeout field with the value in a1. The null check is at 0xee98, and the -1 check on the selector at 0xeee0 leads to `panic` at 0xefdc with a1 as its argument. The address ladder runs from 0xef1c to 0xef44, and the stores are the `sw` at 0xef58 and the `sd` at 0xef74 and 0xef90. The routine returns through 0xeeec.

- `pcireg_intr_dst_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xefec
  **Inferred.** Reads the interrupt destination register selected by the halfword at a0+0x72. The null check is at 0xeff4 and the -1 check at 0xf03c, both leading to `panic` at 0xf150. The address ladder runs from 0xf07c to 0xf09c, and the normal return at 0xf04c is 0x0.
