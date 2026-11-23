/* generated from devices/pic/registers-extra.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 8625d442093f1d068354ca25ec403aee88e928e39d207604767d6738ad20a128 */
/* PIC bits outside the census */
#ifndef PIC_GEN_H
#define PIC_GEN_H

#include <stdint.h>


/*
 * Widget status, the second word of the standard widget configuration block
 * (`p_wid_stat`). Offset, width and name are the header definition. Access
 * direction is not stated by the header or by any code read; nothing in the SN2
 * driver or the IRIX objects reaches this register, so its behaviour is
 * unknown.
 */
/* wid_stat: rw64, reset unknown */
#define PIC_WID_STAT                                 0x000008 /* established */

/*
 * Widget error address, upper word (`p_wid_err_upper`); the lower word is the
 * census register `bus_err`. Offset, width and name are the header definition.
 * Access direction is not stated by the header or by any code read; nothing in
 * the SN2 driver or the IRIX objects reaches this register, so its behaviour is
 * unknown.
 */
/* wid_err_upper: rw64, reset unknown */
#define PIC_WID_ERR_UPPER                            0x000010 /* established */

/*
 * Widget interrupt destination, upper word (`p_wid_int_upper`); the lower word
 * is the census register `intr_dst_target_id`. Offset, width and name are the
 * header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* wid_int_upper: rw64, reset unknown */
#define PIC_WID_INT_UPPER                            0x000030 /* established */

/*
 * Test pin control (`p_wid_tst_pin_ctrl`), the one slot of the bridge-specific
 * block between the response words and the address-lock error register. Offset,
 * width and name are the header definition. Access direction is not stated by
 * the header or by any code read; nothing in the SN2 driver or the IRIX objects
 * reaches this register, so its behaviour is unknown.
 */
/* wid_tst_pin_ctrl: rw64, reset unknown */
#define PIC_WID_TST_PIN_CTRL                         0x000070 /* established */

/*
 * PCI bus error address, upper word (`p_pci_err_upper`); the lower word is the
 * census register `pci_bus_addr`. Offset, width and name are the header
 * definition. Access direction is not stated by the header or by any code read;
 * nothing in the SN2 driver or the IRIX objects reaches this register, so its
 * behaviour is unknown.
 */
/* pci_err_upper: rw64, reset unknown */
#define PIC_PCI_ERR_UPPER                            0x0000d0 /* established */

/*
 * Buffer address match registers: sixteen pairs, upper word then lower word,
 * sixteen bytes per pair (`p_buf_addr_match[n].upper` and `.lower`). Offset,
 * width and name are the header definition. Access direction is not stated by
 * the header or by any code read; nothing in the SN2 driver or the IRIX objects
 * reaches this register, so its behaviour is unknown.
 */
/* buf_addr_match: rw64, reset unknown */
#define PIC_BUF_ADDR_MATCH                           0x000300 /* established */
#define PIC_BUF_ADDR_MATCH_COUNT                     32
#define PIC_BUF_ADDR_MATCH_STRIDE                    8

/*
 * Performance monitor block n, word 0 (`p_buf_count[n].flush_w_touch`): eight
 * blocks of eight words, 0x40 bytes apart. The header comment marks them
 * even-numbered buffers only. The register names are the only description.
 * Offset, width and name are the header definition. Access direction is not
 * stated by the header or by any code read; nothing in the SN2 driver or the
 * IRIX objects reaches this register, so its behaviour is unknown.
 */
/* buf_flush_w_touch: rw64, reset unknown */
#define PIC_BUF_FLUSH_W_TOUCH                        0x000400 /* established */
#define PIC_BUF_FLUSH_W_TOUCH_COUNT                  8
#define PIC_BUF_FLUSH_W_TOUCH_STRIDE                 64

/*
 * Performance monitor block n, word 1 (`flush_wo_touch`). Offset, width and
 * name are the header definition. Access direction is not stated by the header
 * or by any code read; nothing in the SN2 driver or the IRIX objects reaches
 * this register, so its behaviour is unknown.
 */
/* buf_flush_wo_touch: rw64, reset unknown */
#define PIC_BUF_FLUSH_WO_TOUCH                       0x000408 /* established */
#define PIC_BUF_FLUSH_WO_TOUCH_COUNT                 8
#define PIC_BUF_FLUSH_WO_TOUCH_STRIDE                64

/*
 * Performance monitor block n, word 2 (`inflight`). Offset, width and name are
 * the header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* buf_inflight: rw64, reset unknown */
#define PIC_BUF_INFLIGHT                             0x000410 /* established */
#define PIC_BUF_INFLIGHT_COUNT                       8
#define PIC_BUF_INFLIGHT_STRIDE                      64

/*
 * Performance monitor block n, word 3 (`prefetch`). Offset, width and name are
 * the header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* buf_prefetch: rw64, reset unknown */
#define PIC_BUF_PREFETCH                             0x000418 /* established */
#define PIC_BUF_PREFETCH_COUNT                       8
#define PIC_BUF_PREFETCH_STRIDE                      64

/*
 * Performance monitor block n, word 4 (`total_pci_retry`). Offset, width and
 * name are the header definition. Access direction is not stated by the header
 * or by any code read; nothing in the SN2 driver or the IRIX objects reaches
 * this register, so its behaviour is unknown.
 */
/* buf_total_pci_retry: rw64, reset unknown */
#define PIC_BUF_TOTAL_PCI_RETRY                      0x000420 /* established */
#define PIC_BUF_TOTAL_PCI_RETRY_COUNT                8
#define PIC_BUF_TOTAL_PCI_RETRY_STRIDE               64

/*
 * Performance monitor block n, word 5 (`max_pci_retry`). Offset, width and name
 * are the header definition. Access direction is not stated by the header or by
 * any code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* buf_max_pci_retry: rw64, reset unknown */
#define PIC_BUF_MAX_PCI_RETRY                        0x000428 /* established */
#define PIC_BUF_MAX_PCI_RETRY_COUNT                  8
#define PIC_BUF_MAX_PCI_RETRY_STRIDE                 64

/*
 * Performance monitor block n, word 6 (`max_latency`). Offset, width and name
 * are the header definition. Access direction is not stated by the header or by
 * any code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* buf_max_latency: rw64, reset unknown */
#define PIC_BUF_MAX_LATENCY                          0x000430 /* established */
#define PIC_BUF_MAX_LATENCY_COUNT                    8
#define PIC_BUF_MAX_LATENCY_STRIDE                   64

/*
 * Performance monitor block n, word 7 (`clear_all`). Offset, width and name are
 * the header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* buf_clear_all: rw64, reset unknown */
#define PIC_BUF_CLEAR_ALL                            0x000438 /* established */
#define PIC_BUF_CLEAR_ALL_COUNT                      8
#define PIC_BUF_CLEAR_ALL_STRIDE                     64

/*
 * PCI-X timeout (`p_pcix_timeout`), the eighth word of the PCI-X register block
 * that follows the seven census registers. Offset, width and name are the
 * header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* pcix_timeout: rw64, reset unknown */
#define PIC_PCIX_TIMEOUT                             0x000638 /* established */

/*
 * PCI-X read buffer n, address word (`p_pcix_read_buf_64[n].p_buf_addr`); the
 * attribute word of the same buffer follows it. Offset, width and name are the
 * header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* pcix_read_buf_addr: rw64, reset unknown */
#define PIC_PCIX_READ_BUF_ADDR                       0x000a00 /* established */
#define PIC_PCIX_READ_BUF_ADDR_COUNT                 16
#define PIC_PCIX_READ_BUF_ADDR_STRIDE                16

/*
 * PCI-X read buffer n, attribute word (`p_buf_attr`). Offset, width and name
 * are the header definition. Access direction is not stated by the header or by
 * any code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* pcix_read_buf_attr: rw64, reset unknown */
#define PIC_PCIX_READ_BUF_ATTR                       0x000a08 /* established */
#define PIC_PCIX_READ_BUF_ATTR_COUNT                 16
#define PIC_PCIX_READ_BUF_ATTR_STRIDE                16

/*
 * PCI-X write buffer n, address word (`p_pcix_write_buf_64[n].p_buf_addr`); the
 * attribute, valid and one unused word follow at eight-byte steps. Offset,
 * width and name are the header definition. Access direction is not stated by
 * the header or by any code read; nothing in the SN2 driver or the IRIX objects
 * reaches this register, so its behaviour is unknown.
 */
/* pcix_write_buf_addr: rw64, reset unknown */
#define PIC_PCIX_WRITE_BUF_ADDR                      0x000b00 /* established */
#define PIC_PCIX_WRITE_BUF_ADDR_COUNT                8
#define PIC_PCIX_WRITE_BUF_ADDR_STRIDE               32

/*
 * PCI-X write buffer n, attribute word (`p_buf_attr`). Offset, width and name
 * are the header definition. Access direction is not stated by the header or by
 * any code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* pcix_write_buf_attr: rw64, reset unknown */
#define PIC_PCIX_WRITE_BUF_ATTR                      0x000b08 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_COUNT                8
#define PIC_PCIX_WRITE_BUF_ATTR_STRIDE               32

/*
 * PCI-X write buffer n, valid word (`p_buf_valid`). Offset, width and name are
 * the header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* pcix_write_buf_valid: rw64, reset unknown */
#define PIC_PCIX_WRITE_BUF_VALID                     0x000b10 /* established */
#define PIC_PCIX_WRITE_BUF_VALID_COUNT               8
#define PIC_PCIX_WRITE_BUF_VALID_STRIDE              32

/*
 * Second copy of the internal translation entries with manual parity generation
 * (`p_int_ate_ram_mp`); the census register `int_ate` is the automatic-parity
 * copy. No IRIX routine reaches this range. Offset, width and name are the
 * header definition. Access direction is not stated by the header or by any
 * code read; nothing in the SN2 driver or the IRIX objects reaches this
 * register, so its behaviour is unknown.
 */
/* int_ate_mp: rw64, reset unknown */
#define PIC_INT_ATE_MP                               0x012000 /* established */
#define PIC_INT_ATE_MP_COUNT                         1024
#define PIC_INT_ATE_MP_STRIDE                        8

/*
 * Arbitration: request wait tick and enable, grant freeze, bridge high and low
 * priority enables, and device-broke bits (names only).
 */
/* word ARB_REG: 64 bits */
#define PIC_ARB_REG_WIDTH                            64 /* established */
#define PIC_ARB_REG_DEV_BROKE_SHIFT                  20 /* established */
#define PIC_ARB_REG_DEV_BROKE_MASK                   0xfull
#define PIC_ARB_REG_DEV_BROKE_INPLACE (PIC_ARB_REG_DEV_BROKE_MASK << PIC_ARB_REG_DEV_BROKE_SHIFT)
#define PIC_ARB_REG_REQ_WAIT_TICK_SHIFT              16 /* established */
#define PIC_ARB_REG_REQ_WAIT_TICK_MASK               0x3ull
#define PIC_ARB_REG_REQ_WAIT_TICK_INPLACE (PIC_ARB_REG_REQ_WAIT_TICK_MASK << PIC_ARB_REG_REQ_WAIT_TICK_SHIFT)
#define PIC_ARB_REG_REQ_WAIT_EN_SHIFT                8 /* established */
#define PIC_ARB_REG_REQ_WAIT_EN_MASK                 0xfull
#define PIC_ARB_REG_REQ_WAIT_EN_INPLACE (PIC_ARB_REG_REQ_WAIT_EN_MASK << PIC_ARB_REG_REQ_WAIT_EN_SHIFT)
#define PIC_ARB_REG_DISARB_SHIFT                     7 /* established */
#define PIC_ARB_REG_DISARB_MASK                      0x1ull
#define PIC_ARB_REG_DISARB_INPLACE (PIC_ARB_REG_DISARB_MASK << PIC_ARB_REG_DISARB_SHIFT)
#define PIC_ARB_REG_FREEZE_GNT_SHIFT                 6 /* established */
#define PIC_ARB_REG_FREEZE_GNT_MASK                  0x1ull
#define PIC_ARB_REG_FREEZE_GNT_INPLACE (PIC_ARB_REG_FREEZE_GNT_MASK << PIC_ARB_REG_FREEZE_GNT_SHIFT)
#define PIC_ARB_REG_EN_BRIDGE_HI_SHIFT               3 /* established */
#define PIC_ARB_REG_EN_BRIDGE_HI_MASK                0x3ull
#define PIC_ARB_REG_EN_BRIDGE_HI_INPLACE (PIC_ARB_REG_EN_BRIDGE_HI_MASK << PIC_ARB_REG_EN_BRIDGE_HI_SHIFT)
#define PIC_ARB_REG_EN_BRIDGE_LO_SHIFT               0 /* established */
#define PIC_ARB_REG_EN_BRIDGE_LO_MASK                0x3ull
#define PIC_ARB_REG_EN_BRIDGE_LO_INPLACE (PIC_ARB_REG_EN_BRIDGE_LO_MASK << PIC_ARB_REG_EN_BRIDGE_LO_SHIFT)

/*
 * Performance counter, per even buffer block: flushes with no data used. A word
 * write clears it.
 */
/* word BUF_FLUSH_WO_TOUCH_REG: 64 bits */
#define PIC_BUF_FLUSH_WO_TOUCH_REG_WIDTH             64 /* established */
#define PIC_BUF_FLUSH_WO_TOUCH_REG_NOTOUCH_CNT_SHIFT 0 /* established */
#define PIC_BUF_FLUSH_WO_TOUCH_REG_NOTOUCH_CNT_MASK  0xffffull
#define PIC_BUF_FLUSH_WO_TOUCH_REG_NOTOUCH_CNT_INPLACE (PIC_BUF_FLUSH_WO_TOUCH_REG_NOTOUCH_CNT_MASK << PIC_BUF_FLUSH_WO_TOUCH_REG_NOTOUCH_CNT_SHIFT)

/*
 * Performance counter, per even buffer block: flushes after at least one data
 * use. A word write clears it.
 */
/* word BUF_FLUSH_W_TOUCH_REG: 64 bits */
#define PIC_BUF_FLUSH_W_TOUCH_REG_WIDTH              64 /* established */
#define PIC_BUF_FLUSH_W_TOUCH_REG_TOUCH_CNT_SHIFT    0 /* established */
#define PIC_BUF_FLUSH_W_TOUCH_REG_TOUCH_CNT_MASK     0xffffull
#define PIC_BUF_FLUSH_W_TOUCH_REG_TOUCH_CNT_INPLACE (PIC_BUF_FLUSH_W_TOUCH_REG_TOUCH_CNT_MASK << PIC_BUF_FLUSH_W_TOUCH_REG_TOUCH_CNT_SHIFT)

/*
 * Performance counter, per even buffer block: bus clocks a request spent in
 * flight. A word write clears it.
 */
/* word BUF_INFLIGHT_REG: 64 bits */
#define PIC_BUF_INFLIGHT_REG_WIDTH                   64 /* established */
#define PIC_BUF_INFLIGHT_REG_INFLIGHT_CNT_SHIFT      0 /* established */
#define PIC_BUF_INFLIGHT_REG_INFLIGHT_CNT_MASK       0xffffull
#define PIC_BUF_INFLIGHT_REG_INFLIGHT_CNT_INPLACE (PIC_BUF_INFLIGHT_REG_INFLIGHT_CNT_MASK << PIC_BUF_INFLIGHT_REG_INFLIGHT_CNT_SHIFT)

/*
 * Read response buffer address match, lower word.
 */
/* word BUF_MATCH_LOWER_REG: 64 bits */
#define PIC_BUF_MATCH_LOWER_REG_WIDTH                64 /* established */
#define PIC_BUF_MATCH_LOWER_REG_FILLED_SHIFT         63 /* established */
#define PIC_BUF_MATCH_LOWER_REG_FILLED_MASK          0x1ull
#define PIC_BUF_MATCH_LOWER_REG_FILLED_INPLACE (PIC_BUF_MATCH_LOWER_REG_FILLED_MASK << PIC_BUF_MATCH_LOWER_REG_FILLED_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_ARMED_SHIFT          62 /* established */
#define PIC_BUF_MATCH_LOWER_REG_ARMED_MASK           0x1ull
#define PIC_BUF_MATCH_LOWER_REG_ARMED_INPLACE (PIC_BUF_MATCH_LOWER_REG_ARMED_MASK << PIC_BUF_MATCH_LOWER_REG_ARMED_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_FLUSH_SHIFT          61 /* established */
#define PIC_BUF_MATCH_LOWER_REG_FLUSH_MASK           0x1ull
#define PIC_BUF_MATCH_LOWER_REG_FLUSH_INPLACE (PIC_BUF_MATCH_LOWER_REG_FLUSH_MASK << PIC_BUF_MATCH_LOWER_REG_FLUSH_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_XERR_SHIFT           60 /* established */
#define PIC_BUF_MATCH_LOWER_REG_XERR_MASK            0x1ull
#define PIC_BUF_MATCH_LOWER_REG_XERR_INPLACE (PIC_BUF_MATCH_LOWER_REG_XERR_MASK << PIC_BUF_MATCH_LOWER_REG_XERR_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_PKTERR_SHIFT         59 /* established */
#define PIC_BUF_MATCH_LOWER_REG_PKTERR_MASK          0x1ull
#define PIC_BUF_MATCH_LOWER_REG_PKTERR_INPLACE (PIC_BUF_MATCH_LOWER_REG_PKTERR_MASK << PIC_BUF_MATCH_LOWER_REG_PKTERR_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_TIMEOUT_SHIFT        58 /* established */
#define PIC_BUF_MATCH_LOWER_REG_TIMEOUT_MASK         0x1ull
#define PIC_BUF_MATCH_LOWER_REG_TIMEOUT_INPLACE (PIC_BUF_MATCH_LOWER_REG_TIMEOUT_MASK << PIC_BUF_MATCH_LOWER_REG_TIMEOUT_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_PREFETCH_SHIFT       57 /* established */
#define PIC_BUF_MATCH_LOWER_REG_PREFETCH_MASK        0x1ull
#define PIC_BUF_MATCH_LOWER_REG_PREFETCH_INPLACE (PIC_BUF_MATCH_LOWER_REG_PREFETCH_MASK << PIC_BUF_MATCH_LOWER_REG_PREFETCH_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_PRECISE_SHIFT        56 /* established */
#define PIC_BUF_MATCH_LOWER_REG_PRECISE_MASK         0x1ull
#define PIC_BUF_MATCH_LOWER_REG_PRECISE_INPLACE (PIC_BUF_MATCH_LOWER_REG_PRECISE_MASK << PIC_BUF_MATCH_LOWER_REG_PRECISE_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_DW_BE_SHIFT          48 /* established */
#define PIC_BUF_MATCH_LOWER_REG_DW_BE_MASK           0xffull
#define PIC_BUF_MATCH_LOWER_REG_DW_BE_INPLACE (PIC_BUF_MATCH_LOWER_REG_DW_BE_MASK << PIC_BUF_MATCH_LOWER_REG_DW_BE_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_UPP_ADDR_SHIFT       32 /* established */
#define PIC_BUF_MATCH_LOWER_REG_UPP_ADDR_MASK        0xffffull
#define PIC_BUF_MATCH_LOWER_REG_UPP_ADDR_INPLACE (PIC_BUF_MATCH_LOWER_REG_UPP_ADDR_MASK << PIC_BUF_MATCH_LOWER_REG_UPP_ADDR_SHIFT)
#define PIC_BUF_MATCH_LOWER_REG_LOW_ADDR_SHIFT       0 /* established */
#define PIC_BUF_MATCH_LOWER_REG_LOW_ADDR_MASK        0xffffffffull
#define PIC_BUF_MATCH_LOWER_REG_LOW_ADDR_INPLACE (PIC_BUF_MATCH_LOWER_REG_LOW_ADDR_MASK << PIC_BUF_MATCH_LOWER_REG_LOW_ADDR_SHIFT)

/*
 * Read response buffer address match, upper word: buffer state flags and the
 * upper address and byte enables.
 */
/* word BUF_MATCH_UPPER_REG: 64 bits */
#define PIC_BUF_MATCH_UPPER_REG_WIDTH                64 /* established */
#define PIC_BUF_MATCH_UPPER_REG_FILLED_SHIFT         31 /* established */
#define PIC_BUF_MATCH_UPPER_REG_FILLED_MASK          0x1ull
#define PIC_BUF_MATCH_UPPER_REG_FILLED_INPLACE (PIC_BUF_MATCH_UPPER_REG_FILLED_MASK << PIC_BUF_MATCH_UPPER_REG_FILLED_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_ARMED_SHIFT          30 /* established */
#define PIC_BUF_MATCH_UPPER_REG_ARMED_MASK           0x1ull
#define PIC_BUF_MATCH_UPPER_REG_ARMED_INPLACE (PIC_BUF_MATCH_UPPER_REG_ARMED_MASK << PIC_BUF_MATCH_UPPER_REG_ARMED_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_FLUSH_SHIFT          29 /* established */
#define PIC_BUF_MATCH_UPPER_REG_FLUSH_MASK           0x1ull
#define PIC_BUF_MATCH_UPPER_REG_FLUSH_INPLACE (PIC_BUF_MATCH_UPPER_REG_FLUSH_MASK << PIC_BUF_MATCH_UPPER_REG_FLUSH_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_XERR_SHIFT           28 /* established */
#define PIC_BUF_MATCH_UPPER_REG_XERR_MASK            0x1ull
#define PIC_BUF_MATCH_UPPER_REG_XERR_INPLACE (PIC_BUF_MATCH_UPPER_REG_XERR_MASK << PIC_BUF_MATCH_UPPER_REG_XERR_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_PKTERR_SHIFT         27 /* established */
#define PIC_BUF_MATCH_UPPER_REG_PKTERR_MASK          0x1ull
#define PIC_BUF_MATCH_UPPER_REG_PKTERR_INPLACE (PIC_BUF_MATCH_UPPER_REG_PKTERR_MASK << PIC_BUF_MATCH_UPPER_REG_PKTERR_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_TIMEOUT_SHIFT        26 /* established */
#define PIC_BUF_MATCH_UPPER_REG_TIMEOUT_MASK         0x1ull
#define PIC_BUF_MATCH_UPPER_REG_TIMEOUT_INPLACE (PIC_BUF_MATCH_UPPER_REG_TIMEOUT_MASK << PIC_BUF_MATCH_UPPER_REG_TIMEOUT_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_PREFETCH_SHIFT       25 /* established */
#define PIC_BUF_MATCH_UPPER_REG_PREFETCH_MASK        0x1ull
#define PIC_BUF_MATCH_UPPER_REG_PREFETCH_INPLACE (PIC_BUF_MATCH_UPPER_REG_PREFETCH_MASK << PIC_BUF_MATCH_UPPER_REG_PREFETCH_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_PRECISE_SHIFT        24 /* established */
#define PIC_BUF_MATCH_UPPER_REG_PRECISE_MASK         0x1ull
#define PIC_BUF_MATCH_UPPER_REG_PRECISE_INPLACE (PIC_BUF_MATCH_UPPER_REG_PRECISE_MASK << PIC_BUF_MATCH_UPPER_REG_PRECISE_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_DW_BE_SHIFT          16 /* established */
#define PIC_BUF_MATCH_UPPER_REG_DW_BE_MASK           0xffull
#define PIC_BUF_MATCH_UPPER_REG_DW_BE_INPLACE (PIC_BUF_MATCH_UPPER_REG_DW_BE_MASK << PIC_BUF_MATCH_UPPER_REG_DW_BE_SHIFT)
#define PIC_BUF_MATCH_UPPER_REG_UPP_ADDR_SHIFT       0 /* established */
#define PIC_BUF_MATCH_UPPER_REG_UPP_ADDR_MASK        0xffffull
#define PIC_BUF_MATCH_UPPER_REG_UPP_ADDR_INPLACE (PIC_BUF_MATCH_UPPER_REG_UPP_ADDR_MASK << PIC_BUF_MATCH_UPPER_REG_UPP_ADDR_SHIFT)

