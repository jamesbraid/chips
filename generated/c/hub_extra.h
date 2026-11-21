/* generated from devices/hub/registers-extra.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 7704657248a0fc8036bec883c4fcec87a565d969ba87cc19c1e9bc8d2ae9aa05 */
/* Hub block transfer engine registers and control bits outside the census */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/* enum iio_lnk_stat */
#define HUB_IIO_LNK_STAT_WORKING                     2 /* established */

/*
 * Widget identification register of the Hub widget. Offset and field layout are from the public header. The header gives no access type and no reset value, so the The IRIX register table confirms the access.
 */
/* iio_wid: r64, reset 0x1c101048 */
#define HUB_IIO_WID                                  0x400000 /* established */
#define HUB_IIO_WID_REV_SHIFT                        28 /* established */
#define HUB_IIO_WID_REV_MASK                         0xfull
#define HUB_IIO_WID_REV_INPLACE                      (HUB_IIO_WID_REV_MASK << HUB_IIO_WID_REV_SHIFT)
#define HUB_IIO_WID_PART_SHIFT                       12 /* established */
#define HUB_IIO_WID_PART_MASK                        0xffffull
#define HUB_IIO_WID_PART_INPLACE                     (HUB_IIO_WID_PART_MASK << HUB_IIO_WID_PART_SHIFT)
#define HUB_IIO_WID_MFG_SHIFT                        1 /* established */
#define HUB_IIO_WID_MFG_MASK                         0x7ffull
#define HUB_IIO_WID_MFG_INPLACE                      (HUB_IIO_WID_MFG_MASK << HUB_IIO_WID_MFG_SHIFT)

/*
 * The rsvd mask is the members the header's structure names reserved (rsvd1 to rsvd4); the header gives no read or write behaviour for them, so the mask is the header's naming, graded established as a header fact only.
 */
/* iio_wstat: r64, reset 0x0; census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (r, indexed) */
#define HUB_IIO_WSTAT                                0x400008 /* established */
#define HUB_IIO_WSTAT_CRAZY_SHIFT                    32 /* established */
#define HUB_IIO_WSTAT_CRAZY_MASK                     0x1ull
#define HUB_IIO_WSTAT_CRAZY_INPLACE                  (HUB_IIO_WSTAT_CRAZY_MASK << HUB_IIO_WSTAT_CRAZY_SHIFT)
#define HUB_IIO_WSTAT_LLP_TX_CNT_SHIFT               16 /* inferred */
#define HUB_IIO_WSTAT_LLP_TX_CNT_MASK                0xffull
#define HUB_IIO_WSTAT_LLP_TX_CNT_INPLACE             (HUB_IIO_WSTAT_LLP_TX_CNT_MASK << HUB_IIO_WSTAT_LLP_TX_CNT_SHIFT)
#define HUB_IIO_WSTAT_TX_MAX_RTRY_SHIFT              9 /* established */
#define HUB_IIO_WSTAT_TX_MAX_RTRY_MASK               0x1ull
#define HUB_IIO_WSTAT_TX_MAX_RTRY_INPLACE            (HUB_IIO_WSTAT_TX_MAX_RTRY_MASK << HUB_IIO_WSTAT_TX_MAX_RTRY_SHIFT)
#define HUB_IIO_WSTAT_XT_TAIL_TO_SHIFT               6 /* inferred */
#define HUB_IIO_WSTAT_XT_TAIL_TO_MASK                0x1ull
#define HUB_IIO_WSTAT_XT_TAIL_TO_INPLACE             (HUB_IIO_WSTAT_XT_TAIL_TO_MASK << HUB_IIO_WSTAT_XT_TAIL_TO_SHIFT)
#define HUB_IIO_WSTAT_XT_CRD_TO_SHIFT                5 /* inferred */
#define HUB_IIO_WSTAT_XT_CRD_TO_MASK                 0x1ull
#define HUB_IIO_WSTAT_XT_CRD_TO_INPLACE              (HUB_IIO_WSTAT_XT_CRD_TO_MASK << HUB_IIO_WSTAT_XT_CRD_TO_SHIFT)
#define HUB_IIO_WSTAT_PENDING_SHIFT                  1 /* inferred */
#define HUB_IIO_WSTAT_PENDING_MASK                   0xfull
#define HUB_IIO_WSTAT_PENDING_INPLACE                (HUB_IIO_WSTAT_PENDING_MASK << HUB_IIO_WSTAT_PENDING_SHIFT)

/*
 * The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.
 */
/* iio_wcr: r64, reset 0x4001; census: 2 sites, 2 routines */
#define HUB_IIO_WCR                                  0x400020 /* established */
#define HUB_IIO_WCR_E_THRESH_SHIFT                   18 /* established */
#define HUB_IIO_WCR_E_THRESH_MASK                    0x1full
#define HUB_IIO_WCR_E_THRESH_INPLACE                 (HUB_IIO_WCR_E_THRESH_MASK << HUB_IIO_WCR_E_THRESH_SHIFT)
#define HUB_IIO_WCR_DIR_CON_SHIFT                    17 /* established */
#define HUB_IIO_WCR_DIR_CON_MASK                     0x1ull
#define HUB_IIO_WCR_DIR_CON_INPLACE                  (HUB_IIO_WCR_DIR_CON_MASK << HUB_IIO_WCR_DIR_CON_SHIFT)
#define HUB_IIO_WCR_F_BAD_PKT_SHIFT                  16 /* established */
#define HUB_IIO_WCR_F_BAD_PKT_MASK                   0x1ull
#define HUB_IIO_WCR_F_BAD_PKT_INPLACE                (HUB_IIO_WCR_F_BAD_PKT_MASK << HUB_IIO_WCR_F_BAD_PKT_SHIFT)
#define HUB_IIO_WCR_XBAR_CRD_SHIFT                   13 /* established */
#define HUB_IIO_WCR_XBAR_CRD_MASK                    0x7ull
#define HUB_IIO_WCR_XBAR_CRD_INPLACE                 (HUB_IIO_WCR_XBAR_CRD_MASK << HUB_IIO_WCR_XBAR_CRD_SHIFT)
#define HUB_IIO_WCR_TAG_MODE_SHIFT                   4 /* established */
#define HUB_IIO_WCR_TAG_MODE_MASK                    0x1ull
#define HUB_IIO_WCR_TAG_MODE_INPLACE                 (HUB_IIO_WCR_TAG_MODE_MASK << HUB_IIO_WCR_TAG_MODE_SHIFT)
#define HUB_IIO_WCR_WIDGET_ID_SHIFT                  0 /* established */
#define HUB_IIO_WCR_WIDGET_ID_MASK                   0xfull
#define HUB_IIO_WCR_WIDGET_ID_INPLACE                (HUB_IIO_WCR_WIDGET_ID_MASK << HUB_IIO_WCR_WIDGET_ID_SHIFT)

