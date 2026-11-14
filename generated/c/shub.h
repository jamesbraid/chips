/* generated from devices/shub/registers.toml by defs-gen - do not edit, change the source */
/* SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs */
#ifndef SHUB_GEN_H
#define SHUB_GEN_H

#include <stdint.h>


/*
 * Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege vector for acc=0'). Defined by the header; no use in any kernel file read. Layout and role unknown.
 */
/* md_dqlp_dir_privilege_vector: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_DQLP_DIR_PRIVILEGE_VECTOR            0x100030300 /* established */

/*
 * Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names.
 */
/* md_dqrp_dir_privilege_vector: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_DQRP_DIR_PRIVILEGE_VECTOR            0x100050300 /* established */

/*
 * Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR window with send set, the target's physical processor id, a delivery type, a vector and a fixed base. The kernel stores through uncached physical mode with release ordering, after a memory barrier. On a SHub 1 revision 2 or lower it holds a global lock around the store and waits for the PIO write status to drain.
 */
/* ipi_int: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IPI_INT                                 0x110000380 /* established */
#define SHUB_IPI_INT_SEND_SHIFT                      63 /* established */
#define SHUB_IPI_INT_SEND_MASK                       0x1ull
#define SHUB_IPI_INT_SEND_INPLACE                    (SHUB_IPI_INT_SEND_MASK << SHUB_IPI_INT_SEND_SHIFT)
#define SHUB_IPI_INT_IDX_SHIFT                       52 /* established */
#define SHUB_IPI_INT_IDX_MASK                        0xffull
#define SHUB_IPI_INT_IDX_INPLACE                     (SHUB_IPI_INT_IDX_MASK << SHUB_IPI_INT_IDX_SHIFT)
#define SHUB_IPI_INT_BASE_SHIFT                      21 /* established */
#define SHUB_IPI_INT_BASE_MASK                       0x1fffffffull
#define SHUB_IPI_INT_BASE_INPLACE                    (SHUB_IPI_INT_BASE_MASK << SHUB_IPI_INT_BASE_SHIFT)
#define SHUB_IPI_INT_PID_SHIFT                       4 /* established */
#define SHUB_IPI_INT_PID_MASK                        0xffffull
#define SHUB_IPI_INT_PID_INPLACE                     (SHUB_IPI_INT_PID_MASK << SHUB_IPI_INT_PID_SHIFT)
#define SHUB_IPI_INT_AGENT_SHIFT                     3 /* established */
#define SHUB_IPI_INT_AGENT_MASK                      0x1ull
#define SHUB_IPI_INT_AGENT_INPLACE                   (SHUB_IPI_INT_AGENT_MASK << SHUB_IPI_INT_AGENT_SHIFT)
#define SHUB_IPI_INT_TYPE_SHIFT                      0 /* established */
#define SHUB_IPI_INT_TYPE_MASK                       0x7ull
#define SHUB_IPI_INT_TYPE_INPLACE                    (SHUB_IPI_INT_TYPE_MASK << SHUB_IPI_INT_TYPE_SHIFT)

/*
 * Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and processor id fields and leaves type, agent and base zero. The register has the same layout as the IPI message, without the send bit. A fourth comparator (RTC 0) exists; the driver comment says firmware uses it, and the header defines nothing for it.
 */
/* rtc_int_config: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC_INT_CONFIG                          0x110001480 /* established */
#define SHUB_RTC_INT_CONFIG_COUNT                    3
#define SHUB_RTC_INT_CONFIG_STRIDE                   256
#define SHUB_RTC_INT_CONFIG_IDX_SHIFT                52 /* established */
#define SHUB_RTC_INT_CONFIG_IDX_MASK                 0xffull
#define SHUB_RTC_INT_CONFIG_IDX_INPLACE              (SHUB_RTC_INT_CONFIG_IDX_MASK << SHUB_RTC_INT_CONFIG_IDX_SHIFT)
#define SHUB_RTC_INT_CONFIG_BASE_SHIFT               21 /* established */
#define SHUB_RTC_INT_CONFIG_BASE_MASK                0x1fffffffull
#define SHUB_RTC_INT_CONFIG_BASE_INPLACE             (SHUB_RTC_INT_CONFIG_BASE_MASK << SHUB_RTC_INT_CONFIG_BASE_SHIFT)
#define SHUB_RTC_INT_CONFIG_PID_SHIFT                4 /* established */
#define SHUB_RTC_INT_CONFIG_PID_MASK                 0xffffull
#define SHUB_RTC_INT_CONFIG_PID_INPLACE              (SHUB_RTC_INT_CONFIG_PID_MASK << SHUB_RTC_INT_CONFIG_PID_SHIFT)
#define SHUB_RTC_INT_CONFIG_AGENT_SHIFT              3 /* established */
#define SHUB_RTC_INT_CONFIG_AGENT_MASK               0x1ull
#define SHUB_RTC_INT_CONFIG_AGENT_INPLACE            (SHUB_RTC_INT_CONFIG_AGENT_MASK << SHUB_RTC_INT_CONFIG_AGENT_SHIFT)
#define SHUB_RTC_INT_CONFIG_TYPE_SHIFT               0 /* established */
#define SHUB_RTC_INT_CONFIG_TYPE_MASK                0x7ull
#define SHUB_RTC_INT_CONFIG_TYPE_INPLACE             (SHUB_RTC_INT_CONFIG_TYPE_MASK << SHUB_RTC_INT_CONFIG_TYPE_SHIFT)

