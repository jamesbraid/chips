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
| `SERIAL_RING_PTR_B_9_3` | 0x3f8 | inferred |  | Active bits of a producer or consumer index on a 1 KB serial ring of 8-byte entries. The 4 KB ring mask is 0xff8 (the ring bits 11:3 in the register table). |
| `SERIAL_RX_TIMER_COUNT_B_27_16` | 0xfff0000 | inferred |  | Current count of the receive timer, bits 27:16 of the RX timer register. The public driver defines the field and does not read it. |
| `SERIAL_RX_TIMER_RELOAD_B_11_0` | 0xfff | inferred |  | Reload count of the receive timer, bits 11:0 of the RX timer register. The IOC3 receive-timeout routine caps its stored count at 4095, the same twelve bits. |
| `SERIAL_SHADOW_CTS_V_100000` | 0x100000 | inferred |  | Clear-to-send line level, bit 20 of the port shadow register. |
| `SERIAL_SHADOW_DCD_V_800000` | 0x800000 | inferred |  | Carrier-detect line level, bit 23 of the port shadow register. |
| `SERIAL_SHADOW_DCTS_V_10000` | 0x10000 | inferred |  | Clear-to-send changed, bit 16 of the port shadow register. |
| `SERIAL_SHADOW_DDCD_V_80000` | 0x80000 | inferred |  | Carrier-detect changed, bit 19 of the port shadow register. |
| `SERIAL_SHADOW_OUTPUTS_B_28_24` | 0x1f000000 | inferred |  | Modem outputs and loopback, bits 28:24 of the port shadow register. The public driver names DTR, RTS, OUT1, OUT2 and loopback in this field and does not give the position of each one. |
| `SERIAL_SHADOW_RX_FLAGS_B_7_0` | 0xff | inferred |  | Low byte of the port shadow register: receive data and line-status flags. |
| `SERIAL_SRCIR_TIMER_ARM_V_80000000` | 0x80000000 | inferred |  | Bit 31 of the RX consumer write. The public driver calls it the timer-arm bit. Whether the readback reflects it is not established. |
| `SIO_CR_CMD_PULSE` | 0xf | established |  | value stored at attach; that bits 3:0 are a strobe field is [I] |
| `SIO_CR_SIO_DIAG_IDLE` | 0x80 | established |  | bit 7, polled until set; name [I] |
