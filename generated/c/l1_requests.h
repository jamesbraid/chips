/* generated from formats/l1_requests/format.toml by defs-gen - do not edit, change the source */
/* request codes the Origin 3000 kernel sends to the brick controller */
#ifndef L1_GEN_H
#define L1_GEN_H

#include <stdint.h>


#define L1_REQ_ELSC_CONS_NODE                        0x1003u /* established */
#define L1_REQ_ELSC_CONS_SUBCH                       0x1002u /* established */
#define L1_REQ_ELSC_DEBUG_GET                        0x1u /* established */
#define L1_REQ_ELSC_DISPLAY_LINE_1                   0x1004u /* established */
#define L1_REQ_ELSC_DISPLAY_LINE_2                   0x1005u /* established */
#define L1_REQ_ELSC_EVT_UNREG                        0x100au /* established */
#define L1_REQ_ELSC_LED_SET                          0x1009u /* established */
#define L1_REQ_ELSC_ODY_EXPANDER_GET                 0x2007u /* established */
#define L1_REQ_ELSC_ODY_EXPANDER_SET                 0x2008u /* established */
#define L1_REQ_ELSC_PARTITION_GET                    0x9u /* established */
#define L1_REQ_ELSC_PARTITION_SET                    0x1006u /* established */
#define L1_REQ_ELSC_PWR_CYCLE                        0x2006u /* established */
#define L1_REQ_ELSC_PWR_OFF                          0x2005u /* established */
#define L1_REQ_ELSC_SLAB_GET                         0xeu /* established */
#define L1_REQ_ELSC_SYSTEM_RESET                     0x2001u /* established */
#define L1_REQ_IOBRICK_ATTACHED_BRICKS               0xcu /* established */
#define L1_REQ_IOBRICK_GET_SYS_SNUM                  0x8u /* established */
#define L1_REQ_RACK_BAY_TYPE_GET                     0x3u /* established */
#define L1_REQ_SC_COMMAND_INTERP                     0x0u /* established */
#define L1_REQ_SC_PORTSPEED_GET                      0xau /* established */
#define L1_REQ_SC_SET_SYSTEM_STATE                   0x100cu /* established */
#define L1_REQ_SC_VERSION                            0x5u /* established */

#endif /* L1_GEN_H */
