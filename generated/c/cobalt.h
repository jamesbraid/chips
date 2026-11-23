/* generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 19f8621d27161f38e6f456d3242a1560c0986e491015583f41f0bff9b6e515ee */
/* Cobalt (system ASIC of the SGI Visual Workstation 320 and 540): the CPU block with its timer, and the interrupt controller */
#ifndef COBALT_GEN_H
#define COBALT_GEN_H

#include <stdint.h>


/*
 * Interrupt redirection entry, low word, one per interrupt line (thirty lines, 0 to 29). The kernel writes the level bit and an interrupt vector to unmask a line and only the mask bit to mask it, reading the register back after masking. The vector it writes is the kernel's irq number plus 0x20, so it is not the line number.
 */
/* apic_lo: rw32, space apic, reset unknown */
#define COBALT_APIC_LO_OFFSET                        0x0u /* established */
#define COBALT_APIC_LO_COUNT                         30
#define COBALT_APIC_LO_STRIDE                        16
#define COBALT_APIC_LO_BIT17_SHIFT                   17 /* unknown */
#define COBALT_APIC_LO_BIT17_MASK                    0x1u
#define COBALT_APIC_LO_BIT17_INPLACE                 (COBALT_APIC_LO_BIT17_MASK << COBALT_APIC_LO_BIT17_SHIFT)
#define COBALT_APIC_LO_MASK_SHIFT                    16 /* established */
#define COBALT_APIC_LO_MASK_MASK                     0x1u
#define COBALT_APIC_LO_MASK_INPLACE                  (COBALT_APIC_LO_MASK_MASK << COBALT_APIC_LO_MASK_SHIFT)
#define COBALT_APIC_LO_LEVEL_SHIFT                   15 /* established */
#define COBALT_APIC_LO_LEVEL_MASK                    0x1u
#define COBALT_APIC_LO_LEVEL_INPLACE                 (COBALT_APIC_LO_LEVEL_MASK << COBALT_APIC_LO_LEVEL_SHIFT)
#define COBALT_APIC_LO_REMOTE_IRR_SHIFT              14 /* established */
#define COBALT_APIC_LO_REMOTE_IRR_MASK               0x1u
#define COBALT_APIC_LO_REMOTE_IRR_INPLACE            (COBALT_APIC_LO_REMOTE_IRR_MASK << COBALT_APIC_LO_REMOTE_IRR_SHIFT)
#define COBALT_APIC_LO_DEST_MODE_SHIFT               11 /* established */
#define COBALT_APIC_LO_DEST_MODE_MASK                0x1u
#define COBALT_APIC_LO_DEST_MODE_INPLACE             (COBALT_APIC_LO_DEST_MODE_MASK << COBALT_APIC_LO_DEST_MODE_SHIFT)
#define COBALT_APIC_LO_DELIVERY_MODE_SHIFT           8 /* established */
#define COBALT_APIC_LO_DELIVERY_MODE_MASK            0x7u
#define COBALT_APIC_LO_DELIVERY_MODE_INPLACE         (COBALT_APIC_LO_DELIVERY_MODE_MASK << COBALT_APIC_LO_DELIVERY_MODE_SHIFT)
#define COBALT_APIC_LO_VECTOR_SHIFT                  0 /* established */
#define COBALT_APIC_LO_VECTOR_MASK                   0xffu
#define COBALT_APIC_LO_VECTOR_INPLACE                (COBALT_APIC_LO_VECTOR_MASK << COBALT_APIC_LO_VECTOR_SHIFT)

/*
 * Interrupt redirection entry, high word. Linux and the NT HAL write zero beside every device entry's low word; the HAL writes the NMI entry's high word with one bit set per processor id (1 shifted by the processor number) in bits 31:24 for logical delivery. What the HAL writes is established; reading the field as the destination, in the I/O APIC layout, and zero as 'processor id 0, physical' for device entries are inferred from the layout. The HAL never steers a device entry to another processor.
 */
