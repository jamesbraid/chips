/* generated from devices/wd33c93/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 9910f5661f6314c737e8fc59355fe020e6e1845f293604aa3a75852ecd0c3cb5 */
/* WD33C93/WD33C93A SCSI bus interface controller as wired on the Indigo (R3000
 * and R4000 boards) */
#ifndef WD33C93_GEN_H
#define WD33C93_GEN_H

#include <stdint.h>


/*
 * Own ID and CDB size. The bus ID in bits 2:0 and the configuration bits are
 * sampled by the Reset command, so they take effect only after a reset. Both
 * the PROM and IRIX write it before every Reset. In advanced mode, bits 3:0
 * hold the CDB length for a command group the chip does not know (the driver
 * writes it from startwd93 only on parts that answered the reset with advanced
 * features). Bit 5 is EIH on rev E/F A parts and RAF on the B. A qtest can
 * discriminate: write 0 to 7 and read each back; the presence test needs all
 * eight bits to read back.
 */
/* own_id: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_OWN_ID_OFFSET                        0x0u /* established */
#define WD33C93_OWN_ID_FS_SHIFT                      6 /* established */
#define WD33C93_OWN_ID_FS_MASK                       0x3u
#define WD33C93_OWN_ID_FS_INPLACE (WD33C93_OWN_ID_FS_MASK << WD33C93_OWN_ID_FS_SHIFT)
#define WD33C93_OWN_ID_EIH_RAF_SHIFT                 5 /* inferred */
#define WD33C93_OWN_ID_EIH_RAF_MASK                  0x1u
#define WD33C93_OWN_ID_EIH_RAF_INPLACE (WD33C93_OWN_ID_EIH_RAF_MASK << WD33C93_OWN_ID_EIH_RAF_SHIFT)
#define WD33C93_OWN_ID_EHP_SHIFT                     4 /* established */
#define WD33C93_OWN_ID_EHP_MASK                      0x1u
#define WD33C93_OWN_ID_EHP_INPLACE (WD33C93_OWN_ID_EHP_MASK << WD33C93_OWN_ID_EHP_SHIFT)
#define WD33C93_OWN_ID_EAF_SHIFT                     3 /* established */
#define WD33C93_OWN_ID_EAF_MASK                      0x1u
#define WD33C93_OWN_ID_EAF_INPLACE (WD33C93_OWN_ID_EAF_MASK << WD33C93_OWN_ID_EAF_SHIFT)
#define WD33C93_OWN_ID_ID_SHIFT                      0 /* established */
#define WD33C93_OWN_ID_ID_MASK                       0x7u
#define WD33C93_OWN_ID_ID_INPLACE (WD33C93_OWN_ID_ID_MASK << WD33C93_OWN_ID_ID_SHIFT)

/*
 * Control. Interrupt and DMA mode selection. IRIX and the PROM write 0x2d
 * (burst DMA mode) once the chip has been reset and detected as a WD33C93A or
 * B, and 0x8d (single-byte DMA mode) when the burst flag is clear or the chip
 * answered the reset with status 0. A qtest can discriminate: reset clears it;
 * write 0x2d and read it back.
 */
/* control: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_CONTROL_OFFSET                       0x1u /* established */
#define WD33C93_CONTROL_DMA_MODE_SHIFT               5 /* established */
#define WD33C93_CONTROL_DMA_MODE_MASK                0x7u
#define WD33C93_CONTROL_DMA_MODE_INPLACE (WD33C93_CONTROL_DMA_MODE_MASK << WD33C93_CONTROL_DMA_MODE_SHIFT)
#define WD33C93_CONTROL_HHP_SHIFT                    4 /* established */
#define WD33C93_CONTROL_HHP_MASK                     0x1u
#define WD33C93_CONTROL_HHP_INPLACE (WD33C93_CONTROL_HHP_MASK << WD33C93_CONTROL_HHP_SHIFT)
#define WD33C93_CONTROL_EDI_SHIFT                    3 /* established */
#define WD33C93_CONTROL_EDI_MASK                     0x1u
#define WD33C93_CONTROL_EDI_INPLACE (WD33C93_CONTROL_EDI_MASK << WD33C93_CONTROL_EDI_SHIFT)
#define WD33C93_CONTROL_IDI_SHIFT                    2 /* established */
#define WD33C93_CONTROL_IDI_MASK                     0x1u
#define WD33C93_CONTROL_IDI_INPLACE (WD33C93_CONTROL_IDI_MASK << WD33C93_CONTROL_IDI_SHIFT)
#define WD33C93_CONTROL_HA_SHIFT                     1 /* established */
#define WD33C93_CONTROL_HA_MASK                      0x1u
#define WD33C93_CONTROL_HA_INPLACE (WD33C93_CONTROL_HA_MASK << WD33C93_CONTROL_HA_SHIFT)
#define WD33C93_CONTROL_HSP_SHIFT                    0 /* established */
#define WD33C93_CONTROL_HSP_MASK                     0x1u
#define WD33C93_CONTROL_HSP_INPLACE (WD33C93_CONTROL_HSP_MASK << WD33C93_CONTROL_HSP_SHIFT)

