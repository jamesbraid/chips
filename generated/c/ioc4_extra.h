/* generated from devices/ioc4/registers-extra.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 c76a9ebe973b864f75d3bd181dbaa7e4ea1a9a32767fda897711641d5807f1b2 */
/* IOC4 registers outside the census */
#ifndef IOC4_GEN_H
#define IOC4_GEN_H

#include <stdint.h>


/*
 * Generic pin data word. The SGI header defines it at 0x38 with bits 7:0
 * holding the state of the eight generic pins. Offset and name are established
 * by the header and the PROM store; no Linux driver code read touches it, and
 * what a write does is unknown.
 */
/* gpdr: rw32, reset unknown */
#define IOC4_GPDR                                    0x000038 /* established */

/*
 * ATA command block: the eight ATA task-file registers, one per 32-bit slot,
 * each accessed as a byte; index 7 is status on read and command on write.
 * Whether the data register at index 0 is accessed as 16 or 32 bits is decided
 * by the IDE core, not read here.
 */
/* ata_cmd: rw32, reset unknown */
#define IOC4_ATA_CMD                                 0x000100 /* established */
#define IOC4_ATA_CMD_COUNT                           8
#define IOC4_ATA_CMD_STRIDE                          4

/*
 * ATA control block: alternate status on read, device control on write.
 */
/* ata_ctl: rw32, reset unknown */
#define IOC4_ATA_CTL                                 0x000120 /* established */

/* km_rx_kbd: r32, reset unknown */
#define IOC4_KM_RX_KBD                               0x000204 /* established */

/* km_rx_mouse: r32, reset unknown */
#define IOC4_KM_RX_MOUSE                             0x000208 /* established */

/* km_tx_kbd: w32, reset unknown */
#define IOC4_KM_TX_KBD                               0x00020c /* established */

/* km_tx_mouse: w32, reset unknown */
#define IOC4_KM_TX_MOUSE                             0x000210 /* established */

/*
 * ATA DMA control and status (DMA block word 7). Software writes the direction
 * alone to program a transfer, then sets start by read-modify-write. It ends a
 * transfer by writing stop and polling until stop reads back clear. Before
 * arming, it writes stop if active or error is set.
 */
/* word ATA_DMA_CONTROL_WORD: 32 bits */
#define IOC4_ATA_DMA_CONTROL_WORD_WIDTH              32 /* established */
#define IOC4_ATA_DMA_CONTROL_WORD_ERROR_SHIFT        4 /* established */
#define IOC4_ATA_DMA_CONTROL_WORD_ERROR_MASK         0x1u
#define IOC4_ATA_DMA_CONTROL_WORD_ERROR_INPLACE (IOC4_ATA_DMA_CONTROL_WORD_ERROR_MASK << IOC4_ATA_DMA_CONTROL_WORD_ERROR_SHIFT)
#define IOC4_ATA_DMA_CONTROL_WORD_ACTIVE_SHIFT       3 /* established */
#define IOC4_ATA_DMA_CONTROL_WORD_ACTIVE_MASK        0x1u
#define IOC4_ATA_DMA_CONTROL_WORD_ACTIVE_INPLACE (IOC4_ATA_DMA_CONTROL_WORD_ACTIVE_MASK << IOC4_ATA_DMA_CONTROL_WORD_ACTIVE_SHIFT)
#define IOC4_ATA_DMA_CONTROL_WORD_DIR_SHIFT          2 /* established */
#define IOC4_ATA_DMA_CONTROL_WORD_DIR_MASK           0x1u
#define IOC4_ATA_DMA_CONTROL_WORD_DIR_INPLACE (IOC4_ATA_DMA_CONTROL_WORD_DIR_MASK << IOC4_ATA_DMA_CONTROL_WORD_DIR_SHIFT)
#define IOC4_ATA_DMA_CONTROL_WORD_STOP_SHIFT         1 /* established */
#define IOC4_ATA_DMA_CONTROL_WORD_STOP_MASK          0x1u
#define IOC4_ATA_DMA_CONTROL_WORD_STOP_INPLACE (IOC4_ATA_DMA_CONTROL_WORD_STOP_MASK << IOC4_ATA_DMA_CONTROL_WORD_STOP_SHIFT)
#define IOC4_ATA_DMA_CONTROL_WORD_START_SHIFT        0 /* established */
#define IOC4_ATA_DMA_CONTROL_WORD_START_MASK         0x1u
#define IOC4_ATA_DMA_CONTROL_WORD_START_INPLACE (IOC4_ATA_DMA_CONTROL_WORD_START_MASK << IOC4_ATA_DMA_CONTROL_WORD_START_SHIFT)

/*
 * Last word of a 16-byte ATA scatter list entry. Each entry is four big-endian
 * 32-bit words: zero, the low 32 bits of the bus address, zero, this word. The
 * driver splits entries at 64 KB boundaries so an aligned entry can hold
 * 0x10000 bytes, which does not fit in 16 bits; how the chip reads a length of
 * 0x10000 is unknown.
 */
/* word ATA_PRD_LENGTH_WORD: 32 bits */
#define IOC4_ATA_PRD_LENGTH_WORD_WIDTH               32 /* established */
#define IOC4_ATA_PRD_LENGTH_WORD_EOL_SHIFT           31 /* established */
#define IOC4_ATA_PRD_LENGTH_WORD_EOL_MASK            0x1u
#define IOC4_ATA_PRD_LENGTH_WORD_EOL_INPLACE (IOC4_ATA_PRD_LENGTH_WORD_EOL_MASK << IOC4_ATA_PRD_LENGTH_WORD_EOL_SHIFT)
#define IOC4_ATA_PRD_LENGTH_WORD_LENGTH_SHIFT        0 /* established */
#define IOC4_ATA_PRD_LENGTH_WORD_LENGTH_MASK         0xffffu
#define IOC4_ATA_PRD_LENGTH_WORD_LENGTH_INPLACE (IOC4_ATA_PRD_LENGTH_WORD_LENGTH_MASK << IOC4_ATA_PRD_LENGTH_WORD_LENGTH_SHIFT)

