/*
 * ice1724.h - VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller registers
 *
 * Written by hand: the census does not cover this part. It is not an SGI chip; it is the controller of the
 * DMediaPro DM8 audio option. Same label convention as the generated headers: [E] established, [I] inferred,
 * [U] unknown. Every offset and access width is from the shipped audio driver object (chips/ice1724/README.md);
 * the roles are inferred from the register names of the public Linux driver, read only after the binary, and are
 * [I] throughout. The part has no interrupt use in that driver. Offsets are within the named base-address region.
 */
#ifndef ICE1724_H
#define ICE1724_H

/* Controller registers (first base-address region, "CCS"). Order matters when the driver loads them from the
 * EEPROM: 0x04 to 0x07, then 0x18, a 10 microsecond delay, then 0x16 and 0x1f, another delay, then 0x14 and 0x1e. */
#define ICE1724_CCS_SYSCONF                  0x04       /* [E] byte; access r (bits 1:0 read) and w (EEPROM byte 6; the driver stores 0x40 when no EEPROM answers); role [I]: system configuration, bits 1:0 = number of stereo DACs less one (value 3 gives 8 analog output channels, 0 to 2 give 2) */
#define ICE1724_CCS_AC97_CONF                0x05       /* [E] byte; read (bit 7 sets the per-device I2S converter flag) and written from EEPROM byte 7; role [I] */
#define ICE1724_CCS_I2S_FEATURES             0x06       /* [E] byte; written from EEPROM byte 8; role [I] */
#define ICE1724_CCS_SPDIF_CONF               0x07       /* [E] byte; read (bit 0 sets the digital-output-present flag) and written from EEPROM byte 9; role [I] */
#define ICE1724_CCS_I2C_DEV_ADDR             0x10       /* [E] byte; the driver writes 0xa0 for the EEPROM; role [I] */
#define ICE1724_CCS_I2C_BYTE_ADDR            0x11       /* [E] byte; role [I] */
#define ICE1724_CCS_I2C_DATA                 0x12       /* [E] byte; read; role [I] */
#define ICE1724_CCS_I2C_CTRL                 0x13       /* [E] byte; bit 7 tested (EEPROM present) and bit 0 polled for busy; role [I] */
#define ICE1724_CCS_GPIO_DATA                0x14       /* [E] 16-bit; GPIO data bits 15:0, read and written; role [I] */
#define ICE1724_CCS_GPIO_MASK                0x16       /* [E] 16-bit; GPIO write mask bits 15:0, loaded from EEPROM bytes 13 and 14; role [I] */
#define ICE1724_CCS_GPIO_DIR                 0x18       /* [E] 32-bit; GPIO direction, 24 bits used, loaded from EEPROM bytes 10 to 12; role [I] */
#define ICE1724_CCS_GPIO_DATA_HI             0x1e       /* [E] byte; GPIO data bits 22:16; role [I] */
#define ICE1724_CCS_GPIO_MASK_HI             0x1f       /* [E] byte; GPIO write mask bits 22:16, loaded from EEPROM byte 15; role [I] */

/* Multitrack registers (second base-address region, "MT"). */
#define ICE1724_MT_RATE                      0x01       /* [E] byte; sample rate code written by the rate routine: 0 for 48 kHz, 4 for 32 kHz, 2 for 12 kHz, 11 for 88.2 kHz equal the public driver's table */
#define ICE1724_MT_MCLK_128X                 0x02       /* [E] byte; bit 3 set for rates of 120000 Hz and above, cleared below; "128x master clock" role [I] */
#define ICE1724_MT_CONVERTER_RESET           0x05       /* [E] byte; bit 7 set, 10 microsecond delay, then cleared during a rate change; role [I] (a converter reset line) */
#define ICE1724_MT_PLAYBACK_ADDR             0x10       /* [E] 32-bit; start address of the playback buffer; role [I] */
#define ICE1724_MT_PLAYBACK_SIZE             0x14       /* [E] 32-bit; written with the frame count less one; unit not extracted [U] */
#define ICE1724_MT_DMA_CONTROL               0x18       /* [E] byte; the driver keeps a shadow and writes it at start and stop: bit 0 analog output stream, bit 1 capture stream, bit 7 digital output stream; bit roles [I] */
#define ICE1724_MT_BURST                     0x19       /* [E] byte; written 0 when analog output has 8 channels, 3 otherwise; role [I] */
#define ICE1724_MT_CAPTURE_ADDR              0x20       /* [E] 32-bit; capture buffer address; role [I] */
#define ICE1724_MT_CAPTURE_SIZE              0x24       /* [E] 16-bit; capture size, frame count less one; also read back as the DMA position; "current address" semantics [I] */
#define ICE1724_MT_SPDIF_OUT_ADDR            0x40       /* [E] 32-bit; digital output buffer address; role [I] */
#define ICE1724_MT_SPDIF_OUT_SIZE            0x44       /* [E] 16-bit; digital output size; role [I] */

#endif /* ICE1724_H */
