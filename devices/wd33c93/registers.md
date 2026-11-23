<!-- generated from devices/wd33c93/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 9910f5661f6314c737e8fc59355fe020e6e1845f293604aa3a75852ecd0c3cb5 -->

# WD33C93/WD33C93A SCSI bus interface controller as wired on the Indigo (R3000 and R4000 boards)

The SCSI controller behind the Indigo's HPC1. The CPU reaches it through two byte ports in the HPC1 window: an address port, which on a read returns the auxiliary status register, and a data port. A write to the address port selects one of the chip's internal registers; each access to the data port reads or writes the selected register and then advances the selection by one, except for the data and command registers, which stay selected. The internal registers are described in the chip's own index space (offsets are the value written to the address port); the two ports are in two port spaces whose offsets are bytes from the HPC1 window base, physical 0x1fb80000, big-endian view. Names and layouts follow the Western Digital data sheet and the public NetBSD driver, with the IRIX driver's own names only where the page says so. Grades: established means read in full from the IRIX R4000 Indigo SCSI driver object, the 4.0.5D PROM or the data sheet; inferred means a reasoned reading; unknown means nothing shipped settles it. Reset values are from the data sheet, so they hold for the part. Nothing was measured on a board. The prose is in devices/wd33c93/README.md.

Unit `wd33c93`, macro prefix `WD33C93`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| wd33c93_index | byte | Internal register index: the value written to the address port. The index is not a bus address. |
| wd33c93_port_r | byte | Byte offsets from the HPC1 window base (physical 0x1fb80000), big-endian view, for the ports a CPU read reaches. Each port is one byte in the second most significant byte lane of a 4-byte word. |
| wd33c93_port_w | byte | Byte offsets from the HPC1 window base for the same two ports as seen by a CPU write. The address port and the auxiliary status register share one offset. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `own_id` | 0x0 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `control` | 0x1 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `timeout` | 0x2 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `cdb` | 0x3 | rw | 8 | 12 | wd33c93_index | 0x0 (established) | established |  |
| `target_lun` | 0xf | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `command_phase` | 0x10 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `sync_transfer` | 0x11 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `transfer_count` | 0x12 | rw | 8 | 3 | wd33c93_index | 0x0 (established) | established |  |
| `dest_id` | 0x15 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `source_id` | 0x16 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `scsi_status` | 0x17 | r | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `command` | 0x18 | rw | 8 |  | wd33c93_index | 0x0 (established) | established |  |
| `data` | 0x19 | rw | 8 |  | wd33c93_index | unknown | established |  |
| `queue_tag` | 0x1a | rw | 8 |  | wd33c93_index | unknown | inferred |  |
| `aux_status` | 0x122 | r | 8 |  | wd33c93_port_r | 0x80 (established) | established |  |
| `data_port` | 0x126 | rw | 8 |  | wd33c93_port_r | unknown | established |  |
| `address` | 0x122 | w | 8 |  | wd33c93_port_w | unknown | established |  |

### Register `own_id`

Own ID and CDB size. The bus ID in bits 2:0 and the configuration bits are sampled by the Reset command, so they take effect only after a reset. Both the PROM and IRIX write it before every Reset. In advanced mode, bits 3:0 hold the CDB length for a command group the chip does not know (the driver writes it from startwd93 only on parts that answered the reset with advanced features). Bit 5 is EIH on rev E/F A parts and RAF on the B. A qtest can discriminate: write 0 to 7 and read each back; the presence test needs all eight bits to read back.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `fs` | established |  |  | Frequency select. 0 divides the input clock by 2 (8-10 MHz), 1 by 3 (12-15 MHz), 2 by 4 (16-20 MHz). IRIX and the PROM write 2. |
| 5 | `eih_raf` | inferred |  |  | Enable immediate halt on rev E/F of the A part; enable really advanced features on the B. IRIX and the PROM set it with 0xa8, which with EAF is the NetBSD default for the same chips. |
| 4 | `ehp` | established |  |  | Enable host parity (PLCC package only). |
| 3 | `eaf` | established |  |  | Enable advanced features. Selects status 0x01 instead of 0x00 after Reset on A and B parts. |
| 2:0 | `id` | established |  |  |  |

### Register `control`

