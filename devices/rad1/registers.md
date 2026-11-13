<!-- generated from devices/rad1/registers.toml by defs-gen - do not edit, change the source -->

# SGI RAD digital audio ASIC (PCI 10a9:0005) register contract

Register file of the RAD audio ASIC seen on the Octane base board (PCI revision 0xc0) and on the Onyx2 and Origin 2000 MediaIO card (revision 0x70). Offsets are in PCI BAR0, which the shipped driver maps as 0x2000 bytes. The shipped drivers touch the chip only with aligned 32-bit accesses, except the subcode buffers (64-bit) and one 64-bit write to the clock register. Grades say how the layout was derived from software; none of it is a silicon measurement, and reset values are unknown unless stated. Board variants are called modes after the PCI revision's high nibble: 7 for MediaIO, 12 (0xc) for the Octane base board, 13 (0xd) for the PCI audio board; the three modes write a different subset of the registers at start. Interrupts: the shipped drivers connect no data or status interrupt (they poll a completion word in host memory and read position registers), and register only a PCI error handler. Whether the silicon can raise one is unknown. DMA: a descriptor RAM of 12-byte entries, a per-channel working descriptor, and a host-memory status ring that mirrors the position registers; see the DMA items below.

Unit `rad1`, macro prefix `RAD1`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pos_adat_in_a` | 0x4 | r | 32 |  |  | unknown | established |  |
| `pos_adat_in_b` | 0x8 | r | 32 |  |  | unknown | established |  |
| `pos_aes_in_a` | 0xc | r | 32 |  |  | unknown | established |  |
| `pos_aes_in_b` | 0x10 | r | 32 |  |  | unknown | established |  |
| `pos_analog_in_a` | 0x14 | r | 32 |  |  | unknown | established |  |
| `pos_analog_b` | 0x18 | r | 32 |  |  | unknown | established |  |
| `pos_adat_out_a` | 0x1c | r | 32 |  |  | unknown | established |  |
| `pos_adat_out_b` | 0x20 | r | 32 |  |  | unknown | established |  |
| `pos_aes_out_a` | 0x24 | r | 32 |  |  | unknown | established |  |
| `pos_aes_out_b` | 0x28 | r | 32 |  |  | unknown | established |  |
| `pos_analog_out_a` | 0x2c | r | 32 |  |  | unknown | established |  |
| `ust_counter` | 0x30 | r | 32 |  |  | unknown | established |  |
| `sync_status` | 0x34 | r | 32 |  |  | unknown | inferred |  |
| `ust_control` | 0x40 | w | 32 |  |  | unknown | inferred |  |
| `adat_in_ctrl` | 0x44 | rw | 32 |  |  | unknown | established |  |
| `aes_in_ctrl` | 0x48 | rw | 32 |  |  | unknown | established |  |
| `analog_in_ctrl` | 0x4c | rw | 32 |  |  | unknown | established |  |
| `adat_out_ctrl` | 0x50 | rw | 32 |  |  | unknown | established |  |
| `aes_out_ctrl` | 0x54 | rw | 32 |  |  | unknown | established |  |
| `analog_out_ctrl` | 0x58 | rw | 32 |  |  | unknown | established |  |
| `status_ctrl` | 0x5c | w | 32 |  |  | unknown | established |  |
| `output_misc` | 0x70 | w | 32 |  |  | unknown | inferred |  |
| `config_74` | 0x74 | w | 32 |  |  | unknown | unknown |  |
| `config_78` | 0x78 | w | 32 |  |  | unknown | unknown |  |
| `gain` | 0x7c | w | 32 |  |  | unknown | established |  |
| `central_ctrl` | 0x80 | w | 32 |  |  | unknown | inferred |  |
| `mode_84` | 0x84 | w | 32 |  |  | unknown | unknown |  |
| `gpio_relay` | 0x88 | w | 32 |  |  | unknown | inferred |  |
| `gpio_data` | 0x8c | w | 32 |  |  | unknown | inferred |  |
| `analog_out_mode` | 0x90 | w | 32 |  |  | unknown | established |  |
| `clockgen_load` | 0xa0 | w | 32 |  |  | unknown | established |  |
| `clockgen_frac` | 0xa4 | w | 32 |  |  | unknown | established |  |
| `clockgen_master_3` | 0xa8 | w | 32 |  |  | unknown | inferred | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg |
| `clockgen_master_2` | 0xac | w | 32 |  |  | unknown | inferred | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg |
| `clockgen_master_1` | 0xb0 | w | 32 |  |  | unknown | inferred | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg |
| `clockgen_master_0` | 0xb4 | w | 32 |  |  | unknown | inferred | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg |
| `config_b8` | 0xb8 | w | 32 |  |  | unknown | unknown |  |
| `config_bc` | 0xbc | w | 32 |  |  | unknown | unknown |  |
| `desc_lo` | 0x400 | rw | 32 | 16 |  | unknown | established |  |
| `desc_hi` | 0x404 | rw | 32 | 16 |  | unknown | established |  |
| `desc_ctrl` | 0x408 | rw | 32 | 16 |  | unknown | established |  |
| `work_adat_in_lo` | 0x4c0 | rw | 32 |  |  | unknown | established |  |
| `work_adat_in_ctrl` | 0x4c4 | rw | 32 |  |  | unknown | established |  |
| `work_aes_in_lo` | 0x4c8 | rw | 32 |  |  | unknown | established |  |
| `work_aes_in_ctrl` | 0x4cc | rw | 32 |  |  | unknown | established |  |
| `work_analog_in_lo` | 0x4d0 | rw | 32 |  |  | unknown | established |  |
| `work_analog_in_ctrl` | 0x4d4 | rw | 32 |  |  | unknown | established |  |
| `work_adat_in_sub_lo` | 0x4d8 | rw | 32 |  |  | unknown | established |  |
| `work_adat_in_sub_ctrl` | 0x4dc | rw | 32 |  |  | unknown | established |  |
| `work_aes_in_sub_lo` | 0x4e0 | rw | 32 |  |  | unknown | established |  |
| `work_aes_in_sub_ctrl` | 0x4e4 | rw | 32 |  |  | unknown | established |  |
| `work_adat_out_lo` | 0x4e8 | rw | 32 |  |  | unknown | established |  |
| `work_adat_out_ctrl` | 0x4ec | rw | 32 |  |  | unknown | established |  |
| `work_aes_out_lo` | 0x4f0 | rw | 32 |  |  | unknown | established |  |
| `work_aes_out_ctrl` | 0x4f4 | rw | 32 |  |  | unknown | established |  |
| `work_analog_out_lo` | 0x4f8 | rw | 32 |  |  | unknown | established |  |
| `work_analog_out_ctrl` | 0x4fc | rw | 32 |  |  | unknown | established |  |
| `status_lo` | 0x500 | rw | 32 |  |  | unknown | established |  |
| `status_limit` | 0x504 | rw | 32 |  |  | unknown | established |  |
| `work_adat_in_hi` | 0x508 | rw | 32 |  |  | unknown | established |  |
| `work_aes_in_hi` | 0x50c | rw | 32 |  |  | unknown | established |  |
| `work_analog_in_hi` | 0x510 | rw | 32 |  |  | unknown | established |  |
| `work_adat_in_sub_hi` | 0x514 | rw | 32 |  |  | unknown | established |  |
| `work_aes_in_sub_hi` | 0x518 | rw | 32 |  |  | unknown | established |  |
| `work_adat_out_hi` | 0x51c | rw | 32 |  |  | unknown | established |  |
| `work_aes_out_hi` | 0x520 | rw | 32 |  |  | unknown | established |  |
| `work_analog_out_hi` | 0x524 | rw | 32 |  |  | unknown | established |  |
| `status_hi` | 0x528 | rw | 32 |  |  | unknown | established |  |
| `adat_out_subcode_a` | 0x1000 | rw | 64 | 15 |  | unknown | established |  |
| `adat_out_subcode_b` | 0x1080 | rw | 64 | 15 |  | unknown | established |  |
| `aes_out_subcode_a` | 0x1100 | rw | 64 | 16 |  | unknown | established |  |
| `aes_out_subcode_b` | 0x1180 | rw | 64 | 16 |  | unknown | established |  |
| `aes_out_subcode_extra_a` | 0x1200 | rw | 64 | 2 |  | unknown | established |  |
| `aes_out_subcode_extra_b` | 0x1210 | rw | 64 | 2 |  | unknown | established |  |

### Register `pos_adat_in_a`

Sample-position register, ADAT input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_adat_in_b`

