/* generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 35170f49ee8ac12d6c880fa6df715404fff2b2377770e4dfa5c12c473b50a477 */
/* Cobalt (system ASIC of the SGI Visual Workstation 320 and 540): the CPU block and the interrupt controller, as SGI's Linux platform code names them */
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
 * Controller identification and enable. The kernel reads it, sets the enable bit with a read-modify-write that it says must not change the identification, and prints the result. Where the identification field sits is not known. The NT HAL reads it and, only when bits 27:24 are zero, clears bit 8 and the field and stores 4 in the field; it then in every case ORs in bit 8 and stores it again. It masks all thirty entries first, so entries accept writes while the controller is disabled. The PROM does not test the field: it replaces bits 27:24 with 4 unconditionally and keeps every other bit as read, once in the self-test and once in the main module, with no other access to this offset in either. No reset value is known: no code depends on the value before its first write. Addresses: the Cobalt README.
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
 * Cobalt revision. The kernel prints it at start-up and, in the 2.4 interrupt path, reads it after a driver has acknowledged its device as a way to make sure the driver's write has reached the device before the end-of-interrupt. Three shipped readers constrain the value: the NT HAL compares the whole 32-bit word with 0xa0 and 0xa8, so those two revisions read with bits 31:8 zero; the PROM main module keeps only the low byte before the same comparisons; the PROM self-test records the difference between the word with its low nibble cleared and 0xa0, so the revisions it expects have bits 31:8 zero and 0xa in bits 7:4. The low nibble and the layout beneath it are not known. The register is only ever read, so no reset value is known. Addresses: the Cobalt README.
 */
/* cpu_rev: r32, space cpu, reset unknown */
#define COBALT_CPU_REV_OFFSET                        0x8u /* established */

/*
 * Timer and memory control. Linux sets timer_run and clears timer_mask, each by a read-modify-write, after loading the count, and touches no other bit. The NT HAL (halborg.dll 1.3: the Cobalt control set-up in HalInitSystem and HalpEccControl) also clears ecc_enable at start-up, sets timer_mask, ORs in page_close from its PAGEOPENPOLICY boot option, and sets ecc_enable together with bit 0 of the memory block when it enables ECC.
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
 * Machine reset on early boards. The NT HAL sets bit 0 to reboot the 320 below board revision 12 and the 540 revision 0 (halborg.dll 1.3, HalpReboot, BoardResetAtPIIX4); other boards reboot through port 0xcf9. A separate register from the memory block's error status at offset 0x18. The PROM self-test also writes it: a read-modify-write that ORs in bit 0 when the CMOS marker bytes are not 0xa5 (the value read is only ORed, never tested), a store of 3 (bits 1 and 0) right after it stores 0xbb in extended CMOS byte 0x8c, and a store of 1 on a second path whose caller was not traced. What bit 1 does is unknown. Addresses: the Cobalt README.
 */
/* cpu_reset: rw32, space cpu, reset unknown */
#define COBALT_CPU_RESET_OFFSET                      0x18u /* established */
#define COBALT_CPU_RESET_RESET_SHIFT                 0 /* established */
#define COBALT_CPU_RESET_RESET_MASK                  0x1u
#define COBALT_CPU_RESET_RESET_INPLACE               (COBALT_CPU_RESET_RESET_MASK << COBALT_CPU_RESET_RESET_SHIFT)

/*
 * Timer status. The HAL also stores all ones here once while setting up the timer, after it loads the count and sets the run bit, so an all-ones write is accepted and a model that treats a written 1 as no change matches it. The 2.2 and 2.4 timer handlers clear the pending bit by reading the register and writing it back with that bit cleared. The 2.5 and later code never writes it, so whether a level timer interrupt needs this clear to deassert is open.
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
 * Timer count. The kernel writes the Cobalt core rate divided by the tick rate (a 100 MHz core rate) before starting the timer and calls it a countdown value. That it reloads itself each period is inferred from the kernel using it as the periodic tick and writing it once. The NT HAL writes all ones to it with the run bit already set, in a second calibration pass, and reads the current count about one real-time-clock second later; it takes all ones minus that count as the rate, rounded to the nearest 10,000, with no range test. For that to measure one second the write must set the running count at once, not only a reload that waits for the next expiry (software expectation; the hardware behaviour is inferred). The HAL never reads this register back. Addresses: the Cobalt README.
 */
/* cpu_timeval: rw32, space cpu, reset unknown */
#define COBALT_CPU_TIMEVAL_OFFSET                    0x30u /* established */

/*
 * Timer current value. The NT HAL's timer calibration reads it after starting the timer with a reload of 0xffffffff and takes the fall as the tick count over one RTC second (halborg.dll 1.3, HalpCalibrateCobaltTimer); it counts down.
 */
/* cpu_timecur: r32, space cpu, reset unknown */
#define COBALT_CPU_TIMECUR_OFFSET                    0x38u /* established */

/*
 * Memory controller control. At timer set-up the HAL also stores 0 here and 0 in the error status. The PROM self-test sets bit 0 with a full-word store of 1 and clears it with a store of 0; the main module clears bit 0 by read-modify-write before it sizes memory; none depends on a value read before the first write. The NT HAL clears it at start-up and sets bit 0, together with the CPU block's control bit 0, to turn ECC checking on (halborg.dll 1.3, HalpEccControl). Other bits are not touched by any software read.
 */
/* mem_ecc: rw32, space mem, reset unknown */
#define COBALT_MEM_ECC_OFFSET                        0x0u /* established */
#define COBALT_MEM_ECC_ECC_ENABLE_SHIFT              0 /* established */
#define COBALT_MEM_ECC_ECC_ENABLE_MASK               0x1u
#define COBALT_MEM_ECC_ECC_ENABLE_INPLACE            (COBALT_MEM_ECC_ECC_ENABLE_MASK << COBALT_MEM_ECC_ECC_ENABLE_SHIFT)

/*
 * Memory error status. The NT HAL's error handler reads it, treats the error as non-fatal when bit 16 is set or when bit 17 is set and the syndrome is zero, and clears the register by writing zero. The meaning of the bits is inferred from the messages the handler selects with them (invalid address, hard ECC, soft ECC, multiple errors).
 */
/* mem_err_status: rw32, space mem, reset unknown */
#define COBALT_MEM_ERR_STATUS_OFFSET                 0x18u /* established */

/*
 * Memory error address, printed by the HAL as the address of the error.
 */
/* mem_err_addr: r32, space mem, reset unknown */
#define COBALT_MEM_ERR_ADDR_OFFSET                   0x28u /* established */

/*
 * Memory error ECC syndrome. A nonzero syndrome with a correctable error sends the HAL to HalpCorrectSoftEccError, which computes a quadword offset from the syndrome byte that is nonzero but performs no write-back; a model must not depend on a HAL write.
 */
/* mem_err_syndrome: r32, space mem, reset unknown */
#define COBALT_MEM_ERR_SYNDROME_OFFSET               0x30u /* established */

#define COBALT_APIC_8259                             0xcu /* established */
#define COBALT_APIC_AS                               0x18u /* established */
#define COBALT_APIC_CPU                              0x1cu /* established */
#define COBALT_APIC_IDE0                             0x4u /* inferred */
#define COBALT_APIC_IDE1                             0x2u /* established */
#define COBALT_APIC_LINES                            0x1eu /* established */
#define COBALT_APIC_LI_AUDIO                         0x16u /* inferred */
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
#define COBALT_MEM_PHYS                              0xc6000000u /* established */
#define COBALT_TIME_HZ                               0x5f5e100u /* inferred */

#endif /* COBALT_GEN_H */
