/* generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 316a2493ce8fdbc78278d43134e7d66000ec231e17b202c1eee81452a9022731 */
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
 * Interrupt redirection entry, high word. Linux and the NT HAL write zero beside every device entry's low word; the HAL writes the NMI entry's high word with one bit set per processor id (1 shifted by the processor number) in bits 31:24 for logical delivery. So the field is the destination, in the I/O APIC layout (established for the NMI use; zero as 'processor id 0, physical' for device entries is inferred from the layout). The HAL never steers a device entry to another processor.
 */
/* apic_hi: rw32, space apic, reset unknown */
#define COBALT_APIC_HI_OFFSET                        0x4u /* established */
#define COBALT_APIC_HI_COUNT                         30
#define COBALT_APIC_HI_STRIDE                        16
#define COBALT_APIC_HI_DEST_SHIFT                    24 /* established */
#define COBALT_APIC_HI_DEST_MASK                     0xffu
#define COBALT_APIC_HI_DEST_INPLACE                  (COBALT_APIC_HI_DEST_MASK << COBALT_APIC_HI_DEST_SHIFT)

/*
 * Controller identification and enable. The kernel reads it, sets the enable bit with a read-modify-write that it says must not change the identification, and prints the result. Where the identification field sits is not known.
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
 * Cobalt revision. The kernel prints it at start-up and, in the 2.4 interrupt path, reads it after a driver has acknowledged its device as a way to make sure the driver's write has reached the device before the end-of-interrupt. The field layout is not known.
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
 * Machine reset on early boards. The NT HAL sets bit 0 to reboot the 320 below board revision 12 and the 540 revision 0 (halborg.dll 1.3, HalpReboot, BoardResetAtPIIX4); other boards reboot through port 0xcf9. A separate register from the memory block's error status at offset 0x18.
 */
/* cpu_reset: rw32, space cpu, reset unknown */
#define COBALT_CPU_RESET_OFFSET                      0x18u /* established */
#define COBALT_CPU_RESET_RESET_SHIFT                 0 /* established */
#define COBALT_CPU_RESET_RESET_MASK                  0x1u
#define COBALT_CPU_RESET_RESET_INPLACE               (COBALT_CPU_RESET_RESET_MASK << COBALT_CPU_RESET_RESET_SHIFT)

/*
 * Timer status. The 2.2 and 2.4 timer handlers clear the pending bit by reading the register and writing it back with that bit cleared. The 2.5 and later code never writes it, so whether a level timer interrupt needs this clear to deassert is open.
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
 * Timer count. The kernel writes the Cobalt core rate divided by the tick rate (a 100 MHz core rate) before starting the timer and calls it a countdown value. That it reloads itself each period is inferred from the kernel using it as the periodic tick and writing it once.
 */
/* cpu_timeval: rw32, space cpu, reset unknown */
#define COBALT_CPU_TIMEVAL_OFFSET                    0x30u /* established */

/*
 * Timer current value. The NT HAL's timer calibration reads it after starting the timer with a reload of 0xffffffff and takes the fall as the tick count over one RTC second (halborg.dll 1.3, HalpCalibrateCobaltTimer); it counts down.
 */
/* cpu_timecur: r32, space cpu, reset unknown */
#define COBALT_CPU_TIMECUR_OFFSET                    0x38u /* established */

/*
 * Memory controller control. The NT HAL clears it at start-up and sets bit 0, together with the CPU block's control bit 0, to turn ECC checking on (halborg.dll 1.3, HalpEccControl). Other bits are not touched by any software read.
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
 * Memory error ECC syndrome. A nonzero syndrome with a correctable error makes the HAL rewrite the location (HalpCorrectSoftEccError).
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
