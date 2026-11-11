/*
 * heart_extra.h - HEART registers outside the census
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Source: the Octane PROM's memory set-up; the roles (SDRAM mode word, refresh interval) are inferred on the chip page and not stated here.
 */
#ifndef HEART_EXTRA_H
#define HEART_EXTRA_H

#define HEART_SDRAM_MODE                     0x000008   /* [E] width 8 byte(s), access w; eight doubleword stores in a loop; name [I] from the public Linux driver; role [I] */
#define HEART_MEM_REF                        0x000010   /* [E] width 8 byte(s), access w; one doubleword store right after that loop; name [I] from the public Linux driver; role [I] */

#endif /* HEART_EXTRA_H */
