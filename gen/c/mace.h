/* generated from defs/mace.toml by defs-gen - do not edit, change the source */
/* MACE (O2 I/O ASIC) */
#ifndef MACE_GEN_H
#define MACE_GEN_H

#include <stdint.h>


/* pci_err_addr: rw32, reset unknown; census: 5 sites, 4 routines */
#define MACE_PCI_ERR_ADDR                            0x080000 /* established */

/* pci_err_flags: rw32, reset unknown; census: 32 sites, 17 routines */
#define MACE_PCI_ERR_FLAGS                           0x080004 /* established */

/* pci_control: rw32, reset unknown; census: 9 sites, 5 routines */
#define MACE_PCI_CONTROL                             0x080008 /* established */

/* pci_flush_rev: rw32, reset unknown; census: 4 sites, 4 routines */
#define MACE_PCI_FLUSH_REV                           0x08000c /* established */

/* pci_config_addr: w32, reset unknown; census: 15 sites, 6 routines */
#define MACE_PCI_CONFIG_ADDR                         0x080cf8 /* established */

/* pci_config_data: rw32, reset unknown; census: 25 sites, 6 routines */
#define MACE_PCI_CONFIG_DATA                         0x080cfc /* established */

/* vout_vhw_cfg: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_VOUT_VHW_CFG                            0x200058 /* established */

/* eth_mac_control: rw32, reset unknown; census: 5 sites, 3 routines */
#define MACE_ETH_MAC_CONTROL                         0x280000 /* established */

/* eth_rx_fifo: r8, reset unknown; census: 7 sites, 1 routines */
#define MACE_ETH_RX_FIFO                             0x280040 /* established */

/* eth_internal_ram: rw32, reset unknown; census: 5 sites, 1 routines */
#define MACE_ETH_INTERNAL_RAM                        0x280100 /* established */

/* aud_control: rw64, reset unknown; census: 12 sites, 7 routines */
#define MACE_AUD_CONTROL                             0x300000 /* established */

/* aud_codec_cntl: rw64, reset unknown; census: 4 sites, 4 routines */
#define MACE_AUD_CODEC_CNTL                          0x300008 /* established */

/* aud_codec_mask: rw64, reset unknown; census: 3 sites, 2 routines */
#define MACE_AUD_CODEC_MASK                          0x300010 /* established */

/* aud_codec_read: r64, reset unknown; census: 3 sites, 3 routines */
#define MACE_AUD_CODEC_READ                          0x300018 /* established */

/* aud_ch1_cntl: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH1_CNTL                            0x300020 /* established */

/* aud_ch1_read: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH1_READ                            0x300028 /* established */

/* aud_ch1_write: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH1_WRITE                           0x300030 /* established */

/* aud_ch1_depth: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH1_DEPTH                           0x300038 /* established */

/* aud_ch2_cntl: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH2_CNTL                            0x300040 /* established */

/* aud_ch2_read: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH2_READ                            0x300048 /* established */

/* aud_ch2_write: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH2_WRITE                           0x300050 /* established */

/* aud_ch2_depth: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH2_DEPTH                           0x300058 /* established */

/* aud_ch3_cntl: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH3_CNTL                            0x300060 /* established */

/* aud_ch3_read: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH3_READ                            0x300068 /* established */

/* aud_ch3_write: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH3_WRITE                           0x300070 /* established */

/* aud_ch3_depth: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_AUD_CH3_DEPTH                           0x300078 /* established */

/* pioflush: rw32, reset unknown; census: 3 sites, 1 routines */
#define MACE_PIOFLUSH                                0x304018 /* established */

/* isa_ring_base: rw64, reset unknown; census: 9 sites, 6 routines */
#define MACE_ISA_RING_BASE                           0x310000 /* established */

/* isa_misc: rw64, reset unknown; census: 30 sites, 14 routines */
#define MACE_ISA_MISC                                0x310008 /* established */

/* isa_int_stat: rw64, reset unknown; census: 9 sites, 7 routines */
#define MACE_ISA_INT_STAT                            0x310010 /* established */

/* isa_int_mask: rw64, reset unknown; census: 24 sites, 12 routines */
#define MACE_ISA_INT_MASK                            0x310018 /* established */

/* par_cntl_stat: rw64, reset unknown; census: 23 sites, 6 routines */
#define MACE_PAR_CNTL_STAT                           0x314010 /* established */

/* par_diag: r64, reset unknown; census: 5 sites, 2 routines */
#define MACE_PAR_DIAG                                0x314018 /* established */

