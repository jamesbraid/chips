/*
 * ioc4_extra.h - IOC4 registers outside the census
 *
 * Written by hand, not generated: the census cannot reach these, so gen_headers.py never emits them and does not
 * overwrite this file. Same label convention as the generated headers: [E] established, [I] inferred, [U] unknown.
 * Source: the Origin 3000 kernel's keyboard poll routine, which indexes the words by port.
 */
#ifndef IOC4_EXTRA_H
#define IOC4_EXTRA_H

#define IOC4_KM_RX_KBD                       0x000204   /* [E] width 4 byte(s), access r; keyboard receive */
#define IOC4_KM_RX_MOUSE                     0x000208   /* [E] width 4 byte(s), access r; mouse receive */
#define IOC4_KM_TX_KBD                       0x00020c   /* [E] width 4 byte(s), access w; keyboard transmit */
#define IOC4_KM_TX_MOUSE                     0x000210   /* [E] width 4 byte(s), access w; mouse transmit */

#endif /* IOC4_EXTRA_H */