/*
 * Performance counter, per even buffer block: longest request latency in bus
 * clocks. A word write clears it.
 */
/* word BUF_MAX_LATENCY_REG: 64 bits */
#define PIC_BUF_MAX_LATENCY_REG_WIDTH                64 /* established */
#define PIC_BUF_MAX_LATENCY_REG_MAX_LATENCY_CNT_SHIFT 0 /* established */
#define PIC_BUF_MAX_LATENCY_REG_MAX_LATENCY_CNT_MASK 0xffffull
#define PIC_BUF_MAX_LATENCY_REG_MAX_LATENCY_CNT_INPLACE (PIC_BUF_MAX_LATENCY_REG_MAX_LATENCY_CNT_MASK << PIC_BUF_MAX_LATENCY_REG_MAX_LATENCY_CNT_SHIFT)

/*
 * Performance counter, per even buffer block: largest retry count for one
 * request. A word write clears it.
 */
/* word BUF_MAX_RETRY_REG: 64 bits */
#define PIC_BUF_MAX_RETRY_REG_WIDTH                  64 /* established */
#define PIC_BUF_MAX_RETRY_REG_MAX_RETRY_CNT_SHIFT    0 /* established */
#define PIC_BUF_MAX_RETRY_REG_MAX_RETRY_CNT_MASK     0xffffull
#define PIC_BUF_MAX_RETRY_REG_MAX_RETRY_CNT_INPLACE (PIC_BUF_MAX_RETRY_REG_MAX_RETRY_CNT_MASK << PIC_BUF_MAX_RETRY_REG_MAX_RETRY_CNT_SHIFT)

/*
 * Performance counter, per even buffer block: requests from the prefetcher. A
 * word write clears it.
 */
/* word BUF_PREFETCH_REG: 64 bits */
#define PIC_BUF_PREFETCH_REG_WIDTH                   64 /* established */
#define PIC_BUF_PREFETCH_REG_PREFETCH_CNT_SHIFT      0 /* established */
#define PIC_BUF_PREFETCH_REG_PREFETCH_CNT_MASK       0xffffull
#define PIC_BUF_PREFETCH_REG_PREFETCH_CNT_INPLACE (PIC_BUF_PREFETCH_REG_PREFETCH_CNT_MASK << PIC_BUF_PREFETCH_REG_PREFETCH_CNT_SHIFT)

/*
 * Performance counter, per even buffer block: PCI retries that matched the
 * buffer tag. A word write clears it.
 */
/* word BUF_TOTAL_RETRY_REG: 64 bits */
#define PIC_BUF_TOTAL_RETRY_REG_WIDTH                64 /* established */
#define PIC_BUF_TOTAL_RETRY_REG_RETRY_CNT_SHIFT      0 /* established */
#define PIC_BUF_TOTAL_RETRY_REG_RETRY_CNT_MASK       0xffffull
#define PIC_BUF_TOTAL_RETRY_REG_RETRY_CNT_INPLACE (PIC_BUF_TOTAL_RETRY_REG_RETRY_CNT_MASK << PIC_BUF_TOTAL_RETRY_REG_RETRY_CNT_SHIFT)

/*
 * PIO retry control: retry hold-off and retry count for programmed I/O to the
 * PCI bus. IRIX clears the low ten bits for one specific device pair (meaning
 * unknown).
 */
/* word BUS_TIMEOUT_REG: 64 bits */
#define PIC_BUS_TIMEOUT_REG_WIDTH                    64 /* established */
#define PIC_BUS_TIMEOUT_REG_PCI_RETRY_HLD_SHIFT      16 /* established */
#define PIC_BUS_TIMEOUT_REG_PCI_RETRY_HLD_MASK       0x1full
#define PIC_BUS_TIMEOUT_REG_PCI_RETRY_HLD_INPLACE (PIC_BUS_TIMEOUT_REG_PCI_RETRY_HLD_MASK << PIC_BUS_TIMEOUT_REG_PCI_RETRY_HLD_SHIFT)
#define PIC_BUS_TIMEOUT_REG_PCI_RETRY_CNT_SHIFT      0 /* established */
#define PIC_BUS_TIMEOUT_REG_PCI_RETRY_CNT_MASK       0x3ffull
#define PIC_BUS_TIMEOUT_REG_PCI_RETRY_CNT_INPLACE (PIC_BUS_TIMEOUT_REG_PCI_RETRY_CNT_MASK << PIC_BUS_TIMEOUT_REG_PCI_RETRY_CNT_SHIFT)

/*
 * Held Crosstalk command word. Same layout is used for the bus-side error word
 * and the link-side error word (request FIFO overflow, unexpected response).
 */
/* word CMD_WORD_REG: 64 bits */
#define PIC_CMD_WORD_REG_WIDTH                       64 /* established */
#define PIC_CMD_WORD_REG_DIDN_SHIFT                  28 /* established */
#define PIC_CMD_WORD_REG_DIDN_MASK                   0xfull
#define PIC_CMD_WORD_REG_DIDN_INPLACE (PIC_CMD_WORD_REG_DIDN_MASK << PIC_CMD_WORD_REG_DIDN_SHIFT)
#define PIC_CMD_WORD_REG_SIDN_SHIFT                  24 /* established */
#define PIC_CMD_WORD_REG_SIDN_MASK                   0xfull
#define PIC_CMD_WORD_REG_SIDN_INPLACE (PIC_CMD_WORD_REG_SIDN_MASK << PIC_CMD_WORD_REG_SIDN_SHIFT)
#define PIC_CMD_WORD_REG_PACTYP_SHIFT                20 /* established */
#define PIC_CMD_WORD_REG_PACTYP_MASK                 0xfull
#define PIC_CMD_WORD_REG_PACTYP_INPLACE (PIC_CMD_WORD_REG_PACTYP_MASK << PIC_CMD_WORD_REG_PACTYP_SHIFT)
#define PIC_CMD_WORD_REG_TNUM_SHIFT                  15 /* established */
#define PIC_CMD_WORD_REG_TNUM_MASK                   0x1full
#define PIC_CMD_WORD_REG_TNUM_INPLACE (PIC_CMD_WORD_REG_TNUM_MASK << PIC_CMD_WORD_REG_TNUM_SHIFT)
#define PIC_CMD_WORD_REG_COHERENT_SHIFT              14 /* established */
#define PIC_CMD_WORD_REG_COHERENT_MASK               0x1ull
#define PIC_CMD_WORD_REG_COHERENT_INPLACE (PIC_CMD_WORD_REG_COHERENT_MASK << PIC_CMD_WORD_REG_COHERENT_SHIFT)
#define PIC_CMD_WORD_REG_DS_SHIFT                    12 /* established */
#define PIC_CMD_WORD_REG_DS_MASK                     0x3ull
#define PIC_CMD_WORD_REG_DS_INPLACE (PIC_CMD_WORD_REG_DS_MASK << PIC_CMD_WORD_REG_DS_SHIFT)
#define PIC_CMD_WORD_REG_GBR_SHIFT                   11 /* established */
#define PIC_CMD_WORD_REG_GBR_MASK                    0x1ull
#define PIC_CMD_WORD_REG_GBR_INPLACE (PIC_CMD_WORD_REG_GBR_MASK << PIC_CMD_WORD_REG_GBR_SHIFT)
#define PIC_CMD_WORD_REG_VBPM_SHIFT                  10 /* established */
#define PIC_CMD_WORD_REG_VBPM_MASK                   0x1ull
#define PIC_CMD_WORD_REG_VBPM_INPLACE (PIC_CMD_WORD_REG_VBPM_MASK << PIC_CMD_WORD_REG_VBPM_SHIFT)
#define PIC_CMD_WORD_REG_ERROR_SHIFT                 9 /* established */
#define PIC_CMD_WORD_REG_ERROR_MASK                  0x1ull
#define PIC_CMD_WORD_REG_ERROR_INPLACE (PIC_CMD_WORD_REG_ERROR_MASK << PIC_CMD_WORD_REG_ERROR_SHIFT)
#define PIC_CMD_WORD_REG_BARRIER_SHIFT               8 /* established */
#define PIC_CMD_WORD_REG_BARRIER_MASK                0x1ull
#define PIC_CMD_WORD_REG_BARRIER_INPLACE (PIC_CMD_WORD_REG_BARRIER_MASK << PIC_CMD_WORD_REG_BARRIER_SHIFT)

/*
 * Widget control. Fields from the register structure plus the mask definitions
 * in bridge.h for the bits the structure leaves reserved (bus, device and
 * function number, parity enables, no-snoop and relaxed ordering). IRIX attach
 * writes bits 55:48, 31:29 and 21 (see README, "Control register").
 */
/* word CONTROL_REG: 64 bits */
#define PIC_CONTROL_REG_WIDTH                        64 /* established */
#define PIC_CONTROL_REG_NO_SNOOP_SHIFT               62 /* established */
#define PIC_CONTROL_REG_NO_SNOOP_MASK                0x1ull
#define PIC_CONTROL_REG_NO_SNOOP_INPLACE (PIC_CONTROL_REG_NO_SNOOP_MASK << PIC_CONTROL_REG_NO_SNOOP_SHIFT)
#define PIC_CONTROL_REG_RELAX_ORDER_SHIFT            61 /* established */
#define PIC_CONTROL_REG_RELAX_ORDER_MASK             0x1ull
#define PIC_CONTROL_REG_RELAX_ORDER_INPLACE (PIC_CONTROL_REG_RELAX_ORDER_MASK << PIC_CONTROL_REG_RELAX_ORDER_SHIFT)
#define PIC_CONTROL_REG_BUS_NUM_SHIFT                48 /* established */
#define PIC_CONTROL_REG_BUS_NUM_MASK                 0xffull
#define PIC_CONTROL_REG_BUS_NUM_INPLACE (PIC_CONTROL_REG_BUS_NUM_MASK << PIC_CONTROL_REG_BUS_NUM_SHIFT)
#define PIC_CONTROL_REG_DEV_NUM_SHIFT                43 /* established */
#define PIC_CONTROL_REG_DEV_NUM_MASK                 0x1full
#define PIC_CONTROL_REG_DEV_NUM_INPLACE (PIC_CONTROL_REG_DEV_NUM_MASK << PIC_CONTROL_REG_DEV_NUM_SHIFT)
#define PIC_CONTROL_REG_FUN_NUM_SHIFT                40 /* established */
#define PIC_CONTROL_REG_FUN_NUM_MASK                 0x7ull
#define PIC_CONTROL_REG_FUN_NUM_INPLACE (PIC_CONTROL_REG_FUN_NUM_MASK << PIC_CONTROL_REG_FUN_NUM_SHIFT)
#define PIC_CONTROL_REG_PAR_EN_ATE_SHIFT             31 /* established */
#define PIC_CONTROL_REG_PAR_EN_ATE_MASK              0x1ull
#define PIC_CONTROL_REG_PAR_EN_ATE_INPLACE (PIC_CONTROL_REG_PAR_EN_ATE_MASK << PIC_CONTROL_REG_PAR_EN_ATE_SHIFT)
#define PIC_CONTROL_REG_PAR_EN_RESP_SHIFT            30 /* established */
#define PIC_CONTROL_REG_PAR_EN_RESP_MASK             0x1ull
#define PIC_CONTROL_REG_PAR_EN_RESP_INPLACE (PIC_CONTROL_REG_PAR_EN_RESP_MASK << PIC_CONTROL_REG_PAR_EN_RESP_SHIFT)
#define PIC_CONTROL_REG_PAR_EN_REQ_SHIFT             29 /* established */
#define PIC_CONTROL_REG_PAR_EN_REQ_MASK              0x1ull
#define PIC_CONTROL_REG_PAR_EN_REQ_INPLACE (PIC_CONTROL_REG_PAR_EN_REQ_MASK << PIC_CONTROL_REG_PAR_EN_REQ_SHIFT)
#define PIC_CONTROL_REG_RST_PIN_N_SHIFT              24 /* established */
#define PIC_CONTROL_REG_RST_PIN_N_MASK               0xfull
#define PIC_CONTROL_REG_RST_PIN_N_INPLACE (PIC_CONTROL_REG_RST_PIN_N_MASK << PIC_CONTROL_REG_RST_PIN_N_SHIFT)
#define PIC_CONTROL_REG_MEM_SWAP_SHIFT               22 /* established */
#define PIC_CONTROL_REG_MEM_SWAP_MASK                0x1ull
#define PIC_CONTROL_REG_MEM_SWAP_INPLACE (PIC_CONTROL_REG_MEM_SWAP_MASK << PIC_CONTROL_REG_MEM_SWAP_SHIFT)
#define PIC_CONTROL_REG_PAGE_SIZE_SHIFT              21 /* established */
#define PIC_CONTROL_REG_PAGE_SIZE_MASK               0x1ull
#define PIC_CONTROL_REG_PAGE_SIZE_INPLACE (PIC_CONTROL_REG_PAGE_SIZE_MASK << PIC_CONTROL_REG_PAGE_SIZE_SHIFT)
#define PIC_CONTROL_REG_F_BAD_PKT_SHIFT              16 /* established */
#define PIC_CONTROL_REG_F_BAD_PKT_MASK               0x1ull
#define PIC_CONTROL_REG_F_BAD_PKT_INPLACE (PIC_CONTROL_REG_F_BAD_PKT_MASK << PIC_CONTROL_REG_F_BAD_PKT_SHIFT)
#define PIC_CONTROL_REG_LLP_XBAR_CRD_SHIFT           12 /* established */
#define PIC_CONTROL_REG_LLP_XBAR_CRD_MASK            0xfull
#define PIC_CONTROL_REG_LLP_XBAR_CRD_INPLACE (PIC_CONTROL_REG_LLP_XBAR_CRD_MASK << PIC_CONTROL_REG_LLP_XBAR_CRD_SHIFT)
#define PIC_CONTROL_REG_CLR_RLLP_CNT_SHIFT           11 /* established */
#define PIC_CONTROL_REG_CLR_RLLP_CNT_MASK            0x1ull
#define PIC_CONTROL_REG_CLR_RLLP_CNT_INPLACE (PIC_CONTROL_REG_CLR_RLLP_CNT_MASK << PIC_CONTROL_REG_CLR_RLLP_CNT_SHIFT)
#define PIC_CONTROL_REG_CLR_TLLP_CNT_SHIFT           10 /* established */
#define PIC_CONTROL_REG_CLR_TLLP_CNT_MASK            0x1ull
#define PIC_CONTROL_REG_CLR_TLLP_CNT_INPLACE (PIC_CONTROL_REG_CLR_TLLP_CNT_MASK << PIC_CONTROL_REG_CLR_TLLP_CNT_SHIFT)
#define PIC_CONTROL_REG_SYS_END_SHIFT                9 /* established */
#define PIC_CONTROL_REG_SYS_END_MASK                 0x1ull
#define PIC_CONTROL_REG_SYS_END_INPLACE (PIC_CONTROL_REG_SYS_END_MASK << PIC_CONTROL_REG_SYS_END_SHIFT)
#define PIC_CONTROL_REG_PCI_SPEED_SHIFT              4 /* established */
#define PIC_CONTROL_REG_PCI_SPEED_MASK               0x3ull
#define PIC_CONTROL_REG_PCI_SPEED_INPLACE (PIC_CONTROL_REG_PCI_SPEED_MASK << PIC_CONTROL_REG_PCI_SPEED_SHIFT)
#define PIC_CONTROL_REG_WIDGET_ID_SHIFT              0 /* established */
#define PIC_CONTROL_REG_WIDGET_ID_MASK               0xfull
#define PIC_CONTROL_REG_WIDGET_ID_INPLACE (PIC_CONTROL_REG_WIDGET_ID_MASK << PIC_CONTROL_REG_WIDGET_ID_SHIFT)

/*
 * Per-device control. Bit 19 is swap_direct (README, "Device-register bit 19").
 */
/* word DEVICE_REG: 64 bits */
#define PIC_DEVICE_REG_WIDTH                         64 /* established */
#define PIC_DEVICE_REG_EN_VIRTUAL1_SHIFT             29 /* established */
#define PIC_DEVICE_REG_EN_VIRTUAL1_MASK              0x1ull
#define PIC_DEVICE_REG_EN_VIRTUAL1_INPLACE (PIC_DEVICE_REG_EN_VIRTUAL1_MASK << PIC_DEVICE_REG_EN_VIRTUAL1_SHIFT)
#define PIC_DEVICE_REG_EN_ERROR_LOCK_SHIFT           28 /* established */
#define PIC_DEVICE_REG_EN_ERROR_LOCK_MASK            0x1ull
#define PIC_DEVICE_REG_EN_ERROR_LOCK_INPLACE (PIC_DEVICE_REG_EN_ERROR_LOCK_MASK << PIC_DEVICE_REG_EN_ERROR_LOCK_SHIFT)
#define PIC_DEVICE_REG_EN_PAGE_CHK_SHIFT             27 /* established */
#define PIC_DEVICE_REG_EN_PAGE_CHK_MASK              0x1ull
#define PIC_DEVICE_REG_EN_PAGE_CHK_INPLACE (PIC_DEVICE_REG_EN_PAGE_CHK_MASK << PIC_DEVICE_REG_EN_PAGE_CHK_SHIFT)
#define PIC_DEVICE_REG_FORCE_PCI_PAR_SHIFT           26 /* established */
#define PIC_DEVICE_REG_FORCE_PCI_PAR_MASK            0x1ull
#define PIC_DEVICE_REG_FORCE_PCI_PAR_INPLACE (PIC_DEVICE_REG_FORCE_PCI_PAR_MASK << PIC_DEVICE_REG_FORCE_PCI_PAR_SHIFT)
#define PIC_DEVICE_REG_EN_VIRTUAL0_SHIFT             25 /* established */
#define PIC_DEVICE_REG_EN_VIRTUAL0_MASK              0x1ull
#define PIC_DEVICE_REG_EN_VIRTUAL0_INPLACE (PIC_DEVICE_REG_EN_VIRTUAL0_MASK << PIC_DEVICE_REG_EN_VIRTUAL0_SHIFT)
#define PIC_DEVICE_REG_DIR_WRT_GEN_SHIFT             23 /* established */
#define PIC_DEVICE_REG_DIR_WRT_GEN_MASK              0x1ull
#define PIC_DEVICE_REG_DIR_WRT_GEN_INPLACE (PIC_DEVICE_REG_DIR_WRT_GEN_MASK << PIC_DEVICE_REG_DIR_WRT_GEN_SHIFT)
#define PIC_DEVICE_REG_DEV_SIZE_SHIFT                22 /* established */
#define PIC_DEVICE_REG_DEV_SIZE_MASK                 0x1ull
#define PIC_DEVICE_REG_DEV_SIZE_INPLACE (PIC_DEVICE_REG_DEV_SIZE_MASK << PIC_DEVICE_REG_DEV_SIZE_SHIFT)
#define PIC_DEVICE_REG_REAL_TIME_SHIFT               21 /* established */
#define PIC_DEVICE_REG_REAL_TIME_MASK                0x1ull
#define PIC_DEVICE_REG_REAL_TIME_INPLACE (PIC_DEVICE_REG_REAL_TIME_MASK << PIC_DEVICE_REG_REAL_TIME_SHIFT)
#define PIC_DEVICE_REG_SWAP_DIRECT_SHIFT             19 /* established */
#define PIC_DEVICE_REG_SWAP_DIRECT_MASK              0x1ull
#define PIC_DEVICE_REG_SWAP_DIRECT_INPLACE (PIC_DEVICE_REG_SWAP_DIRECT_MASK << PIC_DEVICE_REG_SWAP_DIRECT_SHIFT)
#define PIC_DEVICE_REG_PREFETCH_SHIFT                18 /* established */
#define PIC_DEVICE_REG_PREFETCH_MASK                 0x1ull
#define PIC_DEVICE_REG_PREFETCH_INPLACE (PIC_DEVICE_REG_PREFETCH_MASK << PIC_DEVICE_REG_PREFETCH_SHIFT)
#define PIC_DEVICE_REG_PRECISE_SHIFT                 17 /* established */
#define PIC_DEVICE_REG_PRECISE_MASK                  0x1ull
#define PIC_DEVICE_REG_PRECISE_INPLACE (PIC_DEVICE_REG_PRECISE_MASK << PIC_DEVICE_REG_PRECISE_SHIFT)
#define PIC_DEVICE_REG_COHERENT_SHIFT                16 /* established */
#define PIC_DEVICE_REG_COHERENT_MASK                 0x1ull
#define PIC_DEVICE_REG_COHERENT_INPLACE (PIC_DEVICE_REG_COHERENT_MASK << PIC_DEVICE_REG_COHERENT_SHIFT)
#define PIC_DEVICE_REG_BARRIER_SHIFT                 15 /* established */
#define PIC_DEVICE_REG_BARRIER_MASK                  0x1ull
#define PIC_DEVICE_REG_BARRIER_INPLACE (PIC_DEVICE_REG_BARRIER_MASK << PIC_DEVICE_REG_BARRIER_SHIFT)
#define PIC_DEVICE_REG_GBR_SHIFT                     14 /* established */
#define PIC_DEVICE_REG_GBR_MASK                      0x1ull
#define PIC_DEVICE_REG_GBR_INPLACE (PIC_DEVICE_REG_GBR_MASK << PIC_DEVICE_REG_GBR_SHIFT)
#define PIC_DEVICE_REG_DEV_SWAP_SHIFT                13 /* established */
#define PIC_DEVICE_REG_DEV_SWAP_MASK                 0x1ull
#define PIC_DEVICE_REG_DEV_SWAP_INPLACE (PIC_DEVICE_REG_DEV_SWAP_MASK << PIC_DEVICE_REG_DEV_SWAP_SHIFT)
#define PIC_DEVICE_REG_DEV_IO_MEM_SHIFT              12 /* established */
#define PIC_DEVICE_REG_DEV_IO_MEM_MASK               0x1ull
#define PIC_DEVICE_REG_DEV_IO_MEM_INPLACE (PIC_DEVICE_REG_DEV_IO_MEM_MASK << PIC_DEVICE_REG_DEV_IO_MEM_SHIFT)
#define PIC_DEVICE_REG_DEV_OFF_SHIFT                 0 /* established */
#define PIC_DEVICE_REG_DEV_OFF_MASK                  0xfffull
#define PIC_DEVICE_REG_DEV_OFF_INPLACE (PIC_DEVICE_REG_DEV_OFF_MASK << PIC_DEVICE_REG_DEV_OFF_SHIFT)

