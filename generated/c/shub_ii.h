/* generated from devices/shub_ii/registers.toml by defs-gen - do not edit, change the source */
/* SHub 1 I/O interface (II): Crosstalk port, access protection, CRBs and block transfer engines */
#ifndef SHUB_II_GEN_H
#define SHUB_II_GEN_H

#include <stdint.h>


/*
 * Crosstalk widget identification. Echoes the revision and manufacturer fields of the local block's revision register and carries the part number SGI assigned to SHub. Also visible to a widget on the link at its own offset 0. Header name IIO_WID.
 */
/* widget_id: r64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WIDGET_ID                            0x400000 /* established */
#define SHUB_II_WIDGET_ID_REV_NUM_SHIFT              28 /* established */
#define SHUB_II_WIDGET_ID_REV_NUM_MASK               0xfull
#define SHUB_II_WIDGET_ID_REV_NUM_INPLACE            (SHUB_II_WIDGET_ID_REV_NUM_MASK << SHUB_II_WIDGET_ID_REV_NUM_SHIFT)
#define SHUB_II_WIDGET_ID_PART_NUM_SHIFT             12 /* established */
#define SHUB_II_WIDGET_ID_PART_NUM_MASK              0xffffull
#define SHUB_II_WIDGET_ID_PART_NUM_INPLACE           (SHUB_II_WIDGET_ID_PART_NUM_MASK << SHUB_II_WIDGET_ID_PART_NUM_SHIFT)
#define SHUB_II_WIDGET_ID_MFG_NUM_SHIFT              1 /* established */
#define SHUB_II_WIDGET_ID_MFG_NUM_MASK               0x7ffull
#define SHUB_II_WIDGET_ID_MFG_NUM_INPLACE            (SHUB_II_WIDGET_ID_MFG_NUM_MASK << SHUB_II_WIDGET_ID_MFG_NUM_SHIFT)

/*
 * Widget status: error flags the II sets on a Crosstalk credit timeout, tail timeout, retry limit and similar link faults, plus a pending count. Cleared by the mechanisms the header lists per field. Header name IIO_WSTAT. SAL 5.04 PROM: written 0 once, in its set-up routine (site 0xffab1cc0).
 */
/* widget_status: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WIDGET_STATUS                        0x400008 /* established */
#define SHUB_II_WIDGET_STATUS_CRAZY_SHIFT            32 /* established */
#define SHUB_II_WIDGET_STATUS_CRAZY_MASK             0x1ull
#define SHUB_II_WIDGET_STATUS_CRAZY_INPLACE          (SHUB_II_WIDGET_STATUS_CRAZY_MASK << SHUB_II_WIDGET_STATUS_CRAZY_SHIFT)
#define SHUB_II_WIDGET_STATUS_LLP_TX_CNT_SHIFT       16 /* established */
#define SHUB_II_WIDGET_STATUS_LLP_TX_CNT_MASK        0xffull
#define SHUB_II_WIDGET_STATUS_LLP_TX_CNT_INPLACE     (SHUB_II_WIDGET_STATUS_LLP_TX_CNT_MASK << SHUB_II_WIDGET_STATUS_LLP_TX_CNT_SHIFT)
#define SHUB_II_WIDGET_STATUS_TX_MX_RTY_SHIFT        9 /* established */
#define SHUB_II_WIDGET_STATUS_TX_MX_RTY_MASK         0x1ull
#define SHUB_II_WIDGET_STATUS_TX_MX_RTY_INPLACE      (SHUB_II_WIDGET_STATUS_TX_MX_RTY_MASK << SHUB_II_WIDGET_STATUS_TX_MX_RTY_SHIFT)
#define SHUB_II_WIDGET_STATUS_XT_TAIL_TO_SHIFT       5 /* established */
#define SHUB_II_WIDGET_STATUS_XT_TAIL_TO_MASK        0x1ull
#define SHUB_II_WIDGET_STATUS_XT_TAIL_TO_INPLACE     (SHUB_II_WIDGET_STATUS_XT_TAIL_TO_MASK << SHUB_II_WIDGET_STATUS_XT_TAIL_TO_SHIFT)
#define SHUB_II_WIDGET_STATUS_XT_CRD_TO_SHIFT        4 /* established */
#define SHUB_II_WIDGET_STATUS_XT_CRD_TO_MASK         0x1ull
#define SHUB_II_WIDGET_STATUS_XT_CRD_TO_INPLACE      (SHUB_II_WIDGET_STATUS_XT_CRD_TO_MASK << SHUB_II_WIDGET_STATUS_XT_CRD_TO_SHIFT)
#define SHUB_II_WIDGET_STATUS_PENDING_SHIFT          0 /* established */
#define SHUB_II_WIDGET_STATUS_PENDING_MASK           0xfull
#define SHUB_II_WIDGET_STATUS_PENDING_INPLACE        (SHUB_II_WIDGET_STATUS_PENDING_MASK << SHUB_II_WIDGET_STATUS_PENDING_SHIFT)

/*
 * Widget control: Crosstalk flow control. Holds the widget id the II answers to, tag mode, destination credit count, a force-bad-packet debug bit, the direct-connect bit and the elasticity threshold. Header name IIO_WCR. SAL 5.04 PROM: read-modify-write, each followed by a read back and a 10 ms wait: wid from bits 9:6 of the widget 0 status with tag cleared (site 0xffab33e0), dir_con cleared (site 0xffab3320), tag set (site 0xffab3260), dst_crd set to 4 (site 0xffab3580); wid is read to find the master link (site 0xffab3720).
 */
/* widget_control: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WIDGET_CONTROL                       0x400020 /* established */
#define SHUB_II_WIDGET_CONTROL_E_THRESH_SHIFT        18 /* established */
#define SHUB_II_WIDGET_CONTROL_E_THRESH_MASK         0x1full
#define SHUB_II_WIDGET_CONTROL_E_THRESH_INPLACE      (SHUB_II_WIDGET_CONTROL_E_THRESH_MASK << SHUB_II_WIDGET_CONTROL_E_THRESH_SHIFT)
#define SHUB_II_WIDGET_CONTROL_DIR_CON_SHIFT         17 /* established */
#define SHUB_II_WIDGET_CONTROL_DIR_CON_MASK          0x1ull
#define SHUB_II_WIDGET_CONTROL_DIR_CON_INPLACE       (SHUB_II_WIDGET_CONTROL_DIR_CON_MASK << SHUB_II_WIDGET_CONTROL_DIR_CON_SHIFT)
#define SHUB_II_WIDGET_CONTROL_F_BAD_PKT_SHIFT       16 /* established */
#define SHUB_II_WIDGET_CONTROL_F_BAD_PKT_MASK        0x1ull
#define SHUB_II_WIDGET_CONTROL_F_BAD_PKT_INPLACE     (SHUB_II_WIDGET_CONTROL_F_BAD_PKT_MASK << SHUB_II_WIDGET_CONTROL_F_BAD_PKT_SHIFT)
#define SHUB_II_WIDGET_CONTROL_DST_CRD_SHIFT         13 /* established */
#define SHUB_II_WIDGET_CONTROL_DST_CRD_MASK          0x7ull
#define SHUB_II_WIDGET_CONTROL_DST_CRD_INPLACE       (SHUB_II_WIDGET_CONTROL_DST_CRD_MASK << SHUB_II_WIDGET_CONTROL_DST_CRD_SHIFT)
#define SHUB_II_WIDGET_CONTROL_TAG_SHIFT             4 /* established */
#define SHUB_II_WIDGET_CONTROL_TAG_MASK              0x1ull
#define SHUB_II_WIDGET_CONTROL_TAG_INPLACE           (SHUB_II_WIDGET_CONTROL_TAG_MASK << SHUB_II_WIDGET_CONTROL_TAG_SHIFT)
#define SHUB_II_WIDGET_CONTROL_WID_SHIFT             0 /* established */
#define SHUB_II_WIDGET_CONTROL_WID_MASK              0xfull
#define SHUB_II_WIDGET_CONTROL_WID_INPLACE           (SHUB_II_WIDGET_CONTROL_WID_MASK << SHUB_II_WIDGET_CONTROL_WID_SHIFT)

/*
 * Local access protection: one bit per region of nodes. A PIO read or write is performed only if the requester's region bit is set; reset value permits every node. The header says it is also reachable through an alias window for the local processors. Header name IIO_ILAPR.
 */
/* local_access_protection: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_LOCAL_ACCESS_PROTECTION              0x400100 /* established */
#define SHUB_II_LOCAL_ACCESS_PROTECTION_REGION_SHIFT 0 /* established */
#define SHUB_II_LOCAL_ACCESS_PROTECTION_REGION_MASK  0xffffffffffffffffull
#define SHUB_II_LOCAL_ACCESS_PROTECTION_REGION_INPLACE (SHUB_II_LOCAL_ACCESS_PROTECTION_REGION_MASK << SHUB_II_LOCAL_ACCESS_PROTECTION_REGION_SHIFT)

/*
 * Protection override: writing the 64-bit ASCII string SGIrules sets the requester's region bit in the local access protection register; any other value is ignored. Header name IIO_ILAPO.
 */
/* local_access_override: w64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_LOCAL_ACCESS_OVERRIDE                0x400108 /* established */
#define SHUB_II_LOCAL_ACCESS_OVERRIDE_IO_OVRRIDE_SHIFT 0 /* established */
#define SHUB_II_LOCAL_ACCESS_OVERRIDE_IO_OVRRIDE_MASK 0xffffffffffffffffull
#define SHUB_II_LOCAL_ACCESS_OVERRIDE_IO_OVRRIDE_INPLACE (SHUB_II_LOCAL_ACCESS_OVERRIDE_IO_OVRRIDE_MASK << SHUB_II_LOCAL_ACCESS_OVERRIDE_IO_OVRRIDE_SHIFT)

/*
 * Outbound widget access: one bit per widget qualifying PIO and graphics writes the SHub launches toward that widget, on top of the local access protection register. Header name IIO_IOWA. SAL 5.04 PROM: written 0xff01 (site 0xffab30e0).
 */
/* outbound_widget_access: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_OUTBOUND_WIDGET_ACCESS               0x400110 /* established */
#define SHUB_II_OUTBOUND_WIDGET_ACCESS_WX_OAC_SHIFT  8 /* established */
#define SHUB_II_OUTBOUND_WIDGET_ACCESS_WX_OAC_MASK   0xffull
#define SHUB_II_OUTBOUND_WIDGET_ACCESS_WX_OAC_INPLACE (SHUB_II_OUTBOUND_WIDGET_ACCESS_WX_OAC_MASK << SHUB_II_OUTBOUND_WIDGET_ACCESS_WX_OAC_SHIFT)
#define SHUB_II_OUTBOUND_WIDGET_ACCESS_W0_OAC_SHIFT  0 /* established */
#define SHUB_II_OUTBOUND_WIDGET_ACCESS_W0_OAC_MASK   0x1ull
#define SHUB_II_OUTBOUND_WIDGET_ACCESS_W0_OAC_INPLACE (SHUB_II_OUTBOUND_WIDGET_ACCESS_W0_OAC_MASK << SHUB_II_OUTBOUND_WIDGET_ACCESS_W0_OAC_SHIFT)

/*
 * Inbound widget access: qualifies requests a widget sends toward the SHub. Meant for software to fence off a misbehaving widget. Header name IIO_IIWA. SAL 5.04 PROM: written 0xff01 (site 0xffab30e0).
 */
/* inbound_widget_access: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_INBOUND_WIDGET_ACCESS                0x400118 /* established */
#define SHUB_II_INBOUND_WIDGET_ACCESS_WX_IAC_SHIFT   8 /* established */
#define SHUB_II_INBOUND_WIDGET_ACCESS_WX_IAC_MASK    0xffull
#define SHUB_II_INBOUND_WIDGET_ACCESS_WX_IAC_INPLACE (SHUB_II_INBOUND_WIDGET_ACCESS_WX_IAC_MASK << SHUB_II_INBOUND_WIDGET_ACCESS_WX_IAC_SHIFT)
#define SHUB_II_INBOUND_WIDGET_ACCESS_W0_IAC_SHIFT   0 /* established */
#define SHUB_II_INBOUND_WIDGET_ACCESS_W0_IAC_MASK    0x1ull
#define SHUB_II_INBOUND_WIDGET_ACCESS_W0_IAC_INPLACE (SHUB_II_INBOUND_WIDGET_ACCESS_W0_IAC_MASK << SHUB_II_INBOUND_WIDGET_ACCESS_W0_IAC_SHIFT)

/*
 * Inbound device error mask: per-device (up to eight per widget) enable bits for DMA masters. The SHub clears a device's bit when it detects an error that requires the device to be shut off. Header name IIO_IIDEM.
 */
/* inbound_device_error_mask: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK            0x400120 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WF_DXS_SHIFT 56 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WF_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WF_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_WF_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_WF_DXS_SHIFT)
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WE_DXS_SHIFT 48 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WE_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WE_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_WE_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_WE_DXS_SHIFT)
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WD_DXS_SHIFT 40 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WD_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WD_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_WD_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_WD_DXS_SHIFT)
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WC_DXS_SHIFT 32 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WC_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WC_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_WC_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_WC_DXS_SHIFT)
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WB_DXS_SHIFT 24 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WB_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WB_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_WB_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_WB_DXS_SHIFT)
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WA_DXS_SHIFT 16 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WA_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_WA_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_WA_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_WA_DXS_SHIFT)
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_W9_DXS_SHIFT 8 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_W9_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_W9_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_W9_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_W9_DXS_SHIFT)
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_W8_DXS_SHIFT 0 /* established */
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_W8_DXS_MASK 0xffull
#define SHUB_II_INBOUND_DEVICE_ERROR_MASK_W8_DXS_INPLACE (SHUB_II_INBOUND_DEVICE_ERROR_MASK_W8_DXS_MASK << SHUB_II_INBOUND_DEVICE_ERROR_MASK_W8_DXS_SHIFT)

/*
 * LLP control and status: programmable control and observation fields for the link-level protocol port toward Crosstalk. Header name IIO_ILCSR. SAL 5.04 PROM: bit 13 (llp_stat bit 1, the header's IIO_LLP_CSR_IS_UP) must be set, and the PROM prints that an I/O brick is attached (site 0xffab2e60); read-modify-write of d_avail_sel to 0 (site 0xffab3020), llp_en to 1 (site 0xffab2f80) and nullto to 3 (site 0xffab3780), and wrmrst set when the L1 module type is 111 (site 0xffab3170).
 */
