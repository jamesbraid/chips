/* generated from devices/dm2/registers.toml by defs-gen - do not edit, change the source */
/* DMediaPro DM2 (XT-DIGVID) XIO video board: widget window, XG block, FPGA load, GIF register file and word layouts */
#ifndef DM2_GEN_H
#define DM2_GEN_H

#include <stdint.h>


/* enum fpga_kind: Programming routine set an FPGA info record selects. */
#define DM2_FPGA_KIND_OTHERS_HANDSHAKED              0 /* established */
#define DM2_FPGA_KIND_GIF                            1 /* established */
#define DM2_FPGA_KIND_OTHERS_BLIND                   2 /* established */

/* enum vbob_pipe: Pipe byte of a VBOB message frame. */
#define DM2_VBOB_PIPE_OUTPUT                         0 /* established */
#define DM2_VBOB_PIPE_INPUT                          1 /* established */

/* enum xg_mapram_type: XG configuration word, map-RAM type code: the diagnostic indexes a three-string table with it. */
#define DM2_XG_MAPRAM_TYPE_K32X36                    0 /* established */
#define DM2_XG_MAPRAM_TYPE_K64X18                    1 /* established */
#define DM2_XG_MAPRAM_TYPE_K128X9                    2 /* established */
#define DM2_XG_MAPRAM_TYPE_INVALID                   3 /* established */

/*
 * Widget identification, read by the diagnostic only; the kernel never reads it. The field split is established; the readback value is unknown (the part and manufacturer the driver registers with are not read from this register).
 */
/* widget_id: r32, reset unknown; shipped diagnostic tables */
#define DM2_WIDGET_ID_OFFSET                         0x4u /* established */
#define DM2_WIDGET_ID_REVISION_SHIFT                 28 /* established */
#define DM2_WIDGET_ID_REVISION_MASK                  0xfu
#define DM2_WIDGET_ID_REVISION_INPLACE               (DM2_WIDGET_ID_REVISION_MASK << DM2_WIDGET_ID_REVISION_SHIFT)
#define DM2_WIDGET_ID_PART_SHIFT                     12 /* established */
#define DM2_WIDGET_ID_PART_MASK                      0xffffu
#define DM2_WIDGET_ID_PART_INPLACE                   (DM2_WIDGET_ID_PART_MASK << DM2_WIDGET_ID_PART_SHIFT)
#define DM2_WIDGET_ID_MANUFACTURER_SHIFT             1 /* established */
#define DM2_WIDGET_ID_MANUFACTURER_MASK              0x7ffu
#define DM2_WIDGET_ID_MANUFACTURER_INPLACE           (DM2_WIDGET_ID_MANUFACTURER_MASK << DM2_WIDGET_ID_MANUFACTURER_SHIFT)

/*
 * Widget status. The kernel reads it once at attach and tests bit 5 only: when set it prints that the XIO slot is the slower 400 MB/s kind. The test is established; what the bit encodes is unknown (the message says link speed).
 */
/* widget_status: r32, reset unknown; shipped kernel driver and media library readings */
#define DM2_WIDGET_STATUS_OFFSET                     0xcu /* established */
#define DM2_WIDGET_STATUS_LINK_SLOW_SHIFT            5 /* established */
#define DM2_WIDGET_STATUS_LINK_SLOW_MASK             0x1u
#define DM2_WIDGET_STATUS_LINK_SLOW_INPLACE          (DM2_WIDGET_STATUS_LINK_SLOW_MASK << DM2_WIDGET_STATUS_LINK_SLOW_SHIFT)

/*
 * Widget control (the diagnostic calls it the XG control register). The init routine stores widget id, interrupt target and a constant, then ORs the XG error interrupt enable; the error handler clears the enable first and nothing sets it again. The low nibble comes from the widget's own number and bits 25:22 from the target widget of the XG error interrupt object, both inferred from the helper names. The same target value is also stored in the interrupt destination upper word, bits 19:16. Because the map RAM entry carries no widget field and this is the only other place a target widget is stored, bits 25:22 are the inferred home of the target widget for the board's own DMA requests; nothing in the shipped software states it. Bits 14 and 9 are written as constants and are unexplained. The only routine that sets bit 17 is the XG init routine, which runs at attach and again from the board-reset ioctl; the error handler and the detach routine clear it.
 */
/* widget_control: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_WIDGET_CONTROL_OFFSET                    0x24u /* established */
#define DM2_WIDGET_CONTROL_INT_TARGET_SHIFT          22 /* inferred */
#define DM2_WIDGET_CONTROL_INT_TARGET_MASK           0xfu
#define DM2_WIDGET_CONTROL_INT_TARGET_INPLACE        (DM2_WIDGET_CONTROL_INT_TARGET_MASK << DM2_WIDGET_CONTROL_INT_TARGET_SHIFT)
#define DM2_WIDGET_CONTROL_XG_ERROR_INT_ENABLE_SHIFT 17 /* established */
#define DM2_WIDGET_CONTROL_XG_ERROR_INT_ENABLE_MASK  0x1u
#define DM2_WIDGET_CONTROL_XG_ERROR_INT_ENABLE_INPLACE (DM2_WIDGET_CONTROL_XG_ERROR_INT_ENABLE_MASK << DM2_WIDGET_CONTROL_XG_ERROR_INT_ENABLE_SHIFT)
#define DM2_WIDGET_CONTROL_CONST_BIT14_SHIFT         14 /* unknown */
#define DM2_WIDGET_CONTROL_CONST_BIT14_MASK          0x1u
#define DM2_WIDGET_CONTROL_CONST_BIT14_INPLACE       (DM2_WIDGET_CONTROL_CONST_BIT14_MASK << DM2_WIDGET_CONTROL_CONST_BIT14_SHIFT)
#define DM2_WIDGET_CONTROL_CONST_BIT9_SHIFT          9 /* unknown */
#define DM2_WIDGET_CONTROL_CONST_BIT9_MASK           0x1u
#define DM2_WIDGET_CONTROL_CONST_BIT9_INPLACE        (DM2_WIDGET_CONTROL_CONST_BIT9_MASK << DM2_WIDGET_CONTROL_CONST_BIT9_SHIFT)
#define DM2_WIDGET_CONTROL_WIDGET_NUMBER_SHIFT       0 /* inferred */
#define DM2_WIDGET_CONTROL_WIDGET_NUMBER_MASK        0xfu
#define DM2_WIDGET_CONTROL_WIDGET_NUMBER_INPLACE     (DM2_WIDGET_CONTROL_WIDGET_NUMBER_MASK << DM2_WIDGET_CONTROL_WIDGET_NUMBER_SHIFT)

/*
 * Request timeout, the odd word of common-block slot 0x28. The only access in the shipped software is a store of 0 in the routine the XG init routine calls just before it enables the error interrupt (after reading the error cause word, printing a message if it is non-zero, and before writing the cause word back). Never read. The store is established; the role (the common block's request timeout, here left disabled or at its minimum) is inferred from the slot's role in the common widget block.
 */
/* xg_req_timeout: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_XG_REQ_TIMEOUT_OFFSET                    0x2cu /* established */

/*
 * Interrupt destination, upper: address bits 47:32 in the low half and the target widget id above them, from the interrupt object the kernel allocated for the XG error interrupt. The driver asserts that the two video interrupt objects have the same address and target as the error interrupt, so one destination serves all three. Store established; field names inferred.
 */
/* int_dest_hi: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_INT_DEST_HI_OFFSET                       0x34u /* established */
#define DM2_INT_DEST_HI_TARGET_ID_SHIFT              16 /* inferred */
#define DM2_INT_DEST_HI_TARGET_ID_MASK               0xfu
#define DM2_INT_DEST_HI_TARGET_ID_INPLACE            (DM2_INT_DEST_HI_TARGET_ID_MASK << DM2_INT_DEST_HI_TARGET_ID_SHIFT)
#define DM2_INT_DEST_HI_ADDR_HI_SHIFT                0 /* inferred */
#define DM2_INT_DEST_HI_ADDR_HI_MASK                 0xffffu
#define DM2_INT_DEST_HI_ADDR_HI_INPLACE              (DM2_INT_DEST_HI_ADDR_HI_MASK << DM2_INT_DEST_HI_ADDR_HI_SHIFT)

/*
 * Interrupt destination, lower: the low 32 bits of the interrupt address.
 */
/* int_dest_lo: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_INT_DEST_LO_OFFSET                       0x3cu /* established */
#define DM2_INT_DEST_LO_ADDR_LO_SHIFT                0 /* established */
#define DM2_INT_DEST_LO_ADDR_LO_MASK                 0xffffffffu
#define DM2_INT_DEST_LO_ADDR_LO_INPLACE              (DM2_INT_DEST_LO_ADDR_LO_MASK << DM2_INT_DEST_LO_ADDR_LO_SHIFT)

/*
 * XG interrupt vectors. In the common widget block this slot is an error command word; in the XG it holds interrupt vectors, so the common role does not apply (established for the XG use, inferred that the divergence is deliberate; no read exists). Bits 17 and 8 are ORed in as constants and are inferred to be per-source enables, which one is which is unknown.
 */
/* xg_int_vectors: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_XG_INT_VECTORS_OFFSET                    0x5cu /* established */
#define DM2_XG_INT_VECTORS_ERROR_VECTOR_SHIFT        18 /* established */
#define DM2_XG_INT_VECTORS_ERROR_VECTOR_MASK         0xffu
#define DM2_XG_INT_VECTORS_ERROR_VECTOR_INPLACE      (DM2_XG_INT_VECTORS_ERROR_VECTOR_MASK << DM2_XG_INT_VECTORS_ERROR_VECTOR_SHIFT)
#define DM2_XG_INT_VECTORS_CONST_BIT17_SHIFT         17 /* inferred */
#define DM2_XG_INT_VECTORS_CONST_BIT17_MASK          0x1u
#define DM2_XG_INT_VECTORS_CONST_BIT17_INPLACE       (DM2_XG_INT_VECTORS_CONST_BIT17_MASK << DM2_XG_INT_VECTORS_CONST_BIT17_SHIFT)
#define DM2_XG_INT_VECTORS_GV1_VECTOR_SHIFT          9 /* established */
#define DM2_XG_INT_VECTORS_GV1_VECTOR_MASK           0xffu
#define DM2_XG_INT_VECTORS_GV1_VECTOR_INPLACE        (DM2_XG_INT_VECTORS_GV1_VECTOR_MASK << DM2_XG_INT_VECTORS_GV1_VECTOR_SHIFT)
#define DM2_XG_INT_VECTORS_CONST_BIT8_SHIFT          8 /* inferred */
#define DM2_XG_INT_VECTORS_CONST_BIT8_MASK           0x1u
#define DM2_XG_INT_VECTORS_CONST_BIT8_INPLACE        (DM2_XG_INT_VECTORS_CONST_BIT8_MASK << DM2_XG_INT_VECTORS_CONST_BIT8_SHIFT)
#define DM2_XG_INT_VECTORS_GV0_VECTOR_SHIFT          0 /* established */
#define DM2_XG_INT_VECTORS_GV0_VECTOR_MASK           0xffu
#define DM2_XG_INT_VECTORS_GV0_VECTOR_INPLACE        (DM2_XG_INT_VECTORS_GV0_VECTOR_MASK << DM2_XG_INT_VECTORS_GV0_VECTOR_SHIFT)

/*
 * XG configuration, read at attach and by the diagnostic; read-only from software. The subsystem field must read 1. The map-RAM size code is printed by the kernel as the code times 32 kilobytes; the table from size code to real size is unknown. The type code indexes a three-string table (order established).
 */
/* xg_config: r32, reset unknown; shipped kernel driver and media library readings */
#define DM2_XG_CONFIG_OFFSET                         0x64u /* established */
#define DM2_XG_CONFIG_MAPRAM_TYPE_SHIFT              6 /* established */
#define DM2_XG_CONFIG_MAPRAM_TYPE_MASK               0x3u
#define DM2_XG_CONFIG_MAPRAM_TYPE_INPLACE            (DM2_XG_CONFIG_MAPRAM_TYPE_MASK << DM2_XG_CONFIG_MAPRAM_TYPE_SHIFT)
#define DM2_XG_CONFIG_MAPRAM_SIZE_CODE_SHIFT         3 /* established */
#define DM2_XG_CONFIG_MAPRAM_SIZE_CODE_MASK          0x7u
#define DM2_XG_CONFIG_MAPRAM_SIZE_CODE_INPLACE       (DM2_XG_CONFIG_MAPRAM_SIZE_CODE_MASK << DM2_XG_CONFIG_MAPRAM_SIZE_CODE_SHIFT)
#define DM2_XG_CONFIG_SUBSYSTEM_SHIFT                0 /* established */
#define DM2_XG_CONFIG_SUBSYSTEM_MASK                 0x7u
#define DM2_XG_CONFIG_SUBSYSTEM_INPLACE              (DM2_XG_CONFIG_SUBSYSTEM_MASK << DM2_XG_CONFIG_SUBSYSTEM_SHIFT)

/*
 * XG error cause, one bit per error. The error handler reads it, writes the same value back before decoding, and prints one message per set bit. That the write-back is write-one-to-clear is inferred. Bit 22 is tested twice in the shipped handler and prints both a cache-line and a double-word underflow message; bit 24 is never tested. The intended assignment of bit 24 (graphics double-word credit underflow) is inferred; the diagnostic writes 0 here. Bit 31 has no test in the handler's shift sequence.
 */
