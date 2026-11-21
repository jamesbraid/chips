/* generated from devices/router_sn1/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 b70f66625e769d9712121c425a33c1e848b0297d809537cea42eec8674d89524 */
/* SN1 network router: port block, local routing table and remote reset mask (public header positions) */
#ifndef ROUTER_SN1_GEN_H
#define ROUTER_SN1_GEN_H

#include <stdint.h>


/*
 * Remote reset mask of one port (RR_RESET_MASK, 0x18 from the port base). Bit L minus 1 is the reset-allowed bit for link L (RRM_RESETOK). The header names the bit but not what a reset does with it. The kernel code that reads it is in the router census.
 */
/* reset_mask: rw64, reset unknown; Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) */
#define ROUTER_SN1_RESET_MASK_OFFSET                 0x18u /* established */

/*
 * Local routing table of one port: entry x sits at 0x200 plus 8 times x from the port base (RR_LOCAL_TABLE). Each 64-bit entry holds eight 3-bit fields, one per link. The header gives no meaning for a field value, and the 4-bit stride leaves bits 31 to 63 unnamed. Reset unknown.
 */
/* local_table: rw64, reset unknown; Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) */
#define ROUTER_SN1_LOCAL_TABLE_OFFSET                0x200u /* established */
#define ROUTER_SN1_LOCAL_TABLE_COUNT                 128
#define ROUTER_SN1_LOCAL_TABLE_STRIDE                8
#define ROUTER_SN1_LOCAL_TABLE_LINK8_SHIFT           28 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK8_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK8_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK8_MASK << ROUTER_SN1_LOCAL_TABLE_LINK8_SHIFT)
#define ROUTER_SN1_LOCAL_TABLE_LINK7_SHIFT           24 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK7_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK7_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK7_MASK << ROUTER_SN1_LOCAL_TABLE_LINK7_SHIFT)
#define ROUTER_SN1_LOCAL_TABLE_LINK6_SHIFT           20 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK6_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK6_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK6_MASK << ROUTER_SN1_LOCAL_TABLE_LINK6_SHIFT)
#define ROUTER_SN1_LOCAL_TABLE_LINK5_SHIFT           16 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK5_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK5_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK5_MASK << ROUTER_SN1_LOCAL_TABLE_LINK5_SHIFT)
#define ROUTER_SN1_LOCAL_TABLE_LINK4_SHIFT           12 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK4_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK4_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK4_MASK << ROUTER_SN1_LOCAL_TABLE_LINK4_SHIFT)
#define ROUTER_SN1_LOCAL_TABLE_LINK3_SHIFT           8 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK3_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK3_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK3_MASK << ROUTER_SN1_LOCAL_TABLE_LINK3_SHIFT)
#define ROUTER_SN1_LOCAL_TABLE_LINK2_SHIFT           4 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK2_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK2_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK2_MASK << ROUTER_SN1_LOCAL_TABLE_LINK2_SHIFT)
#define ROUTER_SN1_LOCAL_TABLE_LINK1_SHIFT           0 /* established */
#define ROUTER_SN1_LOCAL_TABLE_LINK1_MASK            0x7ull
#define ROUTER_SN1_LOCAL_TABLE_LINK1_INPLACE         (ROUTER_SN1_LOCAL_TABLE_LINK1_MASK << ROUTER_SN1_LOCAL_TABLE_LINK1_SHIFT)

#define ROUTER_SN1_LOCAL_ENTRIES                     0x80u /* established */
#define ROUTER_SN1_MAX_PORTS                         0x8u /* established */
#define ROUTER_SN1_META_ENTRIES                      0x10u /* established */
#define ROUTER_SN1_RTABLE_FIELD_BITS                 0x3u /* established */
#define ROUTER_SN1_RTABLE_FIELD_STRIDE_BITS          0x4u /* established */

#endif /* ROUTER_SN1_GEN_H */
