# Hub

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): no Hub specification is held). The IP27 node controller: the
processor interface (PI), the memory and directory controller (MD), the I/O interface (II, "IO" elsewhere) and the network
interface (NI), plus the registers of the local block (LB) that sit in PI space outside the contiguous map. Every fact below
comes from two shipped files: the IRIX 6.5.30 IP27 kernel (`unix`, linked, with symbols) and the IP27 CPU PROM
(`ip27prom.img`, a promgen64 container, no symbols). The public Linux SN0 headers (`arch/mips/include/asm/sn/sn0/hubpi.h`,
`hubmd.h`, `hubio.h`, `hubni.h`, `addrs.h`) supply the register names, matched by offset after the census, and were
compared afterwards (see the last section). Census: [census/](census/census.md) (`census.tsv`, `fields.tsv`, `context.tsv`,
`census-sites.tsv`), config [`tools/configs/hub.json`](../../tools/configs/hub.json), header [`include/hub.h`](../../include/hub.h).

## Addresses (established)

- The kernel and the PROM reach the Hub's own register file through two aliases of the same offsets:
  - the **local alias**, uncached I/O-space address `0x9200000001000000 + offset` (physical `0x01000000 + offset`): dozens of
    literal addresses in the kernel's small-data pool, for example `0x9200000001000400`, and the PROM, which builds the base
    with a `lui 0x9200`, shift, `ori 0x100`, shift chain (`0x1fc0081c`);
  - the **node-addressed alias**, `0x9200000001800000 + (node << 32) + offset`: the kernel adds the node number shifted left by
    32 (the node number comes from `get_nasid`, bits 16:8 of the network status register) to the literal `0x9200000001800000`.
    This is how code reaches another node's Hub and also how it reaches its own (`hub_error_clear`, `set_timer_intr`).
  Both forms use the same offsets; a pair of routines that read the same register through different aliases is in the census
  as `idx` 0 (local) and `idx` 1 (node-addressed or indexed). The census reports offsets relative to the alias base.
- Blocks, by address: PI `0x000000` to `0x1fffff`, MD `0x200000` to `0x3fffff`, II `0x400000` to `0x5fffff`, NI `0x600000`
  to `0x7fffff`. Sub-blocks the code reaches: MD performance counters `0x210000`, MD junk bus `0x220000`, II block transfer
  engines `0x410000` and `0x420000`, II performance counters `0x430000`, NI routing tables `0x638000`.
- The **local block** group is the two PI-space registers outside the contiguous map, the hard-reset bit `0x20068` and the
  real-time counter `0x30100`. That grouping is by address only (inferred): no shipped string calls them a block.
- One more address: reading physical `0x02400208` (`0x9200000002400208`) is a deliberate bus-error generator. `handle_uncac_buserr`
  treats a bus error whose address equals `0x2400208` as expected and returns. The public headers call it the I/O bus error
  register (`IIBUSERR`, offset `0x400208` in the I/O block, shown as `0x1400208` there).
- All accesses in the census are doublewords (`ld`, `sd`): 1,022 sites, no word or byte access reaches the register file.
  Registers are eight-byte slots.
- Row `0x0` with the index flag (27 sites in 13 routines, for example `timeout_poll`, `err_int_block_mask`, `gfx_flow_attach_me`)
  is **not** PI_CPU_PROTECT: the routine adds a register offset its caller supplies (`timeout_poll(node, offset, mask, count,
  delay)` reads the register `offset` of the node's Hub until `value & mask`), so the scan records the base. It is left
  unnamed and out of the header; the routines that pass the offset are in `context.tsv`.

## Register inventory

Census result over two images (kernel 730 sites, PROM 292 sites; 1,022 site records, the kernel count including the five
`save_hub_*` accessors seeded with the Hub base): 166 census rows, 132 distinct offsets once the two aliases are folded, of
which the base-plus-index row `0x0` is not a register: **131 registers**. Grades: **51 established, 74 inferred, 6 unknown** (unknown here means touched by code whose role is not read). By block:
PI 28 established, 15 inferred, 0 unknown; LB 1 established, 1 inferred, 0 unknown; MD 8 established, 15 inferred, 4 unknown; II 10 established, 28 inferred, 2 unknown; NI 4 established, 15 inferred, 0 unknown.

Grades follow AGENTS.md. A row is **established** when a routine that uses it was read in full and its offset, width and a role or
field use are in the code, or when the shipped decode text states the field; **inferred** when the role rests on the routine names,
the offset match to a public header or a partial reading; **unknown** when touched but not read. No census row has a name in the
binaries: every name is the public Linux header name at that offset (inferred) except the CRB entry words, named by the shipped
decode text ("ICRB%x_A entry"). Reset values are unknown for every register (no routine reads a register to compare it with a
reset value, except where a section says otherwise).

### PI: processor interface

| Offset | Name | Width | Access | Alias | Grade | What the held code shows |
|---|---|---|---|---|---|---|
| `0x18` | `PI_REGION_PRESENT` | 8 | rw | local/node | inferred | Region-present mask. `mlreset` stores a constant through the node alias; `handle_cac_buserr` reads it. Role from the name only. |
| `0x20` | `PI_CPU_NUM` | 8 | rw | local | established | Processor number within the node. `get_slice` (read in full) returns the low word of this register, and `getcpuid` combines it with the node number to find the processor record; the kernel keeps the same number in the processor record and tests `slice == 0` to pick the A-side registers below. The PROM reads it on every boot path. The PROM also stores three values (Cause, EPC, BadVAddr) to this address in its exception path (`0x1fc02998`); why a store goes to a processor-number register is not read: unknown. |
| `0x28` | `PI_CALIAS_SIZE` | 8 | rw | local/node | inferred | Cached-alias size. `mlreset` stores sizes (1 and 2 seen), `memory_iscalias` and `page_local_calias` read it to decide whether an address falls in the cached alias. Role from the routine names; the stored encoding is not read. |
| `0x30` | `PI_MAX_CRB_TIMEOUT` | 8 | w | node | inferred | CRB timeout limit, written by `per_hub_init` from kernel variables. The unit is not read. |
| `0x38` | `PI_CRB_SFACTOR` | 8 | w | node | inferred | CRB timeout scale factor, written by `per_hub_init` next to the previous register. Unit not read. |
| `0x40` | `PI_CPU_PRESENT_A` | 8 | r | local | established | CPU A present. `hub_error_init` reads it and, when nonzero, copies the CPU A error-stack address (0x418) into the node record. |
| `0x48` | `PI_CPU_PRESENT_B` | 8 | r | local | established | CPU B present. As 0x40, for the CPU B error-stack address (0x420). |
| `0x50` | `PI_CPU_ENABLE_A` | 8 | r | local | established | CPU A enabled. `hub_error_init` tests it to choose the error interrupt masks (see the error section); `save_hub_pi_error` tests it before saving the A error latches. |
| `0x58` | `PI_CPU_ENABLE_B` | 8 | r | local | established | CPU B enabled. As 0x50, for the B side. |
| `0x70` | `PI_NMI_A` | 8 | w | node | inferred | Non-maskable interrupt to CPU A (node alias). Written by the NMI dump and tick paths with a constant; the CPU B register is the next slot, 0x78, which no code reaches. |
| `0x90` | `PI_INT_PEND_MOD` | 8 | w | local/node | inferred | Interrupt pending modify. `intr_connect_level` stores `level + (group << 6)` here through the node alias; the PROM stores through the local alias at four places. Level numbers run 0 to 127, so the register takes a 7-bit number (group = bit 6). Sense of the set or clear is not read. |
| `0x98` | `PI_INT_PEND0` | 8 | r | local/node | inferred | Interrupt pending, levels 0 to 63. Read by the interrupt dispatch and by `intr_connect_level` after the modify store; also by `gfx_flow_detach_me` and the PROM. |
| `0xa0` | `PI_INT_PEND1` | 8 | r | local/node | inferred | Interrupt pending, levels 64 to 127. Read by `check_ni_errors`, `chkdebug`, `intr_dumpvec` and the PROM. The NI error interrupt (level 126) lives here. |
| `0xa8` | `PI_INT_MASK0_A` | 8 | rw | node | inferred | Interrupt mask, group 0, CPU A. `intr_connect_level` and `intr_disconnect_level` read-modify-write it with `1 << level`; `intr_clear_all` clears it. |
| `0xb0` | `PI_INT_MASK1_A` | 8 | rw | node | inferred | Interrupt mask, group 1, CPU A. As 0xa8 for levels 64 to 127. |
| `0xb8` | `PI_INT_MASK0_B` | 8 | rw | node | inferred | Interrupt mask, group 0, CPU B. Reached by `intr_clear_all` and `intr_dumpvec` only (the A and B registers are 0x10 apart, which the connect routine uses). |
| `0xc0` | `PI_INT_MASK1_B` | 8 | rw | node | inferred | Interrupt mask, group 1, CPU B. `do_intr_block_bit` read-modify-writes it to block or unblock a level. |
| `0x108` | `PI_RT_COMPARE_A` | 8 | w | node | established | Real-time compare, CPU A. `set_timer_intr` (read in full) stores the absolute counter value at which the timer interrupt is wanted, through the node alias, then reads the counter back to see whether the time has already passed; slice 0 writes this register, slice 1 writes 0x110. |
| `0x110` | `PI_RT_COMPARE_B` | 8 | w | node | established | Real-time compare, CPU B. As 0x108, selected when the slice is nonzero. |
| `0x118` | `PI_PROFILE_COMPARE` | 8 | w | local | established | Profile compare. `startkgclock` (read in full) stores `RT_COUNT + 1250` here, after storing 1 to the per-slice profile enable (0x150 or 0x158); `prof_intr` rewrites it. 1250 counter ticks is the profiling clock period. |
| `0x120` | `PI_RT_PEND_A` | 8 | w | local | established | Real-time interrupt pending, CPU A. `acktmoclock` (read in full) stores zero to acknowledge the timer interrupt. |
| `0x128` | `PI_RT_PEND_B` | 8 | w | local | established | Real-time interrupt pending, CPU B. As 0x120 for slice 1. |
| `0x130` | `PI_PROF_PEND_A` | 8 | w | local | established | Profile interrupt pending, CPU A. `ackkgclock` (read in full) stores zero to acknowledge. |
| `0x138` | `PI_PROF_PEND_B` | 8 | w | local | established | Profile interrupt pending, CPU B. As 0x130 for slice 1. |
| `0x140` | `PI_RT_EN_A` | 8 | w | node | established | Real-time interrupt enable, CPU A. `hub_rtc_init` (read in full) stores 1 through the node alias. |
| `0x148` | `PI_RT_EN_B` | 8 | w | node | established | Real-time interrupt enable, CPU B. `hub_rtc_init` stores 1. |
| `0x150` | `PI_PROF_EN_A` | 8 | w | local/node | established | Profile interrupt enable, CPU A. `hub_rtc_init` stores 0 at init; `startkgclock` stores 1 (slice 0); `slowkgclock` also writes it. |
| `0x158` | `PI_PROF_EN_B` | 8 | w | local/node | established | Profile interrupt enable, CPU B. As 0x150 for slice 1. |
| `0x160` | `PI_RT_LOCAL_CTRL` | 8 | rw | local | inferred | Real-time local control. Read and written only by one PROM routine (`0x1fc5ac50`, six sites), which also writes the counter at 0x30100; the field layout is not read. |
| `0x320` | `PI_GFX_INT_CMP_A` | 8 | w | node | inferred | Graphics interrupt compare, CPU A. Written by the graphics flow-control routine at 0x395efc (no symbol), together with 0x348, 0x20068 and register 0x400140 in the I/O interface. |
| `0x348` | `PI_GFX_INT_CMP_B` | 8 | w | node | inferred | Graphics interrupt compare, CPU B. See 0x320. |
| `0x400` | `PI_ERR_INT_PEND` | 8 | rw | local/node | established | Error interrupt pending. Read in full in `hubpi_eint_handler`, `hub_error_init`, `save_hub_pi_error`; see the error section for every bit. Each serviced bit is cleared by storing that bit mask back (write-one-to-clear is inferred from the stores, `hubpi_eint_handler` stores the bit it just handled). `handle_uncac_buserr` clears the uncached-load bits the same way. |
| `0x408` | `PI_ERR_INT_MASK_A` | 8 | rw | local/node | established | Error interrupt mask for CPU A. `hub_error_init` writes `0x016555aa` (both CPUs enabled), `0x01aaaaaa` (only A) and removes bit 21 afterwards; `hubpi_eint_handler` reads the mask of the processor it runs on (slice 0 reads this one). |
| `0x410` | `PI_ERR_INT_MASK_B` | 8 | rw | local/node | established | Error interrupt mask for CPU B. `hub_error_init` writes `0x009aaa55` (both CPUs enabled) or `0x01555555` (only B) and removes bit 20. |
| `0x418` | `PI_ERR_STACK_ADDR_A` | 8 | rw | local/node | established | Error stack address, CPU A: the memory address of the error stack. `hub_error_init` reads it (when CPU A is present) and keeps a software copy as the read pointer; `hubpi_spool_get_next` advances its own copy and compares it with this register to see whether hardware has written new entries. |
| `0x420` | `PI_ERR_STACK_ADDR_B` | 8 | rw | local | established | Error stack address, CPU B. As 0x418. |
| `0x428` | `PI_ERR_STACK_SIZE` | 8 | r | local/node | established | Error stack size code. `hub_error_init` computes the stack size as `4096 << (code - 1)` bytes (code 0: no stack); `dump_error_spool` reads it. |
| `0x430` | `PI_ERR_STATUS0_A` | 8 | r | local | established | Error status 0, CPU A. First-error latch: valid bit 63, overrun 62, address, command, type. Fields in the error section; read by `save_hub_pi_error`, `hubpi_spool_get_next`, `get_matching_spool_addr`. |
| `0x440` | `PI_ERR_STATUS1_A` | 8 | r | local | established | Error status 1, CPU A. Spool count, CRB timeout counter, invalidate counter, WRB or RRB number, CRB status, message source. Fields below. |
| `0x448` | `PI_ERR_STATUS1_A_RCLR` | 8 | w | local | established | Clear alias for error status 1, CPU A. `hubpi_spool_get_next` and `hub_error_init` store zero here to release the status registers after a read; the register is not read by any held code. |
| `0x450` | `PI_ERR_STATUS0_B` | 8 | r | local | established | Error status 0, CPU B. As 0x430. |
| `0x460` | `PI_ERR_STATUS1_B` | 8 | r | local | established | Error status 1, CPU B. As 0x440. |
| `0x468` | `PI_ERR_STATUS1_B_RCLR` | 8 | w | local | established | Clear alias for error status 1, CPU B. As 0x448. |

### LB: PI-space registers outside the contiguous map

| Offset | Name | Width | Access | Alias | Grade | What the held code shows |
|---|---|---|---|---|---|---|
| `0x20068` | `PI_HARDRESET_BIT` | 8 | w | node | inferred | Written once by the graphics flow-control routine at 0x395efc (no symbol). Name from the offset match only; role not read. |
| `0x30100` | `PI_RT_COUNT` | 8 | rw | local | established | Real-time counter. Read as a doubleword by `set_timer_intr`, `startkgclock`, `us_delay`, the I2C bit-bang timing, `hub_dmatimeout_kick` and the time-of-day code (161 sites): a free-running count used as the time base, compared as an unsigned difference. The PROM routine at 0x1fc5ac50 stores to it twice (initialisation, not read in full). The counter period is not read. |

### MD: memory and directory

| Offset | Name | Width | Access | Alias | Grade | What the held code shows |
|---|---|---|---|---|---|---|
| `0x200018` | `MD_MEMORY_CONFIG` | 8 | rw | local/node | inferred | Memory configuration, read by the directory access routines (`check_dir_access`, `get_dir_ent`, `show_dir_state`), `cpuprom_map` and `kf_memory_bank_disable`; written through the node alias. Field layout not read. |
| `0x200020` | `MD_REFRESH_CONTROL` | 8 | r | local | inferred | Refresh control. Read once by a PROM routine (0x1fc04700); no kernel access. |
| `0x200028` | `MD_FANDOP_CAC_STAT` | 8 | r | node | inferred | Fetch-and-op cache status, read by `fetchop_flush`. |
| `0x200030` | `MD_MIG_DIFF_THRESH` | 8 | rw | node | inferred | Page migration difference threshold: `migr_effthreshold_diff_set`, the migration interrupt handler and its prologue read and write it. |
| `0x200038` | `MD_MIG_VALUE_THRESH` | 8 | rw | node | inferred | Page migration value threshold: `migr_refcnt_init`, `numa_tune`, `mem_refcnt_ioctl` and the migration handlers read and write it. |
| `0x200048` | `MD_MIG_CANDIDATE_CLR` | 8 | r | node | inferred | Migration candidate, read-to-clear alias: the migration interrupt handler reads it to fetch the latest candidate. |
| `0x200050` | `MD_DIR_ERROR` | 8 | r | local/node | established | Directory error latch: `save_hub_md_error` (read in full) copies it when bit 63 is set; also read by `memerror_sbe_intr`. Fields below. |
| `0x200058` | `MD_DIR_ERROR_CLR` | 8 | r | local/node | established | Directory error, read-and-clear alias: `hub_error_clear`, `log_md_errors` and `memerror_sbe_intr` read it to clear the latch (the read value is discarded or logged). |
| `0x200060` | `MD_PROTOCOL_ERROR` | 8 | r | local | established | Protocol error latch: `save_hub_md_error` copies it when bit 63 is set. Fields below. |
| `0x200068` | `MD_PROTOCOL_ERROR_CLR` | 8 | r | node | established | Protocol error, read-and-clear alias, read by `hub_error_clear` and `log_md_errors`. |
| `0x200070` | `MD_MEM_ERROR` | 8 | r | local/node | established | Memory error latch: `save_hub_md_error` copies it when bit 63 is set; read by `memerror_sbe_intr`. Fields below. |
| `0x200078` | `MD_MEM_ERROR_CLR` | 8 | r | local/node | established | Memory error, read-and-clear alias, read by `hub_error_clear`, `log_md_errors`, `memerror_sbe_intr` and a PROM routine. |
| `0x200080` | `MD_MISC_ERROR` | 8 | r | local | established | Miscellaneous error latch: `save_hub_md_error` copies it when nonzero. The shipped decode prints it as "MD Misc Error" with no field breakdown. |
| `0x200088` | `MD_MISC_ERROR_CLR` | 8 | r | node | established | Miscellaneous error, read-and-clear alias, read by `hub_error_clear` and `log_md_errors`. |
| `0x2000a0` | `MD_MOQ_SIZE` | 8 | w | node | inferred | Outgoing queue size, written once by `per_hub_init`. |
| `0x2000a8` | `MD_MLAN_CTL` | 8 | rw | node | inferred | Microlan (NIC) control, read and written six times by one unnamed kernel routine at 0x6a4d0 that reads the board identification chip. |
| `0x2000c8` | - | 8 | w | node | unknown | Written once by `per_hub_init` with a value from a kernel variable. No name in the public header; role not read. |
| `0x2000d0` | - | 8 | r | node | unknown | Read by `hub_ifdr_fix_value`. No name in the public header; the routine fixes the I/O FIFO depth (0x400398), and these two reads feed its value; role not read. |
| `0x2000d8` | - | 8 | r | node | unknown | Read by `hub_ifdr_fix_value`, next to 0x2000d0. Role not read. |
| `0x2000e0` | - | 8 | rw | node | unknown | Read and written by `per_hub_init`. No name in the public header; role not read. |
| `0x210000` | `MD_PERF_SEL` | 8 | w | node | inferred | Memory performance counter select, written by `md_perf_start_count` and `md_perf_stop_count`. |
| `0x210010` | `MD_PERF_CNT0` | 8 | w | local | inferred | Memory performance counter 0; one PROM store (0x1fc0087c), probably a clear. |
| `0x220000` | `MD_UREG0_0` | 8 | rw | local/node | inferred | Junk-bus microcontroller register 0 ("UART 0 data/command"). The I2C master routines (`i2c_init`, `i2c_arb`, `i2c_master_xmit`, `i2c_master_recv`; the kernel prints "Hub I2C") read and write it to bit-bang the board identification bus, timed with the real-time counter; the PROM stores to it early in boot. |
| `0x220008` | `MD_UREG0_1` | 8 | rw | local/node | inferred | Junk-bus microcontroller register 1, used with 0x220000 by the same I2C routines (36 sites), and by the PROM. |
| `0x220048` | `MD_SLOTID_USTAT` | 8 | r | local/node | inferred | Slot identification: `get_my_slotid`, `get_node_slotid` and `sn0drv_ioctl` read it; the PROM reads it in a routine at 0x1fc5aa80. |
| `0x220050` | `MD_LED0` | 8 | w | local/node | inferred | LED register: the PROM writes a progress code here at 40 places on its boot path (the same routines also write 0x220080); the kernel writes it from `per_hub_init` and `hubni_error_handler`. |
| `0x220080` | `MD_UREG1_0` | 8 | w | node | inferred | Second junk-bus register written in lockstep with 0x220050 by the PROM boot routines (38 sites) and `per_hub_init`; named UART 1 in the public header. What the PROM sends through it is not read. |

### II: I/O interface

| Offset | Name | Width | Access | Alias | Grade | What the held code shows |
|---|---|---|---|---|---|---|
| `0x400008` | `IIO_WSTAT` | 8 | r | local/node | established | Widget status. `hubii_eint_handler` tests bit 32 (the "crazy" error bit, a link failure) and bits 9, 6 and 5 for the reason (micro-packet retry, crosstalk tail and credit timeout); `save_hub_io_error` copies it. Decode string: "32: Error (crazy) bit set". |
| `0x400020` | `IIO_WCR` | 8 | r | node | established | Widget control. `hub_widget_id` returns its low four bits as the node controller's own widget number. |
| `0x400110` | `IIO_IOWA` | 8 | rw | node | inferred | Outbound widget access mask: `hub_set_piomode`, `is_widget_pio_enabled` read it; `hub_widgetdev_shutdown` clears bits; one bit per widget (inferred from the widget-number shifts). |
| `0x400118` | `IIO_IIWA` | 8 | r | node | inferred | Inbound widget access: `hub_dma_enabled` and `hub_device_inquiry` read it. |
| `0x400120` | `IIO_IIDEM` | 8 | rw | node | inferred | Inbound device error mask: `hub_widgetdev_enable` and `hub_widgetdev_shutdown` read-modify-write it with a bit per device. |
| `0x400128` | `IIO_ILCSR` | 8 | rw | local/node | established | LLP control and status. `hubii_eint_init` reads it and tests bit 13 (link up): with the bit clear it clears bit 10 and returns without arming the I/O error interrupt; with it set it connects the interrupt. `hub_xtalk_link_up` reads it for link state; the PROM uses it in 0x1fc0230c. |
| `0x400130` | `IIO_ILLR` | 8 | rw | local/node | inferred | LLP log: `ii_llp_error_monitor`, `capture_hub_stats` and `init_hub_stats` read and clear it for link error counts. |
| `0x400138` | `IIO_IIDSR` | 8 | rw | node | established | Interrupt destination (the I/O error interrupt). `hubii_eint_init` (read in full) composes the word: bits 6:0 the level that `intr_heuristic` allocated, bits 16:8 the node number, bit 24 the enable, keeping the other bits it read; `hubii_eint_handler` clears bit 24 after servicing, so the interrupt stays off until re-armed. `bte_stall_node` and `hub_error_clear` also read or write it. |
| `0x400140` | `IIO_IGFX_0` | 8 | rw | node | inferred | Graphics node and widget register 0, written by the graphics flow-control routine at 0x39ba34. |
| `0x400160` | - | 8 | rw | node | inferred | First of a table of eight-byte entries indexed by a small number. `hub_piomap_alloc` and `hub_piomap_free` write entries; `hub_ioerror_handler` reads an entry (selected from the error code and a base of eight bytes per index) to turn a failed PIO address back into a widget address. Inferred to be the big-window translation table; not named in the public header. |
| `0x400190` | - | 8 | w | node | unknown | Written once by `mlreset`; no name in the public header; role not read. |
| `0x400198` | `IIO_IOPRB_0` | 8 | rw | node | established | PIO read buffer entry 0 (`PRB[%d]` in the shipped decode). `hubiio_prb_error_handler` (read in full) tests bit 48, "Write Resp Pkt Error", on entry 0 and then on entries 8 to 15 (0x1a0 to 0x1d8, indexed by eight); a set bit sends the entry to the CRB error path. `hub_setup_prb` programs the entries. |
| `0x4001e8` | `IIO_IMEM` | 8 | rw | node | established | Miscellaneous enable mask. `hubii_eint_handler` tests bits 0, 4 and 8 to name a shutdown ("Hub Widget 0 has been Shutdown", "BTE 0 ...", "BTE 1 ...") when no timeout bit in 0x400008 explains the error; `hub_xp_error_handler` and `bte_error_handler` write it. |
| `0x4001f8` | `IIO_IECLR` | 8 | rw | local/node | established | I/O error clear. `hubii_eint_handler` stores `0xffffff` (all error bits); `hub_error_clear` and `bte_error_handler` store to it as well. |
| `0x400200` | `IIO_IBCN` | 8 | w | node | inferred | CRB count (BTE), written once by `per_hub_init`. |
| `0x4002c8` | - | 8 | r | node | unknown | Read once by `hub_error_devenable`; no name in the public header; role not read. |
| `0x400308` | `IIO_PRTE_0` | 8 | rw | node | inferred | PIO read address table entry 0 (base of a family): `hub_widget_reset` read-modify-writes entries. |
| `0x400388` | `IIO_IPDR` | 8 | rw | node | inferred | PIO table entry deallocation: `hub_widget_reset` and `hub_error_devenable`. |
| `0x400390` | `IIO_ICDR` | 8 | rw | node | inferred | CRB entry deallocation: `hubiio_crb_free` writes the entry number to release it ("Releasing %s CRB"). |
| `0x400398` | `IIO_IFDR` | 8 | rw | node | inferred | I/O FIFO depth: `hub_init_ifdr_war`, `hub_ifdr_fix_value` and `hub_dmatimeout_kick` read it and rewrite it ("HUB II_IFDR fixed"); the kernel panics if it overflows. |
| `0x4003a8` | `IIO_ICMR` | 8 | rw | node | inferred | CRB management: `per_hub_init`, `hub_merge_clean`, `hub_dmatimeout_kick`. |
| `0x4003b0` | `IIO_ICCR` | 8 | rw | node | inferred | CRB control: read and written seven times by `bte_crb_error_handler`. |
| `0x4003b8` | `IIO_ICTO` | 8 | w | node | inferred | CRB timeout, written once by `per_hub_init`. |
| `0x4003c0` | `IIO_ICTP` | 8 | w | node | inferred | CRB timeout prescaler, written once by `per_hub_init`. |
| `0x400400` | `IIO_ICRB0_A` | 8 | rw | node | established | CRB entry 0, word A (first of a family: 15 entries of four words A to D, 0x20 apart; the loop in `save_hub_io_error` runs 15 times). The shipped decode of word A: bit 0 write, bit 1 valid, bits 39:2 network address, bits 44:40 crosstalk transaction number, bits 48:45 source, bit 49 crosstalk error, bit 50 marked, bit 51 uncorrectable data error, bits 55:52 error code, bit 56 error present. |
| `0x400408` | `IIO_ICRB0_B` | 8 | rw | node | established | CRB entry 0, word B (also entry 1, word B, at 0x400428). Read by `save_hub_err_ext` for all 15 entries, `crbx`, `dump_crb`, `kf_hub_analyze`. |
| `0x400410` | `IIO_ICRB0_C` | 8 | r | node | inferred | CRB entry 0, word C. Read by `crbx`, `dump_crb`, `bte_stall_node`. |
| `0x400418` | `IIO_ICRB0_D` | 8 | r | node | inferred | CRB entry 0, word D. Read by `crbx` and `dump_crb`. |
| `0x400428` | `IIO_ICRB1_B` | 8 | r | local | established | CRB entry 1, word B, read by `save_hub_err_ext` in the loop over entries. |
| `0x410000` | `IIO_IBLS_0` | 8 | rw | local/node | inferred | Block transfer engine 0 length and status. `save_hub_io_error` reads it; `bte_stall_node` writes it to stop the engine. The shipped decode: bits 15:0 length in cache lines, bit 16 error. |
| `0x410008` | `IIO_IBSA_0` | 8 | r | local | inferred | Block transfer engine 0 source address, read by `save_hub_io_error`. |
| `0x410010` | `IIO_IBDA_0` | 8 | r | local | inferred | Block transfer engine 0 destination address, read by `save_hub_io_error`. |
| `0x410018` | `IIO_IBCT_0` | 8 | r | node | inferred | Block transfer engine 0 control, read by `bte_stall_node`. |
| `0x420000` | `IIO_IBLS_1` | 8 | rw | local/node | inferred | Block transfer engine 1 length and status, as 0x410000. |
| `0x420008` | `IIO_IBSA_1` | 8 | rw | local/node | inferred | Block transfer engine 1 source address; `bte_stall_node` writes it, `save_hub_io_error` reads it. |
| `0x420010` | `IIO_IBDA_1` | 8 | rw | local/node | inferred | Block transfer engine 1 destination address; written by `bte_stall_node`. |
| `0x420018` | `IIO_IBCT_1` | 8 | rw | node | inferred | Block transfer engine 1 control; read and written by `bte_stall_node`. |
| `0x420020` | `IIO_IBNA_1` | 8 | w | node | inferred | Block transfer engine 1 notification, written by `bte_stall_node`. |
| `0x430000` | `IIO_IPCR` | 8 | rw | node | inferred | I/O performance counter control: `io_perf_start_count` and `io_perf_stop_count`. |
| `0x430008` | `IIO_IPPR` | 8 | r | node | inferred | I/O performance counter value: `io_perf_start_count` and `io_perf_update_count`. |

### NI: network interface

| Offset | Name | Width | Access | Alias | Grade | What the held code shows |
|---|---|---|---|---|---|---|
| `0x600000` | `NI_STATUS_REV_ID` | 8 | r | local/node | established | Network status, revision and identity. `get_nasid` (read in full) returns bits 16:8 as the node number; `get_hub_chiprev` returns bits 7:4 as the chip revision (the kernel compares it with 5 and 6 in `per_hub_init`). The PROM reads it very early (`start`). |
| `0x600008` | `NI_PORT_RESET` | 8 | w | local | established | Port reset. `ni_reset_port` (read in full) stores 129 (0x81); `hubni_error_handler`, `llp_pfail_intr`, `force_system_shutdown` and the PROM store here too, so a store resets the network port. The meaning of bit 0 and bit 7 is not read. |
| `0x600010` | `NI_PROTECTION` | 8 | r | local | inferred | Protection: read by `check_ni_errors` and `hubni_error_handler`. |
| `0x600018` | `NI_GLOBAL_PARMS` | 8 | rw | node | inferred | Global parameters, read-modify-written by `per_hub_init`. |
| `0x600100` | `NI_SCRATCH_REG0` | 8 | w | local | inferred | Scratch register 0, one PROM store (0x1fc00e94). |
| `0x600108` | `NI_SCRATCH_REG1` | 8 | rw | local | inferred | Scratch register 1: the PROM uses it as a state word across 0x1fc0230c and 0x1fc02d3c (14 sites). |
| `0x600110` | `NI_DIAG_PARMS` | 8 | rw | local/node | inferred | Diagnostic parameters, used by `per_hub_init` and `llp_pfail_intr`. |
| `0x600200` | `NI_VECTOR_PARMS` | 8 | w | node | inferred | Vector parameters. The vector routines (`vector_write_node`, `vector_read_node`, `vector_exch_node`) store it to start a router access; the order is data (0x210), vector (0x208), the age register, then parameters. |
| `0x600208` | `NI_VECTOR` | 8 | w | node | inferred | Vector (router path) for a vector access; first of the stores before the parameter store. |
| `0x600210` | `NI_VECTOR_DATA` | 8 | w | node | inferred | Vector data for a write. |
| `0x600300` | `NI_VECTOR_STATUS` | 8 | r | local/node | inferred | Vector status: the vector routines poll bit 63 with a 10 microsecond delay and test bit 62 for a timeout; the router strings ("Vector response timeout", "Invalid vector") name the failures. |
| `0x600310` | `NI_VECTOR_READ_DATA` | 8 | rw | node | inferred | Vector read data, read by `vector_read_node` and `vector_exch_node`. |
| `0x600380` | `NI_VECTOR_CLEAR` | 8 | r | node | inferred | Vector clear (read to clear): read by all three vector routines before a new access. |
| `0x600500` | `NI_AGE_CPU0_MEMORY` | 8 | rw | node | inferred | Age register for CPU 0 memory (public header name), read and rewritten by the vector routines (a bit cleared, 0x400 set) around each access. |
| `0x600510` | `NI_AGE_CPU1_MEMORY` | 8 | rw | node | inferred | As 0x600500 for CPU 1; selected by the processor slice. |
| `0x608008` | `NI_PORT_ERROR` | 8 | r | local/node | established | Port error. Read by `save_hub_ni_error`, `check_ni_errors`, `hubni_error_handler`, `hubni_print_state`, `ni_llp_error_monitor`; the shipped decode is in the error section. |
| `0x608088` | `NI_PORT_ERROR_CLEAR` | 8 | r | local/node | established | Port error, read-and-clear alias (read by `hub_error_clear`, `check_ni_errors`, `hubni_error_handler`, `llp_pfail_intr`, `capture_hub_stats`). |
| `0x638000` | `NI_META_TABLE0` | 8 | w | node | inferred | First meta-router table entry, written by an unnamed kernel routine (0x3ebf0). |
| `0x638100` | `NI_LOCAL_TABLE0` | 8 | w | node | inferred | First local routing table entry, written by the same routine. |

Registers the public headers define that no census row reaches: PI 39, MD 33, II 21, NI 12 (listed in the last section). They are
unknown, not absent: the kernel's computed-index loops (the CRB and PRB entry tables, the vector routines) reach more slots than
the scan records.


## Error and interrupt handling (established unless marked)

Functions read in full: `hub_error_init`, `hubpi_eint_handler`, `hubpi_spool_get_next`, `process_error_spool`,
`huberror_process_wrb_error`, `huberror_process_stack_entry`, `hubii_eint_init`, `hubni_eint_init`, `hubiio_prb_error_handler`,
`hub_ioerror_local`, `save_hub_pi_error`, `save_hub_md_error`, `save_hub_io_error`, `save_hub_ni_error`, `save_hub_err_ext`,
`hub_error_clear`. Not read in full: `hubii_eint_handler` (read to the point of the register traffic), `handle_uncac_buserr`
(read for the pending-bit tests and the spool lookup), `hub_ioerror_handler`, `hubni_error_handler`, `log_md_errors`.

### PI error interrupt pending (`0x400`), mask (`0x408`, `0x410`)

The decode text the kernel prints for this register (the "HUB error interrupt register" listing) names 25 bits. Odd bit numbers
are CPU A, even are CPU B (every pair is B at the even bit); the order agrees with `hub_error_init` and the handler, which pick
the A bit when the processor's slice is 0.

| Bit | Mask | Shipped text | Handler class |
|---|---|---|---|
| 0, 1 | `0x1`, `0x2` | B, A spool count compare | misc: `process_error_spool`, then clear |
| 2, 3 | `0x4`, `0x8` | B, A spurious message | misc: message printed, clear |
| 4, 5 | `0x10`, `0x20` | B, A write response block, **timeout** error | misc: `process_error_spool`, then clear |
| 6, 7 | `0x40`, `0x80` | B, A write response block, **write** error | misc: `process_error_spool`, then clear |
| 8, 9 | `0x100`, `0x200` | B, A SysState parity error | fatal |
| 10, 11 | `0x400`, `0x800` | B, A SysAd error during data cycle | fatal |
| 12, 13 | `0x1000`, `0x2000` | B, A SysAd error during address cycle | fatal |
| 14, 15 | `0x4000`, `0x8000` | B, A SysCmd parity error (the text says "address cycle") | fatal |
| 16, 17 | `0x10000`, `0x20000` | B, A SysCmd parity error (the text says "data cycle") | fatal |
| 18, 19 | `0x40000`, `0x80000` | B, A write or timeout error during spool | fatal |
| 20, 21 | `0x100000`, `0x200000` | B, A received uncorrectable error during an uncached load | the handler has a print-and-clear branch, but `hub_error_init` masks both bits out, so it never runs; the bits are read through the bus-error path |
| 22, 23 | `0x400000`, `0x800000` | SysState tag error (the text says B for both) | fatal |
| 24 | `0x1000000` | memory/directory uncorrectable error | `log_md_errors` |

"Fatal" is established from `hubpi_eint_handler`: when `pending & mask & 0xcfff00` is nonzero (bits 8 to 19 and 22 to 23)
it calls `enter_panic_mode`, prints "Fatal PI error interrupt received" and `kl_panic`. The misc bits (0 to 7, 20, 21) are
handled and cleared by storing the bit mask back to `0x400`.

**Masks (read in full in `hub_error_init`).** With both processors enabled (`0x50`, `0x58` nonzero) the CPU A mask is
`0x016555aa` and the CPU B mask `0x009aaa55`, then bit 21 is removed from A and bit 20 from B. With only A enabled the A mask is
`0x01aaaaaa`; with only B, the B mask is `0x01555555`. So each processor's error line carries its **own** misc errors (A: bits
1, 3, 5, 7), the **other** processor's fatal errors (A mask: bits 8, 10, 12, 14, 16, 18, 22), and bit 24; the uncached-load
bits 20 and 21 are always masked off. Slice 0 reads `0x408` in the handler, slice 1 reads `0x410`.

