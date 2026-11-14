/* generated from devices/tiocp/registers-extra.toml by defs-gen - do not edit, change the source */
/* TIOCP registers and constants outside the census */
#ifndef TIOCP_GEN_H
#define TIOCP_GEN_H

#include <stdint.h>


/*
 * Widget status (`cp_stat`), second word of the standard widget block. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* stat: rw64, reset unknown */
#define TIOCP_STAT                                   0x000008 /* established */

/*
 * Widget error address, upper word (`cp_err_upper`); the lower word is the census register `bus_err`. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* err_upper: rw64, reset unknown */
#define TIOCP_ERR_UPPER                              0x000010 /* established */

/*
 * Widget interrupt destination, upper word (`cp_intr_upper`); the lower word is the census register `intr_dst_target_id`. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* intr_upper: rw64, reset unknown */
#define TIOCP_INTR_UPPER                             0x000030 /* established */

/*
 * Test pin control (`cp_tst_pin_ctrl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* tst_pin_ctrl: rw64, reset unknown */
#define TIOCP_TST_PIN_CTRL                           0x000070 /* established */

/*
 * PCI error address, upper word (`cp_pci_err_upper`); the lower word is the census register `pci_bus_addr`. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* pci_err_upper: rw64, reset unknown */
#define TIOCP_PCI_ERR_UPPER                          0x0000d0 /* established */

/*
 * Buffer address match registers: sixteen pairs, upper word then lower word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_addr_match_upper: rw64, reset unknown */
#define TIOCP_BUF_ADDR_MATCH_UPPER                   0x000300 /* established */
#define TIOCP_BUF_ADDR_MATCH_UPPER_COUNT             16
#define TIOCP_BUF_ADDR_MATCH_UPPER_STRIDE            16

/*
 * Buffer address match, lower words (second word of each pair). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_addr_match_lower: rw64, reset unknown */
#define TIOCP_BUF_ADDR_MATCH_LOWER                   0x000308 /* established */
#define TIOCP_BUF_ADDR_MATCH_LOWER_COUNT             16
#define TIOCP_BUF_ADDR_MATCH_LOWER_STRIDE            16

/*
 * Performance monitor word `flush_w_touch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_flush_w_touch: rw64, reset unknown */
#define TIOCP_BUF_COUNT_FLUSH_W_TOUCH                0x000400 /* established */
#define TIOCP_BUF_COUNT_FLUSH_W_TOUCH_COUNT          8
#define TIOCP_BUF_COUNT_FLUSH_W_TOUCH_STRIDE         64

/*
 * Performance monitor word `flush_wo_touch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_flush_wo_touch: rw64, reset unknown */
#define TIOCP_BUF_COUNT_FLUSH_WO_TOUCH               0x000408 /* established */
#define TIOCP_BUF_COUNT_FLUSH_WO_TOUCH_COUNT         8
#define TIOCP_BUF_COUNT_FLUSH_WO_TOUCH_STRIDE        64

/*
 * Performance monitor word `inflight` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_inflight: rw64, reset unknown */
#define TIOCP_BUF_COUNT_INFLIGHT                     0x000410 /* established */
#define TIOCP_BUF_COUNT_INFLIGHT_COUNT               8
#define TIOCP_BUF_COUNT_INFLIGHT_STRIDE              64

/*
 * Performance monitor word `prefetch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_prefetch: rw64, reset unknown */
#define TIOCP_BUF_COUNT_PREFETCH                     0x000418 /* established */
#define TIOCP_BUF_COUNT_PREFETCH_COUNT               8
#define TIOCP_BUF_COUNT_PREFETCH_STRIDE              64

/*
 * Performance monitor word `total_pci_retry` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_total_pci_retry: rw64, reset unknown */
#define TIOCP_BUF_COUNT_TOTAL_PCI_RETRY              0x000420 /* established */
#define TIOCP_BUF_COUNT_TOTAL_PCI_RETRY_COUNT        8
#define TIOCP_BUF_COUNT_TOTAL_PCI_RETRY_STRIDE       64

/*
 * Performance monitor word `max_pci_retry` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_max_pci_retry: rw64, reset unknown */
#define TIOCP_BUF_COUNT_MAX_PCI_RETRY                0x000428 /* established */
#define TIOCP_BUF_COUNT_MAX_PCI_RETRY_COUNT          8
#define TIOCP_BUF_COUNT_MAX_PCI_RETRY_STRIDE         64

/*
 * Performance monitor word `max_latency` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_max_latency: rw64, reset unknown */
#define TIOCP_BUF_COUNT_MAX_LATENCY                  0x000430 /* established */
#define TIOCP_BUF_COUNT_MAX_LATENCY_COUNT            8
#define TIOCP_BUF_COUNT_MAX_LATENCY_STRIDE           64

/*
 * Performance monitor word `clear_all` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_clear_all: rw64, reset unknown */
#define TIOCP_BUF_COUNT_CLEAR_ALL                    0x000438 /* established */
#define TIOCP_BUF_COUNT_CLEAR_ALL_COUNT              8
#define TIOCP_BUF_COUNT_CLEAR_ALL_STRIDE             64

/*
 * PCI-X timeout (`cp_pcix_timeout`), eighth word of the PCI-X block. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* pcix_timeout: rw64, reset unknown */
#define TIOCP_PCIX_TIMEOUT                           0x000638 /* established */

/*
 * Coretalk debug control (`cp_ct_debug_ctl`). The debug registers exist on the TIOCP only; the PIC leaves this range as padding. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* ct_debug_ctl: rw64, reset unknown */
#define TIOCP_CT_DEBUG_CTL                           0x000700 /* established */

