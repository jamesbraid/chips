<!-- generated from devices/ioc4/registers-extra.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 c76a9ebe973b864f75d3bd181dbaa7e4ea1a9a32767fda897711641d5807f1b2 -->

# IOC4 registers outside the census

Unit `ioc4_extra`, macro prefix `IOC4`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `gpdr` | 0x38 | rw | 32 |  |  | unknown | established |  |
| `ata_cmd` | 0x100 | rw | 32 | 8 |  | unknown | established |  |
| `ata_ctl` | 0x120 | rw | 32 |  |  | unknown | established |  |
| `km_rx_kbd` | 0x204 | r | 32 |  |  | unknown | established |  |
| `km_rx_mouse` | 0x208 | r | 32 |  |  | unknown | established |  |
| `km_tx_kbd` | 0x20c | w | 32 |  |  | unknown | established |  |
| `km_tx_mouse` | 0x210 | w | 32 |  |  | unknown | established |  |

### Register `gpdr`

Generic pin data word. The SGI header defines it at 0x38 with bits 7:0 holding the state of the eight generic pins. Offset and name are established by the header and the PROM store; no Linux driver code read touches it, and what a write does is unknown.

### Register `ata_cmd`

ATA command block: the eight ATA task-file registers, one per 32-bit slot, each accessed as a byte; index 7 is status on read and command on write. Whether the data register at index 0 is accessed as 16 or 32 bits is decided by the IDE core, not read here.

Array of 8 registers, stride 4.

### Register `ata_ctl`

ATA control block: alternate status on read, device control on write.

### Register `km_rx_kbd`

### Register `km_rx_mouse`

### Register `km_tx_kbd`

### Register `km_tx_mouse`

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `ATA_DMA_CONTROL_WORD` | 32 | established |  |
| `ATA_PRD_LENGTH_WORD` | 32 | established |  |
| `GPCR_WORD` | 32 | established |  |
| `GPDR_WORD` | 32 | established |  |
| `GPPR_WORD` | 32 | established |  |
| `INT_OUT_WORD` | 32 | established |  |
| `OTHER_IR_WORD` | 32 | established |  |
| `PCI_ERR_ADDR_L_WORD` | 32 | established |  |
| `RX_STATUS_BYTE_WORD` | 8 | established |  |
| `SBBR_L_WORD` | 32 | established |  |
| `SERIAL_PTR_WORD` | 32 | established |  |
| `SHADOW_WORD` | 32 | established |  |
| `SIO_CR_WORD` | 32 | established |  |
| `SIO_IR_PORT_WORD` | 8 | established |  |
| `SRCIR_WORD` | 32 | established |  |
| `SRTR_WORD` | 32 | established |  |
| `SSCR_WORD` | 32 | established |  |
| `TX_CONTROL_BYTE_WORD` | 8 | established |  |

### Word `ATA_DMA_CONTROL_WORD`

ATA DMA control and status (DMA block word 7). Software writes the direction alone to program a transfer, then sets start by read-modify-write. It ends a transfer by writing stop and polling until stop reads back clear. Before arming, it writes stop if active or error is set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `error` | established |  |  | the previous transfer ended in an error |
| 3 | `active` | established |  |  | a transfer is in progress |
| 2 | `dir` | established |  |  | 1 moves data from the drive to memory, 0 from memory to the drive |
| 1 | `stop` | established |  |  | stop the engine; reads back clear when done |
| 0 | `start` | established |  |  | start the transfer |

### Word `ATA_PRD_LENGTH_WORD`

