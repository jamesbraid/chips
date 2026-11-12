# MACE (O2 I/O ASIC)

<!-- generated from defs/mace.toml by defs-gen - do not edit, change the source -->

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout. Views: the offset is the 8-byte slot address. "4 at slot+4" is a 32-bit load or store at that address plus 4, the low word of the slot on a big-endian machine; a 64-bit access to the slot address reaches the same register.

Unit `mace`, macro prefix `MACE`.
Default source: census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pci_err_addr` | 0x80000 | rw | 32 |  |  | unknown | established | census: 5 sites, 4 routines |
| `pci_err_flags` | 0x80004 | rw | 32 |  |  | unknown | established | census: 32 sites, 17 routines |
| `pci_control` | 0x80008 | rw | 32 |  |  | unknown | established | census: 9 sites, 5 routines |
| `pci_flush_rev` | 0x8000c | rw | 32 |  |  | unknown | established | census: 4 sites, 4 routines |
| `pci_config_addr` | 0x80cf8 | w | 32 |  |  | unknown | established | census: 15 sites, 6 routines |
| `pci_config_data` | 0x80cfc | rw | 32 |  |  | unknown | established | census: 25 sites, 6 routines |
| `vout_vhw_cfg` | 0x200058 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `eth_mac_control` | 0x280000 | rw | 32 |  |  | unknown | established | census: 5 sites, 3 routines |
| `eth_rx_fifo` | 0x280040 | r | 8 |  |  | unknown | established | census: 7 sites, 1 routines |
| `eth_internal_ram` | 0x280100 | rw | 32 |  |  | unknown | established | census: 5 sites, 1 routines |
| `aud_control` | 0x300000 | rw | 64 |  |  | unknown | established | census: 12 sites, 7 routines |
| `aud_codec_cntl` | 0x300008 | rw | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `aud_codec_mask` | 0x300010 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `aud_codec_read` | 0x300018 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `aud_ch1_cntl` | 0x300020 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch1_read` | 0x300028 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch1_write` | 0x300030 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch1_depth` | 0x300038 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch2_cntl` | 0x300040 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch2_read` | 0x300048 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch2_write` | 0x300050 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch2_depth` | 0x300058 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch3_cntl` | 0x300060 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch3_read` | 0x300068 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch3_write` | 0x300070 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `aud_ch3_depth` | 0x300078 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pioflush` | 0x304018 | rw | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `isa_ring_base` | 0x310000 | rw | 64 |  |  | unknown | established | census: 9 sites, 6 routines |
| `isa_misc` | 0x310008 | rw | 64 |  |  | unknown | established | census: 30 sites, 14 routines |
| `isa_int_stat` | 0x310010 | rw | 64 |  |  | unknown | established | census: 9 sites, 7 routines |
| `isa_int_mask` | 0x310018 | rw | 64 |  |  | unknown | established | census: 24 sites, 12 routines |
| `par_cntl_stat` | 0x314010 | rw | 64 |  |  | unknown | established | census: 23 sites, 6 routines |
| `par_diag` | 0x314018 | r | 64 |  |  | unknown | established | census: 5 sites, 2 routines |
| `s1_tx_cntl` | 0x318000 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `s1_rx_cntl` | 0x318020 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `s2_tx_cntl` | 0x31c000 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `s2_rx_cntl` | 0x31c020 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `i2c_control` | 0x330010 | rw | 64 |  |  | unknown | established | census: 13 sites, 4 routines |
| `i2c_data` | 0x330018 | rw | 64 |  |  | unknown | established | census: 5 sites, 1 routines |
| `tmr_ust` | 0x340000 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `tmr_compare1` | 0x340008 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `tmr_compare2` | 0x340010 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `tmr_compare3` | 0x340018 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `tmr_ain` | 0x340020 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `tmr_aout1` | 0x340028 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `tmr_aout2` | 0x340030 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `isa_parallel` | 0x380000 | w | 8 |  |  | unknown | established | census: 18 sites, 6 routines |
| `isa_parallel_380100` | 0x380100 | r | 8 |  |  | unknown | established | census: 27 sites, 9 routines |
| `isa_parallel_380200` | 0x380200 | rw | 8 |  |  | unknown | established | census: 59 sites, 10 routines |
| `isa_parallel_380300` | 0x380300 | rw | 8 |  |  | unknown | established | census: 46 sites, 7 routines |
| `isa_parallel_380400` | 0x380400 | rw | 8 |  |  | unknown | established | census: 41 sites, 6 routines |
| `isa_ecp1284` | 0x388200 | rw | 8 |  |  | unknown | established | census: 46 sites, 10 routines |
| `isa_rtc` | 0x3a0000 | rw | 8 |  |  | unknown | established | census: 6 sites, 3 routines |
| `isa_rtc_3a0100` | 0x3a0100 | w | 8 |  |  | unknown | established | census: 1 sites, 1 routines |
| `isa_rtc_3a0200` | 0x3a0200 | rw | 8 |  |  | unknown | established | census: 7 sites, 4 routines |
| `isa_rtc_3a0300` | 0x3a0300 | w | 8 |  |  | unknown | established | census: 1 sites, 1 routines |
| `isa_rtc_3a0400` | 0x3a0400 | rw | 8 |  |  | unknown | established | census: 7 sites, 4 routines |
| `isa_rtc_3a0500` | 0x3a0500 | w | 8 |  |  | unknown | established | census: 1 sites, 1 routines |
| `isa_rtc_3a0600` | 0x3a0600 | rw | 8 |  |  | unknown | established | census: 6 sites, 3 routines |
| `isa_rtc_3a0700` | 0x3a0700 | rw | 8 |  |  | unknown | established | census: 7 sites, 4 routines |
| `isa_rtc_3a0800` | 0x3a0800 | rw | 8 |  |  | unknown | established | census: 7 sites, 4 routines |
| `isa_rtc_3a0900` | 0x3a0900 | rw | 8 |  |  | unknown | established | census: 6 sites, 3 routines |
| `isa_rtc_3a0a00` | 0x3a0a00 | rw | 8 |  |  | unknown | established | census: 86 sites, 24 routines |
| `isa_rtc_3a0b00` | 0x3a0b00 | rw | 8 |  |  | unknown | established | census: 22 sites, 5 routines |
| `isa_rtc_3a0c00` | 0x3a0c00 | r | 8 |  |  | unknown | established | census: 4 sites, 4 routines |
| `isa_rtc_3a0e00` | 0x3a0e00 | rw | 8 |  |  | unknown | established | census: 5 sites, 3 routines |
| `isa_rtc_3a4800` | 0x3a4800 | rw | 8 |  |  | unknown | established | census: 6 sites, 3 routines |
| `isa_rtc_3a4900` | 0x3a4900 | w | 8 |  |  | unknown | established | census: 1 sites, 1 routines |
| `isa_rtc_3a4a00` | 0x3a4a00 | rw | 8 |  |  | unknown | established | census: 34 sites, 10 routines |
| `isa_rtc_3a4b00` | 0x3a4b00 | rw | 8 |  |  | unknown | established | census: 28 sites, 6 routines |

