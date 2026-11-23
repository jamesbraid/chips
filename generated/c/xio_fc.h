/* generated from devices/xio_fc/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 57e8737a3343b26b5b9baa63badf937ee000b92384357355a269d98dd44823d0 */
/* XIO Fibre Channel adapter (Adaptec AIC-1160 board), command and register
 * contract */
#ifndef XIO_FC_GEN_H
#define XIO_FC_GEN_H

#include <stdint.h>


#define XIO_FC_BANK_CODE_STEP                        0x11u /* established */
#define XIO_FC_CLOCK_STATUS_DIV_1                    0xbeu /* established */
#define XIO_FC_CLOCK_STATUS_DIV_2_A                  0x2eu /* established */
#define XIO_FC_CLOCK_STATUS_DIV_2_B                  0xfeu /* established */
#define XIO_FC_CLOCK_STATUS_DIV_4                    0x6eu /* established */
#define XIO_FC_CLOCK_STATUS_MASK                     0xfcu /* established */
#define XIO_FC_CLOCK_STATUS_OR                       0x2u /* established */
#define XIO_FC_DONE_HANDLE                           0x0u /* established */
#define XIO_FC_DONE_PASS                             0x3u /* established */
#define XIO_FC_DONE_STATUS                           0x2u /* established */
#define XIO_FC_HOST_CTRL_MASTER_IRQ_EN               0x4u /* established */
#define XIO_FC_HOST_CTRL_PAUSE                       0x40u /* established */
#define XIO_FC_HOST_CTRL_PAUSE_AT_TOP                0x80u /* established */
#define XIO_FC_HOST_CTRL_RESET_WRITE                 0x43u /* established */
#define XIO_FC_INT_BREAKPOINT                        0x200u /* inferred */
#define XIO_FC_INT_HARDWARE_ERROR                    0x4000u /* established */
#define XIO_FC_INT_HOST_COMPLETION                   0x400u /* inferred */
#define XIO_FC_INT_LOOP_ATTENTION                    0x8u /* established */
#define XIO_FC_INT_PCI_ERROR                         0x8000u /* established */
#define XIO_FC_INT_SEQ_COMPLETION                    0x1000u /* established */
#define XIO_FC_INT_SEQ_READY_FOR_LIP                 0x100u /* established */
#define XIO_FC_INT_SOFTWARE_ERROR                    0x2000u /* established */
#define XIO_FC_LINK_CTRL_LINK_ENABLE                 0x40u /* established */
#define XIO_FC_LINK_CTRL_LINK_RESET                  0x20u /* established */
#define XIO_FC_LINK_CTRL_LOSS_OF_SIGNAL              0x1u /* established */
#define XIO_FC_LINK_CTRL_LOSS_OF_SYNC                0x2u /* established */
#define XIO_FC_PLOGI_ACC_CLASS1_PARAMS               0x24u /* inferred */
#define XIO_FC_PLOGI_ACC_CLASS2_PARAMS               0x34u /* inferred */
#define XIO_FC_PLOGI_ACC_CLASS3_PARAMS               0x44u /* inferred */
#define XIO_FC_PLOGI_ACC_CODE                        0x0u /* established */
#define XIO_FC_PLOGI_ACC_COMMON_PARAMS               0x4u /* inferred */
#define XIO_FC_PLOGI_ACC_LENGTH                      0x74u /* established */
#define XIO_FC_PLOGI_ACC_NODE_NAME                   0x1cu /* inferred */
#define XIO_FC_PLOGI_ACC_PORT_NAME                   0x14u /* inferred */
#define XIO_FC_PLOGI_ACC_RESERVED                    0x54u /* inferred */
#define XIO_FC_PLOGI_ACC_VENDOR_VERSION              0x64u /* inferred */
#define XIO_FC_PLOGI_REJECT_EXPLANATION              0x6u /* established */
#define XIO_FC_PLOGI_REJECT_REASON                   0x5u /* established */
#define XIO_FC_PRLI_ACC_CODE                         0x0u /* established */
#define XIO_FC_PRLI_ACC_FLAGS                        0x6u /* inferred */
#define XIO_FC_PRLI_ACC_LENGTH                       0x14u /* established */
#define XIO_FC_PRLI_ACC_ORIGINATOR_ASSOC             0x8u /* inferred */
#define XIO_FC_PRLI_ACC_PAGE_LENGTH                  0x1u /* inferred */
#define XIO_FC_PRLI_ACC_PAYLOAD_LENGTH               0x2u /* inferred */
#define XIO_FC_PRLI_ACC_RESPONDER_ASSOC              0xcu /* inferred */
#define XIO_FC_PRLI_ACC_SERVICE_BYTE                 0x13u /* established */
#define XIO_FC_PRLI_ACC_TYPE                         0x4u /* inferred */
#define XIO_FC_REG_BANK_SELECT                       0x2cu /* established */
#define XIO_FC_REG_CLOCK_STATUS                      0x63u /* established */
#define XIO_FC_REG_HOST_CONTROL                      0x22u /* established */
#define XIO_FC_REG_LINK_CONTROL                      0xe1u /* established */
#define XIO_FC_REG_SEQ_CONTROL                       0x0u /* established */
#define XIO_FC_REG_SERDES_STATUS                     0xebu /* established */
#define XIO_FC_RESID_SEGMENT_RESIDUAL                0x8u /* established */
#define XIO_FC_RESID_SG_ELEMENT_INDEX                0xcu /* established */
#define XIO_FC_RESID_SG_PAGE_PTR                     0x0u /* established */
#define XIO_FC_RESP_FCP_STATUS_FLAGS                 0xau /* established */
#define XIO_FC_RESP_PAYLOAD                          0x18u /* inferred */
#define XIO_FC_RESP_RESIDUAL                         0xcu /* established */
#define XIO_FC_RESP_RESIDUAL_INFO                    0x80u /* established */
#define XIO_FC_RESP_RESPONSE_LEN                     0x14u /* established */
#define XIO_FC_RESP_SCSI_STATUS                      0xbu /* established */
#define XIO_FC_RESP_SENSE_LEN                        0x10u /* established */
#define XIO_FC_SEQ_CTRL_RAM_LOAD                     0x1u /* established */
#define XIO_FC_SEQ_CTRL_RESET_PC                     0x2u /* inferred */
#define XIO_FC_SEQ_CTRL_RUN                          0x40u /* established */
#define XIO_FC_SEQ_CTRL_START                        0x42u /* established */
#define XIO_FC_SERDES_FAULT                          0x10u /* established */
#define XIO_FC_SERDES_LOCK_NOT_IN_USE                0x8u /* established */
#define XIO_FC_SERDES_MEDIA_SENSE_MASK               0x3u /* established */
#define XIO_FC_TCB_CONTROL                           0x21u /* established */
#define XIO_FC_TCB_DATA_LEN                          0x60u /* established */
#define XIO_FC_TCB_DATA_PTR                          0x4cu /* established */
#define XIO_FC_TCB_DELIMITER                         0x9u /* established */
#define XIO_FC_TCB_DESC_MODE                         0x23u /* established */
#define XIO_FC_TCB_D_ID                              0x4u /* established */
#define XIO_FC_TCB_FCP_CDB                           0x30u /* established */
#define XIO_FC_TCB_FCP_CNTL                          0x2cu /* established */
#define XIO_FC_TCB_FCP_DL                            0x40u /* established */
#define XIO_FC_TCB_FCP_LUN                           0x24u /* established */
#define XIO_FC_TCB_F_CTL0                            0x10u /* established */
#define XIO_FC_TCB_F_CTL1                            0x11u /* inferred */
#define XIO_FC_TCB_F_CTL2                            0xeu /* established */
#define XIO_FC_TCB_HANDLE_COPY                       0x68u /* established */
#define XIO_FC_TCB_LOOP_FLAGS                        0x1cu /* established */
#define XIO_FC_TCB_NEXT                              0x44u /* established */
#define XIO_FC_TCB_OX_ID                             0x0u /* established */
#define XIO_FC_TCB_RESP_PTR                          0x58u /* established */
#define XIO_FC_TCB_RX_ID                             0x2u /* established */
#define XIO_FC_TCB_R_CTL                             0x7u /* established */
#define XIO_FC_TCB_SEQ_CNT                           0x14u /* inferred */
#define XIO_FC_TCB_SEQ_ID                            0x13u /* inferred */
#define XIO_FC_TCB_TYPE                              0xfu /* established */
#define XIO_FC_TCB_UNKNOWN_64                        0x64u /* established */
#define XIO_FC_TCB_XFER_LEN                          0x54u /* established */

#endif /* XIO_FC_GEN_H */
