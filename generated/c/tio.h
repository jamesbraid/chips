/* generated from devices/tio/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 b463b599a6e231ec27eb619f305e4db2b5869fa84254ccd3fe4d207973c9b22e */
/* TIO (NUMAlink I/O node ASIC of the Altix generation), as SGI's Linux platform code names its registers */
#ifndef TIO_GEN_H
#define TIO_GEN_H

#include <stdint.h>


/*
 * Widget-format identification word of the TIO itself (`TIO_NODE_ID`). The kernel reads the whole 64-bit register, keeps the low 32 bits and splits them with the same macros it uses for every widget identification word: part number, revision, manufacturer. Its one use: the revision field decides whether the write-request flush workaround applies (revision 1). The SHub 2 PROM also read-modify-writes the register to install the node number (bits 45:32) and a six-bit value (bits 53:48); see devices/tio/prom-access.md.
 */
/* node_id: rw64, reset unknown */
#define TIO_NODE_ID                                  0x90060e80 /* established */
#define TIO_NODE_ID_NODES_PER_BIT_POW2_SHIFT         48 /* inferred */
#define TIO_NODE_ID_NODES_PER_BIT_POW2_MASK          0x3full
#define TIO_NODE_ID_NODES_PER_BIT_POW2_INPLACE       (TIO_NODE_ID_NODES_PER_BIT_POW2_MASK << TIO_NODE_ID_NODES_PER_BIT_POW2_SHIFT)
#define TIO_NODE_ID_NODE_SHIFT                       32 /* established */
#define TIO_NODE_ID_NODE_MASK                        0x3fffull
#define TIO_NODE_ID_NODE_INPLACE                     (TIO_NODE_ID_NODE_MASK << TIO_NODE_ID_NODE_SHIFT)
#define TIO_NODE_ID_REV_SHIFT                        28 /* established */
#define TIO_NODE_ID_REV_MASK                         0xfull
#define TIO_NODE_ID_REV_INPLACE                      (TIO_NODE_ID_REV_MASK << TIO_NODE_ID_REV_SHIFT)
#define TIO_NODE_ID_PART_SHIFT                       12 /* established */
#define TIO_NODE_ID_PART_MASK                        0xffffull
#define TIO_NODE_ID_PART_INPLACE                     (TIO_NODE_ID_PART_MASK << TIO_NODE_ID_PART_SHIFT)
#define TIO_NODE_ID_MFG_SHIFT                        1 /* established */
#define TIO_NODE_ID_MFG_MASK                         0x7ffull
#define TIO_NODE_ID_MFG_INPLACE                      (TIO_NODE_ID_MFG_MASK << TIO_NODE_ID_MFG_SHIFT)

/*
 * ICE chiplet freeze configuration (`TIO_ICE_FRZ_CFG`). Bit 61 disables the conveyor of the FPGA port: the FPGA-port driver clears it to enable and sets it to disable, reading before writing and skipping the write when the bit is already right. Other bits are not read by any code.
 */
/* ice_frz_cfg: rw64, reset unknown */
#define TIO_ICE_FRZ_CFG                              0xb0008100 /* established */
#define TIO_ICE_FRZ_CFG_DISABLE_CONVEYOR_SHIFT       61 /* established */
#define TIO_ICE_FRZ_CFG_DISABLE_CONVEYOR_MASK        0x1ull
#define TIO_ICE_FRZ_CFG_DISABLE_CONVEYOR_INPLACE     (TIO_ICE_FRZ_CFG_DISABLE_CONVEYOR_MASK << TIO_ICE_FRZ_CFG_DISABLE_CONVEYOR_SHIFT)

/*
 * Big-window translation table entries (`TIO_ITTE_BASE`, one entry per big window number 0 to 7). An entry maps one 1 GiB window of the TIO's address space onto a widget. The kernel defines a store macro (`TIO_ITTE_PUT`) and reads a firmware-held copy of the entries to find the widget for a window; no code read writes the register itself. The field positions are the macro's.
 */
/* itte: rw64, reset unknown */
#define TIO_ITTE                                     0xb0008800 /* established */
#define TIO_ITTE_COUNT                               8
#define TIO_ITTE_STRIDE                              8
#define TIO_ITTE_VALID_SHIFT                         16 /* established */
#define TIO_ITTE_VALID_MASK                          0x1ull
#define TIO_ITTE_VALID_INPLACE                       (TIO_ITTE_VALID_MASK << TIO_ITTE_VALID_SHIFT)
#define TIO_ITTE_WIDGET_SHIFT                        12 /* established */
#define TIO_ITTE_WIDGET_MASK                         0x3ull
#define TIO_ITTE_WIDGET_INPLACE                      (TIO_ITTE_WIDGET_MASK << TIO_ITTE_WIDGET_SHIFT)
#define TIO_ITTE_OFFSET_SHIFT                        0 /* established */
#define TIO_ITTE_OFFSET_MASK                         0xffull
#define TIO_ITTE_OFFSET_INPLACE                      (TIO_ITTE_OFFSET_MASK << TIO_ITTE_OFFSET_SHIFT)

/*
 * ICE port-module interface transmit configuration (`TIO_ICE_PMI_TX_CFG`). The FPGA-port driver resets corelet n by writing a one in bit n, waiting 2 ms, writing zero, then waiting 2 ms. The FPGA corelet is number 3.
 */
/* ice_pmi_tx_cfg: rw64, reset unknown */
#define TIO_ICE_PMI_TX_CFG                           0xb000b100 /* established */

/*
 * Dynamic transmit credit status of channel buffer 3 (`TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3`). The driver treats a credit count of 15 as proof that an FPGA bitstream is loaded and the port is running.
 */
/* ice_pmi_tx_dyn_credit_stat_cb3: r64, reset unknown */
#define TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3           0xb000be18 /* established */
#define TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3_CREDIT_COUNT_SHIFT 0 /* established */
#define TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3_CREDIT_COUNT_MASK 0xfull
#define TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3_CREDIT_COUNT_INPLACE (TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3_CREDIT_COUNT_MASK << TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3_CREDIT_COUNT_SHIFT)

#define TIO_BIG_WINDOW_SIZE_BITS                     0x1eu /* established */
#define TIO_CE_PART_NUMBER                           0xce00u /* established */
#define TIO_CTALK_CHIPLET_SHIFT                      0x26u /* established */
#define TIO_CTALK_NASID_SHIFT                        0x28u /* established */
#define TIO_ERROR_VECTOR                             0x36u /* established */
#define TIO_ERROR_VECTOR_TIOCA                       0x35u /* established */
#define TIO_ERROR_VECTOR_TIOCX                       0x37u /* established */
#define TIO_FPGA_CORELET                             0x3u /* established */
#define TIO_INTR_VECTOR_SHIFT                        0x38u /* established */
#define TIO_KLTYPE_TIO                               0x12u /* established */
#define TIO_SAL_HUB_ERROR_INTERRUPT                  0x2000060u /* established */
#define TIO_SAL_IOIF_INTERRUPT                       0x200004au /* established */
#define TIO_SMALL_WINDOW_SIZE_BITS                   0x1cu /* established */
#define TIO_WIDGET_ID_OFFSET                         0x0u /* established */

#endif /* TIO_GEN_H */
