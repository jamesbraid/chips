/* generated from devices/hub_ni/registers-extra.toml by defs-gen - do not edit, change the source */
/* Hub network interface field layouts, port and vector fields, and register offsets outside the census */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/* enum ni_node_mode */
#define HUB_NI_NODE_MODE_MORE_MEMORY                 0 /* established */
#define HUB_NI_NODE_MODE_MORE_NODES                  1 /* established */

/* enum ni_pio_request_type */
#define HUB_NI_PIO_REQUEST_TYPE_READ                 0 /* established */
#define HUB_NI_PIO_REQUEST_TYPE_WRITE                1 /* established */
#define HUB_NI_PIO_REQUEST_TYPE_UNDEFINED            2 /* established */
#define HUB_NI_PIO_REQUEST_TYPE_EXCHANGE             3 /* established */

/* enum ni_pio_type */
#define HUB_NI_PIO_TYPE_READ                         0 /* established */
#define HUB_NI_PIO_TYPE_WRITE                        1 /* established */
#define HUB_NI_PIO_TYPE_UNDEFINED                    2 /* established */
#define HUB_NI_PIO_TYPE_EXCHANGE                     3 /* established */
#define HUB_NI_PIO_TYPE_ADDRESS_ERROR                4 /* established */
#define HUB_NI_PIO_TYPE_COMMAND_ERROR                5 /* established */
#define HUB_NI_PIO_TYPE_PROTECTION_ERROR             6 /* established */
#define HUB_NI_PIO_TYPE_UNKNOWN                      7 /* established */

/* enum ni_region_size */
#define HUB_NI_REGION_SIZE_COARSE                    0 /* established */
#define HUB_NI_REGION_SIZE_FINE                      1 /* established */

/* enum ni_vchannel */
#define HUB_NI_VCHANNEL_CHANNEL_A                    0 /* established */
#define HUB_NI_VCHANNEL_CHANNEL_B                    1 /* established */
#define HUB_NI_VCHANNEL_ANY                          2 /* established */

/*
 * Return vector of a vector operation, named NI_RETURN_VECTOR in the header. The header gives no layout. Access is assumed read and write.
 */
/* ni_return_vector: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_RETURN_VECTOR_OFFSET                  0x600308u /* inferred */

/*
 * PIO protection bits, one per region, named NI_IO_PROTECT in the header. Offset and name are from the header. Access is assumed read and write; the header gives neither a field layout nor a reset.
 */
/* ni_io_protect: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_IO_PROTECT_OFFSET                     0x600400u /* inferred */

/*
 * PIO protection override, named NI_IO_PROT_OVRRD in the header. The header gives no unlock value or behaviour, so none is imported. Access is assumed write only.
 */
/* ni_io_prot_ovrrd: w64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_IO_PROT_OVRRD_OFFSET                  0x600408u /* inferred */

/*
 * CPU 0 PIO age control, named NI_AGE_CPU0_PIO in the header. Layout in NI_AGE_FORMAT. Access is assumed read and write.
 */
/* ni_age_cpu0_pio: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_CPU0_PIO_OFFSET                   0x600508u /* inferred */

/*
 * CPU 1 PIO age control, named NI_AGE_CPU1_PIO in the header. Layout in NI_AGE_FORMAT. Access is assumed read and write.
 */
/* ni_age_cpu1_pio: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_CPU1_PIO_OFFSET                   0x600518u /* inferred */

/*
 * Block-transfer engine memory age control, named NI_AGE_GBR_MEMORY in the header. Layout in NI_AGE_FORMAT. Access is assumed read and write.
 */
/* ni_age_gbr_memory: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_GBR_MEMORY_OFFSET                 0x600520u /* inferred */

/*
 * Block-transfer engine PIO age control, named NI_AGE_GBR_PIO in the header. Layout in NI_AGE_FORMAT. Access is assumed read and write.
 */
/* ni_age_gbr_pio: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_GBR_PIO_OFFSET                    0x600528u /* inferred */

/*
 * I/O interface memory age control, named NI_AGE_IO_MEMORY in the header. Layout in NI_AGE_FORMAT. Access is assumed read and write.
 */
/* ni_age_io_memory: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_IO_MEMORY_OFFSET                  0x600530u /* inferred */

