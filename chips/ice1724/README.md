# VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller

Mode: **no-spec** (no vendor datasheet is held here; the public Linux `sound/pci/ice1712` driver, Linux 7.2-rc7 `envy24ht.h`,
`ice1724.c` and `revo.c`, was read after the binary and only for names and conflicts). The part is not an SGI chip. It is
the controller of the SGI DMediaPro DM8 PCI audio option, see [docs/audio/dm8.md](../../docs/audio/dm8.md) for the board.

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
  [docs/open-questions.md](../../docs/open-questions.md).

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
| `0x01` | byte | sample rate code written by `mad_set_rate` (`0x2268`) | established access. The codes the function selects (`0` for 48 kHz, `4` for 32 kHz, `2` for 12 kHz, `11` for 88.2 kHz) equal the public driver's rate table; the full table was not extracted. |
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
(`Mem_to_PCI_DMA`, `0x1364`, flags `0x2020`). The ring size, alignment and the hardware's 32-bit address limit are not
established.

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

## Questions

Reset values, write masks and read side effects of every register above are **unknown**: no code reads one before writing it,
and no datasheet is held. See [docs/open-questions.md](../../docs/open-questions.md).