/*
 * Direct map: relocates a 2 GiB PCI window onto Crosstalk. IRIX writes widget
 * at 23:20, offset at 16:0 (in units of 2 GiB) and bit 17 only for a
 * translation equal to 0x20000000.
 */
/* word DIR_MAP_REG: 64 bits */
#define PIC_DIR_MAP_REG_WIDTH                        64 /* established */
#define PIC_DIR_MAP_REG_DIR_W_ID_SHIFT               20 /* established */
#define PIC_DIR_MAP_REG_DIR_W_ID_MASK                0xfull
#define PIC_DIR_MAP_REG_DIR_W_ID_INPLACE (PIC_DIR_MAP_REG_DIR_W_ID_MASK << PIC_DIR_MAP_REG_DIR_W_ID_SHIFT)
#define PIC_DIR_MAP_REG_DIR_ADD512_SHIFT             17 /* established */
#define PIC_DIR_MAP_REG_DIR_ADD512_MASK              0x1ull
#define PIC_DIR_MAP_REG_DIR_ADD512_INPLACE (PIC_DIR_MAP_REG_DIR_ADD512_MASK << PIC_DIR_MAP_REG_DIR_ADD512_SHIFT)
#define PIC_DIR_MAP_REG_DIR_OFF_SHIFT                0 /* established */
#define PIC_DIR_MAP_REG_DIR_OFF_MASK                 0x1ffffull
#define PIC_DIR_MAP_REG_DIR_OFF_INPLACE (PIC_DIR_MAP_REG_DIR_OFF_MASK << PIC_DIR_MAP_REG_DIR_OFF_SHIFT)

/*
 * Error interrupt view: records an error whether or not it is enabled. Cleared
 * by any write to the interrupt reset register.
 */
/* word ERR_INT_VIEW_REG: 64 bits */
#define PIC_ERR_INT_VIEW_REG_WIDTH                   64 /* established */
#define PIC_ERR_INT_VIEW_REG_INT_RAM_PERR_SHIFT      41 /* established */
#define PIC_ERR_INT_VIEW_REG_INT_RAM_PERR_MASK       0x1ull
#define PIC_ERR_INT_VIEW_REG_INT_RAM_PERR_INPLACE (PIC_ERR_INT_VIEW_REG_INT_RAM_PERR_MASK << PIC_ERR_INT_VIEW_REG_INT_RAM_PERR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_BUS_ARB_BROKE_SHIFT     40 /* established */
#define PIC_ERR_INT_VIEW_REG_BUS_ARB_BROKE_MASK      0x1ull
#define PIC_ERR_INT_VIEW_REG_BUS_ARB_BROKE_INPLACE (PIC_ERR_INT_VIEW_REG_BUS_ARB_BROKE_MASK << PIC_ERR_INT_VIEW_REG_BUS_ARB_BROKE_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_REQ_TOUT_SHIFT    39 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_REQ_TOUT_MASK     0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_REQ_TOUT_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_REQ_TOUT_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_REQ_TOUT_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_TABORT_SHIFT      38 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_TABORT_MASK       0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_TABORT_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_TABORT_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_TABORT_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_PERR_SHIFT        37 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_PERR_MASK         0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_PERR_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_PERR_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_PERR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_SERR_SHIFT        36 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_SERR_MASK         0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_SERR_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_SERR_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_SERR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_MRETRY_SHIFT      35 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_MRETRY_MASK       0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_MRETRY_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_MRETRY_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_MRETRY_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_MTOUT_SHIFT       34 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_MTOUT_MASK        0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_MTOUT_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_MTOUT_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_MTOUT_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_DA_PARITY_SHIFT   33 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_DA_PARITY_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_DA_PARITY_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_DA_PARITY_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_DA_PARITY_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_X_AD_PARITY_SHIFT   32 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_X_AD_PARITY_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_X_AD_PARITY_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_X_AD_PARITY_MASK << PIC_ERR_INT_VIEW_REG_PCI_X_AD_PARITY_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PMU_PAGE_FAULT_SHIFT    30 /* established */
#define PIC_ERR_INT_VIEW_REG_PMU_PAGE_FAULT_MASK     0x1ull
#define PIC_ERR_INT_VIEW_REG_PMU_PAGE_FAULT_INPLACE (PIC_ERR_INT_VIEW_REG_PMU_PAGE_FAULT_MASK << PIC_ERR_INT_VIEW_REG_PMU_PAGE_FAULT_SHIFT)
#define PIC_ERR_INT_VIEW_REG_UNEXPECTED_RESP_SHIFT   29 /* established */
#define PIC_ERR_INT_VIEW_REG_UNEXPECTED_RESP_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_UNEXPECTED_RESP_INPLACE (PIC_ERR_INT_VIEW_REG_UNEXPECTED_RESP_MASK << PIC_ERR_INT_VIEW_REG_UNEXPECTED_RESP_SHIFT)
#define PIC_ERR_INT_VIEW_REG_BAD_XRESP_PACKET_SHIFT  28 /* established */
#define PIC_ERR_INT_VIEW_REG_BAD_XRESP_PACKET_MASK   0x1ull
#define PIC_ERR_INT_VIEW_REG_BAD_XRESP_PACKET_INPLACE (PIC_ERR_INT_VIEW_REG_BAD_XRESP_PACKET_MASK << PIC_ERR_INT_VIEW_REG_BAD_XRESP_PACKET_SHIFT)
#define PIC_ERR_INT_VIEW_REG_BAD_XREQ_PACKET_SHIFT   27 /* established */
#define PIC_ERR_INT_VIEW_REG_BAD_XREQ_PACKET_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_BAD_XREQ_PACKET_INPLACE (PIC_ERR_INT_VIEW_REG_BAD_XREQ_PACKET_MASK << PIC_ERR_INT_VIEW_REG_BAD_XREQ_PACKET_SHIFT)
#define PIC_ERR_INT_VIEW_REG_RESP_XTALK_ERROR_SHIFT  26 /* established */
#define PIC_ERR_INT_VIEW_REG_RESP_XTALK_ERROR_MASK   0x1ull
#define PIC_ERR_INT_VIEW_REG_RESP_XTALK_ERROR_INPLACE (PIC_ERR_INT_VIEW_REG_RESP_XTALK_ERROR_MASK << PIC_ERR_INT_VIEW_REG_RESP_XTALK_ERROR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_REQ_XTALK_ERROR_SHIFT   25 /* established */
#define PIC_ERR_INT_VIEW_REG_REQ_XTALK_ERROR_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_REQ_XTALK_ERROR_INPLACE (PIC_ERR_INT_VIEW_REG_REQ_XTALK_ERROR_MASK << PIC_ERR_INT_VIEW_REG_REQ_XTALK_ERROR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_INVALID_ACCESS_SHIFT    24 /* established */
#define PIC_ERR_INT_VIEW_REG_INVALID_ACCESS_MASK     0x1ull
#define PIC_ERR_INT_VIEW_REG_INVALID_ACCESS_INPLACE (PIC_ERR_INT_VIEW_REG_INVALID_ACCESS_MASK << PIC_ERR_INT_VIEW_REG_INVALID_ACCESS_SHIFT)
#define PIC_ERR_INT_VIEW_REG_UNSUPPORTED_XOP_SHIFT   23 /* established */
#define PIC_ERR_INT_VIEW_REG_UNSUPPORTED_XOP_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_UNSUPPORTED_XOP_INPLACE (PIC_ERR_INT_VIEW_REG_UNSUPPORTED_XOP_MASK << PIC_ERR_INT_VIEW_REG_UNSUPPORTED_XOP_SHIFT)
#define PIC_ERR_INT_VIEW_REG_XREQ_FIFO_OFLOW_SHIFT   22 /* established */
#define PIC_ERR_INT_VIEW_REG_XREQ_FIFO_OFLOW_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_XREQ_FIFO_OFLOW_INPLACE (PIC_ERR_INT_VIEW_REG_XREQ_FIFO_OFLOW_MASK << PIC_ERR_INT_VIEW_REG_XREQ_FIFO_OFLOW_SHIFT)
#define PIC_ERR_INT_VIEW_REG_LLP_REC_SNERROR_SHIFT   21 /* established */
#define PIC_ERR_INT_VIEW_REG_LLP_REC_SNERROR_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_LLP_REC_SNERROR_INPLACE (PIC_ERR_INT_VIEW_REG_LLP_REC_SNERROR_MASK << PIC_ERR_INT_VIEW_REG_LLP_REC_SNERROR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_LLP_REC_CBERROR_SHIFT   20 /* established */
#define PIC_ERR_INT_VIEW_REG_LLP_REC_CBERROR_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_LLP_REC_CBERROR_INPLACE (PIC_ERR_INT_VIEW_REG_LLP_REC_CBERROR_MASK << PIC_ERR_INT_VIEW_REG_LLP_REC_CBERROR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_LLP_RCTY_SHIFT          19 /* established */
#define PIC_ERR_INT_VIEW_REG_LLP_RCTY_MASK           0x1ull
#define PIC_ERR_INT_VIEW_REG_LLP_RCTY_INPLACE (PIC_ERR_INT_VIEW_REG_LLP_RCTY_MASK << PIC_ERR_INT_VIEW_REG_LLP_RCTY_SHIFT)
#define PIC_ERR_INT_VIEW_REG_LLP_TX_RETRY_SHIFT      18 /* established */
#define PIC_ERR_INT_VIEW_REG_LLP_TX_RETRY_MASK       0x1ull
#define PIC_ERR_INT_VIEW_REG_LLP_TX_RETRY_INPLACE (PIC_ERR_INT_VIEW_REG_LLP_TX_RETRY_MASK << PIC_ERR_INT_VIEW_REG_LLP_TX_RETRY_SHIFT)
#define PIC_ERR_INT_VIEW_REG_LLP_TCTY_SHIFT          17 /* established */
#define PIC_ERR_INT_VIEW_REG_LLP_TCTY_MASK           0x1ull
#define PIC_ERR_INT_VIEW_REG_LLP_TCTY_INPLACE (PIC_ERR_INT_VIEW_REG_LLP_TCTY_MASK << PIC_ERR_INT_VIEW_REG_LLP_TCTY_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_ABORT_SHIFT         15 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_ABORT_MASK          0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_ABORT_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_ABORT_MASK << PIC_ERR_INT_VIEW_REG_PCI_ABORT_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_PARITY_SHIFT        14 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_PARITY_MASK         0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_PARITY_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_PARITY_MASK << PIC_ERR_INT_VIEW_REG_PCI_PARITY_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_SERR_SHIFT          13 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_SERR_MASK           0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_SERR_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_SERR_MASK << PIC_ERR_INT_VIEW_REG_PCI_SERR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_PERR_SHIFT          12 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_PERR_MASK           0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_PERR_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_PERR_MASK << PIC_ERR_INT_VIEW_REG_PCI_PERR_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_MASTER_TOUT_SHIFT   11 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_MASTER_TOUT_MASK    0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_MASTER_TOUT_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_MASTER_TOUT_MASK << PIC_ERR_INT_VIEW_REG_PCI_MASTER_TOUT_SHIFT)
#define PIC_ERR_INT_VIEW_REG_PCI_RETRY_CNT_SHIFT     10 /* established */
#define PIC_ERR_INT_VIEW_REG_PCI_RETRY_CNT_MASK      0x1ull
#define PIC_ERR_INT_VIEW_REG_PCI_RETRY_CNT_INPLACE (PIC_ERR_INT_VIEW_REG_PCI_RETRY_CNT_MASK << PIC_ERR_INT_VIEW_REG_PCI_RETRY_CNT_SHIFT)
#define PIC_ERR_INT_VIEW_REG_XREAD_REQ_TOUT_SHIFT    9 /* established */
#define PIC_ERR_INT_VIEW_REG_XREAD_REQ_TOUT_MASK     0x1ull
#define PIC_ERR_INT_VIEW_REG_XREAD_REQ_TOUT_INPLACE (PIC_ERR_INT_VIEW_REG_XREAD_REQ_TOUT_MASK << PIC_ERR_INT_VIEW_REG_XREAD_REQ_TOUT_SHIFT)

/*
 * Widget error address, lower word: the address held when a bus-side error is
 * logged; bits 47:32 repeat the upper word.
 */
/* word ERR_LOWER_REG: 64 bits */
#define PIC_ERR_LOWER_REG_WIDTH                      64 /* established */
#define PIC_ERR_LOWER_REG_UPP_ADDR_SHIFT             32 /* established */
#define PIC_ERR_LOWER_REG_UPP_ADDR_MASK              0xffffull
#define PIC_ERR_LOWER_REG_UPP_ADDR_INPLACE (PIC_ERR_LOWER_REG_UPP_ADDR_MASK << PIC_ERR_LOWER_REG_UPP_ADDR_SHIFT)
#define PIC_ERR_LOWER_REG_LOW_ADDR_SHIFT             0 /* established */
#define PIC_ERR_LOWER_REG_LOW_ADDR_MASK              0xffffffffull
#define PIC_ERR_LOWER_REG_LOW_ADDR_INPLACE (PIC_ERR_LOWER_REG_LOW_ADDR_MASK << PIC_ERR_LOWER_REG_LOW_ADDR_SHIFT)

/*
 * Widget error address, upper word: the upper 16 address bits held when a
 * bus-side error is logged. Held until the error group is cleared.
 */
/* word ERR_UPPER_REG: 64 bits */
#define PIC_ERR_UPPER_REG_WIDTH                      64 /* established */
#define PIC_ERR_UPPER_REG_UPP_ADDR_SHIFT             0 /* established */
#define PIC_ERR_UPPER_REG_UPP_ADDR_MASK              0xffffull
#define PIC_ERR_UPPER_REG_UPP_ADDR_INPLACE (PIC_ERR_UPPER_REG_UPP_ADDR_MASK << PIC_ERR_UPPER_REG_UPP_ADDR_SHIFT)

/*
 * Widget identification. Layout of the JTAG-style identification word:
 * revision, part number, manufacturer. Bit 0 has no field in the header. The
 * compare value in the SN2 PROM for the low twelve bits is 0x049, which would
 * make bit 0 read one (inferred, see README).
 */
/* word ID_REG: 64 bits */
#define PIC_ID_REG_WIDTH                             64 /* established */
#define PIC_ID_REG_REV_NUM_SHIFT                     28 /* established */
#define PIC_ID_REG_REV_NUM_MASK                      0xfull
#define PIC_ID_REG_REV_NUM_INPLACE (PIC_ID_REG_REV_NUM_MASK << PIC_ID_REG_REV_NUM_SHIFT)
#define PIC_ID_REG_PART_NUM_SHIFT                    12 /* established */
#define PIC_ID_REG_PART_NUM_MASK                     0xffffull
#define PIC_ID_REG_PART_NUM_INPLACE (PIC_ID_REG_PART_NUM_MASK << PIC_ID_REG_PART_NUM_SHIFT)
#define PIC_ID_REG_MFG_NUM_SHIFT                     1 /* established */
#define PIC_ID_REG_MFG_NUM_MASK                      0x7ffull
#define PIC_ID_REG_MFG_NUM_INPLACE (PIC_ID_REG_MFG_NUM_MASK << PIC_ID_REG_MFG_NUM_SHIFT)

/*
 * Per-pin host address: 48-bit destination address and the 8-bit vector (bit
 * position) in the host register.
 */
/* word INT_ADDR_REG: 64 bits */
#define PIC_INT_ADDR_REG_WIDTH                       64 /* established */
#define PIC_INT_ADDR_REG_INT_FLD_SHIFT               48 /* established */
#define PIC_INT_ADDR_REG_INT_FLD_MASK                0xffull
#define PIC_INT_ADDR_REG_INT_FLD_INPLACE (PIC_INT_ADDR_REG_INT_FLD_MASK << PIC_INT_ADDR_REG_INT_FLD_SHIFT)
#define PIC_INT_ADDR_REG_INT_ADDR_SHIFT              0 /* established */
#define PIC_INT_ADDR_REG_INT_ADDR_MASK               0xffffffffffffull
#define PIC_INT_ADDR_REG_INT_ADDR_INPLACE (PIC_INT_ADDR_REG_INT_ADDR_MASK << PIC_INT_ADDR_REG_INT_ADDR_SHIFT)

/*
 * Interrupt destination, lower word: full destination address and the target
 * widget. IRIX reads and writes target widget bits 51:48.
 */
/* word INT_DEST_LOWER_REG: 64 bits */
#define PIC_INT_DEST_LOWER_REG_WIDTH                 64 /* established */
#define PIC_INT_DEST_LOWER_REG_TARGET_ID_SHIFT       48 /* established */
#define PIC_INT_DEST_LOWER_REG_TARGET_ID_MASK        0xfull
#define PIC_INT_DEST_LOWER_REG_TARGET_ID_INPLACE (PIC_INT_DEST_LOWER_REG_TARGET_ID_MASK << PIC_INT_DEST_LOWER_REG_TARGET_ID_SHIFT)
#define PIC_INT_DEST_LOWER_REG_UPP_ADDR_SHIFT        32 /* established */
#define PIC_INT_DEST_LOWER_REG_UPP_ADDR_MASK         0xffffull
#define PIC_INT_DEST_LOWER_REG_UPP_ADDR_INPLACE (PIC_INT_DEST_LOWER_REG_UPP_ADDR_MASK << PIC_INT_DEST_LOWER_REG_UPP_ADDR_SHIFT)
#define PIC_INT_DEST_LOWER_REG_LOW_ADDR_SHIFT        0 /* established */
#define PIC_INT_DEST_LOWER_REG_LOW_ADDR_MASK         0xffffffffull
#define PIC_INT_DEST_LOWER_REG_LOW_ADDR_INPLACE (PIC_INT_DEST_LOWER_REG_LOW_ADDR_MASK << PIC_INT_DEST_LOWER_REG_LOW_ADDR_SHIFT)

/*
 * Interrupt destination, upper word: the high 16 bits of the host address plus
 * the target widget.
 */
/* word INT_DEST_UPPER_REG: 64 bits */
#define PIC_INT_DEST_UPPER_REG_WIDTH                 64 /* established */
#define PIC_INT_DEST_UPPER_REG_TARGET_ID_SHIFT       16 /* established */
#define PIC_INT_DEST_UPPER_REG_TARGET_ID_MASK        0xfull
#define PIC_INT_DEST_UPPER_REG_TARGET_ID_INPLACE (PIC_INT_DEST_UPPER_REG_TARGET_ID_MASK << PIC_INT_DEST_UPPER_REG_TARGET_ID_SHIFT)
#define PIC_INT_DEST_UPPER_REG_UPP_ADDR_SHIFT        0 /* established */
#define PIC_INT_DEST_UPPER_REG_UPP_ADDR_MASK         0xffffull
#define PIC_INT_DEST_UPPER_REG_UPP_ADDR_INPLACE (PIC_INT_DEST_UPPER_REG_UPP_ADDR_MASK << PIC_INT_DEST_UPPER_REG_UPP_ADDR_SHIFT)

/*
 * Interrupt device select: three bits per pin naming the device whose buffers a
 * pin interrupt flushes. IRIX attach writes 0x6db6db, which is device 3 in
 * every field.
 */
/* word INT_DEVICE_REG: 64 bits */
#define PIC_INT_DEVICE_REG_WIDTH                     64 /* established */
#define PIC_INT_DEVICE_REG_INT7_DEV_SHIFT            21 /* established */
#define PIC_INT_DEVICE_REG_INT7_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT7_DEV_INPLACE (PIC_INT_DEVICE_REG_INT7_DEV_MASK << PIC_INT_DEVICE_REG_INT7_DEV_SHIFT)
#define PIC_INT_DEVICE_REG_INT6_DEV_SHIFT            18 /* established */
#define PIC_INT_DEVICE_REG_INT6_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT6_DEV_INPLACE (PIC_INT_DEVICE_REG_INT6_DEV_MASK << PIC_INT_DEVICE_REG_INT6_DEV_SHIFT)
#define PIC_INT_DEVICE_REG_INT5_DEV_SHIFT            15 /* established */
#define PIC_INT_DEVICE_REG_INT5_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT5_DEV_INPLACE (PIC_INT_DEVICE_REG_INT5_DEV_MASK << PIC_INT_DEVICE_REG_INT5_DEV_SHIFT)
#define PIC_INT_DEVICE_REG_INT4_DEV_SHIFT            12 /* established */
#define PIC_INT_DEVICE_REG_INT4_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT4_DEV_INPLACE (PIC_INT_DEVICE_REG_INT4_DEV_MASK << PIC_INT_DEVICE_REG_INT4_DEV_SHIFT)
#define PIC_INT_DEVICE_REG_INT3_DEV_SHIFT            9 /* established */
#define PIC_INT_DEVICE_REG_INT3_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT3_DEV_INPLACE (PIC_INT_DEVICE_REG_INT3_DEV_MASK << PIC_INT_DEVICE_REG_INT3_DEV_SHIFT)
#define PIC_INT_DEVICE_REG_INT2_DEV_SHIFT            6 /* established */
#define PIC_INT_DEVICE_REG_INT2_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT2_DEV_INPLACE (PIC_INT_DEVICE_REG_INT2_DEV_MASK << PIC_INT_DEVICE_REG_INT2_DEV_SHIFT)
#define PIC_INT_DEVICE_REG_INT1_DEV_SHIFT            3 /* established */
#define PIC_INT_DEVICE_REG_INT1_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT1_DEV_INPLACE (PIC_INT_DEVICE_REG_INT1_DEV_MASK << PIC_INT_DEVICE_REG_INT1_DEV_SHIFT)
#define PIC_INT_DEVICE_REG_INT0_DEV_SHIFT            0 /* established */
#define PIC_INT_DEVICE_REG_INT0_DEV_MASK             0x7ull
#define PIC_INT_DEVICE_REG_INT0_DEV_INPLACE (PIC_INT_DEVICE_REG_INT0_DEV_MASK << PIC_INT_DEVICE_REG_INT0_DEV_SHIFT)

/*
 * Interrupt enable: bit n enables the status bit n. The header says all bits
 * are zero after reset. IRIX attach ORs in 0x00003eff7ffffe00 (bits 30:9, 39:32
 * and 45:41); bit 40 (arbitration failure) and the low byte stay clear.
 */
