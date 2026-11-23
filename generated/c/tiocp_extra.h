/* generated from devices/tiocp/registers-extra.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 11f87d67648250748efa0557e3091fcd29937fc879c35edb7bda8e7a07b6c989 */
/* TIOCP registers and constants outside the census */
#ifndef TIOCP_GEN_H
#define TIOCP_GEN_H

#include <stdint.h>


/*
 * Widget status (`cp_stat`), second word of the standard widget block. Offset,
 * width and name are the header definition. Access direction is not stated; no
 * code read reaches it, so its behaviour is unknown.
 */
/* stat: rw64, reset unknown */
#define TIOCP_STAT                                   0x000008 /* established */

/*
 * Widget error address, upper word (`cp_err_upper`); the lower word is the
 * census register `bus_err`. Offset, width and name are the header definition.
 * Access direction is not stated; no code read reaches it, so its behaviour is
 * unknown.
 */
/* err_upper: rw64, reset unknown */
#define TIOCP_ERR_UPPER                              0x000010 /* established */

/*
 * Widget interrupt destination, upper word (`cp_intr_upper`); the lower word is
 * the census register `intr_dst_target_id`. Offset, width and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* intr_upper: rw64, reset unknown */
#define TIOCP_INTR_UPPER                             0x000030 /* established */

/*
 * Test pin control (`cp_tst_pin_ctrl`). Offset, width and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* tst_pin_ctrl: rw64, reset unknown */
#define TIOCP_TST_PIN_CTRL                           0x000070 /* established */

/*
 * PCI error address, upper word (`cp_pci_err_upper`); the lower word is the
 * census register `pci_bus_addr`. Offset, width and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* pci_err_upper: rw64, reset unknown */
#define TIOCP_PCI_ERR_UPPER                          0x0000d0 /* established */

/*
 * Buffer address match registers: sixteen pairs, upper word then lower word.
 * Offset, width and name are the header definition. Access direction is not
 * stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_addr_match_upper: rw64, reset unknown */
#define TIOCP_BUF_ADDR_MATCH_UPPER                   0x000300 /* established */
#define TIOCP_BUF_ADDR_MATCH_UPPER_COUNT             16
#define TIOCP_BUF_ADDR_MATCH_UPPER_STRIDE            16

/*
 * Buffer address match, lower words (second word of each pair). Offset, width
 * and name are the header definition. Access direction is not stated; no code
 * read reaches it, so its behaviour is unknown.
 */
/* buf_addr_match_lower: rw64, reset unknown */
#define TIOCP_BUF_ADDR_MATCH_LOWER                   0x000308 /* established */
#define TIOCP_BUF_ADDR_MATCH_LOWER_COUNT             16
#define TIOCP_BUF_ADDR_MATCH_LOWER_STRIDE            16

/*
 * Performance monitor word `flush_w_touch` of block n; eight blocks, 0x40 bytes
 * apart. Offset, width and name are the header definition. Access direction is
 * not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_flush_w_touch: rw64, reset unknown */
#define TIOCP_BUF_COUNT_FLUSH_W_TOUCH                0x000400 /* established */
#define TIOCP_BUF_COUNT_FLUSH_W_TOUCH_COUNT          8
#define TIOCP_BUF_COUNT_FLUSH_W_TOUCH_STRIDE         64

/*
 * Performance monitor word `flush_wo_touch` of block n; eight blocks, 0x40
 * bytes apart. Offset, width and name are the header definition. Access
 * direction is not stated; no code read reaches it, so its behaviour is
 * unknown.
 */
/* buf_count_flush_wo_touch: rw64, reset unknown */
#define TIOCP_BUF_COUNT_FLUSH_WO_TOUCH               0x000408 /* established */
#define TIOCP_BUF_COUNT_FLUSH_WO_TOUCH_COUNT         8
#define TIOCP_BUF_COUNT_FLUSH_WO_TOUCH_STRIDE        64

/*
 * Performance monitor word `inflight` of block n; eight blocks, 0x40 bytes
 * apart. Offset, width and name are the header definition. Access direction is
 * not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_inflight: rw64, reset unknown */
#define TIOCP_BUF_COUNT_INFLIGHT                     0x000410 /* established */
#define TIOCP_BUF_COUNT_INFLIGHT_COUNT               8
#define TIOCP_BUF_COUNT_INFLIGHT_STRIDE              64

