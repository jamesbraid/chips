/* generated from devices/r5000_identity/registers.toml by defs-gen - do not
 * edit, change the source */
/* defs-gen 4 */
/* input sha256 07e1068ce26ce0f77cf78067f4062c9a866cd127df6ad62dd0ea79185aebe2d0 */
/* MIPS R5000 family processor identity, reset entries, cache geometry and TLB
 * size */
#ifndef R5K_GEN_H
#define R5K_GEN_H

#include <stdint.h>


#define R5K_R5K_COLD_RANDOM                          0x2fu /* established */
#define R5K_R5K_COLD_WIRED                           0x0u /* established */
#define R5K_R5K_FCR0_OBSERVED                        0x2310u /* inferred */
#define R5K_R5K_IMP_VR5000                           0x23u /* established */
#define R5K_R5K_PHYS_ADDR_BITS                       0x24u /* established */
#define R5K_R5K_PRID_IMP_MASK                        0xff00u /* established */
#define R5K_R5K_PRID_IMP_SHIFT                       0x8u /* established */
#define R5K_R5K_PRID_OBSERVED                        0x2321u /* inferred */
#define R5K_R5K_PRID_REV_MASK                        0xffu /* established */
#define R5K_R5K_PRIMARY_CACHE_BYTES                  0x8000u /* established */
#define R5K_R5K_PRIMARY_LINE_BYTES                   0x20u /* established */
#define R5K_R5K_PRIMARY_SETS                         0x200u /* established */
#define R5K_R5K_PRIMARY_WAYS                         0x2u /* established */
/* established */
#define R5K_R5K_RESET_VECTOR                         0xffffffffbfc00000ull
#define R5K_R5K_SECONDARY_LINE_BYTES                 0x20u /* established */
#define R5K_R5K_SECONDARY_WAYS                       0x1u /* established */
#define R5K_R5K_SYSCLK_MAX_MHZ                       0x64u /* established */
#define R5K_R5K_TLB_ENTRIES                          0x30u /* established */
#define R5K_R5K_USER_ADDR_BITS                       0x28u /* established */
#define R5K_R5K_WARM_STATUS_SET                      0x500004u /* established */

#endif /* R5K_GEN_H */