/* apic_hi: rw32, space apic, reset unknown */
#define COBALT_APIC_HI_OFFSET                        0x4u /* established */
#define COBALT_APIC_HI_COUNT                         30
#define COBALT_APIC_HI_STRIDE                        16
#define COBALT_APIC_HI_DEST_SHIFT                    24 /* inferred */
#define COBALT_APIC_HI_DEST_MASK                     0xffu
#define COBALT_APIC_HI_DEST_INPLACE                  (COBALT_APIC_HI_DEST_MASK << COBALT_APIC_HI_DEST_SHIFT)

/*
 * Controller identification and enable. The kernel reads it, sets the enable bit with a read-modify-write that it says must not change the identification, and prints the result. Where the identification field sits is not known. The NT HAL and the PROM main module run the same sequence: read the word, test bits 27:24, and only when they are zero clear bit 8 and the field and store 4 in the field; then in every case set bit 8 and store again. Both test the field before writing it, so each depends on the value only through whether the field is zero. The HAL masks all thirty entries first and the PROM writes all thirty first (low word the vector with the level and mask bits set, then the mask bit cleared for every line that has a registered handler; entry 29 gets all ones; high word 0), so entries accept writes while the controller is disabled. The PROM also has three places that set the field to 4 without testing it: the self-test, the early start-up in the main module, and the same early code in every held release (1.0002 to 1.1005). The main module ends by masking all entries and clearing bit 8. No reset value is known. Addresses: the Cobalt README.
 */
/* apic_id: rw32, space apic, reset unknown */
#define COBALT_APIC_ID_OFFSET                        0xffcu /* established */
#define COBALT_APIC_ID_ID_SHIFT                      24 /* established */
#define COBALT_APIC_ID_ID_MASK                       0xfu
#define COBALT_APIC_ID_ID_INPLACE                    (COBALT_APIC_ID_ID_MASK << COBALT_APIC_ID_ID_SHIFT)
#define COBALT_APIC_ID_ENABLE_SHIFT                  8 /* established */
#define COBALT_APIC_ID_ENABLE_MASK                   0x1u
#define COBALT_APIC_ID_ENABLE_INPLACE                (COBALT_APIC_ID_ENABLE_MASK << COBALT_APIC_ID_ENABLE_SHIFT)

/*
 * Cobalt revision. The kernel prints it at start-up and, in the 2.4 interrupt path, reads it after a driver has acknowledged its device as a way to make sure the driver's write has reached the device before the end-of-interrupt. Readers: the NT HAL compares the whole 32-bit word with 0xa0 and 0xa8; the PROM main module reads it as a byte (and as a dword masked to the low byte) before the same comparisons; the PROM self-test compares the whole dword with them to choose the bank-register base, and records the difference between the word with its low nibble cleared and 0xa0 in extended CMOS without branching on it. Those equality tests bound nothing for a board that is neither 0xa0 nor 0xa8, and the record is never acted on in the code read, so what other revisions read is inferred only from the Cobalt:a4 revision text a real machine reports. Byte and dword reads both occur. The register is only ever read, so no reset value is known. Addresses: the Cobalt README.
 */
/* cpu_rev: r32, space cpu, reset unknown */
#define COBALT_CPU_REV_OFFSET                        0x8u /* established */

/*
 * Timer and memory control. Linux sets timer_run and clears timer_mask, each by a read-modify-write, after loading the count, and touches no other bit. The NT HAL (halborg.dll 1.3: the Cobalt control set-up in HalInitSystem and HalpEccControl) also clears ecc_enable at start-up, sets timer_mask at start-up (it clears the mask later, when it starts the tick: see cpu_timeval), ORs in page_close from its PAGEOPENPOLICY boot option, and sets ecc_enable together with bit 0 of the memory block when it enables ECC.
 */