/*
 * Selection timeout. Zero disables the timeout. IRIX writes 0x40; the PROM
 * writes 0x40 through a helper called at the end of its reset routine. During
 * the hinv bus scan IRIX divides the value by 32 (rounded up) and later
 * restores it, to shorten selects of missing targets. A qtest can discriminate:
 * a Select to a target that is not present stays pending when this is zero, and
 * ends with status 0x42 when it is not.
 */
/* timeout: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_TIMEOUT_OFFSET                       0x2u /* established */

/*
 * CDB bytes 1 to 12 for Select-and-Transfer. The same offsets are total
 * sectors, heads, cylinders, logical address and head and cylinder numbers for
 * Translate Address. The 12 bytes are written with one address-port write of 3
 * and as many data-port writes as the CDB has bytes, using the auto-increment
 * (IRIX stops at 12, rounding a 13+ byte count down). On a WD33C93B with RAF
 * set, index 3 reads back a revision code after Reset (below). A qtest can
 * discriminate: auto-increment and cdb1 reading zero after reset.
 */
/* cdb: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_CDB_OFFSET                           0x3u /* established */
#define WD33C93_CDB_COUNT                            12
#define WD33C93_CDB_STRIDE                           1

/*
 * Target LUN. The initiator writes the LUN for the Identify message; after
 * Select-and-Transfer completes it holds the target's status byte (IRIX reads
 * it on status 0x16 and stores it as the SCSI status). During reselection with
 * advanced features it holds the Identify byte (TLV in bit 7, DOK in bit 6).
 * IRIX reads it first in the interrupt handler and then reads the command phase
 * register by letting the address auto-increment.
 */
/* target_lun: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_TARGET_LUN_OFFSET                    0xfu /* established */
#define WD33C93_TARGET_LUN_TLV_SHIFT                 7 /* established */
#define WD33C93_TARGET_LUN_TLV_MASK                  0x1u
#define WD33C93_TARGET_LUN_TLV_INPLACE (WD33C93_TARGET_LUN_TLV_MASK << WD33C93_TARGET_LUN_TLV_SHIFT)
#define WD33C93_TARGET_LUN_DOK_SHIFT                 6 /* established */
#define WD33C93_TARGET_LUN_DOK_MASK                  0x1u
#define WD33C93_TARGET_LUN_DOK_INPLACE (WD33C93_TARGET_LUN_DOK_MASK << WD33C93_TARGET_LUN_DOK_SHIFT)
#define WD33C93_TARGET_LUN_LUN_SHIFT                 0 /* established */
#define WD33C93_TARGET_LUN_LUN_MASK                  0x7u
#define WD33C93_TARGET_LUN_LUN_INPLACE (WD33C93_TARGET_LUN_LUN_MASK << WD33C93_TARGET_LUN_LUN_SHIFT)

/*
 * Command phase: how far a Select-and-Transfer has progressed. The chip
 * advances it as phases complete (CPH_ constants); the driver writes a value
 * back and reissues Select-and-Transfer to resume. IRIX writes 0x00 to start,
 * 0x41 after Save Data Pointers, 0x44 after reselection and 0x45 after the
 * Identify message or a parity error. A qtest can discriminate: after
 * Select-and-Transfer to a missing target it reads 0x00; to a present one 0x10
 * and up.
 */
/* command_phase: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_COMMAND_PHASE_OFFSET                 0x10u /* established */

/*
 * Synchronous transfer: offset in bits 3:0 (zero means asynchronous), period in
 * bits 6:4 (0 is 8 clock cycles, 2 to 7 are that many cycles), bit 7 fast SCSI
 * on the B. IRIX initialises the per-target copy to 0x20 (two cycles, offset
 * zero, asynchronous) and loads the target's value before every command. The
 * PROM reads it before the first reset and restores it afterwards (inferred: to
 * keep a boot target's setting).
 */