/*
 * I/O interface PIO age control, named NI_AGE_IO_PIO in the header. Layout in NI_AGE_FORMAT. Access is assumed read and write.
 */
/* ni_age_io_pio: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_IO_PIO_OFFSET                     0x600538u /* inferred */

/*
 * Port parameters, named NI_PORT_PARMS in the header. Offset and name are from the header; access is assumed read and write. The fields are graded on their own.
 */
/* ni_port_parms: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_PORT_PARMS_OFFSET                     0x608000u /* inferred */
#define HUB_NI_PORT_PARMS_NULL_TIMEOUT_SHIFT         10 /* inferred */
#define HUB_NI_PORT_PARMS_NULL_TIMEOUT_MASK          0x3full
#define HUB_NI_PORT_PARMS_NULL_TIMEOUT_INPLACE       (HUB_NI_PORT_PARMS_NULL_TIMEOUT_MASK << HUB_NI_PORT_PARMS_NULL_TIMEOUT_SHIFT)
#define HUB_NI_PORT_PARMS_MAX_BURST_SHIFT            0 /* established */
#define HUB_NI_PORT_PARMS_MAX_BURST_MASK             0x3ffull
#define HUB_NI_PORT_PARMS_MAX_BURST_INPLACE          (HUB_NI_PORT_PARMS_MAX_BURST_MASK << HUB_NI_PORT_PARMS_MAX_BURST_SHIFT)

/*
 * Meta routing table entries 1 to 31, eight bytes apart from the census entry ni_meta_table0. The header gives the stride and the count of 32 entries. Access is assumed read and write. The entry width is not stated in the header and is not imported.
 */
/* ni_meta_entry: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_META_ENTRY_OFFSET                     0x638008u /* inferred */
#define HUB_NI_META_ENTRY_COUNT                      31
#define HUB_NI_META_ENTRY_STRIDE                     8

/*
 * Local routing table entries 1 to 15, eight bytes apart from the census entry ni_local_table0. The header gives the stride and the count of 16 entries. Access is assumed read and write. The entry width is not stated in the header and is not imported.
 */
/* ni_local_entry: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_LOCAL_ENTRY_OFFSET                    0x638108u /* inferred */
#define HUB_NI_LOCAL_ENTRY_COUNT                     15
#define HUB_NI_LOCAL_ENTRY_STRIDE                    8

/*
 * Layout of each of the eight ageing registers, ni_age_cpu0_memory through ni_age_io_pio. The census names two of them. The header gives the channel field its own names and no meaning for the congestion field.
 */
/* word NI_AGE_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names */
#define HUB_NI_AGE_FORMAT_WIDTH                      64 /* established */
#define HUB_NI_AGE_FORMAT_VCHANNEL_SHIFT             10 /* established */
#define HUB_NI_AGE_FORMAT_VCHANNEL_MASK              0x3ull
#define HUB_NI_AGE_FORMAT_VCHANNEL_INPLACE           (HUB_NI_AGE_FORMAT_VCHANNEL_MASK << HUB_NI_AGE_FORMAT_VCHANNEL_SHIFT)
#define HUB_NI_AGE_FORMAT_CONGESTION_SHIFT           8 /* established */
#define HUB_NI_AGE_FORMAT_CONGESTION_MASK            0x3ull
#define HUB_NI_AGE_FORMAT_CONGESTION_INPLACE         (HUB_NI_AGE_FORMAT_CONGESTION_MASK << HUB_NI_AGE_FORMAT_CONGESTION_SHIFT)
#define HUB_NI_AGE_FORMAT_AGE_SHIFT                  0 /* established */
#define HUB_NI_AGE_FORMAT_AGE_MASK                   0xffull
#define HUB_NI_AGE_FORMAT_AGE_INPLACE                (HUB_NI_AGE_FORMAT_AGE_MASK << HUB_NI_AGE_FORMAT_AGE_SHIFT)

/*
 * Layout of the diagnostic parameters register, ni_diag_parms. The header names each bit and gives no further behaviour.
 */
