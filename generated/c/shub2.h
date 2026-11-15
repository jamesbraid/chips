/* generated from devices/shub/registers.shub2.toml by defs-gen - do not edit, change the source */
/* SHub 2 registers outside the I/O interface, differences from SHub 1 */
#ifndef SHUB2_GEN_H
#define SHUB2_GEN_H

#include <stdint.h>


/*
 * Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR window with send set, the target's physical processor id, a delivery type, a vector and a fixed base. The kernel stores through uncached physical mode with release ordering, after a memory barrier. On a SHub 1 revision 2 or lower it holds a global lock around the store and waits for the PIO write status to drain.
 */
/* ipi_int: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_IPI_INT                                0x10000380 /* established */
#define SHUB2_IPI_INT_SEND_SHIFT                     63 /* established */
#define SHUB2_IPI_INT_SEND_MASK                      0x1ull
#define SHUB2_IPI_INT_SEND_INPLACE                   (SHUB2_IPI_INT_SEND_MASK << SHUB2_IPI_INT_SEND_SHIFT)
#define SHUB2_IPI_INT_IDX_SHIFT                      52 /* established */
#define SHUB2_IPI_INT_IDX_MASK                       0xffull
#define SHUB2_IPI_INT_IDX_INPLACE                    (SHUB2_IPI_INT_IDX_MASK << SHUB2_IPI_INT_IDX_SHIFT)
#define SHUB2_IPI_INT_BASE_SHIFT                     21 /* established */
#define SHUB2_IPI_INT_BASE_MASK                      0x1fffffffull
#define SHUB2_IPI_INT_BASE_INPLACE                   (SHUB2_IPI_INT_BASE_MASK << SHUB2_IPI_INT_BASE_SHIFT)
#define SHUB2_IPI_INT_PID_SHIFT                      4 /* established */
#define SHUB2_IPI_INT_PID_MASK                       0xffffull
#define SHUB2_IPI_INT_PID_INPLACE                    (SHUB2_IPI_INT_PID_MASK << SHUB2_IPI_INT_PID_SHIFT)
#define SHUB2_IPI_INT_AGENT_SHIFT                    3 /* established */
#define SHUB2_IPI_INT_AGENT_MASK                     0x1ull
#define SHUB2_IPI_INT_AGENT_INPLACE                  (SHUB2_IPI_INT_AGENT_MASK << SHUB2_IPI_INT_AGENT_SHIFT)
#define SHUB2_IPI_INT_TYPE_SHIFT                     0 /* established */
#define SHUB2_IPI_INT_TYPE_MASK                      0x7ull
#define SHUB2_IPI_INT_TYPE_INPLACE                   (SHUB2_IPI_INT_TYPE_MASK << SHUB2_IPI_INT_TYPE_SHIFT)

/*
 * Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and processor id fields and leaves type, agent and base zero. The register has the same layout as the IPI message, without the send bit. A fourth comparator (RTC 0) exists; the driver comment says firmware uses it, and the header defines nothing for it.
 */
/* rtc_int_config: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_RTC_INT_CONFIG                         0x10001480 /* established */
#define SHUB2_RTC_INT_CONFIG_COUNT                   3
#define SHUB2_RTC_INT_CONFIG_STRIDE                  256
#define SHUB2_RTC_INT_CONFIG_IDX_SHIFT               52 /* established */
#define SHUB2_RTC_INT_CONFIG_IDX_MASK                0xffull
#define SHUB2_RTC_INT_CONFIG_IDX_INPLACE             (SHUB2_RTC_INT_CONFIG_IDX_MASK << SHUB2_RTC_INT_CONFIG_IDX_SHIFT)
#define SHUB2_RTC_INT_CONFIG_BASE_SHIFT              21 /* established */
#define SHUB2_RTC_INT_CONFIG_BASE_MASK               0x1fffffffull
#define SHUB2_RTC_INT_CONFIG_BASE_INPLACE            (SHUB2_RTC_INT_CONFIG_BASE_MASK << SHUB2_RTC_INT_CONFIG_BASE_SHIFT)
#define SHUB2_RTC_INT_CONFIG_PID_SHIFT               4 /* established */
#define SHUB2_RTC_INT_CONFIG_PID_MASK                0xffffull
#define SHUB2_RTC_INT_CONFIG_PID_INPLACE             (SHUB2_RTC_INT_CONFIG_PID_MASK << SHUB2_RTC_INT_CONFIG_PID_SHIFT)
#define SHUB2_RTC_INT_CONFIG_AGENT_SHIFT             3 /* established */
#define SHUB2_RTC_INT_CONFIG_AGENT_MASK              0x1ull
#define SHUB2_RTC_INT_CONFIG_AGENT_INPLACE           (SHUB2_RTC_INT_CONFIG_AGENT_MASK << SHUB2_RTC_INT_CONFIG_AGENT_SHIFT)
#define SHUB2_RTC_INT_CONFIG_TYPE_SHIFT              0 /* established */
#define SHUB2_RTC_INT_CONFIG_TYPE_MASK               0x7ull
#define SHUB2_RTC_INT_CONFIG_TYPE_INPLACE            (SHUB2_RTC_INT_CONFIG_TYPE_MASK << SHUB2_RTC_INT_CONFIG_TYPE_SHIFT)