### Register `pci_err_addr`

### Register `pci_err_flags`

### Register `pci_control`

### Register `pci_flush_rev`

### Register `pci_config_addr`

### Register `pci_config_data`

### Register `vout_vhw_cfg`

### Register `eth_mac_control`

### Register `eth_rx_fifo`

### Register `eth_internal_ram`

### Register `aud_control`

### Register `aud_codec_cntl`

### Register `aud_codec_mask`

### Register `aud_codec_read`

### Register `aud_ch1_cntl`

### Register `aud_ch1_read`

### Register `aud_ch1_write`

### Register `aud_ch1_depth`

### Register `aud_ch2_cntl`

### Register `aud_ch2_read`

### Register `aud_ch2_write`

### Register `aud_ch2_depth`

### Register `aud_ch3_cntl`

### Register `aud_ch3_read`

### Register `aud_ch3_write`

### Register `aud_ch3_depth`

### Register `pioflush`

### Register `isa_ring_base`

### Register `isa_misc`

### Register `isa_int_stat`

### Register `isa_int_mask`

### Register `par_cntl_stat`

### Register `par_diag`

### Register `s1_tx_cntl`

### Register `s1_rx_cntl`

### Register `s2_tx_cntl`

### Register `s2_rx_cntl`

### Register `i2c_control`

### Register `i2c_data`

### Register `tmr_ust`

### Register `tmr_compare1`

### Register `tmr_compare2`

### Register `tmr_compare3`

### Register `tmr_ain`

### Register `tmr_aout1`

### Register `tmr_aout2`

### Register `isa_parallel`

### Register `isa_parallel_380100`

### Register `isa_parallel_380200`

### Register `isa_parallel_380300`

### Register `isa_parallel_380400`

### Register `isa_ecp1284`

### Register `isa_rtc`

### Register `isa_rtc_3a0100`

### Register `isa_rtc_3a0200`

### Register `isa_rtc_3a0300`