/* llp_control_status: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_LLP_CONTROL_STATUS                   0x400128 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_MAXBRST_SHIFT     32 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_MAXBRST_MASK      0x3ffull
#define SHUB_II_LLP_CONTROL_STATUS_MAXBRST_INPLACE   (SHUB_II_LLP_CONTROL_STATUS_MAXBRST_MASK << SHUB_II_LLP_CONTROL_STATUS_MAXBRST_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_D_AVAIL_SEL_SHIFT 26 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_D_AVAIL_SEL_MASK  0x3ull
#define SHUB_II_LLP_CONTROL_STATUS_D_AVAIL_SEL_INPLACE (SHUB_II_LLP_CONTROL_STATUS_D_AVAIL_SEL_MASK << SHUB_II_LLP_CONTROL_STATUS_D_AVAIL_SEL_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_MAXRTRY_SHIFT     16 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_MAXRTRY_MASK      0x3ffull
#define SHUB_II_LLP_CONTROL_STATUS_MAXRTRY_INPLACE   (SHUB_II_LLP_CONTROL_STATUS_MAXRTRY_MASK << SHUB_II_LLP_CONTROL_STATUS_MAXRTRY_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_REMOTE_POWER_SHIFT 14 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_REMOTE_POWER_MASK 0x1ull
#define SHUB_II_LLP_CONTROL_STATUS_REMOTE_POWER_INPLACE (SHUB_II_LLP_CONTROL_STATUS_REMOTE_POWER_MASK << SHUB_II_LLP_CONTROL_STATUS_REMOTE_POWER_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_LLP_STAT_SHIFT    12 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_LLP_STAT_MASK     0x3ull
#define SHUB_II_LLP_CONTROL_STATUS_LLP_STAT_INPLACE  (SHUB_II_LLP_CONTROL_STATUS_LLP_STAT_MASK << SHUB_II_LLP_CONTROL_STATUS_LLP_STAT_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_BM8_SHIFT         11 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_BM8_MASK          0x1ull
#define SHUB_II_LLP_CONTROL_STATUS_BM8_INPLACE       (SHUB_II_LLP_CONTROL_STATUS_BM8_MASK << SHUB_II_LLP_CONTROL_STATUS_BM8_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_LLP_EN_SHIFT      10 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_LLP_EN_MASK       0x1ull
#define SHUB_II_LLP_CONTROL_STATUS_LLP_EN_INPLACE    (SHUB_II_LLP_CONTROL_STATUS_LLP_EN_MASK << SHUB_II_LLP_CONTROL_STATUS_LLP_EN_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_WRMRST_SHIFT      8 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_WRMRST_MASK       0x1ull
#define SHUB_II_LLP_CONTROL_STATUS_WRMRST_INPLACE    (SHUB_II_LLP_CONTROL_STATUS_WRMRST_MASK << SHUB_II_LLP_CONTROL_STATUS_WRMRST_SHIFT)
#define SHUB_II_LLP_CONTROL_STATUS_NULLTO_SHIFT      0 /* established */
#define SHUB_II_LLP_CONTROL_STATUS_NULLTO_MASK       0x3full
#define SHUB_II_LLP_CONTROL_STATUS_NULLTO_INPLACE    (SHUB_II_LLP_CONTROL_STATUS_NULLTO_MASK << SHUB_II_LLP_CONTROL_STATUS_NULLTO_SHIFT)

/*
 * LLP log: status of the link error rate. Header name IIO_ILLR. SAL 5.04 PROM: written 0 (site 0xffab1cc0).
 */
/* llp_log: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_LLP_LOG                              0x400130 /* established */
#define SHUB_II_LLP_LOG_CB_CNT_SHIFT                 16 /* established */
#define SHUB_II_LLP_LOG_CB_CNT_MASK                  0xffffull
#define SHUB_II_LLP_LOG_CB_CNT_INPLACE               (SHUB_II_LLP_LOG_CB_CNT_MASK << SHUB_II_LLP_LOG_CB_CNT_SHIFT)
#define SHUB_II_LLP_LOG_SN_CNT_SHIFT                 0 /* established */
#define SHUB_II_LLP_LOG_SN_CNT_MASK                  0xffffull
#define SHUB_II_LLP_LOG_SN_CNT_INPLACE               (SHUB_II_LLP_LOG_SN_CNT_MASK << SHUB_II_LLP_LOG_SN_CNT_SHIFT)

/*
 * Interrupt destination for II-detected non-BTE error interrupts: vector level, target PI unit, target node, an enable bit and a sent state. Which processor interface receives the packet is fixed in hardware: PI0 register 0x1800090 or PI1 register 0x1a00090 of the target node (header text). Header name IIO_IIDSR.
 */
/* interrupt_destination: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_INTERRUPT_DESTINATION                0x400138 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_PI1_FORWARD_INT_SHIFT 33 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_PI1_FORWARD_INT_MASK 0x1ull
#define SHUB_II_INTERRUPT_DESTINATION_PI1_FORWARD_INT_INPLACE (SHUB_II_INTERRUPT_DESTINATION_PI1_FORWARD_INT_MASK << SHUB_II_INTERRUPT_DESTINATION_PI1_FORWARD_INT_SHIFT)
#define SHUB_II_INTERRUPT_DESTINATION_PI0_FORWARD_INT_SHIFT 32 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_PI0_FORWARD_INT_MASK 0x1ull
#define SHUB_II_INTERRUPT_DESTINATION_PI0_FORWARD_INT_INPLACE (SHUB_II_INTERRUPT_DESTINATION_PI0_FORWARD_INT_MASK << SHUB_II_INTERRUPT_DESTINATION_PI0_FORWARD_INT_SHIFT)
#define SHUB_II_INTERRUPT_DESTINATION_INT_SENT_SHIFT 28 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_INT_SENT_MASK  0x3ull
#define SHUB_II_INTERRUPT_DESTINATION_INT_SENT_INPLACE (SHUB_II_INTERRUPT_DESTINATION_INT_SENT_MASK << SHUB_II_INTERRUPT_DESTINATION_INT_SENT_SHIFT)
#define SHUB_II_INTERRUPT_DESTINATION_ENABLE_SHIFT   24 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_ENABLE_MASK    0x1ull
#define SHUB_II_INTERRUPT_DESTINATION_ENABLE_INPLACE (SHUB_II_INTERRUPT_DESTINATION_ENABLE_MASK << SHUB_II_INTERRUPT_DESTINATION_ENABLE_SHIFT)
#define SHUB_II_INTERRUPT_DESTINATION_NODE_SHIFT     9 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_NODE_MASK      0x7ffull
#define SHUB_II_INTERRUPT_DESTINATION_NODE_INPLACE   (SHUB_II_INTERRUPT_DESTINATION_NODE_MASK << SHUB_II_INTERRUPT_DESTINATION_NODE_SHIFT)
#define SHUB_II_INTERRUPT_DESTINATION_PI_ID_SHIFT    8 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_PI_ID_MASK     0x1ull
#define SHUB_II_INTERRUPT_DESTINATION_PI_ID_INPLACE  (SHUB_II_INTERRUPT_DESTINATION_PI_ID_MASK << SHUB_II_INTERRUPT_DESTINATION_PI_ID_SHIFT)
#define SHUB_II_INTERRUPT_DESTINATION_LEVEL_SHIFT    0 /* established */
#define SHUB_II_INTERRUPT_DESTINATION_LEVEL_MASK     0xffull
#define SHUB_II_INTERRUPT_DESTINATION_LEVEL_INPLACE  (SHUB_II_INTERRUPT_DESTINATION_LEVEL_MASK << SHUB_II_INTERRUPT_DESTINATION_LEVEL_SHIFT)

/*
 * Graphics node and widget map: matches write responses coming back from a graphics widget to the processor that issued the write, so the response can be turned into a flow-control credit for that processor. Two instances. Header name IIO_IGFX. SAL 5.04 PROM: instance 0 written 2 and instance 1 written 3 (site 0xffab1cc0).
 */
/* graphics_map: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_GRAPHICS_MAP                         0x400140 /* established */
#define SHUB_II_GRAPHICS_MAP_COUNT                   2
#define SHUB_II_GRAPHICS_MAP_STRIDE                  8
#define SHUB_II_GRAPHICS_MAP_P_NUM_SHIFT             17 /* established */
#define SHUB_II_GRAPHICS_MAP_P_NUM_MASK              0x1ull
#define SHUB_II_GRAPHICS_MAP_P_NUM_INPLACE           (SHUB_II_GRAPHICS_MAP_P_NUM_MASK << SHUB_II_GRAPHICS_MAP_P_NUM_SHIFT)
#define SHUB_II_GRAPHICS_MAP_N_NUM_SHIFT             5 /* established */
#define SHUB_II_GRAPHICS_MAP_N_NUM_MASK              0xfffull
#define SHUB_II_GRAPHICS_MAP_N_NUM_INPLACE           (SHUB_II_GRAPHICS_MAP_N_NUM_MASK << SHUB_II_GRAPHICS_MAP_N_NUM_SHIFT)
#define SHUB_II_GRAPHICS_MAP_PI_ID_SHIFT             4 /* established */
#define SHUB_II_GRAPHICS_MAP_PI_ID_MASK              0x1ull
#define SHUB_II_GRAPHICS_MAP_PI_ID_INPLACE           (SHUB_II_GRAPHICS_MAP_PI_ID_MASK << SHUB_II_GRAPHICS_MAP_PI_ID_SHIFT)
#define SHUB_II_GRAPHICS_MAP_W_NUM_SHIFT             0 /* established */
#define SHUB_II_GRAPHICS_MAP_W_NUM_MASK              0xfull
#define SHUB_II_GRAPHICS_MAP_W_NUM_INPLACE           (SHUB_II_GRAPHICS_MAP_W_NUM_MASK << SHUB_II_GRAPHICS_MAP_W_NUM_SHIFT)

/*
 * Scratch register for software. Two instances, no hardware effect. Header name IIO_ISCR.
 */
/* scratch: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SCRATCH                              0x400150 /* established */
#define SHUB_II_SCRATCH_COUNT                        2
#define SHUB_II_SCRATCH_STRIDE                       8
#define SHUB_II_SCRATCH_SCRATCH_SHIFT                0 /* established */
#define SHUB_II_SCRATCH_SCRATCH_MASK                 0xffffffffffffffffull
#define SHUB_II_SCRATCH_SCRATCH_INPLACE              (SHUB_II_SCRATCH_SCRATCH_MASK << SHUB_II_SCRATCH_SCRATCH_SHIFT)

/*
 * Translation table entry mapping one SHub big window to a Crosstalk address: a 5-bit offset joined to the window-relative address bits, a 4-bit widget number and an I/O space bit. The header numbers the entries 1 to 7; the kernel numbers them 0 to 6, and uses the top big window as a stand-in for small window 0 to work around a defect on the processor-interface side. Header names IIO_ITTE1 to IIO_ITTE7. SAL 5.04 PROM: all seven written 0 (site 0xffab1cc0); it programs no translation and uses no big window.
 */
/* itte: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_ITTE                                 0x400160 /* established */
#define SHUB_II_ITTE_COUNT                           7
#define SHUB_II_ITTE_STRIDE                          8
#define SHUB_II_ITTE_IOSP_SHIFT                      12 /* established */
#define SHUB_II_ITTE_IOSP_MASK                       0x1ull
#define SHUB_II_ITTE_IOSP_INPLACE                    (SHUB_II_ITTE_IOSP_MASK << SHUB_II_ITTE_IOSP_SHIFT)
#define SHUB_II_ITTE_W_NUM_SHIFT                     8 /* established */
#define SHUB_II_ITTE_W_NUM_MASK                      0xfull
#define SHUB_II_ITTE_W_NUM_INPLACE                   (SHUB_II_ITTE_W_NUM_MASK << SHUB_II_ITTE_W_NUM_SHIFT)
#define SHUB_II_ITTE_OFFSET_SHIFT                    0 /* established */
#define SHUB_II_ITTE_OFFSET_MASK                     0x1full
#define SHUB_II_ITTE_OFFSET_INPLACE                  (SHUB_II_ITTE_OFFSET_MASK << SHUB_II_ITTE_OFFSET_SHIFT)

/*
 * PIO request buffer for one widget (widget 0 and widgets 8 to F): the state the II keeps to manage PIO flow control on Crosstalk and toward the router network, including a spurious-read and spurious-write indicator. Nine entries, widget 0 first and widgets 8 to F after it, at an 8-byte stride (header names IIO_IPRB0, IIO_IPRB8 to IIO_IPRBF). SAL 5.04 PROM: f_bit set by read-modify-write in entry 0 and in entries 8 to F (site 0xffab1cc0); the header gives f_bit no meaning.
 */
/* prb: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_PRB                                  0x400198 /* established */
#define SHUB_II_PRB_COUNT                            9
#define SHUB_II_PRB_STRIDE                           8
#define SHUB_II_PRB_MULT_ERR_SHIFT                   63 /* established */
#define SHUB_II_PRB_MULT_ERR_MASK                    0x1ull
#define SHUB_II_PRB_MULT_ERR_INPLACE                 (SHUB_II_PRB_MULT_ERR_MASK << SHUB_II_PRB_MULT_ERR_SHIFT)
#define SHUB_II_PRB_SPUR_RD_SHIFT                    51 /* established */
#define SHUB_II_PRB_SPUR_RD_MASK                     0x1ull
#define SHUB_II_PRB_SPUR_RD_INPLACE                  (SHUB_II_PRB_SPUR_RD_MASK << SHUB_II_PRB_SPUR_RD_SHIFT)
#define SHUB_II_PRB_SPUR_WR_SHIFT                    50 /* established */
#define SHUB_II_PRB_SPUR_WR_MASK                     0x1ull
#define SHUB_II_PRB_SPUR_WR_INPLACE                  (SHUB_II_PRB_SPUR_WR_MASK << SHUB_II_PRB_SPUR_WR_SHIFT)
#define SHUB_II_PRB_RD_TO_SHIFT                      49 /* established */
#define SHUB_II_PRB_RD_TO_MASK                       0x1ull
#define SHUB_II_PRB_RD_TO_INPLACE                    (SHUB_II_PRB_RD_TO_MASK << SHUB_II_PRB_RD_TO_SHIFT)
#define SHUB_II_PRB_ERROR_SHIFT                      48 /* established */
#define SHUB_II_PRB_ERROR_MASK                       0x1ull
#define SHUB_II_PRB_ERROR_INPLACE                    (SHUB_II_PRB_ERROR_MASK << SHUB_II_PRB_ERROR_SHIFT)
#define SHUB_II_PRB_OF_CNT_SHIFT                     43 /* established */
#define SHUB_II_PRB_OF_CNT_MASK                      0x1full
#define SHUB_II_PRB_OF_CNT_INPLACE                   (SHUB_II_PRB_OF_CNT_MASK << SHUB_II_PRB_OF_CNT_SHIFT)
#define SHUB_II_PRB_F_BIT_SHIFT                      42 /* established */
#define SHUB_II_PRB_F_BIT_MASK                       0x1ull
#define SHUB_II_PRB_F_BIT_INPLACE                    (SHUB_II_PRB_F_BIT_MASK << SHUB_II_PRB_F_BIT_SHIFT)
#define SHUB_II_PRB_M_BIT_SHIFT                      40 /* established */
#define SHUB_II_PRB_M_BIT_MASK                       0x3ull
#define SHUB_II_PRB_M_BIT_INPLACE                    (SHUB_II_PRB_M_BIT_MASK << SHUB_II_PRB_M_BIT_SHIFT)
#define SHUB_II_PRB_NB_SHIFT                         24 /* established */
#define SHUB_II_PRB_NB_MASK                          0x3fffull
#define SHUB_II_PRB_NB_INPLACE                       (SHUB_II_PRB_NB_MASK << SHUB_II_PRB_NB_SHIFT)
#define SHUB_II_PRB_NA_SHIFT                         8 /* established */
#define SHUB_II_PRB_NA_MASK                          0x3fffull
#define SHUB_II_PRB_NA_INPLACE                       (SHUB_II_PRB_NA_MASK << SHUB_II_PRB_NA_SHIFT)
#define SHUB_II_PRB_C_BIT_SHIFT                      0 /* established */
#define SHUB_II_PRB_C_BIT_MASK                       0xffull
#define SHUB_II_PRB_C_BIT_INPLACE                    (SHUB_II_PRB_C_BIT_MASK << SHUB_II_PRB_C_BIT_SHIFT)

/*
 * Crosstalk credit timeout threshold: how long, counted in 128 II clocks, outbound Crosstalk credits may stay below the threshold before a credit timeout is flagged. Header name IIO_IXCC.
 */
/* crosstalk_credit_timeout: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CROSSTALK_CREDIT_TIMEOUT             0x4001e0 /* established */
#define SHUB_II_CROSSTALK_CREDIT_TIMEOUT_TIME_OUT_SHIFT 0 /* established */
#define SHUB_II_CROSSTALK_CREDIT_TIMEOUT_TIME_OUT_MASK 0x3ffffffull
#define SHUB_II_CROSSTALK_CREDIT_TIMEOUT_TIME_OUT_INPLACE (SHUB_II_CROSSTALK_CREDIT_TIMEOUT_TIME_OUT_MASK << SHUB_II_CROSSTALK_CREDIT_TIMEOUT_TIME_OUT_SHIFT)

