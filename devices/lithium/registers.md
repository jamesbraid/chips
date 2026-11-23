<!-- generated from devices/lithium/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 70596ec24940e8315b4fb0fe9a073a0422cfac082fac58aa7aa316aae98f2930 -->

# Lithium (I/O ASIC of the SGI Visual Workstation 320 and 540): the PCI bridge window and the audio engine, as SGI's Linux platform code names them

Offsets and bits are software definitions from the Linux Visual Workstation code, cross-checked against SGI's shipped Windows NT 4.0 HAL (halborg.dll 1.3), audio driver (sgisound.sys 5.2.2) and unadjusted-system-time driver (sgiust.sys 5.2.2). Grades: established means the Linux code and a shipped Windows binary agree (or the item is a window address both map); inferred means only Linux defines it, a software expectation of Linux and not of the shipped system. The shipped audio driver was read for the register file only where this page says so. Original basis: the bridge interrupt and bus-number registers from the platform setup and PCI code, the audio engine from SGI's own sound driver (copyright 1999 SGI). The chip's specification is not held. Two bridges (A and B) each show a PCI configuration-style header at a fixed physical window; the audio engine sits at a third. Reset values are unknown throughout. Only registers a kernel touches are here.

Unit `lithium`, macro prefix `LITHIUM`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| bridge | byte |  |
| audio | byte |  |
| audio_page1 | byte |  |
| audio_page2 | byte |  |
| stamp | byte |  |

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
| `ust_low` | 0x200 | rw | 32 |  | audio | unknown | established |  |
| `ust_high` | 0x204 | rw | 32 |  | audio | unknown | established |  |
| `audio1_ust` | 0x300 | r | 32 |  | audio | unknown | established |  |
| `audio1_msc` | 0x304 | rw | 32 |  | audio | unknown | established |  |
| `audio2_ust` | 0x308 | r | 32 |  | audio | unknown | established |  |
| `audio2_msc` | 0x30c | rw | 32 |  | audio | unknown | established |  |
| `silence_word` | 0x500 | w | 32 |  | audio_page1 | unknown | inferred |  |
| `dma_pointer_copy` | 0x98 | w | 32 | 2 | audio_page2 | unknown | inferred |  |
| `bridge_cmd` | 0x4 | rw | 16 |  | bridge | unknown | inferred |  |
| `bridge_status` | 0x6 | rw | 16 |  | bridge | unknown | inferred |  |
| `bridge_rev` | 0x8 | r | 8 |  | bridge | unknown | established |  |
| `bridge_40` | 0x40 | rw | 32 |  | bridge | unknown | inferred |  |
| `bus_number` | 0x44 | rw | 16 |  | bridge | unknown | inferred |  |
| `int_enable` | 0x46 | rw | 16 |  | bridge | unknown | established |  |
| `err_status` | 0x48 | rw | 32 |  | bridge | unknown | inferred |  |
| `bridge_58` | 0x58 | rw | 32 |  | bridge | unknown | inferred |  |
| `dma_ctl` | 0x60 | rw | 32 | 32 | bridge | unknown | inferred |  |
| `cfg_addr` | 0xf8 | rw | 32 |  | bridge | unknown | established |  |
| `cfg_data` | 0xfc | rw | 32 |  | bridge | unknown | established |  |
| `build_stamp` | 0x4 | r | 32 |  | stamp | unknown | inferred |  |

### Register `host_ctl`

