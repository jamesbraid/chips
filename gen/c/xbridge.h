/* generated from defs/bridge.xbridge.toml by defs-gen - do not edit, change the source */
/* XBridge (XIO-to-PCI bridge, later), Origin 2000 and Octane */
#ifndef XBRIDGE_GEN_H
#define XBRIDGE_GEN_H

#include <stdint.h>


/* wid_id: r32, reset unknown; census: 14 sites, 3 routines */
#define XBRIDGE_WID_ID                               0x000000 /* established */

/* wid_stat: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_WID_STAT                             0x000008 /* established */

/* wid_err_upper: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_WID_ERR_UPPER                        0x000010 /* established */

/* wid_err_lower: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_WID_ERR_LOWER                        0x000018 /* established */

/* wid_control: rw32, reset unknown; census: 45 sites, 6 routines */
#define XBRIDGE_WID_CONTROL                          0x000020 /* established */

/* wid_req_timeout: rw32, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_WID_REQ_TIMEOUT                      0x000028 /* established */

/* wid_int_upper: rw32, reset unknown; census: 39 sites, 7 routines */
#define XBRIDGE_WID_INT_UPPER                        0x000030 /* established */

/* wid_int_lower: rw32, reset unknown; census: 15 sites, 5 routines */
#define XBRIDGE_WID_INT_LOWER                        0x000038 /* established */

/* wid_err_cmdword: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_WID_ERR_CMDWORD                      0x000040 /* established */

/* wid_llp: rw32, reset unknown; census: 15 sites, 2 routines */
#define XBRIDGE_WID_LLP                              0x000048 /* established */

/* wid_tflush: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_WID_TFLUSH                           0x000050 /* established */

/* wid_aux_err: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_WID_AUX_ERR                          0x000058 /* established */

/* wid_resp_upper: r32, reset unknown; census: 12 sites, 4 routines */
#define XBRIDGE_WID_RESP_UPPER                       0x000060 /* established */

/* wid_resp_lower: r32, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_WID_RESP_LOWER                       0x000068 /* established */

/* dir_map: rw32, reset unknown; census: 42 sites, 6 routines */
#define XBRIDGE_DIR_MAP                              0x000080 /* established */

/* ram_perr_or_map_fault: r32, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_RAM_PERR_OR_MAP_FAULT                0x000090 /* established */

/* arb: rw32, reset unknown; census: 18 sites, 4 routines */
#define XBRIDGE_ARB                                  0x0000a0 /* established */

/* bus_timeout: rw32, reset unknown; census: 18 sites, 4 routines */
#define XBRIDGE_BUS_TIMEOUT                          0x0000c0 /* established */

/* pci_cfg: rw32, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_PCI_CFG                              0x0000c8 /* established */

/* pci_err_upper: r32, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_PCI_ERR_UPPER                        0x0000d0 /* established */

/* pci_err_lower: r32, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_PCI_ERR_LOWER                        0x0000d8 /* established */

/* int_status: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_INT_STATUS                           0x000100 /* established */

/* int_enable: rw32, reset unknown; census: 18 sites, 4 routines */
#define XBRIDGE_INT_ENABLE                           0x000108 /* established */

/* int_rst_stat: rw32, reset unknown; census: 9 sites, 2 routines */
#define XBRIDGE_INT_RST_STAT                         0x000110 /* established */

/* int_mode: rw32, reset unknown; census: 18 sites, 4 routines */
#define XBRIDGE_INT_MODE                             0x000118 /* established */

/* int_device: rw32, reset unknown; census: 18 sites, 4 routines */
#define XBRIDGE_INT_DEVICE                           0x000120 /* established */

/* int_host_err: rw32, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_INT_HOST_ERR                         0x000128 /* established */

/* int_addr: rw32, reset unknown; census: 36 sites, 6 routines */
#define XBRIDGE_INT_ADDR                             0x000130 /* established */

/* int_view: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_INT_VIEW                             0x000170 /* established */

/* int_multiple: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_INT_MULTIPLE                         0x000178 /* established */

/* int_force_always: w32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_INT_FORCE_ALWAYS                     0x000180 /* established */

/* int_force_pin: w32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_INT_FORCE_PIN                        0x0001c0 /* established */

/* device: rw32, reset unknown; census: 18 sites, 4 routines */
#define XBRIDGE_DEVICE                               0x000200 /* established */

/* wr_req_buf: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_WR_REQ_BUF                           0x000240 /* established */

/* rrb_map: rw32, reset unknown; census: 30 sites, 4 routines */
#define XBRIDGE_RRB_MAP                              0x000280 /* established */

/* resp_status: r32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_RESP_STATUS                          0x000290 /* established */

/* resp_clear: w32, reset unknown; census: 3 sites, 1 routines */
#define XBRIDGE_RESP_CLEAR                           0x000298 /* established */

/* int_ate_ram: rw64, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_INT_ATE_RAM                          0x010000 /* established */

/* ext_ate_ram: rw64, reset unknown; census: 6 sites, 2 routines */
#define XBRIDGE_EXT_ATE_RAM                          0x080000 /* established */

#define XBRIDGE_INT_ADDR_B_10_0                      0x7ffu /* inferred */
#define XBRIDGE_INT_ADDR_B_7_0                       0xffu /* inferred */
#define XBRIDGE_INT_ATE_RAM_B_10_0                   0x7ffu /* inferred */
#define XBRIDGE_RRB_MAP_B_10_0                       0x7ffu /* inferred */
#define XBRIDGE_WID_CONTROL_B_5_4                    0x30u /* inferred */
#define XBRIDGE_WID_ID_B_10_0                        0x7ffu /* inferred */
#define XBRIDGE_WID_ID_B_15_0                        0xffffu /* inferred */
#define XBRIDGE_WID_INT_UPPER_B_5_0                  0x3fu /* inferred */

#endif /* XBRIDGE_GEN_H */
