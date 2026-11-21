/* generated from devices/r12000a_variant/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 4df134dc1016e8cf057c55413f2b161f333b9b165e5097b4b0016efb318a1b37 */
/* R12000A mode-bit fields and performance control 0 syndrome field */
#ifndef R12KA_GEN_H
#define R12KA_GEN_H

#include <stdint.h>


#define R12KA_R12KA_MODE_HSTL_MASK                   0x60000000u /* established */
#define R12KA_R12KA_MODE_HSTL_SHIFT                  0x1du /* established */
#define R12KA_R12KA_MODE_SCCLKDIV_MASK               0x380000u /* established */
#define R12KA_R12KA_MODE_SCCLKDIV_SHIFT              0x13u /* established */
#define R12KA_R12KA_MODE_SCCLKDIV_TEST_CODE          0x7u /* established */
#define R12KA_R12KA_MODE_SYSCLKDIV_CODE_A_ONLY       0xcu /* established */
#define R12KA_R12KA_MODE_SYSCLKDIV_MASK              0x1e00u /* established */
#define R12KA_R12KA_MODE_SYSCLKDIV_SHIFT             0x9u /* established */
#define R12KA_R12KA_PERF_CTL0_SYNDROME_MASK          0xff800000u /* established */
#define R12KA_R12KA_PERF_CTL0_SYNDROME_SHIFT         0x17u /* established */

#endif /* R12KA_GEN_H */
