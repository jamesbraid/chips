# VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller

Mode: **no-spec** (the driver-derived facts below come from the binary; the vendor datasheet in the section after them gives the register layout and reset values; the public Linux `sound/pci/ice1712` driver, Linux 7.2-rc7 `envy24ht.h`,
`ice1724.c` and `revo.c`, was read after the binary and only for names and conflicts). The part is not an SGI chip. It is
the controller of the SGI DMediaPro DM8 PCI audio option, see [devices/dm8/README.md](../../devices/dm8/README.md) for the board,
and [evidence/audio-survey.md](../../evidence/audio-survey.md) for where it sits among the audio options.

Source of every fact below: the IRIX 6.5.30 driver object `mad_dd.o` of the IP35 build
(`IP35/usr/cpu/sysgen/IP35boot/mad_dd.o`, SHA-256 `905a72a73b0351378bc32c265ddae66b4f9f696b31e0eb9d65993acba78c1518`),
disassembled with relocations; addresses are offsets in its `.text`. The IP27 and IP30 builds carry a different build of the
same driver (SHA-256 `d9e547d6...` and `4875d7f8...`); their registration call has the same two constants, nothing else was
compared.

## Identification

- **Established.** `mad_init` (`0x0`) calls the PCI driver registration with vendor `0x1412` (loaded as 5138) and device
  `0x1724` (5924) and no flags. `0x1412:0x1724` is the ICE1724/VT1720 Envy24HT/PT in the public PCI ID list (pci.ids 2026.09.23).
- **Established.** The hinv line the driver's inventory entry produces is `Iris Audio Processor: version MAD revision N`.
  `mad_create_subsys` (`0x1e4`) reads PCI config byte `0x08` (the revision, size 1) and passes it as the state of an
  inventory entry of class 10 and type 7 (`0x2ec`..`0x300`). A user's hinv from a Fuel with the DM8 shows `revision 1`
  (Usenet message-id `V1UGh.52430$Da4.30732@newsfe6-gui.ntli.net`), and the SGI DM8 note shows the Linux enumeration of the
  same board as `ICE1724 [Envy24HT] (rev 01)` (007-4077-001, p. 2). Revision 1 is therefore the controller revision the driver
  was written against.
- **Established.** Sub-device check: `mad_create_subsys` reads config `0x2e` (size 2) and compares it with `0x3630`
  (`0x28c`..`0x294`). Equal sets the per-device "Revolution" flag (offset 5528 of the device record) to 1; unequal leaves it 0
  and the AC'97 setup path at `0x3a4`..`0x3d8` runs instead. `1412:3630` is "M-Audio Revolution 7.1" in the public PCI ID
  list; the same value is `0x12143036` in the Linux driver's `revo.h` (the Linux constant holds the EEPROM byte order). The
  IRIX driver never tests the sub-vendor word.
- **Not established.** What the DM8's own EEPROM and config space read. No capture is held. See the questions in
  [questions/README.md](../../questions/README.md).

## Windows and byte lanes

- **Established.** `mad_attach` (`0x14c`) maps two windows through the Bridge PCI window call: window space 8 at offset 0, 32
  bytes (BAR0), and space 9 at offset 0, 128 bytes (BAR1), both with the flag word 8192. The sizes equal the public driver's
  controller-register (CCS) block of 0x20 bytes and multitrack block (MT) of 0x80 bytes. It also writes config byte `0x0d`
  (latency timer) with all ones (truncated to a byte), and sets the PCI priority to 1.
- **Established.** Every byte access in the driver is at `offset ^ 3` and every halfword access at `offset ^ 2`; words
  are at the offset. This is a big-endian CPU reading little-endian registers in the lane arrangement the IRIX PCI
  window gives; read the tables with the register offset, not the address.
- **Established.** There is no interrupt. The driver imports no interrupt allocation or connect call (the import list holds
  only the PIO window, DMA address translation, PIO flush read and error registration calls). The DMA position is read from the
  device by `mad_update_dev` (`0x105c`).

## Controller registers (BAR0, "CCS")

