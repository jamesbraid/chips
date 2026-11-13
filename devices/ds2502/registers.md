<!-- generated from devices/ds2502/registers.toml by defs-gen - do not edit, change the source -->

# Maxim DS2502 1 Kbit add-only 1-Wire memory: ROM, commands, memory layout and timing

The add-only 1-Wire part with a factory-lasered 64-bit ROM, 128 bytes of EPROM in four 32-byte pages and eight status bytes. This unit holds the constants only: the family code, sizes, the CRC polynomial, the command opcodes and the published timing windows. Grades: established means the manufacturer datasheet states the value; inferred means arithmetic on a stated value. The part fitted to any SGI board, and its contents, are not stated by the datasheet and are not listed here.

Unit `ds2502`, macro prefix `DS2502`.
Default source: Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `DS2502_CMD_MATCH_ROM` | 0x55 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | ROM command before selection: match the following 64-bit ROM. After selection the same opcode is Write Status. |
| `DS2502_CMD_READ_DATA_CRC` | 0xc3 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Memory command: read data with a CRC after each 32-byte page. |
| `DS2502_CMD_READ_MEMORY` | 0xf0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Memory command after ROM selection: read from a 16-bit address. The same opcode is Search ROM before selection. |
| `DS2502_CMD_READ_ROM` | 0x33 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | ROM command: read the family code, serial number and CRC. Valid only when one slave is on the bus. |
| `DS2502_CMD_READ_STATUS` | 0xaa | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Memory command: read the status memory, ending with a CRC over the bytes read. |
| `DS2502_CMD_SEARCH_ROM` | 0xf0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | ROM command before selection: enumerate the ROM codes of all slaves. After selection the same opcode is Read Memory. |
| `DS2502_CMD_SKIP_ROM` | 0xcc | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | ROM command: select every slave for the next memory command, without a ROM sequence. |
| `DS2502_CMD_WRITE_MEMORY` | 0xf | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Memory command: write one byte to the scratchpad and program it. Programming is outside the read-only contract. |
| `DS2502_CMD_WRITE_STATUS` | 0x55 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Memory command after ROM selection: program one status byte. The same opcode is Match ROM before selection. |
| `DS2502_CRC_INIT` | 0x0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Initial value of the CRC-8 accumulator for the ROM and for the command, address and data CRCs. |
| `DS2502_CRC_POLY` | 0x31 | inferred | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | The CRC-8 polynomial x^8 + x^5 + x^4 + 1 written with its x^8 term implied: bits 5, 4 and 0. The datasheet gives the polynomial; the byte form is arithmetic on it. The CRC register starts at zero and each bit is shifted in least significant bit first. |
| `DS2502_EPROM_BYTES` | 0x80 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Add-only data memory: 1024 bits, addresses 0x0000 to 0x007f. Programming can only change a bit from 1 to 0. |
| `DS2502_FAMILY_CODE` | 0x9 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | The 8-bit family code, the lowest byte of the 64-bit ROM, sent first in a Read ROM response. It identifies the part to a reader. |
| `DS2502_PAGE_BYTES` | 0x20 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Size of one EPROM page. Four pages make up the data memory. Read Data with CRC emits a CRC at the end of each page. |
| `DS2502_PROGRAM_PULSE_US` | 0x1e0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Length of the 12-volt programming pulse on the bus that copies scratchpad data into the EPROM or status memory. The pulse needs at least 10 mA of supply current. Programming is outside the read-only contract. |
| `DS2502_ROM_BITS` | 0x40 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Bits in the factory ROM: the family code (8), a unique 48-bit serial number and an 8-bit CRC of the first 56 bits. |
| `DS2502_SERIAL_BITS` | 0x30 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Width of the unique serial number between the family code and the ROM CRC. |
| `DS2502_STATUS_BYTES` | 0x8 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Bytes of status memory, 64 bits. The first seven are programmable from 1 to 0; the eighth is factory-programmed to 0x00. |
| `DS2502_STATUS_FACTORY_LAST` | 0x0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Factory value of status byte 7, the eighth status byte. It is the only status byte with a stated factory value. |
| `DS2502_T_LOW0_MIN_US` | 0x3c | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Master low time for a write-zero: at least 60 us, held until the slot ends. |
| `DS2502_T_LOW1_MAX_US` | 0xf | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Master low time for a write-one or a read slot start: less than 15 us. |
| `DS2502_T_LOW1_MIN_US` | 0x1 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Master low time for a write-one or a read slot start: at least 1 us. |
| `DS2502_T_PDH_MAX_US` | 0x3c | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Presence detect delay: less than 60 us. |
| `DS2502_T_PDH_MIN_US` | 0xf | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Presence detect delay after the master releases the line: at least 15 us. |
| `DS2502_T_PDL_MAX_US` | 0xf0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Presence pulse low time: less than 240 us. |
| `DS2502_T_PDL_MIN_US` | 0x3c | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Presence pulse low time: at least 60 us. |
| `DS2502_T_RDV_US` | 0xf | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Read data valid: the slave's read bit is valid 15 us after the slot starts. |
| `DS2502_T_REC_MIN_US` | 0x1 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Recovery time between slots: at least 1 us. |
| `DS2502_T_RSTH_MIN_US` | 0x1e0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Master high time after a reset pulse, including recovery: at least 480 us. |
| `DS2502_T_RSTL_MAX_US` | 0x3c0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Master reset pulse, low time: less than 960 us. The datasheet's timing table gives this maximum. |
| `DS2502_T_RSTL_MIN_US` | 0x1e0 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Master reset pulse, low time: at least 480 us. |
| `DS2502_T_SLOT_MAX_US` | 0x78 | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Time slot length: less than 120 us. |
| `DS2502_T_SLOT_MIN_US` | 0x3c | established | Maxim DS2502 1Kb Add-Only Memory datasheet, document 19-5075, revision 12/11 | Time slot length: at least 60 us. |