/* xg_error_cause: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_XG_ERROR_CAUSE_OFFSET                    0x6cu /* established */
#define DM2_XG_ERROR_CAUSE_BIT31_UNTESTED_SHIFT      31 /* unknown */
#define DM2_XG_ERROR_CAUSE_BIT31_UNTESTED_MASK       0x1u
#define DM2_XG_ERROR_CAUSE_BIT31_UNTESTED_INPLACE    (DM2_XG_ERROR_CAUSE_BIT31_UNTESTED_MASK << DM2_XG_ERROR_CAUSE_BIT31_UNTESTED_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_WRITE_FULL_FIFO_SHIFT 30 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_WRITE_FULL_FIFO_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_WRITE_FULL_FIFO_INPLACE (DM2_XG_ERROR_CAUSE_XTALK_WRITE_FULL_FIFO_MASK << DM2_XG_ERROR_CAUSE_XTALK_WRITE_FULL_FIFO_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_WRITE_TOO_FEW_SHIFT 29 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_WRITE_TOO_FEW_MASK  0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_WRITE_TOO_FEW_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_WRITE_TOO_FEW_MASK << DM2_XG_ERROR_CAUSE_GUAVA_WRITE_TOO_FEW_SHIFT)
#define DM2_XG_ERROR_CAUSE_IDMA_RESP_INVALID_TAG_SHIFT 28 /* established */
#define DM2_XG_ERROR_CAUSE_IDMA_RESP_INVALID_TAG_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_IDMA_RESP_INVALID_TAG_INPLACE (DM2_XG_ERROR_CAUSE_IDMA_RESP_INVALID_TAG_MASK << DM2_XG_ERROR_CAUSE_IDMA_RESP_INVALID_TAG_SHIFT)
#define DM2_XG_ERROR_CAUSE_IDMA_RESP_SIZE_SHIFT      27 /* established */
#define DM2_XG_ERROR_CAUSE_IDMA_RESP_SIZE_MASK       0x1u
#define DM2_XG_ERROR_CAUSE_IDMA_RESP_SIZE_INPLACE    (DM2_XG_ERROR_CAUSE_IDMA_RESP_SIZE_MASK << DM2_XG_ERROR_CAUSE_IDMA_RESP_SIZE_SHIFT)
#define DM2_XG_ERROR_CAUSE_ODMA_FIFO_OVERFLOW_SHIFT  26 /* established */
#define DM2_XG_ERROR_CAUSE_ODMA_FIFO_OVERFLOW_MASK   0x1u
#define DM2_XG_ERROR_CAUSE_ODMA_FIFO_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_ODMA_FIFO_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_ODMA_FIFO_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_CMD_FIFO_OVERFLOW_SHIFT   25 /* established */
#define DM2_XG_ERROR_CAUSE_CMD_FIFO_OVERFLOW_MASK    0x1u
#define DM2_XG_ERROR_CAUSE_CMD_FIFO_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_CMD_FIFO_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_CMD_FIFO_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_UNDERFLOW_SHIFT 24 /* inferred */
#define DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_UNDERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_UNDERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_UNDERFLOW_MASK << DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_UNDERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_OVERFLOW_SHIFT 23 /* established */
#define DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_OVERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_GFX_DWORD_CREDIT_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_UNDERFLOW_SHIFT 22 /* established */
#define DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_UNDERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_UNDERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_UNDERFLOW_MASK << DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_UNDERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_OVERFLOW_SHIFT 21 /* established */
#define DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_OVERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_GFX_CACHELINE_CREDIT_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_UNDERFLOW_SHIFT 20 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_UNDERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_UNDERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_UNDERFLOW_MASK << DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_UNDERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_OVERFLOW_SHIFT 19 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_OVERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_XTALK_RESP_CREDIT_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_UNDERFLOW_SHIFT 18 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_UNDERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_UNDERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_UNDERFLOW_MASK << DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_UNDERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_OVERFLOW_SHIFT 17 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_OVERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_XTALK_REQ_CREDIT_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_PARITY_SHIFT    16 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_PARITY_MASK     0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_PARITY_INPLACE  (DM2_XG_ERROR_CAUSE_GUAVA_BUS_PARITY_MASK << DM2_XG_ERROR_CAUSE_GUAVA_BUS_PARITY_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_DATA_PARITY_SHIFT 15 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_DATA_PARITY_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_DATA_PARITY_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_BUS_DATA_PARITY_MASK << DM2_XG_ERROR_CAUSE_GUAVA_BUS_DATA_PARITY_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_CMD_PARITY_SHIFT 14 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_CMD_PARITY_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_BUS_CMD_PARITY_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_BUS_CMD_PARITY_MASK << DM2_XG_ERROR_CAUSE_GUAVA_BUS_CMD_PARITY_SHIFT)
#define DM2_XG_ERROR_CAUSE_MAPRAM_INVALID_SHIFT      13 /* established */
#define DM2_XG_ERROR_CAUSE_MAPRAM_INVALID_MASK       0x1u
#define DM2_XG_ERROR_CAUSE_MAPRAM_INVALID_INPLACE    (DM2_XG_ERROR_CAUSE_MAPRAM_INVALID_MASK << DM2_XG_ERROR_CAUSE_MAPRAM_INVALID_SHIFT)
#define DM2_XG_ERROR_CAUSE_MAPRAM_PARITY_SHIFT       12 /* established */
#define DM2_XG_ERROR_CAUSE_MAPRAM_PARITY_MASK        0x1u
#define DM2_XG_ERROR_CAUSE_MAPRAM_PARITY_INPLACE     (DM2_XG_ERROR_CAUSE_MAPRAM_PARITY_MASK << DM2_XG_ERROR_CAUSE_MAPRAM_PARITY_SHIFT)
#define DM2_XG_ERROR_CAUSE_GFX_FIFO_OVERFLOW_SHIFT   11 /* established */
#define DM2_XG_ERROR_CAUSE_GFX_FIFO_OVERFLOW_MASK    0x1u
#define DM2_XG_ERROR_CAUSE_GFX_FIFO_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_GFX_FIFO_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_GFX_FIFO_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_REQUEST_SHIFT       10 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_REQUEST_MASK        0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_REQUEST_INPLACE     (DM2_XG_ERROR_CAUSE_XTALK_REQUEST_MASK << DM2_XG_ERROR_CAUSE_XTALK_REQUEST_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_RESPONSE_SHIFT      9 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_RESPONSE_MASK       0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_RESPONSE_INPLACE    (DM2_XG_ERROR_CAUSE_XTALK_RESPONSE_MASK << DM2_XG_ERROR_CAUSE_XTALK_RESPONSE_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_READ_REQ_TIMEOUT_SHIFT 8 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_READ_REQ_TIMEOUT_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_READ_REQ_TIMEOUT_INPLACE (DM2_XG_ERROR_CAUSE_XTALK_READ_REQ_TIMEOUT_MASK << DM2_XG_ERROR_CAUSE_XTALK_READ_REQ_TIMEOUT_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_BAD_COMMAND_SHIFT   7 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_BAD_COMMAND_MASK    0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_BAD_COMMAND_INPLACE (DM2_XG_ERROR_CAUSE_XTALK_BAD_COMMAND_MASK << DM2_XG_ERROR_CAUSE_XTALK_BAD_COMMAND_SHIFT)
#define DM2_XG_ERROR_CAUSE_XTALK_ADDRESS_SHIFT       6 /* established */
#define DM2_XG_ERROR_CAUSE_XTALK_ADDRESS_MASK        0x1u
#define DM2_XG_ERROR_CAUSE_XTALK_ADDRESS_INPLACE     (DM2_XG_ERROR_CAUSE_XTALK_ADDRESS_MASK << DM2_XG_ERROR_CAUSE_XTALK_ADDRESS_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_BAD_INTERRUPT_SHIFT 5 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_BAD_INTERRUPT_MASK  0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_BAD_INTERRUPT_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_BAD_INTERRUPT_MASK << DM2_XG_ERROR_CAUSE_GUAVA_BAD_INTERRUPT_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_BAD_COMMAND_SHIFT   4 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_BAD_COMMAND_MASK    0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_BAD_COMMAND_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_BAD_COMMAND_MASK << DM2_XG_ERROR_CAUSE_GUAVA_BAD_COMMAND_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_VALID_WHEN_IDLE_SHIFT 3 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_VALID_WHEN_IDLE_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_VALID_WHEN_IDLE_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_VALID_WHEN_IDLE_MASK << DM2_XG_ERROR_CAUSE_GUAVA_VALID_WHEN_IDLE_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_PIO_CMD_RESP_OVERFLOW_SHIFT 2 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_PIO_CMD_RESP_OVERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_PIO_CMD_RESP_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_PIO_CMD_RESP_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_GUAVA_PIO_CMD_RESP_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_PIO_DATA_RESP_OVERFLOW_SHIFT 1 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_PIO_DATA_RESP_OVERFLOW_MASK 0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_PIO_DATA_RESP_OVERFLOW_INPLACE (DM2_XG_ERROR_CAUSE_GUAVA_PIO_DATA_RESP_OVERFLOW_MASK << DM2_XG_ERROR_CAUSE_GUAVA_PIO_DATA_RESP_OVERFLOW_SHIFT)
#define DM2_XG_ERROR_CAUSE_GUAVA_OVERLAP_SHIFT       0 /* established */
#define DM2_XG_ERROR_CAUSE_GUAVA_OVERLAP_MASK        0x1u
#define DM2_XG_ERROR_CAUSE_GUAVA_OVERLAP_INPLACE     (DM2_XG_ERROR_CAUSE_GUAVA_OVERLAP_MASK << DM2_XG_ERROR_CAUSE_GUAVA_OVERLAP_SHIFT)

/*
 * High/low water mark (the diagnostic's name). The init routine keeps the two 6-bit fields from the current value, forces bits 15:0 to a constant and bits 31:28 to 0. The diagnostic stores bits 27:0 as plain storage. What high and low mean (presumably graphics FIFO thresholds) is inferred. This is the XG register at window offset 0x74, not the pipe 0 per-pipe word whose window offset is 0x800074.
 */
/* xg_water_mark: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_XG_WATER_MARK_OFFSET                     0x74u /* established */
#define DM2_XG_WATER_MARK_FORCED_ZERO_SHIFT          28 /* established */
#define DM2_XG_WATER_MARK_FORCED_ZERO_MASK           0xfu
#define DM2_XG_WATER_MARK_FORCED_ZERO_INPLACE        (DM2_XG_WATER_MARK_FORCED_ZERO_MASK << DM2_XG_WATER_MARK_FORCED_ZERO_SHIFT)
#define DM2_XG_WATER_MARK_MARK_B_SHIFT               22 /* inferred */
#define DM2_XG_WATER_MARK_MARK_B_MASK                0x3fu
#define DM2_XG_WATER_MARK_MARK_B_INPLACE             (DM2_XG_WATER_MARK_MARK_B_MASK << DM2_XG_WATER_MARK_MARK_B_SHIFT)
#define DM2_XG_WATER_MARK_MARK_A_SHIFT               16 /* inferred */
#define DM2_XG_WATER_MARK_MARK_A_MASK                0x3fu
#define DM2_XG_WATER_MARK_MARK_A_INPLACE             (DM2_XG_WATER_MARK_MARK_A_MASK << DM2_XG_WATER_MARK_MARK_A_SHIFT)
#define DM2_XG_WATER_MARK_FIXED_LOW_SHIFT            0 /* established */
#define DM2_XG_WATER_MARK_FIXED_LOW_MASK             0xffffu
#define DM2_XG_WATER_MARK_FIXED_LOW_INPLACE          (DM2_XG_WATER_MARK_FIXED_LOW_MASK << DM2_XG_WATER_MARK_FIXED_LOW_SHIFT)

/*
 * Offending map-RAM entry address, read after a map-RAM parity or invalid error and printed as five hex digits. Read-only is inferred.
 */
/* xg_mapram_err_addr: r32, reset unknown; shipped kernel driver and media library readings */
#define DM2_XG_MAPRAM_ERR_ADDR_OFFSET                0x94u /* established */
#define DM2_XG_MAPRAM_ERR_ADDR_ENTRY_ADDR_SHIFT      0 /* established */
#define DM2_XG_MAPRAM_ERR_ADDR_ENTRY_ADDR_MASK       0xfffffu
#define DM2_XG_MAPRAM_ERR_ADDR_ENTRY_ADDR_INPLACE    (DM2_XG_MAPRAM_ERR_ADDR_ENTRY_ADDR_MASK << DM2_XG_MAPRAM_ERR_ADDR_ENTRY_ADDR_SHIFT)

/*
 * Board identity one-wire register, read through the shared one-wire accessor. The offset and accessor are established; the bit protocol is not in the driver object (unknown). The diagnostic stores bits 15:2 as plain storage; bits 1:0 are inferred to be the one-wire pulse and sample bits.
 */
/* xg_nic: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_XG_NIC_OFFSET                            0x9cu /* established */
#define DM2_XG_NIC_STORAGE_SHIFT                     2 /* established */
#define DM2_XG_NIC_STORAGE_MASK                      0x3fffu
#define DM2_XG_NIC_STORAGE_INPLACE                   (DM2_XG_NIC_STORAGE_MASK << DM2_XG_NIC_STORAGE_SHIFT)
#define DM2_XG_NIC_ONEWIRE_SHIFT                     0 /* inferred */
#define DM2_XG_NIC_ONEWIRE_MASK                      0x3u
#define DM2_XG_NIC_ONEWIRE_INPLACE                   (DM2_XG_NIC_ONEWIRE_MASK << DM2_XG_NIC_ONEWIRE_SHIFT)

/*
 * GIF FPGA programming and status register. Read layout (this register): DONE and INIT for each FPGA in adjacent bit pairs. The message calls the GIF INIT bit INIT_L, active low, so it reads 1 when the pin is not asserted. The pairs run in the order GIF, packer, unpacker, input colour converter, output colour converter, VIF, HDOC, CLINK, which is not the order of the library's FPGA numbers. Names are inferred. The write layout is the word FPGA_PROG_WRITE.
 */
/* fpga_prog: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_FPGA_PROG_OFFSET                         0x120000u /* established */
#define DM2_FPGA_PROG_CLINK_INIT_SHIFT               15 /* established */
#define DM2_FPGA_PROG_CLINK_INIT_MASK                0x1u
#define DM2_FPGA_PROG_CLINK_INIT_INPLACE             (DM2_FPGA_PROG_CLINK_INIT_MASK << DM2_FPGA_PROG_CLINK_INIT_SHIFT)
#define DM2_FPGA_PROG_CLINK_DONE_SHIFT               14 /* established */
#define DM2_FPGA_PROG_CLINK_DONE_MASK                0x1u
#define DM2_FPGA_PROG_CLINK_DONE_INPLACE             (DM2_FPGA_PROG_CLINK_DONE_MASK << DM2_FPGA_PROG_CLINK_DONE_SHIFT)
#define DM2_FPGA_PROG_HDOC_INIT_SHIFT                13 /* established */
#define DM2_FPGA_PROG_HDOC_INIT_MASK                 0x1u
#define DM2_FPGA_PROG_HDOC_INIT_INPLACE              (DM2_FPGA_PROG_HDOC_INIT_MASK << DM2_FPGA_PROG_HDOC_INIT_SHIFT)
#define DM2_FPGA_PROG_HDOC_DONE_SHIFT                12 /* established */
#define DM2_FPGA_PROG_HDOC_DONE_MASK                 0x1u
#define DM2_FPGA_PROG_HDOC_DONE_INPLACE              (DM2_FPGA_PROG_HDOC_DONE_MASK << DM2_FPGA_PROG_HDOC_DONE_SHIFT)
#define DM2_FPGA_PROG_VIF_INIT_SHIFT                 11 /* established */
#define DM2_FPGA_PROG_VIF_INIT_MASK                  0x1u
#define DM2_FPGA_PROG_VIF_INIT_INPLACE               (DM2_FPGA_PROG_VIF_INIT_MASK << DM2_FPGA_PROG_VIF_INIT_SHIFT)
#define DM2_FPGA_PROG_VIF_DONE_SHIFT                 10 /* established */
#define DM2_FPGA_PROG_VIF_DONE_MASK                  0x1u
#define DM2_FPGA_PROG_VIF_DONE_INPLACE               (DM2_FPGA_PROG_VIF_DONE_MASK << DM2_FPGA_PROG_VIF_DONE_SHIFT)
#define DM2_FPGA_PROG_OXCC_INIT_SHIFT                9 /* established */
#define DM2_FPGA_PROG_OXCC_INIT_MASK                 0x1u
#define DM2_FPGA_PROG_OXCC_INIT_INPLACE              (DM2_FPGA_PROG_OXCC_INIT_MASK << DM2_FPGA_PROG_OXCC_INIT_SHIFT)
#define DM2_FPGA_PROG_OXCC_DONE_SHIFT                8 /* established */
#define DM2_FPGA_PROG_OXCC_DONE_MASK                 0x1u
#define DM2_FPGA_PROG_OXCC_DONE_INPLACE              (DM2_FPGA_PROG_OXCC_DONE_MASK << DM2_FPGA_PROG_OXCC_DONE_SHIFT)
#define DM2_FPGA_PROG_IXCC_INIT_SHIFT                7 /* established */
#define DM2_FPGA_PROG_IXCC_INIT_MASK                 0x1u
#define DM2_FPGA_PROG_IXCC_INIT_INPLACE              (DM2_FPGA_PROG_IXCC_INIT_MASK << DM2_FPGA_PROG_IXCC_INIT_SHIFT)
#define DM2_FPGA_PROG_IXCC_DONE_SHIFT                6 /* established */
#define DM2_FPGA_PROG_IXCC_DONE_MASK                 0x1u
#define DM2_FPGA_PROG_IXCC_DONE_INPLACE              (DM2_FPGA_PROG_IXCC_DONE_MASK << DM2_FPGA_PROG_IXCC_DONE_SHIFT)
#define DM2_FPGA_PROG_UNPACKER_INIT_SHIFT            5 /* established */
#define DM2_FPGA_PROG_UNPACKER_INIT_MASK             0x1u
#define DM2_FPGA_PROG_UNPACKER_INIT_INPLACE          (DM2_FPGA_PROG_UNPACKER_INIT_MASK << DM2_FPGA_PROG_UNPACKER_INIT_SHIFT)
#define DM2_FPGA_PROG_UNPACKER_DONE_SHIFT            4 /* established */
#define DM2_FPGA_PROG_UNPACKER_DONE_MASK             0x1u
#define DM2_FPGA_PROG_UNPACKER_DONE_INPLACE          (DM2_FPGA_PROG_UNPACKER_DONE_MASK << DM2_FPGA_PROG_UNPACKER_DONE_SHIFT)
#define DM2_FPGA_PROG_PACKER_INIT_SHIFT              3 /* established */
#define DM2_FPGA_PROG_PACKER_INIT_MASK               0x1u
#define DM2_FPGA_PROG_PACKER_INIT_INPLACE            (DM2_FPGA_PROG_PACKER_INIT_MASK << DM2_FPGA_PROG_PACKER_INIT_SHIFT)
#define DM2_FPGA_PROG_PACKER_DONE_SHIFT              2 /* established */
#define DM2_FPGA_PROG_PACKER_DONE_MASK               0x1u
#define DM2_FPGA_PROG_PACKER_DONE_INPLACE            (DM2_FPGA_PROG_PACKER_DONE_MASK << DM2_FPGA_PROG_PACKER_DONE_SHIFT)
#define DM2_FPGA_PROG_GIF_INIT_SHIFT                 1 /* established */
#define DM2_FPGA_PROG_GIF_INIT_MASK                  0x1u
#define DM2_FPGA_PROG_GIF_INIT_INPLACE               (DM2_FPGA_PROG_GIF_INIT_MASK << DM2_FPGA_PROG_GIF_INIT_SHIFT)
#define DM2_FPGA_PROG_GIF_DONE_SHIFT                 0 /* established */
#define DM2_FPGA_PROG_GIF_DONE_MASK                  0x1u
#define DM2_FPGA_PROG_GIF_DONE_INPLACE               (DM2_FPGA_PROG_GIF_DONE_MASK << DM2_FPGA_PROG_GIF_DONE_SHIFT)

