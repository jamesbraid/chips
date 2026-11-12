/* generated from defs/r10000_identity.toml by defs-gen - do not edit, change the source */
/* R10000 family processor identity and secondary-cache configuration fields */
#ifndef R10K_GEN_H
#define R10K_GEN_H

#include <stdint.h>


#define R10K_R10K_CONF_SB_BIT                        0xdu /* established */
#define R10K_R10K_CONF_SB_MASK                       0x2000u /* established */
#define R10K_R10K_CONF_SS_MASK                       0x70000u /* established */
#define R10K_R10K_CONF_SS_SHIFT                      0x10u /* established */
#define R10K_R10K_IMP_R10000                         0x9u /* established */
#define R10K_R10K_IMP_R12000                         0xeu /* established */
#define R10K_R10K_IMP_R14000                         0xfu /* established */
#define R10K_R10K_PRID_IMP_MASK                      0xff00u /* established */
#define R10K_R10K_PRID_IMP_SHIFT                     0x8u /* established */
#define R10K_R10K_PRID_REV_MASK                      0xffu /* established */
#define R10K_R10K_R16000_REV_MAJOR_MIN               0x3u /* established */
#define R10K_R10K_SCACHE_LINE_BASE_BYTES             0x40u /* established */
#define R10K_R10K_SCACHE_SIZE_UNIT                   0x80000u /* established */
#define R10K_R10K_SCACHE_WAYS                        0x2u /* established */

#endif /* R10K_GEN_H */