/* s1_tx_cntl: rw64, reset unknown; census: 3 sites, 2 routines */
#define MACE_S1_TX_CNTL                              0x318000 /* established */

/* s1_rx_cntl: rw64, reset unknown; census: 3 sites, 2 routines */
#define MACE_S1_RX_CNTL                              0x318020 /* established */

/* s2_tx_cntl: rw64, reset unknown; census: 3 sites, 2 routines */
#define MACE_S2_TX_CNTL                              0x31c000 /* established */

/* s2_rx_cntl: rw64, reset unknown; census: 3 sites, 2 routines */
#define MACE_S2_RX_CNTL                              0x31c020 /* established */

/* i2c_control: rw64, reset unknown; census: 13 sites, 4 routines */
#define MACE_I2C_CONTROL                             0x330010 /* established */

/* i2c_data: rw64, reset unknown; census: 5 sites, 1 routines */
#define MACE_I2C_DATA                                0x330018 /* established */

/* tmr_ust: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_TMR_UST                                 0x340000 /* established */

/* tmr_compare1: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_TMR_COMPARE1                            0x340008 /* established */

/* tmr_compare2: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_TMR_COMPARE2                            0x340010 /* established */

/* tmr_compare3: r64, reset unknown; census: 2 sites, 1 routines */
#define MACE_TMR_COMPARE3                            0x340018 /* established */

/* tmr_ain: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_TMR_AIN                                 0x340020 /* established */

/* tmr_aout1: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_TMR_AOUT1                               0x340028 /* established */

/* tmr_aout2: r64, reset unknown; census: 1 sites, 1 routines */
#define MACE_TMR_AOUT2                               0x340030 /* established */

/* isa_parallel: w8, reset unknown; census: 18 sites, 6 routines */
#define MACE_ISA_PARALLEL                            0x380000 /* established */

/* isa_parallel_380100: r8, reset unknown; census: 27 sites, 9 routines */
#define MACE_ISA_PARALLEL_380100                     0x380100 /* established */

/* isa_parallel_380200: rw8, reset unknown; census: 59 sites, 10 routines */
#define MACE_ISA_PARALLEL_380200                     0x380200 /* established */

/* isa_parallel_380300: rw8, reset unknown; census: 46 sites, 7 routines */
#define MACE_ISA_PARALLEL_380300                     0x380300 /* established */

/* isa_parallel_380400: rw8, reset unknown; census: 41 sites, 6 routines */
#define MACE_ISA_PARALLEL_380400                     0x380400 /* established */

/* isa_ecp1284: rw8, reset unknown; census: 46 sites, 10 routines */
#define MACE_ISA_ECP1284                             0x388200 /* established */

/* isa_rtc: rw8, reset unknown; census: 6 sites, 3 routines */
#define MACE_ISA_RTC                                 0x3a0000 /* established */

/* isa_rtc_3a0100: w8, reset unknown; census: 1 sites, 1 routines */
#define MACE_ISA_RTC_3A0100                          0x3a0100 /* established */

/* isa_rtc_3a0200: rw8, reset unknown; census: 7 sites, 4 routines */
#define MACE_ISA_RTC_3A0200                          0x3a0200 /* established */

/* isa_rtc_3a0300: w8, reset unknown; census: 1 sites, 1 routines */
#define MACE_ISA_RTC_3A0300                          0x3a0300 /* established */

/* isa_rtc_3a0400: rw8, reset unknown; census: 7 sites, 4 routines */
#define MACE_ISA_RTC_3A0400                          0x3a0400 /* established */

/* isa_rtc_3a0500: w8, reset unknown; census: 1 sites, 1 routines */
#define MACE_ISA_RTC_3A0500                          0x3a0500 /* established */

/* isa_rtc_3a0600: rw8, reset unknown; census: 6 sites, 3 routines */
#define MACE_ISA_RTC_3A0600                          0x3a0600 /* established */

/* isa_rtc_3a0700: rw8, reset unknown; census: 7 sites, 4 routines */
#define MACE_ISA_RTC_3A0700                          0x3a0700 /* established */

/* isa_rtc_3a0800: rw8, reset unknown; census: 7 sites, 4 routines */
#define MACE_ISA_RTC_3A0800                          0x3a0800 /* established */

/* isa_rtc_3a0900: rw8, reset unknown; census: 6 sites, 3 routines */
#define MACE_ISA_RTC_3A0900                          0x3a0900 /* established */