/*
 * GIF reset/enable word (register number 0x00). The init routine stores 0 when asked to reinitialise; the FPGA load path polls for a value of 0x80. The meaning of the bits is unknown.
 */
/* gif_reset: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_GIF_RESET_OFFSET                         0x800004u /* established */

/*
 * Per-FPGA programming control (register number 0x08), for the seven FPGAs behind the GIF. The select word is one-hot and bit 7 is a strobe level (idle high, pulsed low around each download); the code shows only the values and the pulse shape, so the names are inferred.
 */
/* gif_prog_control: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_GIF_PROG_CONTROL_OFFSET                  0x80000cu /* established */
#define DM2_GIF_PROG_CONTROL_PROG_STROBE_SHIFT       7 /* inferred */
#define DM2_GIF_PROG_CONTROL_PROG_STROBE_MASK        0x1u
#define DM2_GIF_PROG_CONTROL_PROG_STROBE_INPLACE     (DM2_GIF_PROG_CONTROL_PROG_STROBE_MASK << DM2_GIF_PROG_CONTROL_PROG_STROBE_SHIFT)
#define DM2_GIF_PROG_CONTROL_FPGA_SELECT_SHIFT       0 /* inferred */
#define DM2_GIF_PROG_CONTROL_FPGA_SELECT_MASK        0x7fu
#define DM2_GIF_PROG_CONTROL_FPGA_SELECT_INPLACE     (DM2_GIF_PROG_CONTROL_FPGA_SELECT_MASK << DM2_GIF_PROG_CONTROL_FPGA_SELECT_SHIFT)

/*
 * Per-pipe DMA control word, indexed by pipe (pipe 0 at register number 0x10, pipe 1 at 0x38). The driver keeps a shadow and rewrites the whole word. Bits 3:0 are per-slot valid latches and bit 4 is abort; both are ORed into the written value and never kept in the shadow (established from the driver's own assertion). Bit 16 is the pipe interrupt enable (inferred from trace names). Bits 12, 10 and 9 are set and cleared by the raster configuration; their roles are inferred. The valid bits are inferred to be write-one-to-set latches. The initial shadow is 0xea040 for pipe 0 and 0xa040 for pipe 1. The diagnostic stores bits 14:5 (and 20:17 on pipe 0). The diagnostic calls pipe 0 the IDMA engine and pipe 1 the ODMA engine; the contract pages assign pipe 0 to video out (HDOC side) and pipe 1 to video in (VIF side), which is inferred.
 */
/* pipe_dma_control: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE_DMA_CONTROL_OFFSET                  0x800014u /* established */
#define DM2_PIPE_DMA_CONTROL_COUNT                   2
#define DM2_PIPE_DMA_CONTROL_STRIDE                  40
#define DM2_PIPE_DMA_CONTROL_INT_ENABLE_SHIFT        16 /* inferred */
#define DM2_PIPE_DMA_CONTROL_INT_ENABLE_MASK         0x1u
#define DM2_PIPE_DMA_CONTROL_INT_ENABLE_INPLACE      (DM2_PIPE_DMA_CONTROL_INT_ENABLE_MASK << DM2_PIPE_DMA_CONTROL_INT_ENABLE_SHIFT)
#define DM2_PIPE_DMA_CONTROL_CFG_BIT12_SHIFT         12 /* inferred */
#define DM2_PIPE_DMA_CONTROL_CFG_BIT12_MASK          0x1u
#define DM2_PIPE_DMA_CONTROL_CFG_BIT12_INPLACE       (DM2_PIPE_DMA_CONTROL_CFG_BIT12_MASK << DM2_PIPE_DMA_CONTROL_CFG_BIT12_SHIFT)
#define DM2_PIPE_DMA_CONTROL_CFG_BIT10_SHIFT         10 /* inferred */
#define DM2_PIPE_DMA_CONTROL_CFG_BIT10_MASK          0x1u
#define DM2_PIPE_DMA_CONTROL_CFG_BIT10_INPLACE       (DM2_PIPE_DMA_CONTROL_CFG_BIT10_MASK << DM2_PIPE_DMA_CONTROL_CFG_BIT10_SHIFT)
#define DM2_PIPE_DMA_CONTROL_CFG_BIT9_SHIFT          9 /* inferred */
#define DM2_PIPE_DMA_CONTROL_CFG_BIT9_MASK           0x1u
#define DM2_PIPE_DMA_CONTROL_CFG_BIT9_INPLACE        (DM2_PIPE_DMA_CONTROL_CFG_BIT9_MASK << DM2_PIPE_DMA_CONTROL_CFG_BIT9_SHIFT)
#define DM2_PIPE_DMA_CONTROL_ABORT_SHIFT             4 /* established */
#define DM2_PIPE_DMA_CONTROL_ABORT_MASK              0x1u
#define DM2_PIPE_DMA_CONTROL_ABORT_INPLACE           (DM2_PIPE_DMA_CONTROL_ABORT_MASK << DM2_PIPE_DMA_CONTROL_ABORT_SHIFT)
#define DM2_PIPE_DMA_CONTROL_SLOT_VALID_SHIFT        0 /* established */
#define DM2_PIPE_DMA_CONTROL_SLOT_VALID_MASK         0xfu
#define DM2_PIPE_DMA_CONTROL_SLOT_VALID_INPLACE      (DM2_PIPE_DMA_CONTROL_SLOT_VALID_MASK << DM2_PIPE_DMA_CONTROL_SLOT_VALID_SHIFT)

/*
 * Per-pipe raster start address 1 (register numbers 0x18 and 0x40). The value must be below 16 MiB (the driver rejects larger ones). The diagnostic does not store the low 3 bits, so 8-byte alignment is inferred.
 */
/* pipe_start_addr1: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE_START_ADDR1_OFFSET                  0x80001cu /* established */
#define DM2_PIPE_START_ADDR1_COUNT                   2
#define DM2_PIPE_START_ADDR1_STRIDE                  40
#define DM2_PIPE_START_ADDR1_START_ADDR_SHIFT        0 /* established */
#define DM2_PIPE_START_ADDR1_START_ADDR_MASK         0xffffffu
#define DM2_PIPE_START_ADDR1_START_ADDR_INPLACE      (DM2_PIPE_START_ADDR1_START_ADDR_MASK << DM2_PIPE_START_ADDR1_START_ADDR_SHIFT)

/*
 * Per-pipe raster start address 2 (register numbers 0x20 and 0x48), same range test as start address 1. Alignment is inferred.
 */
/* pipe_start_addr2: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE_START_ADDR2_OFFSET                  0x800024u /* established */
#define DM2_PIPE_START_ADDR2_COUNT                   2
#define DM2_PIPE_START_ADDR2_STRIDE                  40
#define DM2_PIPE_START_ADDR2_START_ADDR_SHIFT        0 /* established */
#define DM2_PIPE_START_ADDR2_START_ADDR_MASK         0xffffffu
#define DM2_PIPE_START_ADDR2_START_ADDR_INPLACE      (DM2_PIPE_START_ADDR2_START_ADDR_MASK << DM2_PIPE_START_ADDR2_START_ADDR_SHIFT)

/*
 * Per-pipe video control (register numbers 0x28 and 0x50; the diagnostic's IDMA_OV and ODMA_IV). Formula and width are established, exactly the 26 bits the diagnostic stores; what the two counts and flags mean in the video path is unknown. Bits 11:0 come from a 16-bit field of the pipe record, bits 23:12 from a 12-bit argument of the raster configuration, bit 24 is set when one 16-bit pipe field is zero and bit 25 when another is nonzero.
 */
/* pipe_vid_control: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE_VID_CONTROL_OFFSET                  0x80002cu /* established */
#define DM2_PIPE_VID_CONTROL_COUNT                   2
#define DM2_PIPE_VID_CONTROL_STRIDE                  40
#define DM2_PIPE_VID_CONTROL_FLAG_NONZERO_SHIFT      25 /* established */
#define DM2_PIPE_VID_CONTROL_FLAG_NONZERO_MASK       0x1u
#define DM2_PIPE_VID_CONTROL_FLAG_NONZERO_INPLACE    (DM2_PIPE_VID_CONTROL_FLAG_NONZERO_MASK << DM2_PIPE_VID_CONTROL_FLAG_NONZERO_SHIFT)
#define DM2_PIPE_VID_CONTROL_FLAG_ZERO_SHIFT         24 /* established */
#define DM2_PIPE_VID_CONTROL_FLAG_ZERO_MASK          0x1u
#define DM2_PIPE_VID_CONTROL_FLAG_ZERO_INPLACE       (DM2_PIPE_VID_CONTROL_FLAG_ZERO_MASK << DM2_PIPE_VID_CONTROL_FLAG_ZERO_SHIFT)
#define DM2_PIPE_VID_CONTROL_COUNT_HI_SHIFT          12 /* established */
#define DM2_PIPE_VID_CONTROL_COUNT_HI_MASK           0xfffu
#define DM2_PIPE_VID_CONTROL_COUNT_HI_INPLACE        (DM2_PIPE_VID_CONTROL_COUNT_HI_MASK << DM2_PIPE_VID_CONTROL_COUNT_HI_SHIFT)
#define DM2_PIPE_VID_CONTROL_COUNT_LO_SHIFT          0 /* established */
#define DM2_PIPE_VID_CONTROL_COUNT_LO_MASK           0xfffu
#define DM2_PIPE_VID_CONTROL_COUNT_LO_INPLACE        (DM2_PIPE_VID_CONTROL_COUNT_LO_MASK << DM2_PIPE_VID_CONTROL_COUNT_LO_SHIFT)

/*
 * Per-pipe video control 2 (register numbers 0x30 and 0x58): the low 12 bits of an argument. Meaning unknown.
 */
/* pipe_vid_control2: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE_VID_CONTROL2_OFFSET                 0x800034u /* established */
#define DM2_PIPE_VID_CONTROL2_COUNT                  2
#define DM2_PIPE_VID_CONTROL2_STRIDE                 40
#define DM2_PIPE_VID_CONTROL2_VALUE_SHIFT            0 /* established */
#define DM2_PIPE_VID_CONTROL2_VALUE_MASK             0xfffu
#define DM2_PIPE_VID_CONTROL2_VALUE_INPLACE          (DM2_PIPE_VID_CONTROL2_VALUE_MASK << DM2_PIPE_VID_CONTROL2_VALUE_SHIFT)

/*
 * Pipe 1 per-pipe word (register number 0x60), stored 0 when the pipe's status buffer is set up and by the clink-timeout path. The stores and the pipe assignment (pipe 1 owns this offset, pipe 0 owns 0x800074) are established; that it resets the board's status-ring write index is inferred. The host never reads it.
 */
/* pipe1_ring_ptr_reset: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE1_RING_PTR_RESET_OFFSET              0x800064u /* inferred */

/*
 * Pipe 1 per-pipe word (register number 0x68), stored 0 at DMA start. Meaning unknown.
 */
/* pipe1_reset_word: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE1_RESET_WORD_OFFSET                  0x80006cu /* established */

/*
 * Pipe 0 per-pipe word (register number 0x70), stored 0 when the pipe's status buffer is set up and by the clink-timeout path. The stores and the pipe assignment (pipe 0 owns this offset, pipe 1 owns 0x800064) are established; that it resets the board's status-ring write index is inferred. The host never reads it. Not to be confused with the XG water-mark register at window offset 0x74.
 */
/* pipe0_ring_ptr_reset: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE0_RING_PTR_RESET_OFFSET              0x800074u /* inferred */

/*
 * Pipe 0 per-pipe word (register number 0x78), stored 0 at DMA start. Meaning unknown.
 */
/* pipe0_reset_word: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PIPE0_RESET_WORD_OFFSET                  0x80007cu /* established */

/*
 * GIF identification (register number 0x80). Read once, by the GIF initialisation routine, which runs only from the board-reset ioctl when its argument has bit 1 clear (the media library issues it after all eight FPGAs are loaded), not at attach; the routine first requires the board-alive flag and the GIF DONE bit in the programming register. The upper 24 bits must be the ASCII text GIF; the low byte is the GIF version, which the driver prints at debug level 3 or above. Any other value fails that ioctl with the message that the GIF version is invalid.
 */
/* gif_ident: r32, reset unknown; shipped kernel driver and media library readings */
#define DM2_GIF_IDENT_OFFSET                         0x800084u /* established */
#define DM2_GIF_IDENT_MAGIC_SHIFT                    8 /* established */
#define DM2_GIF_IDENT_MAGIC_MASK                     0xffffffu
#define DM2_GIF_IDENT_MAGIC_INPLACE                  (DM2_GIF_IDENT_MAGIC_MASK << DM2_GIF_IDENT_MAGIC_SHIFT)
#define DM2_GIF_IDENT_VERSION_SHIFT                  0 /* established */
#define DM2_GIF_IDENT_VERSION_MASK                   0xffu
#define DM2_GIF_IDENT_VERSION_INPLACE                (DM2_GIF_IDENT_VERSION_MASK << DM2_GIF_IDENT_VERSION_SHIFT)