/*
 * Generic pin control, written through the set alias (writing a 1 sets that
 * bit) and the clear alias (writing a 1 clears it). Pin 0 drives the external
 * interrupt output, pin 1 is the external interrupt input, pin 3 senses
 * keyboard and mouse presence and pins 4 to 7 select RS-232 (0) or RS-422 (1)
 * for ports 0 to 3. The set and clear behaviour follows the register names and
 * the SGI driver's use of the set alias; the SGI Linux driver never uses the
 * clear alias.
 */
/* word GPCR_WORD: 32 bits */
#define IOC4_GPCR_WORD_WIDTH                         32 /* established */
#define IOC4_GPCR_WORD_INT_OUT_EN_SHIFT              20 /* established */
#define IOC4_GPCR_WORD_INT_OUT_EN_MASK               0x1u
#define IOC4_GPCR_WORD_INT_OUT_EN_INPLACE (IOC4_GPCR_WORD_INT_OUT_EN_MASK << IOC4_GPCR_WORD_INT_OUT_EN_SHIFT)
#define IOC4_GPCR_WORD_EDGE_SHIFT                    8 /* established */
#define IOC4_GPCR_WORD_EDGE_MASK                     0xffu
#define IOC4_GPCR_WORD_EDGE_INPLACE (IOC4_GPCR_WORD_EDGE_MASK << IOC4_GPCR_WORD_EDGE_SHIFT)
#define IOC4_GPCR_WORD_DIR_SHIFT                     0 /* established */
#define IOC4_GPCR_WORD_DIR_MASK                      0xffu
#define IOC4_GPCR_WORD_DIR_INPLACE (IOC4_GPCR_WORD_DIR_MASK << IOC4_GPCR_WORD_DIR_SHIFT)

/*
 * Generic pin data: the state of the eight pins.
 */
/* word GPDR_WORD: 32 bits */
#define IOC4_GPDR_WORD_WIDTH                         32 /* established */
#define IOC4_GPDR_WORD_GEN_PIN_SHIFT                 0 /* established */
#define IOC4_GPDR_WORD_GEN_PIN_MASK                  0xffu
#define IOC4_GPDR_WORD_GEN_PIN_INPLACE (IOC4_GPDR_WORD_GEN_PIN_MASK << IOC4_GPDR_WORD_GEN_PIN_SHIFT)

/*
 * One word per generic pin, eight words. Software writes 0 or 1 to drive the
 * pin; the serial driver uses pins 4 to 7 as the transceiver mode select.
 */
/* word GPPR_WORD: 32 bits */
#define IOC4_GPPR_WORD_WIDTH                         32 /* established */
#define IOC4_GPPR_WORD_GEN_PIN_SHIFT                 0 /* established */
#define IOC4_GPPR_WORD_GEN_PIN_MASK                  0x1u
#define IOC4_GPPR_WORD_GEN_PIN_INPLACE (IOC4_GPPR_WORD_GEN_PIN_MASK << IOC4_GPPR_WORD_GEN_PIN_SHIFT)

/*
 * External interrupt output control. In toggle mode (7) the output pin inverts
 * every count+1 ticks; one tick is 520 PCI clocks, so the square wave period is
 * 2*(count+1)*520 PCI clocks. Bit 31 reads the current output level and is the
 * way the SGI Linux driver measures the PCI clock. Writing zero first returns
 * the section to its power-on state, per the driver comment.
 */
/* word INT_OUT_WORD: 32 bits */
#define IOC4_INT_OUT_WORD_WIDTH                      32 /* established */
#define IOC4_INT_OUT_WORD_INT_OUT_SHIFT              31 /* established */
#define IOC4_INT_OUT_WORD_INT_OUT_MASK               0x1u
#define IOC4_INT_OUT_WORD_INT_OUT_INPLACE (IOC4_INT_OUT_WORD_INT_OUT_MASK << IOC4_INT_OUT_WORD_INT_OUT_SHIFT)
#define IOC4_INT_OUT_WORD_DIAG_SHIFT                 30 /* established */
#define IOC4_INT_OUT_WORD_DIAG_MASK                  0x1u
#define IOC4_INT_OUT_WORD_DIAG_INPLACE (IOC4_INT_OUT_WORD_DIAG_MASK << IOC4_INT_OUT_WORD_DIAG_SHIFT)
#define IOC4_INT_OUT_WORD_MODE_SHIFT                 16 /* established */
#define IOC4_INT_OUT_WORD_MODE_MASK                  0x7u
#define IOC4_INT_OUT_WORD_MODE_INPLACE (IOC4_INT_OUT_WORD_MODE_MASK << IOC4_INT_OUT_WORD_MODE_SHIFT)
#define IOC4_INT_OUT_WORD_COUNT_SHIFT                0 /* established */
#define IOC4_INT_OUT_WORD_COUNT_MASK                 0xffffu
#define IOC4_INT_OUT_WORD_COUNT_INPLACE (IOC4_INT_OUT_WORD_COUNT_MASK << IOC4_INT_OUT_WORD_COUNT_SHIFT)

/*
 * The other interrupt status, enable-set and enable-clear words. Bit 0 follows
 * the drive interrupt and bit 1 is the ATA DMA PCI error; bits 5:2 are the
 * per-port serial DMA PCI errors; the generic pin field raises one bit per
 * generic pin.
 */
