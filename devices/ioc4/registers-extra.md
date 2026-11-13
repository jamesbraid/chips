<!-- generated from devices/ioc4/registers-extra.toml by defs-gen - do not edit, change the source -->

# IOC4 registers outside the census

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
| `KM_CSR_AUX_CLOCK_LINE` | 0x200 | established |  | Bit 9: auxiliary clock line state. See KM_CSR_KBD_DATA_LINE for the bit-order caveat. |
| `KM_CSR_AUX_DATA_LINE` | 0x20 | established |  | Bit 5: auxiliary data line state. See KM_CSR_KBD_DATA_LINE for the bit-order caveat. |
| `KM_CSR_AUX_WRITE_PENDING` | 0x2 | established |  | Bit 1: auxiliary (mouse) transmit pending. Same rule as bit 0. |
| `KM_CSR_IDLE_B_15_14` | 0xc000 | inferred |  | Bits 15:14: state-machine idle flags, by name only. No driver relies on them. |
| `KM_CSR_KBD_CLOCK_LINE` | 0x100 | established |  | Bit 8: keyboard clock line state. See KM_CSR_KBD_DATA_LINE for the bit-order caveat. |
| `KM_CSR_KBD_DATA_LINE` | 0x10 | established |  | Bit 4: keyboard data line state. The public driver names it as a status bit. The bit order of the four line-state bits follows the order of the driver's names, not a second source. |
| `KM_CSR_KBD_WRITE_PENDING` | 0x1 | established |  | Bit 0 of the keyboard and mouse control word: keyboard transmit pending. A written byte stays pending until the transmit completes. |
| `KM_CSR_LAST_WRITE_LINE_B_3_2` | 0xc | inferred |  | Bits 3:2: line control of the last write, by name only. Whether the chip sets or clears them is unknown. |
| `OTHER_IR_KBM` | 0x40 | established |  | Bit 6 of the other-interrupt word: the keyboard and mouse interrupt source. The driver masks and acknowledges it through the same word. IOC3 raises its keyboard and mouse interrupt from a different parent source (bit 22), so IOC3 parent wiring does not carry over. |
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
| `SIO_IR_SRC_UART_0` | 0x40 | inferred |  | Pass-through pending bit for port 0's own 16550 interrupt. OpenBSD enables only the four pass-through bits, so the other serial pending bits are not enabled by that driver. |
| `SIO_IR_SRC_UART_1` | 0x4000 | inferred |  | Pass-through pending bit for port 1's own 16550 interrupt. See SIO_IR_SRC_UART_0. |
| `SIO_IR_SRC_UART_2` | 0x400000 | inferred |  | Pass-through pending bit for port 2's own 16550 interrupt. See SIO_IR_SRC_UART_0. |
| `SIO_IR_SRC_UART_3` | 0x40000000 | inferred |  | Pass-through pending bit for port 3's own 16550 interrupt. See SIO_IR_SRC_UART_0. |
