/* generated from devices/r14000_perf_counters/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 7eecccb8ac094c1de6c36069e754426c42e0d4e6a5dc0a503425e631c68b20df */
/* R14000 CP0 performance counters: selectors, control fields and event numbers */
#ifndef R14KPC_GEN_H
#define R14KPC_GEN_H

#include <stdint.h>


#define R14KPC_R14KPC_CNT_BITS                       0x20u /* inferred */
#define R14KPC_R14KPC_CNT_OVERFLOW_BIT               0x1fu /* inferred */
#define R14KPC_R14KPC_CP0_REG                        0x19u /* inferred */
#define R14KPC_R14KPC_CTL_EVENT_MASK                 0x3e0u /* inferred */
#define R14KPC_R14KPC_CTL_EVENT_SHIFT                0x5u /* inferred */
#define R14KPC_R14KPC_CTL_EXL                        0x1u /* inferred */
#define R14KPC_R14KPC_CTL_IE                         0x10u /* inferred */
#define R14KPC_R14KPC_CTL_K                          0x2u /* inferred */
#define R14KPC_R14KPC_CTL_S                          0x4u /* unknown */
#define R14KPC_R14KPC_CTL_U                          0x8u /* inferred */
#define R14KPC_R14KPC_EV_CYCLES                      0x0u /* established */
#define R14KPC_R14KPC_EV_DECODED_INSTR               0x1u /* established */
#define R14KPC_R14KPC_EV_FAILED_SC                   0x5u /* established */
#define R14KPC_R14KPC_EV_MISPREDICT                  0x18u /* established */
#define R14KPC_R14KPC_EV_PREFETCH_EXEC               0x10u /* established */
#define R14KPC_R14KPC_EV_RETIRED_FP                  0x15u /* established */
#define R14KPC_R14KPC_EV_RETIRED_INSTR               0xfu /* established */
#define R14KPC_R14KPC_EV_SCACHE_ECC_CORRECTABLE      0x8u /* established */
#define R14KPC_R14KPC_EV_TLB_MISS                    0x17u /* established */
#define R14KPC_R14KPC_EV_UNIMPLEMENTED               0xeu /* established */
#define R14KPC_R14KPC_PAIR0_CNT_SEL                  0x1u /* inferred */
#define R14KPC_R14KPC_PAIR0_CTL_SEL                  0x0u /* inferred */
#define R14KPC_R14KPC_PAIR1_CNT_SEL                  0x3u /* inferred */
#define R14KPC_R14KPC_PAIR1_CTL_SEL                  0x2u /* inferred */
#define R14KPC_R14KPC_PAIR2_CNT_SEL                  0x5u /* inferred */
#define R14KPC_R14KPC_PAIR2_CTL_SEL                  0x4u /* inferred */
#define R14KPC_R14KPC_PAIR3_CNT_SEL                  0x7u /* inferred */
#define R14KPC_R14KPC_PAIR3_CTL_SEL                  0x6u /* inferred */
#define R14KPC_R14KPC_PAIRS                          0x4u /* inferred */
#define R14KPC_R14KPC_R12K_CTL0_TRIGGER_MASK         0x18000u /* unknown */
#define R14KPC_R14KPC_R12K_CTL3_LEVEL_BIT            0x8000u /* unknown */
#define R14KPC_R14KPC_R12K_CTL_COND_MASK             0x7c00u /* unknown */

#endif /* R14KPC_GEN_H */
