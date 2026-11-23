/* generated from devices/shub/registers.shub2.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 25a65e6adabd41724ca20aa7682efa4524185c9de88bf41c87116f7cdc9663a8 */
/* SHub 2 registers outside the I/O interface, differences from SHub 1 */
#ifndef SHUB2_GEN_H
#define SHUB2_GEN_H

#include <stdint.h>


/*
 * DIMM population word. One routine (0xff482c60) merges the discovered DIMM
 * layout into the old value: the preserved bits are 38 and above and bits 7,
 * 15, 23 and 31, so bits 37:32 are rewritten, and the same value is written to
 * all three registers (X, Y and JNR); bits 37:36 are then set by 0xff4856b0,
 * which reads the Y register first. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* x_dimm_cfg: rw64, reset unknown */
#define SHUB2_X_DIMM_CFG                             0x010000 /* established */
#define SHUB2_X_DIMM_CFG_CLK_EN_SHIFT                36 /* inferred */
#define SHUB2_X_DIMM_CFG_CLK_EN_MASK                 0x3ull
#define SHUB2_X_DIMM_CFG_CLK_EN_INPLACE (SHUB2_X_DIMM_CFG_CLK_EN_MASK << SHUB2_X_DIMM_CFG_CLK_EN_SHIFT)
#define SHUB2_X_DIMM_CFG_FREQ_SHIFT                  32 /* inferred */
#define SHUB2_X_DIMM_CFG_FREQ_MASK                   0xfull
#define SHUB2_X_DIMM_CFG_FREQ_INPLACE (SHUB2_X_DIMM_CFG_FREQ_MASK << SHUB2_X_DIMM_CFG_FREQ_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM3_CS_SHIFT              29 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM3_CS_MASK               0x3ull
#define SHUB2_X_DIMM_CFG_DIMM3_CS_INPLACE (SHUB2_X_DIMM_CFG_DIMM3_CS_MASK << SHUB2_X_DIMM_CFG_DIMM3_CS_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM3_REV_SHIFT             28 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM3_REV_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM3_REV_INPLACE (SHUB2_X_DIMM_CFG_DIMM3_REV_MASK << SHUB2_X_DIMM_CFG_DIMM3_REV_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM3_2BK_SHIFT             27 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM3_2BK_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM3_2BK_INPLACE (SHUB2_X_DIMM_CFG_DIMM3_2BK_MASK << SHUB2_X_DIMM_CFG_DIMM3_2BK_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM3_SIZE_SHIFT            24 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM3_SIZE_MASK             0x7ull
#define SHUB2_X_DIMM_CFG_DIMM3_SIZE_INPLACE (SHUB2_X_DIMM_CFG_DIMM3_SIZE_MASK << SHUB2_X_DIMM_CFG_DIMM3_SIZE_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM2_CS_SHIFT              21 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM2_CS_MASK               0x3ull
#define SHUB2_X_DIMM_CFG_DIMM2_CS_INPLACE (SHUB2_X_DIMM_CFG_DIMM2_CS_MASK << SHUB2_X_DIMM_CFG_DIMM2_CS_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM2_REV_SHIFT             20 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM2_REV_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM2_REV_INPLACE (SHUB2_X_DIMM_CFG_DIMM2_REV_MASK << SHUB2_X_DIMM_CFG_DIMM2_REV_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM2_2BK_SHIFT             19 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM2_2BK_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM2_2BK_INPLACE (SHUB2_X_DIMM_CFG_DIMM2_2BK_MASK << SHUB2_X_DIMM_CFG_DIMM2_2BK_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM2_SIZE_SHIFT            16 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM2_SIZE_MASK             0x7ull
#define SHUB2_X_DIMM_CFG_DIMM2_SIZE_INPLACE (SHUB2_X_DIMM_CFG_DIMM2_SIZE_MASK << SHUB2_X_DIMM_CFG_DIMM2_SIZE_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM1_CS_SHIFT              13 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM1_CS_MASK               0x3ull
#define SHUB2_X_DIMM_CFG_DIMM1_CS_INPLACE (SHUB2_X_DIMM_CFG_DIMM1_CS_MASK << SHUB2_X_DIMM_CFG_DIMM1_CS_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM1_REV_SHIFT             12 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM1_REV_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM1_REV_INPLACE (SHUB2_X_DIMM_CFG_DIMM1_REV_MASK << SHUB2_X_DIMM_CFG_DIMM1_REV_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM1_2BK_SHIFT             11 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM1_2BK_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM1_2BK_INPLACE (SHUB2_X_DIMM_CFG_DIMM1_2BK_MASK << SHUB2_X_DIMM_CFG_DIMM1_2BK_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM1_SIZE_SHIFT            8 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM1_SIZE_MASK             0x7ull
#define SHUB2_X_DIMM_CFG_DIMM1_SIZE_INPLACE (SHUB2_X_DIMM_CFG_DIMM1_SIZE_MASK << SHUB2_X_DIMM_CFG_DIMM1_SIZE_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM0_CS_SHIFT              5 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM0_CS_MASK               0x3ull
#define SHUB2_X_DIMM_CFG_DIMM0_CS_INPLACE (SHUB2_X_DIMM_CFG_DIMM0_CS_MASK << SHUB2_X_DIMM_CFG_DIMM0_CS_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM0_REV_SHIFT             4 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM0_REV_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM0_REV_INPLACE (SHUB2_X_DIMM_CFG_DIMM0_REV_MASK << SHUB2_X_DIMM_CFG_DIMM0_REV_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM0_2BK_SHIFT             3 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM0_2BK_MASK              0x1ull
#define SHUB2_X_DIMM_CFG_DIMM0_2BK_INPLACE (SHUB2_X_DIMM_CFG_DIMM0_2BK_MASK << SHUB2_X_DIMM_CFG_DIMM0_2BK_SHIFT)
#define SHUB2_X_DIMM_CFG_DIMM0_SIZE_SHIFT            0 /* inferred */
#define SHUB2_X_DIMM_CFG_DIMM0_SIZE_MASK             0x7ull
#define SHUB2_X_DIMM_CFG_DIMM0_SIZE_INPLACE (SHUB2_X_DIMM_CFG_DIMM0_SIZE_MASK << SHUB2_X_DIMM_CFG_DIMM0_SIZE_SHIFT)

/*
 * Same layout and value as X_DIMM_CFG. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* y_dimm_cfg: rw64, reset unknown */
#define SHUB2_Y_DIMM_CFG                             0x010008 /* established */
#define SHUB2_Y_DIMM_CFG_CLK_EN_SHIFT                36 /* inferred */
#define SHUB2_Y_DIMM_CFG_CLK_EN_MASK                 0x3ull
#define SHUB2_Y_DIMM_CFG_CLK_EN_INPLACE (SHUB2_Y_DIMM_CFG_CLK_EN_MASK << SHUB2_Y_DIMM_CFG_CLK_EN_SHIFT)
#define SHUB2_Y_DIMM_CFG_FREQ_SHIFT                  32 /* inferred */
#define SHUB2_Y_DIMM_CFG_FREQ_MASK                   0xfull
#define SHUB2_Y_DIMM_CFG_FREQ_INPLACE (SHUB2_Y_DIMM_CFG_FREQ_MASK << SHUB2_Y_DIMM_CFG_FREQ_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM3_CS_SHIFT              29 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM3_CS_MASK               0x3ull
#define SHUB2_Y_DIMM_CFG_DIMM3_CS_INPLACE (SHUB2_Y_DIMM_CFG_DIMM3_CS_MASK << SHUB2_Y_DIMM_CFG_DIMM3_CS_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM3_REV_SHIFT             28 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM3_REV_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM3_REV_INPLACE (SHUB2_Y_DIMM_CFG_DIMM3_REV_MASK << SHUB2_Y_DIMM_CFG_DIMM3_REV_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM3_2BK_SHIFT             27 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM3_2BK_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM3_2BK_INPLACE (SHUB2_Y_DIMM_CFG_DIMM3_2BK_MASK << SHUB2_Y_DIMM_CFG_DIMM3_2BK_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM3_SIZE_SHIFT            24 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM3_SIZE_MASK             0x7ull
#define SHUB2_Y_DIMM_CFG_DIMM3_SIZE_INPLACE (SHUB2_Y_DIMM_CFG_DIMM3_SIZE_MASK << SHUB2_Y_DIMM_CFG_DIMM3_SIZE_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM2_CS_SHIFT              21 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM2_CS_MASK               0x3ull
#define SHUB2_Y_DIMM_CFG_DIMM2_CS_INPLACE (SHUB2_Y_DIMM_CFG_DIMM2_CS_MASK << SHUB2_Y_DIMM_CFG_DIMM2_CS_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM2_REV_SHIFT             20 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM2_REV_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM2_REV_INPLACE (SHUB2_Y_DIMM_CFG_DIMM2_REV_MASK << SHUB2_Y_DIMM_CFG_DIMM2_REV_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM2_2BK_SHIFT             19 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM2_2BK_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM2_2BK_INPLACE (SHUB2_Y_DIMM_CFG_DIMM2_2BK_MASK << SHUB2_Y_DIMM_CFG_DIMM2_2BK_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM2_SIZE_SHIFT            16 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM2_SIZE_MASK             0x7ull
#define SHUB2_Y_DIMM_CFG_DIMM2_SIZE_INPLACE (SHUB2_Y_DIMM_CFG_DIMM2_SIZE_MASK << SHUB2_Y_DIMM_CFG_DIMM2_SIZE_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM1_CS_SHIFT              13 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM1_CS_MASK               0x3ull
#define SHUB2_Y_DIMM_CFG_DIMM1_CS_INPLACE (SHUB2_Y_DIMM_CFG_DIMM1_CS_MASK << SHUB2_Y_DIMM_CFG_DIMM1_CS_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM1_REV_SHIFT             12 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM1_REV_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM1_REV_INPLACE (SHUB2_Y_DIMM_CFG_DIMM1_REV_MASK << SHUB2_Y_DIMM_CFG_DIMM1_REV_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM1_2BK_SHIFT             11 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM1_2BK_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM1_2BK_INPLACE (SHUB2_Y_DIMM_CFG_DIMM1_2BK_MASK << SHUB2_Y_DIMM_CFG_DIMM1_2BK_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM1_SIZE_SHIFT            8 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM1_SIZE_MASK             0x7ull
#define SHUB2_Y_DIMM_CFG_DIMM1_SIZE_INPLACE (SHUB2_Y_DIMM_CFG_DIMM1_SIZE_MASK << SHUB2_Y_DIMM_CFG_DIMM1_SIZE_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM0_CS_SHIFT              5 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM0_CS_MASK               0x3ull
#define SHUB2_Y_DIMM_CFG_DIMM0_CS_INPLACE (SHUB2_Y_DIMM_CFG_DIMM0_CS_MASK << SHUB2_Y_DIMM_CFG_DIMM0_CS_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM0_REV_SHIFT             4 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM0_REV_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM0_REV_INPLACE (SHUB2_Y_DIMM_CFG_DIMM0_REV_MASK << SHUB2_Y_DIMM_CFG_DIMM0_REV_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM0_2BK_SHIFT             3 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM0_2BK_MASK              0x1ull
#define SHUB2_Y_DIMM_CFG_DIMM0_2BK_INPLACE (SHUB2_Y_DIMM_CFG_DIMM0_2BK_MASK << SHUB2_Y_DIMM_CFG_DIMM0_2BK_SHIFT)
#define SHUB2_Y_DIMM_CFG_DIMM0_SIZE_SHIFT            0 /* inferred */
#define SHUB2_Y_DIMM_CFG_DIMM0_SIZE_MASK             0x7ull
#define SHUB2_Y_DIMM_CFG_DIMM0_SIZE_INPLACE (SHUB2_Y_DIMM_CFG_DIMM0_SIZE_MASK << SHUB2_Y_DIMM_CFG_DIMM0_SIZE_SHIFT)

/*
 * Same layout and value as X_DIMM_CFG. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* jnr_dimm_cfg: rw64, reset unknown */
