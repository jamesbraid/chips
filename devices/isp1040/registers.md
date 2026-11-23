<!-- generated from devices/isp1040/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 c6f60bd0ad553be96496d3d404604374c4fbab53c331492226b573abf3d0d9b4 -->

# QLogic ISP1040 family SCSI host adapter (PCI 1077:1020), register and mailbox contract

The single-channel QLogic SCSI host adapter on the BaseIO and BaseIO-G boards (PCI 1077:1020), as the public drivers use it. Grades say how each item was derived: established means the public driver file or the published standard states it, and inferred means agreeing driver code, a driver's own default, or a reading of the drivers' use of a value. No QLogic programming manual for this part is held here, so the register contract rests on driver agreement, and the reset state of every register is unknown unless a row says otherwise. The bus-reset and selection timing values are the driver's requests, not measured chip behaviour.

Unit `isp1040`, macro prefix `ISP1040`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `id_l` | 0x0 | r | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout |
| `id_h` | 0x2 | r | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout |
| `cfg_0` | 0x4 | r | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout; qla1280 driver hardware revision test |
| `cfg_1` | 0x6 | rw | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout |
| `ictrl` | 0x8 | rw | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout and its use in qla1280 driver |
| `istatus` | 0xa | r | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout |
| `semaphore` | 0xc | rw | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout |
| `nvram` | 0xe | rw | 16 |  |  | unknown | established | Linux qla1280 driver header device register layout |
| `flash_data` | 0x10 | rw | 16 |  |  | unknown | inferred | Linux qla1280 driver header and OpenBSD qlw driver header, both naming the flash data word |
| `flash_address` | 0x12 | rw | 16 |  |  | unknown | inferred | Linux qla1280 driver header and OpenBSD qlw driver header, both naming the flash address word |
| `mailbox` | 0x70 | rw | 16 | 8 |  | unknown | established | Linux qla1280 driver header device register layout (mailbox 0 at 0x70); OpenBSD QLW_MBOX_BASE_PCI |

### Register `id_l`

Low half of the identity word. The reset value is not stated by any source.

### Register `id_h`

High half of the identity word. The reset value is not stated by any source.

### Register `cfg_0`

Configuration 0. Its low four bits hold the hardware revision. Linux compares that revision with the 1040A value only, to decide whether to set the FIFO threshold. Linux does not use it to name the part.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `hw_revision` | established |  | Linux qla1280 driver header device register layout; qla1280 driver hardware revision test | Hardware revision mask; Linux compares it with the 1040A value |

### Register `cfg_1`

Configuration 1: FIFO threshold and bus burst enable, written by the drivers at start-up.

### Register `ictrl`

Bus interface control. It holds the soft reset bit, the interrupt enables and the flash BIOS controls.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9 | `flash_upper` | inferred |  | Linux qla1280 driver header device register layout and its use in qla1280 driver | Upper flash bank select. Named by Linux only |
| 8 | `flash_enable` | inferred |  | Linux qla1280 driver header device register layout and its use in qla1280 driver | Flash BIOS read and write enable. Named by Linux only |
| 2 | `risc_int_enable` | inferred |  | Linux qla1280 driver header device register layout and its use in qla1280 driver | RISC interrupt enable. Linux sets it with the interrupt enable |
| 1 | `int_enable` | inferred |  | Linux qla1280 driver header device register layout and its use in qla1280 driver | Interrupt enable. Linux sets it at start-up |
| 0 | `soft_reset` | inferred |  | Linux qla1280 driver header device register layout and its use in qla1280 driver | Soft reset of the adapter. Linux sets it and then polls until it reads clear |

### Register `istatus`

Interface status. Its bit meanings are not described here; the reset value is unknown.

### Register `semaphore`

Semaphore register. Linux names it; its use is not described here.

### Register `nvram`

Serial NVRAM interface register. Linux names its clock, select, data-out and data-in bits.

### Register `flash_data`

Flash BIOS data. Linux and OpenBSD both name it for this part. The NetBSD driver assigns the same offset to request-queue pointers for a later chip generation, so the naming rests on two drivers and is not confirmed by a manual.

### Register `flash_address`

Flash BIOS address. The same naming and the same two-driver footing as the flash data word.

### Register `mailbox`

Eight 16-bit mailbox registers, mailboxes 0 to 7 at 0x70 to 0x7e. Mailbox 0 carries the opcode of each command. The other mailboxes carry its operands and results, and their meaning is given per opcode below.