/* isa_rtc_3a0a00: rw8, reset unknown; census: 86 sites, 24 routines */
#define MACE_ISA_RTC_3A0A00                          0x3a0a00 /* established */

/* isa_rtc_3a0b00: rw8, reset unknown; census: 22 sites, 5 routines */
#define MACE_ISA_RTC_3A0B00                          0x3a0b00 /* established */

/* isa_rtc_3a0c00: r8, reset unknown; census: 4 sites, 4 routines */
#define MACE_ISA_RTC_3A0C00                          0x3a0c00 /* established */

/* isa_rtc_3a0e00: rw8, reset unknown; census: 5 sites, 3 routines */
#define MACE_ISA_RTC_3A0E00                          0x3a0e00 /* established */

/* isa_rtc_3a4800: rw8, reset unknown; census: 6 sites, 3 routines */
#define MACE_ISA_RTC_3A4800                          0x3a4800 /* established */

/* isa_rtc_3a4900: w8, reset unknown; census: 1 sites, 1 routines */
#define MACE_ISA_RTC_3A4900                          0x3a4900 /* established */

/* isa_rtc_3a4a00: rw8, reset unknown; census: 34 sites, 10 routines */
#define MACE_ISA_RTC_3A4A00                          0x3a4a00 /* established */

/* isa_rtc_3a4b00: rw8, reset unknown; census: 28 sites, 6 routines */
#define MACE_ISA_RTC_3A4B00                          0x3a4b00 /* established */