/* word NI_DIAG_PARMS_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NDP_* masks */
#define HUB_NI_DIAG_PARMS_FORMAT_WIDTH               64 /* established */
#define HUB_NI_DIAG_PARMS_FORMAT_PORT_TIMEOUT_RESET_SHIFT 18 /* established */
#define HUB_NI_DIAG_PARMS_FORMAT_PORT_TIMEOUT_RESET_MASK 0x1ull
#define HUB_NI_DIAG_PARMS_FORMAT_PORT_TIMEOUT_RESET_INPLACE (HUB_NI_DIAG_PARMS_FORMAT_PORT_TIMEOUT_RESET_MASK << HUB_NI_DIAG_PARMS_FORMAT_PORT_TIMEOUT_RESET_SHIFT)
#define HUB_NI_DIAG_PARMS_FORMAT_LLP_8BIT_MODE_SHIFT 12 /* established */
#define HUB_NI_DIAG_PARMS_FORMAT_LLP_8BIT_MODE_MASK  0x1ull
#define HUB_NI_DIAG_PARMS_FORMAT_LLP_8BIT_MODE_INPLACE (HUB_NI_DIAG_PARMS_FORMAT_LLP_8BIT_MODE_MASK << HUB_NI_DIAG_PARMS_FORMAT_LLP_8BIT_MODE_SHIFT)
#define HUB_NI_DIAG_PARMS_FORMAT_PORT_DISABLE_SHIFT  6 /* established */
#define HUB_NI_DIAG_PARMS_FORMAT_PORT_DISABLE_MASK   0x1ull
#define HUB_NI_DIAG_PARMS_FORMAT_PORT_DISABLE_INPLACE (HUB_NI_DIAG_PARMS_FORMAT_PORT_DISABLE_MASK << HUB_NI_DIAG_PARMS_FORMAT_PORT_DISABLE_SHIFT)
#define HUB_NI_DIAG_PARMS_FORMAT_SEND_ERROR_SHIFT    0 /* established */
#define HUB_NI_DIAG_PARMS_FORMAT_SEND_ERROR_MASK     0x1ull
#define HUB_NI_DIAG_PARMS_FORMAT_SEND_ERROR_INPLACE  (HUB_NI_DIAG_PARMS_FORMAT_SEND_ERROR_MASK << HUB_NI_DIAG_PARMS_FORMAT_SEND_ERROR_SHIFT)

/*
 * Layout of the global link parameters register, ni_global_parms. The header's comment on the credit-timeout field repeats the wording of the field above it; the name used here is the mask's own name.
 */
/* word NI_GLOBAL_PARMS_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NGP_* masks and shifts */
#define HUB_NI_GLOBAL_PARMS_FORMAT_WIDTH             64 /* established */
#define HUB_NI_GLOBAL_PARMS_FORMAT_MAX_RETRY_SHIFT   48 /* established */
#define HUB_NI_GLOBAL_PARMS_FORMAT_MAX_RETRY_MASK    0x3ffull
#define HUB_NI_GLOBAL_PARMS_FORMAT_MAX_RETRY_INPLACE (HUB_NI_GLOBAL_PARMS_FORMAT_MAX_RETRY_MASK << HUB_NI_GLOBAL_PARMS_FORMAT_MAX_RETRY_SHIFT)
#define HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_WRAP_SHIFT 32 /* established */
#define HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_WRAP_MASK 0xffffull
#define HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_WRAP_INPLACE (HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_WRAP_MASK << HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_WRAP_SHIFT)
#define HUB_NI_GLOBAL_PARMS_FORMAT_CREDIT_TIMEOUT_SHIFT 16 /* established */
#define HUB_NI_GLOBAL_PARMS_FORMAT_CREDIT_TIMEOUT_MASK 0xfull
#define HUB_NI_GLOBAL_PARMS_FORMAT_CREDIT_TIMEOUT_INPLACE (HUB_NI_GLOBAL_PARMS_FORMAT_CREDIT_TIMEOUT_MASK << HUB_NI_GLOBAL_PARMS_FORMAT_CREDIT_TIMEOUT_SHIFT)
#define HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_SHIFT 4 /* established */
#define HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_MASK 0xfull
#define HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_INPLACE (HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_MASK << HUB_NI_GLOBAL_PARMS_FORMAT_TAIL_TIMEOUT_SHIFT)

/*
 * Layout of the port error register, ni_port_error, and of its clearing alias, ni_port_error_clear. Bit 32 is outside the header's error mask and has no name.
 */
