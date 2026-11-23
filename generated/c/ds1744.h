/* generated from devices/ds1744/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 b5d17eac59842695d624daaad596f06b877f17bfefcdbbe686446be878c5d4fe */
/* Dallas DS1744 nonvolatile timekeeping SRAM (32 KiB, byte-wide, with clock) */
#ifndef DS1744_GEN_H
#define DS1744_GEN_H

#include <stdint.h>


/*
 * Battery-backed RAM below the clock bytes. The sources give no layout inside
 * it. The 32,760 is inferred from the clock placement, not stated by a source.
 */
/* ram: rw8, space chip1744, reset unknown */
#define DS1744_RAM_OFFSET                            0x0u /* inferred */
#define DS1744_RAM_COUNT                             32760
#define DS1744_RAM_STRIDE                            1

/*
 * The eight clock and calendar bytes at the top of the chip. The sources give
 * their order and bit meanings only through the chip's own register page, which
 * this import did not read, so each byte is named here by position only.
 */
/* clock: rw8, space chip1744, reset unknown */
#define DS1744_CLOCK_OFFSET                          0x7ff8u /* established */
#define DS1744_CLOCK_COUNT                           8
#define DS1744_CLOCK_STRIDE                          1

#endif /* DS1744_GEN_H */