/* word INT_ENABLE_REG: 64 bits */
#define PIC_INT_ENABLE_REG_WIDTH                     64 /* established */
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_MSG_PE_SHIFT   45 /* established */
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_MSG_PE_MASK    0x1ull
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_MSG_PE_INPLACE (PIC_INT_ENABLE_REG_PCIX_SPLIT_MSG_PE_MASK << PIC_INT_ENABLE_REG_PCIX_SPLIT_MSG_PE_SHIFT)
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_EMSG_SHIFT     44 /* established */
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_EMSG_MASK      0x1ull
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_EMSG_INPLACE (PIC_INT_ENABLE_REG_PCIX_SPLIT_EMSG_MASK << PIC_INT_ENABLE_REG_PCIX_SPLIT_EMSG_SHIFT)
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_TO_SHIFT       43 /* established */
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_TO_MASK        0x1ull
#define PIC_INT_ENABLE_REG_PCIX_SPLIT_TO_INPLACE (PIC_INT_ENABLE_REG_PCIX_SPLIT_TO_MASK << PIC_INT_ENABLE_REG_PCIX_SPLIT_TO_SHIFT)
#define PIC_INT_ENABLE_REG_PCIX_UNEX_COMP_SHIFT      42 /* established */
#define PIC_INT_ENABLE_REG_PCIX_UNEX_COMP_MASK       0x1ull
#define PIC_INT_ENABLE_REG_PCIX_UNEX_COMP_INPLACE (PIC_INT_ENABLE_REG_PCIX_UNEX_COMP_MASK << PIC_INT_ENABLE_REG_PCIX_UNEX_COMP_SHIFT)
#define PIC_INT_ENABLE_REG_INT_RAM_PERR_SHIFT        41 /* established */
#define PIC_INT_ENABLE_REG_INT_RAM_PERR_MASK         0x1ull
#define PIC_INT_ENABLE_REG_INT_RAM_PERR_INPLACE (PIC_INT_ENABLE_REG_INT_RAM_PERR_MASK << PIC_INT_ENABLE_REG_INT_RAM_PERR_SHIFT)
#define PIC_INT_ENABLE_REG_BUS_ARB_BROKE_SHIFT       40 /* established */
#define PIC_INT_ENABLE_REG_BUS_ARB_BROKE_MASK        0x1ull
#define PIC_INT_ENABLE_REG_BUS_ARB_BROKE_INPLACE (PIC_INT_ENABLE_REG_BUS_ARB_BROKE_MASK << PIC_INT_ENABLE_REG_BUS_ARB_BROKE_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_REQ_TOUT_SHIFT      39 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_REQ_TOUT_MASK       0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_REQ_TOUT_INPLACE (PIC_INT_ENABLE_REG_PCI_X_REQ_TOUT_MASK << PIC_INT_ENABLE_REG_PCI_X_REQ_TOUT_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_TABORT_SHIFT        38 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_TABORT_MASK         0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_TABORT_INPLACE (PIC_INT_ENABLE_REG_PCI_X_TABORT_MASK << PIC_INT_ENABLE_REG_PCI_X_TABORT_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_PERR_SHIFT          37 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_PERR_MASK           0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_PERR_INPLACE (PIC_INT_ENABLE_REG_PCI_X_PERR_MASK << PIC_INT_ENABLE_REG_PCI_X_PERR_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_SERR_SHIFT          36 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_SERR_MASK           0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_SERR_INPLACE (PIC_INT_ENABLE_REG_PCI_X_SERR_MASK << PIC_INT_ENABLE_REG_PCI_X_SERR_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_MRETRY_SHIFT        35 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_MRETRY_MASK         0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_MRETRY_INPLACE (PIC_INT_ENABLE_REG_PCI_X_MRETRY_MASK << PIC_INT_ENABLE_REG_PCI_X_MRETRY_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_MTOUT_SHIFT         34 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_MTOUT_MASK          0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_MTOUT_INPLACE (PIC_INT_ENABLE_REG_PCI_X_MTOUT_MASK << PIC_INT_ENABLE_REG_PCI_X_MTOUT_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_DA_PARITY_SHIFT     33 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_DA_PARITY_MASK      0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_DA_PARITY_INPLACE (PIC_INT_ENABLE_REG_PCI_X_DA_PARITY_MASK << PIC_INT_ENABLE_REG_PCI_X_DA_PARITY_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_X_AD_PARITY_SHIFT     32 /* established */
#define PIC_INT_ENABLE_REG_PCI_X_AD_PARITY_MASK      0x1ull
#define PIC_INT_ENABLE_REG_PCI_X_AD_PARITY_INPLACE (PIC_INT_ENABLE_REG_PCI_X_AD_PARITY_MASK << PIC_INT_ENABLE_REG_PCI_X_AD_PARITY_SHIFT)
#define PIC_INT_ENABLE_REG_PMU_PAGE_FAULT_SHIFT      30 /* established */
#define PIC_INT_ENABLE_REG_PMU_PAGE_FAULT_MASK       0x1ull
#define PIC_INT_ENABLE_REG_PMU_PAGE_FAULT_INPLACE (PIC_INT_ENABLE_REG_PMU_PAGE_FAULT_MASK << PIC_INT_ENABLE_REG_PMU_PAGE_FAULT_SHIFT)
#define PIC_INT_ENABLE_REG_UNEXPECTED_RESP_SHIFT     29 /* established */
#define PIC_INT_ENABLE_REG_UNEXPECTED_RESP_MASK      0x1ull
#define PIC_INT_ENABLE_REG_UNEXPECTED_RESP_INPLACE (PIC_INT_ENABLE_REG_UNEXPECTED_RESP_MASK << PIC_INT_ENABLE_REG_UNEXPECTED_RESP_SHIFT)
#define PIC_INT_ENABLE_REG_BAD_XRESP_PACKET_SHIFT    28 /* established */
#define PIC_INT_ENABLE_REG_BAD_XRESP_PACKET_MASK     0x1ull
#define PIC_INT_ENABLE_REG_BAD_XRESP_PACKET_INPLACE (PIC_INT_ENABLE_REG_BAD_XRESP_PACKET_MASK << PIC_INT_ENABLE_REG_BAD_XRESP_PACKET_SHIFT)
#define PIC_INT_ENABLE_REG_BAD_XREQ_PACKET_SHIFT     27 /* established */
#define PIC_INT_ENABLE_REG_BAD_XREQ_PACKET_MASK      0x1ull
#define PIC_INT_ENABLE_REG_BAD_XREQ_PACKET_INPLACE (PIC_INT_ENABLE_REG_BAD_XREQ_PACKET_MASK << PIC_INT_ENABLE_REG_BAD_XREQ_PACKET_SHIFT)
#define PIC_INT_ENABLE_REG_RESP_XTALK_ERROR_SHIFT    26 /* established */
#define PIC_INT_ENABLE_REG_RESP_XTALK_ERROR_MASK     0x1ull
#define PIC_INT_ENABLE_REG_RESP_XTALK_ERROR_INPLACE (PIC_INT_ENABLE_REG_RESP_XTALK_ERROR_MASK << PIC_INT_ENABLE_REG_RESP_XTALK_ERROR_SHIFT)
#define PIC_INT_ENABLE_REG_REQ_XTALK_ERROR_SHIFT     25 /* established */
#define PIC_INT_ENABLE_REG_REQ_XTALK_ERROR_MASK      0x1ull
#define PIC_INT_ENABLE_REG_REQ_XTALK_ERROR_INPLACE (PIC_INT_ENABLE_REG_REQ_XTALK_ERROR_MASK << PIC_INT_ENABLE_REG_REQ_XTALK_ERROR_SHIFT)
#define PIC_INT_ENABLE_REG_INVALID_ACCESS_SHIFT      24 /* established */
#define PIC_INT_ENABLE_REG_INVALID_ACCESS_MASK       0x1ull
#define PIC_INT_ENABLE_REG_INVALID_ACCESS_INPLACE (PIC_INT_ENABLE_REG_INVALID_ACCESS_MASK << PIC_INT_ENABLE_REG_INVALID_ACCESS_SHIFT)
#define PIC_INT_ENABLE_REG_UNSUPPORTED_XOP_SHIFT     23 /* established */
#define PIC_INT_ENABLE_REG_UNSUPPORTED_XOP_MASK      0x1ull
#define PIC_INT_ENABLE_REG_UNSUPPORTED_XOP_INPLACE (PIC_INT_ENABLE_REG_UNSUPPORTED_XOP_MASK << PIC_INT_ENABLE_REG_UNSUPPORTED_XOP_SHIFT)
#define PIC_INT_ENABLE_REG_XREQ_FIFO_OFLOW_SHIFT     22 /* established */
#define PIC_INT_ENABLE_REG_XREQ_FIFO_OFLOW_MASK      0x1ull
#define PIC_INT_ENABLE_REG_XREQ_FIFO_OFLOW_INPLACE (PIC_INT_ENABLE_REG_XREQ_FIFO_OFLOW_MASK << PIC_INT_ENABLE_REG_XREQ_FIFO_OFLOW_SHIFT)
#define PIC_INT_ENABLE_REG_LLP_REC_SNERROR_SHIFT     21 /* established */
#define PIC_INT_ENABLE_REG_LLP_REC_SNERROR_MASK      0x1ull
#define PIC_INT_ENABLE_REG_LLP_REC_SNERROR_INPLACE (PIC_INT_ENABLE_REG_LLP_REC_SNERROR_MASK << PIC_INT_ENABLE_REG_LLP_REC_SNERROR_SHIFT)
#define PIC_INT_ENABLE_REG_LLP_REC_CBERROR_SHIFT     20 /* established */
#define PIC_INT_ENABLE_REG_LLP_REC_CBERROR_MASK      0x1ull
#define PIC_INT_ENABLE_REG_LLP_REC_CBERROR_INPLACE (PIC_INT_ENABLE_REG_LLP_REC_CBERROR_MASK << PIC_INT_ENABLE_REG_LLP_REC_CBERROR_SHIFT)
#define PIC_INT_ENABLE_REG_LLP_RCTY_SHIFT            19 /* established */
#define PIC_INT_ENABLE_REG_LLP_RCTY_MASK             0x1ull
#define PIC_INT_ENABLE_REG_LLP_RCTY_INPLACE (PIC_INT_ENABLE_REG_LLP_RCTY_MASK << PIC_INT_ENABLE_REG_LLP_RCTY_SHIFT)
#define PIC_INT_ENABLE_REG_LLP_TX_RETRY_SHIFT        18 /* established */
#define PIC_INT_ENABLE_REG_LLP_TX_RETRY_MASK         0x1ull
#define PIC_INT_ENABLE_REG_LLP_TX_RETRY_INPLACE (PIC_INT_ENABLE_REG_LLP_TX_RETRY_MASK << PIC_INT_ENABLE_REG_LLP_TX_RETRY_SHIFT)
#define PIC_INT_ENABLE_REG_LLP_TCTY_SHIFT            17 /* established */
#define PIC_INT_ENABLE_REG_LLP_TCTY_MASK             0x1ull
#define PIC_INT_ENABLE_REG_LLP_TCTY_INPLACE (PIC_INT_ENABLE_REG_LLP_TCTY_MASK << PIC_INT_ENABLE_REG_LLP_TCTY_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_ABORT_SHIFT           15 /* established */
#define PIC_INT_ENABLE_REG_PCI_ABORT_MASK            0x1ull
#define PIC_INT_ENABLE_REG_PCI_ABORT_INPLACE (PIC_INT_ENABLE_REG_PCI_ABORT_MASK << PIC_INT_ENABLE_REG_PCI_ABORT_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_PARITY_SHIFT          14 /* established */
#define PIC_INT_ENABLE_REG_PCI_PARITY_MASK           0x1ull
#define PIC_INT_ENABLE_REG_PCI_PARITY_INPLACE (PIC_INT_ENABLE_REG_PCI_PARITY_MASK << PIC_INT_ENABLE_REG_PCI_PARITY_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_SERR_SHIFT            13 /* established */
#define PIC_INT_ENABLE_REG_PCI_SERR_MASK             0x1ull
#define PIC_INT_ENABLE_REG_PCI_SERR_INPLACE (PIC_INT_ENABLE_REG_PCI_SERR_MASK << PIC_INT_ENABLE_REG_PCI_SERR_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_PERR_SHIFT            12 /* established */
#define PIC_INT_ENABLE_REG_PCI_PERR_MASK             0x1ull
#define PIC_INT_ENABLE_REG_PCI_PERR_INPLACE (PIC_INT_ENABLE_REG_PCI_PERR_MASK << PIC_INT_ENABLE_REG_PCI_PERR_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_MASTER_TOUT_SHIFT     11 /* established */
#define PIC_INT_ENABLE_REG_PCI_MASTER_TOUT_MASK      0x1ull
#define PIC_INT_ENABLE_REG_PCI_MASTER_TOUT_INPLACE (PIC_INT_ENABLE_REG_PCI_MASTER_TOUT_MASK << PIC_INT_ENABLE_REG_PCI_MASTER_TOUT_SHIFT)
#define PIC_INT_ENABLE_REG_PCI_RETRY_CNT_SHIFT       10 /* established */
#define PIC_INT_ENABLE_REG_PCI_RETRY_CNT_MASK        0x1ull
#define PIC_INT_ENABLE_REG_PCI_RETRY_CNT_INPLACE (PIC_INT_ENABLE_REG_PCI_RETRY_CNT_MASK << PIC_INT_ENABLE_REG_PCI_RETRY_CNT_SHIFT)
#define PIC_INT_ENABLE_REG_XREAD_REQ_TOUT_SHIFT      9 /* established */
#define PIC_INT_ENABLE_REG_XREAD_REQ_TOUT_MASK       0x1ull
#define PIC_INT_ENABLE_REG_XREAD_REQ_TOUT_INPLACE (PIC_INT_ENABLE_REG_XREAD_REQ_TOUT_MASK << PIC_INT_ENABLE_REG_XREAD_REQ_TOUT_SHIFT)
#define PIC_INT_ENABLE_REG_INT_STATE_SHIFT           0 /* established */
#define PIC_INT_ENABLE_REG_INT_STATE_MASK            0xffull
#define PIC_INT_ENABLE_REG_INT_STATE_INPLACE (PIC_INT_ENABLE_REG_INT_STATE_MASK << PIC_INT_ENABLE_REG_INT_STATE_SHIFT)

/*
 * Host error field: the bit position in the host interrupt register that an
 * error sets.
 */
/* word INT_HOST_ERR_REG: 64 bits */
#define PIC_INT_HOST_ERR_REG_WIDTH                   64 /* established */
#define PIC_INT_HOST_ERR_REG_BRIDGE_ERR_FLD_SHIFT    0 /* established */
#define PIC_INT_HOST_ERR_REG_BRIDGE_ERR_FLD_MASK     0xffull
#define PIC_INT_HOST_ERR_REG_BRIDGE_ERR_FLD_INPLACE (PIC_INT_HOST_ERR_REG_BRIDGE_ERR_FLD_MASK << PIC_INT_HOST_ERR_REG_BRIDGE_ERR_FLD_SHIFT)

/*
 * Interrupt mode: one bit per pin. IRIX attach writes zero.
 */
/* word INT_MODE_REG: 64 bits */
#define PIC_INT_MODE_REG_WIDTH                       64 /* established */
#define PIC_INT_MODE_REG_CLR_PKT_SHIFT               0 /* established */
#define PIC_INT_MODE_REG_CLR_PKT_MASK                0xffull
#define PIC_INT_MODE_REG_CLR_PKT_INPLACE (PIC_INT_MODE_REG_CLR_PKT_MASK << PIC_INT_MODE_REG_CLR_PKT_SHIFT)

/*
 * Interrupt reset: write only. A one at an error bit clears that bit and rearms
 * the error registers; bit 6 clears the multiple-error indication. Bits 6:0
 * carry the Bridge-family group strobes in bridge.h and 0x7f clears all of
 * them: IRIX attach writes 0x7f. Whether a PIC honours the group strobes is
 * unknown (README, "Open").
 */
