/* generated from devices/ice1724/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 dd9a3eb1279d5d296b0ebe4786280e365b30feac027d7ff9ddb8d012a80e8ecf */
/* VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller registers */
#ifndef ICE1724_GEN_H
#define ICE1724_GEN_H

#include <stdint.h>


/* enum ac97_slot: CCS05 bit 1, the AC'97 data slot layout. */
#define ICE1724_AC97_SLOT_SPLIT                      0 /* established */
#define ICE1724_AC97_SLOT_PACKED                     1 /* established */

/* enum adc_inputs: CCS04 bits 3:2, the physical stereo inputs. */
#define ICE1724_ADC_INPUTS_ONE_STEREO                0 /* established */
#define ICE1724_ADC_INPUTS_TWO_STEREO                1 /* established */
#define ICE1724_ADC_INPUTS_ONE_STEREO_SPDIF          2 /* established */
#define ICE1724_ADC_INPUTS_NONE                      3 /* established */

/* enum converter_type: CCS05 bit 7, the multi-channel converter type. */
#define ICE1724_CONVERTER_TYPE_AC97                  0 /* established */
#define ICE1724_CONVERTER_TYPE_I2S                   1 /* established */

/* enum i2c_direction: CCS10 bit 0. */
#define ICE1724_I2C_DIRECTION_READ                   0 /* established */
#define ICE1724_I2C_DIRECTION_WRITE                  1 /* established */

/* enum i2s_format: MT02 bits 1:0, the serial data format. Other values are
 * reserved. */
#define ICE1724_I2S_FORMAT_I2S                       0 /* established */

/* enum interleave: MT19 bits 1:0, how many playback channels share the
 * interleaved stream. */
#define ICE1724_INTERLEAVE_ALL_EIGHT                 0 /* established */
#define ICE1724_INTERLEAVE_FIRST_SIX                 1 /* established */
#define ICE1724_INTERLEAVE_FIRST_FOUR                2 /* established */
#define ICE1724_INTERLEAVE_FIRST_PAIR                3 /* established */

/* enum pm_state: PCI PM control bits 1:0. */
#define ICE1724_PM_STATE_D0                          0 /* established */
#define ICE1724_PM_STATE_D1                          1 /* established */
#define ICE1724_PM_STATE_D2                          2 /* established */
#define ICE1724_PM_STATE_D3HOT                       3 /* established */

/* enum rate_code: MT01 bits 3:0 when bit 4 is 0: the sample-rate code for the
 * internal clock tree. */
#define ICE1724_RATE_CODE_K48                        0 /* established */
#define ICE1724_RATE_CODE_K24                        1 /* established */
#define ICE1724_RATE_CODE_K12                        2 /* established */
#define ICE1724_RATE_CODE_K9_6                       3 /* established */
#define ICE1724_RATE_CODE_K32                        4 /* established */
#define ICE1724_RATE_CODE_K16                        5 /* established */
#define ICE1724_RATE_CODE_K8                         6 /* established */
#define ICE1724_RATE_CODE_K96                        7 /* established */
#define ICE1724_RATE_CODE_K44_1                      8 /* established */
#define ICE1724_RATE_CODE_K22_05                     9 /* established */
#define ICE1724_RATE_CODE_K11_025                    10 /* established */
#define ICE1724_RATE_CODE_K88_2                      11 /* established */
#define ICE1724_RATE_CODE_K176_4                     12 /* established */
#define ICE1724_RATE_CODE_UNLISTED_13                13 /* unknown */
#define ICE1724_RATE_CODE_K192                       14 /* established */
#define ICE1724_RATE_CODE_K64                        15 /* established */

/* enum resolution_bits: CCS06 bits 5:4, the I2S converter resolution. */
#define ICE1724_RESOLUTION_BITS_BITS16               0 /* established */
#define ICE1724_RESOLUTION_BITS_BITS18               1 /* established */
#define ICE1724_RESOLUTION_BITS_BITS20               2 /* established */
#define ICE1724_RESOLUTION_BITS_BITS24               3 /* established */

/* enum route_source: MT2C source select for one output channel. Routing works
 * only in I2S mode. */
#define ICE1724_ROUTE_SOURCE_NORMAL                  0 /* established */
#define ICE1724_ROUTE_SOURCE_PSDIN0_LEFT             2 /* established */
#define ICE1724_ROUTE_SOURCE_PSDIN0_RIGHT            3 /* established */
#define ICE1724_ROUTE_SOURCE_SPDIN_LEFT              6 /* established */
#define ICE1724_ROUTE_SOURCE_SPDIN_RIGHT             7 /* established */

/* enum spdif_rate: MT3C bits 14:12, the S/PDIF transmitter sample-rate field.
 * Set from MT01 in master mode, by software in slave mode. */
#define ICE1724_SPDIF_RATE_K44_1                     0 /* established */
#define ICE1724_SPDIF_RATE_RESERVED_1                1 /* established */
#define ICE1724_SPDIF_RATE_K48                       2 /* established */
#define ICE1724_SPDIF_RATE_K32                       3 /* established */
#define ICE1724_SPDIF_RATE_K88_2                     4 /* established */
#define ICE1724_SPDIF_RATE_K96                       5 /* established */
#define ICE1724_SPDIF_RATE_K192                      6 /* established */
#define ICE1724_SPDIF_RATE_K176_4                    7 /* established */

/* enum xin1_clock: CCS04 bits 7:6, the XIN1 crystal. Value 2 and 3 are
 * reserved. */
#define ICE1724_XIN1_CLOCK_CLK24_576                 0 /* established */
#define ICE1724_XIN1_CLOCK_CLK49_152                 1 /* established */

/*
 * Bit 7 is a soft reset of the whole chip. The public driver writes 1, waits,
 * then writes 0; the datasheet does not say whether the bit self-clears. Bits 6
 * to 0 are reserved.
 */
/* ccs_control: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_CONTROL_OFFSET                   0x0u /* established */
#define ICE1724_CCS_CONTROL_SOFT_RESET_SHIFT         7 /* established */
#define ICE1724_CCS_CONTROL_SOFT_RESET_MASK          0x1u
#define ICE1724_CCS_CONTROL_SOFT_RESET_INPLACE (ICE1724_CCS_CONTROL_SOFT_RESET_MASK << ICE1724_CCS_CONTROL_SOFT_RESET_SHIFT)

/*
 * Interrupt mask. A set bit masks the source. The datasheet states this
 * polarity only for MT03; here it is inferred from the reset value and the
 * driver's use. Every source is masked at reset.
 */
/* ccs_irq_mask: rw8, space ccs, reset 0xfe */
#define ICE1724_CCS_IRQ_MASK_OFFSET                  0x1u /* established */
#define ICE1724_CCS_IRQ_MASK_MPU_RECEIVE_SHIFT       7 /* established */
#define ICE1724_CCS_IRQ_MASK_MPU_RECEIVE_MASK        0x1u
#define ICE1724_CCS_IRQ_MASK_MPU_RECEIVE_INPLACE (ICE1724_CCS_IRQ_MASK_MPU_RECEIVE_MASK << ICE1724_CCS_IRQ_MASK_MPU_RECEIVE_SHIFT)
#define ICE1724_CCS_IRQ_MASK_MPU_TRANSMIT_SHIFT      5 /* established */
#define ICE1724_CCS_IRQ_MASK_MPU_TRANSMIT_MASK       0x1u
#define ICE1724_CCS_IRQ_MASK_MPU_TRANSMIT_INPLACE (ICE1724_CCS_IRQ_MASK_MPU_TRANSMIT_MASK << ICE1724_CCS_IRQ_MASK_MPU_TRANSMIT_SHIFT)
#define ICE1724_CCS_IRQ_MASK_MULTICHANNEL_SHIFT      4 /* established */
#define ICE1724_CCS_IRQ_MASK_MULTICHANNEL_MASK       0x1u
#define ICE1724_CCS_IRQ_MASK_MULTICHANNEL_INPLACE (ICE1724_CCS_IRQ_MASK_MULTICHANNEL_MASK << ICE1724_CCS_IRQ_MASK_MULTICHANNEL_SHIFT)

/*
 * Bits 7 and 5 are write-1-to-clear. Bit 4 is read only and clears when its
 * source in the multi-channel register clears. Bits are sticky.
 */
/* ccs_irq_status: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_IRQ_STATUS_OFFSET                0x2u /* established */
#define ICE1724_CCS_IRQ_STATUS_MPU_RECEIVE_SHIFT     7 /* established */
#define ICE1724_CCS_IRQ_STATUS_MPU_RECEIVE_MASK      0x1u
#define ICE1724_CCS_IRQ_STATUS_MPU_RECEIVE_INPLACE (ICE1724_CCS_IRQ_STATUS_MPU_RECEIVE_MASK << ICE1724_CCS_IRQ_STATUS_MPU_RECEIVE_SHIFT)
#define ICE1724_CCS_IRQ_STATUS_MPU_TRANSMIT_SHIFT    5 /* established */
#define ICE1724_CCS_IRQ_STATUS_MPU_TRANSMIT_MASK     0x1u
#define ICE1724_CCS_IRQ_STATUS_MPU_TRANSMIT_INPLACE (ICE1724_CCS_IRQ_STATUS_MPU_TRANSMIT_MASK << ICE1724_CCS_IRQ_STATUS_MPU_TRANSMIT_SHIFT)
#define ICE1724_CCS_IRQ_STATUS_MULTICHANNEL_SHIFT    4 /* established */
#define ICE1724_CCS_IRQ_STATUS_MULTICHANNEL_MASK     0x1u
#define ICE1724_CCS_IRQ_STATUS_MULTICHANNEL_INPLACE (ICE1724_CCS_IRQ_STATUS_MULTICHANNEL_MASK << ICE1724_CCS_IRQ_STATUS_MULTICHANNEL_SHIFT)

/*
 * The public driver copies EEPROM bytes 6 to 9 here; the datasheet says the
 * driver loads them, and hardware does not. The reset value means 24.576 MHz,
 * no UART, no inputs and four stereo DACs.
 */
