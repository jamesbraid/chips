/* generated from devices/r10000_secondary_cache_ecc/registers.toml by defs-gen - do not edit, change the source */
/* R10000 family CP0 CacheErr fields for secondary-cache errors */
#ifndef R10K_GEN_H
#define R10K_GEN_H

#include <stdint.h>


#define R10K_R10K_CACHEERR_D_MASK                    0xc000000u /* established */
#define R10K_R10K_CACHEERR_D_SHIFT                   0x1au /* established */
#define R10K_R10K_CACHEERR_SIDX_MASK                 0x7fffc0u /* established */
#define R10K_R10K_CACHEERR_SIDX_SHIFT                0x6u /* established */
#define R10K_R10K_CACHEERR_TA_MASK                   0x3000000u /* established */
#define R10K_R10K_CACHEERR_TA_SHIFT                  0x18u /* established */
#define R10K_R10K_CACHEERR_UNIT_SECONDARY            0x2u /* established */
#define R10K_R10K_CACHEERR_UNIT_SHIFT                0x1eu /* established */

#endif /* R10K_GEN_H */
