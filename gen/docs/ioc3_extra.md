# IOC3 registers outside the census

<!-- generated from defs/ioc3_extra.toml by defs-gen - do not edit, change the source -->

Unit `ioc3_extra`, macro prefix `IOC3`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `one_wire_ctl` | 0x30 | rw | 32 |  |  | unknown | established |  |
| `plp_a_addr_hi` | 0x80 | rw | 32 |  |  | unknown | established |  |
| `plp_a_addr_lo` | 0x84 | rw | 32 |  |  | unknown | established |  |
| `plp_a_count` | 0x88 | rw | 32 |  |  | unknown | established |  |
| `plp_ctl` | 0x8c | rw | 32 |  |  | unknown | established |  |
| `plp_b_addr_hi` | 0x90 | rw | 32 |  |  | unknown | established |  |
| `plp_b_addr_lo` | 0x94 | rw | 32 |  |  | unknown | established |  |
| `plp_b_count` | 0x98 | rw | 32 |  |  | unknown | established |  |
| `km_rx_kbd` | 0xa0 | r | 32 |  |  | unknown | established |  |
| `km_rx_mouse` | 0xa4 | r | 32 |  |  | unknown | established |  |
| `km_tx_kbd` | 0xa8 | w | 32 |  |  | unknown | established |  |
| `km_tx_mouse` | 0xac | w | 32 |  |  | unknown | established |  |

### Register `one_wire_ctl`

### Register `plp_a_addr_hi`

### Register `plp_a_addr_lo`

### Register `plp_a_count`

### Register `plp_ctl`

### Register `plp_b_addr_hi`

### Register `plp_b_addr_lo`

### Register `plp_b_count`

### Register `km_rx_kbd`

### Register `km_rx_mouse`

### Register `km_tx_kbd`

