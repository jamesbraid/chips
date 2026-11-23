<!-- generated from devices/xio_fc/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 57e8737a3343b26b5b9baa63badf937ee000b92384357355a269d98dd44823d0 -->

# XIO Fibre Channel adapter (Adaptec AIC-1160 board), command and register contract

Unit `xio_fc`, macro prefix `XIO_FC`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BANK_CODE_STEP` | 0x11 | established |  | bank n is selected by writing n * 0x11: 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 are written as immediates; 0x66 and 0x77 only by the RAM test, which steps through all eight codes; whether the two nibbles select banks separately is [U] |
| `CLOCK_STATUS_DIV_1` | 0xbe | established |  | accepted result; divisor names [I] |
| `CLOCK_STATUS_DIV_2_A` | 0x2e | established |  | accepted result; divisor names [I] |
| `CLOCK_STATUS_DIV_2_B` | 0xfe | established |  | accepted result; divisor names [I] |
| `CLOCK_STATUS_DIV_4` | 0x6e | established |  | accepted result; divisor names [I] |
| `CLOCK_STATUS_MASK` | 0xfc | established |  |  |
| `CLOCK_STATUS_OR` | 0x2 | established |  |  |
| `DONE_HANDLE` | 0x0 | established |  | 2 bytes LE; completed TCB handle, the tag written at XIO_FC_TCB_OX_ID |
| `DONE_PASS` | 0x3 | established |  | byte; initialised to 0xff; the chip writes the ring-lap number modulo 256 and the driver consumes while it equals the expected value |
| `DONE_STATUS` | 0x2 | established |  | byte; completion status code (normal-command meanings: 0 success, 1 overrun, 2 underrun, 3 TCB parity error, 4 error response, 5 out of order, 6 frame format, 7 count overflow, 8 undelivered, 9 and 0xa bad delimiter, 0xb aborted, 0xf primitive timeout [E]; a loop-init completion reuses some values, and a successful one returns the negotiated loop address) |
| `HOST_CTRL_MASTER_IRQ_EN` | 0x4 | established |  | set and cleared by the interrupt enable and disable routines; name [I] |
| `HOST_CTRL_PAUSE` | 0x40 | established |  | set to pause the sequencer, polled for the acknowledge |
| `HOST_CTRL_PAUSE_AT_TOP` | 0x80 | established |  | set to pause at the top of the program, polled for the acknowledge; unpause clears 0xc0 |
| `HOST_CTRL_RESET_WRITE` | 0x43 | established |  | the value the error-recovery reset writes after a pause (pause plus 0x02 plus 0x01); the effect of the two low bits is [I]; this is a value written, not a reset value of the register ([U]) |
| `INT_BREAKPOINT` | 0x200 | inferred |  | register 0x25 bit 1: named by the sheet's register map; neither interrupt routine tests it on its own |
| `INT_HARDWARE_ERROR` | 0x4000 | established |  | register 0x25 bit 6: the routine reads and latches the error-status register at 0x23 |
| `INT_HOST_COMPLETION` | 0x400 | inferred |  | register 0x25 bit 2: named by the sheet's register map; neither interrupt routine tests it on its own, and the driver does not depend on it |
| `INT_LOOP_ATTENTION` | 0x8 | established |  | register 0x24 bit 3: the back-end routine then selects bank 1 and reads the loop-state register at 0xa1 |
| `INT_PCI_ERROR` | 0x8000 | established |  | register 0x25 bit 7 |
| `INT_SEQ_COMPLETION` | 0x1000 | established |  | register 0x25 bit 4: the done-queue completion bit; the driver drains the queue by scanning pass bytes regardless of this bit. Whether the per-source enable at 0x99 bit 4 is needed is [U] |
| `INT_SEQ_READY_FOR_LIP` | 0x100 | established |  | register 0x25 bit 0: tested by the back-end routine on its saved copy of the status byte; set means the sequencer has run loop initialisation far enough for the host to post its loop-initialisation command block, and the routine then pauses the sequencer. Name [I] |
| `INT_SOFTWARE_ERROR` | 0x2000 | established |  | register 0x25 bit 5 |
| `LINK_CTRL_LINK_ENABLE` | 0x40 | established |  | written second by the initialiser; name [I] |
| `LINK_CTRL_LINK_RESET` | 0x20 | established |  | written first by the initialiser; name [I] |
| `LINK_CTRL_LOSS_OF_SIGNAL` | 0x1 | established |  | tested on the read, raises the loss-of-signal notice; name [I] |
| `LINK_CTRL_LOSS_OF_SYNC` | 0x2 | established |  | tested on the read, raises the loss-of-synchronisation notice; name [I] |
| `PLOGI_ACC_CLASS1_PARAMS` | 0x24 | inferred |  | 16 bytes |
| `PLOGI_ACC_CLASS2_PARAMS` | 0x34 | inferred |  | 16 bytes |
| `PLOGI_ACC_CLASS3_PARAMS` | 0x44 | inferred |  | 16 bytes |
| `PLOGI_ACC_CODE` | 0x0 | established |  | top byte 0x02 is accept, 0x01 is reject; the driver gates login on it |
| `PLOGI_ACC_COMMON_PARAMS` | 0x4 | inferred |  | 16 bytes |
| `PLOGI_ACC_LENGTH` | 0x74 | established |  | bytes copied (116) |
| `PLOGI_ACC_NODE_NAME` | 0x1c | inferred |  | 8 bytes, target node name |
| `PLOGI_ACC_PORT_NAME` | 0x14 | inferred |  | 8 bytes, target port name |
| `PLOGI_ACC_RESERVED` | 0x54 | inferred |  | 16 bytes |
| `PLOGI_ACC_VENDOR_VERSION` | 0x64 | inferred |  | 16 bytes |
| `PLOGI_REJECT_EXPLANATION` | 0x6 | established |  | logged on a reject |
| `PLOGI_REJECT_REASON` | 0x5 | established |  | logged on a reject |
| `PRLI_ACC_CODE` | 0x0 | established |  | byte; 0x02 is accept, 0x01 is reject |
| `PRLI_ACC_FLAGS` | 0x6 | inferred |  | 2 bytes |
| `PRLI_ACC_LENGTH` | 0x14 | established |  | bytes copied (20) |
| `PRLI_ACC_ORIGINATOR_ASSOC` | 0x8 | inferred |  | 4 bytes |
| `PRLI_ACC_PAGE_LENGTH` | 0x1 | inferred |  |  |
| `PRLI_ACC_PAYLOAD_LENGTH` | 0x2 | inferred |  | 2 bytes |
| `PRLI_ACC_RESPONDER_ASSOC` | 0xc | inferred |  | 4 bytes |
| `PRLI_ACC_SERVICE_BYTE` | 0x13 | established |  | byte; the driver requires 0x12 (target-function bit 0x10 plus 0x02), otherwise rejects the target; the bit meanings are [I] |
| `PRLI_ACC_TYPE` | 0x4 | inferred |  | byte; 0x08 for the SCSI protocol |
| `REG_BANK_SELECT` | 0x2c | established |  | byte; register-bank select, not a reset |
| `REG_CLOCK_STATUS` | 0x63 | established |  | byte, read under bank 4: the link-speed routine masks the low two bits with 0xfc, ORs in 0x02 and requires 0xbe, 0x2e, 0xfe or 0x6e, otherwise configuration collection fails |
| `REG_HOST_CONTROL` | 0x22 | established |  | byte; host control |
| `REG_LINK_CONTROL` | 0xe1 | established |  | byte; written 0x20 then 0x40 under bank 3 by the initialiser, read under bank 2 by the error routine |
| `REG_SEQ_CONTROL` | 0x0 | established |  | byte; sequencer control |
| `REG_SERDES_STATUS` | 0xeb | established |  | byte, read under bank 1 |
| `RESID_SEGMENT_RESIDUAL` | 0x8 | established |  | 3 bytes, low byte first; the byte count left in the current segment |
| `RESID_SG_ELEMENT_INDEX` | 0xc | established |  | byte; the element index is the high nibble ([I] that it is an index) |
| `RESID_SG_PAGE_PTR` | 0x0 | established |  | offset in that block: 8-byte bus pointer to the current scatter-gather page |
| `RESP_FCP_STATUS_FLAGS` | 0xa | established |  | byte; bits 0x01 response-length valid, 0x02 sense-length valid, 0x04 residual overrun, 0x08 residual underrun (each tested by a single-bit branch); the names follow the FC-4 SCSI profile [I] |
| `RESP_PAYLOAD` | 0x18 | inferred |  | response information, then sense data, from the standard response unit; [E] only that the completion routine reads the byte at 0x1b |
| `RESP_RESIDUAL` | 0xc | established |  | 4 bytes big-endian (read as an unaligned word pair); the command residual on underrun, reported as a length mismatch on overrun |
| `RESP_RESIDUAL_INFO` | 0x80 | established |  | 16-byte adapter residual-info block, written by the chip little-endian and read as written |
| `RESP_RESPONSE_LEN` | 0x14 | established |  | 4 bytes big-endian, read as an unaligned word pair |
| `RESP_SCSI_STATUS` | 0xb | established |  | byte; passed up as the command's SCSI status; 0x28 (queue full) is compared and handled apart |
| `RESP_SENSE_LEN` | 0x10 | established |  | 4 bytes big-endian, read as an unaligned word pair |
| `SEQ_CTRL_RAM_LOAD` | 0x1 | established |  | written alone before the microcode image is streamed in |
| `SEQ_CTRL_RESET_PC` | 0x2 | inferred |  | reset the sequencer program counter; seen only inside the 0x42 write |
| `SEQ_CTRL_RUN` | 0x40 | established |  | written after the image is verified, to run the sequencer |
| `SEQ_CTRL_START` | 0x42 | established |  | run plus reset, written after the mainline image is loaded to start it from the top |
| `SERDES_FAULT` | 0x10 | established |  | tested by the error routine, raises the media-fault notice; name [I] |
| `SERDES_LOCK_NOT_IN_USE` | 0x8 | established |  | tested only when bit 0x10 of 0xea is set, raises the link-not-usable notice; name [I] |
| `SERDES_MEDIA_SENSE_MASK` | 0x3 | established |  | the initialiser masks these two bits and stores them; that they sense the media module is [I] |
| `TCB_CONTROL` | 0x21 | established |  | command-type discriminator: 0x00 read or no-data command, 0x01 unsolicited-receive buffer, 0x02 write, 0x0a link-service request/reply; roles [I] from the builders |
| `TCB_DATA_LEN` | 0x60 | established |  | 4 bytes LE; copy of the transfer length |
| `TCB_DATA_PTR` | 0x4c | established |  | 8 bytes LE; bus address of the single buffer (mode 0x08) or of the scatter-gather list (mode 0x0b) |
| `TCB_DELIMITER` | 0x9 | established |  | byte written 0x05, class-3 normal [I] |
| `TCB_DESC_MODE` | 0x23 | established |  | data-descriptor mode set by the data mapper: 0x08 one direct buffer, 0x0b scatter-gather list, 0x0c no data |
| `TCB_D_ID` | 0x4 | established |  | 3 bytes; on a loop the byte at 0x04 is the target loop address, looked up from a fixed target-id table; the source ID is absent |
| `TCB_FCP_CDB` | 0x30 | established |  | 16 bytes copied from the request; confirmed at 0x30 on the three machine builds |
| `TCB_FCP_CNTL` | 0x2c | established |  | only the byte at 0x2f is written: 0x02 read, 0x01 write; the rest of FCP_CNTL [I] |
| `TCB_FCP_DL` | 0x40 | established |  | 4 bytes big-endian, FC network order (the builder uses unaligned word stores) |
| `TCB_FCP_LUN` | 0x24 | established |  | that the request's LUN bytes land here (8 bytes, FC order); full 8-byte form [I] |
| `TCB_F_CTL0` | 0x10 | established |  | byte written 0x08 by the normal builder (re-read); name [I] |
| `TCB_F_CTL1` | 0x11 | inferred |  | name by frame-header layout; the normal builder does not store here ([U] value); the link-service builders store a 4-byte big-endian word at 0x10 to 0x13 [E that it is written] |
| `TCB_F_CTL2` | 0xe | established |  | byte written 0x29 for a SCSI command |
| `TCB_HANDLE_COPY` | 0x68 | established |  | 2 bytes LE written; the TCB handle repeated, chip use [I] |
| `TCB_LOOP_FLAGS` | 0x1c | established |  | byte: 0x18 when the host-unfair tunable is set, else 0x40; meaning (open half-duplex, with and without fair arbitration) [I] |
| `TCB_NEXT` | 0x44 | established |  | 8 bytes LE, PCI bus address of the next slot of the driver's circular TCB queue; [I] that the chip uses it as a chain link |
| `TCB_OX_ID` | 0x0 | established |  | 2 bytes LE; the command tag, written again at 0x68 and echoed in the done-queue entry |
| `TCB_RESP_PTR` | 0x58 | established |  | 8 bytes LE; bus address of the 256-byte response and sense buffer |
| `TCB_RX_ID` | 0x2 | established |  | 2 bytes; 0xffff (unassigned) on an outbound command |
| `TCB_R_CTL` | 0x7 | established |  | byte written: 0x01 for a SCSI command, 0x22 for a link-service request, 0x23 for its reply; [I] that this is a chip encoding rather than the wire value (the wire value of a command is 0x06) |
| `TCB_SEQ_CNT` | 0x14 | inferred |  | sequence count, 2 bytes at 0x14 to 0x15, by frame-header layout; no store seen |
| `TCB_SEQ_ID` | 0x13 | inferred |  | sequence ID by frame-header layout; no store from the normal builder (re-read), reached only by the link-service word at 0x10 |
| `TCB_TYPE` | 0xf | established |  | byte written 0x08 for a SCSI command; 0x01 for a link-service request [E written, I as FC-4 type] |
| `TCB_UNKNOWN_64` | 0x64 | established |  | byte written 0x14 by the normal builder (re-read); role [U]: settle by reading the sequencer microcode's use of this byte, or a capture of a completed command block |
| `TCB_XFER_LEN` | 0x54 | established |  | 4 bytes LE byte count for a single buffer; zero in list mode (the list ends on a flag in its last descriptor) |
