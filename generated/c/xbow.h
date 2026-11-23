/* generated from devices/xbow/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 3 */
/* input sha256 1d5707b21be4c7d824b64b2d6d46ae200225b3a331af2e4f73daad0758f2a2ce */
/* Xbow (crossbar) */
#ifndef XBOW_GEN_H
#define XBOW_GEN_H

#include <stdint.h>


/* xb_id: r32, reset unknown; census: 21 sites, 7 routines */
#define XBOW_XB_ID                                   0x000000 /* established */

/* xb_stat: r32, reset unknown; census: 8 sites, 4 routines */
#define XBOW_XB_STAT                                 0x000008 /* established */

/* xb_err_upper: r32, reset unknown; census: 10 sites, 4 routines */
#define XBOW_XB_ERR_UPPER                            0x000010 /* established */

/* xb_err_lower: r32, reset unknown; census: 10 sites, 4 routines */
#define XBOW_XB_ERR_LOWER                            0x000018 /* established */

/* xb_ctrl: rw32, reset unknown; census: 9 sites, 3 routines */
#define XBOW_XB_CTRL                                 0x000020 /* established */

/* xb_pkt_to: r32, reset unknown; census: 3 sites, 1 routines */
#define XBOW_XB_PKT_TO                               0x000028 /* established */

/* xb_int_upper: rw32, reset unknown; census: 6 sites, 2 routines */
#define XBOW_XB_INT_UPPER                            0x000030 /* established */

/* xb_int_lower: rw32, reset unknown; census: 6 sites, 2 routines */
#define XBOW_XB_INT_LOWER                            0x000038 /* established */

/* xb_err_cmdword: rw32, reset unknown; census: 14 sites, 4 routines */
#define XBOW_XB_ERR_CMDWORD                          0x000040 /* established */

/* xb_llp_ctrl: r32, reset unknown; census: 3 sites, 1 routines */
#define XBOW_XB_LLP_CTRL                             0x000048 /* established */

/* xb_stat_clr: r32, reset unknown; census: 3 sites, 1 routines */
#define XBOW_XB_STAT_CLR                             0x000050 /* established */

/* xb_arb_reload: r32, reset unknown; census: 3 sites, 1 routines */
#define XBOW_XB_ARB_RELOAD                           0x000058 /* established */

/* reserved: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED                                0x000080 /* established */

/* reserved_88: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED_88                             0x000088 /* established */

/* reserved_90: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED_90                             0x000090 /* established */

/* reserved_98: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED_98                             0x000098 /* established */

/* reserved_a0: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED_A0                             0x0000a0 /* established */

/* reserved_a8: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED_A8                             0x0000a8 /* established */

/* reserved_b0: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED_B0                             0x0000b0 /* established */

/* reserved_b8: rw32, reset unknown; census: 2 sites, 1 routines */
#define XBOW_RESERVED_B8                             0x0000b8 /* established */

/* xb_link_ctrl: rw32, reset unknown; census: 9 sites, 1 routines */
#define XBOW_XB_LINK_CTRL                            0x000108 /* established */

/* xb_link_stat: r32, reset unknown; census: 3 sites, 3 routines */
#define XBOW_XB_LINK_STAT                            0x000110 /* established */

/* xb_link_arb_upper: rw32, reset unknown; census: 15 sites, 5 routines */
#define XBOW_XB_LINK_ARB_UPPER                       0x000118 /* established */

/* xb_link_arb_lower: rw32, reset unknown; census: 15 sites, 5 routines */
#define XBOW_XB_LINK_ARB_LOWER                       0x000120 /* established */

/* xb_link_stat_clr: r32, reset unknown; census: 3 sites, 1 routines */
#define XBOW_XB_LINK_STAT_CLR                        0x000128 /* established */

/* xb_link_reset: w32, reset unknown; census: 6 sites, 4 routines */
#define XBOW_XB_LINK_RESET                           0x000130 /* established */