/* word NI_PORT_ERROR_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NPE_* masks and shifts */
#define HUB_NI_PORT_ERROR_FORMAT_WIDTH               64 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_LINK_RESET_SHIFT    37 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_LINK_RESET_MASK     0x1ull
#define HUB_NI_PORT_ERROR_FORMAT_LINK_RESET_INPLACE  (HUB_NI_PORT_ERROR_FORMAT_LINK_RESET_MASK << HUB_NI_PORT_ERROR_FORMAT_LINK_RESET_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_INTERNAL_ERROR_SHIFT 36 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_INTERNAL_ERROR_MASK 0x1ull
#define HUB_NI_PORT_ERROR_FORMAT_INTERNAL_ERROR_INPLACE (HUB_NI_PORT_ERROR_FORMAT_INTERNAL_ERROR_MASK << HUB_NI_PORT_ERROR_FORMAT_INTERNAL_ERROR_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_BAD_MESSAGE_SHIFT   35 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_BAD_MESSAGE_MASK    0x1ull
#define HUB_NI_PORT_ERROR_FORMAT_BAD_MESSAGE_INPLACE (HUB_NI_PORT_ERROR_FORMAT_BAD_MESSAGE_MASK << HUB_NI_PORT_ERROR_FORMAT_BAD_MESSAGE_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_BAD_DESTINATION_SHIFT 34 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_BAD_DESTINATION_MASK 0x1ull
#define HUB_NI_PORT_ERROR_FORMAT_BAD_DESTINATION_INPLACE (HUB_NI_PORT_ERROR_FORMAT_BAD_DESTINATION_MASK << HUB_NI_PORT_ERROR_FORMAT_BAD_DESTINATION_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_QUEUE_OVERFLOW_SHIFT 33 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_QUEUE_OVERFLOW_MASK 0x1ull
#define HUB_NI_PORT_ERROR_FORMAT_QUEUE_OVERFLOW_INPLACE (HUB_NI_PORT_ERROR_FORMAT_QUEUE_OVERFLOW_MASK << HUB_NI_PORT_ERROR_FORMAT_QUEUE_OVERFLOW_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_CREDIT_TIMEOUT_COUNT_SHIFT 28 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_CREDIT_TIMEOUT_COUNT_MASK 0xfull
#define HUB_NI_PORT_ERROR_FORMAT_CREDIT_TIMEOUT_COUNT_INPLACE (HUB_NI_PORT_ERROR_FORMAT_CREDIT_TIMEOUT_COUNT_MASK << HUB_NI_PORT_ERROR_FORMAT_CREDIT_TIMEOUT_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_TAIL_TIMEOUT_COUNT_SHIFT 24 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_TAIL_TIMEOUT_COUNT_MASK 0xfull
#define HUB_NI_PORT_ERROR_FORMAT_TAIL_TIMEOUT_COUNT_INPLACE (HUB_NI_PORT_ERROR_FORMAT_TAIL_TIMEOUT_COUNT_MASK << HUB_NI_PORT_ERROR_FORMAT_TAIL_TIMEOUT_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_RETRY_COUNT_SHIFT   16 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_RETRY_COUNT_MASK    0xffull
#define HUB_NI_PORT_ERROR_FORMAT_RETRY_COUNT_INPLACE (HUB_NI_PORT_ERROR_FORMAT_RETRY_COUNT_MASK << HUB_NI_PORT_ERROR_FORMAT_RETRY_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_CHECK_BIT_ERROR_COUNT_SHIFT 8 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_CHECK_BIT_ERROR_COUNT_MASK 0xffull
#define HUB_NI_PORT_ERROR_FORMAT_CHECK_BIT_ERROR_COUNT_INPLACE (HUB_NI_PORT_ERROR_FORMAT_CHECK_BIT_ERROR_COUNT_MASK << HUB_NI_PORT_ERROR_FORMAT_CHECK_BIT_ERROR_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_FORMAT_SEQUENCE_ERROR_COUNT_SHIFT 0 /* established */
#define HUB_NI_PORT_ERROR_FORMAT_SEQUENCE_ERROR_COUNT_MASK 0xffull
#define HUB_NI_PORT_ERROR_FORMAT_SEQUENCE_ERROR_COUNT_INPLACE (HUB_NI_PORT_ERROR_FORMAT_SEQUENCE_ERROR_COUNT_MASK << HUB_NI_PORT_ERROR_FORMAT_SEQUENCE_ERROR_COUNT_SHIFT)

