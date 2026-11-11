/*
 * xbow_extra.h - Xbow registers outside the census
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Sources: the kernel's counter routines (performance counters) and the published Crossbow specification rev 12.0 register map (flush registers; no shipped software is seen using them).
 */
#ifndef XBOW_EXTRA_H
#define XBOW_EXTRA_H

#define XBOW_PERF_A                          0x000060   /* [E] width 4 byte(s), access rw; bits 19:0 count, bits 22:20 link select */
#define XBOW_PERF_A_B_19_0                   0xfffff   /* [E] count field */
#define XBOW_PERF_A_B_22_20                  0x700000   /* [E] link select field */
#define XBOW_PERF_B                          0x000068   /* [E] width 4 byte(s), access rw; same layout as counter A */
#define XBOW_PERF_B_B_19_0                   0xfffff   /* [E] count field */
#define XBOW_PERF_B_B_22_20                  0x700000   /* [E] link select field */
/* Link input buffer flush, one read-only register per link 8 to 15, 0x40 apart. A read returns 0 when the flush
 * finished and 1 when another flush is already running and this one was refused. Offsets and access are from the
 * specification register map; the width is not stated there, so it is [I] (32 bits, as the other Xbow registers). */
#define XBOW_FLUSH_LINK_8                    0x000100   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */
#define XBOW_FLUSH_LINK_9                    0x000140   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */
#define XBOW_FLUSH_LINK_A                    0x000180   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */
#define XBOW_FLUSH_LINK_B                    0x0001c0   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */
#define XBOW_FLUSH_LINK_C                    0x000200   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */
#define XBOW_FLUSH_LINK_D                    0x000240   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */
#define XBOW_FLUSH_LINK_E                    0x000280   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */
#define XBOW_FLUSH_LINK_F                    0x0002c0   /* [E] offset and read-only access from the specification; width 4 byte(s) [I] */

#endif /* XBOW_EXTRA_H */
