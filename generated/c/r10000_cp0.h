/* generated from devices/r10000_cp0/registers.toml by defs-gen - do not edit, change the source */
/* R10000 CP0 Count and Compare timer interrupt and TLB geometry */
#ifndef R10KCP0_GEN_H
#define R10KCP0_GEN_H

#include <stdint.h>


/*
 * The Cause register bit that carries the Count and Compare timer interrupt.
 */
/* word CAUSE_TIMER: 32 bits; published R10000 user's manual (the source reading gives no document number) */
#define R10KCP0_CAUSE_TIMER_WIDTH                    32 /* established */
#define R10KCP0_CAUSE_TIMER_IP7_SHIFT                15 /* established */
#define R10KCP0_CAUSE_TIMER_IP7_MASK                 0x1u
#define R10KCP0_CAUSE_TIMER_IP7_INPLACE              (R10KCP0_CAUSE_TIMER_IP7_MASK << R10KCP0_CAUSE_TIMER_IP7_SHIFT)

#define R10K_CP0_COMPARE                             0xbu /* established */
#define R10K_CP0_COUNT                               0x9u /* established */
#define R10KCP0_R10K_TLB_ASID_BITS                   0x8u /* inferred */
#define R10KCP0_R10K_TLB_ENTRIES                     0x40u /* inferred */

#endif /* R10KCP0_GEN_H */