/*
 * Bridge debug control (`cp_br_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* br_debug_ctl: rw64, reset unknown */
#define TIOCP_BR_DEBUG_CTL                           0x000708 /* established */

/*
 * Debug mux control (`cp_mux3_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* mux3_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX3_DEBUG_CTL                         0x000710 /* established */

/*
 * Debug mux control (`cp_mux4_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* mux4_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX4_DEBUG_CTL                         0x000718 /* established */

/*
 * Debug mux control (`cp_mux5_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* mux5_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX5_DEBUG_CTL                         0x000720 /* established */

/*
 * Debug mux control (`cp_mux6_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* mux6_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX6_DEBUG_CTL                         0x000728 /* established */

/*
 * Debug mux control (`cp_mux7_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* mux7_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX7_DEBUG_CTL                         0x000730 /* established */

/*
 * PCI-X read buffer n, address word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* pcix_read_buf_64_cp_buf_addr: rw64, reset unknown */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ADDR           0x000a00 /* established */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ADDR_COUNT     16
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ADDR_STRIDE    16

/*
 * PCI-X read buffer n, attribute word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* pcix_read_buf_64_cp_buf_attr: rw64, reset unknown */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ATTR           0x000a08 /* established */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ATTR_COUNT     16
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ATTR_STRIDE    16

/*
 * PCI-X write buffer n, address word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* pcix_write_buf_64_cp_buf_addr: rw64, reset unknown */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ADDR          0x000b00 /* established */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ADDR_COUNT    8
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ADDR_STRIDE   32

/*
 * PCI-X write buffer n, attribute word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* pcix_write_buf_64_cp_buf_attr: rw64, reset unknown */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ATTR          0x000b08 /* established */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ATTR_COUNT    8
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ATTR_STRIDE   32

/*
 * PCI-X write buffer n, valid word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* pcix_write_buf_64_cp_buf_valid: rw64, reset unknown */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_VALID         0x000b10 /* established */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_VALID_COUNT   8
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_VALID_STRIDE  32

/*
 * Internal translation entries with manual parity generation (`cp_int_ate_ram_mp`); the automatic-parity copy is the census register `int_ate`. No IRIX routine reaches it. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* int_ate_mp: rw64, reset unknown */
#define TIOCP_INT_ATE_MP                             0x014000 /* established */
#define TIOCP_INT_ATE_MP_COUNT                       1024
#define TIOCP_INT_ATE_MP_STRIDE                      8

/*
 * Write request RAM, lower data bank (`cp_wr_req_lower`). Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* wr_req_lower: rw64, reset unknown */
#define TIOCP_WR_REQ_LOWER                           0x018000 /* established */
#define TIOCP_WR_REQ_LOWER_COUNT                     256
#define TIOCP_WR_REQ_LOWER_STRIDE                    8

/*
 * Write request RAM, upper data bank (`cp_wr_req_upper`). Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* wr_req_upper: rw64, reset unknown */
#define TIOCP_WR_REQ_UPPER                           0x018800 /* established */
#define TIOCP_WR_REQ_UPPER_COUNT                     256
#define TIOCP_WR_REQ_UPPER_STRIDE                    8

/*
 * Write request RAM, parity bank (`cp_wr_req_parity`). Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* wr_req_parity: rw64, reset unknown */
#define TIOCP_WR_REQ_PARITY                          0x019000 /* established */
#define TIOCP_WR_REQ_PARITY_COUNT                    256
#define TIOCP_WR_REQ_PARITY_STRIDE                   8

/*
 * Read response RAM, lower data bank (`cp_rd_resp_lower`). The PIC has no read response RAM. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* rd_resp_lower: rw64, reset unknown */
#define TIOCP_RD_RESP_LOWER                          0x01c000 /* established */
#define TIOCP_RD_RESP_LOWER_COUNT                    512
#define TIOCP_RD_RESP_LOWER_STRIDE                   8

/*
 * Read response RAM, upper data bank. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* rd_resp_upper: rw64, reset unknown */
#define TIOCP_RD_RESP_UPPER                          0x01d000 /* established */
#define TIOCP_RD_RESP_UPPER_COUNT                    512
#define TIOCP_RD_RESP_UPPER_STRIDE                   8

/*
 * Read response RAM, parity bank. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour is unknown.
 */
/* rd_resp_parity: rw64, reset unknown */
#define TIOCP_RD_RESP_PARITY                         0x01e000 /* established */
#define TIOCP_RD_RESP_PARITY_COUNT                   512
#define TIOCP_RD_RESP_PARITY_STRIDE                  8

#define TIOCP_ATE_MSI                                0x4u /* established */
#define TIOCP_ATE_PIO                                0x2u /* established */
#define TIOCP_CFG_TYPE0_BASE                         0x21000u /* established */
#define TIOCP_CFG_TYPE1_BASE                         0x28000u /* established */
#define TIOCP_DEVIO_BASE                             0x200000u /* established */
#define TIOCP_DEVIO_FLUSH_BASE                       0xa00000u /* established */
#define TIOCP_HOST_INTR_ADDR_MASK                    0x3fffffffffffffull /* established */
#define TIOCP_PCI64_CMDTYPE_MEM                      0x1000000000000000ull /* established */
#define TIOCP_PCI64_CMDTYPE_MSI                      0x3000000000000000ull /* established */
#define TIOCP_PCIX_SPECIAL_CYCLE_BASE                0x40000u /* established */
#define TIOCP_PCI_IACK_BASE                          0x30000u /* established */
#define TIOCP_WAR_PV907516                           0x2u /* established */

#endif /* TIOCP_GEN_H */