**Delivery.** `hub_error_init` calls `cause_intr_connect(6, hubpi_eint_handler)`: the PI error interrupt is level 6 of that
routine's eight-entry table (levels 2 and 3 are refused, 0 to 7 otherwise). That the level is a processor Cause interrupt-pending
bit number is **inferred** (the table is indexed by it; the dispatcher was not read).

### PI error status, error stack

- **Status 0** (`0x430` A, `0x450` B), fields from the shipped "HUB error status 0" text: bits 2:0 error type (the text splits
  it into read-buffer and write-buffer tables), 5:3 request (T5 RRB) number, 16:6 message supplemental, 24:17 message command,
  61:25 error address (a physical address shifted right by 3: the text prints `field << 3`), bit 62 overrun, bit 63 valid.
- **Status 1** (`0x440` A, `0x460` B), from the "HUB error status 1" text: bits 20:0 spool count, 28:21 CRB timeout counter,
  38:29 invalidate counter, 41:39 write- or read-buffer number, 52:43 CRB status, 63:53 message source. Bit 42 selects write
  buffer (1) or read buffer (0): `huberror_process_stack_entry` tests it as bit 42 of the second status word.
- **Error type tables** (shipped text). Read buffer: 0 read access error, 1 uncached partial read error, 2 directory error, 3
  timeout error. Write buffer: 0 write access error, 1 uncached partial write error, (2 printed as UNKNOWN); the code also
  treats **type 3 as a write timeout** (`huberror_process_wrb_error` branches on 3 with the same partition and page checks as
  type 0). Type 1 on a write buffer goes to `kl_ioerror_handler` (the PIO write error path), types 0 and 3 to the partition and
  page checks (`error_check_part_page`, `partition_handle_error`), anything else prints "Invalid WRB error type".
- **Release.** When the status registers hold a valid first error and the error stack has no entry, `hubpi_spool_get_next`
  reads status 0 and 1 and then **stores zero to `0x448` (A) or `0x468` (B)**, the register the public header calls the clear
  alias of status 1; no held code reads or writes the clear aliases of status 0 (`0x438`, `0x458`). Whether reading them clears
  status 0 is unknown.
- **Error stack.** The hardware appends entries to a memory ring whose end it exposes in `0x418` (A) / `0x420` (B); the size code
  is `0x428`. `hubpi_spool_get_next` keeps two software pointers per processor, advances the read pointer by 8 and compares it
  with the hardware pointer; entries are read from memory, not through registers. The stack entry fields the code uses: bit 12 is
  the write-buffer flag, bits 63:31 the address (shifted left by 7), and the low three bits the type. (The public header gives
  the type two bits; the kernel masks three, all valid types fit two.)

### Interrupts to the processor

| Source | Level | Programmed by |
|---|---|---|
| PI errors | cause level 6 | `cause_intr_connect(6, hubpi_eint_handler)` (`hub_error_init`) |
| NI errors, local | 126 | `intr_connect_level(cpu, 126, ...)` in `hubni_eint_init`, one connect for the node |
| NI errors, remote | 103 + slice | `hubni_eint_init` loop over the two slices |
| II errors | allocated at run time | `intr_heuristic` returns the level; `hubii_eint_init` writes it, the node number and the enable into `0x400138` |
| Memory/directory single-bit errors | not read | `install_eccintr` (called from `per_hub_init`) |

Levels 0 to 63 are in pending register `0x98` and mask `0xa8`, levels 64 to 127 in `0xa0` and `0xb0` (CPU A; CPU B's masks are
0x10 above): `intr_connect_level` writes `level + 64 * group` to `0x90` and sets bit `level` in a software mask. The II error
level number is not in the binary (inferred: whatever `intr_heuristic` hands out).

### MD error latches

The shipped decode text, with field positions:

- **Directory error** (`0x50`, clear alias `0x58`): bit 0 multiple correctable directory ECC, 1 multiple protection-rights error,
  2 multiple uncorrectable directory ECC, 28:3 bad directory space address, 38:32 bad directory syndrome, 41:39 bad access
  encoding, and the text labels bit 61 "uncorrectable directory ecc", 62 "protection rights ecc error", 63 "correctable directory
  ecc". **Conflict with the kernel's own logic**: `memerror_sbe_intr` (the single-bit-error handler) sends the case "bit 63 set"
  to `log_md_errors` (the hard-error path) and examines bit 61 for the correctable case, and the public header gives 63
  uncorrectable, 62 access error, 61 correctable. The decode text for bits 61 and 63 looks swapped; the code, the header and
  the single-bit handler agree with each other.
- **Memory error** (`0x70`, clear `0x78`): bit 0 multiple correctable, 1 multiple uncorrectable, 31:3 bad address pointer
  (shifted left by 3), 39:32 bad memory syndrome, 62 correctable, 63 uncorrectable. Agrees with the code (`memerror_sbe_intr`
  treats bit 63 as the hard error) and the public header.
- **Protocol error** (`0x60`, clear `0x68`): bit 0 multiple protocol errors, 31:3 request address (<< 3), 32 initiator same or not
  same as the directory pointer, 36:33 directory state (shared, poisoned, exclusive, busy shared, busy exclusive, wait,
  reserved, unowned), 37 requester priority, 39:38 initiator access, 47:40 request type, 49:48 backoff control, 60:50 request
  initiator (node and processor), bit 63 valid.
- **Misc error** (`0x80`, clear `0x88`): no field text.
- `save_hub_md_error` saves a latch only when its valid bit (63; for misc, any bit) is set. The clear aliases are **read** to
  clear (`hub_error_clear`).

### II and NI error latches

- **Widget status** (`0x400008`): bit 32 "Error (crazy) bit set"; when it is set `hubii_eint_handler` names the reason from
  bits 9 (micro-packet retry timeout), 6 (crosstalk tail timeout), 5 (crosstalk credit timeout), else from the enable-mask bits 0
  (widget 0 shutdown), 4 (block transfer engine 0), 8 (engine 1).
- **PIO read buffer entries** (`0x400198`, `0x4001a0` to `0x4001d8`): bit 48 "Write Resp Pkt Error". `hubiio_prb_error_handler`
  tests that bit on entry 0 and entries 8 to 15 and sends a set entry to the CRB error path.
- **CRB entries**: word A fields in the table above; the error code field (bits 55:52) selects a printed "(%s Error)" name.
- **I/O error clear** `0x4001f8`: `hubii_eint_handler` stores `0xffffff`. It also clears bit 24 of `0x400138`.
- **NI port error** (`0x608008`, clear alias `0x608088`): bits 7:0 count of link sequence-number errors, 15:8 check-bit errors,
  23:16 retries, then flags 24 to 27 virtual channel 0 to 3 receiver tail timeout, 28 to 31 virtual channel 0 to 3 credit
  timeout, 32 reserved, 33 receiver FIFO overflow, 34 message with the wrong destination, 35 bad network message, 36 bad internal
  message, 37 link reset detected (shipped text). `hubni_error_handler` resets the port by storing to `0x600008`.

## Access sequences (established unless marked)