/* word OTHER_IR_WORD: 32 bits */
#define IOC4_OTHER_IR_WORD_WIDTH                     32 /* established */
#define IOC4_OTHER_IR_WORD_GEN_INT_SHIFT             24 /* established */
#define IOC4_OTHER_IR_WORD_GEN_INT_MASK              0xffu
#define IOC4_OTHER_IR_WORD_GEN_INT_INPLACE (IOC4_OTHER_IR_WORD_GEN_INT_MASK << IOC4_OTHER_IR_WORD_GEN_INT_SHIFT)
#define IOC4_OTHER_IR_WORD_RT_INT_SHIFT              23 /* established */
#define IOC4_OTHER_IR_WORD_RT_INT_MASK               0x1u
#define IOC4_OTHER_IR_WORD_RT_INT_INPLACE (IOC4_OTHER_IR_WORD_RT_INT_MASK << IOC4_OTHER_IR_WORD_RT_INT_SHIFT)
#define IOC4_OTHER_IR_WORD_KBD_INT_SHIFT             6 /* established */
#define IOC4_OTHER_IR_WORD_KBD_INT_MASK              0x1u
#define IOC4_OTHER_IR_WORD_KBD_INT_INPLACE (IOC4_OTHER_IR_WORD_KBD_INT_MASK << IOC4_OTHER_IR_WORD_KBD_INT_SHIFT)
#define IOC4_OTHER_IR_WORD_SER_MEMERR_SHIFT          2 /* established */
#define IOC4_OTHER_IR_WORD_SER_MEMERR_MASK           0xfu
#define IOC4_OTHER_IR_WORD_SER_MEMERR_INPLACE (IOC4_OTHER_IR_WORD_SER_MEMERR_MASK << IOC4_OTHER_IR_WORD_SER_MEMERR_SHIFT)
#define IOC4_OTHER_IR_WORD_ATA_MEMERR_SHIFT          1 /* established */
#define IOC4_OTHER_IR_WORD_ATA_MEMERR_MASK           0x1u
#define IOC4_OTHER_IR_WORD_ATA_MEMERR_INPLACE (IOC4_OTHER_IR_WORD_ATA_MEMERR_MASK << IOC4_OTHER_IR_WORD_ATA_MEMERR_SHIFT)
#define IOC4_OTHER_IR_WORD_ATA_INT_SHIFT             0 /* established */
#define IOC4_OTHER_IR_WORD_ATA_INT_MASK              0x1u
#define IOC4_OTHER_IR_WORD_ATA_INT_INPLACE (IOC4_OTHER_IR_WORD_ATA_INT_MASK << IOC4_OTHER_IR_WORD_ATA_INT_SHIFT)

/*
 * Low word of the latched PCI error address. The word is read together with the
 * high word after a DMA error interrupt. Master id 0 to 7 names a serial port
 * (port number is the id shifted right one, bit 0 of the id is 1 for the
 * receive ring and 0 for the transmit ring); 8 is the ATA engine; 9 to 15 are
 * undefined. The address field holds bits 31:6 of the address.
 */
/* word PCI_ERR_ADDR_L_WORD: 32 bits */
#define IOC4_PCI_ERR_ADDR_L_WORD_WIDTH               32 /* established */
#define IOC4_PCI_ERR_ADDR_L_WORD_ADDR_SHIFT          6 /* established */
#define IOC4_PCI_ERR_ADDR_L_WORD_ADDR_MASK           0x3ffffffu
#define IOC4_PCI_ERR_ADDR_L_WORD_ADDR_INPLACE (IOC4_PCI_ERR_ADDR_L_WORD_ADDR_MASK << IOC4_PCI_ERR_ADDR_L_WORD_ADDR_SHIFT)
#define IOC4_PCI_ERR_ADDR_L_WORD_MUL_ERR_SHIFT       5 /* established */
#define IOC4_PCI_ERR_ADDR_L_WORD_MUL_ERR_MASK        0x1u
#define IOC4_PCI_ERR_ADDR_L_WORD_MUL_ERR_INPLACE (IOC4_PCI_ERR_ADDR_L_WORD_MUL_ERR_MASK << IOC4_PCI_ERR_ADDR_L_WORD_MUL_ERR_SHIFT)
#define IOC4_PCI_ERR_ADDR_L_WORD_MASTER_ID_SHIFT     1 /* established */
#define IOC4_PCI_ERR_ADDR_L_WORD_MASTER_ID_MASK      0xfu
#define IOC4_PCI_ERR_ADDR_L_WORD_MASTER_ID_INPLACE (IOC4_PCI_ERR_ADDR_L_WORD_MASTER_ID_MASK << IOC4_PCI_ERR_ADDR_L_WORD_MASTER_ID_SHIFT)
#define IOC4_PCI_ERR_ADDR_L_WORD_VALID_SHIFT         0 /* established */
#define IOC4_PCI_ERR_ADDR_L_WORD_VALID_MASK          0x1u
#define IOC4_PCI_ERR_ADDR_L_WORD_VALID_INPLACE (IOC4_PCI_ERR_ADDR_L_WORD_VALID_MASK << IOC4_PCI_ERR_ADDR_L_WORD_VALID_SHIFT)

/*
 * Status byte of a receive ring entry; one per data byte. The chip writes the
 * whole entry. Software clears the two valid bits after consuming a byte, and
 * treats an entry with neither valid bit set in any of its four status bytes as
 * not yet written, since the producer pointer can run ahead of the data.
 */
