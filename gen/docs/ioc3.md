# IOC3 (PCI I/O controller)

<!-- generated from defs/ioc3.toml by defs-gen - do not edit, change the source -->

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout.

Unit `ioc3`, macro prefix `IOC3`.
Default source: census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `sio_ir` | 0x1c | rw | 32 |  |  | unknown | established | census: 54 sites, 8 routines |
| `sio_ies` | 0x20 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `sio_iec` | 0x24 | w | 32 |  |  | unknown | established | census: 5 sites, 1 routines |
| `sio_cr` | 0x28 | rw | 32 |  |  | unknown | established | census: 18 sites, 3 routines |
| `int_out` | 0x2c | w | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `gpcr_s` | 0x34 | rw | 32 |  |  | unknown | established | census: 11 sites, 3 routines |
| `gpcr_c` | 0x38 | w | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `gppr0` | 0x40 | w | 32 |  |  | unknown | established | census: 6 sites, 1 routines |
| `gppr5` | 0x54 | rw | 32 |  |  | unknown | established | census: 12 sites, 1 routines |
| `ppbr_h_a` | 0x80 | w | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ppbr_l_a` | 0x84 | w | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ppcr_a` | 0x88 | rw | 32 |  |  | unknown | established | census: 9 sites, 2 routines |
| `ppcr` | 0x8c | rw | 32 |  |  | unknown | established | census: 39 sites, 4 routines |
| `ppbr_h_b` | 0x90 | w | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ppbr_l_b` | 0x94 | w | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ppcr_b` | 0x98 | rw | 32 |  |  | unknown | established | census: 9 sites, 2 routines |
| `km_csr` | 0x9c | rw | 32 |  |  | unknown | established | census: 21 sites, 3 routines |
| `sbbr_h` | 0xb0 | w | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `sbbr_l` | 0xb4 | w | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `port_a_stpir` | 0xbc | w | 32 |  |  | unknown | established | census: 15 sites, 4 routines |
| `port_a_stcir` | 0xc0 | r | 32 |  |  | unknown | established | census: 12 sites, 4 routines |
| `port_a_srpir` | 0xc4 | r | 32 |  |  | unknown | established | census: 18 sites, 3 routines |
| `port_a_srcir` | 0xc8 | w | 32 |  |  | unknown | established | census: 15 sites, 3 routines |
| `port_a_srtr` | 0xcc | w | 32 |  |  | unknown | established | census: 9 sites, 3 routines |
| `port_a_shadow` | 0xd0 | rw | 32 |  |  | unknown | established | census: 21 sites, 5 routines |
| `emcr` | 0xf0 | rw | 32 |  |  | unknown | established | census: 39 sites, 5 routines |
| `eisr` | 0xf4 | rw | 32 |  |  | unknown | established | census: 9 sites, 2 routines |
| `eier` | 0xf8 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ercsr` | 0xfc | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `erbr_h` | 0x100 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `erbr_l` | 0x104 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `erbar` | 0x108 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ercir` | 0x10c | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `erpir` | 0x110 | rw | 32 |  |  | unknown | established | census: 15 sites, 5 routines |
| `ertr` | 0x114 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `etcsr` | 0x118 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ersr` | 0x11c | w | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `etcdc` | 0x120 | r | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ebir` | 0x124 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `etbr_h` | 0x128 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `etbr_l` | 0x12c | rw | 32 |  |  | unknown | established | census: 12 sites, 2 routines |
| `etcir` | 0x130 | rw | 32 |  |  | unknown | established | census: 9 sites, 3 routines |
| `etpir` | 0x134 | rw | 32 |  |  | unknown | established | census: 9 sites, 3 routines |
| `emar_h` | 0x138 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `emar_l` | 0x13c | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ehar_h` | 0x140 | rw | 32 |  |  | unknown | established | census: 9 sites, 2 routines |
| `ehar_l` | 0x144 | rw | 32 |  |  | unknown | established | census: 9 sites, 2 routines |
| `micr` | 0x148 | rw | 32 |  |  | unknown | established | census: 30 sites, 2 routines |
| `midr_r` | 0x14c | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `midr_w` | 0x150 | w | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `pp_dcr` | 0x20152 | rw | 8 |  |  | unknown | established | census: 6 sites, 1 routines |
| `pp_ecr` | 0x2015a | rw | 8 |  |  | unknown | established | census: 12 sites, 2 routines |
| `uarta_reg0` | 0x20178 | w | 8 |  |  | unknown | established | census: 3 sites, 1 routines |
| `uarta_reg1` | 0x20179 | w | 8 |  |  | unknown | established | census: 6 sites, 2 routines |
| `uarta_reg2` | 0x2017a | w | 8 |  |  | unknown | established | census: 9 sites, 2 routines |
| `uarta_reg3` | 0x2017b | rw | 8 |  |  | unknown | established | census: 33 sites, 5 routines |
| `uarta_reg4` | 0x2017c | rw | 8 |  |  | unknown | established | census: 9 sites, 2 routines |
| `uarta_reg5` | 0x2017d | r | 8 |  |  | unknown | established | census: 3 sites, 1 routines |
| `uarta_reg7` | 0x2017f | w | 8 |  |  | unknown | established | census: 3 sites, 1 routines |
| `cfg_command` | 0x200004 | rw | 32 |  |  | unknown | established | census: 9 sites, 2 routines |
| `cfg_revision` | 0x200008 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `cfg_latency` | 0x20000c | w | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `cfg_error_addr_lo` | 0x200040 | rw | 32 |  |  | unknown | established | census: 6 sites, 1 routines |
| `cfg_error_addr_hi` | 0x200044 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |

### Register `sio_ir`

### Register `sio_ies`

### Register `sio_iec`

### Register `sio_cr`

### Register `int_out`

### Register `gpcr_s`

### Register `gpcr_c`

### Register `gppr0`

### Register `gppr5`

### Register `ppbr_h_a`

### Register `ppbr_l_a`

### Register `ppcr_a`

### Register `ppcr`

### Register `ppbr_h_b`

### Register `ppbr_l_b`

### Register `ppcr_b`

### Register `km_csr`

### Register `sbbr_h`

### Register `sbbr_l`

### Register `port_a_stpir`

### Register `port_a_stcir`

### Register `port_a_srpir`

### Register `port_a_srcir`

### Register `port_a_srtr`

### Register `port_a_shadow`

### Register `emcr`

### Register `eisr`

### Register `eier`

### Register `ercsr`

### Register `erbr_h`

### Register `erbr_l`

### Register `erbar`

### Register `ercir`

### Register `erpir`

### Register `ertr`

### Register `etcsr`

### Register `ersr`

### Register `etcdc`

### Register `ebir`

### Register `etbr_h`

### Register `etbr_l`

### Register `etcir`

### Register `etpir`

### Register `emar_h`

### Register `emar_l`

### Register `ehar_h`

### Register `ehar_l`

### Register `micr`

### Register `midr_r`

### Register `midr_w`

### Register `pp_dcr`

### Register `pp_ecr`

### Register `uarta_reg0`

### Register `uarta_reg1`

### Register `uarta_reg2`

### Register `uarta_reg3`

### Register `uarta_reg4`

### Register `uarta_reg5`

### Register `uarta_reg7`

### Register `cfg_command`

### Register `cfg_revision`

### Register `cfg_latency`

### Register `cfg_error_addr_lo`

### Register `cfg_error_addr_hi`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CFG_COMMAND_V_8146` | 0x8146 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_ERROR_ADDR_LO_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_ERROR_ADDR_LO_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_LATENCY_V_2800` | 0x2800 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_LATENCY_V_FF00` | 0xff00 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_REVISION_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `EMCR_V_1200` | 0x1200 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `EMCR_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `EMCR_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `EMCR_V_AC` | 0xac | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `ERBAR_V_1000000` | 0x1000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `ERCSR_B_8_0` | 0x1ff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `ETBR_L_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `ETCDC_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `ETCIR_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `GPCR_C_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `GPCR_S_V_10000` | 0x10000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `GPCR_S_V_20` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `GPPR5_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `MICR_B_11` | 0x800 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `MICR_V_400` | 0x400 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `MIDR_R_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT_A_SRCIR_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT_A_SRPIR_B_11_3` | 0xff8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT_A_SRTR_V_A0` | 0xa0 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT_A_SSCR` | 0xb8 | established | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset | width 0/4 byte(s), access arw; name [I] from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset; reached in 113 sites, 16 routine(s) |
| `PORT_A_SSCR_V_20000000` | 0x20000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT_A_SSCR_V_8000000` | 0x8000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT_A_SSCR_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT_A_STCIR_B_11_3` | 0xff8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PPCR_A_V_40000000` | 0x40000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PPCR_B_V_40000000` | 0x40000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PPCR_V_40000000` | 0x40000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PPCR_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_CR_V_70000` | 0x70000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_CR_V_AE5E` | 0xae5e | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_IEC_V_7F0000` | 0x7f0000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_IEC_V_FFFF` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_IR_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_IR_V_3C0000` | 0x3c0000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_IR_V_400000` | 0x400000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UARTA_REG2_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UARTA_REG2_V_7` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UARTA_REG3_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UARTA_REG3_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UARTA_REG3_V_40` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UARTA_REG3_V_80` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UARTA_REG5_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