/*
 * Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes the configuration, enables, and only then writes the real expiry, in that order.
 */
/* rtc_int_enable: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_RTC_INT_ENABLE                         0x10001500 /* established */
#define SHUB2_RTC_INT_ENABLE_COUNT                   3
#define SHUB2_RTC_INT_ENABLE_STRIDE                  256
#define SHUB2_RTC_INT_ENABLE_ENABLE_SHIFT            0 /* established */
#define SHUB2_RTC_INT_ENABLE_ENABLE_MASK             0x1ull
#define SHUB2_RTC_INT_ENABLE_ENABLE_INPLACE          (SHUB2_RTC_INT_ENABLE_ENABLE_MASK << SHUB2_RTC_INT_ENABLE_ENABLE_SHIFT)

/*
 * Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them; Linux only reads it. Bits the header names are established. SAL 5.04 reads it for the error bits (mask 0x7ef, sites 0xffa239a0 and 0xffa23fd6) and for bit 21 (site 0xffa31506), and writes bits 5 and 8 to this register itself (sites 0xffa32816 and 0xffa32996); a model should OR written bits in (inferred). Zero from reset is tolerated; the reset value is unknown. Bit 21 must read 0 for the PROM's INIT handling. See interrupts.md.
 */
/* event_occurred: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_EVENT_OCCURRED                         0x10010000 /* established */
#define SHUB2_EVENT_OCCURRED_II_INT1_SHIFT           30 /* established */
#define SHUB2_EVENT_OCCURRED_II_INT1_MASK            0x1ull
#define SHUB2_EVENT_OCCURRED_II_INT1_INPLACE         (SHUB2_EVENT_OCCURRED_II_INT1_MASK << SHUB2_EVENT_OCCURRED_II_INT1_SHIFT)
#define SHUB2_EVENT_OCCURRED_II_INT0_SHIFT           29 /* established */
#define SHUB2_EVENT_OCCURRED_II_INT0_MASK            0x1ull
#define SHUB2_EVENT_OCCURRED_II_INT0_INPLACE         (SHUB2_EVENT_OCCURRED_II_INT0_MASK << SHUB2_EVENT_OCCURRED_II_INT0_SHIFT)
#define SHUB2_EVENT_OCCURRED_IPI_INT_SHIFT           28 /* established */
#define SHUB2_EVENT_OCCURRED_IPI_INT_MASK            0x1ull
#define SHUB2_EVENT_OCCURRED_IPI_INT_INPLACE         (SHUB2_EVENT_OCCURRED_IPI_INT_MASK << SHUB2_EVENT_OCCURRED_IPI_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC3_INT_SHIFT          26 /* established */
#define SHUB2_EVENT_OCCURRED_RTC3_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC3_INT_INPLACE        (SHUB2_EVENT_OCCURRED_RTC3_INT_MASK << SHUB2_EVENT_OCCURRED_RTC3_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC2_INT_SHIFT          25 /* established */
#define SHUB2_EVENT_OCCURRED_RTC2_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC2_INT_INPLACE        (SHUB2_EVENT_OCCURRED_RTC2_INT_MASK << SHUB2_EVENT_OCCURRED_RTC2_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC1_INT_SHIFT          24 /* established */
#define SHUB2_EVENT_OCCURRED_RTC1_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC1_INT_INPLACE        (SHUB2_EVENT_OCCURRED_RTC1_INT_MASK << SHUB2_EVENT_OCCURRED_RTC1_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC0_INT_SHIFT          23 /* inferred */
#define SHUB2_EVENT_OCCURRED_RTC0_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC0_INT_INPLACE        (SHUB2_EVENT_OCCURRED_RTC0_INT_MASK << SHUB2_EVENT_OCCURRED_RTC0_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT21_SHIFT             21 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT21_MASK              0x1ull
#define SHUB2_EVENT_OCCURRED_BIT21_INPLACE           (SHUB2_EVENT_OCCURRED_BIT21_MASK << SHUB2_EVENT_OCCURRED_BIT21_SHIFT)
#define SHUB2_EVENT_OCCURRED_UART_INT_SHIFT          20 /* established */
#define SHUB2_EVENT_OCCURRED_UART_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_UART_INT_INPLACE        (SHUB2_EVENT_OCCURRED_UART_INT_MASK << SHUB2_EVENT_OCCURRED_UART_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT8_SHIFT              8 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT8_MASK               0x1ull
#define SHUB2_EVENT_OCCURRED_BIT8_INPLACE            (SHUB2_EVENT_OCCURRED_BIT8_MASK << SHUB2_EVENT_OCCURRED_BIT8_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT5_SHIFT              5 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT5_MASK               0x1ull
#define SHUB2_EVENT_OCCURRED_BIT5_INPLACE            (SHUB2_EVENT_OCCURRED_BIT5_MASK << SHUB2_EVENT_OCCURRED_BIT5_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT3_SHIFT              3 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT3_MASK               0x1ull
#define SHUB2_EVENT_OCCURRED_BIT3_INPLACE            (SHUB2_EVENT_OCCURRED_BIT3_MASK << SHUB2_EVENT_OCCURRED_BIT3_SHIFT)