/*
 * Local access protection register, named and placed by the public header. The header gives no fields, access type or reset. The IRIX register table confirms the access.
 */
/* iio_ilapr: rw64, reset 0xffffffffffffffff */
#define HUB_IIO_ILAPR                                0x400100 /* established */

/*
 * Protection override register, named and placed by the public header. The header gives no unlock value or behaviour, so none is imported. The IRIX register table confirms the access.
 */
/* iio_ilapo: w64, reset unknown */
#define HUB_IIO_ILAPO                                0x400108 /* established */

/*
 * The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.
 */
/* iio_iowa: rw64, reset 0x0; census: 6 sites, 3 routines */
#define HUB_IIO_IOWA                                 0x400110 /* established */
#define HUB_IIO_IOWA_WXOAC_SHIFT                     8 /* established */
#define HUB_IIO_IOWA_WXOAC_MASK                      0xffull
#define HUB_IIO_IOWA_WXOAC_INPLACE                   (HUB_IIO_IOWA_WXOAC_MASK << HUB_IIO_IOWA_WXOAC_SHIFT)
#define HUB_IIO_IOWA_W0OAC_SHIFT                     0 /* established */
#define HUB_IIO_IOWA_W0OAC_MASK                      0x1ull
#define HUB_IIO_IOWA_W0OAC_INPLACE                   (HUB_IIO_IOWA_W0OAC_MASK << HUB_IIO_IOWA_W0OAC_SHIFT)

/*
 * The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.
 */
/* iio_iiwa: r64, reset 0x0; census: 2 sites, 2 routines */
#define HUB_IIO_IIWA                                 0x400118 /* established */
#define HUB_IIO_IIWA_WXIAC_SHIFT                     8 /* established */
#define HUB_IIO_IIWA_WXIAC_MASK                      0xffull
#define HUB_IIO_IIWA_WXIAC_INPLACE                   (HUB_IIO_IIWA_WXIAC_MASK << HUB_IIO_IIWA_WXIAC_SHIFT)
#define HUB_IIO_IIWA_W0IAC_SHIFT                     0 /* established */
#define HUB_IIO_IIWA_W0IAC_MASK                      0x1ull
#define HUB_IIO_IIWA_W0IAC_INPLACE                   (HUB_IIO_IIWA_W0IAC_MASK << HUB_IIO_IIWA_W0IAC_SHIFT)

/*
 * The rsvd mask is the structure's rsvd, rsvd2, rsvd3 and rsvd4 members (the two bits at 7:6 are named rsvd1 and described as the data ready offset, so they are a field here); header naming only.
 */
/* iio_ilcsr: rw64, reset 0x3fc03ff000a; census: 2 sites, 1 routines (rw); census: 6 sites, 4 routines (rw, indexed) */
#define HUB_IIO_ILCSR                                0x400128 /* established */
#define HUB_IIO_ILCSR_MAX_BURST_SHIFT                32 /* established */
#define HUB_IIO_ILCSR_MAX_BURST_MASK                 0x3ffull
#define HUB_IIO_ILCSR_MAX_BURST_INPLACE              (HUB_IIO_ILCSR_MAX_BURST_MASK << HUB_IIO_ILCSR_MAX_BURST_SHIFT)
#define HUB_IIO_ILCSR_MAX_RETRY_SHIFT                16 /* established */
#define HUB_IIO_ILCSR_MAX_RETRY_MASK                 0x3ffull
#define HUB_IIO_ILCSR_MAX_RETRY_INPLACE              (HUB_IIO_ILCSR_MAX_RETRY_MASK << HUB_IIO_ILCSR_MAX_RETRY_SHIFT)
#define HUB_IIO_ILCSR_LNK_STAT_SHIFT                 12 /* established */
#define HUB_IIO_ILCSR_LNK_STAT_MASK                  0x3ull
#define HUB_IIO_ILCSR_LNK_STAT_INPLACE               (HUB_IIO_ILCSR_LNK_STAT_MASK << HUB_IIO_ILCSR_LNK_STAT_SHIFT)
#define HUB_IIO_ILCSR_BM8_SHIFT                      11 /* established */
#define HUB_IIO_ILCSR_BM8_MASK                       0x1ull
#define HUB_IIO_ILCSR_BM8_INPLACE                    (HUB_IIO_ILCSR_BM8_MASK << HUB_IIO_ILCSR_BM8_SHIFT)
#define HUB_IIO_ILCSR_LLP_EN_SHIFT                   10 /* established */
#define HUB_IIO_ILCSR_LLP_EN_MASK                    0x1ull
#define HUB_IIO_ILCSR_LLP_EN_INPLACE                 (HUB_IIO_ILCSR_LLP_EN_MASK << HUB_IIO_ILCSR_LLP_EN_SHIFT)
#define HUB_IIO_ILCSR_WRM_RESET_SHIFT                8 /* established */
#define HUB_IIO_ILCSR_WRM_RESET_MASK                 0x1ull
#define HUB_IIO_ILCSR_WRM_RESET_INPLACE              (HUB_IIO_ILCSR_WRM_RESET_MASK << HUB_IIO_ILCSR_WRM_RESET_SHIFT)
#define HUB_IIO_ILCSR_DATA_READY_OFFSET_SHIFT        6 /* inferred */
#define HUB_IIO_ILCSR_DATA_READY_OFFSET_MASK         0x3ull
#define HUB_IIO_ILCSR_DATA_READY_OFFSET_INPLACE      (HUB_IIO_ILCSR_DATA_READY_OFFSET_MASK << HUB_IIO_ILCSR_DATA_READY_OFFSET_SHIFT)
#define HUB_IIO_ILCSR_NULL_TO_SHIFT                  0 /* established */
#define HUB_IIO_ILCSR_NULL_TO_MASK                   0x3full
#define HUB_IIO_ILCSR_NULL_TO_INPLACE                (HUB_IIO_ILCSR_NULL_TO_MASK << HUB_IIO_ILCSR_NULL_TO_SHIFT)