/* word RX_STATUS_BYTE_WORD: 8 bits */
#define IOC4_RX_STATUS_BYTE_WORD_WIDTH               8 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_DATA_VALID_SHIFT    7 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_DATA_VALID_MASK     0x1u
#define IOC4_RX_STATUS_BYTE_WORD_DATA_VALID_INPLACE (IOC4_RX_STATUS_BYTE_WORD_DATA_VALID_MASK << IOC4_RX_STATUS_BYTE_WORD_DATA_VALID_SHIFT)
#define IOC4_RX_STATUS_BYTE_WORD_MODEM_VALID_SHIFT   6 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_MODEM_VALID_MASK    0x1u
#define IOC4_RX_STATUS_BYTE_WORD_MODEM_VALID_INPLACE (IOC4_RX_STATUS_BYTE_WORD_MODEM_VALID_MASK << IOC4_RX_STATUS_BYTE_WORD_MODEM_VALID_SHIFT)
#define IOC4_RX_STATUS_BYTE_WORD_DCD_SHIFT           5 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_DCD_MASK            0x1u
#define IOC4_RX_STATUS_BYTE_WORD_DCD_INPLACE (IOC4_RX_STATUS_BYTE_WORD_DCD_MASK << IOC4_RX_STATUS_BYTE_WORD_DCD_SHIFT)
#define IOC4_RX_STATUS_BYTE_WORD_CTS_SHIFT           4 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_CTS_MASK            0x1u
#define IOC4_RX_STATUS_BYTE_WORD_CTS_INPLACE (IOC4_RX_STATUS_BYTE_WORD_CTS_MASK << IOC4_RX_STATUS_BYTE_WORD_CTS_SHIFT)
#define IOC4_RX_STATUS_BYTE_WORD_BRK_SHIFT           3 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_BRK_MASK            0x1u
#define IOC4_RX_STATUS_BYTE_WORD_BRK_INPLACE (IOC4_RX_STATUS_BYTE_WORD_BRK_MASK << IOC4_RX_STATUS_BYTE_WORD_BRK_SHIFT)
#define IOC4_RX_STATUS_BYTE_WORD_FRAME_ERR_SHIFT     2 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_FRAME_ERR_MASK      0x1u
#define IOC4_RX_STATUS_BYTE_WORD_FRAME_ERR_INPLACE (IOC4_RX_STATUS_BYTE_WORD_FRAME_ERR_MASK << IOC4_RX_STATUS_BYTE_WORD_FRAME_ERR_SHIFT)
#define IOC4_RX_STATUS_BYTE_WORD_PAR_ERR_SHIFT       1 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_PAR_ERR_MASK        0x1u
#define IOC4_RX_STATUS_BYTE_WORD_PAR_ERR_INPLACE (IOC4_RX_STATUS_BYTE_WORD_PAR_ERR_MASK << IOC4_RX_STATUS_BYTE_WORD_PAR_ERR_SHIFT)
#define IOC4_RX_STATUS_BYTE_WORD_OVERRUN_SHIFT       0 /* established */
#define IOC4_RX_STATUS_BYTE_WORD_OVERRUN_MASK        0x1u
#define IOC4_RX_STATUS_BYTE_WORD_OVERRUN_INPLACE (IOC4_RX_STATUS_BYTE_WORD_OVERRUN_MASK << IOC4_RX_STATUS_BYTE_WORD_OVERRUN_SHIFT)

/*
 * Low word of a serial ring base for one port pair. The ring group base must be
 * aligned to its total size (four rings); software ORs the ring size into bit
 * 0. How the chip combines base and pointer is not stated.
 */
/* word SBBR_L_WORD: 32 bits */
#define IOC4_SBBR_L_WORD_WIDTH                       32 /* established */
#define IOC4_SBBR_L_WORD_SIZE_SHIFT                  0 /* established */
#define IOC4_SBBR_L_WORD_SIZE_MASK                   0x1u
#define IOC4_SBBR_L_WORD_SIZE_INPLACE (IOC4_SBBR_L_WORD_SIZE_MASK << IOC4_SBBR_L_WORD_SIZE_SHIFT)

/*
 * Producer and consumer pointers are byte offsets into the ring in 8-byte
 * steps: bits 11:3 for 4 KB rings, 9:3 for 1 KB rings. The ring is empty when
 * producer equals consumer and full when the consumer is one entry ahead of the
 * producer.
 */
/* word SERIAL_PTR_WORD: 32 bits */
#define IOC4_SERIAL_PTR_WORD_WIDTH                   32 /* established */
#define IOC4_SERIAL_PTR_WORD_PTR_SHIFT               3 /* established */
#define IOC4_SERIAL_PTR_WORD_PTR_MASK                0x1ffu
#define IOC4_SERIAL_PTR_WORD_PTR_INPLACE (IOC4_SERIAL_PTR_WORD_PTR_MASK << IOC4_SERIAL_PTR_WORD_PTR_SHIFT)

/*
 * Per-port shadow of UART state. Bits 7:0 mirror the line status bits, 23:16
 * the modem status bits and 31:24 the modem control register. The driver writes
 * the modem control byte to the UART and the word back here.
 */