/* ccs_system_config: rw8, space ccs, reset 0xf */
#define ICE1724_CCS_SYSTEM_CONFIG_OFFSET             0x4u /* established */
#define ICE1724_CCS_SYSTEM_CONFIG_XIN1_CLOCK_SHIFT   6 /* established */
#define ICE1724_CCS_SYSTEM_CONFIG_XIN1_CLOCK_MASK    0x3u
#define ICE1724_CCS_SYSTEM_CONFIG_XIN1_CLOCK_INPLACE (ICE1724_CCS_SYSTEM_CONFIG_XIN1_CLOCK_MASK << ICE1724_CCS_SYSTEM_CONFIG_XIN1_CLOCK_SHIFT)
#define ICE1724_CCS_SYSTEM_CONFIG_MPU_UART_SHIFT     5 /* established */
#define ICE1724_CCS_SYSTEM_CONFIG_MPU_UART_MASK      0x1u
#define ICE1724_CCS_SYSTEM_CONFIG_MPU_UART_INPLACE (ICE1724_CCS_SYSTEM_CONFIG_MPU_UART_MASK << ICE1724_CCS_SYSTEM_CONFIG_MPU_UART_SHIFT)
#define ICE1724_CCS_SYSTEM_CONFIG_ADC_INPUTS_SHIFT   2 /* established */
#define ICE1724_CCS_SYSTEM_CONFIG_ADC_INPUTS_MASK    0x3u
#define ICE1724_CCS_SYSTEM_CONFIG_ADC_INPUTS_INPLACE (ICE1724_CCS_SYSTEM_CONFIG_ADC_INPUTS_MASK << ICE1724_CCS_SYSTEM_CONFIG_ADC_INPUTS_SHIFT)
#define ICE1724_CCS_SYSTEM_CONFIG_DAC_COUNT_MINUS_ONE_SHIFT 0 /* established */
#define ICE1724_CCS_SYSTEM_CONFIG_DAC_COUNT_MINUS_ONE_MASK 0x3u
#define ICE1724_CCS_SYSTEM_CONFIG_DAC_COUNT_MINUS_ONE_INPLACE (ICE1724_CCS_SYSTEM_CONFIG_DAC_COUNT_MINUS_ONE_MASK << ICE1724_CCS_SYSTEM_CONFIG_DAC_COUNT_MINUS_ONE_SHIFT)

/*
 * Converter type and AC'97 slot layout. Bit 7 reflects the power-up strap on
 * GPIO 0 in reverse and may be overwritten.
 */
/* ccs_ac97_config: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_AC97_CONFIG_OFFSET               0x5u /* established */
#define ICE1724_CCS_AC97_CONFIG_CONVERTER_TYPE_SHIFT 7 /* established */
#define ICE1724_CCS_AC97_CONFIG_CONVERTER_TYPE_MASK  0x1u
#define ICE1724_CCS_AC97_CONFIG_CONVERTER_TYPE_INPLACE (ICE1724_CCS_AC97_CONFIG_CONVERTER_TYPE_MASK << ICE1724_CCS_AC97_CONFIG_CONVERTER_TYPE_SHIFT)
#define ICE1724_CCS_AC97_CONFIG_AC97_SLOT_SHIFT      1 /* established */
#define ICE1724_CCS_AC97_CONFIG_AC97_SLOT_MASK       0x1u
#define ICE1724_CCS_AC97_CONFIG_AC97_SLOT_INPLACE (ICE1724_CCS_AC97_CONFIG_AC97_SLOT_MASK << ICE1724_CCS_AC97_CONFIG_AC97_SLOT_SHIFT)

/*
 * Converter capabilities, written from the EEPROM.
 */
/* ccs_i2s_features: rw8, space ccs, reset 0x1 */
#define ICE1724_CCS_I2S_FEATURES_OFFSET              0x6u /* established */
#define ICE1724_CCS_I2S_FEATURES_VOLUME_BY_GPIO_SHIFT 7 /* established */
#define ICE1724_CCS_I2S_FEATURES_VOLUME_BY_GPIO_MASK 0x1u
#define ICE1724_CCS_I2S_FEATURES_VOLUME_BY_GPIO_INPLACE (ICE1724_CCS_I2S_FEATURES_VOLUME_BY_GPIO_MASK << ICE1724_CCS_I2S_FEATURES_VOLUME_BY_GPIO_SHIFT)
#define ICE1724_CCS_I2S_FEATURES_SUPPORTS_96K_SHIFT  6 /* established */
#define ICE1724_CCS_I2S_FEATURES_SUPPORTS_96K_MASK   0x1u
#define ICE1724_CCS_I2S_FEATURES_SUPPORTS_96K_INPLACE (ICE1724_CCS_I2S_FEATURES_SUPPORTS_96K_MASK << ICE1724_CCS_I2S_FEATURES_SUPPORTS_96K_SHIFT)
#define ICE1724_CCS_I2S_FEATURES_RESOLUTION_SHIFT    4 /* established */
#define ICE1724_CCS_I2S_FEATURES_RESOLUTION_MASK     0x3u
#define ICE1724_CCS_I2S_FEATURES_RESOLUTION_INPLACE (ICE1724_CCS_I2S_FEATURES_RESOLUTION_MASK << ICE1724_CCS_I2S_FEATURES_RESOLUTION_SHIFT)
#define ICE1724_CCS_I2S_FEATURES_SUPPORTS_192K_SHIFT 3 /* established */
#define ICE1724_CCS_I2S_FEATURES_SUPPORTS_192K_MASK  0x1u
#define ICE1724_CCS_I2S_FEATURES_SUPPORTS_192K_INPLACE (ICE1724_CCS_I2S_FEATURES_SUPPORTS_192K_MASK << ICE1724_CCS_I2S_FEATURES_SUPPORTS_192K_SHIFT)
#define ICE1724_CCS_I2S_FEATURES_OTHER_IDS_SHIFT     0 /* unknown */
#define ICE1724_CCS_I2S_FEATURES_OTHER_IDS_MASK      0x7u
#define ICE1724_CCS_I2S_FEATURES_OTHER_IDS_INPLACE (ICE1724_CCS_I2S_FEATURES_OTHER_IDS_MASK << ICE1724_CCS_I2S_FEATURES_OTHER_IDS_SHIFT)

/*
 * S/PDIF transmitter enable and capability bits. Bit 6 is read only and
 * reflects the SPDTX pin during reset, reversed: 0 means the transmitter is on
 * the board.
 */
/* ccs_spdif_config: rw8, space ccs, reset 0x1 */
#define ICE1724_CCS_SPDIF_CONFIG_OFFSET              0x7u /* established */
#define ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_ENABLE_SHIFT 7 /* established */
#define ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_ENABLE_MASK 0x1u
#define ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_ENABLE_INPLACE (ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_ENABLE_MASK << ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_ENABLE_SHIFT)
#define ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_PRESENT_SHIFT 6 /* established */
#define ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_PRESENT_MASK 0x1u
#define ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_PRESENT_INPLACE (ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_PRESENT_MASK << ICE1724_CCS_SPDIF_CONFIG_TRANSMITTER_PRESENT_SHIFT)
#define ICE1724_CCS_SPDIF_CONFIG_SPDIF_IDS_SHIFT     2 /* unknown */
#define ICE1724_CCS_SPDIF_CONFIG_SPDIF_IDS_MASK      0xfu
#define ICE1724_CCS_SPDIF_CONFIG_SPDIF_IDS_INPLACE (ICE1724_CCS_SPDIF_CONFIG_SPDIF_IDS_MASK << ICE1724_CCS_SPDIF_CONFIG_SPDIF_IDS_SHIFT)
#define ICE1724_CCS_SPDIF_CONFIG_SPDIF_INPUT_SHIFT   1 /* established */
#define ICE1724_CCS_SPDIF_CONFIG_SPDIF_INPUT_MASK    0x1u
#define ICE1724_CCS_SPDIF_CONFIG_SPDIF_INPUT_INPLACE (ICE1724_CCS_SPDIF_CONFIG_SPDIF_INPUT_MASK << ICE1724_CCS_SPDIF_CONFIG_SPDIF_INPUT_SHIFT)
#define ICE1724_CCS_SPDIF_CONFIG_EXTERNAL_OUTPUT_SHIFT 0 /* established */
#define ICE1724_CCS_SPDIF_CONFIG_EXTERNAL_OUTPUT_MASK 0x1u
#define ICE1724_CCS_SPDIF_CONFIG_EXTERNAL_OUTPUT_INPLACE (ICE1724_CCS_SPDIF_CONFIG_EXTERNAL_OUTPUT_MASK << ICE1724_CCS_SPDIF_CONFIG_EXTERNAL_OUTPUT_SHIFT)

/*
 * Valid bytes in the MPU-401 transmit FIFO, which is 32 deep.
 */
/* ccs_uart_tx_count: r8, space ccs, reset 0x0 */
#define ICE1724_CCS_UART_TX_COUNT_OFFSET             0xau /* established */
#define ICE1724_CCS_UART_TX_COUNT_COUNT_SHIFT        0 /* established */
#define ICE1724_CCS_UART_TX_COUNT_COUNT_MASK         0x1fu
#define ICE1724_CCS_UART_TX_COUNT_COUNT_INPLACE (ICE1724_CCS_UART_TX_COUNT_COUNT_MASK << ICE1724_CCS_UART_TX_COUNT_COUNT_SHIFT)

/*
 * Valid bytes in the MPU-401 receive FIFO, which is 32 deep.
 */
/* ccs_uart_rx_count: r8, space ccs, reset 0x0 */
#define ICE1724_CCS_UART_RX_COUNT_OFFSET             0xbu /* established */
#define ICE1724_CCS_UART_RX_COUNT_COUNT_SHIFT        0 /* established */
#define ICE1724_CCS_UART_RX_COUNT_COUNT_MASK         0x1fu
#define ICE1724_CCS_UART_RX_COUNT_COUNT_INPLACE (ICE1724_CCS_UART_RX_COUNT_COUNT_MASK << ICE1724_CCS_UART_RX_COUNT_COUNT_SHIFT)

/*
 * MPU-401 data port.
 */
/* ccs_midi_data: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_MIDI_DATA_OFFSET                 0xcu /* established */

/*
 * MPU-401 command and status. The datasheet gives no bit definitions. The
 * public Linux driver's reading (bit 0 UART mode, bits 1 to 4 FIFO empty and
 * full flags) is an expectation, not established.
 */
/* ccs_midi_command: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_MIDI_COMMAND_OFFSET              0xdu /* unknown */

