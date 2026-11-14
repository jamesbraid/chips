<!-- generated from devices/ioc4/registers-extra.toml by defs-gen - do not edit, change the source -->

# IOC4 registers outside the census

Unit `ioc4_extra`, macro prefix `IOC4`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `gpdr` | 0x38 | rw | 32 |  |  | unknown | established |  |
| `km_rx_kbd` | 0x204 | r | 32 |  |  | unknown | established |  |
| `km_rx_mouse` | 0x208 | r | 32 |  |  | unknown | established |  |
| `km_tx_kbd` | 0x20c | w | 32 |  |  | unknown | established |  |
| `km_tx_mouse` | 0x210 | w | 32 |  |  | unknown | established |  |

### Register `gpdr`

Generic pin data word. The SGI header defines it at 0x38 with bits 7:0 holding the state of the eight generic pins. Offset and name are established by the header and the PROM store; no Linux driver code read touches it, and what a write does is unknown.

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
| `EXTINT_COUNT_DIVISOR` | 0x208 | established |  | PCI clocks per COUNT tick of the external interrupt output. Period of a toggle-mode half cycle is (COUNT plus 1) times this many PCI clocks. |
| `GPCR_DIR_MASK` | 0xff | established |  | Bits 7:0 of the generic pin control set and clear words (0x30, 0x34): pin direction, one bit per pin. |
| `GPCR_EDGE_MASK` | 0xff00 | established |  | Bits 15:8: edge or level mode of the pin interrupt, one bit per pin. |
| `GPCR_INT_OUT_EN` | 0x100000 | established |  | Bit 20: connect the external interrupt output to pin 0. The shipped Origin 350 PROM value 0x1000f0 sets this bit and the direction of pins 4 to 7. |
| `GPIO_PIN_EXT_INT_OUT` | 0x0 | established |  | Generic pin 0 carries the external interrupt output. Pin 1 is the external interrupt input (and the edge-mode pin the header singles out), pin 3 is the keyboard and mouse presence sense, pins 4 to 7 select RS-232 (0) or RS-422 (1) for serial ports 0 to 3. |
| `GPIO_PIN_SERIAL_MODE_0` | 0x4 | established |  | Pin number that selects the transceiver of serial port 0; ports 1 to 3 use pins 5, 6 and 7. The driver writes 0 for RS-232 and 1 for RS-422 to the pin's own word at 0x40 plus 4n. Agrees with the pin numbers read from the IRIX serial object. |
| `INT_OUT_COUNT_MASK` | 0xffff | established |  | Bits 15:0 of the external interrupt output control at 0x28: the period control. In toggle mode the output changes level every COUNT plus 1 ticks; one tick is 520 PCI clocks. |
| `INT_OUT_DIAG` | 0x40000000 | established |  | Bit 30: timebase control. The Linux driver leaves it clear; the shipped Origin 350 PROM clears it. What setting it does is not stated. |
| `INT_OUT_MODE_MASK` | 0x70000 | established |  | Bits 18:16: the output signal shape. Only value 7 (toggle) is used by any code read. |
| `INT_OUT_MODE_TOGGLE` | 0x70000 | established |  | Mode 7 in place: toggle the output every COUNT plus 1 ticks. The Linux driver runs this as a square wave of known period to measure the PCI clock. |
| `INT_OUT_VALUE` | 0x80000000 | established |  | Bit 31: the current output value. Readable, and the Linux driver polls it to time the square wave. |
| `KM_CSR_AUX_CLOCK_LINE` | 0x200 | established |  | Bit 9: auxiliary (mouse) clock line state (OpenBSD IOC3_KBC_STATUS_AUX_CLOCK, Linux KM_CSR_M_CLK). |
| `KM_CSR_AUX_DATA_LINE` | 0x100 | established |  | Bit 8: auxiliary (mouse) data line state (OpenBSD IOC3_KBC_STATUS_AUX_DATA, Linux KM_CSR_M_DATA). An earlier version placed this at bit 5; both public headers put bit 5 on the keyboard clock line. |
| `KM_CSR_AUX_WRITE_PENDING` | 0x2 | established |  | Bit 1: auxiliary (mouse) transmit pending. Same rule as bit 0. |
| `KM_CSR_IDLE_B_15_14` | 0xc000 | inferred |  | Bits 15:14: state-machine idle flags, by name only. No driver relies on them. |
| `KM_CSR_KBD_CLOCK_LINE` | 0x20 | established |  | Bit 5: keyboard clock line state (OpenBSD IOC3_KBC_STATUS_KBD_CLOCK, Linux KM_CSR_K_CLK). An earlier version placed this at bit 8; both public headers put bit 8 on the auxiliary data line. |
| `KM_CSR_KBD_DATA_LINE` | 0x10 | established |  | Bit 4: keyboard data line state. Both public drivers name it as a status bit (OpenBSD IOC3_KBC_STATUS_KBD_DATA, Linux KM_CSR_K_DATA). |
| `KM_CSR_KBD_WRITE_PENDING` | 0x1 | established |  | Bit 0 of the keyboard and mouse control word: keyboard transmit pending. A written byte stays pending until the transmit completes. |
| `KM_CSR_LAST_WRITE_LINE_B_3_2` | 0xc | inferred |  | Bits 3:2: line control of the last write, by name only. Whether the chip sets or clears them is unknown. |
| `OTHER_IR_ATA_INT` | 0x1 | established |  | Bit 0 of the other-interrupt word: ATA port pass-through. Written as part of the value 3 to the enable set by the IRIX ATA path. |
| `OTHER_IR_ATA_MEMERR` | 0x2 | established |  | Bit 1: the ATA DMA engine halted by a PCI memory error (the SGI header says ATAPI DMA PCI error). |
| `OTHER_IR_GEN_INT` | 0xff000000 | established |  | Bits 31:24: interrupt from the eight generic pins, one bit per pin. |
| `OTHER_IR_KBM` | 0x40 | established |  | Bit 6 of the other-interrupt word: the keyboard and mouse interrupt source. The driver masks and acknowledges it through the same word. IOC3 raises its keyboard and mouse interrupt from a different parent source (bit 22), so IOC3 parent wiring does not carry over. |
| `OTHER_IR_RT_INT` | 0x800000 | established |  | Bit 23: the external interrupt output section's latch. The IRIX external-interrupt attach acknowledges bits 31:23 with the value 0xff800000, which is this bit plus OTHER_IR_GEN_INT. |
| `OTHER_IR_SER_MEMERR_0` | 0x4 | established |  | Bit 2: serial port 0 halted by a PCI memory error. Ports 1 to 3 are bits 3, 4 and 5 (0x8, 0x10, 0x20). |
| `OTHER_IR_SER_MEMERR_1` | 0x8 | established |  | Bit 3: serial port 1 memory error. See OTHER_IR_SER_MEMERR_0. |
| `OTHER_IR_SER_MEMERR_2` | 0x10 | established |  | Bit 4: serial port 2 memory error. See OTHER_IR_SER_MEMERR_0. |
| `OTHER_IR_SER_MEMERR_3` | 0x20 | established |  | Bit 5: serial port 3 memory error. See OTHER_IR_SER_MEMERR_0. |
| `PCI_CLASS_CODE` | 0xb4000 | established |  | The PCI class code the Linux driver matches (base class 0x0b, subclass 0x40, interface 0), in addition to vendor 0x10a9 and device 0x100a. It is the match value of a driver, not a captured read. |
| `SERIAL_RING_PTR_B_9_3` | 0x3f8 | inferred |  | Active bits of a producer or consumer index on a 1 KB serial ring of 8-byte entries. The 4 KB ring mask is 0xff8 (the ring bits 11:3 in the register table). |
| `SERIAL_RX_TIMER_COUNT_B_27_16` | 0xfff0000 | inferred |  | Current count of the receive timer, bits 27:16 of the RX timer register. The public driver defines the field and does not read it. |
| `SERIAL_RX_TIMER_RELOAD_B_11_0` | 0xfff | inferred |  | Reload count of the receive timer, bits 11:0 of the RX timer register. The IOC3 receive-timeout routine caps its stored count at 4095, the same twelve bits. |
| `SERIAL_SHADOW_CTS_V_100000` | 0x100000 | inferred |  | Clear-to-send line level, bit 20 of the port shadow register. |
| `SERIAL_SHADOW_DCD_V_800000` | 0x800000 | inferred |  | Carrier-detect line level, bit 23 of the port shadow register. |
| `SERIAL_SHADOW_DCTS_V_10000` | 0x10000 | inferred |  | Clear-to-send changed, bit 16 of the port shadow register. |
| `SERIAL_SHADOW_DDCD_V_80000` | 0x80000 | inferred |  | Carrier-detect changed, bit 19 of the port shadow register. |
| `SERIAL_SHADOW_OUTPUTS_B_28_24` | 0x1f000000 | inferred |  | Modem outputs and loopback, bits 28:24 of the port shadow register. The public driver gives each position: bit 24 DTR, bit 25 RTS, bit 26 OUT1, bit 27 OUT2, bit 28 loopback. |
| `SERIAL_SHADOW_RX_FLAGS_B_7_0` | 0xff | inferred |  | Low byte of the port shadow register: bit 0 data ready, 1 overrun, 2 parity error, 3 framing error, 4 break, 5 transmit holding register empty, 6 transmit shift register empty, 7 error character in the receive FIFO. |
| `SERIAL_SRCIR_TIMER_ARM_V_80000000` | 0x80000000 | inferred |  | Bit 31 of the RX consumer write. The public driver calls it the timer-arm bit. Whether the readback reflects it is not established. |
| `SIO_CR_ARB_DIAG` | 0x70 | established |  | Bits 6:4 of the control word at 0x20: the PCI requester currently granted. Values 0 to 7 are TX0, RX0, TX1, RX1, TX2, RX2, TX3, RX3 in the driver's table. |
| `SIO_CR_ATA_DIAG_ACTIVE` | 0x200 | established |  | Bit 9 of the control word: the ATA request is the arbitration winner. |
| `SIO_CR_ATA_DIAG_IDLE` | 0x100 | established |  | Bit 8 of the control word: active ATA request indication. The header comment pairs it with the serial one at bit 7 (0 is an active request). |
| `SIO_CR_CMD_PULSE` | 0xf | established |  | value stored at attach; that bits 3:0 are a strobe field is [I] |
| `SIO_CR_SIO_DIAG_IDLE` | 0x80 | established |  | bit 7, polled until set; name [I] |
| `SIO_IR_SRC_UART_0` | 0x40 | established |  | Pass-through pending bit for port 0's own 16550 interrupt: bit 6 of that port's byte of the serial interrupt word. The SGI Linux header names the field intr_pass (interrupt pass-through), which settles the role OpenBSD gave it by comment. Whether the chip raises it from the UART level or an edge is not stated. |
| `SIO_IR_SRC_UART_1` | 0x4000 | established |  | Pass-through pending bit for port 1's own 16550 interrupt: bit 6 of that port's byte of the serial interrupt word. The SGI Linux header names the field intr_pass (interrupt pass-through), which settles the role OpenBSD gave it by comment. Whether the chip raises it from the UART level or an edge is not stated. |
| `SIO_IR_SRC_UART_2` | 0x400000 | established |  | Pass-through pending bit for port 2's own 16550 interrupt: bit 6 of that port's byte of the serial interrupt word. The SGI Linux header names the field intr_pass (interrupt pass-through), which settles the role OpenBSD gave it by comment. Whether the chip raises it from the UART level or an edge is not stated. |
| `SIO_IR_SRC_UART_3` | 0x40000000 | established |  | Pass-through pending bit for port 3's own 16550 interrupt: bit 6 of that port's byte of the serial interrupt word. The SGI Linux header names the field intr_pass (interrupt pass-through), which settles the role OpenBSD gave it by comment. Whether the chip raises it from the UART level or an edge is not stated. |