#define SHUB2_JNR_DIMM_CFG                           0x010010 /* established */
#define SHUB2_JNR_DIMM_CFG_CLK_EN_SHIFT              36 /* inferred */
#define SHUB2_JNR_DIMM_CFG_CLK_EN_MASK               0x3ull
#define SHUB2_JNR_DIMM_CFG_CLK_EN_INPLACE (SHUB2_JNR_DIMM_CFG_CLK_EN_MASK << SHUB2_JNR_DIMM_CFG_CLK_EN_SHIFT)
#define SHUB2_JNR_DIMM_CFG_FREQ_SHIFT                32 /* inferred */
#define SHUB2_JNR_DIMM_CFG_FREQ_MASK                 0xfull
#define SHUB2_JNR_DIMM_CFG_FREQ_INPLACE (SHUB2_JNR_DIMM_CFG_FREQ_MASK << SHUB2_JNR_DIMM_CFG_FREQ_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM3_CS_SHIFT            29 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM3_CS_MASK             0x3ull
#define SHUB2_JNR_DIMM_CFG_DIMM3_CS_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM3_CS_MASK << SHUB2_JNR_DIMM_CFG_DIMM3_CS_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM3_REV_SHIFT           28 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM3_REV_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM3_REV_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM3_REV_MASK << SHUB2_JNR_DIMM_CFG_DIMM3_REV_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM3_2BK_SHIFT           27 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM3_2BK_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM3_2BK_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM3_2BK_MASK << SHUB2_JNR_DIMM_CFG_DIMM3_2BK_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM3_SIZE_SHIFT          24 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM3_SIZE_MASK           0x7ull
#define SHUB2_JNR_DIMM_CFG_DIMM3_SIZE_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM3_SIZE_MASK << SHUB2_JNR_DIMM_CFG_DIMM3_SIZE_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM2_CS_SHIFT            21 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM2_CS_MASK             0x3ull
#define SHUB2_JNR_DIMM_CFG_DIMM2_CS_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM2_CS_MASK << SHUB2_JNR_DIMM_CFG_DIMM2_CS_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM2_REV_SHIFT           20 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM2_REV_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM2_REV_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM2_REV_MASK << SHUB2_JNR_DIMM_CFG_DIMM2_REV_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM2_2BK_SHIFT           19 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM2_2BK_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM2_2BK_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM2_2BK_MASK << SHUB2_JNR_DIMM_CFG_DIMM2_2BK_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM2_SIZE_SHIFT          16 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM2_SIZE_MASK           0x7ull
#define SHUB2_JNR_DIMM_CFG_DIMM2_SIZE_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM2_SIZE_MASK << SHUB2_JNR_DIMM_CFG_DIMM2_SIZE_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM1_CS_SHIFT            13 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM1_CS_MASK             0x3ull
#define SHUB2_JNR_DIMM_CFG_DIMM1_CS_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM1_CS_MASK << SHUB2_JNR_DIMM_CFG_DIMM1_CS_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM1_REV_SHIFT           12 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM1_REV_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM1_REV_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM1_REV_MASK << SHUB2_JNR_DIMM_CFG_DIMM1_REV_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM1_2BK_SHIFT           11 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM1_2BK_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM1_2BK_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM1_2BK_MASK << SHUB2_JNR_DIMM_CFG_DIMM1_2BK_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM1_SIZE_SHIFT          8 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM1_SIZE_MASK           0x7ull
#define SHUB2_JNR_DIMM_CFG_DIMM1_SIZE_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM1_SIZE_MASK << SHUB2_JNR_DIMM_CFG_DIMM1_SIZE_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM0_CS_SHIFT            5 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM0_CS_MASK             0x3ull
#define SHUB2_JNR_DIMM_CFG_DIMM0_CS_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM0_CS_MASK << SHUB2_JNR_DIMM_CFG_DIMM0_CS_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM0_REV_SHIFT           4 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM0_REV_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM0_REV_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM0_REV_MASK << SHUB2_JNR_DIMM_CFG_DIMM0_REV_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM0_2BK_SHIFT           3 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM0_2BK_MASK            0x1ull
#define SHUB2_JNR_DIMM_CFG_DIMM0_2BK_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM0_2BK_MASK << SHUB2_JNR_DIMM_CFG_DIMM0_2BK_SHIFT)
#define SHUB2_JNR_DIMM_CFG_DIMM0_SIZE_SHIFT          0 /* inferred */
#define SHUB2_JNR_DIMM_CFG_DIMM0_SIZE_MASK           0x7ull
#define SHUB2_JNR_DIMM_CFG_DIMM0_SIZE_INPLACE (SHUB2_JNR_DIMM_CFG_DIMM0_SIZE_MASK << SHUB2_JNR_DIMM_CFG_DIMM0_SIZE_SHIFT)

/*
 * On-die-termination configuration. Only the one field below is written by the
 * memory bring-up read; it is copied from the Y register. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux; no source defines the reset value.
 */
/* x_odt_cfg: rw64, reset unknown */
#define SHUB2_X_ODT_CFG                              0x010018 /* established */
#define SHUB2_X_ODT_CFG_BITS_23_20_SHIFT             20 /* inferred */
#define SHUB2_X_ODT_CFG_BITS_23_20_MASK              0xfull
#define SHUB2_X_ODT_CFG_BITS_23_20_INPLACE (SHUB2_X_ODT_CFG_BITS_23_20_MASK << SHUB2_X_ODT_CFG_BITS_23_20_SHIFT)

/*
 * Memory controller timing word. The firmware writes the same value to X and Y:
 * 0x4856_5320_3324_110e, built from the old Y value by clearing bit 0, setting
 * bit 1, depositing 3 at bits 7:2, replacing bits 39:8, depositing 3, 5, 6 at
 * bits 43:40, 47:44, 51:48, setting bits 52 and 54, clearing bit 53 (set
 * instead when the DIMM record's word at offset 8 equals 4), depositing 0x10 at
 * bit 55 (width 7) and setting bit 62 (sites 0xff483016 to 0xff4831a0). Only
 * bits 39:8 have a name here; the other positions are as written. Offset in the
 * local window (add 0x2_0000_0000); the name is the PROM's own register-name
 * table, not Linux; no source defines the reset value.
 */
/* x_cfg: rw64, reset unknown */
#define SHUB2_X_CFG                                  0x010020 /* established */
#define SHUB2_X_CFG_TA_DLYS_SHIFT                    8 /* inferred */
#define SHUB2_X_CFG_TA_DLYS_MASK                     0xffffffffull
#define SHUB2_X_CFG_TA_DLYS_INPLACE (SHUB2_X_CFG_TA_DLYS_MASK << SHUB2_X_CFG_TA_DLYS_SHIFT)
#define SHUB2_X_CFG_BIT_0_SHIFT                      0 /* inferred */
#define SHUB2_X_CFG_BIT_0_MASK                       0x1ull
#define SHUB2_X_CFG_BIT_0_INPLACE (SHUB2_X_CFG_BIT_0_MASK << SHUB2_X_CFG_BIT_0_SHIFT)

/*
 * Read and write select delays. The firmware keeps bits 63:25 and sets bits
 * 24:0 to 0x254215 (fields below). Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* x_dqct_cfg: rw64, reset unknown */
#define SHUB2_X_DQCT_CFG                             0x010028 /* established */
#define SHUB2_X_DQCT_CFG_BITS_24_20_SHIFT            20 /* inferred */
#define SHUB2_X_DQCT_CFG_BITS_24_20_MASK             0x1full
#define SHUB2_X_DQCT_CFG_BITS_24_20_INPLACE (SHUB2_X_DQCT_CFG_BITS_24_20_MASK << SHUB2_X_DQCT_CFG_BITS_24_20_SHIFT)
#define SHUB2_X_DQCT_CFG_BITS_19_16_SHIFT            16 /* inferred */
#define SHUB2_X_DQCT_CFG_BITS_19_16_MASK             0xfull
#define SHUB2_X_DQCT_CFG_BITS_19_16_INPLACE (SHUB2_X_DQCT_CFG_BITS_19_16_MASK << SHUB2_X_DQCT_CFG_BITS_19_16_SHIFT)
#define SHUB2_X_DQCT_CFG_BITS_15_12_SHIFT            12 /* inferred */
#define SHUB2_X_DQCT_CFG_BITS_15_12_MASK             0xfull
#define SHUB2_X_DQCT_CFG_BITS_15_12_INPLACE (SHUB2_X_DQCT_CFG_BITS_15_12_MASK << SHUB2_X_DQCT_CFG_BITS_15_12_SHIFT)
#define SHUB2_X_DQCT_CFG_BITS_11_8_SHIFT             8 /* inferred */
#define SHUB2_X_DQCT_CFG_BITS_11_8_MASK              0xfull
#define SHUB2_X_DQCT_CFG_BITS_11_8_INPLACE (SHUB2_X_DQCT_CFG_BITS_11_8_MASK << SHUB2_X_DQCT_CFG_BITS_11_8_SHIFT)
#define SHUB2_X_DQCT_CFG_BITS_7_4_SHIFT              4 /* inferred */
#define SHUB2_X_DQCT_CFG_BITS_7_4_MASK               0xfull
#define SHUB2_X_DQCT_CFG_BITS_7_4_INPLACE (SHUB2_X_DQCT_CFG_BITS_7_4_MASK << SHUB2_X_DQCT_CFG_BITS_7_4_SHIFT)
#define SHUB2_X_DQCT_CFG_BITS_3_0_SHIFT              0 /* inferred */
#define SHUB2_X_DQCT_CFG_BITS_3_0_MASK               0xfull
#define SHUB2_X_DQCT_CFG_BITS_3_0_INPLACE (SHUB2_X_DQCT_CFG_BITS_3_0_MASK << SHUB2_X_DQCT_CFG_BITS_3_0_SHIFT)

/*
 * Refresh control. The firmware reads the Y register, replaces bits 27:8 (and
 * clears bits 27:24 at site 0xff485d0c), merges the enable byte and writes the
 * result to both registers. Offset in the local window (add 0x2_0000_0000); the
 * name is the PROM's own register-name table, not Linux; no source defines the
 * reset value.
 */
/* x_refresh_control: rw64, reset unknown */
#define SHUB2_X_REFRESH_CONTROL                      0x010030 /* established */
#define SHUB2_X_REFRESH_CONTROL_HOLD_SHIFT           17 /* inferred */
#define SHUB2_X_REFRESH_CONTROL_HOLD_MASK            0x3full
#define SHUB2_X_REFRESH_CONTROL_HOLD_INPLACE (SHUB2_X_REFRESH_CONTROL_HOLD_MASK << SHUB2_X_REFRESH_CONTROL_HOLD_SHIFT)
#define SHUB2_X_REFRESH_CONTROL_INTERVAL_SHIFT       8 /* inferred */
#define SHUB2_X_REFRESH_CONTROL_INTERVAL_MASK        0x1ffull
#define SHUB2_X_REFRESH_CONTROL_INTERVAL_INPLACE (SHUB2_X_REFRESH_CONTROL_INTERVAL_MASK << SHUB2_X_REFRESH_CONTROL_INTERVAL_SHIFT)
#define SHUB2_X_REFRESH_CONTROL_ENABLE_SHIFT         0 /* inferred */
#define SHUB2_X_REFRESH_CONTROL_ENABLE_MASK          0xffull
#define SHUB2_X_REFRESH_CONTROL_ENABLE_INPLACE (SHUB2_X_REFRESH_CONTROL_ENABLE_MASK << SHUB2_X_REFRESH_CONTROL_ENABLE_SHIFT)

/*
 * Same layout as X_ODT_CFG. Offset in the local window (add 0x2_0000_0000); the
 * name is the PROM's own register-name table, not Linux; no source defines the
 * reset value.
 */
/* y_odt_cfg: rw64, reset unknown */
#define SHUB2_Y_ODT_CFG                              0x010048 /* established */
#define SHUB2_Y_ODT_CFG_BITS_23_20_SHIFT             20 /* inferred */
#define SHUB2_Y_ODT_CFG_BITS_23_20_MASK              0xfull
#define SHUB2_Y_ODT_CFG_BITS_23_20_INPLACE (SHUB2_Y_ODT_CFG_BITS_23_20_MASK << SHUB2_Y_ODT_CFG_BITS_23_20_SHIFT)

/*
 * Same layout as X_CFG. Offset in the local window (add 0x2_0000_0000); the
 * name is the PROM's own register-name table, not Linux; no source defines the
 * reset value.
 */
/* y_cfg: rw64, reset unknown */
#define SHUB2_Y_CFG                                  0x010050 /* established */
#define SHUB2_Y_CFG_TA_DLYS_SHIFT                    8 /* inferred */
#define SHUB2_Y_CFG_TA_DLYS_MASK                     0xffffffffull
#define SHUB2_Y_CFG_TA_DLYS_INPLACE (SHUB2_Y_CFG_TA_DLYS_MASK << SHUB2_Y_CFG_TA_DLYS_SHIFT)
#define SHUB2_Y_CFG_BIT_0_SHIFT                      0 /* inferred */
#define SHUB2_Y_CFG_BIT_0_MASK                       0x1ull
#define SHUB2_Y_CFG_BIT_0_INPLACE (SHUB2_Y_CFG_BIT_0_MASK << SHUB2_Y_CFG_BIT_0_SHIFT)

/*
 * Same layout and value as X_DQCT_CFG. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* y_dqct_cfg: rw64, reset unknown */
