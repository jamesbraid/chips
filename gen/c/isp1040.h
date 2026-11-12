/* generated from defs/isp1040.toml by defs-gen - do not edit, change the source */
/* QLogic ISP1040 family SCSI host adapter (PCI 1077:1020), register and mailbox contract */
#ifndef ISP1040_GEN_H
#define ISP1040_GEN_H

#include <stdint.h>


/*
 * Low half of the identity word. The reset value is not stated by any source.
 */
/* id_l: r16, reset unknown; Linux qla1280 driver header device register layout */
#define ISP1040_ID_L_OFFSET                          0x0u /* established */

/*
 * High half of the identity word. The reset value is not stated by any source.
 */
/* id_h: r16, reset unknown; Linux qla1280 driver header device register layout */
#define ISP1040_ID_H_OFFSET                          0x2u /* established */

/*
 * Configuration 0. Its low four bits hold the hardware revision. Linux compares that revision with the 1040A value only, to decide whether to set the FIFO threshold. Linux does not use it to name the part.
 */
/* cfg_0: r16, reset unknown; Linux qla1280 driver header device register layout; qla1280 driver hardware revision test */
#define ISP1040_CFG_0_OFFSET                         0x4u /* established */
#define ISP1040_CFG_0_HW_REVISION_SHIFT              0 /* established */
#define ISP1040_CFG_0_HW_REVISION_MASK               0xfu
#define ISP1040_CFG_0_HW_REVISION_INPLACE            (ISP1040_CFG_0_HW_REVISION_MASK << ISP1040_CFG_0_HW_REVISION_SHIFT)

/*
 * Configuration 1: FIFO threshold and bus burst enable, written by the drivers at start-up.
 */
/* cfg_1: rw16, reset unknown; Linux qla1280 driver header device register layout */
#define ISP1040_CFG_1_OFFSET                         0x6u /* established */

/*
 * Bus interface control. It holds the soft reset bit, the interrupt enables and the flash BIOS controls.
 */
/* ictrl: rw16, reset unknown; Linux qla1280 driver header device register layout and its use in qla1280 driver */
#define ISP1040_ICTRL_OFFSET                         0x8u /* established */
#define ISP1040_ICTRL_FLASH_UPPER_SHIFT              9 /* inferred */
#define ISP1040_ICTRL_FLASH_UPPER_MASK               0x1u
#define ISP1040_ICTRL_FLASH_UPPER_INPLACE            (ISP1040_ICTRL_FLASH_UPPER_MASK << ISP1040_ICTRL_FLASH_UPPER_SHIFT)
#define ISP1040_ICTRL_FLASH_ENABLE_SHIFT             8 /* inferred */
#define ISP1040_ICTRL_FLASH_ENABLE_MASK              0x1u
#define ISP1040_ICTRL_FLASH_ENABLE_INPLACE           (ISP1040_ICTRL_FLASH_ENABLE_MASK << ISP1040_ICTRL_FLASH_ENABLE_SHIFT)
#define ISP1040_ICTRL_RISC_INT_ENABLE_SHIFT          2 /* inferred */
#define ISP1040_ICTRL_RISC_INT_ENABLE_MASK           0x1u
#define ISP1040_ICTRL_RISC_INT_ENABLE_INPLACE        (ISP1040_ICTRL_RISC_INT_ENABLE_MASK << ISP1040_ICTRL_RISC_INT_ENABLE_SHIFT)
#define ISP1040_ICTRL_INT_ENABLE_SHIFT               1 /* inferred */
#define ISP1040_ICTRL_INT_ENABLE_MASK                0x1u
#define ISP1040_ICTRL_INT_ENABLE_INPLACE             (ISP1040_ICTRL_INT_ENABLE_MASK << ISP1040_ICTRL_INT_ENABLE_SHIFT)
#define ISP1040_ICTRL_SOFT_RESET_SHIFT               0 /* inferred */
#define ISP1040_ICTRL_SOFT_RESET_MASK                0x1u
#define ISP1040_ICTRL_SOFT_RESET_INPLACE             (ISP1040_ICTRL_SOFT_RESET_MASK << ISP1040_ICTRL_SOFT_RESET_SHIFT)

/*
 * Interface status. Its bit meanings are not described here; the reset value is unknown.
 */
/* istatus: r16, reset unknown; Linux qla1280 driver header device register layout */
#define ISP1040_ISTATUS_OFFSET                       0xau /* established */