/* word INT_RESET_REG: 64 bits */
#define PIC_INT_RESET_REG_WIDTH                      64 /* established */
#define PIC_INT_RESET_REG_PCIX_SPLIT_MSG_PE_SHIFT    45 /* established */
#define PIC_INT_RESET_REG_PCIX_SPLIT_MSG_PE_MASK     0x1ull
#define PIC_INT_RESET_REG_PCIX_SPLIT_MSG_PE_INPLACE (PIC_INT_RESET_REG_PCIX_SPLIT_MSG_PE_MASK << PIC_INT_RESET_REG_PCIX_SPLIT_MSG_PE_SHIFT)
#define PIC_INT_RESET_REG_PCIX_SPLIT_EMSG_SHIFT      44 /* established */
#define PIC_INT_RESET_REG_PCIX_SPLIT_EMSG_MASK       0x1ull
#define PIC_INT_RESET_REG_PCIX_SPLIT_EMSG_INPLACE (PIC_INT_RESET_REG_PCIX_SPLIT_EMSG_MASK << PIC_INT_RESET_REG_PCIX_SPLIT_EMSG_SHIFT)
#define PIC_INT_RESET_REG_PCIX_SPLIT_TO_SHIFT        43 /* established */
#define PIC_INT_RESET_REG_PCIX_SPLIT_TO_MASK         0x1ull
#define PIC_INT_RESET_REG_PCIX_SPLIT_TO_INPLACE (PIC_INT_RESET_REG_PCIX_SPLIT_TO_MASK << PIC_INT_RESET_REG_PCIX_SPLIT_TO_SHIFT)
#define PIC_INT_RESET_REG_PCIX_UNEX_COMP_SHIFT       42 /* established */
#define PIC_INT_RESET_REG_PCIX_UNEX_COMP_MASK        0x1ull
#define PIC_INT_RESET_REG_PCIX_UNEX_COMP_INPLACE (PIC_INT_RESET_REG_PCIX_UNEX_COMP_MASK << PIC_INT_RESET_REG_PCIX_UNEX_COMP_SHIFT)
#define PIC_INT_RESET_REG_INT_RAM_PERR_SHIFT         41 /* established */
#define PIC_INT_RESET_REG_INT_RAM_PERR_MASK          0x1ull
#define PIC_INT_RESET_REG_INT_RAM_PERR_INPLACE (PIC_INT_RESET_REG_INT_RAM_PERR_MASK << PIC_INT_RESET_REG_INT_RAM_PERR_SHIFT)
#define PIC_INT_RESET_REG_BUS_ARB_BROKE_SHIFT        40 /* established */
#define PIC_INT_RESET_REG_BUS_ARB_BROKE_MASK         0x1ull
#define PIC_INT_RESET_REG_BUS_ARB_BROKE_INPLACE (PIC_INT_RESET_REG_BUS_ARB_BROKE_MASK << PIC_INT_RESET_REG_BUS_ARB_BROKE_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_REQ_TOUT_SHIFT       39 /* established */
#define PIC_INT_RESET_REG_PCI_X_REQ_TOUT_MASK        0x1ull
#define PIC_INT_RESET_REG_PCI_X_REQ_TOUT_INPLACE (PIC_INT_RESET_REG_PCI_X_REQ_TOUT_MASK << PIC_INT_RESET_REG_PCI_X_REQ_TOUT_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_TABORT_SHIFT         38 /* established */
#define PIC_INT_RESET_REG_PCI_X_TABORT_MASK          0x1ull
#define PIC_INT_RESET_REG_PCI_X_TABORT_INPLACE (PIC_INT_RESET_REG_PCI_X_TABORT_MASK << PIC_INT_RESET_REG_PCI_X_TABORT_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_PERR_SHIFT           37 /* established */
#define PIC_INT_RESET_REG_PCI_X_PERR_MASK            0x1ull
#define PIC_INT_RESET_REG_PCI_X_PERR_INPLACE (PIC_INT_RESET_REG_PCI_X_PERR_MASK << PIC_INT_RESET_REG_PCI_X_PERR_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_SERR_SHIFT           36 /* established */
#define PIC_INT_RESET_REG_PCI_X_SERR_MASK            0x1ull
#define PIC_INT_RESET_REG_PCI_X_SERR_INPLACE (PIC_INT_RESET_REG_PCI_X_SERR_MASK << PIC_INT_RESET_REG_PCI_X_SERR_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_MRETRY_SHIFT         35 /* established */
#define PIC_INT_RESET_REG_PCI_X_MRETRY_MASK          0x1ull
#define PIC_INT_RESET_REG_PCI_X_MRETRY_INPLACE (PIC_INT_RESET_REG_PCI_X_MRETRY_MASK << PIC_INT_RESET_REG_PCI_X_MRETRY_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_MTOUT_SHIFT          34 /* established */
#define PIC_INT_RESET_REG_PCI_X_MTOUT_MASK           0x1ull
#define PIC_INT_RESET_REG_PCI_X_MTOUT_INPLACE (PIC_INT_RESET_REG_PCI_X_MTOUT_MASK << PIC_INT_RESET_REG_PCI_X_MTOUT_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_DA_PARITY_SHIFT      33 /* established */
#define PIC_INT_RESET_REG_PCI_X_DA_PARITY_MASK       0x1ull
#define PIC_INT_RESET_REG_PCI_X_DA_PARITY_INPLACE (PIC_INT_RESET_REG_PCI_X_DA_PARITY_MASK << PIC_INT_RESET_REG_PCI_X_DA_PARITY_SHIFT)
#define PIC_INT_RESET_REG_PCI_X_AD_PARITY_SHIFT      32 /* established */
#define PIC_INT_RESET_REG_PCI_X_AD_PARITY_MASK       0x1ull
#define PIC_INT_RESET_REG_PCI_X_AD_PARITY_INPLACE (PIC_INT_RESET_REG_PCI_X_AD_PARITY_MASK << PIC_INT_RESET_REG_PCI_X_AD_PARITY_SHIFT)
#define PIC_INT_RESET_REG_PMU_PAGE_FAULT_SHIFT       30 /* established */
#define PIC_INT_RESET_REG_PMU_PAGE_FAULT_MASK        0x1ull
#define PIC_INT_RESET_REG_PMU_PAGE_FAULT_INPLACE (PIC_INT_RESET_REG_PMU_PAGE_FAULT_MASK << PIC_INT_RESET_REG_PMU_PAGE_FAULT_SHIFT)
#define PIC_INT_RESET_REG_UNEXPECTED_RESP_SHIFT      29 /* established */
#define PIC_INT_RESET_REG_UNEXPECTED_RESP_MASK       0x1ull
#define PIC_INT_RESET_REG_UNEXPECTED_RESP_INPLACE (PIC_INT_RESET_REG_UNEXPECTED_RESP_MASK << PIC_INT_RESET_REG_UNEXPECTED_RESP_SHIFT)
#define PIC_INT_RESET_REG_BAD_XRESP_PACKET_SHIFT     28 /* established */
#define PIC_INT_RESET_REG_BAD_XRESP_PACKET_MASK      0x1ull
#define PIC_INT_RESET_REG_BAD_XRESP_PACKET_INPLACE (PIC_INT_RESET_REG_BAD_XRESP_PACKET_MASK << PIC_INT_RESET_REG_BAD_XRESP_PACKET_SHIFT)
#define PIC_INT_RESET_REG_BAD_XREQ_PACKET_SHIFT      27 /* established */
#define PIC_INT_RESET_REG_BAD_XREQ_PACKET_MASK       0x1ull
#define PIC_INT_RESET_REG_BAD_XREQ_PACKET_INPLACE (PIC_INT_RESET_REG_BAD_XREQ_PACKET_MASK << PIC_INT_RESET_REG_BAD_XREQ_PACKET_SHIFT)
#define PIC_INT_RESET_REG_RESP_XTALK_ERROR_SHIFT     26 /* established */
#define PIC_INT_RESET_REG_RESP_XTALK_ERROR_MASK      0x1ull
#define PIC_INT_RESET_REG_RESP_XTALK_ERROR_INPLACE (PIC_INT_RESET_REG_RESP_XTALK_ERROR_MASK << PIC_INT_RESET_REG_RESP_XTALK_ERROR_SHIFT)
#define PIC_INT_RESET_REG_REQ_XTALK_ERROR_SHIFT      25 /* established */
#define PIC_INT_RESET_REG_REQ_XTALK_ERROR_MASK       0x1ull
#define PIC_INT_RESET_REG_REQ_XTALK_ERROR_INPLACE (PIC_INT_RESET_REG_REQ_XTALK_ERROR_MASK << PIC_INT_RESET_REG_REQ_XTALK_ERROR_SHIFT)
#define PIC_INT_RESET_REG_INVALID_ACCESS_SHIFT       24 /* established */
#define PIC_INT_RESET_REG_INVALID_ACCESS_MASK        0x1ull
#define PIC_INT_RESET_REG_INVALID_ACCESS_INPLACE (PIC_INT_RESET_REG_INVALID_ACCESS_MASK << PIC_INT_RESET_REG_INVALID_ACCESS_SHIFT)
#define PIC_INT_RESET_REG_UNSUPPORTED_XOP_SHIFT      23 /* established */
#define PIC_INT_RESET_REG_UNSUPPORTED_XOP_MASK       0x1ull
#define PIC_INT_RESET_REG_UNSUPPORTED_XOP_INPLACE (PIC_INT_RESET_REG_UNSUPPORTED_XOP_MASK << PIC_INT_RESET_REG_UNSUPPORTED_XOP_SHIFT)
#define PIC_INT_RESET_REG_XREQ_FIFO_OFLOW_SHIFT      22 /* established */
#define PIC_INT_RESET_REG_XREQ_FIFO_OFLOW_MASK       0x1ull
#define PIC_INT_RESET_REG_XREQ_FIFO_OFLOW_INPLACE (PIC_INT_RESET_REG_XREQ_FIFO_OFLOW_MASK << PIC_INT_RESET_REG_XREQ_FIFO_OFLOW_SHIFT)
#define PIC_INT_RESET_REG_LLP_REC_SNERROR_SHIFT      21 /* established */
#define PIC_INT_RESET_REG_LLP_REC_SNERROR_MASK       0x1ull
#define PIC_INT_RESET_REG_LLP_REC_SNERROR_INPLACE (PIC_INT_RESET_REG_LLP_REC_SNERROR_MASK << PIC_INT_RESET_REG_LLP_REC_SNERROR_SHIFT)
#define PIC_INT_RESET_REG_LLP_REC_CBERROR_SHIFT      20 /* established */
#define PIC_INT_RESET_REG_LLP_REC_CBERROR_MASK       0x1ull
#define PIC_INT_RESET_REG_LLP_REC_CBERROR_INPLACE (PIC_INT_RESET_REG_LLP_REC_CBERROR_MASK << PIC_INT_RESET_REG_LLP_REC_CBERROR_SHIFT)
#define PIC_INT_RESET_REG_LLP_RCTY_SHIFT             19 /* established */
#define PIC_INT_RESET_REG_LLP_RCTY_MASK              0x1ull
#define PIC_INT_RESET_REG_LLP_RCTY_INPLACE (PIC_INT_RESET_REG_LLP_RCTY_MASK << PIC_INT_RESET_REG_LLP_RCTY_SHIFT)
#define PIC_INT_RESET_REG_LLP_TX_RETRY_SHIFT         18 /* established */
#define PIC_INT_RESET_REG_LLP_TX_RETRY_MASK          0x1ull
#define PIC_INT_RESET_REG_LLP_TX_RETRY_INPLACE (PIC_INT_RESET_REG_LLP_TX_RETRY_MASK << PIC_INT_RESET_REG_LLP_TX_RETRY_SHIFT)
#define PIC_INT_RESET_REG_LLP_TCTY_SHIFT             17 /* established */
#define PIC_INT_RESET_REG_LLP_TCTY_MASK              0x1ull
#define PIC_INT_RESET_REG_LLP_TCTY_INPLACE (PIC_INT_RESET_REG_LLP_TCTY_MASK << PIC_INT_RESET_REG_LLP_TCTY_SHIFT)
#define PIC_INT_RESET_REG_PCI_ABORT_SHIFT            15 /* established */
#define PIC_INT_RESET_REG_PCI_ABORT_MASK             0x1ull
#define PIC_INT_RESET_REG_PCI_ABORT_INPLACE (PIC_INT_RESET_REG_PCI_ABORT_MASK << PIC_INT_RESET_REG_PCI_ABORT_SHIFT)
#define PIC_INT_RESET_REG_PCI_PARITY_SHIFT           14 /* established */
#define PIC_INT_RESET_REG_PCI_PARITY_MASK            0x1ull
#define PIC_INT_RESET_REG_PCI_PARITY_INPLACE (PIC_INT_RESET_REG_PCI_PARITY_MASK << PIC_INT_RESET_REG_PCI_PARITY_SHIFT)
#define PIC_INT_RESET_REG_PCI_SERR_SHIFT             13 /* established */
#define PIC_INT_RESET_REG_PCI_SERR_MASK              0x1ull
#define PIC_INT_RESET_REG_PCI_SERR_INPLACE (PIC_INT_RESET_REG_PCI_SERR_MASK << PIC_INT_RESET_REG_PCI_SERR_SHIFT)
#define PIC_INT_RESET_REG_PCI_PERR_SHIFT             12 /* established */
#define PIC_INT_RESET_REG_PCI_PERR_MASK              0x1ull
#define PIC_INT_RESET_REG_PCI_PERR_INPLACE (PIC_INT_RESET_REG_PCI_PERR_MASK << PIC_INT_RESET_REG_PCI_PERR_SHIFT)
#define PIC_INT_RESET_REG_PCI_MASTER_TOUT_SHIFT      11 /* established */
#define PIC_INT_RESET_REG_PCI_MASTER_TOUT_MASK       0x1ull
#define PIC_INT_RESET_REG_PCI_MASTER_TOUT_INPLACE (PIC_INT_RESET_REG_PCI_MASTER_TOUT_MASK << PIC_INT_RESET_REG_PCI_MASTER_TOUT_SHIFT)
#define PIC_INT_RESET_REG_PCI_RETRY_CNT_SHIFT        10 /* established */
#define PIC_INT_RESET_REG_PCI_RETRY_CNT_MASK         0x1ull
#define PIC_INT_RESET_REG_PCI_RETRY_CNT_INPLACE (PIC_INT_RESET_REG_PCI_RETRY_CNT_MASK << PIC_INT_RESET_REG_PCI_RETRY_CNT_SHIFT)
#define PIC_INT_RESET_REG_XREAD_REQ_TOUT_SHIFT       9 /* established */
#define PIC_INT_RESET_REG_XREAD_REQ_TOUT_MASK        0x1ull
#define PIC_INT_RESET_REG_XREAD_REQ_TOUT_INPLACE (PIC_INT_RESET_REG_XREAD_REQ_TOUT_MASK << PIC_INT_RESET_REG_XREAD_REQ_TOUT_SHIFT)
#define PIC_INT_RESET_REG_MULTI_CLR_SHIFT            6 /* established */
#define PIC_INT_RESET_REG_MULTI_CLR_MASK             0x1ull
#define PIC_INT_RESET_REG_MULTI_CLR_INPLACE (PIC_INT_RESET_REG_MULTI_CLR_MASK << PIC_INT_RESET_REG_MULTI_CLR_SHIFT)

/*
 * Interrupt status: read only. Bits 7:0 are the live level of the eight
 * interrupt pins. The remaining bits latch error conditions when the matching
 * enable bit is set. Bits 45:42 are named in bridge.h but are reserved in the
 * register structure.
 */
/* word INT_STATUS_REG: 64 bits */
#define PIC_INT_STATUS_REG_WIDTH                     64 /* established */
#define PIC_INT_STATUS_REG_PCIX_SPLIT_MSG_PE_SHIFT   45 /* established */
#define PIC_INT_STATUS_REG_PCIX_SPLIT_MSG_PE_MASK    0x1ull
#define PIC_INT_STATUS_REG_PCIX_SPLIT_MSG_PE_INPLACE (PIC_INT_STATUS_REG_PCIX_SPLIT_MSG_PE_MASK << PIC_INT_STATUS_REG_PCIX_SPLIT_MSG_PE_SHIFT)
#define PIC_INT_STATUS_REG_PCIX_SPLIT_EMSG_SHIFT     44 /* established */
#define PIC_INT_STATUS_REG_PCIX_SPLIT_EMSG_MASK      0x1ull
#define PIC_INT_STATUS_REG_PCIX_SPLIT_EMSG_INPLACE (PIC_INT_STATUS_REG_PCIX_SPLIT_EMSG_MASK << PIC_INT_STATUS_REG_PCIX_SPLIT_EMSG_SHIFT)
#define PIC_INT_STATUS_REG_PCIX_SPLIT_TO_SHIFT       43 /* established */
#define PIC_INT_STATUS_REG_PCIX_SPLIT_TO_MASK        0x1ull
#define PIC_INT_STATUS_REG_PCIX_SPLIT_TO_INPLACE (PIC_INT_STATUS_REG_PCIX_SPLIT_TO_MASK << PIC_INT_STATUS_REG_PCIX_SPLIT_TO_SHIFT)
#define PIC_INT_STATUS_REG_PCIX_UNEX_COMP_SHIFT      42 /* established */
#define PIC_INT_STATUS_REG_PCIX_UNEX_COMP_MASK       0x1ull
#define PIC_INT_STATUS_REG_PCIX_UNEX_COMP_INPLACE (PIC_INT_STATUS_REG_PCIX_UNEX_COMP_MASK << PIC_INT_STATUS_REG_PCIX_UNEX_COMP_SHIFT)
#define PIC_INT_STATUS_REG_INT_RAM_PERR_SHIFT        41 /* established */
#define PIC_INT_STATUS_REG_INT_RAM_PERR_MASK         0x1ull
#define PIC_INT_STATUS_REG_INT_RAM_PERR_INPLACE (PIC_INT_STATUS_REG_INT_RAM_PERR_MASK << PIC_INT_STATUS_REG_INT_RAM_PERR_SHIFT)
#define PIC_INT_STATUS_REG_BUS_ARB_BROKE_SHIFT       40 /* established */
#define PIC_INT_STATUS_REG_BUS_ARB_BROKE_MASK        0x1ull
#define PIC_INT_STATUS_REG_BUS_ARB_BROKE_INPLACE (PIC_INT_STATUS_REG_BUS_ARB_BROKE_MASK << PIC_INT_STATUS_REG_BUS_ARB_BROKE_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_REQ_TOUT_SHIFT      39 /* established */
#define PIC_INT_STATUS_REG_PCI_X_REQ_TOUT_MASK       0x1ull
#define PIC_INT_STATUS_REG_PCI_X_REQ_TOUT_INPLACE (PIC_INT_STATUS_REG_PCI_X_REQ_TOUT_MASK << PIC_INT_STATUS_REG_PCI_X_REQ_TOUT_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_TABORT_SHIFT        38 /* established */
#define PIC_INT_STATUS_REG_PCI_X_TABORT_MASK         0x1ull
#define PIC_INT_STATUS_REG_PCI_X_TABORT_INPLACE (PIC_INT_STATUS_REG_PCI_X_TABORT_MASK << PIC_INT_STATUS_REG_PCI_X_TABORT_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_PERR_SHIFT          37 /* established */
#define PIC_INT_STATUS_REG_PCI_X_PERR_MASK           0x1ull
#define PIC_INT_STATUS_REG_PCI_X_PERR_INPLACE (PIC_INT_STATUS_REG_PCI_X_PERR_MASK << PIC_INT_STATUS_REG_PCI_X_PERR_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_SERR_SHIFT          36 /* established */
#define PIC_INT_STATUS_REG_PCI_X_SERR_MASK           0x1ull
#define PIC_INT_STATUS_REG_PCI_X_SERR_INPLACE (PIC_INT_STATUS_REG_PCI_X_SERR_MASK << PIC_INT_STATUS_REG_PCI_X_SERR_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_MRETRY_SHIFT        35 /* established */
#define PIC_INT_STATUS_REG_PCI_X_MRETRY_MASK         0x1ull
#define PIC_INT_STATUS_REG_PCI_X_MRETRY_INPLACE (PIC_INT_STATUS_REG_PCI_X_MRETRY_MASK << PIC_INT_STATUS_REG_PCI_X_MRETRY_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_MTOUT_SHIFT         34 /* established */
#define PIC_INT_STATUS_REG_PCI_X_MTOUT_MASK          0x1ull
#define PIC_INT_STATUS_REG_PCI_X_MTOUT_INPLACE (PIC_INT_STATUS_REG_PCI_X_MTOUT_MASK << PIC_INT_STATUS_REG_PCI_X_MTOUT_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_DA_PARITY_SHIFT     33 /* established */
#define PIC_INT_STATUS_REG_PCI_X_DA_PARITY_MASK      0x1ull
#define PIC_INT_STATUS_REG_PCI_X_DA_PARITY_INPLACE (PIC_INT_STATUS_REG_PCI_X_DA_PARITY_MASK << PIC_INT_STATUS_REG_PCI_X_DA_PARITY_SHIFT)
#define PIC_INT_STATUS_REG_PCI_X_AD_PARITY_SHIFT     32 /* established */
#define PIC_INT_STATUS_REG_PCI_X_AD_PARITY_MASK      0x1ull
#define PIC_INT_STATUS_REG_PCI_X_AD_PARITY_INPLACE (PIC_INT_STATUS_REG_PCI_X_AD_PARITY_MASK << PIC_INT_STATUS_REG_PCI_X_AD_PARITY_SHIFT)
#define PIC_INT_STATUS_REG_PMU_PAGE_FAULT_SHIFT      30 /* established */
#define PIC_INT_STATUS_REG_PMU_PAGE_FAULT_MASK       0x1ull
#define PIC_INT_STATUS_REG_PMU_PAGE_FAULT_INPLACE (PIC_INT_STATUS_REG_PMU_PAGE_FAULT_MASK << PIC_INT_STATUS_REG_PMU_PAGE_FAULT_SHIFT)
#define PIC_INT_STATUS_REG_UNEXPECTED_RESP_SHIFT     29 /* established */
#define PIC_INT_STATUS_REG_UNEXPECTED_RESP_MASK      0x1ull
#define PIC_INT_STATUS_REG_UNEXPECTED_RESP_INPLACE (PIC_INT_STATUS_REG_UNEXPECTED_RESP_MASK << PIC_INT_STATUS_REG_UNEXPECTED_RESP_SHIFT)
#define PIC_INT_STATUS_REG_BAD_XRESP_PACKET_SHIFT    28 /* established */
#define PIC_INT_STATUS_REG_BAD_XRESP_PACKET_MASK     0x1ull
#define PIC_INT_STATUS_REG_BAD_XRESP_PACKET_INPLACE (PIC_INT_STATUS_REG_BAD_XRESP_PACKET_MASK << PIC_INT_STATUS_REG_BAD_XRESP_PACKET_SHIFT)
#define PIC_INT_STATUS_REG_BAD_XREQ_PACKET_SHIFT     27 /* established */
#define PIC_INT_STATUS_REG_BAD_XREQ_PACKET_MASK      0x1ull
#define PIC_INT_STATUS_REG_BAD_XREQ_PACKET_INPLACE (PIC_INT_STATUS_REG_BAD_XREQ_PACKET_MASK << PIC_INT_STATUS_REG_BAD_XREQ_PACKET_SHIFT)
#define PIC_INT_STATUS_REG_RESP_XTALK_ERROR_SHIFT    26 /* established */
#define PIC_INT_STATUS_REG_RESP_XTALK_ERROR_MASK     0x1ull
#define PIC_INT_STATUS_REG_RESP_XTALK_ERROR_INPLACE (PIC_INT_STATUS_REG_RESP_XTALK_ERROR_MASK << PIC_INT_STATUS_REG_RESP_XTALK_ERROR_SHIFT)
#define PIC_INT_STATUS_REG_REQ_XTALK_ERROR_SHIFT     25 /* established */
#define PIC_INT_STATUS_REG_REQ_XTALK_ERROR_MASK      0x1ull
#define PIC_INT_STATUS_REG_REQ_XTALK_ERROR_INPLACE (PIC_INT_STATUS_REG_REQ_XTALK_ERROR_MASK << PIC_INT_STATUS_REG_REQ_XTALK_ERROR_SHIFT)
#define PIC_INT_STATUS_REG_INVALID_ACCESS_SHIFT      24 /* established */
#define PIC_INT_STATUS_REG_INVALID_ACCESS_MASK       0x1ull
#define PIC_INT_STATUS_REG_INVALID_ACCESS_INPLACE (PIC_INT_STATUS_REG_INVALID_ACCESS_MASK << PIC_INT_STATUS_REG_INVALID_ACCESS_SHIFT)
#define PIC_INT_STATUS_REG_UNSUPPORTED_XOP_SHIFT     23 /* established */
#define PIC_INT_STATUS_REG_UNSUPPORTED_XOP_MASK      0x1ull
#define PIC_INT_STATUS_REG_UNSUPPORTED_XOP_INPLACE (PIC_INT_STATUS_REG_UNSUPPORTED_XOP_MASK << PIC_INT_STATUS_REG_UNSUPPORTED_XOP_SHIFT)
#define PIC_INT_STATUS_REG_XREQ_FIFO_OFLOW_SHIFT     22 /* established */
#define PIC_INT_STATUS_REG_XREQ_FIFO_OFLOW_MASK      0x1ull
#define PIC_INT_STATUS_REG_XREQ_FIFO_OFLOW_INPLACE (PIC_INT_STATUS_REG_XREQ_FIFO_OFLOW_MASK << PIC_INT_STATUS_REG_XREQ_FIFO_OFLOW_SHIFT)
#define PIC_INT_STATUS_REG_LLP_REC_SNERROR_SHIFT     21 /* established */
#define PIC_INT_STATUS_REG_LLP_REC_SNERROR_MASK      0x1ull
#define PIC_INT_STATUS_REG_LLP_REC_SNERROR_INPLACE (PIC_INT_STATUS_REG_LLP_REC_SNERROR_MASK << PIC_INT_STATUS_REG_LLP_REC_SNERROR_SHIFT)
#define PIC_INT_STATUS_REG_LLP_REC_CBERROR_SHIFT     20 /* established */
#define PIC_INT_STATUS_REG_LLP_REC_CBERROR_MASK      0x1ull
#define PIC_INT_STATUS_REG_LLP_REC_CBERROR_INPLACE (PIC_INT_STATUS_REG_LLP_REC_CBERROR_MASK << PIC_INT_STATUS_REG_LLP_REC_CBERROR_SHIFT)
#define PIC_INT_STATUS_REG_LLP_RCTY_SHIFT            19 /* established */
#define PIC_INT_STATUS_REG_LLP_RCTY_MASK             0x1ull
#define PIC_INT_STATUS_REG_LLP_RCTY_INPLACE (PIC_INT_STATUS_REG_LLP_RCTY_MASK << PIC_INT_STATUS_REG_LLP_RCTY_SHIFT)
#define PIC_INT_STATUS_REG_LLP_TX_RETRY_SHIFT        18 /* established */
#define PIC_INT_STATUS_REG_LLP_TX_RETRY_MASK         0x1ull
#define PIC_INT_STATUS_REG_LLP_TX_RETRY_INPLACE (PIC_INT_STATUS_REG_LLP_TX_RETRY_MASK << PIC_INT_STATUS_REG_LLP_TX_RETRY_SHIFT)
#define PIC_INT_STATUS_REG_LLP_TCTY_SHIFT            17 /* established */
#define PIC_INT_STATUS_REG_LLP_TCTY_MASK             0x1ull
#define PIC_INT_STATUS_REG_LLP_TCTY_INPLACE (PIC_INT_STATUS_REG_LLP_TCTY_MASK << PIC_INT_STATUS_REG_LLP_TCTY_SHIFT)
#define PIC_INT_STATUS_REG_PCI_ABORT_SHIFT           15 /* established */
#define PIC_INT_STATUS_REG_PCI_ABORT_MASK            0x1ull
#define PIC_INT_STATUS_REG_PCI_ABORT_INPLACE (PIC_INT_STATUS_REG_PCI_ABORT_MASK << PIC_INT_STATUS_REG_PCI_ABORT_SHIFT)
#define PIC_INT_STATUS_REG_PCI_PARITY_SHIFT          14 /* established */
#define PIC_INT_STATUS_REG_PCI_PARITY_MASK           0x1ull
#define PIC_INT_STATUS_REG_PCI_PARITY_INPLACE (PIC_INT_STATUS_REG_PCI_PARITY_MASK << PIC_INT_STATUS_REG_PCI_PARITY_SHIFT)
#define PIC_INT_STATUS_REG_PCI_SERR_SHIFT            13 /* established */
#define PIC_INT_STATUS_REG_PCI_SERR_MASK             0x1ull
#define PIC_INT_STATUS_REG_PCI_SERR_INPLACE (PIC_INT_STATUS_REG_PCI_SERR_MASK << PIC_INT_STATUS_REG_PCI_SERR_SHIFT)
#define PIC_INT_STATUS_REG_PCI_PERR_SHIFT            12 /* established */
#define PIC_INT_STATUS_REG_PCI_PERR_MASK             0x1ull
#define PIC_INT_STATUS_REG_PCI_PERR_INPLACE (PIC_INT_STATUS_REG_PCI_PERR_MASK << PIC_INT_STATUS_REG_PCI_PERR_SHIFT)
#define PIC_INT_STATUS_REG_PCI_MASTER_TOUT_SHIFT     11 /* established */
#define PIC_INT_STATUS_REG_PCI_MASTER_TOUT_MASK      0x1ull
#define PIC_INT_STATUS_REG_PCI_MASTER_TOUT_INPLACE (PIC_INT_STATUS_REG_PCI_MASTER_TOUT_MASK << PIC_INT_STATUS_REG_PCI_MASTER_TOUT_SHIFT)
#define PIC_INT_STATUS_REG_PCI_RETRY_CNT_SHIFT       10 /* established */
#define PIC_INT_STATUS_REG_PCI_RETRY_CNT_MASK        0x1ull
#define PIC_INT_STATUS_REG_PCI_RETRY_CNT_INPLACE (PIC_INT_STATUS_REG_PCI_RETRY_CNT_MASK << PIC_INT_STATUS_REG_PCI_RETRY_CNT_SHIFT)
#define PIC_INT_STATUS_REG_XREAD_REQ_TOUT_SHIFT      9 /* established */
#define PIC_INT_STATUS_REG_XREAD_REQ_TOUT_MASK       0x1ull
#define PIC_INT_STATUS_REG_XREAD_REQ_TOUT_INPLACE (PIC_INT_STATUS_REG_XREAD_REQ_TOUT_MASK << PIC_INT_STATUS_REG_XREAD_REQ_TOUT_SHIFT)
#define PIC_INT_STATUS_REG_INT_STATE_SHIFT           0 /* established */
#define PIC_INT_STATUS_REG_INT_STATE_MASK            0xffull
#define PIC_INT_STATUS_REG_INT_STATE_INPLACE (PIC_INT_STATUS_REG_INT_STATE_MASK << PIC_INT_STATUS_REG_INT_STATE_SHIFT)