/*
 * The rsvd mask is the structure's rsvd member (bits 63:32); header naming only.
 */
/* iio_illr: rw64, reset 0x0; census: 2 sites, 1 routines (rw); census: 3 sites, 2 routines (rw, indexed) */
#define HUB_IIO_ILLR                                 0x400130 /* established */
#define HUB_IIO_ILLR_CB_CNT_SHIFT                    16 /* established */
#define HUB_IIO_ILLR_CB_CNT_MASK                     0xffffull
#define HUB_IIO_ILLR_CB_CNT_INPLACE                  (HUB_IIO_ILLR_CB_CNT_MASK << HUB_IIO_ILLR_CB_CNT_SHIFT)
#define HUB_IIO_ILLR_SN_CNT_SHIFT                    0 /* established */
#define HUB_IIO_ILLR_SN_CNT_MASK                     0xffffull
#define HUB_IIO_ILLR_SN_CNT_INPLACE                  (HUB_IIO_ILLR_SN_CNT_MASK << HUB_IIO_ILLR_SN_CNT_SHIFT)

/* iio_iidsr: rw64, reset 0x0; census: 12 sites, 5 routines */
#define HUB_IIO_IIDSR                                0x400138 /* established */
#define HUB_IIO_IIDSR_SENT_SHIFT                     28 /* established */
#define HUB_IIO_IIDSR_SENT_MASK                      0x1ull
#define HUB_IIO_IIDSR_SENT_INPLACE                   (HUB_IIO_IIDSR_SENT_MASK << HUB_IIO_IIDSR_SENT_SHIFT)
#define HUB_IIO_IIDSR_ENABLE_SHIFT                   24 /* established */
#define HUB_IIO_IIDSR_ENABLE_MASK                    0x1ull
#define HUB_IIO_IIDSR_ENABLE_INPLACE                 (HUB_IIO_IIDSR_ENABLE_MASK << HUB_IIO_IIDSR_ENABLE_SHIFT)
#define HUB_IIO_IIDSR_NODE_SHIFT                     8 /* inferred */
#define HUB_IIO_IIDSR_NODE_MASK                      0x1ffull
#define HUB_IIO_IIDSR_NODE_INPLACE                   (HUB_IIO_IIDSR_NODE_MASK << HUB_IIO_IIDSR_NODE_SHIFT)
#define HUB_IIO_IIDSR_LEVEL_SHIFT                    0 /* inferred */
#define HUB_IIO_IIDSR_LEVEL_MASK                     0x7full
#define HUB_IIO_IIDSR_LEVEL_INPLACE                  (HUB_IIO_IIDSR_LEVEL_MASK << HUB_IIO_IIDSR_LEVEL_SHIFT)

/*
 * The layout is the same as iio_igfx_1.
 */
/* iio_igfx_0: rw64, reset unknown; census: 2 sites, 1 routines */
#define HUB_IIO_IGFX_0                               0x400140 /* established */
#define HUB_IIO_IGFX_0_VALID_SHIFT                   20 /* established */
#define HUB_IIO_IGFX_0_VALID_MASK                    0x1ull
#define HUB_IIO_IGFX_0_VALID_INPLACE                 (HUB_IIO_IGFX_0_VALID_MASK << HUB_IIO_IGFX_0_VALID_SHIFT)
#define HUB_IIO_IGFX_0_PROCESSOR_SHIFT               16 /* established */
#define HUB_IIO_IGFX_0_PROCESSOR_MASK                0x1ull
#define HUB_IIO_IGFX_0_PROCESSOR_INPLACE             (HUB_IIO_IGFX_0_PROCESSOR_MASK << HUB_IIO_IGFX_0_PROCESSOR_SHIFT)
#define HUB_IIO_IGFX_0_NODE_SHIFT                    4 /* established */
#define HUB_IIO_IGFX_0_NODE_MASK                     0x1ffull
#define HUB_IIO_IGFX_0_NODE_INPLACE                  (HUB_IIO_IGFX_0_NODE_MASK << HUB_IIO_IGFX_0_NODE_SHIFT)
#define HUB_IIO_IGFX_0_WIDGET_SHIFT                  0 /* established */
#define HUB_IIO_IGFX_0_WIDGET_MASK                   0xfull
#define HUB_IIO_IGFX_0_WIDGET_INPLACE                (HUB_IIO_IGFX_0_WIDGET_MASK << HUB_IIO_IGFX_0_WIDGET_SHIFT)

/*
 * Graphics node and widget register 1, the twin of iio_igfx_0 in the census. The header gives both the same field layout: widget number in bits 3:0, node number in bits 12:4, processor number at bit 16 and a valid bit at bit 20. The header gives no access type, so rw is assumed.
 */
