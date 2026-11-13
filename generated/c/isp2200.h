/* generated from devices/isp2200/registers.toml by defs-gen - do not edit, change the source */
/* QLogic ISP2200 Fibre Channel host adapter (PCI 1077:2200), the host interface the public drivers use */
#ifndef ISP2200_GEN_H
#define ISP2200_GEN_H

#include <stdint.h>


/* enum hccr_cmd */
#define ISP2200_HCCR_CMD_NOOP                        0 /* established */
#define ISP2200_HCCR_CMD_RESET_RISC                  1 /* established */
#define ISP2200_HCCR_CMD_PAUSE_RISC                  2 /* established */
#define ISP2200_HCCR_CMD_RELEASE_RISC                3 /* established */
#define ISP2200_HCCR_CMD_PARITY                      4 /* established */
#define ISP2200_HCCR_CMD_SET_HOST_INT                5 /* established */
#define ISP2200_HCCR_CMD_CLEAR_HOST_INT              6 /* established */
#define ISP2200_HCCR_CMD_CLEAR_RISC_INT              7 /* established */

/*
 * Control and status register. Writing bit 0 starts a soft reset. The drivers poll the bit until the adapter clears it. Bits 5 and 4 choose the bank that answers the banked window. Linux and NetBSD disagree on the flash bank bits, so those bits are not named here.
 */
/* csr: rw16, reset unknown */
#define ISP2200_CSR_OFFSET                           0x6u /* established */
#define ISP2200_CSR_BANK_SHIFT                       4 /* established */
#define ISP2200_CSR_BANK_MASK                        0x3u
#define ISP2200_CSR_BANK_INPLACE                     (ISP2200_CSR_BANK_MASK << ISP2200_CSR_BANK_SHIFT)
#define ISP2200_CSR_SOFT_RESET_SHIFT                 0 /* established */
#define ISP2200_CSR_SOFT_RESET_MASK                  0x1u
#define ISP2200_CSR_SOFT_RESET_INPLACE               (ISP2200_CSR_SOFT_RESET_MASK << ISP2200_CSR_SOFT_RESET_SHIFT)

/*
 * Interrupt control. The drivers write 0x8008 to enable and 0 to disable. Other bits are not used by any public driver for this part.
 */
/* icr: rw16, reset unknown */
#define ISP2200_ICR_OFFSET                           0x8u /* established */
#define ISP2200_ICR_GLOBAL_ENABLE_SHIFT              15 /* established */
#define ISP2200_ICR_GLOBAL_ENABLE_MASK               0x1u
#define ISP2200_ICR_GLOBAL_ENABLE_INPLACE            (ISP2200_ICR_GLOBAL_ENABLE_MASK << ISP2200_ICR_GLOBAL_ENABLE_SHIFT)
#define ISP2200_ICR_RISC_ENABLE_SHIFT                3 /* established */
#define ISP2200_ICR_RISC_ENABLE_MASK                 0x1u
#define ISP2200_ICR_RISC_ENABLE_INPLACE              (ISP2200_ICR_RISC_ENABLE_MASK << ISP2200_ICR_RISC_ENABLE_SHIFT)

/*
 * Interrupt status. Drivers test the RISC interrupt bit first. OpenBSD also tests the pending bit before it reads the response ring.
 */
/* isr: r16, reset unknown */
#define ISP2200_ISR_OFFSET                           0xau /* established */
#define ISP2200_ISR_ANY_PENDING_SHIFT                15 /* inferred */
#define ISP2200_ISR_ANY_PENDING_MASK                 0x1u
#define ISP2200_ISR_ANY_PENDING_INPLACE              (ISP2200_ISR_ANY_PENDING_MASK << ISP2200_ISR_ANY_PENDING_SHIFT)
#define ISP2200_ISR_RISC_PENDING_SHIFT               3 /* established */
#define ISP2200_ISR_RISC_PENDING_MASK                0x1u
#define ISP2200_ISR_RISC_PENDING_INPLACE             (ISP2200_ISR_RISC_PENDING_MASK << ISP2200_ISR_RISC_PENDING_SHIFT)

