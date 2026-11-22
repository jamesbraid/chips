<!-- generated from devices/lithium/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 54a43e69300a6826905d64ebdf4107626a8df0731e7019264517aa75d3188b1f -->

# Lithium (I/O ASIC of the SGI Visual Workstation 320 and 540): the PCI bridge window and the audio engine, as SGI's Linux platform code names them

Offsets and bits are software definitions from the Linux Visual Workstation code, cross-checked against SGI's shipped Windows NT 4.0 HAL (halborg.dll 1.3), audio driver (sgisound.sys 5.2.2) and unadjusted-system-time driver (sgiust.sys 5.2.2). Grades: established means the Linux code and a shipped Windows binary agree (or the item is a window address both map); inferred means only Linux defines it, a software expectation of Linux and not of the shipped system. The shipped audio driver was read for the register file only where this page says so. Original basis: the bridge interrupt and bus-number registers from the platform setup and PCI code, the audio engine from SGI's own sound driver (copyright 1999 SGI). The chip's specification is not held. Two bridges (A and B) each show a PCI configuration-style header at a fixed physical window; the audio engine sits at a third. Reset values are unknown throughout. Only registers a kernel touches are here.

Unit `lithium`, macro prefix `LITHIUM`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| bridge | byte |  |
| audio | byte |  |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `host_ctl` | 0x0 | rw | 32 |  | audio | unknown | established |  |
| `intr_status` | 0x10 | rw | 32 |  | audio | unknown | inferred |  |
| `intr_mask` | 0x14 | rw | 32 |  | audio | unknown | inferred |  |
| `codec_command` | 0x18 | rw | 32 |  | audio | unknown | established |  |
| `codec_data` | 0x1c | rw | 32 |  | audio | unknown | established |  |
| `comm1_base` | 0x100 | rw | 32 |  | audio | unknown | established |  |
| `comm1_ctl` | 0x104 | rw | 32 |  | audio | unknown | inferred |  |
| `comm1_cfg` | 0x108 | rw | 32 |  | audio | unknown | inferred |  |
| `comm2_base` | 0x10c | rw | 32 |  | audio | unknown | established |  |
| `comm2_ctl` | 0x110 | rw | 32 |  | audio | unknown | inferred |  |
| `comm2_cfg` | 0x114 | rw | 32 |  | audio | unknown | inferred |  |
| `ust_low` | 0x200 | r | 32 |  | audio | unknown | established |  |
| `ust_high` | 0x204 | r | 32 |  | audio | unknown | established |  |
| `audio1_ust` | 0x300 | r | 32 |  | audio | unknown | inferred |  |
| `audio1_msc` | 0x304 | r | 32 |  | audio | unknown | inferred |  |
| `audio2_ust` | 0x308 | r | 32 |  | audio | unknown | inferred |  |
| `audio2_msc` | 0x30c | r | 32 |  | audio | unknown | inferred |  |
| `bus_number` | 0x44 | r | 16 |  | bridge | unknown | inferred |  |
| `int_enable` | 0x46 | rw | 16 |  | bridge | unknown | established |  |

### Register `host_ctl`

