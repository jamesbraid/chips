/* generated from devices/hub/registers-extra.toml by defs-gen - do not edit, change the source */
/* Hub block transfer engine registers and control bits outside the census */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


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
 * Scratch register 0. The header names its bit uses for software only and gives a mask of the bits that exist, 0x0000000f00f11fff. The IRIX register table confirms the access.
 */
/* iio_scratch_reg0: rw64, reset 0x0 */
#define HUB_IIO_SCRATCH_REG0                         0x400150 /* established */

/*
 * Scratch register 1, the twin of register 0. The IRIX register table confirms the access.
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

/*
 * Word A of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individually. The header gives no access type, so the access is carried over from the census row of entry 0 (read-write) and is inferred.
 */
/* iio_icrb_a: rw64, reset unknown; public Linux SN0 Hub I/O header, pinned linux tree: IIO_ICRB_A(x) macro, 15 entries (IIO_NUM_CRBS) four words apart */
#define HUB_IIO_ICRB_A                               0x400400 /* inferred */
#define HUB_IIO_ICRB_A_COUNT                         15
#define HUB_IIO_ICRB_A_STRIDE                        32

/*
 * Word B of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individually. The header gives no access type, so the access is carried over from the census row of entry 0 (read-write) and is inferred.
 */
/* iio_icrb_b: rw64, reset unknown; public Linux SN0 Hub I/O header, pinned linux tree: IIO_ICRB_B(x) macro, 15 entries (IIO_NUM_CRBS) four words apart */
#define HUB_IIO_ICRB_B                               0x400408 /* inferred */
#define HUB_IIO_ICRB_B_COUNT                         15
#define HUB_IIO_ICRB_B_STRIDE                        32

/*
 * Word C of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individually. The header gives no access type, so read-only is carried over from the census row of entry 0 and is inferred.
 */
/* iio_icrb_c: r64, reset unknown; public Linux SN0 Hub I/O header, pinned linux tree: IIO_ICRB_C(x) macro, 15 entries (IIO_NUM_CRBS) four words apart */
#define HUB_IIO_ICRB_C                               0x400410 /* inferred */
#define HUB_IIO_ICRB_C_COUNT                         15
#define HUB_IIO_ICRB_C_STRIDE                        32

/*
 * Word D of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individually. The header gives no access type, so read-only is carried over from the census row of entry 0 and is inferred.
 */
/* iio_icrb_d: r64, reset unknown; public Linux SN0 Hub I/O header, pinned linux tree: IIO_ICRB_D(x) macro, 15 entries (IIO_NUM_CRBS) four words apart */
#define HUB_IIO_ICRB_D                               0x400418 /* inferred */
#define HUB_IIO_ICRB_D_COUNT                         15
#define HUB_IIO_ICRB_D_STRIDE                        32

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

#define HUB_IIO_IBCT_NOTIFY                          0x10u /* established */
#define HUB_IIO_IBCT_POISON                          0x100u /* established */
#define HUB_IIO_IBCT_ZFIL_MODE                       0x1u /* established */
#define HUB_IIO_IBLS_BUSY                            0x100000u /* established */
#define HUB_IIO_IECLR_BTE0                           0x20000u /* inferred */
#define HUB_IIO_IECLR_BTE1                           0x40000u /* inferred */
#define HUB_IIO_IIDSR_ENB                            0x1000000u /* established */
#define HUB_IIO_IIDSR_LVL_MASK                       0x3fu /* established */
#define HUB_IIO_IIDSR_NODE_MASK                      0xff00u /* established */
#define HUB_IIO_IIDSR_SENT                           0x10000000u /* established */
#define HUB_IIO_ILCSR_BM8                            0x800u /* established */
#define HUB_IIO_ILCSR_LLP_EN                         0x400u /* established */
#define HUB_IIO_ILCSR_MAX_BURST_MASK                 0x3ff00000000ull /* established */
#define HUB_IIO_ILCSR_MAX_RETRY_MASK                 0x3ff0000u /* established */
#define HUB_IIO_ILCSR_NULL_TO_MASK                   0x3fu /* established */
#define HUB_IIO_ILCSR_WARM_RESET                     0x100u /* established */
#define HUB_IIO_ILLR_CB_CNT_MASK                     0xffff0000u /* established */
#define HUB_IIO_ILLR_SN_CNT_MASK                     0xffffu /* established */
#define HUB_IIO_ITTE_BASE                            0x400160u /* established */
#define HUB_IIO_ITTE_INVALID_WIDGET                  0x3u /* established */
#define HUB_IIO_ITTE_IOSP                            0x1000u /* established */
#define HUB_IIO_LLP_CSR_IS_UP                        0x2000u /* established */
#define HUB_IIO_LLP_CSR_LLP_STAT_MASK                0x3000u /* established */
#define HUB_IIO_WCR_DIR_CON                          0x20000u /* established */
#define HUB_IIO_WCR_WIDGET_ID_MASK                   0xfu /* established */
#define HUB_IIO_WID_PART_HUB                         0xc101u /* established */
#define HUB_IIO_WSTAT_ECRAZY                         0x100000000ull /* established */
#define HUB_IIO_WSTAT_TXRETRY                        0x200u /* established */
#define HUB_IIO_WSTAT_TXRETRY_MASK                   0x7f0000u /* established */
#define HUB_LNK_STAT_WORKING                         0x2u /* established */

#endif /* HUB_GEN_H */
