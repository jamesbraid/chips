/* generated from devices/heart/registers-extra.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 189e7fa9ecefa172f0e241d791ba09c972fbdd69db03706a5ac043de76587a1e */
/* HEART registers outside the census */
#ifndef HEART_GEN_H
#define HEART_GEN_H

#include <stdint.h>


/* sdram_mode: w64, reset unknown */
#define HEART_SDRAM_MODE                             0x000008 /* established */

/* mem_ref: w64, reset unknown */
#define HEART_MEM_REF                                0x000010 /* established */

/* mlan_ctl: rw64, reset unknown; OpenBSD SGI Crossbow HEART driver at
 * 7011342f6a72: one 64-bit uncached access per pulse, no other user */
#define HEART_MLAN_CTL                               0x0000b8 /* inferred */

#define HEART_MEMCFG_ADDR_MASK                       0x1ffu /* inferred */
#define HEART_MEMCFG_SIZE_MASK                       0x3f0000u /* inferred */
#define HEART_MEMCFG_SIZE_SHIFT                      0x10u /* inferred */
#define HEART_MEMCFG_UNIT_SHIFT                      0x19u /* inferred */
#define HEART_MEMCFG_VALID                           0x80000000u /* inferred */
#define HEART_MLAN_DATA_SHIFT                        0x2u /* inferred */
#define HEART_MLAN_DONE                              0x2u /* inferred */
#define HEART_MLAN_PULSE_SHIFT                       0xau /* inferred */
#define HEART_MLAN_SAMPLE                            0x1u /* inferred */
#define HEART_WIDGET_ERR_LOWER                       0x78u /* established */
#define HEART_WIDGET_ERR_TYPE                        0x60u /* established */
#define HEART_WIDGET_ERR_UPPER                       0x70u /* established */
#define HEART_WIDGET_RD_TIMEOUT_LATCH                0x90u /* established */
#define HEART_WIDGET_REQ_TIMEOUT                     0x28u /* established */

#endif /* HEART_GEN_H */