/*
 * Semaphore. The adapter sets the lock bit when a mailbox result or asynchronous event waits for the host. The host releases it by writing 0, and the drivers release it last, after reading the mailboxes.
 */
/* sema: rw16, reset unknown */
#define ISP2200_SEMA_OFFSET                          0xcu /* established */
#define ISP2200_SEMA_STATUS_SHIFT                    1 /* unknown */
#define ISP2200_SEMA_STATUS_MASK                     0x1u
#define ISP2200_SEMA_STATUS_INPLACE                  (ISP2200_SEMA_STATUS_MASK << ISP2200_SEMA_STATUS_SHIFT)
#define ISP2200_SEMA_LOCK_SHIFT                      0 /* established */
#define ISP2200_SEMA_LOCK_MASK                       0x1u
#define ISP2200_SEMA_LOCK_INPLACE                    (ISP2200_SEMA_LOCK_MASK << ISP2200_SEMA_LOCK_SHIFT)

/*
 * Serial EEPROM port. The host bit-bangs the clock, chip select and data lines to read the board NVRAM.
 */
/* nvram: rw16, reset unknown */
#define ISP2200_NVRAM_OFFSET                         0xeu /* established */
#define ISP2200_NVRAM_DATA_FROM_EEPROM_SHIFT         3 /* established */
#define ISP2200_NVRAM_DATA_FROM_EEPROM_MASK          0x1u
#define ISP2200_NVRAM_DATA_FROM_EEPROM_INPLACE       (ISP2200_NVRAM_DATA_FROM_EEPROM_MASK << ISP2200_NVRAM_DATA_FROM_EEPROM_SHIFT)
#define ISP2200_NVRAM_DATA_TO_EEPROM_SHIFT           2 /* established */
#define ISP2200_NVRAM_DATA_TO_EEPROM_MASK            0x1u
#define ISP2200_NVRAM_DATA_TO_EEPROM_INPLACE         (ISP2200_NVRAM_DATA_TO_EEPROM_MASK << ISP2200_NVRAM_DATA_TO_EEPROM_SHIFT)
#define ISP2200_NVRAM_SELECT_SHIFT                   1 /* established */
#define ISP2200_NVRAM_SELECT_MASK                    0x1u
#define ISP2200_NVRAM_SELECT_INPLACE                 (ISP2200_NVRAM_SELECT_MASK << ISP2200_NVRAM_SELECT_SHIFT)
#define ISP2200_NVRAM_CLOCK_SHIFT                    0 /* established */
#define ISP2200_NVRAM_CLOCK_MASK                     0x1u
#define ISP2200_NVRAM_CLOCK_INPLACE                  (ISP2200_NVRAM_CLOCK_MASK << ISP2200_NVRAM_CLOCK_SHIFT)

/*
 * Mailboxes 0 to 7, two bytes apart. Mailbox 0 carries the command number in and the status out. Mailbox 4 is the request-queue pointer and mailbox 5 the response-queue pointer. The drivers write and read them outside any command, and a write to them does not ring the doorbell.
 */
/* mailbox: rw16, reset unknown */
#define ISP2200_MAILBOX_OFFSET                       0x10u /* established */
#define ISP2200_MAILBOX_COUNT                        8
#define ISP2200_MAILBOX_STRIDE                       2

/*
 * Host command and control register. A write carries a command in bits 15 to 12. A read returns status in the bits named below. Reset values are not stated by any source.
 */