| Offset | Width | Access in `mad_dd.o` | Label |
|---|---|---|---|
| `0x04` | byte | `mad_read_configuration` (`0x414`) reads bits 1:0; `mad_set_eeprom` (`0x2f54`) writes EEPROM byte 6 here; with no EEPROM `mad_create_subsys` stores `0x40` (`0x34c`) | established access; role "system configuration, bits 1:0 = number of stereo DACs less one" **inferred** from the public header and the driver's use: value 3 sets the analog output channel count to 8, 0..2 to 2 (`0x4a8`..`0x4c4`) |
| `0x05` | byte | read: bit 7 sets the per-device "I2S converter" flag (`0x464`..`0x474`); written from EEPROM byte 7 | established access; role inferred (AC'97 configuration byte) |
| `0x06` | byte | written from EEPROM byte 8 | established access; role inferred (I2S features) |
| `0x07` | byte | read: bit 0 sets the "digital output present" flag (`0x478`..`0x48c`); written from EEPROM byte 9 | established access; role inferred (S/PDIF configuration) |
| `0x10` | byte | I2C device address, written `0xa0` (`mad_i2c_read`, `0x2ce4`) | established; role inferred |
| `0x11` | byte | I2C byte address | established; role inferred |
| `0x12` | byte | I2C data, read | established; role inferred |
| `0x13` | byte | bit 7 tested (EEPROM present, `0x2d58`); bit 0 polled for busy | established access; role inferred |
| `0x14` | half | GPIO data bits 15:0, read and written (`mad_gpio_read` `0x2768`, `mad_gpio_write` `0x2790`) | established access; role inferred |
| `0x16` | half | GPIO write mask bits 15:0, from EEPROM bytes 13 and 14 | established access; role inferred |
| `0x18` | word | GPIO direction (24 bits), from EEPROM bytes 10 to 12 | established access; role inferred |
| `0x1e` | byte | GPIO data bits 22:16 | established access; role inferred |
| `0x1f` | byte | GPIO write mask bits 22:16, from EEPROM byte 15 | established access; role inferred |

Order matters in `mad_set_eeprom`: stores to `0x04`, `0x05`, `0x06`, `0x07`; then `0x18`; a 10 microsecond delay; then `0x16`
and `0x1f`; another 10 microsecond delay; then `0x14` and `0x1e`. The delays come from the delay-slot placement of the
`us_delaybus(10)` calls (`0x2fe0`, `0x301c`): the store in the slot runs first, the delay after.

The mapping "EEPROM bytes 6..18 go to these registers" equals the public driver's `ICE_EEP2_*` table. The EEPROM itself is at
I2C address `0xa0`; `mad_read_eeprom` (`0x2d50`) returns "absent" when bit 7 of `0x13` is clear, reads bytes 0..3 and
treats an all-ones first word as "blank", then reads bytes 4 to 18. **Established**: byte index, the blank test and the final
copy. The meaning of bytes 0..3 (the subsystem IDs in the public driver) is **inferred**.

## Multitrack registers (BAR1, "MT")

| Offset | Width | Access | Label |
|---|---|---|---|
| `0x01` | byte | sample rate code written by `mad_set_rate` (`0x2268`) | established access. The codes the function selects (`0` for 48 kHz, `4` for 32 kHz, `2` for 12 kHz, `11` for 88.2 kHz) equal the public driver's rate table; the full table is below. |
| `0x02` | byte | bit 3 set for rates at or above 120000 Hz, cleared below (`0x22f4`..`0x2318`) | established access; "128x master clock" role **inferred** from the public name |
| `0x05` | byte | bit 7 set, 10 microsecond delay, cleared during a rate change (`0x2324`..`0x236c`) | established access; role (a converter reset line) **inferred** |
| `0x10` | word | start address of the playback buffer, mode 1 (`0xf80`..`0xf88`) | established access; role inferred (public name `PLAYBACK_ADDR`) |
| `0x14` | word | playback size, written with the frame count less one (`0xf90`..`0xf98`) | established access; unit not extracted |
| `0x18` | byte | DMA control. The driver keeps a shadow byte (offset 5496 of the device record) and writes it here at start and stop: bit 0 for mode 1, bit 1 for mode 0, bit 7 for mode 3 | established access; bit roles inferred from the public names `PDMA0`, `RDMA0`, `PDMA4` |
| `0x19` | byte | burst/active streams: written 0 when the analog output has 8 channels, 3 otherwise (`0xf68`..`0xf7c`, `0xfe8`..`0xfec`) | established access; role inferred |
| `0x20` | word | capture buffer address, mode 0 (`0xf2c`..`0xf34`) | established access; role inferred (`CAPTURE_ADDR`) |
| `0x24` | half | capture size, frame count less one | established access; role inferred |
| `0x40` | word | S/PDIF output buffer address, mode 3 (`0xfac`..`0xfb4`) | established access; role inferred (`PDMA4_ADDR`) |
| `0x44` | half | S/PDIF output size | established access; role inferred |

Stream modes (`mad_start_dma`, `0xe48`, selects on the mode word at offset 704): 0 is the analog capture stream, 1 the analog
output stream, 3 the digital output stream. Mode 2 does not appear. The shadow of `0x18` is written to the hardware in the common
tail (`0xecc`..`0xee0`). The stop routine (`mad_stop_dma`, `0xff0`) clears the stream's bit in the shadow and writes it back.

Position: `mad_update_dev` (`0x105c`) reads, for mode 0, the capture-size register `MT+0x24` through a PIO flush read
(`0x10f4`..`0x1104`); for mode 1, `MT+0x10`; for mode 3, `MT+0x40` (`0x1298`, `0x12d8`), subtracts the buffer start and shifts
right by 2. Capture samples are then arithmetic-shifted right by 8 in place (`0x117c`, `0x11dc`), so the buffer holds 24-bit
samples in 32-bit words. **Established** for the reads and the shift, **inferred** for "current address register" semantics.

The DMA buffer address passed to these registers is the Bridge's bus-address translation of the kernel buffer
(`Mem_to_PCI_DMA`, `0x1364`, flags `0x2020`). The ring size and alignment are not established.
The address limit: the datasheet never mentions dual-address cycles, so 32-bit buffer addresses are **inferred**. Two
public drivers agree. OpenBSD applies its 28-bit DMA limit only to the non-HT Envy24 (`envy.c:1857`). FreeBSD creates a
32-bit DMA tag for the HT part (`envy24ht.c:2418`-`2432`, `BUS_SPACE_MAXADDR_32BIT`). These are software expectations.

## Converters on the GPIO port (Revolution path)

The driver's Revolution path programs two serial-control converters by bit-banging GPIO. The GPIO bit assignments below are
the same as the public `revo.h`; the **bit-banging itself is established from the binary**.

- GPIO bit 1 is the serial clock, bit 3 the data out, bits 4, 5, 6 the chip selects (active low), bit 22 the mute line
  (`mad_gpio_write_bit` `0x27b8`, `mad_gpio_assert_cs` `0x29e8`, `mad_gpio_deassert_cs` `0x2a34`, `mad_gpio_mute` `0x2a64`).
  `deassert` ORs `0x70` into the GPIO word. Chip 1 asserts bit 5, chip 2 asserts bit 6. **Established.**
- A register write (`mad_gpio_write_spi_register`, `0x28d8`): data low, clock high; assert select; send the 8-bit word
  `(chip-address << 6) | 0x20 | (register & 0x1f)` most significant bit first, then the 8-bit value the same way, each bit as
  clock low, 1 microsecond, data, 1 microsecond, clock high, 1 microsecond; deassert. The chip address is 1 for chip 1 and 3 for
  chip 2 (`0x28c4`, `0x28cc`: `0x40` and `0xc0`). The function also stores the value in a shadow table at offsets 5497 and 5502
  of the device record (`0x29d8`, `0x29e0`). **Established.**
- **Rate to code table (established, `mad_set_rate` `IP35boot/mad_dd.o` 0x2268, 1280 bytes, read in full).** The routine returns at once when the
  request equals the rate it last set (the word at record +0x15a0). Otherwise it snaps the request to the first row below whose
  limit is above it (rows are tested in order), then writes the code at register `0x01`:

  | requested rate below (Hz) | snapped to (Hz) | code |
  |---:|---:|---:|
  | 8800 | 8000 | 6 |
  | 10312 | 9600 | 3 |
  | 11512 | 11025 | 10 |
  | 14000 | 12000 | 2 |
  | 19025 | 16000 | 5 |
  | 23025 | 22050 | 9 |
  | 28000 | 24000 | 1 |
  | 38050 | 32000 | 4 |
  | 46050 | 44100 | 8 |
  | 56000 | 48000 | 0 |
  | 76100 | 64000 | 15 |
  | 91076 | 88200 | 11 |
  | 136200 | 96000 | 7 |
  | 184200 | 176400 | 12 |
  | (everything above) | 192000 | 14 |

  Code 13 is not produced. The table equals the public driver's rate table entry for entry (48000 is 0, 24000 is 1, 12000 is 2,
  9600 is 3, 32000 is 4, 16000 is 5, 8000 is 6, 96000 is 7, 44100 is 8, 22050 is 9, 11025 is 10, 88200 is 11, 176400 is 12, 192000
  is 14, 64000 is 15). The snapping limits are not in the public driver. A snapped value outside the exact table cannot occur; the routine's fallback for it returns 0 without writing.
