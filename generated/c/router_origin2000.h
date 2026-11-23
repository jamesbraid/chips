/* generated from devices/router_origin2000/registers.toml by defs-gen - do not
 * edit, change the source */
/* defs-gen 3 */
/* input sha256 55acab457ef018bc4853a2b04d093f28069ad2bb79ae1b72e1c51ad76c5c6feb */
/* network router as the Origin 2000 kernel reaches it (register numbers of a
 * vector access) */
#ifndef ROUTER_ORIGIN2000_GEN_H
#define ROUTER_ORIGIN2000_GEN_H

#include <stdint.h>


/* status_rev_id_led_write_path: rw64, reset unknown; census: 6 sites, 6
 * routines */
/* established */
#define ROUTER_ORIGIN2000_STATUS_REV_ID_LED_WRITE_PATH 0x000000

/* port_status_error: r64, reset unknown; census: 2 sites, 2 routines */
#define ROUTER_ORIGIN2000_PORT_STATUS_ERROR          0x000008 /* established */

/* prot_conf: rw64, reset unknown; census: 2 sites, 1 routines */
#define ROUTER_ORIGIN2000_PROT_CONF                  0x000010 /* established */

/* global_port_def: rw64, reset unknown; census: 4 sites, 2 routines */
#define ROUTER_ORIGIN2000_GLOBAL_PORT_DEF            0x000018 /* established */

/* nic_access: rw64, reset unknown; census: 3 sites, 1 routines */
#define ROUTER_ORIGIN2000_NIC_ACCESS                 0x000038 /* established */

/* port_error_clear: r64, reset unknown; census: 2 sites, 2 routines */
#define ROUTER_ORIGIN2000_PORT_ERROR_CLEAR           0x000088 /* established */

#endif /* ROUTER_ORIGIN2000_GEN_H */