/*
 * Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.
 */
/* event_occurred_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_EVENT_OCCURRED_ALIAS                   0x10010008 /* established */

/*
 * Which processors may send interprocessor interrupts to this one: four registers, one per processor slice (SH2_IPI_ACCESS0 to 3). Defined by the header; the kernel files read never touch them, so the layout is unknown.
 */
/* ipi_access: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_IPI_ACCESS                             0x10060c00 /* established */
#define SHUB2_IPI_ACCESS_COUNT                       4
#define SHUB2_IPI_ACCESS_STRIDE                      128

/*
 * Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).
 */
/* int_cmp: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_INT_CMP                                0x101b0080 /* established */
#define SHUB2_INT_CMP_COUNT                          3
#define SHUB2_INT_CMP_STRIDE                         128
#define SHUB2_INT_CMP_COMPARE_SHIFT                  0 /* established */
#define SHUB2_INT_CMP_COMPARE_MASK                   0x7fffffffffffffull
#define SHUB2_INT_CMP_COMPARE_INPLACE                (SHUB2_INT_CMP_COMPARE_MASK << SHUB2_INT_CMP_COMPARE_SHIFT)

/*
 * PIO write status, four instances (SHub 2 nodes carry up to four processor slices). Note the kernel indexes them out of order: slices 0, 1, 2, 3 use instances 0, 2, 1, 3, in the setup code's table. The idle value is zero, not all ones.
 */
/* pio_write_status: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_PIO_WRITE_STATUS                       0x20070200 /* established */
#define SHUB2_PIO_WRITE_STATUS_COUNT                 4
#define SHUB2_PIO_WRITE_STATUS_STRIDE                128
#define SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT 56 /* established */
#define SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK 0x3full
#define SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_INPLACE (SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK << SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT)
#define SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT  1 /* established */
#define SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK   0x1ull
#define SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_INPLACE (SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK << SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT)

/*
 * Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.
 */
/* pio_write_status_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_PIO_WRITE_STATUS_ALIAS                 0x20070208 /* inferred */
#define SHUB2_PIO_WRITE_STATUS_ALIAS_COUNT           4
#define SHUB2_PIO_WRITE_STATUS_ALIAS_STRIDE          128

