<!-- generated from devices/l1/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 5d88dc9d5c83288a421175717ea9ea8c6659d4accb6cd6159a690b25d4dc2da0 -->

# L1 system controller UART path (node-local window), Origin 3000 family

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout.

Unit `l1`, macro prefix `L1`.
Default source: census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `uart_data` | 0x80 | rw | 64 |  |  | unknown | established | census: 13 sites, 4 routines |
| `uart_ier` | 0x88 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `uart_fcr_iir` | 0x90 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `uart_lcr` | 0x98 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `uart_mcr` | 0xa0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `uart_lsr` | 0xa8 | r | 64 |  |  | unknown | established | census: 66 sites, 6 routines |
| `uart_intr_clear` | 0x800090 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `uart_intr_pending` | 0x800098 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |

### Register `uart_data`

### Register `uart_ier`

### Register `uart_fcr_iir`

### Register `uart_lcr`

### Register `uart_mcr`

### Register `uart_lsr`

### Register `uart_intr_clear`

### Register `uart_intr_pending`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `UART_DATA_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_DATA_V_44` | 0x44 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_DATA_V_7E` | 0x7e | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_FCR_IIR_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_FCR_IIR_B_2` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_FCR_IIR_B_2_1` | 0x6 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_FCR_IIR_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_FCR_IIR_V_7` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_IER_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_INTR_PENDING_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LCR_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LSR_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LSR_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LSR_B_3_2` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LSR_B_3_2_0` | 0xd | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LSR_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LSR_B_6` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
| `UART_LSR_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the register role the L1 UART routines give it: a 16550-style register file with an 8-byte stride (a hypothesis the line-status, interrupt-identity and divisor-latch tests in the code support), or for 0x800090 and 0x800098 the place the interrupt poll tests and clears (role inferred) |  |
