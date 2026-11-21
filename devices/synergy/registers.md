<!-- generated from devices/synergy/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 4c3ea2546f72bcace270f575e55b39b69ccbbb218f4ea2c4bd2699014b6f3a17 -->

# Synergy: the Itanium processor-bus ASIC of the SN1 IA-64 node (register offsets the Linux port uses)

Offsets are in the Synergy's own register space, all 64-bit. Every offset and access sequence comes from SGI's Linux SN1 IA-64 platform code, so they are established as software facts; field meanings beyond what a comment or an operand states are inferred or unknown. No Synergy specification is held. Reset values are unknown throughout: the only writer of a power-on state is a simulator-only fake PROM.

Unit `synergy`, macro prefix `SYN`.
Default source: Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `vec_mask3_a` | 0x2a0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `vec_mask3_b` | 0x2a8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `vec_mask2_a` | 0x2b0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `vec_mask2_b` | 0x2b8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `vec_mask1_a` | 0x2c0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `vec_mask1_b` | 0x2c8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `vec_mask0_a` | 0x2d0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `vec_mask0_b` | 0x2d8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `gbl_perf_a` | 0x330 | r | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `gbl_perf_b` | 0x338 | r | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `fsb_config` | 0x450 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntl0_a` | 0xab0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntl0_b` | 0xab8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntl1_a` | 0xac0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntl1_b` | 0xac8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntr0_a` | 0xad0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntr0_b` | 0xad8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `syn_tag_disable_way` | 0xae0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntr1_a` | 0xaf0 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |
| `perf_cntr1_b` | 0xaf8 | rw | 64 |  |  | unknown | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) |

### Register `vec_mask3_a`

Interrupt vector enable mask, vectors 192 to 255, for the processor in bus slot 0. Bit n enables vector 192 plus n. The kernel sets a processor's bit here when it is in slot 0 and clears it in the matching B register. The fake PROM writes all ones to every mask register at start.

### Register `vec_mask3_b`

Same as vec_mask3_a for the processor in bus slot 1.

### Register `vec_mask2_a`

Vector enable mask, vectors 128 to 191, slot 0.

### Register `vec_mask2_b`

Vector enable mask, vectors 128 to 191, slot 1.

### Register `vec_mask1_a`

Vector enable mask, vectors 64 to 127, slot 0. The kernel's Bedrock-pending-bit interrupts live here and in the next register.

### Register `vec_mask1_b`

Vector enable mask, vectors 64 to 127, slot 1.

### Register `vec_mask0_a`

Vector enable mask, vectors 0 to 63, slot 0.

### Register `vec_mask0_b`

Vector enable mask, vectors 0 to 63, slot 1.

### Register `gbl_perf_a`

Offset established; role inferred. From the 2.4.18 patches of April 2002 the kernel's I/O write barrier reads this register for a processor on Synergy 0 (gbl_perf_b for Synergy 1) in a loop that sleeps 5 microseconds while the value is zero, after first reading the Bedrock revision register. The code comment calls the polled thing the Bedrock PIO write status register, and the macro names are GBL_PERF_A/B. The loop therefore implies the register reads nonzero when the processor's earlier uncached stores have drained, but the comment says 'clear', so the polarity is unsettled. Which bits carry that, and what the name's 'perf' means, is unknown.

### Register `gbl_perf_b`

Counterpart of gbl_perf_a, polled by processors on Synergy 1. See there.

### Register `fsb_config`

Written once per Synergy by the fake PROM with (nasid << 16) | (synergy << 9); the comment says it sets the NASID in FSB_CONFIG. The value written and the offset are established; the field meanings are inferred from the comment and the operands; every other bit is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `nasid` | inferred |  | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Node's NASID. Seven bits in M-mode; the field width here is the byte the shift leaves, not a stated limit. |
| 9 | `synergy` | inferred |  | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Synergy number, 0 or 1, as the fake PROM passes it. |

### Register `perf_cntl0_a`

Performance control, bus 0, counter A. Only with the kernel's optional perf option. Bit 45 enables counting (the code sets it on every event word it stores, with the comment 'bit 45 is enable'); every other bit of the event select is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45 | `enable` | established |  | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Counting enable, from the kernel's comment. |

### Register `perf_cntl0_b`

Performance control, counter B. The header labels it bus 0, but the kernel's multiplexer writes it through Synergy 1 (and CNTL0_A through Synergy 0), the same event word to both, so 'B' may mean Synergy 1; unknown. Same layout as perf_cntl0_a.

### Register `perf_cntl1_a`

Performance control, bus 1, counter A. Defined in the header; the kernel's multiplexer never writes it.

### Register `perf_cntl1_b`

Performance control, bus 1, counter B. Defined, unused.

### Register `perf_cntr0_a`

Performance counter 0, A. Read through the remote window and masked to 40 bits, then written zero after each interval.

### Register `perf_cntr0_b`

Performance counter 0, B. Same use, but read and cleared through Synergy 1 while counter 0 A is read through Synergy 0, so the header's 'FSB0' label for both is doubtful; unknown.

### Register `syn_tag_disable_way`

Cache-way disable mask for the L4 cache. The kernel's flush routine writes 0xff with one way's bit cleared, reads a run of 512-byte blocks through nine aliases 8 MB apart so that only that way can allocate, repeats for each of eight ways, then writes 0. That a set bit disables a way is inferred from the register's name and this use. Bits above 7 are unknown. First seen in the 2.4.16 patch of November 2001.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `way_disable` | inferred |  | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | One bit per L4 way; a set bit takes the way out of allocation. |

### Register `perf_cntr1_a`

Performance counter 1, A. Defined, unused by the kernel.

### Register `perf_cntr1_b`

Performance counter 1, B. Defined, unused.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `L4_BLOCK_BYTES` | 0x200 | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Block size the flush routine steps by. |
| `L4_BYTES` | 0x4000000 | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Size of the Synergy's L4 cache as the kernel's flush routine models it: 64 MB. Whether silicon matched is not stated. |
| `L4_WAYS` | 0x8 | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Associativity of the L4 cache in the kernel's model. |
| `LOCAL_BASE` | 0xe0000000000 | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Physical address of the local register space as an Itanium on this bus sees it (the code's SSPEC_BASE). Which Synergy answers is the one on the issuing processor's bus; the code leaves the choice open. |
| `PERF_COUNTER_BITS` | 0x28 | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | The kernel masks a counter read to 40 bits (0xffffffffff). The counter may be wider; this is what software uses. |
| `REMOTE_WINDOW_SYN0` | 0x34000000 | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Offset inside a node's hub special space of Synergy 0's registers as seen from another node: the remote register window (0x30000000 into the space) plus 0x04000000. |
| `REMOTE_WINDOW_SYN1` | 0x35000000 | established | Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) | Same for Synergy 1: the remote register window plus 0x05000000. |
