/* generated from devices/lh28f800su/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 71c039ffd5729e496aee717c8dfa100cd9f37ba507e648af391cd31eae7a983a */
/* Sharp LH28F800SU 8 Mbit x16 flash: array geometry, command set, identifier and status registers */
#ifndef LH28F800SU_GEN_H
#define LH28F800SU_GEN_H

#include <stdint.h>


/* enum bsr_op */
#define LH28F800SU_BSR_OP_OK_OR_RUNNING              0 /* established */
#define LH28F800SU_BSR_OP_FAILURE                    2 /* established */
#define LH28F800SU_BSR_OP_ABORTED                    3 /* established */

/* enum gsr_op */
#define LH28F800SU_GSR_OP_OK_OR_RUNNING              0 /* established */
#define LH28F800SU_GSR_OP_SLEEP                      1 /* established */
#define LH28F800SU_GSR_OP_FAILURE                    2 /* established */
#define LH28F800SU_GSR_OP_FAILURE_OR_ABORT           3 /* established */

/*
 * Block status register, one per block, read through the extended-status mode at the BSR word address of that block. Bits 1 and 0 are reserved.
 */
/* word BSR: 8 bits */
#define LH28F800SU_BSR_WIDTH                         8 /* established */
#define LH28F800SU_BSR_BLOCK_READY_SHIFT             7 /* established */
#define LH28F800SU_BSR_BLOCK_READY_MASK              0x1u
#define LH28F800SU_BSR_BLOCK_READY_INPLACE           (LH28F800SU_BSR_BLOCK_READY_MASK << LH28F800SU_BSR_BLOCK_READY_SHIFT)
#define LH28F800SU_BSR_LOCK_CLEARED_SHIFT            6 /* established */
#define LH28F800SU_BSR_LOCK_CLEARED_MASK             0x1u
#define LH28F800SU_BSR_LOCK_CLEARED_INPLACE          (LH28F800SU_BSR_LOCK_CLEARED_MASK << LH28F800SU_BSR_LOCK_CLEARED_SHIFT)
#define LH28F800SU_BSR_OP_STATUS_SHIFT               4 /* established */
#define LH28F800SU_BSR_OP_STATUS_MASK                0x3u
#define LH28F800SU_BSR_OP_STATUS_INPLACE             (LH28F800SU_BSR_OP_STATUS_MASK << LH28F800SU_BSR_OP_STATUS_SHIFT)
#define LH28F800SU_BSR_QUEUE_FULL_SHIFT              3 /* established */
#define LH28F800SU_BSR_QUEUE_FULL_MASK               0x1u
#define LH28F800SU_BSR_QUEUE_FULL_INPLACE            (LH28F800SU_BSR_QUEUE_FULL_MASK << LH28F800SU_BSR_QUEUE_FULL_SHIFT)
#define LH28F800SU_BSR_LOW_VPP_SHIFT                 2 /* established */
#define LH28F800SU_BSR_LOW_VPP_MASK                  0x1u
#define LH28F800SU_BSR_LOW_VPP_INPLACE               (LH28F800SU_BSR_LOW_VPP_MASK << LH28F800SU_BSR_LOW_VPP_SHIFT)

/*
 * Compatible status register, read after 0x70. Bit 7 is ready when set and busy when clear. Bits 2 to 0 are reserved.
 */
/* word CSR: 8 bits */
#define LH28F800SU_CSR_WIDTH                         8 /* established */
#define LH28F800SU_CSR_READY_SHIFT                   7 /* established */
#define LH28F800SU_CSR_READY_MASK                    0x1u
#define LH28F800SU_CSR_READY_INPLACE                 (LH28F800SU_CSR_READY_MASK << LH28F800SU_CSR_READY_SHIFT)
#define LH28F800SU_CSR_ERASE_SUSPENDED_SHIFT         6 /* established */
#define LH28F800SU_CSR_ERASE_SUSPENDED_MASK          0x1u
#define LH28F800SU_CSR_ERASE_SUSPENDED_INPLACE       (LH28F800SU_CSR_ERASE_SUSPENDED_MASK << LH28F800SU_CSR_ERASE_SUSPENDED_SHIFT)
#define LH28F800SU_CSR_ERASE_ERROR_SHIFT             5 /* established */
#define LH28F800SU_CSR_ERASE_ERROR_MASK              0x1u
#define LH28F800SU_CSR_ERASE_ERROR_INPLACE           (LH28F800SU_CSR_ERASE_ERROR_MASK << LH28F800SU_CSR_ERASE_ERROR_SHIFT)
#define LH28F800SU_CSR_PROGRAM_ERROR_SHIFT           4 /* established */
#define LH28F800SU_CSR_PROGRAM_ERROR_MASK            0x1u
#define LH28F800SU_CSR_PROGRAM_ERROR_INPLACE         (LH28F800SU_CSR_PROGRAM_ERROR_MASK << LH28F800SU_CSR_PROGRAM_ERROR_SHIFT)
#define LH28F800SU_CSR_LOW_VPP_SHIFT                 3 /* established */
#define LH28F800SU_CSR_LOW_VPP_MASK                  0x1u
#define LH28F800SU_CSR_LOW_VPP_INPLACE               (LH28F800SU_CSR_LOW_VPP_MASK << LH28F800SU_CSR_LOW_VPP_SHIFT)

