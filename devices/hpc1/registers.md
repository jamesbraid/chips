<!-- generated from devices/hpc1/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 375a6b58c47ddb4d00925fe95a4934440c1d9ae9bbfb1ed95ad1a0fa3c2cbb9d -->

# SGI HPC1 peripheral controller (Indigo, R3000 and R4000 boards)

The first-generation peripheral controller of the Indigo: Ethernet, SCSI and parallel-port DMA channels, the DSP audio interface, an endian and revision byte, the auxiliary byte that bit-bangs the serial EEPROM, and the decode of the peripheral windows behind it (Ethernet, SCSI, serial, clock, interrupt controller). Offsets are from the start of one HPC1 window; the primary HPC1 sits at physical 1fb80000. Every register sits in a 32-bit slot and a narrower register uses the byte lane its field bits name. Grades say how each item was derived: established means read in a shipped IRIX driver object, the shipped developer header, a PROM image or a public driver as the source records; inferred means a reasoned reading, with the reasoning in devices/hpc1/README.md. No specification for the HPC1 is held.

Unit `hpc1`, macro prefix `HPC1`.
Default source: IRIX developer header.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| hpc1 | byte | Byte offsets from the start of one HPC1 window. A register is one 32-bit word; a fields entry gives the lane that a byte or halfword register occupies. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `enet_probe` | 0x0 | r | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `enet_xcount` | 0x8 | rw | 32 |  | hpc1 | unknown | unknown | IRIX Ethernet driver |
| `enet_cxbp` | 0xc | rw | 32 |  | hpc1 | unknown | unknown | IRIX Ethernet driver |
| `enet_nxbdp` | 0x10 | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_xbc` | 0x14 | rw | 32 |  | hpc1 | unknown | inferred | IRIX Ethernet driver; NetBSD register header |
| `enet_xpntr` | 0x18 | rw | 32 |  | hpc1 | unknown | unknown | IRIX Ethernet driver |
| `enet_xfifo` | 0x1c | rw | 32 |  | hpc1 | unknown | unknown | IRIX Ethernet driver |
| `enet_cxbdp` | 0x20 | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_cpfxbdp` | 0x24 | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_ppfxbdp` | 0x28 | rw | 32 |  | hpc1 | unknown | inferred | IRIX Ethernet driver; NetBSD register header |
| `enet_intdelay` | 0x2c | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_trstat` | 0x34 | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_rcvstat` | 0x38 | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_ctl` | 0x3c | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header; Indigo PROM |
| `enet_rcount` | 0x44 | rw | 32 |  | hpc1 | unknown | unknown | IRIX Ethernet driver |
| `enet_rbc` | 0x48 | rw | 32 |  | hpc1 | unknown | inferred | IRIX Ethernet driver; NetBSD register header |
| `enet_crbp` | 0x4c | rw | 32 |  | hpc1 | unknown | inferred | IRIX Ethernet driver |
| `enet_nrbdp` | 0x50 | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_crbdp` | 0x54 | rw | 32 |  | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `enet_rpntr` | 0x58 | rw | 32 |  | hpc1 | unknown | unknown | IRIX Ethernet driver; Indigo PROM |
| `enet_rfifo` | 0x5c | rw | 32 |  | hpc1 | unknown | unknown | IRIX Ethernet driver; Indigo PROM |
| `scsi_bc` | 0x88 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; Indigo PROM |
| `scsi_cbp` | 0x8c | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; Indigo PROM |
| `scsi_nbdp` | 0x90 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel |
| `scsi_ctrl` | 0x94 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; Indigo PROM |
| `scsi_pntr` | 0x98 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header; IRIX kernel |
| `scsi_fifo` | 0x9c | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header; IRIX kernel |
| `par_bc` | 0xa8 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX parallel driver |
| `par_cbp` | 0xac | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; Indigo PROM |
| `par_nbdp` | 0xb0 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX parallel driver |
| `par_ctrl` | 0xb4 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX parallel driver |
| `par_fifo` | 0xb8 | r | 32 |  | hpc1 | unknown | inferred | IRIX parallel driver; NetBSD register header |
| `par_dmacfg` | 0xbc | rw | 32 |  | hpc1 | unknown | unknown | NetBSD register header |
| `endian` | 0xc0 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM |
| `seeq` | 0x100 | rw | 32 | 8 | hpc1 | unknown | established | IRIX Ethernet driver; NetBSD register header |
| `wd33c93_address` | 0x120 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; Indigo PROM |
| `wd33c93_data` | 0x124 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; Indigo PROM |
| `par_status` | 0x134 | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX parallel driver |
| `dsp_dma_count` | 0x180 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header; NetBSD register header |
| `dsp_gio_low` | 0x184 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `dsp_gio_high` | 0x188 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `dsp_pbus_addr` | 0x18c | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `dsp_dma_ctrl` | 0x190 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header; NetBSD register header |
| `dsp_counter` | 0x194 | r | 32 |  | hpc1 | unknown | unknown | IRIX developer header |
| `dsp_hand_tx` | 0x198 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `dsp_hand_rx` | 0x19c | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `dsp_int_status` | 0x1a0 | r | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `dsp_int_mask` | 0x1a4 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header |
| `dsp_misc` | 0x1b0 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header; NetBSD register header; Indigo PROM |
| `dsp_burst` | 0x1b4 | rw | 32 |  | hpc1 | unknown | inferred | IRIX developer header; NetBSD register header |
| `aux` | 0x1bc | rw | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM |
| `int2_window` | 0x1c0 | rw | 32 | 16 | hpc1 | unknown | established | IRIX developer header |
| `serial_window` | 0xd00 | rw | 32 | 16 | hpc1 | unknown | established | IRIX developer header; IRIX serial driver |
| `clock_window` | 0xe00 | rw | 32 | 32 | hpc1 | unknown | established | IRIX developer header; IRIX kernel |
| `board_rev` | 0x50000 | r | 32 |  | hpc1 | unknown | established | IRIX developer header; IRIX kernel; Indigo PROM |
| `dsp_sram` | 0x60000 | rw | 32 | 32768 | hpc1 | unknown | established | IRIX developer header; NetBSD register header; Indigo PROM |

### Register `enet_probe`

The word at the window base. Software probes it with a guarded read to find out whether a controller is present at the slot; what the word holds is not stated.

### Register `enet_xcount`

Transmit count register. The driver's register dump prints it and nothing writes it; its meaning is not settled.

### Register `enet_cxbp`

Current transmit buffer pointer, by the dump label. Read by the register dump only; no driver writes it.

### Register `enet_nxbdp`

Next transmit buffer descriptor pointer: the physical address of the descriptor the transmit channel fetches next. Software writes the head of the queue here, with bits 31:29 clear, before it starts the channel.

### Register `enet_xbc`

Transmit byte count of the descriptor in progress. Named by the dump and by the public driver; no driver reads it in a decision.

### Register `enet_xpntr`

Transmit FIFO pointer, by the dump label. Only dumped.

### Register `enet_xfifo`

Transmit FIFO data port, by the dump label. Only dumped.

### Register `enet_cxbdp`

Current transmit buffer descriptor pointer. Both drivers load it with the same address they put in the next-descriptor pointer when they start or restart the channel.

### Register `enet_cpfxbdp`

Current first transmit buffer descriptor pointer: the first descriptor of the frame being sent. Written with the queue head at a restart.

### Register `enet_ppfxbdp`

Previous first transmit buffer descriptor pointer. Named by the dump and the public header; neither driver writes it.

### Register `enet_intdelay`

Receive interrupt delay count. Bit 24 set (0x01000000) disables the delay; the IRIX driver writes that value at initialisation and writes its tunable delay when it re-enables the delay after a received frame.

### Register `enet_trstat`

Transmit status and channel start. Bit 22 starts the transmit channel when written one and reads one while the channel is running. The bits above it carry the SEEQ transmit status byte; the drivers only test bit 22.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23 | `seeq_tx_status_high` | inferred |  | IRIX Ethernet driver; NetBSD register header | Top bit of the Ethernet chip transmit status byte. |
| 22 | `tx_active` | established |  | IRIX Ethernet driver; NetBSD register header | Write 1 to start transmit DMA from the descriptor in the next-descriptor pointer; reads 1 while the channel is active. |
| 21:16 | `seeq_tx_status_low` | inferred |  | IRIX Ethernet driver; NetBSD register header | Low six bits of the Ethernet chip transmit status byte, shifted up by sixteen. |

### Register `enet_rcvstat`

Receive status and channel start. Bit 14 starts the receive channel when written one and reads one while it runs; the other bits of the upper byte carry the Ethernet chip's receive status.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `seeq_rx_status_high` | inferred |  | IRIX Ethernet driver; NetBSD register header | Top bit of the Ethernet chip receive status byte. |
| 14 | `rx_active` | established |  | IRIX Ethernet driver; NetBSD register header | Write 1 to start receive DMA from the descriptor in the next-descriptor pointer; reads 1 while the channel is active. |
| 13:8 | `seeq_rx_status_low` | inferred |  | IRIX Ethernet driver; NetBSD register header | Low six bits of the Ethernet chip receive status byte. |

### Register `enet_ctl`

Ethernet channel control: reset, interrupt clear and loopback. Reading bit 1 reports a pending interrupt.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `clear_overflow` | inferred |  | IRIX Ethernet driver; NetBSD register header; Indigo PROM | Clear the receive buffer overflow condition, by the public header; the IRIX driver writes it once, after an overflow. |
| 2 | `normal_mode` | inferred |  | IRIX Ethernet driver; NetBSD register header; Indigo PROM | Both drivers keep it set in operation; clear is the loopback setting by the public header's loopback-enable bit. |
| 1 | `clear_int` | established |  | IRIX Ethernet driver; NetBSD register header; Indigo PROM | Write 1 to clear the channel interrupt; reads 1 while an interrupt is pending. |
| 0 | `reset` | established |  | IRIX Ethernet driver; NetBSD register header; Indigo PROM | Reset the Ethernet chip and the channel; held for at least 10 microseconds. |

### Register `enet_rcount`

Receive count register, by the dump label. Only dumped.

### Register `enet_rbc`

Receive byte count of the descriptor in progress.

### Register `enet_crbp`

Current receive buffer pointer, by the dump label.

### Register `enet_nrbdp`

Next receive buffer descriptor pointer: physical address of the first descriptor the receive channel fetches. Software writes the head of the ring here, with bits 31:29 clear, before it sets the receive start bit.

### Register `enet_crbdp`

Current receive buffer descriptor pointer. The IRIX driver loads it with the ring head at start and its watchdog reads it to see whether the channel has moved.

### Register `enet_rpntr`

Receive FIFO pointer, by the dump label. The PROM's early test stores the byte 0x5a to its low byte lane and reads the register after it, without a recorded check.

### Register `enet_rfifo`

Receive FIFO data port, by the dump label.

### Register `scsi_bc`

SCSI channel byte count of the descriptor being moved. The channel loads it from the descriptor; software does not write it in normal operation.

### Register `scsi_cbp`

SCSI channel current buffer pointer: the physical address of the data being moved, loaded from a descriptor.

### Register `scsi_nbdp`

SCSI next descriptor pointer. Software writes the physical address of the first descriptor, then the control register with the start bit; the channel then walks the chain by itself.

### Register `scsi_ctrl`

SCSI channel control. The reset bit holds the WD33C93 chip in reset while set. The flush bit drains the channel FIFO and the start bit reads one while the channel is active, so software sets flush and waits for the start bit to read zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `start` | established |  | IRIX developer header; IRIX kernel; Indigo PROM | Write 1 with a descriptor address loaded to start the DMA; reads 1 while the channel is active. |
| 4 | `direction` | established | scsi_direction (to_device=0, to_memory=1) | IRIX developer header; IRIX kernel; Indigo PROM | 1 moves data from the device to memory. |
| 1 | `flush` | established |  | IRIX developer header; IRIX kernel; Indigo PROM | Flush the SCSI channel buffers. |
| 0 | `reset` | established |  | IRIX developer header; IRIX kernel; Indigo PROM | Hold the WD33C93 reset line; the IRIX bus reset sets it for 25 microseconds and then clears the whole register. |

### Register `scsi_pntr`

SCSI FIFO pointer register. Present in both headers and in the chip interface table; no driver read or write of it was found.

### Register `scsi_fifo`

SCSI FIFO data port. No driver access was found.

### Register `par_bc`

Parallel port byte count with the strobe timing fields. The header gives three seven-bit timing fields at bits 30:24, 22:16 and 14:8; the driver stores a placeholder here before it loads a descriptor.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30:24 | `strobe_min` | inferred |  | IRIX developer header; IRIX parallel driver | Strobe duty cycle (mask 0x7f000000 in the header). |
| 22:16 | `strobe_lead` | inferred |  | IRIX developer header; IRIX parallel driver | Strobe leading edge (mask 0x007f0000). |
| 14:8 | `strobe_trail` | inferred |  | IRIX developer header; IRIX parallel driver | Strobe trailing edge (mask 0x00007f00). |

### Register `par_cbp`

Parallel current buffer pointer. The PROM's power-on test writes a walking one from bit 27 down to bit 0 and reads each value back, so the low 28 bits are plain storage.

### Register `par_nbdp`

Parallel next descriptor pointer: the physical address of the first descriptor, written before the control register.

### Register `par_ctrl`

Parallel port control.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `start` | established |  | IRIX developer header; IRIX parallel driver | Start DMA; reads 1 while active. |
| 6 | `flush` | established |  | IRIX developer header; IRIX parallel driver | Flush the port buffers; the stop routine sets it and polls the start bit. |
| 5 | `ignore_ack` | inferred |  | IRIX developer header; IRIX parallel driver | Ignore the acknowledge input (header). |
| 4 | `to_memory` | established |  | IRIX developer header; IRIX parallel driver | 1 for a transfer from the port to memory; the start routine ORs 0x90 for a read and 0x80 for a write. |
| 3 | `soft_ack` | established |  | IRIX developer header; IRIX parallel driver | Soft acknowledge; the reset routine sets it and clears it. |
| 2 | `polarity` | inferred |  | IRIX developer header; IRIX parallel driver | Strobe polarity (header). |
| 1 | `interrupt` | established |  | IRIX developer header; IRIX parallel driver | Reads 1 for a pending interrupt; writing 1 clears it. |
| 0 | `reset` | established |  | IRIX developer header; IRIX parallel driver | Reset the parallel port; set then cleared with a 400 microsecond wait. |

### Register `par_fifo`

Parallel FIFO status. Bits 22:16 hold the number of bytes still in the port FIFO; the stop routine drains that many bytes by hand when the count is under four.

### Register `par_dmacfg`

Parallel DMA configuration, named by the public header only. No IRIX object touches it.

### Register `endian`

DMA byte order of each channel and the controller revision. A set bit makes that channel's DMA words and descriptors little-endian; clear leaves them big-endian. Only the low byte is used.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `revision` | inferred |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | Controller revision; the developer header says 1 means the 1.5 part. Read by the public driver to tell the generations apart; the IRIX PROM and kernel never read it. |
| 4 | `dsp_little` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | DSP DMA little-endian. |
| 3 | `par_little` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | Parallel DMA little-endian. |
| 2 | `scsi_little` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | SCSI DMA little-endian. |
| 1 | `enet_little` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | Ethernet DMA little-endian. |
| 0 | `cpu_little` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | Set when the CPU runs little-endian. The PROM's first access reads this bit and, if set, stores zero to the whole word. |

### Register `seeq`

The Ethernet chip's eight registers, one per 32-bit slot with the byte in bits 7:0; register n is at 0x100 plus 4n. Registers 0 to 5 hold the station address, register 6 is the receive command and status and register 7 the transmit command and status. The registers themselves are in devices/seeq_8003.

Array of 8 registers, stride 4.

### Register `wd33c93_address`

The WD33C93's address/auxiliary-status port. The chip sits on the 15:8 byte lane of the word: a big-endian byte access is at +2 and a little-endian one at +1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `data` | established |  | IRIX developer header; IRIX kernel; Indigo PROM | The chip's byte. |

### Register `wd33c93_data`

The WD33C93's data port, on the same byte lane.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `data` | established |  | IRIX developer header; IRIX kernel; Indigo PROM | The chip's byte. |

### Register `par_status`

Parallel port external status and remote register, one byte in bits 23:16 of the word. A DMA read start stores 1 and a write start stores 3; the reset routine clears it then stores 3.

### Register `dsp_dma_count`

DSP DMA transfer length in SRAM words. See devices/hollywood-dsp.

### Register `dsp_gio_low`

Low 16 bits of the memory-side DMA address.

### Register `dsp_gio_high`

High 16 bits of the memory-side DMA address.

### Register `dsp_pbus_addr`

16-bit peripheral-bus (DSP SRAM) address of the DMA.

### Register `dsp_dma_ctrl`

DSP DMA control.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `folded` | inferred |  | IRIX developer header; NetBSD register header | 1 selects folded mode. |
| 1 | `direction` | inferred |  | IRIX developer header; NetBSD register header | 0 is MIPS to DSP; the public driver reads the opposite sense, so the direction is a recorded conflict. |
| 0 | `go` | inferred |  | IRIX developer header; NetBSD register header | Start the DMA. |

### Register `dsp_counter`

A free-running 24-bit counter; what it counts is not stated.

### Register `dsp_hand_tx`

Handshake transmit word, written by the DSP for the host.

### Register `dsp_hand_rx`

Handshake receive word, written by the host for the DSP.

### Register `dsp_int_status`

DSP-to-CPU interrupt status: bit 0 end of DMA, bit 1 the DSP wrote the transmit word, bit 2 the DSP read the receive word.

### Register `dsp_int_mask`

Enable bits for the three DSP interrupt sources.

### Register `dsp_misc`

DSP miscellaneous control. The PROM stores 9 (reset with 32K SRAM) at start-up, 1 (reset) while it loads the DSP and 8 (run, 32K SRAM) afterwards.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:4 | `pbus_extend` | inferred |  | IRIX developer header; NetBSD register header; Indigo PROM | Sign extension of a narrow peripheral-bus read: 0x70 8-bit, 0x60 16-bit, 0x40 24-bit, 0 none. |
| 3 | `sram_32k` | established |  | IRIX developer header; NetBSD register header; Indigo PROM | 1 selects 32K words of DSP SRAM, 0 selects 8K. |
| 2 | `irqa_high` | inferred |  | IRIX developer header; NetBSD register header; Indigo PROM | IRQA polarity, 1 is high. |
| 1 | `irqa` | inferred |  | IRIX developer header; NetBSD register header; Indigo PROM | Force IRQA at the polarity of bit 2. |
| 0 | `reset` | established |  | IRIX developer header; NetBSD register header; Indigo PROM | Hard reset the DSP. |

### Register `dsp_burst`

DMA burst length and spacing; the fields are not stated.

### Register `aux`

The auxiliary byte: the console LED and the four wires of the serial EEPROM. Bit 0 is shared by the LED and the EEPROM protect-register enable.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `eeprom_do` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | Data from the EEPROM to the CPU; read-only. |
| 3 | `eeprom_di` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | Data from the CPU to the EEPROM. |
| 2 | `eeprom_sk` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | EEPROM serial clock; left high between cycles. |
| 1 | `eeprom_cs` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | EEPROM chip select. |
| 0 | `led_pre` | established |  | IRIX developer header; IRIX kernel; NetBSD register header; Indigo PROM | Console LED, and the FM93CS56 PRE pin; both drivers save it and restore it around every EEPROM cycle. |

### Register `int2_window`

The interrupt controller window, 64 bytes at 0x1c0. The registers are in the interrupt controller's own unit; the controller is not part of the HPC1.

Array of 16 registers, stride 4.

### Register `serial_window`

Four 16-byte blocks of 8-bit registers at 0xd00, 0xd10, 0xd20, 0xd30, each register in its own slot with the byte in bits 7:0 (offset +3 big-endian). Blocks 0 to 2 are Z85C30 serial controllers; block 3 holds the two headphone gain converters. The chip's registers are in its own unit.

Array of 16 registers, stride 4.

### Register `clock_window`

The battery-backed real-time clock window, one 8-bit register per 32-bit slot, accessed by word at the slot. The chip's registers are in its own unit.

Array of 32 registers, stride 4.

### Register `board_rev`

Board revision word, in the modem SRAM space. The kernel inverts the word and takes bits 14:12; bit 15 is the header's marker for the HP1 base board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `hp1_marker` | inferred |  | IRIX developer header; IRIX kernel; Indigo PROM | Header name REV_HP1. |
| 14:12 | `revision_inverted` | established |  | IRIX developer header; IRIX kernel; Indigo PROM | Revision, active low. |

### Register `dsp_sram`

The DSP SRAM, one 24-bit word per 32-bit slot, 128 KB.

Array of 32768 registers, stride 4.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `ENET_DESC_W0` | 32 | established | IRIX Ethernet driver; NetBSD register header |
| `ENET_DESC_W1` | 32 | established | IRIX Ethernet driver; NetBSD register header |
| `ENET_DESC_W2` | 32 | established | IRIX Ethernet driver; NetBSD register header |
| `SCSI_DESC_W0` | 32 | established | IRIX developer header; IRIX kernel |
| `SCSI_DESC_W1` | 32 | established | IRIX developer header; IRIX kernel |
| `SCSI_DESC_W2` | 32 | established | IRIX developer header |

### Word `ENET_DESC_W0`

Word 0 of the Ethernet DMA descriptor: flags and byte count. The HPC3 puts the buffer address first and the flags second; the HPC1 order is the reverse.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eop` | inferred |  | IRIX Ethernet driver; NetBSD register header | End of packet. |
| 30 | `own` | inferred |  | IRIX Ethernet driver; NetBSD register header | Ownership flag. The public driver sets it when it posts a receive descriptor and reads a clear bit as received; the IRIX driver sets it on queued transmit descriptors and clears it when it reclaims them. Which side clears it in hardware is not settled. |
| 15 | `intr` | inferred |  | IRIX Ethernet driver; NetBSD register header | Interrupt when finished. |
| 12:0 | `byte_count` | established |  | IRIX Ethernet driver; NetBSD register header | Buffer size on queue; on a receive the HPC leaves the unused count. |

