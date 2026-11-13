<!-- generated from devices/isp2200/registers.toml by defs-gen - do not edit, change the source -->

# QLogic ISP2200 Fibre Channel host adapter (PCI 1077:2200), the host interface the public drivers use

The single-chip Fibre Channel host adapter of the Origin 3000 I-brick (PCI 1077:2200), as the public Linux, OpenBSD and NetBSD drivers use it. Grades say how each item was derived: established means at least two of the public driver trees state the value and agree; inferred means one driver states it, or a driver's own struct or use names it without a second source; unknown means the sources do not settle it. No QLogic programming manual for this part is held, so the register contract rests on driver agreement, and the reset state of every register is unknown. The mailbox opcodes and status values are what the drivers send and read, not measured chip behaviour.

Unit `isp2200`, macro prefix `ISP2200`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `csr` | 0x6 | rw | 16 |  |  | unknown | established |  |
| `icr` | 0x8 | rw | 16 |  |  | unknown | established |  |
| `isr` | 0xa | r | 16 |  |  | unknown | established |  |
| `sema` | 0xc | rw | 16 |  |  | unknown | established |  |
| `nvram` | 0xe | rw | 16 |  |  | unknown | established |  |
| `mailbox` | 0x10 | rw | 16 | 8 |  | unknown | established |  |
| `hccr` | 0xc0 | rw | 16 |  |  | unknown | established |  |
| `mailbox_hi` | 0xe0 | rw | 16 | 16 |  | unknown | inferred |  |

### Register `csr`

Control and status register. Writing bit 0 starts a soft reset. The drivers poll the bit until the adapter clears it. Bits 5 and 4 choose the bank that answers the banked window. Linux and NetBSD disagree on the flash bank bits, so those bits are not named here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5:4 | `bank` | established |  |  | Bank behind the banked window at offsets 0x80 to 0xBF. The drivers leave it at the RISC bank. The other values select frame-buffer and diagnostic banks that no public driver uses. |
| 0 | `soft_reset` | established |  |  | Soft reset. Writing 1 starts a reset. The drivers poll until it reads 0. |

### Register `icr`

Interrupt control. The drivers write 0x8008 to enable and 0 to disable. Other bits are not used by any public driver for this part.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `global_enable` | established |  |  | Global interrupt enable. Drivers set it together with the RISC enable. |
| 3 | `risc_enable` | established |  |  | RISC interrupt enable. Drivers set it together with the global enable. |

### Register `isr`

Interrupt status. Drivers test the RISC interrupt bit first. OpenBSD also tests the pending bit before it reads the response ring.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `any_pending` | inferred |  |  | Interrupt pending. OpenBSD tests it before reading the response ring. Linux does not read it. |
| 3 | `risc_pending` | established |  |  | RISC interrupt pending. Linux tests only this bit. |

### Register `sema`

Semaphore. The adapter sets the lock bit when a mailbox result or asynchronous event waits for the host. The host releases it by writing 0, and the drivers release it last, after reading the mailboxes.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `status` | unknown |  |  | Named status by NetBSD. No driver reads it, and what a write of 1 does is not known. |
| 0 | `lock` | established |  |  | Lock. Set while mailbox or event data waits for the host. Writing 0 releases it. |

### Register `nvram`

Serial EEPROM port. The host bit-bangs the clock, chip select and data lines to read the board NVRAM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `data_from_eeprom` | established |  |  | Data from the EEPROM to the host. |
| 2 | `data_to_eeprom` | established |  |  | Data from the host to the EEPROM. |
| 1 | `select` | established |  |  | Chip select for the EEPROM. |
| 0 | `clock` | established |  |  | Serial clock to the EEPROM. |

### Register `mailbox`

Mailboxes 0 to 7, two bytes apart. Mailbox 0 carries the command number in and the status out. Mailbox 4 is the request-queue pointer and mailbox 5 the response-queue pointer. The drivers write and read them outside any command, and a write to them does not ring the doorbell.

Array of 8 registers, stride 2.

### Register `hccr`