/*
 * Performance monitor word `prefetch` of block n; eight blocks, 0x40 bytes
 * apart. Offset, width and name are the header definition. Access direction is
 * not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_prefetch: rw64, reset unknown */
#define TIOCP_BUF_COUNT_PREFETCH                     0x000418 /* established */
#define TIOCP_BUF_COUNT_PREFETCH_COUNT               8
#define TIOCP_BUF_COUNT_PREFETCH_STRIDE              64

/*
 * Performance monitor word `total_pci_retry` of block n; eight blocks, 0x40
 * bytes apart. Offset, width and name are the header definition. Access
 * direction is not stated; no code read reaches it, so its behaviour is
 * unknown.
 */
/* buf_count_total_pci_retry: rw64, reset unknown */
#define TIOCP_BUF_COUNT_TOTAL_PCI_RETRY              0x000420 /* established */
#define TIOCP_BUF_COUNT_TOTAL_PCI_RETRY_COUNT        8
#define TIOCP_BUF_COUNT_TOTAL_PCI_RETRY_STRIDE       64

/*
 * Performance monitor word `max_pci_retry` of block n; eight blocks, 0x40 bytes
 * apart. Offset, width and name are the header definition. Access direction is
 * not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_max_pci_retry: rw64, reset unknown */
#define TIOCP_BUF_COUNT_MAX_PCI_RETRY                0x000428 /* established */
#define TIOCP_BUF_COUNT_MAX_PCI_RETRY_COUNT          8
#define TIOCP_BUF_COUNT_MAX_PCI_RETRY_STRIDE         64

/*
 * Performance monitor word `max_latency` of block n; eight blocks, 0x40 bytes
 * apart. Offset, width and name are the header definition. Access direction is
 * not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_max_latency: rw64, reset unknown */
#define TIOCP_BUF_COUNT_MAX_LATENCY                  0x000430 /* established */
#define TIOCP_BUF_COUNT_MAX_LATENCY_COUNT            8
#define TIOCP_BUF_COUNT_MAX_LATENCY_STRIDE           64

/*
 * Performance monitor word `clear_all` of block n; eight blocks, 0x40 bytes
 * apart. Offset, width and name are the header definition. Access direction is
 * not stated; no code read reaches it, so its behaviour is unknown.
 */
/* buf_count_clear_all: rw64, reset unknown */
#define TIOCP_BUF_COUNT_CLEAR_ALL                    0x000438 /* established */
#define TIOCP_BUF_COUNT_CLEAR_ALL_COUNT              8
#define TIOCP_BUF_COUNT_CLEAR_ALL_STRIDE             64

/*
 * PCI-X timeout (`cp_pcix_timeout`), eighth word of the PCI-X block. Offset,
 * width and name are the header definition. Access direction is not stated; no
 * code read reaches it, so its behaviour is unknown.
 */
/* pcix_timeout: rw64, reset unknown */
#define TIOCP_PCIX_TIMEOUT                           0x000638 /* established */

/*
 * Coretalk debug control (`cp_ct_debug_ctl`). The debug registers exist on the
 * TIOCP only; the PIC leaves this range as padding. Offset, width and name are
 * the header definition. Access direction is not stated; no code read reaches
 * it, so its behaviour is unknown.
 */
/* ct_debug_ctl: rw64, reset unknown */
#define TIOCP_CT_DEBUG_CTL                           0x000700 /* established */

/*
 * Bridge debug control (`cp_br_debug_ctl`). Offset, width and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* br_debug_ctl: rw64, reset unknown */
#define TIOCP_BR_DEBUG_CTL                           0x000708 /* established */

/*
 * Debug mux control (`cp_mux3_debug_ctl`). Offset, width and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* mux3_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX3_DEBUG_CTL                         0x000710 /* established */

/*
 * Debug mux control (`cp_mux4_debug_ctl`). Offset, width and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* mux4_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX4_DEBUG_CTL                         0x000718 /* established */

/*
 * Debug mux control (`cp_mux5_debug_ctl`). Offset, width and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* mux5_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX5_DEBUG_CTL                         0x000720 /* established */

/*
 * Debug mux control (`cp_mux6_debug_ctl`). Offset, width and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* mux6_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX6_DEBUG_CTL                         0x000728 /* established */