/* word SHADOW_WORD: 32 bits */
#define IOC4_SHADOW_WORD_WIDTH                       32 /* established */
#define IOC4_SHADOW_WORD_LOOP_SHIFT                  28 /* established */
#define IOC4_SHADOW_WORD_LOOP_MASK                   0x1u
#define IOC4_SHADOW_WORD_LOOP_INPLACE (IOC4_SHADOW_WORD_LOOP_MASK << IOC4_SHADOW_WORD_LOOP_SHIFT)
#define IOC4_SHADOW_WORD_OUT2_SHIFT                  27 /* established */
#define IOC4_SHADOW_WORD_OUT2_MASK                   0x1u
#define IOC4_SHADOW_WORD_OUT2_INPLACE (IOC4_SHADOW_WORD_OUT2_MASK << IOC4_SHADOW_WORD_OUT2_SHIFT)
#define IOC4_SHADOW_WORD_OUT1_SHIFT                  26 /* established */
#define IOC4_SHADOW_WORD_OUT1_MASK                   0x1u
#define IOC4_SHADOW_WORD_OUT1_INPLACE (IOC4_SHADOW_WORD_OUT1_MASK << IOC4_SHADOW_WORD_OUT1_SHIFT)
#define IOC4_SHADOW_WORD_RTS_SHIFT                   25 /* established */
#define IOC4_SHADOW_WORD_RTS_MASK                    0x1u
#define IOC4_SHADOW_WORD_RTS_INPLACE (IOC4_SHADOW_WORD_RTS_MASK << IOC4_SHADOW_WORD_RTS_SHIFT)
#define IOC4_SHADOW_WORD_DTR_SHIFT                   24 /* established */
#define IOC4_SHADOW_WORD_DTR_MASK                    0x1u
#define IOC4_SHADOW_WORD_DTR_INPLACE (IOC4_SHADOW_WORD_DTR_MASK << IOC4_SHADOW_WORD_DTR_SHIFT)
#define IOC4_SHADOW_WORD_DCD_SHIFT                   23 /* established */
#define IOC4_SHADOW_WORD_DCD_MASK                    0x1u
#define IOC4_SHADOW_WORD_DCD_INPLACE (IOC4_SHADOW_WORD_DCD_MASK << IOC4_SHADOW_WORD_DCD_SHIFT)
#define IOC4_SHADOW_WORD_CTS_SHIFT                   20 /* established */
#define IOC4_SHADOW_WORD_CTS_MASK                    0x1u
#define IOC4_SHADOW_WORD_CTS_INPLACE (IOC4_SHADOW_WORD_CTS_MASK << IOC4_SHADOW_WORD_CTS_SHIFT)
#define IOC4_SHADOW_WORD_DDCD_SHIFT                  19 /* established */
#define IOC4_SHADOW_WORD_DDCD_MASK                   0x1u
#define IOC4_SHADOW_WORD_DDCD_INPLACE (IOC4_SHADOW_WORD_DDCD_MASK << IOC4_SHADOW_WORD_DDCD_SHIFT)
#define IOC4_SHADOW_WORD_DCTS_SHIFT                  16 /* established */
#define IOC4_SHADOW_WORD_DCTS_MASK                   0x1u
#define IOC4_SHADOW_WORD_DCTS_INPLACE (IOC4_SHADOW_WORD_DCTS_MASK << IOC4_SHADOW_WORD_DCTS_SHIFT)
#define IOC4_SHADOW_WORD_RFCE_SHIFT                  7 /* established */
#define IOC4_SHADOW_WORD_RFCE_MASK                   0x1u
#define IOC4_SHADOW_WORD_RFCE_INPLACE (IOC4_SHADOW_WORD_RFCE_MASK << IOC4_SHADOW_WORD_RFCE_SHIFT)
#define IOC4_SHADOW_WORD_TEMT_SHIFT                  6 /* established */
#define IOC4_SHADOW_WORD_TEMT_MASK                   0x1u
#define IOC4_SHADOW_WORD_TEMT_INPLACE (IOC4_SHADOW_WORD_TEMT_MASK << IOC4_SHADOW_WORD_TEMT_SHIFT)
#define IOC4_SHADOW_WORD_THRE_SHIFT                  5 /* established */
#define IOC4_SHADOW_WORD_THRE_MASK                   0x1u
#define IOC4_SHADOW_WORD_THRE_INPLACE (IOC4_SHADOW_WORD_THRE_MASK << IOC4_SHADOW_WORD_THRE_SHIFT)
#define IOC4_SHADOW_WORD_BI_SHIFT                    4 /* established */
#define IOC4_SHADOW_WORD_BI_MASK                     0x1u
#define IOC4_SHADOW_WORD_BI_INPLACE (IOC4_SHADOW_WORD_BI_MASK << IOC4_SHADOW_WORD_BI_SHIFT)
#define IOC4_SHADOW_WORD_FE_SHIFT                    3 /* established */
#define IOC4_SHADOW_WORD_FE_MASK                     0x1u
#define IOC4_SHADOW_WORD_FE_INPLACE (IOC4_SHADOW_WORD_FE_MASK << IOC4_SHADOW_WORD_FE_SHIFT)
#define IOC4_SHADOW_WORD_PE_SHIFT                    2 /* established */
#define IOC4_SHADOW_WORD_PE_MASK                     0x1u
#define IOC4_SHADOW_WORD_PE_INPLACE (IOC4_SHADOW_WORD_PE_MASK << IOC4_SHADOW_WORD_PE_SHIFT)
#define IOC4_SHADOW_WORD_OE_SHIFT                    1 /* established */
#define IOC4_SHADOW_WORD_OE_MASK                     0x1u
#define IOC4_SHADOW_WORD_OE_INPLACE (IOC4_SHADOW_WORD_OE_MASK << IOC4_SHADOW_WORD_OE_SHIFT)
#define IOC4_SHADOW_WORD_DR_SHIFT                    0 /* established */
#define IOC4_SHADOW_WORD_DR_MASK                     0x1u
#define IOC4_SHADOW_WORD_DR_INPLACE (IOC4_SHADOW_WORD_DR_MASK << IOC4_SHADOW_WORD_DR_SHIFT)

/*
 * Serial and arbitration control. Bits 3:0 are the only software-written field.
 * Bits 9:4 are diagnostic status. The requester field encodes 0 transmit port
 * 0, 1 receive port 0, 2 transmit port 1 and so on up to 7 receive port 3.
 */
/* word SIO_CR_WORD: 32 bits */
#define IOC4_SIO_CR_WORD_WIDTH                       32 /* established */
#define IOC4_SIO_CR_WORD_ATA_DIAG_ACTIVE_SHIFT       9 /* inferred */
#define IOC4_SIO_CR_WORD_ATA_DIAG_ACTIVE_MASK        0x1u
#define IOC4_SIO_CR_WORD_ATA_DIAG_ACTIVE_INPLACE (IOC4_SIO_CR_WORD_ATA_DIAG_ACTIVE_MASK << IOC4_SIO_CR_WORD_ATA_DIAG_ACTIVE_SHIFT)
#define IOC4_SIO_CR_WORD_ATA_DIAG_IDLE_SHIFT         8 /* inferred */
#define IOC4_SIO_CR_WORD_ATA_DIAG_IDLE_MASK          0x1u
#define IOC4_SIO_CR_WORD_ATA_DIAG_IDLE_INPLACE (IOC4_SIO_CR_WORD_ATA_DIAG_IDLE_MASK << IOC4_SIO_CR_WORD_ATA_DIAG_IDLE_SHIFT)
#define IOC4_SIO_CR_WORD_SIO_DIAG_IDLE_SHIFT         7 /* established */
#define IOC4_SIO_CR_WORD_SIO_DIAG_IDLE_MASK          0x1u
#define IOC4_SIO_CR_WORD_SIO_DIAG_IDLE_INPLACE (IOC4_SIO_CR_WORD_SIO_DIAG_IDLE_MASK << IOC4_SIO_CR_WORD_SIO_DIAG_IDLE_SHIFT)
#define IOC4_SIO_CR_WORD_ARB_DIAG_SHIFT              4 /* established */
#define IOC4_SIO_CR_WORD_ARB_DIAG_MASK               0x7u
#define IOC4_SIO_CR_WORD_ARB_DIAG_INPLACE (IOC4_SIO_CR_WORD_ARB_DIAG_MASK << IOC4_SIO_CR_WORD_ARB_DIAG_SHIFT)
#define IOC4_SIO_CR_WORD_CMD_PULSE_SHIFT             0 /* established */
#define IOC4_SIO_CR_WORD_CMD_PULSE_MASK              0xfu
#define IOC4_SIO_CR_WORD_CMD_PULSE_INPLACE (IOC4_SIO_CR_WORD_CMD_PULSE_MASK << IOC4_SIO_CR_WORD_CMD_PULSE_SHIFT)