### Register `isa_rtc_3a0400`

### Register `isa_rtc_3a0500`

### Register `isa_rtc_3a0600`

### Register `isa_rtc_3a0700`

### Register `isa_rtc_3a0800`

### Register `isa_rtc_3a0900`

### Register `isa_rtc_3a0a00`

### Register `isa_rtc_3a0b00`

### Register `isa_rtc_3a0c00`

### Register `isa_rtc_3a0e00`

### Register `isa_rtc_3a4800`

### Register `isa_rtc_3a4900`

### Register `isa_rtc_3a4a00`

### Register `isa_rtc_3a4b00`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `AUD_CODEC_CNTL_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `AUD_CODEC_CNTL_V_10000` | 0x10000 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `AUD_CODEC_READ_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `AUD_CONTROL_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `AUD_CONTROL_B_11_5` | 0xfe0 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `AUD_CONTROL_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ETH_MAC_CONTROL_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ETH_MAC_CONTROL_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `I2C_CONTROL_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `I2C_CONTROL_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `I2C_CONTROL_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_ECP1284_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_ECP1284_V_10` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_ECP1284_V_40` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_ECP1284_V_60` | 0x60 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_ECP1284_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_ECP1284_V_80` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_ECP1284_V_C0` | 0xc0 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_INT_MASK_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_INT_MASK_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_INT_MASK_V_18` | 0x18 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_INT_MASK_V_A00` | 0xa00 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_INT_STAT_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_INT_STAT_B_8` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_MISC_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_MISC_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_MISC_B_5_4` | 0x30 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_MISC_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_MISC_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_3` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_6` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_6_3` | 0x48 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_7` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_7_3` | 0xf8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_7_4` | 0xf0 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_7_5_4` | 0xb0 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380100_B_7_6_3` | 0xc8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_B_6` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_B_6_3` | 0x78 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_B_7_5_4` | 0xb0 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_B_7_6_3` | 0xc8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_20` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_7` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_D` | 0xd | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380200_V_E` | 0xe | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_V_6` | 0x6 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_V_9` | 0x9 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380300_V_A` | 0xa | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380400_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380400_V_1A` | 0x1a | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380400_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380400_V_42` | 0x42 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380400_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380400_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_380400_V_9` | 0x9 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_55` | 0x55 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_78` | 0x78 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_87` | 0x87 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_AA` | 0xaa | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_FE` | 0xfe | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_PARALLEL_V_FF` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RING_BASE_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RING_BASE_V_0` | 0x0 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0100_V_C0` | 0xc0 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0200_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0200_B_5_0` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0300_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0400_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0400_B_5_0` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0400_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0500_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0600_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0700_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0700_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0700_B_5_0` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0800_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0800_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0900_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_B_15_5_3_0` | 0xffef | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_B_15_7_5_0` | 0xffbf | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_B_6_5` | 0x60 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_B_7` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_V_10` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_V_20` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0A00_V_30` | 0x30 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0B00_B_15_3_1_0` | 0xfffb | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0B00_B_15_8_6_0` | 0xff7f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0B00_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0B00_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0B00_V_80` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0B00_V_82` | 0x82 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0C00_B_7` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0E00_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A0E00_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4900_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4A00_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4A00_B_15_2` | 0xfffc | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4A00_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4A00_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4A00_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4B00_B_15_2_0` | 0xfffd | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4B00_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4B00_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4B00_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4B00_V_83` | 0x83 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_3A4B00_V_9` | 0x9 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `ISA_RTC_B_5_0` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PAR_CNTL_STAT_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PAR_CNTL_STAT_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PAR_CNTL_STAT_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PAR_CNTL_STAT_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PAR_DIAG_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PAR_DIAG_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PAR_DIAG_B_11_0` | 0xfff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONFIG_ADDR_B_7_2` | 0xfc | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONFIG_ADDR_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONFIG_ADDR_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONFIG_ADDR_V_C` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONFIG_DATA_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONFIG_DATA_V_3020` | 0x3020 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONFIG_DATA_V_6` | 0x6 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONTROL_B_11` | 0x800 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONTROL_V_503` | 0x503 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONTROL_V_85FF` | 0x85ff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONTROL_V_8DFF` | 0x8dff | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONTROL_V_FE000000` | 0xfe000000 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_CONTROL_V_FF000000` | 0xff000000 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `PCI_FLUSH_REV_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
| `VOUT_VHW_CFG_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the MACE I/O ASIC Specification, chip revision 2.0, register title (applied by the census join after the offsets were read from the code) |  |
