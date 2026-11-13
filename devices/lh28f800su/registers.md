<!-- generated from devices/lh28f800su/registers.toml by defs-gen - do not edit, change the source -->

# Sharp LH28F800SU 8 Mbit x16 flash: array geometry, command set, identifier and status registers

The 1 MiB flash part in x16 mode: block geometry, the compatible and extended command opcodes, the identifier words, the typical operation times and the status words read back through the status and extended-status commands. Grades: established means the manufacturer datasheet states the value; inferred means arithmetic on a stated value or a reading of the command table; unknown means the datasheet does not settle it. Which SGI board fits this part, and how its pins are wired, is not stated by the datasheet and is not listed here.

Unit `lh28f800su`, macro prefix `LH28F800SU`.
Default source: Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `BSR` | 8 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |
| `CSR` | 8 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |
| `GSR` | 8 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |

### Word `BSR`

Block status register, one per block, read through the extended-status mode at the BSR word address of that block. Bits 1 and 0 are reserved.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `block_ready` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | This block's write operation is ready. |
| 6 | `lock_cleared` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | The displayed lock is cleared when this bit is set. Every displayed lock reads locked at power-up, until the status upload has run. The displayed bit is not the stored lock bit. |
| 5:4 | `op_status` | established | bsr_op (ok_or_running=0, failure=2, aborted=3) | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Bit 5 is operation unsuccessful and bit 4 is operation aborted, read together. The value 01 is invalid. |
| 3 | `queue_full` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Queue full. |
| 2 | `low_vpp` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Low VPP detected during an operation on this block. |

### Word `CSR`

Compatible status register, read after 0x70. Bit 7 is ready when set and busy when clear. Bits 2 to 0 are reserved.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `ready` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | 1 when the write state machine is ready, 0 while busy. |
| 6 | `erase_suspended` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Erase suspended. |
| 5 | `erase_error` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Erase error. Bits 5 and 4 both set after an erase attempt mean an improper command sequence. Printed p. 12. |
| 4 | `program_error` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Program error. Printed p. 12. |
| 3 | `low_vpp` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Low VPP detected during an operation. Printed p. 12. |

### Word `GSR`

Global status register, read through the extended-status mode at the GSR word address of a block. Only the low byte is defined. DQ8 to DQ15 are not used for status register reads (printed p. 4).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `write_ready` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Write state machine ready. |
| 6 | `suspended` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Operation suspended. |
| 5:4 | `op_status` | established | gsr_op (ok_or_running=0, sleep=1, failure=2, failure_or_abort=3) | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Bit 5 and bit 4 together give the operation state. |
| 3 | `queue_full` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Command queue full. |
| 2 | `buffer_available` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | At least one page buffer available. |
| 1 | `buffer_ready` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Selected page buffer ready. |
| 0 | `buffer_select` | established |  | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Buffer 1 selected when set. |

## Enums

### Enum `bsr_op`

| Label | Value | Grade | Source |
|---|---|---|---|
| `ok_or_running` | 0 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |
| `failure` | 2 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |
| `aborted` | 3 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |

### Enum `gsr_op`

| Label | Value | Grade | Source |
|---|---|---|---|
| `ok_or_running` | 0 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |
| `sleep` | 1 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |
| `failure` | 2 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |
| `failure_or_abort` | 3 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `LH28F800SU_ARRAY_BYTES` | 0x100000 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Array size: 8 Mbit, 1 MiB, in sixteen blocks. Printed pp. 2, 4 to 7. |
| `LH28F800SU_BLOCK_BYTES` | 0x10000 | inferred | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Bytes per block: the array size divided by the block count, 64 KiB. Arithmetic on the two values above. |
| `LH28F800SU_BLOCK_COUNT` | 0x10 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Independently lockable blocks in the array. Printed p. 2. |
| `LH28F800SU_BLOCK_ERASE_TYP_MS` | 0x2bc | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Typical block erase time, 0.7 s. The datasheet says it is a typical figure, not a guaranteed limit. Printed p. 6. |
| `LH28F800SU_BLOCK_WORDS` | 0x8000 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Words per block in x16 mode. Printed pp. 2 and 4 to 7. |
| `LH28F800SU_CMD_BLOCK_LOCK` | 0x77 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Block lock setup in the enhanced command set, confirmed by 0xd0. Named here for its opcode only; the lock contract is not imported. Printed pp. 6, 8, 11 to 14. |
| `LH28F800SU_CMD_CLEAR_STATUS` | 0x50 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Write cycle with no following read. Clears CSR bits 3 to 5, GSR bit 5, and bits 5 and 2 of every BSR. It does not change the array or the stored lock bits. Printed p. 10. |
| `LH28F800SU_CMD_CONFIRM` | 0xd0 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Erase confirm, written after 0x20 at an address in the target block. The block containing this address is the one erased. It also resumes a suspended erase. Printed p. 10. |
| `LH28F800SU_CMD_ERASE_SETUP` | 0x20 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Block erase setup. Written at any address. The address of this cycle is not used. Printed p. 10. |
| `LH28F800SU_CMD_EXT_STATUS` | 0x71 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Extended status mode. The read address that follows, not this write address, selects a GSR or a BSR. Printed pp. 6, 8, 11 to 14. |
| `LH28F800SU_CMD_IDENTIFY` | 0x90 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Write cycle that selects identifier output. The next read at word address 0 or 1 returns an identifier word. Printed p. 10. |
| `LH28F800SU_CMD_PROGRAM` | 0x40 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Word program setup. The next write cycle, at the destination word, carries the data. Printed p. 10. |
| `LH28F800SU_CMD_PROGRAM_ALT` | 0x10 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Second word program setup code, with the same sequence as 0x40. Printed p. 10. |
| `LH28F800SU_CMD_READ_ARRAY` | 0xff | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Write cycle that selects array output. The next read at any address returns array data. Printed p. 10. |
| `LH28F800SU_CMD_READ_STATUS` | 0x70 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Write cycle that selects compatible status output. Printed p. 10. |
| `LH28F800SU_CMD_SUSPEND` | 0xb0 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Erase suspend. Resumed by a write of 0xd0. Printed p. 10. |
| `LH28F800SU_CMD_UPLOAD_STATUS` | 0x97 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Status upload setup, confirmed by 0xd0. Copies the stored lock bits to the displayed BSR bit 6 fields. Both write addresses are not used. Printed p. 11. |
| `LH28F800SU_ID_WORD0` | 0xb0 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Identifier word read at word address 0 after 0x90, with all other address pins zero. Printed p. 9. |
| `LH28F800SU_ID_WORD1` | 0x66a8 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Identifier word read at word address 1 after 0x90, with all other address pins zero. Printed p. 9. |
| `LH28F800SU_RP_RECOVERY_NS` | 0x190 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Recovery interval after RP is released before the device returns to array mode. Printed reset section, pp. 4 and 7. |
| `LH28F800SU_WORD_PROGRAM_TYP_US` | 0x8 | established | Sharp, LH28F800SU 8M Flash Memory, SMT96107 (May 1996) | Typical word program time. The datasheet says it is a typical figure, not a guaranteed limit. Printed p. 6. |
