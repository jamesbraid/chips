/* generated from devices/pic/registers-extra.toml by defs-gen - do not edit, change the source */
/* PIC bits outside the census */
#ifndef PIC_GEN_H
#define PIC_GEN_H

#include <stdint.h>


/*
 * Widget status, the second word of the standard widget configuration block (`p_wid_stat`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* wid_stat: rw64, reset unknown */
#define PIC_WID_STAT                                 0x000008 /* established */

/*
 * Widget error address, upper word (`p_wid_err_upper`); the lower word is the census register `bus_err`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* wid_err_upper: rw64, reset unknown */
#define PIC_WID_ERR_UPPER                            0x000010 /* established */

/*
 * Widget interrupt destination, upper word (`p_wid_int_upper`); the lower word is the census register `intr_dst_target_id`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* wid_int_upper: rw64, reset unknown */
#define PIC_WID_INT_UPPER                            0x000030 /* established */

/*
 * Test pin control (`p_wid_tst_pin_ctrl`), the one slot of the bridge-specific block between the response words and the address-lock error register. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* wid_tst_pin_ctrl: rw64, reset unknown */
#define PIC_WID_TST_PIN_CTRL                         0x000070 /* established */

/*
 * PCI bus error address, upper word (`p_pci_err_upper`); the lower word is the census register `pci_bus_addr`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* pci_err_upper: rw64, reset unknown */
#define PIC_PCI_ERR_UPPER                            0x0000d0 /* established */

/*
 * Buffer address match registers: sixteen pairs, upper word then lower word, sixteen bytes per pair (`p_buf_addr_match[n].upper` and `.lower`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_addr_match: rw64, reset unknown */
#define PIC_BUF_ADDR_MATCH                           0x000300 /* established */
#define PIC_BUF_ADDR_MATCH_COUNT                     32
#define PIC_BUF_ADDR_MATCH_STRIDE                    8

/*
 * Performance monitor block n, word 0 (`p_buf_count[n].flush_w_touch`): eight blocks of eight words, 0x40 bytes apart. The header comment marks them even-numbered buffers only. The register names are the only description. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_flush_w_touch: rw64, reset unknown */
#define PIC_BUF_FLUSH_W_TOUCH                        0x000400 /* established */
#define PIC_BUF_FLUSH_W_TOUCH_COUNT                  8
#define PIC_BUF_FLUSH_W_TOUCH_STRIDE                 64

/*
 * Performance monitor block n, word 1 (`flush_wo_touch`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_flush_wo_touch: rw64, reset unknown */
#define PIC_BUF_FLUSH_WO_TOUCH                       0x000408 /* established */
#define PIC_BUF_FLUSH_WO_TOUCH_COUNT                 8
#define PIC_BUF_FLUSH_WO_TOUCH_STRIDE                64

/*
 * Performance monitor block n, word 2 (`inflight`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_inflight: rw64, reset unknown */
#define PIC_BUF_INFLIGHT                             0x000410 /* established */
#define PIC_BUF_INFLIGHT_COUNT                       8
#define PIC_BUF_INFLIGHT_STRIDE                      64

/*
 * Performance monitor block n, word 3 (`prefetch`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_prefetch: rw64, reset unknown */
#define PIC_BUF_PREFETCH                             0x000418 /* established */
#define PIC_BUF_PREFETCH_COUNT                       8
#define PIC_BUF_PREFETCH_STRIDE                      64

/*
 * Performance monitor block n, word 4 (`total_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_total_pci_retry: rw64, reset unknown */
#define PIC_BUF_TOTAL_PCI_RETRY                      0x000420 /* established */
#define PIC_BUF_TOTAL_PCI_RETRY_COUNT                8
#define PIC_BUF_TOTAL_PCI_RETRY_STRIDE               64

/*
 * Performance monitor block n, word 5 (`max_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_max_pci_retry: rw64, reset unknown */
#define PIC_BUF_MAX_PCI_RETRY                        0x000428 /* established */
#define PIC_BUF_MAX_PCI_RETRY_COUNT                  8
#define PIC_BUF_MAX_PCI_RETRY_STRIDE                 64

/*
 * Performance monitor block n, word 6 (`max_latency`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_max_latency: rw64, reset unknown */
#define PIC_BUF_MAX_LATENCY                          0x000430 /* established */
#define PIC_BUF_MAX_LATENCY_COUNT                    8
#define PIC_BUF_MAX_LATENCY_STRIDE                   64

/*
 * Performance monitor block n, word 7 (`clear_all`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_clear_all: rw64, reset unknown */
#define PIC_BUF_CLEAR_ALL                            0x000438 /* established */
#define PIC_BUF_CLEAR_ALL_COUNT                      8
#define PIC_BUF_CLEAR_ALL_STRIDE                     64

/*
 * PCI-X timeout (`p_pcix_timeout`), the eighth word of the PCI-X register block that follows the seven census registers. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* pcix_timeout: rw64, reset unknown */