/*
 * Register number 0x88, stored 0 by the UST initialisation just before the host UST is sampled. The store is established; that it is the board's own UST/MSC counter is inferred from the pattern and the driver's message.
 */
/* ust_msc_counter: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_UST_MSC_COUNTER_OFFSET                   0x80008cu /* inferred */

/*
 * Packer register number 0x800. The library's per-pipe init stores a constant (see PACK_INIT_R0800). Roles unknown.
 */
/* pack_r0800: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PACK_R0800_OFFSET                        0x800804u /* established */

/*
 * Packer register number 0x808. Init constant PACK_INIT_R0808. Roles unknown.
 */
/* pack_r0808: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PACK_R0808_OFFSET                        0x80080cu /* established */

/*
 * Packer register number 0x810. Init constant PACK_INIT_R0810. Roles unknown.
 */
/* pack_r0810: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PACK_R0810_OFFSET                        0x800814u /* established */

/*
 * Packer miscellaneous select (register number 0x820, the diagnostic's PACK_MISC_SEL). Name and storage mask (bits 2 and 0) are established; the library stores 1 during init. Role unknown.
 */
/* pack_misc_sel: rw32, reset unknown; shipped diagnostic tables */
#define DM2_PACK_MISC_SEL_OFFSET                     0x800824u /* established */
#define DM2_PACK_MISC_SEL_STORAGE_BIT2_SHIFT         2 /* established */
#define DM2_PACK_MISC_SEL_STORAGE_BIT2_MASK          0x1u
#define DM2_PACK_MISC_SEL_STORAGE_BIT2_INPLACE       (DM2_PACK_MISC_SEL_STORAGE_BIT2_MASK << DM2_PACK_MISC_SEL_STORAGE_BIT2_SHIFT)
#define DM2_PACK_MISC_SEL_STORAGE_BIT0_SHIFT         0 /* established */
#define DM2_PACK_MISC_SEL_STORAGE_BIT0_MASK          0x1u
#define DM2_PACK_MISC_SEL_STORAGE_BIT0_INPLACE       (DM2_PACK_MISC_SEL_STORAGE_BIT0_MASK << DM2_PACK_MISC_SEL_STORAGE_BIT0_SHIFT)

/*
 * Packer register number 0x840. Init value is 0x1000 for pipe 1 (PACK_INIT_R0840). Roles unknown.
 */
/* pack_r0840: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PACK_R0840_OFFSET                        0x800844u /* established */

/*
 * Packer register number 0x848. Init constant PACK_INIT_R0848. Roles unknown.
 */
/* pack_r0848: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PACK_R0848_OFFSET                        0x80084cu /* established */

/*
 * Packer register number 0x850. Init constant PACK_INIT_R0850. Roles unknown.
 */
/* pack_r0850: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_PACK_R0850_OFFSET                        0x800854u /* established */

/*
 * Unpacker register number 0x1000. Init constant UNPACK_INIT_R1000. Roles unknown.
 */
/* unpack_r1000: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_UNPACK_R1000_OFFSET                      0x801004u /* established */

/*
 * Unpacker register number 0x1008. Init constant UNPACK_INIT_R1008. Roles unknown.
 */
/* unpack_r1008: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_UNPACK_R1008_OFFSET                      0x80100cu /* established */

/*
 * Unpacker VERSION_SEL (register number 0x1010). Name only; the diagnostic's storage mask is 0, which means not tested rather than read-only. Role unknown.
 */
/* unpack_version_sel: rw32, reset unknown; shipped diagnostic tables */
#define DM2_UNPACK_VERSION_SEL_OFFSET                0x801014u /* established */

/*
 * Unpacker MISC_SEL (register number 0x1018). The library stores 0x0fffe0f9 with a flag shifted into bit 28 (UNPACK_INIT_MISC_BASE); the diagnostic's storage mask is bits 11:2 and 0. Bits of the library constant outside that mask are either not storage or not tested. Roles unknown.
 */
/* unpack_misc_sel: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_UNPACK_MISC_SEL_OFFSET                   0x80101cu /* established */
#define DM2_UNPACK_MISC_SEL_FLAG28_SHIFT             28 /* inferred */
#define DM2_UNPACK_MISC_SEL_FLAG28_MASK              0x1u
#define DM2_UNPACK_MISC_SEL_FLAG28_INPLACE           (DM2_UNPACK_MISC_SEL_FLAG28_MASK << DM2_UNPACK_MISC_SEL_FLAG28_SHIFT)
#define DM2_UNPACK_MISC_SEL_DIAG_STORAGE_HI_SHIFT    2 /* established */
#define DM2_UNPACK_MISC_SEL_DIAG_STORAGE_HI_MASK     0x3ffu
#define DM2_UNPACK_MISC_SEL_DIAG_STORAGE_HI_INPLACE  (DM2_UNPACK_MISC_SEL_DIAG_STORAGE_HI_MASK << DM2_UNPACK_MISC_SEL_DIAG_STORAGE_HI_SHIFT)
#define DM2_UNPACK_MISC_SEL_DIAG_STORAGE_LO_SHIFT    0 /* established */
#define DM2_UNPACK_MISC_SEL_DIAG_STORAGE_LO_MASK     0x1u
#define DM2_UNPACK_MISC_SEL_DIAG_STORAGE_LO_INPLACE  (DM2_UNPACK_MISC_SEL_DIAG_STORAGE_LO_MASK << DM2_UNPACK_MISC_SEL_DIAG_STORAGE_LO_SHIFT)

/*
 * Unpacker IDMA_DATA0_SEL and IDMA_DATA1_SEL (register numbers 0x1020 and 0x1028). Names only; diagnostic mask 0. Roles unknown.
 */
/* unpack_idma_data_sel: rw32, reset unknown; shipped diagnostic tables */
#define DM2_UNPACK_IDMA_DATA_SEL_OFFSET              0x801024u /* established */
#define DM2_UNPACK_IDMA_DATA_SEL_COUNT               2
#define DM2_UNPACK_IDMA_DATA_SEL_STRIDE              8

/*
 * Unpacker OVFIFO_TEST_PATTERN0_SEL and OVFIFO_TEST_PATTERN1_SEL (register numbers 0x1030 and 0x1038). Names only; diagnostic mask 0. Roles unknown.
 */
/* unpack_ovfifo_test_pattern_sel: rw32, reset unknown; shipped diagnostic tables */
#define DM2_UNPACK_OVFIFO_TEST_PATTERN_SEL_OFFSET    0x801034u /* established */
#define DM2_UNPACK_OVFIFO_TEST_PATTERN_SEL_COUNT     2
#define DM2_UNPACK_OVFIFO_TEST_PATTERN_SEL_STRIDE    8

/*
 * Unpacker register number 0x1040. Init value is 0x1200 for pipe 0 (UNPACK_INIT_R1040). Roles unknown.
 */
/* unpack_r1040: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_UNPACK_R1040_OFFSET                      0x801044u /* established */

/*
 * Unpacker register number 0x1048. Init constant UNPACK_INIT_R1048. Roles unknown.
 */
/* unpack_r1048: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_UNPACK_R1048_OFFSET                      0x80104cu /* established */

/*
 * VIF control (register number 0x1800, the diagnostic's CONTROL_SEL). Formula and width (14 bits) are established, matching the diagnostic's storage mask; the meaning of any bit is unknown. Bit 0 is 0 on the path the library reads, bits 5:4 are one of two bits chosen by a standard-definition flag, bit 6 is that flag, bit 7 is 0 in the formula (the debug-build library pulses it high then low at the start of an input transfer, which is inferred to clear a sticky error flag in register 0x1810), bits 10:8 are always 7, bit 11 comes from a format-table word and bit 12 is a nonzero test.
 */
/* vif_control: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_VIF_CONTROL_OFFSET                       0x801804u /* established */
#define DM2_VIF_CONTROL_NONZERO_TEST_SHIFT           12 /* established */
#define DM2_VIF_CONTROL_NONZERO_TEST_MASK            0x1u
#define DM2_VIF_CONTROL_NONZERO_TEST_INPLACE         (DM2_VIF_CONTROL_NONZERO_TEST_MASK << DM2_VIF_CONTROL_NONZERO_TEST_SHIFT)
#define DM2_VIF_CONTROL_ROW_WORD1_SHIFT              11 /* established */
#define DM2_VIF_CONTROL_ROW_WORD1_MASK               0x1u
#define DM2_VIF_CONTROL_ROW_WORD1_INPLACE            (DM2_VIF_CONTROL_ROW_WORD1_MASK << DM2_VIF_CONTROL_ROW_WORD1_SHIFT)
#define DM2_VIF_CONTROL_CONST_7_SHIFT                8 /* established */
#define DM2_VIF_CONTROL_CONST_7_MASK                 0x7u
#define DM2_VIF_CONTROL_CONST_7_INPLACE              (DM2_VIF_CONTROL_CONST_7_MASK << DM2_VIF_CONTROL_CONST_7_SHIFT)
#define DM2_VIF_CONTROL_ERR_CLEAR_SHIFT              7 /* inferred */
#define DM2_VIF_CONTROL_ERR_CLEAR_MASK               0x1u
#define DM2_VIF_CONTROL_ERR_CLEAR_INPLACE            (DM2_VIF_CONTROL_ERR_CLEAR_MASK << DM2_VIF_CONTROL_ERR_CLEAR_SHIFT)
#define DM2_VIF_CONTROL_SD_FLAG_SHIFT                6 /* established */
#define DM2_VIF_CONTROL_SD_FLAG_MASK                 0x1u
#define DM2_VIF_CONTROL_SD_FLAG_INPLACE              (DM2_VIF_CONTROL_SD_FLAG_MASK << DM2_VIF_CONTROL_SD_FLAG_SHIFT)
#define DM2_VIF_CONTROL_MODE_SEL_SHIFT               4 /* established */
#define DM2_VIF_CONTROL_MODE_SEL_MASK                0x3u
#define DM2_VIF_CONTROL_MODE_SEL_INPLACE             (DM2_VIF_CONTROL_MODE_SEL_MASK << DM2_VIF_CONTROL_MODE_SEL_SHIFT)
#define DM2_VIF_CONTROL_BIT0_SHIFT                   0 /* established */
#define DM2_VIF_CONTROL_BIT0_MASK                    0x1u
#define DM2_VIF_CONTROL_BIT0_INPLACE                 (DM2_VIF_CONTROL_BIT0_MASK << DM2_VIF_CONTROL_BIT0_SHIFT)

/*
 * VIF enable (register number 0x1808, the diagnostic's ENABLE_SEL); the kernel stores the pipe's second shadow word here and abort clears bit 0. The store is established; that bit 0 is the enable is inferred. This is the in-pipe (pipe 1) video enable; the pairing is inferred from trace names.
 */
/* vif_enable: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_VIF_ENABLE_OFFSET                        0x80180cu /* established */
#define DM2_VIF_ENABLE_BIT1_SHIFT                    1 /* unknown */
#define DM2_VIF_ENABLE_BIT1_MASK                     0x1u
#define DM2_VIF_ENABLE_BIT1_INPLACE                  (DM2_VIF_ENABLE_BIT1_MASK << DM2_VIF_ENABLE_BIT1_SHIFT)
#define DM2_VIF_ENABLE_ENABLE_SHIFT                  0 /* inferred */
#define DM2_VIF_ENABLE_ENABLE_MASK                   0x1u
#define DM2_VIF_ENABLE_ENABLE_INPLACE                (DM2_VIF_ENABLE_ENABLE_MASK << DM2_VIF_ENABLE_ENABLE_SHIFT)

/*
 * Register number 0x1810. The diagnostic writes it between every write and read-back of the other VIF registers, a bus-hold or clearing write. The release library never touches it; the debug build of the library reads it at the start of an input transfer and tests bit 5, pulsing bit 7 of the VIF control (register number 0x1800) high then low when it is set, and reads it again 27 ms later. That bit 5 is a sticky input-error flag cleared by that pulse is inferred.
 */
/* vif_scratch: rw32, reset unknown; shipped diagnostic tables */
#define DM2_VIF_SCRATCH_OFFSET                       0x801814u /* inferred */
#define DM2_VIF_SCRATCH_ERR_FLAG_SHIFT               5 /* inferred */
#define DM2_VIF_SCRATCH_ERR_FLAG_MASK                0x1u
#define DM2_VIF_SCRATCH_ERR_FLAG_INPLACE             (DM2_VIF_SCRATCH_ERR_FLAG_MASK << DM2_VIF_SCRATCH_ERR_FLAG_SHIFT)

/*
 * VIF DMUX register (register number 0x1828, the diagnostic's DMUX_REG_SEL). Bits 2:0 are a small selector (0 on the path read), bits 4:3 a two-bit mode (2 or 3, from the format class), bit 5 is set when a path field equals 10 and bit 7 is set except in one special path case. Formula established; meaning unknown.
 */
/* vif_dmux: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_VIF_DMUX_OFFSET                          0x80182cu /* established */
#define DM2_VIF_DMUX_BIT7_SHIFT                      7 /* established */
#define DM2_VIF_DMUX_BIT7_MASK                       0x1u
#define DM2_VIF_DMUX_BIT7_INPLACE                    (DM2_VIF_DMUX_BIT7_MASK << DM2_VIF_DMUX_BIT7_SHIFT)
#define DM2_VIF_DMUX_PATH_IS_10_SHIFT                5 /* established */
#define DM2_VIF_DMUX_PATH_IS_10_MASK                 0x1u
#define DM2_VIF_DMUX_PATH_IS_10_INPLACE              (DM2_VIF_DMUX_PATH_IS_10_MASK << DM2_VIF_DMUX_PATH_IS_10_SHIFT)
#define DM2_VIF_DMUX_MODE_SHIFT                      3 /* established */
#define DM2_VIF_DMUX_MODE_MASK                       0x3u
#define DM2_VIF_DMUX_MODE_INPLACE                    (DM2_VIF_DMUX_MODE_MASK << DM2_VIF_DMUX_MODE_SHIFT)
#define DM2_VIF_DMUX_SELECTOR_SHIFT                  0 /* established */
#define DM2_VIF_DMUX_SELECTOR_MASK                   0x7u
#define DM2_VIF_DMUX_SELECTOR_INPLACE                (DM2_VIF_DMUX_SELECTOR_MASK << DM2_VIF_DMUX_SELECTOR_SHIFT)

/*
 * VIF field 0 active video (register number 0x1880): two 11-bit line numbers computed from the format row's line count and the path's start offsets. What each line is, is unknown.
 */
/* vif_f0_actvid: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_VIF_F0_ACTVID_OFFSET                     0x801884u /* established */
#define DM2_VIF_F0_ACTVID_LINE1_SHIFT                11 /* established */
#define DM2_VIF_F0_ACTVID_LINE1_MASK                 0x7ffu
#define DM2_VIF_F0_ACTVID_LINE1_INPLACE              (DM2_VIF_F0_ACTVID_LINE1_MASK << DM2_VIF_F0_ACTVID_LINE1_SHIFT)
#define DM2_VIF_F0_ACTVID_LINE0_SHIFT                0 /* established */
#define DM2_VIF_F0_ACTVID_LINE0_MASK                 0x7ffu
#define DM2_VIF_F0_ACTVID_LINE0_INPLACE              (DM2_VIF_F0_ACTVID_LINE0_MASK << DM2_VIF_F0_ACTVID_LINE0_SHIFT)