/* xb_link_aux_stat: r32, reset unknown; census: 6 sites, 4 routines */
#define XBOW_XB_LINK_AUX_STAT                        0x000138 /* established */

/* xb_link_ctrl_148: rw32, reset unknown; census: 9 sites, 1 routines */
#define XBOW_XB_LINK_CTRL_148                        0x000148 /* established */

/* xb_link_stat_150: r32, reset unknown; census: 3 sites, 3 routines */
#define XBOW_XB_LINK_STAT_150                        0x000150 /* established */

/* xb_link_stat_clr_168: r32, reset unknown; census: 3 sites, 1 routines */
#define XBOW_XB_LINK_STAT_CLR_168                    0x000168 /* established */

/* xb_link_aux_stat_178: r32, reset unknown; census: 6 sites, 4 routines */
#define XBOW_XB_LINK_AUX_STAT_178                    0x000178 /* established */

/* xb_link_arb_upper_198: rw32, reset unknown; census: 4 sites, 1 routines */
#define XBOW_XB_LINK_ARB_UPPER_198                   0x000198 /* established */

/* xb_link_arb_upper_1d8: rw32, reset unknown; census: 4 sites, 1 routines */
#define XBOW_XB_LINK_ARB_UPPER_1D8                   0x0001d8 /* established */

#define XBOW_RESERVED_V_FF                           0xffu /* inferred */
#define XBOW_XB_CTRL_20_B_3_0                        0xfu /* inferred */
#define XBOW_XB_CTRL_20_B_7_0                        0xffu /* inferred */
#define XBOW_XB_CTRL_20_V_24                         0x24u /* inferred */
#define XBOW_XB_CTRL_20_V_80000000                   0x80000000u /* inferred */
#define XBOW_XB_CTRL_B_3_0                           0xfu /* inferred */
#define XBOW_XB_CTRL_B_7_0                           0xffu /* inferred */
#define XBOW_XB_CTRL_V_24                            0x24u /* inferred */
#define XBOW_XB_CTRL_V_80000000                      0x80000000u /* inferred */
#define XBOW_XB_ID_0_B_10_0                          0x7ffu /* inferred */
#define XBOW_XB_ID_0_B_15_0                          0xffffu /* inferred */
#define XBOW_XB_ID_0_B_2_0                           0x7u /* inferred */
#define XBOW_XB_ID_B_10_0                            0x7ffu /* inferred */
#define XBOW_XB_ID_B_15_0                            0xffffu /* inferred */
#define XBOW_XB_ID_B_2_0                             0x7u /* inferred */
#define XBOW_XB_INT_UPPER_B_15_0                     0xffffu /* inferred */
#define XBOW_XB_LINK_ARB_UPPER_1D8_V_9               0x9u /* inferred */
#define XBOW_XB_LINK_AUX_STAT_138_B_5                0x20u /* inferred */
#define XBOW_XB_LINK_AUX_STAT_138_B_7_0              0xffu /* inferred */
#define XBOW_XB_LINK_AUX_STAT_178_B_5                0x20u /* inferred */
#define XBOW_XB_LINK_AUX_STAT_B_5                    0x20u /* inferred */
#define XBOW_XB_LINK_AUX_STAT_B_7_0                  0xffu /* inferred */
#define XBOW_XB_LINK_CTRL_108_B_3                    0x8u /* inferred */
#define XBOW_XB_LINK_CTRL_108_V_80000                0x80000u /* inferred */
#define XBOW_XB_LINK_CTRL_148_B_3                    0x8u /* inferred */
#define XBOW_XB_LINK_CTRL_B_3                        0x8u /* inferred */
#define XBOW_XB_LINK_CTRL_V_80000                    0x80000u /* inferred */
#define XBOW_XB_STAT_8_B_5_2                         0x24u /* inferred */
#define XBOW_XB_STAT_8_B_9_6                         0x3c0u /* inferred */
#define XBOW_XB_STAT_B_5_2                           0x24u /* inferred */
#define XBOW_XB_STAT_B_9_6                           0x3c0u /* inferred */

#endif /* XBOW_GEN_H */
