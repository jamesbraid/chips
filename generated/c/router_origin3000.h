/* generated from devices/router_origin3000/registers.toml by defs-gen - do not
 * edit, change the source */
/* defs-gen 4 */
/* input sha256 f05ec3257a5dd901126db53badb95885bd988bb22c6f7690f241e3c347fa3a6a */
/* network router as the Origin 3000 kernel reaches it (register numbers of a
 * vector access) */
#ifndef ROUTER_ORIGIN3000_GEN_H
#define ROUTER_ORIGIN3000_GEN_H

#include <stdint.h>


/* status_rev_id: r64, reset unknown; census: 4 sites, 4 routines */
#define ROUTER_ORIGIN3000_STATUS_REV_ID              0x000000 /* established */

/* port_status_error: r64, reset unknown; census: 3 sites, 3 routines */
#define ROUTER_ORIGIN3000_PORT_STATUS_ERROR          0x000008 /* established */

/* prot_conf: rw64, reset unknown; census: 2 sites, 1 routines */
#define ROUTER_ORIGIN3000_PROT_CONF                  0x000010 /* established */

/* port_reset_mask: rw64, reset unknown; census: 2 sites, 1 routines */
#define ROUTER_ORIGIN3000_PORT_RESET_MASK            0x000018 /* established */

/* global_parms0: rw64, reset unknown; census: 2 sites, 1 routines */
#define ROUTER_ORIGIN3000_GLOBAL_PARMS0              0x000020 /* established */

/* global_parms1: rw64, reset unknown; census: 2 sites, 1 routines */
#define ROUTER_ORIGIN3000_GLOBAL_PARMS1              0x000028 /* established */

/* port_error_clear: r64, reset unknown; census: 1 sites, 1 routines */
#define ROUTER_ORIGIN3000_PORT_ERROR_CLEAR           0x000088 /* established */

/* jbus0_0: w64, reset unknown; census: 1 sites, 1 routines */
#define ROUTER_ORIGIN3000_JBUS0_0                    0x000200 /* established */

#endif /* ROUTER_ORIGIN3000_GEN_H */