#define SHUB2_Y_DQCT_CFG                             0x010058 /* established */
#define SHUB2_Y_DQCT_CFG_BITS_24_20_SHIFT            20 /* inferred */
#define SHUB2_Y_DQCT_CFG_BITS_24_20_MASK             0x1full
#define SHUB2_Y_DQCT_CFG_BITS_24_20_INPLACE (SHUB2_Y_DQCT_CFG_BITS_24_20_MASK << SHUB2_Y_DQCT_CFG_BITS_24_20_SHIFT)
#define SHUB2_Y_DQCT_CFG_BITS_19_16_SHIFT            16 /* inferred */
#define SHUB2_Y_DQCT_CFG_BITS_19_16_MASK             0xfull
#define SHUB2_Y_DQCT_CFG_BITS_19_16_INPLACE (SHUB2_Y_DQCT_CFG_BITS_19_16_MASK << SHUB2_Y_DQCT_CFG_BITS_19_16_SHIFT)
#define SHUB2_Y_DQCT_CFG_BITS_15_12_SHIFT            12 /* inferred */
#define SHUB2_Y_DQCT_CFG_BITS_15_12_MASK             0xfull
#define SHUB2_Y_DQCT_CFG_BITS_15_12_INPLACE (SHUB2_Y_DQCT_CFG_BITS_15_12_MASK << SHUB2_Y_DQCT_CFG_BITS_15_12_SHIFT)
#define SHUB2_Y_DQCT_CFG_BITS_11_8_SHIFT             8 /* inferred */
#define SHUB2_Y_DQCT_CFG_BITS_11_8_MASK              0xfull
#define SHUB2_Y_DQCT_CFG_BITS_11_8_INPLACE (SHUB2_Y_DQCT_CFG_BITS_11_8_MASK << SHUB2_Y_DQCT_CFG_BITS_11_8_SHIFT)
#define SHUB2_Y_DQCT_CFG_BITS_7_4_SHIFT              4 /* inferred */
#define SHUB2_Y_DQCT_CFG_BITS_7_4_MASK               0xfull
#define SHUB2_Y_DQCT_CFG_BITS_7_4_INPLACE (SHUB2_Y_DQCT_CFG_BITS_7_4_MASK << SHUB2_Y_DQCT_CFG_BITS_7_4_SHIFT)
#define SHUB2_Y_DQCT_CFG_BITS_3_0_SHIFT              0 /* inferred */
#define SHUB2_Y_DQCT_CFG_BITS_3_0_MASK               0xfull
#define SHUB2_Y_DQCT_CFG_BITS_3_0_INPLACE (SHUB2_Y_DQCT_CFG_BITS_3_0_MASK << SHUB2_Y_DQCT_CFG_BITS_3_0_SHIFT)

/*
 * Same layout as X_REFRESH_CONTROL. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* y_refresh_control: rw64, reset unknown */
#define SHUB2_Y_REFRESH_CONTROL                      0x010060 /* established */
#define SHUB2_Y_REFRESH_CONTROL_HOLD_SHIFT           17 /* inferred */
#define SHUB2_Y_REFRESH_CONTROL_HOLD_MASK            0x3full
#define SHUB2_Y_REFRESH_CONTROL_HOLD_INPLACE (SHUB2_Y_REFRESH_CONTROL_HOLD_MASK << SHUB2_Y_REFRESH_CONTROL_HOLD_SHIFT)
#define SHUB2_Y_REFRESH_CONTROL_INTERVAL_SHIFT       8 /* inferred */
#define SHUB2_Y_REFRESH_CONTROL_INTERVAL_MASK        0x1ffull
#define SHUB2_Y_REFRESH_CONTROL_INTERVAL_INPLACE (SHUB2_Y_REFRESH_CONTROL_INTERVAL_MASK << SHUB2_Y_REFRESH_CONTROL_INTERVAL_SHIFT)
#define SHUB2_Y_REFRESH_CONTROL_ENABLE_SHIFT         0 /* inferred */
#define SHUB2_Y_REFRESH_CONTROL_ENABLE_MASK          0xffull
#define SHUB2_Y_REFRESH_CONTROL_ENABLE_INPLACE (SHUB2_Y_REFRESH_CONTROL_ENABLE_MASK << SHUB2_Y_REFRESH_CONTROL_ENABLE_SHIFT)

/*
 * Written once with 0x4e20_0400. The PROM name suggests two time fields (bits
 * 15:0 and 51:16); the code does not split the value. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux; no source defines the reset value.
 */
/* mem_red_black: w64, reset unknown */
#define SHUB2_MEM_RED_BLACK                          0x010078 /* established */

/*
 * Miscellaneous memory controller word. The firmware writes
 * 0x0fc4_0000_000c_4c4c once, then clears bit 58 when a masked size argument
 * exceeds 0x3ff and bit 59 when it exceeds 0x1ff (routine 0xff481280, sites
 * 0xff481696 and 0xff4816c6). Offset in the local window (add 0x2_0000_0000);
 * the name is the PROM's own register-name table, not Linux; no source defines
 * the reset value.
 */
/* misc_mem_cfg: rw64, reset unknown */
#define SHUB2_MISC_MEM_CFG                           0x010080 /* established */
#define SHUB2_MISC_MEM_CFG_BIT_59_SHIFT              59 /* inferred */
#define SHUB2_MISC_MEM_CFG_BIT_59_MASK               0x1ull
#define SHUB2_MISC_MEM_CFG_BIT_59_INPLACE (SHUB2_MISC_MEM_CFG_BIT_59_MASK << SHUB2_MISC_MEM_CFG_BIT_59_SHIFT)
#define SHUB2_MISC_MEM_CFG_BIT_58_SHIFT              58 /* inferred */
#define SHUB2_MISC_MEM_CFG_BIT_58_MASK               0x1ull
#define SHUB2_MISC_MEM_CFG_BIT_58_INPLACE (SHUB2_MISC_MEM_CFG_BIT_58_MASK << SHUB2_MISC_MEM_CFG_BIT_58_SHIFT)

/*
 * PIO request credit control. The first-stage firmware writes 2; the node
 * set-up table writes 0xf9_0000_0000 to register 0xd8, a different register.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* pio_rq_crd_ctl: rw64, reset unknown */
#define SHUB2_PIO_RQ_CRD_CTL                         0x0100d8 /* established */

/*
 * Credit depth register; the firmware writes 0xc. The PROM name gives a 6-bit
 * depth field. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux; no source defines the reset value.
 */
/* pi_md_rq_crd_ctl: w64, reset unknown */
#define SHUB2_PI_MD_RQ_CRD_CTL                       0x0100e0 /* established */

/*
 * Credit depth register; the firmware writes 0x4. The PROM name gives a 6-bit
 * depth field. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux; no source defines the reset value.
 */
/* pi_md_rp_crd_ctl: w64, reset unknown */
#define SHUB2_PI_MD_RP_CRD_CTL                       0x0100e8 /* established */

/*
 * Credit depth register; the firmware writes 0xb. The PROM name gives a 6-bit
 * depth field. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux; no source defines the reset value.
 */
/* xn_md_rq_crd_ctl: w64, reset unknown */
#define SHUB2_XN_MD_RQ_CRD_CTL                       0x0100f0 /* established */

/*
 * Credit depth register; the firmware writes 0x3. The PROM name gives a 6-bit
 * depth field. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux; no source defines the reset value.
 */
/* xn_md_rp_crd_ctl: w64, reset unknown */
#define SHUB2_XN_MD_RP_CRD_CTL                       0x0100f8 /* established */

/*
 * Start address of a memory test block. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* mmrbist_base: w64, reset unknown */
#define SHUB2_MMRBIST_BASE                           0x020080 /* established */

/*
 * Memory test control: the early path writes 0x11_0000_0010 and polls bit 40
 * clear (for up to 2,000,000 microseconds). The other fields of the PROM name
 * are not read in code here. Offset in the local window (add 0x2_0000_0000);
 * the name is the PROM's own register-name table, not Linux; no source defines
 * the reset value.
 */
/* mmrbist_ctl: rw64, reset unknown */
#define SHUB2_MMRBIST_CTL                            0x020088 /* established */
#define SHUB2_MMRBIST_CTL_IN_PROGRESS_SHIFT          40 /* inferred */
#define SHUB2_MMRBIST_CTL_IN_PROGRESS_MASK           0x1ull
#define SHUB2_MMRBIST_CTL_IN_PROGRESS_INPLACE (SHUB2_MMRBIST_CTL_IN_PROGRESS_MASK << SHUB2_MMRBIST_CTL_IN_PROGRESS_SHIFT)

/*
 * Directory configuration. The firmware reads it and merges: bits 2:0 from the
 * node count, clears bits 11 and 10 by size tests, sets bit 3 and bit 15. The
 * DQRP twin, 0x5_0000, receives the same value. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* dir_config_dqlp: rw64, reset unknown */
#define SHUB2_DIR_CONFIG_DQLP                        0x030000 /* established */
#define SHUB2_DIR_CONFIG_DQLP_BIT_15_SHIFT           15 /* inferred */
#define SHUB2_DIR_CONFIG_DQLP_BIT_15_MASK            0x1ull
#define SHUB2_DIR_CONFIG_DQLP_BIT_15_INPLACE (SHUB2_DIR_CONFIG_DQLP_BIT_15_MASK << SHUB2_DIR_CONFIG_DQLP_BIT_15_SHIFT)
#define SHUB2_DIR_CONFIG_DQLP_BIT_11_SHIFT           11 /* inferred */
#define SHUB2_DIR_CONFIG_DQLP_BIT_11_MASK            0x1ull
#define SHUB2_DIR_CONFIG_DQLP_BIT_11_INPLACE (SHUB2_DIR_CONFIG_DQLP_BIT_11_MASK << SHUB2_DIR_CONFIG_DQLP_BIT_11_SHIFT)
#define SHUB2_DIR_CONFIG_DQLP_BIT_10_SHIFT           10 /* inferred */
#define SHUB2_DIR_CONFIG_DQLP_BIT_10_MASK            0x1ull
#define SHUB2_DIR_CONFIG_DQLP_BIT_10_INPLACE (SHUB2_DIR_CONFIG_DQLP_BIT_10_MASK << SHUB2_DIR_CONFIG_DQLP_BIT_10_SHIFT)
#define SHUB2_DIR_CONFIG_DQLP_BIT_3_SHIFT            3 /* inferred */
#define SHUB2_DIR_CONFIG_DQLP_BIT_3_MASK             0x1ull
#define SHUB2_DIR_CONFIG_DQLP_BIT_3_INPLACE (SHUB2_DIR_CONFIG_DQLP_BIT_3_MASK << SHUB2_DIR_CONFIG_DQLP_BIT_3_SHIFT)
#define SHUB2_DIR_CONFIG_DQLP_SYS_SIZE_SHIFT         0 /* inferred */
#define SHUB2_DIR_CONFIG_DQLP_SYS_SIZE_MASK          0x7ull
#define SHUB2_DIR_CONFIG_DQLP_SYS_SIZE_INPLACE (SHUB2_DIR_CONFIG_DQLP_SYS_SIZE_MASK << SHUB2_DIR_CONFIG_DQLP_SYS_SIZE_SHIFT)

/*
 * Eight local-vector registers 0x10 apart, all set to ones at initialisation.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value.
 */
/* dir_locvec_dqlp: w64, reset unknown */
#define SHUB2_DIR_LOCVEC_DQLP                        0x030200 /* established */
#define SHUB2_DIR_LOCVEC_DQLP_COUNT                  8
#define SHUB2_DIR_LOCVEC_DQLP_STRIDE                 16

/*
 * Eight registers 0x10 apart written with constants in order: 0x4bfff,
 * 0xc96f25b, 0xfffffff, 0x96ffff, 0, 0, 0x4803f, 0x48000. Not all ones, so the
 * writes do not simply open access to every node; the field layout is not read.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value.
 */
/* dir_privec_dqlp: w64, reset unknown */
#define SHUB2_DIR_PRIVEC_DQLP                        0x030300 /* established */
#define SHUB2_DIR_PRIVEC_DQLP_COUNT                  8
#define SHUB2_DIR_PRIVEC_DQLP_STRIDE                 16

/*
 * Written once with 0x1000 (bit 12). Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* dir_timer_dqlp: w64, reset unknown */
#define SHUB2_DIR_TIMER_DQLP                         0x030400 /* established */

/*
 * AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in
 * the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value.
 */
/* amo_cfg_0: rw64, reset unknown */
#define SHUB2_AMO_CFG_0                              0x034800 /* established */
#define SHUB2_AMO_CFG_0_BITS_3_2_SHIFT               2 /* inferred */
#define SHUB2_AMO_CFG_0_BITS_3_2_MASK                0x3ull
#define SHUB2_AMO_CFG_0_BITS_3_2_INPLACE (SHUB2_AMO_CFG_0_BITS_3_2_MASK << SHUB2_AMO_CFG_0_BITS_3_2_SHIFT)

/*
 * Memory test pattern register, high half; written with the arm bit. Offset in
 * the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value. Four ports
 * 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).
 */
/* x_bist_h: w64, reset unknown */
#define SHUB2_X_BIST_H                               0x038000 /* established */
#define SHUB2_X_BIST_H_COUNT                         4
#define SHUB2_X_BIST_H_STRIDE                        65536
#define SHUB2_X_BIST_H_ARM_SHIFT                     43 /* inferred */
#define SHUB2_X_BIST_H_ARM_MASK                      0x1ull
#define SHUB2_X_BIST_H_ARM_INPLACE (SHUB2_X_BIST_H_ARM_MASK << SHUB2_X_BIST_H_ARM_SHIFT)
#define SHUB2_X_BIST_H_BIT_41_SHIFT                  41 /* inferred */
#define SHUB2_X_BIST_H_BIT_41_MASK                   0x1ull
#define SHUB2_X_BIST_H_BIT_41_INPLACE (SHUB2_X_BIST_H_BIT_41_MASK << SHUB2_X_BIST_H_BIT_41_SHIFT)
#define SHUB2_X_BIST_H_BIT_40_SHIFT                  40 /* inferred */
#define SHUB2_X_BIST_H_BIT_40_MASK                   0x1ull
#define SHUB2_X_BIST_H_BIT_40_INPLACE (SHUB2_X_BIST_H_BIT_40_MASK << SHUB2_X_BIST_H_BIT_40_SHIFT)
#define SHUB2_X_BIST_H_PATTERN_SHIFT                 0 /* inferred */
#define SHUB2_X_BIST_H_PATTERN_MASK                  0xffffffffffull
#define SHUB2_X_BIST_H_PATTERN_INPLACE (SHUB2_X_BIST_H_PATTERN_MASK << SHUB2_X_BIST_H_PATTERN_SHIFT)