/*
 * Miscellaneous error mask: enable bits for widget 0 and the two BTE streams; the SHub clears a bit when it shuts that source down after an error. Software sets it again by writing a one. The kernel's BTE recovery sets the two BTE bits. Kernel: read, BTE 0 and BTE 1 bits set, written back after a BTE error. Header name IIO_IMEM.
 */
/* misc_error_mask: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_MISC_ERROR_MASK                      0x4001e8 /* established */
#define SHUB_II_MISC_ERROR_MASK_CLR_PRECISE_SHIFT    12 /* established */
#define SHUB_II_MISC_ERROR_MASK_CLR_PRECISE_MASK     0x1ull
#define SHUB_II_MISC_ERROR_MASK_CLR_PRECISE_INPLACE  (SHUB_II_MISC_ERROR_MASK_CLR_PRECISE_MASK << SHUB_II_MISC_ERROR_MASK_CLR_PRECISE_SHIFT)
#define SHUB_II_MISC_ERROR_MASK_B1_ESD_SHIFT         8 /* established */
#define SHUB_II_MISC_ERROR_MASK_B1_ESD_MASK          0x1ull
#define SHUB_II_MISC_ERROR_MASK_B1_ESD_INPLACE       (SHUB_II_MISC_ERROR_MASK_B1_ESD_MASK << SHUB_II_MISC_ERROR_MASK_B1_ESD_SHIFT)
#define SHUB_II_MISC_ERROR_MASK_B0_ESD_SHIFT         4 /* established */
#define SHUB_II_MISC_ERROR_MASK_B0_ESD_MASK          0x1ull
#define SHUB_II_MISC_ERROR_MASK_B0_ESD_INPLACE       (SHUB_II_MISC_ERROR_MASK_B0_ESD_MASK << SHUB_II_MISC_ERROR_MASK_B0_ESD_SHIFT)
#define SHUB_II_MISC_ERROR_MASK_W0_ESD_SHIFT         0 /* established */
#define SHUB_II_MISC_ERROR_MASK_W0_ESD_MASK          0x1ull
#define SHUB_II_MISC_ERROR_MASK_W0_ESD_INPLACE       (SHUB_II_MISC_ERROR_MASK_W0_ESD_MASK << SHUB_II_MISC_ERROR_MASK_W0_ESD_SHIFT)

/*
 * Crosstalk timeout threshold: read response timeout, its prescaler and the tail-flit timeout, after which the II raises an error interrupt. Header name IIO_IXTT.
 */
/* crosstalk_timeout_threshold: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD          0x4001f0 /* established */
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_TO_SHIFT 55 /* established */
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_TO_MASK 0x1full
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_TO_INPLACE (SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_TO_MASK << SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_TO_SHIFT)
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_PS_SHIFT 32 /* established */
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_PS_MASK 0x7fffffull
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_PS_INPLACE (SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_PS_MASK << SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_RRSP_PS_SHIFT)
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_TAIL_TO_SHIFT 0 /* established */
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_TAIL_TO_MASK 0x3ffffffull
#define SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_TAIL_TO_INPLACE (SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_TAIL_TO_MASK << SHUB_II_CROSSTALK_TIMEOUT_THRESHOLD_TAIL_TO_SHIFT)

/*
 * Error clear: writing a one clears the matching error bit elsewhere in the SHub (PRB entries, crazy-widget, BTE 0 and 1, CAM and queue over/underflows, bad commands). The kernel's BTE recovery writes the BTE 0 and BTE 1 bits. Kernel: written with BTE 0 and BTE 1 clear bits after a BTE error (write-one-to-clear). Header name IIO_IECLR. SAL 5.04 PROM: written 0x7ffffffffff, bits 42:0, which cover every defined clear bit and the reserved bits between them (site 0xffab1cc0); its BTE error path writes bits 17 and 18 (site 0xffa94d40).
 */
/* error_clear: w64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_ERROR_CLEAR                          0x4001f8 /* established */
#define SHUB_II_ERROR_CLEAR_XN_II_INVALID_CMD_SHIFT  42 /* established */
#define SHUB_II_ERROR_CLEAR_XN_II_INVALID_CMD_MASK   0x1ull
#define SHUB_II_ERROR_CLEAR_XN_II_INVALID_CMD_INPLACE (SHUB_II_ERROR_CLEAR_XN_II_INVALID_CMD_MASK << SHUB_II_ERROR_CLEAR_XN_II_INVALID_CMD_SHIFT)
#define SHUB_II_ERROR_CLEAR_II_XN_INVALID_CMD_SHIFT  41 /* established */
#define SHUB_II_ERROR_CLEAR_II_XN_INVALID_CMD_MASK   0x1ull
#define SHUB_II_ERROR_CLEAR_II_XN_INVALID_CMD_INPLACE (SHUB_II_ERROR_CLEAR_II_XN_INVALID_CMD_MASK << SHUB_II_ERROR_CLEAR_II_XN_INVALID_CMD_SHIFT)
#define SHUB_II_ERROR_CLEAR_II_XN_REQ_CRED_OVERFLOW_SHIFT 40 /* established */
#define SHUB_II_ERROR_CLEAR_II_XN_REQ_CRED_OVERFLOW_MASK 0x1ull
#define SHUB_II_ERROR_CLEAR_II_XN_REQ_CRED_OVERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_II_XN_REQ_CRED_OVERFLOW_MASK << SHUB_II_ERROR_CLEAR_II_XN_REQ_CRED_OVERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_II_XN_REP_CRED_OVERFLOW_SHIFT 39 /* established */
#define SHUB_II_ERROR_CLEAR_II_XN_REP_CRED_OVERFLOW_MASK 0x1ull
#define SHUB_II_ERROR_CLEAR_II_XN_REP_CRED_OVERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_II_XN_REP_CRED_OVERFLOW_MASK << SHUB_II_ERROR_CLEAR_II_XN_REP_CRED_OVERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_IIQ_REQ_OVERFLOW_SHIFT   38 /* established */
#define SHUB_II_ERROR_CLEAR_IIQ_REQ_OVERFLOW_MASK    0x1ull
#define SHUB_II_ERROR_CLEAR_IIQ_REQ_OVERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_IIQ_REQ_OVERFLOW_MASK << SHUB_II_ERROR_CLEAR_IIQ_REQ_OVERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_IIQ_REP_OVERFLOW_SHIFT   37 /* established */
#define SHUB_II_ERROR_CLEAR_IIQ_REP_OVERFLOW_MASK    0x1ull
#define SHUB_II_ERROR_CLEAR_IIQ_REP_OVERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_IIQ_REP_OVERFLOW_MASK << SHUB_II_ERROR_CLEAR_IIQ_REP_OVERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_IOQ_REQ_OVERFLOW_SHIFT   36 /* established */
#define SHUB_II_ERROR_CLEAR_IOQ_REQ_OVERFLOW_MASK    0x1ull
#define SHUB_II_ERROR_CLEAR_IOQ_REQ_OVERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_IOQ_REQ_OVERFLOW_MASK << SHUB_II_ERROR_CLEAR_IOQ_REQ_OVERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_IOQ_REP_OVERFLOW_SHIFT   35 /* established */
#define SHUB_II_ERROR_CLEAR_IOQ_REP_OVERFLOW_MASK    0x1ull
#define SHUB_II_ERROR_CLEAR_IOQ_REP_OVERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_IOQ_REP_OVERFLOW_MASK << SHUB_II_ERROR_CLEAR_IOQ_REP_OVERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_IOQ_REQ_UNDERFLOW_SHIFT  34 /* established */
#define SHUB_II_ERROR_CLEAR_IOQ_REQ_UNDERFLOW_MASK   0x1ull
#define SHUB_II_ERROR_CLEAR_IOQ_REQ_UNDERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_IOQ_REQ_UNDERFLOW_MASK << SHUB_II_ERROR_CLEAR_IOQ_REQ_UNDERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_IOQ_REP_UNDERFLOW_SHIFT  33 /* established */
#define SHUB_II_ERROR_CLEAR_IOQ_REP_UNDERFLOW_MASK   0x1ull
#define SHUB_II_ERROR_CLEAR_IOQ_REP_UNDERFLOW_INPLACE (SHUB_II_ERROR_CLEAR_IOQ_REP_UNDERFLOW_MASK << SHUB_II_ERROR_CLEAR_IOQ_REP_UNDERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_CAM_READ_MISS_SHIFT      32 /* established */
#define SHUB_II_ERROR_CLEAR_CAM_READ_MISS_MASK       0x1ull
#define SHUB_II_ERROR_CLEAR_CAM_READ_MISS_INPLACE    (SHUB_II_ERROR_CLEAR_CAM_READ_MISS_MASK << SHUB_II_ERROR_CLEAR_CAM_READ_MISS_SHIFT)
#define SHUB_II_ERROR_CLEAR_CAM_OVERFLOW_SHIFT       31 /* established */
#define SHUB_II_ERROR_CLEAR_CAM_OVERFLOW_MASK        0x1ull
#define SHUB_II_ERROR_CLEAR_CAM_OVERFLOW_INPLACE     (SHUB_II_ERROR_CLEAR_CAM_OVERFLOW_MASK << SHUB_II_ERROR_CLEAR_CAM_OVERFLOW_SHIFT)
#define SHUB_II_ERROR_CLEAR_CAM_INTR_TO_SHIFT        30 /* established */
#define SHUB_II_ERROR_CLEAR_CAM_INTR_TO_MASK         0x1ull
#define SHUB_II_ERROR_CLEAR_CAM_INTR_TO_INPLACE      (SHUB_II_ERROR_CLEAR_CAM_INTR_TO_MASK << SHUB_II_ERROR_CLEAR_CAM_INTR_TO_SHIFT)
#define SHUB_II_ERROR_CLEAR_SPUR_RD_HDR_SHIFT        29 /* established */
#define SHUB_II_ERROR_CLEAR_SPUR_RD_HDR_MASK         0x1ull
#define SHUB_II_ERROR_CLEAR_SPUR_RD_HDR_INPLACE      (SHUB_II_ERROR_CLEAR_SPUR_RD_HDR_MASK << SHUB_II_ERROR_CLEAR_SPUR_RD_HDR_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_BTE_1_SHIFT            18 /* established */
#define SHUB_II_ERROR_CLEAR_E_BTE_1_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_BTE_1_INPLACE          (SHUB_II_ERROR_CLEAR_E_BTE_1_MASK << SHUB_II_ERROR_CLEAR_E_BTE_1_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_BTE_0_SHIFT            17 /* established */
#define SHUB_II_ERROR_CLEAR_E_BTE_0_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_BTE_0_INPLACE          (SHUB_II_ERROR_CLEAR_E_BTE_0_MASK << SHUB_II_ERROR_CLEAR_E_BTE_0_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_CRAZY_SHIFT            16 /* established */
#define SHUB_II_ERROR_CLEAR_E_CRAZY_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_CRAZY_INPLACE          (SHUB_II_ERROR_CLEAR_E_CRAZY_MASK << SHUB_II_ERROR_CLEAR_E_CRAZY_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_F_SHIFT            15 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_F_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_F_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_F_MASK << SHUB_II_ERROR_CLEAR_E_PRB_F_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_E_SHIFT            14 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_E_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_E_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_E_MASK << SHUB_II_ERROR_CLEAR_E_PRB_E_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_D_SHIFT            13 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_D_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_D_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_D_MASK << SHUB_II_ERROR_CLEAR_E_PRB_D_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_C_SHIFT            12 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_C_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_C_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_C_MASK << SHUB_II_ERROR_CLEAR_E_PRB_C_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_B_SHIFT            11 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_B_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_B_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_B_MASK << SHUB_II_ERROR_CLEAR_E_PRB_B_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_A_SHIFT            10 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_A_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_A_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_A_MASK << SHUB_II_ERROR_CLEAR_E_PRB_A_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_9_SHIFT            9 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_9_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_9_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_9_MASK << SHUB_II_ERROR_CLEAR_E_PRB_9_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_8_SHIFT            8 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_8_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_8_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_8_MASK << SHUB_II_ERROR_CLEAR_E_PRB_8_SHIFT)
#define SHUB_II_ERROR_CLEAR_E_PRB_0_SHIFT            0 /* established */
#define SHUB_II_ERROR_CLEAR_E_PRB_0_MASK             0x1ull
#define SHUB_II_ERROR_CLEAR_E_PRB_0_INPLACE          (SHUB_II_ERROR_CLEAR_E_PRB_0_MASK << SHUB_II_ERROR_CLEAR_E_PRB_0_SHIFT)

/*
 * BTE control, shared by both engines: the combined count of CRBs the two engines may use (which sets their bandwidth) and a soft reset used to recover after an error. Kernel: read, soft reset set, written back to reinitialise both BTE state machines after an error. Header name IIO_IBCR.
 */
/* bte_common_control: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_BTE_COMMON_CONTROL                   0x400200 /* established */
#define SHUB_II_BTE_COMMON_CONTROL_SOFT_RESET_SHIFT  8 /* established */
#define SHUB_II_BTE_COMMON_CONTROL_SOFT_RESET_MASK   0x1ull
#define SHUB_II_BTE_COMMON_CONTROL_SOFT_RESET_INPLACE (SHUB_II_BTE_COMMON_CONTROL_SOFT_RESET_MASK << SHUB_II_BTE_COMMON_CONTROL_SOFT_RESET_SHIFT)
#define SHUB_II_BTE_COMMON_CONTROL_COUNT_SHIFT       0 /* established */
#define SHUB_II_BTE_COMMON_CONTROL_COUNT_MASK        0xfull
#define SHUB_II_BTE_COMMON_CONTROL_COUNT_INPLACE     (SHUB_II_BTE_COMMON_CONTROL_COUNT_MASK << SHUB_II_BTE_COMMON_CONTROL_COUNT_SHIFT)

/*
 * Header of a spurious read response from Crosstalk, captured together with the spurious-sideband register. Header name IIO_IXSM.
 */