- **Node number and identity.** `get_nasid`: read `0x600000`, shift right 8, mask `0x1ff`. `get_hub_chiprev`: read `0x600000`
  through the node alias, shift right 4, mask 15. `get_slice`: read `0x20`. `getcpuid` reads the node number and the slice
  with interrupts off and looks the pair up. The kernel compares the chip revision with 5 and 6 in `per_hub_init` (the string
  "hub chip of version 2.3 or better" is nearby; the revision-to-version mapping is the public header's, inferred).
- **Timer.** `hub_rtc_init`: store 1 to the real-time enables (`0x140`, `0x148`) and 0 to the profile enables (`0x150`, `0x158`).
  `set_timer_intr(cpu, when)`: if `when` is later than `0x30100`, store it to the compare register of the target slice
  (`0x108` or `0x110`) through the node alias, `sync`, read the counter again, and poke the processor if the time has passed.
  `acktmoclock` stores 0 to `0x120` or `0x128`. Profiling: `startkgclock` stores 1 to `0x150` or `0x158` and `counter + 1250` to
  `0x118`; `ackkgclock` stores 0 to `0x130` or `0x138`.
- **Error initialisation.** `hub_error_init`: clear (`hub_error_clear`), write the masks, read the error stack addresses
  (`0x418`, `0x420`) and size (`0x428`), connect the PI error interrupt (cause level 6), then `hubii_eint_init` and
  `hubni_eint_init`; if the cause connect fails it prints "cause_intr_connect failed" and still continues.
- **Error clear** (`hub_error_clear`, read in full): store `0xffffff` to PI pending `0x400` (bits 23:0; bit 24 is cleared in MD)
  and to II error clear `0x4001f8`, read the MD clear aliases `0x58`, `0x68`, `0x78`, `0x88` and the NI clear alias `0x608088`,
  and clear bit 24 of `0x400138`.
- **Router access (inferred).** `vector_write_node` stores the vector data (`0x600210`), the vector (`0x600208`), writes the age
  register, stores the parameters (`0x600200`), then polls status `0x600300` bit 63 with 10 microsecond delays up to a count and
  tests bit 62. It repeats up to eight times.
- **Junk bus.** The PROM stores progress codes to `0x220050` and `0x220080` together; the I2C master bit-bangs through
  `0x220000` and `0x220008`.

## Reset expectations

Established: `hub_error_init` and `hubii_eint_init` re-arm the error system from scratch (they do not read a register to compare
it with a reset value). Unknown: reset values of every register. No held code reads a register before writing it except to
read-modify-write.

## Error reporting for a refused or timed-out uncached write (and read)

Graded answers to the write-error questions, from the shipped kernel and PROM only. The sections above hold the evidence.

1. **What sets each error bit.** *Established as text, not as stimulus.* The shipped decode names the conditions. A write that
   the interconnect answers with an error sets the write-buffer bit "write response block, write error" (`0x40` B / `0x80` A);
   a write that gets no answer within the CRB time-out sets "write response block, timeout error" (`0x10` B / `0x20` A);
   a failure to write the error record to memory sets "write or timeout error during spool" (`0x40000` B / `0x80000` A, fatal in
   the kernel). A failed uncached **load** sets "received uncorrectable error during an uncached load" (`0x100000` B /
   `0x200000` A). Which transaction raises which response (a partial store, a store to a protected region, a store to a
   non-existent node, a router drop) is **unknown**: the decode says what the bit is called, no held code causes one.
2. **What is latched on a failed or timed-out write.** *Established.* The first error is held in status 0 and status 1 for the
   processor that issued it: valid (bit 63) and overrun (bit 62) flags, the target physical address (bits 61:25, shifted right by 3),
   the message command, supplemental and request number, the error type (write buffer: 0 write error, 1 uncached partial write
   error, 3 timeout), the CRB timeout counter, the write buffer number, the CRB status and the message source; the hardware also
   appends the error to the memory error stack. A second error while the first is held sets overrun (inferred from the name; the
   keep-first rule is inferred from the clear sequence: status is released by a store to `0x448`/`0x468`). For a failed **read** the
   same registers hold a read-buffer type (read access error, uncached partial read error, directory error, timeout error), and the
   CPU additionally takes a bus-error exception: `handle_uncac_buserr` first looks the faulting address up in the spool
   (`get_matching_spool_addr`), and only when none matches tests and clears the uncached-load pending bit.
3. **Which interrupt vectors fire.** *Established for the processor side.* PI errors: the processor-level-6 error interrupt, gated by
   `0x408` (CPU A) and `0x410` (CPU B); misc bits clear after service, fatal bits panic; the uncached-load bits are masked
   out, so a failed read arrives only as the bus error. NI errors: levels 126 (local) and 103 and 104 (per slice remote). II errors:
   a run-time level programmed into `0x400138`. *Inferred*: that a failed write to a **widget** raises the II error rather
   than the PI one (the "Hub nasid %d got a PIO Write error from widget %d" message is in the II path; the PI write-buffer bits are for
   writes the PI itself sees fail). *Unknown*: the processor line the cause level 6 maps to, the level number `intr_heuristic`
   hands the II error.
4. **A refused write to a Hub register itself.** *Established for the reporting, unknown for the trigger.* `hub_ioerror_local`
   (read in full) tests one bit of PI register `0` of the target node, selected by the accessor's node number, through the node
   alias and, whichever way that goes, calls `kl_panic` with "Hub Register Access Permission error" or "Hub Register Access
   error", naming the register address, node and processor. Which register writes are refused (PI/MD/II protection registers) is not read.
5. **What a failed write does to the CPU.** *Unknown from these files.* Whether the kernel's write-timeout case raises a bus-error
   exception or only the error interrupt (an R10000-family CPU posts the store) is not shown by the Hub code.

## Routines of the IP27 kernel that touch the node controller

Each entry below is one routine of `IP27/unix` (the linked IRIX 6.5.30 IP27 kernel), read in full from its disassembly. Addresses are
the symbol values; `local alias` and `node alias` are the two address forms defined under Addresses. Register names are the public
header names used in the tables above.

### Clock, timer and processor identity

- `ackkgclock` (`IP27/unix` `0xc000000000048588`, 56 bytes) acknowledges the profiling interrupt of the processor it
  runs on. It reads the halfword at absolute address `0xffffffffffffc420` (the processor number), indexes a table of
  16-byte entries with it, follows the pointer at entry +8 and tests the byte at +1312 of that record. A zero byte
  makes it store a zero doubleword to address 0x9200000001000130 (`PI_PROF_PEND_A`, local alias); any other value
  makes it store the zero to address 0x9200000001000138 (`PI_PROF_PEND_B`). Established for the stores; inferred that
  the byte is the processor's slice number.
- `acktmoclock` (`IP27/unix` `0xc000000000048550`, 56 bytes) is the same code path for the real-time (timeout)
  interrupt: the byte at +1312 of the processor record chooses between storing zero to address 0x9200000001000120
  (`PI_RT_PEND_A`, byte zero) and address 0x9200000001000128 (`PI_RT_PEND_B`). Established for the stores; inferred
  that the byte is the slice number.
- `startkgclock` (`IP27/unix` `0xc0000000000485c0`, 280 bytes, 32-byte frame) turns on the profiling clock for the
  calling processor under the lock at gp+2608. It takes that lock with `mutex_spinlock_spl` (second argument
  `splprof`), and on its first use calls `setkgvector` with the address of `prof_intr` and sets the word at gp-32360.
  If the word at address 0xffffffffffffc534 already holds 1250 it releases the lock with `mutex_spinunlock` and
  returns; otherwise it stores 1250 there, adds 1 to the word at +18736 of the record pointed to by the doubleword at
  address 0xffffffffffffc400, and stores 1 to address 0x9200000001000150 (`PI_PROF_EN_A`) when the byte at +1312 of
  the processor record is zero or to address 0x9200000001000158 (`PI_PROF_EN_B`) otherwise. When the word at +18736
  became 1, or when `cnodetocpu` of the halfword at address 0xffffffffffffc422 equals the processor number, it stores
  `PI_RT_COUNT + 1250` at +18728 of that record and again to address 0x9200000001000118 (`PI_PROFILE_COMPARE`). It
  ends by incrementing the word at gp-32356 and unlocking. Established.
- `slowkgclock` (`IP27/unix` `0xc0000000000486d8`, 216 bytes, 16-byte frame) is the opposite of
  `startkgclock`. The first call runs `spinlock_init` on the lock at gp+2608 with the name string "kgclock" and sets
  the word at gp-32352. It then takes the lock with `mutex_spinlock_spl`; when the halfword at gp-26608 equals the
  processor number and the word at gp-32416 is nonzero it unlocks and returns without touching the hardware. Otherwise
  it stores zero to `PI_PROF_EN_A` (address 0x9200000001000150, slice byte zero) or `PI_PROF_EN_B` (address
  0x9200000001000158), decrements the counters at gp-32356 and at +18736 of the current record when the word at
  gp-32360 is set, clears the word at address 0xffffffffffffc534, unlocks with `mutex_spinunlock` and calls
  `ackkgclock`. Established.
- `set_timer_intr` (`IP27/unix` `0xc000000000046648`, 248 bytes) arms the real-time compare of the processor numbered
  in its first argument for the absolute counter value in its second. When that value is zero or not later than
  `PI_RT_COUNT` (address 0x9200000001030100) it stores nothing, calls `timepoke` directly if the target is the calling
  processor and otherwise `cpuaction(cpu, timepoke, 1)`, and returns 0. Otherwise it adds the target's node number
  (the halfword at +1060 of its processor record) shifted left 32 to address 0x9200000001800000 and stores the value
  at +264 (`PI_RT_COMPARE_A`, slice byte zero) or +272 (`PI_RT_COMPARE_B`), runs `sync`, and reads the counter again.
  Calling itself, it runs `timepoke` and returns 0 when the counter has reached the value; for another processor it
  does so when the value is within 2 ticks of the counter. In every other case it returns 1. Established.
- `hub_rtc_init` (`IP27/unix` `0xc0000000000484f8`, 88 bytes) initialises the real-time and profile interrupt enables
  of one node, and only when its argument equals the result of `get_compact_nodeid`. It looks the node number up in
  the halfword table at `0xc0000000014d4e80`, adds it shifted left 32 to address 0x9200000001800000 and stores 1 at
  +320 (`PI_RT_EN_A`) and +328 (`PI_RT_EN_B`) and 0 at +336 (`PI_PROF_EN_A`) and +344
  (`PI_PROF_EN_B`). Established.
- `us_delay` (`IP27/unix` `0xc000000000047c0c`, 164 bytes) busy-waits for the number of microseconds in its first
  argument (taken as an unsigned 32-bit value). It multiplies by 1,250,000 (`0x1312d0`), divides by
  1,000,000 (`0xf4240`) and spins reading
  `PI_RT_COUNT` (address 0x9200000001030100) until the count is no longer below the start value plus that quotient.
  The constants give 1.25 counter ticks per microsecond, which matches the 1250-tick profile period of `startkgclock`
  being one millisecond (inferred). Established for the loop, which reads the counter five times per pass of its
  unrolled body.
- `get_realtime_ticks` (`IP27/unix` `0xc0000000000479a8`, 40 bytes) returns the signed quotient of
  `PI_RT_COUNT` minus the doubleword at address 0xc0000000014d2b40 (gp+2512) divided by the doubleword at address
  0xc0000000014d2b90 (gp+2592), truncated to its low 32 bits. The divisor is checked with a trap on zero. Established;
  inferred that gp+2512 is the count at boot and gp+2592 the ticks per output unit, because `init_timebase` writes the
  neighbouring words.
- `rtc_read` (`IP27/unix` `0xc0000000000465dc`, 12 bytes) returns the doubleword at address 0x9200000001030100
  (`PI_RT_COUNT`, local alias) and nothing else. Established.
- `init_timebase` (`IP27/unix` `0xc000000000045c68`, 216 bytes) starts the kernel's time base. It calls `rtodc` to
  read the time-of-day chip and stores the value at gp+6264 and through the pointer at gp-19488, stores `PI_RT_COUNT`
  at gp+2528, clears the words at gp+2524 and gp+2520 and the doublewords at gp+2552, gp+2544 and +8 of that pointer,
  then spins until the counter has advanced by 2,500,000 (`0x2625a0`, two seconds at the tick rate derived under
  `us_delay`). It calls `rtodc` again and, if the value is unchanged, calls `cmn_err` with level 4 and the message
  "System time-of-day chip is not advancing." followed by "CHECK AND RESET THE DATE!". Established; the two-second
  figure follows from the inferred tick rate.
- `get_nasid` (`IP27/unix` `0xc00000000001d664`, 28 bytes) returns bits 16:8 of the doubleword at address
  0x9200000001600000 (`NI_STATUS_REV_ID`, local alias): shift right 8, mask `0x1ff`, then sign-extend the low
  halfword. Established; the field is the node number because `getcpuid` and `get_hub_chiprev`'s callers use it as
  one.
- `get_slice` (`IP27/unix` `0xc00000000001d680`, 16 bytes) returns the low 32 bits of the doubleword at address
  0x9200000001000020 (`PI_CPU_NUM`, local alias). Established.
- `getcpuid` (`IP27/unix` `0xc000000000027178`, 116 bytes, 32-byte frame) raises the interrupt level with the routine
  at `0xc00000000003b30c` (the entry shared by `splhi` and the other `spl` names), calls `get_nasid`, reads
  `PI_CPU_NUM`, passes both to `nasid_slice_to_cpuinfo`, restores the level with `splx` and returns the halfword at
  +30 of the record found. When no record is found it calls `assfail` with the text "klcpu" and line number 1333.
  Established.
- `get_hub_chiprev` (`IP27/unix` `0xc00000000001d6a4`, 28 bytes) returns bits 7:4 of
  `NI_STATUS_REV_ID` read through the node alias: it adds its first argument (a node number) shifted left 32 to
  address 0x9200000001e00000, loads the doubleword there, shifts right 4 and masks 15. Established.
### Widget, slot and device lookups

- `hub_widget_id` (`IP27/unix` `0xc00000000001d64c`, 24 bytes) returns the low four bits of the doubleword at offset
  32 from address 0x9200000001c00000 plus its first argument (a node number) shifted left 32, which is `IIO_WCR`
  (`0x400020`) through the node alias. Established.
- `hub_check_is_widget0` (`IP27/unix` `0xc00000000003c1cc`, 124 bytes) tells whether an uncached address belongs to
  the node controller's own widget. It takes bits 39:32 of its first argument as the node number, forms
  `N = node << 32`, and returns 1 when the address lies in `[N + 0x9200000000000000, N + 0x9200000001000000)` or in
  `[N + 0x92000000e0000000, N + 0x9200000100000000)` and 0 otherwise. Established for the two ranges; inferred that
  they are widget 0's I/O windows, because the first ends where the register file at address 0x9200000001000000
  begins.
- `is_widget_pio_enabled` (`IP27/unix` `0xc000000000027be8`, 104 bytes) tells whether programmed I/O to a widget is
  allowed. Its argument is a device record: the halfword at +12 is a compact node number (-1 returns 0), looked up in
  the halfword table at `0xc0000000014d4e80` (-1 returns 0); the byte at +7 is the widget number. It reads the
  doubleword at offset 272 from address 0x9200000001c00000 plus the node number shifted left 32 (`IIO_IOWA`,
  `0x400110`, node alias) and returns 1 when the bit with the widget's number is set. Established.
- `hubdev_cnodeid_get` (`IP27/unix` `0xc00000000004c20c`, 48 bytes) calls `hwgraph_info_get_LBL` with its argument and
  the label string at `0xc00000000140fa18`, then returns the halfword at +8 of the record the call stored.
  Established.
- `hubdev_prombase_get` (`IP27/unix` `0xc00000000004c1d0`, 60 bytes) makes the same
  `hwgraph_info_get_LBL` call as `hubdev_cnodeid_get` and returns the halfword at +10 of the record shifted left 32
  and added to address 0x9000000030000000. Established; inferred that the halfword is the node number and the sum the
  node's PROM window.
- `hub_slot_to_crossbow` (`IP27/unix` `0xc00000000003cbc0`, 36 bytes) maps a slot byte to a crossbow number: the
  branch at address 0xc00000000003cbd0 returns 0 when the high nibble (mask `0xf0`) equals 80 (`0x50`), otherwise it
  returns `(slot - 1) & 1`. Established.
- `hub_slot_get` (`IP27/unix` `0xc00000000003cee0`, 36 bytes) calls `get_my_slotid` and returns the low four bits of
  the result. Established.
- `hub_xtalk_link_up` (`IP27/unix` `0xc000000000042fa0`, 40 bytes) returns 1 when bit 13 (`0x2000`) of the doubleword
  at offset 296 from address 0x9200000001c00000 plus its first argument (a node number) shifted left 32 is set, which
  is `IIO_ILCSR` (`0x400128`) through the node alias, and 0 otherwise. Established.
### Small wrappers and one-register routines

- `ni_reset_port` (`IP27/unix` `0xc00000000001d760`, 16 bytes) stores 129 (`0x81`) as a doubleword to address
  0x9200000001600008 (`NI_PORT_RESET`, local alias). Established.
- `md_perf_stop_count` (`IP27/unix` `0xc00000000005b9d8`, 24 bytes) stores a zero doubleword to address
  0x9200000001a10000 plus the node number shifted left 32, which is `MD_PERF_SEL` (`0x210000`) through the node alias;
  the node number is the halfword at +26 of its argument. Established.
- `sn0_skip_dump` (`IP27/unix` `0xc00000000003590c`, 24 bytes) calls `dumptlb` with the processor number from address
  0xffffffffffffc420 and then branches to itself, so it never returns. Established.
- `intr_block_bit` (`IP27/unix` `0xc0000000000389a0`, 28 bytes) calls `do_intr_block_bit` with its two arguments and a
  third argument of 1, which selects blocking, and returns. Established; inferred that 1 means block, from the partner
  routine passing 0.
- `intr_unblock_bit` (`IP27/unix` `0xc0000000000389bc`, 28 bytes) calls `do_intr_block_bit` with its two arguments and
  a third argument of 0 and returns, the unblocking counterpart of `intr_block_bit`. Established.
- `hub_intr_alloc` (`IP27/unix` `0xc00000000003bfbc`, 28 bytes) calls the symbol-less routine at `0xc00000000003bd0c`
  with a fourth argument of 0 and returns its result. The listing labels that address `hub_dmalist_drain`+0x64, which
  is a neighbouring symbol with no claim to it. Established.
- `hub_intr_alloc_nothd` (`IP27/unix` `0xc00000000003bfd8`, 28 bytes) calls the symbol-less routine at address
  0xc00000000003bd0c, as `hub_intr_alloc` does, with the fourth argument 1 instead of 0, and returns its result.
  Established.
- `hub_intr_cpu_get` (`IP27/unix` `0xc00000000003c158`, 28 bytes) takes the halfword at +36 of its argument as a
  processor number, finds that processor's record through the 16-byte table at `0xc0000000014d5020` (pointer at entry
  +8) and returns the word at +0x734 (1844) of it. Established.
- `hub_provider_shutdown` (`IP27/unix` `0xc00000000003c1b0`, 28 bytes) calls `xtalk_provider_unregister` and returns
  its result. Established.
- `early_counter_intr` (`IP27/unix` `0xc000000000047bb4`, 28 bytes) calls `resetcounter` with the argument formed by
  `lui 0xf000` and returns its result. Established.
- `router_reg_read` (`IP27/unix` `0xc00000000001b344`, 48 bytes) calls `hub_vector_read` with the halfword at +2, the
  doubleword at +24 and the word at +32 of its first argument (a router record) followed by its own second and third
  arguments. Established.
- `router_reg_write` (`IP27/unix` `0xc00000000001b374`, 48 bytes) makes the same call as `router_reg_read` but to
  `hub_vector_write`, with the halfword at +2, the doubleword at +24 and the word at +32 of the router record and its
  own second and third arguments. Established.
- `hubni_eint_handler` (`IP27/unix` `0xc000000000033324`, 36 bytes) calls `hubni_error_handler` with the string "NI
  interrupt" and 1. Established.
- `hubni_rmteint_handler` (`IP27/unix` `0xc000000000033348`, 36 bytes) calls `hubni_error_handler` with the string
  "Remote NI interrupt" and 0 where `hubni_eint_handler` passes 1. Established.
- `bte_avail` (`IP27/unix` `0xc00000000002c11c`, 12 bytes) returns 1 when the word at address 0xc0000000014cae78
  (gp-29432) is zero and 0 otherwise. Established; inferred that the word is a software flag, since no register is
  touched.
- `bte_disable` (`IP27/unix` `0xc00000000002d9d8`, 12 bytes) stores 1 to the word at address 0xc0000000014cae78
  (gp-29432) that `bte_avail` tests, which makes `bte_avail` return 0 from then on. Established.
- `callout_time_to_hz` (`IP27/unix` `0xc000000000046bf0`, 48 bytes) converts an absolute counter value to a tick
  count: the unsigned quotient of (argument minus `PI_RT_COUNT`) and the doubleword at address 0xc0000000014d2b90
  (gp+2592), truncated to 32 bits and raised to 1 when it is below 1. Established.
- `clear_hub_pi_error` (`IP27/unix` `0xc00000000002f634`, 88 bytes) walks two 8-byte slots of the error record in its
  argument. For each slot whose doubleword at +0x28 is nonzero it subtracts the doubleword at +0x18 from
  `PI_RT_COUNT`; when the difference exceeds
  90,000,000 (`0x55d4a80`) it stores zero doublewords at +0x38 and +0x28. Established; inferred that +0x18 holds the
  time of the last error and the threshold is 72 seconds at the tick rate under `us_delay`.

## Against the public headers (reported after the reading above)

No Hub specification is held, so there is no specification comparison. The Linux SN0 headers (`hubpi.h`, `hubmd.h`, `hubio.h`,
`hubni.h`, `addrs.h`) were compared with every row.

Agreements:
- 121 of the 132 census offsets equal an offset the headers define (the other 11: seven with no header name, `0x2000c8`,
  `0x2000d0`, `0x2000d8`, `0x2000e0`, `0x400160`, `0x400190`, `0x4002c8`, and the four CRB words `0x400408`, `0x400410`, `0x400418`,
  `0x400428`, which the headers define with an index macro). The census found them from code, not from the headers.
- Every PI error-interrupt bit position the shipped text prints, except the two noted below, equals the Linux `PI_ERR_*` mask; the
  status 0 field layout (type 2:0, request 5:3, supplemental 16:6, command 24:17, address 61:25, overrun 62, valid 63) and the status
  1 layout (spool 20:0, timeout 28:21, invalidate 38:29, number 41:39, flag 42, CRB status 52:43, source 63:53) equal Linux
  `PI_ERR_ST0_*` and `PI_ERR_ST1_*` exactly. The write error types (0 write error, 1 partial write error, 3 timeout) equal Linux
  `PI_ERR_WR_*`; the read types equal `PI_ERR_RD_*` plus the shipped "0 read access error".
- The memory error valid bits (62 correctable, 63 uncorrectable), the stack-entry write-buffer flag (bit 12) and address (63:31,
  shift 7), the I/O widget status error bit 32 (`IIO_WSTAT_ECRAZY`), the interrupt-destination enable bit 24 and node field starting
  at bit 8 (`IIO_IIDSR_ENB`, `_NODE`), and the whole network port error layout (`NPE_*`: counts in 7:0, 15:8, 23:16, tail timeouts
  27:24, credit timeouts 31:28, FIFO overflow 33, wrong destination 34, bad message 35, internal error 36, link reset 37) agree.

Conflicts and gaps:
- **SysCmd parity pair.** The shipped text labels bits 14 and 15 "SysCmd parity error during address cycle" and 16 and 17 "during data
  cycle"; Linux names `0x4000`, `0x8000` `SYSCMD_DATA` and `0x10000`, `0x20000` `SYSCMD_ADDR`. Same bit positions, opposite
  address and data labels. Both classify as fatal in the kernel, so no code depends on it.
- **Bit 23.** The shipped text says "CPU B SysState tag error" for both 22 and 23; Linux and the pair structure make bit 23 CPU A.
- **Interrupt destination fields.** `hubii_eint_init` keeps seven bits of level (`& 0x7f`) and nine of node number (`& 0x1ff`, shifted
  by 8); `IIO_IIDSR_LVL_MASK` is six bits and `IIO_IIDSR_NODE_MASK` eight (`0xff00`). `get_nasid` also masks nine bits. The header's
  widths fit its M-mode node numbering; the IRIX code is written for the wider field. No conflict for values below 64 and 256.
- **Directory error bits 61 and 63.** See the MD section: the shipped labels disagree with the single-bit-error handler and with
  Linux.
- Linux defines 105 registers the census does not reach. By block: PI 39, MD 33, II 21, NI 12. The
  ones the code surely reaches by computed index and the scan records only at their base: the `IIO_IOPRB_8` to `_F` entries and
  the CRB entries.


Public-header names with no census row, by block (not graded: untouched or reached by a computed index): PI: PI_PROT_OVERRD 0x8, PI_IO_PROTECT 0x10, PI_REPLY_LEVEL 0x60, PI_NMI_B 0x78, PI_SOFTRESET 0x80, PI_CC_PEND_SET_A 0xc8, PI_CC_PEND_SET_B 0xd0, PI_CC_PEND_CLR_A 0xd8, PI_CC_PEND_CLR_B 0xe0, PI_CC_MASK 0xe8, PI_RT_FILTER_CTRL 0x168, PI_BIST_WRITE_DATA 0x200, PI_BIST_READ_DATA 0x208, PI_BIST_COUNT_TARG 0x210, PI_BIST_READY 0x218, PI_BIST_SHIFT_LOAD 0x220, PI_BIST_SHIFT_UNLOAD 0x228, PI_BIST_ENTER_RUN 0x230, PI_GFX_PAGE_A 0x300, PI_GFX_CREDIT_CNTR_A 0x308, PI_GFX_BIAS_A 0x310, PI_GFX_INT_CNTR_A 0x318, PI_GFX_PAGE_B 0x328, PI_GFX_CREDIT_CNTR_B 0x330, PI_GFX_BIAS_B 0x338, PI_GFX_INT_CNTR_B 0x340, PI_ERR_STATUS0_A_RCLR 0x438, PI_ERR_STATUS0_B_RCLR 0x458, PI_SPOOL_CMP_A 0x470, PI_SPOOL_CMP_B 0x478, PI_CRB_TIMEOUT_A 0x480, PI_CRB_TIMEOUT_B 0x488, PI_SYSAD_ERRCHK_EN 0x490, PI_BAD_CHECK_BIT_A 0x498, PI_BAD_CHECK_BIT_B 0x4a0, PI_NACK_CNT_A 0x4a8, PI_NACK_CNT_B 0x4b0, PI_NACK_CMP 0x4b8, PI_NACK_CNT_EN_MASK 0x100000; MD: MD_IO_PROTECT 0x200000, MD_IO_PROT_OVRRD 0x200008, MD_HSPEC_PROTECT 0x200010, MD_MIG_CANDIDATE 0x200040, MD_MEM_DIMM_INIT 0x200090, MD_DIR_DIMM_INIT 0x200098, MD_PERF_CNT1 0x210018, MD_PERF_CNT2 0x210020, MD_PERF_CNT3 0x210028, MD_PERF_CNT4 0x210030, MD_PERF_CNT5 0x210038, MD_UREG0_2 0x220010, MD_UREG0_3 0x220018, MD_UREG0_4 0x220020, MD_UREG0_5 0x220028, MD_UREG0_6 0x220030, MD_UREG0_7 0x220038, MD_LED1 0x220058, MD_UREG1_1 0x220088, MD_UREG1_2 0x220090, MD_UREG1_3 0x220098, MD_UREG1_4 0x2200a0, MD_UREG1_5 0x2200a8, MD_UREG1_6 0x2200b0, MD_UREG1_7 0x2200b8, MD_UREG1_8 0x2200c0, MD_UREG1_9 0x2200c8, MD_UREG1_10 0x2200d0, MD_UREG1_11 0x2200d8, MD_UREG1_12 0x2200e0, MD_UREG1_13 0x2200e8, MD_UREG1_14 0x2200f0, MD_UREG1_15 0x2200f8; II: IIO_WID 0x400000, IIO_ILAPR 0x400100, IIO_ILAPO 0x400108, IIO_IGFX_1 0x400148, IIO_SCRATCH_REG0 0x400150, IIO_SCRATCH_REG1 0x400158, IIO_IOPRB_8 0x4001a0, IIO_IOPRB_9 0x4001a8, IIO_IOPRB_A 0x4001b0, IIO_IOPRB_B 0x4001b8, IIO_IOPRB_C 0x4001c0, IIO_IOPRB_D 0x4001c8, IIO_IOPRB_E 0x4001d0, IIO_IOPRB_F 0x4001d8, IIO_IXCC 0x4001e0, IIO_IXTT 0x4001f0, IIO_IPCA 0x400300, IIO_IIAP 0x4003a0, IIO_IBNA_0 0x410020, IIO_IBIA_0 0x410028, IIO_IBIA_1 0x420028; NI: NI_RETURN_VECTOR 0x600308, NI_IO_PROTECT 0x600400, NI_IO_PROT_OVRRD 0x600408, NI_AGE_CPU0_PIO 0x600508, NI_AGE_CPU1_PIO 0x600518, NI_AGE_GBR_MEMORY 0x600520, NI_AGE_GBR_PIO 0x600528, NI_AGE_IO_MEMORY 0x600530, NI_AGE_IO_PIO 0x600538, NI_PORT_PARMS 0x608000, NI_BASE_TABLES 0x630000, IIO_IIBUSERR 0x1400208.


## Routines of the IP27 kernel (`IP27/unix`)

One entry per routine, read in full from the linked IRIX 6.5.30 IP27 kernel. Addresses are the kernel's own. Register offsets
use the local alias of the table above (`0x9200000001000000 + offset`).

