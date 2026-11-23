<!-- generated from devices/int2/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 ddb7d5c9a928bcccdae1a8a3a03b7439bba8c65460f360e653d4e8612963b52e -->

# INT2 local interrupt controller and 8254 timer block (Indigo, R3000 and R4000 boards)

The Indigo's interrupt multiplexer: two local interrupt status and mask registers, the VME interrupt status and masks, a five-bit port register that also acknowledges the vertical-retrace latch, a timer acknowledge strobe and an 8254 timer block. Offsets are from the INT2 base, physical 0x1fb801c0 on both the R3000 and R4000 Indigo boards, and name the byte a big-endian CPU addresses: each register is one byte on a 4-byte stride and sits in the low byte lane, so a little-endian CPU addresses the same register 3 bytes lower (0x1fb801c0 for local 0 status). Names follow the shipped IRIX header for the R4000 Indigo and, for the 8254, the standard part; NetBSD's names for the same offsets are in the page. Grades: established means read in full in the R4000 Indigo kernel object or the 4.0.5D PROM (the README cites the addresses) or stated by a public header; inferred means a reasoned reading; unknown means nothing shipped settles it. Nothing was measured on a board. The prose is in devices/int2/README.md and the interrupt routing table in the R4000 Indigo platform directory.

Unit `int2`, macro prefix `INT2`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `local0_status` | 0x3 | r | 8 |  |  | unknown | established |  |
| `local0_mask` | 0x7 | rw | 8 |  |  | 0x0 (inferred) | established |  |
| `local1_status` | 0xb | r | 8 |  |  | unknown | established |  |
| `local1_mask` | 0xf | rw | 8 |  |  | 0x0 (inferred) | established |  |
| `vme_status` | 0x13 | r | 8 |  |  | unknown | established |  |
| `vme0_mask` | 0x17 | rw | 8 |  |  | 0x0 (inferred) | established |  |
| `vme1_mask` | 0x1b | rw | 8 |  |  | 0x0 (inferred) | established |  |
| `port_config` | 0x1f | rw | 8 |  |  | unknown | established |  |
| `timer_ack` | 0x23 | w | 8 |  |  | unknown | established |  |
| `error_status` | 0x27 | r | 8 |  |  | unknown | unknown |  |
| `timer0` | 0x33 | rw | 8 |  |  | unknown | established |  |
| `timer1` | 0x37 | rw | 8 |  |  | unknown | established |  |
| `timer2` | 0x3b | rw | 8 |  |  | unknown | established |  |
| `timer_control` | 0x3f | w | 8 |  |  | unknown | established |  |

### Register `local0_status`

Raw state of the eight local 0 sources, one bit each, high while the source asserts. It is not gated by the mask: the PROM clears both masks and then reads status, and IRIX ANDs status with the mask in software. Bit layout is the LOCAL0 constants. A qtest can discriminate: a write has no effect; the bit follows the source signal.

### Register `local0_mask`

Enables local 0 sources toward the CPU. A one bit lets the source raise the local 0 output. All eight bits read back what was written: the PROM writes 00 aa cc f0 ff 55 33 0f in turn and compares. A qtest can discriminate: byte write then read of 0xaa and 0x55.

### Register `local1_status`

Raw state of the eight local 1 sources. Same rules as local 0 status. With all masks clear the PROM expects bits 0, 2, 3 and 4 to read zero and tolerates bits 1, 5, 6 and 7.

### Register `local1_mask`

Enables local 1 sources toward the CPU. All eight bits read back.

### Register `vme_status`

VME interrupt request levels 1 to 7 in bits 1 to 7 (inferred from the header names; no shipped R4000 Indigo code reads it for VME). Bit 0 is read by the GR2 retrace handler as the vertical-retrace status, active low (the header says 'no interrupt' when set): the handler polls it up to ten times 1 microsecond apart. NetBSD names this offset the map status register of the Indy's INT3 and gives it a different meaning.

### Register `vme0_mask`

Which VME levels may raise local 0 bit 7. The IRIX routine that targets an I/O interrupt at the CPU sets bit n in this register. The PROM never reads this register back.

### Register `vme1_mask`

Which VME levels may raise local 1 bit 3. The PROM writes 0x5a and checks the read-back, so all eight bits hold.

### Register `port_config`

Five-bit read/write port at the offset NetBSD calls the map polarity register on the Indy generation. The header calls it the LED and serial-port configuration register. Bits 1 and 2 are the RTS lines of serial ports 0 and 1 (the serial driver sets and clears them to switch the port between RS-232 and RS-422 modes); bit 3 is the vertical-retrace interrupt latch control; bit 4 is named power in the header. The PROM writes 0x16 during start-up. The header also names bits 1 to 3 as LEDs on the R4000 board and bit 0 as a cache parity flag; which role a bit plays on which board, and the LED polarity, are not settled.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `power` | unknown |  |  | PCON_POWER. The PROM sets it at start-up and no shipped code clears it; the header comment says power off, so its polarity is not settled. |
| 3 | `vr_interrupt_latch` | established |  |  | Vertical retrace interrupt latch control. The graphics retrace handlers write it clear, flush the bus and write it set again to acknowledge the interrupt; it is set the rest of the time. The header also names it LED_GFX. |
| 2 | `ser1_rts` | established |  |  | The other serial port's select, same use as bit 1; the header also names it LED_IDLE. |
| 1 | `ser0_rts` | established |  |  | One serial port's RS-232 or RS-422 select (the header names it RTS and TX+ for port 0). The serial driver sets it when the port opens and clears it for RS-422 mode; the header also names it LED_HEART. |
| 0 | `parity_or_ext_clock` | unknown |  |  | PCON_PARITY on the R4000 board (cache parity error), external serial clock on the R3000 board. No shipped code reads or writes it. |