/*
 * MPU-401 watermark. Both watermarks reset to 0.
 */
/* ccs_uart_setting: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_UART_SETTING_OFFSET              0xeu /* established */
#define ICE1724_CCS_UART_SETTING_RX_MARK_SELECT_SHIFT 5 /* established */
#define ICE1724_CCS_UART_SETTING_RX_MARK_SELECT_MASK 0x1u
#define ICE1724_CCS_UART_SETTING_RX_MARK_SELECT_INPLACE (ICE1724_CCS_UART_SETTING_RX_MARK_SELECT_MASK << ICE1724_CCS_UART_SETTING_RX_MARK_SELECT_SHIFT)
#define ICE1724_CCS_UART_SETTING_WATERMARK_SHIFT     0 /* established */
#define ICE1724_CCS_UART_SETTING_WATERMARK_MASK      0x1fu
#define ICE1724_CCS_UART_SETTING_WATERMARK_INPLACE (ICE1724_CCS_UART_SETTING_WATERMARK_MASK << ICE1724_CCS_UART_SETTING_WATERMARK_SHIFT)

/*
 * Writing this register starts an I2C transfer, so the busy bit must be clear
 * first. Device address 1010000 is reserved for the configuration EEPROM.
 */
/* ccs_i2c_device: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_I2C_DEVICE_OFFSET                0x10u /* established */
#define ICE1724_CCS_I2C_DEVICE_DEVICE_SHIFT          1 /* established */
#define ICE1724_CCS_I2C_DEVICE_DEVICE_MASK           0x7fu
#define ICE1724_CCS_I2C_DEVICE_DEVICE_INPLACE (ICE1724_CCS_I2C_DEVICE_DEVICE_MASK << ICE1724_CCS_I2C_DEVICE_DEVICE_SHIFT)
#define ICE1724_CCS_I2C_DEVICE_DIRECTION_SHIFT       0 /* established */
#define ICE1724_CCS_I2C_DEVICE_DIRECTION_MASK        0x1u
#define ICE1724_CCS_I2C_DEVICE_DIRECTION_INPLACE (ICE1724_CCS_I2C_DEVICE_DIRECTION_MASK << ICE1724_CCS_I2C_DEVICE_DIRECTION_SHIFT)

/*
 * I2C byte address.
 */
/* ccs_i2c_byte: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_I2C_BYTE_OFFSET                  0x11u /* established */

/*
 * I2C data byte, written before a write transfer and read after a read
 * transfer.
 */
/* ccs_i2c_data: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_I2C_DATA_OFFSET                  0x12u /* established */

/*
 * Bit 7 mirrors the EEPROM strap on GPIO 3 at reset, so a board with an EEPROM
 * reads 80. The printed reset 00 conflicts with that text; the text is taken.
 * Bit 0 is busy. Bit 1 is reserved, keep 0.
 */
/* ccs_i2c_status: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_I2C_STATUS_OFFSET                0x13u /* established */
#define ICE1724_CCS_I2C_STATUS_EEPROM_PRESENT_SHIFT  7 /* established */
#define ICE1724_CCS_I2C_STATUS_EEPROM_PRESENT_MASK   0x1u
#define ICE1724_CCS_I2C_STATUS_EEPROM_PRESENT_INPLACE (ICE1724_CCS_I2C_STATUS_EEPROM_PRESENT_MASK << ICE1724_CCS_I2C_STATUS_EEPROM_PRESENT_SHIFT)
#define ICE1724_CCS_I2C_STATUS_BUSY_SHIFT            0 /* established */
#define ICE1724_CCS_I2C_STATUS_BUSY_MASK             0x1u
#define ICE1724_CCS_I2C_STATUS_BUSY_INPLACE (ICE1724_CCS_I2C_STATUS_BUSY_MASK << ICE1724_CCS_I2C_STATUS_BUSY_SHIFT)

/*
 * GPIO data, bits 15 to 0. A bit takes a write only while its write-mask bit is
 * 0. Bits 22 to 16 are in ccs_gpio_data_hi.
 */
/* ccs_gpio_data: rw16, space ccs, reset 0x0 */
#define ICE1724_CCS_GPIO_DATA_OFFSET                 0x14u /* established */

/*
 * GPIO write mask, bits 15 to 0. Reset masks every bit, so no GPIO data can be
 * written until software clears mask bits. Bits 22 to 16 are in
 * ccs_gpio_mask_hi.
 */
/* ccs_gpio_mask: rw16, space ccs, reset 0xffff */
#define ICE1724_CCS_GPIO_MASK_OFFSET                 0x16u /* established */

/*
 * GPIO direction in three bytes, 0x18 to 0x1A. Bits 22 to 0 are defined: 0 is
 * input, 1 is output. Bit 3 doubles as the EEPROM strap at reset; bit 2 is
 * forced to input while the test-enable pin is active.
 */
/* ccs_gpio_direction: rw32, space ccs, reset 0x0 */
#define ICE1724_CCS_GPIO_DIRECTION_OFFSET            0x18u /* established */
#define ICE1724_CCS_GPIO_DIRECTION_DIRECTION_SHIFT   0 /* established */
#define ICE1724_CCS_GPIO_DIRECTION_DIRECTION_MASK    0x7fffffu
#define ICE1724_CCS_GPIO_DIRECTION_DIRECTION_INPLACE (ICE1724_CCS_GPIO_DIRECTION_DIRECTION_MASK << ICE1724_CCS_GPIO_DIRECTION_DIRECTION_SHIFT)

/*
 * Each bit set stops or powers down the named clock. Bits 6 and 1 are reserved.
 * The ALSA driver writes 0 here, which is an expectation.
 */
/* ccs_power_down: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_POWER_DOWN_OFFSET                0x1cu /* established */
#define ICE1724_CCS_POWER_DOWN_XIN1_CLOCK_SHIFT      7 /* established */
#define ICE1724_CCS_POWER_DOWN_XIN1_CLOCK_MASK       0x1u
#define ICE1724_CCS_POWER_DOWN_XIN1_CLOCK_INPLACE (ICE1724_CCS_POWER_DOWN_XIN1_CLOCK_MASK << ICE1724_CCS_POWER_DOWN_XIN1_CLOCK_SHIFT)
#define ICE1724_CCS_POWER_DOWN_XIN2_CLOCK_SHIFT      5 /* established */
#define ICE1724_CCS_POWER_DOWN_XIN2_CLOCK_MASK       0x1u
#define ICE1724_CCS_POWER_DOWN_XIN2_CLOCK_INPLACE (ICE1724_CCS_POWER_DOWN_XIN2_CLOCK_MASK << ICE1724_CCS_POWER_DOWN_XIN2_CLOCK_SHIFT)
#define ICE1724_CCS_POWER_DOWN_I2C_CLOCK_SHIFT       4 /* established */
#define ICE1724_CCS_POWER_DOWN_I2C_CLOCK_MASK        0x1u
#define ICE1724_CCS_POWER_DOWN_I2C_CLOCK_INPLACE (ICE1724_CCS_POWER_DOWN_I2C_CLOCK_MASK << ICE1724_CCS_POWER_DOWN_I2C_CLOCK_SHIFT)
#define ICE1724_CCS_POWER_DOWN_MIDI_CLOCK_SHIFT      3 /* established */
#define ICE1724_CCS_POWER_DOWN_MIDI_CLOCK_MASK       0x1u
#define ICE1724_CCS_POWER_DOWN_MIDI_CLOCK_INPLACE (ICE1724_CCS_POWER_DOWN_MIDI_CLOCK_MASK << ICE1724_CCS_POWER_DOWN_MIDI_CLOCK_SHIFT)
#define ICE1724_CCS_POWER_DOWN_SPDIF_CLOCK_SHIFT     2 /* established */
#define ICE1724_CCS_POWER_DOWN_SPDIF_CLOCK_MASK      0x1u
#define ICE1724_CCS_POWER_DOWN_SPDIF_CLOCK_INPLACE (ICE1724_CCS_POWER_DOWN_SPDIF_CLOCK_MASK << ICE1724_CCS_POWER_DOWN_SPDIF_CLOCK_SHIFT)
#define ICE1724_CCS_POWER_DOWN_SERIAL_CLOCK_SHIFT    0 /* established */
#define ICE1724_CCS_POWER_DOWN_SERIAL_CLOCK_MASK     0x1u
#define ICE1724_CCS_POWER_DOWN_SERIAL_CLOCK_INPLACE (ICE1724_CCS_POWER_DOWN_SERIAL_CLOCK_MASK << ICE1724_CCS_POWER_DOWN_SERIAL_CLOCK_SHIFT)

/*
 * GPIO data, bits 22 to 16 in bits 6 to 0. Masked by ccs_gpio_mask_hi.
 */
/* ccs_gpio_data_hi: rw8, space ccs, reset 0x0 */
#define ICE1724_CCS_GPIO_DATA_HI_OFFSET              0x1eu /* established */
#define ICE1724_CCS_GPIO_DATA_HI_DATA_SHIFT          0 /* established */
#define ICE1724_CCS_GPIO_DATA_HI_DATA_MASK           0x7fu
#define ICE1724_CCS_GPIO_DATA_HI_DATA_INPLACE (ICE1724_CCS_GPIO_DATA_HI_DATA_MASK << ICE1724_CCS_GPIO_DATA_HI_DATA_SHIFT)

/*
 * GPIO write mask, bits 22 to 16 in bits 6 to 0.
 */
/* ccs_gpio_mask_hi: rw8, space ccs, reset 0xff */
#define ICE1724_CCS_GPIO_MASK_HI_OFFSET              0x1fu /* established */
#define ICE1724_CCS_GPIO_MASK_HI_MASK_SHIFT          0 /* established */
#define ICE1724_CCS_GPIO_MASK_HI_MASK_MASK           0x7fu
#define ICE1724_CCS_GPIO_MASK_HI_MASK_INPLACE (ICE1724_CCS_GPIO_MASK_HI_MASK_MASK << ICE1724_CCS_GPIO_MASK_HI_MASK_SHIFT)

/*
 * One bit per source; write 1 to clear. The multi-channel source bit in the
 * controller's status register is inferred to be the OR of the unmasked bits
 * here. Bit 3 is set by any underrun or overrun flag.
 */