- `ackkgclock` (`IP27/unix` at 0xc000000000048588,
  56 bytes) acknowledges the profiling-clock interrupt of the calling processor. It indexes the table at
  0xc0000000014d5020 (`pdaindr`) with the halfword at 0xffffffffffffc420 times 16, loads the doubleword at +0x8 of
  that entry and tests the byte at +0x520 of the record it points to. A zero byte stores 0 to `0x9200000001000130`
  (`PI_PROF_PEND_A`); a nonzero byte stores 0 to `0x9200000001000138` (`PI_PROF_PEND_B`). No other register is
  touched. Inferred: the byte at +0x520 is the slice number, because it alone chooses between the two registers.
- `acktmoclock` (`IP27/unix` at 0xc000000000048550,
  56 bytes) is the same body for the real-time interrupt: the same table walk (halfword `0xffffffffffffc420`,
  `pdaindr`, +0x8, byte +0x520), then a store of 0 to `0x9200000001000120` (`PI_RT_PEND_A`) when the byte is zero and
  to `0x9200000001000128` (`PI_RT_PEND_B`) when it is not. The delay slot of the final return holds the store for the
  zero case. Inferred: slice 0 and slice 1, as for the profiling-clock routine.
- `bootstrap` (`IP27/unix` at 0xc000000000043738,
  208 bytes) is the first code the kernel runs. It writes `0x400080` to coprocessor-0 register 12, builds
  `0xa8000000000021d0` and ORs in the node number, which it reads from the doubleword at 0x9200000001600000 (bits
  16:8, the same network-status field that `get_nasid` decodes), and loads a pointer from that address. Two halfwords
  at +0x4 and +0x6 of the record it points to are the arguments of its call to `mapped_kernel_setup_tlb`. It then
  jumps to bootstrap+124 through its linked address `0xc0000000000437b4`, so the rest runs at the mapped kernel
  address. There it sets `gp` to `0xc0000000014d2170`, writes 0 to registers 18 and 19, `0x6000` to 5,
  7 to 6, `63 << 40` to 20, `0xc000` to 21 and 0 to 10, and jumps to
  `cboot` at 0xc000000000044860. Established: the sequence and constants. Inferred: the register meanings (page mask
  16 KiB, wired count 7) from the architecture's register numbers.
- `bte_avail` (`IP27/unix` at 0xc00000000002c11c,
  12 bytes) loads the word `disable_bte` at 0xc0000000014cae78 and returns 1 when it is zero, 0 otherwise
  (`sltiu v0,v0,1` in the delay slot of the return). It touches no register. Established.
- `bte_disable` (`IP27/unix` at 0xc00000000002d9d8,
  12 bytes) stores 1 to the word `disable_bte` at 0xc0000000014cae78 and returns; the store sits in the return's delay
  slot. Established. The copy routines compare this word with `maxcpus`, so the stored value acts as a processor-count
  threshold, and 1 is below every real count.
- `bte_free_interfaces` (`IP27/unix` at 0xc00000000002c68c,
  120 bytes) takes a node record in a0 and an interface number in a1. For interface 0 and then interface 1 it skips
  the one equal to a1; for the other it loads the interface record at `*(a0 + 104) + 21448 + 8 * i` and calls
  `nested_spinunlock` on the lock at +68 of that record. It returns no value. Inferred: it releases what
  `bte_get_all_interfaces` took, because the same table, offset +68 and lock call pair appear there.
- `bte_get_all_interfaces` (`IP27/unix` at 0xc00000000002c704,
  464 bytes) takes an interface record in a0 and the address of a saved interrupt-level word in a1. It takes the lock
  at +0x44 of both interface records (the records at `*(a0 + 104) + 21448 + 8 * i`, i = 0 then 1) with a call to
  `nested_spintrylock`; when a try fails it runs `splx` on the saved level, `us_delay(1)` and
  `splhi`, stores the new level and tries the same lock again. It then walks both interfaces and skips an interface
  that is missing, is the caller's own (the word at +0x54 equals i) or has its bit clear in the byte at a0 + 66. For
  any other it reads the doubleword that `*(*record)` addresses and, while bit 20 (`0x100000`) is set and bit 12
  (`0x1000`) is clear and the doubleword that the pointer at +40 addresses is not `0x1000`, drops to the saved level,
  delays 1 and retakes it, until the counter at 0x9200000001030100 passes the word at +0x70 plus the counter value
  read on entry to that step. It returns 0 with both locks held. Inferred: bits 20 and 12 describe a busy engine,
  because the loop waits on them; their definition is not read here.
- `bte_init_buffers` (`IP27/unix` at 0xc00000000002c044,
  216 bytes) runs for each node below the word `maxnodes` (`0xc0000000014d3e24`) and, for each of two buffers per
  node, calls `kmem_zalloc_node(16384, 2305, node)` and stores the pointer in the table whose base is the pool
  doubleword at 0xc0000000014cd1f0 (slot `2 * node + k`, 8 bytes each). A failed allocation calls `cmn_err` with level
  4 and the text "bte_init_buffers:buffer %d on node %d not allocated". Every slot, failed or not, also gets a zero
  byte at table + 1024 + slot, and each node ends with `spinlock_init` on the word at table + 1152 + 4 * node. After
  the last node it stores a zero byte at 0xc0000000014ca244. Established.
- `bte_lateinit` (`IP27/unix` at 0xc00000000002c128,
  716 bytes) builds the two block-transfer interface records of the calling node, i = 0 and 1, under the node record
  at the doubleword `0xffffffffffffc400`. An existing record at `+21448 + 8 * i` is kept and, when the doubleword at
  0xffffffffffffc718 is empty and i equals the low bit of the halfword at 0xffffffffffffc420, copied there. A missing
  one starts as `kmem_zalloc_node(120, 1, node)` (its pointer also goes to that doubleword under the same parity
  test), then a 1024-byte buffer from `kmem_zalloc_node(1024, 2305, node)`, and the routine at 0xc00000000002bf5c (no
  symbol) is called with the block, the buffer and i. What it returns becomes the record stored at `+21448 + 8 * i`
  and gets the node record at +104; interface 0 gets a 4-byte lock initialised as "bte_recover" at +96 and interface 1
  copies that pointer. Each record then gets a zeroed 16384-byte page and an unzeroed one; both must lie in
  `0xa800000000000000` to `0xa800010000000000` (an `IS_KSEG0(zpage)` assertion in the binary), and their low 40 bits are stored at +8 and +16. A second loop ORs bits 0 and 1 into the

  byte at +66 of both records. Established: the sequence. Inferred: +8 holds the zero page and +16 the poison page,
  from the allocation failure texts ("BTE zero page", "BTE poison transfers").
- `bte_pbcopy` (`IP27/unix` at 0xc00000000002c3f4,
  192 bytes) copies a0 to a1 for a2 bytes. When the word
  `disable_bte_pbcopy` (`0xc0000000014cae74`) is nonzero and `maxcpus` is not below it, or the same holds for
  `disable_bte`, it calls `bcopy` with both addresses ORed with `0xa800000000000000`. Otherwise it calls
  `bte_copy(a0, a1, a2, 16)` and falls back to the same `bcopy` only when that returns nonzero. It returns 0 on every
  path. Established.
- `bte_pbzero` (`IP27/unix` at 0xc00000000002c4b4,
  472 bytes) zeroes a1 bytes at a0. If a1 is 0 it returns 0. A nonzero `disable_bte_pbzero` (`0xc0000000014cae70`) or
  `disable_bte` that `maxcpus` has reached sends it to `bzero` (destination ORed with `0xa800000000000000`); if
  a2 is set it first saves the halfword at +0xf6 of the record at 0xffffffffffffc020, stores 5 there, and puts the
  saved value back after `bzero`. Otherwise it calls `get_hub_chiprev` for the node's Hub revision, picks mode 16
  below revision 5 and 17 from revision 5 up, and issues `bte_copy(0, dest, n, mode)` in pieces of at most 16384
  bytes. A status of 0 from the last piece returns 0, a status other than 1 is returned as it is, and a status of 1
  falls back to the `bzero` path for the whole range. Established.
- `bte_poison_copy` (`IP27/unix` at 0xc00000000002d874,
  84 bytes) calls `bte_copy(a0, a1, a2, 272)` unless a2 is 0, in which case it returns 0. A nonzero status is logged
  through `cmn_err` at level 12 with the text "bte_poison_copy: Returning error status %d" and returned; a zero status
  returns 0. Established: mode 272 is `0x110`, which sets bit 8, the bit `bte_copy` tests at 0x2cdc8 before calling
  `poison_state_clear`.
- `bte_poison_range` (`IP27/unix` at 0xc00000000002d8c8,
  272 bytes) works on the range a0 for a1 bytes and returns 0 when a1 is 0. It compares `maxcpus` with
  `disable_bte_poison_range` (`0xc0000000014cae6c`) and `disable_bte` the way `bte_pbcopy` does. When block transfer
  is disabled it calls `poison_state_alter_range(a0 | 0xa800000000000000, a1, 1)` and returns 0. Otherwise it calls
  `bte_copy(addr, 0, n, 272)` in pieces of at most 16384 bytes and returns 0 after the last. A status of 1 makes it
  call `poison_state_alter_range` on the remaining range with the same third argument and return 0; any other nonzero
  status is returned. Established.
- `bte_wait_for_xfer_completion` (`IP27/unix` at 0xc00000000002d9e4,
  116 bytes) takes an interface record in a0, reads the doubleword at 0x9200000001030100 and the status doubleword
  that `*a0` addresses, and returns at once when its low 16 bits are 0. Otherwise it polls both until the low 16 bits
  clear or the counter passes the first reading plus 500. On timeout with bits left it calls `cmn_err` at level 20
  with "II_IFDR_WAR: BTE running after %d usecs wait. Remaining Length 0x%x", 500 and the remaining count times 128.
  It returns no value. Established; it matches the Hub status layout (bits 15:0 length in cache lines) already
  recorded for the block transfer engines.
- `bte_bpush_war` (`IP27/unix` at 0xc00000000003b1cc,
  292 bytes) takes a node number in a0 and a record pointer in a1 and always returns 0. It does nothing unless the
  word `bpush_war_enable` (`0xc0000000014caf48`) is nonzero and a1 is not null, and nothing when `get_hub_chiprev` of
  that node's number (a halfword table at 0xc0000000014d4e80, 2 bytes a node) is 5 or more or when the node's bit is
  already set in the doubleword `bte_stall_node_mask` (`0xc0000000014d2b10`). Otherwise it pins the thread with
  `rt_pin_thread` and compares the byte at a1 + 5 with the low byte of `bpush_source1` (`0xc0000000014caf44`),
  `bpush_source2` (`0xc0000000014caf40`), `bpush_source3` (`0xc0000000014caf3c`) and `bpush_source4`
  (`0xc0000000014caf38`) in that order. A match calls `bte_stall_node` on the node; the routine ends with
  `rt_unpin_thread`. Inferred: it stops the block-transfer engines of a Hub older than revision 5 when a push from a
  listed source is seen, from the callee and the variable `bpush_war_enable`.
- `callout_time_to_hz` (`IP27/unix` at 0xc000000000046bf0,
  48 bytes) subtracts the real-time counter at 0x9200000001030100 from a0, divides the difference by the doubleword at
  0xc0000000014d2b90 with `ddivu` (a zero divisor traps with code 7) and returns the low 32 bits of the quotient, or 1
  when that is below 1. Inferred: it converts a counter deadline to a tick count, because the quotient is a counter
  span divided by a period.
- `chkdebug` (`IP27/unix` at 0xc000000000039af4,
  80 bytes) walks `pdaindr` with the halfword at 0xffffffffffffc420 times 16, loads the byte at +1312 behind the
  entry's +8 pointer, reads the doubleword at 0x92000000010000a0 (`PI_INT_PEND1`) and, when bit `54 + byte` of it is
  set, calls the routine at 0xc0000000000397fc (no symbol) with 0. It returns no value. Inferred: the byte is the
  slice number, so the bit is level 118 for slice 0 or 119 for slice 1, since the register holds levels 64 to 127.
- `clear_hub_md_error` (`IP27/unix` at 0xc00000000002f68c,
  200 bytes) takes a pointer to a record in a0 holding four pairs of a timestamp and a saved error word, at +16 and
  +24, +0 and +8, +32 and +40, +48 and +56. For each, in that order, a nonzero word is cleared to 0 when the counter
  at 0x9200000001030100 has advanced more than `0x55d4a80` (90,000,000 ticks) beyond its timestamp. It writes no
  register. Inferred: it ages out four saved memory-error records, because it applies the same age test as
  `clear_hub_pi_error` to words that `check_md_errors` (the memory-error checker) sits beside.
- `clear_hub_pi_error` (`IP27/unix` at 0xc00000000002f634,
  88 bytes) takes a record in a0 and, for slice 0 and then slice 1, tests the doubleword at +40 + 8 * slice. When it is
  nonzero and the counter at 0x9200000001030100 is more than `0x55d4a80` (90,000,000 ticks) past the doubleword timestamp at
  +24 + 8 * slice, it stores a zero doubleword to +56 + 8 * slice and then to +40 + 8 * slice. No register is written.
  Inferred: the two doublewords are a processor-interface error summary and detail saved earlier.
- `check_dir_access` (`IP27/unix` at 0xc00000000002a184,
  128 bytes) takes a physical address in a0. It reads `MD_MEMORY_CONFIG` (offset `0x200018`) through the node alias
  `0x9200000001a00000 + (bits 39:32 of a0 << 32)`, forms a directory address from `(a0 >> 3) & 0x1f0`,
  `a0 & 0xff00000000` and `(a0 >> 2) & 0x3ffffc00`, ORs in `0x90000000c0000200` and reads the doubleword there. If bit
  28 of the configuration is set it returns bit 7 of that word; otherwise bit 5 of its low 16 bits. Established: the
  decode. Inferred: the bit is the access-permission flag of the entry, from the routine's name and the two entry
  layouts it selects between.
- `cpuprom_map` (`IP27/unix` at 0xc00000000006ba98,
  204 bytes) calls `prominfo_nodeget` with a0 and returns 5 when that gives 0. Otherwise it calls
  `hubdev_prombase_get` and `hubdev_cnodeid_get` on the result, then `v_mapphys(a1, prombase, min(a3, 0x10000000))`,
  and returns that status when it is nonzero. On success it takes the node's number from the halfword table at
  0xc0000000014d4e80 (2 bytes a node), reads `MD_MEMORY_CONFIG` (offset 0x200018) through the node alias
  `0x9200000001a00000 + (node << 32)`, clears bits 53:44 with the mask `0xffc00fffffffffff` and ORs in `257 << 44`
  when the byte at `0xffffffffffffc523` is zero, or `121 << 46` when it is not. It writes the result back and returns 0.
  Established: the sequence and constants. Inferred: it maps the node's PROM window and then sets a 10-bit field of
  the memory configuration register, because the field and both values come straight from the constants and nothing
  else reads that field here.
- `bte_unaligned_copy` (`IP27/unix` at 0xc00000000002d620,
  596 bytes) takes source a0, destination a1, length a2 and flags
  a3. It returns 1 without copying when the word `disable_bte` is nonzero and `maxcpus` has reached it, and 0 for a
  zero length. If the low seven bits of a0 and a1 differ it copies the whole range in one step and returns that step's
  status: `bcopy` when a3 bit 13 (`0x2000`) is clear, otherwise the routine at 0xc00000000002d398 (no symbol) with bit
  12 (`0x1000`) of a3 cleared. If they are equal it copies in this order: the head, of length
  `min(a2, 128 - (a0 & 0x7f))` and absent when a0 is aligned and a2 is 128 or more, then the tail, the last
  `(a2 - head) & 0x7f` bytes, each by the same `bcopy` or 0xc00000000002d398 choice, and last the 128-byte multiple in
  the middle by `bte_copy` with a3 & ~0x1000, in pieces of at most 0x7fff80 bytes. A nonzero status ends the routine
  with that status; the normal result is 0. Established: the paths and constants. Inferred: bit 13 requests the engine
  and bit 12 is private to the helper, from which of them each call clears or tests.
- `check_md_errors` (`IP27/unix` at 0xc000000000033798,
  588 bytes) takes a physical address in a0, an output pointer in a1, an age limit in a2 and a pointer to a record
  pointer in a3. It takes the node number from bits 39:32 of a0, maps it with `nasid_to_compact_node` and indexes the
  pointer table `kl_error_log` at 0xc0000000014dd768 with it, returning 0 when there is none. It starts at
  `md_err_log_last` of that log, or at `md_err_log_prev` of the record already at a3, and walks back through
  `md_err_log_prev`. A record older than the limit (the counter at `0x9200000001030100` minus the stamp at +0x8 is not
  below a2, which is skipped when a2 is -1) stores 0 at a3 and returns 0; any other record is stored at a3 first. For
  a record whose kind word at +0x10 is 1, 2 or 3 it compares the saved address at +0x0 with
  a0, shifted and masked as `check_dir_access` forms a directory address (kind 1) or against `scache_linemask` (kinds
  2 and 3); a match stores the saved address through a1 and returns the kind. Kind 4 is skipped and any other kind
  calls `kl_panic`. Established: the walk and the compares. Inferred: the walk finds the saved memory error that
  covers a0, because it returns the kind and the saved address only on a match.
- `bte_stall_node` (`IP27/unix` at 0xc00000000003ae1c,
  944 bytes) takes a node number in a0. It returns at once when `verify_snchip_rev` gives 5 or more or when the word
  at +0x5138 of the node record is 0. It sets the node's bit in `bte_stall_node_mask` with a `lld`/`scd` retry loop
  (`beqzl` at 0xc00000000003ae60) and returns if the bit was already set. It then calls
  `kmem_alloc_node(512, 2305, node)` and clears bit 24 (the interrupt enable) of the doubleword at +0x138 of the
  node's II block, reached through `0x9200000001c00000`, keeping the old value. It then drives the two block-transfer
  engines at `0x9200000001c10000` and `0x9200000001c20000`, the one at `0x9200000001c20000` first when the byte at
  +0x520 of the processor record is 0. The first engine gets source 0xff00000000 at +0x8, the buffer's low 40 bits at
  +0x10, `0x10001` at +0x0, the buffer plus 256 at +0x20 and 16 at +0x18, and is polled with `us_delay(1)` until the
  low 16 bits of +0x0 are 0. After `us_delay(10)` the other engine gets the same words with source and destination
  swapped and is polled up to 100000 times for bit 16 of +0x0. It then walks 15 CRB entries of 32 bytes at +0x400 of
  the II block and, for each whose word A has bit 50 set and bits 39:2 shifted left 3 equal to 0xff00000000 and whose
  word C has bit 48 set, stores word A with bit 1 set under the mask `0xff0bffffffffffff` and word B ANDed with
  `0xfffffe01ffffffff`. It writes 0 to both +0x0 words, restores +0x138, calls `bte_error_handler` for each `pdaindr`
  entry in the node's processor range (first index the halfword at +0x4956 of the node record, count the halfword at
  +0x4958) whose first word is not -1, with the record at +0x718 behind its +0x8 pointer plus 0x28, after clearing the
  byte at +0x42 of that record, and ends with `kmem_free(buffer, 512)`. Established: the register sequence and
  constants. Inferred: a recovery step for a stuck engine, because it quiesces the error interrupt, drives both
  engines with one-line transfers, edits the matching CRB entries and then runs the engine error handler.
- `err_int_block_mask` (`IP27/unix` `0xc000000000035604`, 68 bytes) takes a bit mask as its first argument.
  It reads the halfword at address `0xffffffffffffc420` (the processor number), indexes the 16-byte table at
  0xc0000000014d5020 with it, follows the pointer at +0x8 of the entry and loads the byte at +0x520 (1312) of that
  record (the slice, 0 or 1; inferred, as in `ackkgclock`). It then clears in the
  doubleword at `0x9200000001000408 + 8 * slice` (`PI_ERR_INT_MASK_A` for slice 0, `PI_ERR_INT_MASK_B` for slice 1,
  local alias) the bits of `a0 >> slice`, a read-modify-write that ANDs the register with the complement. The store sits
  in the delay slot of the return. It returns no value and touches no other register. Established.
- `err_int_unblock_mask` (`IP27/unix` `0xc000000000035648`, 76 bytes) takes a bit mask and a flag.
  It finds the processor's slice as `err_int_block_mask` does (halfword at address 0xffffffffffffc420, the table at
  0xc0000000014d5020, +0x8, byte +0x520).
  It computes `a0 >> slice`; the shift is in the delay slot of the flag test, so it runs whether or not the flag is set.
  When a1 is nonzero it first stores that shifted mask to `0x9200000001000400` (`PI_ERR_INT_PEND`, local alias), which
  clears the pending bits it names, per the write-back rule in the error section. It then sets those bits in the
  doubleword at `0x9200000001000408 + 8 * slice` (the A or B interrupt mask) with an OR and stores it in the delay slot
  of the return. Established; the pending-clear meaning of the store is inferred from the stores in `hubpi_eint_handler`.
- `force_system_shutdown` (`IP27/unix` `0xc00000000003fc54`, 100 bytes) logs "Powering off the system." with
  `cmn_err(4, ...)` (the string at `0xc00000000140d2f0`), waits `us_delay(500000)` (0x7a120) and calls
  `elsc_system_reset` with the global at `0xc0000000014ddd78`. A result of zero or more returns. A negative result prints
  "MSC Reset command failed.Doing warm reset" with `printf`, waits `us_delay(1000000)` (0xf4240) and stores 129 (0x81)
  as a doubleword to `0x9200000001600008` (`NI_PORT_RESET`, local alias; the store is in a delay slot) before it
  returns. Established. Inferred: the system-controller reset is the first choice and the port reset the fallback,
  because the port reset runs only after the controller's call fails.
- `get_my_slotid` (`IP27/unix` `0xc00000000003cd64`, 36 bytes) loads the doubleword at `0x9200000001220048`
  (`MD_SLOTID_USTAT`, local alias), masks its low byte with `andi 0xff` in the delay slot of the call, and returns
  what `hub_slotbits_to_slot` makes of it. Established.
- `get_node_slotid` (`IP27/unix` `0xc00000000003cd38`, 44 bytes) is the same read for another node: it adds the node
  number in a0, shifted left 32, to `0x9200000001a20000` and loads the doubleword at +0x48 of the sum, which is
  `MD_SLOTID_USTAT` through the node alias. It passes the low byte of that to `hub_slotbits_to_slot` and returns the
  result. Established.
- `early_pckminit` (`IP27/unix` `0xc0000000000a1f44`, 40 bytes) loads the pointer at the literal-pool slot gp-16864
  (`0xc0000000014cdf90`, which holds `0xc0000000014f70c8`) and from it the doubleword at +1112, which is the global
  `pckm_cons_funcs` at `0xc0000000014f7520`. A zero value returns at once; otherwise it calls through it with
  `jalr` and returns the callee's value. Established. The routine touches no register. Inferred: the function
  pointer is the keyboard driver's early-initialisation entry, because the global holds the keyboard console table.
- `gfx_flow_flush_my_wg` (`IP27/unix` `0xc000000000396840`, 24 bytes) loads the doubleword at address
  0x9200000001030100 (`PI_RT_COUNT`, local alias) and stores it to its own stack slot, discarding it, then returns. Established for the
  read and the discard. Inferred: the load exists to make earlier posted writes complete, because its value is not
  used and nothing else in the routine has an effect.
- `hub_check_window_equiv` (`IP27/unix` `0xc00000000003c248`, 104 bytes) takes two addresses.
  It calls `hub_check_is_widget0` on each; when both answers are nonzero it returns 1 (the `li` is in the delay slot of the
  branch to the return). When either is zero it compares bits 31:24 of the two addresses (`dsrl 0x18`, `andi 0xff`) and
  returns 1 when they are equal and 0 otherwise. The instruction at 0xc00000000003c280 is not reached. Established.
- `hub_check_pci_equiv` (`IP27/unix` `0xc00000000003c2b0`, 136 bytes) takes two addresses and returns 0 when
  `hub_check_window_equiv` says they differ. Otherwise it compares their low 24 bits (mask 0xffffff from `lui 0xff` and
  `ori 0xffff`; the compare is at address 0xc00000000003c2e4) and returns 0 on a mismatch. When those match it extracts bits 39:32 of each address, sign-extended
  from 16 bits, and returns `check_nasid_equiv` of the two with a third argument of 0. Established. Inferred: the
  bits 39:32 are the node number, because they are the argument of a routine whose callee takes node numbers.
- `hub_dmamap_alloc` (`IP27/unix` `0xc00000000003bad8`, 128 bytes) builds a 16-byte map record for a device.
  It calls `xwidget_info_get` with its first argument, then `xwidget_info_id_get` and `xwidget_info_master_get` on
  the result, and `kern_malloc(16)`. The new record gets the first argument as a word at +0x0, the widget id as a
  byte at +0x4, the master as a word at +0x8 and a flag word of 1 at +0xc. When bit 0 of the fourth argument is set
  the flag word is 5 instead. It returns the record without testing the allocation. Established; inferred: flag bit 2
  marks a map that may be used again, because the routines that take a map complain only when it is clear.
