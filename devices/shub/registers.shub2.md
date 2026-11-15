<!-- generated from devices/shub/registers.shub2.toml by defs-gen - do not edit, change the source -->

# SHub 2 registers outside the I/O interface, differences from SHub 1

SHub 2 offsets as the SGI Linux ia64 platform header defines them (SH2_ names). Registers the header defines only for SHub 1 are removed; for those, SHub 2's address is not in the sources read (unknown). Field layouts not patched here are the SHub 1 ones: the header gives one set of field macros for both chips.

Unit `shub2`, macro prefix `SHUB2`.
Default source: Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `ipi_int` | 0x10000380 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc_int_config` | 0x10001480 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc_int_enable` | 0x10001500 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred` | 0x10010000 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred_alias` | 0x10010008 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ipi_access` | 0x10060c00 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `int_cmp` | 0x101b0080 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pio_write_status` | 0x20070200 | r | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pio_write_status_alias` | 0x20070208 | w | 64 | 4 |  | unknown | inferred | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `bt_eng_csr` | 0x30040000 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `bt_eng_src` | 0x30040080 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `bt_eng_dest` | 0x30040100 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `bt_eng_notify` | 0x30040180 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `junk_bus_led` | 0xf0000000 | w | 16 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ptc` | 0x170000000 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc` | 0x2101c0000 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |

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

Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them; Linux only reads it. Bits the header names are established. SAL 5.04 reads it for the error bits (mask 0x7ef, sites 0xffa239a0 and 0xffa23fd6) and for bit 21 (site 0xffa31506), and writes bits 5 and 8 to this register itself (sites 0xffa32816 and 0xffa32996); a model should OR written bits in (inferred). Zero from reset is tolerated; the reset value is unknown. Bit 21 must read 0 for the PROM's INIT handling. See interrupts.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `ii_int1` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 1. |
| 29 | `ii_int0` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 0. |
| 28 | `ipi_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending IPI interrupt. |
| 26 | `rtc3_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 3 interrupt. |
| 25 | `rtc2_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 2 interrupt. |
| 24 | `rtc1_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 1 interrupt. |
| 23 | `rtc0_int` | inferred |  | SAL 5.04 PROM site 0xffa31d96 (alias write 0x800000 right after RTC0's enable is cleared) | Pending RTC comparator 0 interrupt, from the sequence and from Linux numbering comparators 1 to 3 as bits 24 to 26. Name is ours. |
| 21 | `bit21` | inferred |  | SAL 5.04 PROM site 0xffa31506 (read), 0xffa31566 (clear through the alias, 0x200000) | Read by the PROM's INIT handling before it forwards INIT to the other processors, cleared through the alias. Meaning unknown; name is ours. |
| 20 | `uart_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending junk-bus UART interrupt. |
| 8 | `bit8` | inferred |  | SAL 5.04 PROM site 0xffa32816 (write to the register), 0xffa23a20 (mask 0x7ef) | As bit 5. Name is ours. |
| 5 | `bit5` | inferred |  | SAL 5.04 PROM site 0xffa32996 (write to the register), 0xffa23a20 (mask 0x7ef) | In the PROM's error mask 0x7ef; the PROM also writes this bit to the register itself in its express-path workaround. Name is ours. |
| 3 | `bit3` | inferred |  | SAL 5.04 PROM site 0xffa0bb16 and 0xffa0bb46 | The PROM writes 8 to the alias (and to the overflow alias) of another node when it clears a processor-interface error before a remote access. Role inferred; name is ours. |

### Register `event_occurred_alias`

Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.

### Register `ipi_access`

Which processors may send interprocessor interrupts to this one: four registers, one per processor slice (SH2_IPI_ACCESS0 to 3). Defined by the header; the kernel files read never touch them, so the layout is unknown.

Array of 4 registers, stride 128.

### Register `int_cmp`

Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).

Array of 3 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `compare` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `pio_write_status`

PIO write status, four instances (SHub 2 nodes carry up to four processor slices). Note the kernel indexes them out of order: slices 0, 1, 2, 3 use instances 0, 2, 1, 3, in the setup code's table. The idle value is zero, not all ones.

Array of 4 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:56 | `pending_write_count` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Count of PIO writes still in flight. On SHub 1 the kernel treats all ones as idle (see PIO_WRITE_STATUS_IDLE); the header gives no reason. |
| 1 | `write_deadlock` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | A deadlock response was detected for a PIO write. |

### Register `pio_write_status_alias`

Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.

Array of 4 registers, stride 128.

### Register `bt_eng_csr`