Sample-position register, ADAT input, position B; also the ADAT-input subcode channel's position (read at shift 4). The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_aes_in_a`

Sample-position register, AES3 input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_aes_in_b`

Sample-position register, AES3 input, position B; also the AES3-input subcode channel's position (read at shift 4). The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_analog_in_a`

Sample-position register, analog input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_analog_b`

Sample-position register, analog input position B in bits 31:18; the analog output reads bits 17:4 of this same register as its position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_adat_out_a`

Sample-position register, ADAT output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_adat_out_b`

Sample-position register, ADAT output, position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_aes_out_a`

Sample-position register, AES3 output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_aes_out_b`

Sample-position register, AES3 output, position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `pos_analog_out_a`

Sample-position register, analog output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:18 | `frame_count` | established |  |  | 14-bit frame count; the driver masks it with 0x3fff after the shift |
| 17:0 | `ust_latch` | inferred |  |  | Low bits of the free-running counter at the frame named by frame_count; the driver splices them into its timestamp. Inferred |

### Register `ust_counter`

Free-running counter that the driver reads for timestamps and a liveness check: two reads 10 microseconds apart must differ by at least 3. No write to it exists. The tick period is inferred to be about 1 microsecond (the driver scales by 800 or 960 ns); the reset routine that runs on the PCI audio board stores 960 ns (UST_TICK_NS_FIXED) or a period computed from the Bedrock register, and the choice is unknown. Reset value, wrap, and read side effects are unknown. On board mode 7 it runs from reset with no enable write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | inferred |  |  | Counter value; tick period inferred, not measured |

### Register `sync_status`

Receiver and video-reference status. The driver reads it only through the status slot copy. The bits are undecoded; use is established, meaning inferred.

### Register `ust_control`

Controls the counter on the Octane board. The bit meanings, whether the writes are pulses, and whether the counter resets are unknown. On the PCI audio board (mode 13) the reset routine writes 6 then 2 when the Bedrock flag is set or the brick type is 55, 56, 57, 69 or 81, and 4 then 0 otherwise (see docs/rad1.md).

### Register `adat_in_ctrl`

ADAT input channel control. Start value 0xa0000008 is written unconditionally; the other bits are undecoded. The shadow word is written whole; the driver clears the enable at subsystem start.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `subcode_enable` | established |  |  | Enable of the ADAT-input subcode channel (type 7) |
| 0 | `enable` | established |  |  | Channel DMA enable |

### Register `aes_in_ctrl`

AES3 input channel control. Start value 0x10. The shadow word is written whole; the driver clears the enable at subsystem start.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `subcode_enable` | established |  |  | Enable of the AES3-input subcode channel (type 6) |
| 0 | `enable` | established |  |  | Channel DMA enable |

### Register `analog_in_ctrl`

Analog input channel control. Start value is 0x03000000 on board mode 12 and 0x05000000 on modes 7 and 13. On mode 7 bit 27 is also the serial clock of the video-clock mux interface: the driver clears it and sets it once per shifted bit, preserving the enable bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27 | `mux_clock` | established |  |  | Mux serial clock, mode 7 only |
| 0 | `enable` | established |  |  | Channel DMA enable |

### Register `adat_out_ctrl`

ADAT output channel control. Start value 0x60000000 on modes 7 and 12; on mode 13 the reading above leaves the earlier value unknown, but a second reading of the shipped drivers finds 0x20000000 written there (see docs/rad1.md, Not settled). The shadow word is written whole; the driver clears the enable at subsystem start.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  |  | Channel DMA enable |

### Register `aes_out_ctrl`

AES3 output channel control. Start value 0x40000000 on modes 7 and 12 and 0 on mode 13. The driver sets bits 2 and 3 as output metadata flags without starting audio. Linux pairs 0x40000000 with clock generator 2. The shadow word is written whole; the driver clears the enable at subsystem start.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:2 | `metadata_flags` | inferred |  |  | Metadata flag bits the subcode writer changes; meaning inferred |
| 0 | `enable` | established |  |  | Channel DMA enable |

### Register `analog_out_ctrl`

Analog output channel control. Idle value 0x20000000, running 0x20000001. Software treats bit 0 as the start and the Octane PROM as busy: it waits for the bit to read clear after a one-shot transfer, so hardware clears it when the last descriptor ends. A stop routine reads the register back twice after clearing the enable.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `clock_gen2` | inferred |  |  | Selects clock generator 2; used by the Octane PROM. The pattern bit 28 + n selects generator n fits all three writers but no source states it |
| 29 | `clock_gen1` | inferred |  |  | Selects clock generator 1; set in the IRIX and Linux idle value |
| 25 | `line_mux` | unknown |  |  | Set by a vendor diagnostic as a line-output multiplexer select; effect unknown |
| 0 | `enable` | established |  |  | Start and busy |

### Register `status_ctrl`

Starts and stops the status ring. One shot is 0x40001, continuous is the interval field plus 0x40003, stop is 0x1fffc. Bit meanings beyond the grade of each field are undecoded.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 18 | `go` | unknown |  |  | Set in both start words; meaning unknown |
| 16:2 | `interval` | inferred |  |  | Completion interval: the driver programs 250 * 33 + 1 = 8251, read as 250 microseconds of 33 MHz clocks. The stop word sets all of these bits |
| 1 | `continuous` | inferred |  |  | Set with start to keep completing slots around the ring |
| 0 | `start` | inferred |  |  | Set to start a transfer; clear in the stop word |

### Register `output_misc`

Output control shadow. Bring-up value 0x1500; halt ORs bit 8. A vendor PROM writes 0x480. Write-and-shadow: the drivers never read it back.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `mute` | inferred |  |  | Analog output mute; set when the analog-output interface parameter is above zero and at halt. Name inferred |
| 6 | `subcode_enable` | inferred |  |  | Output subcode transmit enable; set by the subcode transmit start and cleared at subsystem start |

### Register `config_74`

Written 0x08000010 once at start on every board mode. Purpose unknown.

### Register `config_78`

Written 0x00fac688 once at start on every board mode. Purpose unknown.

### Register `gain`

On analog-capable boards: four gain bytes, each the driver's dB value plus 0x48, with 0 meaning mute; the whole shadow is written on each change. Start value 0xd6d6d6d6. On the PCI board (mode 13) the register instead carries the video-clock mux word.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `out_right` | established |  |  | Output right gain byte |
| 23:16 | `out_left` | established |  |  | Output left gain byte |
| 15:8 | `in_right` | established |  |  | Input right gain byte |
| 7:0 | `in_left` | established |  |  | Input left gain byte |

### Register `central_ctrl`

Block reset and receiver control, written whole from a shadow. At start the driver writes 0xffffffff, 0xffe3cffe, 0xffe3c0fe, 0xffe24070, then 0xffe20000, with 1 ms delays in between, so a set bit is read as holding a block in reset. Linux brackets each clock-generator load with 0xffe20000 | (0x100 << n) before and 0xffe20000 after. Whole-register meaning is inferred; the bits below are the ones the drivers name by use.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 14 | `analog_out_if_reset` | inferred |  |  | External analog-output interface reset; cleared by every board's start routine. Name inferred |
| 11:8 | `clockgen_reset` | inferred |  |  | Bit 8 + n holds clock generator n in reset; cleared by the load routine. Inferred from the driver and Linux |
| 7 | `adat_rx_resync` | inferred |  |  | ADAT receiver resync pulse, pulsed every 1024th status pass while locked. Name inferred |
| 6 | `adat_rx_enable` | inferred |  |  | ADAT receiver enable; cleared when starting an ADAT input with no signal. Name inferred |

### Register `mode_84`

Written 0 at start on board modes 7 and 13; skipped on mode 12. Purpose unknown.

### Register `gpio_relay`

General-purpose output 1. On the Octane board a vendor PROM treats it as the analog-output relay: 3 releases the mute and 2 applies it; halt writes 2 then 0. On the MediaIO card the mux routine writes 2 then 3 after its 16 shifted bits, which latches the word into the clock-selection logic (the latch strobe; effect inferred). It has no effect on any DMA channel as far as the sources show. On the PCI audio board (mode 13) a second reading of the shipped drivers finds 0 written here at start, which the reading above does not cover.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `bit1` | inferred |  |  | Written 1 in the latch-start and mute values |
| 0 | `bit0` | inferred |  |  | Written 1 to release the relay mute and to finish a mux latch, 0 at halt |

### Register `gpio_data`

General-purpose output 2. On the MediaIO card (mode 7) it is the serial data line of the 16-bit video-clock mux: for each of 16 bits, most significant first, the driver writes (bit | 2), then drops and raises the clock on the analog input control register (bit 27), and after all 16 bits writes 2 then 3 to gpio_relay as the latch strobe and restores this register from a shadow. Separately every 1024 status passes (about 1.024 s) the driver rewrites it as (selector | 2), flipping the selector between 0 and 1, which is the 3, 2, 3, 2 pattern seen on the bus: the selector alternates 0 and 1 between writes, bit 1 stays set, and the driver samples bit 10 of the register 0x34 mirror in the status slot between writes (what that probes is unknown). On the Octane board a vendor PROM uses it as the DAC mute: 3 mutes and 2 unmutes, and the unmute also writes 0x03000000 to the analog input control. On the PCI audio board (mode 13) a second reading of the shipped drivers finds 0 written here at start.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `const1` | inferred |  |  | Set in every value the shipped driver writes while streaming; cleared only by the start and halt zero writes |
| 0 | `data` | inferred |  |  | Serial data bit (mux shift), status-probe selector (periodic write), or DAC mute on mode 12 |

### Register `analog_out_mode`

Analog-output level or mode. Written 2 on board modes 7 and 12, 0 on mode 13, and 2 or 3 when the output's interface parameter selects it. What the settings select is unknown.

### Register `clockgen_load`

Loads one clock generator: set select bit 28 + n and the integer divisor minus one in the low bits. Rate = master / (divisor + remainder / denominator), with the remainder in clockgen_frac. A 64-bit store to this offset appears in one setup path. Bring-up value 0x02000001 loads no generator (bit 25 is set in such words; meaning unknown). Linux writes flag bits 10:9 as 0x600 or 0x200 and the Octane PROM 0x400; their effect is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `select` | established |  |  | Bit 28 + n loads generator n; several bits load several generators with the same divisor (inferred) |
| 10:9 | `flags` | unknown |  |  | Observed as 0x600 or 0x200 from Linux and IRIX; effect unknown |
| 8:0 | `divisor_minus_1` | inferred |  |  | Integer divisor less one; field width inferred from the Linux layout |

### Register `clockgen_frac`

Fractional part of the clock divisor: the remainder in bits 31:16 and 0x10000 minus the denominator in bits 15:0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `remainder` | established |  |  | Remainder of the divisor |
| 15:0 | `denominator_complement` | established |  |  | 0x10000 minus the denominator |

### Register `clockgen_master_3`

Master clock select of clock generator 3, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `master_192k` | inferred |  | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg | 1 selects the 192 kHz master, 0 the 176.4 kHz master |

### Register `clockgen_master_2`

Master clock select of clock generator 2, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `master_192k` | inferred |  | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg | 1 selects the 192 kHz master, 0 the 176.4 kHz master |

### Register `clockgen_master_1`

Master clock select of clock generator 1, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `master_192k` | inferred |  | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg | 1 selects the 192 kHz master, 0 the 176.4 kHz master |

### Register `clockgen_master_0`

Master clock select of clock generator 0, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `master_192k` | inferred |  | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg | 1 selects the 192 kHz master, 0 the 176.4 kHz master |

### Register `config_b8`

Written once at start on every board mode with a 32-bit mask of all ones except bits 30 and 29. Purpose unknown.

### Register `config_bc`

Written with the same all-ones-but-bits-30:29 mask as config_b8, immediately after it. Purpose unknown.

### Register `desc_lo`

Descriptor RAM, low 32 bits of the buffer's PCI address of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). Entry n of data channel type n holds the descriptor the channel's working registers link to for the next lap; the status ring's descriptor is inferred to be entry 15. Whether the RAM is shared by every channel's engine, and what a write to a live entry does, are unknown: no shipped software does it.

Array of 16 registers, stride 12.

### Register `desc_hi`

Descriptor RAM, high 32 bits of the buffer's PCI address of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). Entry n of data channel type n holds the descriptor the channel's working registers link to for the next lap; the status ring's descriptor is inferred to be entry 15. Whether the RAM is shared by every channel's engine, and what a write to a live entry does, are unknown: no shipped software does it.

Array of 16 registers, stride 12.

### Register `desc_ctrl`

Descriptor RAM, control word, see DESC_WORD of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). Entry n of data channel type n holds the descriptor the channel's working registers link to for the next lap; the status ring's descriptor is inferred to be entry 15. Whether the RAM is shared by every channel's engine, and what a write to a live entry does, are unknown: no shipped software does it.

Array of 16 registers, stride 12.

### Register `work_adat_in_lo`

Working descriptor of channel type 4 (adat_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_adat_in_ctrl`