/* hccr: rw16, reset unknown */
#define ISP2200_HCCR_OFFSET                          0xc0u /* established */
#define ISP2200_HCCR_CMD_SHIFT                       12 /* established */
#define ISP2200_HCCR_CMD_MASK                        0xfu
#define ISP2200_HCCR_CMD_INPLACE                     (ISP2200_HCCR_CMD_MASK << ISP2200_HCCR_CMD_SHIFT)
#define ISP2200_HCCR_HOST_INT_SHIFT                  7 /* established */
#define ISP2200_HCCR_HOST_INT_MASK                   0x1u
#define ISP2200_HCCR_HOST_INT_INPLACE                (ISP2200_HCCR_HOST_INT_MASK << ISP2200_HCCR_HOST_INT_SHIFT)
#define ISP2200_HCCR_RISC_RESET_SHIFT                6 /* inferred */
#define ISP2200_HCCR_RISC_RESET_MASK                 0x1u
#define ISP2200_HCCR_RISC_RESET_INPLACE              (ISP2200_HCCR_RISC_RESET_MASK << ISP2200_HCCR_RISC_RESET_SHIFT)
#define ISP2200_HCCR_RISC_PAUSED_SHIFT               5 /* established */
#define ISP2200_HCCR_RISC_PAUSED_MASK                0x1u
#define ISP2200_HCCR_RISC_PAUSED_INPLACE             (ISP2200_HCCR_RISC_PAUSED_MASK << ISP2200_HCCR_RISC_PAUSED_SHIFT)

/*
 * Mailboxes 8 to 23. The count of 24 comes from two drivers, but only Linux gives where the upper sixteen sit. Linux writes all 24 on every mailbox command, zeroing the ones the command does not use.
 */
/* mailbox_hi: rw16, reset unknown */
#define ISP2200_MAILBOX_HI_OFFSET                    0xe0u /* inferred */
#define ISP2200_MAILBOX_HI_COUNT                     16
#define ISP2200_MAILBOX_HI_STRIDE                    2