/*
 * VIF field 1 active video (register number 0x1888): same layout as field 0.
 */
/* vif_f1_actvid: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_VIF_F1_ACTVID_OFFSET                     0x80188cu /* established */
#define DM2_VIF_F1_ACTVID_LINE1_SHIFT                11 /* established */
#define DM2_VIF_F1_ACTVID_LINE1_MASK                 0x7ffu
#define DM2_VIF_F1_ACTVID_LINE1_INPLACE              (DM2_VIF_F1_ACTVID_LINE1_MASK << DM2_VIF_F1_ACTVID_LINE1_SHIFT)
#define DM2_VIF_F1_ACTVID_LINE0_SHIFT                0 /* established */
#define DM2_VIF_F1_ACTVID_LINE0_MASK                 0x7ffu
#define DM2_VIF_F1_ACTVID_LINE0_INPLACE              (DM2_VIF_F1_ACTVID_LINE0_MASK << DM2_VIF_F1_ACTVID_LINE0_SHIFT)

/*
 * VIF lines per frame (register number 0x1890): the format row's total line count minus 1 (1124 for the 1125-line HD rows).
 */
/* vif_lines_per_frame: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_VIF_LINES_PER_FRAME_OFFSET               0x801894u /* established */

/*
 * HDOC status (register number 0x2000). The library sets bit 24 as a hold-off before writing the other HDOC registers and clears it after; the final value is built from pipe flags and ORs bit 17 last, except that on a board whose NIC part number is 1653 with revision 3 or later bit 17 is cleared instead (the inferred reading of which NIC fields hold part and revision comes from the GET_NIC ioctl result). The constant part is 0xc8008, or 0x2c8008 by a path flag. Formula established; field meanings unknown. 26 bits.
 */
/* hdoc_status: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_STATUS_OFFSET                       0x802004u /* established */
#define DM2_HDOC_STATUS_HOLD_OFF_SHIFT               24 /* established */
#define DM2_HDOC_STATUS_HOLD_OFF_MASK                0x1u
#define DM2_HDOC_STATUS_HOLD_OFF_INPLACE             (DM2_HDOC_STATUS_HOLD_OFF_MASK << DM2_HDOC_STATUS_HOLD_OFF_SHIFT)
#define DM2_HDOC_STATUS_FLAG17_SHIFT                 17 /* established */
#define DM2_HDOC_STATUS_FLAG17_MASK                  0x1u
#define DM2_HDOC_STATUS_FLAG17_INPLACE               (DM2_HDOC_STATUS_FLAG17_MASK << DM2_HDOC_STATUS_FLAG17_SHIFT)
#define DM2_HDOC_STATUS_FLAG12_SHIFT                 12 /* established */
#define DM2_HDOC_STATUS_FLAG12_MASK                  0x1u
#define DM2_HDOC_STATUS_FLAG12_INPLACE               (DM2_HDOC_STATUS_FLAG12_MASK << DM2_HDOC_STATUS_FLAG12_SHIFT)
#define DM2_HDOC_STATUS_FLAG11_SHIFT                 11 /* established */
#define DM2_HDOC_STATUS_FLAG11_MASK                  0x1u
#define DM2_HDOC_STATUS_FLAG11_INPLACE               (DM2_HDOC_STATUS_FLAG11_MASK << DM2_HDOC_STATUS_FLAG11_SHIFT)
#define DM2_HDOC_STATUS_FLAG10_SHIFT                 10 /* established */
#define DM2_HDOC_STATUS_FLAG10_MASK                  0x1u
#define DM2_HDOC_STATUS_FLAG10_INPLACE               (DM2_HDOC_STATUS_FLAG10_MASK << DM2_HDOC_STATUS_FLAG10_SHIFT)
#define DM2_HDOC_STATUS_SEL_9_7_SHIFT                7 /* established */
#define DM2_HDOC_STATUS_SEL_9_7_MASK                 0x7u
#define DM2_HDOC_STATUS_SEL_9_7_INPLACE              (DM2_HDOC_STATUS_SEL_9_7_MASK << DM2_HDOC_STATUS_SEL_9_7_SHIFT)
#define DM2_HDOC_STATUS_SEL_6_5_SHIFT                5 /* established */
#define DM2_HDOC_STATUS_SEL_6_5_MASK                 0x3u
#define DM2_HDOC_STATUS_SEL_6_5_INPLACE              (DM2_HDOC_STATUS_SEL_6_5_MASK << DM2_HDOC_STATUS_SEL_6_5_SHIFT)
#define DM2_HDOC_STATUS_SEL_1_0_SHIFT                0 /* established */
#define DM2_HDOC_STATUS_SEL_1_0_MASK                 0x3u
#define DM2_HDOC_STATUS_SEL_1_0_INPLACE              (DM2_HDOC_STATUS_SEL_1_0_MASK << DM2_HDOC_STATUS_SEL_1_0_SHIFT)

/*
 * HDOC enable (register number 0x2008, the diagnostic's ENABLE_SEL); the kernel stores the pipe's second shadow here and abort clears bit 0. The out-pipe (pipe 0) video enable; the pairing is inferred.
 */
/* hdoc_enable: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_ENABLE_OFFSET                       0x80200cu /* established */
#define DM2_HDOC_ENABLE_ENABLE_SHIFT                 0 /* inferred */
#define DM2_HDOC_ENABLE_ENABLE_MASK                  0x1u
#define DM2_HDOC_ENABLE_ENABLE_INPLACE               (DM2_HDOC_ENABLE_ENABLE_MASK << DM2_HDOC_ENABLE_ENABLE_SHIFT)

/*
 * HDOC format (register number 0x2010): total lines minus 1 and samples per line minus 1, from format-row words (1125 lines and 2200 samples for 1080i at 59.94).
 */
/* hdoc_format: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_FORMAT_OFFSET                       0x802014u /* established */
#define DM2_HDOC_FORMAT_LINES_MINUS_1_SHIFT          12 /* established */
#define DM2_HDOC_FORMAT_LINES_MINUS_1_MASK           0x7ffu
#define DM2_HDOC_FORMAT_LINES_MINUS_1_INPLACE        (DM2_HDOC_FORMAT_LINES_MINUS_1_MASK << DM2_HDOC_FORMAT_LINES_MINUS_1_SHIFT)
#define DM2_HDOC_FORMAT_SAMPLES_MINUS_1_SHIFT        0 /* established */
#define DM2_HDOC_FORMAT_SAMPLES_MINUS_1_MASK         0xfffu
#define DM2_HDOC_FORMAT_SAMPLES_MINUS_1_INPLACE      (DM2_HDOC_FORMAT_SAMPLES_MINUS_1_MASK << DM2_HDOC_FORMAT_SAMPLES_MINUS_1_SHIFT)

/*
 * HDOC xcc_rden (register number 0x2018): active width plus 41 in the low 12 bits, with constant bits 17, 15 and 12 (0x29000). Formula established; meaning unknown.
 */
/* hdoc_xcc_rden: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_XCC_RDEN_OFFSET                     0x80201cu /* established */
#define DM2_HDOC_XCC_RDEN_WIDTH_PLUS_41_SHIFT        0 /* established */
#define DM2_HDOC_XCC_RDEN_WIDTH_PLUS_41_MASK         0xfffu
#define DM2_HDOC_XCC_RDEN_WIDTH_PLUS_41_INPLACE      (DM2_HDOC_XCC_RDEN_WIDTH_PLUS_41_MASK << DM2_HDOC_XCC_RDEN_WIDTH_PLUS_41_SHIFT)

/*
 * HDOC trs_hblank (register number 0x2020): two 12-bit fields; the high one is active width plus 4 (standard-definition timing) or 8, the low one is 2 or 4 by the same flag. Formula established; meaning unknown.
 */
/* hdoc_trs_hblank: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_TRS_HBLANK_OFFSET                   0x802024u /* established */
#define DM2_HDOC_TRS_HBLANK_HBLANK_END_SHIFT         12 /* established */
#define DM2_HDOC_TRS_HBLANK_HBLANK_END_MASK          0xfffu
#define DM2_HDOC_TRS_HBLANK_HBLANK_END_INPLACE       (DM2_HDOC_TRS_HBLANK_HBLANK_END_MASK << DM2_HDOC_TRS_HBLANK_HBLANK_END_SHIFT)
#define DM2_HDOC_TRS_HBLANK_MODE_SHIFT               0 /* established */
#define DM2_HDOC_TRS_HBLANK_MODE_MASK                0xfffu
#define DM2_HDOC_TRS_HBLANK_MODE_INPLACE             (DM2_HDOC_TRS_HBLANK_MODE_MASK << DM2_HDOC_TRS_HBLANK_MODE_SHIFT)

/*
 * Five HDOC registers with one layout, in order: actvid_fld0, trs_vblank_fld0, actvid_fld1, trs_vblank_fld1, field (register numbers 0x2028 to 0x2048). Two 11-bit line numbers computed from the format row and the path. The last register is forced to 0 when the first and second operands are equal. Formula established; meaning unknown. 22 bits each.
 */
/* hdoc_line_regs: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_LINE_REGS_OFFSET                    0x80202cu /* established */
#define DM2_HDOC_LINE_REGS_COUNT                     5
#define DM2_HDOC_LINE_REGS_STRIDE                    8
#define DM2_HDOC_LINE_REGS_LINE1_SHIFT               11 /* established */
#define DM2_HDOC_LINE_REGS_LINE1_MASK                0x7ffu
#define DM2_HDOC_LINE_REGS_LINE1_INPLACE             (DM2_HDOC_LINE_REGS_LINE1_MASK << DM2_HDOC_LINE_REGS_LINE1_SHIFT)
#define DM2_HDOC_LINE_REGS_LINE0_SHIFT               0 /* established */
#define DM2_HDOC_LINE_REGS_LINE0_MASK                0x7ffu
#define DM2_HDOC_LINE_REGS_LINE0_INPLACE             (DM2_HDOC_LINE_REGS_LINE0_MASK << DM2_HDOC_LINE_REGS_LINE0_SHIFT)

/*
 * HDOC xcc_rden2 (register number 0x2050): two 12-bit fields. Normally the first is active width plus 41 and the second is 41; when the path's geometry equals the full raster both are samples per line minus 41.
 */
/* hdoc_xcc_rden2: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_XCC_RDEN2_OFFSET                    0x802054u /* established */
#define DM2_HDOC_XCC_RDEN2_BLANK_FIELD_SHIFT         12 /* established */
#define DM2_HDOC_XCC_RDEN2_BLANK_FIELD_MASK          0xfffu
#define DM2_HDOC_XCC_RDEN2_BLANK_FIELD_INPLACE       (DM2_HDOC_XCC_RDEN2_BLANK_FIELD_MASK << DM2_HDOC_XCC_RDEN2_BLANK_FIELD_SHIFT)
#define DM2_HDOC_XCC_RDEN2_WIDTH_FIELD_SHIFT         0 /* established */
#define DM2_HDOC_XCC_RDEN2_WIDTH_FIELD_MASK          0xfffu
#define DM2_HDOC_XCC_RDEN2_WIDTH_FIELD_INPLACE       (DM2_HDOC_XCC_RDEN2_WIDTH_FIELD_MASK << DM2_HDOC_XCC_RDEN2_WIDTH_FIELD_SHIFT)

/*
 * HDOC VITC_SEL (register number 0x2058). Name and 23-bit mask only; not written by the library.
 */
/* hdoc_vitc_sel: rw32, reset unknown; shipped diagnostic tables */
#define DM2_HDOC_VITC_SEL_OFFSET                     0x80205cu /* established */

/*
 * HDOC resync (register number 0x2060). The library reads it at init and hands the two fields to the kernel as the resync value, and writes the pair back from the resync routine.
 */
/* hdoc_resync: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_RESYNC_OFFSET                       0x802064u /* established */
#define DM2_HDOC_RESYNC_LINE_SHIFT                   12 /* established */
#define DM2_HDOC_RESYNC_LINE_MASK                    0x7ffu
#define DM2_HDOC_RESYNC_LINE_INPLACE                 (DM2_HDOC_RESYNC_LINE_MASK << DM2_HDOC_RESYNC_LINE_SHIFT)
#define DM2_HDOC_RESYNC_SAMPLE_SHIFT                 0 /* established */
#define DM2_HDOC_RESYNC_SAMPLE_MASK                  0xfffu
#define DM2_HDOC_RESYNC_SAMPLE_INPLACE               (DM2_HDOC_RESYNC_SAMPLE_MASK << DM2_HDOC_RESYNC_SAMPLE_SHIFT)

/*
 * HDOC resync window (register number 0x2068): the resync position moved by 7 samples with carry into the line count and a wrap at the line total. Window semantics are inferred from the name.
 */
/* hdoc_resync_wndw: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_RESYNC_WNDW_OFFSET                  0x80206cu /* established */
#define DM2_HDOC_RESYNC_WNDW_LINE_SHIFT              12 /* established */
#define DM2_HDOC_RESYNC_WNDW_LINE_MASK               0x7ffu
#define DM2_HDOC_RESYNC_WNDW_LINE_INPLACE            (DM2_HDOC_RESYNC_WNDW_LINE_MASK << DM2_HDOC_RESYNC_WNDW_LINE_SHIFT)
#define DM2_HDOC_RESYNC_WNDW_SAMPLE_SHIFT            0 /* established */
#define DM2_HDOC_RESYNC_WNDW_SAMPLE_MASK             0xfffu
#define DM2_HDOC_RESYNC_WNDW_SAMPLE_INPLACE          (DM2_HDOC_RESYNC_WNDW_SAMPLE_MASK << DM2_HDOC_RESYNC_WNDW_SAMPLE_SHIFT)

/*
 * HDOC data_rden (register number 0x2070): active width plus 1 or 2 in the low 12 bits and 0x1000 or 0x2000 in bits 13:12, chosen by the standard-definition flag.
 */
/* hdoc_data_rden: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_HDOC_DATA_RDEN_OFFSET                    0x802074u /* established */
#define DM2_HDOC_DATA_RDEN_MODE_SHIFT                12 /* established */
#define DM2_HDOC_DATA_RDEN_MODE_MASK                 0x3u
#define DM2_HDOC_DATA_RDEN_MODE_INPLACE              (DM2_HDOC_DATA_RDEN_MODE_MASK << DM2_HDOC_DATA_RDEN_MODE_SHIFT)
#define DM2_HDOC_DATA_RDEN_END_SHIFT                 0 /* established */
#define DM2_HDOC_DATA_RDEN_END_MASK                  0xfffu
#define DM2_HDOC_DATA_RDEN_END_INPLACE               (DM2_HDOC_DATA_RDEN_END_MASK << DM2_HDOC_DATA_RDEN_END_SHIFT)

/*
 * HDOC FIFOA_WEN_SEL and FIFOB_WEN_SEL (register numbers 0x2078 and 0x2080). Names and 24-bit masks only; not written by the library.
 */
/* hdoc_fifo_wen_sel: rw32, reset unknown; shipped diagnostic tables */
#define DM2_HDOC_FIFO_WEN_SEL_OFFSET                 0x80207cu /* established */
#define DM2_HDOC_FIFO_WEN_SEL_COUNT                  2
#define DM2_HDOC_FIFO_WEN_SEL_STRIDE                 8