- Chip 1 takes registers 0 to 4 (`mad_init_revolution`, `0x2b2c`; values `0x0c`, `3`, `0`, `0xff`, `0xff`, then `0x0f` to
  register 0). Chip 2 takes registers 0 to 10. The rate-dependent registers are chip 1 register 1 (`3`, `11` or `19` for rates
  below 60000, below 120000 and above) and chip 2 register 2 (`14`, `30` or `46`). The attenuation registers are chip 1 registers
  3 and 4 and chip 2 registers 4 to 9, loaded from the shadow table (`mad_set_rate`, `0x23c0`..`0x24d0`). **Established**.
- Which parts these are is **inferred**: chip 1 matches the AKM AK4381 (stereo, two attenuation registers, double and quad speed
  bits in register 1) and chip 2 the AKM AK4355 (six attenuation registers, speed bits in register 2), which is exactly
  the pair the public driver programs on the 1412:3630 card with chip addresses 1 and 3. See [../ak4381](../ak4381/README.md)
  and [../ak4355](../ak4355/README.md). No code in the driver names either part.
- The analog gain code maps a 0..255 level through the table `mad_revo_logtolin` (`0x1fa8`, 256 bytes in `.data`) into
  those attenuation registers (`mad_set_i2s_analog_gain`, `0x1b84`). The table's contents were not decoded.