/* iio_igfx_1: rw64, reset unknown */
#define HUB_IIO_IGFX_1                               0x400148 /* inferred */
#define HUB_IIO_IGFX_1_VALID_SHIFT                   20 /* established */
#define HUB_IIO_IGFX_1_VALID_MASK                    0x1ull
#define HUB_IIO_IGFX_1_VALID_INPLACE                 (HUB_IIO_IGFX_1_VALID_MASK << HUB_IIO_IGFX_1_VALID_SHIFT)
#define HUB_IIO_IGFX_1_PROCESSOR_SHIFT               16 /* established */
#define HUB_IIO_IGFX_1_PROCESSOR_MASK                0x1ull
#define HUB_IIO_IGFX_1_PROCESSOR_INPLACE             (HUB_IIO_IGFX_1_PROCESSOR_MASK << HUB_IIO_IGFX_1_PROCESSOR_SHIFT)
#define HUB_IIO_IGFX_1_NODE_SHIFT                    4 /* established */
#define HUB_IIO_IGFX_1_NODE_MASK                     0x1ffull
#define HUB_IIO_IGFX_1_NODE_INPLACE                  (HUB_IIO_IGFX_1_NODE_MASK << HUB_IIO_IGFX_1_NODE_SHIFT)
#define HUB_IIO_IGFX_1_WIDGET_SHIFT                  0 /* established */
#define HUB_IIO_IGFX_1_WIDGET_MASK                   0xfull
#define HUB_IIO_IGFX_1_WIDGET_INPLACE                (HUB_IIO_IGFX_1_WIDGET_MASK << HUB_IIO_IGFX_1_WIDGET_SHIFT)

/*
 * Scratch register 0. The header names its bit uses for software only and gives a mask of the bits that exist, 0x0000000f00f11fff. The IRIX register table confirms the access. Only the bits in the header's IIO_SCRATCH_MASK, 0x0000000f00f11fff, exist; the rsvd mask is its complement. Established as the header's statement that not all bits are available; whether the missing bits read zero is not stated.
 */
/* iio_scratch_reg0: rw64, reset 0x0 */
#define HUB_IIO_SCRATCH_REG0                         0x400150 /* established */

/*
 * Scratch register 1, the twin of register 0. The IRIX register table confirms the access. Only the bits in the header's IIO_SCRATCH_MASK, 0x0000000f00f11fff, exist; the rsvd mask is its complement. Established as the header's statement that not all bits are available; whether the missing bits read zero is not stated.
 */
/* iio_scratch_reg1: rw64, reset 0x0 */
#define HUB_IIO_SCRATCH_REG1                         0x400158 /* established */

/*
 * Big-window translation entry n, for n from 0 to 6. Entry 0 is at the register offset and each later entry is eight bytes further on. The IRIX register table confirms the access.
 */
/* iio_itte: rw64, reset 0x0 */
#define HUB_IIO_ITTE                                 0x400160 /* established */
#define HUB_IIO_ITTE_COUNT                           7
#define HUB_IIO_ITTE_STRIDE                          8
#define HUB_IIO_ITTE_IOSPACE_SHIFT                   12 /* established */
#define HUB_IIO_ITTE_IOSPACE_MASK                    0x1ull
#define HUB_IIO_ITTE_IOSPACE_INPLACE                 (HUB_IIO_ITTE_IOSPACE_MASK << HUB_IIO_ITTE_IOSPACE_SHIFT)
#define HUB_IIO_ITTE_WIDGET_SHIFT                    8 /* established */
#define HUB_IIO_ITTE_WIDGET_MASK                     0xfull
#define HUB_IIO_ITTE_WIDGET_INPLACE                  (HUB_IIO_ITTE_WIDGET_MASK << HUB_IIO_ITTE_WIDGET_SHIFT)
#define HUB_IIO_ITTE_SLICE_SHIFT                     0 /* established */
#define HUB_IIO_ITTE_SLICE_MASK                      0x1full
#define HUB_IIO_ITTE_SLICE_INPLACE                   (HUB_IIO_ITTE_SLICE_MASK << HUB_IIO_ITTE_SLICE_SHIFT)

/* iio_imem: rw64, reset unknown; census: 4 sites, 3 routines */
#define HUB_IIO_IMEM                                 0x4001e8 /* established */
#define HUB_IIO_IMEM_B1ESD_SHIFT                     8 /* established */
#define HUB_IIO_IMEM_B1ESD_MASK                      0x1ull
#define HUB_IIO_IMEM_B1ESD_INPLACE                   (HUB_IIO_IMEM_B1ESD_MASK << HUB_IIO_IMEM_B1ESD_SHIFT)
#define HUB_IIO_IMEM_B0ESD_SHIFT                     4 /* established */
#define HUB_IIO_IMEM_B0ESD_MASK                      0x1ull
#define HUB_IIO_IMEM_B0ESD_INPLACE                   (HUB_IIO_IMEM_B0ESD_MASK << HUB_IIO_IMEM_B0ESD_SHIFT)
#define HUB_IIO_IMEM_W0ESD_SHIFT                     0 /* established */
#define HUB_IIO_IMEM_W0ESD_MASK                      0x1ull
#define HUB_IIO_IMEM_W0ESD_INPLACE                   (HUB_IIO_IMEM_W0ESD_MASK << HUB_IIO_IMEM_W0ESD_SHIFT)

/*
 * The header calls each bit a clear bit; whether the register is write-1-to-clear is not stated, so no w1c mask is recorded.
 */