Array of 8 registers, stride 2.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ASYNC_BUS_RESET` | 0x8001 | established | Linux qla1280 driver header MBA_BUS_RESET and qla1280 driver; NetBSD isp driver header ASYNC_BUS_RESET | Asynchronous event: a bus reset. Linux reads the bus number from bit 0 of mailbox 6. The event shows that a reset happened; whether the firmware posts it for a reset the host itself requested is unknown. |
| `BUSES` | 0x1 | inferred | OpenBSD qlw PCI attach sets one bus for each ISP1040 revision | SCSI channels per chip. The ISP1040 has one; the two-channel part is a different chip. |
| `DRIVER_SELECTION_TIMEOUT_DEFAULT` | 0xfa | inferred | Linux qla1280 driver nvram defaults; NetBSD isp driver defaults; OpenBSD qlw driver defaults | The value every driver uses when the NVRAM is not valid, and programs with the selection-timeout command. It is the driver's own default, not a chip default: no source states what the chip uses when it is never programmed. |
| `OP_BUS_RESET` | 0x18 | established | Linux qla1280 driver header MBC_BUS_RESET; NetBSD isp driver header MBOX_BUS_RESET; OpenBSD qlw driver header QLW_MBOX_BUS_RESET | Reset one SCSI bus. Mailbox 1 carries a delay and mailbox 2 the bus number. The delay's unit is inferred to be seconds: Linux sleeps for that many seconds after the command completes, and OpenBSD delays for the same count. NetBSD raises any value below 2 to 2. Whether the firmware starts no SCSI activity on that bus for the delay is inferred from the Linux and OpenBSD drivers waiting it out before they issue commands; no firmware document states it. |
| `OP_DUMP_RAM_64` | 0xa | inferred | Linux qla1280 driver header MBC_DUMP_RAM_A64_ROM; qla1280 driver selects it for 64-bit DMA builds | Dump RAM with 64-bit DMA addresses. The pair of the 64-bit load opcode above. |
| `OP_GET_TARGET_PARAMS` | 0x28 | established | Linux qla1280 driver header MBC_GET_TARGET_PARAMETERS and qla1280 driver; NetBSD mailbox table mask 0x03 in and 0x4f out; OpenBSD qlw driver | Read a target's negotiated transfer parameters. Mailbox 1 names the target: Linux puts the target in the high byte and sets bit 7 for bus 1. The results come back in mailboxes 0 to 3 and 6, by NetBSD's output mask. Which field each of those mailboxes carries is inferred from the set-target-parameters layout, not stated by a driver. |
| `OP_LOAD_RAM_64` | 0x9 | inferred | Linux qla1280 driver header MBC_LOAD_RAM_A64_ROM; qla1280 driver selects it for 64-bit DMA builds | Load RAM with 64-bit DMA addresses. Linux picks this opcode, not the 32-bit load, when its build uses 64-bit DMA addresses. |
| `OP_SET_RESET_DELAY_PARAMS` | 0x3a | established | Linux qla1280 driver header MBC_SET_RESET_DELAY_PARAMETERS; NetBSD isp driver header MBOX_SET_RESET_DELAY_PARAMS; NetBSD mailbox table mask 0x07 | Set the SCSI bus-reset delay parameters as a configuration write. Its operand layout is not stated by any source here; the entry is named so that a host sending it is recognised. |
| `OP_SET_RETRY_COUNT` | 0x32 | established | Linux qla1280 driver header MBC_SET_RETRY_COUNT and qla1280 driver; NetBSD mailbox table mask 0xc7 | Set the selection retry count and delay. Mailbox 1 is the count and mailbox 2 the delay for bus 0; mailboxes 6 and 7 carry the same pair for bus 1. Whether the firmware retries a failed selection itself, and how many attempts a count gives, is unknown; NetBSD sets the count to zero because it wants selection failures reported at once, which implies that a non-zero count makes the firmware retry on its own. |
| `OP_SET_SELECTION_TIMEOUT` | 0x31 | established | Linux qla1280 driver header MBC_SET_SELECTION_TIMEOUT and qla1280 driver; NetBSD mailbox table mask 0x07; OpenBSD qlw driver | Set the selection timeout. Mailbox 1 carries bus 0's value and mailbox 2 bus 1's value. A one-bus part uses only mailbox 1; the drivers leave mailbox 2 unspecified then, so a guest must not read it back as a bus-1 value. The unit is not stated by any driver. Inferred milliseconds: the drivers' default, 250, is the SCSI-2 recommended selection time-out, and the SCSI-2 row below uses the same unit. |
| `OP_SET_TARGET_PARAMS` | 0x38 | established | Linux qla1280 driver header MBC_SET_TARGET_PARAMETERS; NetBSD isp driver header MBOX_SET_TARGET_PARAMS; NetBSD mailbox table mask 0x4f | Set a target's transfer parameters. Named here because the read-back opcode uses the same layout. The field meanings are not repeated in this unit. |
| `PCI_REV_1040` | 0x2 | inferred | OpenBSD qlw PCI attach revision table | PCI revision ID that OpenBSD maps to the plain ISP1040 (read with PCI_REVISION of the class word). OpenBSD sets the clock to 60 MHz for revision two and above. |
| `PCI_REV_1040A` | 0x3 | inferred | OpenBSD qlw PCI attach revision table | PCI revision ID that OpenBSD maps to the ISP1040A. OpenBSD clears the FIFO setting on this part, which it calls busted. |
| `PCI_REV_1040B` | 0x4 | inferred | OpenBSD qlw PCI attach revision table | PCI revision ID that OpenBSD maps to the ISP1040B. |
| `PCI_REV_1040C` | 0x5 | inferred | OpenBSD qlw PCI attach revision table, which also maps every higher value to the 1040C | PCI revision ID that OpenBSD maps to the ISP1040C. OpenBSD's table is the only source here for this mapping. The revision-two label on SGI inventory output names a letter and version, not this byte: if OpenBSD's table is right, that label cannot be the PCI revision, since revision two maps to the plain ISP1040 there. |
| `SCSI2_SELECTION_ABORT_US` | 0xc8 | established |  | SCSI-2 selection abort time, in microseconds: the maximum time a target or initiator takes from being selected to asserting BSY, so that it does not assert BSY after a selection was aborted. This is not the selection time-out. |
| `SCSI2_SELECTION_TIMEOUT_MS` | 0xfa | established |  | SCSI-2 recommended selection time-out delay: how long a device should wait for a BSY response before starting its time-out procedure. The standard calls this a recommended period, not a requirement. The drivers' 250 default matches this value. |
| `STATE_GOT_BUS` | 0x100 | established | Linux qla1280 driver header SF_GOT_BUS; NetBSD isp driver header RQSF_GOT_BUS; OpenBSD qlw driver header QLW_STATE_GOT_BUS | State flag: the command reached the bus. |
| `STATE_GOT_SENSE` | 0x2000 | inferred | Linux qla1280 driver header SF_GOT_SENSE; NetBSD isp driver header RQSF_GOT_SENSE | State flag: sense data came back. Named by two drivers; the condition under which firmware sets it is not stated by any source here. |
| `STATE_GOT_TARGET` | 0x200 | established | Linux qla1280 driver header SF_GOT_TARGET and qla1280 driver; NetBSD isp driver header RQSF_GOT_TARGET and isp driver; OpenBSD qlw driver header QLW_STATE_GOT_TARGET | State flag: the target answered selection. For an incomplete completion with this bit clear, Linux reports DID_BAD_TARGET when got-bus is set and DID_NO_CONNECT when it is clear, and NetBSD reports a selection timeout. A command to an absent target therefore completes incomplete with got-bus set and got-target clear. |
| `STATUS_COMP_INCOMPLETE` | 0x1 | established | Linux qla1280 driver header CS_INCOMPLETE; NetBSD isp driver header RQCS_INCOMPLETE; OpenBSD qlw driver header QLW_IOCB_STATUS_INCOMPLETE | Completion status incomplete. For a selection that found no device the state flags below say how far the command got. |
| `STATUS_COMP_RESET` | 0x4 | established | Linux qla1280 driver header CS_RESET; NetBSD isp driver header RQCS_RESET_OCCURRED; OpenBSD qlw driver header QLW_IOCB_STATUS_RESET | Completion status reset: a bus reset destroyed the command. All three drivers handle it as a destroyed command and report it as a reset. Whether the firmware sends it for a command that had not yet been selected is inferred, not stated. |
| `STATUS_ENTRY_COMP_STATUS_OFFSET` | 0xa | established | Linux qla1280 driver header struct response; OpenBSD qlw driver header struct qlw_iocb_status | Byte offset of the 16-bit completion status in a status entry. The entry's header is four bytes. |
| `STATUS_ENTRY_SENSE_LENGTH_OFFSET` | 0x12 | established | Linux qla1280 driver header struct response (req_sense_length); OpenBSD qlw driver header struct qlw_iocb_status (sense_len) | Byte offset of the 16-bit sense length. Linux reads it to decide how many sense bytes to trust. |
| `STATUS_ENTRY_STATE_FLAGS_OFFSET` | 0xc | established | Linux qla1280 driver header struct response; OpenBSD qlw driver header struct qlw_iocb_status | Byte offset of the 16-bit state flags in a status entry. |
| `STATUS_ENTRY_STATUS_FLAGS_OFFSET` | 0xe | established | Linux qla1280 driver header struct response; OpenBSD qlw driver header struct qlw_iocb_status | Byte offset of the 16-bit status flags in a status entry. |
| `STATUS_FLAG_SELECTION_TIMEOUT` | 0x40 | inferred | NetBSD isp driver header RQSTF_TIMEOUT, read by the NetBSD driver for a transport error only | Status flag: a timeout. Only the NetBSD header names it, and that driver reads it for a transport error rather than for a missing target. Whether the firmware sets it for an absent target is not established by any source held here. |