/*
 * One serial port's byte of the serial interrupt status, enable-set and
 * enable-clear words. Port n occupies bits 8n+7 down to 8n. Software
 * acknowledges tx explicit, rx timer, delta DCD and delta CTS by writing the
 * bit to the status word; rx high is a level condition the driver cannot
 * acknowledge; it masks the enable until the ring drains. Transmit empty is
 * masked the same way (inferred).
 */
/* word SIO_IR_PORT_WORD: 8 bits */
#define IOC4_SIO_IR_PORT_WORD_WIDTH                  8 /* established */
#define IOC4_SIO_IR_PORT_WORD_TX_EXPLICIT_SHIFT      7 /* established */
#define IOC4_SIO_IR_PORT_WORD_TX_EXPLICIT_MASK       0x1u
#define IOC4_SIO_IR_PORT_WORD_TX_EXPLICIT_INPLACE (IOC4_SIO_IR_PORT_WORD_TX_EXPLICIT_MASK << IOC4_SIO_IR_PORT_WORD_TX_EXPLICIT_SHIFT)
#define IOC4_SIO_IR_PORT_WORD_INTR_PASS_SHIFT        6 /* established */
#define IOC4_SIO_IR_PORT_WORD_INTR_PASS_MASK         0x1u
#define IOC4_SIO_IR_PORT_WORD_INTR_PASS_INPLACE (IOC4_SIO_IR_PORT_WORD_INTR_PASS_MASK << IOC4_SIO_IR_PORT_WORD_INTR_PASS_SHIFT)
#define IOC4_SIO_IR_PORT_WORD_DELTA_CTS_SHIFT        5 /* established */
#define IOC4_SIO_IR_PORT_WORD_DELTA_CTS_MASK         0x1u
#define IOC4_SIO_IR_PORT_WORD_DELTA_CTS_INPLACE (IOC4_SIO_IR_PORT_WORD_DELTA_CTS_MASK << IOC4_SIO_IR_PORT_WORD_DELTA_CTS_SHIFT)
#define IOC4_SIO_IR_PORT_WORD_DELTA_DCD_SHIFT        4 /* established */
#define IOC4_SIO_IR_PORT_WORD_DELTA_DCD_MASK         0x1u
#define IOC4_SIO_IR_PORT_WORD_DELTA_DCD_INPLACE (IOC4_SIO_IR_PORT_WORD_DELTA_DCD_MASK << IOC4_SIO_IR_PORT_WORD_DELTA_DCD_SHIFT)
#define IOC4_SIO_IR_PORT_WORD_RX_TIMER_SHIFT         3 /* established */
#define IOC4_SIO_IR_PORT_WORD_RX_TIMER_MASK          0x1u
#define IOC4_SIO_IR_PORT_WORD_RX_TIMER_INPLACE (IOC4_SIO_IR_PORT_WORD_RX_TIMER_MASK << IOC4_SIO_IR_PORT_WORD_RX_TIMER_SHIFT)
#define IOC4_SIO_IR_PORT_WORD_RX_HIGH_SHIFT          2 /* established */
#define IOC4_SIO_IR_PORT_WORD_RX_HIGH_MASK           0x1u
#define IOC4_SIO_IR_PORT_WORD_RX_HIGH_INPLACE (IOC4_SIO_IR_PORT_WORD_RX_HIGH_MASK << IOC4_SIO_IR_PORT_WORD_RX_HIGH_SHIFT)
#define IOC4_SIO_IR_PORT_WORD_RX_FULL_SHIFT          1 /* established */
#define IOC4_SIO_IR_PORT_WORD_RX_FULL_MASK           0x1u
#define IOC4_SIO_IR_PORT_WORD_RX_FULL_INPLACE (IOC4_SIO_IR_PORT_WORD_RX_FULL_MASK << IOC4_SIO_IR_PORT_WORD_RX_FULL_SHIFT)
#define IOC4_SIO_IR_PORT_WORD_TX_MT_SHIFT            0 /* established */
#define IOC4_SIO_IR_PORT_WORD_TX_MT_MASK             0x1u
#define IOC4_SIO_IR_PORT_WORD_TX_MT_INPLACE (IOC4_SIO_IR_PORT_WORD_TX_MT_MASK << IOC4_SIO_IR_PORT_WORD_TX_MT_SHIFT)

/*
 * Receive consumer pointer. Writing it with bit 31 set arms the receive timer;
 * the timer starts on the first byte received after arming.
 */
/* word SRCIR_WORD: 32 bits */
#define IOC4_SRCIR_WORD_WIDTH                        32 /* established */
#define IOC4_SRCIR_WORD_ARM_SHIFT                    31 /* established */
#define IOC4_SRCIR_WORD_ARM_MASK                     0x1u
#define IOC4_SRCIR_WORD_ARM_INPLACE (IOC4_SRCIR_WORD_ARM_MASK << IOC4_SRCIR_WORD_ARM_SHIFT)
#define IOC4_SRCIR_WORD_PTR_SHIFT                    3 /* established */
#define IOC4_SRCIR_WORD_PTR_MASK                     0x1ffu
#define IOC4_SRCIR_WORD_PTR_INPLACE (IOC4_SRCIR_WORD_PTR_MASK << IOC4_SRCIR_WORD_PTR_SHIFT)

/*
 * Receive timer. The count unit is 1/16000 second, so 160 gives 10 ms.
 */