Last word of a 16-byte ATA scatter list entry. Each entry is four big-endian 32-bit words: zero, the low 32 bits of the bus address, zero, this word. The driver splits entries at 64 KB boundaries so an aligned entry can hold 0x10000 bytes, which does not fit in 16 bits; how the chip reads a length of 0x10000 is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eol` | established |  |  | last entry of the list |
| 15:0 | `length` | established |  |  | byte count |

### Word `GPCR_WORD`

Generic pin control, written through the set alias (writing a 1 sets that bit) and the clear alias (writing a 1 clears it). Pin 0 drives the external interrupt output, pin 1 is the external interrupt input, pin 3 senses keyboard and mouse presence and pins 4 to 7 select RS-232 (0) or RS-422 (1) for ports 0 to 3. The set and clear behaviour follows the register names and the SGI driver's use of the set alias; the SGI Linux driver never uses the clear alias.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `int_out_en` | established |  |  | enables the external interrupt output on its pin |
| 15:8 | `edge` | established |  |  | edge or level mode per pin; which value means edge is not stated |
| 7:0 | `dir` | established |  |  | pin direction, 1 output |

### Word `GPDR_WORD`

Generic pin data: the state of the eight pins.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `gen_pin` | established |  |  | pin state |

### Word `GPPR_WORD`

One word per generic pin, eight words. Software writes 0 or 1 to drive the pin; the serial driver uses pins 4 to 7 as the transceiver mode select.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `gen_pin` | established |  |  | single pin state |

### Word `INT_OUT_WORD`

External interrupt output control. In toggle mode (7) the output pin inverts every count+1 ticks; one tick is 520 PCI clocks, so the square wave period is 2*(count+1)*520 PCI clocks. Bit 31 reads the current output level and is the way the SGI Linux driver measures the PCI clock. Writing zero first returns the section to its power-on state, per the driver comment.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `int_out` | established |  |  | current value of the output |
| 30 | `diag` | established |  |  | timebase control; never set by the SGI Linux driver |
| 18:16 | `mode` | established |  |  | output shape; only mode 7 (toggle) is used |
| 15:0 | `count` | established |  |  | period control |

### Word `OTHER_IR_WORD`

The other interrupt status, enable-set and enable-clear words. Bit 0 follows the drive interrupt and bit 1 is the ATA DMA PCI error; bits 5:2 are the per-port serial DMA PCI errors; the generic pin field raises one bit per generic pin.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `gen_int` | established |  |  | interrupt from generic pin n, bit 24+n |
| 23 | `rt_int` | established |  |  | latch of the external interrupt output section |
| 6 | `kbd_int` | established |  |  | keyboard and mouse interrupt |
| 5:2 | `ser_memerr` | established |  |  | serial port n DMA halted by a PCI error, bit 2+n |
| 1 | `ata_memerr` | established |  |  | ATA DMA halted by a PCI error |
| 0 | `ata_int` | established |  |  | ATA drive interrupt pass-through |

### Word `PCI_ERR_ADDR_L_WORD`

Low word of the latched PCI error address. The word is read together with the high word after a DMA error interrupt. Master id 0 to 7 names a serial port (port number is the id shifted right one, bit 0 of the id is 1 for the receive ring and 0 for the transmit ring); 8 is the ATA engine; 9 to 15 are undefined. The address field holds bits 31:6 of the address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:6 | `addr` | established |  |  | address bits 31:6, in the same position as in the word |
| 5 | `mul_err` | established |  |  | more than one error occurred before the register was read |
| 4:1 | `master_id` | established |  |  | unit that caused the error |
| 0 | `valid` | established |  |  | an address was captured |

### Word `RX_STATUS_BYTE_WORD`

Status byte of a receive ring entry; one per data byte. The chip writes the whole entry. Software clears the two valid bits after consuming a byte, and treats an entry with neither valid bit set in any of its four status bytes as not yet written, since the producer pointer can run ahead of the data.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `data_valid` | established |  |  | data byte and its error bits are valid |
| 6 | `modem_valid` | established |  |  | DCD, CTS and overrun are valid |
| 5 | `dcd` | established |  |  | DCD state |
| 4 | `cts` | established |  |  | CTS state |
| 3 | `brk` | established |  |  | break |
| 2 | `frame_err` | established |  |  | framing error |
| 1 | `par_err` | established |  |  | parity error |
| 0 | `overrun` | established |  |  | characters lost |

### Word `SBBR_L_WORD`

Low word of a serial ring base for one port pair. The ring group base must be aligned to its total size (four rings); software ORs the ring size into bit 0. How the chip combines base and pointer is not stated.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `size` | established |  |  | 0 for 1 KB rings, 1 for 4 KB rings |

### Word `SERIAL_PTR_WORD`

Producer and consumer pointers are byte offsets into the ring in 8-byte steps: bits 11:3 for 4 KB rings, 9:3 for 1 KB rings. The ring is empty when producer equals consumer and full when the consumer is one entry ahead of the producer.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:3 | `ptr` | established |  |  | ring offset in entries of 8 bytes |

### Word `SHADOW_WORD`

Per-port shadow of UART state. Bits 7:0 mirror the line status bits, 23:16 the modem status bits and 31:24 the modem control register. The driver writes the modem control byte to the UART and the word back here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 28 | `loop` | established |  |  | loopback |
| 27 | `out2` | established |  |  | OUT2 |
| 26 | `out1` | established |  |  | OUT1 |
| 25 | `rts` | established |  |  | RTS |
| 24 | `dtr` | established |  |  | DTR |
| 23 | `dcd` | established |  |  | data carrier detect |
| 20 | `cts` | established |  |  | clear to send |
| 19 | `ddcd` | established |  |  | delta DCD |
| 16 | `dcts` | established |  |  | delta CTS |
| 7 | `rfce` | established |  |  | error character in receive FIFO |
| 6 | `temt` | established |  |  | transmitter empty |
| 5 | `thre` | established |  |  | transmit holding register empty |
| 4 | `bi` | established |  |  | break |
| 3 | `fe` | established |  |  | framing error |
| 2 | `pe` | established |  |  | parity error |
| 1 | `oe` | established |  |  | overrun error |
| 0 | `dr` | established |  |  | data ready |

### Word `SIO_CR_WORD`

Serial and arbitration control. Bits 3:0 are the only software-written field. Bits 9:4 are diagnostic status. The requester field encodes 0 transmit port 0, 1 receive port 0, 2 transmit port 1 and so on up to 7 receive port 3.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9 | `ata_diag_active` | inferred |  |  | ATA request is the arbitration winner; polarity taken from the name |
| 8 | `ata_diag_idle` | inferred |  |  | ATA request activity; the header comment does not say which level is idle |
| 7 | `sio_diag_idle` | established |  |  | set when no serial port has a bus request active; software waits for it after a reset |
| 6:4 | `arb_diag` | established |  |  | PCI bus requester currently granted |
| 3:0 | `cmd_pulse` | established |  |  | byte-bus strobe width; software writes 15 |

### Word `SIO_IR_PORT_WORD`

One serial port's byte of the serial interrupt status, enable-set and enable-clear words. Port n occupies bits 8n+7 down to 8n. Software acknowledges tx explicit, rx timer, delta DCD and delta CTS by writing the bit to the status word; rx high is a level condition the driver cannot acknowledge; it masks the enable until the ring drains. Transmit empty is masked the same way (inferred).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `tx_explicit` | established |  |  | a transmit entry that asked for an interrupt has been sent; acknowledged by writing the bit |
| 6 | `intr_pass` | established |  |  | pass-through of the port 16550 interrupt |
| 5 | `delta_cts` | established |  |  | CTS changed; acknowledged by writing the bit |
| 4 | `delta_dcd` | established |  |  | DCD changed; acknowledged by writing the bit |
| 3 | `rx_timer` | established |  |  | receive timer expired with data held; acknowledged by writing the bit |
| 2 | `rx_high` | established |  |  | receive ring occupancy at or above the high-water mark; level, not acknowledged by a write |
| 1 | `rx_full` | established |  |  | receive ring full; no software in the SGI Linux driver handles it |
| 0 | `tx_mt` | established |  |  | transmit ring empty |

### Word `SRCIR_WORD`

Receive consumer pointer. Writing it with bit 31 set arms the receive timer; the timer starts on the first byte received after arming.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `arm` | established |  |  | arm the receive timer |
| 11:3 | `ptr` | established |  |  | consumer offset |

### Word `SRTR_WORD`

Receive timer. The count unit is 1/16000 second, so 160 gives 10 ms.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27:16 | `current` | established |  |  | current count; read, never used by the driver |
| 11:0 | `reload` | established |  |  | reload value |

### Word `SSCR_WORD`

Serial port control. The receive threshold counts ring entries (four bytes each). The driver pauses DMA before touching the UART line control, modem control or FIFO, by writing pause and polling pause state.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `reset` | established |  |  | reset the DMA channels |
| 30 | `pause_state` | established |  |  | set when the pause has taken effect |
| 29 | `dma_pause` | established |  |  | pause DMA |
| 28 | `dma_en` | established |  |  | ring DMA enable |
| 27 | `rx_drain` | established |  |  | flush bytes held for fewer than four to the ring; cleared by the chip when the drain is done |
| 21 | `diag` | established |  |  | bypass the clock divider for simulation |
| 19 | `rx_ring_cts` | established |  |  | post a receive record when CTS changes; defined, not set by the driver |
| 18 | `rx_ring_dcd` | established |  |  | post a receive record when DCD changes |
| 17 | `hfc_en` | established |  |  | hardware flow control enable |
| 16 | `tx_timer_busy` | established |  |  | transmit timer in progress |
| 8:0 | `rx_threshold` | established |  |  | receive high-water mark in ring entries |

### Word `TX_CONTROL_BYTE_WORD`

Control byte of a transmit ring entry; one per data byte. Value 0 is an invalid byte. Type 1 sends the data byte. Types 2 (data to the modem control register) and 3 (delay of the data value in milliseconds) are defined by the SGI header; the SGI Linux driver never issues them.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `type` | established |  |  | 0 invalid, 1 valid data, 2 modem control, 3 delay |
| 5 | `int_when_done` | established |  |  | raise tx explicit after this byte is sent |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ATA_DMA_CONTROL` | 0x15c | established |  | index 7; the SGI Linux driver accesses it as a 32-bit word; bits below |
| `ATA_DMA_CONTROL_ACTIVE` | 0x8 | established |  | bit 3: read first by the start routine, which stops the engine before arming when set; name [I] |
| `ATA_DMA_CONTROL_DIR_TO_MEMORY` | 0x4 | established |  | bit 2: 1 copies ATA data to memory; the direction convention rests on the public driver's comments |
| `ATA_DMA_CONTROL_ERROR` | 0x10 | established |  | bit 4: tested; when set the start routine stores 2 and the completion routine reads it back; name [I] |
| `ATA_DMA_CONTROL_START` | 0x1 | established |  | bit 0: ORed with the direction bit and stored once to start a transfer (earlier full reading; the combined value was not re-derived); name [I] |
| `ATA_DMA_CONTROL_STOP` | 0x2 | established |  | bit 1: the value 2 is stored, then the word is read until the bit clears; name [I] |
| `ATA_DMA_COUNT_DEVICE` | 0x154 | established |  | index 5; read by the completion routine |
| `ATA_DMA_COUNT_MEMORY` | 0x158 | established |  | index 6; read by the completion routine |
| `ATA_DMA_CURRENT_HIGH` | 0x150 | inferred |  | index 4; named current memory address (high) by the SGI driver, which never accesses it |
| `ATA_DMA_CURRENT_LOW` | 0x14c | inferred |  | index 3; named current memory address (low) by the SGI driver, which never accesses it |
| `ATA_DMA_END_AREA` | 0x160 | established |  | index 8; bus address of the 128-byte end-of-transfer area |
| `ATA_DMA_LIST_HIGH` | 0x148 | established |  | index 2; the SGI Linux driver never writes it (low half only); the IRIX packet-DMA start routine writes it (coverage.md) |
| `ATA_DMA_LIST_LOW` | 0x144 | established |  | index 1; address of the scatter list; written by the SGI Linux driver and the IRIX packet-DMA start routine |
| `ATA_DMA_TIMING` | 0x140 | inferred |  | index 0; the SGI driver names it timing and the structure it overlays calls the first two words timing registers; no code in it reads or writes the word, so what it controls is unknown |
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