- There is no code path that writes a converter for the analog input. The analog input gain range the driver reports is fixed.
  This agrees with the public pages' ADC (see [../ak5380](../ak5380/README.md)) being a no-control-interface part, and with the
  Usenet report that the input level cannot be changed on this card (hinv post above).

## The AC'97 variant (inferred to be unused by the DM8)

If the sub-device check fails, `mad_create_subsys` writes AC'97 registers `0x18`, `0x1a`, `0x0e` and `0x1c` (`mad_ac97_write`,
`0x306c`) through MT bytes `0x04` (index), `0x05` (command/status) and halfword `0x06` (data), polling status bits `0x30` and `0x08`
before and bit `0x20` after, 65536 loops each. **Established** as code. Which board takes this path is **unknown**; the DM8
manual's connector list (mic, line in, three line outs, headphone) is the Revolution 7.1 shape.

## Tezro placement

On the Tezro tower the controller is inferred to sit behind the TI PCI2050 at IO9 bus 0 device 2, as
device 2 of the secondary bus; the bridge driver's behaviour, the exact multi-master condition (two or
more bus masters behind the bridge) and the interrupt swizzle are in
[questions/tezro-ice1724.md](../../questions/tezro-ice1724.md). The driver imports no interrupt
call and never writes the interrupt mask or status registers, whose reset state masks every source.

## Vendor datasheet facts