/* spurious_message: r64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SPURIOUS_MESSAGE                     0x400208 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_DIDN_SHIFT          60 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_DIDN_MASK           0xfull
#define SHUB_II_SPURIOUS_MESSAGE_DIDN_INPLACE        (SHUB_II_SPURIOUS_MESSAGE_DIDN_MASK << SHUB_II_SPURIOUS_MESSAGE_DIDN_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_SIDN_SHIFT          56 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_SIDN_MASK           0xfull
#define SHUB_II_SPURIOUS_MESSAGE_SIDN_INPLACE        (SHUB_II_SPURIOUS_MESSAGE_SIDN_MASK << SHUB_II_SPURIOUS_MESSAGE_SIDN_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_PACTYP_SHIFT        52 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_PACTYP_MASK         0xfull
#define SHUB_II_SPURIOUS_MESSAGE_PACTYP_INPLACE      (SHUB_II_SPURIOUS_MESSAGE_PACTYP_MASK << SHUB_II_SPURIOUS_MESSAGE_PACTYP_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_TNUM_SHIFT          47 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_TNUM_MASK           0x1full
#define SHUB_II_SPURIOUS_MESSAGE_TNUM_INPLACE        (SHUB_II_SPURIOUS_MESSAGE_TNUM_MASK << SHUB_II_SPURIOUS_MESSAGE_TNUM_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_CT_SHIFT            46 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_CT_MASK             0x1ull
#define SHUB_II_SPURIOUS_MESSAGE_CT_INPLACE          (SHUB_II_SPURIOUS_MESSAGE_CT_MASK << SHUB_II_SPURIOUS_MESSAGE_CT_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_DS_SHIFT            44 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_DS_MASK             0x3ull
#define SHUB_II_SPURIOUS_MESSAGE_DS_INPLACE          (SHUB_II_SPURIOUS_MESSAGE_DS_MASK << SHUB_II_SPURIOUS_MESSAGE_DS_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_GBR_SHIFT           43 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_GBR_MASK            0x1ull
#define SHUB_II_SPURIOUS_MESSAGE_GBR_INPLACE         (SHUB_II_SPURIOUS_MESSAGE_GBR_MASK << SHUB_II_SPURIOUS_MESSAGE_GBR_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_VBPM_SHIFT          42 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_VBPM_MASK           0x1ull
#define SHUB_II_SPURIOUS_MESSAGE_VBPM_INPLACE        (SHUB_II_SPURIOUS_MESSAGE_VBPM_MASK << SHUB_II_SPURIOUS_MESSAGE_VBPM_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_ERROR_SHIFT         41 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_ERROR_MASK          0x1ull
#define SHUB_II_SPURIOUS_MESSAGE_ERROR_INPLACE       (SHUB_II_SPURIOUS_MESSAGE_ERROR_MASK << SHUB_II_SPURIOUS_MESSAGE_ERROR_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_BO_SHIFT            40 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_BO_MASK             0x1ull
#define SHUB_II_SPURIOUS_MESSAGE_BO_INPLACE          (SHUB_II_SPURIOUS_MESSAGE_BO_MASK << SHUB_II_SPURIOUS_MESSAGE_BO_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_ALT_PACTYP_SHIFT    36 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_ALT_PACTYP_MASK     0xfull
#define SHUB_II_SPURIOUS_MESSAGE_ALT_PACTYP_INPLACE  (SHUB_II_SPURIOUS_MESSAGE_ALT_PACTYP_MASK << SHUB_II_SPURIOUS_MESSAGE_ALT_PACTYP_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_TAG_SHIFT           33 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_TAG_MASK            0x7ull
#define SHUB_II_SPURIOUS_MESSAGE_TAG_INPLACE         (SHUB_II_SPURIOUS_MESSAGE_TAG_MASK << SHUB_II_SPURIOUS_MESSAGE_TAG_SHIFT)
#define SHUB_II_SPURIOUS_MESSAGE_BYTE_EN_SHIFT       0 /* established */
#define SHUB_II_SPURIOUS_MESSAGE_BYTE_EN_MASK        0xffffffffull
#define SHUB_II_SPURIOUS_MESSAGE_BYTE_EN_INPLACE     (SHUB_II_SPURIOUS_MESSAGE_BYTE_EN_MASK << SHUB_II_SPURIOUS_MESSAGE_BYTE_EN_SHIFT)

/*
 * Spurious sideband and valid flag for the capture in the spurious-message register. Header name IIO_IXSS.
 */
/* spurious_sideband: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SPURIOUS_SIDEBAND                    0x400210 /* established */
#define SHUB_II_SPURIOUS_SIDEBAND_VALID_SHIFT        63 /* established */
#define SHUB_II_SPURIOUS_SIDEBAND_VALID_MASK         0x1ull
#define SHUB_II_SPURIOUS_SIDEBAND_VALID_INPLACE      (SHUB_II_SPURIOUS_SIDEBAND_VALID_MASK << SHUB_II_SPURIOUS_SIDEBAND_VALID_SHIFT)
#define SHUB_II_SPURIOUS_SIDEBAND_SIDEBAND_SHIFT     0 /* established */
#define SHUB_II_SPURIOUS_SIDEBAND_SIDEBAND_MASK      0xffull
#define SHUB_II_SPURIOUS_SIDEBAND_SIDEBAND_INPLACE   (SHUB_II_SPURIOUS_SIDEBAND_SIDEBAND_MASK << SHUB_II_SPURIOUS_SIDEBAND_SIDEBAND_SHIFT)

/*
 * LLP channel test: access to the LLP's test port. Header name IIO_ILCT.
 */
/* llp_channel_test: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_LLP_CHANNEL_TEST                     0x400218 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_ERR_CAPTURE_SHIFT 54 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_ERR_CAPTURE_MASK 0x1ull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_ERR_CAPTURE_INPLACE (SHUB_II_LLP_CHANNEL_TEST_TEST_ERR_CAPTURE_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_ERR_CAPTURE_SHIFT)
#define SHUB_II_LLP_CHANNEL_TEST_TEST_CLEAR_SHIFT    53 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_CLEAR_MASK     0x1ull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_CLEAR_INPLACE  (SHUB_II_LLP_CHANNEL_TEST_TEST_CLEAR_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_CLEAR_SHIFT)
#define SHUB_II_LLP_CHANNEL_TEST_TEST_FLIT_SHIFT     50 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_FLIT_MASK      0x7ull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_FLIT_INPLACE   (SHUB_II_LLP_CHANNEL_TEST_TEST_FLIT_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_FLIT_SHIFT)
#define SHUB_II_LLP_CHANNEL_TEST_TEST_CBERR_SHIFT    49 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_CBERR_MASK     0x1ull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_CBERR_INPLACE  (SHUB_II_LLP_CHANNEL_TEST_TEST_CBERR_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_CBERR_SHIFT)
#define SHUB_II_LLP_CHANNEL_TEST_TEST_VALID_SHIFT    48 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_VALID_MASK     0x1ull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_VALID_INPLACE  (SHUB_II_LLP_CHANNEL_TEST_TEST_VALID_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_VALID_SHIFT)
#define SHUB_II_LLP_CHANNEL_TEST_TEST_DATA_SHIFT     28 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_DATA_MASK      0xfffffull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_DATA_INPLACE   (SHUB_II_LLP_CHANNEL_TEST_TEST_DATA_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_DATA_SHIFT)
#define SHUB_II_LLP_CHANNEL_TEST_TEST_MASK_SHIFT     20 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_MASK_MASK      0xffull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_MASK_INPLACE   (SHUB_II_LLP_CHANNEL_TEST_TEST_MASK_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_MASK_SHIFT)
#define SHUB_II_LLP_CHANNEL_TEST_TEST_SEED_SHIFT     0 /* established */
#define SHUB_II_LLP_CHANNEL_TEST_TEST_SEED_MASK      0xfffffull
#define SHUB_II_LLP_CHANNEL_TEST_TEST_SEED_INPLACE   (SHUB_II_LLP_CHANNEL_TEST_TEST_SEED_MASK << SHUB_II_LLP_CHANNEL_TEST_TEST_SEED_SHIFT)

/*
 * Header, part 1, of an illegal incoming network packet, with a valid flag, an overrun flag and an error type (short or long request or reply). Header name IIO_IIEPH1. SAL 5.04 PROM: written 0 (site 0xffab1cc0).
 */
/* error_packet_header_1: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_ERROR_PACKET_HEADER_1                0x400220 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_1_VALID_SHIFT    50 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_1_VALID_MASK     0x1ull
#define SHUB_II_ERROR_PACKET_HEADER_1_VALID_INPLACE  (SHUB_II_ERROR_PACKET_HEADER_1_VALID_MASK << SHUB_II_ERROR_PACKET_HEADER_1_VALID_SHIFT)
#define SHUB_II_ERROR_PACKET_HEADER_1_OVERRUN_SHIFT  46 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_1_OVERRUN_MASK   0x1ull
#define SHUB_II_ERROR_PACKET_HEADER_1_OVERRUN_INPLACE (SHUB_II_ERROR_PACKET_HEADER_1_OVERRUN_MASK << SHUB_II_ERROR_PACKET_HEADER_1_OVERRUN_SHIFT)
#define SHUB_II_ERROR_PACKET_HEADER_1_ERR_TYPE_SHIFT 38 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_1_ERR_TYPE_MASK  0xfull
#define SHUB_II_ERROR_PACKET_HEADER_1_ERR_TYPE_INPLACE (SHUB_II_ERROR_PACKET_HEADER_1_ERR_TYPE_MASK << SHUB_II_ERROR_PACKET_HEADER_1_ERR_TYPE_SHIFT)
#define SHUB_II_ERROR_PACKET_HEADER_1_SOURCE_SHIFT   23 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_1_SOURCE_MASK    0x3fffull
#define SHUB_II_ERROR_PACKET_HEADER_1_SOURCE_INPLACE (SHUB_II_ERROR_PACKET_HEADER_1_SOURCE_MASK << SHUB_II_ERROR_PACKET_HEADER_1_SOURCE_SHIFT)
#define SHUB_II_ERROR_PACKET_HEADER_1_SUPPL_SHIFT    8 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_1_SUPPL_MASK     0x3fffull
#define SHUB_II_ERROR_PACKET_HEADER_1_SUPPL_INPLACE  (SHUB_II_ERROR_PACKET_HEADER_1_SUPPL_MASK << SHUB_II_ERROR_PACKET_HEADER_1_SUPPL_SHIFT)
#define SHUB_II_ERROR_PACKET_HEADER_1_COMMAND_SHIFT  0 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_1_COMMAND_MASK   0x7full
#define SHUB_II_ERROR_PACKET_HEADER_1_COMMAND_INPLACE (SHUB_II_ERROR_PACKET_HEADER_1_COMMAND_MASK << SHUB_II_ERROR_PACKET_HEADER_1_COMMAND_SHIFT)

/*
 * Header, part 2, of an illegal incoming network packet. Header name IIO_IIEPH2. SAL 5.04 PROM: written 0 (site 0xffab1cc0).
 */
/* error_packet_header_2: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_ERROR_PACKET_HEADER_2                0x400228 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_2_TAIL_SHIFT     60 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_2_TAIL_MASK      0x1ull
#define SHUB_II_ERROR_PACKET_HEADER_2_TAIL_INPLACE   (SHUB_II_ERROR_PACKET_HEADER_2_TAIL_MASK << SHUB_II_ERROR_PACKET_HEADER_2_TAIL_SHIFT)
#define SHUB_II_ERROR_PACKET_HEADER_2_ADDRESS_SHIFT  3 /* established */
#define SHUB_II_ERROR_PACKET_HEADER_2_ADDRESS_MASK   0x7fffffffffffull
#define SHUB_II_ERROR_PACKET_HEADER_2_ADDRESS_INPLACE (SHUB_II_ERROR_PACKET_HEADER_2_ADDRESS_MASK << SHUB_II_ERROR_PACKET_HEADER_2_ADDRESS_SHIFT)

/*
 * Local access protection for the SXB. Same scheme as the main local access protection register. Header name IIO_ISLAPR.
 */
/* sxb_access_protection: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SXB_ACCESS_PROTECTION                0x400230 /* established */
#define SHUB_II_SXB_ACCESS_PROTECTION_REGION_SHIFT   0 /* established */
#define SHUB_II_SXB_ACCESS_PROTECTION_REGION_MASK    0xffffffffffffffffull
#define SHUB_II_SXB_ACCESS_PROTECTION_REGION_INPLACE (SHUB_II_SXB_ACCESS_PROTECTION_REGION_MASK << SHUB_II_SXB_ACCESS_PROTECTION_REGION_SHIFT)

/*
 * Override for the SXB access protection register. Header name IIO_ISLAPO.
 */
/* sxb_access_override: w64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SXB_ACCESS_OVERRIDE                  0x400238 /* established */
#define SHUB_II_SXB_ACCESS_OVERRIDE_IO_SBX_OVRRIDE_SHIFT 0 /* established */
#define SHUB_II_SXB_ACCESS_OVERRIDE_IO_SBX_OVRRIDE_MASK 0xffffffffffffffull
#define SHUB_II_SXB_ACCESS_OVERRIDE_IO_SBX_OVRRIDE_INPLACE (SHUB_II_SXB_ACCESS_OVERRIDE_IO_SBX_OVRRIDE_MASK << SHUB_II_SXB_ACCESS_OVERRIDE_IO_SBX_OVRRIDE_SHIFT)

/*
 * Wrapper interrupt: how long the II wrapper waits for an issued interrupt before it times it out and drops it. Header name IIO_IWI.
 */
/* wrapper_interrupt: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WRAPPER_INTERRUPT                    0x400240 /* established */
#define SHUB_II_WRAPPER_INTERRUPT_INTRPT_RETRY_PERIOD_SHIFT 48 /* established */
#define SHUB_II_WRAPPER_INTERRUPT_INTRPT_RETRY_PERIOD_MASK 0xffull
#define SHUB_II_WRAPPER_INTERRUPT_INTRPT_RETRY_PERIOD_INPLACE (SHUB_II_WRAPPER_INTERRUPT_INTRPT_RETRY_PERIOD_MASK << SHUB_II_WRAPPER_INTERRUPT_INTRPT_RETRY_PERIOD_SHIFT)
#define SHUB_II_WRAPPER_INTERRUPT_TIMEOUT_SHIFT      32 /* established */
#define SHUB_II_WRAPPER_INTERRUPT_TIMEOUT_MASK       0xffull
#define SHUB_II_WRAPPER_INTERRUPT_TIMEOUT_INPLACE    (SHUB_II_WRAPPER_INTERRUPT_TIMEOUT_MASK << SHUB_II_WRAPPER_INTERRUPT_TIMEOUT_SHIFT)
#define SHUB_II_WRAPPER_INTERRUPT_PRESCALE_SHIFT     0 /* established */
#define SHUB_II_WRAPPER_INTERRUPT_PRESCALE_MASK      0xffffffull
#define SHUB_II_WRAPPER_INTERRUPT_PRESCALE_INPLACE   (SHUB_II_WRAPPER_INTERRUPT_PRESCALE_MASK << SHUB_II_WRAPPER_INTERRUPT_PRESCALE_SHIFT)

/*
 * Wrapper error log. Header name IIO_IWEL.
 */
/* wrapper_error_log: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WRAPPER_ERROR_LOG                    0x400248 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_XN_II_INVALID_CMD_SHIFT 33 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_XN_II_INVALID_CMD_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_XN_II_INVALID_CMD_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_XN_II_INVALID_CMD_MASK << SHUB_II_WRAPPER_ERROR_LOG_XN_II_INVALID_CMD_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_INVALID_CMD_SHIFT 32 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_INVALID_CMD_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_INVALID_CMD_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_II_XN_INVALID_CMD_MASK << SHUB_II_WRAPPER_ERROR_LOG_II_XN_INVALID_CMD_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_REQ_CRED_OVER_UNDER_SHIFT 25 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_REQ_CRED_OVER_UNDER_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_REQ_CRED_OVER_UNDER_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_II_XN_REQ_CRED_OVER_UNDER_MASK << SHUB_II_WRAPPER_ERROR_LOG_II_XN_REQ_CRED_OVER_UNDER_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_REP_CRED_OVER_UNDER_SHIFT 24 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_REP_CRED_OVER_UNDER_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_II_XN_REP_CRED_OVER_UNDER_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_II_XN_REP_CRED_OVER_UNDER_MASK << SHUB_II_WRAPPER_ERROR_LOG_II_XN_REP_CRED_OVER_UNDER_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_IIQ_REQ_OVERFLOW_SHIFT 17 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_IIQ_REQ_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_IIQ_REQ_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_IIQ_REQ_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_LOG_IIQ_REQ_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_IIQ_REP_OVERFLOW_SHIFT 16 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_IIQ_REP_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_IIQ_REP_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_IIQ_REP_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_LOG_IIQ_REP_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_OVERFLOW_SHIFT 15 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_OVERFLOW_SHIFT 14 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_UNDERFLOW_SHIFT 13 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_UNDERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_UNDERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_UNDERFLOW_MASK << SHUB_II_WRAPPER_ERROR_LOG_IOQ_REQ_UNDERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_UNDERFLOW_SHIFT 12 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_UNDERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_UNDERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_UNDERFLOW_MASK << SHUB_II_WRAPPER_ERROR_LOG_IOQ_REP_UNDERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_CAM_READ_MISS_SHIFT 9 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_CAM_READ_MISS_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_CAM_READ_MISS_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_CAM_READ_MISS_MASK << SHUB_II_WRAPPER_ERROR_LOG_CAM_READ_MISS_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_CAM_OVERFLOW_SHIFT 8 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_CAM_OVERFLOW_MASK  0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_CAM_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_CAM_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_LOG_CAM_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_LOG_INTR_TIMED_OUT_SHIFT 0 /* established */
#define SHUB_II_WRAPPER_ERROR_LOG_INTR_TIMED_OUT_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_LOG_INTR_TIMED_OUT_INPLACE (SHUB_II_WRAPPER_ERROR_LOG_INTR_TIMED_OUT_MASK << SHUB_II_WRAPPER_ERROR_LOG_INTR_TIMED_OUT_SHIFT)