Host command and control register. A write carries a command in bits 15 to 12. A read returns status in the bits named below. Reset values are not stated by any source.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:12 | `cmd` | established | hccr_cmd (noop=0, reset_risc=1, pause_risc=2, release_risc=3, parity=4, set_host_int=5, clear_host_int=6, clear_risc_int=7) |  | Write: command number. Value 4 covers the words 0x4000 and 0x4001. Drivers write 0x4001, which Linux and NetBSD call disable parity pause, and OpenBSD writes 0x4000 between reset and release, which it calls mask parity while NetBSD calls it single step. What the chip does with either word is unknown. |
| 7 | `host_int` | established |  |  | Read: host interrupt set, the command-pending flag. Drivers wait for it to clear after a doorbell. That it clears once the firmware takes the command, without a clear-host-interrupt write, is inferred from the waits in two drivers. |
| 6 | `risc_reset` | inferred |  |  | Read: RISC held in reset. NetBSD names it reset in progress. Whether the bit clears by itself when a soft reset ends, or only at a release, is unknown. |
| 5 | `risc_paused` | established |  |  | Read: RISC paused. Linux treats a paused status seen during an interrupt as a fault. |

### Register `mailbox_hi`

Mailboxes 8 to 23. The count of 24 comes from two drivers, but only Linux gives where the upper sixteen sit. Linux writes all 24 on every mailbox command, zeroing the ones the command does not use.

Array of 16 registers, stride 2.

## Enums

### Enum `hccr_cmd`