/*
 * Global status register, read through the extended-status mode at the GSR word address of a block. Only the low byte is defined. DQ8 to DQ15 are not used for status register reads (printed p. 4).
 */
/* word GSR: 8 bits */
#define LH28F800SU_GSR_WIDTH                         8 /* established */
#define LH28F800SU_GSR_WRITE_READY_SHIFT             7 /* established */
#define LH28F800SU_GSR_WRITE_READY_MASK              0x1u
#define LH28F800SU_GSR_WRITE_READY_INPLACE           (LH28F800SU_GSR_WRITE_READY_MASK << LH28F800SU_GSR_WRITE_READY_SHIFT)
#define LH28F800SU_GSR_SUSPENDED_SHIFT               6 /* established */
#define LH28F800SU_GSR_SUSPENDED_MASK                0x1u
#define LH28F800SU_GSR_SUSPENDED_INPLACE             (LH28F800SU_GSR_SUSPENDED_MASK << LH28F800SU_GSR_SUSPENDED_SHIFT)
#define LH28F800SU_GSR_OP_STATUS_SHIFT               4 /* established */
#define LH28F800SU_GSR_OP_STATUS_MASK                0x3u
#define LH28F800SU_GSR_OP_STATUS_INPLACE             (LH28F800SU_GSR_OP_STATUS_MASK << LH28F800SU_GSR_OP_STATUS_SHIFT)
#define LH28F800SU_GSR_QUEUE_FULL_SHIFT              3 /* established */
#define LH28F800SU_GSR_QUEUE_FULL_MASK               0x1u
#define LH28F800SU_GSR_QUEUE_FULL_INPLACE            (LH28F800SU_GSR_QUEUE_FULL_MASK << LH28F800SU_GSR_QUEUE_FULL_SHIFT)
#define LH28F800SU_GSR_BUFFER_AVAILABLE_SHIFT        2 /* established */
#define LH28F800SU_GSR_BUFFER_AVAILABLE_MASK         0x1u
#define LH28F800SU_GSR_BUFFER_AVAILABLE_INPLACE      (LH28F800SU_GSR_BUFFER_AVAILABLE_MASK << LH28F800SU_GSR_BUFFER_AVAILABLE_SHIFT)
#define LH28F800SU_GSR_BUFFER_READY_SHIFT            1 /* established */
#define LH28F800SU_GSR_BUFFER_READY_MASK             0x1u
#define LH28F800SU_GSR_BUFFER_READY_INPLACE          (LH28F800SU_GSR_BUFFER_READY_MASK << LH28F800SU_GSR_BUFFER_READY_SHIFT)
#define LH28F800SU_GSR_BUFFER_SELECT_SHIFT           0 /* established */
#define LH28F800SU_GSR_BUFFER_SELECT_MASK            0x1u
#define LH28F800SU_GSR_BUFFER_SELECT_INPLACE         (LH28F800SU_GSR_BUFFER_SELECT_MASK << LH28F800SU_GSR_BUFFER_SELECT_SHIFT)

#define LH28F800SU_LH28F800SU_ARRAY_BYTES            0x100000u /* established */
#define LH28F800SU_LH28F800SU_BLOCK_BYTES            0x10000u /* inferred */
#define LH28F800SU_LH28F800SU_BLOCK_COUNT            0x10u /* established */
#define LH28F800SU_LH28F800SU_BLOCK_ERASE_TYP_MS     0x2bcu /* established */
#define LH28F800SU_LH28F800SU_BLOCK_WORDS            0x8000u /* established */
#define LH28F800SU_LH28F800SU_CMD_BLOCK_LOCK         0x77u /* established */
#define LH28F800SU_LH28F800SU_CMD_CLEAR_STATUS       0x50u /* established */
#define LH28F800SU_LH28F800SU_CMD_CONFIRM            0xd0u /* established */
#define LH28F800SU_LH28F800SU_CMD_ERASE_SETUP        0x20u /* established */
#define LH28F800SU_LH28F800SU_CMD_EXT_STATUS         0x71u /* established */
#define LH28F800SU_LH28F800SU_CMD_IDENTIFY           0x90u /* established */
#define LH28F800SU_LH28F800SU_CMD_PROGRAM            0x40u /* established */
#define LH28F800SU_LH28F800SU_CMD_PROGRAM_ALT        0x10u /* established */
#define LH28F800SU_LH28F800SU_CMD_READ_ARRAY         0xffu /* established */
#define LH28F800SU_LH28F800SU_CMD_READ_STATUS        0x70u /* established */
#define LH28F800SU_LH28F800SU_CMD_SUSPEND            0xb0u /* established */
#define LH28F800SU_LH28F800SU_CMD_UPLOAD_STATUS      0x97u /* established */
#define LH28F800SU_LH28F800SU_ID_WORD0               0xb0u /* established */
#define LH28F800SU_LH28F800SU_ID_WORD1               0x66a8u /* established */
#define LH28F800SU_LH28F800SU_RP_RECOVERY_NS         0x190u /* established */
#define LH28F800SU_LH28F800SU_WORD_PROGRAM_TYP_US    0x8u /* established */

#endif /* LH28F800SU_GEN_H */