/*
 * Layout of the port reset register, ni_port_reset. The register is written, not read back; the header gives no read value.
 */
/* word NI_PORT_RESET_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NPR_* masks */
#define HUB_NI_PORT_RESET_FORMAT_WIDTH               64 /* established */
#define HUB_NI_PORT_RESET_FORMAT_WARM_RESET_SHIFT    7 /* established */
#define HUB_NI_PORT_RESET_FORMAT_WARM_RESET_MASK     0x1ull
#define HUB_NI_PORT_RESET_FORMAT_WARM_RESET_INPLACE  (HUB_NI_PORT_RESET_FORMAT_WARM_RESET_MASK << HUB_NI_PORT_RESET_FORMAT_WARM_RESET_SHIFT)
#define HUB_NI_PORT_RESET_FORMAT_LINK_RESET_SHIFT    1 /* established */
#define HUB_NI_PORT_RESET_FORMAT_LINK_RESET_MASK     0x1ull
#define HUB_NI_PORT_RESET_FORMAT_LINK_RESET_INPLACE  (HUB_NI_PORT_RESET_FORMAT_LINK_RESET_MASK << HUB_NI_PORT_RESET_FORMAT_LINK_RESET_SHIFT)
#define HUB_NI_PORT_RESET_FORMAT_LOCAL_RESET_SHIFT   0 /* established */
#define HUB_NI_PORT_RESET_FORMAT_LOCAL_RESET_MASK    0x1ull
#define HUB_NI_PORT_RESET_FORMAT_LOCAL_RESET_INPLACE (HUB_NI_PORT_RESET_FORMAT_LOCAL_RESET_MASK << HUB_NI_PORT_RESET_FORMAT_LOCAL_RESET_SHIFT)

/*
 * Layout of the protection configuration register, ni_protection.
 */
/* word NI_PROTECTION_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NPROT_RESETOK */
#define HUB_NI_PROTECTION_FORMAT_WIDTH               64 /* established */
#define HUB_NI_PROTECTION_FORMAT_RESET_OK_SHIFT      0 /* established */
#define HUB_NI_PROTECTION_FORMAT_RESET_OK_MASK       0x1ull
#define HUB_NI_PROTECTION_FORMAT_RESET_OK_INPLACE    (HUB_NI_PROTECTION_FORMAT_RESET_OK_MASK << HUB_NI_PROTECTION_FORMAT_RESET_OK_SHIFT)

/*
 * Layout of the status, revision and identity register, ni_status_rev_id. The header names the port status bits separately; this word uses the same names. The census of the shipped IRIX Origin 200/2000 kernel (the census field table) shows the register read with a shift of 8 and a nine-bit mask for the node number, a shift of 4 for the chip revision and a test of bit 17 for the region size; the header's layout agrees.
 */