/*
 * Debug mux control (`cp_mux7_debug_ctl`). Offset, width and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* mux7_debug_ctl: rw64, reset unknown */
#define TIOCP_MUX7_DEBUG_CTL                         0x000730 /* established */

/*
 * PCI-X read buffer n, address word. Offset, width and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* pcix_read_buf_64_cp_buf_addr: rw64, reset unknown */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ADDR           0x000a00 /* established */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ADDR_COUNT     16
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ADDR_STRIDE    16

/*
 * PCI-X read buffer n, attribute word. Offset, width and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* pcix_read_buf_64_cp_buf_attr: rw64, reset unknown */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ATTR           0x000a08 /* established */
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ATTR_COUNT     16
#define TIOCP_PCIX_READ_BUF_64_CP_BUF_ATTR_STRIDE    16

/*
 * PCI-X write buffer n, address word. Offset, width and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* pcix_write_buf_64_cp_buf_addr: rw64, reset unknown */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ADDR          0x000b00 /* established */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ADDR_COUNT    8
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ADDR_STRIDE   32

/*
 * PCI-X write buffer n, attribute word. Offset, width and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* pcix_write_buf_64_cp_buf_attr: rw64, reset unknown */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ATTR          0x000b08 /* established */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ATTR_COUNT    8
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_ATTR_STRIDE   32

/*
 * PCI-X write buffer n, valid word. Offset, width and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* pcix_write_buf_64_cp_buf_valid: rw64, reset unknown */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_VALID         0x000b10 /* established */
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_VALID_COUNT   8
#define TIOCP_PCIX_WRITE_BUF_64_CP_BUF_VALID_STRIDE  32

/*
 * Internal translation entries with manual parity generation
 * (`cp_int_ate_ram_mp`); the automatic-parity copy is the census register
 * `int_ate`. No IRIX routine reaches it. Offset and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* int_ate_mp: rw64, reset unknown */
#define TIOCP_INT_ATE_MP                             0x014000 /* established */
#define TIOCP_INT_ATE_MP_COUNT                       1024
#define TIOCP_INT_ATE_MP_STRIDE                      8

/*
 * Write request RAM, lower data bank (`cp_wr_req_lower`). Offset and name are
 * the header definition. Access direction is not stated; no code read reaches
 * it, so its behaviour is unknown.
 */
/* wr_req_lower: rw64, reset unknown */
#define TIOCP_WR_REQ_LOWER                           0x018000 /* established */
#define TIOCP_WR_REQ_LOWER_COUNT                     256
#define TIOCP_WR_REQ_LOWER_STRIDE                    8

/*
 * Write request RAM, upper data bank (`cp_wr_req_upper`). Offset and name are
 * the header definition. Access direction is not stated; no code read reaches
 * it, so its behaviour is unknown.
 */
/* wr_req_upper: rw64, reset unknown */
#define TIOCP_WR_REQ_UPPER                           0x018800 /* established */
#define TIOCP_WR_REQ_UPPER_COUNT                     256
#define TIOCP_WR_REQ_UPPER_STRIDE                    8

/*
 * Write request RAM, parity bank (`cp_wr_req_parity`). Offset and name are the
 * header definition. Access direction is not stated; no code read reaches it,
 * so its behaviour is unknown.
 */
/* wr_req_parity: rw64, reset unknown */
#define TIOCP_WR_REQ_PARITY                          0x019000 /* established */
#define TIOCP_WR_REQ_PARITY_COUNT                    256
#define TIOCP_WR_REQ_PARITY_STRIDE                   8

/*
 * Read response RAM, lower data bank (`cp_rd_resp_lower`). The PIC has no read
 * response RAM. Offset and name are the header definition. Access direction is
 * not stated; no code read reaches it, so its behaviour is unknown.
 */
/* rd_resp_lower: rw64, reset unknown */
#define TIOCP_RD_RESP_LOWER                          0x01c000 /* established */
#define TIOCP_RD_RESP_LOWER_COUNT                    512
#define TIOCP_RD_RESP_LOWER_STRIDE                   8

/*
 * Read response RAM, upper data bank. Offset and name are the header
 * definition. Access direction is not stated; no code read reaches it, so its
 * behaviour is unknown.
 */