### Word `ENET_DESC_W1`

Word 1 of the Ethernet DMA descriptor: the buffer address with the end-of-chain flag.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eochain` | established |  | IRIX Ethernet driver; NetBSD register header | Last descriptor of the chain. |
| 27:0 | `buffer` | established |  | IRIX Ethernet driver; NetBSD register header | Physical buffer address. |

### Word `ENET_DESC_W2`

Word 2 of the Ethernet DMA descriptor.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27:0 | `next` | established |  | IRIX Ethernet driver; NetBSD register header | Physical address of the next descriptor. |

### Word `SCSI_DESC_W0`

Word 0 of the SCSI and parallel DMA descriptor. A descriptor is three hardware words in a 16-byte slot; the fourth word is software-only. The words are in the byte order that the endian register selects for the channel.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12:0 | `byte_count` | established |  | IRIX developer header; IRIX kernel | Transfer size in bytes, at most 8191. |

### Word `SCSI_DESC_W1`

Word 1 of the SCSI and parallel DMA descriptor.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `eox` | established |  | IRIX developer header; IRIX kernel | Last descriptor of the chain. |
| 27:0 | `buffer` | established |  | IRIX developer header; IRIX kernel | Physical buffer address. |

### Word `SCSI_DESC_W2`

Word 2 of the SCSI and parallel DMA descriptor.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27:0 | `next` | established |  | IRIX developer header | Physical address of the next descriptor. |

## Enums

### Enum `scsi_direction`

| Label | Value | Grade | Source |
|---|---|---|---|
| `to_device` | 0 | established | IRIX developer header |
| `to_memory` | 1 | established | IRIX developer header |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `EEPROM_OP_PROTECT_CLEAR` | 0xffff | established | IRIX developer header | Protect register clear, issued with PRE high. |
| `EEPROM_OP_READ` | 0xc000 | established | IRIX developer header | Instruction word: start bit, read, address in bits 12:5 (shifted out MSB first, 11 bits). |
| `EEPROM_OP_WRITE` | 0xa000 | established | IRIX developer header | Write instruction; the 16 data bits follow. |
| `EEPROM_OP_WRITE_ALL` | 0x8800 | inferred | IRIX developer header | Write-all instruction, named by the shipped header; no code was seen using it. |
| `EEPROM_OP_WRITE_DISABLE` | 0x8000 | established | IRIX developer header | Write-disable instruction. |
| `EEPROM_OP_WRITE_ENABLE` | 0x9800 | established | IRIX developer header | Write-enable instruction. |
| `NVRAM_ENET_OFFSET` | 0xfa | established | IRIX developer header | Station address, six bytes, the protected tail of the EEPROM. |
| `NVRAM_REVISION` | 0x6 | established | IRIX developer header | Layout revision the PROM and the kernel require in byte 1. |
| `NVRAM_SIZE` | 0x100 | established | IRIX developer header | Serial EEPROM size in bytes. |
| `SCSI_START_DMA` | 0x80 | established | IRIX developer header | Control value that starts a memory-to-device transfer. |
| `SCSI_START_DMA_TO_MEM` | 0x90 | established | IRIX developer header | Control value that starts a device-to-memory transfer. |