/* word SRTR_WORD: 32 bits */
#define IOC4_SRTR_WORD_WIDTH                         32 /* established */
#define IOC4_SRTR_WORD_CURRENT_SHIFT                 16 /* established */
#define IOC4_SRTR_WORD_CURRENT_MASK                  0xfffu
#define IOC4_SRTR_WORD_CURRENT_INPLACE (IOC4_SRTR_WORD_CURRENT_MASK << IOC4_SRTR_WORD_CURRENT_SHIFT)
#define IOC4_SRTR_WORD_RELOAD_SHIFT                  0 /* established */
#define IOC4_SRTR_WORD_RELOAD_MASK                   0xfffu
#define IOC4_SRTR_WORD_RELOAD_INPLACE (IOC4_SRTR_WORD_RELOAD_MASK << IOC4_SRTR_WORD_RELOAD_SHIFT)

/*
 * Serial port control. The receive threshold counts ring entries (four bytes
 * each). The driver pauses DMA before touching the UART line control, modem
 * control or FIFO, by writing pause and polling pause state.
 */
/* word SSCR_WORD: 32 bits */
#define IOC4_SSCR_WORD_WIDTH                         32 /* established */
#define IOC4_SSCR_WORD_RESET_SHIFT                   31 /* established */
#define IOC4_SSCR_WORD_RESET_MASK                    0x1u
#define IOC4_SSCR_WORD_RESET_INPLACE (IOC4_SSCR_WORD_RESET_MASK << IOC4_SSCR_WORD_RESET_SHIFT)
#define IOC4_SSCR_WORD_PAUSE_STATE_SHIFT             30 /* established */
#define IOC4_SSCR_WORD_PAUSE_STATE_MASK              0x1u
#define IOC4_SSCR_WORD_PAUSE_STATE_INPLACE (IOC4_SSCR_WORD_PAUSE_STATE_MASK << IOC4_SSCR_WORD_PAUSE_STATE_SHIFT)
#define IOC4_SSCR_WORD_DMA_PAUSE_SHIFT               29 /* established */
#define IOC4_SSCR_WORD_DMA_PAUSE_MASK                0x1u
#define IOC4_SSCR_WORD_DMA_PAUSE_INPLACE (IOC4_SSCR_WORD_DMA_PAUSE_MASK << IOC4_SSCR_WORD_DMA_PAUSE_SHIFT)
#define IOC4_SSCR_WORD_DMA_EN_SHIFT                  28 /* established */
#define IOC4_SSCR_WORD_DMA_EN_MASK                   0x1u
#define IOC4_SSCR_WORD_DMA_EN_INPLACE (IOC4_SSCR_WORD_DMA_EN_MASK << IOC4_SSCR_WORD_DMA_EN_SHIFT)
#define IOC4_SSCR_WORD_RX_DRAIN_SHIFT                27 /* established */
#define IOC4_SSCR_WORD_RX_DRAIN_MASK                 0x1u
#define IOC4_SSCR_WORD_RX_DRAIN_INPLACE (IOC4_SSCR_WORD_RX_DRAIN_MASK << IOC4_SSCR_WORD_RX_DRAIN_SHIFT)
#define IOC4_SSCR_WORD_DIAG_SHIFT                    21 /* established */
#define IOC4_SSCR_WORD_DIAG_MASK                     0x1u
#define IOC4_SSCR_WORD_DIAG_INPLACE (IOC4_SSCR_WORD_DIAG_MASK << IOC4_SSCR_WORD_DIAG_SHIFT)
#define IOC4_SSCR_WORD_RX_RING_CTS_SHIFT             19 /* established */
#define IOC4_SSCR_WORD_RX_RING_CTS_MASK              0x1u
#define IOC4_SSCR_WORD_RX_RING_CTS_INPLACE (IOC4_SSCR_WORD_RX_RING_CTS_MASK << IOC4_SSCR_WORD_RX_RING_CTS_SHIFT)
#define IOC4_SSCR_WORD_RX_RING_DCD_SHIFT             18 /* established */
#define IOC4_SSCR_WORD_RX_RING_DCD_MASK              0x1u
#define IOC4_SSCR_WORD_RX_RING_DCD_INPLACE (IOC4_SSCR_WORD_RX_RING_DCD_MASK << IOC4_SSCR_WORD_RX_RING_DCD_SHIFT)
#define IOC4_SSCR_WORD_HFC_EN_SHIFT                  17 /* established */
#define IOC4_SSCR_WORD_HFC_EN_MASK                   0x1u
#define IOC4_SSCR_WORD_HFC_EN_INPLACE (IOC4_SSCR_WORD_HFC_EN_MASK << IOC4_SSCR_WORD_HFC_EN_SHIFT)
#define IOC4_SSCR_WORD_TX_TIMER_BUSY_SHIFT           16 /* established */
#define IOC4_SSCR_WORD_TX_TIMER_BUSY_MASK            0x1u
#define IOC4_SSCR_WORD_TX_TIMER_BUSY_INPLACE (IOC4_SSCR_WORD_TX_TIMER_BUSY_MASK << IOC4_SSCR_WORD_TX_TIMER_BUSY_SHIFT)
#define IOC4_SSCR_WORD_RX_THRESHOLD_SHIFT            0 /* established */
#define IOC4_SSCR_WORD_RX_THRESHOLD_MASK             0x1ffu
#define IOC4_SSCR_WORD_RX_THRESHOLD_INPLACE (IOC4_SSCR_WORD_RX_THRESHOLD_MASK << IOC4_SSCR_WORD_RX_THRESHOLD_SHIFT)

/*
 * Control byte of a transmit ring entry; one per data byte. Value 0 is an
 * invalid byte. Type 1 sends the data byte. Types 2 (data to the modem control
 * register) and 3 (delay of the data value in milliseconds) are defined by the
 * SGI header; the SGI Linux driver never issues them.
 */