/* rd_resp_upper: rw64, reset unknown */
#define TIOCP_RD_RESP_UPPER                          0x01d000 /* established */
#define TIOCP_RD_RESP_UPPER_COUNT                    512
#define TIOCP_RD_RESP_UPPER_STRIDE                   8

/*
 * Read response RAM, parity bank. Offset and name are the header definition.
 * Access direction is not stated; no code read reaches it, so its behaviour is
 * unknown.
 */
/* rd_resp_parity: rw64, reset unknown */
#define TIOCP_RD_RESP_PARITY                         0x01e000 /* established */
#define TIOCP_RD_RESP_PARITY_COUNT                   512
#define TIOCP_RD_RESP_PARITY_STRIDE                  8

/*
 * Low flag bits of an internal address translation entry, the 64-bit word the
 * provider stores at the translation RAM (the internal translation RAM). The
 * page address is the physical page number placed at bit 12
 * (PCI32_ATE_ADDR_SHFT is 12; the kernel ORs the page-aligned address in
 * directly). The top of the address field and any other bits are not defined by
 * the code (unknown). Bit 1 is a different property on the PIC (coherent).
 */
/* word ATE: 64 bits */
#define TIOCP_ATE_WIDTH                              64 /* established */
#define TIOCP_ATE_BAR_SHIFT                          4 /* established */
#define TIOCP_ATE_BAR_MASK                           0x1ull
#define TIOCP_ATE_BAR_INPLACE (TIOCP_ATE_BAR_MASK << TIOCP_ATE_BAR_SHIFT)
#define TIOCP_ATE_PREF_SHIFT                         3 /* established */
#define TIOCP_ATE_PREF_MASK                          0x1ull
#define TIOCP_ATE_PREF_INPLACE (TIOCP_ATE_PREF_MASK << TIOCP_ATE_PREF_SHIFT)
#define TIOCP_ATE_MSI_SHIFT                          2 /* established */
#define TIOCP_ATE_MSI_MASK                           0x1ull
#define TIOCP_ATE_MSI_INPLACE (TIOCP_ATE_MSI_MASK << TIOCP_ATE_MSI_SHIFT)
#define TIOCP_ATE_PIO_SHIFT                          1 /* established */
#define TIOCP_ATE_PIO_MASK                           0x1ull
#define TIOCP_ATE_PIO_INPLACE (TIOCP_ATE_PIO_MASK << TIOCP_ATE_PIO_SHIFT)
#define TIOCP_ATE_VALID_SHIFT                        0 /* established */
#define TIOCP_ATE_VALID_MASK                         0x1ull
#define TIOCP_ATE_VALID_INPLACE (TIOCP_ATE_VALID_MASK << TIOCP_ATE_VALID_SHIFT)

/*
 * The one bit of the control register (census register at 0x20, `cp_control`)
 * that the Linux provider sets by name; no other control field is defined by
 * code read for this page.
 */
/* word CONTROL_BITS: 64 bits */
#define TIOCP_CONTROL_BITS_WIDTH                     64 /* established */
#define TIOCP_CONTROL_BITS_PAGE_SIZE_SHIFT           21 /* established */
#define TIOCP_CONTROL_BITS_PAGE_SIZE_MASK            0x1ull
#define TIOCP_CONTROL_BITS_PAGE_SIZE_INPLACE (TIOCP_CONTROL_BITS_PAGE_SIZE_MASK << TIOCP_CONTROL_BITS_PAGE_SIZE_SHIFT)

/*
 * The one bit of a device register (`cp_device[n]`) the Linux provider tests.
 * It tests a copy the firmware supplied, not a read of the register.
 */
/* word DEVICE_BITS: 64 bits */
#define TIOCP_DEVICE_BITS_WIDTH                      64 /* established */
#define TIOCP_DEVICE_BITS_SWAP_DIR_SHIFT             19 /* established */
#define TIOCP_DEVICE_BITS_SWAP_DIR_MASK              0x1ull
#define TIOCP_DEVICE_BITS_SWAP_DIR_INPLACE (TIOCP_DEVICE_BITS_SWAP_DIR_MASK << TIOCP_DEVICE_BITS_SWAP_DIR_SHIFT)

