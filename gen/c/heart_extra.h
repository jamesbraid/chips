/* generated from defs/heart_extra.toml by defs-gen - do not edit, change the source */
/* HEART registers outside the census */
#ifndef HEART_GEN_H
#define HEART_GEN_H

#include <stdint.h>


/* sdram_mode: w64, reset unknown */
#define HEART_SDRAM_MODE                             0x000008 /* established */

/* mem_ref: w64, reset unknown */
#define HEART_MEM_REF                                0x000010 /* established */

#define HEART_WIDGET_ERR_LOWER                       0x78u /* established */
#define HEART_WIDGET_ERR_TYPE                        0x60u /* established */
#define HEART_WIDGET_ERR_UPPER                       0x70u /* established */
#define HEART_WIDGET_RD_TIMEOUT_LATCH                0x90u /* established */
#define HEART_WIDGET_REQ_TIMEOUT                     0x28u /* established */

#endif /* HEART_GEN_H */