/* sync_transfer: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_SYNC_TRANSFER_OFFSET                 0x11u /* established */
#define WD33C93_SYNC_TRANSFER_FAST_SHIFT             7 /* inferred */
#define WD33C93_SYNC_TRANSFER_FAST_MASK              0x1u
#define WD33C93_SYNC_TRANSFER_FAST_INPLACE (WD33C93_SYNC_TRANSFER_FAST_MASK << WD33C93_SYNC_TRANSFER_FAST_SHIFT)
#define WD33C93_SYNC_TRANSFER_PERIOD_SHIFT           4 /* established */
#define WD33C93_SYNC_TRANSFER_PERIOD_MASK            0x7u
#define WD33C93_SYNC_TRANSFER_PERIOD_INPLACE (WD33C93_SYNC_TRANSFER_PERIOD_MASK << WD33C93_SYNC_TRANSFER_PERIOD_SHIFT)
#define WD33C93_SYNC_TRANSFER_OFFSET_SHIFT           0 /* established */
#define WD33C93_SYNC_TRANSFER_OFFSET_MASK            0xfu
#define WD33C93_SYNC_TRANSFER_OFFSET_INPLACE (WD33C93_SYNC_TRANSFER_OFFSET_MASK << WD33C93_SYNC_TRANSFER_OFFSET_SHIFT)

/*
 * 24-bit transfer count, most significant byte at index 12h, written with one
 * address-port write of 12h and three data-port writes. IRIX writes zero for
 * commands with no data phase and the HPC1-programmed length otherwise (at most
 * 0xfffffc). After an interrupted transfer it holds the bytes not transferred
 * (IRIX reads it back when it saves the data pointers). A qtest can
 * discriminate: three-byte write through the auto-increment and read back.
 */
/* transfer_count: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_TRANSFER_COUNT_OFFSET                0x12u /* established */
#define WD33C93_TRANSFER_COUNT_COUNT                 3
#define WD33C93_TRANSFER_COUNT_STRIDE                1

/*
 * Destination ID: target to select or reselect, bits 2:0; bit 6 DPD gives the
 * expected data direction in advanced mode (1 is device to host); bit 7 SCC and
 * bit 5 DF are target-mode chaining controls. IRIX writes the target ID with
 * bit 6 from the data direction (the command's 0x40 flag) at every command
 * start. The PROM's first-time path reads it back and saves bits 2:0.
 */
/* dest_id: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_DEST_ID_OFFSET                       0x15u /* established */
#define WD33C93_DEST_ID_SCC_SHIFT                    7 /* inferred */
#define WD33C93_DEST_ID_SCC_MASK                     0x1u
#define WD33C93_DEST_ID_SCC_INPLACE (WD33C93_DEST_ID_SCC_MASK << WD33C93_DEST_ID_SCC_SHIFT)
#define WD33C93_DEST_ID_DPD_SHIFT                    6 /* established */
#define WD33C93_DEST_ID_DPD_MASK                     0x1u
#define WD33C93_DEST_ID_DPD_INPLACE (WD33C93_DEST_ID_DPD_MASK << WD33C93_DEST_ID_DPD_SHIFT)
#define WD33C93_DEST_ID_DF_SHIFT                     5 /* inferred */
#define WD33C93_DEST_ID_DF_MASK                      0x1u
#define WD33C93_DEST_ID_DF_INPLACE (WD33C93_DEST_ID_DF_MASK << WD33C93_DEST_ID_DF_SHIFT)
#define WD33C93_DEST_ID_ID_SHIFT                     0 /* established */
#define WD33C93_DEST_ID_ID_MASK                      0x7u
#define WD33C93_DEST_ID_ID_INPLACE (WD33C93_DEST_ID_ID_MASK << WD33C93_DEST_ID_ID_SHIFT)

/*
 * Source ID: ER (bit 7) enables reselection, ES (bit 6) selection, DSP (bit 5)
 * ignores select parity; bit 3 SIV and bits 2:0 report who selected or
 * reselected the chip. IRIX and the PROM write 0x80 after a reset when
 * disconnect is enabled (the PROM's per-controller enable word is 1) and 0
 * otherwise. After a reselect IRIX reads this register and then the SCSI status
 * register by auto-increment and uses bits 2:0 to find the channel.
 */