/*
 * Wrapper control. Header name IIO_IWC. SAL 5.04 PROM: dma_byte_swap cleared by read-modify-write, no wait (site 0xffaad720).
 */
/* wrapper_control: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WRAPPER_CONTROL                      0x400250 /* established */
#define SHUB_II_WRAPPER_CONTROL_FORCE_REQ_CRED_SHIFT 63 /* established */
#define SHUB_II_WRAPPER_CONTROL_FORCE_REQ_CRED_MASK  0x1ull
#define SHUB_II_WRAPPER_CONTROL_FORCE_REQ_CRED_INPLACE (SHUB_II_WRAPPER_CONTROL_FORCE_REQ_CRED_MASK << SHUB_II_WRAPPER_CONTROL_FORCE_REQ_CRED_SHIFT)
#define SHUB_II_WRAPPER_CONTROL_FORCE_REP_CRED_SHIFT 62 /* established */
#define SHUB_II_WRAPPER_CONTROL_FORCE_REP_CRED_MASK  0x1ull
#define SHUB_II_WRAPPER_CONTROL_FORCE_REP_CRED_INPLACE (SHUB_II_WRAPPER_CONTROL_FORCE_REP_CRED_MASK << SHUB_II_WRAPPER_CONTROL_FORCE_REP_CRED_SHIFT)
#define SHUB_II_WRAPPER_CONTROL_IIQ_DEPTH_SHIFT      44 /* established */
#define SHUB_II_WRAPPER_CONTROL_IIQ_DEPTH_MASK       0x3full
#define SHUB_II_WRAPPER_CONTROL_IIQ_DEPTH_INPLACE    (SHUB_II_WRAPPER_CONTROL_IIQ_DEPTH_MASK << SHUB_II_WRAPPER_CONTROL_IIQ_DEPTH_SHIFT)
#define SHUB_II_WRAPPER_CONTROL_XN_REQ_IQ_DEPTH_SHIFT 36 /* established */
#define SHUB_II_WRAPPER_CONTROL_XN_REQ_IQ_DEPTH_MASK 0x1full
#define SHUB_II_WRAPPER_CONTROL_XN_REQ_IQ_DEPTH_INPLACE (SHUB_II_WRAPPER_CONTROL_XN_REQ_IQ_DEPTH_MASK << SHUB_II_WRAPPER_CONTROL_XN_REQ_IQ_DEPTH_SHIFT)
#define SHUB_II_WRAPPER_CONTROL_XN_REP_IQ_DEPTH_SHIFT 28 /* established */
#define SHUB_II_WRAPPER_CONTROL_XN_REP_IQ_DEPTH_MASK 0x1full
#define SHUB_II_WRAPPER_CONTROL_XN_REP_IQ_DEPTH_INPLACE (SHUB_II_WRAPPER_CONTROL_XN_REP_IQ_DEPTH_MASK << SHUB_II_WRAPPER_CONTROL_XN_REP_IQ_DEPTH_SHIFT)
#define SHUB_II_WRAPPER_CONTROL_II_XN_CRED_OVER_UNDER_LOG_SHIFT 8 /* established */
#define SHUB_II_WRAPPER_CONTROL_II_XN_CRED_OVER_UNDER_LOG_MASK 0x1ull
#define SHUB_II_WRAPPER_CONTROL_II_XN_CRED_OVER_UNDER_LOG_INPLACE (SHUB_II_WRAPPER_CONTROL_II_XN_CRED_OVER_UNDER_LOG_MASK << SHUB_II_WRAPPER_CONTROL_II_XN_CRED_OVER_UNDER_LOG_SHIFT)
#define SHUB_II_WRAPPER_CONTROL_CAM_READ_LINES_RESET_SHIFT 4 /* established */
#define SHUB_II_WRAPPER_CONTROL_CAM_READ_LINES_RESET_MASK 0x1ull
#define SHUB_II_WRAPPER_CONTROL_CAM_READ_LINES_RESET_INPLACE (SHUB_II_WRAPPER_CONTROL_CAM_READ_LINES_RESET_MASK << SHUB_II_WRAPPER_CONTROL_CAM_READ_LINES_RESET_SHIFT)
#define SHUB_II_WRAPPER_CONTROL_DMA_BYTE_SWAP_SHIFT  0 /* established */
#define SHUB_II_WRAPPER_CONTROL_DMA_BYTE_SWAP_MASK   0x1ull
#define SHUB_II_WRAPPER_CONTROL_DMA_BYTE_SWAP_INPLACE (SHUB_II_WRAPPER_CONTROL_DMA_BYTE_SWAP_MASK << SHUB_II_WRAPPER_CONTROL_DMA_BYTE_SWAP_SHIFT)

/*
 * Wrapper status. Header name IIO_IWS.
 */
/* wrapper_status: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WRAPPER_STATUS                       0x400258 /* established */
#define SHUB_II_WRAPPER_STATUS_XN_REQ_IQ_CREDITS_SHIFT 8 /* established */
#define SHUB_II_WRAPPER_STATUS_XN_REQ_IQ_CREDITS_MASK 0x1full
#define SHUB_II_WRAPPER_STATUS_XN_REQ_IQ_CREDITS_INPLACE (SHUB_II_WRAPPER_STATUS_XN_REQ_IQ_CREDITS_MASK << SHUB_II_WRAPPER_STATUS_XN_REQ_IQ_CREDITS_SHIFT)
#define SHUB_II_WRAPPER_STATUS_XN_REP_IQ_CREDITS_SHIFT 0 /* established */
#define SHUB_II_WRAPPER_STATUS_XN_REP_IQ_CREDITS_MASK 0x1full
#define SHUB_II_WRAPPER_STATUS_XN_REP_IQ_CREDITS_INPLACE (SHUB_II_WRAPPER_STATUS_XN_REP_IQ_CREDITS_MASK << SHUB_II_WRAPPER_STATUS_XN_REP_IQ_CREDITS_SHIFT)

/*
 * Wrapper error interrupt mask. Header name IIO_IWEIM. SAL 5.04 PROM: ioq_req_overflow (bit 15) set by read-modify-write (site 0xffab1cc0).
 */
/* wrapper_error_interrupt_mask: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK         0x400260 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_XN_II_INVALID_CMD_SHIFT 33 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_XN_II_INVALID_CMD_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_XN_II_INVALID_CMD_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_XN_II_INVALID_CMD_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_XN_II_INVALID_CMD_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_INVALID_CMD_SHIFT 32 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_INVALID_CMD_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_INVALID_CMD_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_INVALID_CMD_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_INVALID_CMD_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REQ_CRED_OVERFLOW_SHIFT 25 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REQ_CRED_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REQ_CRED_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REQ_CRED_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REQ_CRED_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REP_CRED_OVERFLOW_SHIFT 24 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REP_CRED_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REP_CRED_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REP_CRED_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_II_XN_REP_CRED_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REQ_OVERFLOW_SHIFT 17 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REQ_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REQ_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REQ_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REQ_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REP_OVERFLOW_SHIFT 16 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REP_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REP_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REP_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IIQ_REP_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_OVERFLOW_SHIFT 15 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_OVERFLOW_SHIFT 14 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_UNDERFLOW_SHIFT 13 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_UNDERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_UNDERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_UNDERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REQ_UNDERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_UNDERFLOW_SHIFT 12 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_UNDERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_UNDERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_UNDERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_IOQ_REP_UNDERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_READ_MISS_SHIFT 9 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_READ_MISS_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_READ_MISS_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_READ_MISS_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_READ_MISS_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_OVERFLOW_SHIFT 8 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_OVERFLOW_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_OVERFLOW_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_OVERFLOW_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_CAM_OVERFLOW_SHIFT)
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_INTR_TIMED_OUT_SHIFT 0 /* established */
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_INTR_TIMED_OUT_MASK 0x1ull
#define SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_INTR_TIMED_OUT_INPLACE (SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_INTR_TIMED_OUT_MASK << SHUB_II_WRAPPER_ERROR_INTERRUPT_MASK_INTR_TIMED_OUT_SHIFT)

/*
 * PRB counter adjust: a write moves a field of the matching widget's PRB entry up or down by one. For recovery after errors and resets. Header name IIO_IPCA.
 */
/* prb_counter_adjust: w64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_PRB_COUNTER_ADJUST                   0x400300 /* established */
#define SHUB_II_PRB_COUNTER_ADJUST_FIELD_SHIFT       8 /* established */
#define SHUB_II_PRB_COUNTER_ADJUST_FIELD_MASK        0x3ull
#define SHUB_II_PRB_COUNTER_ADJUST_FIELD_INPLACE     (SHUB_II_PRB_COUNTER_ADJUST_FIELD_MASK << SHUB_II_PRB_COUNTER_ADJUST_FIELD_SHIFT)
#define SHUB_II_PRB_COUNTER_ADJUST_ADJUST_SHIFT      4 /* established */
#define SHUB_II_PRB_COUNTER_ADJUST_ADJUST_MASK       0x1ull
#define SHUB_II_PRB_COUNTER_ADJUST_ADJUST_INPLACE    (SHUB_II_PRB_COUNTER_ADJUST_ADJUST_MASK << SHUB_II_PRB_COUNTER_ADJUST_ADJUST_SHIFT)
#define SHUB_II_PRB_COUNTER_ADJUST_WID_SHIFT         0 /* established */
#define SHUB_II_PRB_COUNTER_ADJUST_WID_MASK          0xfull
#define SHUB_II_PRB_COUNTER_ADJUST_WID_INPLACE       (SHUB_II_PRB_COUNTER_ADJUST_WID_MASK << SHUB_II_PRB_COUNTER_ADJUST_WID_SHIFT)

/*
 * PIO read table entry, part A: what the II remembers about an outstanding PIO read so it can build the network reply when Crosstalk answers. Eight entries. Header names IIO_IPRTE0_A to IIO_IPRTE7_A. SAL 5.04 PROM: each entry read (value discarded), then written 0 (site 0xffab1cc0).
 */
/* pio_read_entry_a: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_PIO_READ_ENTRY_A                     0x400308 /* established */
#define SHUB_II_PIO_READ_ENTRY_A_COUNT               8
#define SHUB_II_PIO_READ_ENTRY_A_STRIDE              8
#define SHUB_II_PIO_READ_ENTRY_A_VLD_SHIFT           63 /* established */
#define SHUB_II_PIO_READ_ENTRY_A_VLD_MASK            0x1ull
#define SHUB_II_PIO_READ_ENTRY_A_VLD_INPLACE         (SHUB_II_PIO_READ_ENTRY_A_VLD_MASK << SHUB_II_PIO_READ_ENTRY_A_VLD_SHIFT)
#define SHUB_II_PIO_READ_ENTRY_A_TO_CNT_SHIFT        58 /* established */
#define SHUB_II_PIO_READ_ENTRY_A_TO_CNT_MASK         0x1full
#define SHUB_II_PIO_READ_ENTRY_A_TO_CNT_INPLACE      (SHUB_II_PIO_READ_ENTRY_A_TO_CNT_MASK << SHUB_II_PIO_READ_ENTRY_A_TO_CNT_SHIFT)
#define SHUB_II_PIO_READ_ENTRY_A_WIDGET_SHIFT        54 /* established */
#define SHUB_II_PIO_READ_ENTRY_A_WIDGET_MASK         0xfull
#define SHUB_II_PIO_READ_ENTRY_A_WIDGET_INPLACE      (SHUB_II_PIO_READ_ENTRY_A_WIDGET_MASK << SHUB_II_PIO_READ_ENTRY_A_WIDGET_SHIFT)

/*
 * PIO read table entry, part B. Eight entries. Header names IIO_IPRTE0_B to IIO_IPRTE7_B. SAL 5.04 PROM: each entry read (value discarded), then written 0 (site 0xffab1cc0).
 */
/* pio_read_entry_b: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_PIO_READ_ENTRY_B                     0x400348 /* established */
#define SHUB_II_PIO_READ_ENTRY_B_COUNT               8
#define SHUB_II_PIO_READ_ENTRY_B_STRIDE              8
#define SHUB_II_PIO_READ_ENTRY_B_SOURCE_SHIFT        53 /* established */
#define SHUB_II_PIO_READ_ENTRY_B_SOURCE_MASK         0x7ffull
#define SHUB_II_PIO_READ_ENTRY_B_SOURCE_INPLACE      (SHUB_II_PIO_READ_ENTRY_B_SOURCE_MASK << SHUB_II_PIO_READ_ENTRY_B_SOURCE_SHIFT)
#define SHUB_II_PIO_READ_ENTRY_B_INIT_SHIFT          50 /* established */
#define SHUB_II_PIO_READ_ENTRY_B_INIT_MASK           0x7ull
#define SHUB_II_PIO_READ_ENTRY_B_INIT_INPLACE        (SHUB_II_PIO_READ_ENTRY_B_INIT_MASK << SHUB_II_PIO_READ_ENTRY_B_INIT_SHIFT)
#define SHUB_II_PIO_READ_ENTRY_B_ADDRESS_SHIFT       3 /* established */
#define SHUB_II_PIO_READ_ENTRY_B_ADDRESS_MASK        0x7fffffffffffull
#define SHUB_II_PIO_READ_ENTRY_B_ADDRESS_INPLACE     (SHUB_II_PIO_READ_ENTRY_B_ADDRESS_MASK << SHUB_II_PIO_READ_ENTRY_B_ADDRESS_SHIFT)

/*
 * PIO deallocation: a write frees one outstanding-read entry after a read response timeout. Kept for compatibility; SHub cleans up read timeouts itself. Header name IIO_IPDR.
 */
/* pio_deallocate: w64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_PIO_DEALLOCATE                       0x400388 /* established */
#define SHUB_II_PIO_DEALLOCATE_INIT_RPCNT_SHIFT      5 /* established */
#define SHUB_II_PIO_DEALLOCATE_INIT_RPCNT_MASK       0x1ull
#define SHUB_II_PIO_DEALLOCATE_INIT_RPCNT_INPLACE    (SHUB_II_PIO_DEALLOCATE_INIT_RPCNT_MASK << SHUB_II_PIO_DEALLOCATE_INIT_RPCNT_SHIFT)
#define SHUB_II_PIO_DEALLOCATE_PND_SHIFT             4 /* established */
#define SHUB_II_PIO_DEALLOCATE_PND_MASK              0x1ull
#define SHUB_II_PIO_DEALLOCATE_PND_INPLACE           (SHUB_II_PIO_DEALLOCATE_PND_MASK << SHUB_II_PIO_DEALLOCATE_PND_SHIFT)
#define SHUB_II_PIO_DEALLOCATE_TE_SHIFT              0 /* established */
#define SHUB_II_PIO_DEALLOCATE_TE_MASK               0x7ull
#define SHUB_II_PIO_DEALLOCATE_TE_INPLACE            (SHUB_II_PIO_DEALLOCATE_TE_MASK << SHUB_II_PIO_DEALLOCATE_TE_SHIFT)

/*
 * CRB entry deallocation: after software has handled an error captured in a CRB entry and cleared its mark bit, it writes the CRB number plus the pending bit here to return the entry to the free list. The pending bit reads back until the hardware has finished. Kernel: written to free a CRB, then polled until the pending bit clears. Header name IIO_ICDR.
 */
