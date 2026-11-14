/* generated from devices/hub_windows/registers.toml by defs-gen - do not edit, change the source */
/* Hub register arrays whose extent is a fact of its own */
#ifndef HUB_WIN_GEN_H
#define HUB_WIN_GEN_H

#include <stdint.h>


/*
 * The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then the same five for slot B. The source gives the distance between the two sets as the offset of the slot B page from the slot A page. The entries are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data.
 */
/* pi_gfx_window: rw64, reset 0x0 */
#define HUB_WIN_PI_GFX_WINDOW                        0x000300 /* established */
#define HUB_WIN_PI_GFX_WINDOW_COUNT                  10
#define HUB_WIN_PI_GFX_WINDOW_STRIDE                 8

/*
 * The sixteen microcontroller and UART 1 registers as one array. They are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data. On the Origin 200 (the SN00 variant) the kernel's per-processor LED macro writes the LED of slice 0 at element 0 and the LED of slice 1 at element 4, a spacing of four elements per slice; other Hub variants use the separate LED registers. The IRIX register table gives read and write access for the entries it lists (0, 1 and 15) and the header gives all sixteen the same description.
 */
/* md_ureg1: rw64, reset unknown */
#define HUB_WIN_MD_UREG1                             0x220080 /* established */
#define HUB_WIN_MD_UREG1_COUNT                       16
#define HUB_WIN_MD_UREG1_STRIDE                      8

#endif /* HUB_WIN_GEN_H */
