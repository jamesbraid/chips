/* generated from defs/r10000_diagnostic.toml by defs-gen - do not edit, change the source */
/* R10000 family CP0 Diagnostic register (branch diagnostic): field positions */
#ifndef R10KDIAG_GEN_H
#define R10KDIAG_GEN_H

#include <stdint.h>


#define R10KDIAG_R10KDIAG_BPIDX_R10K_MASK            0xff8u /* established */
#define R10KDIAG_R10KDIAG_BPIDX_R12K_MASK            0x3ff8u /* established */
#define R10KDIAG_R10KDIAG_BPMODE_MASK                0x30000u /* established */
#define R10KDIAG_R10KDIAG_BPOP_MASK                  0x3u /* established */
#define R10KDIAG_R10KDIAG_BPSTATE_MASK               0xc000u /* established */
#define R10KDIAG_R10KDIAG_DBRC_BIT                   0x16u /* established */
#define R10KDIAG_R10KDIAG_DBRC_MASK                  0x400000u /* established */
#define R10KDIAG_R10KDIAG_R12K_BTAC_DIS_BIT          0x1bu /* established */
#define R10KDIAG_R10KDIAG_R12K_BTAC_DIS_MASK         0x8000000u /* established */
#define R10KDIAG_R10KDIAG_R12K_GHIST_ALL_BIT         0x1au /* established */
#define R10KDIAG_R10KDIAG_R12K_GHIST_COUNT_MASK      0x3800000u /* established */

#endif /* R10KDIAG_GEN_H */
