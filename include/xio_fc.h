/*
 * xio_fc.h - XIO Fibre Channel adapter (Adaptec AIC-1160 board), command and register contract
 *
 * Written by hand: the census does not cover this adapter. Same label convention as the generated headers:
 * [E] established, [I] inferred, [U] unknown. There is no public programming manual for the controller; every fact
 * is from reading the shipped adapter driver objects (docs/xio-fibre-channel.md names the routines) and was
 * re-read against one machine build's driver object for the normal command builder, the two data-descriptor mappers
 * and the link-service builders' stores; fields not re-read carry the sheet's grade.
 */
#ifndef XIO_FC_H
#define XIO_FC_H

/* Command block ("TCB"), built by the driver in host memory and read by the chip by DMA. A 32-byte frame header at
 * 0x00 to 0x1f, four control bytes at 0x20 to 0x23, a 32-byte FCP command unit at 0x24, then a descriptor area.
 * Multi-byte fields are little-endian unless noted; the chip fills the frame's source ID itself. */
#define XIO_FC_TCB_OX_ID                     0x00       /* [E] 2 bytes LE; the command tag, written again at 0x68 and echoed in the done-queue entry */
#define XIO_FC_TCB_RX_ID                     0x02       /* [E] 2 bytes; 0xffff (unassigned) on an outbound command */
#define XIO_FC_TCB_D_ID                      0x04       /* [E] 3 bytes; on a loop the byte at 0x04 is the target loop address, looked up from a fixed target-id table; the source ID is absent */
#define XIO_FC_TCB_R_CTL                     0x07       /* [E] byte written: 0x01 for a SCSI command, 0x22 for a link-service request, 0x23 for its reply; [I] that this is a chip encoding rather than the wire value (the wire value of a command is 0x06) */
#define XIO_FC_TCB_DELIMITER                 0x09       /* [E] byte written 0x05, class-3 normal [I] */
#define XIO_FC_TCB_F_CTL2                    0x0e       /* [E] byte written 0x29 for a SCSI command */
#define XIO_FC_TCB_TYPE                      0x0f       /* [E] byte written 0x08 for a SCSI command; 0x01 for a link-service request [E written, I as FC-4 type] */
#define XIO_FC_TCB_F_CTL0                    0x10       /* [E] byte written 0x08 by the normal builder (re-read); name [I] */
#define XIO_FC_TCB_F_CTL1                    0x11       /* [I] name by frame-header layout; the normal builder does not store here ([U] value); the link-service builders store a 4-byte big-endian word at 0x10 to 0x13 [E that it is written] */
#define XIO_FC_TCB_SEQ_ID                    0x13       /* [I] sequence ID by frame-header layout; no store from the normal builder (re-read), reached only by the link-service word at 0x10 */
#define XIO_FC_TCB_SEQ_CNT                   0x14       /* [I] sequence count, 2 bytes at 0x14 to 0x15, by frame-header layout; no store seen */
#define XIO_FC_TCB_LOOP_FLAGS                0x1c       /* [E] byte: 0x18 when the host-unfair tunable is set, else 0x40; meaning (open half-duplex, with and without fair arbitration) [I] */
#define XIO_FC_TCB_CONTROL                   0x21       /* [E] command-type discriminator: 0x00 read or no-data command, 0x01 unsolicited-receive buffer, 0x02 write, 0x0a link-service request/reply; roles [I] from the builders */
#define XIO_FC_TCB_DESC_MODE                 0x23       /* [E] data-descriptor mode set by the data mapper: 0x08 one direct buffer, 0x0b scatter-gather list, 0x0c no data */
#define XIO_FC_TCB_FCP_LUN                   0x24       /* [E] that the request's LUN bytes land here (8 bytes, FC order); full 8-byte form [I] */
#define XIO_FC_TCB_FCP_CNTL                  0x2c       /* [E] only the byte at 0x2f is written: 0x02 read, 0x01 write; the rest of FCP_CNTL [I] */
#define XIO_FC_TCB_FCP_CDB                   0x30       /* [E] 16 bytes copied from the request; confirmed at 0x30 on the three machine builds */
#define XIO_FC_TCB_FCP_DL                    0x40       /* [E] 4 bytes big-endian, FC network order (the builder uses unaligned word stores) */
#define XIO_FC_TCB_NEXT                      0x44       /* [E] 8 bytes LE, PCI bus address of the next slot of the driver's circular TCB queue; [I] that the chip uses it as a chain link */
#define XIO_FC_TCB_DATA_PTR                  0x4c       /* [E] 8 bytes LE; bus address of the single buffer (mode 0x08) or of the scatter-gather list (mode 0x0b) */
#define XIO_FC_TCB_XFER_LEN                  0x54       /* [E] 4 bytes LE byte count for a single buffer; zero in list mode (the list ends on a flag in its last descriptor) */
#define XIO_FC_TCB_RESP_PTR                  0x58       /* [E] 8 bytes LE; bus address of the 256-byte response and sense buffer */
#define XIO_FC_TCB_DATA_LEN                  0x60       /* [E] 4 bytes LE; copy of the transfer length */
#define XIO_FC_TCB_UNKNOWN_64                0x64       /* [E] byte written 0x14 by the normal builder (re-read); role [U]: settle by reading the sequencer microcode's use of this byte, or a capture of a completed command block */
#define XIO_FC_TCB_HANDLE_COPY               0x68       /* [E] 2 bytes LE written; the TCB handle repeated, chip use [I] */