/* mt_irq_status: rw8, space mt, reset 0x0 */
#define ICE1724_MT_IRQ_STATUS_OFFSET                 0x0u /* established */
#define ICE1724_MT_IRQ_STATUS_SPDIF_OUT_SHIFT        7 /* established */
#define ICE1724_MT_IRQ_STATUS_SPDIF_OUT_MASK         0x1u
#define ICE1724_MT_IRQ_STATUS_SPDIF_OUT_INPLACE (ICE1724_MT_IRQ_STATUS_SPDIF_OUT_MASK << ICE1724_MT_IRQ_STATUS_SPDIF_OUT_SHIFT)
#define ICE1724_MT_IRQ_STATUS_PDMA3_SHIFT            6 /* established */
#define ICE1724_MT_IRQ_STATUS_PDMA3_MASK             0x1u
#define ICE1724_MT_IRQ_STATUS_PDMA3_INPLACE (ICE1724_MT_IRQ_STATUS_PDMA3_MASK << ICE1724_MT_IRQ_STATUS_PDMA3_SHIFT)
#define ICE1724_MT_IRQ_STATUS_PDMA2_SHIFT            5 /* established */
#define ICE1724_MT_IRQ_STATUS_PDMA2_MASK             0x1u
#define ICE1724_MT_IRQ_STATUS_PDMA2_INPLACE (ICE1724_MT_IRQ_STATUS_PDMA2_MASK << ICE1724_MT_IRQ_STATUS_PDMA2_SHIFT)
#define ICE1724_MT_IRQ_STATUS_PDMA1_SHIFT            4 /* established */
#define ICE1724_MT_IRQ_STATUS_PDMA1_MASK             0x1u
#define ICE1724_MT_IRQ_STATUS_PDMA1_INPLACE (ICE1724_MT_IRQ_STATUS_PDMA1_MASK << ICE1724_MT_IRQ_STATUS_PDMA1_SHIFT)
#define ICE1724_MT_IRQ_STATUS_FIFO_ERROR_SHIFT       3 /* established */
#define ICE1724_MT_IRQ_STATUS_FIFO_ERROR_MASK        0x1u
#define ICE1724_MT_IRQ_STATUS_FIFO_ERROR_INPLACE (ICE1724_MT_IRQ_STATUS_FIFO_ERROR_MASK << ICE1724_MT_IRQ_STATUS_FIFO_ERROR_SHIFT)
#define ICE1724_MT_IRQ_STATUS_RDMA1_SHIFT            2 /* established */
#define ICE1724_MT_IRQ_STATUS_RDMA1_MASK             0x1u
#define ICE1724_MT_IRQ_STATUS_RDMA1_INPLACE (ICE1724_MT_IRQ_STATUS_RDMA1_MASK << ICE1724_MT_IRQ_STATUS_RDMA1_SHIFT)
#define ICE1724_MT_IRQ_STATUS_RDMA0_SHIFT            1 /* established */
#define ICE1724_MT_IRQ_STATUS_RDMA0_MASK             0x1u
#define ICE1724_MT_IRQ_STATUS_RDMA0_INPLACE (ICE1724_MT_IRQ_STATUS_RDMA0_MASK << ICE1724_MT_IRQ_STATUS_RDMA0_SHIFT)
#define ICE1724_MT_IRQ_STATUS_PDMA0_SHIFT            0 /* established */
#define ICE1724_MT_IRQ_STATUS_PDMA0_MASK             0x1u
#define ICE1724_MT_IRQ_STATUS_PDMA0_INPLACE (ICE1724_MT_IRQ_STATUS_PDMA0_MASK << ICE1724_MT_IRQ_STATUS_PDMA0_SHIFT)

/*
 * Sample rate. When bit 4 is 1 the rate code is ignored and the S/PDIF input
 * clock is the master, with the master clock on the SPMCLKIN pin.
 */
/* mt_sampling_rate: rw8, space mt, reset 0x0 */
#define ICE1724_MT_SAMPLING_RATE_OFFSET              0x1u /* established */
#define ICE1724_MT_SAMPLING_RATE_SPDIF_INPUT_MASTER_SHIFT 4 /* established */
#define ICE1724_MT_SAMPLING_RATE_SPDIF_INPUT_MASTER_MASK 0x1u
#define ICE1724_MT_SAMPLING_RATE_SPDIF_INPUT_MASTER_INPLACE (ICE1724_MT_SAMPLING_RATE_SPDIF_INPUT_MASTER_MASK << ICE1724_MT_SAMPLING_RATE_SPDIF_INPUT_MASTER_SHIFT)
#define ICE1724_MT_SAMPLING_RATE_RATE_CODE_SHIFT     0 /* established */
#define ICE1724_MT_SAMPLING_RATE_RATE_CODE_MASK      0xfu
#define ICE1724_MT_SAMPLING_RATE_RATE_CODE_INPLACE (ICE1724_MT_SAMPLING_RATE_RATE_CODE_MASK << ICE1724_MT_SAMPLING_RATE_RATE_CODE_SHIFT)

/*
 * Clock ratio and data format. Bit 3 selects a 128x master clock; 176.4 kHz
 * forces it. Bit 2 is listed read-write with no description.
 */
/* mt_i2s_format: rw8, space mt, reset 0x0 */
#define ICE1724_MT_I2S_FORMAT_OFFSET                 0x2u /* established */
#define ICE1724_MT_I2S_FORMAT_MCLK_128X_SHIFT        3 /* established */
#define ICE1724_MT_I2S_FORMAT_MCLK_128X_MASK         0x1u
#define ICE1724_MT_I2S_FORMAT_MCLK_128X_INPLACE (ICE1724_MT_I2S_FORMAT_MCLK_128X_MASK << ICE1724_MT_I2S_FORMAT_MCLK_128X_SHIFT)
#define ICE1724_MT_I2S_FORMAT_BIT2_SHIFT             2 /* unknown */
#define ICE1724_MT_I2S_FORMAT_BIT2_MASK              0x1u
#define ICE1724_MT_I2S_FORMAT_BIT2_INPLACE (ICE1724_MT_I2S_FORMAT_BIT2_MASK << ICE1724_MT_I2S_FORMAT_BIT2_SHIFT)
#define ICE1724_MT_I2S_FORMAT_FORMAT_SHIFT           0 /* established */
#define ICE1724_MT_I2S_FORMAT_FORMAT_MASK            0x3u
#define ICE1724_MT_I2S_FORMAT_FORMAT_INPLACE (ICE1724_MT_I2S_FORMAT_FORMAT_MASK << ICE1724_MT_I2S_FORMAT_FORMAT_SHIFT)

/*
 * Source mask, same bit layout as mt_irq_status. A set bit masks the source.
 * Every source is masked at reset.
 */
/* mt_irq_mask: rw8, space mt, reset 0xff */
#define ICE1724_MT_IRQ_MASK_OFFSET                   0x3u /* established */
#define ICE1724_MT_IRQ_MASK_SPDIF_OUT_SHIFT          7 /* established */
#define ICE1724_MT_IRQ_MASK_SPDIF_OUT_MASK           0x1u
#define ICE1724_MT_IRQ_MASK_SPDIF_OUT_INPLACE (ICE1724_MT_IRQ_MASK_SPDIF_OUT_MASK << ICE1724_MT_IRQ_MASK_SPDIF_OUT_SHIFT)
#define ICE1724_MT_IRQ_MASK_PDMA3_SHIFT              6 /* established */
#define ICE1724_MT_IRQ_MASK_PDMA3_MASK               0x1u
#define ICE1724_MT_IRQ_MASK_PDMA3_INPLACE (ICE1724_MT_IRQ_MASK_PDMA3_MASK << ICE1724_MT_IRQ_MASK_PDMA3_SHIFT)
#define ICE1724_MT_IRQ_MASK_PDMA2_SHIFT              5 /* established */
#define ICE1724_MT_IRQ_MASK_PDMA2_MASK               0x1u
#define ICE1724_MT_IRQ_MASK_PDMA2_INPLACE (ICE1724_MT_IRQ_MASK_PDMA2_MASK << ICE1724_MT_IRQ_MASK_PDMA2_SHIFT)
#define ICE1724_MT_IRQ_MASK_PDMA1_SHIFT              4 /* established */
#define ICE1724_MT_IRQ_MASK_PDMA1_MASK               0x1u
#define ICE1724_MT_IRQ_MASK_PDMA1_INPLACE (ICE1724_MT_IRQ_MASK_PDMA1_MASK << ICE1724_MT_IRQ_MASK_PDMA1_SHIFT)
#define ICE1724_MT_IRQ_MASK_FIFO_ERROR_SHIFT         3 /* established */
#define ICE1724_MT_IRQ_MASK_FIFO_ERROR_MASK          0x1u
#define ICE1724_MT_IRQ_MASK_FIFO_ERROR_INPLACE (ICE1724_MT_IRQ_MASK_FIFO_ERROR_MASK << ICE1724_MT_IRQ_MASK_FIFO_ERROR_SHIFT)
#define ICE1724_MT_IRQ_MASK_RDMA1_SHIFT              2 /* established */
#define ICE1724_MT_IRQ_MASK_RDMA1_MASK               0x1u
#define ICE1724_MT_IRQ_MASK_RDMA1_INPLACE (ICE1724_MT_IRQ_MASK_RDMA1_MASK << ICE1724_MT_IRQ_MASK_RDMA1_SHIFT)
#define ICE1724_MT_IRQ_MASK_RDMA0_SHIFT              1 /* established */
#define ICE1724_MT_IRQ_MASK_RDMA0_MASK               0x1u
#define ICE1724_MT_IRQ_MASK_RDMA0_INPLACE (ICE1724_MT_IRQ_MASK_RDMA0_MASK << ICE1724_MT_IRQ_MASK_RDMA0_SHIFT)
#define ICE1724_MT_IRQ_MASK_PDMA0_SHIFT              0 /* established */
#define ICE1724_MT_IRQ_MASK_PDMA0_MASK               0x1u
#define ICE1724_MT_IRQ_MASK_PDMA0_INPLACE (ICE1724_MT_IRQ_MASK_PDMA0_MASK << ICE1724_MT_IRQ_MASK_PDMA0_SHIFT)

/*
 * AC'97 register index. Valid only in AC-link mode, though the drivers also use
 * the converter reset bit in I2S mode.
 */
