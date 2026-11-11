/*
 * xbow_extra.h - Xbow registers outside the census
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Sources: the kernel's counter routines (performance counters), the published Crossbow specification rev 12.0 register map (flush registers; no shipped software is seen using them), the identification word and revision tables of the shipped crossbar driver and header, and one measurement of the reset fences and resource lock on an Octane2 after its PROM ran (docs/xbow-family.md).
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

/* Identification word (offset 0, 32-bit access at slot+4): bits 31:28 revision, 27:12 part, 11:1 manufacturer, bit 0 always set. */
#define XBOW_ID_REV_MASK                     0xf0000000 /* [E] revision field, bits 31:28 */
#define XBOW_ID_PART_MASK                    0x0ffff000 /* [E] part field, bits 27:12 */
#define XBOW_ID_MFR_MASK                     0x00000ffe /* [E] manufacturer field, bits 11:1 */
#define XBOW_PART_XBOW                       0x0000     /* [E] Crossbow; manufacturer 0 */
#define XBOW_PART_XXBOW                      0xd000     /* [E] part value in the shipped crossbar header, the public Linux crossbar probe file and OpenBSD; "the crossbar of the Xbridge" is [I] (Linux comment only) */
#define XBOW_PART_PXBOW                      0xd100     /* [E] part value in the same three sources; "the crossbar face of the PIC" is [I] */
/* Revision codes, bits 31:28; the label differs by source (the Octane2 PROM banner prints 1.4 for code 5). */
#define XBOW_REV_CODE_1                      0x1        /* [E] header name 1.0 */
#define XBOW_REV_CODE_2                      0x2        /* [E] header name 1.1; no name-table entry in the kernel object. Origin 300 and Fuel captures print revision 2 beside part 0xd000 [E] */
#define XBOW_REV_CODE_3                      0x3        /* [E] header name 1.2. Origin 350 captures print "XBOW Rev 3" [E]; which part that unit reports is [I] (captures do not print it) */
#define XBOW_REV_CODE_4                      0x4        /* [E] header name 1.3 */
#define XBOW_REV_CODE_5                      0x5        /* [E] header name 2.0; the Octane2 PROM labels it 1.4 */

/* Reset fences and resource lock, code-5 Crossbows only. Measured on one Octane2 after the PROM ran; no shipped
 * software is seen using them, so the roles are [I] (the names here are descriptive, taken from no source) and power-on values
 * are [U]: settle by reading each from a PROM monitor immediately after reset on a halted early boot. */
#define XBOW_FENCE_WIDGET_0                  0x000078   /* [I] existence and read value 0xf7 measured on one Octane2 [E as an observation only]; role inferred; reset value [U] */
#define XBOW_FENCE_LINK_8                    0x000080   /* [I] offsets 0x80 to 0xb8 step 8 are the reset fences for links 8 to F; xbow.h carries the same slots as XBOW_RESERVED_* with write sites [E] */
#define XBOW_FENCE_LINK_9                    0x000088   /* [I] as above */
#define XBOW_FENCE_LINK_A                    0x000090   /* [I] as above */
#define XBOW_FENCE_LINK_B                    0x000098   /* [I] as above */
#define XBOW_FENCE_LINK_C                    0x0000a0   /* [I] as above */
#define XBOW_FENCE_LINK_D                    0x0000a8   /* [I] as above */
#define XBOW_FENCE_LINK_E                    0x0000b0   /* [I] as above */
#define XBOW_FENCE_LINK_F                    0x0000b8   /* [I] as above */
#define XBOW_RESOURCE_LOCK                   0x0000c0   /* [I] read value 0 measured on one Octane2 after the PROM ran; acquire and release behaviour [I]; reset value [U] */
#define XBOW_RESOURCE_LOCK_CLEAR             0x0000c8   /* [I] lock clear, as above */

#endif /* XBOW_EXTRA_H */