Control. Interrupt and DMA mode selection. IRIX and the PROM write 0x2d (burst DMA mode) once the chip has been reset and detected as a WD33C93A or B, and 0x8d (single-byte DMA mode) when the burst flag is clear or the chip answered the reset with status 0. A qtest can discriminate: reset clears it; write 0x2d and read it back.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:5 | `dma_mode` | established |  |  | 0 programmed I/O; 1 burst demand-mode DMA (the HPC1 channel); 2 WD bus mode; 4 single-byte DMA. IRIX uses 1, or 4 when its flag is clear. |
| 4 | `hhp` | established |  |  | Halt on host parity error. |
| 3 | `edi` | established |  |  | Ending disconnect interrupt. |
| 2 | `idi` | established |  |  | Intermediate disconnect interrupt: status 0x85 on a disconnect during Select-and-Transfer. |
| 1 | `ha` | established |  |  | Halt on ATN (target mode). |
| 0 | `hsp` | established |  |  | Halt on SCSI parity error. |

### Register `timeout`

Selection timeout. Zero disables the timeout. IRIX writes 0x40; the PROM writes 0x40 through a helper called at the end of its reset routine. During the hinv bus scan IRIX divides the value by 32 (rounded up) and later restores it, to shorten selects of missing targets. A qtest can discriminate: a Select to a target that is not present stays pending when this is zero, and ends with status 0x42 when it is not.

### Register `cdb`

CDB bytes 1 to 12 for Select-and-Transfer. The same offsets are total sectors, heads, cylinders, logical address and head and cylinder numbers for Translate Address. The 12 bytes are written with one address-port write of 3 and as many data-port writes as the CDB has bytes, using the auto-increment (IRIX stops at 12, rounding a 13+ byte count down). On a WD33C93B with RAF set, index 3 reads back a revision code after Reset (below). A qtest can discriminate: auto-increment and cdb1 reading zero after reset.

Array of 12 registers, stride 1.

### Register `target_lun`

Target LUN. The initiator writes the LUN for the Identify message; after Select-and-Transfer completes it holds the target's status byte (IRIX reads it on status 0x16 and stores it as the SCSI status). During reselection with advanced features it holds the Identify byte (TLV in bit 7, DOK in bit 6). IRIX reads it first in the interrupt handler and then reads the command phase register by letting the address auto-increment.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `tlv` | established |  |  | Identify message valid. |
| 6 | `dok` | established |  |  | Disconnect OK, from the reselecting target's Identify message. |
| 2:0 | `lun` | established |  |  |  |

### Register `command_phase`

Command phase: how far a Select-and-Transfer has progressed. The chip advances it as phases complete (CPH_ constants); the driver writes a value back and reissues Select-and-Transfer to resume. IRIX writes 0x00 to start, 0x41 after Save Data Pointers, 0x44 after reselection and 0x45 after the Identify message or a parity error. A qtest can discriminate: after Select-and-Transfer to a missing target it reads 0x00; to a present one 0x10 and up.

### Register `sync_transfer`

Synchronous transfer: offset in bits 3:0 (zero means asynchronous), period in bits 6:4 (0 is 8 clock cycles, 2 to 7 are that many cycles), bit 7 fast SCSI on the B. IRIX initialises the per-target copy to 0x20 (two cycles, offset zero, asynchronous) and loads the target's value before every command. The PROM reads it before the first reset and restores it afterwards (inferred: to keep a boot target's setting).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `fast` | inferred |  |  | WD33C93B only (E062-B item 1); IRIX never sets it. |
| 6:4 | `period` | established |  |  |  |
| 3:0 | `offset` | established |  |  |  |

### Register `transfer_count`

24-bit transfer count, most significant byte at index 12h, written with one address-port write of 12h and three data-port writes. IRIX writes zero for commands with no data phase and the HPC1-programmed length otherwise (at most 0xfffffc). After an interrupted transfer it holds the bytes not transferred (IRIX reads it back when it saves the data pointers). A qtest can discriminate: three-byte write through the auto-increment and read back.

Array of 3 registers, stride 1.

### Register `dest_id`