/* word NI_STATUS_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NSRI_* masks and shifts */
#define HUB_NI_STATUS_FORMAT_WIDTH                   64 /* established */
#define HUB_NI_STATUS_FORMAT_EIGHTBIT_MODE_SHIFT     30 /* established */
#define HUB_NI_STATUS_FORMAT_EIGHTBIT_MODE_MASK      0x1ull
#define HUB_NI_STATUS_FORMAT_EIGHTBIT_MODE_INPLACE   (HUB_NI_STATUS_FORMAT_EIGHTBIT_MODE_MASK << HUB_NI_STATUS_FORMAT_EIGHTBIT_MODE_SHIFT)
#define HUB_NI_STATUS_FORMAT_LINK_UP_SHIFT           29 /* established */
#define HUB_NI_STATUS_FORMAT_LINK_UP_MASK            0x1ull
#define HUB_NI_STATUS_FORMAT_LINK_UP_INPLACE         (HUB_NI_STATUS_FORMAT_LINK_UP_MASK << HUB_NI_STATUS_FORMAT_LINK_UP_SHIFT)
#define HUB_NI_STATUS_FORMAT_DOWN_REASON_SHIFT       28 /* established */
#define HUB_NI_STATUS_FORMAT_DOWN_REASON_MASK        0x1ull
#define HUB_NI_STATUS_FORMAT_DOWN_REASON_INPLACE     (HUB_NI_STATUS_FORMAT_DOWN_REASON_MASK << HUB_NI_STATUS_FORMAT_DOWN_REASON_SHIFT)
#define HUB_NI_STATUS_FORMAT_MORE_NODES_SHIFT        18 /* established */
#define HUB_NI_STATUS_FORMAT_MORE_NODES_MASK         0x1ull
#define HUB_NI_STATUS_FORMAT_MORE_NODES_INPLACE      (HUB_NI_STATUS_FORMAT_MORE_NODES_MASK << HUB_NI_STATUS_FORMAT_MORE_NODES_SHIFT)
#define HUB_NI_STATUS_FORMAT_REGION_SIZE_SHIFT       17 /* established */
#define HUB_NI_STATUS_FORMAT_REGION_SIZE_MASK        0x1ull
#define HUB_NI_STATUS_FORMAT_REGION_SIZE_INPLACE     (HUB_NI_STATUS_FORMAT_REGION_SIZE_MASK << HUB_NI_STATUS_FORMAT_REGION_SIZE_SHIFT)
#define HUB_NI_STATUS_FORMAT_NODE_ID_SHIFT           8 /* established */
#define HUB_NI_STATUS_FORMAT_NODE_ID_MASK            0x1ffull
#define HUB_NI_STATUS_FORMAT_NODE_ID_INPLACE         (HUB_NI_STATUS_FORMAT_NODE_ID_MASK << HUB_NI_STATUS_FORMAT_NODE_ID_SHIFT)
#define HUB_NI_STATUS_FORMAT_CHIP_REV_SHIFT          4 /* established */
#define HUB_NI_STATUS_FORMAT_CHIP_REV_MASK           0xfull
#define HUB_NI_STATUS_FORMAT_CHIP_REV_INPLACE        (HUB_NI_STATUS_FORMAT_CHIP_REV_MASK << HUB_NI_STATUS_FORMAT_CHIP_REV_SHIFT)
#define HUB_NI_STATUS_FORMAT_CHIP_ID_SHIFT           0 /* established */
#define HUB_NI_STATUS_FORMAT_CHIP_ID_MASK            0xfull
#define HUB_NI_STATUS_FORMAT_CHIP_ID_INPLACE         (HUB_NI_STATUS_FORMAT_CHIP_ID_MASK << HUB_NI_STATUS_FORMAT_CHIP_ID_SHIFT)

/*
 * Layout of the vector routing parameters register, ni_vector_parms. The header's identifier mask covers bits 49:40. Other sources put the top bit of that field at 50; this layout follows the public header.
 */
/* word NI_VECTOR_PARMS_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NVP_* masks and shifts */
#define HUB_NI_VECTOR_PARMS_FORMAT_WIDTH             64 /* established */
#define HUB_NI_VECTOR_PARMS_FORMAT_PIO_ID_SHIFT      40 /* established */
#define HUB_NI_VECTOR_PARMS_FORMAT_PIO_ID_MASK       0x3ffull
#define HUB_NI_VECTOR_PARMS_FORMAT_PIO_ID_INPLACE    (HUB_NI_VECTOR_PARMS_FORMAT_PIO_ID_MASK << HUB_NI_VECTOR_PARMS_FORMAT_PIO_ID_SHIFT)
#define HUB_NI_VECTOR_PARMS_FORMAT_WRITE_ID_SHIFT    32 /* established */
#define HUB_NI_VECTOR_PARMS_FORMAT_WRITE_ID_MASK     0xffull
#define HUB_NI_VECTOR_PARMS_FORMAT_WRITE_ID_INPLACE  (HUB_NI_VECTOR_PARMS_FORMAT_WRITE_ID_MASK << HUB_NI_VECTOR_PARMS_FORMAT_WRITE_ID_SHIFT)
#define HUB_NI_VECTOR_PARMS_FORMAT_ADDRESS_SHIFT     3 /* established */
#define HUB_NI_VECTOR_PARMS_FORMAT_ADDRESS_MASK      0x1ffffull
#define HUB_NI_VECTOR_PARMS_FORMAT_ADDRESS_INPLACE   (HUB_NI_VECTOR_PARMS_FORMAT_ADDRESS_MASK << HUB_NI_VECTOR_PARMS_FORMAT_ADDRESS_SHIFT)
#define HUB_NI_VECTOR_PARMS_FORMAT_PIO_TYPE_SHIFT    0 /* established */
#define HUB_NI_VECTOR_PARMS_FORMAT_PIO_TYPE_MASK     0x3ull
#define HUB_NI_VECTOR_PARMS_FORMAT_PIO_TYPE_INPLACE  (HUB_NI_VECTOR_PARMS_FORMAT_PIO_TYPE_MASK << HUB_NI_VECTOR_PARMS_FORMAT_PIO_TYPE_SHIFT)