/* crb_deallocate: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_DEALLOCATE                       0x400390 /* established */
#define SHUB_II_CRB_DEALLOCATE_PND_SHIFT             4 /* established */
#define SHUB_II_CRB_DEALLOCATE_PND_MASK              0x1ull
#define SHUB_II_CRB_DEALLOCATE_PND_INPLACE           (SHUB_II_CRB_DEALLOCATE_PND_MASK << SHUB_II_CRB_DEALLOCATE_PND_SHIFT)
#define SHUB_II_CRB_DEALLOCATE_CRB_NUM_SHIFT         0 /* established */
#define SHUB_II_CRB_DEALLOCATE_CRB_NUM_MASK          0xfull
#define SHUB_II_CRB_DEALLOCATE_CRB_NUM_INPLACE       (SHUB_II_CRB_DEALLOCATE_CRB_NUM_MASK << SHUB_II_CRB_DEALLOCATE_CRB_NUM_SHIFT)

/*
 * Debug access to the depth of two internal II queues. Header name IIO_IFDR.
 */
/* ioq_fifo_depth: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_IOQ_FIFO_DEPTH                       0x400398 /* established */
#define SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RP_SHIFT      15 /* established */
#define SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RP_MASK       0x1ull
#define SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RP_INPLACE    (SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RP_MASK << SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RP_SHIFT)
#define SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RP_SHIFT      8 /* established */
#define SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RP_MASK       0x7full
#define SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RP_INPLACE    (SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RP_MASK << SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RP_SHIFT)
#define SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RQ_SHIFT      7 /* established */
#define SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RQ_MASK       0x1ull
#define SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RQ_INPLACE    (SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RQ_MASK << SHUB_II_IOQ_FIFO_DEPTH_SET_IOQ_RQ_SHIFT)
#define SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RQ_SHIFT      0 /* established */
#define SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RQ_MASK       0x7full
#define SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RQ_INPLACE    (SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RQ_MASK << SHUB_II_IOQ_FIFO_DEPTH_IOQ_MAX_RQ_SHIFT)

/*
 * Inbound queue arbitration: a slow-drain mode for stress testing. Header name IIO_IIAP.
 */
/* iiq_arbitration: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_IIQ_ARBITRATION                      0x4003a0 /* established */
#define SHUB_II_IIQ_ARBITRATION_RP_MLS_SHIFT         8 /* established */
#define SHUB_II_IIQ_ARBITRATION_RP_MLS_MASK          0x3full
#define SHUB_II_IIQ_ARBITRATION_RP_MLS_INPLACE       (SHUB_II_IIQ_ARBITRATION_RP_MLS_MASK << SHUB_II_IIQ_ARBITRATION_RP_MLS_SHIFT)
#define SHUB_II_IIQ_ARBITRATION_RQ_MLS_SHIFT         0 /* established */
#define SHUB_II_IIQ_ARBITRATION_RQ_MLS_MASK          0x3full
#define SHUB_II_IIQ_ARBITRATION_RQ_MLS_INPLACE       (SHUB_II_IIQ_ARBITRATION_RQ_MLS_MASK << SHUB_II_IIQ_ARBITRATION_RQ_MLS_SHIFT)

/*
 * CRB management: valid and error-mark bit vectors for the 15 CRBs, the spurious-message flag and tuning fields. The header warns that writing it while the CRBs are active is dangerous. The kernel reads it to find marked or valid CRBs before cleaning up BTE errors. Kernel: read-only, to see which CRBs are valid or marked before BTE cleanup. Header name IIO_ICMR.
 */
/* crb_management: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_MANAGEMENT                       0x4003a8 /* established */
#define SHUB_II_CRB_MANAGEMENT_PRECISE_SHIFT         52 /* established */
#define SHUB_II_CRB_MANAGEMENT_PRECISE_MASK          0x1ull
#define SHUB_II_CRB_MANAGEMENT_PRECISE_INPLACE       (SHUB_II_CRB_MANAGEMENT_PRECISE_MASK << SHUB_II_CRB_MANAGEMENT_PRECISE_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_CRB_MARK_SHIFT        35 /* established */
#define SHUB_II_CRB_MANAGEMENT_CRB_MARK_MASK         0x7fffull
#define SHUB_II_CRB_MANAGEMENT_CRB_MARK_INPLACE      (SHUB_II_CRB_MANAGEMENT_CRB_MARK_MASK << SHUB_II_CRB_MANAGEMENT_CRB_MARK_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_CRB_VLD_SHIFT         20 /* established */
#define SHUB_II_CRB_MANAGEMENT_CRB_VLD_MASK          0x7fffull
#define SHUB_II_CRB_MANAGEMENT_CRB_VLD_INPLACE       (SHUB_II_CRB_MANAGEMENT_CRB_VLD_MASK << SHUB_II_CRB_MANAGEMENT_CRB_VLD_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_FC_CNT_SHIFT          16 /* established */
#define SHUB_II_CRB_MANAGEMENT_FC_CNT_MASK           0xfull
#define SHUB_II_CRB_MANAGEMENT_FC_CNT_INPLACE        (SHUB_II_CRB_MANAGEMENT_FC_CNT_MASK << SHUB_II_CRB_MANAGEMENT_FC_CNT_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_CLR_RPPD_SHIFT        13 /* established */
#define SHUB_II_CRB_MANAGEMENT_CLR_RPPD_MASK         0x1ull
#define SHUB_II_CRB_MANAGEMENT_CLR_RPPD_INPLACE      (SHUB_II_CRB_MANAGEMENT_CLR_RPPD_MASK << SHUB_II_CRB_MANAGEMENT_CLR_RPPD_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_CLR_RQPD_SHIFT        12 /* established */
#define SHUB_II_CRB_MANAGEMENT_CLR_RQPD_MASK         0x1ull
#define SHUB_II_CRB_MANAGEMENT_CLR_RQPD_INPLACE      (SHUB_II_CRB_MANAGEMENT_CLR_RQPD_MASK << SHUB_II_CRB_MANAGEMENT_CLR_RQPD_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_C_CNT_SHIFT           4 /* established */
#define SHUB_II_CRB_MANAGEMENT_C_CNT_MASK            0xfull
#define SHUB_II_CRB_MANAGEMENT_C_CNT_INPLACE         (SHUB_II_CRB_MANAGEMENT_C_CNT_MASK << SHUB_II_CRB_MANAGEMENT_C_CNT_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_RD_HDR_SHIFT          1 /* established */
#define SHUB_II_CRB_MANAGEMENT_RD_HDR_MASK           0x1ull
#define SHUB_II_CRB_MANAGEMENT_RD_HDR_INPLACE        (SHUB_II_CRB_MANAGEMENT_RD_HDR_MASK << SHUB_II_CRB_MANAGEMENT_RD_HDR_SHIFT)
#define SHUB_II_CRB_MANAGEMENT_SP_MSG_SHIFT          0 /* established */
#define SHUB_II_CRB_MANAGEMENT_SP_MSG_MASK           0x1ull
#define SHUB_II_CRB_MANAGEMENT_SP_MSG_INPLACE        (SHUB_II_CRB_MANAGEMENT_SP_MSG_MASK << SHUB_II_CRB_MANAGEMENT_SP_MSG_SHIFT)

/*
 * CRB control: software control of the CRB table logic; takes priority over incoming Crosstalk and BTE requests. Header name IIO_ICCR.
 */
/* crb_control: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_CONTROL                          0x4003b0 /* established */
#define SHUB_II_CRB_CONTROL_PENDING_SHIFT            16 /* established */
#define SHUB_II_CRB_CONTROL_PENDING_MASK             0x1ull
#define SHUB_II_CRB_CONTROL_PENDING_INPLACE          (SHUB_II_CRB_CONTROL_PENDING_MASK << SHUB_II_CRB_CONTROL_PENDING_SHIFT)
#define SHUB_II_CRB_CONTROL_CMD_SHIFT                8 /* established */
#define SHUB_II_CRB_CONTROL_CMD_MASK                 0xffull
#define SHUB_II_CRB_CONTROL_CMD_INPLACE              (SHUB_II_CRB_CONTROL_CMD_MASK << SHUB_II_CRB_CONTROL_CMD_SHIFT)
#define SHUB_II_CRB_CONTROL_CRB_NUM_SHIFT            0 /* established */
#define SHUB_II_CRB_CONTROL_CRB_NUM_MASK             0xfull
#define SHUB_II_CRB_CONTROL_CRB_NUM_INPLACE          (SHUB_II_CRB_CONTROL_CRB_NUM_MASK << SHUB_II_CRB_CONTROL_CRB_NUM_SHIFT)

/*
 * CRB timeout: the maximum timeout value. Header name IIO_ICTO.
 */
/* crb_timeout: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_TIMEOUT                          0x4003b8 /* established */
#define SHUB_II_CRB_TIMEOUT_TIMEOUT_SHIFT            0 /* established */
#define SHUB_II_CRB_TIMEOUT_TIMEOUT_MASK             0xffull
#define SHUB_II_CRB_TIMEOUT_TIMEOUT_INPLACE          (SHUB_II_CRB_TIMEOUT_TIMEOUT_MASK << SHUB_II_CRB_TIMEOUT_TIMEOUT_SHIFT)

/*
 * CRB timeout prescaler: how often the per-CRB timeout counters advance. Header name IIO_ICTP. SAL 5.04 PROM: written 0x1fffff (site 0xffab1cc0).
 */
/* crb_timeout_prescaler: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_TIMEOUT_PRESCALER                0x4003c0 /* established */
#define SHUB_II_CRB_TIMEOUT_PRESCALER_PRESCALE_SHIFT 0 /* established */
#define SHUB_II_CRB_TIMEOUT_PRESCALER_PRESCALE_MASK  0xffffffull
#define SHUB_II_CRB_TIMEOUT_PRESCALER_PRESCALE_INPLACE (SHUB_II_CRB_TIMEOUT_PRESCALER_PRESCALE_MASK << SHUB_II_CRB_TIMEOUT_PRESCALER_PRESCALE_SHIFT)

/*
 * CRB entry doubleword A (header IIO_ICRB0_A to IIO_ICRBE_A). Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).
 */
/* crb_a: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_A                                0x400400 /* established */
#define SHUB_II_CRB_A_COUNT                          15
#define SHUB_II_CRB_A_STRIDE                         48
#define SHUB_II_CRB_A_SIDN_SHIFT                     54 /* established */
#define SHUB_II_CRB_A_SIDN_MASK                      0xfull
#define SHUB_II_CRB_A_SIDN_INPLACE                   (SHUB_II_CRB_A_SIDN_MASK << SHUB_II_CRB_A_SIDN_SHIFT)
#define SHUB_II_CRB_A_TNUM_SHIFT                     49 /* established */
#define SHUB_II_CRB_A_TNUM_MASK                      0x1full
#define SHUB_II_CRB_A_TNUM_INPLACE                   (SHUB_II_CRB_A_TNUM_MASK << SHUB_II_CRB_A_TNUM_SHIFT)
#define SHUB_II_CRB_A_ADDR_SHIFT                     2 /* established */
#define SHUB_II_CRB_A_ADDR_MASK                      0x7fffffffffffull
#define SHUB_II_CRB_A_ADDR_INPLACE                   (SHUB_II_CRB_A_ADDR_MASK << SHUB_II_CRB_A_ADDR_SHIFT)
#define SHUB_II_CRB_A_VLD_SHIFT                      1 /* established */
#define SHUB_II_CRB_A_VLD_MASK                       0x1ull
#define SHUB_II_CRB_A_VLD_INPLACE                    (SHUB_II_CRB_A_VLD_MASK << SHUB_II_CRB_A_VLD_SHIFT)
#define SHUB_II_CRB_A_IOW_SHIFT                      0 /* established */
#define SHUB_II_CRB_A_IOW_MASK                       0x1ull
#define SHUB_II_CRB_A_IOW_INPLACE                    (SHUB_II_CRB_A_IOW_MASK << SHUB_II_CRB_A_IOW_SHIFT)

/*
 * CRB entry doubleword B (header IIO_ICRB0_B to IIO_ICRBE_B): holds the mark bit that flags an error entry, the 3-bit error code, the initiator and the incoming message type. The kernel reads it for every CRB when an II error interrupt arrives, clears the mark and then frees the entry through the deallocation register. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).
 */
