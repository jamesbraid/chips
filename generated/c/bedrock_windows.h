/* generated from devices/bedrock_windows/registers.toml by defs-gen - do not
 * edit, change the source */
/* defs-gen 3 */
/* input sha256 4ce22aad6bef30dbc9d45d94765826ca9936e0ce29420eac7da13078ea7efa6d */
/* Bedrock register arrays whose extent is a fact of its own */
#ifndef BEDROCK_WIN_GEN_H
#define BEDROCK_WIN_GEN_H

#include <stdint.h>


/*
 * The graphics registers of both processor slots as one window: page, credit
 * counter, bias, interrupt counter and interrupt comparator for slot A, then
 * the same five for slot B. The entries are also listed one by one under their
 * own names; this is the same storage seen as an array, so that its extent is
 * data. The entries have different reset values, so the window has none.
 */
/* gfx_window: rw64, reset unknown */
#define BEDROCK_WIN_GFX_WINDOW                       0x000300 /* established */
#define BEDROCK_WIN_GFX_WINDOW_COUNT                 10
#define BEDROCK_WIN_GFX_WINDOW_STRIDE                8

#endif /* BEDROCK_WIN_GEN_H */