Source: IC Ensemble, *ICE1724 PCI Multi-Channel Audio Controller (Envy24HT)*, preliminary, running footer "Rev. 0.91, 11/05/01"
(one page reads "Rev. 0.9"), 68 pages, marked confidential. The copy is a third-party one from the ALSA project's manual archive.
Page numbers below are the printed ones ("datasheet p."). The register layout, access types and reset values are in
`devices/ice1724/registers.toml`, which generates [devices/ice1724/registers.md](../../devices/ice1724/registers.md). This section holds the facts that do not fit a
register table. Grades: established means the datasheet states it; inferred means a reading the text does not state, with the reason given.

The VIA VT1720 datasheet (Envy24PT, rev. 1.0, 2004) is a sibling part. It is named below only where it is noted as a sibling statement
and never applied to this chip.

### Package and bus

- **Established.** 128-pin PQFP, 3.3 V supply, 5 V tolerant I/O (datasheet pp. ii, 1-10).
- **Established.** A PCI 2.2 bus master with burst mode. The data path is 32 bits (`AD[31:0]`); DMA address registers use bits 31 to 2.
- **Established.** Memory-write-and-invalidate is disabled and cache-line size is not supported.
- **Inferred.** 64-bit buffer addresses are unsupported: the datasheet never mentions dual-address cycles.
- **Unknown.** The PCI commands the bursts use.
- **Established.** `INTA#` is open drain. `REQ#` and `GNT#` are the only arbitration pins (p. 2-3).
- **Established.** The two register windows are I/O-space BARs.
- **Established.** CCS registers take byte, word and dword access. The datasheet gives no widths for MT registers. Drivers use byte, word and
  dword accesses at the map offsets; that is an expectation from the public driver, so the rule itself is unknown.

### Reset and power

- **Established.** "Default Value" is the value after PCI `RST#` (pp. 3-7, 4-3).
- **Established.** D3hot to D0 resets the whole chip, configuration space included (p. 3-7).
- **Established.** D2 and D3hot power down the blocks selected by CCS1C. A write of D1 (`01`) is not supported; the response is not stated.
- **Unknown.** What CCS00 bit 7 (soft reset) leaves untouched, and whether the strapped bits reset. The datasheet says nothing about it.
  The VT1720 sibling states that its soft reset keeps the PCI configuration registers, CCS00 and CCS04 to CCS07, rereads the EEPROM and
  pulses `PRST#` (VT1720 datasheet p. 27). That is a different chip, so the statement is not applied here.

### Interrupts

- **Established.** One interrupt pin, `INTA#`. The sources are MPU-401 receive and transmit (CCS02 bits 7 and 5) and the multi-channel
  macro (CCS02 bit 4) (pp. 4-3, 4-4). MT00 sets when an engine's terminal count reaches zero, and bit 3 sets when any underrun or overrun
  flag is set (pp. 4-12, 4-22). Writing 1 clears a flag.
- **Inferred.** The macro bit is the OR of the unmasked MT00 bits, and `INTA#` is asserted while any unmasked CCS02 bit is set. The datasheet
  does not draw this logic.
- **Inferred.** A masked source does not latch into MT00. The wording suggests this; nothing states it.
- **Expectation (public Linux driver, inferred here).** The driver unmasks only the multi-channel source and MIDI on demand. It keeps the
  FIFO-error source masked because it caused continual interrupts. It acknowledges MT00 by writing back the value it read, and it ignores a
  transmit interrupt that comes with every playback.

### Clocks

- **Established.** XIN1 takes 24.576 MHz (CCS04 bit 6 = 0) or 49.152 MHz (= 1). XIN2 takes 22.5792 MHz.
- **Established as drawn (figures 4-3 and 4-4, pp. 4-15, 4-16).** The 256x master clock comes from XIN1 through a divider chain, or from XIN2
  for rate codes `1000` to `1011`, or from `SPMCLKIN` in slave mode. A further divide by two gives the 128x clock when MT02 bit 3 is set.
  `PBCLK` is 256x or 64x fs, `PSYNC` is fs and `PMCLK` is 256x or 128x fs. The figures were read as images.
- **Unknown.** Which divider each rate code picks, and whether a halving stage applies on XIN1 when CCS04 bit 6 is 1. The text does not tabulate it.
- **Established.** Every stream, record and S/PDIF output included, runs at one rate (p. 4-1).
- **Established.** In slave mode the highest accepted master clock is 256x. AC'97 needs 512x.