Destination ID: target to select or reselect, bits 2:0; bit 6 DPD gives the expected data direction in advanced mode (1 is device to host); bit 7 SCC and bit 5 DF are target-mode chaining controls. IRIX writes the target ID with bit 6 from the data direction (the command's 0x40 flag) at every command start. The PROM's first-time path reads it back and saves bits 2:0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `scc` | inferred |  |  | Select command chain; target mode only, never used by IRIX. |
| 6 | `dpd` | established |  |  |  |
| 5 | `df` | inferred |  |  | Data phase direction check disable, A rev E/F. |
| 2:0 | `id` | established |  |  |  |

### Register `source_id`

Source ID: ER (bit 7) enables reselection, ES (bit 6) selection, DSP (bit 5) ignores select parity; bit 3 SIV and bits 2:0 report who selected or reselected the chip. IRIX and the PROM write 0x80 after a reset when disconnect is enabled (the PROM's per-controller enable word is 1) and 0 otherwise. After a reselect IRIX reads this register and then the SCSI status register by auto-increment and uses bits 2:0 to find the channel.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `er` | established |  |  |  |
| 6 | `es` | inferred |  |  | Never set by IRIX. |
| 5 | `dsp` | inferred |  |  | Never set by IRIX. |
| 3 | `siv` | established |  |  |  |
| 2:0 | `id` | established |  |  |  |

### Register `scsi_status`

SCSI status: the cause of the last interrupt, high nibble the group (0 reset, 1 done, 2 paused, 4 terminated, 8 service) and low nibble the qualifier or phase. Reading it clears INT in the auxiliary status register and the chip's interrupt request; the chip will not change it until it is read. The driver must not issue a command within 7 microseconds of reading it, or the chip ignores the command and sets LCI. Values acted on by IRIX are the STATUS_ constants. A qtest can discriminate: after Reset read 0x00 or 0x01 depending on own_id.eaf, then INT is clear.

### Register `command`

Command: bits 6:0 the command code, bit 7 single-byte transfer. The register stays selected after a write (no auto-increment). It must not be written while CIP or INT is set. A command written while an interrupt is pending is ignored and sets LCI; the IRIX driver handles that in wd93cmd_lci by reading SCSI status and rewriting the command. A qtest can discriminate: a write with INT set must leave LCI set and not start the command.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `sbt` | established |  |  |  |
| 6:0 | `code` | established |  |  |  |

### Register `data`

Data register: the host side of the 12-byte FIFO. IRIX uses it in programmed-I/O message and inquiry phases, polling the DBR bit of the auxiliary status register, and never for bulk data. The register stays selected after an access. In the HPC1 burst mode the DMA channel moves bulk data through the same register without CPU involvement.

### Register `queue_tag`

Queue tag, WD33C93B only. IRIX never touches it. NetBSD writes 0x55 here and reads it back after a reset that returned status 0x01: if it reads 0x55 the part is a B, otherwise an A. On an A part the register does not exist and the read returns all ones (data sheet note 2 to the register map). A qtest can discriminate: the write sticks only on a model configured as a B.

### Register `aux_status`

Auxiliary status. Bit 7 INT is the interrupt-request pin: it stays set until the SCSI status register is read. Bit 6 LCI says a command was written while an interrupt was pending or the chip was busy decoding the last command, and the command was ignored. Bit 5 BSY is set while a level II command runs. Bit 4 CIP is set while the chip decodes a command; the command register may not be written while it is set. Bit 1 PE is a parity error, cleared when a new command is issued. Bit 0 DBR is data-buffer-ready for programmed data-register transfers. Both IRIX and the PROM poll bit 4 clear before every command and bit 7 for interrupts. A qtest can discriminate: after a hard reset read 0x80; after a Reset command and before the status read INT stays set; reading scsi_status clears bit 7.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `int` | established |  |  |  |
| 6 | `lci` | established |  |  |  |
| 5 | `bsy` | established |  |  |  |
| 4 | `cip` | established |  |  |  |
| 1 | `pe` | established |  |  |  |
| 0 | `dbr` | established |  |  |  |

### Register `data_port`

Data port. Reads and writes the internal register selected through the address port. Every IRIX and PROM access is a byte access. A qtest can discriminate: write own_id then read it back (the controller presence test, below).

### Register `address`

Address port. A byte written here selects the internal register the next data-port access uses. No shipped code reads it back (a read returns the auxiliary status register). The index auto-increments after every data-port access except when the selected register is the data register or the command register. A qtest can discriminate: write 0x03, write three bytes to the data port, and read cdb1 to cdb3 back by writing 0x03 once and reading the data port three times.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CMD_ABORT` | 0x1 | inferred |  | Abort. Used by the IRIX driver on timeouts (passed through the driver's last-command-ignored retry routine); the call site's constant is the delay-slot argument, so the read is inferred. |
| `CMD_ASSERT_ATN` | 0x2 | inferred |  | Assert ATN, initiator. Passed to the retry routine in the extended-message handler. |
| `CMD_DISCONNECT` | 0x4 | established |  | Disconnect. Written by the interrupt handler after an unexpected bus-free status, and passed to the retry routine by the abort and inquiry paths. |
| `CMD_NEGATE_ACK` | 0x3 | inferred |  | Negate ACK, initiator. The driver passes it after message-in handling. |
| `CMD_RESELECT` | 0x5 | inferred |  | Reselect, target role. Not used by an initiator-only driver. |
| `CMD_RESET` | 0x0 | established |  | Reset command. Levels I. The IRIX driver and the PROM write it to the command register to start the chip with the own-ID register's configuration. |
| `CMD_SBT` | 0x80 | established |  | Single-byte-transfer qualifier ORed into the command code (data sheet 6.2.20); the driver uses 0xa0. |
| `CMD_SELECT` | 0x7 | inferred |  | Select-without-ATN. Defined by the part; no shipped Indigo code was seen issuing it. |
| `CMD_SELECT_ATN` | 0x6 | established |  | Select-with-ATN. The PROM and IRIX use it for the device probe: the chip must answer status 0x11 (selected) and then 0x8e (message-out requested). |
| `CMD_SELECT_ATN_XFER` | 0x8 | established |  | Select-with-ATN-and-Transfer, the combination command the IRIX driver and the PROM use for every normal SCSI command. |
| `CMD_SELECT_XFER` | 0x9 | inferred |  | Select-without-ATN-and-Transfer. Defined by the part; not seen issued. |
| `CMD_TRANSFER_INFO` | 0x20 | established |  | Transfer Info, initiator, level II. The driver also issues it with the single-byte-transfer bit set (0xa0) to accept one message byte. |
| `CMD_TRANSLATE` | 0x18 | inferred |  | Translate Address (disk geometry). Defined by the part; not seen issued. |
| `CONTROL_IRIX_BURST` | 0x2d | established |  | Control register value the IRIX driver (when its burst flag is set, which wd93_init sets) and the PROM (when its flag, set during SCSI init, is set) write after reset: burst-mode DMA, EDI, IDI, halt on SCSI parity error. |
| `CONTROL_IRIX_SINGLE` | 0x8d | established |  | Control register value written when the burst flag is clear: single-byte DMA mode instead of burst, same other bits. Also the value the driver writes on a part that answered the reset with status 0. |
| `CPH_CMD_COMPLETE` | 0x60 | established |  | Command Complete message received. |
| `CPH_CMD_START` | 0x30 | established |  | Command phase started; 0x30 + n after n bytes. |
| `CPH_DATA_DONE` | 0x46 | established |  | Data phase complete (transfer count reached zero). |
| `CPH_DISCONNECTED` | 0x43 | established |  | Target has disconnected. |
| `CPH_DISCONNECT_MSG` | 0x42 | established |  | Disconnect message received, bus not free. |
| `CPH_IDENTIFY_IN` | 0x45 | established |  | Identify message received from the reselecting target. The driver writes it back to resume data transfer and after a parity error. |
| `CPH_IDENTIFY_SENT` | 0x20 | established |  | Identify message sent. |
| `CPH_RESELECTED` | 0x44 | established |  | Reselected by the original target. The driver writes it back to resume after reselection. |
| `CPH_SAVE_DP` | 0x41 | established |  | Save data pointers received. The driver writes it back to resume after a save-data-pointers interrupt. |
| `CPH_SELECTED` | 0x10 | established |  | Command phase after selection (data sheet 6.2.14). |
| `CPH_STATUS_DONE` | 0x50 | established |  | Status byte received into the target LUN register. |
| `CPH_STATUS_PHASE` | 0x47 | established |  | Status phase started. |
| `OWNID_IRIX_AF` | 0xa8 | established |  | Own-ID base value the PROM and the IRIX driver write before a Reset command when they want advanced features: frequency select 2 (divisor 4, 16 to 20 MHz clock), bit 5 and EAF. The host ID (0 to 7) is ORed in. |
| `OWNID_IRIX_PLAIN` | 0x80 | established |  | Own-ID base value without advanced features, written when the caller asks for a plain reset. |
| `PHASE_COMMAND` | 0x2 | established |  | MCI field 010: command. |
| `PHASE_DATA_IN` | 0x1 | established |  | MCI field 001: data in. |
| `PHASE_DATA_OUT` | 0x0 | established |  | MCI field 000: data out. |
| `PHASE_MSG_IN` | 0x7 | established |  | MCI field 111: message in. |
| `PHASE_MSG_OUT` | 0x6 | established |  | MCI field 110: message out. |
| `PHASE_STATUS` | 0x3 | established |  | MCI field 011: status. |
| `SOURCEID_ENABLE_RESEL` | 0x80 | established |  | Source ID register value that enables reselection, written when disconnect is enabled. |
| `STATUS_BAD_CMD` | 0x40 | inferred |  | Invalid command. |
| `STATUS_BAD_STATUS` | 0x47 | established |  | Bad status byte during Select-and-Transfer. The handler resumes the transfer. |
| `STATUS_DISCONNECT` | 0x85 | established |  | Disconnect with intermediate-disconnect interrupt enabled (control IDI). |
| `STATUS_MSGIN_PAUSED` | 0x20 | inferred |  | Transfer Info paused with ACK asserted for a message-in byte. |
| `STATUS_PARITY` | 0x43 | established |  | Parity error, ATN not asserted. The handler resumes with command phase 0x45. |
| `STATUS_PARITY_ATN` | 0x44 | established |  | Parity error with ATN asserted. Same handler as 0x43. |
| `STATUS_REQ_MSGIN` | 0x8f | established |  | Service required, REQ asserted with message-in phase. |
| `STATUS_REQ_MSGOUT` | 0x8e | established |  | Service required, REQ asserted with message-out phase. The device probe waits for it after status 0x11. |
| `STATUS_RESELECT` | 0x80 | established |  | Reselected, no Identify message transferred yet (advanced features off). |
| `STATUS_RESELECT_AF` | 0x81 | established |  | Reselected with advanced features on; source ID register holds the target ID and the data register holds the Identify message. |
| `STATUS_RESET` | 0x0 | established |  | Reset command completed on a part without advanced features, or hardware reset. Data sheet 6.2.19; the PROM and driver accept it and treat the chip as a plain WD33C93. |
| `STATUS_RESET_AF` | 0x1 | established |  | Reset command completed with advanced features enabled (own-ID EAF set): the part is a WD33C93A or WD33C93B. This is the reset-complete status the PROM and the driver look for. |
| `STATUS_SAT_DONE` | 0x16 | established |  | Select-and-Transfer completed. The target status byte is then in the target LUN register. |
| `STATUS_SAVE_DP` | 0x21 | established |  | Save data pointers message received during Select-and-Transfer; the handler saves the pointers and resumes with command phase 0x41. |
| `STATUS_SELECT_DONE` | 0x11 | established |  | Select command completed, now connected as initiator. The PROM's and driver's device probe expects it. |
| `STATUS_SEL_TIMEOUT` | 0x42 | established |  | Selection timed out. The handler retries or fails the command. |
| `STATUS_UNEXP_DISC` | 0x41 | established |  | Unexpected disconnect (bus free). The handler issues Disconnect and releases the channel. |
| `STATUS_UNEXP_PHASE` | 0x48 | established |  | Base of the unexpected-information-phase family 0x48 to 0x4f; the low three bits are the requested phase. The handler decodes the family with a bit test, and treats 0x4f (message-in) separately. |
| `STATUS_XFER_DONE` | 0x18 | established |  | Transfer Info completed; the low three bits give the next bus phase (MCI). |
| `TIMEOUT_IRIX` | 0x40 | established |  | Selection timeout period the IRIX driver and the PROM write (the PROM through a helper called at the end of its reset routine; the helper writes 0x08 instead when its flag argument is nonzero). With a 20 MHz clock the data sheet formula gives 64 * 80 / 20 = 256 ms. |