/* Done-queue entry, read by the back-end interrupt routine after the chip writes a completion. */
#define XIO_FC_DONE_HANDLE                   0x00       /* [E] 2 bytes LE; completed TCB handle, the tag written at XIO_FC_TCB_OX_ID */
#define XIO_FC_DONE_STATUS                   0x02       /* [E] byte; completion status code (normal-command meanings: 0 success, 1 overrun, 2 underrun, 3 TCB parity error, 4 error response, 5 out of order, 6 frame format, 7 count overflow, 8 undelivered, 9 and 0xa bad delimiter, 0xb aborted, 0xf primitive timeout [E]; a loop-init completion reuses some values, and a successful one returns the negotiated loop address) */
#define XIO_FC_DONE_PASS                     0x03       /* [E] byte; initialised to 0xff; the chip writes the ring-lap number modulo 256 and the driver consumes while it equals the expected value */

/* FCP response buffer: the 256-byte buffer whose bus address is XIO_FC_TCB_RESP_PTR. The chip writes a standard FCP
 * response unit here, and the driver reads it only when the done-queue status is 4 (error response). Re-read against
 * the completion routine of one machine build's driver object: the three byte loads and the unaligned word load
 * below are what it does. */
#define XIO_FC_RESP_FCP_STATUS_FLAGS         0x0a       /* [E] byte; bits 0x01 response-length valid, 0x02 sense-length valid, 0x04 residual overrun, 0x08 residual underrun (each tested by a single-bit branch); the names follow the FC-4 SCSI profile [I] */
#define XIO_FC_RESP_SCSI_STATUS              0x0b       /* [E] byte; passed up as the command's SCSI status; 0x28 (queue full) is compared and handled apart */
#define XIO_FC_RESP_RESIDUAL                 0x0c       /* [E] 4 bytes big-endian (read as an unaligned word pair); the command residual on underrun, reported as a length mismatch on overrun */
#define XIO_FC_RESP_SENSE_LEN                0x10       /* [E] 4 bytes big-endian, read as an unaligned word pair */
#define XIO_FC_RESP_RESPONSE_LEN             0x14       /* [E] 4 bytes big-endian, read as an unaligned word pair */

/* Interrupt-status register at 0x24 (16-bit pending test masks with 0xff08; the chip mirrors it into a two-byte
 * host status block, low byte = 0x24, high byte = 0x25; handled bits are cleared by writing them back as byte
 * writes). Meanings are inferred from the branch each bit guards [I]; that the driver tests each bit is [E]. */
#define XIO_FC_INT_LOOP_ATTENTION            0x0008     /* [E] register 0x24 bit 3: the back-end routine then selects bank 1 and reads the loop-state register at 0xa1 */
#define XIO_FC_INT_SEQ_READY_FOR_LIP         0x0100     /* [E] register 0x25 bit 0: tested by the back-end routine on its saved copy of the status byte; set means the sequencer has run loop initialisation far enough for the host to post its loop-initialisation command block, and the routine then pauses the sequencer. Name [I] */
#define XIO_FC_INT_HOST_COMPLETION           0x0400     /* [I] register 0x25 bit 2: named by the sheet's register map; neither interrupt routine tests it on its own, and the driver does not depend on it */
#define XIO_FC_INT_BREAKPOINT                0x0200     /* [I] register 0x25 bit 1: named by the sheet's register map; neither interrupt routine tests it on its own */
#define XIO_FC_INT_PCI_ERROR                 0x8000     /* [E] register 0x25 bit 7 */
#define XIO_FC_INT_HARDWARE_ERROR            0x4000     /* [E] register 0x25 bit 6: the routine reads and latches the error-status register at 0x23 */
#define XIO_FC_INT_SOFTWARE_ERROR            0x2000     /* [E] register 0x25 bit 5 */
#define XIO_FC_INT_SEQ_COMPLETION            0x1000     /* [E] register 0x25 bit 4: the done-queue completion bit; the driver drains the queue by scanning pass bytes regardless of this bit. Whether the per-source enable at 0x99 bit 4 is needed is [U] */