- `hub_dmamap_free` (`IP27/unix` `0xc00000000003bb58`, 40 bytes) clears bit 0 of the flag word at +0xc of the map
  record (mask -2, stored in the delay slot of the call) and calls `kern_free` on the record. It returns what
  `kern_free` returns. Established.
- `hub_dmamap_addr` (`IP27/unix` `0xc00000000003bb80`, 92 bytes) returns its second argument unchanged, the
  physical address it was given. It first reads the flag word at +0xc of the map record: with bit 1 clear it sets that
  bit and stores the word back (the store is in the delay slot of the return); with bits 1 and 2 both set it stores
  nothing; with bit 1 set and bit 2 clear it first calls `cmn_err(4, ...)` with the text "%v: hub_dmamap_addr re-uses
  dmamap." and the word at +0x0 of the record. Established; inferred: bit 1 means in use.
- `hub_dmamap_list` (`IP27/unix` `0xc00000000003bbdc`, 92 bytes) has the same shape as the routine at 0xc00000000003bb80
  with its own message: it returns its second argument unchanged and sets bit 1 of the flag word at +0xc when that bit
  was clear.
  When bit 1 was set and bit 2 clear it calls `cmn_err(4, ...)` with "%v: hub_dmamap_list re-uses dmamap" and the
  word at +0x0 first. With bit 2 set it skips the message. Established.
- `hub_dmamap_done` (`IP27/unix` `0xc00000000003bc38`, 80 bytes) reads the flag word at +0xc of the map record. When
  bit 1 is set it clears that bit (mask -3) and returns. When bit 1 is clear and bit 2 is set it returns with no
  store. When both are clear it calls `cmn_err(4, ...)` with "%v: hub_dmamap_done already done with dmamap" and the
  word at +0x0 of the record. It returns no value. Established; inferred: it ends the use that `hub_dmamap_addr` or
  `hub_dmamap_list` began.
- `hub_dmatrans_addr` (`IP27/unix` `0xc00000000003bc88`, 8 bytes) returns its third argument unchanged: the only
  instruction besides the return, `or v0,a2,zero`, is in its delay slot. It touches no memory, and the next routine at
  0xc00000000003bc90 has the same two instructions. Established.
- `hub_dmatrans_list` (`IP27/unix` `0xc00000000003bc90`, 8 bytes) is the same two instructions as the routine at
  0xc00000000003bc88: it returns its third argument and nothing else, so a translated address passes through
  unchanged. Established.
- `hub_dmamap_drain` (`IP27/unix` `0xc00000000003bc98`, 8 bytes) is a return with a no-op in its delay slot: it reads
  no argument and writes nothing, so draining a map does nothing in this kernel. Established for the body; the
  routine at 0xc00000000003bca0 has the same two instructions.
- `hub_dmaaddr_drain` (`IP27/unix` `0xc00000000003bca0`, 8 bytes) is also a return and a no-op, the second of three
  such back-to-back routines (the others are at 0xc00000000003bc98 and 0xc00000000003bca8). It reads no argument
  and has no effect. Established.
- `hub_dmalist_drain` (`IP27/unix` `0xc00000000003bca8`, 8 bytes) is the third of those routines: a return with a
  no-op in the delay slot and no effect. The symbol-less routine at 0xc00000000003bcb0 follows it. Established.
- `hub_piomap_done` (`IP27/unix` `0xc00000000003ba04`, 8 bytes) is a return with a no-op in the delay slot. It touches
  no argument and no memory, so finishing a programmed-I/O mapping has no work to do here; the routine at
  0xc00000000003ba0c follows it. Established for the body.
- `hub_piomap_addr` (`IP27/unix` `0xc00000000003b9a4`, 96 bytes) takes a map record, an address and a length. It
  returns 0 when the address is below the doubleword at +0x8 of the record, or when the end of the range (address plus
  length) is past +0x8 plus the doubleword at +0x10. Otherwise, when bit 0 of the word at +0x28 is set, it returns the
  doubleword at +0x18 plus the address modulo the one at +0x10 (`ddivu`, `mfhi`; the `teq` at 0xc00000000003b9e4 traps
  on a zero divisor); with bit 0 clear it returns 0. Established; inferred: +0x8 is the mapped base, +0x10 its size and
  +0x18 the window address, because the checks and the sum use them so.
- `hub_intr_cpuid_get` (`IP27/unix` `0xc00000000003c174`, 8 bytes) returns the halfword at +0x24 (36) of its
  argument, sign-extended (`lh` in the delay slot of the return). Established; inferred: the record is an interrupt
  handle and the halfword the target processor number, as the routines that connect and free it pass it to
  `intr_connect_level` and `intr_unreserve_level` first.
- `hub_intr_connect` (`IP27/unix` `0xc00000000003c06c`, 136 bytes) takes an interrupt handle and four more
  arguments. It calls `intr_connect_level` with the halfword at +0x24, the words at +0x28 and +0x20 of the handle,
  the second and third arguments and 0. A negative result is returned as it is. Otherwise it stores the fourth
  argument at +0x18 and the fifth at +0x10, calls the fourth with the handle when it is nonzero, sets bit 2 of the
  word at +0x2c and returns 0. Established.
- `hub_intr_disconnect` (`IP27/unix` `0xc00000000003c0f4`, 100 bytes) calls the function at +0x18 of the handle
  first when that doubleword is nonzero (the handle and the word at +0x28 are its arguments), then
  `intr_disconnect_level` with the halfword at +0x24, and clears bit 2 of the word at +0x2c (mask -5). The value left
  in v0 is that mask, not a result. Established.
- `hub_intr_free` (`IP27/unix` `0xc00000000003bff4`, 120 bytes) saves the halfword at +0x24 and the word at +0x28
  of the handle. When bit 2 of the word at +0x2c is set it zeroes the byte at +0x5 and the doubleword at +0x8,
  stores -1 to the word at +0x0 and calls `hub_intr_disconnect`. When bit 0 of that word is set it calls `kmem_free`
  with a size of 48 (0x30). It ends with `intr_unreserve_level` on the saved processor and level and returns
  its result. Established.
- `hub_error_status_war` (`IP27/unix` `0xc000000000035034`, 96 bytes) reads
  `PI_CPU_NUM` (`0x9200000001000020`) and, for a nonzero value, `PI_ERR_STATUS0_B` (`0x9200000001000450`),
  otherwise `PI_ERR_STATUS0_A` (`0x9200000001000430`).
  If bit 63 of the status read is set it returns at once. If clear, it calls `_badaddr_val` with address
  0x9200000002400208, size 8 and a stack buffer, the deliberate bus-error read described under Addresses, and returns
  its result; the early return leaves v0 unset. Established for the sequence; inferred: a workaround that forces an error cycle when the
  first-error latch is empty.
- `hub_error_count_enable` (`IP27/unix` `0xc000000000035238`, 172 bytes) takes an index below 256. It maps the index
  through the halfword table at 0xc0000000014d4c80 to a slot of the pointer table at 0xc0000000014dd768 plus 0x200.
  A negative or too large index, an index whose halfword is -1, or a record whose first word is already nonzero returns
  -1. Otherwise it zeroes the record (`blkclr`, 64 bytes), stores 1 to its first word and calls
  `timeout` for `hub_error_count_update` with the index and 100 ticks, returning 0. Established.
- `hub_error_count_disable` (`IP27/unix` `0xc0000000000352e4`, 84 bytes) checks the index as
  `hub_error_count_enable` does and stores 0 to the first word of the record that index selects. It returns 0, or -1
  for a bad index or a -1 halfword in the table at 0xc0000000014d4c80. It cancels nothing. Established.
- `hub_error_count_get` (`IP27/unix` `0xc000000000035338`, 88 bytes) takes an index and a pointer. Using the table at
  0xc0000000014d4c80, for a valid index
  it stores 64 (the record size) as a word through the pointer and returns the record's address; for a bad index or a
  -1 halfword it returns 0 and stores nothing. Established.
- `hub_error_count_update` (`IP27/unix` `0xc0000000000351c0`, 120 bytes) is the periodic job that
  `hub_error_count_enable` starts. It finds the record for its index and calls `ii_llp_error_monitor` on record +8
  and `ni_llp_error_monitor` on record +32. While the first word of the record is nonzero it calls `timeout`
  for itself again with the index and 100 ticks. Established.
- `hub_ifdr_check_value` (`IP27/unix` `0xc000000000028ecc`, 112 bytes) reports whether the I/O FIFO depth field
  needs lowering on a node. It returns 0 at once when the word `hubio_ifdr_skip` (0xc0000000014ca210) is nonzero.
  Otherwise it takes bits 14:8 (`dsrl 8`, mask 0x7f) of the doubleword at +0x398 (`IIO_IFDR`) of the node's II
  window and returns 1 when the halfword at +0x4c84 of the node's record is below it, and 0 otherwise. The window
  is `0x9200000001c00000` plus the halfword that the table at 0xc0000000014d4e80 holds for the node, shifted left 32;
  `hub_ifdr_fix_value` and `hub_init_ifdr_war` reach it the same way. Established.
- `hub_ifdr_fix_value` (`IP27/unix` `0xc000000000028f3c`, 236 bytes) rewrites the I/O FIFO depth field of one node.
  It returns -1 when bits 14:8 of the doubleword at +0x398 of the node's II window (`IIO_IFDR`; the
  window is found as in `hub_ifdr_check_value`) are above 64. Otherwise it adds 1 to the halfword at +0x4c82 of the
  node's record and polls the doublewords at +0xd0 and +0xd8 of the window at `0x9200000001a00000`
  up to 99 times, waiting until bits 23:17 of both are zero (the second test is a branch-likely, so the count
  drops in its delay slot only when it is taken). If the poll runs out it stores the +0xd0 value to
  `last_reqqd_val` and the +0xd8 value to `last_repqd_val` and adds 1 to `wait_exceeded`. In either case it ends by
  replacing bits 14:8 of `IIO_IFDR` with the low seven bits of the halfword at +0x4c84 of the record and returns 1.
  Established; the two polled registers (0x2000d0 and 0x2000d8) have no public name.
- `hub_init_ifdr_war` (`IP27/unix` `0xc000000000028dd0`, 252 bytes) takes a node number. It sets the halfword at
  +0x4c82 of the node's record to 0, the halfword at +0x4c84 to 40 (0x28) and the word at +0x4c7c to the word
  `hub_ifdr_war_freq` (0xc0000000014ca214). It then reads `IIO_IFDR` at +0x398 of the node's II window, and when 40
  is below its bits 14:8 it replaces those bits with 40 (the same mask as `hub_ifdr_fix_value`); for node 0 only it
  first prints "HUB IFDR value not correctly set. Please upgrade your prom" with `cmn_err(5, ...)`. It returns
  no value. Established.
- `hub_migrintr_init` (`IP27/unix` `0xc000000000039bac`, 108 bytes) calls `cnodetocpu` with its own argument and,
  unless the word `numnodes` (0xc0000000014d3e1c) is 1 or the processor number is -1, calls `intr_connect_level`.
  The arguments are that processor, level 3, 0, `migr_intr_handler`, 0 and `migr_intr_prologue_handler`.
  A nonzero result prints "hub_migrintr_init: Can't connect interrupt." with `cmn_err(0, ...)`. It returns
  no value. Established.
- `hub_dma_enabled` (`IP27/unix` `0xc0000000000277e8`, 196 bytes) takes a device vertex. It gets the widget id and
  master vertex with `xwidget_info_id_get` and `xwidget_info_master_get`, then looks up the label `_node` on the
  master with `hwgraph_info_get_LBL`. It returns 0 for a missing label or a node number of -1 (the halfword at +0xa
  of the label's record). Otherwise it reads the doubleword at +0x118 (`IIO_IIWA`) of that node's II window and
  tests the bit numbered by the widget id (low byte): set returns 1; clear prints "No Inbound access" with the
  widget and node numbers through `cmn_err(6, ...)` and returns 0. Established.
- `hub_error_devenable` (`IP27/unix` `0xc000000000027b24`, 196 bytes) takes a device vertex and a code in its third
  argument. It finds the node as `hub_dma_enabled` does. For code 5 it reads the doubleword at +0x2c8 plus 8 times the
  widget id (low byte) of the node's II window; when bit 56 of it is set it stores the widget id ORed with
  0x10 to +0x388 (`IIO_IPDR`). Code 6 and every other code do nothing. It returns 0 on every path and does not
  test for a missing label. Established.
- `hub_device_flags_set` (`IP27/unix` `0xc00000000003c508`, 148 bytes) takes a device vertex and a flag word. It
  gets the widget id and master vertex, looks up the `_node` label for the node record, takes the lock at +0x318 of
  that record with `mutex_spinlock`, calls `hub_widget_flags_set` with the halfword at +0xa of the record, the widget
  id (low byte) and the flags, releases the lock with `mutex_spinunlock` and returns the result of
  `hub_widget_flags_set`. Established.
- `hub_piotrans_addr` (`IP27/unix` `0xc00000000003ba0c`, 196 bytes) takes a device vertex in its first argument, the
  address and length in its third and fourth and flags in its fifth. It finds the node record as
  `hub_device_flags_set` does and returns 0 when address plus length is above 0x1000000 (`lui 0x100`). Otherwise it
  calls `hub_piomap_addr` on the 48-byte widget record at +0x10 plus 48 times the widget id, with the address and
  length, and returns its result; when bit 3 (0x8) of the flags is set it ORs in `7 << 59` first. Established.
- `hub_provider_startup` (`IP27/unix` `0xc00000000003c17c`, 52 bytes) takes one argument and passes it to three
  routines in turn, the ones at 0xc00000000003b440, 0xc00000000003bad0 and 0xc00000000003bcb0, none of which has a
  symbol of its own. It returns the last one's result. Established.
- `gfx_flow_delayed_hiwater_intr_prehandler` (`IP27/unix` `0xc000000000395e6c`, 144 bytes) indexes
  `gfx_flow_cpu_attachments` with the processor number (halfword at address 0xffffffffffffc420). When the entry is
  not zero it calls the function at +0x20 of the entry with the argument at +0x28, and a flag that is 1 when bits 4:3
  of the doubleword at +0xf8 of its second argument equal 2. It then finds the processor's slice (+8 of the 16-byte
  entry of `pdaindr`, byte +0x520) and stores 0 to `0x9200000001000000` plus 40 times the slice plus 792, that is
  0x318 (`PI_GFX_INT_CNTR_A`) or 0x340 (`PI_GFX_INT_CNTR_B`), followed by `sync`. Established.

### Further routines of the IP27 kernel (`IP27/unix`)

Read in full from the linked IRIX 6.5.30 IP27 kernel, one entry per routine, after the entries above; addresses are the kernel's own. These routines reach the
Hub's registers, or the Hub's real-time counter, through the aliases described at the top of this page.

- `crbx` (`IP27/unix` at 0xc000000000028054,
  3312 bytes) dumps the fifteen I/O-interface CRB entries of one node as text. It takes the node number in `a0` and a
  printf-style output routine in `a1`, kept in `s1`; every line goes out through `jalr s1`. It prints "NASID %d", then seven
  fixed heading lines naming the columns of the four entry words. It builds the node alias from the literal-pool word
  `0x9200000001c00000` (the Hub node alias plus the I/O block offset 0x400000) and, for entry `i` = 0 to 14 (stride 0x20,
  the loop ends when `slti i,15` fails), loads four doublewords at +0x400, +0x408, +0x410 and +0x418 of
  `base + (node << 32) + 0x20 * i`: words A, B, C and D. From A it prints bits 57, 56, 55, 54:52, 51, 50, 49, 48:45,
  44:40, bits 39:2 shifted left 3 (a byte address) and bits 1 and 0, with the entry number first. From B it takes the
  two-bit kind in bits 42:41 and builds an eight-byte mnemonic from the command number in bits 40:33: kind 0 prefixes "XT" and
  compares `(B >> 33) & 0xaf` against seven values, kind 1 prefixes "BT" and uses a 65-entry table, kind 2 prefixes "LN" and uses a
  256-entry table, kind 3 prefixes "CR" and knows five values (0, 1, 2, 4, 8). The two tables are `jr` tables whose targets each
  copy a fixed name (for example "VRD", "VERRPCA", "RDSH", "PRDH", "GFXWS", "UPACK") into a stack buffer; an unlisted value
  calls `sprintf` with "??0x%02x?". Bits 29:25 of B index an 18-entry `jr` table of operation names ("PRDC", "DEX", "WB",
  "BLKR", "WRIO", "BSHU", "BEXU", "RDEX", "WINV", "PIOR", "PIOW" among them; values 10 to 15 and 18 or more take the default
  `sprintf` of "??%d??"). Bits 32:30 of B pick one of five short strings (values 0, 1, 2, 3 and 5; any other takes the "??" text).
  The rest of B, all of C and the bits of D are printed through the callback with four more formats. Besides the callback the only call
  is `sprintf` (0xc0000000001fd9d0). It writes no register and returns nothing. Established: the access addresses, loop,
  table indices and print order. Inferred: that A, B, C and D are the CRB entry words, from the `dump_crb` entry in the
  hub datasheet that decodes the same offsets.
- `memerror_sbe_intr` (`IP27/unix` at 0xc000000000049e74,
  2596 bytes) handles a correctable (single-bit) ECC error report for one node. `a0` is 0 when called from the interrupt (the
  messages then carry the tag "intr", otherwise "polled") and `a1` is the node number, which `get_nasid` replaces when `a0` is 0.
  It maps the node with `nasid_to_compact_node`, loads that node's record pointer at +0x4d20 and returns at once when the
  first word it points to is nonzero. It reads `MD_DIR_ERROR` (+0x50) and `MD_MEM_ERROR` (+0x70) from the alias
  `0x9200000001a00000 + (node << 32)`; if bit 63 of either is set the error is uncorrectable, so it calls `log_md_errors`
  and returns. Otherwise it reads the clearing aliases `MD_DIR_ERROR_CLR` (+0x58) and `MD_MEM_ERROR_CLR` (+0x78) and tests
  one flag in each. With neither flag it prints "Unexpected uncorrectable directory/memory ECC error", "Unexpected protection
  rights ECC error" or "Spurious correctable ECC error interrupt" (only when `a0` is 0) and returns. A directory error prints
  the tag, directory word, memory address and decoded syndrome (`mdir_xlate_syndrome`; the width argument is 2 when bit 28 of
  the doubleword at +0x18 is set, else 1) and the address translation `mdir_xlate_addr_pdir` (bit set) or
  `mdir_xlate_addr_sdir`, prints the DIMM bank (`get_slotname`), then calls `memory_present` and `page_ispoison`. A present,
  unpoisoned page is repaired by reading the word at its uncached address (`0xa800...`) and writing it back once (eight times at
  stride 0x80 when the address is in the 0x30000000 window), each followed by `__cache_wb_inval` (length 8), and "Single-bit error
  has been repaired." is printed. A memory error uses `mdir_xlate_addr_mem` and one write-back, and when bit 62 of `MD_MEM_ERROR`
  is 1 it reads a byte through a `0x9000000080000000`-based address and re-reads +0x78: bit 62 still 1 prints "Hard Single-bit
  error.", else "Single-bit error has been repaired."; bit 62 not 1 prints "Transient read error ignored". A missing page prints
  "Memory address not present!" and a poisoned one "Ignoring correctable error in poisoned page". `panic_on_sbe` nonzero calls
  `cmn_err` (level 0). A count at +0x128 of the record (window ending at the `time` held at +0x12c, reset to `time + 60`)
  reaching 600 calls the static routine at 0xc000000000049d48. Up to 16 records of four words from +0x8 remember page numbers
  (`addr >> 14`) with a type bit, a count and an expiry; expired ones are compacted out. A repeat count equal to
  `sbe_max_per_page` prints "Excessive single-bit ECC corrections in pfn %d", the bank line, calls `page_discard` (1, 0) and
  sets the expiry to `time + 600`; equal to `sbe_maxout` calls 0xc000000000049d48; a full table of 16 does too. It returns nothing.
  Inferred: the exact flag bits tested, because the decompiled masks were not re-read in the disassembly, and the role of the
  static at 0xc000000000049d48, which was not read.
- `sn0drv_ioctl` (`IP27/unix` at 0xc00000000006aa10,
  2252 bytes) is the ioctl entry point of the node-controller character driver. It takes the device vertex in `a0`, the command in
  `a1`, the user argument in `a2` and a pointer for the call's return value in `a5`, and keeps its error number in the
  stack word at 0(sp), which it returns. A command from 8 to 22 goes through a 15-entry `jr` table at 0xc0000000003c52e0
  (command 14, 20 and 21 and every command outside the range take the default arm and return what `sndrv_ioctl_common` returns).
  The arms that reach the driver's own code check what kind of node the vertex is with `device_info_get` (kind 1, 2, 3 or 4 by
  command; a mismatch returns 22) and, for the ones that change state, call `cap_able` with `1 << 37` (a refusal returns 1);
  a failed `copyin` or `copyout` returns 14. The commands: 8 and 9 enable and disable the memory-directory performance counters
  (label `_mdperf`, then `md_perf_node_enable` or `md_perf_node_disable`, kind 2, privileged); 10 and 11 copy out the counter values
  (288 bytes, `md_perf_get_node_count`) and the control word (4 bytes, `md_perf_get_node_ctrl`) of that label; 12 resolves the
  vertex's node with `nodevertex_to_cnodeid` (22 when it is -1), reads eight words with `memerror_get_stats`, fills the unused
  ones with -1 and copies out 32 bytes (kind 2, privileged); 13 reads or writes the system controller's NVRAM
  (`elsc_nvram_read` for flag bit 0, `elsc_nvram_write` for bit 1, otherwise error 5), copying in 12 bytes and out 12 bytes, under
  the controller's spinlock and `setmustrun` on a processor of that node (kind 3, privileged); 15 copies in 112 bytes, calls
  `rou_fence_op` on a processor of the node and copies 112 bytes back (label `_rou_fence`, kind 1, privileged);
  16 copies out the 6-byte port map from `router_port_map_get`, 17 copies in 8 bytes and copies out 8 bytes of
  `router_port_mfg_info_get` (both after `check_router`); 18 searches the label `_nic` string for "Laser:" and
  copies out the hexadecimal number after it (`strtoull`, base 16) as 8 bytes; 19 copies in 96 bytes and runs `elsc_command`
  (kind 4, privileged); 22 writes to the return-value pointer bits 7:4 of the doubleword at +0x48 of
  `0x9200000001a20000 + (node << 32)` when the string of label `_mon`, taken through `nic_hub_vertex_info`, contains "IP31", else the
  value 15. Inferred: the command meanings, which come from the callees and label names (`_mdperf`, `_rou_fence`, `_nic`, `_mon`).
- `handle_cac_buserr` (`IP27/unix` at 0xc000000000036e50,
  1644 bytes) classifies a bus error taken by a cached access. It takes the exception frame in `a0`, the faulting physical
  address in `a1` (node number in bits 47:32) and a flag in `a2` (the value 1 suppresses the not-populated message). It first calls
  `get_matching_spool_addr` for the cache-line-aligned address (mask from the word at `gp + 0x1eec`), and a result of -1 prints "Lost
  spool info on cached buserr". For results 1 and 2 it takes the saved Hub error word of the PI spool entry: a 3-bit type from bits
  2:0 and a flag (bit 12 of the first word for result 1, bit 42 of the second for result 2); a set flag calls `kl_panic` and returns 3, a
  type other than 2 or 3 prints "Cached read access: bad error type" and returns 3. Type 2 (directory error) calls
  `log_md_errors`, prints "directory error" unless `a2` is 1, and then: a node in another partition (`nasid_to_partid` against
  `part_id`) returns what `partition_handle_error` gives for kind 4; otherwise `error_page_discard` (1, 1) failing with any result
  except 0 or 1 prints "Page with memory/directory error could not be discarded" and returns 2, `error_check_part_page` nonzero
  returns `partition_handle_error` (kind 4), and the normal result is 2. Type 3 (time-out) from another partition returns
  `partition_handle_error` (kind 1), a partition page returns it too, and a local one prints "time out error" and returns 3.
  With no spool match it checks that the node's region is populated (`nasid_to_region` against a bitmask at the pool pointer,
  printing "region not populated" and returning 3), then for a node in this partition looks up the faulting instruction type
  (`error_lookup_inst_type`; a result of -1 is treated as a store) and asks `error_check_memory_access`,
  `error_check_poisoned_state`, `memory_iscalias` and `klerror_check_recoverable` (type 3); a recoverable error returns 0 (or 2 when the
  memory-access check says so); when `verify_snchip_rev` is below 5 and bits 6:2 of the frame's word at +0x118 equal 0x18 it prints
  "trying to recover from ibus error" and returns 0; an unrecoverable one prints the "Unrecoverable bus error exception" block, reads
  the directory entry words through `0x90000000c0000200`/`0x90000000c0000208` (the pool words), calls `get_dir_ent` and, for a
  directory state of 3 or 4 with an I/O-owned bit set, `dump_crb`, and returns 3. A node in another partition returns
  `partition_handle_error` with kind 5 or 6 when the page check fails. Inferred: the meanings of the type values and return
  codes, which come from the message text and the partition-handler name.