/*
 * Memory test pattern register, low half; same value without the arm bit.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value. Four ports
 * 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).
 */
/* x_bist_l: w64, reset unknown */
#define SHUB2_X_BIST_L                               0x038010 /* established */
#define SHUB2_X_BIST_L_COUNT                         4
#define SHUB2_X_BIST_L_STRIDE                        65536
#define SHUB2_X_BIST_L_BIT_41_SHIFT                  41 /* inferred */
#define SHUB2_X_BIST_L_BIT_41_MASK                   0x1ull
#define SHUB2_X_BIST_L_BIT_41_INPLACE (SHUB2_X_BIST_L_BIT_41_MASK << SHUB2_X_BIST_L_BIT_41_SHIFT)
#define SHUB2_X_BIST_L_BIT_40_SHIFT                  40 /* inferred */
#define SHUB2_X_BIST_L_BIT_40_MASK                   0x1ull
#define SHUB2_X_BIST_L_BIT_40_INPLACE (SHUB2_X_BIST_L_BIT_40_MASK << SHUB2_X_BIST_L_BIT_40_SHIFT)
#define SHUB2_X_BIST_L_PATTERN_SHIFT                 0 /* inferred */
#define SHUB2_X_BIST_L_PATTERN_MASK                  0xffffffffffull
#define SHUB2_X_BIST_L_PATTERN_INPLACE (SHUB2_X_BIST_L_PATTERN_MASK << SHUB2_X_BIST_L_PATTERN_SHIFT)

/*
 * Memory test error register, high half, read after a failure; reads 0 on a
 * pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's
 * own register-name table, not Linux; no source defines the reset value. Four
 * ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).
 */
/* x_bist_err_h: r64, reset unknown */
#define SHUB2_X_BIST_ERR_H                           0x038020 /* established */
#define SHUB2_X_BIST_ERR_H_COUNT                     4
#define SHUB2_X_BIST_ERR_H_STRIDE                    65536
#define SHUB2_X_BIST_ERR_H_VAL_SHIFT                 40 /* inferred */
#define SHUB2_X_BIST_ERR_H_VAL_MASK                  0x1ull
#define SHUB2_X_BIST_ERR_H_VAL_INPLACE (SHUB2_X_BIST_ERR_H_VAL_MASK << SHUB2_X_BIST_ERR_H_VAL_SHIFT)
#define SHUB2_X_BIST_ERR_H_PAT_SHIFT                 0 /* inferred */
#define SHUB2_X_BIST_ERR_H_PAT_MASK                  0xffffffffffull
#define SHUB2_X_BIST_ERR_H_PAT_INPLACE (SHUB2_X_BIST_ERR_H_PAT_MASK << SHUB2_X_BIST_ERR_H_PAT_SHIFT)

/*
 * Memory test error register, low half, read after a failure; reads 0 on a
 * pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's
 * own register-name table, not Linux; no source defines the reset value. Four
 * ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).
 */
/* x_bist_err_l: r64, reset unknown */
#define SHUB2_X_BIST_ERR_L                           0x038030 /* established */
#define SHUB2_X_BIST_ERR_L_COUNT                     4
#define SHUB2_X_BIST_ERR_L_STRIDE                    65536
#define SHUB2_X_BIST_ERR_L_VAL_SHIFT                 40 /* inferred */
#define SHUB2_X_BIST_ERR_L_VAL_MASK                  0x1ull
#define SHUB2_X_BIST_ERR_L_VAL_INPLACE (SHUB2_X_BIST_ERR_L_VAL_MASK << SHUB2_X_BIST_ERR_L_VAL_SHIFT)
#define SHUB2_X_BIST_ERR_L_PAT_SHIFT                 0 /* inferred */
#define SHUB2_X_BIST_ERR_L_PAT_MASK                  0xffffffffffull
#define SHUB2_X_BIST_ERR_L_PAT_INPLACE (SHUB2_X_BIST_ERR_L_PAT_MASK << SHUB2_X_BIST_ERR_L_PAT_SHIFT)

/*
 * Y-side twin of X_BIST_H. Offset in the local window (add 0x2_0000_0000); the
 * name is the PROM's own register-name table, not Linux; no source defines the
 * reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx,
 * 0x6_8xxx).
 */
/* y_bist_h: w64, reset unknown */
#define SHUB2_Y_BIST_H                               0x038800 /* established */
#define SHUB2_Y_BIST_H_COUNT                         4
#define SHUB2_Y_BIST_H_STRIDE                        65536
#define SHUB2_Y_BIST_H_ARM_SHIFT                     43 /* inferred */
#define SHUB2_Y_BIST_H_ARM_MASK                      0x1ull
#define SHUB2_Y_BIST_H_ARM_INPLACE (SHUB2_Y_BIST_H_ARM_MASK << SHUB2_Y_BIST_H_ARM_SHIFT)
#define SHUB2_Y_BIST_H_BIT_41_SHIFT                  41 /* inferred */
#define SHUB2_Y_BIST_H_BIT_41_MASK                   0x1ull
#define SHUB2_Y_BIST_H_BIT_41_INPLACE (SHUB2_Y_BIST_H_BIT_41_MASK << SHUB2_Y_BIST_H_BIT_41_SHIFT)
#define SHUB2_Y_BIST_H_BIT_40_SHIFT                  40 /* inferred */
#define SHUB2_Y_BIST_H_BIT_40_MASK                   0x1ull
#define SHUB2_Y_BIST_H_BIT_40_INPLACE (SHUB2_Y_BIST_H_BIT_40_MASK << SHUB2_Y_BIST_H_BIT_40_SHIFT)
#define SHUB2_Y_BIST_H_PATTERN_SHIFT                 0 /* inferred */
#define SHUB2_Y_BIST_H_PATTERN_MASK                  0xffffffffffull
#define SHUB2_Y_BIST_H_PATTERN_INPLACE (SHUB2_Y_BIST_H_PATTERN_MASK << SHUB2_Y_BIST_H_PATTERN_SHIFT)

/*
 * Y-side twin of X_BIST_L. Offset in the local window (add 0x2_0000_0000); the
 * name is the PROM's own register-name table, not Linux; no source defines the
 * reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx,
 * 0x6_8xxx).
 */
/* y_bist_l: w64, reset unknown */
#define SHUB2_Y_BIST_L                               0x038810 /* established */
#define SHUB2_Y_BIST_L_COUNT                         4
#define SHUB2_Y_BIST_L_STRIDE                        65536
#define SHUB2_Y_BIST_L_BIT_41_SHIFT                  41 /* inferred */
#define SHUB2_Y_BIST_L_BIT_41_MASK                   0x1ull
#define SHUB2_Y_BIST_L_BIT_41_INPLACE (SHUB2_Y_BIST_L_BIT_41_MASK << SHUB2_Y_BIST_L_BIT_41_SHIFT)
#define SHUB2_Y_BIST_L_BIT_40_SHIFT                  40 /* inferred */
#define SHUB2_Y_BIST_L_BIT_40_MASK                   0x1ull
#define SHUB2_Y_BIST_L_BIT_40_INPLACE (SHUB2_Y_BIST_L_BIT_40_MASK << SHUB2_Y_BIST_L_BIT_40_SHIFT)
#define SHUB2_Y_BIST_L_PATTERN_SHIFT                 0 /* inferred */
#define SHUB2_Y_BIST_L_PATTERN_MASK                  0xffffffffffull
#define SHUB2_Y_BIST_L_PATTERN_INPLACE (SHUB2_Y_BIST_L_PATTERN_MASK << SHUB2_Y_BIST_L_PATTERN_SHIFT)

/*
 * Memory test error register, high half, read after a failure; reads 0 on a
 * pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's
 * own register-name table, not Linux; no source defines the reset value. Four
 * ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).
 */
/* y_bist_err_h: r64, reset unknown */
#define SHUB2_Y_BIST_ERR_H                           0x038820 /* established */
#define SHUB2_Y_BIST_ERR_H_COUNT                     4
#define SHUB2_Y_BIST_ERR_H_STRIDE                    65536
#define SHUB2_Y_BIST_ERR_H_VAL_SHIFT                 40 /* inferred */
#define SHUB2_Y_BIST_ERR_H_VAL_MASK                  0x1ull
#define SHUB2_Y_BIST_ERR_H_VAL_INPLACE (SHUB2_Y_BIST_ERR_H_VAL_MASK << SHUB2_Y_BIST_ERR_H_VAL_SHIFT)
#define SHUB2_Y_BIST_ERR_H_PAT_SHIFT                 0 /* inferred */
#define SHUB2_Y_BIST_ERR_H_PAT_MASK                  0xffffffffffull
#define SHUB2_Y_BIST_ERR_H_PAT_INPLACE (SHUB2_Y_BIST_ERR_H_PAT_MASK << SHUB2_Y_BIST_ERR_H_PAT_SHIFT)

/*
 * Memory test error register, low half, read after a failure; reads 0 on a
 * pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's
 * own register-name table, not Linux; no source defines the reset value. Four
 * ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).
 */
/* y_bist_err_l: r64, reset unknown */
#define SHUB2_Y_BIST_ERR_L                           0x038830 /* established */
#define SHUB2_Y_BIST_ERR_L_COUNT                     4
#define SHUB2_Y_BIST_ERR_L_STRIDE                    65536
#define SHUB2_Y_BIST_ERR_L_VAL_SHIFT                 40 /* inferred */
#define SHUB2_Y_BIST_ERR_L_VAL_MASK                  0x1ull
#define SHUB2_Y_BIST_ERR_L_VAL_INPLACE (SHUB2_Y_BIST_ERR_L_VAL_MASK << SHUB2_Y_BIST_ERR_L_VAL_SHIFT)
#define SHUB2_Y_BIST_ERR_L_PAT_SHIFT                 0 /* inferred */
#define SHUB2_Y_BIST_ERR_L_PAT_MASK                  0xffffffffffull
#define SHUB2_Y_BIST_ERR_L_PAT_INPLACE (SHUB2_Y_BIST_ERR_L_PAT_MASK << SHUB2_Y_BIST_ERR_L_PAT_SHIFT)

/*
 * AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in
 * the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value.
 */
/* amo_cfg_1: rw64, reset unknown */
#define SHUB2_AMO_CFG_1                              0x04b000 /* established */
#define SHUB2_AMO_CFG_1_BITS_3_2_SHIFT               2 /* inferred */
#define SHUB2_AMO_CFG_1_BITS_3_2_MASK                0x3ull
#define SHUB2_AMO_CFG_1_BITS_3_2_INPLACE (SHUB2_AMO_CFG_1_BITS_3_2_MASK << SHUB2_AMO_CFG_1_BITS_3_2_SHIFT)

/*
 * Twin of DIR_CONFIG_DQLP; the firmware writes the same value. Offset in the
 * local window (add 0x2_0000_0000); the name is the PROM's own register-name
 * table, not Linux; no source defines the reset value.
 */
/* dir_config_dqrp: rw64, reset unknown */
#define SHUB2_DIR_CONFIG_DQRP                        0x050000 /* established */

/*
 * Eight registers 0x10 apart, all set to ones. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* dir_locvec_dqrp: w64, reset unknown */
#define SHUB2_DIR_LOCVEC_DQRP                        0x050200 /* established */
#define SHUB2_DIR_LOCVEC_DQRP_COUNT                  8
#define SHUB2_DIR_LOCVEC_DQRP_STRIDE                 16

/*
 * Twin of DIR_PRIVEC_DQLP, same values. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no
 * source defines the reset value.
 */
/* dir_privec_dqrp: w64, reset unknown */
#define SHUB2_DIR_PRIVEC_DQRP                        0x050300 /* established */
#define SHUB2_DIR_PRIVEC_DQRP_COUNT                  8
#define SHUB2_DIR_PRIVEC_DQRP_STRIDE                 16

/*
 * Twin of DIR_TIMER_DQLP. Offset in the local window (add 0x2_0000_0000); the
 * name is the PROM's own register-name table, not Linux; no source defines the
 * reset value.
 */
/* dir_timer_dqrp: w64, reset unknown */
#define SHUB2_DIR_TIMER_DQRP                         0x050400 /* established */

/*
 * AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in
 * the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value.
 */
/* amo_cfg_2: rw64, reset unknown */
#define SHUB2_AMO_CFG_2                              0x054800 /* established */
#define SHUB2_AMO_CFG_2_BITS_3_2_SHIFT               2 /* inferred */
#define SHUB2_AMO_CFG_2_BITS_3_2_MASK                0x3ull
#define SHUB2_AMO_CFG_2_BITS_3_2_INPLACE (SHUB2_AMO_CFG_2_BITS_3_2_MASK << SHUB2_AMO_CFG_2_BITS_3_2_SHIFT)