#define PIC_PCIX_TIMEOUT                             0x000638 /* established */

/*
 * PCI-X read buffer n, address word (`p_pcix_read_buf_64[n].p_buf_addr`); the attribute word of the same buffer follows it. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* pcix_read_buf_addr: rw64, reset unknown */
#define PIC_PCIX_READ_BUF_ADDR                       0x000a00 /* established */
#define PIC_PCIX_READ_BUF_ADDR_COUNT                 16
#define PIC_PCIX_READ_BUF_ADDR_STRIDE                16

/*
 * PCI-X read buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* pcix_read_buf_attr: rw64, reset unknown */
#define PIC_PCIX_READ_BUF_ATTR                       0x000a08 /* established */
#define PIC_PCIX_READ_BUF_ATTR_COUNT                 16
#define PIC_PCIX_READ_BUF_ATTR_STRIDE                16

/*
 * PCI-X write buffer n, address word (`p_pcix_write_buf_64[n].p_buf_addr`); the attribute, valid and one unused word follow at eight-byte steps. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* pcix_write_buf_addr: rw64, reset unknown */
#define PIC_PCIX_WRITE_BUF_ADDR                      0x000b00 /* established */
#define PIC_PCIX_WRITE_BUF_ADDR_COUNT                8
#define PIC_PCIX_WRITE_BUF_ADDR_STRIDE               32

/*
 * PCI-X write buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* pcix_write_buf_attr: rw64, reset unknown */
#define PIC_PCIX_WRITE_BUF_ATTR                      0x000b08 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_COUNT                8
#define PIC_PCIX_WRITE_BUF_ATTR_STRIDE               32

/*
 * PCI-X write buffer n, valid word (`p_buf_valid`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* pcix_write_buf_valid: rw64, reset unknown */
#define PIC_PCIX_WRITE_BUF_VALID                     0x000b10 /* established */
#define PIC_PCIX_WRITE_BUF_VALID_COUNT               8
#define PIC_PCIX_WRITE_BUF_VALID_STRIDE              32

/*
 * Second copy of the internal translation entries with manual parity generation (`p_int_ate_ram_mp`); the census register `int_ate` is the automatic-parity copy. No IRIX routine reaches this range. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.
 */
/* int_ate_mp: rw64, reset unknown */
#define PIC_INT_ATE_MP                               0x012000 /* established */
#define PIC_INT_ATE_MP_COUNT                         1024
#define PIC_INT_ATE_MP_STRIDE                        8

#define PIC_ATE_ADDR_SHIFT                           0xcu /* established */
#define PIC_ATE_BARRIER                              0x10u /* established */
#define PIC_ATE_COHERENT                             0x2u /* established */
#define PIC_ATE_MSI                                  0x4u /* established */
#define PIC_ATE_PREFETCH                             0x8u /* established */
#define PIC_ATE_TARGET_SHIFT                         0x8u /* established */
#define PIC_ATE_VALID                                0x1u /* established */
#define PIC_CFG_TYPE0_BASE                           0x20000u /* established */
#define PIC_CFG_TYPE1_BASE                           0x28000u /* established */
#define PIC_CONTROL_PAGE_SIZE_16K                    0x200000u /* established */
#define PIC_DEVICE_SWAP_DIRECT                       0x80000u /* inferred */
#define PIC_DIRECT64_ATTR_BARRIER                    0x100000000000000ull /* established */
#define PIC_DIRECT64_ATTR_PRECISE                    0x400000000000000ull /* established */
#define PIC_DIRECT64_ATTR_PREFETCH                   0x800000000000000ull /* established */
#define PIC_DIRECT64_ATTR_SWAP                       0x80000000000000ull /* established */
#define PIC_DIRECT64_ATTR_TARGET_SHIFT               0x3cu /* established */
#define PIC_DIRECT64_ATTR_VIRTUAL                    0x200000000000000ull /* established */
#define PIC_DIRECT64_ATTR_VIRTUAL1                   0x40000000000000ull /* established */
#define PIC_HOST_INTR_ADDR_MASK                      0xffffffffffffull /* established */
#define PIC_INTR_FLUSH_WAIT_VALUE                    0x10fu /* established */
#define PIC_INTR_PCIX_MASTER_TIMEOUT                 0x400000000ull /* established */
#define PIC_INTR_PCI_MASTER_TIMEOUT                  0x800u /* established */
#define PIC_INTR_RESET_MULTIPLE_CLEAR                0x40u /* established */
#define PIC_PCI32_DIRECT_BASE                        0x80000000u /* established */
#define PIC_PCI32_MAPPED_BASE                        0x40000000u /* established */
#define PIC_PCI32_MAPPED_SWAP                        0x20000000u /* established */
#define PIC_PCIX_SPECIAL_CYCLE_BASE                  0x40000u /* established */
#define PIC_PCI_IACK_BASE                            0x30000u /* established */

#endif /* PIC_GEN_H */
