# Hub block transfer engine registers and control bits outside the census

<!-- generated from defs/hub_extra.toml by defs-gen - do not edit, change the source -->

Unit `hub_extra`, macro prefix `HUB`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `iio_ibna_0` | 0x410020 | rw | 64 |  |  | unknown | inferred |  |
| `iio_ibia_0` | 0x410028 | rw | 64 |  |  | unknown | inferred |  |
| `iio_ibia_1` | 0x420028 | rw | 64 |  |  | unknown | inferred |  |

### Register `iio_ibna_0`

Notification address of engine 0, the twin of the engine 1 slot in the census. Offset and name are from the public header. The header gives no access type, so rw is assumed.

### Register `iio_ibia_0`

Interrupt address of engine 0. Offset and name are from the public header. The header gives no access type, so rw is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `level` | established |  |  | Interrupt level: mask 0x7f shifted to bits 22:16 in the public header. |
| 8:0 | `node` | established |  |  | Destination node number: mask 0x1ff in the public header. |

### Register `iio_ibia_1`

Interrupt address of engine 1. Offset and name are from the public header. The header gives no access type, so rw is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `level` | established |  |  | Interrupt level: mask 0x7f shifted to bits 22:16 in the public header. |
| 8:0 | `node` | established |  |  | Destination node number: mask 0x1ff in the public header. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `IIO_IBCT_NOTIFY` | 0x10 | established |  | Notify bit of the control/terminate register, named NOTIFY in the public header. The census has the same value as an inferred constant. |
| `IIO_IBCT_POISON` | 0x100 | established |  | Poison bit of the control/terminate register, named POISON in the public header. The Theory of Operations calls directory poisoning a proposed feature, so its effect on shipped hardware is unknown. |
| `IIO_IBCT_ZFIL_MODE` | 0x1 | established |  | Zero-fill mode bit of the control/terminate register, named ZFIL_MODE in the public header. The header gives no behaviour for it. |
| `IIO_IBLS_BUSY` | 0x100000 | established |  | Busy bit of the length/status register, named IBLS_BUSY in the public header. |
| `IIO_IECLR_BTE0` | 0x20000 | inferred |  | Clears engine 0's latched error, per the public header's name. The header's comment on the bit is marked uncertain, so the meaning is inferred. |
| `IIO_IECLR_BTE1` | 0x40000 | inferred |  | Clears engine 1's latched error, per the public header's name. The header's comment on the bit is marked uncertain, so the meaning is inferred. |