/* mt_ac97_index: rw8, space mt, reset 0x0 */
#define ICE1724_MT_AC97_INDEX_OFFSET                 0x4u /* established */
#define ICE1724_MT_AC97_INDEX_INDEX_SHIFT            0 /* established */
#define ICE1724_MT_AC97_INDEX_INDEX_MASK             0x7fu
#define ICE1724_MT_AC97_INDEX_INDEX_INPLACE (ICE1724_MT_AC97_INDEX_INDEX_MASK << ICE1724_MT_AC97_INDEX_INDEX_SHIFT)

/*
 * AC'97 command and status. The datasheet limits this register to AC-link mode.
 * In I2S mode bit 7 is inferred to reset the converters, from the sibling
 * part's datasheet and both drivers.
 */
/* mt_ac97_command: rw8, space mt, reset 0x0 */
#define ICE1724_MT_AC97_COMMAND_OFFSET               0x5u /* established */
#define ICE1724_MT_AC97_COMMAND_COLD_RESET_SHIFT     7 /* established */
#define ICE1724_MT_AC97_COMMAND_COLD_RESET_MASK      0x1u
#define ICE1724_MT_AC97_COMMAND_COLD_RESET_INPLACE (ICE1724_MT_AC97_COMMAND_COLD_RESET_MASK << ICE1724_MT_AC97_COMMAND_COLD_RESET_SHIFT)
#define ICE1724_MT_AC97_COMMAND_WARM_RESET_SHIFT     6 /* established */
#define ICE1724_MT_AC97_COMMAND_WARM_RESET_MASK      0x1u
#define ICE1724_MT_AC97_COMMAND_WARM_RESET_INPLACE (ICE1724_MT_AC97_COMMAND_WARM_RESET_MASK << ICE1724_MT_AC97_COMMAND_WARM_RESET_SHIFT)
#define ICE1724_MT_AC97_COMMAND_WRITE_CYCLE_SHIFT    5 /* established */
#define ICE1724_MT_AC97_COMMAND_WRITE_CYCLE_MASK     0x1u
#define ICE1724_MT_AC97_COMMAND_WRITE_CYCLE_INPLACE (ICE1724_MT_AC97_COMMAND_WRITE_CYCLE_MASK << ICE1724_MT_AC97_COMMAND_WRITE_CYCLE_SHIFT)
#define ICE1724_MT_AC97_COMMAND_READ_CYCLE_SHIFT     4 /* established */
#define ICE1724_MT_AC97_COMMAND_READ_CYCLE_MASK      0x1u
#define ICE1724_MT_AC97_COMMAND_READ_CYCLE_INPLACE (ICE1724_MT_AC97_COMMAND_READ_CYCLE_MASK << ICE1724_MT_AC97_COMMAND_READ_CYCLE_SHIFT)
#define ICE1724_MT_AC97_COMMAND_CODEC_READY_SHIFT    3 /* established */
#define ICE1724_MT_AC97_COMMAND_CODEC_READY_MASK     0x1u
#define ICE1724_MT_AC97_COMMAND_CODEC_READY_INPLACE (ICE1724_MT_AC97_COMMAND_CODEC_READY_MASK << ICE1724_MT_AC97_COMMAND_CODEC_READY_SHIFT)
#define ICE1724_MT_AC97_COMMAND_CODEC_SELECT_SHIFT   0 /* established */
#define ICE1724_MT_AC97_COMMAND_CODEC_SELECT_MASK    0x3u
#define ICE1724_MT_AC97_COMMAND_CODEC_SELECT_INPLACE (ICE1724_MT_AC97_COMMAND_CODEC_SELECT_MASK << ICE1724_MT_AC97_COMMAND_CODEC_SELECT_SHIFT)

/*
 * AC'97 data port.
 */
/* mt_ac97_data: rw16, space mt, reset 0x0 */
#define ICE1724_MT_AC97_DATA_OFFSET                  0x6u /* established */

/*
 * Start of the interleaved playback buffer. Bits 1 and 0 read 0, so the address
 * is dword aligned. The datasheet says the field is in dword units; the drivers
 * store the byte address unshifted, which is taken here.
 */
/* mt_pdmai_address: rw32, space mt, reset 0x0 */
#define ICE1724_MT_PDMAI_ADDRESS_OFFSET              0x10u /* established */
#define ICE1724_MT_PDMAI_ADDRESS_ADDRESS_SHIFT       2 /* established */
#define ICE1724_MT_PDMAI_ADDRESS_ADDRESS_MASK        0x3fffffffu
#define ICE1724_MT_PDMAI_ADDRESS_ADDRESS_INPLACE (ICE1724_MT_PDMAI_ADDRESS_ADDRESS_MASK << ICE1724_MT_PDMAI_ADDRESS_ADDRESS_SHIFT)

/*
 * Buffer size in dwords less one, counting down as data moves. Reloads at zero,
 * so the buffer wraps. Bits 18 to 0 are used.
 */
/* mt_pdmai_count: rw32, space mt, reset 0x0 */
#define ICE1724_MT_PDMAI_COUNT_OFFSET                0x14u /* established */
#define ICE1724_MT_PDMAI_COUNT_COUNT_SHIFT           0 /* established */
#define ICE1724_MT_PDMAI_COUNT_COUNT_MASK            0x7ffffu
#define ICE1724_MT_PDMAI_COUNT_COUNT_INPLACE (ICE1724_MT_PDMAI_COUNT_COUNT_MASK << ICE1724_MT_PDMAI_COUNT_COUNT_SHIFT)

/*
 * Read-modify-write only. A 1 starts the stream and a 0 stops it. Bit 3 is read
 * only, 0. Bit positions are the same as mt_irq_status.
 */
/* mt_dma_start: rw8, space mt, reset 0x0 */
#define ICE1724_MT_DMA_START_OFFSET                  0x18u /* established */
#define ICE1724_MT_DMA_START_PDMA4_SHIFT             7 /* established */
#define ICE1724_MT_DMA_START_PDMA4_MASK              0x1u
#define ICE1724_MT_DMA_START_PDMA4_INPLACE (ICE1724_MT_DMA_START_PDMA4_MASK << ICE1724_MT_DMA_START_PDMA4_SHIFT)
#define ICE1724_MT_DMA_START_PDMA3_SHIFT             6 /* established */
#define ICE1724_MT_DMA_START_PDMA3_MASK              0x1u
#define ICE1724_MT_DMA_START_PDMA3_INPLACE (ICE1724_MT_DMA_START_PDMA3_MASK << ICE1724_MT_DMA_START_PDMA3_SHIFT)
#define ICE1724_MT_DMA_START_PDMA2_SHIFT             5 /* established */
#define ICE1724_MT_DMA_START_PDMA2_MASK              0x1u
#define ICE1724_MT_DMA_START_PDMA2_INPLACE (ICE1724_MT_DMA_START_PDMA2_MASK << ICE1724_MT_DMA_START_PDMA2_SHIFT)
#define ICE1724_MT_DMA_START_PDMA1_SHIFT             4 /* established */
#define ICE1724_MT_DMA_START_PDMA1_MASK              0x1u
#define ICE1724_MT_DMA_START_PDMA1_INPLACE (ICE1724_MT_DMA_START_PDMA1_MASK << ICE1724_MT_DMA_START_PDMA1_SHIFT)
#define ICE1724_MT_DMA_START_RDMA1_SHIFT             2 /* established */
#define ICE1724_MT_DMA_START_RDMA1_MASK              0x1u
#define ICE1724_MT_DMA_START_RDMA1_INPLACE (ICE1724_MT_DMA_START_RDMA1_MASK << ICE1724_MT_DMA_START_RDMA1_SHIFT)
#define ICE1724_MT_DMA_START_RDMA0_SHIFT             1 /* established */
#define ICE1724_MT_DMA_START_RDMA0_MASK              0x1u
#define ICE1724_MT_DMA_START_RDMA0_INPLACE (ICE1724_MT_DMA_START_RDMA0_MASK << ICE1724_MT_DMA_START_RDMA0_SHIFT)
#define ICE1724_MT_DMA_START_PDMA0_SHIFT             0 /* established */
#define ICE1724_MT_DMA_START_PDMA0_MASK              0x1u
#define ICE1724_MT_DMA_START_PDMA0_INPLACE (ICE1724_MT_DMA_START_PDMA0_MASK << ICE1724_MT_DMA_START_PDMA0_SHIFT)

/*
 * Interleaved channel count; see enum interleave. Sets which of PDMA1 to PDMA3
 * are free.
 */
/* mt_pdmai_streams: rw8, space mt, reset 0x0 */
#define ICE1724_MT_PDMAI_STREAMS_OFFSET              0x19u /* established */
#define ICE1724_MT_PDMAI_STREAMS_INTERLEAVE_SHIFT    0 /* established */
#define ICE1724_MT_PDMAI_STREAMS_INTERLEAVE_MASK     0x3u
#define ICE1724_MT_PDMAI_STREAMS_INTERLEAVE_INPLACE (ICE1724_MT_PDMAI_STREAMS_INTERLEAVE_MASK << ICE1724_MT_PDMAI_STREAMS_INTERLEAVE_SHIFT)

/*
 * Underrun on playback or overrun on record, per stream. Bit positions are the
 * same as mt_dma_start. Write 1 to clear; any flag raises the interrupt through
 * mt_irq_status bit 3.
 */
/* mt_dma_underrun: rw8, space mt, reset 0x0 */
#define ICE1724_MT_DMA_UNDERRUN_OFFSET               0x1au /* established */

/*
 * Pause and resume, per stream; bit positions are the same as mt_dma_start. A 1
 * pauses and a 0 resumes.
 */
/* mt_dma_pause: rw8, space mt, reset 0x0 */
#define ICE1724_MT_DMA_PAUSE_OFFSET                  0x1bu /* established */

/*
 * Interrupt interval in dwords less one. Counts down; at zero it raises the
 * stream's source. Write only. The index line says 1C to 1D, but the layout
 * covers 1C to 1E, which holds the 19-bit field.
 */
/* mt_pdmai_terminal: w32, space mt, reset 0x0 */
#define ICE1724_MT_PDMAI_TERMINAL_OFFSET             0x1cu /* established */
#define ICE1724_MT_PDMAI_TERMINAL_COUNT_SHIFT        0 /* established */
#define ICE1724_MT_PDMAI_TERMINAL_COUNT_MASK         0x7ffffu
#define ICE1724_MT_PDMAI_TERMINAL_COUNT_INPLACE (ICE1724_MT_PDMAI_TERMINAL_COUNT_MASK << ICE1724_MT_PDMAI_TERMINAL_COUNT_SHIFT)

