/*
 * router_origin3000_extra.h - Network router registers outside the census (Origin 3000 kernel)
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Source: the Origin 3000 brick-controller UART routines, which use the second bank as a UART register file, data first and line status last. Register numbers of a vector access, as in router_origin3000.h; the console-UART role is [I].
 */
#ifndef ROUTER_ORIGIN3000_EXTRA_H
#define ROUTER_ORIGIN3000_EXTRA_H

#define ROUTER_ORIGIN3000_JBUS1_0            0x000240   /* [E] width 8 byte(s), access rw; name [I] from the public Linux router header */
#define ROUTER_ORIGIN3000_JBUS1_1            0x000248   /* [E] width 8 byte(s), access rw; name [I] from the public Linux router header */
#define ROUTER_ORIGIN3000_JBUS1_2            0x000250   /* [E] width 8 byte(s), access rw; name [I] from the public Linux router header */
#define ROUTER_ORIGIN3000_JBUS1_3            0x000258   /* [E] width 8 byte(s), access rw; name [I] from the public Linux router header */
#define ROUTER_ORIGIN3000_JBUS1_4            0x000260   /* [E] width 8 byte(s), access rw; name [I] from the public Linux router header */
#define ROUTER_ORIGIN3000_JBUS1_5            0x000268   /* [E] width 8 byte(s), access rw; name [I] from the public Linux router header */

#endif /* ROUTER_ORIGIN3000_EXTRA_H */