- `bte_copy` (`IP27/unix` at 0xc00000000002cbdc,
  1532 bytes) runs one block transfer on the node's block-transfer engine and waits for it. It takes the source address in `a0`, the
  destination in `a1` (either 0 means "use the interface record's default", words +0x8 and +0x10 of the record), the byte
  length in `a2` and the mode flags in `a3`. It returns 1 when `disable_bte` is nonzero and `maxcpus` is not below it, 6 when the
  length is 0x7fff81 or more, and 0 at once for a zero length. Otherwise it raises the level with `spl1`, picks the interface
  record of the engine whose number is the processor number's low bit (table at +0x53c8 of the node record), returns 1 when that
  record's byte at +0x42 (the engine-present mask) is zero, and tries the interface's spinlock (word at +0x44) with
  `nested_spintrylock` while `bitlock_islocked` says the engine's bit lock is free; it tries the other engine when this one is busy
  or its lock is taken, and returns 1 when neither is free. With the lock held it loads the register block pointer from the
  first doubleword of the record, clears the engine's error count (word +0x58) and, after a `__dcache_wb_inval` of a
  128-byte stack area it uses as the completion word (initialised to -1, then `__prefetch_load`), stores in this order:
  the notification address into the record's word at +0x28, the source to register +0x8, the destination to +0x10, the length
  `(len >> 7) | 0x100000` (128-byte units, bit 20 set) to +0x0, then the completion address to +0x20 and the mode `flags & 0x1ff` to
  +0x18 (that last store sits in the delay slot of `nested_spinunlock`; the lock is released and the level restored with
  `splx` right after). It then polls the completion word, flushing it with `__dcache_wb_inval` and `__prefetch_load`, until it changes
  or the real-time counter at `0x9200000001030100` passes a deadline of the record's timeout word (+0x70) beyond its start. A
  completion word of 0 returns 0; any other word without bit 16 retries (the record's retry word +0x58 counts up and a count
  above 15 calls `cmn_err` with "BTE(%x): bte_copy failed with bte_status = 0x%x"); a word with bit 16 (0x10000) calls
  `bte_error_handler` and returns its result (or retries when the retry word is zero). When `a3` has bit 0x100 set it calls
  `poison_state_clear` after an error. Inferred: that the +0x18 store starts the engine, from its position as the last register write.
- `hub_dmatimeout_kick` (`IP27/unix` at 0xc000000000029144,
  1308 bytes) stops every other processor, then repairs the I/O interface's FIFO-depth register for one node. `a0` is the
  node number and `a1` chooses whether to wait for `global_kick_lock` (`mutex_spinlock`) or only try it (`mutex_spintrylock`, returning 1
  when it is held). On the first node, while the table word at 0xc0000000014ca218 is nonzero and `graph_done` is clear, it
  rebuilds the master node's pointer from the CRB of the node's widget 0 (the halfword node ids from `compact_to_nasid_node`).
  It then sets `kicker` to the calling processor, clears the two doublewords of `entermask`, and for each processor number
  below `maxcpus` that is not the caller and whose table word is not -1 sets its bit in `entermask`; for each set bit it
  stores the number in `kicking` and runs `cpuaction` with `kick_action`, flag 1. After `bte_wait_for_xfer_completion` it polls
  `entermask` (reading the real-time counter at `0x9200000001030100` against a deadline) until the other processors have cleared their
  bits. When the deadline has not passed it raises the level with `splerr`, for sixteen device entries of the node's list saves two
  words (+0x10c and +0xa4), zeroes the first and sets bit 6 (0x40) of the second, waits `us_delay(5)`, calls
  `hub_merge_clean` with the node, waits `us_delay(2)`, reads the doubleword at +0x398 of `0x9200000001c00000 + (node << 32)`
  (`IIO_IFDR`), calls `hub_ifdr_fix_value`, restores the saved words, sets `release`, stores 0xffff into `kicker`, waits
  `us_delay(2)`, restores the level and `mutex_spinunlock`. A fix result of 0 returns 0; a positive result calls `cmn_err` (level
  0x15) with "HUB II_IFDR (0x%x) fixed. Value was 0x%x", a negative one calls `cmn_err` (level 0x10) with "HUB II_IFDR (0x%x)
  overflowed. Fatal". When the processors did not all arrive it calls `cmn_err` (level 5) naming the first missing one
  ("CPU %d didn't arrive in kick_action.") and then `cmn_err` (level 0) with "Timeout/IFDR kick failed.  CPUs didn't all arrive."
  Inferred: the register is the I/O FIFO depth register, from the string and `hub_ifdr_fix_value`; the return convention of the
  `cmn_err` calls, which the decompiler marked as not returning.
- `numa_tune` (`IP27/unix` at 0xc0000000002852b0,
  1216 bytes) reads or sets the page-migration parameters of one node or of all nodes. It takes the command in `a0` (100 reads,
  101 sets), a path name in `a1` and a user buffer in `a2` of 0x83c bytes. A nonzero `a1` goes through `lookupname`
  (error 2 when the name is not found), `master_node_get` on the vnode's device and `vn_rele`; a zero `a1` means the calling
  node's number (the halfword at -0x3bde of the process page) for a read and "all nodes" (-1) for a set. Any other command returns 22.
  Read (100): a zero buffer returns 14; it copies the node's parameter block (pointer at +0x8 of the node record: two words and twelve
  more pairs of words) into a stack buffer and calls `copyout` of 0x83c bytes, returning 14 when that fails. Set (101):
  `cap_able(0x2000000)` refusing returns 1, a zero buffer or a failed `copyin` returns 14; it checks the new values with
  `migr_parms_check` for each node (an error is returned unchanged), stops each node's counting with `mem_tick_quiesce_node` (on a
  failure it re-enables the nodes already stopped with `mem_tick_reactivate_node` and returns 16), copies the parameter block
  into every selected node's record, stores `word_at_+0x10 | 0x8000000000000000` into the doubleword at +0x38 of
  `0x9200000001a00000 + (node << 32)` (`MD_MIG_VALUE_THRESH`), and restarts with `mem_tick_init_node` and
  `mem_tick_reactivate_node`. It returns 0 on success. Inferred: that bit 63 enables the threshold, since the routine only sets
  it together with the value and `migr_refcnt_init` has not been compared.
- `handle_uncac_buserr` (`IP27/unix` at 0xc000000000036998,
  1208 bytes) classifies a bus error taken by an uncached access. It takes the exception frame in `a0`, the faulting physical address
  in `a1` (node in bits 47:32) and a flag in `a2` (1 suppresses the messages). It calls `get_matching_spool_addr` for the
  doubleword-aligned address and branches on the result. 0 (no spool entry): it builds a mask, 0x200000 for processor slice
  A (the byte at +0x520 of the processor record is zero) or 0x100000 for slice B, and tests it against `PI_ERR_INT_PEND`
  (the doubleword at `0x9200000001000400`); with the bit clear and an address that is neither physical 0x2400208 (the
  deliberate bus-error read) nor the node's own expected address, and a node in another partition (`nasid_to_partid` against
  `part_id`) it prints "Uncached memory access error ... cause unknown" unless `a2` is 1 and returns 2; with the bit set it prints
  "Uncached remote partition Partial Read Error" (other partition) or the local text, stores the mask back to `PI_ERR_INT_PEND`
  to clear it, calls `error_page_discard` (1, 1) (0 or 1 returns 0; 2 stays quiet; other values print "Page with memory/directory error
  could not be discarded") and `error_check_part_page` (nonzero prints the page message and returns what `partition_handle_error` gives
  for kind 9), or for another partition returns `partition_handle_error` (kind 9). A result of -1 prints "Lost spool info on
  uncached buserr" and returns 3. Results 1 and 2 take the 3-bit type from the spool word (bits 2:0), the other the stored
  field; type 3 (time-out) prints "Uncached read access timed out" and returns 2 for a local page that passes
  `error_check_part_page`, else `partition_handle_error` (kind 1); type 1 (memory error) in this partition runs
  `error_check_memory_access` and `error_check_poisoned_state` (nonzero results go through `partition_handle_error`, kinds 5 and 6 when
  the page check fails) and prints "Uncorrectable error on uncached memory access" and returns 3 when nothing explains it, while
  a remote one returns `partition_handle_error` (kind 10); any other type prints "bad error type" and returns 3. Inferred: the
  meaning of the return values 0, 2 and 3 (handled, retry, fatal), from the messages and the partition handler name.
- `router_init` (`IP27/unix` at 0xc00000000001c084,
  1196 bytes) sets up the per-router software record and the router's global register when a router vertex is attached. It takes the
  compact node number in `a0`, a value it stores at +0x20 of the record in `a1` and a three-field attach record in `a2`
  (vertex at +0x20 of it, a halfword result at +0x8, two bytes and a word it copies). It allocates a zeroed 0x1b8-byte record
  with `kmem_zalloc_node`, attaches it to the vertex under the label `_router` with `hwgraph_info_add_LBL`, initialises the lock at
  +0x650 (`spinlock_init`, name "routerinfolock"), stores the node number (+0x8), the node's NASID from `compact_to_nasid_node`
  (+0x10), a timeout constant 75000000 (+0x178) and the node's board pointer (+0x184), then reads router register 0 into
  +0x40 and register 0x18 into +0x580 with `router_reg_read` (a nonzero error calls `cmn_err` level 1 with "Router init read failed"
  and `net_errmsg`). It rewrites register 0x18's image: if bits 35:28 are not 0x20 they become 0x20 (mask `0xfffffff00fffffff`
  and `0x200000000`); bit 0 is set when `craylnk_bypass_disable` and `hasmetarouter` are both zero, else cleared; the result
  is masked with `0xffff000fffffffff` and ORed with `0xafe000000000`, then written back with `router_reg_write`. Bits 48:46 of register 0
  go to the halfword in the attach record, and a register-0 low nibble other than 1 calls `cmn_err` level 4 "Not a router". It
  allocates a pointer array of `numnodes` entries and a 0x50-byte name buffer (`kern_malloc_node`; an allocation failure calls
  `assfail` with the source line 0x46b or 0x470), fills the name with the stored prefix and `board_to_path`, and uses
  `vertex_to_router_board`; no board prints "Couldn't locate board structure" through `cmn_err`. For a board whose type nibble
  (byte +0x56a, mask 0xf0) is 0x10 it zeroes the six words in the board's node page, then for ports 1 to 6 records in the port-mask
  byte (+0x20) a bit for each port whose bit in register 0 (starting at bit 29, then every third bit) is set, and calls
  `router_port_init` (an error calls `cmn_err` level 4 "Router port init failed"). Afterwards it calls `router_set_fences`,
  `nic_vertex_info_set`, `router_acquire_info`, stores 6 at +0 of the record, calls `build_router_invent_info` and `sndrv_attach`,
  sets `p_routertick` from `router_poll_ticks` and returns the write's result. Other board types call `cmn_err` level 4
  "Incorrectly jumpered router board". Inferred: register 0 and 0x18 meanings, from the masks and the check on register 0's low nibble.
- `log_tstamp_vevent` (`IP27/unix` at 0xc000000000238df0,
  1168 bytes) appends a time-stamped trace record to the calling processor's event buffer. It takes the event code in `a0`, the
  data pointer in `a1` and the data length in `a2`. It finds the processor's record through `pdaindr` and the halfword at
  0xffffffffffffc420, and branches on the word at +0x310 of that record: zero selects the shared-buffer path (which does nothing when the pointer at +0x288 is
  null), nonzero the plain ring described last. The shared-buffer path reserves ceil((len + 15) / 48) + 1 48-byte slots with `atomicAddWithWrap` on the shared
  index, and gives up (counting a lost event) when the slots exceed the buffer's size at +0x14 or when a slot in the way is still in use
  (first word nonzero). It copies the data into the slots with `ovbcopy` (splitting at the buffer end), and sets the record's
  timestamp at +8 to the doubleword at `0x9200000001030100` (the Hub real-time counter): when the slot after the new run is
  occupied and has an earlier stamp than the counter it uses that stamp minus one so records stay in order. It stores the
  slot count minus one in the halfword at +6 and the code in word 0, adds the slot count to the buffer's fill counter at +4 and, when
  the fill reaches the threshold at +0x18, an enabler at +0x28 is nonzero, the code is not 0xea62, the processor is not in an
  interrupt (byte at -0x3fae of the process page) and the level is not profiling (`getsr`, `issplprof`), it raises the level with
  `spl1`, decrements the counter with `compare_and_dec_int_gt` and wakes a reader with `sv_signal`. The plain path stores 40-byte
  records: the first holds code, stamp and the first 32 data bytes, each continuation holds code 0xf619 and 20 bytes. It returns nothing.
  Inferred: the buffer field names and what the +0x310 mode word stands for, from the two paths' structure.
- `mlreset` (`IP27/unix` at 0xc0000000000260e0,
  1056 bytes) is the machine-level start-up routine each processor runs before the rest of the kernel; `a0` is nonzero on a
  processor other than the boot one, which skips the node and memory set-up. Every processor first clears the four
  performance-counter pairs of its core with `r1nkperf_control_register_set` and `r1nkperf_data_register_set` (counters 0 and
  1; counters 2 and 3 as well when the processor revision register read by `get_cpu_irr` shows a part whose bits 15:8 are 0xe
  or 0xf), and at the end sets the branch-prediction mode from the tunable at `gp - 0x7714` (0 `branch_prediction_on`,
  1 `branch_prediction_fwd_not_taken`, 2 `branch_prediction_off`, 3 `branch_prediction_taken`; any other value on the boot processor
  prints "WARNING: Illegal value for r10k_bpmode"), bumps a counter when the revision's bits 15:8 equal 9, and calls `flush_tlb`
  (2) and `flush_cache`. On the boot processor it records the node number from `get_nasid`, calls `set_master_bridge_base`,
  reads the first widget's identification through the `0x9600000000000000` window to find the console I/O chip and calls
  `ioc3_mlreset`, then `nvram_baseinit`, `is_fine_dirmode`, `cpu_node_probe` (asserting a positive node count, source line 0x119, and a
  positive count again at 0x11c; it stores them with a processor mask built as `0xffffffffffffffff >> (64 - count)`),
  `getcpuid`, `get_cpu_cnode`, `setup_replication_mask` and checks that the master node equals `get_nasid` (assertion, line
  0x12e). For each node it stores into the node alias `0x9200000001800000 + (nasid << 32)` the doubleword `PI_REGION_PRESENT` (+0x18)
  = the region mask word ORed with 1 and `PI_CALIAS_SIZE` (+0x28) = 2, and zeroes the doubleword at +0x190 of the I/O block alias
  `0x9200000001c00000`. It then initialises `hub_mask_lock`, moves the boot processor's mask when it is not processor 0,
  and calls `iograph_early_init`, `mem_init`, `hubdev_init`, two static routines (0xc000000000027510 and 0xc00000000002741c), clears two
  flag bits (0x5000) in two kernel flag words, `verify_snchip_rev`, `he_arcs_set_vectors` and `intrgroup_init`. It returns nothing.
  Inferred: the names of the registers at +0x18, +0x28 and +0x190, which `hub_dmatimeout_kick` and `memory_iscalias` use under those names.
- `mgras_attach` (`IP27/unix` at 0xc000000000376fdc,
  1048 bytes) attaches one MGRAS graphics board found on a Crosstalk widget. It takes the widget's vertex in `a0` and returns
  nothing. It reads the widget identification (`xwidget_info_get`, `xwidget_info_id_get`, `xwidget_info_master_get`) and the
  master node (`master_node_get`, then the NASID from `compact_to_nasid_node`), reads the doubleword at offset 0 of
  `0x9200000001e00000 + (node << 32)` (`NI_STATUS_REV_ID`) and calls `cmn_err` (level 4) with the string "INCOMPATIBLE HARDWARE"
  if its bits 7:4, the chip revision, are below 4. It takes `GfxBoardInitSema` (`psema`, 0x19), makes the character device `mgras`
  (`hwgraph_char_device_add`) and maps the board's first 0xc00000 bytes with `xtalk_piotrans_addr` (offsets 0 and 0, length
  0xc00000). It searches the three 0x58-byte slots of `MgrasBoards` for one with that mapping, else for a slot whose widget number
  (word +0x24) matches and whose node is in the same module and on the same crossbow (`get_module_id`, `get_node_crossbow`);
  without a match `cmn_err` is called, and with one it stores the node (+0x50) and mapping (+0x0) in the slot. It records the master
  id in the byte at +0x7d4 and the vertex in +0x7d0 of the board record, calls `nic_hq4_vertex_info` and a static lookup, and releases the
  semaphore (`vsema`). It then allocates four interrupts on the widget with `xtalk_intr_alloc`, using a duplicated device
  descriptor: the first one in its default form (record +0x7e0), the second with the target CPU copied from the first (+0x7e8), the
  third with flag bit 0 set (+0x7f8) and the fourth with the descriptor's software level set (+0x7f0), saves their vectors as
  halfwords at +0x800, +0x802, +0x804 and +0x806 (`xtalk_intr_vector_get`) and connects them with `xtalk_intr_connect` to
  `MgrasGeneralInterrupt` (+0x7e0), `mgras_hq4_lowater_intr` (+0x7e8), `MgrasRetraceHandler` (+0x7f0) and `MgrasHQ4ErrInterrupt`
  (+0x7f8). A last static routine finishes the board record. Inferred: the slot-matching rule's purpose, since the
  `get_module_id` and `get_node_crossbow` comparison was read in the decompiled form only.
- `hub_ioerror_handler` (`IP27/unix` at 0xc000000000027c50,
  1028 bytes) is the Hub's entry point for a PIO error reported against a widget. It takes the node vertex in `a0`, the error kind in `a1`,
  a caller-supplied word in `a2` and the error record in `a3`. It fetches the node record from the vertex label `_node`
  (`hwgraph_info_get_LBL`) and its NASID from the halfword at +0xa. Kind 9 returns 9, kind 10 goes to `hub_xp_error_handler` with kind 10,
  and any other kind but 5 and 6 returns 4. Kind 6 takes the widget number from the halfword at +0x6 of the record: widget 1 (the Hub's own
  port) goes to `hub_ioerror_local`; another widget goes to `hub_xp_error_handler` when `is_widget_pio_enabled` is true, otherwise
  it prints the "No outbound widget access - " dump with `ioerror_dump` when `error_state_get` is 3 and returns 0. Kind 5 first works
  out which widget the failed address belongs to: an address (the doubleword at +0x30 of the record, masked with
  `0xf9ffffffffffffff`) outside the `0x9000000000000000` to `0x9000010000000000` range uses the address in +0x10, where bits 31:29 select a
  small window; window 0 gives the widget from bits 27:24 and an offset of the low 24 bits, and window 1 to 7 reads the doubleword at
  `0x160 + 8 * (window - 1)` of the I/O block alias `0x9200000001c00000 + (node << 32)` and takes the widget from its bits 11:8 and the base
  from its low five bits times 0x20000000; a physical address in the Hub node-alias ranges (`0x92000000e0000000`,
  `0x920000000a000000`, `0x9200000020000000`, `0x9200000100000000`, each plus the node shifted by 32) is mapped to a widget through the
  six-entry table of the node record (`xtalk_pio_target_get`, `xtalk_pio_xtalk_addr_get`), and the flags are set to
  0x41000000. A kind-5 record whose flag bit 25 is clear returns 5. Then widget 1 goes to `hub_ioerror_local` and others as for kind 6. A
  result of 8 from any handler prints "Unable to handle IO error: hardware graph not setup" with `printf`. Inferred: the kind numbers
  5, 6, 9 and 10 as read and write errors, from the shared dump text, and the decoded windows from the register layout the code assumes.
- `per_hub_init` (`IP27/unix` at 0xc000000000026acc,
  1000 bytes) initialises one node's Hub once, when the first processor of the node starts; `a0` is the compact node number. It sets the
  node's bit in a started mask (word at `gp + 0x938`, under `hub_mask_lock` at `gp + 0x948`); a later processor of the same
  node waits until the node's bit in the done mask (`gp + 0x940`) is set and returns. The first one stores the chip revision from
  `get_hub_chiprev` into +0x49b8 of the node record and, for each of the two slices whose processor `cpu_enabled` reports as absent,
  stores 0xf into the junk-bus word at `0x9200000001a20050 + 8 * slice` or, when the byte at -0x3add of the process page is nonzero,
  `0x9200000001a20080 + 32 * slice`. When the word at `gp + 0x914` is nonzero it sets 0xffff00000000 in the NI alias doubleword at +0x18 and
  clears bit 18 of +0x110 (`0x9200000001e00000` alias), and writes `0x900` (after clearing bits 11:8) into the NI age registers at
  offsets 0x600500 through 0x600538 of the node alias `0x9200000001800000`; with the word zero it clears bits 11:8 of each. It writes the
  doubleword `0xfe00000000` (the kernel variable at `gp - 0x75b0`) to offset +0xc8 of the memory block alias `0x9200000001a00000`, and for revision
  below 5 (or 5 with the tunable at `gp - 0x7718`) sets bits 12:8 of +0xe0 to 1. For revision below 6 it stores 2 to I/O block offset
  +0x200 and ORs 0x40 into +0x3a8 under the mask `0xffefffffffffff00`; for revision 6 it stores the variable at `gp - 0x75bc` to +0x200 and
  the variable at `gp - 0x75b8` ORed with the one at `gp - 0x75b4` shifted left 4 into +0x3a8. It then stores 0x1000 to +0x3c0 and
  0xff to +0x3b8, and calls `intr_reserve_hardwired`, `hub_error_init`, `install_eccintr`, `protect_hub_calias`, `hub_rtc_init`,
  `hub_migrintr_init`, `hub_setup_kick` and `hub_init_ifdr_war`. It stores 0xd0 to node-alias +0x30 and 0xd400 to +0x38 when the word at
  `gp + 0x914` is nonzero, 0xfe and 0xc000 when the word read through `0x9000000010000090` is nonzero, and 0x3012 to memory-block +0xa0. The
  last step sets the node's bit in the done mask under the lock. It returns nothing. Inferred: the register meanings
  (CRB timeout, scale factor, queue size, FIFO counts), which come from the hub table and the variable names; the unnamed +0xc8 and +0xe0.
- `tick_actions` (`IP27/unix` at 0xc0000000000461e0,
  976 bytes) is the per-tick housekeeping each processor runs from the clock interrupt; it takes no arguments and returns nothing. In
  order: it calls `ecc_log` when the byte at -0x38d0 of the process page is nonzero, always `tlb_tick_actions`, then tests the
  halfword at -0x3adc: bit 0 calls `kick_the_hub` and bit 4 (0x10) calls `hub_error_status_war`. When the processor number equals the one
  `cnodetocpu` gives for the node (one processor a node), it decrements the counter at +0x4d18 of the node record and calls
  `capture_hub_stats` when it reaches 0; unless the tunable at `gp - 0x727c` is set it also decrements the counter at +0x4d1c and calls
  `probe_md_errors` with the NASID from `get_nasid` when that reaches 0, then calls `memerror_sbe_intr` (1, NASID), and finally
  `sysctlr_check_reenable`. Separately, when the progress check is enabled (word at `gp - 0x7288`) and the countdown at -0x3850 reaches
  0 it reloads it from `gp - 0x7290` and scans the other processors (table entries of 16 bytes, skipping the caller and entries
  of -1): a processor whose timestamp at +0x5b8 of its record is nonzero and not later than the Hub real-time counter at
  `0x9200000001030100`, whose gap is not below the limit at `gp - 0x7298`, that is not flagged (byte +0x4f zero in the mode 1 case, and
  flag bits 0x50 of +0x48 clear), has its stall count at +0x7c8 incremented. On the first stall it looks for another processor whose
  byte +0x429 is set; if none does, it compares the gap with the limit at `gp - 0x7e70` and calls `cmn_err` (level 0xc) with
  "Process on cpu %d not making progress" and the processor number. When the progress word at -0x3848 of the caller's own page is set
  and the other check is off it calls `cmn_err` (level 0xd) with "!cpu now making progress". The strings and the counter at
  `gp - 0x7288` are read; nothing is written to a device register. Inferred: the role of each counter, from the called routines and
  the two messages; the exact stall conditions, which were read through the decompiler.