/*
 * Start of the first record buffer. Dword aligned, same encoding as
 * mt_pdmai_address.
 */
/* mt_rdma0_address: rw32, space mt, reset 0x0 */
#define ICE1724_MT_RDMA0_ADDRESS_OFFSET              0x20u /* established */
#define ICE1724_MT_RDMA0_ADDRESS_ADDRESS_SHIFT       2 /* established */
#define ICE1724_MT_RDMA0_ADDRESS_ADDRESS_MASK        0x3fffffffu
#define ICE1724_MT_RDMA0_ADDRESS_ADDRESS_INPLACE (ICE1724_MT_RDMA0_ADDRESS_ADDRESS_MASK << ICE1724_MT_RDMA0_ADDRESS_ADDRESS_SHIFT)

/*
 * Buffer size in dwords less one, counting down. Read the position only after
 * at least two sample frames have passed.
 */
/* mt_rdma0_count: rw16, space mt, reset 0x0 */
#define ICE1724_MT_RDMA0_COUNT_OFFSET                0x24u /* established */

/*
 * Interrupt interval in dwords less one. Write only.
 */
/* mt_rdma0_terminal: w16, space mt, reset 0x0 */
#define ICE1724_MT_RDMA0_TERMINAL_OFFSET             0x26u /* established */

/*
 * Source of each output channel, in I2S mode only, adding at most one sample
 * time of delay. The layout is established; the zero reset is inferred from the
 * printed 00h for a 32-bit register.
 */
/* mt_routing: rw32, space mt, reset 0x0 */
#define ICE1724_MT_ROUTING_OFFSET                    0x2cu /* inferred */
#define ICE1724_MT_ROUTING_PSDOUT3_RIGHT_SHIFT       29 /* established */
#define ICE1724_MT_ROUTING_PSDOUT3_RIGHT_MASK        0x7u
#define ICE1724_MT_ROUTING_PSDOUT3_RIGHT_INPLACE (ICE1724_MT_ROUTING_PSDOUT3_RIGHT_MASK << ICE1724_MT_ROUTING_PSDOUT3_RIGHT_SHIFT)
#define ICE1724_MT_ROUTING_PSDOUT2_RIGHT_SHIFT       26 /* established */
#define ICE1724_MT_ROUTING_PSDOUT2_RIGHT_MASK        0x7u
#define ICE1724_MT_ROUTING_PSDOUT2_RIGHT_INPLACE (ICE1724_MT_ROUTING_PSDOUT2_RIGHT_MASK << ICE1724_MT_ROUTING_PSDOUT2_RIGHT_SHIFT)
#define ICE1724_MT_ROUTING_PSDOUT1_RIGHT_SHIFT       23 /* established */
#define ICE1724_MT_ROUTING_PSDOUT1_RIGHT_MASK        0x7u
#define ICE1724_MT_ROUTING_PSDOUT1_RIGHT_INPLACE (ICE1724_MT_ROUTING_PSDOUT1_RIGHT_MASK << ICE1724_MT_ROUTING_PSDOUT1_RIGHT_SHIFT)
#define ICE1724_MT_ROUTING_PSDOUT0_RIGHT_SHIFT       20 /* established */
#define ICE1724_MT_ROUTING_PSDOUT0_RIGHT_MASK        0x7u
#define ICE1724_MT_ROUTING_PSDOUT0_RIGHT_INPLACE (ICE1724_MT_ROUTING_PSDOUT0_RIGHT_MASK << ICE1724_MT_ROUTING_PSDOUT0_RIGHT_SHIFT)
#define ICE1724_MT_ROUTING_PSDOUT3_LEFT_SHIFT        17 /* established */
#define ICE1724_MT_ROUTING_PSDOUT3_LEFT_MASK         0x7u
#define ICE1724_MT_ROUTING_PSDOUT3_LEFT_INPLACE (ICE1724_MT_ROUTING_PSDOUT3_LEFT_MASK << ICE1724_MT_ROUTING_PSDOUT3_LEFT_SHIFT)
#define ICE1724_MT_ROUTING_PSDOUT2_LEFT_SHIFT        14 /* established */
#define ICE1724_MT_ROUTING_PSDOUT2_LEFT_MASK         0x7u
#define ICE1724_MT_ROUTING_PSDOUT2_LEFT_INPLACE (ICE1724_MT_ROUTING_PSDOUT2_LEFT_MASK << ICE1724_MT_ROUTING_PSDOUT2_LEFT_SHIFT)
#define ICE1724_MT_ROUTING_PSDOUT1_LEFT_SHIFT        11 /* established */
#define ICE1724_MT_ROUTING_PSDOUT1_LEFT_MASK         0x7u
#define ICE1724_MT_ROUTING_PSDOUT1_LEFT_INPLACE (ICE1724_MT_ROUTING_PSDOUT1_LEFT_MASK << ICE1724_MT_ROUTING_PSDOUT1_LEFT_SHIFT)
#define ICE1724_MT_ROUTING_PSDOUT0_LEFT_SHIFT        8 /* established */
#define ICE1724_MT_ROUTING_PSDOUT0_LEFT_MASK         0x7u
#define ICE1724_MT_ROUTING_PSDOUT0_LEFT_INPLACE (ICE1724_MT_ROUTING_PSDOUT0_LEFT_MASK << ICE1724_MT_ROUTING_PSDOUT0_LEFT_SHIFT)
#define ICE1724_MT_ROUTING_SPDIF_RIGHT_SHIFT         3 /* established */
#define ICE1724_MT_ROUTING_SPDIF_RIGHT_MASK          0x7u
#define ICE1724_MT_ROUTING_SPDIF_RIGHT_INPLACE (ICE1724_MT_ROUTING_SPDIF_RIGHT_MASK << ICE1724_MT_ROUTING_SPDIF_RIGHT_SHIFT)
#define ICE1724_MT_ROUTING_SPDIF_LEFT_SHIFT          0 /* established */
#define ICE1724_MT_ROUTING_SPDIF_LEFT_MASK           0x7u
#define ICE1724_MT_ROUTING_SPDIF_LEFT_INPLACE (ICE1724_MT_ROUTING_SPDIF_LEFT_MASK << ICE1724_MT_ROUTING_SPDIF_LEFT_SHIFT)

/*
 * Start of the second record buffer. Dword aligned, same encoding as
 * mt_pdmai_address.
 */
/* mt_rdma1_address: rw32, space mt, reset 0x0 */
#define ICE1724_MT_RDMA1_ADDRESS_OFFSET              0x30u /* established */
#define ICE1724_MT_RDMA1_ADDRESS_ADDRESS_SHIFT       2 /* established */
#define ICE1724_MT_RDMA1_ADDRESS_ADDRESS_MASK        0x3fffffffu
#define ICE1724_MT_RDMA1_ADDRESS_ADDRESS_INPLACE (ICE1724_MT_RDMA1_ADDRESS_ADDRESS_MASK << ICE1724_MT_RDMA1_ADDRESS_ADDRESS_SHIFT)

/*
 * Buffer size in dwords less one, counting down.
 */
/* mt_rdma1_count: rw16, space mt, reset 0x0 */
#define ICE1724_MT_RDMA1_COUNT_OFFSET                0x34u /* established */

/*
 * Interrupt interval in dwords less one. Write only.
 */
/* mt_rdma1_terminal: w16, space mt, reset 0x0 */
#define ICE1724_MT_RDMA1_TERMINAL_OFFSET             0x36u /* established */

/*
 * S/PDIF transmitter channel status. Reads 0000 when the SPDTX pin is floating
 * or high, and 2000 at power-up when the transmitter is fitted. Every field
 * except validity is writable only while ccs_spdif_config bit 7 is 0.
 */
/* mt_spdif_control: rw16, space mt, reset unknown */
#define ICE1724_MT_SPDIF_CONTROL_OFFSET              0x3cu /* established */
#define ICE1724_MT_SPDIF_CONTROL_VALIDITY_SHIFT      15 /* established */
#define ICE1724_MT_SPDIF_CONTROL_VALIDITY_MASK       0x1u
#define ICE1724_MT_SPDIF_CONTROL_VALIDITY_INPLACE (ICE1724_MT_SPDIF_CONTROL_VALIDITY_MASK << ICE1724_MT_SPDIF_CONTROL_VALIDITY_SHIFT)
#define ICE1724_MT_SPDIF_CONTROL_SPDIF_RATE_SHIFT    12 /* established */
#define ICE1724_MT_SPDIF_CONTROL_SPDIF_RATE_MASK     0x7u
#define ICE1724_MT_SPDIF_CONTROL_SPDIF_RATE_INPLACE (ICE1724_MT_SPDIF_CONTROL_SPDIF_RATE_MASK << ICE1724_MT_SPDIF_CONTROL_SPDIF_RATE_SHIFT)
#define ICE1724_MT_SPDIF_CONTROL_GENERATION_LEVEL_SHIFT 11 /* established */
#define ICE1724_MT_SPDIF_CONTROL_GENERATION_LEVEL_MASK 0x1u
#define ICE1724_MT_SPDIF_CONTROL_GENERATION_LEVEL_INPLACE (ICE1724_MT_SPDIF_CONTROL_GENERATION_LEVEL_MASK << ICE1724_MT_SPDIF_CONTROL_GENERATION_LEVEL_SHIFT)
#define ICE1724_MT_SPDIF_CONTROL_CATEGORY_SHIFT      4 /* established */
#define ICE1724_MT_SPDIF_CONTROL_CATEGORY_MASK       0x7fu
#define ICE1724_MT_SPDIF_CONTROL_CATEGORY_INPLACE (ICE1724_MT_SPDIF_CONTROL_CATEGORY_MASK << ICE1724_MT_SPDIF_CONTROL_CATEGORY_SHIFT)
#define ICE1724_MT_SPDIF_CONTROL_PRE_EMPHASIS_SHIFT  3 /* established */
#define ICE1724_MT_SPDIF_CONTROL_PRE_EMPHASIS_MASK   0x1u
#define ICE1724_MT_SPDIF_CONTROL_PRE_EMPHASIS_INPLACE (ICE1724_MT_SPDIF_CONTROL_PRE_EMPHASIS_MASK << ICE1724_MT_SPDIF_CONTROL_PRE_EMPHASIS_SHIFT)
#define ICE1724_MT_SPDIF_CONTROL_COPYRIGHT_SHIFT     2 /* established */
#define ICE1724_MT_SPDIF_CONTROL_COPYRIGHT_MASK      0x1u
#define ICE1724_MT_SPDIF_CONTROL_COPYRIGHT_INPLACE (ICE1724_MT_SPDIF_CONTROL_COPYRIGHT_MASK << ICE1724_MT_SPDIF_CONTROL_COPYRIGHT_SHIFT)
#define ICE1724_MT_SPDIF_CONTROL_NON_AUDIO_SHIFT     1 /* established */
#define ICE1724_MT_SPDIF_CONTROL_NON_AUDIO_MASK      0x1u
#define ICE1724_MT_SPDIF_CONTROL_NON_AUDIO_INPLACE (ICE1724_MT_SPDIF_CONTROL_NON_AUDIO_MASK << ICE1724_MT_SPDIF_CONTROL_NON_AUDIO_SHIFT)
#define ICE1724_MT_SPDIF_CONTROL_PROFESSIONAL_SHIFT  0 /* established */
#define ICE1724_MT_SPDIF_CONTROL_PROFESSIONAL_MASK   0x1u
#define ICE1724_MT_SPDIF_CONTROL_PROFESSIONAL_INPLACE (ICE1724_MT_SPDIF_CONTROL_PROFESSIONAL_MASK << ICE1724_MT_SPDIF_CONTROL_PROFESSIONAL_SHIFT)

