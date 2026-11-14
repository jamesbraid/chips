<!-- generated from devices/shub/registers.toml by defs-gen - do not edit, change the source -->

# SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs

SHub 1 offsets as the SGI Linux ia64 platform header defines them (SH1_ names), relative to the node's register space; the SHub 2 overlay changes them. Every register is 64 bits wide unless noted, because the kernel reaches all of them with 64-bit loads and stores. The header gives neither the unit a register belongs to nor reset values; the unit named in each doc is inferred from the register's name prefix and address block. Reset values are unknown except where the header's INIT macro names a value, which is recorded as inferred. Roles are paraphrased from the header comments and the kernel's use.

Unit `shub`, macro prefix `SHUB`.
Default source: Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `md_dqlp_dir_privilege_vector` | 0x100030300 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `md_dqrp_dir_privilege_vector` | 0x100050300 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ipi_int` | 0x110000380 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc_int_config` | 0x110001480 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc_int_enable` | 0x110001500 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred` | 0x110010000 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred_alias` | 0x110010008 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ipi_access` | 0x110060480 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `shub_id` | 0x110060580 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ptc` | 0x1101a0000 | w | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `int_cmp` | 0x1101b0080 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc` | 0x1101c0000 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pi_cam_control` | 0x120050300 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pio_write_status` | 0x120070200 | r | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pio_write_status_alias` | 0x120070208 | w | 64 | 2 |  | unknown | inferred | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `junk_bus_led` | 0x7fed00000 | w | 16 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |

### Register `md_dqlp_dir_privilege_vector`

Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege vector for acc=0'). Defined by the header; no use in any kernel file read. Layout and role unknown.

### Register `md_dqrp_dir_privilege_vector`

Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names.

### Register `ipi_int`

Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR window with send set, the target's physical processor id, a delivery type, a vector and a fixed base. The kernel stores through uncached physical mode with release ordering, after a memory barrier. On a SHub 1 revision 2 or lower it holds a global lock around the store and waits for the PIO write status to drain.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `send` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Sending the message; the header says it generates a pulse. |
| 59:52 | `idx` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Interrupt vector delivered to the target processor. |
| 49:21 | `base` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Optional interrupt vector area, 2 MiB aligned. The kernel always puts 0xfee here. |
| 19:4 | `pid` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Processor id, the same value the target processor's SAPIC id holds. |
| 3 | `agent` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Must be zero for SHub. |
| 2:0 | `type` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Interrupt type: 0 interrupt, 2 platform management interrupt, 4 NMI, 5 INIT. |

### Register `rtc_int_config`

Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and processor id fields and leaves type, agent and base zero. The register has the same layout as the IPI message, without the send bit. A fourth comparator (RTC 0) exists; the driver comment says firmware uses it, and the header defines nothing for it.

Array of 3 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:52 | `idx` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 49:21 | `base` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 19:4 | `pid` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 3 | `agent` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 2:0 | `type` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `rtc_int_enable`

Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes the configuration, enables, and only then writes the real expiry, in that order.

Array of 3 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `event_occurred`

Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them. Only bits the header names are recorded; the others are unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `ii_int1` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 1. |
| 29 | `ii_int0` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 0. |
| 28 | `ipi_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending IPI interrupt. |
| 26 | `rtc3_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 3 interrupt. |
| 25 | `rtc2_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 2 interrupt. |
| 24 | `rtc1_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 1 interrupt. |
| 20 | `uart_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending junk-bus UART interrupt. |

### Register `event_occurred_alias`

Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.

### Register `ipi_access`

Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross-partition driver reading it as the target of a protected remote read; the driver comment says there is no special reason for that choice. So the register can be read without harm; its bit layout and write behaviour are unknown.

### Register `shub_id`

SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in the fallback for an old PROM the nodes-per-bit field, which it reports as the region size. SHub 2's counterpart is not named in the header.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52:48 | `nodes_per_bit` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Nodes per bit (the kernel's name for the region size). The positions come from macros in the SAL header; the role is the kernel's use of the value as the region size in its old-PROM fallback. |
| 31:28 | `revision` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Chip revision. The kernel treats 2 or lower as SHub 1.1. |

### Register `ptc`

Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel writes the two registers of that node's global window back to back with interrupts and interruption collection off, the first with a type bit, the page-size exponent, the region id and a start bit, the second with the virtual address and a start bit; both stores are in one atomic assembly sequence. It does this once per page of the range, after taking a global lock, for every node that has the mm's processors, except the local node which uses the processor's own global purge instruction instead. Entry 0 is the control word and entry 1 the address word. After a batch of nodes it waits on the PIO write status.

Array of 2 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `start` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Start. Set in the first write; entry 1 has its own start bit at the same position. |
| 62:8 | `rid` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Region identifier and region number: the kernel passes the mm's context shifted left by three, ORed with the region number of the address. The upper bound is inferred from bit 63 being the start bit. |
| 7:2 | `ps` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Page size as a power of two. The field is six bits wide only by inference: the kernel passes a value below 64 and the next field starts at bit 8. |
| 0 | `type_bit` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Header title: type. The kernel always writes 1; no other value is known. |

### Register `int_cmp`

Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).

Array of 3 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `compare` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `rtc`

Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `counter` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `pi_cam_control`

Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the kernel writes 0x8000000000000010 here on every timer tick, through the address of its own node. What the value does is unknown.

### Register `pio_write_status`

PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O write barrier spins until the pending write count shows idle. The kernel stores the address of the instance for its slice (the slice is the processor's position within the node) in its per-processor data.

Array of 2 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:56 | `pending_write_count` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Count of PIO writes still in flight. On SHub 1 the kernel treats all ones as idle (see PIO_WRITE_STATUS_IDLE); the header gives no reason. |
| 1 | `write_deadlock` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | A deadlock response was detected for a PIO write. |

### Register `pio_write_status_alias`

Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.

Array of 2 registers, stride 128.

### Register `junk_bus_led`

Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps a 16-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.

Array of 4 registers, stride 65536.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `IPI_BASE_VALUE` | 0xfee | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Constant the kernel puts in the base field of every IPI message: 0xfee in units of the field, i.e. the 0xfee00000 interrupt area of IA-64 platform conventions. Used with the vector in the idx field. |
| `PIO_WRITE_STATUS_ALIAS_CLEAR` | 0x7 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Value the kernel's TLB-purge deadlock recovery writes to the alias on SHub 1 to clear the deadlock, write error and multiple write error bits (assembly comment). |
| `PIO_WRITE_STATUS_IDLE` | 0x3f00000000000000 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | What the kernel waits for the masked pending-write count to equal on SHub 1: all six bits set, not zero. The kernel comment points at a defect number for this behaviour; the defect text is not in the sources read. The SHub 2 overlay sets zero. |
| `PI_CAM_WAR_VALUE` | 0x8000000000000010 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Value the kernel writes to the PI CAM control register from every timer tick on a SHub 1 of revision 2 or lower. Meaning not stated by the sources. |
| `RTC_CONFIG_MASK` | 0xff3ffffffefffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of an RTC interrupt configuration register (header SH_RTC1_INT_CONFIG_MASK): bits 59:52 and 49:0 except bit 20. |
| `RTC_ENABLE_MASK` | 0x1 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of an RTC interrupt enable register. |
| `RTC_MASK` | 0x7fffffffffffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of the real-time clock and of each comparator: 55 bits. The mmtimer driver reports 55 as the clock width. |
| `SHUB_1_1_MAX_REVISION` | 0x2 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Revision field value at or below which the kernel enables its SHub 1.1 workarounds. |