/*
 * AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in
 * the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux; no source defines the reset value.
 */
/* amo_cfg_3: rw64, reset unknown */
#define SHUB2_AMO_CFG_3                              0x06b000 /* established */
#define SHUB2_AMO_CFG_3_BITS_3_2_SHIFT               2 /* inferred */
#define SHUB2_AMO_CFG_3_BITS_3_2_MASK                0x3ull
#define SHUB2_AMO_CFG_3_BITS_3_2_INPLACE (SHUB2_AMO_CFG_3_BITS_3_2_MASK << SHUB2_AMO_CFG_3_BITS_3_2_SHIFT)

/*
 * Send an interprocessor interrupt (processor interface or local block,
 * inferred). The sender writes this register in the target node's global MMR
 * window with send set, the target's physical processor id, a delivery type, a
 * vector and a fixed base. The kernel stores through uncached physical mode
 * with release ordering, after a memory barrier. On a SHub 1 revision 2 or
 * lower it holds a global lock around the store and waits for the PIO write
 * status to drain.
 */
/* ipi_int: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL):
 * name and offset */
/* established */
#define SHUB2_IPI_INT                                0x10000380
#define SHUB2_IPI_INT_SEND_SHIFT                     63 /* established */
#define SHUB2_IPI_INT_SEND_MASK                      0x1ull
#define SHUB2_IPI_INT_SEND_INPLACE (SHUB2_IPI_INT_SEND_MASK << SHUB2_IPI_INT_SEND_SHIFT)
#define SHUB2_IPI_INT_IDX_SHIFT                      52 /* established */
#define SHUB2_IPI_INT_IDX_MASK                       0xffull
#define SHUB2_IPI_INT_IDX_INPLACE (SHUB2_IPI_INT_IDX_MASK << SHUB2_IPI_INT_IDX_SHIFT)
#define SHUB2_IPI_INT_BASE_SHIFT                     21 /* established */
#define SHUB2_IPI_INT_BASE_MASK                      0x1fffffffull
#define SHUB2_IPI_INT_BASE_INPLACE (SHUB2_IPI_INT_BASE_MASK << SHUB2_IPI_INT_BASE_SHIFT)
#define SHUB2_IPI_INT_PID_SHIFT                      4 /* established */
#define SHUB2_IPI_INT_PID_MASK                       0xffffull
#define SHUB2_IPI_INT_PID_INPLACE (SHUB2_IPI_INT_PID_MASK << SHUB2_IPI_INT_PID_SHIFT)
#define SHUB2_IPI_INT_AGENT_SHIFT                    3 /* established */
#define SHUB2_IPI_INT_AGENT_MASK                     0x1ull
#define SHUB2_IPI_INT_AGENT_INPLACE (SHUB2_IPI_INT_AGENT_MASK << SHUB2_IPI_INT_AGENT_SHIFT)
#define SHUB2_IPI_INT_TYPE_SHIFT                     0 /* established */
#define SHUB2_IPI_INT_TYPE_MASK                      0x7ull
#define SHUB2_IPI_INT_TYPE_INPLACE (SHUB2_IPI_INT_TYPE_MASK << SHUB2_IPI_INT_TYPE_SHIFT)

/*
 * Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target
 * processor id, vector area and vector. The mmtimer driver writes the vector
 * and processor id fields and leaves type, agent and base zero. The register
 * has the same layout as the IPI message, without the send bit. A fourth
 * comparator (RTC 0) exists; the driver comment says firmware uses it, and the
 * header defines nothing for it.
 */
/* rtc_int_config: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_RTC_INT_CONFIG                         0x10001480
#define SHUB2_RTC_INT_CONFIG_COUNT                   3
#define SHUB2_RTC_INT_CONFIG_STRIDE                  256
#define SHUB2_RTC_INT_CONFIG_IDX_SHIFT               52 /* established */
#define SHUB2_RTC_INT_CONFIG_IDX_MASK                0xffull
#define SHUB2_RTC_INT_CONFIG_IDX_INPLACE (SHUB2_RTC_INT_CONFIG_IDX_MASK << SHUB2_RTC_INT_CONFIG_IDX_SHIFT)
#define SHUB2_RTC_INT_CONFIG_BASE_SHIFT              21 /* established */
#define SHUB2_RTC_INT_CONFIG_BASE_MASK               0x1fffffffull
#define SHUB2_RTC_INT_CONFIG_BASE_INPLACE (SHUB2_RTC_INT_CONFIG_BASE_MASK << SHUB2_RTC_INT_CONFIG_BASE_SHIFT)
#define SHUB2_RTC_INT_CONFIG_PID_SHIFT               4 /* established */
#define SHUB2_RTC_INT_CONFIG_PID_MASK                0xffffull
#define SHUB2_RTC_INT_CONFIG_PID_INPLACE (SHUB2_RTC_INT_CONFIG_PID_MASK << SHUB2_RTC_INT_CONFIG_PID_SHIFT)
#define SHUB2_RTC_INT_CONFIG_AGENT_SHIFT             3 /* established */
#define SHUB2_RTC_INT_CONFIG_AGENT_MASK              0x1ull
#define SHUB2_RTC_INT_CONFIG_AGENT_INPLACE (SHUB2_RTC_INT_CONFIG_AGENT_MASK << SHUB2_RTC_INT_CONFIG_AGENT_SHIFT)
#define SHUB2_RTC_INT_CONFIG_TYPE_SHIFT              0 /* established */
#define SHUB2_RTC_INT_CONFIG_TYPE_MASK               0x7ull
#define SHUB2_RTC_INT_CONFIG_TYPE_INPLACE (SHUB2_RTC_INT_CONFIG_TYPE_MASK << SHUB2_RTC_INT_CONFIG_TYPE_SHIFT)

/*
 * Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver
 * disables it, sets the comparator to all ones, clears the pending bit, writes
 * the configuration, enables, and only then writes the real expiry, in that
 * order.
 */
/* rtc_int_enable: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_RTC_INT_ENABLE                         0x10001500
#define SHUB2_RTC_INT_ENABLE_COUNT                   3
#define SHUB2_RTC_INT_ENABLE_STRIDE                  256
#define SHUB2_RTC_INT_ENABLE_ENABLE_SHIFT            0 /* established */
#define SHUB2_RTC_INT_ENABLE_ENABLE_MASK             0x1ull
#define SHUB2_RTC_INT_ENABLE_ENABLE_INPLACE (SHUB2_RTC_INT_ENABLE_ENABLE_MASK << SHUB2_RTC_INT_ENABLE_ENABLE_SHIFT)

/*
 * Pending interrupt events for the node (SHub interrupt event occurred). The
 * kernel's interrupt acknowledge reads it, keeps the bits in the mask of the
 * junk-bus UART, IPI and the two II interrupts, and writes that value to the
 * alias to clear them; Linux only reads it. Bits the header names are
 * established. SAL 5.04 reads it for the error bits (mask 0x7ef, sites
 * 0xffa239a0 and 0xffa23fd6) and for bit 21 (site 0xffa31506), and writes bits
 * 5 and 8 to this register itself (sites 0xffa32816 and 0xffa32996); a model
 * should OR written bits in (inferred). Zero from reset is tolerated; the reset
 * value is unknown. Bit 21 must read 0 for the PROM's INIT handling. See
 * interrupts.md.
 */
/* event_occurred: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_EVENT_OCCURRED                         0x10010000
#define SHUB2_EVENT_OCCURRED_II_INT1_SHIFT           30 /* established */
#define SHUB2_EVENT_OCCURRED_II_INT1_MASK            0x1ull
#define SHUB2_EVENT_OCCURRED_II_INT1_INPLACE (SHUB2_EVENT_OCCURRED_II_INT1_MASK << SHUB2_EVENT_OCCURRED_II_INT1_SHIFT)
#define SHUB2_EVENT_OCCURRED_II_INT0_SHIFT           29 /* established */
#define SHUB2_EVENT_OCCURRED_II_INT0_MASK            0x1ull
#define SHUB2_EVENT_OCCURRED_II_INT0_INPLACE (SHUB2_EVENT_OCCURRED_II_INT0_MASK << SHUB2_EVENT_OCCURRED_II_INT0_SHIFT)
#define SHUB2_EVENT_OCCURRED_IPI_INT_SHIFT           28 /* established */
#define SHUB2_EVENT_OCCURRED_IPI_INT_MASK            0x1ull
#define SHUB2_EVENT_OCCURRED_IPI_INT_INPLACE (SHUB2_EVENT_OCCURRED_IPI_INT_MASK << SHUB2_EVENT_OCCURRED_IPI_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC3_INT_SHIFT          26 /* established */
#define SHUB2_EVENT_OCCURRED_RTC3_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC3_INT_INPLACE (SHUB2_EVENT_OCCURRED_RTC3_INT_MASK << SHUB2_EVENT_OCCURRED_RTC3_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC2_INT_SHIFT          25 /* established */
#define SHUB2_EVENT_OCCURRED_RTC2_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC2_INT_INPLACE (SHUB2_EVENT_OCCURRED_RTC2_INT_MASK << SHUB2_EVENT_OCCURRED_RTC2_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC1_INT_SHIFT          24 /* established */
#define SHUB2_EVENT_OCCURRED_RTC1_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC1_INT_INPLACE (SHUB2_EVENT_OCCURRED_RTC1_INT_MASK << SHUB2_EVENT_OCCURRED_RTC1_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_RTC0_INT_SHIFT          23 /* inferred */
#define SHUB2_EVENT_OCCURRED_RTC0_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_RTC0_INT_INPLACE (SHUB2_EVENT_OCCURRED_RTC0_INT_MASK << SHUB2_EVENT_OCCURRED_RTC0_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT21_SHIFT             21 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT21_MASK              0x1ull
#define SHUB2_EVENT_OCCURRED_BIT21_INPLACE (SHUB2_EVENT_OCCURRED_BIT21_MASK << SHUB2_EVENT_OCCURRED_BIT21_SHIFT)
#define SHUB2_EVENT_OCCURRED_UART_INT_SHIFT          20 /* established */
#define SHUB2_EVENT_OCCURRED_UART_INT_MASK           0x1ull
#define SHUB2_EVENT_OCCURRED_UART_INT_INPLACE (SHUB2_EVENT_OCCURRED_UART_INT_MASK << SHUB2_EVENT_OCCURRED_UART_INT_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT8_SHIFT              8 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT8_MASK               0x1ull
#define SHUB2_EVENT_OCCURRED_BIT8_INPLACE (SHUB2_EVENT_OCCURRED_BIT8_MASK << SHUB2_EVENT_OCCURRED_BIT8_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT5_SHIFT              5 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT5_MASK               0x1ull
#define SHUB2_EVENT_OCCURRED_BIT5_INPLACE (SHUB2_EVENT_OCCURRED_BIT5_MASK << SHUB2_EVENT_OCCURRED_BIT5_SHIFT)
#define SHUB2_EVENT_OCCURRED_BIT3_SHIFT              3 /* inferred */
#define SHUB2_EVENT_OCCURRED_BIT3_MASK               0x1ull
#define SHUB2_EVENT_OCCURRED_BIT3_INPLACE (SHUB2_EVENT_OCCURRED_BIT3_MASK << SHUB2_EVENT_OCCURRED_BIT3_SHIFT)

/*
 * Clears pending events: the kernel writes the bits it wants cleared here and
 * never reads it. That a one clears and a zero leaves a bit alone is inferred
 * from the kernel writing back exactly the bits it read as set (interrupt
 * acknowledge) and a single bit to clear one RTC event (the mmtimer driver).
 * Neither the kernel nor the header says what a read returns.
 */
/* event_occurred_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR
 * header (GPL): name and offset */
/* established */
#define SHUB2_EVENT_OCCURRED_ALIAS                   0x10010008

/*
 * Junk-bus access timing, written once by the first-stage firmware with
 * 0xffff_ffff_0003. Meaning of the value is inferred from the PROM name; the
 * hardware accepts the store. Offset in the local window (add 0x2_0000_0000);
 * the name is the PROM's own register-name table, not Linux.
 */
/* junk_bus_time: w64, reset unknown */
/* established */
#define SHUB2_JUNK_BUS_TIME                          0x10020000

/*
 * Four registers, one per slice, 0x80 apart, that the firmware reads only to
 * remember the progress code it last wrote while it waits on a lock. Any value
 * is accepted. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux.
 */
/* junk_bus_led_data: r64, reset unknown */
/* established */
#define SHUB2_JUNK_BUS_LED_DATA                      0x10030000
#define SHUB2_JUNK_BUS_LED_DATA_COUNT                4
#define SHUB2_JUNK_BUS_LED_DATA_STRIDE               128

/*
 * L1 UART transmit data: eight packet bytes per write, padded with 0x7e after
 * the frame. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux.
 */
/* asic_to_l1_data: w64, reset unknown */
/* established */
#define SHUB2_ASIC_TO_L1_DATA                        0x10038000