/*
 * Stream to meter. 0 to 7 are the eight interleaved slots, 8 and 9 the S/PDIF
 * left and right, 10 and 11 RDMA0, 18 and 19 RDMA1. Other values are ignored.
 */
/* mt_peak_index: rw8, space mt, reset 0x0 */
#define ICE1724_MT_PEAK_INDEX_OFFSET                 0x3eu /* established */
#define ICE1724_MT_PEAK_INDEX_INDEX_SHIFT            0 /* established */
#define ICE1724_MT_PEAK_INDEX_INDEX_MASK             0x1fu
#define ICE1724_MT_PEAK_INDEX_INDEX_INPLACE (ICE1724_MT_PEAK_INDEX_INDEX_MASK << ICE1724_MT_PEAK_INDEX_INDEX_SHIFT)

/*
 * Peak level of the selected stream, the nine most significant bits of the
 * level. Reading clears the peak.
 */
/* mt_peak_data: r8, space mt, reset 0x0 */
#define ICE1724_MT_PEAK_DATA_OFFSET                  0x3fu /* established */
#define ICE1724_MT_PEAK_DATA_PEAK_SHIFT              0 /* established */
#define ICE1724_MT_PEAK_DATA_PEAK_MASK               0xffu
#define ICE1724_MT_PEAK_DATA_PEAK_INPLACE (ICE1724_MT_PEAK_DATA_PEAK_MASK << ICE1724_MT_PEAK_DATA_PEAK_SHIFT)

/*
 * Start of the playback buffer for the S/PDIF stream and the three extra stereo
 * pairs. Element 0 is PDMA4 (S/PDIF), 1 is PDMA3, 2 is PDMA2, 3 is PDMA1. Dword
 * aligned.
 */
/* mt_pdma_address: rw32, space mt, reset 0x0 */
#define ICE1724_MT_PDMA_ADDRESS_OFFSET               0x40u /* established */
#define ICE1724_MT_PDMA_ADDRESS_COUNT                4
#define ICE1724_MT_PDMA_ADDRESS_STRIDE               16
#define ICE1724_MT_PDMA_ADDRESS_ADDRESS_SHIFT        2 /* established */
#define ICE1724_MT_PDMA_ADDRESS_ADDRESS_MASK         0x3fffffffu
#define ICE1724_MT_PDMA_ADDRESS_ADDRESS_INPLACE (ICE1724_MT_PDMA_ADDRESS_ADDRESS_MASK << ICE1724_MT_PDMA_ADDRESS_ADDRESS_SHIFT)

/*
 * Buffer size in dwords less one, counting down. Element order as
 * mt_pdma_address.
 */
/* mt_pdma_count: rw16, space mt, reset 0x0 */
#define ICE1724_MT_PDMA_COUNT_OFFSET                 0x44u /* established */
#define ICE1724_MT_PDMA_COUNT_COUNT                  4
#define ICE1724_MT_PDMA_COUNT_STRIDE                 16

/*
 * Interrupt interval in dwords less one. Write only. Element order as
 * mt_pdma_address.
 */
/* mt_pdma_terminal: w16, space mt, reset 0x0 */
#define ICE1724_MT_PDMA_TERMINAL_OFFSET              0x46u /* established */
#define ICE1724_MT_PDMA_TERMINAL_COUNT               4
#define ICE1724_MT_PDMA_TERMINAL_STRIDE              16

/*
 * PCI vendor ID, IC Ensemble.
 */
/* pci_vendor_id: r16, space pci, reset 0x1412 */
#define ICE1724_PCI_VENDOR_ID_OFFSET                 0x0u /* established */

/*
 * PCI device ID. The same ID is used by the VT1720 (Envy24PT), so it does not
 * tell the parts apart.
 */
/* pci_device_id: r16, space pci, reset 0x1724 */
#define ICE1724_PCI_DEVICE_ID_OFFSET                 0x2u /* established */

/*
 * Bit 1 (memory space) and bits 3 to 7 and 9 are hardwired to 0. The datasheet
 * lists bit 8 as read-write but describes it as hardwired to 0; it reads 0
 * here.
 */
/* pci_command: rw16, space pci, reset 0x0 */
#define ICE1724_PCI_COMMAND_OFFSET                   0x4u /* established */
#define ICE1724_PCI_COMMAND_BUS_MASTER_SHIFT         2 /* established */
#define ICE1724_PCI_COMMAND_BUS_MASTER_MASK          0x1u
#define ICE1724_PCI_COMMAND_BUS_MASTER_INPLACE (ICE1724_PCI_COMMAND_BUS_MASTER_MASK << ICE1724_PCI_COMMAND_BUS_MASTER_SHIFT)
#define ICE1724_PCI_COMMAND_IO_SPACE_SHIFT           0 /* established */
#define ICE1724_PCI_COMMAND_IO_SPACE_MASK            0x1u
#define ICE1724_PCI_COMMAND_IO_SPACE_INPLACE (ICE1724_PCI_COMMAND_IO_SPACE_MASK << ICE1724_PCI_COMMAND_IO_SPACE_SHIFT)

/*
 * Bits 15 to 12 are write-1-to-clear. Bit 11 is hardwired to 0. Bit 14 reads 0.
 * Bit 4 (capability list) is hardwired to 1.
 */
/* pci_status: rw16, space pci, reset 0x210 */
#define ICE1724_PCI_STATUS_OFFSET                    0x6u /* established */
#define ICE1724_PCI_STATUS_PARITY_ERROR_SHIFT        15 /* established */
#define ICE1724_PCI_STATUS_PARITY_ERROR_MASK         0x1u
#define ICE1724_PCI_STATUS_PARITY_ERROR_INPLACE (ICE1724_PCI_STATUS_PARITY_ERROR_MASK << ICE1724_PCI_STATUS_PARITY_ERROR_SHIFT)
#define ICE1724_PCI_STATUS_MASTER_ABORT_SHIFT        13 /* established */
#define ICE1724_PCI_STATUS_MASTER_ABORT_MASK         0x1u
#define ICE1724_PCI_STATUS_MASTER_ABORT_INPLACE (ICE1724_PCI_STATUS_MASTER_ABORT_MASK << ICE1724_PCI_STATUS_MASTER_ABORT_SHIFT)
#define ICE1724_PCI_STATUS_TARGET_ABORT_SHIFT        12 /* established */
#define ICE1724_PCI_STATUS_TARGET_ABORT_MASK         0x1u
#define ICE1724_PCI_STATUS_TARGET_ABORT_INPLACE (ICE1724_PCI_STATUS_TARGET_ABORT_MASK << ICE1724_PCI_STATUS_TARGET_ABORT_SHIFT)
#define ICE1724_PCI_STATUS_DEVSEL_TIMING_SHIFT       9 /* inferred */
#define ICE1724_PCI_STATUS_DEVSEL_TIMING_MASK        0x3u
#define ICE1724_PCI_STATUS_DEVSEL_TIMING_INPLACE (ICE1724_PCI_STATUS_DEVSEL_TIMING_MASK << ICE1724_PCI_STATUS_DEVSEL_TIMING_SHIFT)
#define ICE1724_PCI_STATUS_CAPABILITY_LIST_SHIFT     4 /* established */
#define ICE1724_PCI_STATUS_CAPABILITY_LIST_MASK      0x1u
#define ICE1724_PCI_STATUS_CAPABILITY_LIST_INPLACE (ICE1724_PCI_STATUS_CAPABILITY_LIST_MASK << ICE1724_PCI_STATUS_CAPABILITY_LIST_SHIFT)

/*
 * Vendor revision. The datasheet shows it as a placeholder; the value is not
 * given.
 */
/* pci_revision: r8, space pci, reset unknown */
#define ICE1724_PCI_REVISION_OFFSET                  0x8u /* established */

/*
 * Class code: multimedia, audio. The field is 24 bits in the header; the
 * programming interface byte at offset 0x09 reads 0.
 */
/* pci_class: r16, space pci, reset 0x401 */
#define ICE1724_PCI_CLASS_OFFSET                     0xau /* established */
#define ICE1724_PCI_CLASS_BASE_CLASS_SHIFT           8 /* established */
#define ICE1724_PCI_CLASS_BASE_CLASS_MASK            0xffu
#define ICE1724_PCI_CLASS_BASE_CLASS_INPLACE (ICE1724_PCI_CLASS_BASE_CLASS_MASK << ICE1724_PCI_CLASS_BASE_CLASS_SHIFT)
#define ICE1724_PCI_CLASS_SUBCLASS_SHIFT             0 /* established */
#define ICE1724_PCI_CLASS_SUBCLASS_MASK              0xffu
#define ICE1724_PCI_CLASS_SUBCLASS_INPLACE (ICE1724_PCI_CLASS_SUBCLASS_MASK << ICE1724_PCI_CLASS_SUBCLASS_SHIFT)

