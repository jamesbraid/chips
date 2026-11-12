# Bridge-family registers and bits outside the census

<!-- generated from defs/bridge_extra.toml by defs-gen - do not edit, change the source -->

Unit `bridge_extra`, macro prefix `BRIDGE`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CONTROL_FLASH_WR_EN` | 0x80000000 | established |  | bit 31, flash write enable; reset 0. Set to allow writes to the flash. Clear, a write to the flash is an error and is not completed; the specification does not say what the requester receives. Specification section 3.2.5, table 11, printed page 21 |
| `CONTROL_RST_PIN_N` | 0xf000000 | established |  | bits 27:24, the four software reset pins RST_PIN_N(3:0); reset 0xf, every pin released. Writing 1 drives a pin high (released) and 0 drives it low (asserted). Bit n driving the n-th PCI bus reset output is inferred: the specification gives no bit-to-pin table. Which device each pin reaches is board wiring and unknown |
| `CONTROL_WIDGET_NUMBER` | 0xf | established |  | bits 3:0, the crosstalk widget number this chip answers at; reset 0xf, the specification's not-yet-assigned value. Firmware writes the assigned number |
| `DEVICE_BARRIER` | 0x8000 | established |  | bit 15; meaning [I] |
| `DEVICE_PRECISE` | 0x20000 | established |  | bit 17, precise exception; meaning [I] |
| `DEVICE_PREFETCH` | 0x40000 | established |  | bit 18; meaning [I] |
| `DEVICE_REALTIME` | 0x200000 | established |  | bit 21, written only on a revision 2 Bridge by the priority routine; meaning [I] |
| `DEVICE_SIZE_64` | 0x400000 | established |  | bit 22, 64-bit device size, 0 for 32-bit and 1 for 64-bit; reset 0; dropped from the set mask when the chip is the PIC; meaning [I] |
| `DEVICE_SWAP_PAIR` | 0x180000 | established |  | bits 20:19, the PMU and direct byte-swap bits, cleared when the two endian arguments are equal and set otherwise; meaning [I] |
| `DEVICE_SWAP_PROGRAMMED` | 0x2000 | established |  | bit 13, byte swap for accesses that reach the device through its programmed-I/O window; reset clear. With it clear, the device window byte lanes follow the swap-clear rule (see bridge-family.md) |
| `DEVICE_WRITE_GATHER_EN` | 0x1800000 | established |  | bits 24 and 23 together: PMU and direct write-gather enables; one flag pair controls both |
| `INT_STATUS_INVALID_ADDRESS` | 0x1000000 | established |  | bit 24, address invalid for this widget. Whether this error also fills the error address registers is not stated by the specification (unknown) |
| `STATUS_FLASH_SELECT` | 0x40 | established |  | bit 6 of the status register (offset 0x08), read only, reset undefined. A hard-wired strap: 0 makes chip select 0 and 1 makes chip select 1 serve the flash at address 0xc00000. The strap pin is FLASH_SELECT, specification section 2.1.4, table 4, printed page 13; the register bit is section 3.2.2, table 8, printed page 20 |
| `TEST_PIN_CONTROL` | 0x70 | established |  | access rw; resets to 0 in the specification |
| `TEST_PIN_CONTROL_DATA_OUT` | 0xf00 | established |  | Bridge: bits 11:8, test data out |
| `TEST_PIN_CONTROL_SELECT0` | 0x3 | established |  | Bridge: bits 1:0, pin-function select, two bits |
| `TEST_PIN_CONTROL_SELECT1` | 0xc | established |  | Bridge: bits 3:2 |
| `TEST_PIN_CONTROL_SELECT2` | 0x30 | established |  | Bridge: bits 5:4 |
| `TEST_PIN_CONTROL_SELECT3` | 0xc0 | established |  | Bridge: bits 7:6 |
| `XBRIDGE_TEST_PIN_CONTROL_DATA_OUT` | 0xff0000 | established |  | Xbridge: bits 23:16, an 8-bit data field; the Xbridge specification also widens the selects to eight, whose positions this header does not give ([U]) |
