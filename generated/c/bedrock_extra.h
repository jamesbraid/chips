/* generated from devices/bedrock/registers-extra.toml by defs-gen - do not edit, change the source */
/* Hub and Bedrock network-controller registers outside the census */
#ifndef BEDROCK_GEN_H
#define BEDROCK_GEN_H

#include <stdint.h>


/* ii_widget_status: r64, reset 0x0 */
#define BEDROCK_II_WIDGET_STATUS                     0x400008 /* established */

/* ii_shutdown_status: r64, reset 0x111 */
#define BEDROCK_II_SHUTDOWN_STATUS                   0x4001e8 /* established */

/* ii_error_header_1: r64, reset 0x0 */
#define BEDROCK_II_ERROR_HEADER_1                    0x400220 /* established */

/* ii_error_header_2: r64, reset 0x0 */
#define BEDROCK_II_ERROR_HEADER_2                    0x400228 /* established */

/* node_region_mask: r64, reset unknown */
#define BEDROCK_NODE_REGION_MASK                     0x1000018 /* established */

/* mem_bank_config: rw64, reset unknown */
#define BEDROCK_MEM_BANK_CONFIG                      0x1f80008 /* established */

#define BEDROCK_II_CREDIT_TIMEOUT                    0x4001e0u /* established */
#define BEDROCK_II_ERROR_HEADER_1_COMMAND            0x7fu /* established */
#define BEDROCK_II_ERROR_HEADER_1_ERR_TYPE           0xf00000000ull /* established */
#define BEDROCK_II_ERROR_HEADER_1_OVERRUN            0x10000000000ull /* established */
#define BEDROCK_II_ERROR_HEADER_1_PRINT_GATE         0x100000000000ull /* established */
#define BEDROCK_II_ERROR_HEADER_1_SOURCE             0x7ff00000u /* established */
#define BEDROCK_II_ERROR_HEADER_1_SUPPLEMENTAL       0x7ff00u /* established */
#define BEDROCK_II_ERROR_HEADER_2_ADDRESS            0x3fffffffffull /* established */
#define BEDROCK_II_ERROR_HEADER_2_TAIL               0x10000000000ull /* established */
#define BEDROCK_II_READ_RESP_PRESCALE_B_54_32        0x7fffff00000000ull /* established */
#define BEDROCK_II_READ_RESP_TIMEOUT_B_59_55         0xf80000000000000ull /* established */
#define BEDROCK_II_TAIL_TIMEOUT                      0x4001f0u /* established */
#define BEDROCK_II_WIDGET_STATUS_CREDIT_TIMEOUT      0x10u /* established */
#define BEDROCK_II_WIDGET_STATUS_ERROR               0x100000000ull /* established */
#define BEDROCK_II_WIDGET_STATUS_RETRY_TIMEOUT       0x200u /* established */
#define BEDROCK_II_WIDGET_STATUS_TAIL_TIMEOUT        0x20u /* established */
#define BEDROCK_MEM_BANK_CONFIG_BANK_SELECT          0x300000000ull /* established */
#define BEDROCK_MEM_BANK_CONFIG_B_58_56              0x700000000000000ull /* established */
#define BEDROCK_MEM_BANK_CONFIG_LANE_ENABLE          0x3u /* established */
#define BEDROCK_MEM_BANK_CONFIG_LANE_SIZE            0xf0u /* established */
#define BEDROCK_NIC_ACCESS_HUB_PHYS_LOW              0x1e04030u /* established */
#define BEDROCK_NODE_SHIFT                           0x21u /* established */
#define BEDROCK_PI_ERROR_SPOOL_SIZE_BASE             0x1000u /* established */

#endif /* BEDROCK_GEN_H */