/*
 * Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes the configuration, enables, and only then writes the real expiry, in that order.
 */
/* rtc_int_enable: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC_INT_ENABLE                          0x110001500 /* established */
#define SHUB_RTC_INT_ENABLE_COUNT                    3
#define SHUB_RTC_INT_ENABLE_STRIDE                   256
#define SHUB_RTC_INT_ENABLE_ENABLE_SHIFT             0 /* established */
#define SHUB_RTC_INT_ENABLE_ENABLE_MASK              0x1ull
#define SHUB_RTC_INT_ENABLE_ENABLE_INPLACE           (SHUB_RTC_INT_ENABLE_ENABLE_MASK << SHUB_RTC_INT_ENABLE_ENABLE_SHIFT)

/*
 * Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them. Only bits the header names are recorded; the others are unknown.
 */
/* event_occurred: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_EVENT_OCCURRED                          0x110010000 /* established */
#define SHUB_EVENT_OCCURRED_II_INT1_SHIFT            30 /* established */
#define SHUB_EVENT_OCCURRED_II_INT1_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_II_INT1_INPLACE          (SHUB_EVENT_OCCURRED_II_INT1_MASK << SHUB_EVENT_OCCURRED_II_INT1_SHIFT)
#define SHUB_EVENT_OCCURRED_II_INT0_SHIFT            29 /* established */
#define SHUB_EVENT_OCCURRED_II_INT0_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_II_INT0_INPLACE          (SHUB_EVENT_OCCURRED_II_INT0_MASK << SHUB_EVENT_OCCURRED_II_INT0_SHIFT)
#define SHUB_EVENT_OCCURRED_IPI_INT_SHIFT            28 /* established */
#define SHUB_EVENT_OCCURRED_IPI_INT_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_IPI_INT_INPLACE          (SHUB_EVENT_OCCURRED_IPI_INT_MASK << SHUB_EVENT_OCCURRED_IPI_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC3_INT_SHIFT           26 /* established */
#define SHUB_EVENT_OCCURRED_RTC3_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC3_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC3_INT_MASK << SHUB_EVENT_OCCURRED_RTC3_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC2_INT_SHIFT           25 /* established */
#define SHUB_EVENT_OCCURRED_RTC2_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC2_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC2_INT_MASK << SHUB_EVENT_OCCURRED_RTC2_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC1_INT_SHIFT           24 /* established */
#define SHUB_EVENT_OCCURRED_RTC1_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC1_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC1_INT_MASK << SHUB_EVENT_OCCURRED_RTC1_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_UART_INT_SHIFT           20 /* established */
#define SHUB_EVENT_OCCURRED_UART_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_UART_INT_INPLACE         (SHUB_EVENT_OCCURRED_UART_INT_MASK << SHUB_EVENT_OCCURRED_UART_INT_SHIFT)

/*
 * Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.
 */
/* event_occurred_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_EVENT_OCCURRED_ALIAS                    0x110010008 /* established */

/*
 * Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross-partition driver reading it as the target of a protected remote read; the driver comment says there is no special reason for that choice. So the register can be read without harm; its bit layout and write behaviour are unknown.
 */
/* ipi_access: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IPI_ACCESS                              0x110060480 /* established */

/*
 * SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in the fallback for an old PROM the nodes-per-bit field, which it reports as the region size. SHub 2's counterpart is not named in the header.
 */
/* shub_id: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_SHUB_ID                                 0x110060580 /* established */
#define SHUB_SHUB_ID_NODES_PER_BIT_SHIFT             48 /* established */
#define SHUB_SHUB_ID_NODES_PER_BIT_MASK              0x1full
#define SHUB_SHUB_ID_NODES_PER_BIT_INPLACE           (SHUB_SHUB_ID_NODES_PER_BIT_MASK << SHUB_SHUB_ID_NODES_PER_BIT_SHIFT)
#define SHUB_SHUB_ID_REVISION_SHIFT                  28 /* established */
#define SHUB_SHUB_ID_REVISION_MASK                   0xfull
#define SHUB_SHUB_ID_REVISION_INPLACE                (SHUB_SHUB_ID_REVISION_MASK << SHUB_SHUB_ID_REVISION_SHIFT)