Audio link controller. The driver resets the codec link by writing reset, waiting a microsecond, then writing link_enable alone, and never reads the register after that in the code read. PROM 1.1005 also stores link enable plus bit 8 here, as a 32-bit write on Lithium generation 5 (software/visws/boot-path.md). The three low bits are named by the driver but never tested.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `reset` | established |  |  | 1 asserts the codec reset (the driver's comment calls it the active-low reset signal). |
| 14 | `link_enable` | established |  |  | 1 takes the codec link out of reset after the reset pulse. |
| 8 | `prom_bit8` | unknown |  |  | Set by the PROM's host-control store on generation 5; no audio driver reads or writes it, and its meaning is unknown. |
| 2 | `link_failure` | established |  |  | Link failure. The NT audio driver's link check (HwCheckLink) reads the halfword at offset 0 and treats the link as good when this bit is 0; it is the only bit that driver tests. |
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
| 30:28 | `size` | established |  |  | Ring size code: log2(ring bytes) minus 6. Linux writes 7 for 8 KiB; the NT driver writes 7 for an 8 KiB ring and 6 (4 KiB) for any other size it is configured with, and its default is 8 KiB. Codes below 2 are not used by Linux. |
| 27 | `dma_enable` | established |  |  | 1 runs the channel. The NT driver sets it last, after the base, configuration and size, and clears it again when it stops an input channel. |
| 26:24 | `tmask` | inferred |  |  | Trigger mask: an interrupt fires when the hardware pointer and the trigger pointer agree after masking the low (8 minus this) bits. 0 means a mask of 0xff. |
| 23:16 | `tptr` | inferred |  |  | Trigger pointer, 32-byte chunks. |
| 15:8 | `rptr` | established |  |  | Read pointer, 32-byte chunks. Software on input. The NT driver accesses it as the byte at offset +1 (hardware on output, software on input). |
| 7:0 | `wptr` | established |  |  | Write pointer, 32-byte chunks. Hardware on input. The NT driver reads and writes it as the byte at offset +0 of the register (software on output, hardware on input). |

### Register `comm1_cfg`

Input DMA configuration.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `lock` | inferred |  |  | Name only; the driver clears it. |
| 6:4 | `slot` | inferred |  |  | Serial slot of the codec the channel uses; Linux writes 2 for both channels; the NT audio driver never writes the field, so it stays 0 there. |
| 3 | `direction` | established |  |  | 1 output, 0 input (NT driver: set for the output channel only). |
| 2 | `mode` | established |  |  | 1 stereo, 0 mono (NT driver: set when the format has two channels). |
| 1:0 | `format` | established |  |  | 0 is 8-bit unsigned (the engine xors each byte with 0x80), 1 is 16-bit two's complement. The NT driver derives the value from the sample size (8 gives 0, 16 gives 1) and writes the silence word 0x80808080 or 0 to match. |

### Register `comm2_base`

Output DMA ring buffer base, same encoding as comm1_base.

### Register `comm2_ctl`

Output DMA control and pointers, same layout as comm1_ctl. For output the hardware advances the read pointer and software the write pointer.

### Register `comm2_cfg`

Output DMA configuration, same layout as comm1_cfg.

### Register `ust_low`

Low word of a 64-bit counter Linux calls unadjusted system time, microseconds since boot (the unit is Linux's comment; the time driver scales the value by 1000). The NT audio driver never reads it. The time driver and the video driver map these eight bytes on their own, and the time driver writes zero to both words at load, so they are writable. Both drivers also retry a read when the low halfword is 0xffff (their rules differ; see the NT drivers page).

### Register `ust_high`

High word of the same counter. The NT audio, time and video drivers all read it before and after the other words and retry if it changed; the time driver zeroes it at load.

### Register `audio1_ust`

Time stamp of the input channel's last sample counter update. The NT driver pairs it with ust_high (read first, re-read afterwards, retried until equal) to form a 64-bit time stamp for the media stream counter.

### Register `audio1_msc`

Input media stream counter: samples processed as of audio1_ust. The NT driver writes zero to it when it starts input with no pending counter pair, so it is writable.

### Register `audio2_ust`

Time stamp for the output channel, read the same way as audio1_ust.

### Register `audio2_msc`

Output media stream counter. The NT driver writes zero to it when it starts output with no pending counter pair, so it is writable.

### Register `silence_word`

A word on the second audio page, offset from physical 0xff00f000. The NT audio driver stores the silence sample here before it starts DMA, in both directions: 0x80808080 for 8-bit samples, 0 for 16-bit (sgisound.sys 5.2.2, sndStartDMA, read in full for the Windows 2000 build only; not verified at binary level in the other two builds here). Linux's Visual Workstation sound driver writes it only once, with 0, when output stops; it never writes 0x80808080. Linux's comment calls it an undocumented register holding the zero sample, which the hardware repeats after an underflow with a bug that leaves the old value in place. That comment is the only statement of its role, so the role is inferred. No driver reads it, so access is write only as software uses it and the readable value is unknown.

### Register `dma_pointer_copy`

Two words on the third audio page, offset from physical 0xff010000 (0x98 and 0x9c). Linux's comment calls them undocumented internal copies of the DMA read and write pointers that the chip fails to zero when DMA stops, so it zeroes them itself after stopping output. The NT driver zeroes both when it starts output (sgisound.sys 5.2.2, sndStartDMA, Windows 2000 build; not verified at binary level in the other two builds here). No driver reads them, so access is write only as software uses it. Which word is which pointer is unknown. The behaviour is Linux's statement only and the accesses are established, so the role is inferred.

Array of 2 registers, stride 4.

### Register `bridge_cmd`

Command word of the standard header. The NT HAL stores all ones here once when it sets up a bridge whose revision byte is above zero; nothing reads it back. Whether every bit is writable is unknown. No reset value is known.

### Register `bridge_status`

Status word of the standard header. The HAL stores a value with bits 15:11 set here at bridge set-up and the master-abort bit (bit 13) after each configuration access; the PROM never touches it. That the bits clear on a written one is the standard header's rule and is inferred. Which bits the bridge ever sets is unknown.

### Register `bridge_rev`

Revision byte. The HAL tests it above zero to choose where the bus number goes; the PROM tests bridge B's byte against zero and maps zero to Lithium generation 1. Only zero or not zero is used; the values and the reset state are unknown.

### Register `bridge_40`

When the revision byte is zero the top byte holds the bus number: the HAL clears bits 31:24 and ORs in the bus number shifted up 24, as a 32-bit read-modify-write. PROM 1.0002 and 1.0004 also read-modify-write this word on both bridges, keeping bits 23:6 and 4:0 and setting bit 5; on bridge A they also set bit 24 (top byte 0x01), on bridge B the top byte becomes 0, before their error-status and control stores. Later PROM images do not touch it. The HAL writes it only when the revision byte is zero. The meaning of the other bits is unknown.

### Register `bus_number`

Bus numbers behind the bridge. Linux reads it as a 16-bit value from each bridge's window and keeps the low byte as that bridge's PCI bus number, then scans that bus. The header comment says low byte primary, high byte subordinate; the high byte is never read by Linux. It is writable: the NT HAL read-modify-writes it (clears and sets the low byte for the primary number, then the next byte for the subordinate number) and the PROM stores its two bytes separately in its bus numbering. The self-test also reads and restores the dword that holds it, in bridge B only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `subordinate` | inferred |  |  | Highest bus number behind the bridge, from the header comment only. |
| 7:0 | `primary` | inferred |  |  | Bus number the kernel scans for this bridge. |

### Register `int_enable`

Interrupt enables, one bit per PCI interrupt source of the bridge. Linux writes it once at start-up, to every device bit on both bridges (the 2.2 kernel writes 0xffff, later kernels 0x00ff), and never reads it. The header calls the five low bits the INTA lines of the five slots and the next three the shared INTB, INTC and INTD. The PROM self-test requires bits 13:8 to be settable and clearable, on bridge B only (it reads, tests and restores the 32-bit word that holds this register in its upper half, mask bits 29:24), so six more bits exist above the eight the kernels use; their sources are unknown. The NT HAL uses the register differently from the header comment: for a Cobalt interrupt line n below 16 (lines 0 to 7 on bridge A, 8 to 15 on bridge B) it ORs bit n&7 into this register, under a spin lock, once, and never clears a bit (halborg.dll 1.3 HalpEnableLiInt, read in full). So the bit gates the Cobalt line by number, whichever bus the source is on, which does not fit the per-device reading of the bit names below; the bit names stay as the header comment gives them (inferred) and the HAL's use is the established software behaviour. Reset state unknown, and so whether the firmware leaves it masked.

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

### Register `err_status`

Error status. The PROM stores all ones here in both bridges at the start of its bridge set-up and nothing in the NT HAL or the PROM reads it, so the PROM never examines what the bridge records. The shipped NT USB driver also writes all ones and prints the word as PCI Error Status. Write-one-to-clear is the reading of those stores and the name. The bit meanings, what raises them and whether the bridge reports parity errors are unknown. The USB driver's message table also has a "PCI Error Status Address" string, which implies an address register beside this one; the driver's code touches only the error status word (it maps 0x70 bytes of the window and stores once), so the address register's offset is unread and unknown.

### Register `bridge_58`

Bridge control, meaning unknown. All accesses are 32-bit and all by the PROM: the boot block ORs the low five bits into it in both bridges before the main module runs, the main module then stores a value with bit 11 and bits 4:0 set, and the self-test checks that bits 1:0 can be set and cleared, on bridge B only. The NT HAL never touches it.

### Register `dma_ctl`

Thirty-two words, one per PCI device number on the bridge's bus (inferred from the PROM's device scan, which indexes them by device number). The PROM sets up the first five with one 32-bit read-modify-write each, in both bridges, and its device scan read-modify-writes any of the 32 for a QLogic ISP2100 Fibre Channel adapter: it clears bits 7:6 and sets bits 9:8 of that device's word. Bits 5:1 and bit 10 are cleared and bits 31:12, 11, 9:6 and 0 are kept. Then bit 10 is set unless the firmware setting coherentdma starts with n, and bits 13, 7, 6 and 1 are set on Lithium generation 5 or later unless the setting streambuffer starts with n. The setting names make bit 10 coherent DMA and the other four stream buffering (inferred from the names only). What bits 11, 8 and 5:2 do is unknown. The NT HAL never touches them.

Array of 32 registers, stride 4.

### Register `cfg_addr`

Configuration address for a type 1 cycle on the bridge's own bus and the buses behind it: bit 31 set, bus in 23:16, device in 15:11, function in 10:8, dword register in 7:2. Used by the HAL and, from the first instruction after reset, by the PROM boot block on bridge B. The PROM self-test checks, on bridge B only, that bits 23:2 can be set and cleared; it reads the old value first and restores it.

### Register `cfg_data`

Configuration data. Accessed as a byte, halfword or word; the lane is picked by the low address bits (the boot block stores a byte at this offset plus the register's low two bits).

### Register `build_stamp`

Word at physical 0xff01c004, in a one-page Lithium-side block that no driver touches. The PROM reads it (no HAL or driver read was found) and compares it with four values that decode as Unix times of 30 July, 10 September, 2 November and 7 December 1998 (0x35c0194c, 0x35f7357f, 0x363e4470, 0x366c3dfb) to pick the Cobalt I/O generation 2 to 5; a larger value gives 6, any other value gives -2, and bridge B's revision byte of zero gives 1 before the word is read. PROM 1.1005 also copies a table into the table window (constant TABLE_WINDOW_PHYS) unless the word is above 0x36ffd62f; that gate was read in 1.1005 only. The firmware prints it as the Serial I/O revision. A build stamp is a reading from the values, so the meaning is inferred; the reads are established (PROM 1.1005 and 1.0006, whole functions; see software/visws/boot-path.md). The block's other words are unknown, and so are its reset and write behaviour.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `AUDIO_DMA_CHANNELS` | 0x7 | inferred |  | Number of DMA channel register sets. The NT audio driver carries a seven-entry table, indexed by channel, of the register offsets of each set: each set repeats comm1_base, comm1_ctl and comm1_cfg at a 12-byte stride and each time-stamp and counter pair repeats audio1_ust and audio1_msc at an 8-byte stride (the table is listed in the Lithium page). The driver uses entries 0 (input) and 1 (output), matching Linux. That channels 2 to 6 exist in hardware is inferred from the table alone. |
| `AUDIO_PAGE1` | 0xff00f000 | established |  | Second audio page; one undocumented word far into the page is zeroed when output stops (see the device page). |
| `AUDIO_PAGE2` | 0xff010000 | established |  | Third audio page; two undocumented words (copies of the DMA pointers) are zeroed when output stops (see the device page). |
| `AUDIO_PHYS` | 0xff001000 | established |  | Physical base of the audio engine's first register page. |
| `BRIDGE_A_PCI_MEM_PHYS` | 0xf0000000 | established |  | Processor physical address of bridge A's 64 MiB PCI memory window, which appears at PCI address 0x80000000 (established from the PROM 1.0006 mapping that pairs this address with bridge A; PROM 1.1005 maps the same; the HAL's initial bridge records carry a PCI-to-processor offset that agrees, though the layout of those records is inferred). |
| `BRIDGE_B_PCI_MEM_PHYS` | 0xf4000000 | established |  | Processor physical address of bridge B's 64 MiB PCI memory window, at PCI address 0x80000000 (PROM 1.0006 mapping; the HAL's record offset agrees). |
| `DEVICE_ID` | 0x1002 | inferred |  | PCI device id read from both bridges. |
| `DMA_CHUNK` | 0x20 | inferred |  | Bytes the audio DMA moves per pointer step. |
| `PCI_A_PHYS` | 0xfc000000 | established |  | Physical window of bridge A, the one with the Ethernet device. |
| `PCI_B_PHYS` | 0xfd000000 | established |  | Physical window of bridge B, the one with the PIIX4. |
| `PCI_MEM_BUS_BASE` | 0x80000000 | established |  | PCI-side address of the start of both bridges' memory windows. |
| `PCI_MEM_SIZE` | 0x4000000 | established |  | Size of each bridge's PCI memory window, 64 MiB (HAL records; PROM mapping). |
| `STAMP_PHYS` | 0xff01c000 | established |  | Physical base of the one-page Lithium-side block whose second word is build_stamp. The PROM maps it, and also reads that word through its mapping of the four-page table window, past the end of that mapping. |
| `TABLE_WINDOW_PHYS` | 0xff018000 | established |  | Physical base of a four-page window the PROM fills with a 256-dword table (117 dwords written) on generation 5 when the stamp is at most 0x36ffd62f. The role of the window is unknown. |
| `VENDOR_ID` | 0x10a9 | inferred |  | PCI vendor id read from both bridges (SGI). |