/*
 * Widget identification word as the Linux code splits every Crosstalk-style
 * widget id: the same layout the PIC page records. The TIOCP's own part number
 * is not named by the v5.3 code (unknown here; the IRIX accessors accept two,
 * see the chip page). Bit 0 and the layout of the upper half of the 64-bit
 * register are not defined by the code.
 */
/* word ID: 32 bits */
#define TIOCP_ID_WIDTH                               32 /* established */
#define TIOCP_ID_REV_SHIFT                           28 /* established */
#define TIOCP_ID_REV_MASK                            0xfu
#define TIOCP_ID_REV_INPLACE (TIOCP_ID_REV_MASK << TIOCP_ID_REV_SHIFT)
#define TIOCP_ID_PART_SHIFT                          12 /* established */
#define TIOCP_ID_PART_MASK                           0xffffu
#define TIOCP_ID_PART_INPLACE (TIOCP_ID_PART_MASK << TIOCP_ID_PART_SHIFT)
#define TIOCP_ID_MFG_SHIFT                           1 /* established */
#define TIOCP_ID_MFG_MASK                            0x7ffu
#define TIOCP_ID_MFG_INPLACE (TIOCP_ID_MFG_MASK << TIOCP_ID_MFG_SHIFT)

/*
 * Per-pin interrupt address register (`cp_int_addr[n]`). The provider clears
 * the destination field, then ORs in the Crosstalk address the pin's interrupt
 * write goes to, masked to the field. Other bits are preserved and not defined
 * by the code.
 */
/* word INT_ADDR: 64 bits */
#define TIOCP_INT_ADDR_WIDTH                         64 /* established */
#define TIOCP_INT_ADDR_ADDR_SHIFT                    0 /* established */
#define TIOCP_INT_ADDR_ADDR_MASK                     0x3fffffffffffffull
#define TIOCP_INT_ADDR_ADDR_INPLACE (TIOCP_INT_ADDR_ADDR_MASK << TIOCP_INT_ADDR_ADDR_SHIFT)

/*
 * Layout of the interrupt enable register: one bit per bridge interrupt pin
 * (the status register is likely to use the same pin bits, inferred; no code
 * read tests it), numbered as the pin's per-pin address register
 * (`cp_int_addr[n]`) and force register (`cp_force_pin[n]`). The provider sets
 * and clears bit n of the enable register with the pin number from the
 * firmware-supplied interrupt record. Upper bits (error interrupts) are not
 * named by the code (unknown).
 */
/* word INT_PIN_BITS: 64 bits */
#define TIOCP_INT_PIN_BITS_WIDTH                     64 /* established */
#define TIOCP_INT_PIN_BITS_PIN_SHIFT                 0 /* established */
#define TIOCP_INT_PIN_BITS_PIN_MASK                  0xffull
#define TIOCP_INT_PIN_BITS_PIN_INPLACE (TIOCP_INT_PIN_BITS_PIN_MASK << TIOCP_INT_PIN_BITS_PIN_SHIFT)

/*
 * A 32-bit bus address the provider hands out for a translation-entry mapping:
 * 0x40000000 plus the offset in the page plus the I/O page size times the entry
 * index, with bit 29 set when the device's endian swap is on. Addresses from
 * 0x80000000 are the 2 GiB direct window (PCI32_DIRECT_BASE) instead. The
 * kernel refuses the 2 GiB direct window in PCI-X mode on either chip and
 * refuses entry mappings in PCI-X mode on the PIC only, so the TIOCP maps
 * 32-bit addresses through entries there.
 */
/* word PCI32_MAPPED_ADDR: 32 bits */
#define TIOCP_PCI32_MAPPED_ADDR_WIDTH                32 /* established */
#define TIOCP_PCI32_MAPPED_ADDR_SWAP_SHIFT           29 /* established */
#define TIOCP_PCI32_MAPPED_ADDR_SWAP_MASK            0x1u
#define TIOCP_PCI32_MAPPED_ADDR_SWAP_INPLACE (TIOCP_PCI32_MAPPED_ADDR_SWAP_MASK << TIOCP_PCI32_MAPPED_ADDR_SWAP_SHIFT)

/*
 * The 64-bit direct DMA address a device is given: the DMA view of the memory
 * address with attribute bits ORed in. On the PIC bits 63:60 name the target
 * widget instead of the command type. Memory address width and the meaning of
 * bits 63:62 are not defined by the code (unknown).
 */