/*
 * Block transfer engine control and status, one per engine, SHub 2 (four engines, SH2_BT_ENG_CSR_0 to 3). Unlike SHub 1 the kernel starts a transfer with one store here: busy, the mode shifted left by 24, and the length in cache lines in the low bits. The kernel reads it for busy and error; the engine's error code sits in bits 41:36 (kernel's BTE_ERR_BITS).
 */
/* bt_eng_csr: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_BT_ENG_CSR                             0x30040000 /* established */
#define SHUB2_BT_ENG_CSR_COUNT                       4
#define SHUB2_BT_ENG_CSR_STRIDE                      65536
#define SHUB2_BT_ENG_CSR_ERROR_CODE_SHIFT            36 /* inferred */
#define SHUB2_BT_ENG_CSR_ERROR_CODE_MASK             0x3full
#define SHUB2_BT_ENG_CSR_ERROR_CODE_INPLACE          (SHUB2_BT_ENG_CSR_ERROR_CODE_MASK << SHUB2_BT_ENG_CSR_ERROR_CODE_SHIFT)
#define SHUB2_BT_ENG_CSR_NOTIFY_SHIFT                28 /* inferred */
#define SHUB2_BT_ENG_CSR_NOTIFY_MASK                 0x1ull
#define SHUB2_BT_ENG_CSR_NOTIFY_INPLACE              (SHUB2_BT_ENG_CSR_NOTIFY_MASK << SHUB2_BT_ENG_CSR_NOTIFY_SHIFT)
#define SHUB2_BT_ENG_CSR_ZERO_FILL_SHIFT             24 /* inferred */
#define SHUB2_BT_ENG_CSR_ZERO_FILL_MASK              0x1ull
#define SHUB2_BT_ENG_CSR_ZERO_FILL_INPLACE           (SHUB2_BT_ENG_CSR_ZERO_FILL_MASK << SHUB2_BT_ENG_CSR_ZERO_FILL_SHIFT)
#define SHUB2_BT_ENG_CSR_BUSY_SHIFT                  20 /* inferred */
#define SHUB2_BT_ENG_CSR_BUSY_MASK                   0x1ull
#define SHUB2_BT_ENG_CSR_BUSY_INPLACE                (SHUB2_BT_ENG_CSR_BUSY_MASK << SHUB2_BT_ENG_CSR_BUSY_SHIFT)
#define SHUB2_BT_ENG_CSR_ERROR_SHIFT                 16 /* inferred */
#define SHUB2_BT_ENG_CSR_ERROR_MASK                  0x1ull
#define SHUB2_BT_ENG_CSR_ERROR_INPLACE               (SHUB2_BT_ENG_CSR_ERROR_MASK << SHUB2_BT_ENG_CSR_ERROR_SHIFT)
#define SHUB2_BT_ENG_CSR_LENGTH_SHIFT                0 /* inferred */
#define SHUB2_BT_ENG_CSR_LENGTH_MASK                 0xffffull
#define SHUB2_BT_ENG_CSR_LENGTH_INPLACE              (SHUB2_BT_ENG_CSR_LENGTH_MASK << SHUB2_BT_ENG_CSR_LENGTH_SHIFT)

/*
 * BTE source address, per engine. The kernel converts the physical address to the network address form first (nasid moved to bit 40 upward, the bank-select bits moved to bit 36).
 */
/* bt_eng_src: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_BT_ENG_SRC                             0x30040080 /* established */
#define SHUB2_BT_ENG_SRC_COUNT                       4
#define SHUB2_BT_ENG_SRC_STRIDE                      65536

/*
 * BTE destination address, per engine; same conversion as the source.
 */
/* bt_eng_dest: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_BT_ENG_DEST                            0x30040100 /* established */
#define SHUB2_BT_ENG_DEST_COUNT                      4
#define SHUB2_BT_ENG_DEST_STRIDE                     65536

/*
 * BTE notification address, per engine; same conversion.
 */
/* bt_eng_notify: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_BT_ENG_NOTIFY                          0x30040180 /* established */
#define SHUB2_BT_ENG_NOTIFY_COUNT                    4
#define SHUB2_BT_ENG_NOTIFY_STRIDE                   65536