/*
 * L1 UART transmit status: bit 0 set means busy; the firmware polls it clear
 * before each write, 10 microseconds apart, for up to 5,000,000 microseconds.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* asic_to_l1_status: r64, reset unknown */
/* established */
#define SHUB2_ASIC_TO_L1_STATUS                      0x10038080
#define SHUB2_ASIC_TO_L1_STATUS_BUSY_SHIFT           0 /* inferred */
#define SHUB2_ASIC_TO_L1_STATUS_BUSY_MASK            0x1ull
#define SHUB2_ASIC_TO_L1_STATUS_BUSY_INPLACE (SHUB2_ASIC_TO_L1_STATUS_BUSY_MASK << SHUB2_ASIC_TO_L1_STATUS_BUSY_SHIFT)

/*
 * L1 UART receive data: eight bytes per word, the first byte in bits 7:0.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* l1_to_asic_data: r64, reset unknown */
/* established */
#define SHUB2_L1_TO_ASIC_DATA                        0x10038100

/*
 * L1 UART receive status: bit 0 set means a word is waiting; the firmware
 * writes 0 to release it. Offset in the local window (add 0x2_0000_0000); the
 * name is the PROM's own register-name table, not Linux.
 */
/* l1_to_asic_status: rw64, reset unknown */
/* established */
#define SHUB2_L1_TO_ASIC_STATUS                      0x10038180
#define SHUB2_L1_TO_ASIC_STATUS_DATA_READY_SHIFT     0 /* inferred */
#define SHUB2_L1_TO_ASIC_STATUS_DATA_READY_MASK      0x1ull
#define SHUB2_L1_TO_ASIC_STATUS_DATA_READY_INPLACE (SHUB2_L1_TO_ASIC_STATUS_DATA_READY_MASK << SHUB2_L1_TO_ASIC_STATUS_DATA_READY_SHIFT)

/*
 * Rack and slot data provided by the L1 controller; the firmware reads it only
 * on paths this page does not reach on a normal boot. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux.
 */
/* rack_slot_data: r64, reset unknown */
/* established */
#define SHUB2_RACK_SLOT_DATA                         0x10038200
#define SHUB2_RACK_SLOT_DATA_BYTE_SHIFT              16 /* inferred */
#define SHUB2_RACK_SLOT_DATA_BYTE_MASK               0xffull
#define SHUB2_RACK_SLOT_DATA_BYTE_INPLACE (SHUB2_RACK_SLOT_DATA_BYTE_MASK << SHUB2_RACK_SLOT_DATA_BYTE_SHIFT)
#define SHUB2_RACK_SLOT_DATA_NUMBER_SHIFT            4 /* inferred */
#define SHUB2_RACK_SLOT_DATA_NUMBER_MASK             0xfffull
#define SHUB2_RACK_SLOT_DATA_NUMBER_INPLACE (SHUB2_RACK_SLOT_DATA_NUMBER_MASK << SHUB2_RACK_SLOT_DATA_NUMBER_SHIFT)
#define SHUB2_RACK_SLOT_DATA_CODE_SHIFT              1 /* inferred */
#define SHUB2_RACK_SLOT_DATA_CODE_MASK               0x7ull
#define SHUB2_RACK_SLOT_DATA_CODE_INPLACE (SHUB2_RACK_SLOT_DATA_CODE_MASK << SHUB2_RACK_SLOT_DATA_CODE_SHIFT)
#define SHUB2_RACK_SLOT_DATA_BIT0_SHIFT              0 /* inferred */
#define SHUB2_RACK_SLOT_DATA_BIT0_MASK               0x1ull
#define SHUB2_RACK_SLOT_DATA_BIT0_INPLACE (SHUB2_RACK_SLOT_DATA_BIT0_MASK << SHUB2_RACK_SLOT_DATA_BIT0_SHIFT)

/*
 * Clock source control for the real-time clock. The PROM converts counter ticks
 * to microseconds as counter * (max_count * 10 + 10) / 1000, so with max_count
 * 4 the counter advances 20 ticks per microsecond. Offset in the local window
 * (add 0x2_0000_0000); the name is the PROM's own register-name table, not
 * Linux.
 */
/* gc_src_ctrl: rw64, reset unknown */
/* established */
#define SHUB2_GC_SRC_CTRL                            0x10060700
#define SHUB2_GC_SRC_CTRL_SOURCE_SEL_SHIFT           32 /* inferred */
#define SHUB2_GC_SRC_CTRL_SOURCE_SEL_MASK            0x3ull
#define SHUB2_GC_SRC_CTRL_SOURCE_SEL_INPLACE (SHUB2_GC_SRC_CTRL_SOURCE_SEL_MASK << SHUB2_GC_SRC_CTRL_SOURCE_SEL_SHIFT)
#define SHUB2_GC_SRC_CTRL_MAX_COUNT_SHIFT            4 /* established */
#define SHUB2_GC_SRC_CTRL_MAX_COUNT_MASK             0x3ffull
#define SHUB2_GC_SRC_CTRL_MAX_COUNT_INPLACE (SHUB2_GC_SRC_CTRL_MAX_COUNT_MASK << SHUB2_GC_SRC_CTRL_MAX_COUNT_SHIFT)
#define SHUB2_GC_SRC_CTRL_ENABLE_COUNTER_SHIFT       0 /* established */
#define SHUB2_GC_SRC_CTRL_ENABLE_COUNTER_MASK        0x1ull
#define SHUB2_GC_SRC_CTRL_ENABLE_COUNTER_INPLACE (SHUB2_GC_SRC_CTRL_ENABLE_COUNTER_MASK << SHUB2_GC_SRC_CTRL_ENABLE_COUNTER_SHIFT)

/*
 * Which processors may send interprocessor interrupts to this one: four
 * registers, one per processor slice (SH2_IPI_ACCESS0 to 3). Defined by the
 * header; the kernel files read never touch them, so the layout is unknown.
 */
/* ipi_access: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_IPI_ACCESS                             0x10060c00
#define SHUB2_IPI_ACCESS_COUNT                       4
#define SHUB2_IPI_ACCESS_STRIDE                      128

/*
 * The node's identification word. Read by the firmware to find its own node
 * number (bits 45:32) and the sharing parameters; written during the
 * interconnect phase. Linux v5.3 does not define it for SHub 2. Offset in the
 * local window (add 0x2_0000_0000); the name is the PROM's own register-name
 * table, not Linux.
 */
/* node_id: rw64, reset unknown */
/* established */
#define SHUB2_NODE_ID                                0x10060f00
#define SHUB2_NODE_ID_RANGE_CHECK_SHIFT              55 /* established */
#define SHUB2_NODE_ID_RANGE_CHECK_MASK               0x1ull
#define SHUB2_NODE_ID_RANGE_CHECK_INPLACE (SHUB2_NODE_ID_RANGE_CHECK_MASK << SHUB2_NODE_ID_RANGE_CHECK_SHIFT)
#define SHUB2_NODE_ID_SHARERS_1K_SHIFT               54 /* established */
#define SHUB2_NODE_ID_SHARERS_1K_MASK                0x1ull
#define SHUB2_NODE_ID_SHARERS_1K_INPLACE (SHUB2_NODE_ID_SHARERS_1K_MASK << SHUB2_NODE_ID_SHARERS_1K_SHIFT)
#define SHUB2_NODE_ID_NODES_PER_BIT_SHIFT            48 /* established */
#define SHUB2_NODE_ID_NODES_PER_BIT_MASK             0x3full
#define SHUB2_NODE_ID_NODES_PER_BIT_INPLACE (SHUB2_NODE_ID_NODES_PER_BIT_MASK << SHUB2_NODE_ID_NODES_PER_BIT_SHIFT)
#define SHUB2_NODE_ID_SHARING_MODE_SHIFT             46 /* established */
#define SHUB2_NODE_ID_SHARING_MODE_MASK              0x3ull
#define SHUB2_NODE_ID_SHARING_MODE_INPLACE (SHUB2_NODE_ID_SHARING_MODE_MASK << SHUB2_NODE_ID_SHARING_MODE_SHIFT)
#define SHUB2_NODE_ID_NODE_ID_SHIFT                  32 /* established */
#define SHUB2_NODE_ID_NODE_ID_MASK                   0x3fffull
#define SHUB2_NODE_ID_NODE_ID_INPLACE (SHUB2_NODE_ID_NODE_ID_MASK << SHUB2_NODE_ID_NODE_ID_SHIFT)
#define SHUB2_NODE_ID_REVISION_SHIFT                 28 /* established */
#define SHUB2_NODE_ID_REVISION_MASK                  0xfull
#define SHUB2_NODE_ID_REVISION_INPLACE (SHUB2_NODE_ID_REVISION_MASK << SHUB2_NODE_ID_REVISION_SHIFT)

/*
 * Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB,
 * SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for
 * processor B, C, D'). The interrupt fires when the clock reaches the value.
 * The comparator for RTC 0 would sit 0x80 below these and is not defined in the
 * header (unknown).
 */
/* int_cmp: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): name
 * and offset */
/* established */
#define SHUB2_INT_CMP                                0x101b0080
#define SHUB2_INT_CMP_COUNT                          3
#define SHUB2_INT_CMP_STRIDE                         128
#define SHUB2_INT_CMP_COMPARE_SHIFT                  0 /* established */
#define SHUB2_INT_CMP_COMPARE_MASK                   0x7fffffffffffffull
#define SHUB2_INT_CMP_COMPARE_INPLACE (SHUB2_INT_CMP_COMPARE_MASK << SHUB2_INT_CMP_COMPARE_SHIFT)

/*
 * Node election word: each slice writes slice + 1 through the alias and reads
 * it back; the winner is the one that reads its own value. Plain storage
 * satisfies the code. Offset in the local window (add 0x2_0000_0000); the name
 * is the PROM's own register-name table, not Linux.
 */
/* scratch1: rw64, reset unknown */
/* established */
#define SHUB2_SCRATCH1                               0x101d0080

/*
 * Write path onto the SCRATCH1 word; the relation is inferred from the use.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* scratch1_alias: w64, reset unknown */
/* established */
#define SHUB2_SCRATCH1_ALIAS                         0x101d0088

/*
 * Firmware mailbox word for the L1 console link. Plain storage satisfies the
 * code; the fields are how the 10.54 firmware uses it, names are ours. Offset
 * in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* scratch2: rw64, reset unknown */
/* established */
#define SHUB2_SCRATCH2                               0x101d0100
#define SHUB2_SCRATCH2_CLEAR_BIT_SHIFT               63 /* inferred */
#define SHUB2_SCRATCH2_CLEAR_BIT_MASK                0x1ull
#define SHUB2_SCRATCH2_CLEAR_BIT_INPLACE (SHUB2_SCRATCH2_CLEAR_BIT_MASK << SHUB2_SCRATCH2_CLEAR_BIT_SHIFT)
#define SHUB2_SCRATCH2_RX_INDEX_SHIFT                58 /* inferred */
#define SHUB2_SCRATCH2_RX_INDEX_MASK                 0x1full
#define SHUB2_SCRATCH2_RX_INDEX_INPLACE (SHUB2_SCRATCH2_RX_INDEX_MASK << SHUB2_SCRATCH2_RX_INDEX_SHIFT)
#define SHUB2_SCRATCH2_CHANNEL_SHIFT                 50 /* inferred */
#define SHUB2_SCRATCH2_CHANNEL_MASK                  0x1full
#define SHUB2_SCRATCH2_CHANNEL_INPLACE (SHUB2_SCRATCH2_CHANNEL_MASK << SHUB2_SCRATCH2_CHANNEL_SHIFT)
#define SHUB2_SCRATCH2_SEQUENCE_SHIFT                42 /* inferred */
#define SHUB2_SCRATCH2_SEQUENCE_MASK                 0xffull
#define SHUB2_SCRATCH2_SEQUENCE_INPLACE (SHUB2_SCRATCH2_SEQUENCE_MASK << SHUB2_SCRATCH2_SEQUENCE_SHIFT)
#define SHUB2_SCRATCH2_STATE_SHIFT                   39 /* inferred */
#define SHUB2_SCRATCH2_STATE_MASK                    0x7ull
#define SHUB2_SCRATCH2_STATE_INPLACE (SHUB2_SCRATCH2_STATE_MASK << SHUB2_SCRATCH2_STATE_SHIFT)

/*
 * Release side of the second firmware lock; the alias 0x08 above is the take
 * side. Whether a read of the alias takes the lock in hardware is unknown; a
 * plain pair that always reads 0 satisfies every access. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux.
 */
/* scratch3: w64, reset unknown */
/* established */
#define SHUB2_SCRATCH3                               0x101d0180

/*
 * Take side of the second firmware lock. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.
 */
/* scratch3_alias: r64, reset unknown */
/* established */
#define SHUB2_SCRATCH3_ALIAS                         0x101d0188

/*
 * Release side of the node lock that guards SCRATCH6 and SCRATCH7. Offset in
 * the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* scratch4: w64, reset unknown */
/* established */
#define SHUB2_SCRATCH4                               0x101d0200

/*
 * Take side of the node lock; a plain register that always reads 0 satisfies
 * every access. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux.
 */
