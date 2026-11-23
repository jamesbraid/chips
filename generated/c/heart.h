/* generated from devices/heart/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 3 */
/* input sha256 ae368d15e21d51d42b2115a87fdc90eb6aebf0433a74724323058784d2a713ad */
/* HEART (Octane system controller) */
#ifndef HEART_GEN_H
#define HEART_GEN_H

#include <stdint.h>


/* mode: rw64, reset unknown; census: 78 sites, 34 routines */
#define HEART_MODE                                   0x000000 /* established */

/* mem_arb: rw64, reset unknown; census: 12 sites, 4 routines */
#define HEART_MEM_ARB                                0x000018 /* established */

/* memcfg0: rw64, reset unknown; census: 4 sites, 4 routines */
#define HEART_MEMCFG0                                0x000020 /* established */

/* memcfg1: rw64, reset unknown; census: 4 sites, 4 routines */
#define HEART_MEMCFG1                                0x000028 /* established */

/* memcfg2: r64, reset unknown; census: 2 sites, 2 routines */
#define HEART_MEMCFG2                                0x000030 /* established */

/* memcfg3: r64, reset unknown; census: 2 sites, 2 routines */
#define HEART_MEMCFG3                                0x000038 /* established */

/* fc_mode: rw64, reset unknown; census: 17 sites, 9 routines */
#define HEART_FC_MODE                                0x000040 /* established */

/* fc_limit: w64, reset unknown; census: 1 sites, 1 routines */
#define HEART_FC_LIMIT                               0x000048 /* established */

/* fc0_addr: w64, reset unknown; census: 2 sites, 2 routines */
#define HEART_FC0_ADDR                               0x000050 /* established */

/* fc0_count: rw64, reset unknown; census: 5 sites, 5 routines */
#define HEART_FC0_COUNT                              0x000060 /* established */

/* status: r64, reset unknown; census: 48 sites, 40 routines */
#define HEART_STATUS                                 0x000080 /* established */

/* berr_addr: r64, reset unknown; census: 9 sites, 7 routines */
#define HEART_BERR_ADDR                              0x000088 /* established */

/* berr_misc: r64, reset unknown; census: 10 sites, 8 routines */
#define HEART_BERR_MISC                              0x000090 /* established */

/* mem_err: r64, reset unknown; census: 14 sites, 12 routines */
#define HEART_MEM_ERR                                0x000098 /* established */

/* bad_mem: r64, reset unknown; census: 12 sites, 10 routines */
#define HEART_BAD_MEM                                0x0000a0 /* established */

/* piu_err: r64, reset unknown; census: 9 sites, 7 routines */
#define HEART_PIU_ERR                                0x0000a8 /* established */

/* imr0: w64, reset unknown; census: 3 sites, 3 routines */
#define HEART_IMR0                                   0x010000 /* established */

/* imr1: w64, reset unknown; census: 3 sites, 3 routines */
#define HEART_IMR1                                   0x010008 /* established */

/* imr2: w64, reset unknown; census: 3 sites, 3 routines */
#define HEART_IMR2                                   0x010010 /* established */

/* imr3: rw64, reset unknown; census: 9 sites, 5 routines */
#define HEART_IMR3                                   0x010018 /* established */

/* set_isr: w64, reset unknown; census: 7 sites, 6 routines */
#define HEART_SET_ISR                                0x010020 /* established */

/* clr_isr: w64, reset unknown; census: 21 sites, 20 routines */
#define HEART_CLR_ISR                                0x010028 /* established */

/* isr: r64, reset unknown; census: 27 sites, 17 routines */
#define HEART_ISR                                    0x010030 /* established */

/* imsr: r64, reset unknown; census: 13 sites, 10 routines */
#define HEART_IMSR                                   0x010038 /* established */

/* cause: rw64, reset unknown; census: 58 sites, 22 routines */
#define HEART_CAUSE                                  0x010040 /* established */

/* count: r64, reset unknown; census: 162 sites, 80 routines */
#define HEART_COUNT                                  0x020000 /* established */

/* trigger: w64, reset unknown; census: 4 sites, 2 routines */
#define HEART_TRIGGER                                0x040000 /* established */

/* prid: r64, reset unknown; census: 84 sites, 33 routines */
#define HEART_PRID                                   0x050000 /* established */

/* sync: r64, reset unknown; census: 6 sites, 1 routines */
#define HEART_SYNC                                   0x060000 /* established */

/* wid_id: r64, reset unknown; census: 28 sites, 21 routines */
#define HEART_WID_ID                                 0x100000 /* established */

/* wid_err_upper: r32, reset unknown; census: 3 sites, 3 routines */
#define HEART_WID_ERR_UPPER                          0x100010 /* established */

/* wid_err_lower: r32, reset unknown; census: 3 sites, 3 routines */
#define HEART_WID_ERR_LOWER                          0x100018 /* established */

/* wid_req_timeout: rw32, reset unknown; census: 4 sites, 2 routines */
#define HEART_WID_REQ_TIMEOUT                        0x100028 /* established */

/* wid_err_cmdword: rw64, reset unknown; census: 12 sites, 11 routines */
#define HEART_WID_ERR_CMDWORD                        0x100040 /* established */

/* wid_err_type: rw64, reset unknown; census: 20 sites, 11 routines */
#define HEART_WID_ERR_TYPE                           0x100060 /* established */

/* wid_err_mask: w64, reset unknown; census: 2 sites, 1 routines */
#define HEART_WID_ERR_MASK                           0x100068 /* established */

/* wid_pio_err_upper: r64, reset unknown; census: 3 sites, 3 routines */
#define HEART_WID_PIO_ERR_UPPER                      0x100070 /* established */

/* wid_pio_err_lower: r64, reset unknown; census: 3 sites, 3 routines */
#define HEART_WID_PIO_ERR_LOWER                      0x100078 /* established */

/* wid_pio_rto_addr: r64, reset unknown; census: 3 sites, 3 routines */
#define HEART_WID_PIO_RTO_ADDR                       0x100090 /* established */

#define HEART_CAUSE_B_0                              0x1u /* inferred */
#define HEART_CAUSE_B_1                              0x2u /* inferred */
#define HEART_CAUSE_B_1_0                            0x3u /* inferred */
#define HEART_CAUSE_V_1                              0x1u /* inferred */
#define HEART_COUNT_B_11_0                           0xfffu /* inferred */
#define HEART_FC_MODE_V_45                           0x45u /* inferred */
#define HEART_IMR3_V_1                               0x1u /* inferred */
#define HEART_MEM_ARB_V_100000                       0x100000u /* inferred */
#define HEART_MODE_B_3_0                             0xfu /* inferred */
#define HEART_MODE_V_200000                          0x200000u /* inferred */
#define HEART_MODE_V_400000                          0x400000u /* inferred */
#define HEART_STATUS_B_11                            0x800u /* inferred */
#define HEART_STATUS_B_3_0                           0xfu /* inferred */
#define HEART_STATUS_B_7_4                           0xf0u /* inferred */
#define HEART_WID_ERR_MASK_V_2C07                    0x2c07u /* inferred */
#define HEART_WID_ERR_MASK_V_3FF60000                0x3ff60000u /* inferred */
#define HEART_WID_REQ_TIMEOUT_V_80                   0x80u /* inferred */

/* hand-written helper macros */
#include "../../devices/heart/helpers.h"

#endif /* HEART_GEN_H */