### Register `timer_ack`

Write-only strobe. Writing 1 clears the timer 0 interrupt latch, 2 clears timer 1. IRIX acknowledges timer 0 with 1 and timer 1 with 2; the PROM writes 3 at start to clear both. Writing zero bits has no effect. A qtest can discriminate: timer 0 interrupt line drops after a write of 1 and timer 1 stays asserted.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `timer1` | established |  |  |  |
| 0 | `timer0` | established |  |  |  |

### Register `error_status`

No R4000 Indigo kernel object or the PROM touches this offset. NetBSD defines it for the Indy generation, where Linux calls it reserved on INT2. Nothing shipped for the Indigo reads it.

### Register `timer0`

8254 counter 0 data, one byte at a time per the control word. Its output is the timer 0 interrupt (CPU IP4). IRIX loads it with 50 after control word 0x34, giving 100 Hz from the 5 kHz counter 2 output.

### Register `timer1`

8254 counter 1 data. Its output is the timer 1 interrupt (CPU IP5), the profiling and fast clock. IRIX loads it with 5000 divided by the wanted rate, MSB shifted down, after control word 0x74.

### Register `timer2`

8254 counter 2 data. Its output clocks counters 0 and 1 (NetBSD's header states this; IRIX's counter 0 and 1 divisors only make sense with it). IRIX counts 200 into it; the PROM reuses it as a 100 Hz reference with count 10000 and latches it with control word 0x80.

### Register `timer_control`

8254 control word. The R4000 Indigo kernel and the PROM only write it. Standard 8254 layout; the values seen are 0x34, 0x74 and 0xb4 (counter 0, 1, 2 in mode 2 with LSB then MSB), 0x32, 0x72 and 0xb2 (mode 1) and 0x80 (latch counter 2) and 0xb8 (counter 2 mode 4).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `counter` | established |  |  |  |
| 5:4 | `rw` | established |  |  |  |
| 3:1 | `mode` | established |  |  |  |
| 0 | `bcd` | established |  |  |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ACK_TIMER0` | 0x1 | established |  | Timer acknowledge bit for timer 0. |
| `ACK_TIMER1` | 0x2 | established |  | Timer acknowledge bit for timer 1. |
| `LOCAL0_CENTR` | 0x2 | established |  | Local 0 bit 1: parallel (Centronics) port, from the HPC1 parallel channel. |
| `LOCAL0_DUART` | 0x20 | established |  | Local 0 bit 5: the serial controllers, ORed. |
| `LOCAL0_ENET` | 0x8 | established |  | Local 0 bit 3: Ethernet. |
| `LOCAL0_FIFO` | 0x1 | established |  | Local 0 bit 0: GIO slot 0 interrupt, also named FIFO full. |
| `LOCAL0_GDMA` | 0x10 | established |  | Local 0 bit 4: graphics DMA done. |
| `LOCAL0_GIO1` | 0x40 | established |  | Local 0 bit 6: GIO slot 1 (graphics geometry engine, or a second HPC1). |
| `LOCAL0_SCSI` | 0x4 | established |  | Local 0 bit 2: SCSI. |
| `LOCAL0_VME0` | 0x80 | established |  | Local 0 bit 7: VME interrupt group 0, gated by the VME 0 mask. |
| `LOCAL1_ACFAIL` | 0x20 | established |  | Local 1 bit 5: AC power failure. |
| `LOCAL1_DSP` | 0x10 | established |  | Local 1 bit 4: DSP, from the HPC1 DSP interrupt block. |
| `LOCAL1_GIO2` | 0x80 | established |  | Local 1 bit 7: GIO slot 2, which carries the graphics vertical retrace. |
| `LOCAL1_GR1MODE` | 0x2 | established |  | Local 1 bit 1: the GR1 mode input on the R4000 board, the case interlock on the R3000 board (the header names it for both boards). |
| `LOCAL1_VIDEO` | 0x40 | established |  | Local 1 bit 6: video option. |
| `LOCAL1_VME1` | 0x8 | established |  | Local 1 bit 3: VME interrupt group 1, gated by the VME 1 mask. |
| `TIMER_MASTER_HZ` | 0xf4240 | inferred |  | 8254 clock input. IRIX programs counter 2 with 200 and uses 5000 as the counter 2 output rate, and the PROM programs it with 10000 for a 100 Hz reference; both agree only at 1 MHz. No shipped header states it. |