- `i2c_master_xmit_recv` (`IP27/unix` at 0xc00000000009b374,
  964 bytes) performs one combined write-then-read transaction on a node's I2C master. It takes the node number in `a0`, the 7-bit slave
  address in `a1`, the bytes to send in `a2` with their count in `a3`, a pointer for the sent count in `a4`, the receive buffer in `a5` with
  its length in `a6`, a pointer for the received count in `a7`, and on the stack a length-prefix adjustment (the word at 164(sp)), the
  argument handed on to `i2c_arb` (168(sp)) and a flag (the word after it). Both counts start at 0. It calls `i2c_arb`
  (node, that argument, 0); a negative result is returned unchanged and a result of 0 with the flag nonzero returns -10. It then works
  on two doublewords of `0x9200000001a20000 + (node << 32)`: the data register at +0x0 and the status register at +0x8. If any of status
  bits 1, 2 and 4 (mask 0x16) is set before it starts it returns -2 without writing. Every wait polls until status bit 7 (0x80) is clear
  and ends with -2 when a bit of 0x16 is set; the deadline is the stack argument plus 800/1000 of the Hub real-time counter read
  at entry (`0x9200000001030100`), compared with the same scaled counter on each pass. Once the address byte is written, every error
  return (-2, -3, -6, -7, -9) first stores 0xc2 to the status register. Order of writes: data `address << 1`, status 0xc5, wait (timeout
  -6; bit 3 of the status afterwards returns -3); for each byte to send, data = byte, wait (timeout -7), sent count + 1, stop sending
  early when status bit 3 is set; status 0x45, data `(address << 1) | 1`, wait (timeout -6; bit 3 set returns -3). Receive: status 0x40
  first when exactly one byte is wanted; for each byte, wait (timeout -9), status 0x40 when the index is the length minus 2, read the data
  register into the buffer, count it, and when the adjustment is not negative the first byte received plus it becomes the new length. Finally
  status 0x45, data 0xfe, wait (timeout -6) and return 0. Inferred: the status bit meanings (bit 7 busy, bit 3 no-acknowledge, bits
  1, 2 and 4 error), from how the code tests them; the scaled deadline's unit.
- `hub_error_init` (`IP27/unix` at 0xc0000000000324f4,
  928 bytes) sets up the Hub's error reporting for one node; `a0` is the compact node number. It first calls `hub_error_clear`.
  On node 0 it allocates, for every node, a 0x1938-byte error log record (`kmem_zalloc_node`, flags 1) and a 0x40-byte count record
  (flags 0x101), with `assfail` on a failure (source line 0x9b). On the node that matches `get_compact_nodeid` it checks both
  records (lines 0xa4 and 0xa5), zeroes the log's first word, runs `recover_error_init` on the log's +0x1810 and +0x1890, and writes the
  PI error interrupt masks at `0x9200000001000408` (`PI_ERR_INT_MASK_A`) and `0x9200000001000410` (`PI_ERR_INT_MASK_B`): reading
  `PI_CPU_ENABLE_B` (+0x58) zero stores 0x1aaaaaa to A, else reading `PI_CPU_ENABLE_A` (+0x50) zero stores 0x1555555 to B, else it
  stores 0x16555aa to A and 0x9aaa55 to B. It then clears bit 21 of A and bit 20 of B by read-modify-write. When bit 1 of the
  halfword at -0x3adc of the process page is clear it zeroes the two status clear aliases at +0x448 and +0x468; for each present processor (`PI_CPU_PRESENT_A`
  at +0x40, `PI_CPU_PRESENT_B` at +0x48) it copies the error stack address from +0x418 or +0x420 into the log record (+0x1920 and +0x1910 for A,
  +0x1928 and +0x1918 for B), derives the stack size from +0x428 as `0x1000 << (code - 1)` (0 for code 0) into +0x1930, and when the
  two addresses agree above bit 7 adds that size to the B address and the stored copies. It connects the cause interrupt 6 to
  `hubpi_eint_handler` with `cause_intr_connect` (a failure calls `cmn_err` level 0x14 "hub_error_init: cause_intr_connect failed on %d").
  Processors on other nodes only write 0 to the node-alias doublewords at +0x408 and +0x410. For every node it calls
  `hubii_eint_init` and `hubni_eint_init`; node 0 also initialises the global lock `error_dump_lock` and sets two words. Last it
  stores 12000 (0x2ee0) at +0x4d1c of the node record. It returns nothing. Inferred: the log field names, from the later users.
- `hubiio_crb_error_handler` (`IP27/unix` at 0xc000000000034a30,
  896 bytes) walks a node's fifteen I/O-interface CRB entries after an error interrupt and disposes of the ones that failed. It takes an
  error-context argument in `a0` and the node record in `a1` (NASID as the halfword at +0xa, entry lock at +0x31c) and returns the number of
  entries it handled. It takes the lock with `mutex_spinlock_spl` at level `spl7`. For each entry `i` = 0 to 14 it loads word A at
  `0x9200000001c00000 + (nasid << 32) + 0x20 * i + 0x400` and skips the entry unless bit 50 of A is set. Then it loads B (+0x408) and
  C (+0x410). When bit 48 of C is set, or when the command in bits 32:30 of B is not 1 or 5, or the type in bits 42:41 is not 1 or
  2, the entry is a processor-side error: it builds a record (flags 0xc1000000, the address from A bits 39:2 shifted left 2, the number
  from A bits 48:45, the access class from bits 54:52), requires A bits 44:40 to be in 0x10..0x17 when A bit 0 is set (`assfail`, source
  line 0x70c) and then, depending on A bit 55 and on the class in bits 54:52 (an 8-entry table at 0xc00000000140aff0 sends classes 0 and 5
  to 7 to the "Fatal %s on hub : %d" path and 1 to 4 to the "%s on hub cnodeid: %d" path), calls `cmn_err` and `sn0_error_dump`; a class of
  8 or more dumps and calls `cmn_err` level 0. Bits 49 and 51 of A call `cmn_err` level 0 with "Xtalk Packet with error bit set to hub %d" and
  "Uncorrectable data error detected on data from Craylink to node %d". Otherwise (a BTE entry) it passes the
  BTE flag from B or C to `bte_crb_error_handler`, frees the entry with `hubiio_crb_free`, and counts it. After the last entry
  it releases the lock with `mutex_spinunlock` and returns the count. Inferred: the field names, from the matching `dump_crb`
  decode, and which message belongs to which class; the table was read as addresses only.
- `kf_hub_analyze` (`IP27/unix` at 0xc0000000001540cc,
  876 bytes) is the Hub step of the post-crash fault analysis. It takes an optional pointer to a 21-word fault record in `a0`. With a
  null pointer it counts the CRB entries of the current node (word A at `0x9200000001c00000 + (current_nasid << 32) + 0x20 * i + 0x408`
  for i = 0 to 14, twice) whose command field (bits 29:25) is 0xb or 6, and when all 30 reads qualify and the pointer at +0x48 of
  `kf_conf_tab` is nonzero it stores the larger of 0x55 and the byte it points to (twice, to the same byte). With a record it saves a
  copy on the stack, clears its word +0x14, sets word +0x8 to 0x109, and when the byte at `kf_conf_tab` +0x48 is 'U' it also
  logs a second record (0x126, with that byte) with `kf_guess_put` and prints the slot name through `get_slotname` and `ip27log_printf` (level 2); a
  byte that is not 'U' is stored into the record (byte +0x30) and put; a nonzero pointer at +0x128 puts another record (0x125, the
  word it points to) and restores the first copy. It then runs `kf_pi_analyze`, `kf_md_analyze`, `kf_ii_analyze` and `kf_ni_analyze` in
  that order, each only when the previous returned 1, and finally restores the caller's record. It returns nothing. Inferred: the
  purpose of the byte 'U', since only its comparison and the log text were read.
- `dump_hub_registers` (`IP27/unix` at 0xc00000000021a300,
  828 bytes) walks a built-in table of Hub register ranges for every node and hands each 16 KiB page of the node alias to an output
  routine; it takes no arguments and returns 0, or the nonzero result of that routine. The table (0xc00000000146cc98) holds 27 pairs
  of first and last offsets ending at -1: `0x0-0x430`, `0x440`, `0x450`, `0x460`, `0x470-0x4b8` (processor interface), `0x200000-0x200040`,
  single registers at `0x200050`, `0x200060`, `0x200070`, `0x200080`, `0x200090-0x2000a8`, `0x2000b0-0x2000e0`, `0x210000-0x210038`,
  `0x220000-0x2200f8` (memory), `0x400000-0x400008`, `0x400020`, `0x400100-0x400200`, `0x400300-0x400340`, `0x400388-0x4003c0`,
  `0x400400-0x4005d8`, `0x410000-0x410028`, `0x420000-0x420028`, `0x430000-0x430008` (I/O), `0x600000-0x600310`, `0x600400-0x600538`,
  `0x608000-0x608008` and `0x638000-0x638178` (network). It first fills a 16 KiB stack buffer with the pattern
  `0x5555555555555555` (that fill is repeated whenever the buffer is flushed), calls `get_nasid`, and for each of the `numnodes` nodes
  loads each doubleword from `0x9200000001800000 + (nasid << 32) + offset` (read through the `compact_to_nasid_node` table) and stores
  it into the buffer at `offset & 0x3ff8`, so the buffer mirrors one 16 KiB page. When the next offset leaves the current page or
  block (bits 23:20 or 19:14 change) or the table ends, it calls the static routine at 0xc000000000219c48 with the
  page's address, the buffer, length 0x4000 and a flag of 0x200, and refills the buffer. A nonzero result is returned at once. Every
  read is a doubleword load from the node alias; none is written. Inferred: the output routine's purpose (writing a dump), because
  it was not read; and that the pattern marks registers that were not read.
- `get_matching_spool_addr` (`IP27/unix` at 0xc000000000034668,
  808 bytes) searches the Hub's error spool for an entry that matches a faulting address. It takes two output pointers in `a0` and `a1` (the
  entry's two words), the address in `a2`, the byte length in `a3` and a type filter in `a4` (2 means any). It returns 0 for no match, -1
  for a spool-read error, 1 for a match on a processor-interface cache error and 2 for a match on a processor error word. It loops on
  `hubpi_spool_get_next`: result -1 returns -1; 1 matches when the address `(word0 >> 31) * 128` plus either `a3` (a single line when
  `a3` is 0x80 or more) covers `a2`, and `a4` is 2 or equals bit 12 of word 0; 2 matches when `(word0 >> 25 & 0x1fffffffff) * 8`
  plus `a3` (or 8 when `a3` is below 8) covers `a2` and `a4` is 2 or equals bit 42 of word 1; any other result calls `cmn_err` level 0x14 with
  "Unknown spool type %x". A non-match goes through `huberror_process_stack_entry` (a nonzero result outside a dump panics: `in_dump_mode`, `kl_panic_setup`,
  then `cmn_err` level 0x12 with "%s. PhysAddr 0x%x", the string from `hub_rw_err_info`) and the loop continues. When the spool is empty
  (`hubpi_spool_get_next` returns 0) and bit 1 of the halfword at -0x3adc of the process page is set it also checks the processor's two live
  registers, selected by the byte at +0x520 of its record (0 uses `0x9200000001000430` and `0x9200000001000440`, else
  `0x9200000001000450` and `0x9200000001000460`): when the first has bit 63 set and its field `(w >> 25 & 0x1fffffffff) * 8` covers the
  address it returns 2 with both words stored through the output pointers. Inferred: the register names at those four offsets, since only
  the select byte and their use as address and status words were read.
- `hub_piomap_alloc` (`IP27/unix` at 0xc00000000003b5a0,
  792 bytes) reserves a window through which a processor can reach a range of a Crosstalk widget's address space. It takes the widget vertex in
  `a0`, the device number in `a1`, the Crosstalk address in `a2`, the byte count in `a3`, the smallest acceptable count in `a4` and flags in `a5`
  (bit 0 reserved window, bit 1 may wait together with bit 0, bit 3 changes the access attribute). It reads the widget number
  (`xwidget_info_id_get`) and master (`xwidget_info_master_get`) of the vertex, finds the master's record from its `_node` label
  (`hwgraph_info_get_LBL`), and returns 0 when `a3` is below `a4`. A request whose address plus count fits below 0x1000001 (16 MiB)
  needs no register: it returns the small-window record at +0x10 of the 0x30-byte entry for the widget (index `widget & 0xff`) and, when
  flag bit 3 is set, ORs 0x3800000000000000 into the entry's word at +0x28. Larger requests must fit within one 512 MiB window
  (`(a2 & 0x1fffffff) + a3` below 0x20000001) or return 0. Under the node lock at +0x318 (`mutex_spinlock`) it scans the six large-window
  records (0x30 bytes each from +0x328): a valid one (flag bit 0 of word +0x350) that is reserved (bit 2), has the same upper
  address bits (`a2 & 0xffffffffe0000000`) and widget is reused; a free one is taken, and with flag bit 0 the reserved-window count at
  +0x320 may not exceed 5 (else the call fails). To take a free slot it writes `((widget & 0xf) << 8) | (a2 >> 29 & 0x1f)` to the
  doubleword at `0x160 + 8 * slot` of the I/O block alias `0x9200000001c00000 + (nasid << 32)`, stores the address, widget, the window's
  Hub address `0x9200000020000000 + slot * 0x20000000 + (nasid << 32)` (ORed with 0x3800000000000000 when flag 3 is set), the
  slot number (byte +0x34e), bumps the use count (halfword +0x34c) and marks the record valid (and reserved when flag 0 is set).
  When every slot is in use it fails if flags 1 and 0 are both clear, else waits on the semaphore at +0x310 (`sv_wait`) and rescans. The
  lock is released on every path (`mutex_spinunlock`). It returns the record's address, or 0. Inferred: the field names; the
  `0x3800...` bits' role as an access attribute, from their being set only for flag bit 3.
- `llp_pfail_intr` (`IP27/unix` at 0xc00000000003e424,
  792 bytes) handles the network-link power-fail interrupt on the processor that owns the node's router link; it takes no arguments and
  returns nothing. It scans the module table (`modules`) with a static lookup for the entry whose processor equals the calling one (one
  entry only when the byte at -0x3add of the process page is set); without a match it takes the delay-only path. It reads router
  vector 0, offset 0 (`vector_read`) and calls `llp_pfail_barrier`. When it found its entry it waits 100 microseconds and then: if the
  low nibble of the vector word is 0 and the byte at -0x3add is set, it reads `NI_DIAG_PARMS` (+0x600110) by `vector_read`, sets bit 12 (when the
  kernel's link-speed variable at `gp + 0x9b0` is 8) or clears it, writes it back with `vector_write`, does the same to the local
  alias doubleword at `0x9200000001600110`, waits 100 microseconds and stores 2 into `NI_PORT_RESET`
  (`0x9200000001600008`); if the nibble is 1 it also reads the neighbouring router's vector 6 (`vector_read` with port 6), and when that nibble is 1
  too it sets bits 14:12 (speed 8) or clears them in offset 0x30 of each of the two vectors with `vector_write`, waits, then writes 0xe to offset 8 of
  both vectors; any other nibble only waits 100 microseconds. Without an entry it waits 300 microseconds. Finally it busy-waits while bit 37
  (`0x2000000000`) of the doubleword at `0x9200000001608088` (`NI_PORT_ERROR_CLEAR`) stays set, reading it repeatedly. Inferred: the offsets 0x30 and 8 of
  the router vectors, which are named in the router entries elsewhere, and the meaning of nibble 0 and 1, from the comparisons.
- `counter_intr` (`IP27/unix` at 0xc0000000000457a0,
  728 bytes) is the handler for the processor's compare-counter (clock) interrupt; `a0` is the saved exception frame. When bit 5 (0x20) of
  the trace-flag doubleword at -0x3d80 of the process page is set it logs trace events 0x6c at entry and 0x65 (with 0x6c) at exit through
  `log_tstamp_event`. If the word at -0x3960 is nonzero it calls `frs_handle_counter_intr` and leaves. Otherwise it asks
  `hwperf_overflowed_intr` whether a hardware performance counter overflowed; if so it runs `l2_sbe_intr` when `l2_sbe_check` has a
  nonzero low byte (returning without more work when bit 0 of `l2_sbe_check` is then set) and `hwperf_intr` with the frame, and returns. A
  clock tick (flag bit 6 of the word at -0x3fb8 clear) measures the interval since the previous one, from the Hub real-time counter at
  `0x9200000001030100` against the stored stamp at -0x3a48, and once `lbolt` exceeds 1000 it records the counter minus compare lag
  (`get_r4k_counter` minus `_get_compare`) as a maximum at -0x3a34, a count at -0x3a38 and a sum at -0x3a40. When the interval is at
  least the warning limit (`counter_intr_warn_cycles`, or `counter_intr_warn_period * 0x1312d0 / 2` when the period is 1 to 255), the
  interval is a lost-interrupt candidate: unless the compare value at -0x3a9c is `-0x10000000` or the per-processor flag in the table at
  `0xc0000000014de510` + 0x10 + 4 * processor is already set, it calls `cmn_err` (level 4, or 0 when `counter_intr_panic` is set) with
  "Probable lost interrupt!" and the interval in 0x1312d0-cycle units, the frame's words at +0x120 and +0xf0 and a
  string that adds "Probably caused by splhi or spl7 delaying the interrupt" unless the interval is within two units of
  `0x10c6 / (word at -0x38c0)`. It then stores the new stamp, clears the processor's flag, calls `resetcounter` with the compare value
  at -0x3a9c and `clock`. A tick with flag bit 6 set only calls `resetcounter`. Inferred: the units of the interval, from the
  constant 0x1312d0 and the Hub counter, whose frequency this routine does not state.
- `hubpi_eint_handler` (`IP27/unix` at 0xc000000000032b28,
  728 bytes) services the Hub's processor-interface error interrupt on the processor that took it; it takes no arguments and returns nothing.
  It first calls `check_ni_errors` and, when that finds a network error, `hubni_error_handler` with the label "PI interrupt" and 1. It reads
  `PI_ERR_INT_PEND` (`0x9200000001000400`) and the mask of the processor's slice (the byte at +0x520 of its record: 0 reads
  `PI_ERR_INT_MASK_A` at `0x9200000001000408`, else `PI_ERR_INT_MASK_B` at `0x9200000001000410`) and ANDs them. If any of the bits 0xcfff00
  (8 to 19 and 22 to 23) is set it calls `enter_panic_mode` and `cmn_err` level 0x14 with "Fatal PI error interrupt received". Bit 24
  calls `log_md_errors` with the NASID from `get_nasid`. Then for each of three pairs of spool bits it tests the processor's own bit (A with slice 0, B
  with slice 1): bits 1 or 0 (spool count), 7 or 6 (write-response write error) and 5 or 4 (write-response timeout): a hit calls
  `process_error_spool` and stores the bit's mask back to `PI_ERR_INT_PEND` to clear it (2 or 1, 0x80 or 0x40, 0x20 or 0x10). Bit 21 or 20
  (0x200000, 0x100000) set calls `cmn_err` level 0x14 with "Unexpected UCE error interrupt. int pend 0x%x"; bit 3 or 2 (8, 4) calls
  `cmn_err` level 0x14 with "Spurious message intr, likely partition reboot". With nothing pending it returns. Established: the order of
  the checks and each constant. Inferred: that the stores are write-one-to-clear, from their using the handled bit as the value.
- `migr_refcnt_init` (`IP27/unix` at 0xc00000000026c940,
  724 bytes) allocates the page-migration reference-count storage of one node; `a0` is the compact node number and the result is 0, or 1
  when an allocation fails. It runs only when the node's record (+0x4958) shows it has memory and, when it names a master processor
  (halfword +0x4956, not -1), that processor's record flag 4 of the halfword at +0x524 is clear; otherwise it falls through to
  return. It sums `slot_getsize` over the 32 memory slots of the node, gets `numnodes * sum * 32` bytes with `kmem_contig_alloc_node`
  (alignment 0x10000, flag 1), zeroes them with `blkclr` and allocates a 0x100-byte table of 32 pointers with `kmem_alloc_node`
  (flag 1). Each pointer is zero for an empty slot, else the next piece of the block, advanced by `numnodes * slot_size * 32`
  bytes, with an `assfail` (source line 0xe5) when the cursor ran past the block's end. It stores the pointer table, the block, the block size
  and `sum * 4` at +0x28, +0x30, +0x38 and +0x40 of the migration record that the node record's first word points to. It then sets bit 63 of
  `MD_MIG_VALUE_THRESH` (offset +0x38 of `0x9200000001a00000 + (nasid << 32)`), first writing the word at +0x10 of that same record ORed with bit 63
  and then ORing bit 63 in again. If a block or table allocation fails it frees the block with `kmem_contig_free` and zeroes the four fields,
  returning 1. Inferred: the field names, from the layout, and that +0x10 is the threshold value the routine writes.