/*
 * Eight diagnostic-only registers, register numbers 0x20b0 to 0x20e8. The diagnostic names, in order, LFIFO_TEST_PATTEN, OXCC_DATA_HI, OXCC_DATA_LO, LFIFO_DATA, VIF_LB_TEST_PATTERN_LO, VIF_LB_TEST_PATTERN_HI, DEFAULT_Y (0x20e0) and DEFAULT_C (0x20e8). Only the last two numbers are tied to names; the assignment of the others to slots follows the listing order and is inferred. Roles unknown. Diagnostic mask 0.
 */
/* hdoc_diag_regs: rw32, reset unknown; shipped diagnostic tables */
#define DM2_HDOC_DIAG_REGS_OFFSET                    0x8020b4u /* inferred */
#define DM2_HDOC_DIAG_REGS_COUNT                     8
#define DM2_HDOC_DIAG_REGS_STRIDE                    8

/*
 * CLINK transmit message: twelve halfword registers (register numbers 0x3800 to 0x3858) that the send ioctl fills from the 24-byte VBOB message, byte 2k in the high half and byte 2k+1 in the low half, before ringing the doorbell. Stores established; that it is a transmit buffer is inferred from the next store.
 */
/* clink_tx_message: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_CLINK_TX_MESSAGE_OFFSET                  0x803804u /* established */
#define DM2_CLINK_TX_MESSAGE_COUNT                   12
#define DM2_CLINK_TX_MESSAGE_STRIDE                  8
#define DM2_CLINK_TX_MESSAGE_HALFWORD_SHIFT          0 /* established */
#define DM2_CLINK_TX_MESSAGE_HALFWORD_MASK           0xffffu
#define DM2_CLINK_TX_MESSAGE_HALFWORD_INPLACE        (DM2_CLINK_TX_MESSAGE_HALFWORD_MASK << DM2_CLINK_TX_MESSAGE_HALFWORD_SHIFT)

/*
 * CLINK pattern-generator divider, low (register number 0x3860, the diagnostic's PGEN_LO_SEL). The library writes CLINK_PGEN_LO_INIT when configuring the on-board 50 MHz clock, but only when the environment variable _XTDIGVID_NO_VBOB_SUPPORT is set (the diagnostic build of the initialisation path); in normal operation it is never written. Role inferred.
 */
/* clink_pgen_lo: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_CLINK_PGEN_LO_OFFSET                     0x803864u /* established */
#define DM2_CLINK_PGEN_LO_DIVIDER_LO_SHIFT           0 /* inferred */
#define DM2_CLINK_PGEN_LO_DIVIDER_LO_MASK            0xffffu
#define DM2_CLINK_PGEN_LO_DIVIDER_LO_INPLACE         (DM2_CLINK_PGEN_LO_DIVIDER_LO_MASK << DM2_CLINK_PGEN_LO_DIVIDER_LO_SHIFT)

/*
 * CLINK pattern-generator divider, high (register number 0x3868, PGEN_HI_SEL). The library writes CLINK_PGEN_HI_INIT, under the same environment-variable condition as the low register. Role inferred.
 */
/* clink_pgen_hi: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_CLINK_PGEN_HI_OFFSET                     0x80386cu /* established */
#define DM2_CLINK_PGEN_HI_DIVIDER_HI_SHIFT           0 /* inferred */
#define DM2_CLINK_PGEN_HI_DIVIDER_HI_MASK            0xffu
#define DM2_CLINK_PGEN_HI_DIVIDER_HI_INPLACE         (DM2_CLINK_PGEN_HI_DIVIDER_HI_MASK << DM2_CLINK_PGEN_HI_DIVIDER_HI_SHIFT)

/*
 * CLINK KSYNC_SEL (register number 0x3870). Name and 9-bit mask only; not written by the library.
 */
/* clink_ksync_sel: rw32, reset unknown; shipped diagnostic tables */
#define DM2_CLINK_KSYNC_SEL_OFFSET                   0x803874u /* established */
#define DM2_CLINK_KSYNC_SEL_STORAGE_SHIFT            0 /* established */
#define DM2_CLINK_KSYNC_SEL_STORAGE_MASK             0x1ffu
#define DM2_CLINK_KSYNC_SEL_STORAGE_INPLACE          (DM2_CLINK_KSYNC_SEL_STORAGE_MASK << DM2_CLINK_KSYNC_SEL_STORAGE_SHIFT)

/*
 * CLINK receive message: twelve halfword registers (register numbers 0x3880 to 0x38d8) the status-ring service routine reads when a message-received flag is set, keeping bits 15:0 of each as a high and a low byte.
 */
/* clink_rx_message: r32, reset unknown; shipped kernel driver and media library readings */
#define DM2_CLINK_RX_MESSAGE_OFFSET                  0x803884u /* established */
#define DM2_CLINK_RX_MESSAGE_COUNT                   12
#define DM2_CLINK_RX_MESSAGE_STRIDE                  8
#define DM2_CLINK_RX_MESSAGE_HALFWORD_SHIFT          0 /* established */
#define DM2_CLINK_RX_MESSAGE_HALFWORD_MASK           0xffffu
#define DM2_CLINK_RX_MESSAGE_HALFWORD_INPLACE        (DM2_CLINK_RX_MESSAGE_HALFWORD_MASK << DM2_CLINK_RX_MESSAGE_HALFWORD_SHIFT)

/*
 * CLINK UART reset (register number 0x38e0, UART_RESET_SEL): the library writes 1 then 0 at init and when an input path opens while the output pipe is idle. Name from the diagnostic, accesses from the library.
 */
/* clink_uart_reset: rw32, reset unknown; shipped kernel driver and media library readings */
#define DM2_CLINK_UART_RESET_OFFSET                  0x8038e4u /* established */
#define DM2_CLINK_UART_RESET_RESET_SHIFT             0 /* established */
#define DM2_CLINK_UART_RESET_RESET_MASK              0x1u
#define DM2_CLINK_UART_RESET_RESET_INPLACE           (DM2_CLINK_UART_RESET_RESET_MASK << DM2_CLINK_UART_RESET_RESET_SHIFT)

/*
 * CLINK transmit doorbell (register number 0x38e8): the send ioctl stores 1 after filling the transmit message and arms a 250-tick timeout; the board answers with the transmit-done status flag. The lock, the outstanding-ack halfword and the wait variable are board-wide (one send at a time for both pipes), so the flag may come on either pipe's ring.
 */
/* clink_tx_doorbell: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_CLINK_TX_DOORBELL_OFFSET                 0x8038ecu /* established */
#define DM2_CLINK_TX_DOORBELL_RING_SHIFT             0 /* established */
#define DM2_CLINK_TX_DOORBELL_RING_MASK              0x1u
#define DM2_CLINK_TX_DOORBELL_RING_INPLACE           (DM2_CLINK_TX_DOORBELL_RING_MASK << DM2_CLINK_TX_DOORBELL_RING_SHIFT)

/*
 * CLINK receive release (register number 0x38f0): the service routine stores 1 after copying a received frame; the event post routine stores a register value to the same word in two places whose value was not traced (unknown).
 */
/* clink_rx_release: w32, reset unknown; shipped kernel driver and media library readings */
#define DM2_CLINK_RX_RELEASE_OFFSET                  0x8038f4u /* established */
#define DM2_CLINK_RX_RELEASE_RELEASE_SHIFT           0 /* established */
#define DM2_CLINK_RX_RELEASE_RELEASE_MASK            0x1u
#define DM2_CLINK_RX_RELEASE_RELEASE_INPLACE         (DM2_CLINK_RX_RELEASE_RELEASE_MASK << DM2_CLINK_RX_RELEASE_RELEASE_SHIFT)

/*
 * Diagnostic layout, input block CONTROL0 (register number 0x2800), 9 storage bits. The layout goes with the second input image, which only the diagnostic loads; which layout belongs to which image is read from who loads it, not from the bitstreams (inferred).
 */
/* ixcc_diag_control0: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_IXCC_DIAG_CONTROL0_OFFSET                0x802804u /* established */
#define DM2_IXCC_DIAG_CONTROL0_STORAGE_SHIFT         0 /* established */
#define DM2_IXCC_DIAG_CONTROL0_STORAGE_MASK          0x1ffu
#define DM2_IXCC_DIAG_CONTROL0_STORAGE_INPLACE       (DM2_IXCC_DIAG_CONTROL0_STORAGE_MASK << DM2_IXCC_DIAG_CONTROL0_STORAGE_SHIFT)

/*
 * Diagnostic layout, input block CONTROL1 (register number 0x2808), 8 storage bits.
 */
/* ixcc_diag_control1: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_IXCC_DIAG_CONTROL1_OFFSET                0x80280cu /* established */
#define DM2_IXCC_DIAG_CONTROL1_STORAGE_SHIFT         0 /* established */
#define DM2_IXCC_DIAG_CONTROL1_STORAGE_MASK          0xffu
#define DM2_IXCC_DIAG_CONTROL1_STORAGE_INPLACE       (DM2_IXCC_DIAG_CONTROL1_STORAGE_MASK << DM2_IXCC_DIAG_CONTROL1_STORAGE_SHIFT)

/*
 * Diagnostic layout, input block LUT_CONTROL (register number 0x2810), 5 storage bits.
 */
/* ixcc_diag_lut_control: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_IXCC_DIAG_LUT_CONTROL_OFFSET             0x802814u /* established */
#define DM2_IXCC_DIAG_LUT_CONTROL_STORAGE_SHIFT      0 /* established */
#define DM2_IXCC_DIAG_LUT_CONTROL_STORAGE_MASK       0x1fu
#define DM2_IXCC_DIAG_LUT_CONTROL_STORAGE_INPLACE    (DM2_IXCC_DIAG_LUT_CONTROL_STORAGE_MASK << DM2_IXCC_DIAG_LUT_CONTROL_STORAGE_SHIFT)

/*
 * Diagnostic layout, input block LUT_DATA (register number 0x2818). Diagnostic mask 0: not tested rather than read-only.
 */
/* ixcc_diag_lut_data: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_IXCC_DIAG_LUT_DATA_OFFSET                0x80281cu /* established */

/*
 * Diagnostic layout, output block control (register number 0x3000), 9 storage bits.
 */
/* oxcc_diag_control0: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_OXCC_DIAG_CONTROL0_OFFSET                0x803004u /* established */
#define DM2_OXCC_DIAG_CONTROL0_STORAGE_SHIFT         0 /* established */
#define DM2_OXCC_DIAG_CONTROL0_STORAGE_MASK          0x1ffu
#define DM2_OXCC_DIAG_CONTROL0_STORAGE_INPLACE       (DM2_OXCC_DIAG_CONTROL0_STORAGE_MASK << DM2_OXCC_DIAG_CONTROL0_STORAGE_SHIFT)

/*
 * Diagnostic layout, output block register number 0x3008, 10 storage bits.
 */
/* oxcc_diag_control1: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_OXCC_DIAG_CONTROL1_OFFSET                0x80300cu /* established */
#define DM2_OXCC_DIAG_CONTROL1_STORAGE_SHIFT         0 /* established */
#define DM2_OXCC_DIAG_CONTROL1_STORAGE_MASK          0x3ffu
#define DM2_OXCC_DIAG_CONTROL1_STORAGE_INPLACE       (DM2_OXCC_DIAG_CONTROL1_STORAGE_MASK << DM2_OXCC_DIAG_CONTROL1_STORAGE_SHIFT)

/*
 * Diagnostic layout, output block register number 0x3010, 5 storage bits.
 */
/* oxcc_diag_lut_control: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_OXCC_DIAG_LUT_CONTROL_OFFSET             0x803014u /* established */
#define DM2_OXCC_DIAG_LUT_CONTROL_STORAGE_SHIFT      0 /* established */
#define DM2_OXCC_DIAG_LUT_CONTROL_STORAGE_MASK       0x1fu
#define DM2_OXCC_DIAG_LUT_CONTROL_STORAGE_INPLACE    (DM2_OXCC_DIAG_LUT_CONTROL_STORAGE_MASK << DM2_OXCC_DIAG_LUT_CONTROL_STORAGE_SHIFT)

/*
 * Diagnostic layout, output block register number 0x3018. Diagnostic mask 0: not tested rather than read-only.
 */
/* oxcc_diag_lut_data: rw32, space xcc_diag, reset unknown; shipped diagnostic tables */
#define DM2_OXCC_DIAG_LUT_DATA_OFFSET                0x80301cu /* established */

/*
 * Input colour-converter LUT control (block base, register number 0x2800). Per component the library writes 8, then 2, 4 or 1 for component 0, 1 or 2, then 8192 data writes, then 0. The sequence is established; the meaning of the control values is unknown.
 */
/* ixcc_prog_lut_control: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_LUT_CONTROL_OFFSET             0x802804u /* established */

/*
 * Input colour-converter LUT data (register number 0x2808). Each of the 8192 entries per component is one 32-bit store carrying no index; whether the entry index auto-increments is unknown.
 */
/* ixcc_prog_lut_data: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_LUT_DATA_OFFSET                0x80280cu /* established */

/*
 * Input colour-converter red, green, blue and alpha offsets (register numbers 0x2810, 0x2818, 0x2820, 0x2828): format-table row words 10 to 13, as unsplit 32-bit values.
 */
/* ixcc_prog_offset: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_OFFSET_OFFSET                  0x802814u /* established */
#define DM2_IXCC_PROG_OFFSET_COUNT                   4
#define DM2_IXCC_PROG_OFFSET_STRIDE                  8

/*
 * Input colour converter misc (register number 0x2830): bit 0 is set when the path's conversion mode is zero and bit 8 is the mode's bit 0 shifted up. Formula established; meaning unknown.
 */
/* ixcc_prog_misc: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_MISC_OFFSET                    0x802834u /* established */
#define DM2_IXCC_PROG_MISC_MODE_BIT0_SHIFT           8 /* established */
#define DM2_IXCC_PROG_MISC_MODE_BIT0_MASK            0x1u
#define DM2_IXCC_PROG_MISC_MODE_BIT0_INPLACE         (DM2_IXCC_PROG_MISC_MODE_BIT0_MASK << DM2_IXCC_PROG_MISC_MODE_BIT0_SHIFT)
#define DM2_IXCC_PROG_MISC_MODE_ZERO_SHIFT           0 /* established */
#define DM2_IXCC_PROG_MISC_MODE_ZERO_MASK            0x1u
#define DM2_IXCC_PROG_MISC_MODE_ZERO_INPLACE         (DM2_IXCC_PROG_MISC_MODE_ZERO_MASK << DM2_IXCC_PROG_MISC_MODE_ZERO_SHIFT)

/*
 * Input colour converter alpha pair (register numbers 0x2838 and 0x2840, one failure message): the first is 4 when the standard-definition flag is set, else the path mode; the second is 0 when the table row index equals a path field, else 3 or the path mode. Offsets established; meaning unknown.
 */
/* ixcc_prog_alpha: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_ALPHA_OFFSET                   0x80283cu /* established */
#define DM2_IXCC_PROG_ALPHA_COUNT                    2
#define DM2_IXCC_PROG_ALPHA_STRIDE                   8

/*
 * Input colour converter coefficient, low 16 bits (register number 0x2848). Written before the high bit and the index.
 */