### Interleaved and stereo DMA

- **Established.** Streams are 32-bit unpacked words, left justified. A 24-bit sample occupies bits 31 to 8 (p. 4-18).
- **Established.** Interleaved playback fetches four sample times per burst, so one 8-channel burst is 32 data cycles. The chip buffers
  12 sample times of 8 channels at 24 bits, so the first fill needs three bus requests (p. 4-18).
- **Established.** In I2S mode the interleaved slots feed the output pins in pairs: slots 1 and 2 to `PSDOUT0`, 3 and 4 to `PSDOUT1`,
  5 and 6 to `PSDOUT2`, 7 and 8 to `PSDOUT3` (table 4-3, p. 4-19).
- **Established.** MT19 sets how many channels are interleaved, which frees PDMA1 to PDMA3 (p. 4-20).
- **Established.** Each engine's buffer is one contiguous ring. There are no scatter-gather lists. The count register reloads its original
  value when it reaches zero, so the buffer wraps (p. 4-19).
- **Inferred.** The buffer limits the field widths imply, assuming the dword unit: about 2 MiB for the interleaved engine and 256 KiB for
  the stereo engines.
- **Unknown.** Whether the terminal count reloads after zero, and what its register reads back. The datasheet does not say.
- **Unknown.** The record burst length. The playback stereo burst is eight cycles, and record is assumed to match (inferred).
- **Unknown.** The converter output while a stream is stopped, and what stopping mid-buffer does to the address and the count.
- **Unit (resolved).** The datasheet gives the playback count as dwords less one (p. 4-19). The IRIX driver zeroes `count << 2`
  bytes and programs `count - 1` into the count register, so it uses the same unit. That the zeroed length is the buffer
  length is **inferred** from the call's byte argument. Linux (`ice1724.c:827-829`), OpenBSD (`envy.c:2137`) and FreeBSD
  (`envy24ht.c:2082`-`2083`) all write dwords less one. A "frame count" reading is not needed.
- **Inferred.** The IRIX driver never writes a terminal-count register and polls the position instead. The notes show no such write.
- **Established.** Start and stop are read-modify-write only; the datasheet insists (p. 4-20). Pause and resume are in MT1B (p. 4-21).
- **Established.** Reading the RDMA0 pointer is only valid after at least two sample frames have elapsed (p. 4-22).

### Routing, peak meters and S/PDIF

- **Established.** The routing register (MT2C) works only in I2S mode and adds at most one sample time of delay (p. 4-25).
- **Inferred.** The IRIX driver never writes MT2C, so default routing (every output from DMA) applies there.
- **Established.** Peak meter: a read of MT3F returns the peak of the selected stream and clears it (p. 4-28).
- **Established.** The S/PDIF transmitter sample-rate field sets itself from MT01 in master mode and takes a software value in slave mode (p. 4-27).
- **Inferred.** The IRIX driver does not use the S/PDIF channel status (MT3C); the notes show no access.

### GPIO pins and the converter bus

- **Established.** 23 GPIOs. Each is bidirectional with a weak pull-up and 8 mA drive (p. 4-8).
- **Established.** A GPIO data bit takes a write only while its write-mask bit is 0. The mask resets to all ones.
- **Established.** GPIO 0 is the AC-link or I2S strap at reset, with AC-link as the default (p. 2-4). GPIO 3 is the EEPROM-present strap, with present as the default (p. 2-4).
- **Established.** GPIO direction bit 2 is forced to input while the test-enable pin is active (p. 4-9).
- **Expectation (public Linux board table, inferred for the DM8).** GPIO 1 is the converter serial clock, GPIO 3 the data out, GPIO 5 and 6
  the active-low chip selects, and GPIO 22 the mute line. The DM8 board wiring is not documented; see [devices/dm8/README.md](../../devices/dm8/README.md).
- **Established (converter datasheets, not the ICE1724).** The converter frame is 16 bits: two chip address bits, a fixed write bit, a
  five-bit register address and eight data bits, most significant bit first. Converters take no reads. A write is latched on the rising
  clock edge and takes effect when the select rises. The minimum clock period is 200 ns. The converters ignore writes while their power-down
  pin is low or master clock is absent. The idle levels of the clock and select between frames are not stated.