/*
 * Not supported; reads 0.
 */
/* pci_cache_line: r8, space pci, reset 0x0 */
#define ICE1724_PCI_CACHE_LINE_OFFSET                0xcu /* established */

/*
 * Writes take effect in eight-clock steps: writing FF reads back F8.
 */
/* pci_latency_timer: rw8, space pci, reset 0x0 */
#define ICE1724_PCI_LATENCY_TIMER_OFFSET             0xdu /* established */
#define ICE1724_PCI_LATENCY_TIMER_COUNT_SHIFT        3 /* established */
#define ICE1724_PCI_LATENCY_TIMER_COUNT_MASK         0x1fu
#define ICE1724_PCI_LATENCY_TIMER_COUNT_INPLACE (ICE1724_PCI_LATENCY_TIMER_COUNT_MASK << ICE1724_PCI_LATENCY_TIMER_COUNT_SHIFT)

/*
 * Type 0, single function.
 */
/* pci_header_type: r8, space pci, reset 0x0 */
#define ICE1724_PCI_HEADER_TYPE_OFFSET               0xeu /* established */

/*
 * Built-in self test is not supported.
 */
/* pci_bist: r8, space pci, reset 0x0 */
#define ICE1724_PCI_BIST_OFFSET                      0xfu /* established */

/*
 * Controller registers (CCS), 32 bytes of I/O space. Bits 31 to 5 are the base.
 */
/* pci_bar0: rw32, space pci, reset 0x1 */
#define ICE1724_PCI_BAR0_OFFSET                      0x10u /* established */
#define ICE1724_PCI_BAR0_BASE_SHIFT                  5 /* established */
#define ICE1724_PCI_BAR0_BASE_MASK                   0x7ffffffu
#define ICE1724_PCI_BAR0_BASE_INPLACE (ICE1724_PCI_BAR0_BASE_MASK << ICE1724_PCI_BAR0_BASE_SHIFT)

/*
 * Multi-channel registers (MT), 128 bytes of I/O space. Bits 31 to 7 are the
 * base.
 */
/* pci_bar1: rw32, space pci, reset 0x1 */
#define ICE1724_PCI_BAR1_OFFSET                      0x14u /* established */
#define ICE1724_PCI_BAR1_BASE_SHIFT                  7 /* established */
#define ICE1724_PCI_BAR1_BASE_MASK                   0x1ffffffu
#define ICE1724_PCI_BAR1_BASE_INPLACE (ICE1724_PCI_BAR1_BASE_MASK << ICE1724_PCI_BAR1_BASE_SHIFT)

/*
 * Subsystem IDs. Loaded from the EEPROM after reset when one answers, otherwise
 * the reset value. Writable only while the subsystem mask bit is set. Which
 * EEPROM bytes map to which half is not documented.
 */
/* pci_subsystem: rw32, space pci, reset 0x17241412 */
#define ICE1724_PCI_SUBSYSTEM_OFFSET                 0x2cu /* established */
#define ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_DEVICE_SHIFT 16 /* established */
#define ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_DEVICE_MASK  0xffffu
#define ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_DEVICE_INPLACE (ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_DEVICE_MASK << ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_DEVICE_SHIFT)
#define ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_VENDOR_SHIFT 0 /* established */
#define ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_VENDOR_MASK  0xffffu
#define ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_VENDOR_INPLACE (ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_VENDOR_MASK << ICE1724_PCI_SUBSYSTEM_SUBSYSTEM_VENDOR_SHIFT)

/*
 * Reserved; the part has no option ROM.
 */
/* pci_expansion_rom: r32, space pci, reset 0x0 */
#define ICE1724_PCI_EXPANSION_ROM_OFFSET             0x30u /* established */

/*
 * Points to the power-management capability at 0x80.
 */
/* pci_capability_ptr: r8, space pci, reset 0x80 */
#define ICE1724_PCI_CAPABILITY_PTR_OFFSET            0x34u /* established */

/*
 * Set by firmware. FF means the interrupt is not routed.
 */
/* pci_interrupt_line: rw8, space pci, reset 0xff */
#define ICE1724_PCI_INTERRUPT_LINE_OFFSET            0x3cu /* established */

/*
 * INTA#.
 */
/* pci_interrupt_pin: r8, space pci, reset 0x1 */
#define ICE1724_PCI_INTERRUPT_PIN_OFFSET             0x3du /* established */

/*
 * Minimum grant in the low byte, maximum latency in the high byte. Both 0.
 */
/* pci_grant_latency: r16, space pci, reset 0x0 */
#define ICE1724_PCI_GRANT_LATENCY_OFFSET             0x3eu /* established */
#define ICE1724_PCI_GRANT_LATENCY_MAX_LATENCY_SHIFT  8 /* established */
#define ICE1724_PCI_GRANT_LATENCY_MAX_LATENCY_MASK   0xffu
#define ICE1724_PCI_GRANT_LATENCY_MAX_LATENCY_INPLACE (ICE1724_PCI_GRANT_LATENCY_MAX_LATENCY_MASK << ICE1724_PCI_GRANT_LATENCY_MAX_LATENCY_SHIFT)
#define ICE1724_PCI_GRANT_LATENCY_MIN_GRANT_SHIFT    0 /* established */
#define ICE1724_PCI_GRANT_LATENCY_MIN_GRANT_MASK     0xffu
#define ICE1724_PCI_GRANT_LATENCY_MIN_GRANT_INPLACE (ICE1724_PCI_GRANT_LATENCY_MIN_GRANT_MASK << ICE1724_PCI_GRANT_LATENCY_MIN_GRANT_SHIFT)

/*
 * The table places the subsystem ID mask at 0x40 and the register section at
 * 0x42. Bit 7 is the control that makes the subsystem IDs writable. The offset
 * is taken from the register section.
 */
/* pci_svid_mask: rw8, space pci, reset 0x0 */
#define ICE1724_PCI_SVID_MASK_OFFSET                 0x42u /* inferred */
#define ICE1724_PCI_SVID_MASK_WRITABLE_SHIFT         7 /* inferred */
#define ICE1724_PCI_SVID_MASK_WRITABLE_MASK          0x1u
#define ICE1724_PCI_SVID_MASK_WRITABLE_INPLACE (ICE1724_PCI_SVID_MASK_WRITABLE_MASK << ICE1724_PCI_SVID_MASK_WRITABLE_SHIFT)

/*
 * Capability ID: power management.
 */
/* pci_pm_capability_id: r8, space pci, reset 0x1 */
#define ICE1724_PCI_PM_CAPABILITY_ID_OFFSET          0x80u /* established */

/*
 * End of the capability list.
 */
/* pci_pm_next: r8, space pci, reset 0x0 */
#define ICE1724_PCI_PM_NEXT_OFFSET                   0x81u /* established */

/*
 * Power management version 1.0. D2 is supported, D1 and PME are not.
 */
/* pci_pm_caps: r16, space pci, reset 0x401 */
#define ICE1724_PCI_PM_CAPS_OFFSET                   0x82u /* established */

/*
 * Power state select.
 */
/* pci_pm_control: rw16, space pci, reset 0x0 */
#define ICE1724_PCI_PM_CONTROL_OFFSET                0x84u /* established */
#define ICE1724_PCI_PM_CONTROL_POWER_STATE_SHIFT     0 /* established */
#define ICE1724_PCI_PM_CONTROL_POWER_STATE_MASK      0x3u
#define ICE1724_PCI_PM_CONTROL_POWER_STATE_INPLACE (ICE1724_PCI_PM_CONTROL_POWER_STATE_MASK << ICE1724_PCI_PM_CONTROL_POWER_STATE_SHIFT)

/*
 * Power management bridge extension and data. Read only, reset 0.
 */
/* pci_pm_data: r16, space pci, reset 0x0 */
#define ICE1724_PCI_PM_DATA_OFFSET                   0x86u /* established */

#define ICE1724_CCS_AC97_CONF                        0x5u /* established */
#define ICE1724_CCS_GPIO_DATA                        0x14u /* established */
#define ICE1724_CCS_GPIO_DATA_HI                     0x1eu /* established */
#define ICE1724_CCS_GPIO_DIR                         0x18u /* established */
#define ICE1724_CCS_GPIO_MASK                        0x16u /* established */
#define ICE1724_CCS_GPIO_MASK_HI                     0x1fu /* established */
#define ICE1724_CCS_I2C_BYTE_ADDR                    0x11u /* established */
#define ICE1724_CCS_I2C_CTRL                         0x13u /* established */
#define ICE1724_CCS_I2C_DATA                         0x12u /* established */
#define ICE1724_CCS_I2C_DEV_ADDR                     0x10u /* established */
#define ICE1724_CCS_I2S_FEATURES                     0x6u /* established */
#define ICE1724_CCS_IRQ_MASK                         0x1u /* inferred */
#define ICE1724_CCS_IRQ_STATUS                       0x2u /* inferred */
#define ICE1724_CCS_SPDIF_CONF                       0x7u /* established */
#define ICE1724_CCS_SYSCONF                          0x4u /* established */
#define ICE1724_MT_BURST                             0x19u /* established */
#define ICE1724_MT_CAPTURE_ADDR                      0x20u /* established */
#define ICE1724_MT_CAPTURE_SIZE                      0x24u /* established */
#define ICE1724_MT_CONVERTER_RESET                   0x5u /* established */
#define ICE1724_MT_DMA_CONTROL                       0x18u /* established */
#define ICE1724_MT_DMA_INT_MASK                      0x3u /* inferred */
#define ICE1724_MT_IRQ_STATUS                        0x0u /* inferred */
#define ICE1724_MT_MCLK_128X                         0x2u /* established */
#define ICE1724_MT_PLAYBACK_ADDR                     0x10u /* established */
#define ICE1724_MT_PLAYBACK_SIZE                     0x14u /* established */
#define ICE1724_MT_RATE                              0x1u /* established */
#define ICE1724_MT_SPDIF_OUT_ADDR                    0x40u /* established */
#define ICE1724_MT_SPDIF_OUT_SIZE                    0x44u /* established */

/* hand-written helper macros */
#include "../../devices/ice1724/helpers.h"

#endif /* ICE1724_GEN_H */