/* iio_ieclr: rw64, reset unknown; census: 2 sites, 1 routines (w); census: 5 sites, 4 routines (rw, indexed) */
#define HUB_IIO_IECLR                                0x4001f8 /* established */
#define HUB_IIO_IECLR_BTE1_SHIFT                     18 /* inferred */
#define HUB_IIO_IECLR_BTE1_MASK                      0x1ull
#define HUB_IIO_IECLR_BTE1_INPLACE                   (HUB_IIO_IECLR_BTE1_MASK << HUB_IIO_IECLR_BTE1_SHIFT)
#define HUB_IIO_IECLR_BTE0_SHIFT                     17 /* inferred */
#define HUB_IIO_IECLR_BTE0_MASK                      0x1ull
#define HUB_IIO_IECLR_BTE0_INPLACE                   (HUB_IIO_IECLR_BTE0_MASK << HUB_IIO_IECLR_BTE0_SHIFT)
#define HUB_IIO_IECLR_CRAZY_SHIFT                    16 /* established */
#define HUB_IIO_IECLR_CRAZY_MASK                     0x1ull
#define HUB_IIO_IECLR_CRAZY_INPLACE                  (HUB_IIO_IECLR_CRAZY_MASK << HUB_IIO_IECLR_CRAZY_SHIFT)
#define HUB_IIO_IECLR_PRB_F_SHIFT                    15 /* established */
#define HUB_IIO_IECLR_PRB_F_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_F_INPLACE                  (HUB_IIO_IECLR_PRB_F_MASK << HUB_IIO_IECLR_PRB_F_SHIFT)
#define HUB_IIO_IECLR_PRB_E_SHIFT                    14 /* established */
#define HUB_IIO_IECLR_PRB_E_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_E_INPLACE                  (HUB_IIO_IECLR_PRB_E_MASK << HUB_IIO_IECLR_PRB_E_SHIFT)
#define HUB_IIO_IECLR_PRB_D_SHIFT                    13 /* established */
#define HUB_IIO_IECLR_PRB_D_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_D_INPLACE                  (HUB_IIO_IECLR_PRB_D_MASK << HUB_IIO_IECLR_PRB_D_SHIFT)
#define HUB_IIO_IECLR_PRB_C_SHIFT                    12 /* established */
#define HUB_IIO_IECLR_PRB_C_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_C_INPLACE                  (HUB_IIO_IECLR_PRB_C_MASK << HUB_IIO_IECLR_PRB_C_SHIFT)
#define HUB_IIO_IECLR_PRB_B_SHIFT                    11 /* established */
#define HUB_IIO_IECLR_PRB_B_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_B_INPLACE                  (HUB_IIO_IECLR_PRB_B_MASK << HUB_IIO_IECLR_PRB_B_SHIFT)
#define HUB_IIO_IECLR_PRB_A_SHIFT                    10 /* established */
#define HUB_IIO_IECLR_PRB_A_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_A_INPLACE                  (HUB_IIO_IECLR_PRB_A_MASK << HUB_IIO_IECLR_PRB_A_SHIFT)
#define HUB_IIO_IECLR_PRB_9_SHIFT                    9 /* established */
#define HUB_IIO_IECLR_PRB_9_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_9_INPLACE                  (HUB_IIO_IECLR_PRB_9_MASK << HUB_IIO_IECLR_PRB_9_SHIFT)
#define HUB_IIO_IECLR_PRB_8_SHIFT                    8 /* established */
#define HUB_IIO_IECLR_PRB_8_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_8_INPLACE                  (HUB_IIO_IECLR_PRB_8_MASK << HUB_IIO_IECLR_PRB_8_SHIFT)
#define HUB_IIO_IECLR_PRB_0_SHIFT                    0 /* established */
#define HUB_IIO_IECLR_PRB_0_MASK                     0x1ull
#define HUB_IIO_IECLR_PRB_0_INPLACE                  (HUB_IIO_IECLR_PRB_0_MASK << HUB_IIO_IECLR_PRB_0_SHIFT)

/*
 * Reads here cause a bus error, per the header's comment. The header gives no layout and no reset. The access letter is the comment's reading and is graded inferred.
 */
/* iio_iibuserr: r64, reset unknown; public Linux SN0 Hub I/O header: IIO_IIBUSERR (offset and name; the header lists it as 0x1400208 in the local I/O window, which is this offset past the 0x1000000 window base) */
#define HUB_IIO_IIBUSERR                             0x400208 /* inferred */

/* iio_ipdr: rw64, reset 0x0; census: 5 sites, 2 routines */
#define HUB_IIO_IPDR                                 0x400388 /* established */
#define HUB_IIO_IPDR_PND_SHIFT                       4 /* established */
#define HUB_IIO_IPDR_PND_MASK                        0x1ull
#define HUB_IIO_IPDR_PND_INPLACE                     (HUB_IIO_IPDR_PND_MASK << HUB_IIO_IPDR_PND_SHIFT)

/* iio_icdr: rw64, reset 0x0; census: 3 sites, 1 routines */
#define HUB_IIO_ICDR                                 0x400390 /* established */
#define HUB_IIO_ICDR_PND_SHIFT                       4 /* established */
#define HUB_IIO_ICDR_PND_MASK                        0x1ull
#define HUB_IIO_ICDR_PND_INPLACE                     (HUB_IIO_ICDR_PND_MASK << HUB_IIO_ICDR_PND_SHIFT)

/*
 * The rsvd mask is the structure's rsvd and rsvd1 members; header naming only.
 */
/* iio_ifdr: rw64, reset 0x0; census: 8 sites, 3 routines */
#define HUB_IIO_IFDR                                 0x400398 /* established */
#define HUB_IIO_IFDR_MAXRP_SHIFT                     8 /* established */
#define HUB_IIO_IFDR_MAXRP_MASK                      0x7full
#define HUB_IIO_IFDR_MAXRP_INPLACE                   (HUB_IIO_IFDR_MAXRP_MASK << HUB_IIO_IFDR_MAXRP_SHIFT)
#define HUB_IIO_IFDR_MAXRQ_SHIFT                     0 /* established */
#define HUB_IIO_IFDR_MAXRQ_MASK                      0x7full
#define HUB_IIO_IFDR_MAXRQ_INPLACE                   (HUB_IIO_IFDR_MAXRQ_MASK << HUB_IIO_IFDR_MAXRQ_SHIFT)