/* word TX_CONTROL_BYTE_WORD: 8 bits */
#define IOC4_TX_CONTROL_BYTE_WORD_WIDTH              8 /* established */
#define IOC4_TX_CONTROL_BYTE_WORD_TYPE_SHIFT         6 /* established */
#define IOC4_TX_CONTROL_BYTE_WORD_TYPE_MASK          0x3u
#define IOC4_TX_CONTROL_BYTE_WORD_TYPE_INPLACE (IOC4_TX_CONTROL_BYTE_WORD_TYPE_MASK << IOC4_TX_CONTROL_BYTE_WORD_TYPE_SHIFT)
#define IOC4_TX_CONTROL_BYTE_WORD_INT_WHEN_DONE_SHIFT 5 /* established */
#define IOC4_TX_CONTROL_BYTE_WORD_INT_WHEN_DONE_MASK 0x1u
#define IOC4_TX_CONTROL_BYTE_WORD_INT_WHEN_DONE_INPLACE (IOC4_TX_CONTROL_BYTE_WORD_INT_WHEN_DONE_MASK << IOC4_TX_CONTROL_BYTE_WORD_INT_WHEN_DONE_SHIFT)

#define IOC4_ATA_DMA_CONTROL                         0x15cu /* established */
#define IOC4_ATA_DMA_CONTROL_ACTIVE                  0x8u /* established */
#define IOC4_ATA_DMA_CONTROL_DIR_TO_MEMORY           0x4u /* established */
#define IOC4_ATA_DMA_CONTROL_ERROR                   0x10u /* established */
#define IOC4_ATA_DMA_CONTROL_START                   0x1u /* established */
#define IOC4_ATA_DMA_CONTROL_STOP                    0x2u /* established */
#define IOC4_ATA_DMA_COUNT_DEVICE                    0x154u /* established */
#define IOC4_ATA_DMA_COUNT_MEMORY                    0x158u /* established */
#define IOC4_ATA_DMA_CURRENT_HIGH                    0x150u /* inferred */
#define IOC4_ATA_DMA_CURRENT_LOW                     0x14cu /* inferred */
#define IOC4_ATA_DMA_END_AREA                        0x160u /* established */
#define IOC4_ATA_DMA_LIST_HIGH                       0x148u /* established */
#define IOC4_ATA_DMA_LIST_LOW                        0x144u /* established */
#define IOC4_ATA_DMA_TIMING                          0x140u /* inferred */
#define IOC4_EXTINT_COUNT_DIVISOR                    0x208u /* established */
#define IOC4_GPCR_DIR_MASK                           0xffu /* established */
#define IOC4_GPCR_EDGE_MASK                          0xff00u /* established */
#define IOC4_GPCR_INT_OUT_EN                         0x100000u /* established */
#define IOC4_GPIO_PIN_EXT_INT_OUT                    0x0u /* established */
#define IOC4_GPIO_PIN_SERIAL_MODE_0                  0x4u /* established */
#define IOC4_INT_OUT_COUNT_MASK                      0xffffu /* established */
/* established */
#define IOC4_INT_OUT_DIAG                            0x40000000u
#define IOC4_INT_OUT_MODE_MASK                       0x70000u /* established */
#define IOC4_INT_OUT_MODE_TOGGLE                     0x70000u /* established */
/* established */
#define IOC4_INT_OUT_VALUE                           0x80000000u
#define IOC4_KM_CSR_AUX_CLOCK_LINE                   0x200u /* established */
#define IOC4_KM_CSR_AUX_DATA_LINE                    0x100u /* established */
#define IOC4_KM_CSR_AUX_WRITE_PENDING                0x2u /* established */
#define IOC4_KM_CSR_IDLE_B_15_14                     0xc000u /* inferred */
#define IOC4_KM_CSR_KBD_CLOCK_LINE                   0x20u /* established */
#define IOC4_KM_CSR_KBD_DATA_LINE                    0x10u /* established */
#define IOC4_KM_CSR_KBD_WRITE_PENDING                0x1u /* established */
#define IOC4_KM_CSR_LAST_WRITE_LINE_B_3_2            0xcu /* inferred */
#define IOC4_OTHER_IR_ATA_INT                        0x1u /* established */
#define IOC4_OTHER_IR_ATA_MEMERR                     0x2u /* established */
/* established */
#define IOC4_OTHER_IR_GEN_INT                        0xff000000u
#define IOC4_OTHER_IR_KBM                            0x40u /* established */
#define IOC4_OTHER_IR_RT_INT                         0x800000u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_0                   0x4u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_1                   0x8u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_2                   0x10u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_3                   0x20u /* established */
#define IOC4_PCI_CLASS_CODE                          0xb4000u /* established */
#define IOC4_SERIAL_RING_PTR_B_9_3                   0x3f8u /* inferred */
#define IOC4_SERIAL_RX_TIMER_COUNT_B_27_16           0xfff0000u /* inferred */
#define IOC4_SERIAL_RX_TIMER_RELOAD_B_11_0           0xfffu /* inferred */
#define IOC4_SERIAL_SHADOW_CTS_V_100000              0x100000u /* inferred */
#define IOC4_SERIAL_SHADOW_DCD_V_800000              0x800000u /* inferred */
#define IOC4_SERIAL_SHADOW_DCTS_V_10000              0x10000u /* inferred */
#define IOC4_SERIAL_SHADOW_DDCD_V_80000              0x80000u /* inferred */
#define IOC4_SERIAL_SHADOW_OUTPUTS_B_28_24           0x1f000000u /* inferred */
#define IOC4_SERIAL_SHADOW_RX_FLAGS_B_7_0            0xffu /* inferred */
#define IOC4_SERIAL_SRCIR_TIMER_ARM_V_80000000       0x80000000u /* inferred */
#define IOC4_SIO_CR_ARB_DIAG                         0x70u /* established */
#define IOC4_SIO_CR_ATA_DIAG_ACTIVE                  0x200u /* established */
#define IOC4_SIO_CR_ATA_DIAG_IDLE                    0x100u /* established */
#define IOC4_SIO_CR_CMD_PULSE                        0xfu /* established */
#define IOC4_SIO_CR_SIO_DIAG_IDLE                    0x80u /* established */
#define IOC4_SIO_IR_SRC_UART_0                       0x40u /* established */
#define IOC4_SIO_IR_SRC_UART_1                       0x4000u /* established */
#define IOC4_SIO_IR_SRC_UART_2                       0x400000u /* established */
/* established */
#define IOC4_SIO_IR_SRC_UART_3                       0x40000000u

#endif /* IOC4_GEN_H */
