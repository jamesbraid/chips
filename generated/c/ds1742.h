/* generated from devices/ds1742/registers.toml by defs-gen - do not edit, change the source */
/* Dallas DS1742W nonvolatile timekeeping RAM (Fuel L1 storage part, 3.3 V, 2 KiB) */
#ifndef DS1742_GEN_H
#define DS1742_GEN_H

#include <stdint.h>


/*
 * Battery-backed RAM below the clock bytes. The sources give no RAM count and no layout inside it. The 2,040 is inferred from the clock placement, not stated by a source.
 */
/* ram: rw8, space chip, reset unknown */
#define DS1742_RAM_OFFSET                            0x0u /* inferred */
#define DS1742_RAM_COUNT                             2040
#define DS1742_RAM_STRIDE                            1

/*
 * The eight clock and calendar bytes at the top of the chip. The sources give their order and bit meanings only through the chip's own register page, which this import did not read, so each byte is named here by offset only.
 */
/* clock: rw8, space chip, reset unknown; Dallas DS1742 datasheet, address map (the chip places the clock bytes at offsets 0x7f8 to 0x7ff) */
#define DS1742_CLOCK_OFFSET                          0x7f8u /* established */
#define DS1742_CLOCK_COUNT                           8
#define DS1742_CLOCK_STRIDE                          1

#endif /* DS1742_GEN_H */
