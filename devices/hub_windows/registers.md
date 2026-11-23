<!-- generated from devices/hub_windows/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 433dec6921b0152c218127b867a36172e0ae5ba71149fa793336f17dac3023f3 -->

# Hub register arrays whose extent is a fact of its own

Runs of consecutive Hub registers seen as one array each, so that the end of the run is data. Each entry overlaps the registers listed one by one in the other Hub units, which carry the individual names; the two views describe the same storage. The offsets, names and counts come from the IRIX register headers and register table named in each entry.

Unit `hub_windows`, macro prefix `HUB_WIN`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pi_gfx_window` | 0x300 | rw | 64 | 10 |  | 0x0 (established) | established |  |
| `md_perf_cnt` | 0x210010 | rw | 64 | 6 |  | unknown | inferred | Linux SN0 Hub memory/directory header: MD_PERF_CNT0 to MD_PERF_CNT5 |
| `md_ureg0` | 0x220000 | rw | 64 | 8 |  | unknown | inferred | Linux SN0 Hub memory/directory header: MD_UREG0_0 to MD_UREG0_7 |
| `md_ureg1` | 0x220080 | rw | 64 | 16 |  | unknown | established |  |
| `iio_ioprb` | 0x400198 | rw | 64 | 9 |  | unknown | inferred | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure |
| `iio_prte` | 0x400308 | rw | 64 | 8 |  | unknown | inferred | Linux SN0 Hub I/O header: IIO_PRTE_0, IIO_PRTE(x), IIO_NUM_PRTES; the iprte_a structure |
| `ni_age` | 0x600500 | rw | 64 | 8 |  | unknown | inferred | Linux SN0 Hub network interface header: NI_AGE_CPU0_MEMORY to NI_AGE_IO_PIO (NI_AGE_REG_MIN, NI_AGE_REG_MAX) |
| `ni_meta_table` | 0x638000 | rw | 64 | 32 |  | unknown | inferred | Linux SN0 Hub network interface header: NI_META_TABLE(x), NI_META_ENTRIES, NMT_EXIT_PORT_MASK |
| `ni_local_table` | 0x638100 | rw | 64 | 16 |  | unknown | inferred | Linux SN0 Hub network interface header: NI_LOCAL_TABLE(x), NI_LOCAL_ENTRIES, NLT_EXIT_PORT_MASK |

### Register `pi_gfx_window`

The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then the same five for slot B. The source gives the distance between the two sets as the offset of the slot B page from the slot A page. The entries are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data.

Array of 10 registers, stride 8.

### Register `md_perf_cnt`

The six memory/directory performance counters as one array. The header gives no access type, so rw is an assumption.

Array of 6 registers, stride 8.

### Register `md_ureg0`

The eight microcontroller and UART 0 registers as one array. The same storage is listed one by one where the census reaches it. The header gives no access type, so rw is an assumption.

Array of 8 registers, stride 8.

### Register `md_ureg1`

The sixteen microcontroller and UART 1 registers as one array. They are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data. On the Origin 200 (the SN00 variant) the kernel's per-processor LED macro writes the LED of slice 0 at element 0 and the LED of slice 1 at element 4, a spacing of four elements per slice; other Hub variants use the separate LED registers. The IRIX register table gives read and write access for the entries it lists (0, 1 and 15) and the header gives all sixteen the same description.

Array of 16 registers, stride 8.

### Register `iio_ioprb`

The nine I/O partial-request buffer entries (0, then 8 to f) as one array; entry 0 sits at the first offset and entries 8 to f follow, eight bytes apart. The header gives no access type, so rw is an assumption. The header says the nak and overflow counters are status fields to be used only when cleaning up after errors.

Array of 9 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 48 | `error` | established |  | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure | Widget received a write response packet with an error. |
| 47:43 | `ovflow` | established |  | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure | Overflow count, five bits (performance measurement). |
| 42 | `fire_and_forget` | established |  | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure | Launch the write without a response. |
| 41:40 | `mode` | established | iio_prb_mode (normal=0, collect_a=1, service_a=2, service_b=3) | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure | Widget operation mode. |
| 37:24 | `bnakctr` | established |  | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure | B-side nak counter, fourteen bits. |
| 21:8 | `anakctr` | established |  | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure | A-side nak counter, fourteen bits. |
| 7:0 | `xtalkctr` | established |  | Linux SN0 Hub I/O header: IIO_IOPRB_0 to IIO_IOPRB_F, IIO_NUM_IPRBS; the iprb_t structure | Crosstalk counter, eight bits. |

### Register `iio_prte`

The eight PIO read address table entries as one array. The header gives no access type, so rw is an assumption.

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 56 | `valid` | established |  | Linux SN0 Hub I/O header: IIO_PRTE_0, IIO_PRTE(x), IIO_NUM_PRTES; the iprte_a structure | Maps to a timeout entry. |
| 54:46 | `srcnode` | established |  | Linux SN0 Hub I/O header: IIO_PRTE_0, IIO_PRTE(x), IIO_NUM_PRTES; the iprte_a structure | Node that issued the PIO, nine bits. |
| 45:44 | `initiator` | established |  | Linux SN0 Hub I/O header: IIO_PRTE_0, IIO_PRTE(x), IIO_NUM_PRTES; the iprte_a structure | Initiator, two bits (T5A, T5B or I/O). |
| 40:3 | `addr` | established |  | Linux SN0 Hub I/O header: IIO_PRTE_0, IIO_PRTE(x), IIO_NUM_PRTES; the iprte_a structure | Physical address of the PIO, 38 bits (the header's address shift is 3). |

### Register `ni_age`

The eight network age-control registers as one array: CPU 0 memory, CPU 0 PIO, CPU 1 memory, CPU 1 PIO, GBR memory, GBR PIO, I/O memory, I/O PIO, in that order. The same storage is listed one by one in the network interface unit, where the field layout sits. The header gives no access type, so rw is an assumption.

Array of 8 registers, stride 8.

### Register `ni_meta_table`

The 32-entry meta routing table as one array, replacing the split of the first entry and the other 31. Each entry holds the exit port. The header gives no access type, so rw is an assumption.

Array of 32 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `exit_port` | established |  | Linux SN0 Hub network interface header: NI_META_TABLE(x), NI_META_ENTRIES, NMT_EXIT_PORT_MASK | Exit port, four bits (NMT_EXIT_PORT_MASK 0xf). |

### Register `ni_local_table`

The 16-entry local routing table as one array, replacing the split of the first entry and the other 15. Each entry holds the exit port. The header gives no access type, so rw is an assumption.

Array of 16 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `exit_port` | established |  | Linux SN0 Hub network interface header: NI_LOCAL_TABLE(x), NI_LOCAL_ENTRIES, NLT_EXIT_PORT_MASK | Exit port, four bits (NLT_EXIT_PORT_MASK 0xf). |

## Enums

### Enum `iio_prb_mode`

| Label | Value | Grade | Source |
|---|---|---|---|
| `normal` | 0 | established |  |
| `collect_a` | 1 | established |  |
| `service_a` | 2 | established |  |
| `service_b` | 3 | established |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BWIN_INDEX_BITS` | 0x3 | established |  | Bits that index a big window. |
| `BWIN_SIZE_BITS_M_MODE` | 0x1d | established |  | Size of a big I/O window in address bits, M mode (512 MiB). |
| `BWIN_SIZE_BITS_N_MODE` | 0x1c | established |  | Size of a big I/O window in address bits, N mode (256 MiB). |
| `HUB_REGISTER_WIDGET` | 0x1 | established |  | Small window the Hub's own registers sit in. |
| `HUB_REGISTER_WINDOW_SIZE` | 0x800000 | established |  | Size of the Hub register window, 8 MiB, from the header's IALIAS_SIZE. |
| `NASID_BITS_M_MODE` | 0x8 | established |  | Node number width, M mode (mask 0xff). |
| `NASID_BITS_N_MODE` | 0x9 | established |  | Node number width, N mode (mask 0x1ff). |
| `NASID_LOCAL_BITS` | 0x4 | established |  | Low bits of a node number that name a node within its meta region. |
| `NASID_SHIFT_M_MODE` | 0x20 | established |  | Shift of the node number in a physical address, M mode. |
| `NASID_SHIFT_N_MODE` | 0x1f | established |  | Shift of the node number in a physical address, N mode. |
| `NODE_SIZE_BITS_M_MODE` | 0x20 | established |  | Address bits per node in M mode, from the header; a node's address space is 4 GiB. |
| `NODE_SIZE_BITS_N_MODE` | 0x1f | established |  | Address bits per node in N mode. |
| `SWIN_SIZE_BITS` | 0x18 | established |  | Size of a small I/O window in address bits (16 MiB). |