/*
 * Link-side error address.
 */
/* word LINK_ERR_ADDR_REG: 64 bits */
#define PIC_LINK_ERR_ADDR_REG_WIDTH                  64 /* established */
#define PIC_LINK_ERR_ADDR_REG_UPP_ADDR_SHIFT         32 /* established */
#define PIC_LINK_ERR_ADDR_REG_UPP_ADDR_MASK          0xffffull
#define PIC_LINK_ERR_ADDR_REG_UPP_ADDR_INPLACE (PIC_LINK_ERR_ADDR_REG_UPP_ADDR_MASK << PIC_LINK_ERR_ADDR_REG_UPP_ADDR_SHIFT)
#define PIC_LINK_ERR_ADDR_REG_LOW_ADDR_SHIFT         0 /* established */
#define PIC_LINK_ERR_ADDR_REG_LOW_ADDR_MASK          0xffffffffull
#define PIC_LINK_ERR_ADDR_REG_LOW_ADDR_INPLACE (PIC_LINK_ERR_ADDR_REG_LOW_ADDR_MASK << PIC_LINK_ERR_ADDR_REG_LOW_ADDR_SHIFT)

/*
 * Link-layer configuration; valid on the first bus only (head 0).
 */
/* word LLP_CFG_REG: 64 bits */
#define PIC_LLP_CFG_REG_WIDTH                        64 /* established */
#define PIC_LLP_CFG_REG_LLP_MAXRETRY_SHIFT           16 /* established */
#define PIC_LLP_CFG_REG_LLP_MAXRETRY_MASK            0x3ffull
#define PIC_LLP_CFG_REG_LLP_MAXRETRY_INPLACE (PIC_LLP_CFG_REG_LLP_MAXRETRY_MASK << PIC_LLP_CFG_REG_LLP_MAXRETRY_SHIFT)
#define PIC_LLP_CFG_REG_LLP_NULLTIMEOUT_SHIFT        10 /* established */
#define PIC_LLP_CFG_REG_LLP_NULLTIMEOUT_MASK         0x3full
#define PIC_LLP_CFG_REG_LLP_NULLTIMEOUT_INPLACE (PIC_LLP_CFG_REG_LLP_NULLTIMEOUT_MASK << PIC_LLP_CFG_REG_LLP_NULLTIMEOUT_SHIFT)
#define PIC_LLP_CFG_REG_LLP_MAXBURST_SHIFT           0 /* established */
#define PIC_LLP_CFG_REG_LLP_MAXBURST_MASK            0x3ffull
#define PIC_LLP_CFG_REG_LLP_MAXBURST_INPLACE (PIC_LLP_CFG_REG_LLP_MAXBURST_MASK << PIC_LLP_CFG_REG_LLP_MAXBURST_SHIFT)

/*
 * Page map fault address: PCI address bits 21:4 and device number of a
 * translation that faulted.
 */
/* word MAP_FAULT_REG: 64 bits */
#define PIC_MAP_FAULT_REG_WIDTH                      64 /* established */
#define PIC_MAP_FAULT_REG_PCI_ADDR_SHIFT             4 /* established */
#define PIC_MAP_FAULT_REG_PCI_ADDR_MASK              0x3ffffull
#define PIC_MAP_FAULT_REG_PCI_ADDR_INPLACE (PIC_MAP_FAULT_REG_PCI_ADDR_MASK << PIC_MAP_FAULT_REG_PCI_ADDR_SHIFT)
#define PIC_MAP_FAULT_REG_PCI_DEV_NUM_SHIFT          0 /* established */
#define PIC_MAP_FAULT_REG_PCI_DEV_NUM_MASK           0x7ull
#define PIC_MAP_FAULT_REG_PCI_DEV_NUM_INPLACE (PIC_MAP_FAULT_REG_PCI_DEV_NUM_MASK << PIC_MAP_FAULT_REG_PCI_DEV_NUM_SHIFT)

/*
 * Multiple interrupt: set when a condition recurs before it is cleared. Bit 6
 * of the reset register clears it.
 */
/* word MULT_INT_REG: 64 bits */
#define PIC_MULT_INT_REG_WIDTH                       64 /* established */
#define PIC_MULT_INT_REG_INT_RAM_PERR_SHIFT          41 /* established */
#define PIC_MULT_INT_REG_INT_RAM_PERR_MASK           0x1ull
#define PIC_MULT_INT_REG_INT_RAM_PERR_INPLACE (PIC_MULT_INT_REG_INT_RAM_PERR_MASK << PIC_MULT_INT_REG_INT_RAM_PERR_SHIFT)
#define PIC_MULT_INT_REG_BUS_ARB_BROKE_SHIFT         40 /* established */
#define PIC_MULT_INT_REG_BUS_ARB_BROKE_MASK          0x1ull
#define PIC_MULT_INT_REG_BUS_ARB_BROKE_INPLACE (PIC_MULT_INT_REG_BUS_ARB_BROKE_MASK << PIC_MULT_INT_REG_BUS_ARB_BROKE_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_REQ_TOUT_SHIFT        39 /* established */
#define PIC_MULT_INT_REG_PCI_X_REQ_TOUT_MASK         0x1ull
#define PIC_MULT_INT_REG_PCI_X_REQ_TOUT_INPLACE (PIC_MULT_INT_REG_PCI_X_REQ_TOUT_MASK << PIC_MULT_INT_REG_PCI_X_REQ_TOUT_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_TABORT_SHIFT          38 /* established */
#define PIC_MULT_INT_REG_PCI_X_TABORT_MASK           0x1ull
#define PIC_MULT_INT_REG_PCI_X_TABORT_INPLACE (PIC_MULT_INT_REG_PCI_X_TABORT_MASK << PIC_MULT_INT_REG_PCI_X_TABORT_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_PERR_SHIFT            37 /* established */
#define PIC_MULT_INT_REG_PCI_X_PERR_MASK             0x1ull
#define PIC_MULT_INT_REG_PCI_X_PERR_INPLACE (PIC_MULT_INT_REG_PCI_X_PERR_MASK << PIC_MULT_INT_REG_PCI_X_PERR_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_SERR_SHIFT            36 /* established */
#define PIC_MULT_INT_REG_PCI_X_SERR_MASK             0x1ull
#define PIC_MULT_INT_REG_PCI_X_SERR_INPLACE (PIC_MULT_INT_REG_PCI_X_SERR_MASK << PIC_MULT_INT_REG_PCI_X_SERR_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_MRETRY_SHIFT          35 /* established */
#define PIC_MULT_INT_REG_PCI_X_MRETRY_MASK           0x1ull
#define PIC_MULT_INT_REG_PCI_X_MRETRY_INPLACE (PIC_MULT_INT_REG_PCI_X_MRETRY_MASK << PIC_MULT_INT_REG_PCI_X_MRETRY_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_MTOUT_SHIFT           34 /* established */
#define PIC_MULT_INT_REG_PCI_X_MTOUT_MASK            0x1ull
#define PIC_MULT_INT_REG_PCI_X_MTOUT_INPLACE (PIC_MULT_INT_REG_PCI_X_MTOUT_MASK << PIC_MULT_INT_REG_PCI_X_MTOUT_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_DA_PARITY_SHIFT       33 /* established */
#define PIC_MULT_INT_REG_PCI_X_DA_PARITY_MASK        0x1ull
#define PIC_MULT_INT_REG_PCI_X_DA_PARITY_INPLACE (PIC_MULT_INT_REG_PCI_X_DA_PARITY_MASK << PIC_MULT_INT_REG_PCI_X_DA_PARITY_SHIFT)
#define PIC_MULT_INT_REG_PCI_X_AD_PARITY_SHIFT       32 /* established */
#define PIC_MULT_INT_REG_PCI_X_AD_PARITY_MASK        0x1ull
#define PIC_MULT_INT_REG_PCI_X_AD_PARITY_INPLACE (PIC_MULT_INT_REG_PCI_X_AD_PARITY_MASK << PIC_MULT_INT_REG_PCI_X_AD_PARITY_SHIFT)
#define PIC_MULT_INT_REG_PMU_PAGE_FAULT_SHIFT        30 /* established */
#define PIC_MULT_INT_REG_PMU_PAGE_FAULT_MASK         0x1ull
#define PIC_MULT_INT_REG_PMU_PAGE_FAULT_INPLACE (PIC_MULT_INT_REG_PMU_PAGE_FAULT_MASK << PIC_MULT_INT_REG_PMU_PAGE_FAULT_SHIFT)
#define PIC_MULT_INT_REG_UNEXPECTED_RESP_SHIFT       29 /* established */
#define PIC_MULT_INT_REG_UNEXPECTED_RESP_MASK        0x1ull
#define PIC_MULT_INT_REG_UNEXPECTED_RESP_INPLACE (PIC_MULT_INT_REG_UNEXPECTED_RESP_MASK << PIC_MULT_INT_REG_UNEXPECTED_RESP_SHIFT)
#define PIC_MULT_INT_REG_BAD_XRESP_PACKET_SHIFT      28 /* established */
#define PIC_MULT_INT_REG_BAD_XRESP_PACKET_MASK       0x1ull
#define PIC_MULT_INT_REG_BAD_XRESP_PACKET_INPLACE (PIC_MULT_INT_REG_BAD_XRESP_PACKET_MASK << PIC_MULT_INT_REG_BAD_XRESP_PACKET_SHIFT)
#define PIC_MULT_INT_REG_BAD_XREQ_PACKET_SHIFT       27 /* established */
#define PIC_MULT_INT_REG_BAD_XREQ_PACKET_MASK        0x1ull
#define PIC_MULT_INT_REG_BAD_XREQ_PACKET_INPLACE (PIC_MULT_INT_REG_BAD_XREQ_PACKET_MASK << PIC_MULT_INT_REG_BAD_XREQ_PACKET_SHIFT)
#define PIC_MULT_INT_REG_RESP_XTALK_ERROR_SHIFT      26 /* established */
#define PIC_MULT_INT_REG_RESP_XTALK_ERROR_MASK       0x1ull
#define PIC_MULT_INT_REG_RESP_XTALK_ERROR_INPLACE (PIC_MULT_INT_REG_RESP_XTALK_ERROR_MASK << PIC_MULT_INT_REG_RESP_XTALK_ERROR_SHIFT)
#define PIC_MULT_INT_REG_REQ_XTALK_ERROR_SHIFT       25 /* established */
#define PIC_MULT_INT_REG_REQ_XTALK_ERROR_MASK        0x1ull
#define PIC_MULT_INT_REG_REQ_XTALK_ERROR_INPLACE (PIC_MULT_INT_REG_REQ_XTALK_ERROR_MASK << PIC_MULT_INT_REG_REQ_XTALK_ERROR_SHIFT)
#define PIC_MULT_INT_REG_INVALID_ACCESS_SHIFT        24 /* established */
#define PIC_MULT_INT_REG_INVALID_ACCESS_MASK         0x1ull
#define PIC_MULT_INT_REG_INVALID_ACCESS_INPLACE (PIC_MULT_INT_REG_INVALID_ACCESS_MASK << PIC_MULT_INT_REG_INVALID_ACCESS_SHIFT)
#define PIC_MULT_INT_REG_UNSUPPORTED_XOP_SHIFT       23 /* established */
#define PIC_MULT_INT_REG_UNSUPPORTED_XOP_MASK        0x1ull
#define PIC_MULT_INT_REG_UNSUPPORTED_XOP_INPLACE (PIC_MULT_INT_REG_UNSUPPORTED_XOP_MASK << PIC_MULT_INT_REG_UNSUPPORTED_XOP_SHIFT)
#define PIC_MULT_INT_REG_XREQ_FIFO_OFLOW_SHIFT       22 /* established */
#define PIC_MULT_INT_REG_XREQ_FIFO_OFLOW_MASK        0x1ull
#define PIC_MULT_INT_REG_XREQ_FIFO_OFLOW_INPLACE (PIC_MULT_INT_REG_XREQ_FIFO_OFLOW_MASK << PIC_MULT_INT_REG_XREQ_FIFO_OFLOW_SHIFT)
#define PIC_MULT_INT_REG_LLP_REC_SNERROR_SHIFT       21 /* established */
#define PIC_MULT_INT_REG_LLP_REC_SNERROR_MASK        0x1ull
#define PIC_MULT_INT_REG_LLP_REC_SNERROR_INPLACE (PIC_MULT_INT_REG_LLP_REC_SNERROR_MASK << PIC_MULT_INT_REG_LLP_REC_SNERROR_SHIFT)
#define PIC_MULT_INT_REG_LLP_REC_CBERROR_SHIFT       20 /* established */
#define PIC_MULT_INT_REG_LLP_REC_CBERROR_MASK        0x1ull
#define PIC_MULT_INT_REG_LLP_REC_CBERROR_INPLACE (PIC_MULT_INT_REG_LLP_REC_CBERROR_MASK << PIC_MULT_INT_REG_LLP_REC_CBERROR_SHIFT)
#define PIC_MULT_INT_REG_LLP_RCTY_SHIFT              19 /* established */
#define PIC_MULT_INT_REG_LLP_RCTY_MASK               0x1ull
#define PIC_MULT_INT_REG_LLP_RCTY_INPLACE (PIC_MULT_INT_REG_LLP_RCTY_MASK << PIC_MULT_INT_REG_LLP_RCTY_SHIFT)
#define PIC_MULT_INT_REG_LLP_TX_RETRY_SHIFT          18 /* established */
#define PIC_MULT_INT_REG_LLP_TX_RETRY_MASK           0x1ull
#define PIC_MULT_INT_REG_LLP_TX_RETRY_INPLACE (PIC_MULT_INT_REG_LLP_TX_RETRY_MASK << PIC_MULT_INT_REG_LLP_TX_RETRY_SHIFT)
#define PIC_MULT_INT_REG_LLP_TCTY_SHIFT              17 /* established */
#define PIC_MULT_INT_REG_LLP_TCTY_MASK               0x1ull
#define PIC_MULT_INT_REG_LLP_TCTY_INPLACE (PIC_MULT_INT_REG_LLP_TCTY_MASK << PIC_MULT_INT_REG_LLP_TCTY_SHIFT)
#define PIC_MULT_INT_REG_PCI_ABORT_SHIFT             15 /* established */
#define PIC_MULT_INT_REG_PCI_ABORT_MASK              0x1ull
#define PIC_MULT_INT_REG_PCI_ABORT_INPLACE (PIC_MULT_INT_REG_PCI_ABORT_MASK << PIC_MULT_INT_REG_PCI_ABORT_SHIFT)
#define PIC_MULT_INT_REG_PCI_PARITY_SHIFT            14 /* established */
#define PIC_MULT_INT_REG_PCI_PARITY_MASK             0x1ull
#define PIC_MULT_INT_REG_PCI_PARITY_INPLACE (PIC_MULT_INT_REG_PCI_PARITY_MASK << PIC_MULT_INT_REG_PCI_PARITY_SHIFT)
#define PIC_MULT_INT_REG_PCI_SERR_SHIFT              13 /* established */
#define PIC_MULT_INT_REG_PCI_SERR_MASK               0x1ull
#define PIC_MULT_INT_REG_PCI_SERR_INPLACE (PIC_MULT_INT_REG_PCI_SERR_MASK << PIC_MULT_INT_REG_PCI_SERR_SHIFT)
#define PIC_MULT_INT_REG_PCI_PERR_SHIFT              12 /* established */
#define PIC_MULT_INT_REG_PCI_PERR_MASK               0x1ull
#define PIC_MULT_INT_REG_PCI_PERR_INPLACE (PIC_MULT_INT_REG_PCI_PERR_MASK << PIC_MULT_INT_REG_PCI_PERR_SHIFT)
#define PIC_MULT_INT_REG_PCI_MASTER_TOUT_SHIFT       11 /* established */
#define PIC_MULT_INT_REG_PCI_MASTER_TOUT_MASK        0x1ull
#define PIC_MULT_INT_REG_PCI_MASTER_TOUT_INPLACE (PIC_MULT_INT_REG_PCI_MASTER_TOUT_MASK << PIC_MULT_INT_REG_PCI_MASTER_TOUT_SHIFT)
#define PIC_MULT_INT_REG_PCI_RETRY_CNT_SHIFT         10 /* established */
#define PIC_MULT_INT_REG_PCI_RETRY_CNT_MASK          0x1ull
#define PIC_MULT_INT_REG_PCI_RETRY_CNT_INPLACE (PIC_MULT_INT_REG_PCI_RETRY_CNT_MASK << PIC_MULT_INT_REG_PCI_RETRY_CNT_SHIFT)
#define PIC_MULT_INT_REG_XREAD_REQ_TOUT_SHIFT        9 /* established */
#define PIC_MULT_INT_REG_XREAD_REQ_TOUT_MASK         0x1ull
#define PIC_MULT_INT_REG_XREAD_REQ_TOUT_INPLACE (PIC_MULT_INT_REG_XREAD_REQ_TOUT_MASK << PIC_MULT_INT_REG_XREAD_REQ_TOUT_SHIFT)
#define PIC_MULT_INT_REG_INT_STATE_SHIFT             0 /* established */
#define PIC_MULT_INT_REG_INT_STATE_MASK              0xffull
#define PIC_MULT_INT_REG_INT_STATE_INPLACE (PIC_MULT_INT_REG_INT_STATE_MASK << PIC_MULT_INT_REG_INT_STATE_SHIFT)

/*
 * PCI-X error attribute (the 2.4-era offset list and the Altix structure differ
 * on where it sits; IRIX reaches the bus error attribute at 0x608). Assuming
 * the split-completion and DMA-request error attributes (0x620, 0x628) share
 * the layout is inferred from the names only.
 */
/* word PCIX_ERR_ATTR_REG: 64 bits */
#define PIC_PCIX_ERR_ATTR_REG_WIDTH                  64 /* established */
#define PIC_PCIX_ERR_ATTR_REG_BUS_CMD_SHIFT          44 /* established */
#define PIC_PCIX_ERR_ATTR_REG_BUS_CMD_MASK           0xfull
#define PIC_PCIX_ERR_ATTR_REG_BUS_CMD_INPLACE (PIC_PCIX_ERR_ATTR_REG_BUS_CMD_MASK << PIC_PCIX_ERR_ATTR_REG_BUS_CMD_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_BYTE_CNT_SHIFT         32 /* established */
#define PIC_PCIX_ERR_ATTR_REG_BYTE_CNT_MASK          0xfffull
#define PIC_PCIX_ERR_ATTR_REG_BYTE_CNT_INPLACE (PIC_PCIX_ERR_ATTR_REG_BYTE_CNT_MASK << PIC_PCIX_ERR_ATTR_REG_BYTE_CNT_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_NS_SHIFT               30 /* established */
#define PIC_PCIX_ERR_ATTR_REG_NS_MASK                0x1ull
#define PIC_PCIX_ERR_ATTR_REG_NS_INPLACE (PIC_PCIX_ERR_ATTR_REG_NS_MASK << PIC_PCIX_ERR_ATTR_REG_NS_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_RO_SHIFT               29 /* established */
#define PIC_PCIX_ERR_ATTR_REG_RO_MASK                0x1ull
#define PIC_PCIX_ERR_ATTR_REG_RO_INPLACE (PIC_PCIX_ERR_ATTR_REG_RO_MASK << PIC_PCIX_ERR_ATTR_REG_RO_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_TAG_SHIFT              24 /* established */
#define PIC_PCIX_ERR_ATTR_REG_TAG_MASK               0x1full
#define PIC_PCIX_ERR_ATTR_REG_TAG_INPLACE (PIC_PCIX_ERR_ATTR_REG_TAG_MASK << PIC_PCIX_ERR_ATTR_REG_TAG_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_BUS_NUM_SHIFT          16 /* established */
#define PIC_PCIX_ERR_ATTR_REG_BUS_NUM_MASK           0xffull
#define PIC_PCIX_ERR_ATTR_REG_BUS_NUM_INPLACE (PIC_PCIX_ERR_ATTR_REG_BUS_NUM_MASK << PIC_PCIX_ERR_ATTR_REG_BUS_NUM_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_DEV_NUM_SHIFT          11 /* established */
#define PIC_PCIX_ERR_ATTR_REG_DEV_NUM_MASK           0x1full
#define PIC_PCIX_ERR_ATTR_REG_DEV_NUM_INPLACE (PIC_PCIX_ERR_ATTR_REG_DEV_NUM_MASK << PIC_PCIX_ERR_ATTR_REG_DEV_NUM_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_FUN_NUM_SHIFT          8 /* established */
#define PIC_PCIX_ERR_ATTR_REG_FUN_NUM_MASK           0x7ull
#define PIC_PCIX_ERR_ATTR_REG_FUN_NUM_INPLACE (PIC_PCIX_ERR_ATTR_REG_FUN_NUM_MASK << PIC_PCIX_ERR_ATTR_REG_FUN_NUM_SHIFT)
#define PIC_PCIX_ERR_ATTR_REG_L_BYTE_CNT_SHIFT       0 /* established */
#define PIC_PCIX_ERR_ATTR_REG_L_BYTE_CNT_MASK        0xffull
#define PIC_PCIX_ERR_ATTR_REG_L_BYTE_CNT_INPLACE (PIC_PCIX_ERR_ATTR_REG_L_BYTE_CNT_MASK << PIC_PCIX_ERR_ATTR_REG_L_BYTE_CNT_SHIFT)

/*
 * PCI-X read buffer attribute.
 */