/* cpu_ctrl: rw32, space cpu, reset unknown */
#define COBALT_CPU_CTRL_OFFSET                       0x10u /* established */
#define COBALT_CPU_CTRL_TIMER_MASK_SHIFT             3 /* established */
#define COBALT_CPU_CTRL_TIMER_MASK_MASK              0x1u
#define COBALT_CPU_CTRL_TIMER_MASK_INPLACE           (COBALT_CPU_CTRL_TIMER_MASK_MASK << COBALT_CPU_CTRL_TIMER_MASK_SHIFT)
#define COBALT_CPU_CTRL_TIMER_RUN_SHIFT              2 /* established */
#define COBALT_CPU_CTRL_TIMER_RUN_MASK               0x1u
#define COBALT_CPU_CTRL_TIMER_RUN_INPLACE            (COBALT_CPU_CTRL_TIMER_RUN_MASK << COBALT_CPU_CTRL_TIMER_RUN_SHIFT)
#define COBALT_CPU_CTRL_PAGE_CLOSE_SHIFT             1 /* established */
#define COBALT_CPU_CTRL_PAGE_CLOSE_MASK              0x1u
#define COBALT_CPU_CTRL_PAGE_CLOSE_INPLACE           (COBALT_CPU_CTRL_PAGE_CLOSE_MASK << COBALT_CPU_CTRL_PAGE_CLOSE_SHIFT)
#define COBALT_CPU_CTRL_ECC_ENABLE_SHIFT             0 /* established */
#define COBALT_CPU_CTRL_ECC_ENABLE_MASK              0x1u
#define COBALT_CPU_CTRL_ECC_ENABLE_INPLACE           (COBALT_CPU_CTRL_ECC_ENABLE_MASK << COBALT_CPU_CTRL_ECC_ENABLE_SHIFT)

/*
 * Machine reset on early boards (the PROM main module's reboot routine does the same: it sets bit 0 here, or writes 6 to port 0xcf9 on the newer board classes). The NT HAL sets bit 0 to reboot the 320 below board revision 12 and the 540 revision 0 (halborg.dll 1.3, HalpReboot, BoardResetAtPIIX4); other boards reboot through port 0xcf9. A separate register from the memory block's error status at offset 0x18. The PROM self-test also writes it: a read-modify-write that ORs in bit 0 only when neither of two CMOS marker bytes is 0xa5 (a cold boot: it writes 0xa5 to both, and every boot then zeroes both) (the value read is only ORed, never tested), a store of 3 (bits 1 and 0) right after it stores 0xbb in extended CMOS byte 0x8c, and a store of 1 on a second path whose caller was not traced. What bit 1 does is unknown. Addresses: the Cobalt README.
 */
/* cpu_reset: rw32, space cpu, reset unknown */
#define COBALT_CPU_RESET_OFFSET                      0x18u /* established */
#define COBALT_CPU_RESET_RESET_SHIFT                 0 /* established */
#define COBALT_CPU_RESET_RESET_MASK                  0x1u
#define COBALT_CPU_RESET_RESET_INPLACE               (COBALT_CPU_RESET_RESET_MASK << COBALT_CPU_RESET_RESET_SHIFT)

/*
 * Timer status. The HAL also stores all ones here once while setting up the timer, after it loads the count and sets the run bit, so an all-ones write is accepted and a model that treats a written 1 as no change matches it. It does not read it back there. The 2.2 and 2.4 timer handlers clear the pending bit by reading the register and writing it back with that bit cleared. The 2.5 and later code never writes it, so whether a level timer interrupt needs this clear to deassert is open.
 */
/* cpu_stat: rw32, space cpu, reset unknown */
#define COBALT_CPU_STAT_OFFSET                       0x20u /* established */
#define COBALT_CPU_STAT_TIMER_INTR_SHIFT             1 /* established */
#define COBALT_CPU_STAT_TIMER_INTR_MASK              0x1u
#define COBALT_CPU_STAT_TIMER_INTR_INPLACE           (COBALT_CPU_STAT_TIMER_INTR_MASK << COBALT_CPU_STAT_TIMER_INTR_SHIFT)
#define COBALT_CPU_STAT_CACHEOP_INTR_SHIFT           0 /* established */
#define COBALT_CPU_STAT_CACHEOP_INTR_MASK            0x1u
#define COBALT_CPU_STAT_CACHEOP_INTR_INPLACE         (COBALT_CPU_STAT_CACHEOP_INTR_MASK << COBALT_CPU_STAT_CACHEOP_INTR_SHIFT)