/* source_id: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_SOURCE_ID_OFFSET                     0x16u /* established */
#define WD33C93_SOURCE_ID_ER_SHIFT                   7 /* established */
#define WD33C93_SOURCE_ID_ER_MASK                    0x1u
#define WD33C93_SOURCE_ID_ER_INPLACE (WD33C93_SOURCE_ID_ER_MASK << WD33C93_SOURCE_ID_ER_SHIFT)
#define WD33C93_SOURCE_ID_ES_SHIFT                   6 /* inferred */
#define WD33C93_SOURCE_ID_ES_MASK                    0x1u
#define WD33C93_SOURCE_ID_ES_INPLACE (WD33C93_SOURCE_ID_ES_MASK << WD33C93_SOURCE_ID_ES_SHIFT)
#define WD33C93_SOURCE_ID_DSP_SHIFT                  5 /* inferred */
#define WD33C93_SOURCE_ID_DSP_MASK                   0x1u
#define WD33C93_SOURCE_ID_DSP_INPLACE (WD33C93_SOURCE_ID_DSP_MASK << WD33C93_SOURCE_ID_DSP_SHIFT)
#define WD33C93_SOURCE_ID_SIV_SHIFT                  3 /* established */
#define WD33C93_SOURCE_ID_SIV_MASK                   0x1u
#define WD33C93_SOURCE_ID_SIV_INPLACE (WD33C93_SOURCE_ID_SIV_MASK << WD33C93_SOURCE_ID_SIV_SHIFT)
#define WD33C93_SOURCE_ID_ID_SHIFT                   0 /* established */
#define WD33C93_SOURCE_ID_ID_MASK                    0x7u
#define WD33C93_SOURCE_ID_ID_INPLACE (WD33C93_SOURCE_ID_ID_MASK << WD33C93_SOURCE_ID_ID_SHIFT)

/*
 * SCSI status: the cause of the last interrupt, high nibble the group (0 reset,
 * 1 done, 2 paused, 4 terminated, 8 service) and low nibble the qualifier or
 * phase. Reading it clears INT in the auxiliary status register and the chip's
 * interrupt request; the chip will not change it until it is read. The driver
 * must not issue a command within 7 microseconds of reading it, or the chip
 * ignores the command and sets LCI. Values acted on by IRIX are the STATUS_
 * constants. A qtest can discriminate: after Reset read 0x00 or 0x01 depending
 * on own_id.eaf, then INT is clear.
 */
/* scsi_status: r8, space wd33c93_index, reset 0x0 */
#define WD33C93_SCSI_STATUS_OFFSET                   0x17u /* established */

/*
 * Command: bits 6:0 the command code, bit 7 single-byte transfer. The register
 * stays selected after a write (no auto-increment). It must not be written
 * while CIP or INT is set. A command written while an interrupt is pending is
 * ignored and sets LCI; the IRIX driver handles that in wd93cmd_lci by reading
 * SCSI status and rewriting the command. A qtest can discriminate: a write with
 * INT set must leave LCI set and not start the command.
 */
/* command: rw8, space wd33c93_index, reset 0x0 */
#define WD33C93_COMMAND_OFFSET                       0x18u /* established */
#define WD33C93_COMMAND_SBT_SHIFT                    7 /* established */
#define WD33C93_COMMAND_SBT_MASK                     0x1u
#define WD33C93_COMMAND_SBT_INPLACE (WD33C93_COMMAND_SBT_MASK << WD33C93_COMMAND_SBT_SHIFT)
#define WD33C93_COMMAND_CODE_SHIFT                   0 /* established */
#define WD33C93_COMMAND_CODE_MASK                    0x7fu
#define WD33C93_COMMAND_CODE_INPLACE (WD33C93_COMMAND_CODE_MASK << WD33C93_COMMAND_CODE_SHIFT)

/*
 * Data register: the host side of the 12-byte FIFO. IRIX uses it in
 * programmed-I/O message and inquiry phases, polling the DBR bit of the
 * auxiliary status register, and never for bulk data. The register stays
 * selected after an access. In the HPC1 burst mode the DMA channel moves bulk
 * data through the same register without CPU involvement.
 */
/* data: rw8, space wd33c93_index, reset unknown */
#define WD33C93_DATA_OFFSET                          0x19u /* established */