/* word PCIX_READ_BUF_ATTR_REG: 64 bits */
#define PIC_PCIX_READ_BUF_ATTR_REG_WIDTH             64 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_BUS_CMD_SHIFT     44 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_BUS_CMD_MASK      0xfull
#define PIC_PCIX_READ_BUF_ATTR_REG_BUS_CMD_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_BUS_CMD_MASK << PIC_PCIX_READ_BUF_ATTR_REG_BUS_CMD_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_BYTE_CNT_SHIFT    32 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_BYTE_CNT_MASK     0xfffull
#define PIC_PCIX_READ_BUF_ATTR_REG_BYTE_CNT_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_BYTE_CNT_MASK << PIC_PCIX_READ_BUF_ATTR_REG_BYTE_CNT_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_ENTRY_VALID_SHIFT 31 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_ENTRY_VALID_MASK  0x1ull
#define PIC_PCIX_READ_BUF_ATTR_REG_ENTRY_VALID_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_ENTRY_VALID_MASK << PIC_PCIX_READ_BUF_ATTR_REG_ENTRY_VALID_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_NS_SHIFT          30 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_NS_MASK           0x1ull
#define PIC_PCIX_READ_BUF_ATTR_REG_NS_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_NS_MASK << PIC_PCIX_READ_BUF_ATTR_REG_NS_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_RO_SHIFT          29 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_RO_MASK           0x1ull
#define PIC_PCIX_READ_BUF_ATTR_REG_RO_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_RO_MASK << PIC_PCIX_READ_BUF_ATTR_REG_RO_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_TAG_SHIFT         24 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_TAG_MASK          0x1full
#define PIC_PCIX_READ_BUF_ATTR_REG_TAG_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_TAG_MASK << PIC_PCIX_READ_BUF_ATTR_REG_TAG_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_BUS_NUM_SHIFT     16 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_BUS_NUM_MASK      0xffull
#define PIC_PCIX_READ_BUF_ATTR_REG_BUS_NUM_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_BUS_NUM_MASK << PIC_PCIX_READ_BUF_ATTR_REG_BUS_NUM_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_DEV_NUM_SHIFT     11 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_DEV_NUM_MASK      0x1full
#define PIC_PCIX_READ_BUF_ATTR_REG_DEV_NUM_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_DEV_NUM_MASK << PIC_PCIX_READ_BUF_ATTR_REG_DEV_NUM_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_FUN_NUM_SHIFT     8 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_FUN_NUM_MASK      0x7ull
#define PIC_PCIX_READ_BUF_ATTR_REG_FUN_NUM_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_FUN_NUM_MASK << PIC_PCIX_READ_BUF_ATTR_REG_FUN_NUM_SHIFT)
#define PIC_PCIX_READ_BUF_ATTR_REG_F_BUFFER_INDEX_SHIFT 0 /* established */
#define PIC_PCIX_READ_BUF_ATTR_REG_F_BUFFER_INDEX_MASK 0x3full
#define PIC_PCIX_READ_BUF_ATTR_REG_F_BUFFER_INDEX_INPLACE (PIC_PCIX_READ_BUF_ATTR_REG_F_BUFFER_INDEX_MASK << PIC_PCIX_READ_BUF_ATTR_REG_F_BUFFER_INDEX_SHIFT)

/*
 * PCI-X read request timeout error pointer (read buffer structure and
 * location). The 2.4-era offset list puts it in the low register page, but the
 * Altix structure puts the PCI-X error group at 0x600 and up. Which slot holds
 * this layout is unknown (README, revision differences).
 */
/* word PCIX_TIMEOUT_REG: 64 bits */
#define PIC_PCIX_TIMEOUT_REG_WIDTH                   64 /* established */
#define PIC_PCIX_TIMEOUT_REG_RD_BUFF_LOC_SHIFT       4 /* established */
#define PIC_PCIX_TIMEOUT_REG_RD_BUFF_LOC_MASK        0x1full
#define PIC_PCIX_TIMEOUT_REG_RD_BUFF_LOC_INPLACE (PIC_PCIX_TIMEOUT_REG_RD_BUFF_LOC_MASK << PIC_PCIX_TIMEOUT_REG_RD_BUFF_LOC_SHIFT)
#define PIC_PCIX_TIMEOUT_REG_RD_BUFF_STRUCT_SHIFT    0 /* established */
#define PIC_PCIX_TIMEOUT_REG_RD_BUFF_STRUCT_MASK     0xfull
#define PIC_PCIX_TIMEOUT_REG_RD_BUFF_STRUCT_INPLACE (PIC_PCIX_TIMEOUT_REG_RD_BUFF_STRUCT_MASK << PIC_PCIX_TIMEOUT_REG_RD_BUFF_STRUCT_SHIFT)

/*
 * PCI-X write buffer attribute.
 */
/* word PCIX_WRITE_BUF_ATTR_REG: 64 bits */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_WIDTH            64 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_CMD_SHIFT    44 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_CMD_MASK     0xfull
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_CMD_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_CMD_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_CMD_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BYTE_CNT_SHIFT   32 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BYTE_CNT_MASK    0xfffull
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BYTE_CNT_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_BYTE_CNT_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_BYTE_CNT_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_ENTRY_VALID_SHIFT 31 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_ENTRY_VALID_MASK 0x1ull
#define PIC_PCIX_WRITE_BUF_ATTR_REG_ENTRY_VALID_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_ENTRY_VALID_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_ENTRY_VALID_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_NS_SHIFT         30 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_NS_MASK          0x1ull
#define PIC_PCIX_WRITE_BUF_ATTR_REG_NS_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_NS_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_NS_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_RO_SHIFT         29 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_RO_MASK          0x1ull
#define PIC_PCIX_WRITE_BUF_ATTR_REG_RO_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_RO_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_RO_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_TAG_SHIFT        24 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_TAG_MASK         0x1full
#define PIC_PCIX_WRITE_BUF_ATTR_REG_TAG_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_TAG_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_TAG_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_NUM_SHIFT    16 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_NUM_MASK     0xffull
#define PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_NUM_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_NUM_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_BUS_NUM_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_DEV_NUM_SHIFT    11 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_DEV_NUM_MASK     0x1full
#define PIC_PCIX_WRITE_BUF_ATTR_REG_DEV_NUM_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_DEV_NUM_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_DEV_NUM_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_FUN_NUM_SHIFT    8 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_FUN_NUM_MASK     0x7ull
#define PIC_PCIX_WRITE_BUF_ATTR_REG_FUN_NUM_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_FUN_NUM_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_FUN_NUM_SHIFT)
#define PIC_PCIX_WRITE_BUF_ATTR_REG_F_BUFFER_INDEX_SHIFT 0 /* established */
#define PIC_PCIX_WRITE_BUF_ATTR_REG_F_BUFFER_INDEX_MASK 0x3full
#define PIC_PCIX_WRITE_BUF_ATTR_REG_F_BUFFER_INDEX_INPLACE (PIC_PCIX_WRITE_BUF_ATTR_REG_F_BUFFER_INDEX_MASK << PIC_PCIX_WRITE_BUF_ATTR_REG_F_BUFFER_INDEX_SHIFT)

/*
 * PCI-X write buffer valid cache lines.
 */
/* word PCIX_WRITE_BUF_VALID_REG: 64 bits */
#define PIC_PCIX_WRITE_BUF_VALID_REG_WIDTH           64 /* established */
#define PIC_PCIX_WRITE_BUF_VALID_REG_WRT_VALID_BUFF_SHIFT 0 /* established */
#define PIC_PCIX_WRITE_BUF_VALID_REG_WRT_VALID_BUFF_MASK 0xffffffffull
#define PIC_PCIX_WRITE_BUF_VALID_REG_WRT_VALID_BUFF_INPLACE (PIC_PCIX_WRITE_BUF_VALID_REG_WRT_VALID_BUFF_MASK << PIC_PCIX_WRITE_BUF_VALID_REG_WRT_VALID_BUFF_SHIFT)

/*
 * PCI bus error address, lower word, with the requester identity. IRIX reads it
 * for the bus address of the error.
 */
/* word PCI_ERR_LOWER_REG: 64 bits */
#define PIC_PCI_ERR_LOWER_REG_WIDTH                  64 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_XTALK_DID_SHIFT    56 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_XTALK_DID_MASK     0xfull
#define PIC_PCI_ERR_LOWER_REG_PCI_XTALK_DID_INPLACE (PIC_PCI_ERR_LOWER_REG_PCI_XTALK_DID_MASK << PIC_PCI_ERR_LOWER_REG_PCI_XTALK_DID_SHIFT)
#define PIC_PCI_ERR_LOWER_REG_PCI_DAC_SHIFT          53 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_DAC_MASK           0x1ull
#define PIC_PCI_ERR_LOWER_REG_PCI_DAC_INPLACE (PIC_PCI_ERR_LOWER_REG_PCI_DAC_MASK << PIC_PCI_ERR_LOWER_REG_PCI_DAC_SHIFT)
#define PIC_PCI_ERR_LOWER_REG_PCI_DEV_MASTER_SHIFT   52 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_DEV_MASTER_MASK    0x1ull
#define PIC_PCI_ERR_LOWER_REG_PCI_DEV_MASTER_INPLACE (PIC_PCI_ERR_LOWER_REG_PCI_DEV_MASTER_MASK << PIC_PCI_ERR_LOWER_REG_PCI_DEV_MASTER_SHIFT)
#define PIC_PCI_ERR_LOWER_REG_PCI_VDEV_SHIFT         51 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_VDEV_MASK          0x1ull
#define PIC_PCI_ERR_LOWER_REG_PCI_VDEV_INPLACE (PIC_PCI_ERR_LOWER_REG_PCI_VDEV_MASK << PIC_PCI_ERR_LOWER_REG_PCI_VDEV_SHIFT)
#define PIC_PCI_ERR_LOWER_REG_PCI_DEV_NUM_SHIFT      48 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_DEV_NUM_MASK       0x7ull
#define PIC_PCI_ERR_LOWER_REG_PCI_DEV_NUM_INPLACE (PIC_PCI_ERR_LOWER_REG_PCI_DEV_NUM_MASK << PIC_PCI_ERR_LOWER_REG_PCI_DEV_NUM_SHIFT)
#define PIC_PCI_ERR_LOWER_REG_PCI_UADDR_ERR_SHIFT    32 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_UADDR_ERR_MASK     0xffffull
#define PIC_PCI_ERR_LOWER_REG_PCI_UADDR_ERR_INPLACE (PIC_PCI_ERR_LOWER_REG_PCI_UADDR_ERR_MASK << PIC_PCI_ERR_LOWER_REG_PCI_UADDR_ERR_SHIFT)
#define PIC_PCI_ERR_LOWER_REG_PCI_LADDR_ERR_SHIFT    0 /* established */
#define PIC_PCI_ERR_LOWER_REG_PCI_LADDR_ERR_MASK     0xffffffffull
#define PIC_PCI_ERR_LOWER_REG_PCI_LADDR_ERR_INPLACE (PIC_PCI_ERR_LOWER_REG_PCI_LADDR_ERR_MASK << PIC_PCI_ERR_LOWER_REG_PCI_LADDR_ERR_SHIFT)

/*
 * PCI bus error address, upper word, with the requester identity.
 */
/* word PCI_ERR_UPPER_REG: 64 bits */
#define PIC_PCI_ERR_UPPER_REG_WIDTH                  64 /* established */
#define PIC_PCI_ERR_UPPER_REG_PCI_XTALK_DID_SHIFT    24 /* established */
#define PIC_PCI_ERR_UPPER_REG_PCI_XTALK_DID_MASK     0xfull
#define PIC_PCI_ERR_UPPER_REG_PCI_XTALK_DID_INPLACE (PIC_PCI_ERR_UPPER_REG_PCI_XTALK_DID_MASK << PIC_PCI_ERR_UPPER_REG_PCI_XTALK_DID_SHIFT)
#define PIC_PCI_ERR_UPPER_REG_PCI_DAC_SHIFT          21 /* established */
#define PIC_PCI_ERR_UPPER_REG_PCI_DAC_MASK           0x1ull
#define PIC_PCI_ERR_UPPER_REG_PCI_DAC_INPLACE (PIC_PCI_ERR_UPPER_REG_PCI_DAC_MASK << PIC_PCI_ERR_UPPER_REG_PCI_DAC_SHIFT)
#define PIC_PCI_ERR_UPPER_REG_PCI_DEV_MASTER_SHIFT   20 /* established */
#define PIC_PCI_ERR_UPPER_REG_PCI_DEV_MASTER_MASK    0x1ull
#define PIC_PCI_ERR_UPPER_REG_PCI_DEV_MASTER_INPLACE (PIC_PCI_ERR_UPPER_REG_PCI_DEV_MASTER_MASK << PIC_PCI_ERR_UPPER_REG_PCI_DEV_MASTER_SHIFT)
#define PIC_PCI_ERR_UPPER_REG_PCI_VDEV_SHIFT         19 /* established */
#define PIC_PCI_ERR_UPPER_REG_PCI_VDEV_MASK          0x1ull
#define PIC_PCI_ERR_UPPER_REG_PCI_VDEV_INPLACE (PIC_PCI_ERR_UPPER_REG_PCI_VDEV_MASK << PIC_PCI_ERR_UPPER_REG_PCI_VDEV_SHIFT)
#define PIC_PCI_ERR_UPPER_REG_PCI_DEV_NUM_SHIFT      16 /* established */
#define PIC_PCI_ERR_UPPER_REG_PCI_DEV_NUM_MASK       0x7ull
#define PIC_PCI_ERR_UPPER_REG_PCI_DEV_NUM_INPLACE (PIC_PCI_ERR_UPPER_REG_PCI_DEV_NUM_MASK << PIC_PCI_ERR_UPPER_REG_PCI_DEV_NUM_SHIFT)
#define PIC_PCI_ERR_UPPER_REG_PCI_UADDR_ERR_SHIFT    0 /* established */
#define PIC_PCI_ERR_UPPER_REG_PCI_UADDR_ERR_MASK     0xffffull
#define PIC_PCI_ERR_UPPER_REG_PCI_UADDR_ERR_INPLACE (PIC_PCI_ERR_UPPER_REG_PCI_UADDR_ERR_MASK << PIC_PCI_ERR_UPPER_REG_PCI_UADDR_ERR_SHIFT)

/*
 * Internal RAM parity error log: failing entry address and per-RAM error flags.
 */
/* word RAM_PERR_REG: 64 bits */
#define PIC_RAM_PERR_REG_WIDTH                       64 /* established */
#define PIC_RAM_PERR_REG_ATE_ERR_ADDR_SHIFT          48 /* established */
#define PIC_RAM_PERR_REG_ATE_ERR_ADDR_MASK           0x3ffull
#define PIC_RAM_PERR_REG_ATE_ERR_ADDR_INPLACE (PIC_RAM_PERR_REG_ATE_ERR_ADDR_MASK << PIC_RAM_PERR_REG_ATE_ERR_ADDR_SHIFT)
#define PIC_RAM_PERR_REG_RD_RESP_ERR_ADDR_SHIFT      32 /* established */
#define PIC_RAM_PERR_REG_RD_RESP_ERR_ADDR_MASK       0x1ffull
#define PIC_RAM_PERR_REG_RD_RESP_ERR_ADDR_INPLACE (PIC_RAM_PERR_REG_RD_RESP_ERR_ADDR_MASK << PIC_RAM_PERR_REG_RD_RESP_ERR_ADDR_SHIFT)
#define PIC_RAM_PERR_REG_WRT_RESP_ERR_ADDR_SHIFT     24 /* established */
#define PIC_RAM_PERR_REG_WRT_RESP_ERR_ADDR_MASK      0xffull
#define PIC_RAM_PERR_REG_WRT_RESP_ERR_ADDR_INPLACE (PIC_RAM_PERR_REG_WRT_RESP_ERR_ADDR_MASK << PIC_RAM_PERR_REG_WRT_RESP_ERR_ADDR_SHIFT)
#define PIC_RAM_PERR_REG_ATE_ERR_SHIFT               21 /* established */
#define PIC_RAM_PERR_REG_ATE_ERR_MASK                0x1ull
#define PIC_RAM_PERR_REG_ATE_ERR_INPLACE (PIC_RAM_PERR_REG_ATE_ERR_MASK << PIC_RAM_PERR_REG_ATE_ERR_SHIFT)
#define PIC_RAM_PERR_REG_RD_RESP_ERR_SHIFT           20 /* established */
#define PIC_RAM_PERR_REG_RD_RESP_ERR_MASK            0x1ull
#define PIC_RAM_PERR_REG_RD_RESP_ERR_INPLACE (PIC_RAM_PERR_REG_RD_RESP_ERR_MASK << PIC_RAM_PERR_REG_RD_RESP_ERR_SHIFT)
#define PIC_RAM_PERR_REG_WRT_RESP_ERR_SHIFT          19 /* established */
#define PIC_RAM_PERR_REG_WRT_RESP_ERR_MASK           0x1ull
#define PIC_RAM_PERR_REG_WRT_RESP_ERR_INPLACE (PIC_RAM_PERR_REG_WRT_RESP_ERR_MASK << PIC_RAM_PERR_REG_WRT_RESP_ERR_SHIFT)
#define PIC_RAM_PERR_REG_DBE_ATE_SHIFT               16 /* established */
#define PIC_RAM_PERR_REG_DBE_ATE_MASK                0x7ull
#define PIC_RAM_PERR_REG_DBE_ATE_INPLACE (PIC_RAM_PERR_REG_DBE_ATE_MASK << PIC_RAM_PERR_REG_DBE_ATE_SHIFT)
#define PIC_RAM_PERR_REG_DBE_RD_SHIFT                8 /* established */
#define PIC_RAM_PERR_REG_DBE_RD_MASK                 0xffull
#define PIC_RAM_PERR_REG_DBE_RD_INPLACE (PIC_RAM_PERR_REG_DBE_RD_MASK << PIC_RAM_PERR_REG_DBE_RD_SHIFT)
#define PIC_RAM_PERR_REG_DBE_WRT_SHIFT               0 /* established */
#define PIC_RAM_PERR_REG_DBE_WRT_MASK                0xffull
#define PIC_RAM_PERR_REG_DBE_WRT_INPLACE (PIC_RAM_PERR_REG_DBE_WRT_MASK << PIC_RAM_PERR_REG_DBE_WRT_SHIFT)

/*
 * Request timeout reload value. The timer ticks every 32 PCI clocks (960 ns at
 * 33 MHz). IRIX writes 0x750 on revision 1 only.
 */
/* word REQ_TIMEOUT_REG: 64 bits */
#define PIC_REQ_TIMEOUT_REG_WIDTH                    64 /* established */
#define PIC_REQ_TIMEOUT_REG_TIME_OUT_SHIFT           0 /* established */
#define PIC_REQ_TIMEOUT_REG_TIME_OUT_MASK            0xfffffull
#define PIC_REQ_TIMEOUT_REG_TIME_OUT_INPLACE (PIC_REQ_TIMEOUT_REG_TIME_OUT_MASK << PIC_REQ_TIMEOUT_REG_TIME_OUT_SHIFT)

/*
 * Read response buffer clear: write a one to discard a buffer.
 */
/* word RESP_CLEAR_REG: 64 bits */
#define PIC_RESP_CLEAR_REG_WIDTH                     64 /* established */
#define PIC_RESP_CLEAR_REG_RRB_CLEAR_SHIFT           0 /* established */
#define PIC_RESP_CLEAR_REG_RRB_CLEAR_MASK            0xffffull
#define PIC_RESP_CLEAR_REG_RRB_CLEAR_INPLACE (PIC_RESP_CLEAR_REG_RRB_CLEAR_MASK << PIC_RESP_CLEAR_REG_RRB_CLEAR_SHIFT)

/*
 * Response-buffer error address, lower word, with the device and buffer number.
 */
/* word RESP_ERR_LOWER_REG: 64 bits */
#define PIC_RESP_ERR_LOWER_REG_WIDTH                 64 /* established */
#define PIC_RESP_ERR_LOWER_REG_DEV_NUM_SHIFT         52 /* established */
#define PIC_RESP_ERR_LOWER_REG_DEV_NUM_MASK          0x7ull
#define PIC_RESP_ERR_LOWER_REG_DEV_NUM_INPLACE (PIC_RESP_ERR_LOWER_REG_DEV_NUM_MASK << PIC_RESP_ERR_LOWER_REG_DEV_NUM_SHIFT)
#define PIC_RESP_ERR_LOWER_REG_BUFF_NUM_SHIFT        48 /* established */
#define PIC_RESP_ERR_LOWER_REG_BUFF_NUM_MASK         0xfull
#define PIC_RESP_ERR_LOWER_REG_BUFF_NUM_INPLACE (PIC_RESP_ERR_LOWER_REG_BUFF_NUM_MASK << PIC_RESP_ERR_LOWER_REG_BUFF_NUM_SHIFT)
#define PIC_RESP_ERR_LOWER_REG_UPP_ADDR_SHIFT        32 /* established */
#define PIC_RESP_ERR_LOWER_REG_UPP_ADDR_MASK         0xffffull
#define PIC_RESP_ERR_LOWER_REG_UPP_ADDR_INPLACE (PIC_RESP_ERR_LOWER_REG_UPP_ADDR_MASK << PIC_RESP_ERR_LOWER_REG_UPP_ADDR_SHIFT)
#define PIC_RESP_ERR_LOWER_REG_LOW_ADDR_SHIFT        0 /* established */
#define PIC_RESP_ERR_LOWER_REG_LOW_ADDR_MASK         0xffffffffull
#define PIC_RESP_ERR_LOWER_REG_LOW_ADDR_INPLACE (PIC_RESP_ERR_LOWER_REG_LOW_ADDR_MASK << PIC_RESP_ERR_LOWER_REG_LOW_ADDR_SHIFT)

/*
 * Response-buffer error address, upper word, with the device and buffer number
 * of the failing entry.
 */
/* word RESP_ERR_UPPER_REG: 64 bits */
#define PIC_RESP_ERR_UPPER_REG_WIDTH                 64 /* established */
#define PIC_RESP_ERR_UPPER_REG_DEV_NUM_SHIFT         20 /* established */
#define PIC_RESP_ERR_UPPER_REG_DEV_NUM_MASK          0x7ull
#define PIC_RESP_ERR_UPPER_REG_DEV_NUM_INPLACE (PIC_RESP_ERR_UPPER_REG_DEV_NUM_MASK << PIC_RESP_ERR_UPPER_REG_DEV_NUM_SHIFT)
#define PIC_RESP_ERR_UPPER_REG_BUFF_NUM_SHIFT        16 /* established */
#define PIC_RESP_ERR_UPPER_REG_BUFF_NUM_MASK         0xfull
#define PIC_RESP_ERR_UPPER_REG_BUFF_NUM_INPLACE (PIC_RESP_ERR_UPPER_REG_BUFF_NUM_MASK << PIC_RESP_ERR_UPPER_REG_BUFF_NUM_SHIFT)
#define PIC_RESP_ERR_UPPER_REG_UPP_ADDR_SHIFT        0 /* established */
#define PIC_RESP_ERR_UPPER_REG_UPP_ADDR_MASK         0xffffull
#define PIC_RESP_ERR_UPPER_REG_UPP_ADDR_INPLACE (PIC_RESP_ERR_UPPER_REG_UPP_ADDR_MASK << PIC_RESP_ERR_UPPER_REG_UPP_ADDR_SHIFT)

