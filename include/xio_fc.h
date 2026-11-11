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

#endif /* XIO_FC_H */
