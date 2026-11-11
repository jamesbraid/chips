/*
 * ioc3_extra.h - IOC3 registers outside the census
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Source: the Origin 2000 kernel's one-wire, parallel-port and keyboard routines, read in full. The count-word flags and the control-word bits are [I] on the chip page and are not stated here.
 */
#ifndef IOC3_EXTRA_H
#define IOC3_EXTRA_H

#define IOC3_ONE_WIRE_CTL                    0x000030   /* [E] width 4 byte(s), access rw; name [I] */
#define IOC3_PLP_A_ADDR_HI                   0x000080   /* [E] width 4 byte(s), access rw; parallel-port DMA context A buffer address, upper half */
#define IOC3_PLP_A_ADDR_LO                   0x000084   /* [E] width 4 byte(s), access rw; context A buffer address, lower half */
#define IOC3_PLP_A_COUNT                     0x000088   /* [E] width 4 byte(s), access rw; context A count and flags (flag names [I]) */
#define IOC3_PLP_CTL                         0x00008c   /* [E] width 4 byte(s), access rw; DMA control (bit meanings [I]) */
#define IOC3_PLP_B_ADDR_HI                   0x000090   /* [E] width 4 byte(s), access rw; context B buffer address, upper half */
#define IOC3_PLP_B_ADDR_LO                   0x000094   /* [E] width 4 byte(s), access rw; context B buffer address, lower half */
#define IOC3_PLP_B_COUNT                     0x000098   /* [E] width 4 byte(s), access rw; context B count and flags (flag names [I]) */
#define IOC3_KM_RX_KBD                       0x0000a0   /* [E] width 4 byte(s), access r; keyboard receive */
#define IOC3_KM_RX_MOUSE                     0x0000a4   /* [E] width 4 byte(s), access r; mouse receive */
#define IOC3_KM_TX_KBD                       0x0000a8   /* [E] width 4 byte(s), access w; keyboard transmit */
#define IOC3_KM_TX_MOUSE                     0x0000ac   /* [E] width 4 byte(s), access w; mouse transmit */

#endif /* IOC3_EXTRA_H */
