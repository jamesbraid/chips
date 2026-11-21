/* generated from devices/xbow/registers-extra.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 5d0eaa0d4362a4e57ae74a9515b91ea99d1ae0b25cbc4f8dbf94696f4a778ea6 */
/* Xbow registers outside the census */
#ifndef XBOW_GEN_H
#define XBOW_GEN_H

#include <stdint.h>


/* perf_a: rw32, reset unknown */
#define XBOW_PERF_A                                  0x000060 /* established */

/* perf_b: rw32, reset unknown */
#define XBOW_PERF_B                                  0x000068 /* established */

/* link_f_arb_upper: rw32, reset unknown */
#define XBOW_LINK_F_ARB_UPPER                        0x0002d8 /* inferred */

#define XBOW_FENCE_LINK_8                            0x80u /* inferred */
#define XBOW_FENCE_LINK_9                            0x88u /* inferred */
#define XBOW_FENCE_LINK_A                            0x90u /* inferred */
#define XBOW_FENCE_LINK_B                            0x98u /* inferred */
#define XBOW_FENCE_LINK_C                            0xa0u /* inferred */
#define XBOW_FENCE_LINK_D                            0xa8u /* inferred */
#define XBOW_FENCE_LINK_E                            0xb0u /* inferred */
#define XBOW_FENCE_LINK_F                            0xb8u /* inferred */
#define XBOW_FENCE_WIDGET_0                          0x78u /* inferred */
#define XBOW_FLUSH_LINK_8                            0x100u /* established */
#define XBOW_FLUSH_LINK_9                            0x140u /* established */
#define XBOW_FLUSH_LINK_A                            0x180u /* established */
#define XBOW_FLUSH_LINK_B                            0x1c0u /* established */
#define XBOW_FLUSH_LINK_C                            0x200u /* established */
#define XBOW_FLUSH_LINK_D                            0x240u /* established */
#define XBOW_FLUSH_LINK_E                            0x280u /* established */
#define XBOW_FLUSH_LINK_F                            0x2c0u /* established */
#define XBOW_ID_MFR_MASK                             0xffeu /* established */
#define XBOW_ID_PART_MASK                            0xffff000u /* established */
#define XBOW_ID_REV_MASK                             0xf0000000u /* established */
#define XBOW_PART_PXBOW                              0xd100u /* established */
#define XBOW_PART_XBOW                               0x0u /* established */
#define XBOW_PART_XXBOW                              0xd000u /* established */
#define XBOW_PERF_A_B_19_0                           0xfffffu /* established */
#define XBOW_PERF_A_B_22_20                          0x700000u /* established */
#define XBOW_PERF_B_B_19_0                           0xfffffu /* established */
#define XBOW_PERF_B_B_22_20                          0x700000u /* established */
#define XBOW_PROM_CROSSBAR_LOCK_BIT                  0x2u /* inferred */
#define XBOW_RESOURCE_LOCK                           0xc0u /* inferred */
#define XBOW_RESOURCE_LOCK_CLEAR                     0xc8u /* inferred */
#define XBOW_REV_CODE_1                              0x1u /* established */
#define XBOW_REV_CODE_2                              0x2u /* established */
#define XBOW_REV_CODE_3                              0x3u /* established */
#define XBOW_REV_CODE_4                              0x4u /* established */
#define XBOW_REV_CODE_5                              0x5u /* established */

#endif /* XBOW_GEN_H */