/*
 * Semaphore register. Linux names it; its use is not described here.
 */
/* semaphore: rw16, reset unknown; Linux qla1280 driver header device register layout */
#define ISP1040_SEMAPHORE_OFFSET                     0xcu /* established */

/*
 * Serial NVRAM interface register. Linux names its clock, select, data-out and data-in bits.
 */
/* nvram: rw16, reset unknown; Linux qla1280 driver header device register layout */
#define ISP1040_NVRAM_OFFSET                         0xeu /* established */

/*
 * Flash BIOS data. Linux and OpenBSD both name it for this part. The NetBSD driver assigns the same offset to request-queue pointers for a later chip generation, so the naming rests on two drivers and is not confirmed by a manual.
 */
/* flash_data: rw16, reset unknown; Linux qla1280 driver header and OpenBSD qlw driver header, both naming the flash data word */
#define ISP1040_FLASH_DATA_OFFSET                    0x10u /* inferred */

/*
 * Flash BIOS address. The same naming and the same two-driver footing as the flash data word.
 */
/* flash_address: rw16, reset unknown; Linux qla1280 driver header and OpenBSD qlw driver header, both naming the flash address word */
#define ISP1040_FLASH_ADDRESS_OFFSET                 0x12u /* inferred */

/*
 * Eight 16-bit mailbox registers, mailboxes 0 to 7 at 0x70 to 0x7e. Mailbox 0 carries the opcode of each command. The other mailboxes carry its operands and results, and their meaning is given per opcode below.
 */
/* mailbox: rw16, reset unknown; Linux qla1280 driver header device register layout (mailbox 0 at 0x70); OpenBSD QLW_MBOX_BASE_PCI */
#define ISP1040_MAILBOX_OFFSET                       0x70u /* established */
#define ISP1040_MAILBOX_COUNT                        8
#define ISP1040_MAILBOX_STRIDE                       2

#define ISP1040_ASYNC_BUS_RESET                      0x8001u /* established */
#define ISP1040_BUSES                                0x1u /* inferred */
#define ISP1040_DRIVER_SELECTION_TIMEOUT_DEFAULT     0xfau /* inferred */
#define ISP1040_OP_BUS_RESET                         0x18u /* established */
#define ISP1040_OP_DUMP_RAM_64                       0xau /* inferred */
#define ISP1040_OP_GET_TARGET_PARAMS                 0x28u /* established */
#define ISP1040_OP_LOAD_RAM_64                       0x9u /* inferred */
#define ISP1040_OP_SET_RESET_DELAY_PARAMS            0x3au /* established */
#define ISP1040_OP_SET_RETRY_COUNT                   0x32u /* established */
#define ISP1040_OP_SET_SELECTION_TIMEOUT             0x31u /* established */
#define ISP1040_OP_SET_TARGET_PARAMS                 0x38u /* established */
#define ISP1040_PCI_REV_1040                         0x2u /* inferred */
#define ISP1040_PCI_REV_1040A                        0x3u /* inferred */
#define ISP1040_PCI_REV_1040B                        0x4u /* inferred */
#define ISP1040_PCI_REV_1040C                        0x5u /* inferred */
#define ISP1040_SCSI2_SELECTION_ABORT_US             0xc8u /* established */
#define ISP1040_SCSI2_SELECTION_TIMEOUT_MS           0xfau /* established */
#define ISP1040_STATE_GOT_BUS                        0x100u /* established */
#define ISP1040_STATE_GOT_SENSE                      0x2000u /* inferred */
#define ISP1040_STATE_GOT_TARGET                     0x200u /* established */
#define ISP1040_STATUS_COMP_INCOMPLETE               0x1u /* established */
#define ISP1040_STATUS_COMP_RESET                    0x4u /* established */
#define ISP1040_STATUS_ENTRY_COMP_STATUS_OFFSET      0xau /* established */
#define ISP1040_STATUS_ENTRY_SENSE_LENGTH_OFFSET     0x12u /* established */
#define ISP1040_STATUS_ENTRY_STATE_FLAGS_OFFSET      0xcu /* established */
#define ISP1040_STATUS_ENTRY_STATUS_FLAGS_OFFSET     0xeu /* established */
#define ISP1040_STATUS_FLAG_SELECTION_TIMEOUT        0x40u /* inferred */

#endif /* ISP1040_GEN_H */