/*
 * Timer count. The kernel writes the Cobalt core rate divided by the tick rate (a 100 MHz core rate) before starting the timer and calls it a countdown value. That it reloads itself each period is inferred from the kernel using it as the periodic tick and writing it once. The NT HAL writes all ones to it three times: once at set-up before the run bit is set, then twice more in the calibration loop (two passes, run bit already set), and each pass reads the current count about one real-time-clock second later, of which only the last is used; it takes all ones minus that count as the rate, rounded to the nearest 10,000, with no range test. For that to measure one second the write must set the running count at once, not only a reload that waits for the next expiry (software expectation; the hardware behaviour is inferred). After calibration the HAL also writes the computed tick reload here (halborg.dll 1.3, addresses in the Cobalt README), then sets timer_run and clears timer_mask. The HAL never reads this register back. Addresses: the Cobalt README.
 */
/* cpu_timeval: rw32, space cpu, reset unknown */
#define COBALT_CPU_TIMEVAL_OFFSET                    0x30u /* established */

/*
 * Timer current value. The NT HAL's timer calibration reads it after starting the timer with a reload of 0xffffffff and takes the fall as the tick count over one RTC second (halborg.dll 1.3, HalpCalibrateCobaltTimer); it counts down.
 */
/* cpu_timecur: r32, space cpu, reset unknown */
#define COBALT_CPU_TIMECUR_OFFSET                    0x38u /* established */

/*
 * Cache-operation request, used by the NT HAL's cache flush routine. It first waits for bit 16 to clear, then stores the line count (the byte length rounded up to 32-byte lines, at most 0xffff per request) in bits 15:0 with bit 16 set (start), and bit 18 set as well when the caller asks for invalidate and the HAL's invalidate flag is set. The address goes to cpu_cacheop_addr first. The HAL does not use these registers on the reduced revisions. The bit meanings come from this use only; nothing says what the operation does on the bus.
 */
/* cpu_cacheop_ctl: rw32, space cpu, reset unknown */
#define COBALT_CPU_CACHEOP_CTL_OFFSET                0x40u /* inferred */

/*
 * Start address of the cache operation requested through the cache-operation request register (cpu_cacheop_ctl). The HAL stores it immediately before the request word and never reads it.
 */
/* cpu_cacheop_addr: rw32, space cpu, reset unknown */
#define COBALT_CPU_CACHEOP_ADDR_OFFSET               0x48u /* inferred */

/*
 * Bit 16 is set while cache operations are outstanding. The HAL polls it, stalling between reads, after the last flush request; the request routine polls bit 16 of the request register the same way before it starts a new one.
 */
/* cpu_cacheop_busy: r32, space cpu, reset unknown */
#define COBALT_CPU_CACHEOP_BUSY_OFFSET               0x50u /* inferred */

#define COBALT_APIC_8259                             0xcu /* established */
#define COBALT_APIC_AS                               0x18u /* established */
#define COBALT_APIC_CPU                              0x1cu /* established */
#define COBALT_APIC_IDE0                             0x4u /* inferred */
#define COBALT_APIC_IDE1                             0x2u /* established */
#define COBALT_APIC_LINES                            0x1eu /* established */
#define COBALT_APIC_LI_AUDIO                         0x16u /* inferred */
#define COBALT_APIC_MEM_ERR0                         0x1au /* established */
#define COBALT_APIC_MEM_ERR1                         0x1bu /* established */
#define COBALT_APIC_NMI                              0x1du /* established */
#define COBALT_APIC_PCIA_BASE0                       0x0u /* established */
#define COBALT_APIC_PCIA_BASE123                     0x5u /* established */
#define COBALT_APIC_PCIB_BASE0                       0x8u /* established */
#define COBALT_APIC_PCIB_BASE123                     0xdu /* established */
#define COBALT_APIC_PHYS                             0xc4000000u /* established */
#define COBALT_APIC_PIIX4_USB                        0x7u /* established */
#define COBALT_APIC_RE                               0x19u /* established */
#define COBALT_APIC_VIDIN0                           0x12u /* established */
#define COBALT_APIC_VIDIN1                           0x13u /* established */
#define COBALT_APIC_VIDOUT0                          0x10u /* established */
#define COBALT_APIC_VIDOUT1                          0x11u /* established */
#define COBALT_CPU_MAX                               0x4u /* inferred */
#define COBALT_CPU_NUM_PHYS                          0x1e00u /* established */
#define COBALT_CPU_PHYS                              0xc2000000u /* established */
#define COBALT_TIME_HZ                               0x5f5e100u /* inferred */

#endif /* COBALT_GEN_H */