/* Chip host registers, primary window (BAR 0). Byte accessors are 8-bit, "word" accessors 16-bit. The register file is
 * bank-switched by the byte at XIO_FC_REG_BANK_SELECT, so an offset can mean different things in different banks.
 * Re-read in one machine build's driver objects (the same bytes in the other two builds for the three objects that
 * carry these accesses); the roles are inferred from the driver's use and say so. */
#define XIO_FC_REG_SEQ_CONTROL               0x00       /* [E] byte; sequencer control */
#define XIO_FC_SEQ_CTRL_RAM_LOAD             0x01       /* [E] written alone before the microcode image is streamed in */
#define XIO_FC_SEQ_CTRL_RUN                  0x40       /* [E] written after the image is verified, to run the sequencer */
#define XIO_FC_SEQ_CTRL_RESET_PC             0x02       /* [I] reset the sequencer program counter; seen only inside the 0x42 write */
#define XIO_FC_SEQ_CTRL_START                0x42       /* [E] run plus reset, written after the mainline image is loaded to start it from the top */
#define XIO_FC_REG_HOST_CONTROL              0x22       /* [E] byte; host control */
#define XIO_FC_HOST_CTRL_MASTER_IRQ_EN       0x04       /* [E] set and cleared by the interrupt enable and disable routines; name [I] */
#define XIO_FC_HOST_CTRL_PAUSE               0x40       /* [E] set to pause the sequencer, polled for the acknowledge */
#define XIO_FC_HOST_CTRL_PAUSE_AT_TOP        0x80       /* [E] set to pause at the top of the program, polled for the acknowledge; unpause clears 0xc0 */
#define XIO_FC_HOST_CTRL_RESET_WRITE         0x43       /* [E] the value the error-recovery reset writes after a pause (pause plus 0x02 plus 0x01); the effect of the two low bits is [I]; this is a value written, not a reset value of the register ([U]) */
#define XIO_FC_REG_BANK_SELECT               0x2c       /* [E] byte; register-bank select, not a reset */
#define XIO_FC_BANK_CODE_STEP                0x11       /* [E] bank n is selected by writing n * 0x11: 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 are written as immediates; 0x66 and 0x77 only by the RAM test, which steps through all eight codes; whether the two nibbles select banks separately is [U] */
#define XIO_FC_REG_CLOCK_STATUS              0x63       /* [E] byte, read under bank 4: the link-speed routine masks the low two bits with 0xfc, ORs in 0x02 and requires 0xbe, 0x2e, 0xfe or 0x6e, otherwise configuration collection fails */
#define XIO_FC_CLOCK_STATUS_MASK             0xfc       /* [E] */
#define XIO_FC_CLOCK_STATUS_OR               0x02       /* [E] */
#define XIO_FC_CLOCK_STATUS_DIV_1            0xbe       /* [E] accepted result; divisor names [I] */
#define XIO_FC_CLOCK_STATUS_DIV_2_A          0x2e       /* [E] accepted result; divisor names [I] */
#define XIO_FC_CLOCK_STATUS_DIV_2_B          0xfe       /* [E] accepted result; divisor names [I] */
#define XIO_FC_CLOCK_STATUS_DIV_4            0x6e       /* [E] accepted result; divisor names [I] */
#define XIO_FC_REG_LINK_CONTROL              0xe1       /* [E] byte; written 0x20 then 0x40 under bank 3 by the initialiser, read under bank 2 by the error routine */
#define XIO_FC_LINK_CTRL_LOSS_OF_SIGNAL      0x01       /* [E] tested on the read, raises the loss-of-signal notice; name [I] */
#define XIO_FC_LINK_CTRL_LOSS_OF_SYNC        0x02       /* [E] tested on the read, raises the loss-of-synchronisation notice; name [I] */
#define XIO_FC_LINK_CTRL_LINK_RESET          0x20       /* [E] written first by the initialiser; name [I] */
#define XIO_FC_LINK_CTRL_LINK_ENABLE         0x40       /* [E] written second by the initialiser; name [I] */
#define XIO_FC_REG_SERDES_STATUS             0xeb       /* [E] byte, read under bank 1 */
#define XIO_FC_SERDES_FAULT                  0x10       /* [E] tested by the error routine, raises the media-fault notice; name [I] */
#define XIO_FC_SERDES_LOCK_NOT_IN_USE        0x08       /* [E] tested only when bit 0x10 of 0xea is set, raises the link-not-usable notice; name [I] */
#define XIO_FC_SERDES_MEDIA_SENSE_MASK       0x03       /* [E] the initialiser masks these two bits and stores them; that they sense the media module is [I] */