- **Inferred.** The MT05 bit 7 pulse resets the converters in I2S mode, and the converter reset pins are wired to `PRST#`. The datasheet
  does not say this. Both drivers rewrite every converter register after the pulse.

### I2C port and EEPROM

- **Established.** The controller is the only I2C master. It does no multi-byte bursts. `SCLK` runs at about 31.25 kHz only during a transfer,
  and is tri-stated when idle. `SDA` is bidirectional (p. 4-8).
- **Established.** CCS13 bit 7 mirrors the GPIO 3 strap at reset. A board with no EEPROM leaves it 0, and the driver then uses defaults.
- **Established.** Device address `1010000` is reserved for the configuration EEPROM; a 24C02 is named (p. 4-7).
- **Unknown.** NAK handling, error reporting, and what a read does when no device answers.
- **Expectation (public Linux driver, inferred here).** The EEPROM layout is:

  | Bytes | Contents |
  |---|---|
  | 0 to 3 | Subsystem IDs, read little-endian. An all-ones first word means blank. |
  | 4 | Size in bytes. The driver falls back to 32 when this is under 6 and rejects it above 32. |
  | 5 | Version, 1 or 2. |
  | 6 to 9 | Values for CCS04 to CCS07. |
  | 10 to 12 | CCS18 direction. |
  | 13 to 15 | GPIO write mask: CCS16 (13, 14) and CCS1F (15). |
  | 16 to 18 | GPIO data: CCS14 (16, 17) and CCS1E (18). |

### AC'97 port

- **Established.** The datasheet defines the AC'97 port: MT04 to MT06, and CCS05 bit 1 for split or packed slots.
- **Inferred.** The DM8 is an I2S design, so the AC'97 path is not used on it.

### Datasheet defects and the working reading for each

Each is something a reader must settle. The working reading is the one the rest of this page uses.

| Defect | Working reading |
|---|---|
| Table 3-1 puts the subsystem ID mask at 0x40; the register section puts it at 0x42. | 0x42, bit 7. |
| PCI command bit 8 is read-write in the table but "hardwired to 0" in the text. | Reads 0, writes ignored. |
| PCI status bits 10:9 are labelled `10b`; the text and the reset value say `01b`. | `01b`. |
| The class code is shown as 16 bits; the header field is 24 bits with a programming interface. | Programming interface 0. |
| MT10, MT20, MT30, MT40, MT50, MT60 and MT70 say "dword units" for bits 31:2. | Byte address, dword aligned. Drivers store it unshifted. |
| MT20 is described as the playback base; it is a record register. | Typo. |
| MT1C is listed at 1C-1D but its field is 18:0. | Laid out over 1C to 1E, which holds 19 bits. |
| MT04 to MT06 are "valid only in AC-link mode", yet both drivers use MT05 bit 7 in I2S mode. | Bit 7 works in I2S mode. The sibling datasheet says so; inferred here. |
| The pin table names "ICE1712". | Copy error. |
| CCS04 bits 7:6: the datasheet says `00` is 24.576 MHz; a comment in the public driver says 22.5792 MHz. | 24.576 MHz. |
| CCS13 bit 7 "default 1" against a printed reset of 00. | Follows the GPIO 3 strap: `80` on a board with an EEPROM. |
| The S/PDIF transmitter presence bit is "CCS07 bit 0" in the pin table and "bit 6" in the register text. | Bit 6. |
| The interrupt line register is headed with the capability pointer's name. | Offset 3Ch, as Table 3-1 shows. |
| The "hardware configuration control" register at 0x60 has no description; the pin table cites bit 7 of PCI61. | Unknown; CCS05 bit 7 carries the same strap. |

## Questions

Register layout, access types and reset values come from the vendor datasheet (see `devices/ice1724/registers.toml`). Still unknown: the
read side effects the datasheet leaves out, the soft-reset effect on this chip, the MPU-401 command bits, the converter
rate-code divider for each rate, and the DM8's own EEPROM image and subsystem IDs. See [questions/README.md](../../questions/README.md).