Block transfer engine control and status, one per engine, SHub 2 (four engines, SH2_BT_ENG_CSR_0 to 3). Unlike SHub 1 the kernel starts a transfer with one store here: busy, the mode shifted left by 24, and the length in cache lines in the low bits. The kernel reads it for busy and error; the engine's error code sits in bits 41:36 (kernel's BTE_ERR_BITS).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41:36 | `error_code` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Six-bit error code; non-zero means error. Bits: 1 short response, 2 long response, 4 (RESP_DSP), 8 access, 0x10 CRB timeout, 0x20 NACK limit (kernel BTEFAIL_SH2_* names). Whether the hardware also sets the error flag at bit 16 when this field is non-zero is unknown: the kernel's SHub 2 status decode ORs the flag in itself when the code is non-zero. |
| 28 | `notify` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | The kernel's notify mode bit is bit 4, so it lands at bit 28. The kernel always sets it. |
| 24 | `zero_fill` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | The kernel shifts its mode word left by 24; its zero-fill mode bit is bit 0, so it lands here. |
| 20 | `busy` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Busy: same position as SHub 1's status register in the kernel's macros. |
| 16 | `error` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Error flag: the kernel tests the same IBLS_ERROR bit position on both chips. |
| 15:0 | `length` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Length in cache lines, as in the SHub 1 status register. The kernel keeps one length width for both chips (BTE_LEN_MASK, 16 bits). |

### Register `bt_eng_src`

BTE source address, per engine. The kernel converts the physical address to the network address form first (nasid moved to bit 40 upward, the bank-select bits moved to bit 36).

Array of 4 registers, stride 65536.

### Register `bt_eng_dest`

BTE destination address, per engine; same conversion as the source.

Array of 4 registers, stride 65536.

### Register `bt_eng_notify`

BTE notification address, per engine; same conversion.

Array of 4 registers, stride 65536.

### Register `junk_bus_led`

Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.

Array of 4 registers, stride 65536.

### Register `ptc`

Purge translation cache message, SHub 2 (header SH2_PTC). One 64-bit store per target node replaces SHub 1's two. The region id and region number do not go in the data: the kernel adds them, shifted left by four, to the register's address. (The header's `SH2_PTC_ADDR_SHFT` is 4 but sits under a region-id comment and no kernel code uses it, which uses `SH2_PTC_RID_SHFT`; the data's address field is `SH2_PTC_ADDR_MASK`, which starts at bit 12, and that is what this file uses.) The data carries the type bit, the page size and the start bit, and the virtual address in bits 60:12. How wide the address-encoded part is, and so how large the register window is, is unknown. The kernel only waits on the PIO write status afterwards; on a deadlock it reads the status alias instead of clearing it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `start` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 60:12 | `address` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Virtual address to purge (header SH2_PTC_ADDR_MASK 0x1ffffffffffff000). |
| 3:2 | `ps` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Page size as a power of two. The width is a guess from the next field starting at bit 4; the kernel passes a value that may need more bits, so the width is unknown. |
| 0 | `type_bit` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Header title: type; the kernel always writes 1. |

### Register `rtc`

Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only. The SHub 1 PROM (SAL 5.04) writes 0 to it at the SAL_B reset entry (0xffa94d20) and again to a node's counter in the interconnect phase, then reads it on every delay and timeout, so it must advance. Its tick period comes from rtc_ctl (SHub 1: 10 ns times the field plus one, 50 ns after the PROM's own write). See prom-reset.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `counter` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `EVENT_OCCURRED_EXTIO_INT2` | 0x200000000 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Bit 33 of the event register: pending SHub 2 external I/O interrupt 2 (header SH2_EVENT_OCCURRED_EXTIO_INT2). The base unit's field table has no entry for it because overlays cannot add fields. |
| `EVENT_OCCURRED_EXTIO_INT3` | 0x400000000 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Bit 34 of the event register: pending SHub 2 external I/O interrupt 3. |
| `IPI_BASE_VALUE` | 0xfee | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Constant the kernel puts in the base field of every IPI message: 0xfee in units of the field (2 MiB, from bit 21), which is 0x1_fdc0_0000 as an address (0xfee << 21; inferred arithmetic). It is not the 0xfee00000 of the kernel's generic interrupt base constant: that equivalence does not follow from the field position. Used with the vector in the idx field. |
| `PIO_WRITE_STATUS_ALIAS_CLEAR` | 0x7 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Value the kernel's TLB-purge deadlock recovery writes to the alias on SHub 1 to clear the deadlock, write error and multiple write error bits (assembly comment). |
| `PIO_WRITE_STATUS_IDLE` | 0x0 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | What the kernel waits for the masked pending-write count to equal on SHub 2: zero. |
| `PI_CAM_WAR_VALUE` | 0x8000000000000010 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Value the kernel writes to the PI CAM control register from every timer tick on a SHub 1 of revision 2 or lower. Meaning not stated by the sources. |
| `RTC_CONFIG_MASK` | 0xff3ffffffefffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of an RTC interrupt configuration register (header SH_RTC1_INT_CONFIG_MASK): bits 59:52 and 49:0 except bit 20. |
| `RTC_ENABLE_MASK` | 0x1 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of an RTC interrupt enable register. |
| `RTC_MASK` | 0x7fffffffffffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of the real-time clock and of each comparator: 55 bits. The mmtimer driver reports 55 as the clock width. |
| `SHUB_1_1_MAX_REVISION` | 0x2 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Revision field value at or below which the kernel enables its SHub 1.1 workarounds. |
