/* generated from devices/r5000_cp0/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 6a9b39abb11b3b99b791300a4de226fd477602f6718575488b04e14313a7ffdf */
/* MIPS R5000 CP0 Config, Status, PageMask and LLAddr field positions, and FCR31 flags */
#ifndef R5KCP0_GEN_H
#define R5KCP0_GEN_H

#include <stdint.h>


#define R5KCP0_R5KCFG_BE_MASK                        0x8000u /* established */
#define R5KCP0_R5KCFG_CACHE_32K_CODE                 0x3u /* established */
#define R5KCP0_R5KCFG_DB_MASK                        0x10u /* established */
#define R5KCP0_R5KCFG_DC_MASK                        0x1c0u /* established */
#define R5KCP0_R5KCFG_DC_SHIFT                       0x6u /* established */
#define R5KCP0_R5KCFG_EB_MASK                        0x2000u /* established */
#define R5KCP0_R5KCFG_EC_DIVISOR_BASE                0x2u /* established */
#define R5KCP0_R5KCFG_EC_MASK                        0x70000000u /* established */
#define R5KCP0_R5KCFG_EC_SHIFT                       0x1cu /* established */
#define R5KCP0_R5KCFG_EM_MASK                        0x4000u /* established */
#define R5KCP0_R5KCFG_EP_MASK                        0xf000000u /* established */
#define R5KCP0_R5KCFG_EP_SHIFT                       0x18u /* established */
#define R5KCP0_R5KCFG_EW_MASK                        0xc0000u /* established */
#define R5KCP0_R5KCFG_EW_SHIFT                       0x12u /* established */
#define R5KCP0_R5KCFG_FIXED_ONE_MASK                 0x10000u /* established */
#define R5KCP0_R5KCFG_IB_MASK                        0x20u /* established */
#define R5KCP0_R5KCFG_IC_MASK                        0xe00u /* established */
#define R5KCP0_R5KCFG_IC_SHIFT                       0x9u /* established */
#define R5KCP0_R5KCFG_K0_MASK                        0x7u /* established */
#define R5KCP0_R5KCFG_K0_SHIFT                       0x0u /* established */
#define R5KCP0_R5KCFG_SB_MASK                        0xc00000u /* established */
#define R5KCP0_R5KCFG_SB_SHIFT                       0x16u /* established */
#define R5KCP0_R5KCFG_SC_BIT                         0x11u /* established */
#define R5KCP0_R5KCFG_SC_MASK                        0x20000u /* established */
#define R5KCP0_R5KCFG_SE_MASK                        0x1000u /* established */
#define R5KCP0_R5KCFG_SS_MASK                        0x300000u /* established */
#define R5KCP0_R5KCFG_SS_SHIFT                       0x14u /* established */
#define R5KCP0_R5KFCR_CAUSE_MASK                     0x3f000u /* established */
#define R5KCP0_R5KFCR_CAUSE_SHIFT                    0xcu /* established */
#define R5KCP0_R5KFCR_CC0_MASK                       0x800000u /* established */
#define R5KCP0_R5KFCR_CC_HI_MASK                     0xfe000000u /* established */
#define R5KCP0_R5KFCR_CC_HI_SHIFT                    0x19u /* established */
#define R5KCP0_R5KFCR_ENABLE_MASK                    0xf80u /* established */
#define R5KCP0_R5KFCR_ENABLE_SHIFT                   0x7u /* established */
#define R5KCP0_R5KFCR_FLAG_MASK                      0x7cu /* established */
#define R5KCP0_R5KFCR_FLAG_SHIFT                     0x2u /* established */
#define R5KCP0_R5KFCR_FS_MASK                        0x1000000u /* established */
#define R5KCP0_R5KFCR_RM_MASK                        0x3u /* established */
#define R5KCP0_R5KFCR_RSVD_MASK                      0x7c0000u /* established */
#define R5KCP0_R5KLL_MASK                            0xffffffffu /* established */
#define R5KCP0_R5KLL_SHIFT                           0x4u /* established */
#define R5KCP0_R5KPM_FIELD_MASK                      0x1ffe000u /* established */
#define R5KCP0_R5KPM_FIELD_SHIFT                     0xdu /* established */
#define R5KCP0_R5KPM_PAGE_16K                        0x6000u /* established */
#define R5KCP0_R5KPM_PAGE_16M                        0x1ffe000u /* established */
#define R5KCP0_R5KPM_PAGE_1M                         0x1fe000u /* established */
#define R5KCP0_R5KPM_PAGE_256K                       0x7e000u /* established */
#define R5KCP0_R5KPM_PAGE_4K                         0x0u /* established */
#define R5KCP0_R5KPM_PAGE_4M                         0x7fe000u /* established */
#define R5KCP0_R5KPM_PAGE_64K                        0x1e000u /* established */
#define R5KCP0_R5KST_BEV_MASK                        0x400000u /* established */
#define R5KCP0_R5KST_CE_MASK                         0x20000u /* established */
#define R5KCP0_R5KST_CU_MASK                         0x70000000u /* established */
#define R5KCP0_R5KST_DE_MASK                         0x10000u /* established */
#define R5KCP0_R5KST_ERL_MASK                        0x4u /* established */
#define R5KCP0_R5KST_EXL_MASK                        0x2u /* established */
#define R5KCP0_R5KST_FR_MASK                         0x4000000u /* established */
#define R5KCP0_R5KST_IE_MASK                         0x1u /* established */
#define R5KCP0_R5KST_IMPLEMENTED_MASK                0xf653ffffu /* established */
#define R5KCP0_R5KST_IM_MASK                         0xff00u /* established */
#define R5KCP0_R5KST_IM_SHIFT                        0x8u /* established */
#define R5KCP0_R5KST_KSU_MASK                        0x18u /* established */
#define R5KCP0_R5KST_KSU_SHIFT                       0x3u /* established */
#define R5KCP0_R5KST_KX_MASK                         0x80u /* established */
#define R5KCP0_R5KST_RE_MASK                         0x2000000u /* established */
#define R5KCP0_R5KST_SR_MASK                         0x100000u /* established */
#define R5KCP0_R5KST_SX_MASK                         0x40u /* established */
#define R5KCP0_R5KST_UX_MASK                         0x20u /* established */
#define R5KCP0_R5KST_XX_MASK                         0x80000000u /* established */

#endif /* R5KCP0_GEN_H */