/*
 * Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.
 */
/* junk_bus_led: w16, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_JUNK_BUS_LED                           0xf0000000 /* established */
#define SHUB2_JUNK_BUS_LED_COUNT                     4
#define SHUB2_JUNK_BUS_LED_STRIDE                    65536

/*
 * Purge translation cache message, SHub 2 (header SH2_PTC). One 64-bit store per target node replaces SHub 1's two. The region id and region number do not go in the data: the kernel adds them, shifted left by four, to the register's address. (The header's `SH2_PTC_ADDR_SHFT` is 4 but sits under a region-id comment and no kernel code uses it, which uses `SH2_PTC_RID_SHFT`; the data's address field is `SH2_PTC_ADDR_MASK`, which starts at bit 12, and that is what this file uses.) The data carries the type bit, the page size and the start bit, and the virtual address in bits 60:12. How wide the address-encoded part is, and so how large the register window is, is unknown. The kernel only waits on the PIO write status afterwards; on a deadlock it reads the status alias instead of clearing it.
 */
/* ptc: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_PTC                                    0x170000000 /* established */
#define SHUB2_PTC_START_SHIFT                        63 /* established */
#define SHUB2_PTC_START_MASK                         0x1ull
#define SHUB2_PTC_START_INPLACE                      (SHUB2_PTC_START_MASK << SHUB2_PTC_START_SHIFT)
#define SHUB2_PTC_ADDRESS_SHIFT                      12 /* established */
#define SHUB2_PTC_ADDRESS_MASK                       0x1ffffffffffffull
#define SHUB2_PTC_ADDRESS_INPLACE                    (SHUB2_PTC_ADDRESS_MASK << SHUB2_PTC_ADDRESS_SHIFT)
#define SHUB2_PTC_PS_SHIFT                           2 /* inferred */
#define SHUB2_PTC_PS_MASK                            0x3ull
#define SHUB2_PTC_PS_INPLACE                         (SHUB2_PTC_PS_MASK << SHUB2_PTC_PS_SHIFT)
#define SHUB2_PTC_TYPE_BIT_SHIFT                     0 /* inferred */
#define SHUB2_PTC_TYPE_BIT_MASK                      0x1ull
#define SHUB2_PTC_TYPE_BIT_INPLACE                   (SHUB2_PTC_TYPE_BIT_MASK << SHUB2_PTC_TYPE_BIT_SHIFT)

/*
 * Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only. The SHub 1 PROM (SAL 5.04) writes 0 to it at the SAL_B reset entry (0xffa94d20) and again to a node's counter in the interconnect phase, then reads it on every delay and timeout, so it must advance. Its tick period comes from rtc_ctl (SHub 1: 10 ns times the field plus one, 50 ns after the PROM's own write). See prom-reset.md.
 */
/* rtc: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB2_RTC                                    0x2101c0000 /* established */
#define SHUB2_RTC_COUNTER_SHIFT                      0 /* established */
#define SHUB2_RTC_COUNTER_MASK                       0x7fffffffffffffull
#define SHUB2_RTC_COUNTER_INPLACE                    (SHUB2_RTC_COUNTER_MASK << SHUB2_RTC_COUNTER_SHIFT)

#define SHUB2_EVENT_OCCURRED_EXTIO_INT2              0x200000000ull /* established */
#define SHUB2_EVENT_OCCURRED_EXTIO_INT3              0x400000000ull /* established */
#define SHUB2_IPI_BASE_VALUE                         0xfeeu /* established */
#define SHUB2_PIO_WRITE_STATUS_ALIAS_CLEAR           0x7u /* established */
#define SHUB2_PIO_WRITE_STATUS_IDLE                  0x0u /* established */
#define SHUB2_PI_CAM_WAR_VALUE                       0x8000000000000010ull /* established */
#define SHUB2_RTC_CONFIG_MASK                        0xff3ffffffefffffull /* established */
#define SHUB2_RTC_ENABLE_MASK                        0x1u /* established */
#define SHUB2_RTC_MASK                               0x7fffffffffffffull /* established */
#define SHUB2_SHUB_1_1_MAX_REVISION                  0x2u /* established */

#endif /* SHUB2_GEN_H */