/* ixcc_prog_coeflo: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_COEFLO_OFFSET                  0x80284cu /* established */
#define DM2_IXCC_PROG_COEFLO_VALUE_SHIFT             0 /* established */
#define DM2_IXCC_PROG_COEFLO_VALUE_MASK              0xffffu
#define DM2_IXCC_PROG_COEFLO_VALUE_INPLACE           (DM2_IXCC_PROG_COEFLO_VALUE_MASK << DM2_IXCC_PROG_COEFLO_VALUE_SHIFT)

/*
 * Input colour converter coefficient, bit 16 (register number 0x2850).
 */
/* ixcc_prog_coefhi: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_COEFHI_OFFSET                  0x802854u /* established */
#define DM2_IXCC_PROG_COEFHI_BIT16_SHIFT             0 /* established */
#define DM2_IXCC_PROG_COEFHI_BIT16_MASK              0x1u
#define DM2_IXCC_PROG_COEFHI_BIT16_INPLACE           (DM2_IXCC_PROG_COEFHI_BIT16_MASK << DM2_IXCC_PROG_COEFHI_BIT16_SHIFT)

/*
 * Input colour converter coefficient index (register number 0x2858), 5 bits, written after the low and high parts. That it latches the coefficient is inferred from the order. Ten coefficients come from a per-format table: words 0 to 8 go to indices 16, 20, 24, 17, 21, 25, 18, 22, 26 (a transposed 3 by 3 matrix, inferred) and word 9 to index 28; then seven filter taps go to indices 0 to 6.
 */
/* ixcc_prog_coefind: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_IXCC_PROG_COEFIND_OFFSET                 0x80285cu /* established */
#define DM2_IXCC_PROG_COEFIND_INDEX_SHIFT            0 /* established */
#define DM2_IXCC_PROG_COEFIND_INDEX_MASK             0x1fu
#define DM2_IXCC_PROG_COEFIND_INDEX_INPLACE          (DM2_IXCC_PROG_COEFIND_INDEX_MASK << DM2_IXCC_PROG_COEFIND_INDEX_SHIFT)

/*
 * Output colour-converter LUT control (block base, register number 0x3000); same sequence as the input block.
 */
/* oxcc_prog_lut_control: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_LUT_CONTROL_OFFSET             0x803004u /* established */

/*
 * Output colour-converter LUT data (register number 0x3008); same behaviour as the input block.
 */
/* oxcc_prog_lut_data: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_LUT_DATA_OFFSET                0x80300cu /* established */

/*
 * Output colour converter red, green and blue offsets, low 16 bits (register numbers 0x3010, 0x3020, 0x3030), from format-table row words 10 to 12. Each is followed by a register holding bit 16 of the same offset.
 */
/* oxcc_prog_offset_lo: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_OFFSET_LO_OFFSET               0x803014u /* established */
#define DM2_OXCC_PROG_OFFSET_LO_COUNT                3
#define DM2_OXCC_PROG_OFFSET_LO_STRIDE               16
#define DM2_OXCC_PROG_OFFSET_LO_VALUE_SHIFT          0 /* established */
#define DM2_OXCC_PROG_OFFSET_LO_VALUE_MASK           0xffffu
#define DM2_OXCC_PROG_OFFSET_LO_VALUE_INPLACE        (DM2_OXCC_PROG_OFFSET_LO_VALUE_MASK << DM2_OXCC_PROG_OFFSET_LO_VALUE_SHIFT)

/*
 * Output colour converter red, green and blue offsets, bit 16 (register numbers 0x3018, 0x3028, 0x3038).
 */
/* oxcc_prog_offset_bit16: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_OFFSET_BIT16_OFFSET            0x80301cu /* established */
#define DM2_OXCC_PROG_OFFSET_BIT16_COUNT             3
#define DM2_OXCC_PROG_OFFSET_BIT16_STRIDE            16
#define DM2_OXCC_PROG_OFFSET_BIT16_BIT16_SHIFT       0 /* established */
#define DM2_OXCC_PROG_OFFSET_BIT16_BIT16_MASK        0x1u
#define DM2_OXCC_PROG_OFFSET_BIT16_BIT16_INPLACE     (DM2_OXCC_PROG_OFFSET_BIT16_BIT16_MASK << DM2_OXCC_PROG_OFFSET_BIT16_BIT16_SHIFT)

/*
 * Output colour converter around (register number 0x3040): format-table row word 13.
 */
/* oxcc_prog_around: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_AROUND_OFFSET                  0x803044u /* established */

/*
 * Output colour converter pack8 (register number 0x3048): 1 when the component size is 8 bits.
 */
/* oxcc_prog_pack8: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_PACK8_OFFSET                   0x80304cu /* established */

/*
 * Output colour converter dec (register number 0x3050): 0, or 3 or the pipe mode, chosen by the path. Offset established; formula unknown.
 */
/* oxcc_prog_dec: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_DEC_OFFSET                     0x803054u /* established */

/*
 * Output colour converter coefficient, low 16 bits (register number 0x3058).
 */
/* oxcc_prog_coeflo: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_COEFLO_OFFSET                  0x80305cu /* established */
#define DM2_OXCC_PROG_COEFLO_VALUE_SHIFT             0 /* established */
#define DM2_OXCC_PROG_COEFLO_VALUE_MASK              0xffffu
#define DM2_OXCC_PROG_COEFLO_VALUE_INPLACE           (DM2_OXCC_PROG_COEFLO_VALUE_MASK << DM2_OXCC_PROG_COEFLO_VALUE_SHIFT)

/*
 * Output colour converter coefficient, bit 16 (register number 0x3060).
 */
/* oxcc_prog_coefhi: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_COEFHI_OFFSET                  0x803064u /* established */
#define DM2_OXCC_PROG_COEFHI_BIT16_SHIFT             0 /* established */
#define DM2_OXCC_PROG_COEFHI_BIT16_MASK              0x1u
#define DM2_OXCC_PROG_COEFHI_BIT16_INPLACE           (DM2_OXCC_PROG_COEFHI_BIT16_MASK << DM2_OXCC_PROG_COEFHI_BIT16_SHIFT)

/*
 * Output colour converter coefficient index (register number 0x3068), 5 bits, written after the low and high parts.
 */
/* oxcc_prog_coefind: rw32, space xcc_prog, reset unknown; shipped kernel driver and media library readings */
#define DM2_OXCC_PROG_COEFIND_OFFSET                 0x80306cu /* established */
#define DM2_OXCC_PROG_COEFIND_INDEX_SHIFT            0 /* established */
#define DM2_OXCC_PROG_COEFIND_INDEX_MASK             0x1fu
#define DM2_OXCC_PROG_COEFIND_INDEX_INPLACE          (DM2_OXCC_PROG_COEFIND_INDEX_MASK << DM2_OXCC_PROG_COEFIND_INDEX_SHIFT)

/*
 * Word at +4 of a 28-byte FPGA info record (all fields are big-endian 32-bit words): the kind, which selects the start, byte and stop routines.
 */
/* word FPGA_INFO_KIND: 32 bits; shipped kernel driver and media library readings */
#define DM2_FPGA_INFO_KIND_WIDTH                     32 /* established */
#define DM2_FPGA_INFO_KIND_KIND_SHIFT                0 /* established */
#define DM2_FPGA_INFO_KIND_KIND_MASK                 0x3u
#define DM2_FPGA_INFO_KIND_KIND_INPLACE              (DM2_FPGA_INFO_KIND_KIND_MASK << DM2_FPGA_INFO_KIND_KIND_SHIFT)

/*
 * Write layout of the GIF programming register: an 8-bit data byte, a clock in bit 8 and a strobe in bit 9 that is high in the idle and active-data states. Each image byte of the GIF load is stored eight times unshifted, once with the clock low and once high. Values and tests established; the names are inferred. The kernel's own byte-load case stores a byte ORed with the clock-low and clock-high patterns the same way.
 */
/* word FPGA_PROG_WRITE: 32 bits; shipped kernel driver and media library readings */
#define DM2_FPGA_PROG_WRITE_WIDTH                    32 /* established */
#define DM2_FPGA_PROG_WRITE_STROBE_SHIFT             9 /* inferred */
#define DM2_FPGA_PROG_WRITE_STROBE_MASK              0x1u
#define DM2_FPGA_PROG_WRITE_STROBE_INPLACE           (DM2_FPGA_PROG_WRITE_STROBE_MASK << DM2_FPGA_PROG_WRITE_STROBE_SHIFT)
#define DM2_FPGA_PROG_WRITE_CLOCK_SHIFT              8 /* inferred */
#define DM2_FPGA_PROG_WRITE_CLOCK_MASK               0x1u
#define DM2_FPGA_PROG_WRITE_CLOCK_INPLACE            (DM2_FPGA_PROG_WRITE_CLOCK_MASK << DM2_FPGA_PROG_WRITE_CLOCK_SHIFT)
#define DM2_FPGA_PROG_WRITE_DATA_SHIFT               0 /* established */
#define DM2_FPGA_PROG_WRITE_DATA_MASK                0xffu
#define DM2_FPGA_PROG_WRITE_DATA_INPLACE             (DM2_FPGA_PROG_WRITE_DATA_MASK << DM2_FPGA_PROG_WRITE_DATA_SHIFT)

/*
 * A valid map-RAM page-table entry, one 32-bit word per 16 KiB page of the board's own DMA address space, stored by the driver as one big-endian PIO store. Written value is the page number's low 26 bits shifted left by 2, ORed with the valid bit. Whether the hardware reads bits 1:0 or the top bits as attributes, and the byte order its logic applies to the store, are unknown: nothing reads an entry back.
 */
/* word MAPRAM_ENTRY: 32 bits; shipped kernel driver and media library readings */
#define DM2_MAPRAM_ENTRY_WIDTH                       32 /* established */
#define DM2_MAPRAM_ENTRY_VALID_SHIFT                 29 /* established */
#define DM2_MAPRAM_ENTRY_VALID_MASK                  0x1u
#define DM2_MAPRAM_ENTRY_VALID_INPLACE               (DM2_MAPRAM_ENTRY_VALID_MASK << DM2_MAPRAM_ENTRY_VALID_SHIFT)
#define DM2_MAPRAM_ENTRY_INVALID_SHIFT               28 /* established */
#define DM2_MAPRAM_ENTRY_INVALID_MASK                0x1u
#define DM2_MAPRAM_ENTRY_INVALID_INPLACE             (DM2_MAPRAM_ENTRY_INVALID_MASK << DM2_MAPRAM_ENTRY_INVALID_SHIFT)
#define DM2_MAPRAM_ENTRY_PPN_SHIFT                   2 /* established */
#define DM2_MAPRAM_ENTRY_PPN_MASK                    0x3ffffffu
#define DM2_MAPRAM_ENTRY_PPN_INPLACE                 (DM2_MAPRAM_ENTRY_PPN_MASK << DM2_MAPRAM_ENTRY_PPN_SHIFT)

/*
 * An invalidated map-RAM entry: bit 28 set and a run-length counter below it. The driver writes n consecutive entries, the i-th as the invalid bit with the value n minus 1 minus i, so a single invalidated page is exactly the invalid bit alone. That bit 28 is what the hardware tests, and that the counter is only a run length, is inferred; the effect is the map-RAM-invalid error cause with the entry address in the map-RAM error address register.
 */
/* word MAPRAM_ENTRY_INVALIDATED: 32 bits; shipped kernel driver and media library readings */
#define DM2_MAPRAM_ENTRY_INVALIDATED_WIDTH           32 /* established */
#define DM2_MAPRAM_ENTRY_INVALIDATED_INVALID_SHIFT   28 /* established */
#define DM2_MAPRAM_ENTRY_INVALIDATED_INVALID_MASK    0x1u
#define DM2_MAPRAM_ENTRY_INVALIDATED_INVALID_INPLACE (DM2_MAPRAM_ENTRY_INVALIDATED_INVALID_MASK << DM2_MAPRAM_ENTRY_INVALIDATED_INVALID_SHIFT)
#define DM2_MAPRAM_ENTRY_INVALIDATED_RUN_LEFT_SHIFT  0 /* inferred */
#define DM2_MAPRAM_ENTRY_INVALIDATED_RUN_LEFT_MASK   0xfffffffu
#define DM2_MAPRAM_ENTRY_INVALIDATED_RUN_LEFT_INPLACE (DM2_MAPRAM_ENTRY_INVALIDATED_RUN_LEFT_MASK << DM2_MAPRAM_ENTRY_INVALIDATED_RUN_LEFT_SHIFT)

/*
 * Word 1 of a status-ring entry, the flag word. Bit numbers and names come from the driver's own 20-entry flag-name table (established); what each bit means in hardware terms is inferred from its name. Pipe 0 is the out pipe (video interrupt 1), pipe 1 the in pipe (video interrupt 0). The host clears VALID first, then handles the completion bits slot by slot in order, then the field-interrupt bit, the error bits while DMA is enabled, and the two link bits. Bits 20 to 31 have no table entry and no test.
 */