/*
 * Layout of the vector routing status register, ni_vector_status. The source field is ten bits in the header (60:51). Another source gives it eleven bits (61:51); this layout follows the public header.
 */
/* word NI_VECTOR_STATUS_FORMAT: 64 bits; public Linux SN0 Hub network interface header: NVS_* masks and shifts */
#define HUB_NI_VECTOR_STATUS_FORMAT_WIDTH            64 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_VALID_SHIFT      63 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_VALID_MASK       0x1ull
#define HUB_NI_VECTOR_STATUS_FORMAT_VALID_INPLACE    (HUB_NI_VECTOR_STATUS_FORMAT_VALID_MASK << HUB_NI_VECTOR_STATUS_FORMAT_VALID_SHIFT)
#define HUB_NI_VECTOR_STATUS_FORMAT_OVERRUN_SHIFT    62 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_OVERRUN_MASK     0x1ull
#define HUB_NI_VECTOR_STATUS_FORMAT_OVERRUN_INPLACE  (HUB_NI_VECTOR_STATUS_FORMAT_OVERRUN_MASK << HUB_NI_VECTOR_STATUS_FORMAT_OVERRUN_SHIFT)
#define HUB_NI_VECTOR_STATUS_FORMAT_TARGET_SHIFT     51 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_TARGET_MASK      0x3ffull
#define HUB_NI_VECTOR_STATUS_FORMAT_TARGET_INPLACE   (HUB_NI_VECTOR_STATUS_FORMAT_TARGET_MASK << HUB_NI_VECTOR_STATUS_FORMAT_TARGET_SHIFT)
#define HUB_NI_VECTOR_STATUS_FORMAT_PIO_ID_SHIFT     40 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_PIO_ID_MASK      0x3ffull
#define HUB_NI_VECTOR_STATUS_FORMAT_PIO_ID_INPLACE   (HUB_NI_VECTOR_STATUS_FORMAT_PIO_ID_MASK << HUB_NI_VECTOR_STATUS_FORMAT_PIO_ID_SHIFT)
#define HUB_NI_VECTOR_STATUS_FORMAT_WRITE_ID_SHIFT   32 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_WRITE_ID_MASK    0xffull
#define HUB_NI_VECTOR_STATUS_FORMAT_WRITE_ID_INPLACE (HUB_NI_VECTOR_STATUS_FORMAT_WRITE_ID_MASK << HUB_NI_VECTOR_STATUS_FORMAT_WRITE_ID_SHIFT)
#define HUB_NI_VECTOR_STATUS_FORMAT_ADDRESS_SHIFT    3 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_ADDRESS_MASK     0x1fffffffull
#define HUB_NI_VECTOR_STATUS_FORMAT_ADDRESS_INPLACE  (HUB_NI_VECTOR_STATUS_FORMAT_ADDRESS_MASK << HUB_NI_VECTOR_STATUS_FORMAT_ADDRESS_SHIFT)
#define HUB_NI_VECTOR_STATUS_FORMAT_PIO_TYPE_SHIFT   0 /* established */
#define HUB_NI_VECTOR_STATUS_FORMAT_PIO_TYPE_MASK    0x7ull
#define HUB_NI_VECTOR_STATUS_FORMAT_PIO_TYPE_INPLACE (HUB_NI_VECTOR_STATUS_FORMAT_PIO_TYPE_MASK << HUB_NI_VECTOR_STATUS_FORMAT_PIO_TYPE_SHIFT)

#define HUB_NI_LOCAL_ENTRIES                         0x10u /* established */
#define HUB_NI_META_ENTRIES                          0x20u /* established */
#define HUB_NI_PORT_ERROR_COUNT_MAX                  0xffu /* established */
#define HUB_NI_PORT_PARMS_DEFAULTS                   0x1bf0u /* inferred */
#define HUB_NI_PORT_PARMS_HUB20_DEFAULTS             0x7f0u /* inferred */

#endif /* HUB_GEN_H */