/* crb_b: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_B                                0x400408 /* established */
#define SHUB_II_CRB_B_COUNT                          15
#define SHUB_II_CRB_B_STRIDE                         48
#define SHUB_II_CRB_B_USE_OLD_SHIFT                  52 /* established */
#define SHUB_II_CRB_B_USE_OLD_MASK                   0x1ull
#define SHUB_II_CRB_B_USE_OLD_INPLACE                (SHUB_II_CRB_B_USE_OLD_MASK << SHUB_II_CRB_B_USE_OLD_SHIFT)
#define SHUB_II_CRB_B_IMSGTYPE_SHIFT                 50 /* established */
#define SHUB_II_CRB_B_IMSGTYPE_MASK                  0x3ull
#define SHUB_II_CRB_B_IMSGTYPE_INPLACE               (SHUB_II_CRB_B_IMSGTYPE_MASK << SHUB_II_CRB_B_IMSGTYPE_SHIFT)
#define SHUB_II_CRB_B_IMSG_SHIFT                     42 /* established */
#define SHUB_II_CRB_B_IMSG_MASK                      0xffull
#define SHUB_II_CRB_B_IMSG_INPLACE                   (SHUB_II_CRB_B_IMSG_MASK << SHUB_II_CRB_B_IMSG_SHIFT)
#define SHUB_II_CRB_B_INIT_SHIFT                     39 /* established */
#define SHUB_II_CRB_B_INIT_MASK                      0x7ull
#define SHUB_II_CRB_B_INIT_INPLACE                   (SHUB_II_CRB_B_INIT_MASK << SHUB_II_CRB_B_INIT_SHIFT)
#define SHUB_II_CRB_B_EXC_SHIFT                      34 /* established */
#define SHUB_II_CRB_B_EXC_MASK                       0x1full
#define SHUB_II_CRB_B_EXC_INPLACE                    (SHUB_II_CRB_B_EXC_MASK << SHUB_II_CRB_B_EXC_SHIFT)
#define SHUB_II_CRB_B_ACK_CNT_SHIFT                  16 /* established */
#define SHUB_II_CRB_B_ACK_CNT_MASK                   0x7ffull
#define SHUB_II_CRB_B_ACK_CNT_INPLACE                (SHUB_II_CRB_B_ACK_CNT_MASK << SHUB_II_CRB_B_ACK_CNT_SHIFT)
#define SHUB_II_CRB_B_RESP_SHIFT                     15 /* established */
#define SHUB_II_CRB_B_RESP_MASK                      0x1ull
#define SHUB_II_CRB_B_RESP_INPLACE                   (SHUB_II_CRB_B_RESP_MASK << SHUB_II_CRB_B_RESP_SHIFT)
#define SHUB_II_CRB_B_ACK_SHIFT                      14 /* established */
#define SHUB_II_CRB_B_ACK_MASK                       0x1ull
#define SHUB_II_CRB_B_ACK_INPLACE                    (SHUB_II_CRB_B_ACK_MASK << SHUB_II_CRB_B_ACK_SHIFT)
#define SHUB_II_CRB_B_HOLD_SHIFT                     13 /* established */
#define SHUB_II_CRB_B_HOLD_MASK                      0x1ull
#define SHUB_II_CRB_B_HOLD_INPLACE                   (SHUB_II_CRB_B_HOLD_MASK << SHUB_II_CRB_B_HOLD_SHIFT)
#define SHUB_II_CRB_B_WB_SHIFT                       12 /* established */
#define SHUB_II_CRB_B_WB_MASK                        0x1ull
#define SHUB_II_CRB_B_WB_INPLACE                     (SHUB_II_CRB_B_WB_MASK << SHUB_II_CRB_B_WB_SHIFT)
#define SHUB_II_CRB_B_INTVN_SHIFT                    11 /* established */
#define SHUB_II_CRB_B_INTVN_MASK                     0x1ull
#define SHUB_II_CRB_B_INTVN_INPLACE                  (SHUB_II_CRB_B_INTVN_MASK << SHUB_II_CRB_B_INTVN_SHIFT)
#define SHUB_II_CRB_B_STALL_IB_SHIFT                 10 /* established */
#define SHUB_II_CRB_B_STALL_IB_MASK                  0x1ull
#define SHUB_II_CRB_B_STALL_IB_INPLACE               (SHUB_II_CRB_B_STALL_IB_MASK << SHUB_II_CRB_B_STALL_IB_SHIFT)
#define SHUB_II_CRB_B_STALL_INTR_SHIFT               9 /* established */
#define SHUB_II_CRB_B_STALL_INTR_MASK                0x1ull
#define SHUB_II_CRB_B_STALL_INTR_INPLACE             (SHUB_II_CRB_B_STALL_INTR_MASK << SHUB_II_CRB_B_STALL_INTR_SHIFT)
#define SHUB_II_CRB_B_STALL_BTE_0_SHIFT              8 /* established */
#define SHUB_II_CRB_B_STALL_BTE_0_MASK               0x1ull
#define SHUB_II_CRB_B_STALL_BTE_0_INPLACE            (SHUB_II_CRB_B_STALL_BTE_0_MASK << SHUB_II_CRB_B_STALL_BTE_0_SHIFT)
#define SHUB_II_CRB_B_STALL_BTE_1_SHIFT              7 /* established */
#define SHUB_II_CRB_B_STALL_BTE_1_MASK               0x1ull
#define SHUB_II_CRB_B_STALL_BTE_1_INPLACE            (SHUB_II_CRB_B_STALL_BTE_1_MASK << SHUB_II_CRB_B_STALL_BTE_1_SHIFT)
#define SHUB_II_CRB_B_ERROR_SHIFT                    6 /* established */
#define SHUB_II_CRB_B_ERROR_MASK                     0x1ull
#define SHUB_II_CRB_B_ERROR_INPLACE                  (SHUB_II_CRB_B_ERROR_MASK << SHUB_II_CRB_B_ERROR_SHIFT)
#define SHUB_II_CRB_B_ERRCODE_SHIFT                  3 /* established */
#define SHUB_II_CRB_B_ERRCODE_MASK                   0x7ull
#define SHUB_II_CRB_B_ERRCODE_INPLACE                (SHUB_II_CRB_B_ERRCODE_MASK << SHUB_II_CRB_B_ERRCODE_SHIFT)
#define SHUB_II_CRB_B_LN_UCE_SHIFT                   2 /* established */
#define SHUB_II_CRB_B_LN_UCE_MASK                    0x1ull
#define SHUB_II_CRB_B_LN_UCE_INPLACE                 (SHUB_II_CRB_B_LN_UCE_MASK << SHUB_II_CRB_B_LN_UCE_SHIFT)
#define SHUB_II_CRB_B_MARK_SHIFT                     1 /* established */
#define SHUB_II_CRB_B_MARK_MASK                      0x1ull
#define SHUB_II_CRB_B_MARK_INPLACE                   (SHUB_II_CRB_B_MARK_MASK << SHUB_II_CRB_B_MARK_SHIFT)
#define SHUB_II_CRB_B_XT_ERR_SHIFT                   0 /* established */
#define SHUB_II_CRB_B_XT_ERR_MASK                    0x1ull
#define SHUB_II_CRB_B_XT_ERR_INPLACE                 (SHUB_II_CRB_B_XT_ERR_MASK << SHUB_II_CRB_B_XT_ERR_SHIFT)

/*
 * CRB entry doubleword C (header IIO_ICRB0_C to IIO_ICRBE_C): the kernel reads the BTE number from it when the entry belongs to a BTE operation. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).
 */
/* crb_c: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_C                                0x400410 /* established */
#define SHUB_II_CRB_C_COUNT                          15
#define SHUB_II_CRB_C_STRIDE                         48
#define SHUB_II_CRB_C_SUPPL_SHIFT                    22 /* established */
#define SHUB_II_CRB_C_SUPPL_MASK                     0x7fffull
#define SHUB_II_CRB_C_SUPPL_INPLACE                  (SHUB_II_CRB_C_SUPPL_MASK << SHUB_II_CRB_C_SUPPL_SHIFT)
#define SHUB_II_CRB_C_BO_SHIFT                       21 /* established */
#define SHUB_II_CRB_C_BO_MASK                        0x1ull
#define SHUB_II_CRB_C_BO_INPLACE                     (SHUB_II_CRB_C_BO_MASK << SHUB_II_CRB_C_BO_SHIFT)
#define SHUB_II_CRB_C_RESPRQD_SHIFT                  20 /* established */
#define SHUB_II_CRB_C_RESPRQD_MASK                   0x1ull
#define SHUB_II_CRB_C_RESPRQD_INPLACE                (SHUB_II_CRB_C_RESPRQD_MASK << SHUB_II_CRB_C_RESPRQD_SHIFT)
#define SHUB_II_CRB_C_GBR_SHIFT                      19 /* established */
#define SHUB_II_CRB_C_GBR_MASK                       0x1ull
#define SHUB_II_CRB_C_GBR_INPLACE                    (SHUB_II_CRB_C_GBR_MASK << SHUB_II_CRB_C_GBR_SHIFT)
#define SHUB_II_CRB_C_BTE_NUM_SHIFT                  18 /* established */
#define SHUB_II_CRB_C_BTE_NUM_MASK                   0x1ull
#define SHUB_II_CRB_C_BTE_NUM_INPLACE                (SHUB_II_CRB_C_BTE_NUM_MASK << SHUB_II_CRB_C_BTE_NUM_SHIFT)
#define SHUB_II_CRB_C_CT_SHIFT                       17 /* established */
#define SHUB_II_CRB_C_CT_MASK                        0x1ull
#define SHUB_II_CRB_C_CT_INPLACE                     (SHUB_II_CRB_C_CT_MASK << SHUB_II_CRB_C_CT_SHIFT)
#define SHUB_II_CRB_C_SIZE_SHIFT                     15 /* established */
#define SHUB_II_CRB_C_SIZE_MASK                      0x3ull
#define SHUB_II_CRB_C_SIZE_INPLACE                   (SHUB_II_CRB_C_SIZE_MASK << SHUB_II_CRB_C_SIZE_SHIFT)
#define SHUB_II_CRB_C_SOURCE_SHIFT                   0 /* established */
#define SHUB_II_CRB_C_SOURCE_MASK                    0x7fffull
#define SHUB_II_CRB_C_SOURCE_INPLACE                 (SHUB_II_CRB_C_SOURCE_MASK << SHUB_II_CRB_C_SOURCE_SHIFT)

/*
 * CRB entry doubleword D (header IIO_ICRB0_D to IIO_ICRBE_D): carries the BTE-operation flag the kernel tests to tell BTE entries from others, and the per-entry timeout counter. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).
 */
/* crb_d: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_D                                0x400418 /* established */
#define SHUB_II_CRB_D_COUNT                          15
#define SHUB_II_CRB_D_STRIDE                         48
#define SHUB_II_CRB_D_SLEEP_SHIFT                    52 /* established */
#define SHUB_II_CRB_D_SLEEP_MASK                     0x1ull
#define SHUB_II_CRB_D_SLEEP_INPLACE                  (SHUB_II_CRB_D_SLEEP_MASK << SHUB_II_CRB_D_SLEEP_SHIFT)
#define SHUB_II_CRB_D_PR_CNT_SHIFT                   48 /* established */
#define SHUB_II_CRB_D_PR_CNT_MASK                    0xfull
#define SHUB_II_CRB_D_PR_CNT_INPLACE                 (SHUB_II_CRB_D_PR_CNT_MASK << SHUB_II_CRB_D_PR_CNT_SHIFT)
#define SHUB_II_CRB_D_PR_PSC_SHIFT                   44 /* established */
#define SHUB_II_CRB_D_PR_PSC_MASK                    0xfull
#define SHUB_II_CRB_D_PR_PSC_INPLACE                 (SHUB_II_CRB_D_PR_PSC_MASK << SHUB_II_CRB_D_PR_PSC_SHIFT)
#define SHUB_II_CRB_D_BTE_OP_SHIFT                   43 /* established */
#define SHUB_II_CRB_D_BTE_OP_MASK                    0x1ull
#define SHUB_II_CRB_D_BTE_OP_INPLACE                 (SHUB_II_CRB_D_BTE_OP_MASK << SHUB_II_CRB_D_BTE_OP_SHIFT)
#define SHUB_II_CRB_D_PA_BE_SHIFT                    0 /* established */
#define SHUB_II_CRB_D_PA_BE_MASK                     0x7ffffffffffull
#define SHUB_II_CRB_D_PA_BE_INPLACE                  (SHUB_II_CRB_D_PA_BE_MASK << SHUB_II_CRB_D_PA_BE_SHIFT)

/*
 * CRB entry doubleword E (header IIO_ICRB0_E to IIO_ICRBE_E): read by the error handler together with the other four. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).
 */
/* crb_e: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_CRB_E                                0x400420 /* established */
#define SHUB_II_CRB_E_COUNT                          15
#define SHUB_II_CRB_E_STRIDE                         48
#define SHUB_II_CRB_E_CVLD_SHIFT                     25 /* established */
#define SHUB_II_CRB_E_CVLD_MASK                      0x1ull
#define SHUB_II_CRB_E_CVLD_INPLACE                   (SHUB_II_CRB_E_CVLD_MASK << SHUB_II_CRB_E_CVLD_SHIFT)
#define SHUB_II_CRB_E_TVLD_SHIFT                     24 /* established */
#define SHUB_II_CRB_E_TVLD_MASK                      0x1ull
#define SHUB_II_CRB_E_TVLD_INPLACE                   (SHUB_II_CRB_E_TVLD_MASK << SHUB_II_CRB_E_TVLD_SHIFT)
#define SHUB_II_CRB_E_CONTEXT_SHIFT                  8 /* established */
#define SHUB_II_CRB_E_CONTEXT_MASK                   0x7fffull
#define SHUB_II_CRB_E_CONTEXT_INPLACE                (SHUB_II_CRB_E_CONTEXT_MASK << SHUB_II_CRB_E_CONTEXT_SHIFT)
#define SHUB_II_CRB_E_TIMEOUT_SHIFT                  0 /* established */
#define SHUB_II_CRB_E_TIMEOUT_MASK                   0xffull
#define SHUB_II_CRB_E_TIMEOUT_INPLACE                (SHUB_II_CRB_E_TIMEOUT_MASK << SHUB_II_CRB_E_TIMEOUT_SHIFT)

/*
 * Spurious message header, low 64 bits; valid when the spurious flag in the CRB management register is set. Header name IIO_ICSML.
 */
/* spurious_crb_message_low: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW             0x400700 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_OVERFLOW_SHIFT 63 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_OVERFLOW_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_OVERFLOW_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_OVERFLOW_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_OVERFLOW_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_NEWSUPPL_EX_SHIFT 47 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_NEWSUPPL_EX_MASK 0x3fffull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_NEWSUPPL_EX_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_NEWSUPPL_EX_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_NEWSUPPL_EX_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_TT_ADDR_SHIFT 0 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_TT_ADDR_MASK 0x7fffffffffffull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_TT_ADDR_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_TT_ADDR_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_LOW_TT_ADDR_SHIFT)

/*
 * Spurious message header, middle 64 bits. Header name IIO_ICSMM.
 */
/* spurious_crb_message_mid: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_MID             0x400708 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_MID_TT_ACK_CNT_SHIFT 0 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_MID_TT_ACK_CNT_MASK 0x7ffull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_MID_TT_ACK_CNT_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_MID_TT_ACK_CNT_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_MID_TT_ACK_CNT_SHIFT)

/*
 * Spurious message header, high bits. Header name IIO_ICSMH.
 */
/* spurious_crb_message_high: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH            0x400710 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INIT_SHIFT 56 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INIT_MASK 0x7ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INIT_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INIT_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INIT_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_DEVICE_SHIFT 49 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_DEVICE_MASK 0x7full
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_DEVICE_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_DEVICE_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_DEVICE_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_2_SHIFT 48 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_2_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_2_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_2_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_2_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_2_SHIFT 47 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_2_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_2_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_2_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_2_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_18_SHIFT 46 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_18_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_18_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_18_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_GE_18_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_18_SHIFT 45 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_18_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_18_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_18_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RQCNT_LT_18_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_2_SHIFT 44 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_2_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_2_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_2_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_2_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_2_SHIFT 43 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_2_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_2_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_2_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_2_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_18_SHIFT 42 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_18_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_18_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_18_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_18_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_18_SHIFT 41 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_18_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_18_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_18_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_18_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_34_SHIFT 40 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_34_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_34_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_34_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_GE_34_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_34_SHIFT 39 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_34_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_34_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_34_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_RPCNT_LT_34_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MATCH_SHIFT 38 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MATCH_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MATCH_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MATCH_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MATCH_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_CBN_SHIFT  37 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_CBN_MASK   0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_CBN_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_CBN_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_CBN_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_BTE_NUM_SHIFT 36 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_BTE_NUM_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_BTE_NUM_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_BTE_NUM_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_BTE_NUM_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESPREQD_SHIFT 35 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESPREQD_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESPREQD_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESPREQD_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESPREQD_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_USE_OLD_SHIFT 34 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_USE_OLD_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_USE_OLD_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_USE_OLD_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_USE_OLD_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSGTYPE_SHIFT 32 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSGTYPE_MASK 0x3ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSGTYPE_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSGTYPE_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSGTYPE_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSG_SHIFT 24 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSG_MASK 0xffull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSG_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSG_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_IMSG_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IB_SHIFT 23 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IB_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IB_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IB_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IB_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IL_SHIFT 22 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IL_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IL_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IL_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_IL_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE0_SHIFT 21 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE0_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE0_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE0_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE0_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE1_SHIFT 20 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE1_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE1_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE1_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_G_STALL_BTE1_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INTVN_SHIFT 19 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INTVN_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INTVN_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INTVN_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_INTVN_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESP_SHIFT 18 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESP_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESP_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESP_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_RESP_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_ACK_SHIFT 17 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_ACK_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_ACK_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_ACK_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_ACK_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_HOLD_SHIFT 16 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_HOLD_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_HOLD_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_HOLD_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_HOLD_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_WB_SHIFT 15 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_WB_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_WB_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_WB_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_WB_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_EXC_SHIFT 10 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_EXC_MASK 0x1full
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_EXC_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_EXC_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_EXC_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSG_SHIFT 9 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSG_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSG_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSG_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSG_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSZ_SHIFT 8 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSZ_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSZ_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSZ_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_PLUSZ_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSZ_SHIFT 7 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSZ_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSZ_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSZ_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSZ_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSG_SHIFT 6 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSG_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSG_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSG_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_MNUSG_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_SYNC_SHIFT 5 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_SYNC_MASK  0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_SYNC_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_SYNC_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_SYNC_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_ACTIVE_O_SHIFT 4 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_ACTIVE_O_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_ACTIVE_O_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_ACTIVE_O_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_ACTIVE_O_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_WACT_O_SHIFT 3 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_WACT_O_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_WACT_O_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_WACT_O_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_WACT_O_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_CWACT_O_SHIFT 2 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_CWACT_O_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_CWACT_O_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_CWACT_O_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_FT_CWACT_O_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_XERR_SHIFT 1 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_XERR_MASK  0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_XERR_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_XERR_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_XERR_SHIFT)
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_VLD_SHIFT 0 /* established */
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_VLD_MASK 0x1ull
#define SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_VLD_INPLACE (SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_VLD_MASK << SHUB_II_SPURIOUS_CRB_MESSAGE_HIGH_TT_VLD_SHIFT)