### Register `km_tx_mouse`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `GPCR_S_MICROLAN_ROUTE_BIT` | 0x200000 | inferred |  | Pin-control bit 21: routes the MicroLAN engine to GPIO pin 8. Nothing on the one-wire bus works until it is set. |
| `GPPR_LIGHTBAR_RED_PIN` | 0x1 | inferred |  | Pin 1, red fault lamp, active high. |
| `GPPR_LIGHTBAR_WHITE_PIN` | 0x0 | inferred |  | Pin 0, white lamps. Polarity not measured. |
| `GPPR_MEANINGFUL_MASK` | 0x1ff | inferred |  | Pin data bits 8:0. Pins 0 to 8 are the meaningful ones on Origin base I/O. |
| `GPPR_MICROLAN_PIN` | 0x8 | inferred |  | Pin the MicroLAN engine drives when pin-control bit 21 is set. |
| `GPPR_PHY_RESET_PIN` | 0x5 | inferred |  | Pin 5, ethernet PHY reset. |
| `GPPR_UARTA_MODESEL_PIN` | 0x7 | inferred |  | Pin 7, selects RS-232 or RS-422 for port A. |
| `GPPR_UARTB_MODESEL_PIN` | 0x6 | inferred |  | Pin 6, selects RS-232 or RS-422 for port B. |
| `INT_OUT_COUNT_MASK` | 0xffff | inferred |  | Bits 15:0, the interval count. The hardware tick is 7.8 microseconds; the count converts as COUNT + 1 ticks. |
| `INT_OUT_DIAG_BIT` | 0x40000000 | inferred |  | Bit 30, named diagnostic mode. Behaviour unknown. |
| `INT_OUT_MODE_HIGH` | 0x4 | inferred |  | Mode field 100: drive the output high. |
| `INT_OUT_MODE_LOW` | 0x0 | inferred |  | Mode field 000: drive the output low. |
| `INT_OUT_MODE_MASK` | 0x70000 | inferred |  | Bits 18:16, the mode field. |
| `INT_OUT_MODE_ONE_PULSE` | 0x5 | inferred |  | Mode field 101: one high pulse of three ticks (23.4 microseconds), then low. |
| `INT_OUT_MODE_PULSE_TRAIN` | 0x6 | inferred |  | Mode field 110: repeated high pulses. The guide truncates the period to a multiple of 7.8 microseconds. |
| `INT_OUT_MODE_SQUARE` | 0x7 | inferred |  | Mode field 111: toggle the output at each interval. The guide truncates the toggle interval to a multiple of 23.4 microseconds; a full cycle is twice the interval. |
| `INT_OUT_PIN0_ROUTE_BIT` | 0x100000 | inferred |  | Pin-control bit 20 (register 0x34 set, 0x38 clear): routes the interrupt-output block to GPIO pin 0. |
| `INT_OUT_PULSE_TICKS` | 0x3 | inferred |  | Ticks in one pulse: 23.4 microseconds. |
| `INT_OUT_STATE_BIT` | 0x80000000 | inferred |  | Bit 31, the current output state, read back. |
| `INT_OUT_TICK_NS` | 0x1e78 | inferred |  | Hardware tick of the interrupt-output timer, in nanoseconds (7.8 microseconds). |
| `PORT_CTL_CARRIER_REQ_BIT` | 0x40000 | inferred |  | Bit 18: post a receive record when carrier detect changes. |
| `PORT_CTL_CTS_REQ_BIT` | 0x80000 | inferred |  | Bit 19: post a receive record when clear-to-send changes. |
| `PORT_CTL_FLOW_CTL_BIT` | 0x20000 | inferred |  | Bit 17: hardware flow control. |
| `PORT_CTL_HIGH_WATER_MASK` | 0x1ff | inferred |  | Bits 8:0, the receive high-water mark in entries. |
| `PORT_CTL_QUAD_SPEED_BIT` | 0x100000 | inferred |  | Bit 20: quadruple speed. |
| `PORT_CTL_RING_DMA_EN_BIT` | 0x10000000 | inferred |  | Bit 28: enables ring DMA for the port. |
| `SIO_CR_ARBITER_IDLE_BIT` | 0x400000 | inferred |  | Bit 22, arbiter idle. Read-only and diagnostic. |
| `SIO_CR_REQUESTER_MASK` | 0x380000 | inferred |  | Bits 21:19, which internal master wants the PCI bus. Read-only and diagnostic. |
| `SIO_CR_RESET_BIT` | 0x1 | inferred |  | Bit 0: resets the SuperIO block. |
| `SIO_CR_SER_A_BASE_MASK` | 0xfe | inferred |  | Bits 7:1, port A's SuperIO byte offset divided by 8. Port A's UART is at 0x178, so the field holds 0x2f. |
| `SIO_CR_SER_B_BASE_MASK` | 0x7f00 | inferred |  | Bits 14:8, port B's SuperIO byte offset divided by 8. Port B's UART is at 0x170, so the field holds 0x2e. |
| `SIO_CR_STROBE_MASK` | 0x78000 | inferred |  | Bits 18:15, the byte-bus strobe length. |
| `SIO_IR_SRC_A_CARRIER` | 0x10 | inferred |  | Port A carrier-detect changed. |
| `SIO_IR_SRC_A_CTS` | 0x20 | inferred |  | Port A clear-to-send changed. |
| `SIO_IR_SRC_A_PCI_ERR` | 0x100 | inferred |  | PCI error on port A's DMA. |
| `SIO_IR_SRC_A_RX_FULL` | 0x2 | inferred |  | Port A receive ring full: a level that falls once software makes room. |
| `SIO_IR_SRC_A_RX_HIGH` | 0x4 | inferred |  | Port A receive high-water mark reached: a level that follows the waiting count. |
| `SIO_IR_SRC_A_RX_TIMER` | 0x8 | inferred |  | Port A receive timer expired. |
| `SIO_IR_SRC_A_TX_DONE` | 0x80 | inferred |  | Port A explicit transmit completion. |
| `SIO_IR_SRC_A_TX_EMPTY` | 0x1 | inferred |  | Port A transmit ring empty: a level, set while ring DMA runs and nothing is left to send. |
| `SIO_IR_SRC_A_UART` | 0x40 | inferred |  | Port A pass-through of the 16550's own interrupt. A level: writes to it do nothing. |
| `SIO_IR_SRC_B_CARRIER` | 0x2000 | inferred |  | Port B carrier-detect changed. |
| `SIO_IR_SRC_B_CTS` | 0x4000 | inferred |  | Port B clear-to-send changed. |
| `SIO_IR_SRC_B_PCI_ERR` | 0x20000 | inferred |  | PCI error on port B's DMA. |
| `SIO_IR_SRC_B_RX_FULL` | 0x400 | inferred |  | Port B receive ring full. |
| `SIO_IR_SRC_B_RX_HIGH` | 0x800 | inferred |  | Port B receive high-water mark reached. |
| `SIO_IR_SRC_B_RX_TIMER` | 0x1000 | inferred |  | Port B receive timer expired. |
| `SIO_IR_SRC_B_TX_DONE` | 0x10000 | inferred |  | Port B explicit transmit completion. |
| `SIO_IR_SRC_B_TX_EMPTY` | 0x200 | inferred |  | Port B transmit ring empty (port A's bit moved 9 up). |
| `SIO_IR_SRC_B_UART` | 0x8000 | inferred |  | Port B pass-through of the 16550's own interrupt. A level: writes to it do nothing. |
| `SIO_IR_SRC_KBD` | 0x400000 | inferred |  | Shared keyboard and mouse interrupt, bit 22. Latched: write one to clear. |
| `SIO_IR_SRC_PP_PASSTHRU` | 0x40000 | inferred |  | Parallel port pass-through interrupt, bit 18. Follows its sub-block's level. |
| `SIO_IR_SRC_PP_PCI_ERR` | 0x200000 | inferred |  | PCI error on the parallel port's DMA, bit 21. Bits 19 and 20 are its two DMA contexts. |
| `SIO_IR_SRC_RT_IN_PULSE` | 0x10000000 | inferred |  | Real-time interrupt input pulsed, bit 28. |
| `SIO_IR_SRC_RT_OUT_PULSE` | 0x8000000 | inferred |  | Real-time interrupt output emitted a pulse, bit 27. |
