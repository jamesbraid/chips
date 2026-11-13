# CRIME 1.5 Specification, revision 0.3: CPU interface and memory controller register map

Transcribed from the specification's text layer (2 June 1997) for the register comparison in
`tools/configs/crime.json`: Table 5-7 on printed page 5-25 and Table 6-12 on printed page 6-30, with the field
tables that follow each (printed pages 5-26 to 5-32 and 6-30 to 6-35). Offsets are byte offsets from the CRIME
register base, physical address 0x14000000. The specification says the CPU interface registers (0x14000000
through 0x14004048) and the memory controller registers can be accessed only with double-word operations.
The rendering engine registers (base 0x15000000) are outside this transcription; the separate graphics workspace
covers them.

The specification places the CPU error status register at 0x4048 for CRIME 1.5 and says that in CRIME 1.1 it
appears at 0x48 (printed page 5-25). The map lists both offsets below, as two rows.

## CPU interface registers

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x0` | CRM_ID | read-only | ID-Revision (Table 5-8, p. 5-26) |
| `0x8` | CRM_CONTROL | read/write | CPU Interface Control (Table 5-9, pp. 5-26 to 5-27) |
| `0x10` | CRM_INTSTAT | read-only | Interrupt Status (Table 5-10, p. 5-28) |
| `0x18` | CRM_INTMASK | read/write | Interrupt Enable (Table 5-11, p. 5-29) |
| `0x20` | CRM_SOFTINT | read/write | Software Interrupt (Table 5-12, p. 5-29) |
| `0x28` | CRM_HARDINT | mixed | Hardware Interrupt (Table 5-13, pp. 5-29 to 5-30) |
| `0x30` | CRM_WATCHDOG | read/write | Watchdog Timer (Table 5-14, p. 5-30) |
| `0x38` | CRM_TIMER | read/write | Crime Timer (Table 5-15, p. 5-31) |
| `0x40` | CRM_CPU_ERROR_ADDR | read-only | CPU Error Address (Table 5-16, p. 5-32) |
| `0x48` | CRM_CPU_ERROR_STAT_1_1 | read/write | CPU/VICE Error Status, CRIME 1.1 location (Table 5-17, p. 5-32) |
| `0x4048` | CRM_CPU_ERROR_STAT | read/write | CPU/VICE Error Status, CRIME 1.5 location (Table 5-17, p. 5-32) |

## Memory controller registers

| Offset | Name | Access | Register title |
|---|---|---|---|
| `0x200` | MC_CONTROL | read/write | MC Status/Control (Table 6-13, p. 6-30) |
| `0x208 to 0x240` | MC_BANK_CONTROL | read/write | Bank 0 to Bank 7 Control (Table 6-14, p. 6-32) |
| `0x248` | MC_REFRESH | read/write | Refresh Counter (Table 6-15, p. 6-32) |
| `0x250` | MC_MEM_ERROR_STAT | read/write | Memory Error Status (Table 6-16, pp. 6-32 to 6-33) |
| `0x258` | MC_MEM_ERROR_ADDR | read-only | Memory Error Address (Table 6-17, p. 6-34) |
| `0x260` | MC_ECC_SYNDROME | read-only | ECC Syndrome Bits (Table 6-18, p. 6-34) |
| `0x268` | MC_ECC_CHECK | read-only | ECC Generated Check Bits (Table 6-19, p. 6-34) |
| `0x270` | MC_ECC_REPLACE | read/write | ECC Replacement Check Bits (Table 6-20, p. 6-35) |