/*
 * Queue tag, WD33C93B only. IRIX never touches it. NetBSD writes 0x55 here and
 * reads it back after a reset that returned status 0x01: if it reads 0x55 the
 * part is a B, otherwise an A. On an A part the register does not exist and the
 * read returns all ones (data sheet note 2 to the register map). A qtest can
 * discriminate: the write sticks only on a model configured as a B.
 */
/* queue_tag: rw8, space wd33c93_index, reset unknown */
#define WD33C93_QUEUE_TAG_OFFSET                     0x1au /* inferred */

/*
 * Auxiliary status. Bit 7 INT is the interrupt-request pin: it stays set until
 * the SCSI status register is read. Bit 6 LCI says a command was written while
 * an interrupt was pending or the chip was busy decoding the last command, and
 * the command was ignored. Bit 5 BSY is set while a level II command runs. Bit
 * 4 CIP is set while the chip decodes a command; the command register may not
 * be written while it is set. Bit 1 PE is a parity error, cleared when a new
 * command is issued. Bit 0 DBR is data-buffer-ready for programmed
 * data-register transfers. Both IRIX and the PROM poll bit 4 clear before every
 * command and bit 7 for interrupts. A qtest can discriminate: after a hard
 * reset read 0x80; after a Reset command and before the status read INT stays
 * set; reading scsi_status clears bit 7.
 */
/* aux_status: r8, space wd33c93_port_r, reset 0x80 */
#define WD33C93_AUX_STATUS_OFFSET                    0x122u /* established */
#define WD33C93_AUX_STATUS_INT_SHIFT                 7 /* established */
#define WD33C93_AUX_STATUS_INT_MASK                  0x1u
#define WD33C93_AUX_STATUS_INT_INPLACE (WD33C93_AUX_STATUS_INT_MASK << WD33C93_AUX_STATUS_INT_SHIFT)
#define WD33C93_AUX_STATUS_LCI_SHIFT                 6 /* established */
#define WD33C93_AUX_STATUS_LCI_MASK                  0x1u
#define WD33C93_AUX_STATUS_LCI_INPLACE (WD33C93_AUX_STATUS_LCI_MASK << WD33C93_AUX_STATUS_LCI_SHIFT)
#define WD33C93_AUX_STATUS_BSY_SHIFT                 5 /* established */
#define WD33C93_AUX_STATUS_BSY_MASK                  0x1u
#define WD33C93_AUX_STATUS_BSY_INPLACE (WD33C93_AUX_STATUS_BSY_MASK << WD33C93_AUX_STATUS_BSY_SHIFT)
#define WD33C93_AUX_STATUS_CIP_SHIFT                 4 /* established */
#define WD33C93_AUX_STATUS_CIP_MASK                  0x1u
#define WD33C93_AUX_STATUS_CIP_INPLACE (WD33C93_AUX_STATUS_CIP_MASK << WD33C93_AUX_STATUS_CIP_SHIFT)
#define WD33C93_AUX_STATUS_PE_SHIFT                  1 /* established */
#define WD33C93_AUX_STATUS_PE_MASK                   0x1u
#define WD33C93_AUX_STATUS_PE_INPLACE (WD33C93_AUX_STATUS_PE_MASK << WD33C93_AUX_STATUS_PE_SHIFT)
#define WD33C93_AUX_STATUS_DBR_SHIFT                 0 /* established */
#define WD33C93_AUX_STATUS_DBR_MASK                  0x1u
#define WD33C93_AUX_STATUS_DBR_INPLACE (WD33C93_AUX_STATUS_DBR_MASK << WD33C93_AUX_STATUS_DBR_SHIFT)

/*
 * Data port. Reads and writes the internal register selected through the
 * address port. Every IRIX and PROM access is a byte access. A qtest can
 * discriminate: write own_id then read it back (the controller presence test,
 * below).
 */
/* data_port: rw8, space wd33c93_port_r, reset unknown */
#define WD33C93_DATA_PORT_OFFSET                     0x126u /* established */

/*
 * Address port. A byte written here selects the internal register the next
 * data-port access uses. No shipped code reads it back (a read returns the
 * auxiliary status register). The index auto-increments after every data-port
 * access except when the selected register is the data register or the command
 * register. A qtest can discriminate: write 0x03, write three bytes to the data
 * port, and read cdb1 to cdb3 back by writing 0x03 once and reading the data
 * port three times.
 */
/* address: w8, space wd33c93_port_w, reset unknown */
#define WD33C93_ADDRESS_OFFSET                       0x122u /* established */

