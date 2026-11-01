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
  88 bytes) takes a record in a0 and, for slice 0 and then slice 1, tests the word at +40 + 8 * slice. When it is
  nonzero and the counter at 0x9200000001030100 is more than `0x55d4a80` (90,000,000 ticks) past the timestamp at +24 +
  8 * slice, it stores 0 to +56 + 8 * slice and then to +40 + 8 * slice. No register is written. Inferred: the two
  words are a processor-interface error summary and detail saved earlier.
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
