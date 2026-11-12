# IOC4 registers outside the census

<!-- generated from defs/ioc4_extra.toml by defs-gen - do not edit, change the source -->

Unit `ioc4_extra`, macro prefix `IOC4`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `km_rx_kbd` | 0x204 | r | 32 |  |  | unknown | established |  |
| `km_rx_mouse` | 0x208 | r | 32 |  |  | unknown | established |  |
| `km_tx_kbd` | 0x20c | w | 32 |  |  | unknown | established |  |
| `km_tx_mouse` | 0x210 | w | 32 |  |  | unknown | established |  |

### Register `km_rx_kbd`

### Register `km_rx_mouse`

### Register `km_tx_kbd`

### Register `km_tx_mouse`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ATA_DMA_CONTROL` | 0x15c | established |  | index 7, byte accesses; bits below |
| `ATA_DMA_CONTROL_ACTIVE` | 0x8 | established |  | bit 3: read first by the start routine, which stops the engine before arming when set; name [I] |
| `ATA_DMA_CONTROL_DIR_TO_MEMORY` | 0x4 | inferred |  | bit 2: 1 copies ATA data to memory; the direction convention rests on the public driver's comments |
| `ATA_DMA_CONTROL_ERROR` | 0x10 | established |  | bit 4: tested; when set the start routine stores 2 and the completion routine reads it back; name [I] |
| `ATA_DMA_CONTROL_START` | 0x1 | established |  | bit 0: ORed with the direction bit and stored once to start a transfer (earlier full reading; the combined value was not re-derived); name [I] |
| `ATA_DMA_CONTROL_STOP` | 0x2 | established |  | bit 1: the value 2 is stored, then the word is read until the bit clears; name [I] |
| `ATA_DMA_COUNT_DEVICE` | 0x154 | inferred |  | index 5; read by the completion routine |
| `ATA_DMA_COUNT_MEMORY` | 0x158 | inferred |  | index 6; read by the completion routine |
| `ATA_DMA_CURRENT_HIGH` | 0x150 | unknown |  | index 4; name from the public driver only |
| `ATA_DMA_CURRENT_LOW` | 0x14c | unknown |  | index 3; name from the public driver only |
| `ATA_DMA_END_AREA` | 0x160 | inferred |  | index 8; bus address of the 128-byte end-of-transfer area |
| `ATA_DMA_LIST_HIGH` | 0x148 | inferred |  | index 2; written by the packet-DMA start routine |
| `ATA_DMA_LIST_LOW` | 0x144 | inferred |  | index 1; written by the packet-DMA start routine |
| `ATA_DMA_TIMING` | 0x140 | inferred |  | width 4 byte(s); index 0; name from the public driver only |
| `SIO_CR_CMD_PULSE` | 0xf | established |  | value stored at attach; that bits 3:0 are a strobe field is [I] |
| `SIO_CR_SIO_DIAG_IDLE` | 0x80 | established |  | bit 7, polled until set; name [I] |