/* word RING_ENTRY_FLAGS: 32 bits; shipped kernel driver and media library readings */
#define DM2_RING_ENTRY_FLAGS_WIDTH                   32 /* established */
#define DM2_RING_ENTRY_FLAGS_CLINK_RCV_DONE_SHIFT    19 /* established */
#define DM2_RING_ENTRY_FLAGS_CLINK_RCV_DONE_MASK     0x1u
#define DM2_RING_ENTRY_FLAGS_CLINK_RCV_DONE_INPLACE  (DM2_RING_ENTRY_FLAGS_CLINK_RCV_DONE_MASK << DM2_RING_ENTRY_FLAGS_CLINK_RCV_DONE_SHIFT)
#define DM2_RING_ENTRY_FLAGS_CLINK_XMIT_DONE_SHIFT   18 /* established */
#define DM2_RING_ENTRY_FLAGS_CLINK_XMIT_DONE_MASK    0x1u
#define DM2_RING_ENTRY_FLAGS_CLINK_XMIT_DONE_INPLACE (DM2_RING_ENTRY_FLAGS_CLINK_XMIT_DONE_MASK << DM2_RING_ENTRY_FLAGS_CLINK_XMIT_DONE_SHIFT)
#define DM2_RING_ENTRY_FLAGS_CURRENT_VALID_SHIFT     16 /* inferred */
#define DM2_RING_ENTRY_FLAGS_CURRENT_VALID_MASK      0x3u
#define DM2_RING_ENTRY_FLAGS_CURRENT_VALID_INPLACE   (DM2_RING_ENTRY_FLAGS_CURRENT_VALID_MASK << DM2_RING_ENTRY_FLAGS_CURRENT_VALID_SHIFT)
#define DM2_RING_ENTRY_FLAGS_ABORTED_SHIFT           12 /* established */
#define DM2_RING_ENTRY_FLAGS_ABORTED_MASK            0xfu
#define DM2_RING_ENTRY_FLAGS_ABORTED_INPLACE         (DM2_RING_ENTRY_FLAGS_ABORTED_MASK << DM2_RING_ENTRY_FLAGS_ABORTED_SHIFT)
#define DM2_RING_ENTRY_FLAGS_DONE_SHIFT              8 /* established */
#define DM2_RING_ENTRY_FLAGS_DONE_MASK               0xfu
#define DM2_RING_ENTRY_FLAGS_DONE_INPLACE            (DM2_RING_ENTRY_FLAGS_DONE_MASK << DM2_RING_ENTRY_FLAGS_DONE_SHIFT)
#define DM2_RING_ENTRY_FLAGS_F_INTR_SHIFT            7 /* established */
#define DM2_RING_ENTRY_FLAGS_F_INTR_MASK             0x1u
#define DM2_RING_ENTRY_FLAGS_F_INTR_INPLACE          (DM2_RING_ENTRY_FLAGS_F_INTR_MASK << DM2_RING_ENTRY_FLAGS_F_INTR_SHIFT)
#define DM2_RING_ENTRY_FLAGS_FIF_SHIFT               6 /* established */
#define DM2_RING_ENTRY_FLAGS_FIF_MASK                0x1u
#define DM2_RING_ENTRY_FLAGS_FIF_INPLACE             (DM2_RING_ENTRY_FLAGS_FIF_MASK << DM2_RING_ENTRY_FLAGS_FIF_SHIFT)
#define DM2_RING_ENTRY_FLAGS_IN_CHANGE_SHIFT         5 /* established */
#define DM2_RING_ENTRY_FLAGS_IN_CHANGE_MASK          0x1u
#define DM2_RING_ENTRY_FLAGS_IN_CHANGE_INPLACE       (DM2_RING_ENTRY_FLAGS_IN_CHANGE_MASK << DM2_RING_ENTRY_FLAGS_IN_CHANGE_SHIFT)
#define DM2_RING_ENTRY_FLAGS_OVERFLOW_SHIFT          4 /* established */
#define DM2_RING_ENTRY_FLAGS_OVERFLOW_MASK           0x1u
#define DM2_RING_ENTRY_FLAGS_OVERFLOW_INPLACE        (DM2_RING_ENTRY_FLAGS_OVERFLOW_MASK << DM2_RING_ENTRY_FLAGS_OVERFLOW_SHIFT)
#define DM2_RING_ENTRY_FLAGS_TRS_ERROR_SHIFT         3 /* established */
#define DM2_RING_ENTRY_FLAGS_TRS_ERROR_MASK          0x1u
#define DM2_RING_ENTRY_FLAGS_TRS_ERROR_INPLACE       (DM2_RING_ENTRY_FLAGS_TRS_ERROR_MASK << DM2_RING_ENTRY_FLAGS_TRS_ERROR_SHIFT)
#define DM2_RING_ENTRY_FLAGS_INPUT_OFF_SHIFT         2 /* established */
#define DM2_RING_ENTRY_FLAGS_INPUT_OFF_MASK          0x1u
#define DM2_RING_ENTRY_FLAGS_INPUT_OFF_INPLACE       (DM2_RING_ENTRY_FLAGS_INPUT_OFF_MASK << DM2_RING_ENTRY_FLAGS_INPUT_OFF_SHIFT)
#define DM2_RING_ENTRY_FLAGS_F_SHIFT                 1 /* established */
#define DM2_RING_ENTRY_FLAGS_F_MASK                  0x1u
#define DM2_RING_ENTRY_FLAGS_F_INPLACE               (DM2_RING_ENTRY_FLAGS_F_MASK << DM2_RING_ENTRY_FLAGS_F_SHIFT)
#define DM2_RING_ENTRY_FLAGS_VALID_SHIFT             0 /* established */
#define DM2_RING_ENTRY_FLAGS_VALID_MASK              0x1u
#define DM2_RING_ENTRY_FLAGS_VALID_INPLACE           (DM2_RING_ENTRY_FLAGS_VALID_MASK << DM2_RING_ENTRY_FLAGS_VALID_SHIFT)

/*
 * Word 0 of a 0x80-byte status-ring entry. The service routine treats bits 23:0 as a device media stream counter (MSC) and extends it to 64 bits, detecting a wrap by an unsigned compare with the previous value. The code only works if bits 31:24 read as zero (inferred; the driver does not check). The name MSC is inferred from the driver's own strings.
 */
/* word RING_ENTRY_W0: 32 bits; shipped kernel driver and media library readings */
#define DM2_RING_ENTRY_W0_WIDTH                      32 /* established */
#define DM2_RING_ENTRY_W0_RESERVED_ZERO_SHIFT        24 /* inferred */
#define DM2_RING_ENTRY_W0_RESERVED_ZERO_MASK         0xffu
#define DM2_RING_ENTRY_W0_RESERVED_ZERO_INPLACE      (DM2_RING_ENTRY_W0_RESERVED_ZERO_MASK << DM2_RING_ENTRY_W0_RESERVED_ZERO_SHIFT)
#define DM2_RING_ENTRY_W0_MSC_SHIFT                  0 /* inferred */
#define DM2_RING_ENTRY_W0_MSC_MASK                   0xffffffu
#define DM2_RING_ENTRY_W0_MSC_INPLACE                (DM2_RING_ENTRY_W0_MSC_MASK << DM2_RING_ENTRY_W0_MSC_SHIFT)

/*
 * First four bytes of the 24-byte VBOB control message frame, in wire order from the high byte: count of bytes that follow, pipe, register id with bit 7 set for a write, then the first data byte. Byte layout established from every message builder in the library; names are inferred. The same 24 bytes are carried as twelve halfwords in the CLINK transmit and receive registers. Which pipe's ring carries a receive flag is unknown.
 */
/* word VBOB_MSG_HEADER: 32 bits; shipped kernel driver and media library readings */
#define DM2_VBOB_MSG_HEADER_WIDTH                    32 /* established */
#define DM2_VBOB_MSG_HEADER_COUNT_SHIFT              24 /* established */
#define DM2_VBOB_MSG_HEADER_COUNT_MASK               0xffu
#define DM2_VBOB_MSG_HEADER_COUNT_INPLACE            (DM2_VBOB_MSG_HEADER_COUNT_MASK << DM2_VBOB_MSG_HEADER_COUNT_SHIFT)
#define DM2_VBOB_MSG_HEADER_PIPE_SHIFT               16 /* established */
#define DM2_VBOB_MSG_HEADER_PIPE_MASK                0xffu
#define DM2_VBOB_MSG_HEADER_PIPE_INPLACE             (DM2_VBOB_MSG_HEADER_PIPE_MASK << DM2_VBOB_MSG_HEADER_PIPE_SHIFT)
#define DM2_VBOB_MSG_HEADER_WRITE_SHIFT              15 /* established */
#define DM2_VBOB_MSG_HEADER_WRITE_MASK               0x1u
#define DM2_VBOB_MSG_HEADER_WRITE_INPLACE            (DM2_VBOB_MSG_HEADER_WRITE_MASK << DM2_VBOB_MSG_HEADER_WRITE_SHIFT)
#define DM2_VBOB_MSG_HEADER_REG_ID_SHIFT             8 /* established */
#define DM2_VBOB_MSG_HEADER_REG_ID_MASK              0x7fu
#define DM2_VBOB_MSG_HEADER_REG_ID_INPLACE           (DM2_VBOB_MSG_HEADER_REG_ID_MASK << DM2_VBOB_MSG_HEADER_REG_ID_SHIFT)
#define DM2_VBOB_MSG_HEADER_DATA0_SHIFT              0 /* inferred */
#define DM2_VBOB_MSG_HEADER_DATA0_MASK               0xffu
#define DM2_VBOB_MSG_HEADER_DATA0_INPLACE            (DM2_VBOB_MSG_HEADER_DATA0_MASK << DM2_VBOB_MSG_HEADER_DATA0_SHIFT)

#define DM2_CLINK_PGEN_HI_INIT                       0x25u /* established */
#define DM2_CLINK_PGEN_LO_INIT                       0xc3f7u /* established */
#define DM2_FPGA_CLINK_DONE_MASK                     0x4000u /* established */
#define DM2_FPGA_CLINK_IMAGE_SIZE                    0x8a64u /* established */
#define DM2_FPGA_CLINK_INIT_MASK                     0x8000u /* established */
#define DM2_FPGA_CLINK_KIND                          0x0u /* established */
#define DM2_FPGA_CLINK_NUMBER                        0x7u /* established */
#define DM2_FPGA_CLINK_PORT_OFFSET                   0x3800u /* established */
#define DM2_FPGA_CLINK_SELECT                        0x40u /* inferred */
#define DM2_FPGA_DATA_PORT_ADD                       0x80000u /* established */
#define DM2_FPGA_GIF_DONE_MASK                       0x1u /* established */
#define DM2_FPGA_GIF_IMAGE_SIZE                      0x2bc21u /* established */
#define DM2_FPGA_GIF_INIT_MASK                       0x2u /* established */
#define DM2_FPGA_GIF_KIND                            0x1u /* established */
#define DM2_FPGA_GIF_NUMBER                          0x0u /* established */
#define DM2_FPGA_GIF_PORT_OFFSET                     0x0u /* established */
#define DM2_FPGA_GIF_SELECT                          0x0u /* established */
#define DM2_FPGA_HDOC_DONE_MASK                      0x1000u /* established */
#define DM2_FPGA_HDOC_IMAGE_SIZE                     0x19682u /* established */
#define DM2_FPGA_HDOC_INIT_MASK                      0x2000u /* established */
#define DM2_FPGA_HDOC_KIND                           0x0u /* established */
#define DM2_FPGA_HDOC_NUMBER                         0x5u /* established */
#define DM2_FPGA_HDOC_PORT_OFFSET                    0x2000u /* established */
#define DM2_FPGA_HDOC_SELECT                         0x8u /* inferred */
#define DM2_FPGA_INFO_OFF_DONE_MASK                  0x14u /* established */
#define DM2_FPGA_INFO_OFF_IMAGE_SIZE                 0x8u /* established */
#define DM2_FPGA_INFO_OFF_INIT_MASK                  0x18u /* established */
#define DM2_FPGA_INFO_OFF_KIND                       0x4u /* established */
#define DM2_FPGA_INFO_OFF_NAME                       0x0u /* established */
#define DM2_FPGA_INFO_OFF_PORT_OFFSET                0x10u /* established */
#define DM2_FPGA_INFO_OFF_SELECT                     0xcu /* established */
#define DM2_FPGA_INFO_RECORDS                        0x8u /* established */
#define DM2_FPGA_INFO_RECORD_SIZE                    0x1cu /* established */
#define DM2_FPGA_IXCC_DONE_MASK                      0x40u /* established */
#define DM2_FPGA_IXCC_IMAGE_SIZE                     0x4db30u /* established */
#define DM2_FPGA_IXCC_INIT_MASK                      0x80u /* established */
#define DM2_FPGA_IXCC_KIND                           0x2u /* established */
#define DM2_FPGA_IXCC_NUMBER                         0x4u /* established */
#define DM2_FPGA_IXCC_PORT_OFFSET                    0x2800u /* established */
#define DM2_FPGA_IXCC_SELECT                         0x10u /* inferred */
#define DM2_FPGA_OXCC_DONE_MASK                      0x100u /* established */
#define DM2_FPGA_OXCC_IMAGE_SIZE                     0x4db30u /* established */
#define DM2_FPGA_OXCC_INIT_MASK                      0x200u /* established */
#define DM2_FPGA_OXCC_KIND                           0x2u /* established */
#define DM2_FPGA_OXCC_NUMBER                         0x3u /* established */
#define DM2_FPGA_OXCC_PORT_OFFSET                    0x3000u /* established */
#define DM2_FPGA_OXCC_SELECT                         0x20u /* inferred */
#define DM2_FPGA_PACK_DONE_MASK                      0x4u /* established */
#define DM2_FPGA_PACK_IMAGE_SIZE                     0x19682u /* established */
#define DM2_FPGA_PACK_INIT_MASK                      0x8u /* established */
#define DM2_FPGA_PACK_KIND                           0x0u /* established */
#define DM2_FPGA_PACK_NUMBER                         0x1u /* established */
#define DM2_FPGA_PACK_PORT_OFFSET                    0x800u /* established */
#define DM2_FPGA_PACK_SELECT                         0x1u /* inferred */
#define DM2_FPGA_UNPACK_DONE_MASK                    0x10u /* established */
#define DM2_FPGA_UNPACK_IMAGE_SIZE                   0x19682u /* established */
#define DM2_FPGA_UNPACK_INIT_MASK                    0x20u /* established */
#define DM2_FPGA_UNPACK_KIND                         0x0u /* established */
#define DM2_FPGA_UNPACK_NUMBER                       0x2u /* established */
#define DM2_FPGA_UNPACK_PORT_OFFSET                  0x1000u /* established */
#define DM2_FPGA_UNPACK_SELECT                       0x2u /* inferred */
#define DM2_FPGA_VIF_DONE_MASK                       0x400u /* established */
#define DM2_FPGA_VIF_IMAGE_SIZE                      0x19682u /* established */
#define DM2_FPGA_VIF_INIT_MASK                       0x800u /* established */
#define DM2_FPGA_VIF_KIND                            0x0u /* established */
#define DM2_FPGA_VIF_NUMBER                          0x6u /* established */
#define DM2_FPGA_VIF_PORT_OFFSET                     0x1800u /* established */
#define DM2_FPGA_VIF_SELECT                          0x4u /* inferred */
#define DM2_GIF_BLOCK_CLINK                          0x3800u /* established */
#define DM2_GIF_BLOCK_CORE                           0x0u /* established */
#define DM2_GIF_BLOCK_HDOC                           0x2000u /* established */
#define DM2_GIF_BLOCK_IXCC                           0x2800u /* established */
#define DM2_GIF_BLOCK_OXCC                           0x3000u /* established */
#define DM2_GIF_BLOCK_PACKER                         0x800u /* established */
#define DM2_GIF_BLOCK_SIZE                           0x800u /* established */
#define DM2_GIF_BLOCK_UNPACKER                       0x1000u /* established */
#define DM2_GIF_BLOCK_VIF                            0x1800u /* established */
#define DM2_GIF_FILE_BASE                            0x800000u /* established */
#define DM2_GIF_SLOT_STRIDE                          0x8u /* established */
#define DM2_MAPRAM_BASE                              0x100000u /* established */
#define DM2_MAPRAM_PAGE_SHIFT                        0xeu /* established */
#define DM2_MAPRAM_SLOT_PAGES_MAX                    0x400u /* established */
#define DM2_PACK_INIT_R0800                          0x1f0008u /* established */
#define DM2_PACK_INIT_R0808                          0x1f0008u /* established */
#define DM2_PACK_INIT_R0810                          0x1f0008u /* established */
#define DM2_PACK_INIT_R0840                          0x1000u /* established */
#define DM2_PACK_INIT_R0848                          0x1000u /* established */
#define DM2_PACK_INIT_R0850                          0xd00u /* established */
#define DM2_PIPE_DMA_CONTROL_INIT_PIPE0              0xea040u /* established */
#define DM2_PIPE_DMA_CONTROL_INIT_PIPE1              0xa040u /* established */
#define DM2_RING_DMA_ADDR_PIPE0                      0x8000000u /* established */
#define DM2_RING_DMA_ADDR_PIPE1                      0x9000000u /* established */
#define DM2_RING_ENTRIES                             0x10u /* established */
#define DM2_RING_ENTRY_BYTES                         0x80u /* established */
#define DM2_UNPACK_INIT_MISC_BASE                    0xfffe0f9u /* established */
#define DM2_UNPACK_INIT_R1000                        0x160008u /* established */
#define DM2_UNPACK_INIT_R1008                        0x32001fu /* established */
#define DM2_UNPACK_INIT_R1040                        0x1200u /* established */
#define DM2_UNPACK_INIT_R1048                        0xd00u /* established */
#define DM2_VBOB_MSG_BYTES                           0x18u /* established */
#define DM2_VBOB_TX_TIMEOUT_TICKS                    0xfau /* established */

#endif /* DM2_GEN_H */
