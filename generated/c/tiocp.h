/* generated from devices/tiocp/registers.toml by defs-gen - do not edit, change the source */
/* TIOCP (PCI-X bridge, later family), as the Origin 3000 family Bridge driver reaches it */
#ifndef TIOCP_GEN_H
#define TIOCP_GEN_H

#include <stdint.h>


/* id: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_ID                                     0x000000 /* established */

/* bus_err: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_BUS_ERR                                0x000018 /* established */

/* ssram_size: rw64, reset unknown; census: 25 sites, 6 routines */
#define TIOCP_SSRAM_SIZE                             0x000020 /* established */

/* req_timeout: rw64, reset unknown; census: 2 sites, 2 routines */
#define TIOCP_REQ_TIMEOUT                            0x000028 /* established */

/* intr_dst_target_id: rw64, reset unknown; census: 17 sites, 6 routines */
#define TIOCP_INTR_DST_TARGET_ID                     0x000038 /* established */

/* cmdword_err: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_CMDWORD_ERR                            0x000040 /* established */

/* tflush: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_TFLUSH                                 0x000050 /* established */

/* linkside_err: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_LINKSIDE_ERR                           0x000058 /* established */

/* resp_err_buf: r64, reset unknown; census: 2 sites, 2 routines */
#define TIOCP_RESP_ERR_BUF                           0x000060 /* established */

/* resp_err_addr: r64, reset unknown; census: 3 sites, 2 routines */
#define TIOCP_RESP_ERR_ADDR                          0x000068 /* established */

/* linkside_err_addr: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_LINKSIDE_ERR_ADDR                      0x000078 /* established */

/* dirmap_diroff: rw64, reset unknown; census: 18 sites, 6 routines */
#define TIOCP_DIRMAP_DIROFF                          0x000080 /* established */

/* ssram_parity: r64, reset unknown; census: 2 sites, 2 routines */
#define TIOCP_SSRAM_PARITY                           0x000090 /* established */

/* arbitration: rw64, reset unknown; census: 6 sites, 4 routines */
#define TIOCP_ARBITRATION                            0x0000a0 /* established */

/* parity_err: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PARITY_ERR                             0x0000b0 /* established */

/* timeout: rw64, reset unknown; census: 6 sites, 4 routines */
#define TIOCP_TIMEOUT                                0x0000c0 /* established */

/* type1_cntr: rw64, reset unknown; census: 2 sites, 2 routines */
#define TIOCP_TYPE1_CNTR                             0x0000c8 /* established */

/* pci_bus_addr_addr: r64, reset unknown; census: 3 sites, 2 routines */
#define TIOCP_PCI_BUS_ADDR_ADDR                      0x0000d8 /* established */

/* intr_status: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_INTR_STATUS                            0x000100 /* established */

/* intr_enable: rw64, reset unknown; census: 6 sites, 4 routines */
#define TIOCP_INTR_ENABLE                            0x000108 /* established */

/* intr_reset: rw64, reset unknown; census: 3 sites, 2 routines */
#define TIOCP_INTR_RESET                             0x000110 /* established */

/* intr_mode: rw64, reset unknown; census: 6 sites, 4 routines */
#define TIOCP_INTR_MODE                              0x000118 /* established */

/* intr_device: rw64, reset unknown; census: 6 sites, 4 routines */
#define TIOCP_INTR_DEVICE                            0x000120 /* established */

/* intr_host_err: rw64, reset unknown; census: 2 sites, 2 routines */
#define TIOCP_INTR_HOST_ERR                          0x000128 /* established */

/* intr_addr_vect: rw64, reset unknown; census: 12 sites, 6 routines */
#define TIOCP_INTR_ADDR_VECT                         0x000130 /* established */

/* intr_view: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_INTR_VIEW                              0x000170 /* established */

/* intr_multiple: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_INTR_MULTIPLE                          0x000178 /* established */

/* force_always: w64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_FORCE_ALWAYS                           0x000180 /* established */

/* force_intr: w64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_FORCE_INTR                             0x0001c0 /* established */

/* device: rw64, reset unknown; census: 6 sites, 4 routines */
#define TIOCP_DEVICE                                 0x000200 /* established */

/* wrb_flush: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_WRB_FLUSH                              0x000240 /* established */

/* rrb: rw64, reset unknown; census: 6 sites, 4 routines */
#define TIOCP_RRB                                    0x000280 /* established */

/* rrb_status: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_RRB_STATUS                             0x000290 /* established */

/* rrb_clear: w64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_RRB_CLEAR                              0x000298 /* established */

/* pcix_bus_err_addr: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PCIX_BUS_ERR_ADDR                      0x000600 /* established */

/* pcix_bus_err_attr: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PCIX_BUS_ERR_ATTR                      0x000608 /* established */

/* pcix_bus_err_data: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PCIX_BUS_ERR_DATA                      0x000610 /* established */

/* pcix_pio_split_addr: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PCIX_PIO_SPLIT_ADDR                    0x000618 /* established */

/* pcix_pio_split_attr: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PCIX_PIO_SPLIT_ATTR                    0x000620 /* established */

/* pcix_req_err_attr: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PCIX_REQ_ERR_ATTR                      0x000628 /* established */

/* pcix_req_err_addr: r64, reset unknown; census: 1 sites, 1 routines */
#define TIOCP_PCIX_REQ_ERR_ADDR                      0x000630 /* established */

/* int_ate: rw64, reset unknown; census: 2 sites, 2 routines */
#define TIOCP_INT_ATE                                0x010000 /* established */

/* ext_ate: rw64, reset unknown; census: 6 sites, 2 routines */
#define TIOCP_EXT_ATE                                0x080000 /* established */

#define TIOCP_ID_B_10_0                              0x7ffu /* inferred */
#define TIOCP_ID_B_15_0                              0xffffu /* inferred */
#define TIOCP_INTR_ADDR_VECT_B_10_0                  0x7ffu /* inferred */
#define TIOCP_INTR_ADDR_VECT_B_7_0                   0xffu /* inferred */
#define TIOCP_INTR_DST_TARGET_ID_V_A5A5              0xa5a5u /* inferred */
#define TIOCP_INTR_DST_TARGET_ID_V_A5A50000          0xa5a50000u /* inferred */
#define TIOCP_INT_ATE_B_10_0                         0x7ffu /* inferred */
#define TIOCP_LINKSIDE_ERR_ADDR_V_BEEF               0xbeefu /* inferred */
#define TIOCP_RRB_B_10_0                             0x7ffu /* inferred */
#define TIOCP_SSRAM_SIZE_B_5_4                       0x30u /* inferred */

#endif /* TIOCP_GEN_H */
