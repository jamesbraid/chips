<!-- generated from devices/bedrock_md/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 5ab763a1dbf1570b7df1888172fc665b0fd53a8e4cc99dde24ccac8e3ba965af -->

# Bedrock memory and directory (MD) registers: field layouts, reset statements, error records and backdoor carriers

The memory and directory unit starts 7.5 MiB into the node's register space and holds the registers from the current-cell vector through the debug selector. Field positions, access widths and reset statements come from the public Linux 2.5.40 SN1 memory-directory header and its companion, so they are established as header facts. Where the companion header is marked as partly carried over from an earlier machine, its claims are graded inferred. Behaviour the header gives only in comments is graded as the comment's own claim, and behaviour it leaves open is unknown. No Bedrock specification is held, so no reset value is established where the header is silent. Diagnostic and PROM code tables are software expectations and graded inferred.

Unit `bedrock_md`, macro prefix `BEDROCK_MD`.
Default source: Linux 2.5.40 SN1 memory-directory register header.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `current_cell` | 0x780000 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `memory_config` | 0x780008 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 memory-directory register header |
| `arbitration_control` | 0x780010 | rw | 64 |  |  | 0x8f (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `migration_config` | 0x780018 | rw | 64 |  |  | 0xff0020 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `fetchop_cache_status0` | 0x780020 | r | 64 |  |  | 0xc0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `fetchop_cache_status1` | 0x780028 | r | 64 |  |  | 0xc0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `misc_error0` | 0x780040 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `misc_error1` | 0x780048 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `misc_error1_clr` | 0x780058 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `outgoing_reply_queue_size` | 0x780060 | rw | 64 |  |  | 0x1818180c0c0c00 (inferred; Linux 2.5.40 SN1 memory-directory register header, which gives 12 header entries and 24 data entries as the defaults; no IRIX source states them) | established | Linux 2.5.40 SN1 memory-directory register header |
| `perf_select0` | 0x790000 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 memory-directory register header |
| `perf_select1` | 0x790008 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 memory-directory register header |
| `perf_counter0` | 0x790010 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `perf_counter1` | 0x790018 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `refresh_control` | 0x7a0000 | rw | 64 |  |  | 0x800 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `junk_bus_timing` | 0x7a0008 | rw | 64 |  |  | 0xffffffffffff (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `led0` | 0x7a0010 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `led1` | 0x7a0018 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `led2` | 0x7a0020 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `led3` | 0x7a0028 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `self_test_control` | 0x7a0030 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 memory-directory register header |
| `self_test_data` | 0x7a0038 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `self_test_error_addr` | 0x7a0040 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `self_test_status` | 0x7a0048 | r | 64 |  |  | unknown | established | Linux 2.5.40 SN1 memory-directory register header |
| `issue_debug_select` | 0x7a0060 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `dir_config` | 0x7c0000 | rw | 64 |  |  | 0x2 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `dir_error` | 0x7c0010 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `dir_error_clr` | 0x7c0018 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `protocol_error` | 0x7c0020 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `protocol_error_clr` | 0x7c0028 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mig_candidate` | 0x7c0030 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mig_candidate_clr` | 0x7c0038 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mig_diff_thresh` | 0x7c0040 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mig_value_thresh` | 0x7c0048 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `outgoing_request_queue_size` | 0x7c0050 | rw | 64 |  |  | 0x4040400 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `selftest_dir_error_data` | 0x7c0058 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `dir_debug_select` | 0x7c0060 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mb_ecc_config` | 0x7e0000 | rw | 64 |  |  | 0x1 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mem_error` | 0x7e0010 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mem_error_clr` | 0x7e0018 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `selftest_mem_error_data0` | 0x7e0020 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `selftest_mem_error_data1` | 0x7e0028 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `selftest_mem_error_data2` | 0x7e0030 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `selftest_mem_error_data3` | 0x7e0038 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |
| `mem_debug_select` | 0x7e0040 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 memory-directory register header |

### Register `current_cell`

Access-rights vector. A region whose bit is set is inside the cell and uses the directory's local-access protection instead of per-region protection. The same vector sets the access rights for the Hub special spaces: set gives read and write, clear gives read only, except the local and remote register windows, which are inaccessible when the bit is clear. The header attributes region size to the network interface, while the local block's revision register holds it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `region_bits` | established |  | Linux 2.5.40 SN1 memory-directory register header | One bit per region. |

### Register `memory_config`

Memory configuration. Each DIMM position d has a byte at bits 8d+7 to 8d holding two bank enables, a DRAM width bit and a size code. Addresses beyond a configured size return errors. The header says software must ask the system controller whether a DIMM is x4 or x8/x16 before it sets the width. The header says the register survives a soft reset. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:60 | `rcd_rp_config` | established |  | Linux 2.5.40 SN1 memory-directory register header | Register-control and row-precharge configuration bits. The header gives no encoding. |
| 58:56 | `timing_high` | established |  | Linux 2.5.40 SN1 memory-directory register header | Timing field, high group. The companion header calls it write-only with a default of 7; that claim is inferred from the partly carried-over companion. |
| 53:48 | `timing_low` | established |  | Linux 2.5.40 SN1 memory-directory register header | Timing field, low group. |
| 47 | `ignore_cpu_protection` | established |  | Linux 2.5.40 SN1 memory-directory register header | Ignore CPU protection. |
| 46 | `ignore_io_protection` | established |  | Linux 2.5.40 SN1 memory-directory register header | Ignore I/O protection. |
| 45 | `io_protection_enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | I/O protection enable. |
| 44 | `cell_protection_enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | Cell protection enable. |
| 33:32 | `bank_select` | established |  | Linux 2.5.40 SN1 memory-directory register header | Bank-select field. Locational banks map to software banks by exclusive-or with this field. |
| 31:28 | `pos3_size` | established | size_code (empty=0, mb64=1, mb128=2, mb256=3, mb512=4, gb1=5) | Linux 2.5.40 SN1 memory-directory register header | Size code for DIMM position 3. |
| 27 | `pos3_width` | established |  | Linux 2.5.40 SN1 memory-directory register header | DRAM width for DIMM position 3. |
| 25:24 | `pos3_enables` | established |  | Linux 2.5.40 SN1 memory-directory register header | Bank enables for DIMM position 3. |
| 23:20 | `pos2_size` | established | size_code (empty=0, mb64=1, mb128=2, mb256=3, mb512=4, gb1=5) | Linux 2.5.40 SN1 memory-directory register header | Size code for DIMM position 2. |
| 19 | `pos2_width` | established |  | Linux 2.5.40 SN1 memory-directory register header | DRAM width for DIMM position 2. |
| 17:16 | `pos2_enables` | established |  | Linux 2.5.40 SN1 memory-directory register header | Bank enables for DIMM position 2. |
| 15:12 | `pos1_size` | established | size_code (empty=0, mb64=1, mb128=2, mb256=3, mb512=4, gb1=5) | Linux 2.5.40 SN1 memory-directory register header | Size code for DIMM position 1. |
| 11 | `pos1_width` | established |  | Linux 2.5.40 SN1 memory-directory register header | DRAM width for DIMM position 1. |
| 9:8 | `pos1_enables` | established |  | Linux 2.5.40 SN1 memory-directory register header | Bank enables for DIMM position 1. |
| 7:4 | `pos0_size` | established | size_code (empty=0, mb64=1, mb128=2, mb256=3, mb512=4, gb1=5) | Linux 2.5.40 SN1 memory-directory register header | Size code for DIMM position 0. |
| 3 | `pos0_width` | established |  | Linux 2.5.40 SN1 memory-directory register header | DRAM width for DIMM position 0. The header gives no encoding. |
| 1:0 | `pos0_enables` | established |  | Linux 2.5.40 SN1 memory-directory register header | Bank enables for DIMM position 0, one bit per physical bank. |

### Register `arbitration_control`

Arbitration control. The arbitration timing is not specified by the header.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `write_guarantee` | established |  | Linux 2.5.40 SN1 memory-directory register header | Write guarantee field. |
| 3:0 | `reply_guarantee` | established |  | Linux 2.5.40 SN1 memory-directory register header | Reply guarantee field. |

### Register `migration_config`

Page-migration configuration. The header names the interval, node mask and enable. Interval units and the scheduling rule are not given. The software that uses the migration interface never touches this register, so who sets the enable bit is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | Migration enable. |
| 23:16 | `node_mask` | established |  | Linux 2.5.40 SN1 memory-directory register header | Node mask. |
| 9:0 | `interval` | established |  | Linux 2.5.40 SN1 memory-directory register header | Migration interval. Units not given. |

### Register `fetchop_cache_status0`

Fetch-and-op cache status 0: a captured cache entry. Guest write behaviour is not given.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Entry valid. |
| 32:6 | `address` | established |  | Linux 2.5.40 SN1 memory-directory register header | Address of the captured entry. |

### Register `fetchop_cache_status1`

Fetch-and-op cache status 1: a second captured cache entry with the same layout as status 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Entry valid. |
| 32:6 | `address` | established |  | Linux 2.5.40 SN1 memory-directory register header | Address of the captured entry. |

### Register `misc_error0`

Miscellaneous error word 0: message header fields and two-bit error flags. The field positions are not summarised here.

### Register `misc_error1`

Miscellaneous error word 1: a 38-bit address and the same style of flags. The field positions are not summarised here.

### Register `misc_error1_clr`

Clear alias of miscellaneous error word 1. The header names it a clear register without saying whether a read or a write clears it. The one consumer reads and discards the value. The clearing mechanism is unknown.

### Register `outgoing_reply_queue_size`

Reply-queue credit sizes, all read-only fields. The header gives 12 header entries and 24 data entries as the defaults for each queue. A write resets the credit counters to these defaults. The shipped Origin 350 PROM register table holds 0x12 in the header fields and 0x24 in the data fields, which do not fit four and five bits as hex and equal 12 and 24 read as decimal, so the table does not settle the value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52:48 | `third_data_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Data-queue size for the third queue. Default 24. |
| 44:40 | `pi1_data_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Data-queue size for processor interface 1. Default 24. |
| 36:32 | `pi0_data_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Data-queue size for processor interface 0. Default 24. |
| 27:24 | `third_header_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Header-queue size for the third queue. Default 12. |
| 19:16 | `pi1_header_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Header-queue size for processor interface 1. Default 12. |
| 11:8 | `pi0_header_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Header-queue size for processor interface 0. Default 12. |

### Register `perf_select0`

Performance counter 0 selection. Complete event encodings and interrupt cadence are not given by the header. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `interrupt` | established |  | Linux 2.5.40 SN1 memory-directory register header | Interrupt enable. |
| 59:20 | `command` | established |  | Linux 2.5.40 SN1 memory-directory register header | Command field. |
| 19:16 | `channel` | established |  | Linux 2.5.40 SN1 memory-directory register header | Channel selector. |
| 14:8 | `source` | established |  | Linux 2.5.40 SN1 memory-directory register header | Event source selector. |
| 7:4 | `activity` | established |  | Linux 2.5.40 SN1 memory-directory register header | Activity selector. |
| 1:0 | `mode` | established |  | Linux 2.5.40 SN1 memory-directory register header | Counting mode. |

### Register `perf_select1`

Performance counter 1 selection, with the same layout as counter 0. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `interrupt` | established |  | Linux 2.5.40 SN1 memory-directory register header | Interrupt enable. |
| 59:20 | `command` | established |  | Linux 2.5.40 SN1 memory-directory register header | Command field. |
| 19:16 | `channel` | established |  | Linux 2.5.40 SN1 memory-directory register header | Channel selector. |
| 14:8 | `source` | established |  | Linux 2.5.40 SN1 memory-directory register header | Event source selector. |
| 7:4 | `activity` | established |  | Linux 2.5.40 SN1 memory-directory register header | Activity selector. |
| 1:0 | `mode` | established |  | Linux 2.5.40 SN1 memory-directory register header | Counting mode. |

### Register `perf_counter0`

Performance counter 0. The header describes a 41-bit count; the events that advance it are not given. The Itanium console code and the boot firmware of this machine class both use the word as a lock word by setting and clearing bits, which the header does not sanction. That use is a software expectation, inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40:0 | `count` | established |  | Linux 2.5.40 SN1 memory-directory register header | 41-bit count. |

### Register `perf_counter1`

Performance counter 1. The same 41-bit count layout as counter 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40:0 | `count` | established |  | Linux 2.5.40 SN1 memory-directory register header | 41-bit count. |

### Register `refresh_control`

Refresh control. Once the memory configuration holds the DIMM information, the hardware refreshes every bank. If a refresh window expires with banks unrefreshed, all other traffic halts until they are refreshed. The enable bit is cleared on reset because the first DIMM operation must be a mode-register write. The enable and threshold survive a soft reset. The live counter's

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | Refresh enable. Reads 0 after reset. |
| 23:12 | `live_counter` | established |  | Linux 2.5.40 SN1 memory-directory register header | Live refresh counter. |
| 11:0 | `threshold` | established |  | Linux 2.5.40 SN1 memory-directory register header | Refresh threshold in Bedrock clocks. |

### Register `junk_bus_timing`

Junk-bus timing for the flash PROM, the L1 UART and a device the Linux header names Synergy. The header names the timing fields; it does not place the Synergy device on any board. This is the only register in any unit that names the UART and the flash PROM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:40 | `synergy_enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | Synergy enable time, as the header names it. |
| 39:32 | `synergy_setup_hold` | established |  | Linux 2.5.40 SN1 memory-directory register header | Synergy setup and hold time, as the header names it. |
| 31:24 | `uart_enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | UART enable time. |
| 23:16 | `uart_setup_hold` | established |  | Linux 2.5.40 SN1 memory-directory register header | UART setup and hold time. |
| 15:8 | `flash_enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | Flash PROM enable time. |
| 7:0 | `flash_setup_hold` | established |  | Linux 2.5.40 SN1 memory-directory register header | Flash PROM setup and hold time. |

### Register `led0`

Reads the value on LED bank 0. The header says a read of this register gives the 8-bit LED value. Whether a write drives the LEDs is not stated.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `data` | established |  | Linux 2.5.40 SN1 memory-directory register header | LED bank value. |

### Register `led1`

Reads the value on LED bank 1. Otherwise as LED bank 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `data` | established |  | Linux 2.5.40 SN1 memory-directory register header | LED bank value. |

### Register `led2`

Reads the value on LED bank 2. Otherwise as LED bank 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `data` | established |  | Linux 2.5.40 SN1 memory-directory register header | LED bank value. |

### Register `led3`

Reads the value on LED bank 3. Otherwise as LED bank 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `data` | established |  | Linux 2.5.40 SN1 memory-directory register header | LED bank value. |

### Register `self_test_control`

Self-test control. Command precedence, self-clearing behaviour, the algorithm and the duration are unresolved. A retained write cannot qualify a completed test.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:5 | `dimm` | established |  | Linux 2.5.40 SN1 memory-directory register header | DIMM selector. |
| 4 | `bank` | established |  | Linux 2.5.40 SN1 memory-directory register header | Bank selector within the DIMM. |
| 2 | `reset` | established |  | Linux 2.5.40 SN1 memory-directory register header | Reset the self-test engine. |
| 1 | `stop` | established |  | Linux 2.5.40 SN1 memory-directory register header | Stop the test. |
| 0 | `start` | established |  | Linux 2.5.40 SN1 memory-directory register header | Start the test. |

### Register `self_test_data`

Self-test data and pattern control. The header gives the control names, not their full transformation rules.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `write_control` | established |  | Linux 2.5.40 SN1 memory-directory register header | Write control. |
| 6 | `cycle_control` | established |  | Linux 2.5.40 SN1 memory-directory register header | Cycle control. |
| 5 | `byte_control` | established |  | Linux 2.5.40 SN1 memory-directory register header | Byte control. |
| 4 | `nibble_control` | established |  | Linux 2.5.40 SN1 memory-directory register header | Nibble control. |
| 3:0 | `initial_pattern` | established |  | Linux 2.5.40 SN1 memory-directory register header | Initial pattern. |

### Register `self_test_error_addr`

Self-test error address: the failing column and row, and which block failed. Guest writes and the clearing mechanism are unresolved.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49 | `directory_error` | established |  | Linux 2.5.40 SN1 memory-directory register header | Directory block failed. |
| 48 | `memory_error` | established |  | Linux 2.5.40 SN1 memory-directory register header | Memory block failed. |
| 46:32 | `row` | established |  | Linux 2.5.40 SN1 memory-directory register header | Row of the failing address. |
| 30:16 | `memory_column` | established |  | Linux 2.5.40 SN1 memory-directory register header | Memory column of the failing address. |
| 14:0 | `directory_column` | established |  | Linux 2.5.40 SN1 memory-directory register header | Directory column of the failing address. |

### Register `self_test_status`

Self-test status. Reports the result of the test. Neither bit is meaningful until the test has run to completion.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `done` | established |  | Linux 2.5.40 SN1 memory-directory register header | Test complete. |
| 0 | `passed` | established |  | Linux 2.5.40 SN1 memory-directory register header | Test passed. |

### Register `issue_debug_select`

Issue-block debug selector. The prose gives three bits while both endian layouts declare two. The width conflict is open. The meanings of the selections are not given.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1:0 | `selection` | established |  | Linux 2.5.40 SN1 memory-directory register header | Debug selection; width unresolved, see the register note. |

### Register `dir_config`

Directory configuration. Bit 0 selects the premium directory format, and bit 1 ignores directory ECC. The register survives a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `ignore_dir_ecc` | established |  | Linux 2.5.40 SN1 memory-directory register header | Ignore directory ECC. |
| 0 | `premium` | established |  | Linux 2.5.40 SN1 memory-directory register header | Premium directory format: 64-bit words. Clear selects the standard format with 32-bit words. |

### Register `dir_error`

Directory error record. The address and syndrome belong to the highest-priority kind latched: uncorrectable above protection above correctable.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `uncorrectable_valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Uncorrectable directory error recorded. |
| 62 | `protection_double_valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Double-bit access-protection error recorded. |
| 61 | `correctable_valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Correctable directory error recorded. |
| 60 | `protection_correctable_valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Correctable access-protection error recorded. |
| 59 | `uncorrectable_overrun` | established |  | Linux 2.5.40 SN1 memory-directory register header | An uncorrectable error arrived while one was recorded. |
| 58 | `protection_double_overrun` | established |  | Linux 2.5.40 SN1 memory-directory register header | Overrun for the double-bit access-protection kind. |
| 57 | `correctable_overrun` | established |  | Linux 2.5.40 SN1 memory-directory register header | Overrun for the correctable directory kind. |
| 56 | `protection_correctable_overrun` | established |  | Linux 2.5.40 SN1 memory-directory register header | Overrun for the correctable access-protection kind. |
| 54:52 | `protection_index` | established |  | Linux 2.5.40 SN1 memory-directory register header | Protection index. Protection kinds only. |
| 51:48 | `bad_protection` | established |  | Linux 2.5.40 SN1 memory-directory register header | Bad protection value. Protection kinds only. |
| 46:40 | `syndrome` | established |  | Linux 2.5.40 SN1 memory-directory register header | Seven-bit syndrome of the latched error. |
| 32:3 | `hub_special_address` | established |  | Linux 2.5.40 SN1 memory-directory register header | Hub special address of the offending directory entry. |

### Register `dir_error_clr`

Clear alias of the directory error record. The header repeats the base register's text and names no mechanism. Read-to-clear is the consumer's expectation, not a stated rule.

### Register `protocol_error`

Protocol error record: directory state and format, pointer, message type, initiator, valid and overrun. The field positions are not summarised here.

### Register `protocol_error_clr`

Clear alias of the protocol error record. The mechanism is not stated.

### Register `mig_candidate`

Page-migration candidate. On overrun the newest candidate replaces the earlier one. The clear operation is not established by the header's repeated text. No shipped IRIX Origin 300/350 kernel accesses this register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Candidate valid. |
| 34 | `local` | established |  | Linux 2.5.40 SN1 memory-directory register header | Local flag. |
| 33 | `threshold_type` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold type that raised the candidate. Which register raises which type is unknown. |
| 32 | `overrun` | established |  | Linux 2.5.40 SN1 memory-directory register header | Overrun. |
| 31:21 | `initiator` | established |  | Linux 2.5.40 SN1 memory-directory register header | Requesting initiator. |
| 20:0 | `page_address` | established |  | Linux 2.5.40 SN1 memory-directory register header | Page address. |

### Register `mig_candidate_clr`

Clear alias of the migration candidate. Software reads only this alias and never the base register. That reading removes the candidate is inferred; the header does not say so. No shipped IRIX Origin 300/350 kernel accesses this register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Candidate valid. |
| 34 | `local` | established |  | Linux 2.5.40 SN1 memory-directory register header | Local flag. |
| 33 | `threshold_type` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold type. |
| 32 | `overrun` | established |  | Linux 2.5.40 SN1 memory-directory register header | Overrun. |
| 31:21 | `initiator` | established |  | Linux 2.5.40 SN1 memory-directory register header | Requesting initiator. |
| 20:0 | `page_address` | established |  | Linux 2.5.40 SN1 memory-directory register header | Page address. |

### Register `mig_diff_thresh`

Page-migration difference threshold. A valid threshold is reached when the difference between the requester's count and the home count is at least the threshold. The action encodings are not given. The shipped IRIX Origin 300/350 kernels only write this register, setting bit 63 to arm the threshold and clearing it to disarm.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold valid. |
| 37:35 | `saturation_action` | established |  | Linux 2.5.40 SN1 memory-directory register header | Saturation action. Encoding unknown. |
| 34:32 | `threshold_action` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold action. Encoding unknown. |
| 14:0 | `threshold` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold. |

### Register `mig_value_thresh`

Page-migration value threshold. Software writes it with bit 63 set and the local interrupt enable and action fields clear. Whether bits 18 to 15 are ignored is unknown. No shipped IRIX Origin 300/350 kernel accesses this register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold valid. |
| 62 | `local_interrupt_enable` | established |  | Linux 2.5.40 SN1 memory-directory register header | Local interrupt enable. |
| 37:35 | `saturation_action` | established |  | Linux 2.5.40 SN1 memory-directory register header | Saturation action. Encoding unknown. |
| 34:32 | `threshold_action` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold action. Encoding unknown. |
| 14:0 | `threshold` | established |  | Linux 2.5.40 SN1 memory-directory register header | Threshold. |

### Register `outgoing_request_queue_size`

Outgoing request-queue size. Each field defaults to four and has a maximum of four. A header occupies one entry. Writes above four and the side effects of resizing are not specified.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 26:24 | `third_request_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Third request queue. Default 4, maximum 4. |
| 18:16 | `pi1_request_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Request queue for processor interface 1. Default 4, maximum 4. |
| 10:8 | `pi0_request_queue` | established |  | Linux 2.5.40 SN1 memory-directory register header | Request queue for processor interface 0. Default 4, maximum 4. |

### Register `selftest_dir_error_data`

Failing directory word captured by the self-test. Guest writes are not established.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `word` | established |  | Linux 2.5.40 SN1 memory-directory register header | Failing directory word. |

### Register `dir_debug_select`

Directory-block debug selector. The meanings of the selections come from a separate design specification that is not held.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1:0 | `selection` | established |  | Linux 2.5.40 SN1 memory-directory register header | Debug selection. |

### Register `mb_ecc_config`

Memory-block ECC configuration. Bit 0 ignores data ECC.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `ignore_data_ecc` | established |  | Linux 2.5.40 SN1 memory-directory register header | Ignore data ECC. |

### Register `mem_error`

Memory error record: an address, a syndrome and a valid and overrun flag pair for each of three kinds. The address and syndrome belong to the earliest error of the highest priority: uncorrectable read above uncorrectable write above correctable read. Bit 63 is set when uncorrectable errors reached different cache lines. The header's flag summary gives the order of each pair's bits only in one place, so the pair order is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `differing_address` | established |  | Linux 2.5.40 SN1 memory-directory register header | Uncorrectable errors reached different cache lines. |
| 61:60 | `read_uncorrectable_flags` | inferred |  | Linux 2.5.40 SN1 memory-directory register header | Overrun and valid flags for the read-uncorrectable kind, in that order (61 overrun, 60 valid). The order is inferred from the register line; the memory diagnostic's own wait names bits 54 to 52 for the read-correctable kind, which conflicts with the summary. |
| 57:56 | `write_uncorrectable_flags` | inferred |  | Linux 2.5.40 SN1 memory-directory register header | Overrun and valid flags for the write-uncorrectable kind. The order is inferred as for the read kind. No consumer produces this kind. |
| 53:52 | `read_correctable_flags` | inferred |  | Linux 2.5.40 SN1 memory-directory register header | Overrun and valid flags for the read-correctable kind. The order is inferred as for the read-uncorrectable kind. |
| 47:40 | `syndrome` | established |  | Linux 2.5.40 SN1 memory-directory register header | Eight-bit syndrome of the latched error. |
| 32:3 | `address` | established |  | Linux 2.5.40 SN1 memory-directory register header | Thirty-bit doubleword address of the latched error, with the low three bits dropped. |

### Register `mem_error_clr`

Clear alias of the memory error record. The header repeats the base register's text and names no mechanism. Read-to-clear is the consumer's expectation, not a stated rule.

### Register `selftest_mem_error_data0`

Self-test captured memory data, quarter 0 of the failing line.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:0 | `word` | established |  | Linux 2.5.40 SN1 memory-directory register header | Captured data. |

### Register `selftest_mem_error_data1`

Self-test captured memory data, quarter 1 of the failing line.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:0 | `word` | established |  | Linux 2.5.40 SN1 memory-directory register header | Captured data. |

### Register `selftest_mem_error_data2`

Self-test captured memory data, quarter 2 of the failing line.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:0 | `word` | established |  | Linux 2.5.40 SN1 memory-directory register header | Captured data. |

### Register `selftest_mem_error_data3`

Self-test captured memory data, quarter 3 of the failing line.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:0 | `word` | established |  | Linux 2.5.40 SN1 memory-directory register header | Captured data. |

### Register `mem_debug_select`

Memory-block debug selector. The meaning of the selection requires the separate design specification.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `selection` | established |  | Linux 2.5.40 SN1 memory-directory register header | Debug selection. |

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `DIR_ENTRY_POINTER` | 64 | established | Linux 2.5.40 SN1 memory-directory header, directory word layout |
| `DIR_ENTRY_SHARED_FINE` | 64 | established | Linux 2.5.40 SN1 memory-directory header, directory word layout |

### Word `DIR_ENTRY_POINTER`

Directory word in the pointer format. Bits 1:0 hold the format, which is the same in both flavors. In a premium word bits 24:22 extend the pointer to ten bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24:22 | `first_pointer_high` | established |  | Linux 2.5.40 SN1 memory-directory header, directory word layout | Premium only: pointer bits 10:8. |
| 15:8 | `first_pointer` | established |  | Linux 2.5.40 SN1 memory-directory header, directory word layout | First pointer: node above three device bits, see PTR_NODE_SHIFT. |
| 4:2 | `state` | established | dir_pointer_state (exclusive=0, busy_shared=4, busy_exclusive=5, wait=6, poisoned=7) | Linux 2.5.40 SN1 memory-directory header, directory word layout | Pointer-format state. |
| 1:0 | `format` | established | dir_format (unowned=0, pointer=1, shared_fine=2, shared_coarse=3) | Linux 2.5.40 SN1 memory-directory header, directory word layout | Format. Pointer format is 1. |

### Word `DIR_ENTRY_SHARED_FINE`

Directory word in the shared-fine format. In this format a vector bit stands for one processor interface, not one processor.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `first_vector_high` | established |  | Linux 2.5.40 SN1 memory-directory header, directory word layout | Premium only: extends the first vector. |
| 23:22 | `first_tag_high` | established |  | Linux 2.5.40 SN1 memory-directory header, directory word layout | Premium only: extends the first tag. |
| 15:8 | `first_vector` | established |  | Linux 2.5.40 SN1 memory-directory header, directory word layout | First vector. |
| 4:2 | `first_tag` | established |  | Linux 2.5.40 SN1 memory-directory header, directory word layout | First tag. |
| 1:0 | `format` | established | dir_format (unowned=0, pointer=1, shared_fine=2, shared_coarse=3) | Linux 2.5.40 SN1 memory-directory header, directory word layout | Format. Shared fine is 2. |

## Enums

### Enum `dir_format`

| Label | Value | Grade | Source |
|---|---|---|---|
| `unowned` | 0 | established | Linux 2.5.40 SN1 memory-directory register header |
| `pointer` | 1 | established | Linux 2.5.40 SN1 memory-directory register header |
| `shared_fine` | 2 | established | Linux 2.5.40 SN1 memory-directory register header |
| `shared_coarse` | 3 | established | Linux 2.5.40 SN1 memory-directory register header |

### Enum `dir_pointer_state`

| Label | Value | Grade | Source |
|---|---|---|---|
| `exclusive` | 0 | established | Linux 2.5.40 SN1 memory-directory register header |
| `busy_shared` | 4 | established | Linux 2.5.40 SN1 memory-directory register header |
| `busy_exclusive` | 5 | established | Linux 2.5.40 SN1 memory-directory register header |
| `wait` | 6 | established | Linux 2.5.40 SN1 memory-directory register header |
| `poisoned` | 7 | established | Linux 2.5.40 SN1 memory-directory register header |

### Enum `size_code`

| Label | Value | Grade | Source |
|---|---|---|---|
| `empty` | 0 | inferred | Linux 2.5.40 SN1 memory-directory register header |
| `mb64` | 1 | inferred | Linux 2.5.40 SN1 memory-directory register header |
| `mb128` | 2 | inferred | Linux 2.5.40 SN1 memory-directory register header |
| `mb256` | 3 | inferred | Linux 2.5.40 SN1 memory-directory register header |
| `mb512` | 4 | inferred | Linux 2.5.40 SN1 memory-directory register header |
| `gb1` | 5 | inferred | Linux 2.5.40 SN1 memory-directory register header |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `DIMM_POSITIONS` | 0x4 | established | Linux 2.5.40 SN1 memory-directory register header | DIMM bank positions per node, in two pairs. |
| `DIR_BACKDOOR_EIGHTHS` | 0x7 | established | Linux 2.5.40 SN1 memory-directory register header | The directory backdoor starts at seven eighths of the node's Hub special space, per the public SN1 address header. |
| `DIR_LINE_BYTES` | 0x80 | established | Linux 2.5.40 SN1 memory-directory register header | Memory cache line covered by one directory word, from the public SN1 address header. |
| `DIR_WORD_STRIDE` | 0x10 | established | Linux 2.5.40 SN1 memory-directory register header | Stride of directory words in the directory backdoor: one 64-bit word per 16 bytes of backdoor space, one per 128-byte line. |
| `ECC_BACKDOOR_EIGHTHS` | 0x5 | established | Linux 2.5.40 SN1 memory-directory register header | The memory ECC entry backdoor starts at five eighths of the node's Hub special space, per the public SN1 address header. |
| `INTR_CORRECTABLE_MEM_BIT` | 0x3d | established | Linux 2.5.40 SN1 memory-directory register header | Level-1 interrupt bit that the public interrupt tables give for a correctable memory or directory error. The line that raises it on Bedrock is inferred. |
| `INTR_UNCORRECTABLE_MEM_BIT` | 0x18 | established | Linux 2.5.40 SN1 memory-directory register header | Error-interrupt pending bit that the processor-interface header assigns to memory and directory errors (the header comment says it must be cleared in the MD unit). The line that raises it on Bedrock is inferred. |
| `PAGE_COUNTER_OFFSET` | 0x8 | established | Linux 2.5.40 SN1 memory-directory register header | Offset of the page-counter entry from the directory word, per the public SN1 address header. The counter's fields are not given. |
| `PHYSICAL_BANKS_PER_DIMM` | 0x2 | established | Linux 2.5.40 SN1 memory-directory register header | Physical banks in each DIMM position. |
| `PROTECTION_ENTRY_OFFSET` | 0x408 | established | Linux 2.5.40 SN1 memory-directory register header | Offset of the protection entry from the directory base, per the public SN1 address header. Its meaning is not given. |
| `PTR_DEVICE_MASK` | 0x7 | established | Linux 2.5.40 SN1 memory-directory register header | Mask of the three device bits in a directory pointer. Device bit 1 marks an I/O owner; a processor's slice is device bit 0 plus device bit 2 shifted down. |
| `PTR_NODE_SHIFT` | 0x3 | established | Linux 2.5.40 SN1 memory-directory register header | A directory pointer carries the node number above three device bits. |
| `REFRESH_CYCLES_PER_4096` | 0xc35 | established | Linux 2.5.40 SN1 memory-directory register header | Threshold in Bedrock clocks that the header's comment gives for 4096 refreshes per 64 ms. The header gives this as the comment's own arithmetic. |
| `REFRESH_INTERVAL_BOOK_NS` | 0x1f40 | established | Linux 2.5.40 SN1 memory-directory register header | The Origin 3000 architecture book says the interface refreshes the DIMMs about every 8 microseconds. This disagrees with the 3125-cycle threshold, which is about 15.6 microseconds at 200 MHz. The clock rate is inferred, and the conflict is unresolved. |
| `SCRUB_BACKDOOR_EIGHTHS` | 0x4 | established | Linux 2.5.40 SN1 memory-directory register header | The ECC scrub carrier starts at four eighths of the node's Hub special space, per the public SN1 address header. The header names it and says nothing more. |
| `SOFTWARE_BANKS` | 0x8 | established | Linux 2.5.40 SN1 memory-directory register header | Software banks per node. Software bank n sits at node offset n gigabytes. |
| `SOFTWARE_BANK_BYTES` | 0x40000000 | established | Linux 2.5.40 SN1 memory-directory register header | Size of one software bank: 1 GB. |
