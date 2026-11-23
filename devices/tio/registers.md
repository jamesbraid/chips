<!-- generated from devices/tio/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 b463b599a6e231ec27eb619f305e4db2b5869fa84254ccd3fe4d207973c9b22e -->

# TIO (NUMAlink I/O node ASIC of the Altix generation), as SGI's Linux platform code names its registers

Offsets, field positions and constants are software definitions from SGI's Linux Altix platform code (header and driver, v5.3); the TIO's own register specification is not held. Only five registers are named by that code. Reset values are unknown throughout. Offsets are node offsets inside the TIO's address space, not CPU addresses.

Unit `tio`, macro prefix `TIO`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `node_id` | 0x90060e80 | rw | 64 |  |  | unknown | established |  |
| `ice_frz_cfg` | 0xb0008100 | rw | 64 |  |  | unknown | established |  |
| `itte` | 0xb0008800 | rw | 64 | 8 |  | unknown | established |  |
| `ice_pmi_tx_cfg` | 0xb000b100 | rw | 64 |  |  | unknown | established |  |
| `ice_pmi_tx_dyn_credit_stat_cb3` | 0xb000be18 | r | 64 |  |  | unknown | established |  |

### Register `node_id`

Widget-format identification word of the TIO itself (`TIO_NODE_ID`). The kernel reads the whole 64-bit register, keeps the low 32 bits and splits them with the same macros it uses for every widget identification word: part number, revision, manufacturer. Its one use: the revision field decides whether the write-request flush workaround applies (revision 1). The SHub 2 PROM also read-modify-writes the register to install the node number (bits 45:32) and a six-bit value (bits 53:48); see devices/tio/prom-access.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 53:48 | `nodes_per_bit_pow2` | inferred |  |  | Six-bit value written by the same method: a power of two derived from the call's size argument. The meaning is inferred from the SHub 2 node register, whose same-position field the PROM names NODES_PER_BIT. |
| 45:32 | `node` | established |  |  | Node number (NASID), written by the SHub 2 PROM's node-number method with a 14-bit deposit. Read-modify-write: other bits are kept. |
| 31:28 | `rev` | established |  |  | Revision. 1 is the revision the TIOCP flush erratum applies to. |
| 27:12 | `part` | established |  |  |  |
| 11:1 | `mfg` | established |  |  |  |

### Register `ice_frz_cfg`

ICE chiplet freeze configuration (`TIO_ICE_FRZ_CFG`). Bit 61 disables the conveyor of the FPGA port: the FPGA-port driver clears it to enable and sets it to disable, reading before writing and skipping the write when the bit is already right. Other bits are not read by any code.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61 | `disable_conveyor` | established |  |  | Named `disable_cb` in the driver. 1 disables the conveyor. |

### Register `itte`

Big-window translation table entries (`TIO_ITTE_BASE`, one entry per big window number 0 to 7). An entry maps one 1 GiB window of the TIO's address space onto a widget. The kernel defines a store macro (`TIO_ITTE_PUT`) and reads a firmware-held copy of the entries to find the widget for a window; no code read writes the register itself. The field positions are the macro's.

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `valid` | established |  |  |  |
| 13:12 | `widget` | established |  |  | Target widget, 0 to 3. |
| 7:0 | `offset` | established |  |  | Window offset: address bits 37:30 of the target, from `(addr >> 30) & 0xff`. |

### Register `ice_pmi_tx_cfg`

ICE port-module interface transmit configuration (`TIO_ICE_PMI_TX_CFG`). The FPGA-port driver resets corelet n by writing a one in bit n, waiting 2 ms, writing zero, then waiting 2 ms. The FPGA corelet is number 3.

### Register `ice_pmi_tx_dyn_credit_stat_cb3`

Dynamic transmit credit status of channel buffer 3 (`TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3`). The driver treats a credit count of 15 as proof that an FPGA bitstream is loaded and the port is running.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `credit_count` | established |  |  |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BIG_WINDOW_SIZE_BITS` | 0x1e | established |  | Big windows are 1 GiB; the window number is three bits above that. |
| `CE_PART_NUMBER` | 0xce00 | established |  | Widget part number of the TIOCE, which can sit on the FPGA port's widget. |
| `CTALK_CHIPLET_SHIFT` | 0x26 | established |  | Chiplet id position in a coretalk address, 2 bits. Node offset is bits 37:0. |
| `CTALK_NASID_SHIFT` | 0x28 | established |  | NASID position in a coretalk address, 14 bits. |
| `ERROR_VECTOR` | 0x36 | established |  | Kernel interrupt vector of the TIO error interrupt, shared by every TIO. The handler's only action is a firmware call. |
| `ERROR_VECTOR_TIOCA` | 0x35 | established |  | Error vector of the TIOCA. |
| `ERROR_VECTOR_TIOCX` | 0x37 | established |  | Defined; no registration of it appears in the files read. |
| `FPGA_CORELET` | 0x3 | established |  | Widget (corelet) number of the FPGA port. |
| `INTR_VECTOR_SHIFT` | 0x38 | established |  | Position of the kernel vector in a TIOCE interrupt destination word; the Crosstalk address supplied by firmware fills the low bits. |
| `KLTYPE_TIO` | 0x12 | established |  | Board type of a TIO in the klconfig list. |
| `SAL_HUB_ERROR_INTERRUPT` | 0x2000060 | established |  | Firmware call made by the TIO error handler; a nonzero result is fatal. |
| `SAL_IOIF_INTERRUPT` | 0x200004a | established |  | Firmware call that allocates (1), frees (2) or redirects (3) a bridge interrupt. |
| `SMALL_WINDOW_SIZE_BITS` | 0x1c | established |  | Small windows are 256 MiB, one per widget, selected by two address bits, so a TIO has four small-window widgets (0 to 3). |
| `WIDGET_ID_OFFSET` | 0x0 | established |  | Every widget behind the TIO, including the FPGA port, has its identification word (revision 31:28, part 27:12, manufacturer 11:1) at offset 0 of its small window. |