/* scratch4_alias: r64, reset unknown */
/* established */
#define SHUB2_SCRATCH4_ALIAS                         0x101d0208

/*
 * Claim bits of the second firmware lock: the firmware sets a bit to claim a
 * resource (bit 0 for the barrier, bit 7 for the console link, bit 0xf for a
 * packet exchange). Offset in the local window (add 0x2_0000_0000); the name is
 * the PROM's own register-name table, not Linux.
 */
/* scratch5: rw64, reset unknown */
/* established */
#define SHUB2_SCRATCH5                               0x101d0280

/*
 * Shared firmware word guarded by the node lock: slice present and arrival
 * bits, the barrier flag and a per-slice-pair field. Plain storage; names of
 * the fields are ours. Offset in the local window (add 0x2_0000_0000); the name
 * is the PROM's own register-name table, not Linux.
 */
/* scratch6: rw64, reset unknown */
/* established */
#define SHUB2_SCRATCH6                               0x101d0300
#define SHUB2_SCRATCH6_PAIR1_STATE_SHIFT             50 /* inferred */
#define SHUB2_SCRATCH6_PAIR1_STATE_MASK              0x7ull
#define SHUB2_SCRATCH6_PAIR1_STATE_INPLACE (SHUB2_SCRATCH6_PAIR1_STATE_MASK << SHUB2_SCRATCH6_PAIR1_STATE_SHIFT)
#define SHUB2_SCRATCH6_PAIR0_STATE_SHIFT             47 /* inferred */
#define SHUB2_SCRATCH6_PAIR0_STATE_MASK              0x7ull
#define SHUB2_SCRATCH6_PAIR0_STATE_INPLACE (SHUB2_SCRATCH6_PAIR0_STATE_MASK << SHUB2_SCRATCH6_PAIR0_STATE_SHIFT)
#define SHUB2_SCRATCH6_BARRIER_BUSY_SHIFT            34 /* inferred */
#define SHUB2_SCRATCH6_BARRIER_BUSY_MASK             0x1ull
#define SHUB2_SCRATCH6_BARRIER_BUSY_INPLACE (SHUB2_SCRATCH6_BARRIER_BUSY_MASK << SHUB2_SCRATCH6_BARRIER_BUSY_SHIFT)
#define SHUB2_SCRATCH6_SLICE_ARRIVED_SHIFT           30 /* inferred */
#define SHUB2_SCRATCH6_SLICE_ARRIVED_MASK            0xfull
#define SHUB2_SCRATCH6_SLICE_ARRIVED_INPLACE (SHUB2_SCRATCH6_SLICE_ARRIVED_MASK << SHUB2_SCRATCH6_SLICE_ARRIVED_SHIFT)
#define SHUB2_SCRATCH6_SLICE_PRESENT_SHIFT           26 /* inferred */
#define SHUB2_SCRATCH6_SLICE_PRESENT_MASK            0xfull
#define SHUB2_SCRATCH6_SLICE_PRESENT_INPLACE (SHUB2_SCRATCH6_SLICE_PRESENT_MASK << SHUB2_SCRATCH6_SLICE_PRESENT_SHIFT)
#define SHUB2_SCRATCH6_PAL_FLAGS_SHIFT               21 /* inferred */
#define SHUB2_SCRATCH6_PAL_FLAGS_MASK                0xfull
#define SHUB2_SCRATCH6_PAL_FLAGS_INPLACE (SHUB2_SCRATCH6_PAL_FLAGS_MASK << SHUB2_SCRATCH6_PAL_FLAGS_SHIFT)

/*
 * Second shared firmware word with the same lock cycle as SCRATCH6. Offset in
 * the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* scratch7: rw64, reset unknown */
/* established */
#define SHUB2_SCRATCH7                               0x101d0380

/*
 * Holds the address of the firmware's node-addressing table row (the low 32
 * bits of the row address with bit 63 set); every later node-number read loads
 * the row through it. The firmware reads it back, so it must store all 64 bits.
 * Offset in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* scratch24: rw64, reset unknown */
/* established */
#define SHUB2_SCRATCH24                              0x101d0c00

/*
 * Which processor slices of the node are present. The firmware tests bit 0 and
 * bit 1 for slices 0 and 1 and wants two equal non-zero reads in a row. Offset
 * in the local window (add 0x2_0000_0000); the name is the PROM's own
 * register-name table, not Linux.
 */
/* fsb_symmetric_agent_status: r64, reset unknown */
/* established */
#define SHUB2_FSB_SYMMETRIC_AGENT_STATUS             0x20020010
#define SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_1_ACTIVE_SHIFT 1 /* inferred */
#define SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_1_ACTIVE_MASK 0x1ull
#define SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_1_ACTIVE_INPLACE (SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_1_ACTIVE_MASK << SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_1_ACTIVE_SHIFT)
#define SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_0_ACTIVE_SHIFT 0 /* inferred */
#define SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_0_ACTIVE_MASK 0x1ull
#define SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_0_ACTIVE_INPLACE (SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_0_ACTIVE_MASK << SHUB2_FSB_SYMMETRIC_AGENT_STATUS_CPU_0_ACTIVE_SHIFT)

/*
 * PIO write status, four instances (SHub 2 nodes carry up to four processor
 * slices). Note the kernel indexes them out of order: slices 0, 1, 2, 3 use
 * instances 0, 2, 1, 3, in the setup code's table. The idle value is zero, not
 * all ones. The write_error, multi_write_error, write_error_address and
 * writes_ok fields are the SHub 1 header's; the SHub 2 layout was not read.
 */
/* pio_write_status: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_PIO_WRITE_STATUS                       0x20070200
#define SHUB2_PIO_WRITE_STATUS_COUNT                 4
#define SHUB2_PIO_WRITE_STATUS_STRIDE                128
#define SHUB2_PIO_WRITE_STATUS_WRITES_OK_SHIFT       63 /* established */
#define SHUB2_PIO_WRITE_STATUS_WRITES_OK_MASK        0x1ull
#define SHUB2_PIO_WRITE_STATUS_WRITES_OK_INPLACE (SHUB2_PIO_WRITE_STATUS_WRITES_OK_MASK << SHUB2_PIO_WRITE_STATUS_WRITES_OK_SHIFT)
#define SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT 56 /* established */
#define SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK 0x3full
#define SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_INPLACE (SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK << SHUB2_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT)
#define SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_ADDRESS_SHIFT 3 /* established */
#define SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_ADDRESS_MASK 0x7fffffffffffull
#define SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_ADDRESS_INPLACE (SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_ADDRESS_MASK << SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_ADDRESS_SHIFT)
#define SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_SHIFT     2 /* established */
#define SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_MASK      0x1ull
#define SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_INPLACE (SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_MASK << SHUB2_PIO_WRITE_STATUS_WRITE_ERROR_SHIFT)
#define SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT  1 /* established */
#define SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK   0x1ull
#define SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_INPLACE (SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK << SHUB2_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT)
#define SHUB2_PIO_WRITE_STATUS_MULTI_WRITE_ERROR_SHIFT 0 /* established */
#define SHUB2_PIO_WRITE_STATUS_MULTI_WRITE_ERROR_MASK 0x1ull
#define SHUB2_PIO_WRITE_STATUS_MULTI_WRITE_ERROR_INPLACE (SHUB2_PIO_WRITE_STATUS_MULTI_WRITE_ERROR_MASK << SHUB2_PIO_WRITE_STATUS_MULTI_WRITE_ERROR_SHIFT)

/*
 * Alias of the PIO write status. The header names only the instance for slice
 * 0. The deadlock recovery assembly adds 8 to whichever status address it was
 * given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock,
 * write error and multiple write error bits (assembly comment); the header
 * names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown.
 * The kernel does this on SHub 1 and reads the alias instead on SHub 2.
 */
/* pio_write_status_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR
 * header (GPL): name and offset */
#define SHUB2_PIO_WRITE_STATUS_ALIAS                 0x20070208 /* inferred */
#define SHUB2_PIO_WRITE_STATUS_ALIAS_COUNT           4
#define SHUB2_PIO_WRITE_STATUS_ALIAS_STRIDE          128

/*
 * V, the node-addressing selector: the PROM reads it before forming any global
 * or TIO address and uses it unmasked as an index into a five-entry table, so
 * it must read 0 to 4 (devices/shub/shub2.md section 1 gives the shifts for
 * each value). Real value unknown. Offset in the local window (add
 * 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.
 */
/* address_mode: r64, reset unknown */
/* established */
#define SHUB2_ADDRESS_MODE                           0x20110000

/*
 * Remote flash remap: the PROM writes the enable bit and a 9-bit field it takes
 * from bits 32:24 of its argument. Meaning of the fields is inferred from the
 * PROM name. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux.
 */
/* firmware_remap: w64, reset unknown */
/* established */
#define SHUB2_FIRMWARE_REMAP                         0x20110008
#define SHUB2_FIRMWARE_REMAP_ENABLE_SHIFT            60 /* established */
#define SHUB2_FIRMWARE_REMAP_ENABLE_MASK             0x1ull
#define SHUB2_FIRMWARE_REMAP_ENABLE_INPLACE (SHUB2_FIRMWARE_REMAP_ENABLE_MASK << SHUB2_FIRMWARE_REMAP_ENABLE_SHIFT)
#define SHUB2_FIRMWARE_REMAP_OFFSET_SHIFT            24 /* established */
#define SHUB2_FIRMWARE_REMAP_OFFSET_MASK             0x1ffull
#define SHUB2_FIRMWARE_REMAP_OFFSET_INPLACE (SHUB2_FIRMWARE_REMAP_OFFSET_MASK << SHUB2_FIRMWARE_REMAP_OFFSET_SHIFT)

/*
 * The first-stage firmware reads it and compares the whole word with zero to
 * choose which bit pair of the PAL argument becomes the slice number in cr.lid
 * (zero: bits 2:1, else bits 3:2). Meaning of the bit is inferred from the PROM
 * name. Offset in the local window (add 0x2_0000_0000); the name is the PROM's
 * own register-name table, not Linux.
 */
/* processor_type: r64, reset unknown */
/* established */
#define SHUB2_PROCESSOR_TYPE                         0x20110010
#define SHUB2_PROCESSOR_TYPE_CODE_SHIFT              0 /* inferred */
#define SHUB2_PROCESSOR_TYPE_CODE_MASK               0x1ull
#define SHUB2_PROCESSOR_TYPE_CODE_INPLACE (SHUB2_PROCESSOR_TYPE_CODE_MASK << SHUB2_PROCESSOR_TYPE_CODE_SHIFT)

/*
 * Block transfer engine control and status, one per engine, SHub 2 (four
 * engines, SH2_BT_ENG_CSR_0 to 3). Unlike SHub 1 the kernel starts a transfer
 * with one store here: busy, the mode shifted left by 24, and the length in
 * cache lines in the low bits. The kernel reads it for busy and error; the
 * engine's error code sits in bits 41:36 (kernel's BTE_ERR_BITS).
 */
/* bt_eng_csr: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_BT_ENG_CSR                             0x30040000
#define SHUB2_BT_ENG_CSR_COUNT                       4
#define SHUB2_BT_ENG_CSR_STRIDE                      65536
#define SHUB2_BT_ENG_CSR_ERROR_CODE_SHIFT            36 /* inferred */
#define SHUB2_BT_ENG_CSR_ERROR_CODE_MASK             0x3full
#define SHUB2_BT_ENG_CSR_ERROR_CODE_INPLACE (SHUB2_BT_ENG_CSR_ERROR_CODE_MASK << SHUB2_BT_ENG_CSR_ERROR_CODE_SHIFT)
#define SHUB2_BT_ENG_CSR_NOTIFY_SHIFT                28 /* inferred */
#define SHUB2_BT_ENG_CSR_NOTIFY_MASK                 0x1ull
#define SHUB2_BT_ENG_CSR_NOTIFY_INPLACE (SHUB2_BT_ENG_CSR_NOTIFY_MASK << SHUB2_BT_ENG_CSR_NOTIFY_SHIFT)
#define SHUB2_BT_ENG_CSR_ZERO_FILL_SHIFT             24 /* inferred */
#define SHUB2_BT_ENG_CSR_ZERO_FILL_MASK              0x1ull
#define SHUB2_BT_ENG_CSR_ZERO_FILL_INPLACE (SHUB2_BT_ENG_CSR_ZERO_FILL_MASK << SHUB2_BT_ENG_CSR_ZERO_FILL_SHIFT)
#define SHUB2_BT_ENG_CSR_BUSY_SHIFT                  20 /* inferred */
#define SHUB2_BT_ENG_CSR_BUSY_MASK                   0x1ull
#define SHUB2_BT_ENG_CSR_BUSY_INPLACE (SHUB2_BT_ENG_CSR_BUSY_MASK << SHUB2_BT_ENG_CSR_BUSY_SHIFT)
#define SHUB2_BT_ENG_CSR_ERROR_SHIFT                 16 /* inferred */
#define SHUB2_BT_ENG_CSR_ERROR_MASK                  0x1ull
#define SHUB2_BT_ENG_CSR_ERROR_INPLACE (SHUB2_BT_ENG_CSR_ERROR_MASK << SHUB2_BT_ENG_CSR_ERROR_SHIFT)
#define SHUB2_BT_ENG_CSR_LENGTH_SHIFT                0 /* inferred */
#define SHUB2_BT_ENG_CSR_LENGTH_MASK                 0xffffull
#define SHUB2_BT_ENG_CSR_LENGTH_INPLACE (SHUB2_BT_ENG_CSR_LENGTH_MASK << SHUB2_BT_ENG_CSR_LENGTH_SHIFT)