#define WD33C93_CMD_ABORT                            0x1u /* inferred */
#define WD33C93_CMD_ASSERT_ATN                       0x2u /* inferred */
#define WD33C93_CMD_DISCONNECT                       0x4u /* established */
#define WD33C93_CMD_NEGATE_ACK                       0x3u /* inferred */
#define WD33C93_CMD_RESELECT                         0x5u /* inferred */
#define WD33C93_CMD_RESET                            0x0u /* established */
#define WD33C93_CMD_SBT                              0x80u /* established */
#define WD33C93_CMD_SELECT                           0x7u /* inferred */
#define WD33C93_CMD_SELECT_ATN                       0x6u /* established */
#define WD33C93_CMD_SELECT_ATN_XFER                  0x8u /* established */
#define WD33C93_CMD_SELECT_XFER                      0x9u /* inferred */
#define WD33C93_CMD_TRANSFER_INFO                    0x20u /* established */
#define WD33C93_CMD_TRANSLATE                        0x18u /* inferred */
#define WD33C93_CONTROL_IRIX_BURST                   0x2du /* established */
#define WD33C93_CONTROL_IRIX_SINGLE                  0x8du /* established */
#define WD33C93_CPH_CMD_COMPLETE                     0x60u /* established */
#define WD33C93_CPH_CMD_START                        0x30u /* established */
#define WD33C93_CPH_DATA_DONE                        0x46u /* established */
#define WD33C93_CPH_DISCONNECTED                     0x43u /* established */
#define WD33C93_CPH_DISCONNECT_MSG                   0x42u /* established */
#define WD33C93_CPH_IDENTIFY_IN                      0x45u /* established */
#define WD33C93_CPH_IDENTIFY_SENT                    0x20u /* established */
#define WD33C93_CPH_RESELECTED                       0x44u /* established */
#define WD33C93_CPH_SAVE_DP                          0x41u /* established */
#define WD33C93_CPH_SELECTED                         0x10u /* established */
#define WD33C93_CPH_STATUS_DONE                      0x50u /* established */
#define WD33C93_CPH_STATUS_PHASE                     0x47u /* established */
#define WD33C93_OWNID_IRIX_AF                        0xa8u /* established */
#define WD33C93_OWNID_IRIX_PLAIN                     0x80u /* established */
#define WD33C93_PHASE_COMMAND                        0x2u /* established */
#define WD33C93_PHASE_DATA_IN                        0x1u /* established */
#define WD33C93_PHASE_DATA_OUT                       0x0u /* established */
#define WD33C93_PHASE_MSG_IN                         0x7u /* established */
#define WD33C93_PHASE_MSG_OUT                        0x6u /* established */
#define WD33C93_PHASE_STATUS                         0x3u /* established */
#define WD33C93_SOURCEID_ENABLE_RESEL                0x80u /* established */
#define WD33C93_STATUS_BAD_CMD                       0x40u /* inferred */
#define WD33C93_STATUS_BAD_STATUS                    0x47u /* established */
#define WD33C93_STATUS_DISCONNECT                    0x85u /* established */
#define WD33C93_STATUS_MSGIN_PAUSED                  0x20u /* inferred */
#define WD33C93_STATUS_PARITY                        0x43u /* established */
#define WD33C93_STATUS_PARITY_ATN                    0x44u /* established */
#define WD33C93_STATUS_REQ_MSGIN                     0x8fu /* established */
#define WD33C93_STATUS_REQ_MSGOUT                    0x8eu /* established */
#define WD33C93_STATUS_RESELECT                      0x80u /* established */
#define WD33C93_STATUS_RESELECT_AF                   0x81u /* established */
#define WD33C93_STATUS_RESET                         0x0u /* established */
#define WD33C93_STATUS_RESET_AF                      0x1u /* established */
#define WD33C93_STATUS_SAT_DONE                      0x16u /* established */
#define WD33C93_STATUS_SAVE_DP                       0x21u /* established */
#define WD33C93_STATUS_SELECT_DONE                   0x11u /* established */
#define WD33C93_STATUS_SEL_TIMEOUT                   0x42u /* established */
#define WD33C93_STATUS_UNEXP_DISC                    0x41u /* established */
#define WD33C93_STATUS_UNEXP_PHASE                   0x48u /* established */
#define WD33C93_STATUS_XFER_DONE                     0x18u /* established */
#define WD33C93_TIMEOUT_IRIX                         0x40u /* established */

#endif /* WD33C93_GEN_H */