/* iio_icmr: rw64, reset 0x0; census: 6 sites, 3 routines */
#define HUB_IIO_ICMR                                 0x4003a8 /* established */
#define HUB_IIO_ICMR_PRECISE_SHIFT                   52 /* established */
#define HUB_IIO_ICMR_PRECISE_MASK                    0x1ull
#define HUB_IIO_ICMR_PRECISE_INPLACE                 (HUB_IIO_ICMR_PRECISE_MASK << HUB_IIO_ICMR_PRECISE_SHIFT)
#define HUB_IIO_ICMR_PC_VLD_SHIFT                    36 /* established */
#define HUB_IIO_ICMR_PC_VLD_MASK                     0x7fffull
#define HUB_IIO_ICMR_PC_VLD_INPLACE                  (HUB_IIO_ICMR_PC_VLD_MASK << HUB_IIO_ICMR_PC_VLD_SHIFT)
#define HUB_IIO_ICMR_CRB_VLD_SHIFT                   20 /* established */
#define HUB_IIO_ICMR_CRB_VLD_MASK                    0x7fffull
#define HUB_IIO_ICMR_CRB_VLD_INPLACE                 (HUB_IIO_ICMR_CRB_VLD_MASK << HUB_IIO_ICMR_CRB_VLD_SHIFT)
#define HUB_IIO_ICMR_FC_CNT_SHIFT                    16 /* established */
#define HUB_IIO_ICMR_FC_CNT_MASK                     0xfull
#define HUB_IIO_ICMR_FC_CNT_INPLACE                  (HUB_IIO_ICMR_FC_CNT_MASK << HUB_IIO_ICMR_FC_CNT_SHIFT)
#define HUB_IIO_ICMR_CLR_RPPD_SHIFT                  13 /* established */
#define HUB_IIO_ICMR_CLR_RPPD_MASK                   0x1ull
#define HUB_IIO_ICMR_CLR_RPPD_INPLACE                (HUB_IIO_ICMR_CLR_RPPD_MASK << HUB_IIO_ICMR_CLR_RPPD_SHIFT)
#define HUB_IIO_ICMR_CLR_RQPD_SHIFT                  12 /* established */
#define HUB_IIO_ICMR_CLR_RQPD_MASK                   0x1ull
#define HUB_IIO_ICMR_CLR_RQPD_INPLACE                (HUB_IIO_ICMR_CLR_RQPD_MASK << HUB_IIO_ICMR_CLR_RQPD_SHIFT)
#define HUB_IIO_ICMR_C_CNT_SHIFT                     4 /* established */
#define HUB_IIO_ICMR_C_CNT_MASK                      0xfull
#define HUB_IIO_ICMR_C_CNT_INPLACE                   (HUB_IIO_ICMR_C_CNT_MASK << HUB_IIO_ICMR_C_CNT_SHIFT)
#define HUB_IIO_ICMR_P_CNT_SHIFT                     0 /* established */
#define HUB_IIO_ICMR_P_CNT_MASK                      0xfull
#define HUB_IIO_ICMR_P_CNT_INPLACE                   (HUB_IIO_ICMR_P_CNT_MASK << HUB_IIO_ICMR_P_CNT_SHIFT)

/*
 * The header gives the commands as values already in place (0x100, 0x200, 0x400, 0x800) next to a command mask of 0xff at shift 7, which disagree; they are recorded here as single bits, graded inferred.
 */
/* iio_iccr: rw64, reset 0x0; census: 7 sites, 1 routines */
#define HUB_IIO_ICCR                                 0x4003b0 /* established */
#define HUB_IIO_ICCR_PENDING_SHIFT                   16 /* established */
#define HUB_IIO_ICCR_PENDING_MASK                    0x1ull
#define HUB_IIO_ICCR_PENDING_INPLACE                 (HUB_IIO_ICCR_PENDING_MASK << HUB_IIO_ICCR_PENDING_SHIFT)
#define HUB_IIO_ICCR_FLUSH_SHIFT                     11 /* inferred */
#define HUB_IIO_ICCR_FLUSH_MASK                      0x1ull
#define HUB_IIO_ICCR_FLUSH_INPLACE                   (HUB_IIO_ICCR_FLUSH_MASK << HUB_IIO_ICCR_FLUSH_SHIFT)
#define HUB_IIO_ICCR_EJECT_SHIFT                     10 /* inferred */
#define HUB_IIO_ICCR_EJECT_MASK                      0x1ull
#define HUB_IIO_ICCR_EJECT_INPLACE                   (HUB_IIO_ICCR_EJECT_MASK << HUB_IIO_ICCR_EJECT_SHIFT)
#define HUB_IIO_ICCR_TIMEOUT_SHIFT                   9 /* inferred */
#define HUB_IIO_ICCR_TIMEOUT_MASK                    0x1ull
#define HUB_IIO_ICCR_TIMEOUT_INPLACE                 (HUB_IIO_ICCR_TIMEOUT_MASK << HUB_IIO_ICCR_TIMEOUT_SHIFT)
#define HUB_IIO_ICCR_WAKE_SHIFT                      8 /* inferred */
#define HUB_IIO_ICCR_WAKE_MASK                       0x1ull
#define HUB_IIO_ICCR_WAKE_INPLACE                    (HUB_IIO_ICCR_WAKE_MASK << HUB_IIO_ICCR_WAKE_SHIFT)

/* iio_ibls_0: rw64, reset 0x0; census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) */
#define HUB_IIO_IBLS_0                               0x410000 /* established */
#define HUB_IIO_IBLS_0_BUSY_SHIFT                    20 /* established */
#define HUB_IIO_IBLS_0_BUSY_MASK                     0x1ull
#define HUB_IIO_IBLS_0_BUSY_INPLACE                  (HUB_IIO_IBLS_0_BUSY_MASK << HUB_IIO_IBLS_0_BUSY_SHIFT)
#define HUB_IIO_IBLS_0_ERROR_SHIFT                   16 /* established */
#define HUB_IIO_IBLS_0_ERROR_MASK                    0x1ull
#define HUB_IIO_IBLS_0_ERROR_INPLACE                 (HUB_IIO_IBLS_0_ERROR_MASK << HUB_IIO_IBLS_0_ERROR_SHIFT)
#define HUB_IIO_IBLS_0_LENGTH_SHIFT                  0 /* established */
#define HUB_IIO_IBLS_0_LENGTH_MASK                   0xffffull
#define HUB_IIO_IBLS_0_LENGTH_INPLACE                (HUB_IIO_IBLS_0_LENGTH_MASK << HUB_IIO_IBLS_0_LENGTH_SHIFT)