/* word PCI64_DMA_ADDR: 64 bits */
#define TIOCP_PCI64_DMA_ADDR_WIDTH                   64 /* established */
#define TIOCP_PCI64_DMA_ADDR_CMDTYPE_SHIFT           60 /* established */
#define TIOCP_PCI64_DMA_ADDR_CMDTYPE_MASK            0x3ull
#define TIOCP_PCI64_DMA_ADDR_CMDTYPE_INPLACE (TIOCP_PCI64_DMA_ADDR_CMDTYPE_MASK << TIOCP_PCI64_DMA_ADDR_CMDTYPE_SHIFT)
#define TIOCP_PCI64_DMA_ADDR_PREF_SHIFT              59 /* established */
#define TIOCP_PCI64_DMA_ADDR_PREF_MASK               0x1ull
#define TIOCP_PCI64_DMA_ADDR_PREF_INPLACE (TIOCP_PCI64_DMA_ADDR_PREF_MASK << TIOCP_PCI64_DMA_ADDR_PREF_SHIFT)
#define TIOCP_PCI64_DMA_ADDR_PREC_SHIFT              58 /* established */
#define TIOCP_PCI64_DMA_ADDR_PREC_MASK               0x1ull
#define TIOCP_PCI64_DMA_ADDR_PREC_INPLACE (TIOCP_PCI64_DMA_ADDR_PREC_MASK << TIOCP_PCI64_DMA_ADDR_PREC_SHIFT)
#define TIOCP_PCI64_DMA_ADDR_VIRTUAL_SHIFT           57 /* established */
#define TIOCP_PCI64_DMA_ADDR_VIRTUAL_MASK            0x1ull
#define TIOCP_PCI64_DMA_ADDR_VIRTUAL_INPLACE (TIOCP_PCI64_DMA_ADDR_VIRTUAL_MASK << TIOCP_PCI64_DMA_ADDR_VIRTUAL_SHIFT)
#define TIOCP_PCI64_DMA_ADDR_BAR_SHIFT               56 /* established */
#define TIOCP_PCI64_DMA_ADDR_BAR_MASK                0x1ull
#define TIOCP_PCI64_DMA_ADDR_BAR_INPLACE (TIOCP_PCI64_DMA_ADDR_BAR_MASK << TIOCP_PCI64_DMA_ADDR_BAR_SHIFT)
#define TIOCP_PCI64_DMA_ADDR_SWAP_SHIFT              55 /* established */
#define TIOCP_PCI64_DMA_ADDR_SWAP_MASK               0x1ull
#define TIOCP_PCI64_DMA_ADDR_SWAP_INPLACE (TIOCP_PCI64_DMA_ADDR_SWAP_MASK << TIOCP_PCI64_DMA_ADDR_SWAP_SHIFT)
#define TIOCP_PCI64_DMA_ADDR_VIRTUAL1_SHIFT          54 /* established */
#define TIOCP_PCI64_DMA_ADDR_VIRTUAL1_MASK           0x1ull
#define TIOCP_PCI64_DMA_ADDR_VIRTUAL1_INPLACE (TIOCP_PCI64_DMA_ADDR_VIRTUAL1_MASK << TIOCP_PCI64_DMA_ADDR_VIRTUAL1_SHIFT)

#define TIOCP_ATE_MSI                                0x4u /* established */
#define TIOCP_ATE_PIO                                0x2u /* established */
#define TIOCP_CFG_TYPE0_BASE                         0x21000u /* established */
#define TIOCP_CFG_TYPE1_BASE                         0x28000u /* established */
#define TIOCP_DEVIO_BASE                             0x200000u /* established */
#define TIOCP_DEVIO_FLUSH_BASE                       0xa00000u /* established */
/* established */
#define TIOCP_HOST_INTR_ADDR_MASK                    0x3fffffffffffffull
/* established */
#define TIOCP_PCI64_CMDTYPE_MEM                      0x1000000000000000ull
/* established */
#define TIOCP_PCI64_CMDTYPE_MSI                      0x3000000000000000ull
#define TIOCP_PCIX_SPECIAL_CYCLE_BASE                0x40000u /* established */
#define TIOCP_PCI_IACK_BASE                          0x30000u /* established */
#define TIOCP_WAR_PV907516                           0x2u /* established */

#endif /* TIOCP_GEN_H */
