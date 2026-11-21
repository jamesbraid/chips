<!-- generated from devices/ioc4/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 ccef576c800b092fc2194a8aa07585500681e875bfc599b39ac495fed053d9e6 -->

# IOC4 (PCI I/O controller, later)

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout.

Unit `ioc4`, macro prefix `IOC4`.
Default source: census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pci_err_addr_l` | 0x0 | rw | 32 |  |  | unknown | established | census: 7 sites, 2 routines |
| `pci_err_addr_h` | 0x4 | r | 32 |  |  | unknown | established | census: 2 sites, 2 routines |
| `sio_ir` | 0x8 | rw | 32 |  |  | unknown | established | census: 13 sites, 5 routines |
| `other_ir` | 0xc | rw | 32 |  |  | unknown | established | census: 5 sites, 5 routines |
| `sio_ies` | 0x10 | rw | 32 |  |  | unknown | established | census: 2 sites, 2 routines |
| `other_ies` | 0x14 | rw | 32 |  |  | unknown | established | census: 2 sites, 2 routines |
| `sio_iec` | 0x18 | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `other_iec` | 0x1c | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sio_cr` | 0x20 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ioc4_attach` | 0x24 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `int_out` | 0x28 | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `gpcr_s` | 0x30 | w | 32 |  |  | unknown | established | census: 3 sites, 2 routines |
| `gpcr_c` | 0x34 | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `gppr0` | 0x40 | w | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `km_csr` | 0x200 | rw | 32 |  |  | unknown | established | census: 7 sites, 3 routines |
| `sbbr01_l` | 0x300 | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sbbr01_h` | 0x304 | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sbbr23_l` | 0x308 | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sbbr23_h` | 0x30c | w | 32 |  |  | unknown | established | census: 1 sites, 1 routines |
| `port0_sscr` | 0x310 | rw | 32 |  |  | unknown | established | census: 37 sites, 16 routines |
| `port0_stpir` | 0x314 | w | 32 |  |  | unknown | established | census: 5 sites, 4 routines |
| `port0_stcir` | 0x318 | r | 32 |  |  | unknown | established | census: 4 sites, 4 routines |
| `port0_srpir` | 0x31c | r | 32 |  |  | unknown | established | census: 5 sites, 3 routines |
| `port0_srcir` | 0x320 | w | 32 |  |  | unknown | established | census: 5 sites, 3 routines |
| `port0_srtr` | 0x324 | w | 32 |  |  | unknown | established | census: 3 sites, 3 routines |
| `port0_shadow` | 0x328 | rw | 32 |  |  | unknown | established | census: 6 sites, 4 routines |
| `uart0_reg0` | 0x380 | rw | 8 |  |  | unknown | established | census: 17 sites, 5 routines |
| `uart0_reg4` | 0x384 | rw | 8 |  |  | unknown | established | census: 4 sites, 2 routines |
| `cfg_id` | 0x200000 | r | 16 |  |  | unknown | established | census: 2 sites, 1 routines |
| `cfg_command_status` | 0x200004 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `cfg_revision` | 0x200008 | r | 32 |  |  | unknown | established | census: 1 sites, 1 routines |

### Register `pci_err_addr_l`

### Register `pci_err_addr_h`

### Register `sio_ir`

### Register `other_ir`

### Register `sio_ies`

### Register `other_ies`

### Register `sio_iec`

### Register `other_iec`

### Register `sio_cr`

### Register `ioc4_attach`

### Register `int_out`

### Register `gpcr_s`

### Register `gpcr_c`

### Register `gppr0`

### Register `km_csr`

### Register `sbbr01_l`

### Register `sbbr01_h`

### Register `sbbr23_l`

### Register `sbbr23_h`

### Register `port0_sscr`

### Register `port0_stpir`

### Register `port0_stcir`

### Register `port0_srpir`

### Register `port0_srcir`

### Register `port0_srtr`

### Register `port0_shadow`

### Register `uart0_reg0`

### Register `uart0_reg4`

### Register `cfg_id`

### Register `cfg_command_status`

### Register `cfg_revision`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CFG_COMMAND_STATUS_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_COMMAND_STATUS_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_COMMAND_STATUS_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_COMMAND_STATUS_V_146` | 0x146 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `CFG_REVISION_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `GPCR_C_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `GPCR_S_V_200` | 0x200 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `GPCR_S_V_FF00` | 0xff00 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `OTHER_IR_V_40` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `OTHER_IR_V_FF800000` | 0xff800000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PCI_ERR_ADDR_L_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PCI_ERR_ADDR_L_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PCI_ERR_ADDR_L_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PCI_ERR_ADDR_L_B_3_1` | 0xe | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PCI_ERR_ADDR_L_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT0_SRCIR_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT0_SRPIR_B_11_3` | 0xff8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT0_SRTR_V_A0` | 0xa0 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT0_SSCR_V_20000000` | 0x20000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT0_SSCR_V_8000000` | 0x8000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT0_SSCR_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `PORT0_STCIR_B_11_3` | 0xff8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SBBR01_L_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SBBR23_L_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_CR_B_7` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_CR_V_F` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `SIO_IR_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UART0_REG0_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UART0_REG0_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UART0_REG0_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UART0_REG0_V_40` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UART0_REG0_V_7` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UART0_REG0_V_80` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
| `UART0_REG4_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the public Linux headers' register titles (comparison names; the offsets and roles were read from the shipped routines first); configuration-space rows are the window base 0x200000 plus the configuration offset |  |