| Label | Value | Grade | Source |
|---|---|---|---|
| `noop` | 0 | established |  |
| `reset_risc` | 1 | established |  |
| `pause_risc` | 2 | established |  |
| `release_risc` | 3 | established |  |
| `parity` | 4 | established |  |
| `set_host_int` | 5 | established |  |
| `clear_host_int` | 6 | established |  |
| `clear_risc_int` | 7 | established |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ASYNC_EVENT_FIRST` | 0x8000 | established |  | The codes from this value to 0xBFFF in mailbox 0 are asynchronous events, delivered like a mailbox result. |
| `ASYNC_EVENT_LAST` | 0xbfff | inferred |  | Last code in the asynchronous event range. |
| `ASYNC_LIP` | 0x8010 | established |  | Asynchronous event: a loop initialization primitive occurred. |
| `ASYNC_LOOP_DOWN` | 0x8012 | established |  | Asynchronous event: the loop went down. |
| `ASYNC_LOOP_UP` | 0x8011 | established |  | Asynchronous event: the loop came up. |
| `ASYNC_PORT_DB_CHANGE` | 0x8014 | established |  | Asynchronous event: the port database changed. |
| `ASYNC_RESET` | 0x8001 | established |  | Asynchronous event: the adapter reset. |
| `ASYNC_RSCN` | 0x8015 | established |  | Asynchronous event: a registered state change notification arrived. |
| `CMD_ENTRY_32` | 0x11 | inferred |  | Request entry type for a command with 32-bit segment addresses. Only Linux uses it. |
| `CMD_ENTRY_64` | 0x19 | established |  | Request entry type for a command with 64-bit segment addresses. The entry carries the CDB and the first two segments. Continuations carry the rest. |
| `CONT_ENTRY_32` | 0x2 | inferred |  | Request continuation entry carrying further 32-bit segments. Only Linux uses it. |
| `CONT_ENTRY_64` | 0xa | inferred |  | Request continuation entry carrying further 64-bit segments. Only Linux uses it. |
| `CPL_ABORTED` | 0x5 | established |  | Completion status of an aborted command. |
| `CPL_COMPLETE` | 0x0 | established |  | Completion status of a command that finished normally. |
| `CPL_DATA_OVERRUN` | 0x7 | established |  | Completion status of a command whose target sent more data than the host expected. The residual count gives the difference. |
| `CPL_DATA_UNDERRUN` | 0x15 | established |  | Completion status of a command whose target sent less data than the host expected. The residual count gives the difference. |
| `CPL_DMA_ERROR` | 0x2 | established |  | Completion status of a command whose data DMA failed. |
| `CPL_INCOMPLETE` | 0x1 | established |  | Completion status of a command that did not finish. The state and status flags in the same entry say why, and their bits are unknown. |
| `CPL_PORT_BUSY` | 0x2b | established |  | Completion status of a command sent to a port that is busy. |
| `CPL_PORT_CONFIG_CHANGED` | 0x2a | established |  | Completion status of a command sent to a port whose configuration changed. |
| `CPL_PORT_LOGGED_OUT` | 0x29 | established |  | Completion status of a command sent to a port that is logged out. |
| `CPL_PORT_UNAVAILABLE` | 0x28 | established |  | Completion status of a command sent to a port that is not available. |
| `CPL_QUEUE_FULL` | 0x1c | established |  | Completion status of a command the target refused because its queue was full. |
| `CPL_RESET` | 0x4 | established |  | Completion status of a command the adapter dropped during a reset. |
| `CPL_TIMEOUT` | 0x6 | established |  | Completion status of a command that timed out. |
| `CPL_TRANSPORT_ERROR` | 0x3 | established |  | Completion status of a command that failed in the transport. |
| `ENTRY_BYTES` | 0x40 | established |  | Size of every request and response ring entry, in bytes. Fields are little-endian. |
| `FIRMWARE_LENGTH_WORD_INDEX` | 0x3 | established |  | Index of the word in a firmware image that gives its length in words. All three loaders read it there. |
| `ICB_BYTES` | 0x60 | established |  | Size of the initialization control block that INIT FIRMWARE reads from host memory. |
| `ICB_VERSION` | 0x1 | established |  | Version byte at the start of the initialization control block. The drivers write 1. |
| `MAILBOXES_TOTAL` | 0x18 | established |  | Number of 16-bit mailboxes. Only the first eight are used by the OpenBSD driver. Linux writes all of them on every command. |
| `MARKER_ENTRY` | 0x4 | established |  | Request entry the host posts after a loop reset, abort or LIP to resynchronise the firmware. It produces no response entry. |
| `MBOX0_BUSY` | 0x4 | established |  | Mailbox 0 reads this value while the RISC is held in reset or paused, and the drivers wait until it stops reading it. |
| `MBOX_COMPLETION_LAST` | 0x7fff | inferred |  | The codes from 0x4000 to this value in mailbox 0 are command completions. The drivers test the range rather than single codes. |
| `NVRAM_IMAGE_BYTES` | 0x100 | established |  | Size of the serial EEPROM image the drivers read through the NVRAM register. |
| `OP_ABOUT_FIRMWARE` | 0x8 | established |  | Return the firmware version in mailboxes 1 to 3 and the attributes word in mailbox 6. |
| `OP_DUMP_RAM` | 0x3 | inferred |  | Dump RAM to host memory, the inverse of the 32-bit load. The operand layout follows the load command. |
| `OP_EXECUTE_FIRMWARE` | 0x2 | established |  | Start the RISC at a RAM address given in mailbox 1. Linux and OpenBSD check its status. NetBSD does not. |
| `OP_FIRMWARE_STATUS` | 0x1f | inferred |  | Firmware status. OpenBSD reads the maximum number of outstanding commands from mailbox 2. Linux does not send it. |
| `OP_GET_FIRMWARE_OPTIONS` | 0x28 | inferred |  | Read the firmware options words kept by the firmware. Linux sends it before INIT FIRMWARE. What the options change is not stated. |
| `OP_INIT_FIRMWARE` | 0x60 | established |  | Give the firmware the initialization control block by DMA. The address goes in mailboxes 2, 3, 6 and 7. The three drivers send different input masks: they differ on mailboxes 1, 4 and 5, which some of them send as zero. |
| `OP_LOAD_RAM_32` | 0x1 | inferred |  | Load RAM with a 32-bit host address: mailbox 1 is the RAM word address, mailboxes 2 and 3 the host address, and mailbox 4 the word count. No public driver sends it for this part. |
| `OP_LOAD_RAM_DMA` | 0x9 | inferred |  | Load RAM from host memory by DMA. Mailbox 1 is the RAM word address. Mailbox 2 carries bits 31 to 16 of the low 32 bits of the host address and mailbox 3 bits 15 to 0; mailboxes 6 and 7 carry the top 32 bits, and mailbox 4 the word count. Only Linux uses it for this part. |
| `OP_LOAD_RAM_EXT` | 0xb | inferred |  | Load RAM by DMA, as the 0x0009 form, with RAM address bits 31 to 16 in mailbox 8. Linux selects it only when the RAM address needs more than 16 bits. |
| `OP_MAILBOX_TEST` | 0x6 | inferred |  | Echo command. Linux writes a fixed pattern to mailboxes 1 to 7 and checks that the same values come back. It runs before the queues exist. |
| `OP_NOOP` | 0x0 | established |  | No-op mailbox command. Returns the complete status. |
| `OP_READ_RAM_WORD` | 0x5 | inferred |  | Read one word of controller RAM: mailbox 1 is the address and mailbox 2 returns the data. |
| `OP_SET_FIRMWARE_OPTIONS` | 0x38 | inferred |  | Store firmware options in mailboxes 1 to 3. OpenBSD treats a refusal as a failed attach. |
| `OP_VERIFY_CHECKSUM` | 0x7 | established |  | Sum a loaded firmware image in RAM. The sum over the length in the image's length word is the check the drivers make. The sum comes back in mailbox 1, and the drivers treat zero as a match. |
| `OP_WRITE_RAM_WORD` | 0x4 | established |  | Write one word of controller RAM: mailbox 1 is the address and mailbox 2 the data. |
| `PCI_BAR_IO_CONFIG_OFFSET` | 0x10 | established |  | Configuration-space offset of BAR0, the I/O-space BAR. Linux and OpenBSD both use it for the register window. The window is also decoded in memory space through the BAR at the next offset, and the drivers read the same registers through either. |
| `PCI_BAR_MEM_CONFIG_OFFSET` | 0x14 | established |  | Configuration-space offset of BAR1, the memory-space BAR. The BAR type (32-bit or 64-bit memory) is unknown: the drivers accept either. |
| `PCI_CONFIG_BUS_MASTER_BIT` | 0x4 | established |  | Bit 2 of the PCI command register. The drivers set it, and the adapter's DMA depends on it. The bit is the standard PCI definition, not a register of this chip. |
| `PCI_DEVICE_ID` | 0x2200 | established |  | PCI device ID of the ISP2200 under vendor 0x1077. pci.ids gives the marketing name QLA2200 64-bit Fibre Channel Adapter, which is not a silicon marking. |
| `PCI_VENDOR_ID` | 0x1077 | established |  | QLogic's PCI vendor ID. The same vendor ID is on every QLogic part in this repository. |
| `PRODUCT_ID_MAILBOX1` | 0x4953 | established |  | Mailbox 1 after a reset, read as the ASCII text IS. The drivers test it to confirm the part answers as a QLogic adapter. |
| `PRODUCT_ID_MAILBOX2` | 0x5020 | established |  | Mailbox 2 after a reset, read as the ASCII text followed by a space. Linux also accepts zero here. OpenBSD issues another RISC release when the value is wrong. |
| `PRODUCT_ID_MAILBOX3` | 0x2020 | established |  | Mailbox 3 after a reset, read as two spaces. |
| `REGISTER_WINDOW_BYTES` | 0x100 | established |  | Size of the register window. The last mailbox ends exactly at this size, so it is the smallest window that holds the register file. |
| `RISC_CODE_ORIGIN_WORD` | 0x1000 | established |  | Word address in controller RAM where downloaded RISC code starts. Both drivers agree on it. |
| `ROM_VERSION_MAILBOX7` | 0x4 | inferred |  | Mailbox 7 after a reset, which Linux names the QLA2200A RISC ROM version. Linux limits firmware transfers to 128 bytes when it reads this value. Only that one driver reads it, so whether it tells a 2200A from a 2200 is unknown. |
| `SEGMENT_LIST_ENTRY` | 0x15 | inferred |  | Request entry that points at a list of segments in host memory instead of carrying continuations. Only OpenBSD uses it. |
| `STATUS_COMMAND_ERROR` | 0x4005 | established |  | Mailbox 0 status for a command that failed in the firmware. |
| `STATUS_COMPLETE` | 0x4000 | established |  | Mailbox 0 status for a command that completed. |
| `STATUS_CONT_ENTRY` | 0x10 | established |  | Response continuation that carries sense data beyond the first 32 bytes. The two drivers disagree on how much sense data one of these holds, so the capacity is unknown. |
| `STATUS_ENTRY` | 0x3 | established |  | Response entry that reports the completion of a command. The handle in it is the one the host put in the command. |
| `STATUS_HOST_INTERFACE_ERROR` | 0x4002 | established |  | Mailbox 0 status for a command whose host DMA failed. |
| `STATUS_INVALID_COMMAND` | 0x4001 | established |  | Mailbox 0 status for a command number the firmware does not accept. |
| `STATUS_PARAMETER_ERROR` | 0x4006 | established |  | Mailbox 0 status for a bad parameter. The sources name the value but not which malformed input returns it. |
| `STATUS_TEST_FAILED` | 0x4003 | established |  | Mailbox 0 status for a failed test, such as a checksum that does not sum to zero. |