/*
 * Debug submenu select: selects what the SHub debug unit shows from the II. Header name IIO_IDBSS.
 */
/* debug_submenu_select: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_DEBUG_SUBMENU_SELECT                 0x400718 /* established */
#define SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_MENU_SHIFT 16 /* established */
#define SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_MENU_MASK 0x1full
#define SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_MENU_INPLACE (SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_MENU_MASK << SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_MENU_SHIFT)
#define SHUB_II_DEBUG_SUBMENU_SELECT_FSBCLK_WRAPPER_SUBMENU_SHIFT 8 /* established */
#define SHUB_II_DEBUG_SUBMENU_SELECT_FSBCLK_WRAPPER_SUBMENU_MASK 0x7ull
#define SHUB_II_DEBUG_SUBMENU_SELECT_FSBCLK_WRAPPER_SUBMENU_INPLACE (SHUB_II_DEBUG_SUBMENU_SELECT_FSBCLK_WRAPPER_SUBMENU_MASK << SHUB_II_DEBUG_SUBMENU_SELECT_FSBCLK_WRAPPER_SUBMENU_SHIFT)
#define SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_CORE_SUBMENU_SHIFT 0 /* established */
#define SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_CORE_SUBMENU_MASK 0x7ull
#define SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_CORE_SUBMENU_INPLACE (SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_CORE_SUBMENU_MASK << SHUB_II_DEBUG_SUBMENU_SELECT_IIOCLK_CORE_SUBMENU_SHIFT)

/*
 * BTE length and status, one block per engine (engine 1 is 64 KiB above engine 0). Length is in 128-byte cache lines. A write loads the length, sets busy and clears error; the engine counts the length down and clears busy at the end. On SHub 1 the kernel writes the length first and the control register second, which starts the transfer. Header names IIO_IBLS0 and IIO_IBLS1. Kernel: written with the length, read to see busy and error. SAL 5.04 PROM: read and written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes it with the length in lines and bit 20 set, then the notify word is polled. The PROM error-decoder name table calls it II_IBLS0 and II_IBLS1.
 */
/* bte_length_status: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_BTE_LENGTH_STATUS                    0x410000 /* established */
#define SHUB_II_BTE_LENGTH_STATUS_COUNT              2
#define SHUB_II_BTE_LENGTH_STATUS_STRIDE             65536
#define SHUB_II_BTE_LENGTH_STATUS_BUSY_SHIFT         20 /* established */
#define SHUB_II_BTE_LENGTH_STATUS_BUSY_MASK          0x1ull
#define SHUB_II_BTE_LENGTH_STATUS_BUSY_INPLACE       (SHUB_II_BTE_LENGTH_STATUS_BUSY_MASK << SHUB_II_BTE_LENGTH_STATUS_BUSY_SHIFT)
#define SHUB_II_BTE_LENGTH_STATUS_ERROR_SHIFT        16 /* established */
#define SHUB_II_BTE_LENGTH_STATUS_ERROR_MASK         0x1ull
#define SHUB_II_BTE_LENGTH_STATUS_ERROR_INPLACE      (SHUB_II_BTE_LENGTH_STATUS_ERROR_MASK << SHUB_II_BTE_LENGTH_STATUS_ERROR_SHIFT)
#define SHUB_II_BTE_LENGTH_STATUS_LENGTH_SHIFT       0 /* established */
#define SHUB_II_BTE_LENGTH_STATUS_LENGTH_MASK        0xffffull
#define SHUB_II_BTE_LENGTH_STATUS_LENGTH_INPLACE     (SHUB_II_BTE_LENGTH_STATUS_LENGTH_MASK << SHUB_II_BTE_LENGTH_STATUS_LENGTH_SHIFT)

/*
 * BTE source physical address, cache-line aligned. One per engine. Header names IIO_IBSA0 and IIO_IBSA1. Kernel: written with the source physical address, AS bits removed. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes the source with bits 63, 37 and 36 cleared. PROM name table: II_IBSA0, II_IBSA1.
 */
/* bte_source: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_BTE_SOURCE                           0x410008 /* established */
#define SHUB_II_BTE_SOURCE_COUNT                     2
#define SHUB_II_BTE_SOURCE_STRIDE                    65536
#define SHUB_II_BTE_SOURCE_ADDR_SHIFT                7 /* established */
#define SHUB_II_BTE_SOURCE_ADDR_MASK                 0x3ffffffffffull
#define SHUB_II_BTE_SOURCE_ADDR_INPLACE              (SHUB_II_BTE_SOURCE_ADDR_MASK << SHUB_II_BTE_SOURCE_ADDR_SHIFT)

/*
 * BTE destination physical address, cache-line aligned. One per engine. Header names IIO_IBDA0 and IIO_IBDA1. Kernel: written with the destination physical address, AS bits removed. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes the destination with bits 63, 37 and 36 cleared. PROM name table: II_IBDA0, II_IBDA1.
 */
/* bte_destination: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_BTE_DESTINATION                      0x410010 /* established */
#define SHUB_II_BTE_DESTINATION_COUNT                2
#define SHUB_II_BTE_DESTINATION_STRIDE               65536
#define SHUB_II_BTE_DESTINATION_ADDR_SHIFT           7 /* established */
#define SHUB_II_BTE_DESTINATION_ADDR_MASK            0x3ffffffffffull
#define SHUB_II_BTE_DESTINATION_ADDR_INPLACE         (SHUB_II_BTE_DESTINATION_ADDR_MASK << SHUB_II_BTE_DESTINATION_ADDR_SHIFT)

/*
 * BTE control and terminate: the zero-fill and notify attributes. Writing it starts the transfer. The header says that reading it ends a transfer in progress, and that stopping one engine can disturb the other. The kernel uses notify (bit 4) always and zero-fill (bit 0) for memory clears. Header names IIO_IBCT0 and IIO_IBCT1. Kernel: the last write of a transfer, with the mode. SAL 5.04 PROM: read in both engines (plain 8-byte reads, values discarded) and never written by its set-up routine (site 0xffab1cc0), which by the header ends any transfer in progress; the block copy 0xffa952f0 writes it last, with the caller flags masked to 0x11 (zero fill and notify); the credit routine 0xffa7a960 writes 0x11; the two-engine copy test 0xffa96980 writes 0x10 (notify, a plain copy) to both engines, last of the writes (see the README). PROM name table: II_IBCT0, II_IBCT1, fields POISON, NOTIFY, ZEROFILL.
 */
/* bte_control: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_BTE_CONTROL                          0x410018 /* established */
#define SHUB_II_BTE_CONTROL_COUNT                    2
#define SHUB_II_BTE_CONTROL_STRIDE                   65536
#define SHUB_II_BTE_CONTROL_POISON_SHIFT             8 /* established */
#define SHUB_II_BTE_CONTROL_POISON_MASK              0x1ull
#define SHUB_II_BTE_CONTROL_POISON_INPLACE           (SHUB_II_BTE_CONTROL_POISON_MASK << SHUB_II_BTE_CONTROL_POISON_SHIFT)
#define SHUB_II_BTE_CONTROL_NOTIFY_SHIFT             4 /* established */
#define SHUB_II_BTE_CONTROL_NOTIFY_MASK              0x1ull
#define SHUB_II_BTE_CONTROL_NOTIFY_INPLACE           (SHUB_II_BTE_CONTROL_NOTIFY_MASK << SHUB_II_BTE_CONTROL_NOTIFY_SHIFT)
#define SHUB_II_BTE_CONTROL_ZEROFILL_SHIFT           0 /* established */
#define SHUB_II_BTE_CONTROL_ZEROFILL_MASK            0x1ull
#define SHUB_II_BTE_CONTROL_ZEROFILL_INPLACE         (SHUB_II_BTE_CONTROL_ZEROFILL_MASK << SHUB_II_BTE_CONTROL_ZEROFILL_SHIFT)

/*
 * BTE notification address: a cache-line-aligned address that receives the completion write (the header calls it a write-invalidate) carrying the final length and status. Header names IIO_IBNA0 and IIO_IBNA1. Kernel: written with the physical address of a notification word. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes the notify address with bits 63, 37 and 36 cleared, after IBDA and before IBCT. PROM name table: II_IBNA0, II_IBNA1, field ADDRESS<39:07>.
 */
/* bte_notify: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_BTE_NOTIFY                           0x410020 /* established */
#define SHUB_II_BTE_NOTIFY_COUNT                     2
#define SHUB_II_BTE_NOTIFY_STRIDE                    65536
#define SHUB_II_BTE_NOTIFY_ADDR_SHIFT                7 /* established */
#define SHUB_II_BTE_NOTIFY_ADDR_MASK                 0x3ffffffffffull
#define SHUB_II_BTE_NOTIFY_ADDR_INPLACE              (SHUB_II_BTE_NOTIFY_ADDR_MASK << SHUB_II_BTE_NOTIFY_ADDR_SHIFT)

/*
 * BTE interrupt address: programmable level, node and PI unit of the processor to interrupt on completion. The kernel never uses it. Header names IIO_IBIA0 and IIO_IBIA1. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0) and never otherwise. PROM name table: II_IBIA0, II_IBIA1, field NODEID.
 */
/* bte_interrupt: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_BTE_INTERRUPT                        0x410028 /* established */
#define SHUB_II_BTE_INTERRUPT_COUNT                  2
#define SHUB_II_BTE_INTERRUPT_STRIDE                 65536
#define SHUB_II_BTE_INTERRUPT_LEVEL_SHIFT            16 /* established */
#define SHUB_II_BTE_INTERRUPT_LEVEL_MASK             0x7full
#define SHUB_II_BTE_INTERRUPT_LEVEL_INPLACE          (SHUB_II_BTE_INTERRUPT_LEVEL_MASK << SHUB_II_BTE_INTERRUPT_LEVEL_SHIFT)
#define SHUB_II_BTE_INTERRUPT_NODE_ID_SHIFT          1 /* established */
#define SHUB_II_BTE_INTERRUPT_NODE_ID_MASK           0x7ffull
#define SHUB_II_BTE_INTERRUPT_NODE_ID_INPLACE        (SHUB_II_BTE_INTERRUPT_NODE_ID_MASK << SHUB_II_BTE_INTERRUPT_NODE_ID_SHIFT)

/*
 * I/O performance control: selects which of 17 quantities each of the two performance counters measures. Header name IIO_IPCR. SAL 5.04 PROM: written 0 (site 0xffab1cc0).
 */
/* perf_control: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_PERF_CONTROL                         0x430000 /* established */
#define SHUB_II_PERF_CONTROL_ICCT_SHIFT              8 /* established */
#define SHUB_II_PERF_CONTROL_ICCT_MASK               0xffull
#define SHUB_II_PERF_CONTROL_ICCT_INPLACE            (SHUB_II_PERF_CONTROL_ICCT_MASK << SHUB_II_PERF_CONTROL_ICCT_SHIFT)
#define SHUB_II_PERF_CONTROL_IPPR1_C_SHIFT           4 /* established */
#define SHUB_II_PERF_CONTROL_IPPR1_C_MASK            0xfull
#define SHUB_II_PERF_CONTROL_IPPR1_C_INPLACE         (SHUB_II_PERF_CONTROL_IPPR1_C_MASK << SHUB_II_PERF_CONTROL_IPPR1_C_SHIFT)
#define SHUB_II_PERF_CONTROL_IPPR0_C_SHIFT           0 /* established */
#define SHUB_II_PERF_CONTROL_IPPR0_C_MASK            0xfull
#define SHUB_II_PERF_CONTROL_IPPR0_C_INPLACE         (SHUB_II_PERF_CONTROL_IPPR0_C_MASK << SHUB_II_PERF_CONTROL_IPPR0_C_SHIFT)

/*
 * I/O performance profiling: the counter values. Header name IIO_IPPR. SAL 5.04 PROM: read once, value discarded (site 0xffab1cc0).
 */
/* perf_profile: rw64, reset unknown; Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code */
#define SHUB_II_PERF_PROFILE                         0x430008 /* established */
#define SHUB_II_PERF_PROFILE_IPPR1_SHIFT             32 /* established */
#define SHUB_II_PERF_PROFILE_IPPR1_MASK              0xffffffffull
#define SHUB_II_PERF_PROFILE_IPPR1_INPLACE           (SHUB_II_PERF_PROFILE_IPPR1_MASK << SHUB_II_PERF_PROFILE_IPPR1_SHIFT)
#define SHUB_II_PERF_PROFILE_IPPR0_SHIFT             0 /* established */
#define SHUB_II_PERF_PROFILE_IPPR0_MASK              0xffffffffull
#define SHUB_II_PERF_PROFILE_IPPR0_INPLACE           (SHUB_II_PERF_PROFILE_IPPR0_MASK << SHUB_II_PERF_PROFILE_IPPR0_SHIFT)

#define SHUB_II_BTE_ENGINES                          0x2u /* established */
#define SHUB_II_BTE_LEN_BITS                         0x10u /* established */
#define SHUB_II_BTE_LINE_BYTES                       0x80u /* inferred */
#define SHUB_II_CRB_STRIDE                           0x30u /* established */
#define SHUB_II_CRB_TIMEOUT_PRESCALE_PROM            0x1fffffu /* established */
#define SHUB_II_ERROR_CLEAR_ALL                      0x7ffffffffffull /* established */
#define SHUB_II_HUB_WIDGET_ID_MAX                    0xfu /* established */
#define SHUB_II_ICRB_ECODE_AERR                      0x3u /* established */
#define SHUB_II_ICRB_ECODE_DERR                      0x0u /* established */
#define SHUB_II_ICRB_ECODE_PERR                      0x1u /* established */
#define SHUB_II_ICRB_ECODE_PRERR                     0x5u /* established */
#define SHUB_II_ICRB_ECODE_PWERR                     0x4u /* established */
#define SHUB_II_ICRB_ECODE_TOUT                      0x6u /* established */
#define SHUB_II_ICRB_ECODE_WERR                      0x2u /* established */
#define SHUB_II_ICRB_ECODE_XTERR                     0x7u /* established */
#define SHUB_II_ICRB_IMSGT_BTE                       0x1u /* established */
#define SHUB_II_ICRB_IMSGT_CRB                       0x3u /* established */
#define SHUB_II_ICRB_IMSGT_SN1NET                    0x2u /* established */
#define SHUB_II_ICRB_IMSGT_XTALK                     0x0u /* established */
#define SHUB_II_ICRB_INIT_BTE0                       0x1u /* established */
#define SHUB_II_ICRB_INIT_BTE1                       0x5u /* established */
#define SHUB_II_ICRB_INIT_CRB                        0x3u /* established */
#define SHUB_II_ICRB_INIT_NET                        0x2u /* established */
#define SHUB_II_ICRB_INIT_XTALK                      0x0u /* established */
#define SHUB_II_IIDEM_DEVICES_PER_WIDGET             0x8u /* established */
#define SHUB_II_LLP_NULLTO_PROM                      0x3u /* established */
#define SHUB_II_NUM_BIG_WINDOWS                      0x6u /* established */
#define SHUB_II_NUM_CRBS                             0xfu /* established */
#define SHUB_II_NUM_ITTES                            0x7u /* established */
#define SHUB_II_PROTECTION_OVERRIDE_KEY              0x53474972756c6573ull /* established */
#define SHUB_II_WARM_RESET                           0x100u /* established */
#define SHUB_II_WCR_DST_CRD_PROM                     0x4u /* established */
#define SHUB_II_WIDGET_ACCESS_OPEN                   0xff01u /* established */
#define SHUB_II_XTALK_ADDR_REGISTER_SPACE            0x800000000000ull /* inferred */
#define SHUB_II_XTALK_DMA_NASID_SHIFT                0x24u /* established */

#endif /* SHUB_II_GEN_H */
