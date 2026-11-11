/*
 * heart_extra.h - HEART registers outside the census
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Sources: the Octane PROM's memory set-up (the two registers just below, processor-interface block); the roles (SDRAM mode word, refresh interval) are inferred on the chip page and not stated here.
 */
#ifndef HEART_EXTRA_H
#define HEART_EXTRA_H

#define HEART_SDRAM_MODE                     0x000008   /* [E] width 8 byte(s), access w; eight doubleword stores in a loop; name [I] from the public Linux driver; role [I] */
#define HEART_MEM_REF                        0x000010   /* [E] width 8 byte(s), access w; one doubleword store right after that loop; name [I] from the public Linux driver; role [I] */

/* HEART widget face: a separate window from the processor-interface block above, offsets relative to the widget
 * face base. Eight-byte slots; the common Crosstalk registers hold 32-bit values in the low half. Names are from the
 * monitor decode table and the public Linux and OpenBSD headers; the table of error-type bit names and the latch
 * layouts are in docs/crosstalk-host-ends.md. The error type and mask slots here are unrelated to the same-numbered slots of
 * the processor-interface block. */
#define HEART_WIDGET_REQ_TIMEOUT             0x000028   /* [E] value 0x28 (40) read from one Octane2 by its owner, the 32-bit value in the low half of the slot; kernel stores of 40000 and 128 reach it through a pointer and the destination is [I]; tick unit [U]: settle by a timed uncached read of an unclaimed widget address at two programmed values (hardware) */
#define HEART_WIDGET_ERR_TYPE                0x000060   /* [E] widget error type; bit names [E] from the monitor table; kernel writes back the value it read, clear rule [I]; bits 0 and 10, 11 meaning [U] */
#define HEART_WIDGET_ERR_UPPER               0x000070   /* [E] failed PIO latch, upper: bits 7:0 address 39:32, 23:22 processor, 15 read/write flag (sense [I]); cleared with the error type [I] */
#define HEART_WIDGET_ERR_LOWER               0x000078   /* [E] failed PIO latch, lower: address 31:0 */
#define HEART_WIDGET_RD_TIMEOUT_LATCH        0x000090   /* [E] PIO read-timeout latch: bits 19:18 processor, 15:12 widget port, 11:0 address bits 23:12 */

#endif /* HEART_EXTRA_H */
