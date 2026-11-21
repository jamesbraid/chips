/* generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 65075ae8c86b91fe79d4c928e0275c1d67dde934618f654a26e4b81ce56d0d58 */
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
#define COBALT_APIC_LO_MASK_SHIFT                    16 /* established */
#define COBALT_APIC_LO_MASK_MASK                     0x1u
#define COBALT_APIC_LO_MASK_INPLACE                  (COBALT_APIC_LO_MASK_MASK << COBALT_APIC_LO_MASK_SHIFT)
#define COBALT_APIC_LO_LEVEL_SHIFT                   15 /* established */
#define COBALT_APIC_LO_LEVEL_MASK                    0x1u
#define COBALT_APIC_LO_LEVEL_INPLACE                 (COBALT_APIC_LO_LEVEL_MASK << COBALT_APIC_LO_LEVEL_SHIFT)
#define COBALT_APIC_LO_VECTOR_SHIFT                  0 /* inferred */
#define COBALT_APIC_LO_VECTOR_MASK                   0xffu
#define COBALT_APIC_LO_VECTOR_INPLACE                (COBALT_APIC_LO_VECTOR_MASK << COBALT_APIC_LO_VECTOR_SHIFT)

/*
 * Interrupt redirection entry, high word. The kernel writes zero beside every low word it sets and never reads it. By the standard I/O APIC layout it would hold the destination processor; that is inferred from the layout of the low word and the register spacing, and no code reads it back.
 */
/* apic_hi: rw32, space apic, reset unknown */
#define COBALT_APIC_HI_OFFSET                        0x4u /* inferred */
#define COBALT_APIC_HI_COUNT                         30
#define COBALT_APIC_HI_STRIDE                        16

/*
 * Controller identification and enable. The kernel reads it, sets the enable bit with a read-modify-write that it says must not change the identification, and prints the result. Where the identification field sits is not known.
 */
/* apic_id: rw32, space apic, reset unknown */
#define COBALT_APIC_ID_OFFSET                        0xffcu /* established */
#define COBALT_APIC_ID_ENABLE_SHIFT                  8 /* established */
#define COBALT_APIC_ID_ENABLE_MASK                   0x1u
#define COBALT_APIC_ID_ENABLE_INPLACE                (COBALT_APIC_ID_ENABLE_MASK << COBALT_APIC_ID_ENABLE_SHIFT)

/*
 * Cobalt revision. The kernel prints it at start-up and, in the 2.4 interrupt path, reads it after a driver has acknowledged its device as a way to make sure the driver's write has reached the device before the end-of-interrupt. The field layout is not known.
 */
/* cpu_rev: r32, space cpu, reset unknown */
#define COBALT_CPU_REV_OFFSET                        0x8u /* established */

/*
 * Timer control. The kernel sets timer_run and clears timer_mask, each by a read-modify-write, after loading the count. Other bits are never touched.
 */
/* cpu_ctrl: rw32, space cpu, reset unknown */
#define COBALT_CPU_CTRL_OFFSET                       0x10u /* established */
#define COBALT_CPU_CTRL_TIMER_MASK_SHIFT             3 /* established */
#define COBALT_CPU_CTRL_TIMER_MASK_MASK              0x1u
#define COBALT_CPU_CTRL_TIMER_MASK_INPLACE           (COBALT_CPU_CTRL_TIMER_MASK_MASK << COBALT_CPU_CTRL_TIMER_MASK_SHIFT)
#define COBALT_CPU_CTRL_TIMER_RUN_SHIFT              2 /* established */
#define COBALT_CPU_CTRL_TIMER_RUN_MASK               0x1u
#define COBALT_CPU_CTRL_TIMER_RUN_INPLACE            (COBALT_CPU_CTRL_TIMER_RUN_MASK << COBALT_CPU_CTRL_TIMER_RUN_SHIFT)

/*
 * Timer status. The 2.2 and 2.4 timer handlers clear the pending bit by reading the register and writing it back with that bit cleared. The 2.5 and later code never writes it, so whether a level timer interrupt needs this clear to deassert is open.
 */
/* cpu_stat: rw32, space cpu, reset unknown */
#define COBALT_CPU_STAT_OFFSET                       0x20u /* established */
#define COBALT_CPU_STAT_TIMER_INTR_SHIFT             1 /* established */
#define COBALT_CPU_STAT_TIMER_INTR_MASK              0x1u
#define COBALT_CPU_STAT_TIMER_INTR_INPLACE           (COBALT_CPU_STAT_TIMER_INTR_MASK << COBALT_CPU_STAT_TIMER_INTR_SHIFT)

/*
 * Timer count. The kernel writes the Cobalt core rate divided by the tick rate (a 100 MHz core rate) before starting the timer and calls it a countdown value. That it reloads itself each period is inferred from the kernel using it as the periodic tick and writing it once.
 */
/* cpu_timeval: rw32, space cpu, reset unknown */
#define COBALT_CPU_TIMEVAL_OFFSET                    0x30u /* established */

#define COBALT_APIC_8259                             0xcu /* established */
#define COBALT_APIC_AS                               0x18u /* established */
#define COBALT_APIC_CPU                              0x1cu /* established */
#define COBALT_APIC_IDE0                             0x4u /* established */
#define COBALT_APIC_IDE1                             0x2u /* established */
#define COBALT_APIC_LINES                            0x1eu /* established */
#define COBALT_APIC_LI_AUDIO                         0x16u /* established */
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
#define COBALT_CPU_MAX                               0x4u /* established */
#define COBALT_CPU_NUM_PHYS                          0x1e00u /* established */
#define COBALT_CPU_PHYS                              0xc2000000u /* established */
#define COBALT_TIME_HZ                               0x5f5e100u /* established */

#endif /* COBALT_GEN_H */