- `log_tstamp_event` (`IP27/unix` at 0xc000000000238b24,
  716 bytes) appends one fixed-size time-stamped trace record to the calling processor's event buffer. It takes the event code in `a0` and
  four data words in `a1` to `a4`. It finds the processor's trace record through `pdaindr` and the halfword at 0xffffffffffffc420 and
  branches on the word at +0x310: nonzero writes into a plain ring (position at +0x300, ring from +0x2f8 to +0x308, 48-byte slots): the
  next slot is the current one plus 0x30, or the ring start when the current one is at or beyond the end, and the old position's slot
  gets the Hub real-time counter (`0x9200000001030100`) at +8, the four words at +0x10, +0x18, +0x20 and +0x28 and the code at +0 (stored last); it
  returns. Zero uses the shared buffer whose pointer is at +0x288 (nothing happens when it is null; a nonzero first word of that
  buffer's header is incremented as a lost-event count). It takes a slot with `atomicIncWithWrap` on the header's index (+0x8) and the
  size at +0x14, loses the event (increments the header's first word) when the slot's first word is already nonzero, and otherwise
  stores the four words at +0x10 to +0x28 and a timestamp at +0x8: the current counter, or, when the next slot is occupied and
  carries an earlier stamp, that stamp minus one. It zeroes the halfword at +6, writes the code, adds 1 to the header's fill word
  (+0x4) and, when the fill is at or above the threshold at +0x18, the enabler at +0x28 is nonzero, the code is not 0xea62 and the byte at
  -0x3fae of the process page is 0, raises the level (`getsr`, `issplprof`, `spl1`) and, if the counter at +0x28 decrements through
  `compare_and_dec_int_gt`, wakes the reader with `sv_signal`; it restores the level with `splx`. It returns nothing.
  Inferred: the buffer's field names and that +0x310 selects between two buffer kinds, from the two code paths.
- `cont_nmi_dump` (`IP27/unix` at 0xc000000000044d8c,
  712 bytes) is the continuation of the non-maskable interrupt handler that produces a crash dump; it takes no arguments and does not
  return. It gets the processor number (`getcpuid`) and pins that processor's per-processor area with `wirepda`. When the tunables
  `r10k_intervene` and `r10k_progress_nmi` are both nonzero and the flag halfword at -0x3832 is set, it saves the processor's
  frame with `nmi_cpu_eframe_save` and reports a "Progress intervention" through `cmn_err`: level 6 with the process name, pid, EPC and
  status when bits 4:3 of the saved status word (+0xf8) equal 2 (user mode), else level 8 with "Progress intervention in kernel mode EPC
  0x%x (sr 0x%x)" and the EPC at +0x158. Otherwise it calls `enter_panic_mode`, clears the byte at -0x3fad, sets the byte at -0x3fb1
  to 1 and enters a wait loop of up to 1500 passes (0x5dc) of `us_delay(10000)`, ending as soon as every node's word at +0x5168 is nonzero. On
  pass 1000 it forces the processors that have not reported: for each node whose word is still zero it sets the bit of each of that node's
  processors in the mask at 0xc0000000014de4f0 + 0x10 and stores 1 into the node-alias doubleword
  `0x9200000001800000 + (nasid << 32) + 0x70 + 8 * slice` (the PI NMI register of that slice), starting at the node's first processor and
  covering its processor count. After the loop it runs `nmi_eframes_save`, `sn0_error_dump` and `cmn_err` level 0 with "User requested
  vmcore dump (NMI), cpu %d handling" and the processor number, which does not return. Inferred: that offsets 0x70 and 0x78 are the PI
  non-maskable-interrupt registers, from the public header names and the way the loop uses the slice number as the index.
- `hubpi_spool_get_next` (`IP27/unix` at 0xc000000000033dac,
  680 bytes) takes the next entry from the Hub processor interface's error spool (the memory stack the Hub fills with error words), or,
  when the spool is empty, reads the live error registers. It takes two output pointers in `a0` and `a1`; it returns 0 for nothing, 1 for a
  spool entry and 2 for registers read directly. It raises the level with `spl7`, finds the node's error log record (`kl_error_log` indexed
  by the node halfword at -0x3be2 of the process page) and the processor's slice (byte +0x520 of its record); a missing record
  or a zero read pointer at record +0x1910 + 8 * slice returns 0 after `splx`. With the read pointer (+0x1910 + 8 * slice) equal to the write
  pointer (+0x1920 + 8 * slice) the spool is empty, so it reads `PI_ERR_STATUS0` (offset 0x430 for slice 0, 0x450 for slice 1) into `*a0`
  and the second status register (0x440 or 0x460) into `*a1` from `0x9200000001000000`; if bit 1 of the halfword at -0x3adc is clear and
  bit 63 of `*a0` is clear it returns 0, and if bit 63 is set it stores 0 to the status clear alias (0x448 or 0x468). It then stores the
  value of the stack address register (offset 0x418 for slice 0, 0x420 for slice 1) into the write pointer; with bit 1 of the halfword clear it
  calls `klsave_spool_registers` (the two words, 2) and returns 2, and with it set it re-compares the pointers and returns 0 if they are now
  equal. A nonempty spool reads one doubleword from `0x9600000000000000 | (nasid << 32) | read pointer` into `*a0`, advances the read pointer by
  8, wraps it by subtracting the stack size at record +0x1930 when the new pointer is aligned to it, and returns 1. The level is restored
  with `splx` on every path. Inferred: the register names at offsets 0x430 to 0x468, which the hub datasheet gives under those names for this
  routine's uses; the meaning of bit 1 of the halfword at -0x3adc, which is only tested.
- `i2c_master_recv` (`IP27/unix` at 0xc00000000009b0cc,
  680 bytes) reads bytes from an I2C slave through a node's I2C master. It takes the node number in `a0`, the slave address in `a1`, the buffer in
  `a2` and its length in `a3`, a pointer for the received count in `a4`, a length-prefix adjustment in `a5`, the argument for
  `i2c_arb` in `a6` and a flag in `a7`. The count starts at 0; `i2c_arb` (node, `a6`, 0) returning negative is passed on, and 0 with the flag nonzero
  returns -10. The registers are the data register at +0x0 and the status register at +0x8 of `0x9200000001a20000 + (node << 32)`; a status
  with bit 1, 2 or 4 (mask 0x16) set before the start returns -2 with no write. It writes `(address << 1) | 1` to the data register and 0xc5 to
  the status register, then waits for status bit 7 (0x80) to clear (timeout -6, error bits -2, bit 3 set afterwards -3), the deadline being the
  `a6` value plus 800/1000 of the Hub real-time counter (`0x9200000001030100`) read at entry. When exactly one byte is wanted it writes
  0x40 to the status register first; for each byte (none when the length is zero or less) it waits (timeout -9), writes 0x40 to the status register
  when the index is the length minus 2, reads the data register into the buffer, counts it, and when `a5` is not negative makes the first byte
  received plus `a5` the new length. It ends with status 0x45, data 0xfe and a final wait (timeout -6), returning 0. Every error return after
  the data write first stores 0xc2 to the status register. Inferred: the bit meanings, as in the write-then-read routine.
- `intr_connect_level` (`IP27/unix` at 0xc0000000000383ec,
  668 bytes) connects a handler to one Hub interrupt level of a processor and unmasks it. It takes the processor number in `a0`, the
  level in `a1` (it is passed by address to a static routine, which may change it), and four handler words in `a2` to `a5`. A static
  routine at 0xc000000000038390 resolves the processor and level to the node's interrupt-table record, the pointer to the processor's
  mask word and the group (0 for levels below 64, else 1). Under the record's lock at +0x1e00 (`mutex_spinlock_spl`, level word at
  +0x1e08) it looks at the flags word of the level's 0x30-byte entry (+0x122c): it proceeds only when bit 0 (reserved) is set and bit 1
  (connected) is clear. Then it stores into the level's 0x48-byte entry (record + level * 0x48): the words from `a4` at +0x0, `a5` at +0x8
  and `a3` at +0x10 and the halfword from `a2` at +0x38; sets flag bit 1; writes `level + group * 0x40` to
  `PI_INT_PEND_MOD` (+0x90 of the node alias `0x9200000001800000`, node taken from the processor's record halfword at +0x422); ORs
  `1 << level` into the processor's mask word; bumps the per-slice count at `record + 0x1e18 + 4 * slice`; when entry flag bit 8 (0x100) is
  set it sets bit 9, stores the processor number at +0x40 of the entry and, if the word at +0x1e20 is nonzero, calls a static routine at
  0xc00000000003a4e8 with the entry, the node, the level and the `a2` value; and finally writes the mask word to the node alias
  doubleword `PI_INT_MASK0_A` (+0xa8) or, for group 1, `PI_INT_MASK1_A` (+0xb0), plus 16 bytes per slice. It releases the lock
  with `mutex_spinunlock` and returns 0 after a connection; the value it returns when the level is not reserved or already connected was not
  read. Inferred: the handler field assignment, since the stored words are only consumed by the dispatcher; the group rule, from the
  literal 64 and the two mask registers.
- `kf_memory_bank_disable` (`IP27/unix` at 0xc00000000015361c,
  660 bytes) records in the boot-environment variables that one memory bank of a node is to be disabled at the next start. It takes the
  bank number in `a0` and the node number in `a1`, and returns 1 when it set the variables and 0 otherwise. It reads the doubleword at +0x18 of
  `0x9200000001a00000 + (node << 32)` (`MD_MEMORY_CONFIG`) and, when `get_nvreg` (0x3884) returns the character 'y', converts it with
  `translate_hub_mcreg`. It reads six variables with `ip27log_getenv`: the disabled-size string, the disable-reason string, the disabled
  bank mask, the memory size, the memory mask and the swap-bank flag; any read that fails (negative or, for the later ones, nonzero)
  returns 0. For bank 0 it first compares the swap-bank value with the empty string: a difference returns 1 unchanged, and the
  memory-size string's third character not '2' (or its first character '0') returns 0. It formats the bank number with "%d" and
  appends it to the disable-mask string when `strstr` does not find it; turns a reason character '0' of that bank into '3'; stores
  `'0' + ((config >> (3 * bank)) & 7)` into that bank's character of the size string; writes the size, reason and mask variables back with
  `ip27log_setenv`; and for bank 0 also sets the swap-bank variable to "2". Inferred: the variable meanings, from the variable strings ("DisableMemSz",
  "MemDisReason", "DisableMemMask", "MemorySize", "SwapBank", "MemMask") and the three-bit size field, which comes from the shift of 3.
- `sysctlr_keepalive` (`IP27/unix` at 0xc00000000003f9ec,
  616 bytes) keeps the module system controller's heartbeat alive; it takes no arguments, works on the first module in `modules`
  and returns nothing. It computes the time in seconds as `real-time counter * 800 / 1000000000` (the doubleword at
  `0x9200000001030100`; the counter ticks every 800 ns). The module's heartbeat state is the word at +0x2f0 and the time of the
  last heartbeat is the doubleword at +0x2f8; a global word (`gp - 0x7274`) says whether heartbeats are wanted. State and want
  decide the action. Not wanted and state 0: return. Not wanted and state nonzero: `cmn_err` level 5 "Disabling heartbeats", then a
  disable. Wanted and state 0: if the halfword at `gp - 0x6796` is nonzero (a debugger is installed) it prints "Heartbeats not enabled
  (debugger installed)", clears the want word and returns; otherwise it prints "Enabling heartbeats" and enables. Wanted and state nonzero:
  it returns when fewer than 10 seconds have passed since the stored time, else sends a keepalive. Each action takes the module's
  lock at +0x2a8 (`mutex_spinlock_spl` at level `spl7`) and calls `_elsc_hbt` with the controller at +0x30 and the arguments (30, 20)
  to enable (success stores 1 into the state word), (0, 0) to disable (success stores 0), or (0, 1) to send a keepalive (success stores
  the current seconds at +0x2f8); it releases the lock with `mutex_spinunlock`. A negative result calls `cmn_err` level 4
  "module %M MSC: Error %s heartbeat: %s" with the word "enabling", "disabling" or "sending" and `elsc_errmsg`; the result -112 (-0x70)
  also calls `cmn_err` (level 0x804) "Keyswitch must be in diagnostic position for heartbeats". After a failed enable the want word is
  cleared. Established: the state machine and arguments. Inferred: the role of `_elsc_hbt`'s arguments, which are named nowhere in the routine.
- `intr_dumpvec` (`IP27/unix` at 0xc00000000003a0d8,
  608 bytes) prints the interrupt state of one node: the two interrupt-pending words of the node's Hub, the interrupt-table record behind each,
  and every level that is reserved or pending. It takes the node number in `a0` and a print function in `a1`, called through `jalr` for
  every line, and returns nothing. A node number below zero, or not below the word at `gp` + 7340 (the node count), prints
  "intr_dumpvec: cnodeid out of range: %d"; a node whose entry in the halfword table at 0xc0000000014d4e80 (indexed by twice the node
  number) is -1 prints "intr_dumpvec: Bad cnodeid: %d". Both return after the message. Otherwise that halfword shifted left 32 is the node's
  alias offset, and the node's record pointer is the doubleword at `[[0xffffffffffffc400] + 8 * node]`. Two passes follow, numbered 0 and 1.
  Pass 0 uses the interrupt-table record at +0xcd8 of the node record and pass 1 the one at +0x2b00. Each pass forms three addresses
  on `0x9200000001800000` plus the alias offset: the pending doubleword at +0x98 (pass 0) or +0xa0 (pass 1), the first processor's mask
  at +0xa8 or +0xb0 and the second processor's at +0xb8 or +0xc0, and loads the doubleword at each. It then prints "Node %d PI %d INT_PEND%d (0x%x):"
  with the node, 0, the pass number and, as the fifth argument, the address of the pending register (a4 is not changed between its
  formation and the call). The word at +0x1e20 of the record chooses " Ithreads enabled" (nonzero) or " Ithreads disabled", and the lines
  " vector_count = %d, vector_state = %d" (words +0x1e14 and +0x1e10), " CPU A count %d, CPU B count %d" (words +0x1e18 and +0x1e1c)
  and " &vector_lock = 0x%x" (the address record + 0x1e00) follow. It then walks levels 0 to 63: when bit 0 of the word at +0x122c + 0x30 * level
  is set, or the level's bit is set in the pending value, it calls the static routine at 0xc000000000039f18 (reached by the `jal` at 0xc00000000003a250,
  which the listing labels as part of `intr_clear_all`) with the 0x30-byte entry at +0x1200 + 0x30 * level in `a0`, the 0x48-byte handler entry at
  0x48 * level in `a1`, the level in `a2`, the pending value in `a3`, the two mask values in `a4` and `a5` and the print function in `a6`. Each pass ends
  with a bare newline. Established: the control flow, the offsets and the address arithmetic. Inferred: that the 0x30-byte and 0x48-byte
  entries are the level's flag and handler records, from `intr_connect_level` storing handler words at 0x48 * level and the flag word at +0x122c;
  what the static routine prints beyond its "  Bit %02d: %s: func 0x%x arg 0x%x prefunc 0x%x" line was read only in outline.
- `check_ni_errors` (`IP27/unix` at 0xc000000000032f40,
  604 bytes) looks for a network (NI) error that needs the system to act and returns 1 when it found and reported one, 0 otherwise; it takes no
  arguments. It reads `NI_PORT_ERROR` (`0x9200000001608008`) and keeps the value, and reads the network status word (`0x9200000001600000`). With
  none of the flag bits 24 to 31 and 33 to 37 of the port error set (mask 0x3eff000000), it tests the status word against 0x30000000; when that
  is clear it reads `NI_PROTECTION` (`0x9200000001600010`) and returns 1 after `cmn_err` level 20 "NI Link went down (0x%x)" (the value
  printed is the zero left in `a2`) when the register is nonzero, or, when it is zero, calls `cmn_err` level 21 "Detected a link reset due to other
  partition reset", reads the clear alias at `0x9200000001608088` and returns 0. When the status word has bits set, it reads `PI_INT_PEND1`
  (`0x92000000010000a0`) and, when bit 39 or bit 40 of it is set (levels 103 and 104), calls `cmn_err` level 20 "Hub Widget 0 has been Shutdown"
  and returns 1; with neither set it returns 0. With any of the listed port-error flags set it first looks at bit 37 (link reset): when that bit
  is set and `NI_PROTECTION` is zero it takes the same "other partition reset" path (message, clear alias read, return 0); in every other case
  it calls `cmn_err` level 20 "Fatal NI error interrupt" and "    NI PORT_ERROR 0x%x" with the port error, then one more `cmn_err` per set flag in this order: bit 36
  "Internal NI error", bit 35 "Bad message", bit 34 "Bad destination", bit 33 "Receiver had a FIFO overflow" (each printing the bit mask), bits
  31:28 "Credit timeout (0x%x)" with the four-bit field (`(value >> 28) & 0xf`) and bits 27:24 "Tail timeout (0x%x)" with `(value >> 24) & 0xf`. It ends with two
  calls to `protected_broadcast` (arguments 103, then 104) and returns 1. Established. Inferred: that bits 29:28 of the status word are a link
  state, and that protected-broadcast levels 103 and 104 are the NI-error and widget-shutdown signals, from the messages and the matching pending bits.
- `i2c_master_xmit` (`IP27/unix` at 0xc00000000009ae74,
  600 bytes) writes bytes to an I2C slave through a node's I2C master and is the write twin of `i2c_master_recv`. It takes the node number in `a0`, the slave address
  in `a1`, the buffer in `a2` and the length in `a3`, a pointer to the sent count in `a4`, a time allowance in `a5` and a flag in `a6`. It zeroes the count, calls
  `i2c_arb` (node, `a5`, 0) and returns a negative result unchanged; when `a6` is nonzero and the result is 0 it returns -10. The registers are the
  data register at +0x0 and the status register at +0x8 of `0x9200000001a20000 + (node << 32)`. A status with any of bits 1, 2 or 4 (mask 0x16) set before the
  start returns -2 with no store. The routine stores `address << 1` to the data register (bit 0 clear, write), then 0xc5 to the status register and
  waits for status bit 7 (0x80) to clear, the deadline being `a5` plus the Hub real-time counter (`0x9200000001030100`) times 800 divided by 1000
  read at entry; an error bit during any wait, a timeout (-6 after the address, -7 after a data byte) and bit 3 set after the address (-3) all end
  the call. Each data byte is stored to the data register, awaited the same way and counted in `*a4` before bit 3 of the status is tested; bit 3 set
  stops the loop without an error. The end is status 0x45, data 0xfe and a last wait (timeout -6), returning 0. Every return after the address
  store, including the success one, first stores 0xc2 to the status register. Established. Inferred: the bit meanings (busy as bit 7, not-acknowledged as
  bit 3), from the way the loop uses them.
- `check_dir_state` (`IP27/unix` at 0xc00000000002ab2c,
  600 bytes) prints the memory directory state of every populated bank of one node. It takes the node number in `a0` and a print function in `a2`, and returns the
  first nonzero result of the per-bank walkers, else 0. It reads the doubleword at +0x18 of `0x9200000001a00000 + (node << 32)` (`MD_MEMORY_CONFIG`), prints the header
  "Node   ___Off___    __Owner__      __State__   (DirLo)" and loops over eight banks with three bits each: the field `(config >> (3 * bank)) & 7` gives a size of
  `4 << field` units of 1 MiB (zero field: size 0). Bit 28 of the configuration (0x10000000) chooses the walker for all banks: with it set the routine calls the
  static routine at 0xc00000000002a8b4 (`mdir_pstate`), with it clear the one at 0xc00000000002a9ec (`mdir_sstate`); each is called with -1, the bank's base
  (`(node << 32) | (bank << 29)`), the size in bytes (`size << 20`) and the print function. A size of 256 units is split into four calls of a quarter of the size
  (signed divide by four) at the base and at base + 0x8000000, + 0x10000000 and + 0x18000000, each call stopping the whole routine on a nonzero result. The
  walker `mdir_pstate` loops over 4096-byte pages and, within a page, over 128-byte steps, calling a static routine at 0xc00000000002afa0 for each entry. Established
  for the routine's own body; the walkers' work was read only as far as their loop structure. Inferred: that bit 28 of the configuration selects the
  premium directory format, from the walker names.

## Routines in the IP27 `hubspc.o` build

One entry per routine, read in full from the IRIX 6.5.30 IP27 `hubspc.o` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o`, a relocatable
object). Addresses are offsets in its `.text`. The object registers two special-file drivers on the node controller vertex and
keeps a list that ties each device node it creates back to its controller. The list head is the doubleword at the start of
`.sbss` and the spinlock `cpuprom_spinlock` is the word at `.sbss` +8. A list record is 16 bytes: +0 holds the device vertex,
+4 the controller vertex and +8 the next record. The `.srdata` literal pool has four doubleword slots: the `.rodata` base,
`compact_to_nasid_node`, `mem_refcnt_attach` and `cpuprom_attach`, in that order. The `.rodata` strings are `_detail_invent`
(+0), `prom` (+16), `hubspc_` (+24) and `promlist` (+32). `.lit8` holds `0x90000000100000a4`, `0x90000000100000a0`,
`0x9200000001a00000` and the mask `0xffc00fffffffffff`. A device vertex carries a small integer set with `device_info_set` and
read back with `device_info_get`: 1 marks the `prom` node `cpuprom_attach` makes; every routine below that dispatches on it
treats 0 as the other driver (`mem_refcnt_*`, from another object) and anything else as an error.

- `prominfo_add` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x0, 100 bytes)
  takes the controller vertex in `a0` and the device vertex in `a1`. It allocates a 16-byte record with `kmem_alloc` (flags 0),
  stores `a0` at +4 and `a1` at +0 (that store sits in the delay slot of the `mutex_spinlock` call on `cpuprom_spinlock`), links
  the old list head at +8 and makes the new record the head, then releases the lock with `mutex_spinunlock` (the head store is in
  its delay slot). New records go on the front. It returns nothing of its own. Established.
- `prominfo_del` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x64, 120 bytes)
  takes a device vertex in `a0`. Under `cpuprom_spinlock` it walks the list from the head comparing the word at +0 of each
  record, and on a match stores that record's +8 into the link that pointed at it (the head or the previous record's +8). It
  makes no call to free the record. With no match it changes nothing. No routine of this object calls it. Established.
- `prominfo_nodeget` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0xdc, 112 bytes)
  takes a device vertex in `a0` and returns the word at +4 of the first record whose +0 equals it, or 0 when none does. It
  releases the spinlock before the match's +4 is loaded: the load is in the delay slot of the branch that follows the
  `mutex_spinunlock` call. Established. Inferred: the result is the controller vertex that `cpuprom_attach` paired with the
  device, because `prominfo_add` stores its first argument at +4 and `cpuprom_map` passes the result to `hubdev_prombase_get`.
- `cpuprom_detailed_inventory_info_add` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x14c, 128 bytes)
  takes the device vertex in `a0` and the controller vertex in `a1`. It gets the compact node number with `hubdev_cnodeid_get`
  on `a1` (cut to 16 bits), allocates a 32-byte inventory record with `klhwg_invent_alloc` (class argument 21), stores 1 at +20
  and 1 at +4 (a byte), the word read from `0x90000000100000a4` at +12 and the word read from `0x90000000100000a0` at +16,
  attaches the record to the device vertex under the label `_detail_invent` with `hwgraph_info_add_LBL`, and exports that label
  with `hwgraph_info_export_LBL` (length 32). Established. Inferred: the two words are firmware-supplied identification of the
  node's PROM, because they are copied unchanged into an inventory record that is labelled `_detail_invent`. Unknown: what lies at
  physical `0x100000a0` and `0x100000a4`. Route: the Bedrock census lists the same physical offsets for several routines, and the PROM's own
  readers of them are the next place to look.
- `cpuprom_attach` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x1cc, 128 bytes)
  takes the controller vertex in `a0`. It calls `hwgraph_char_device_add` with that vertex, the name `prom`, the prefix `hubspc_`
  and a stack slot that receives the new device vertex, then `device_inventory_add` (that vertex, class 21, 1, three zeros),
  `cpuprom_detailed_inventory_info_add` (device, controller), `device_info_set` (device, 1) and `prominfo_add` (controller,
  device). It always returns 0 and ignores the status of every call; the first `hubdev_cnodeid_get` result is unused. Established.
- `cpuprom_map` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x24c, 204 bytes)
  takes the device vertex in `a0`, a map handle in `a1` and a length in `a3`. It calls `prominfo_nodeget` and returns 5 when
  nothing is found. Otherwise it maps the controller's PROM base with `v_mapphys` (handle `a1`, the base from
  `hubdev_prombase_get`, length the smaller of `a3` and `0x10000000`) and returns a nonzero status unchanged. On success it takes
  the nasid from the halfword table `compact_to_nasid_node` indexed by the compact node number, reads the doubleword at
  `0x9200000001a00000 + (nasid << 32) + 24`, clears bits 53:44 with `0xffc00fffffffffff` and ORs in `257 << 44` when the byte at
  `0xffffffffffffc523` is zero or `121 << 46` when it is not, stores it back and returns 0. Established. It is the same
  sequence as the `IP27/unix` copy described under "Routines of the IP27 kernel" for `cpuprom_map`, which names the doubleword
  `MD_MEMORY_CONFIG`; the third argument is ignored here.
- `cpuprom_unmap` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x318, 8 bytes)
  returns 0 at once and touches no register or memory, so mapping the PROM window leaves nothing to undo. Established.
- `hubspc_init` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x320, 52 bytes)
  registers the two drivers with `hubdev_register`, `mem_refcnt_attach` first and `cpuprom_attach` second, then calls
  `spinlock_init` on `cpuprom_spinlock` with the name `promlist`. Established.
- `hubspc_open` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x354, 116 bytes)
  takes a pointer to the device number in `a0` and three more arguments. It reads the word at that pointer, passes it to
  `device_info_get`, and on 0 returns `mem_refcnt_open` called with the four original arguments. On 1 it calls `cap_able` with
  `1 << 37` and returns 0 when that grants the capability and 1 when it does not (`sltiu` on the result sits in the delay slot of
  the jump back). Any other value returns 19. Established.
- `hubspc_close` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x3c8, 108 bytes)
  takes the device number in `a0`. `device_info_get` of it selects: 0 returns what `mem_refcnt_close` returns for the four
  original arguments, 1 returns 0 without calling anything, any other value returns 19. Established.
- `hubspc_map` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x434, 156 bytes)
  returns 6 without further work when the fourth argument `a3` is 0. Otherwise it calls `device_info_get` on `a0` (twice with the
  same argument; the first result is overwritten), then on 0 returns `mem_refcnt_mmap` called with all five arguments, on 1
  returns `cpuprom_map` called with `a0` to `a3` (the fifth argument is dropped), and on any other value returns 19. Established.
- `hubspc_unmap` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x4d0, 96 bytes)
  takes the device number in `a0` and a second argument. `device_info_get` of `a0` selects: 0 returns `mem_refcnt_unmap` of both
  arguments, 1 returns `cpuprom_unmap` of both (so 0), any other value returns 19. Established.
- `hubspc_ioctl` (`IP27/usr/cpu/sysgen/IP27boot/hubspc.o` at 0x530, 124 bytes)
  takes six arguments with the device number in `a0`. `device_info_get` of it selects: 0 returns `mem_refcnt_ioctl` called with
  all six, 1 returns 0 without examining the request, any other value returns 19. Established. So the `prom` node accepts every
  ioctl request and does nothing for it.

## Open

Graded entries; each ends with the route that would settle it. Collected in [docs/open-questions.md](../../docs/open-questions.md).

- **PI write-buffer error bits: which fault sets which (bits 4 to 7, 18, 19).** Established: names, positions, handler class and the
  latched status (above). Inferred: write error = an error response to a write, timeout = no response within the CRB time-out
  (`0x30`, `0x38`, written by `per_hub_init` from kernel variables; the unit is not read). Unknown: the transaction that produces
  each, including partial (4-byte) stores and stores to a node that does not exist. Next: read `huberror_process_wrb_error`'s
  callers' tests against `hub_ioerror_handler`, the PROM's error dump routines (0x1fc056e0 region reads the MD latches), and the
  "kf_*" analysis routines in the kernel that print a cause per CRB status.
- **Cause level 6 and the II error level.** Established: the level and the registration. Unknown: the CPU interrupt-pending bit that
  level 6 is, and the number `intr_heuristic` returns for the II error. Next: read the trap dispatcher that indexes the cause
  table and `intr_heuristic`.
- **Status clear semantics.** Established: a store of zero to `0x448`/`0x468` follows every read of a valid first error. Unknown:
  whether reading `0x438`/`0x458` clears status 0, and whether status 1 alone is released by the store. Next: no held code touches
  the status 0 clear aliases; a published erratum or a capture.
- **Hub register protection.** Established: the report path. Unknown: which writes `PI_CPU_PROTECT` and the II protection registers
  (`0x400100`, `0x400108`, not reached) refuse and what the refused store latches. Next: `hub_ioerror_handler` in full.
- **Registers with no named role.** `0x2000c8`, `0x2000d0`, `0x2000d8`, `0x2000e0`, `0x400160`, `0x400190`, `0x4002c8` (not in
  the public headers). Next: `hub_ifdr_fix_value`, `hub_piomap_alloc`, the I/O interface initialisation in full.
- **Router vector access.** Inferred end to end (`vector_*_node`). Next: read the three routines in full and the router strings.
- **PROM images beyond the CPU PROM.** The I/O-board PROM (`io6prom.img`) and the IP35 PROM reach Hub-class registers through
  the same windows but are not in this census (the IP35 PROM belongs to the Bedrock page).
