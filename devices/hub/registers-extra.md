<!-- generated from devices/hub/registers-extra.toml by defs-gen - do not edit, change the source -->

# Hub block transfer engine registers and control bits outside the census

Unit `hub_extra`, macro prefix `HUB`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `iio_wid` | 0x400000 | r | 64 |  |  | 0x1c101048 (established) | established |  |
| `iio_ilapr` | 0x400100 | rw | 64 |  |  | 0xffffffffffffffff (established) | established |  |
| `iio_ilapo` | 0x400108 | w | 64 |  |  | unknown | established |  |
| `iio_igfx_1` | 0x400148 | rw | 64 |  |  | unknown | inferred |  |
| `iio_scratch_reg0` | 0x400150 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_scratch_reg1` | 0x400158 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_itte` | 0x400160 | rw | 64 | 7 |  | 0x0 (established) | established |  |
| `iio_ibna_0` | 0x410020 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_ibia_0` | 0x410028 | rw | 64 |  |  | 0x0 (established) | established |  |
| `iio_ibia_1` | 0x420028 | rw | 64 |  |  | 0x0 (established) | established |  |

### Register `iio_wid`

Widget identification register of the Hub widget. Offset and field layout are from the public header. The header gives no access type and no reset value, so the The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `rev` | established |  |  | Revision number, bits 31:28, in the header's identification structure. |
| 27:12 | `part` | established |  |  | Widget part number, bits 27:12, in the header's identification structure. The header comment gives the Hub's value, IIO_WID_PART_HUB. |
| 11:1 | `mfg` | established |  |  | Manufacturer number, bits 11:1, in the header's identification structure. The header comment names a manufacturer; the name is not imported here, and the value is unknown. |

### Register `iio_ilapr`

Local access protection register, named and placed by the public header. The header gives no fields, access type or reset. The IRIX register table confirms the access.

### Register `iio_ilapo`

Protection override register, named and placed by the public header. The header gives no unlock value or behaviour, so none is imported. The IRIX register table confirms the access.

### Register `iio_igfx_1`

Graphics node and widget register 1, the twin of iio_igfx_0 in the census. The header gives both the same field layout: widget number in bits 3:0, node number in bits 12:4, processor number at bit 16 and a valid bit at bit 20. The header gives no access type, so rw is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `valid` | established |  |  | Valid: one bit at shift 20 in the header. |
| 16 | `processor` | established |  |  | Processor number: one bit at shift 16 in the header. |
| 12:4 | `node` | established |  |  | Node number: nine bits at shift 4 in the header. |
| 3:0 | `widget` | established |  |  | Widget number: four bits at shift 0 in the header. |

### Register `iio_scratch_reg0`

Scratch register 0. The header names its bit uses for software only and gives a mask of the bits that exist, 0x0000000f00f11fff. The IRIX register table confirms the access.

### Register `iio_scratch_reg1`

Scratch register 1, the twin of register 0. The IRIX register table confirms the access.

### Register `iio_itte`

Big-window translation entry n, for n from 0 to 6. Entry 0 is at the register offset and each later entry is eight bytes further on. The IRIX register table confirms the access.

Array of 7 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `iospace` | established |  |  | I/O space bit, bit 12 (IIO_ITTE_IOSP). Set selects the widget's I/O space, clear its memory space. |
| 11:8 | `widget` | established |  |  | Target widget number, bits 11:8 (IIO_ITTE_WIDGET_MASK, shift 8). |
| 4:0 | `slice` | established |  |  | Slice field, bits 4:0 (IIO_ITTE_OFFSET_MASK in the public header). |

### Register `iio_ibna_0`

Notification address of engine 0, the twin of the engine 1 slot in the census. Offset and name are from the public header. The IRIX register table confirms the access.

### Register `iio_ibia_0`

Interrupt address of engine 0. Offset and name are from the public header. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `level` | established |  |  | Interrupt level: mask 0x7f shifted to bits 22:16 in the public header. |
| 8:0 | `node` | established |  |  | Destination node number: mask 0x1ff in the public header. |

### Register `iio_ibia_1`

Interrupt address of engine 1. Offset and name are from the public header. The IRIX register table confirms the access.

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
| `IIO_IECLR_BTE0` | 0x20000 | inferred |  | Clears engine 0's latched error, per the public header's name. The header's comment on the bit is marked uncertain, so the meaning is inferred. The IRIX header defines the same bit and marks its comment with question marks, so the meaning stays inferred. |
| `IIO_IECLR_BTE1` | 0x40000 | inferred |  | Clears engine 1's latched error, per the public header's name. The header's comment on the bit is marked uncertain, so the meaning is inferred. The IRIX header defines the same bit and marks its comment with question marks, so the meaning stays inferred. |
| `IIO_IIDSR_ENB` | 0x1000000 | established |  | Interrupt enable bit, bit 24 of the interrupt destination register, from the public header's mask. |
| `IIO_IIDSR_LVL_MASK` | 0x3f | established |  | Interrupt number field, bits 5:0 of the interrupt destination register, from the public header's mask. |
| `IIO_IIDSR_NODE_MASK` | 0xff00 | established |  | Destination node field, bits 15:8, from the public header's mask. The reviewed tree has no bit-field structure for this register, so only the masks are imported. |
| `IIO_IIDSR_SENT` | 0x10000000 | established |  | Interrupt-sent bit, bit 28 of the interrupt destination register, from the public header's mask. |
| `IIO_ILCSR_BM8` | 0x800 | established |  | Eight-bit mode bit, bit 11 of the link control register, named bm8 in the public header's structure. |
| `IIO_ILCSR_LLP_EN` | 0x400 | established |  | Link enable bit, bit 10 of the link control register, named llp_en in the public header's structure. |
| `IIO_ILCSR_MAX_BURST_MASK` | 0x3ff00000000 | established |  | Maximum burst field, bits 41:32 of the link control register, from the public header's structure. |
| `IIO_ILCSR_MAX_RETRY_MASK` | 0x3ff0000 | established |  | Maximum retry field, bits 25:16 of the link control register, from the public header's structure. |
| `IIO_ILCSR_NULL_TO_MASK` | 0x3f | established |  | Null timeout field, bits 5:0 of the link control register, from the public header's structure. |
| `IIO_ILCSR_WARM_RESET` | 0x100 | established |  | Warm reset bit of the link control register, bit 8, named ILCSR_WARM_RESET in the public header. The census carries the same value as an inferred constant. The header gives no behaviour for it. |
| `IIO_ILLR_CB_CNT_MASK` | 0xffff0000 | established |  | Check-bit error count, bits 31:16 of the link log register, from the public header's structure. |
| `IIO_ILLR_SN_CNT_MASK` | 0xffff | established |  | Sequence-number error count, bits 15:0 of the link log register, from the public header's structure. |
| `IIO_ITTE_BASE` | 0x400160 | established |  | Offset of big-window translation entry 0, from the public header. Entry n sits at this value plus 8 times n. The census has entry 0 under an inferred name and entry 6 as a write-only register, which overlaps the header's entry 6. |
| `IIO_ITTE_INVALID_WIDGET` | 0x3 | established |  | Widget value the public header's disable routine writes to park a translation entry. |
| `IIO_ITTE_IOSP` | 0x1000 | established |  | I/O space bit of a translation entry, bit 12, from the public header. |
| `IIO_LLP_CSR_IS_UP` | 0x2000 | established |  | Link-up bit, bit 13 of the link control and status register, named IS_UP in the public header. The header names the bit only; what the other values of the status field mean is not imported. |
| `IIO_LLP_CSR_LLP_STAT_MASK` | 0x3000 | established |  | Two-bit link status field, bits 13:12, named LLP_STAT_MASK in the public header. |
| `IIO_WCR_DIR_CON` | 0x20000 | established |  | Widget direct-connect bit, bit 17 of the widget control register, named in the public header's structure. |
| `IIO_WCR_WIDGET_ID_MASK` | 0xf | established |  | The Hub's own widget number, bits 3:0 of the widget control register. The public header reads the number with this mask. The reset value is not imported. |
| `IIO_WID_PART_HUB` | 0xc101 | established |  | Widget part number the public header's comment assigns to the Hub (hub=c101). |
| `IIO_WSTAT_ECRAZY` | 0x100000000 | established |  | Crazy bit of the widget status register, bit 32, named ECRAZY in the public header ('Hub gone crazy'). The header gives no behaviour for it. |
| `IIO_WSTAT_TXRETRY` | 0x200 | established |  | Transmit retry timeout bit of the widget status register, bit 9, from the public header's mask. |
| `IIO_WSTAT_TXRETRY_MASK` | 0x7f0000 | established |  | Transmit retry counter, bits 22:16: mask 0x7f at shift 16 in the public header. The same header's bit-field structure gives eight bits at 23:16, so the width is disputed inside the header and not settled here. |
| `LNK_STAT_WORKING` | 0x2 | established |  | Value of the link status field the public header names WORKING. The name is the driver's expectation. The header names no other value of the field. The IRIX header defines the name with this value. |
