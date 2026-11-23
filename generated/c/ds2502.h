/* generated from devices/ds2502/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 9941eae5ea6d1a9225c3286c2cb883222d28d7bacbc24cc284abb93703acdb6e */
/* Maxim DS2502 1 Kbit add-only 1-Wire memory: ROM, commands, memory layout and
 * timing */
#ifndef DS2502_GEN_H
#define DS2502_GEN_H

#include <stdint.h>


#define DS2502_DS2502_CMD_MATCH_ROM                  0x55u /* established */
#define DS2502_DS2502_CMD_READ_DATA_CRC              0xc3u /* established */
#define DS2502_DS2502_CMD_READ_MEMORY                0xf0u /* established */
#define DS2502_DS2502_CMD_READ_ROM                   0x33u /* established */
#define DS2502_DS2502_CMD_READ_STATUS                0xaau /* established */
#define DS2502_DS2502_CMD_SEARCH_ROM                 0xf0u /* established */
#define DS2502_DS2502_CMD_SKIP_ROM                   0xccu /* established */
#define DS2502_DS2502_CMD_WRITE_MEMORY               0xfu /* established */
#define DS2502_DS2502_CMD_WRITE_STATUS               0x55u /* established */
#define DS2502_DS2502_CRC_INIT                       0x0u /* established */
#define DS2502_DS2502_CRC_POLY                       0x31u /* inferred */
#define DS2502_DS2502_EPROM_BYTES                    0x80u /* established */
#define DS2502_DS2502_FAMILY_CODE                    0x9u /* established */
#define DS2502_DS2502_PAGE_BYTES                     0x20u /* established */
#define DS2502_DS2502_PROGRAM_PULSE_US               0x1e0u /* established */
#define DS2502_DS2502_ROM_BITS                       0x40u /* established */
#define DS2502_DS2502_SERIAL_BITS                    0x30u /* established */
#define DS2502_DS2502_STATUS_BYTES                   0x8u /* established */
#define DS2502_DS2502_STATUS_FACTORY_LAST            0x0u /* established */
#define DS2502_DS2502_T_LOW0_MIN_US                  0x3cu /* established */
#define DS2502_DS2502_T_LOW1_MAX_US                  0xfu /* established */
#define DS2502_DS2502_T_LOW1_MIN_US                  0x1u /* established */
#define DS2502_DS2502_T_PDH_MAX_US                   0x3cu /* established */
#define DS2502_DS2502_T_PDH_MIN_US                   0xfu /* established */
#define DS2502_DS2502_T_PDL_MAX_US                   0xf0u /* established */
#define DS2502_DS2502_T_PDL_MIN_US                   0x3cu /* established */
#define DS2502_DS2502_T_RDV_US                       0xfu /* established */
#define DS2502_DS2502_T_REC_MIN_US                   0x1u /* established */
#define DS2502_DS2502_T_RSTH_MIN_US                  0x1e0u /* established */
#define DS2502_DS2502_T_RSTL_MAX_US                  0x3c0u /* established */
#define DS2502_DS2502_T_RSTL_MIN_US                  0x1e0u /* established */
#define DS2502_DS2502_T_SLOT_MAX_US                  0x78u /* established */
#define DS2502_DS2502_T_SLOT_MIN_US                  0x3cu /* established */

#endif /* DS2502_GEN_H */
