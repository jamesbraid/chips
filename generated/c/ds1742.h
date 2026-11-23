/* generated from devices/ds1742/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 b5672543306ae2503fda41b02a00f5048d44954b349878d975e681f37ea3002a */
/* Dallas DS1742W nonvolatile timekeeping RAM (Fuel L1 storage part, 3.3 V, 2
 * KiB) */
#ifndef DS1742_GEN_H
#define DS1742_GEN_H

#include <stdint.h>


/*
 * Battery-backed RAM below the clock bytes. The sources give no RAM count and
 * no layout inside it. The 2,040 is inferred from the clock placement, not
 * stated by a source.
 */
/* ram: rw8, space chip, reset unknown */
#define DS1742_RAM_OFFSET                            0x0u /* inferred */
#define DS1742_RAM_COUNT                             2040
#define DS1742_RAM_STRIDE                            1

/*
 * The eight clock and calendar bytes at the top of the chip. Table 2 (p. 5)
 * gives their order and bit meanings, which the device README transcribes; this
 * entry names each byte by offset only.
 */
/* clock: rw8, space chip, reset unknown; Maxim DS1742 Y2KC datasheet 19-6715
 * Rev 6/13, Table 2 register map, p. 5 (clock at 0x7f8 to 0x7ff) */
#define DS1742_CLOCK_OFFSET                          0x7f8u /* established */
#define DS1742_CLOCK_COUNT                           8
#define DS1742_CLOCK_STRIDE                          1

#endif /* DS1742_GEN_H */