#define ISP2200_ASYNC_EVENT_FIRST                    0x8000u /* established */
#define ISP2200_ASYNC_EVENT_LAST                     0xbfffu /* inferred */
#define ISP2200_ASYNC_LIP                            0x8010u /* established */
#define ISP2200_ASYNC_LOOP_DOWN                      0x8012u /* established */
#define ISP2200_ASYNC_LOOP_UP                        0x8011u /* established */
#define ISP2200_ASYNC_PORT_DB_CHANGE                 0x8014u /* established */
#define ISP2200_ASYNC_RESET                          0x8001u /* established */
#define ISP2200_ASYNC_RSCN                           0x8015u /* established */
#define ISP2200_CMD_ENTRY_32                         0x11u /* inferred */
#define ISP2200_CMD_ENTRY_64                         0x19u /* established */
#define ISP2200_CONT_ENTRY_32                        0x2u /* inferred */
#define ISP2200_CONT_ENTRY_64                        0xau /* inferred */
#define ISP2200_CPL_ABORTED                          0x5u /* established */
#define ISP2200_CPL_COMPLETE                         0x0u /* established */
#define ISP2200_CPL_DATA_OVERRUN                     0x7u /* established */
#define ISP2200_CPL_DATA_UNDERRUN                    0x15u /* established */
#define ISP2200_CPL_DMA_ERROR                        0x2u /* established */
#define ISP2200_CPL_INCOMPLETE                       0x1u /* established */
#define ISP2200_CPL_PORT_BUSY                        0x2bu /* established */
#define ISP2200_CPL_PORT_CONFIG_CHANGED              0x2au /* established */
#define ISP2200_CPL_PORT_LOGGED_OUT                  0x29u /* established */
#define ISP2200_CPL_PORT_UNAVAILABLE                 0x28u /* established */
#define ISP2200_CPL_QUEUE_FULL                       0x1cu /* established */
#define ISP2200_CPL_RESET                            0x4u /* established */
#define ISP2200_CPL_TIMEOUT                          0x6u /* established */
#define ISP2200_CPL_TRANSPORT_ERROR                  0x3u /* established */
#define ISP2200_ENTRY_BYTES                          0x40u /* established */
#define ISP2200_FIRMWARE_LENGTH_WORD_INDEX           0x3u /* established */
#define ISP2200_ICB_BYTES                            0x60u /* established */
#define ISP2200_ICB_VERSION                          0x1u /* established */
#define ISP2200_MAILBOXES_TOTAL                      0x18u /* established */
#define ISP2200_MARKER_ENTRY                         0x4u /* established */
#define ISP2200_MBOX0_BUSY                           0x4u /* established */
#define ISP2200_MBOX_COMPLETION_LAST                 0x7fffu /* inferred */
#define ISP2200_NVRAM_IMAGE_BYTES                    0x100u /* established */
#define ISP2200_OP_ABOUT_FIRMWARE                    0x8u /* established */
#define ISP2200_OP_DUMP_RAM                          0x3u /* inferred */
#define ISP2200_OP_EXECUTE_FIRMWARE                  0x2u /* established */
#define ISP2200_OP_FIRMWARE_STATUS                   0x1fu /* inferred */
#define ISP2200_OP_GET_FIRMWARE_OPTIONS              0x28u /* inferred */
#define ISP2200_OP_INIT_FIRMWARE                     0x60u /* established */
#define ISP2200_OP_LOAD_RAM_32                       0x1u /* inferred */
#define ISP2200_OP_LOAD_RAM_DMA                      0x9u /* inferred */
#define ISP2200_OP_LOAD_RAM_EXT                      0xbu /* inferred */
#define ISP2200_OP_MAILBOX_TEST                      0x6u /* inferred */
#define ISP2200_OP_NOOP                              0x0u /* established */
#define ISP2200_OP_READ_RAM_WORD                     0x5u /* inferred */
#define ISP2200_OP_SET_FIRMWARE_OPTIONS              0x38u /* inferred */
#define ISP2200_OP_VERIFY_CHECKSUM                   0x7u /* established */
#define ISP2200_OP_WRITE_RAM_WORD                    0x4u /* established */
#define ISP2200_PCI_BAR_IO_CONFIG_OFFSET             0x10u /* established */
#define ISP2200_PCI_BAR_MEM_CONFIG_OFFSET            0x14u /* established */
#define ISP2200_PCI_CONFIG_BUS_MASTER_BIT            0x4u /* established */
#define ISP2200_PCI_DEVICE_ID                        0x2200u /* established */
#define ISP2200_PCI_VENDOR_ID                        0x1077u /* established */
#define ISP2200_PRODUCT_ID_MAILBOX1                  0x4953u /* established */
#define ISP2200_PRODUCT_ID_MAILBOX2                  0x5020u /* established */
#define ISP2200_PRODUCT_ID_MAILBOX3                  0x2020u /* established */
#define ISP2200_REGISTER_WINDOW_BYTES                0x100u /* established */
#define ISP2200_RISC_CODE_ORIGIN_WORD                0x1000u /* established */
#define ISP2200_ROM_VERSION_MAILBOX7                 0x4u /* inferred */
#define ISP2200_SEGMENT_LIST_ENTRY                   0x15u /* inferred */
#define ISP2200_STATUS_COMMAND_ERROR                 0x4005u /* established */
#define ISP2200_STATUS_COMPLETE                      0x4000u /* established */
#define ISP2200_STATUS_CONT_ENTRY                    0x10u /* established */
#define ISP2200_STATUS_ENTRY                         0x3u /* established */
#define ISP2200_STATUS_HOST_INTERFACE_ERROR          0x4002u /* established */
#define ISP2200_STATUS_INVALID_COMMAND               0x4001u /* established */
#define ISP2200_STATUS_PARAMETER_ERROR               0x4006u /* established */
#define ISP2200_STATUS_TEST_FAILED                   0x4003u /* established */

#endif /* ISP2200_GEN_H */