/* iio_ibct_0: r64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_IIO_IBCT_0                               0x410018 /* established */
#define HUB_IIO_IBCT_0_POISON_SHIFT                  8 /* established */
#define HUB_IIO_IBCT_0_POISON_MASK                   0x1ull
#define HUB_IIO_IBCT_0_POISON_INPLACE                (HUB_IIO_IBCT_0_POISON_MASK << HUB_IIO_IBCT_0_POISON_SHIFT)
#define HUB_IIO_IBCT_0_NOTIFY_SHIFT                  4 /* established */
#define HUB_IIO_IBCT_0_NOTIFY_MASK                   0x1ull
#define HUB_IIO_IBCT_0_NOTIFY_INPLACE                (HUB_IIO_IBCT_0_NOTIFY_MASK << HUB_IIO_IBCT_0_NOTIFY_SHIFT)
#define HUB_IIO_IBCT_0_ZFIL_MODE_SHIFT               0 /* established */
#define HUB_IIO_IBCT_0_ZFIL_MODE_MASK                0x1ull
#define HUB_IIO_IBCT_0_ZFIL_MODE_INPLACE             (HUB_IIO_IBCT_0_ZFIL_MODE_MASK << HUB_IIO_IBCT_0_ZFIL_MODE_SHIFT)

/*
 * Notification address of engine 0, the twin of the engine 1 slot in the census. Offset and name are from the public header. The IRIX register table confirms the access.
 */
/* iio_ibna_0: rw64, reset 0x0 */
#define HUB_IIO_IBNA_0                               0x410020 /* established */

/*
 * Interrupt address of engine 0. Offset and name are from the public header. The IRIX register table confirms the access.
 */
/* iio_ibia_0: rw64, reset 0x0 */
#define HUB_IIO_IBIA_0                               0x410028 /* established */
#define HUB_IIO_IBIA_0_LEVEL_SHIFT                   16 /* established */
#define HUB_IIO_IBIA_0_LEVEL_MASK                    0x7full
#define HUB_IIO_IBIA_0_LEVEL_INPLACE                 (HUB_IIO_IBIA_0_LEVEL_MASK << HUB_IIO_IBIA_0_LEVEL_SHIFT)
#define HUB_IIO_IBIA_0_NODE_SHIFT                    0 /* established */
#define HUB_IIO_IBIA_0_NODE_MASK                     0x1ffull
#define HUB_IIO_IBIA_0_NODE_INPLACE                  (HUB_IIO_IBIA_0_NODE_MASK << HUB_IIO_IBIA_0_NODE_SHIFT)

/* iio_ibls_1: rw64, reset 0x0; census: 1 sites, 1 routines (r); census: 3 sites, 1 routines (rw, indexed) */
#define HUB_IIO_IBLS_1                               0x420000 /* established */
#define HUB_IIO_IBLS_1_BUSY_SHIFT                    20 /* established */
#define HUB_IIO_IBLS_1_BUSY_MASK                     0x1ull
#define HUB_IIO_IBLS_1_BUSY_INPLACE                  (HUB_IIO_IBLS_1_BUSY_MASK << HUB_IIO_IBLS_1_BUSY_SHIFT)
#define HUB_IIO_IBLS_1_ERROR_SHIFT                   16 /* established */
#define HUB_IIO_IBLS_1_ERROR_MASK                    0x1ull
#define HUB_IIO_IBLS_1_ERROR_INPLACE                 (HUB_IIO_IBLS_1_ERROR_MASK << HUB_IIO_IBLS_1_ERROR_SHIFT)
#define HUB_IIO_IBLS_1_LENGTH_SHIFT                  0 /* established */
#define HUB_IIO_IBLS_1_LENGTH_MASK                   0xffffull
#define HUB_IIO_IBLS_1_LENGTH_INPLACE                (HUB_IIO_IBLS_1_LENGTH_MASK << HUB_IIO_IBLS_1_LENGTH_SHIFT)

/* iio_ibct_1: rw64, reset 0x0; census: 3 sites, 1 routines */
#define HUB_IIO_IBCT_1                               0x420018 /* established */
#define HUB_IIO_IBCT_1_POISON_SHIFT                  8 /* established */
#define HUB_IIO_IBCT_1_POISON_MASK                   0x1ull
#define HUB_IIO_IBCT_1_POISON_INPLACE                (HUB_IIO_IBCT_1_POISON_MASK << HUB_IIO_IBCT_1_POISON_SHIFT)
#define HUB_IIO_IBCT_1_NOTIFY_SHIFT                  4 /* established */
#define HUB_IIO_IBCT_1_NOTIFY_MASK                   0x1ull
#define HUB_IIO_IBCT_1_NOTIFY_INPLACE                (HUB_IIO_IBCT_1_NOTIFY_MASK << HUB_IIO_IBCT_1_NOTIFY_SHIFT)
#define HUB_IIO_IBCT_1_ZFIL_MODE_SHIFT               0 /* established */
#define HUB_IIO_IBCT_1_ZFIL_MODE_MASK                0x1ull
#define HUB_IIO_IBCT_1_ZFIL_MODE_INPLACE             (HUB_IIO_IBCT_1_ZFIL_MODE_MASK << HUB_IIO_IBCT_1_ZFIL_MODE_SHIFT)

/*
 * Interrupt address of engine 1. Offset and name are from the public header. The IRIX register table confirms the access.
 */
