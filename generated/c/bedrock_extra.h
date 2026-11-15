/* generated from devices/bedrock/registers-extra.toml by defs-gen - do not edit, change the source */
/* Hub and Bedrock network-controller registers outside the census */
#ifndef BEDROCK_GEN_H
#define BEDROCK_GEN_H

#include <stdint.h>


/* node_region_mask: r64, reset unknown */
#define BEDROCK_NODE_REGION_MASK                     0x1000018 /* established */

/* mem_bank_config: rw64, reset unknown */
#define BEDROCK_MEM_BANK_CONFIG                      0x1f80008 /* established */

#define BEDROCK_II_CREDIT_TIMEOUT                    0x4001e0u /* established */
#define BEDROCK_II_READ_RESP_PRESCALE_B_54_32        0x7fffff00000000ull /* established */
#define BEDROCK_II_READ_RESP_TIMEOUT_B_59_55         0xf80000000000000ull /* established */
#define BEDROCK_II_TAIL_TIMEOUT                      0x4001f0u /* established */
#define BEDROCK_MEM_BANK_CONFIG_BANK_SELECT          0x300000000ull /* established */
#define BEDROCK_MEM_BANK_CONFIG_B_58_56              0x700000000000000ull /* established */
#define BEDROCK_MEM_BANK_CONFIG_LANE_ENABLE          0x3u /* established */
#define BEDROCK_MEM_BANK_CONFIG_LANE_SIZE            0xf0u /* established */
#define BEDROCK_NIC_ACCESS_HUB_PHYS_LOW              0x1e04030u /* established */
#define BEDROCK_NODE_SHIFT                           0x21u /* established */
#define BEDROCK_PI_ERROR_SPOOL_SIZE_BASE             0x1000u /* established */

#endif /* BEDROCK_GEN_H */