/*
 * Read response buffer status: one valid bit and one in-use bit per buffer.
 */
/* word RESP_STATUS_REG: 64 bits */
#define PIC_RESP_STATUS_REG_WIDTH                    64 /* established */
#define PIC_RESP_STATUS_REG_RRB_VALID_SHIFT          16 /* established */
#define PIC_RESP_STATUS_REG_RRB_VALID_MASK           0xffffull
#define PIC_RESP_STATUS_REG_RRB_VALID_INPLACE (PIC_RESP_STATUS_REG_RRB_VALID_MASK << PIC_RESP_STATUS_REG_RRB_VALID_SHIFT)
#define PIC_RESP_STATUS_REG_RRB_INUSE_SHIFT          0 /* established */
#define PIC_RESP_STATUS_REG_RRB_INUSE_MASK           0xffffull
#define PIC_RESP_STATUS_REG_RRB_INUSE_INPLACE (PIC_RESP_STATUS_REG_RRB_INUSE_MASK << PIC_RESP_STATUS_REG_RRB_INUSE_SHIFT)

/*
 * Read response buffer allocation, even devices. Buffers 0,2,...,14, four bits
 * each: enable, 2-bit virtual channel, device-pair bit.
 */
/* word RRB_EVEN_REG: 64 bits */
#define PIC_RRB_EVEN_REG_WIDTH                       64 /* established */
#define PIC_RRB_EVEN_REG_BUFF_14_EN_SHIFT            31 /* established */
#define PIC_RRB_EVEN_REG_BUFF_14_EN_MASK             0x1ull
#define PIC_RRB_EVEN_REG_BUFF_14_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_14_EN_MASK << PIC_RRB_EVEN_REG_BUFF_14_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_14_VDEV_SHIFT          29 /* established */
#define PIC_RRB_EVEN_REG_BUFF_14_VDEV_MASK           0x3ull
#define PIC_RRB_EVEN_REG_BUFF_14_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_14_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_14_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_14_PDEV_SHIFT          28 /* established */
#define PIC_RRB_EVEN_REG_BUFF_14_PDEV_MASK           0x1ull
#define PIC_RRB_EVEN_REG_BUFF_14_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_14_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_14_PDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_12_EN_SHIFT            27 /* established */
#define PIC_RRB_EVEN_REG_BUFF_12_EN_MASK             0x1ull
#define PIC_RRB_EVEN_REG_BUFF_12_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_12_EN_MASK << PIC_RRB_EVEN_REG_BUFF_12_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_12_VDEV_SHIFT          25 /* established */
#define PIC_RRB_EVEN_REG_BUFF_12_VDEV_MASK           0x3ull
#define PIC_RRB_EVEN_REG_BUFF_12_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_12_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_12_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_12_PDEV_SHIFT          24 /* established */
#define PIC_RRB_EVEN_REG_BUFF_12_PDEV_MASK           0x1ull
#define PIC_RRB_EVEN_REG_BUFF_12_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_12_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_12_PDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_10_EN_SHIFT            23 /* established */
#define PIC_RRB_EVEN_REG_BUFF_10_EN_MASK             0x1ull
#define PIC_RRB_EVEN_REG_BUFF_10_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_10_EN_MASK << PIC_RRB_EVEN_REG_BUFF_10_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_10_VDEV_SHIFT          21 /* established */
#define PIC_RRB_EVEN_REG_BUFF_10_VDEV_MASK           0x3ull
#define PIC_RRB_EVEN_REG_BUFF_10_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_10_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_10_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_10_PDEV_SHIFT          20 /* established */
#define PIC_RRB_EVEN_REG_BUFF_10_PDEV_MASK           0x1ull
#define PIC_RRB_EVEN_REG_BUFF_10_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_10_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_10_PDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_8_EN_SHIFT             19 /* established */
#define PIC_RRB_EVEN_REG_BUFF_8_EN_MASK              0x1ull
#define PIC_RRB_EVEN_REG_BUFF_8_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_8_EN_MASK << PIC_RRB_EVEN_REG_BUFF_8_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_8_VDEV_SHIFT           17 /* established */
#define PIC_RRB_EVEN_REG_BUFF_8_VDEV_MASK            0x3ull
#define PIC_RRB_EVEN_REG_BUFF_8_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_8_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_8_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_8_PDEV_SHIFT           16 /* established */
#define PIC_RRB_EVEN_REG_BUFF_8_PDEV_MASK            0x1ull
#define PIC_RRB_EVEN_REG_BUFF_8_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_8_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_8_PDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_6_EN_SHIFT             15 /* established */
#define PIC_RRB_EVEN_REG_BUFF_6_EN_MASK              0x1ull
#define PIC_RRB_EVEN_REG_BUFF_6_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_6_EN_MASK << PIC_RRB_EVEN_REG_BUFF_6_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_6_VDEV_SHIFT           13 /* established */
#define PIC_RRB_EVEN_REG_BUFF_6_VDEV_MASK            0x3ull
#define PIC_RRB_EVEN_REG_BUFF_6_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_6_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_6_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_6_PDEV_SHIFT           12 /* established */
#define PIC_RRB_EVEN_REG_BUFF_6_PDEV_MASK            0x1ull
#define PIC_RRB_EVEN_REG_BUFF_6_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_6_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_6_PDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_4_EN_SHIFT             11 /* established */
#define PIC_RRB_EVEN_REG_BUFF_4_EN_MASK              0x1ull
#define PIC_RRB_EVEN_REG_BUFF_4_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_4_EN_MASK << PIC_RRB_EVEN_REG_BUFF_4_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_4_VDEV_SHIFT           9 /* established */
#define PIC_RRB_EVEN_REG_BUFF_4_VDEV_MASK            0x3ull
#define PIC_RRB_EVEN_REG_BUFF_4_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_4_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_4_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_4_PDEV_SHIFT           8 /* established */
#define PIC_RRB_EVEN_REG_BUFF_4_PDEV_MASK            0x1ull
#define PIC_RRB_EVEN_REG_BUFF_4_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_4_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_4_PDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_2_EN_SHIFT             7 /* established */
#define PIC_RRB_EVEN_REG_BUFF_2_EN_MASK              0x1ull
#define PIC_RRB_EVEN_REG_BUFF_2_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_2_EN_MASK << PIC_RRB_EVEN_REG_BUFF_2_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_2_VDEV_SHIFT           5 /* established */
#define PIC_RRB_EVEN_REG_BUFF_2_VDEV_MASK            0x3ull
#define PIC_RRB_EVEN_REG_BUFF_2_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_2_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_2_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_2_PDEV_SHIFT           4 /* established */
#define PIC_RRB_EVEN_REG_BUFF_2_PDEV_MASK            0x1ull
#define PIC_RRB_EVEN_REG_BUFF_2_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_2_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_2_PDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_0_EN_SHIFT             3 /* established */
#define PIC_RRB_EVEN_REG_BUFF_0_EN_MASK              0x1ull
#define PIC_RRB_EVEN_REG_BUFF_0_EN_INPLACE (PIC_RRB_EVEN_REG_BUFF_0_EN_MASK << PIC_RRB_EVEN_REG_BUFF_0_EN_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_0_VDEV_SHIFT           1 /* established */
#define PIC_RRB_EVEN_REG_BUFF_0_VDEV_MASK            0x3ull
#define PIC_RRB_EVEN_REG_BUFF_0_VDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_0_VDEV_MASK << PIC_RRB_EVEN_REG_BUFF_0_VDEV_SHIFT)
#define PIC_RRB_EVEN_REG_BUFF_0_PDEV_SHIFT           0 /* established */
#define PIC_RRB_EVEN_REG_BUFF_0_PDEV_MASK            0x1ull
#define PIC_RRB_EVEN_REG_BUFF_0_PDEV_INPLACE (PIC_RRB_EVEN_REG_BUFF_0_PDEV_MASK << PIC_RRB_EVEN_REG_BUFF_0_PDEV_SHIFT)

/*
 * Read response buffer allocation, odd devices. Buffers 1,3,...,15, four bits
 * each.
 */
/* word RRB_ODD_REG: 64 bits */
#define PIC_RRB_ODD_REG_WIDTH                        64 /* established */
#define PIC_RRB_ODD_REG_BUFF_15_EN_SHIFT             31 /* established */
#define PIC_RRB_ODD_REG_BUFF_15_EN_MASK              0x1ull
#define PIC_RRB_ODD_REG_BUFF_15_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_15_EN_MASK << PIC_RRB_ODD_REG_BUFF_15_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_15_VDEV_SHIFT           29 /* established */
#define PIC_RRB_ODD_REG_BUFF_15_VDEV_MASK            0x3ull
#define PIC_RRB_ODD_REG_BUFF_15_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_15_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_15_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_15_PDEV_SHIFT           28 /* established */
#define PIC_RRB_ODD_REG_BUFF_15_PDEV_MASK            0x1ull
#define PIC_RRB_ODD_REG_BUFF_15_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_15_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_15_PDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_13_EN_SHIFT             27 /* established */
#define PIC_RRB_ODD_REG_BUFF_13_EN_MASK              0x1ull
#define PIC_RRB_ODD_REG_BUFF_13_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_13_EN_MASK << PIC_RRB_ODD_REG_BUFF_13_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_13_VDEV_SHIFT           25 /* established */
#define PIC_RRB_ODD_REG_BUFF_13_VDEV_MASK            0x3ull
#define PIC_RRB_ODD_REG_BUFF_13_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_13_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_13_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_13_PDEV_SHIFT           24 /* established */
#define PIC_RRB_ODD_REG_BUFF_13_PDEV_MASK            0x1ull
#define PIC_RRB_ODD_REG_BUFF_13_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_13_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_13_PDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_11_EN_SHIFT             23 /* established */
#define PIC_RRB_ODD_REG_BUFF_11_EN_MASK              0x1ull
#define PIC_RRB_ODD_REG_BUFF_11_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_11_EN_MASK << PIC_RRB_ODD_REG_BUFF_11_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_11_VDEV_SHIFT           21 /* established */
#define PIC_RRB_ODD_REG_BUFF_11_VDEV_MASK            0x3ull
#define PIC_RRB_ODD_REG_BUFF_11_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_11_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_11_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_11_PDEV_SHIFT           20 /* established */
#define PIC_RRB_ODD_REG_BUFF_11_PDEV_MASK            0x1ull
#define PIC_RRB_ODD_REG_BUFF_11_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_11_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_11_PDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_9_EN_SHIFT              19 /* established */
#define PIC_RRB_ODD_REG_BUFF_9_EN_MASK               0x1ull
#define PIC_RRB_ODD_REG_BUFF_9_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_9_EN_MASK << PIC_RRB_ODD_REG_BUFF_9_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_9_VDEV_SHIFT            17 /* established */
#define PIC_RRB_ODD_REG_BUFF_9_VDEV_MASK             0x3ull
#define PIC_RRB_ODD_REG_BUFF_9_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_9_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_9_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_9_PDEV_SHIFT            16 /* established */
#define PIC_RRB_ODD_REG_BUFF_9_PDEV_MASK             0x1ull
#define PIC_RRB_ODD_REG_BUFF_9_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_9_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_9_PDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_7_EN_SHIFT              15 /* established */
#define PIC_RRB_ODD_REG_BUFF_7_EN_MASK               0x1ull
#define PIC_RRB_ODD_REG_BUFF_7_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_7_EN_MASK << PIC_RRB_ODD_REG_BUFF_7_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_7_VDEV_SHIFT            13 /* established */
#define PIC_RRB_ODD_REG_BUFF_7_VDEV_MASK             0x3ull
#define PIC_RRB_ODD_REG_BUFF_7_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_7_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_7_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_7_PDEV_SHIFT            12 /* established */
#define PIC_RRB_ODD_REG_BUFF_7_PDEV_MASK             0x1ull
#define PIC_RRB_ODD_REG_BUFF_7_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_7_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_7_PDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_5_EN_SHIFT              11 /* established */
#define PIC_RRB_ODD_REG_BUFF_5_EN_MASK               0x1ull
#define PIC_RRB_ODD_REG_BUFF_5_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_5_EN_MASK << PIC_RRB_ODD_REG_BUFF_5_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_5_VDEV_SHIFT            9 /* established */
#define PIC_RRB_ODD_REG_BUFF_5_VDEV_MASK             0x3ull
#define PIC_RRB_ODD_REG_BUFF_5_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_5_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_5_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_5_PDEV_SHIFT            8 /* established */
#define PIC_RRB_ODD_REG_BUFF_5_PDEV_MASK             0x1ull
#define PIC_RRB_ODD_REG_BUFF_5_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_5_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_5_PDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_3_EN_SHIFT              7 /* established */
#define PIC_RRB_ODD_REG_BUFF_3_EN_MASK               0x1ull
#define PIC_RRB_ODD_REG_BUFF_3_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_3_EN_MASK << PIC_RRB_ODD_REG_BUFF_3_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_3_VDEV_SHIFT            5 /* established */
#define PIC_RRB_ODD_REG_BUFF_3_VDEV_MASK             0x3ull
#define PIC_RRB_ODD_REG_BUFF_3_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_3_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_3_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_3_PDEV_SHIFT            4 /* established */
#define PIC_RRB_ODD_REG_BUFF_3_PDEV_MASK             0x1ull
#define PIC_RRB_ODD_REG_BUFF_3_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_3_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_3_PDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_1_EN_SHIFT              3 /* established */
#define PIC_RRB_ODD_REG_BUFF_1_EN_MASK               0x1ull
#define PIC_RRB_ODD_REG_BUFF_1_EN_INPLACE (PIC_RRB_ODD_REG_BUFF_1_EN_MASK << PIC_RRB_ODD_REG_BUFF_1_EN_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_1_VDEV_SHIFT            1 /* established */
#define PIC_RRB_ODD_REG_BUFF_1_VDEV_MASK             0x3ull
#define PIC_RRB_ODD_REG_BUFF_1_VDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_1_VDEV_MASK << PIC_RRB_ODD_REG_BUFF_1_VDEV_SHIFT)
#define PIC_RRB_ODD_REG_BUFF_1_PDEV_SHIFT            0 /* established */
#define PIC_RRB_ODD_REG_BUFF_1_PDEV_MASK             0x1ull
#define PIC_RRB_ODD_REG_BUFF_1_PDEV_INPLACE (PIC_RRB_ODD_REG_BUFF_1_PDEV_MASK << PIC_RRB_ODD_REG_BUFF_1_PDEV_SHIFT)

/*
 * Widget status. Bus-side status. Bits 35:33 carry the PCI-X mode report; the
 * low byte is the live level of the miscellaneous PCI inputs.
 */
/* word STATUS_REG: 64 bits */
#define PIC_STATUS_REG_WIDTH                         64 /* established */
#define PIC_STATUS_REG_PCI_X_SPEED_SHIFT             34 /* established */
#define PIC_STATUS_REG_PCI_X_SPEED_MASK              0x3ull
#define PIC_STATUS_REG_PCI_X_SPEED_INPLACE (PIC_STATUS_REG_PCI_X_SPEED_MASK << PIC_STATUS_REG_PCI_X_SPEED_SHIFT)
#define PIC_STATUS_REG_PCI_X_ACTIVE_SHIFT            33 /* established */
#define PIC_STATUS_REG_PCI_X_ACTIVE_MASK             0x1ull
#define PIC_STATUS_REG_PCI_X_ACTIVE_INPLACE (PIC_STATUS_REG_PCI_X_ACTIVE_MASK << PIC_STATUS_REG_PCI_X_ACTIVE_SHIFT)
#define PIC_STATUS_REG_LLP_REC_CNT_SHIFT             24 /* established */
#define PIC_STATUS_REG_LLP_REC_CNT_MASK              0xffull
#define PIC_STATUS_REG_LLP_REC_CNT_INPLACE (PIC_STATUS_REG_LLP_REC_CNT_MASK << PIC_STATUS_REG_LLP_REC_CNT_SHIFT)
#define PIC_STATUS_REG_LLP_TX_CNT_SHIFT              16 /* established */
#define PIC_STATUS_REG_LLP_TX_CNT_MASK               0xffull
#define PIC_STATUS_REG_LLP_TX_CNT_INPLACE (PIC_STATUS_REG_LLP_TX_CNT_MASK << PIC_STATUS_REG_LLP_TX_CNT_SHIFT)
#define PIC_STATUS_REG_RX_CREDIT_CNT_SHIFT           12 /* established */
#define PIC_STATUS_REG_RX_CREDIT_CNT_MASK            0xfull
#define PIC_STATUS_REG_RX_CREDIT_CNT_INPLACE (PIC_STATUS_REG_RX_CREDIT_CNT_MASK << PIC_STATUS_REG_RX_CREDIT_CNT_SHIFT)
#define PIC_STATUS_REG_TX_CREDIT_CNT_SHIFT           8 /* established */
#define PIC_STATUS_REG_TX_CREDIT_CNT_MASK            0xfull
#define PIC_STATUS_REG_TX_CREDIT_CNT_INPLACE (PIC_STATUS_REG_TX_CREDIT_CNT_MASK << PIC_STATUS_REG_TX_CREDIT_CNT_SHIFT)
#define PIC_STATUS_REG_PCI_MISC_INPUT_SHIFT          0 /* established */
#define PIC_STATUS_REG_PCI_MISC_INPUT_MASK           0xffull
#define PIC_STATUS_REG_PCI_MISC_INPUT_INPLACE (PIC_STATUS_REG_PCI_MISC_INPUT_MASK << PIC_STATUS_REG_PCI_MISC_INPUT_SHIFT)

/*
 * Test pin control: selects output function and value for the test pins.
 * Diagnostic only.
 */
/* word TEST_PIN_CTRL_REG: 64 bits */
#define PIC_TEST_PIN_CTRL_REG_WIDTH                  64 /* established */
#define PIC_TEST_PIN_CTRL_REG_TDATA_OUT_SHIFT        16 /* established */
#define PIC_TEST_PIN_CTRL_REG_TDATA_OUT_MASK         0xffull
#define PIC_TEST_PIN_CTRL_REG_TDATA_OUT_INPLACE (PIC_TEST_PIN_CTRL_REG_TDATA_OUT_MASK << PIC_TEST_PIN_CTRL_REG_TDATA_OUT_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_7_SHIFT       14 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_7_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_7_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_7_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_7_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_6_SHIFT       12 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_6_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_6_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_6_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_6_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_5_SHIFT       10 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_5_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_5_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_5_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_5_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_4_SHIFT       8 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_4_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_4_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_4_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_4_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_3_SHIFT       6 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_3_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_3_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_3_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_3_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_2_SHIFT       4 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_2_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_2_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_2_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_2_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_1_SHIFT       2 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_1_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_1_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_1_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_1_SHIFT)
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_0_SHIFT       0 /* established */
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_0_MASK        0x3ull
#define PIC_TEST_PIN_CTRL_REG_SEL_TPIN_0_INPLACE (PIC_TEST_PIN_CTRL_REG_SEL_TPIN_0_MASK << PIC_TEST_PIN_CTRL_REG_SEL_TPIN_0_SHIFT)

/*
 * Type-1 configuration address bits: supplies the secondary bus and device
 * number of a type-1 configuration cycle.
 */
/* word TYPE1_CFG_REG: 64 bits */
#define PIC_TYPE1_CFG_REG_WIDTH                      64 /* established */
#define PIC_TYPE1_CFG_REG_BUS_NUM_SHIFT              16 /* established */
#define PIC_TYPE1_CFG_REG_BUS_NUM_MASK               0xffull
#define PIC_TYPE1_CFG_REG_BUS_NUM_INPLACE (PIC_TYPE1_CFG_REG_BUS_NUM_MASK << PIC_TYPE1_CFG_REG_BUS_NUM_SHIFT)
#define PIC_TYPE1_CFG_REG_DEV_NUM_SHIFT              11 /* established */
#define PIC_TYPE1_CFG_REG_DEV_NUM_MASK               0x1full
#define PIC_TYPE1_CFG_REG_DEV_NUM_INPLACE (PIC_TYPE1_CFG_REG_DEV_NUM_MASK << PIC_TYPE1_CFG_REG_DEV_NUM_SHIFT)

#define PIC_ATE_ADDR_SHIFT                           0xcu /* established */
#define PIC_ATE_BARRIER                              0x10u /* established */
#define PIC_ATE_COHERENT                             0x2u /* established */
#define PIC_ATE_ENTRIES                              0x400u /* established */
#define PIC_ATE_MSI                                  0x4u /* established */
#define PIC_ATE_PREFETCH                             0x8u /* established */
#define PIC_ATE_TARGET_SHIFT                         0x8u /* established */
#define PIC_ATE_VALID                                0x1u /* established */
#define PIC_CFG_TYPE0_BASE                           0x20000u /* established */
#define PIC_CFG_TYPE1_BASE                           0x28000u /* established */
#define PIC_CONTROL_PAGE_SIZE_16K                    0x200000u /* established */
#define PIC_DEVICE_SWAP_DIRECT                       0x80000u /* inferred */
/* established */
#define PIC_DIRECT32_WINDOW_SIZE                     0x80000000u
/* established */
#define PIC_DIRECT64_ATTR_BARRIER                    0x100000000000000ull
/* established */
#define PIC_DIRECT64_ATTR_PRECISE                    0x400000000000000ull
/* established */
#define PIC_DIRECT64_ATTR_PREFETCH                   0x800000000000000ull
/* established */
#define PIC_DIRECT64_ATTR_SWAP                       0x80000000000000ull
#define PIC_DIRECT64_ATTR_TARGET_SHIFT               0x3cu /* established */
/* established */
#define PIC_DIRECT64_ATTR_VIRTUAL                    0x200000000000000ull
/* established */
#define PIC_DIRECT64_ATTR_VIRTUAL1                   0x40000000000000ull
#define PIC_DIR_MAP_OFFSET_SHIFT                     0x1fu /* established */
/* established */
#define PIC_HOST_INTR_ADDR_MASK                      0xffffffffffffull
#define PIC_INTR_FLUSH_WAIT_VALUE                    0x10fu /* established */
/* established */
#define PIC_INTR_PCIX_MASTER_TIMEOUT                 0x400000000ull
#define PIC_INTR_PCI_MASTER_TIMEOUT                  0x800u /* established */
#define PIC_INTR_RESET_MULTIPLE_CLEAR                0x40u /* established */
/* established */
#define PIC_PCI32_DIRECT_BASE                        0x80000000u
/* established */
#define PIC_PCI32_MAPPED_BASE                        0x40000000u
/* established */
#define PIC_PCI32_MAPPED_SWAP                        0x20000000u
#define PIC_PCIX_SPECIAL_CYCLE_BASE                  0x40000u /* established */
#define PIC_PCI_IACK_BASE                            0x30000u /* established */
#define PIC_TNUM_INTR_PIN_BASE                       0x18u /* inferred */
#define PIC_TNUM_PCI_WRITE_BASE                      0x10u /* inferred */
#define PIC_TNUM_READ_MAX                            0xfu /* inferred */

#endif /* PIC_GEN_H */