/* Layout offsets of the host-memory structures the chip fills or the driver reads, beyond the fields above. */
#define XIO_FC_RESP_PAYLOAD                  0x18       /* [I] response information, then sense data, from the standard response unit; [E] only that the completion routine reads the byte at 0x1b */
#define XIO_FC_RESP_RESIDUAL_INFO            0x80       /* [E] 16-byte adapter residual-info block, written by the chip little-endian and read as written */
#define XIO_FC_RESID_SG_PAGE_PTR             0x00       /* [E] offset in that block: 8-byte bus pointer to the current scatter-gather page */
#define XIO_FC_RESID_SEGMENT_RESIDUAL        0x08       /* [E] 3 bytes, low byte first; the byte count left in the current segment */
#define XIO_FC_RESID_SG_ELEMENT_INDEX        0x0c       /* [E] byte; the element index is the high nibble ([I] that it is an index) */

/* Link-service accept payloads (the reply the chip DMAs into the driver's buffer). The driver copies each whole, reads
 * only the first word (PLOGI) or byte (PRLI), the byte at offset 0x13 (PRLI) and, on a reject, bytes +5 and +6, so the field
 * layout below is the standard payload shape and its grade is [I], not what the driver parses. */
#define XIO_FC_PLOGI_ACC_CODE                0x00       /* [E] top byte 0x02 is accept, 0x01 is reject; the driver gates login on it */
#define XIO_FC_PLOGI_REJECT_REASON           0x05       /* [E] logged on a reject */
#define XIO_FC_PLOGI_REJECT_EXPLANATION      0x06       /* [E] logged on a reject */
#define XIO_FC_PLOGI_ACC_COMMON_PARAMS       0x04       /* [I] 16 bytes */
#define XIO_FC_PLOGI_ACC_PORT_NAME           0x14       /* [I] 8 bytes, target port name */
#define XIO_FC_PLOGI_ACC_NODE_NAME           0x1c       /* [I] 8 bytes, target node name */
#define XIO_FC_PLOGI_ACC_CLASS1_PARAMS       0x24       /* [I] 16 bytes */
#define XIO_FC_PLOGI_ACC_CLASS2_PARAMS       0x34       /* [I] 16 bytes */
#define XIO_FC_PLOGI_ACC_CLASS3_PARAMS       0x44       /* [I] 16 bytes */
#define XIO_FC_PLOGI_ACC_RESERVED            0x54       /* [I] 16 bytes */
#define XIO_FC_PLOGI_ACC_VENDOR_VERSION      0x64       /* [I] 16 bytes */
#define XIO_FC_PLOGI_ACC_LENGTH              0x74       /* [E] bytes copied (116) */
#define XIO_FC_PRLI_ACC_CODE                 0x00       /* [E] byte; 0x02 is accept, 0x01 is reject */
#define XIO_FC_PRLI_ACC_PAGE_LENGTH          0x01       /* [I] */
#define XIO_FC_PRLI_ACC_PAYLOAD_LENGTH       0x02       /* [I] 2 bytes */
#define XIO_FC_PRLI_ACC_TYPE                 0x04       /* [I] byte; 0x08 for the SCSI protocol */
#define XIO_FC_PRLI_ACC_FLAGS                0x06       /* [I] 2 bytes */
#define XIO_FC_PRLI_ACC_ORIGINATOR_ASSOC     0x08       /* [I] 4 bytes */
#define XIO_FC_PRLI_ACC_RESPONDER_ASSOC      0x0c       /* [I] 4 bytes */
#define XIO_FC_PRLI_ACC_SERVICE_BYTE         0x13       /* [E] byte; the driver requires 0x12 (target-function bit 0x10 plus 0x02), otherwise rejects the target; the bit meanings are [I] */
#define XIO_FC_PRLI_ACC_LENGTH               0x14       /* [E] bytes copied (20) */

#endif /* XIO_FC_H */