Audio link controller. The driver resets the codec link by writing reset, waiting a microsecond, then writing link_enable alone, and never reads the register after that in the code read. The three low bits are named by the driver but never tested.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `reset` | established |  |  | 1 asserts the codec reset (the driver's comment calls it the active-low reset signal). |
| 14 | `link_enable` | established |  |  | 1 takes the codec link out of reset after the reset pulse. |
| 2 | `link_failure` | inferred |  |  | Name only (LI_HC_LINK_FAILURE). |
| 1 | `link_codec` | inferred |  |  | Name only (LI_HC_LINK_CODEC). |
| 0 | `link_ready` | inferred |  |  | Name only (LI_HC_LINK_READY). |

### Register `intr_status`

Audio interrupt status. The driver clears pending bits by writing ones to the bits it wants cleared, and writes all ones to clear everything, so the bits are write-one-to-clear (inferred from the driver's use; no comment says so). It then masks the value it read with the mask register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `link_err` | inferred |  |  | Codec link error. |
| 3 | `comm2_trig` | inferred |  |  | Output channel trigger point reached. |
| 2 | `comm2_underflow` | inferred |  |  | Output channel underflow. |
| 1 | `comm1_trig` | inferred |  |  | Input channel trigger point reached. |
| 0 | `comm1_overflow` | inferred |  |  | Input channel overflow. |

### Register `intr_mask`

Audio interrupt enable mask, same bit layout as the status. The driver sets bits by read-modify-write and clears them the same way.

### Register `codec_command`

Codec register access. A write starts a codec register read or write; the driver waits until busy clears (about two ticks at most) before and after. For a write it puts the data in codec_data first; for a read it reads codec_data afterwards.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `busy` | established |  |  | 1 while a transfer is in progress. |
| 7 | `dir` | established |  |  | 1 read, 0 write. |
| 6:0 | `addr` | established |  |  | Codec register number, 0 to 25 in use. |

### Register `codec_data`

Codec register data, 16 bits used by the driver.

### Register `comm1_base`

Input DMA ring buffer base: the 40-bit physical address shifted right 8, with bit 29 set. The driver says bit 37 of the address (bit 29 here) must be set, and that it enables cache coherence. The ring is up to 8 KiB, 256 byte-aligned. The driver also writes this register once with the output buffer's address even when only output is used, because the input channel carries stray data otherwise (the driver quotes the NT driver on this).

### Register `comm1_ctl`

Input DMA control and pointers. The two low bytes are the write and read pointers in 32-byte chunks; for the input channel the hardware advances the write pointer and software the read pointer. The driver reads and writes each pointer as a single byte, at the first and second byte of this register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `reset` | inferred |  |  | 1 resets the channel; the driver writes it alone before setting up. |
| 30:28 | `size` | inferred |  |  | Ring size code: the driver writes log2(ring bytes) minus 6, so 7 for 8 KiB. Codes below 2 are not used. |
| 27 | `dma_enable` | inferred |  |  | 1 runs the channel. |
| 26:24 | `tmask` | inferred |  |  | Trigger mask: an interrupt fires when the hardware pointer and the trigger pointer agree after masking the low (8 minus this) bits. 0 means a mask of 0xff. |
| 23:16 | `tptr` | inferred |  |  | Trigger pointer, 32-byte chunks. |
| 15:8 | `rptr` | inferred |  |  | Read pointer, 32-byte chunks. Software on input. |
| 7:0 | `wptr` | inferred |  |  | Write pointer, 32-byte chunks. Hardware on input. |

### Register `comm1_cfg`

Input DMA configuration.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `lock` | inferred |  |  | Name only; the driver clears it. |
| 6:4 | `slot` | inferred |  |  | Serial slot of the codec the channel uses; the driver writes 2 for both channels. |
| 3 | `direction` | inferred |  |  | 1 output, 0 input. |
| 2 | `mode` | inferred |  |  | 1 stereo, 0 mono. |
| 1:0 | `format` | inferred |  |  | 0 is 8-bit unsigned (the engine xors each byte with 0x80), 1 is 16-bit two's complement. |

### Register `comm2_base`

Output DMA ring buffer base, same encoding as comm1_base.

### Register `comm2_ctl`

Output DMA control and pointers, same layout as comm1_ctl. For output the hardware advances the read pointer and software the write pointer.

### Register `comm2_cfg`

Output DMA configuration, same layout as comm1_cfg.

### Register `ust_low`

Low word of a 64-bit counter the driver calls unadjusted system time, microseconds since boot.

### Register `ust_high`

High word of the same counter. The driver reads it before and after the other words and retries if it changed.

### Register `audio1_ust`

Time stamp of the input channel's last sample counter update.

### Register `audio1_msc`

Input media stream counter: samples processed as of audio1_ust.

### Register `audio2_ust`

Time stamp for the output channel.

### Register `audio2_msc`

Output media stream counter.

### Register `bus_number`

Bus numbers behind the bridge. Linux reads it as a 16-bit value from each bridge's window and keeps the low byte as that bridge's PCI bus number, then scans that bus. The header comment says low byte primary, high byte subordinate; the high byte is never read. Whether the register is writable is unknown (only read).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `subordinate` | inferred |  |  | Highest bus number behind the bridge, from the header comment only. |
| 7:0 | `primary` | inferred |  |  | Bus number the kernel scans for this bridge. |

### Register `int_enable`

Interrupt enables, one bit per PCI interrupt source of the bridge. Linux writes it once at start-up, to every device bit on both bridges (the 2.2 kernel writes 0xffff, later kernels 0x00ff), and never reads it. The header calls the five low bits the INTA lines of the five slots and the next three the shared INTB, INTC and INTD. Reset state unknown, and so whether the firmware leaves it masked.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `intd` | inferred |  |  | INTD from any device. |
| 6 | `intc` | inferred |  |  | INTC from any device. |
| 5 | `intb` | inferred |  |  | INTB from any device. |
| 4 | `inta_4` | inferred |  |  | INTA of device 4. |
| 3 | `inta_3` | inferred |  |  | INTA of device 3. |
| 2 | `inta_2` | inferred |  |  | INTA of device 2. |
| 1 | `inta_1` | inferred |  |  | INTA of device 1. |
| 0 | `inta_0` | inferred |  |  | INTA of device 0 on this bridge. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `AUDIO_PAGE1` | 0xff00f000 | established |  | Second audio page; one undocumented word far into the page is zeroed when output stops (see the device page). |
| `AUDIO_PAGE2` | 0xff010000 | established |  | Third audio page; two undocumented words (copies of the DMA pointers) are zeroed when output stops (see the device page). |
| `AUDIO_PHYS` | 0xff001000 | established |  | Physical base of the audio engine's first register page. |
| `DEVICE_ID` | 0x1002 | inferred |  | PCI device id read from both bridges. |
| `DMA_CHUNK` | 0x20 | inferred |  | Bytes the audio DMA moves per pointer step. |
| `PCI_A_PHYS` | 0xfc000000 | established |  | Physical window of bridge A, the one with the Ethernet device. |
| `PCI_B_PHYS` | 0xfd000000 | established |  | Physical window of bridge B, the one with the PIIX4. |
| `VENDOR_ID` | 0x10a9 | inferred |  | PCI vendor id read from both bridges (SGI). |