/*
 * Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel writes the two registers of that node's global window back to back with interrupts and interruption collection off, the first with a type bit, the page-size exponent, the region id and a start bit, the second with the virtual address and a start bit; both stores are in one atomic assembly sequence. It does this once per page of the range, after taking a global lock, for every node that has the mm's processors, except the local node which uses the processor's own global purge instruction instead. Entry 0 is the control word and entry 1 the address word. After a batch of nodes it waits on the PIO write status.
 */
/* ptc: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PTC                                     0x1101a0000 /* established */
#define SHUB_PTC_COUNT                               2
#define SHUB_PTC_STRIDE                              128
#define SHUB_PTC_START_SHIFT                         63 /* established */
#define SHUB_PTC_START_MASK                          0x1ull
#define SHUB_PTC_START_INPLACE                       (SHUB_PTC_START_MASK << SHUB_PTC_START_SHIFT)
#define SHUB_PTC_RID_SHIFT                           8 /* inferred */
#define SHUB_PTC_RID_MASK                            0x7fffffffffffffull
#define SHUB_PTC_RID_INPLACE                         (SHUB_PTC_RID_MASK << SHUB_PTC_RID_SHIFT)
#define SHUB_PTC_PS_SHIFT                            2 /* inferred */
#define SHUB_PTC_PS_MASK                             0x3full
#define SHUB_PTC_PS_INPLACE                          (SHUB_PTC_PS_MASK << SHUB_PTC_PS_SHIFT)
#define SHUB_PTC_TYPE_BIT_SHIFT                      0 /* inferred */
#define SHUB_PTC_TYPE_BIT_MASK                       0x1ull
#define SHUB_PTC_TYPE_BIT_INPLACE                    (SHUB_PTC_TYPE_BIT_MASK << SHUB_PTC_TYPE_BIT_SHIFT)

/*
 * Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).
 */
/* int_cmp: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_INT_CMP                                 0x1101b0080 /* established */
#define SHUB_INT_CMP_COUNT                           3
#define SHUB_INT_CMP_STRIDE                          128
#define SHUB_INT_CMP_COMPARE_SHIFT                   0 /* established */
#define SHUB_INT_CMP_COMPARE_MASK                    0x7fffffffffffffull
#define SHUB_INT_CMP_COMPARE_INPLACE                 (SHUB_INT_CMP_COMPARE_MASK << SHUB_INT_CMP_COMPARE_SHIFT)

/*
 * Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only.
 */
/* rtc: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC                                     0x1101c0000 /* established */
#define SHUB_RTC_COUNTER_SHIFT                       0 /* established */
#define SHUB_RTC_COUNTER_MASK                        0x7fffffffffffffull
#define SHUB_RTC_COUNTER_INPLACE                     (SHUB_RTC_COUNTER_MASK << SHUB_RTC_COUNTER_SHIFT)

/*
 * Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the kernel writes 0x8000000000000010 here on every timer tick, through the address of its own node. What the value does is unknown.
 */
/* pi_cam_control: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PI_CAM_CONTROL                          0x120050300 /* established */

/*
 * PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O write barrier spins until the pending write count shows idle. The kernel stores the address of the instance for its slice (the slice is the processor's position within the node) in its per-processor data.
 */
/* pio_write_status: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PIO_WRITE_STATUS                        0x120070200 /* established */
#define SHUB_PIO_WRITE_STATUS_COUNT                  2
#define SHUB_PIO_WRITE_STATUS_STRIDE                 128
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT 56 /* established */
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK 0x3full
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_INPLACE (SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK << SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT)
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT   1 /* established */
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK    0x1ull
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_INPLACE (SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK << SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT)

/*
 * Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.
 */
/* pio_write_status_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PIO_WRITE_STATUS_ALIAS                  0x120070208 /* inferred */
#define SHUB_PIO_WRITE_STATUS_ALIAS_COUNT            2
#define SHUB_PIO_WRITE_STATUS_ALIAS_STRIDE           128

/*
 * Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.
 */
/* junk_bus_led: w16, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_JUNK_BUS_LED                            0x7fed00000 /* established */
#define SHUB_JUNK_BUS_LED_COUNT                      4
#define SHUB_JUNK_BUS_LED_STRIDE                     65536

#define SHUB_IPI_BASE_VALUE                          0xfeeu /* established */
#define SHUB_PIO_WRITE_STATUS_ALIAS_CLEAR            0x7u /* established */
#define SHUB_PIO_WRITE_STATUS_IDLE                   0x3f00000000000000ull /* established */
#define SHUB_PI_CAM_WAR_VALUE                        0x8000000000000010ull /* established */
#define SHUB_RTC_CONFIG_MASK                         0xff3ffffffefffffull /* established */
#define SHUB_RTC_ENABLE_MASK                         0x1u /* established */
#define SHUB_RTC_MASK                                0x7fffffffffffffull /* established */
#define SHUB_SHUB_1_1_MAX_REVISION                   0x2u /* established */

#endif /* SHUB_GEN_H */