/* iio_ibia_1: rw64, reset 0x0 */
#define HUB_IIO_IBIA_1                               0x420028 /* established */
#define HUB_IIO_IBIA_1_LEVEL_SHIFT                   16 /* established */
#define HUB_IIO_IBIA_1_LEVEL_MASK                    0x7full
#define HUB_IIO_IBIA_1_LEVEL_INPLACE                 (HUB_IIO_IBIA_1_LEVEL_MASK << HUB_IIO_IBIA_1_LEVEL_SHIFT)
#define HUB_IIO_IBIA_1_NODE_SHIFT                    0 /* established */
#define HUB_IIO_IBIA_1_NODE_MASK                     0x1ffull
#define HUB_IIO_IBIA_1_NODE_INPLACE                  (HUB_IIO_IBIA_1_NODE_MASK << HUB_IIO_IBIA_1_NODE_SHIFT)

/*
 * Layout is the header's performance-select structure, io_perf_sel; which register that structure belongs to is inferred from the register names.
 */
/* iio_ipcr: rw64, reset unknown; census: 4 sites, 2 routines */
#define HUB_IIO_IPCR                                 0x430000 /* established */
#define HUB_IIO_IPCR_ICCT_SHIFT                      8 /* inferred */
#define HUB_IIO_IPCR_ICCT_MASK                       0xffull
#define HUB_IIO_IPCR_ICCT_INPLACE                    (HUB_IIO_IPCR_ICCT_MASK << HUB_IIO_IPCR_ICCT_SHIFT)
#define HUB_IIO_IPCR_IPPR1_SHIFT                     4 /* inferred */
#define HUB_IIO_IPCR_IPPR1_MASK                      0xfull
#define HUB_IIO_IPCR_IPPR1_INPLACE                   (HUB_IIO_IPCR_IPPR1_MASK << HUB_IIO_IPCR_IPPR1_SHIFT)
#define HUB_IIO_IPCR_IPPR0_SHIFT                     0 /* inferred */
#define HUB_IIO_IPCR_IPPR0_MASK                      0xfull
#define HUB_IIO_IPCR_IPPR0_INPLACE                   (HUB_IIO_IPCR_IPPR0_MASK << HUB_IIO_IPCR_IPPR0_SHIFT)

/*
 * Layout is the header's performance-count structure; its offset equals the header's IIO_PERF_CNT, 0x430008.
 */
/* iio_ippr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_IIO_IPPR                                 0x430008 /* established */
#define HUB_IIO_IPPR_COUNT_SHIFT                     0 /* inferred */
#define HUB_IIO_IPPR_COUNT_MASK                      0xfffffull
#define HUB_IIO_IPPR_COUNT_INPLACE                   (HUB_IIO_IPPR_COUNT_MASK << HUB_IIO_IPPR_COUNT_SHIFT)

#define HUB_HUB_NUM_WIDGET                           0x9u /* established */
#define HUB_HUB_WIDGET_ID_MAX                        0xfu /* established */
#define HUB_HUB_WIDGET_ID_MIN                        0x8u /* established */
#define HUB_IIO_BASE                                 0x400000u /* established */
#define HUB_IIO_BASE_BTE0                            0x410000u /* established */
#define HUB_IIO_BASE_BTE1                            0x420000u /* established */
#define HUB_IIO_BASE_PERF                            0x430000u /* established */
#define HUB_IIO_IBCT_NOTIFY                          0x10u /* established */
#define HUB_IIO_IBCT_POISON                          0x100u /* established */
#define HUB_IIO_IBCT_ZFIL_MODE                       0x1u /* established */
#define HUB_IIO_IBLS_BUSY                            0x100000u /* established */
#define HUB_IIO_IECLR_BTE0                           0x20000u /* inferred */
#define HUB_IIO_IECLR_BTE1                           0x40000u /* inferred */
#define HUB_IIO_IIDSR_ENB                            0x1000000u /* established */
#define HUB_IIO_IIDSR_LVL_MASK                       0x3fu /* established */
#define HUB_IIO_IIDSR_SENT                           0x10000000u /* established */
#define HUB_IIO_ILCSR_BM8                            0x800u /* established */
#define HUB_IIO_ILCSR_LLP_EN                         0x400u /* established */
#define HUB_IIO_ILCSR_WARM_RESET                     0x100u /* established */
#define HUB_IIO_ITTE_BASE                            0x400160u /* established */
#define HUB_IIO_ITTE_INVALID_WIDGET                  0x3u /* established */
#define HUB_IIO_ITTE_IOSP                            0x1000u /* established */
#define HUB_IIO_LLP_CSR_IS_UP                        0x2000u /* established */
#define HUB_IIO_LLP_CSR_LLP_STAT_MASK                0x3000u /* established */
#define HUB_IIO_NUM_CRBS                             0xfu /* established */
#define HUB_IIO_NUM_IPRBS                            0x9u /* established */
#define HUB_IIO_NUM_ITTES                            0x7u /* established */
#define HUB_IIO_NUM_NORMAL_CRBS                      0xcu /* established */
#define HUB_IIO_NUM_PC_CRBS                          0x4u /* established */
#define HUB_IIO_NUM_PRTES                            0x8u /* established */
#define HUB_IIO_PROTECT_OVRRD_KEY                    0x53474972756c6573ull /* established */
#define HUB_IIO_SCRATCH_MASK                         0xf00f11fffull /* established */
#define HUB_IIO_WCR_DIR_CON                          0x20000u /* established */
#define HUB_IIO_WID_PART_HUB                         0xc101u /* established */
#define HUB_IIO_WSTAT_ECRAZY                         0x100000000ull /* established */
#define HUB_IIO_WSTAT_TXRETRY                        0x200u /* established */
#define HUB_IIO_WSTAT_TXRETRY_MASK                   0x7f0000u /* established */
#define HUB_LNK_STAT_WORKING                         0x2u /* established */

#endif /* HUB_GEN_H */
