# DMediaPro DM8 PCI audio option

## Identification (read this first)

**The DM8 is a commercial off-the-shelf audio design, not an SGI ASIC board.** Grade: controller **established**; "an M-Audio
Revolution 7.1 under an SGI name" **inferred** (strong). The evidence, in order of weight:

1. **Established.** The IRIX 6.5.30 driver for it, `mad_dd.o` (IP35 build, SHA-256
   `905a72a73b0351378bc32c265ddae66b4f9f696b31e0eb9d65993acba78c1518`), registers for PCI vendor `0x1412`, device `0x1724` in
   `mad_init` (`0x0`: `li a0,5138`, `li a1,5924`). `1412:1724` is the VIA/IC Ensemble ICE1724 (Envy24HT) in the public PCI ID
   list (pci.ids 2026.09.23).
2. **Established.** The SGI note *Important Note SGI DMediaPro DM8 PCI Audio Operation*, 007-4077-001 (2004), p. 2, shows the
   Linux enumeration of the board as `Multimedia audio controller: IC Ensemble Inc ICE1724 [Envy24HT] (rev 01)` and a loaded
   module `mad_dd`. The IRIX side reports it as `Iris Audio Processor: version MAD revision 1, number x` (same note, p. 2).
3. **Established.** `mad_create_subsys` (`0x1e4`) reads PCI config `0x2e` (sub-device ID, 2 bytes) and tests it against `0x3630`
   (`0x28c`..`0x294`). `1412:3630` is "M-Audio Revolution 7.1" under the ICE1724 entry in the public PCI ID list; the Linux driver's
   constant for the same card is `VT1724_SUBDEVICE_REVOLUTION71 = 0x12143036` (`revo.h`, Linux 7.2-rc7).
4. **Established.** The code that follows for that match is the public Revolution 7.1 hardware recipe: GPIO bit-banged serial
   control of two converters on chip selects 5 and 6 with chip addresses 1 and 3, a mute line on GPIO 22, an I2C EEPROM at `0xa0`.
   The function names carry the vendor's board name: `mad_init_revolution` (`0x2b2c`) and the table `mad_revo_logtolin`
   (`0x1fa8`). Detail: [chips/ice1724](../../chips/ice1724/README.md).
5. **Inferred.** Converters: AKM AK4381 (chip 1, front pair) and AK4355 (chip 2, six channels) match the public driver's
   programming of that board (see [ak4381](../../chips/ak4381/README.md), [ak4355](../../chips/ak4355/README.md)); the
   input converter AK5380 is named only in secondary reviews of the retail card ([ak5380](../../chips/ak5380/README.md)).

What is **not** established: the actual DM8 board's EEPROM and PCI config contents (no capture), whether SGI changed any
component, and the SGI manufacturing part number (none found in the SGI documents read). If the DM8's sub-device ID were not
`0x3630` the driver would take the AC'97 path instead, which gives a two-channel analog output; the manual's eight-channel
IRIX output list (below) argues against that, so the match is expected but unmeasured.

## Product facts

All from 007-4077-001 unless stated. **Established** as SGI's published statements.

- Name: "SGI DMediaPro DM8 PCI audio option card" (p. 1). Half-size PCI board (p. 1).
- Rear panel, left to right (p. 2 to 3): Surround Center L/R (silver, channels 7/8, IRIX only), Surround L/R (black, channels 5/6,
  IRIX only), Center/Subwoofer (orange, channels 3/4, IRIX only), Front L/R / Phones (green), Line In (blue, stereo), Mic In
  (pink, mono, TRS, electret power).
- Line out: dynamic range 106 dB typical, 1.26 V rms maximum, response +0.8/-3.0 dB, 20 Hz to 80 kHz. Mic in: 90 dB,
  1.45 V rms maximum. Line in: 105 dB (p. 3).
- Rates (kHz): 8, 11.025, 16, 22.05, 32, 44.1, 48, plus 96 and 192 on IRIX only. Playback 24-bit PCM up to 192 kHz (48 on Linux),
  record 24-bit up to 96 kHz (48 on Linux) (p. 3).
- Hosts "tested": Onyx4, Origin 350, Onyx 350 (p. 1). Single card on SGI Linux systems; IRIX takes one or two, needs IRIX 6.5.21
  or later (pp. 1, 4). "Recommended that it not be installed in other SGI systems" (p. 1).
- No digital connector is listed. The driver has a digital output interface (below); with no connector on the panel it is
  inferred to be unpopulated.
- Troubleshooting says to check the default input and output settings in the audio panel when two are installed (p. 4).

Machine support, graded separately:

| Machine | Evidence | Grade |
|---|---|---|
| Origin 350 / Onyx 350 / Onyx4 | tested hosts in 007-4077-001 p. 1 | established (SGI statement) |
| Tezro rackmount | media options list names "DMediaPro DM8 Audio I/O PCI option", 007-4643-003, p. 34; the slot diagram marks "Bus 2, slot 2 (optional audio)", p. 42 | established (SGI statement) |
| Tezro tower | options list "8-channel Digital Audio I/O board", 007-4564-001, p. 42. The text does not say DM8. | inferred that this is the DM8 (eight channels, same era) |
| Fuel | the hardware guide (007-4480-001, pp. 39 and 42) lists a "Digital Audio I/O board"; it does not name DM8. A Fuel owner's hinv with `Iris Audio Processor: version MAD revision 1, number 1` and the post's subject "DM8 audio card" (Usenet message-id `V1UGh.52430$Da4.30732@newsfe6-gui.ntli.net`) | the user report is evidence a DM8 works on a Fuel; **not** an SGI support statement. Grade: **inferred** that a DM8 ran in a Fuel (one user's own hinv and post subject; the MAD revision 1 line is the one the DM8 note gives for the board, but the line names the audio processor, not the card); SGI support: **unknown** |
| Octane/Octane2 | `mad_dd.o` is in the IP30 build; the DM8 note does not list it | unknown: the driver carries a probe, nothing says SGI supported the board there. No MAD line appears in 29 Octane and 3 Octane2 captures of the published hinv corpus (the table in [drivers.md](drivers.md)), which shows no use but is not evidence of absence. Settling test: the Octane and Octane2 option lists in the owner's guides, or a capture from an owner who installed one |

## What the IRIX driver expects (`mad_dd.o`, IP35 build)

Register-level tables and byte-lane rule: [chips/ice1724](../../chips/ice1724/README.md). Summary, all **established** unless marked:

- **Probe.** `1412:1724`; attach at `mad_attach` (`0x14c`) maps BAR0 32 bytes and BAR1 128 bytes, sets latency timer all ones,
  PCI priority 1, then `mad_create_subsys`.
- **Revision.** Config byte `0x08` is placed in the hinv entry (revision 1 expected, see above).
- **Setup order** (`mad_create_subsys`): register the error handler, create the hardware-graph character device (the object's strings include `MAD%d`, `audio` and `mad_subsys`), add the inventory entry, read the EEPROM and copy it to the controller (or `0x40` to the configuration
  byte if no EEPROM), read the configuration (`0x414`), then for the Revolution path run `mad_init_revolution` and
  `mad_set_rate(48000)`; otherwise write four AC'97 registers.
- **Interrupts.** None. No interrupt allocation or connection is imported by the object. Position is polled.
- **DMA.** Three streams. Analog capture at BAR1 `0x20`/`0x24`, multichannel analog playback at `0x10`/`0x14`, digital output at
  `0x40`/`0x44`; start/stop through BAR1 `0x18` with a software shadow. Capture samples are shifted right by 8 after reading.
  A buffer is translated with the Bridge's DMA address call; address limits are not established.
- **Rates.** `mad_set_rate` (`0x2268`) clamps and maps to a code in BAR1 `0x01`, sets the "128x" bit in BAR1 `0x02` for 120 kHz and
  above, pulses BAR1 `0x05` bit 7, and reprograms both converters with speed-dependent registers.
- **Clocks.** One crystal master clock, named "Internal Clock" (`CrystalMclk`), one clock generator. No external clock sync
  appears (**inferred** from the absence of other master-clock strings; the driver has strings for none).
- **Interfaces** (strings at `0x6f10`..`0x7020`): Analog In (Line In, Microphone), Analog Out (Line Out), AES Out (AES Output).
  Physical-interface parameters: sample rate, master clock, gain, gain reference, wordsize, channels. The channel count for
  analog out is 8 when the configuration byte's low two bits are 3, otherwise 2 (`0x4a8`..`0x4c4`).
- **Timestamps.** The driver has no hardware time counter: `mad_enable_ust`, `mad_disable_ust`, `mad_reset_ust` and
  `mad_set_ust_offset` are 8-byte stubs, and `mad_get_hw_mscust` (`0x1340`) returns a software frame count plus a host time.
- **Errors.** `mad_error_handler` (`0x4d0`) prints "DMA Write/Read Error" or "PIO Write/read error" with the PCI address.
- **Mute.** `mad_gpio_mute` (GPIO 22); soft mute through converter register 1 (`mad_i2s_mute`, `0x2a88`).

## Chips on the board

| Part | Role | Revision | Source | Grade |
|---|---|---|---|---|
| VIA/IC Ensemble ICE1724 (Envy24HT) | PCI audio controller | 1 (PCI revision) | driver probe; 007-4077-001 p. 2; hinv post | established |
| AKM AK4381 | front stereo DAC | not given | driver sequence vs public driver | inferred |
| AKM AK4355 | six-channel DAC | not given | same | inferred |
| AKM AK5380 | line/mic ADC | not given | secondary reviews only; no software path | unknown. Settled by: a photograph of the board's converter package marking, or a parts list; no driver reads the ADC, so no binary route exists |
| 24Cxx-style I2C EEPROM at 8-bit address `0xa0` | board configuration | not given | `mad_read_eeprom` (`0x2d50`) | established as a device at that address; part unknown. `mad_read_eeprom` reads 19 bytes at word addresses 0 to 0x12 through `mad_i2c_read` (routine fact tool). Settling test: read `mad_i2c_read` to see whether it sends one address byte (then the part is a 24C01 to 24C16 class device) or two; the exact part needs a photograph of the board's EEPROM marking or a parts list |

## Unknowns and what would settle them

| Unknown | Route |
|---|---|
| The DM8's own PCI config (sub-vendor, sub-device, revision) and EEPROM image | none in software; any published `lspci -vv`/EEPROM dump of a DM8; a hinv `-vm` capture of a DM8 would give the revision only |
| ICE1724 reset values, write masks, rate-code table, DMA size units | the public vendor datasheet (not held), then re-read `mad_set_rate` and `mad_start_dma` against it |
| Converter register field meanings | AKM AK4381 and AK4355 datasheets (public) |
| SGI part number, and whether SGI changed anything | SGI parts lists, or a board photograph |
| Whether the Fuel and Octane support are real (driver present, board unlisted) | a Fuel or Octane hinv capture that shows the MAD line; the Fuel one exists as a user report |
| The AC'97 path's board | none in these media; could be an earlier or other-OEM board |