/*
 * BTE source address, per engine. The kernel converts the physical address to
 * the network address form first (nasid moved to bit 40 upward, the bank-select
 * bits moved to bit 36).
 */
/* bt_eng_src: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_BT_ENG_SRC                             0x30040080
#define SHUB2_BT_ENG_SRC_COUNT                       4
#define SHUB2_BT_ENG_SRC_STRIDE                      65536

/*
 * BTE destination address, per engine; same conversion as the source.
 */
/* bt_eng_dest: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_BT_ENG_DEST                            0x30040100
#define SHUB2_BT_ENG_DEST_COUNT                      4
#define SHUB2_BT_ENG_DEST_STRIDE                     65536

/*
 * BTE notification address, per engine; same conversion.
 */
/* bt_eng_notify: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_BT_ENG_NOTIFY                          0x30040180
#define SHUB2_BT_ENG_NOTIFY_COUNT                    4
#define SHUB2_BT_ENG_NOTIFY_STRIDE                   65536

/*
 * Board type word. The PROM stores the board type here and then checks it
 * (accepted values 0x7b, 0x200, 0xa00, 0xe00; any other prints "unknown board
 * type" and returns, after the store) and eight later sites call the 64-bit
 * read helper on it (one ninth site was not classified); one of them is a
 * predicate that returns whether it equals 0xe00. Nothing zeroes it before the
 * store. Offset in the local window (add 0x2_0000_0000); the name is the PROM's
 * own register-name table, not Linux. A node crossbar debug-compare register by
 * name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_iilb_pi_cmp_exp_data0: rw64, reset unknown */
/* established */
#define SHUB2_XN_IILB_PI_CMP_EXP_DATA0               0x50031240

/*
 * Firmware scratch word, slot 3 of the group-a list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_iilb_ni0_cmp_exp_data0: rw64, reset unknown */
/* established */
#define SHUB2_XN_IILB_NI0_CMP_EXP_DATA0              0x50031280

/*
 * Firmware scratch word, slot 3 of the group-b list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_iilb_ni0_cmp_exp_data1: rw64, reset unknown */
/* established */
#define SHUB2_XN_IILB_NI0_CMP_EXP_DATA1              0x50031290

/*
 * Firmware scratch word, slot 2 of the group-a list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_iilb_ni1_cmp_exp_data0: rw64, reset unknown */
/* established */
#define SHUB2_XN_IILB_NI1_CMP_EXP_DATA0              0x500312c0

/*
 * Firmware scratch word, slot 2 of the group-b list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_iilb_ni1_cmp_exp_data1: rw64, reset unknown */
/* established */
#define SHUB2_XN_IILB_NI1_CMP_EXP_DATA1              0x500312d0

/*
 * Per-slice word 2 of the four read by the processor lookup (the compact-id
 * lookup picks it by bits 9:7 of the id; a second routine reads it by table).
 * One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the
 * node set-up write list does not zero them. What the word holds is unknown
 * beyond the caller keeping bits 51:50 of the value read. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux. A node crossbar debug-compare register by name; the PROM uses it
 * as 64-bit storage (inferred).
 */
/* xn_md_ni1_cmp_exp_data1: rw64, reset unknown */
/* established */
#define SHUB2_XN_MD_NI1_CMP_EXP_DATA1                0x50031590

/*
 * Per-slice word 3 of the four read by the processor lookup (the compact-id
 * lookup picks it by bits 9:7 of the id; a second routine reads it by table).
 * One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the
 * node set-up write list does not zero them. What the word holds is unknown
 * beyond the caller keeping bits 51:50 of the value read. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux. A node crossbar debug-compare register by name; the PROM uses it
 * as 64-bit storage (inferred).
 */
/* xn_md_ni1_cmp_enable1: rw64, reset unknown */
/* established */
#define SHUB2_XN_MD_NI1_CMP_ENABLE1                  0x500315b0

/*
 * Firmware scratch word, slot 0 of the group-a list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_md_sic_cmp_exp_hdr0: rw64, reset unknown */
/* established */
#define SHUB2_XN_MD_SIC_CMP_EXP_HDR0                 0x500315c0

/*
 * Firmware scratch word, slot 0 of the group-b list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred). SHub 1's
 * equivalent (SH_XN_MD_SIC_CMP_EXP_HDR1) implements bits 41:0 only; the SHub 2
 * width is not known and a model should keep 64 bits.
 */
/* xn_md_sic_cmp_exp_hdr1: rw64, reset unknown */
/* established */
#define SHUB2_XN_MD_SIC_CMP_EXP_HDR1                 0x500315d0

/*
 * Per-slice word 0 of the four read by the processor lookup (the compact-id
 * lookup picks it by bits 9:7 of the id; a second routine reads it by table).
 * One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the
 * node set-up write list does not zero them. What the word holds is unknown
 * beyond the caller keeping bits 51:50 of the value read. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux. A node crossbar debug-compare register by name; the PROM uses it
 * as 64-bit storage (inferred).
 */
/* xn_md_sic_cmp_hdr_enable0: rw64, reset unknown */
/* established */
#define SHUB2_XN_MD_SIC_CMP_HDR_ENABLE0              0x500315e0

/*
 * Per-slice word 1 of the four read by the processor lookup (the compact-id
 * lookup picks it by bits 9:7 of the id; a second routine reads it by table).
 * One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the
 * node set-up write list does not zero them. What the word holds is unknown
 * beyond the caller keeping bits 51:50 of the value read. Offset in the local
 * window (add 0x2_0000_0000); the name is the PROM's own register-name table,
 * not Linux. A node crossbar debug-compare register by name; the PROM uses it
 * as 64-bit storage (inferred). SHub 1's equivalent
 * (SH_XN_MD_SIC_CMP_HDR_ENABLE1) implements bits 41:0 only; the SHub 2 width is
 * not known and a model should keep 64 bits.
 */
/* xn_md_sic_cmp_hdr_enable1: rw64, reset unknown */
/* established */
#define SHUB2_XN_MD_SIC_CMP_HDR_ENABLE1              0x500315f0

/*
 * Firmware scratch word, slot 0 of the group-c list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_ni0_iilb_cmp_exp_data0: rw64, reset unknown */
/* established */
#define SHUB2_XN_NI0_IILB_CMP_EXP_DATA0              0x50031700

/*
 * Firmware scratch word, slot 1 of the group-c list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_ni0_iilb_cmp_exp_data1: rw64, reset unknown */
/* established */
#define SHUB2_XN_NI0_IILB_CMP_EXP_DATA1              0x50031710

/*
 * Firmware scratch word, slot 2 of the group-c list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_ni0_llp_cmp_exp_data0: rw64, reset unknown */
/* established */
#define SHUB2_XN_NI0_LLP_CMP_EXP_DATA0               0x50031800

/*
 * Firmware scratch word, slot 3 of the group-c list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_ni0_llp_cmp_exp_data1: rw64, reset unknown */
/* established */
#define SHUB2_XN_NI0_LLP_CMP_EXP_DATA1               0x50031810

/*
 * Firmware scratch word, slot 1 of the group-b list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_ni0_md_cmp_exp_hdr0: rw64, reset unknown */
/* established */
#define SHUB2_XN_NI0_MD_CMP_EXP_HDR0                 0x50031b40

/*
 * Firmware scratch word, slot 1 of the group-a list the node set-up zeroes
 * (three lists of four, indexed by slice). Its use after the zeroing was not
 * traced. Offset in the local window (add 0x2_0000_0000); the name is the
 * PROM's own register-name table, not Linux. A node crossbar debug-compare
 * register by name; the PROM uses it as 64-bit storage (inferred).
 */
/* xn_ni0_md_cmp_exp_hdr1: rw64, reset unknown */
/* established */
#define SHUB2_XN_NI0_MD_CMP_EXP_HDR1                 0x50031b50

/*
 * Junk bus LED registers, one per processor slice (header
 * SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED
 * state per processor and stores it with a 16-bit write at LED0 plus slice
 * times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer
 * interrupt, bit 1 an activity flag. The junk bus also holds the UART whose
 * interrupt is event_occurred bit 20.
 */
/* junk_bus_led: w16, reset unknown; Linux v5.3 SGI SN2 platform MMR header
 * (GPL): name and offset */
/* established */
#define SHUB2_JUNK_BUS_LED                           0xf0000000
#define SHUB2_JUNK_BUS_LED_COUNT                     4
#define SHUB2_JUNK_BUS_LED_STRIDE                    65536

/*
 * Purge translation cache message, SHub 2 (header SH2_PTC). One 64-bit store
 * per target node replaces SHub 1's two. The region id and region number do not
 * go in the data: the kernel adds them, shifted left by four, to the register's
 * address. (The header's `SH2_PTC_ADDR_SHFT` is 4 but sits under a region-id
 * comment and no kernel code uses it, which uses `SH2_PTC_RID_SHFT`; the data's
 * address field is `SH2_PTC_ADDR_MASK`, which starts at bit 12, and that is
 * what this file uses.) The data carries the type bit, the page size and the
 * start bit, and the virtual address in bits 60:12. How wide the
 * address-encoded part is, and so how large the register window is, is unknown.
 * The kernel only waits on the PIO write status afterwards; on a deadlock it
 * reads the status alias instead of clearing it.
 */
/* ptc: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): name
 * and offset */
/* established */
#define SHUB2_PTC                                    0x170000000
#define SHUB2_PTC_START_SHIFT                        63 /* established */
#define SHUB2_PTC_START_MASK                         0x1ull
#define SHUB2_PTC_START_INPLACE (SHUB2_PTC_START_MASK << SHUB2_PTC_START_SHIFT)
#define SHUB2_PTC_ADDRESS_SHIFT                      12 /* established */
#define SHUB2_PTC_ADDRESS_MASK                       0x1ffffffffffffull
#define SHUB2_PTC_ADDRESS_INPLACE (SHUB2_PTC_ADDRESS_MASK << SHUB2_PTC_ADDRESS_SHIFT)
#define SHUB2_PTC_PS_SHIFT                           2 /* inferred */
#define SHUB2_PTC_PS_MASK                            0x3ull
#define SHUB2_PTC_PS_INPLACE (SHUB2_PTC_PS_MASK << SHUB2_PTC_PS_SHIFT)
#define SHUB2_PTC_TYPE_BIT_SHIFT                     0 /* inferred */
#define SHUB2_PTC_TYPE_BIT_MASK                      0x1ull
#define SHUB2_PTC_TYPE_BIT_INPLACE (SHUB2_PTC_TYPE_BIT_MASK << SHUB2_PTC_TYPE_BIT_SHIFT)

/*
 * Real-time clock: a 55-bit counter, read by the kernel as its clock source
 * (clock source rating 450, mask 55 bits) and for microsecond delays, because
 * the CPU cycle counters are not synchronised across processors. The frequency
 * is not in a register; the kernel asks firmware for it. The driver comment
 * says the clock registers sit alone on a 64 KiB page, which is what lets user
 * space map it read-only. The SHub 1 PROM (SAL 5.04) writes 0 to it at the
 * SAL_B reset entry (0xffa94d20) and again to a node's counter in the
 * interconnect phase, then reads it on every delay and timeout, so it must
 * advance. Its tick period comes from rtc_ctl (SHub 1: 10 ns times the field
 * plus one, 50 ns after the PROM's own write). See prom-reset.md.
 */
/* rtc: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): name
 * and offset */
/* established */
#define SHUB2_RTC                                    0x2101c0000
#define SHUB2_RTC_COUNTER_SHIFT                      0 /* established */
#define SHUB2_RTC_COUNTER_MASK                       0x7fffffffffffffull
#define SHUB2_RTC_COUNTER_INPLACE (SHUB2_RTC_COUNTER_MASK << SHUB2_RTC_COUNTER_SHIFT)

/* established */
#define SHUB2_EVENT_OCCURRED_EXTIO_INT2              0x200000000ull
/* established */
#define SHUB2_EVENT_OCCURRED_EXTIO_INT3              0x400000000ull
#define SHUB2_IPI_BASE_VALUE                         0xfeeu /* established */
#define SHUB2_PIO_WRITE_STATUS_ALIAS_CLEAR           0x7u /* established */
#define SHUB2_PIO_WRITE_STATUS_IDLE                  0x0u /* established */
/* established */
#define SHUB2_PI_CAM_WAR_VALUE                       0x8000000000000010ull
/* established */
#define SHUB2_RTC_CONFIG_MASK                        0xff3ffffffefffffull
#define SHUB2_RTC_ENABLE_MASK                        0x1u /* established */
/* established */
#define SHUB2_RTC_MASK                               0x7fffffffffffffull
#define SHUB2_SHUB_1_1_MAX_REVISION                  0x2u /* established */

#endif /* SHUB2_GEN_H */