#define MACE_AUD_CODEC_CNTL_B_15_0                   0xffffu /* inferred */
#define MACE_AUD_CODEC_CNTL_V_10000                  0x10000u /* inferred */
#define MACE_AUD_CODEC_READ_B_15_0                   0xffffu /* inferred */
#define MACE_AUD_CONTROL_B_1                         0x2u /* inferred */
#define MACE_AUD_CONTROL_B_11_5                      0xfe0u /* inferred */
#define MACE_AUD_CONTROL_V_1                         0x1u /* inferred */
#define MACE_ETH_MAC_CONTROL_B_7_0                   0xffu /* inferred */
#define MACE_ETH_MAC_CONTROL_V_1                     0x1u /* inferred */
#define MACE_I2C_CONTROL_B_0                         0x1u /* inferred */
#define MACE_I2C_CONTROL_V_1                         0x1u /* inferred */
#define MACE_I2C_CONTROL_V_3                         0x3u /* inferred */
#define MACE_ISA_ECP1284_B_7_0                       0xffu /* inferred */
#define MACE_ISA_ECP1284_V_10                        0x10u /* inferred */
#define MACE_ISA_ECP1284_V_40                        0x40u /* inferred */
#define MACE_ISA_ECP1284_V_60                        0x60u /* inferred */
#define MACE_ISA_ECP1284_V_8                         0x8u /* inferred */
#define MACE_ISA_ECP1284_V_80                        0x80u /* inferred */
#define MACE_ISA_ECP1284_V_C0                        0xc0u /* inferred */
#define MACE_ISA_INT_MASK_B_7_0                      0xffu /* inferred */
#define MACE_ISA_INT_MASK_V_100                      0x100u /* inferred */
#define MACE_ISA_INT_MASK_V_18                       0x18u /* inferred */
#define MACE_ISA_INT_MASK_V_A00                      0xa00u /* inferred */
#define MACE_ISA_INT_STAT_B_1                        0x2u /* inferred */
#define MACE_ISA_INT_STAT_B_8                        0x100u /* inferred */
#define MACE_ISA_MISC_B_1                            0x2u /* inferred */
#define MACE_ISA_MISC_B_4                            0x10u /* inferred */
#define MACE_ISA_MISC_B_5_4                          0x30u /* inferred */
#define MACE_ISA_MISC_B_7_0                          0xffu /* inferred */
#define MACE_ISA_MISC_V_1                            0x1u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_3                 0x8u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_4                 0x10u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_5                 0x20u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_6                 0x40u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_6_3               0x48u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_7                 0x80u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_7_0               0xffu /* inferred */
#define MACE_ISA_PARALLEL_380100_B_7_3               0xf8u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_7_4               0xf0u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_7_5_4             0xb0u /* inferred */
#define MACE_ISA_PARALLEL_380100_B_7_6_3             0xc8u /* inferred */
#define MACE_ISA_PARALLEL_380200_B_6                 0x40u /* inferred */
#define MACE_ISA_PARALLEL_380200_B_6_3               0x78u /* inferred */
#define MACE_ISA_PARALLEL_380200_B_7_0               0xffu /* inferred */
#define MACE_ISA_PARALLEL_380200_B_7_5_4             0xb0u /* inferred */
#define MACE_ISA_PARALLEL_380200_B_7_6_3             0xc8u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_1                 0x1u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_2                 0x2u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_20                0x20u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_4                 0x4u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_5                 0x5u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_7                 0x7u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_8                 0x8u /* inferred */
#define MACE_ISA_PARALLEL_380200_V_D                 0xdu /* inferred */
#define MACE_ISA_PARALLEL_380200_V_E                 0xeu /* inferred */
#define MACE_ISA_PARALLEL_380300_B_7_0               0xffu /* inferred */
#define MACE_ISA_PARALLEL_380300_V_1                 0x1u /* inferred */
#define MACE_ISA_PARALLEL_380300_V_2                 0x2u /* inferred */
#define MACE_ISA_PARALLEL_380300_V_3                 0x3u /* inferred */
#define MACE_ISA_PARALLEL_380300_V_6                 0x6u /* inferred */
#define MACE_ISA_PARALLEL_380300_V_8                 0x8u /* inferred */
#define MACE_ISA_PARALLEL_380300_V_9                 0x9u /* inferred */
#define MACE_ISA_PARALLEL_380300_V_A                 0xau /* inferred */
#define MACE_ISA_PARALLEL_380400_B_7_0               0xffu /* inferred */
#define MACE_ISA_PARALLEL_380400_V_1A                0x1au /* inferred */
#define MACE_ISA_PARALLEL_380400_V_2                 0x2u /* inferred */
#define MACE_ISA_PARALLEL_380400_V_42                0x42u /* inferred */
#define MACE_ISA_PARALLEL_380400_V_5                 0x5u /* inferred */
#define MACE_ISA_PARALLEL_380400_V_8                 0x8u /* inferred */
#define MACE_ISA_PARALLEL_380400_V_9                 0x9u /* inferred */
#define MACE_ISA_PARALLEL_B_7_0                      0xffu /* inferred */
#define MACE_ISA_PARALLEL_V_100                      0x100u /* inferred */
#define MACE_ISA_PARALLEL_V_2                        0x2u /* inferred */
#define MACE_ISA_PARALLEL_V_4                        0x4u /* inferred */
#define MACE_ISA_PARALLEL_V_5                        0x5u /* inferred */
#define MACE_ISA_PARALLEL_V_55                       0x55u /* inferred */
#define MACE_ISA_PARALLEL_V_78                       0x78u /* inferred */
#define MACE_ISA_PARALLEL_V_87                       0x87u /* inferred */
#define MACE_ISA_PARALLEL_V_AA                       0xaau /* inferred */
#define MACE_ISA_PARALLEL_V_FE                       0xfeu /* inferred */
#define MACE_ISA_PARALLEL_V_FF                       0xffu /* inferred */
#define MACE_ISA_RING_BASE_B_4                       0x10u /* inferred */
#define MACE_ISA_RING_BASE_V_0                       0x0u /* inferred */
#define MACE_ISA_RTC_3A0100_V_C0                     0xc0u /* inferred */
#define MACE_ISA_RTC_3A0200_B_4_0                    0x1fu /* inferred */
#define MACE_ISA_RTC_3A0200_B_5_0                    0x3fu /* inferred */
#define MACE_ISA_RTC_3A0300_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A0400_B_4_0                    0x1fu /* inferred */
#define MACE_ISA_RTC_3A0400_B_5_0                    0x3fu /* inferred */
#define MACE_ISA_RTC_3A0400_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A0500_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A0600_B_2_0                    0x7u /* inferred */
#define MACE_ISA_RTC_3A0700_B_2_0                    0x7u /* inferred */
#define MACE_ISA_RTC_3A0700_B_4_0                    0x1fu /* inferred */
#define MACE_ISA_RTC_3A0700_B_5_0                    0x3fu /* inferred */
#define MACE_ISA_RTC_3A0800_B_2_0                    0x7u /* inferred */
#define MACE_ISA_RTC_3A0800_B_4_0                    0x1fu /* inferred */
#define MACE_ISA_RTC_3A0900_B_2_0                    0x7u /* inferred */
#define MACE_ISA_RTC_3A0A00_B_15_5_3_0               0xffefu /* inferred */
#define MACE_ISA_RTC_3A0A00_B_15_7_5_0               0xffbfu /* inferred */
#define MACE_ISA_RTC_3A0A00_B_4                      0x10u /* inferred */
#define MACE_ISA_RTC_3A0A00_B_6_5                    0x60u /* inferred */
#define MACE_ISA_RTC_3A0A00_B_7                      0x80u /* inferred */
#define MACE_ISA_RTC_3A0A00_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A0A00_V_10                     0x10u /* inferred */
#define MACE_ISA_RTC_3A0A00_V_20                     0x20u /* inferred */
#define MACE_ISA_RTC_3A0A00_V_30                     0x30u /* inferred */
#define MACE_ISA_RTC_3A0B00_B_15_3_1_0               0xfffbu /* inferred */
#define MACE_ISA_RTC_3A0B00_B_15_8_6_0               0xff7fu /* inferred */
#define MACE_ISA_RTC_3A0B00_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A0B00_V_2                      0x2u /* inferred */
#define MACE_ISA_RTC_3A0B00_V_80                     0x80u /* inferred */
#define MACE_ISA_RTC_3A0B00_V_82                     0x82u /* inferred */
#define MACE_ISA_RTC_3A0C00_B_7                      0x80u /* inferred */
#define MACE_ISA_RTC_3A0E00_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A0E00_V_1                      0x1u /* inferred */
#define MACE_ISA_RTC_3A4900_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A4A00_B_0                      0x1u /* inferred */
#define MACE_ISA_RTC_3A4A00_B_15_2                   0xfffcu /* inferred */
#define MACE_ISA_RTC_3A4A00_B_1_0                    0x3u /* inferred */
#define MACE_ISA_RTC_3A4A00_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A4A00_V_8                      0x8u /* inferred */
#define MACE_ISA_RTC_3A4B00_B_15_2_0                 0xfffdu /* inferred */
#define MACE_ISA_RTC_3A4B00_B_7_0                    0xffu /* inferred */
#define MACE_ISA_RTC_3A4B00_V_2                      0x2u /* inferred */
#define MACE_ISA_RTC_3A4B00_V_81                     0x81u /* inferred */
#define MACE_ISA_RTC_3A4B00_V_83                     0x83u /* inferred */
#define MACE_ISA_RTC_3A4B00_V_9                      0x9u /* inferred */
#define MACE_ISA_RTC_B_5_0                           0x3fu /* inferred */
#define MACE_PAR_CNTL_STAT_B_0                       0x1u /* inferred */
#define MACE_PAR_CNTL_STAT_V_1                       0x1u /* inferred */
#define MACE_PAR_CNTL_STAT_V_2                       0x2u /* inferred */
#define MACE_PAR_CNTL_STAT_V_4                       0x4u /* inferred */
#define MACE_PAR_DIAG_B_0                            0x1u /* inferred */
#define MACE_PAR_DIAG_B_1                            0x2u /* inferred */
#define MACE_PAR_DIAG_B_11_0                         0xfffu /* inferred */
#define MACE_PCI_CONFIG_ADDR_B_7_2                   0xfcu /* inferred */
#define MACE_PCI_CONFIG_ADDR_V_4                     0x4u /* inferred */
#define MACE_PCI_CONFIG_ADDR_V_8                     0x8u /* inferred */
#define MACE_PCI_CONFIG_ADDR_V_C                     0xcu /* inferred */
#define MACE_PCI_CONFIG_DATA_B_7_0                   0xffu /* inferred */
#define MACE_PCI_CONFIG_DATA_V_3020                  0x3020u /* inferred */
#define MACE_PCI_CONFIG_DATA_V_6                     0x6u /* inferred */
#define MACE_PCI_CONTROL_B_11                        0x800u /* inferred */
#define MACE_PCI_CONTROL_V_503                       0x503u /* inferred */
#define MACE_PCI_CONTROL_V_85FF                      0x85ffu /* inferred */
#define MACE_PCI_CONTROL_V_8DFF                      0x8dffu /* inferred */
#define MACE_PCI_CONTROL_V_FE000000                  0xfe000000u /* inferred */
#define MACE_PCI_CONTROL_V_FF000000                  0xff000000u /* inferred */
#define MACE_PCI_FLUSH_REV_V_1                       0x1u /* inferred */
#define MACE_VOUT_VHW_CFG_B_3_0                      0xfu /* inferred */

#endif /* MACE_GEN_H */