Working descriptor of channel type 4 (adat_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `work_aes_in_lo`

Working descriptor of channel type 2 (aes_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_aes_in_ctrl`

Working descriptor of channel type 2 (aes_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `work_analog_in_lo`

Working descriptor of channel type 0 (analog_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_analog_in_ctrl`

Working descriptor of channel type 0 (analog_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `work_adat_in_sub_lo`

Working descriptor of channel type 7 (adat_in_sub), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_adat_in_sub_ctrl`

Working descriptor of channel type 7 (adat_in_sub), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `work_aes_in_sub_lo`

Working descriptor of channel type 6 (aes_in_sub), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_aes_in_sub_ctrl`

Working descriptor of channel type 6 (aes_in_sub), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `work_adat_out_lo`

Working descriptor of channel type 5 (adat_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_adat_out_ctrl`

Working descriptor of channel type 5 (adat_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `work_aes_out_lo`

Working descriptor of channel type 3 (aes_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_aes_out_ctrl`

Working descriptor of channel type 3 (aes_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `work_analog_out_lo`

Working descriptor of channel type 1 (analog_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.

### Register `work_analog_out_ctrl`

Working descriptor of channel type 1 (analog_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.

### Register `status_lo`

Status ring, base PCI address low. A one-shot transfer uses the same registers with the limit set to 0xfffffffc.

### Register `status_limit`

Status ring limit and wrap: the driver writes 0x78 minus slot count times 0x80, and 0xfffffffc for one shot. Field layout undecoded.

### Register `work_adat_in_hi`

Working descriptor of channel type 4 (adat_in), address high.

### Register `work_aes_in_hi`

Working descriptor of channel type 2 (aes_in), address high.

### Register `work_analog_in_hi`

Working descriptor of channel type 0 (analog_in), address high.

### Register `work_adat_in_sub_hi`

Working descriptor of channel type 7 (adat_in_sub), address high.

### Register `work_aes_in_sub_hi`

Working descriptor of channel type 6 (aes_in_sub), address high.

### Register `work_adat_out_hi`

Working descriptor of channel type 5 (adat_out), address high.

### Register `work_aes_out_hi`

Working descriptor of channel type 3 (aes_out), address high.

### Register `work_analog_out_hi`

Working descriptor of channel type 1 (analog_out), address high.

### Register `status_hi`

Status ring, base PCI address high.

### Register `adat_out_subcode_a`

ADAT output subcode buffer A: 15 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.

Array of 15 registers, stride 8.

### Register `adat_out_subcode_b`

ADAT output subcode buffer B: 15 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.

Array of 15 registers, stride 8.

### Register `aes_out_subcode_a`

AES3 output subcode buffer A: 16 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.

Array of 16 registers, stride 8.

### Register `aes_out_subcode_b`

AES3 output subcode buffer B: 16 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.

Array of 16 registers, stride 8.

### Register `aes_out_subcode_extra_a`

extra AES3 subcode doublewords of buffer A: 2 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.

Array of 2 registers, stride 8.

### Register `aes_out_subcode_extra_b`

extra AES3 subcode doublewords of buffer B: 2 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.

Array of 2 registers, stride 8.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `DESC_WORD` | 32 | inferred |  |
| `PCI_REVISION` | 8 | established |  |
| `STATUS_DONE` | 32 | established |  |
| `STATUS_FLAGS` | 32 | inferred |  |

### Word `DESC_WORD`

Control word of a descriptor, in the RAM entry and in the working descriptor of a channel. The driver builds it as ((tag & 0xf) << 3) + (-length_units << 7), so bits 2:0 are zero in every driver-written word.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:7 | `length_units` | established |  |  | Transfer length as a negative count of 128-byte units, 25 bits. 0x1ffffe0 is 32 units, 4096 bytes |
| 6:3 | `next_index` | inferred |  |  | Index of the descriptor RAM entry the channel continues with. The drivers write the channel's own entry number (analog output 1, AES3 output 3, ADAT output 5, AES3-input subcode 6) so the ring loops on itself; Linux writes 7. Inferred as the one reading under which all three writers work |
| 2 | `end_of_descriptor` | inferred |  |  | Set: the transfer stops after this descriptor. Only the Octane PROM sets it (from reading its image); the shipped drivers never do. Inferred |

### Word `PCI_REVISION`

Low byte of PCI config offset 8. The driver reads the dword and splits this byte.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `board_mode` | established |  |  | Board variant; also the board number in hinv |
| 3:0 | `chip_rev` | established |  |  | Chip revision; hinv prints board.chip |

### Word `STATUS_DONE`

Slot word at byte offset 0x7c. The driver clears it before a transfer and waits for the engine to set bit 31.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `done` | established |  |  | Slot complete |
| 26:24 | `aes_rate_code` | established |  |  | AES3 input sample-rate code, looked up in an eight-entry table; 0 means no rate |
| 19 | `aes_no_input` | inferred |  |  | Set means no valid AES3 input, so the decoded rate is 0. Name inferred |

### Word `STATUS_FLAGS`

Slot word at byte offset 0x78 of each status slot. Bits not listed are never read by the driver.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `video_event_b` | inferred |  |  | As video_event_a, counted separately |
| 7 | `video_event_a` | inferred |  |  | Counted by the driver over 1024 passes to derive a period, which it uses only to classify a video reference. Name inferred |
| 6 | `adat_present` | inferred |  |  | ADAT input signal present; tested by the ADAT receiver state machine. Name inferred from the function |

## Enums

### Enum `channel_type`

| Label | Value | Grade | Source |
|---|---|---|---|
| `analog_in` | 0 | established |  |
| `analog_out` | 1 | established |  |
| `aes_in` | 2 | established |  |
| `aes_out` | 3 | established |  |
| `adat_in` | 4 | established |  |
| `adat_out` | 5 | established |  |
| `aes_in_subcode` | 6 | inferred |  |
| `adat_in_subcode` | 7 | inferred |  |

### Enum `status_pointer_slot`

| Label | Value | Grade | Source |
|---|---|---|---|
| `adat_in` | 0 | established |  |
| `aes_in` | 8 | established |  |
| `analog_in` | 16 | established |  |
| `adat_in_subcode` | 24 | established |  |
| `aes_in_subcode` | 32 | established |  |
| `adat_out` | 40 | established |  |
| `aes_out` | 48 | established |  |
| `analog_out` | 56 | established |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BAR0_SIZE` | 0x2000 | inferred |  | Bytes of BAR0 the driver maps; a lower bound on the decode size. The BAR sizing response itself is not measured |
| `CLOCKGEN_AES_OUT` | 0x2 | established | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_setrate_pipe | Clock generator that sets the AES3 output rate |
| `CLOCKGEN_ANALOG_IN` | 0x0 | established | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_setrate_pipe | Clock generator that sets the analog input rate |
| `CLOCKGEN_ANALOG_OUT` | 0x1 | established | public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_setrate_pipe | Clock generator that sets the analog output rate |
| `CLOCKGEN_COUNT` | 0x4 | inferred | public Linux RAD1 driver (linux-mips posting, 2008-07-31) | Number of clock generators; select bit 28 + n of the clock load register loads generator n |
| `DESC_ENTRIES` | 0x10 | inferred |  | Number of 12-byte descriptor RAM entries. The shipped drivers use entries 0 to 7 for the eight data channels and (inferred) entry 15 for the status ring |
| `DESC_ENTRY_BYTES` | 0xc | established |  | Size of one descriptor RAM entry |
| `DESC_STATUS_ENTRY` | 0xf | inferred |  | Descriptor RAM entry that holds the status ring's descriptor. Inferred from the offsets; no source names it |
| `DMA_UNIT_BYTES` | 0x80 | established |  | Length unit of a descriptor's control word |
| `GAIN_BIAS` | 0x48 | established |  | Added to a driver dB-to-register value to form a gain byte in the gain register; zero means mute |
| `GAIN_BRINGUP` | 0xd6d6d6d6 | established |  | Value the driver writes to the gain register at start on the analog-capable boards |
| `MODE_MEDIAIO` | 0x7 | established |  | Board mode value (PCI revision high nibble) of the MediaIO card |
| `MODE_OCTANE` | 0xc | established |  | Board mode value of the Octane base board |
| `MODE_PCI_BOARD` | 0xd | established |  | Board mode value of the PCI audio board; it has no analog section |
| `MUX_BITS` | 0x10 | established |  | Length in bits of the video-clock mux word the MediaIO card shifts out, most significant bit first |
| `MUX_PROBE_PASSES` | 0x400 | inferred |  | Status passes between rewrites of the gpio_data register; with the roughly 1 ms status interval this gives the 1.024 s cadence observed on the bus. Inferred |
| `PCI_CLASS_OCTANE` | 0x0 | established | public Linux lspci capture of the onboard RAD, linux-pci-list message 20170213224512.GA8080@bhelgaas-glaptop.roam.corp.google.com (2017-02-13), bus 0 device 3 function 0 | PCI class code of the onboard RAD on the Octane board: the 24-bit class field (config offset 0x08 bits 31:8) reads zero. Revision 0xc0 is the same listing's byte (REV_OCTANE) |
| `PCI_DEVICE` | 0x5 | established |  | PCI device id the driver registers for |
| `PCI_VENDOR` | 0x10a9 | established |  | PCI vendor id the driver registers for |
| `RBUF_REQUEST_BOARD12` | 0x3 | established |  | Read-response buffers the driver asks the bridge for on the Octane base board |
| `RBUF_REQUEST_BOARD13` | 0x2 | established |  | Read-response buffers the driver asks the bridge for on the PCI audio board. Board 12 asks for three |
| `REV_MEDIAIO` | 0x70 | inferred |  | PCI revision byte presented by the MediaIO card: board mode 7, chip revision 0. Inferred from the mode dispatch and the hinv text, not from a config read |
| `REV_OCTANE` | 0xc0 | established |  | PCI revision byte on the Octane base board: board mode 12, chip revision 0 |
| `REV_PCI_BOARD` | 0xd0 | inferred |  | PCI revision byte shown by the PCI audio board and Origin 3000-family base I/O: board mode 13. Inferred from hinv |
| `RING_WORDS_ADAT` | 0x1000 | established |  | Ring size in 32-bit words (16 KiB) for the ADAT channels |
| `RING_WORDS_ANALOG` | 0x400 | established |  | Ring size in 32-bit words (4 KiB) for the analog, AES3 and subcode channels |
| `STATUS_INTERVAL_DRIVER` | 0xfa | established |  | Interval the driver stores before starting the ring; with the multiplier it gives field 8251 |
| `STATUS_INTERVAL_UNITS` | 0x21 | inferred |  | Multiplier from the driver's interval (250) to the interval field |
| `STATUS_ONESHOT_POLLS` | 0x64 | established |  | Most times the driver polls the status slot's completion word after starting a one-shot transfer |
| `STATUS_ONESHOT_POLL_US` | 0x5 | established |  | Delay in microseconds between completion-word polls |
| `STATUS_SLOTS_MAX` | 0x80 | established |  | Most slots the driver gives the status ring; it is a power of two |
| `STATUS_SLOT_BYTES` | 0x80 | established |  | Size of one status ring slot in host memory |
| `STATUS_SLOT_DONE` | 0x7c | established |  | Slot byte offset of the completion word |
| `STATUS_SLOT_FLAGS` | 0x78 | established |  | Slot byte offset of the receiver flag word |
| `STATUS_SLOT_MIRROR` | 0x44 | established |  | Slot byte offset where the mirror of registers 0x04 to 0x34 starts: slot offset = register offset + 0x40 |
| `STATUS_START_CONT` | 0x40003 | established |  | Value (before the interval field) written to the status control register to run the status ring continuously |
| `STATUS_START_ONESHOT` | 0x40001 | established |  | Value written to the status control register for a single transfer |
| `STATUS_STOP` | 0x1fffc | established |  | Value written to the status control register to stop the status ring |
| `UST_BEDROCK_FLAG_MASK` | 0xf000 | established |  | Mask applied to the value read from the Bedrock real-time clock control register (0x604200 in the local block) at load |
| `UST_BEDROCK_FLAG_VALUE` | 0x4000 | established |  | Masked value that sets the driver's UST flag. Bit 14 of the Bedrock register is undefined in the local block (see docs/bedrock-local-block.md) |
| `UST_MIN_ADVANCE` | 0x3 | established |  | The driver reads the free-running counter twice 10 microseconds apart and reports an alert if it moved by fewer than this |
| `UST_TICK_NS_FIXED` | 0x3c0 | established |  | Tick period in nanoseconds that the reset routine stores for the counter at 0x30. The other choice is computed from the Bedrock register (see docs/rad1.md). Which choice a given machine gets is unknown |

## Test vectors

A vector is a value recorded from a source. An example only shows the layout.

| Target | Value | Kind | Decoded |
|---|---|---|---|
| `analog_out_ctrl` | 0x20000001 | vector | enable=1, clock_gen1=1, clock_gen2=0 |
| `status_ctrl` | 0x480ef | vector | start=1, continuous=1, interval=8251, go=1 |
| `gain` | 0xd6d6d6d6 | vector | in_left=214, in_right=214, out_left=214, out_right=214 |
| `central_ctrl` | 0xffe20000 | vector | adat_rx_enable=0, adat_rx_resync=0, clockgen_reset=0, analog_out_if_reset=0 |
| `gpio_relay` | 0x2 | vector | bit0=0, bit1=1 |
| `gpio_relay` | 0x3 | vector | bit0=1, bit1=1 |
| `gpio_data` | 0x2 | vector | data=0, const1=1 |
| `gpio_data` | 0x3 | vector | data=1, const1=1 |
| `clockgen_load` | 0x20000603 | vector | divisor_minus_1=3, flags=3, select=2 |
| `clockgen_frac` | 0x34ff6d | vector | remainder=52, denominator_complement=65389 |
| `DESC_WORD` | 0xfffff008 | vector | end_of_descriptor=0, next_index=1, length_units=33554400 |
