/* generated from defs/isp12160.toml by defs-gen - do not edit, change the source */
/* QLogic ISP12160 dual-channel Ultra2 SCSI host adapter (PCI 1077:1216), the constants the held sources establish */
#ifndef ISP12160_GEN_H
#define ISP12160_GEN_H

#include <stdint.h>


#define ISP12160_BUSES                               0x2u /* established */
#define ISP12160_BUS_RESET_DELAY_DEFAULT_S           0x5u /* established */
#define ISP12160_BUS_RESET_DELAY_MAX_S               0xfu /* established */
#define ISP12160_CONTROLLER_PROGRAM_WORDS            0x361du /* inferred */
#define ISP12160_DRIVER_SELECTION_TIMEOUT_DEFAULT    0xfau /* inferred */
#define ISP12160_OP_ABORT_DEVICE                     0x16u /* inferred */
#define ISP12160_OP_BUS_RESET                        0x18u /* inferred */
#define ISP12160_OP_DUMP_RAM                         0x3u /* inferred */
#define ISP12160_OP_LOAD_RAM                         0x1u /* inferred */
#define ISP12160_OP_SET_SELECTION_TIMEOUT            0x31u /* inferred */
#define ISP12160_PCI_BUS_WIDTH_BITS                  0x40u /* established */
#define ISP12160_PCI_CLOCK_MHZ                       0x42u /* established */
#define ISP12160_PCI_DEVICE_ID                       0x1216u /* established */

#endif /* ISP12160_GEN_H */
