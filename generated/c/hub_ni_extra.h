/* generated from devices/hub_ni/registers-extra.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 491bd24195abfc81c22b65262321f9a32808de8e8b25ffb6d0b0aa6ce3827496 */
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
 * Layout of the status, revision and identity register, ni_status_rev_id. The header names the port status bits separately; this word uses the same names. The census of the shipped IRIX Origin 200/2000 kernel (the census field table) shows the register read with a shift of 8 and a nine-bit mask for the node number, a shift of 4 for the chip revision and a test of bit 17 for the region size; the header's layout agrees.
 */
/* ni_status_rev_id: r64, reset 0x20020; census: 18 sites, 16 routines (r); census: 5 sites, 4 routines (r, indexed) */
#define HUB_NI_STATUS_REV_ID_OFFSET                  0x600000u /* established */
#define HUB_NI_STATUS_REV_ID_EIGHTBIT_MODE_SHIFT     30 /* established */
#define HUB_NI_STATUS_REV_ID_EIGHTBIT_MODE_MASK      0x1ull
#define HUB_NI_STATUS_REV_ID_EIGHTBIT_MODE_INPLACE   (HUB_NI_STATUS_REV_ID_EIGHTBIT_MODE_MASK << HUB_NI_STATUS_REV_ID_EIGHTBIT_MODE_SHIFT)
#define HUB_NI_STATUS_REV_ID_LINK_UP_SHIFT           29 /* established */
#define HUB_NI_STATUS_REV_ID_LINK_UP_MASK            0x1ull
#define HUB_NI_STATUS_REV_ID_LINK_UP_INPLACE         (HUB_NI_STATUS_REV_ID_LINK_UP_MASK << HUB_NI_STATUS_REV_ID_LINK_UP_SHIFT)
#define HUB_NI_STATUS_REV_ID_DOWN_REASON_SHIFT       28 /* established */
#define HUB_NI_STATUS_REV_ID_DOWN_REASON_MASK        0x1ull
#define HUB_NI_STATUS_REV_ID_DOWN_REASON_INPLACE     (HUB_NI_STATUS_REV_ID_DOWN_REASON_MASK << HUB_NI_STATUS_REV_ID_DOWN_REASON_SHIFT)
#define HUB_NI_STATUS_REV_ID_MORE_NODES_SHIFT        18 /* established */
#define HUB_NI_STATUS_REV_ID_MORE_NODES_MASK         0x1ull
#define HUB_NI_STATUS_REV_ID_MORE_NODES_INPLACE      (HUB_NI_STATUS_REV_ID_MORE_NODES_MASK << HUB_NI_STATUS_REV_ID_MORE_NODES_SHIFT)
#define HUB_NI_STATUS_REV_ID_REGION_SIZE_SHIFT       17 /* established */
#define HUB_NI_STATUS_REV_ID_REGION_SIZE_MASK        0x1ull
#define HUB_NI_STATUS_REV_ID_REGION_SIZE_INPLACE     (HUB_NI_STATUS_REV_ID_REGION_SIZE_MASK << HUB_NI_STATUS_REV_ID_REGION_SIZE_SHIFT)
#define HUB_NI_STATUS_REV_ID_NODE_ID_SHIFT           8 /* established */
#define HUB_NI_STATUS_REV_ID_NODE_ID_MASK            0x1ffull
#define HUB_NI_STATUS_REV_ID_NODE_ID_INPLACE         (HUB_NI_STATUS_REV_ID_NODE_ID_MASK << HUB_NI_STATUS_REV_ID_NODE_ID_SHIFT)
#define HUB_NI_STATUS_REV_ID_CHIP_REV_SHIFT          4 /* established */
#define HUB_NI_STATUS_REV_ID_CHIP_REV_MASK           0xfull
#define HUB_NI_STATUS_REV_ID_CHIP_REV_INPLACE        (HUB_NI_STATUS_REV_ID_CHIP_REV_MASK << HUB_NI_STATUS_REV_ID_CHIP_REV_SHIFT)
#define HUB_NI_STATUS_REV_ID_CHIP_ID_SHIFT           0 /* established */
#define HUB_NI_STATUS_REV_ID_CHIP_ID_MASK            0xfull
#define HUB_NI_STATUS_REV_ID_CHIP_ID_INPLACE         (HUB_NI_STATUS_REV_ID_CHIP_ID_MASK << HUB_NI_STATUS_REV_ID_CHIP_ID_SHIFT)

/*
 * Layout of the port reset register, ni_port_reset. The register is written, not read back; the header gives no read value.
 */
/* ni_port_reset: w64, reset unknown; census: 6 sites, 6 routines */
#define HUB_NI_PORT_RESET_OFFSET                     0x600008u /* established */
#define HUB_NI_PORT_RESET_WARM_RESET_SHIFT           7 /* established */
#define HUB_NI_PORT_RESET_WARM_RESET_MASK            0x1ull
#define HUB_NI_PORT_RESET_WARM_RESET_INPLACE         (HUB_NI_PORT_RESET_WARM_RESET_MASK << HUB_NI_PORT_RESET_WARM_RESET_SHIFT)
#define HUB_NI_PORT_RESET_LINK_RESET_SHIFT           1 /* established */
#define HUB_NI_PORT_RESET_LINK_RESET_MASK            0x1ull
#define HUB_NI_PORT_RESET_LINK_RESET_INPLACE         (HUB_NI_PORT_RESET_LINK_RESET_MASK << HUB_NI_PORT_RESET_LINK_RESET_SHIFT)
#define HUB_NI_PORT_RESET_LOCAL_RESET_SHIFT          0 /* established */
#define HUB_NI_PORT_RESET_LOCAL_RESET_MASK           0x1ull
#define HUB_NI_PORT_RESET_LOCAL_RESET_INPLACE        (HUB_NI_PORT_RESET_LOCAL_RESET_MASK << HUB_NI_PORT_RESET_LOCAL_RESET_SHIFT)

/*
 * Layout of the protection configuration register, ni_protection.
 */
/* ni_protection: r64, reset 0x1; census: 3 sites, 2 routines */
#define HUB_NI_PROTECTION_OFFSET                     0x600010u /* established */
#define HUB_NI_PROTECTION_RESET_OK_SHIFT             0 /* established */
#define HUB_NI_PROTECTION_RESET_OK_MASK              0x1ull
#define HUB_NI_PROTECTION_RESET_OK_INPLACE           (HUB_NI_PROTECTION_RESET_OK_MASK << HUB_NI_PROTECTION_RESET_OK_SHIFT)

/*
 * Layout of the global link parameters register, ni_global_parms. The header's comment on the credit-timeout field repeats the wording of the field above it; the name used here is the mask's own name.
 */
/* ni_global_parms: rw64, reset 0x3fffffe000f00f0; census: 2 sites, 1 routines */
#define HUB_NI_GLOBAL_PARMS_OFFSET                   0x600018u /* established */
#define HUB_NI_GLOBAL_PARMS_MAX_RETRY_SHIFT          48 /* established */
#define HUB_NI_GLOBAL_PARMS_MAX_RETRY_MASK           0x3ffull
#define HUB_NI_GLOBAL_PARMS_MAX_RETRY_INPLACE        (HUB_NI_GLOBAL_PARMS_MAX_RETRY_MASK << HUB_NI_GLOBAL_PARMS_MAX_RETRY_SHIFT)
#define HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_WRAP_SHIFT  32 /* established */
#define HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_WRAP_MASK   0xffffull
#define HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_WRAP_INPLACE (HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_WRAP_MASK << HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_WRAP_SHIFT)
#define HUB_NI_GLOBAL_PARMS_CREDIT_TIMEOUT_SHIFT     16 /* established */
#define HUB_NI_GLOBAL_PARMS_CREDIT_TIMEOUT_MASK      0xfull
#define HUB_NI_GLOBAL_PARMS_CREDIT_TIMEOUT_INPLACE   (HUB_NI_GLOBAL_PARMS_CREDIT_TIMEOUT_MASK << HUB_NI_GLOBAL_PARMS_CREDIT_TIMEOUT_SHIFT)
#define HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_SHIFT       4 /* established */
#define HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_MASK        0xfull
#define HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_INPLACE     (HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_MASK << HUB_NI_GLOBAL_PARMS_TAIL_TIMEOUT_SHIFT)

/*
 * Layout of the diagnostic parameters register, ni_diag_parms. The header names each bit and gives no further behaviour.
 */
/* ni_diag_parms: rw64, reset unknown; census: 2 sites, 1 routines (rw); census: 2 sites, 1 routines (rw, indexed) */
#define HUB_NI_DIAG_PARMS_OFFSET                     0x600110u /* established */
#define HUB_NI_DIAG_PARMS_PORT_TIMEOUT_RESET_SHIFT   18 /* established */
#define HUB_NI_DIAG_PARMS_PORT_TIMEOUT_RESET_MASK    0x1ull
#define HUB_NI_DIAG_PARMS_PORT_TIMEOUT_RESET_INPLACE (HUB_NI_DIAG_PARMS_PORT_TIMEOUT_RESET_MASK << HUB_NI_DIAG_PARMS_PORT_TIMEOUT_RESET_SHIFT)
#define HUB_NI_DIAG_PARMS_LLP_8BIT_MODE_SHIFT        12 /* established */
#define HUB_NI_DIAG_PARMS_LLP_8BIT_MODE_MASK         0x1ull
#define HUB_NI_DIAG_PARMS_LLP_8BIT_MODE_INPLACE      (HUB_NI_DIAG_PARMS_LLP_8BIT_MODE_MASK << HUB_NI_DIAG_PARMS_LLP_8BIT_MODE_SHIFT)
#define HUB_NI_DIAG_PARMS_PORT_DISABLE_SHIFT         6 /* established */
#define HUB_NI_DIAG_PARMS_PORT_DISABLE_MASK          0x1ull
#define HUB_NI_DIAG_PARMS_PORT_DISABLE_INPLACE       (HUB_NI_DIAG_PARMS_PORT_DISABLE_MASK << HUB_NI_DIAG_PARMS_PORT_DISABLE_SHIFT)
#define HUB_NI_DIAG_PARMS_SEND_ERROR_SHIFT           0 /* established */
#define HUB_NI_DIAG_PARMS_SEND_ERROR_MASK            0x1ull
#define HUB_NI_DIAG_PARMS_SEND_ERROR_INPLACE         (HUB_NI_DIAG_PARMS_SEND_ERROR_MASK << HUB_NI_DIAG_PARMS_SEND_ERROR_SHIFT)

/*
 * Layout of the vector routing parameters register, ni_vector_parms. The header's identifier mask covers bits 49:40. Other sources put the top bit of that field at 50; this layout follows the public header.
 */
/* ni_vector_parms: w64, reset unknown; census: 3 sites, 3 routines */
#define HUB_NI_VECTOR_PARMS_OFFSET                   0x600200u /* established */
#define HUB_NI_VECTOR_PARMS_PIO_ID_SHIFT             40 /* established */
#define HUB_NI_VECTOR_PARMS_PIO_ID_MASK              0x3ffull
#define HUB_NI_VECTOR_PARMS_PIO_ID_INPLACE           (HUB_NI_VECTOR_PARMS_PIO_ID_MASK << HUB_NI_VECTOR_PARMS_PIO_ID_SHIFT)
#define HUB_NI_VECTOR_PARMS_WRITE_ID_SHIFT           32 /* established */
#define HUB_NI_VECTOR_PARMS_WRITE_ID_MASK            0xffull
#define HUB_NI_VECTOR_PARMS_WRITE_ID_INPLACE         (HUB_NI_VECTOR_PARMS_WRITE_ID_MASK << HUB_NI_VECTOR_PARMS_WRITE_ID_SHIFT)
#define HUB_NI_VECTOR_PARMS_ADDRESS_SHIFT            3 /* established */
#define HUB_NI_VECTOR_PARMS_ADDRESS_MASK             0x1ffffull
#define HUB_NI_VECTOR_PARMS_ADDRESS_INPLACE          (HUB_NI_VECTOR_PARMS_ADDRESS_MASK << HUB_NI_VECTOR_PARMS_ADDRESS_SHIFT)
#define HUB_NI_VECTOR_PARMS_PIO_TYPE_SHIFT           0 /* established */
#define HUB_NI_VECTOR_PARMS_PIO_TYPE_MASK            0x3ull
#define HUB_NI_VECTOR_PARMS_PIO_TYPE_INPLACE         (HUB_NI_VECTOR_PARMS_PIO_TYPE_MASK << HUB_NI_VECTOR_PARMS_PIO_TYPE_SHIFT)

/*
 * Layout of the vector routing status register, ni_vector_status. The source field is ten bits in the header (60:51). Another source gives it eleven bits (61:51); this layout follows the public header.
 */
/* ni_vector_status: r64, reset unknown; census: 1 sites, 1 routines (r); census: 7 sites, 3 routines (r, indexed) */
#define HUB_NI_VECTOR_STATUS_OFFSET                  0x600300u /* established */
#define HUB_NI_VECTOR_STATUS_VALID_SHIFT             63 /* established */
#define HUB_NI_VECTOR_STATUS_VALID_MASK              0x1ull
#define HUB_NI_VECTOR_STATUS_VALID_INPLACE           (HUB_NI_VECTOR_STATUS_VALID_MASK << HUB_NI_VECTOR_STATUS_VALID_SHIFT)
#define HUB_NI_VECTOR_STATUS_OVERRUN_SHIFT           62 /* established */
#define HUB_NI_VECTOR_STATUS_OVERRUN_MASK            0x1ull
#define HUB_NI_VECTOR_STATUS_OVERRUN_INPLACE         (HUB_NI_VECTOR_STATUS_OVERRUN_MASK << HUB_NI_VECTOR_STATUS_OVERRUN_SHIFT)
#define HUB_NI_VECTOR_STATUS_TARGET_SHIFT            51 /* established */
#define HUB_NI_VECTOR_STATUS_TARGET_MASK             0x3ffull
#define HUB_NI_VECTOR_STATUS_TARGET_INPLACE          (HUB_NI_VECTOR_STATUS_TARGET_MASK << HUB_NI_VECTOR_STATUS_TARGET_SHIFT)
#define HUB_NI_VECTOR_STATUS_PIO_ID_SHIFT            40 /* established */
#define HUB_NI_VECTOR_STATUS_PIO_ID_MASK             0x3ffull
#define HUB_NI_VECTOR_STATUS_PIO_ID_INPLACE          (HUB_NI_VECTOR_STATUS_PIO_ID_MASK << HUB_NI_VECTOR_STATUS_PIO_ID_SHIFT)
#define HUB_NI_VECTOR_STATUS_WRITE_ID_SHIFT          32 /* established */
#define HUB_NI_VECTOR_STATUS_WRITE_ID_MASK           0xffull
#define HUB_NI_VECTOR_STATUS_WRITE_ID_INPLACE        (HUB_NI_VECTOR_STATUS_WRITE_ID_MASK << HUB_NI_VECTOR_STATUS_WRITE_ID_SHIFT)
#define HUB_NI_VECTOR_STATUS_ADDRESS_SHIFT           3 /* established */
#define HUB_NI_VECTOR_STATUS_ADDRESS_MASK            0x1fffffffull
#define HUB_NI_VECTOR_STATUS_ADDRESS_INPLACE         (HUB_NI_VECTOR_STATUS_ADDRESS_MASK << HUB_NI_VECTOR_STATUS_ADDRESS_SHIFT)
#define HUB_NI_VECTOR_STATUS_PIO_TYPE_SHIFT          0 /* established */
#define HUB_NI_VECTOR_STATUS_PIO_TYPE_MASK           0x7ull
#define HUB_NI_VECTOR_STATUS_PIO_TYPE_INPLACE        (HUB_NI_VECTOR_STATUS_PIO_TYPE_MASK << HUB_NI_VECTOR_STATUS_PIO_TYPE_SHIFT)

/*
 * Return vector of a vector operation, named NI_RETURN_VECTOR in the header. The header gives no layout. The IRIX register table confirms the access.
 */
/* ni_return_vector: rw64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_RETURN_VECTOR_OFFSET                  0x600308u /* established */

/*
 * The header describes the register as 'Vector PIO read & clear status': a read clears, so the cor mask is all bits. Established by the header's comment, the same evidence the processor clear-on-read registers cite.
 */
/* ni_vector_clear: r64, reset unknown; census: 3 sites, 3 routines */
#define HUB_NI_VECTOR_CLEAR_OFFSET                   0x600380u /* established */

/*
 * PIO protection bits, one per region, named NI_IO_PROTECT in the header. Offset and name are from the header. The header gives neither a field layout nor a reset. The IRIX register table confirms the access.
 */
/* ni_io_protect: rw64, reset 0xffffffffffffffff; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_IO_PROTECT_OFFSET                     0x600400u /* established */

/*
 * PIO protection override, named NI_IO_PROT_OVRRD in the header. The header gives no unlock value or behaviour, so none is imported. The IRIX register table confirms the access.
 */
/* ni_io_prot_ovrrd: w64, reset unknown; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_IO_PROT_OVRRD_OFFSET                  0x600408u /* established */

/*
 * Layout of each of the eight ageing registers, ni_age_cpu0_memory through ni_age_io_pio. The census names two of them. The header gives the channel field its own names and no meaning for the congestion field.
 */
/* ni_age_cpu0_memory: rw64, reset 0x0; census: 9 sites, 3 routines */
#define HUB_NI_AGE_CPU0_MEMORY_OFFSET                0x600500u /* established */
#define HUB_NI_AGE_CPU0_MEMORY_VCHANNEL_SHIFT        10 /* established */
#define HUB_NI_AGE_CPU0_MEMORY_VCHANNEL_MASK         0x3ull
#define HUB_NI_AGE_CPU0_MEMORY_VCHANNEL_INPLACE      (HUB_NI_AGE_CPU0_MEMORY_VCHANNEL_MASK << HUB_NI_AGE_CPU0_MEMORY_VCHANNEL_SHIFT)
#define HUB_NI_AGE_CPU0_MEMORY_CONGESTION_SHIFT      8 /* established */
#define HUB_NI_AGE_CPU0_MEMORY_CONGESTION_MASK       0x3ull
#define HUB_NI_AGE_CPU0_MEMORY_CONGESTION_INPLACE    (HUB_NI_AGE_CPU0_MEMORY_CONGESTION_MASK << HUB_NI_AGE_CPU0_MEMORY_CONGESTION_SHIFT)
#define HUB_NI_AGE_CPU0_MEMORY_AGE_SHIFT             0 /* established */
#define HUB_NI_AGE_CPU0_MEMORY_AGE_MASK              0xffull
#define HUB_NI_AGE_CPU0_MEMORY_AGE_INPLACE           (HUB_NI_AGE_CPU0_MEMORY_AGE_MASK << HUB_NI_AGE_CPU0_MEMORY_AGE_SHIFT)

/*
 * CPU 0 PIO age control, named NI_AGE_CPU0_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.
 */
/* ni_age_cpu0_pio: rw64, reset 0x0; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_CPU0_PIO_OFFSET                   0x600508u /* established */
#define HUB_NI_AGE_CPU0_PIO_VCHANNEL_SHIFT           10 /* established */
#define HUB_NI_AGE_CPU0_PIO_VCHANNEL_MASK            0x3ull
#define HUB_NI_AGE_CPU0_PIO_VCHANNEL_INPLACE         (HUB_NI_AGE_CPU0_PIO_VCHANNEL_MASK << HUB_NI_AGE_CPU0_PIO_VCHANNEL_SHIFT)
#define HUB_NI_AGE_CPU0_PIO_CONGESTION_SHIFT         8 /* established */
#define HUB_NI_AGE_CPU0_PIO_CONGESTION_MASK          0x3ull
#define HUB_NI_AGE_CPU0_PIO_CONGESTION_INPLACE       (HUB_NI_AGE_CPU0_PIO_CONGESTION_MASK << HUB_NI_AGE_CPU0_PIO_CONGESTION_SHIFT)
#define HUB_NI_AGE_CPU0_PIO_AGE_SHIFT                0 /* established */
#define HUB_NI_AGE_CPU0_PIO_AGE_MASK                 0xffull
#define HUB_NI_AGE_CPU0_PIO_AGE_INPLACE              (HUB_NI_AGE_CPU0_PIO_AGE_MASK << HUB_NI_AGE_CPU0_PIO_AGE_SHIFT)

/*
 * Layout of each of the eight ageing registers, ni_age_cpu0_memory through ni_age_io_pio. The census names two of them. The header gives the channel field its own names and no meaning for the congestion field.
 */
/* ni_age_cpu1_memory: rw64, reset 0x0; census: 9 sites, 3 routines */
#define HUB_NI_AGE_CPU1_MEMORY_OFFSET                0x600510u /* established */
#define HUB_NI_AGE_CPU1_MEMORY_VCHANNEL_SHIFT        10 /* established */
#define HUB_NI_AGE_CPU1_MEMORY_VCHANNEL_MASK         0x3ull
#define HUB_NI_AGE_CPU1_MEMORY_VCHANNEL_INPLACE      (HUB_NI_AGE_CPU1_MEMORY_VCHANNEL_MASK << HUB_NI_AGE_CPU1_MEMORY_VCHANNEL_SHIFT)
#define HUB_NI_AGE_CPU1_MEMORY_CONGESTION_SHIFT      8 /* established */
#define HUB_NI_AGE_CPU1_MEMORY_CONGESTION_MASK       0x3ull
#define HUB_NI_AGE_CPU1_MEMORY_CONGESTION_INPLACE    (HUB_NI_AGE_CPU1_MEMORY_CONGESTION_MASK << HUB_NI_AGE_CPU1_MEMORY_CONGESTION_SHIFT)
#define HUB_NI_AGE_CPU1_MEMORY_AGE_SHIFT             0 /* established */
#define HUB_NI_AGE_CPU1_MEMORY_AGE_MASK              0xffull
#define HUB_NI_AGE_CPU1_MEMORY_AGE_INPLACE           (HUB_NI_AGE_CPU1_MEMORY_AGE_MASK << HUB_NI_AGE_CPU1_MEMORY_AGE_SHIFT)

/*
 * CPU 1 PIO age control, named NI_AGE_CPU1_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.
 */
/* ni_age_cpu1_pio: rw64, reset 0x0; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_CPU1_PIO_OFFSET                   0x600518u /* established */
#define HUB_NI_AGE_CPU1_PIO_VCHANNEL_SHIFT           10 /* established */
#define HUB_NI_AGE_CPU1_PIO_VCHANNEL_MASK            0x3ull
#define HUB_NI_AGE_CPU1_PIO_VCHANNEL_INPLACE         (HUB_NI_AGE_CPU1_PIO_VCHANNEL_MASK << HUB_NI_AGE_CPU1_PIO_VCHANNEL_SHIFT)
#define HUB_NI_AGE_CPU1_PIO_CONGESTION_SHIFT         8 /* established */
#define HUB_NI_AGE_CPU1_PIO_CONGESTION_MASK          0x3ull
#define HUB_NI_AGE_CPU1_PIO_CONGESTION_INPLACE       (HUB_NI_AGE_CPU1_PIO_CONGESTION_MASK << HUB_NI_AGE_CPU1_PIO_CONGESTION_SHIFT)
#define HUB_NI_AGE_CPU1_PIO_AGE_SHIFT                0 /* established */
#define HUB_NI_AGE_CPU1_PIO_AGE_MASK                 0xffull
#define HUB_NI_AGE_CPU1_PIO_AGE_INPLACE              (HUB_NI_AGE_CPU1_PIO_AGE_MASK << HUB_NI_AGE_CPU1_PIO_AGE_SHIFT)

/*
 * Block-transfer engine memory age control, named NI_AGE_GBR_MEMORY in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.
 */
/* ni_age_gbr_memory: rw64, reset 0x0; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_GBR_MEMORY_OFFSET                 0x600520u /* established */
#define HUB_NI_AGE_GBR_MEMORY_VCHANNEL_SHIFT         10 /* established */
#define HUB_NI_AGE_GBR_MEMORY_VCHANNEL_MASK          0x3ull
#define HUB_NI_AGE_GBR_MEMORY_VCHANNEL_INPLACE       (HUB_NI_AGE_GBR_MEMORY_VCHANNEL_MASK << HUB_NI_AGE_GBR_MEMORY_VCHANNEL_SHIFT)
#define HUB_NI_AGE_GBR_MEMORY_CONGESTION_SHIFT       8 /* established */
#define HUB_NI_AGE_GBR_MEMORY_CONGESTION_MASK        0x3ull
#define HUB_NI_AGE_GBR_MEMORY_CONGESTION_INPLACE     (HUB_NI_AGE_GBR_MEMORY_CONGESTION_MASK << HUB_NI_AGE_GBR_MEMORY_CONGESTION_SHIFT)
#define HUB_NI_AGE_GBR_MEMORY_AGE_SHIFT              0 /* established */
#define HUB_NI_AGE_GBR_MEMORY_AGE_MASK               0xffull
#define HUB_NI_AGE_GBR_MEMORY_AGE_INPLACE            (HUB_NI_AGE_GBR_MEMORY_AGE_MASK << HUB_NI_AGE_GBR_MEMORY_AGE_SHIFT)

/*
 * Block-transfer engine PIO age control, named NI_AGE_GBR_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.
 */
/* ni_age_gbr_pio: rw64, reset 0x0; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_GBR_PIO_OFFSET                    0x600528u /* established */
#define HUB_NI_AGE_GBR_PIO_VCHANNEL_SHIFT            10 /* established */
#define HUB_NI_AGE_GBR_PIO_VCHANNEL_MASK             0x3ull
#define HUB_NI_AGE_GBR_PIO_VCHANNEL_INPLACE          (HUB_NI_AGE_GBR_PIO_VCHANNEL_MASK << HUB_NI_AGE_GBR_PIO_VCHANNEL_SHIFT)
#define HUB_NI_AGE_GBR_PIO_CONGESTION_SHIFT          8 /* established */
#define HUB_NI_AGE_GBR_PIO_CONGESTION_MASK           0x3ull
#define HUB_NI_AGE_GBR_PIO_CONGESTION_INPLACE        (HUB_NI_AGE_GBR_PIO_CONGESTION_MASK << HUB_NI_AGE_GBR_PIO_CONGESTION_SHIFT)
#define HUB_NI_AGE_GBR_PIO_AGE_SHIFT                 0 /* established */
#define HUB_NI_AGE_GBR_PIO_AGE_MASK                  0xffull
#define HUB_NI_AGE_GBR_PIO_AGE_INPLACE               (HUB_NI_AGE_GBR_PIO_AGE_MASK << HUB_NI_AGE_GBR_PIO_AGE_SHIFT)

/*
 * I/O interface memory age control, named NI_AGE_IO_MEMORY in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.
 */
/* ni_age_io_memory: rw64, reset 0x0; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_IO_MEMORY_OFFSET                  0x600530u /* established */
#define HUB_NI_AGE_IO_MEMORY_VCHANNEL_SHIFT          10 /* established */
#define HUB_NI_AGE_IO_MEMORY_VCHANNEL_MASK           0x3ull
#define HUB_NI_AGE_IO_MEMORY_VCHANNEL_INPLACE        (HUB_NI_AGE_IO_MEMORY_VCHANNEL_MASK << HUB_NI_AGE_IO_MEMORY_VCHANNEL_SHIFT)
#define HUB_NI_AGE_IO_MEMORY_CONGESTION_SHIFT        8 /* established */
#define HUB_NI_AGE_IO_MEMORY_CONGESTION_MASK         0x3ull
#define HUB_NI_AGE_IO_MEMORY_CONGESTION_INPLACE      (HUB_NI_AGE_IO_MEMORY_CONGESTION_MASK << HUB_NI_AGE_IO_MEMORY_CONGESTION_SHIFT)
#define HUB_NI_AGE_IO_MEMORY_AGE_SHIFT               0 /* established */
#define HUB_NI_AGE_IO_MEMORY_AGE_MASK                0xffull
#define HUB_NI_AGE_IO_MEMORY_AGE_INPLACE             (HUB_NI_AGE_IO_MEMORY_AGE_MASK << HUB_NI_AGE_IO_MEMORY_AGE_SHIFT)

/*
 * I/O interface PIO age control, named NI_AGE_IO_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.
 */
/* ni_age_io_pio: rw64, reset 0x0; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_AGE_IO_PIO_OFFSET                     0x600538u /* established */
#define HUB_NI_AGE_IO_PIO_VCHANNEL_SHIFT             10 /* established */
#define HUB_NI_AGE_IO_PIO_VCHANNEL_MASK              0x3ull
#define HUB_NI_AGE_IO_PIO_VCHANNEL_INPLACE           (HUB_NI_AGE_IO_PIO_VCHANNEL_MASK << HUB_NI_AGE_IO_PIO_VCHANNEL_SHIFT)
#define HUB_NI_AGE_IO_PIO_CONGESTION_SHIFT           8 /* established */
#define HUB_NI_AGE_IO_PIO_CONGESTION_MASK            0x3ull
#define HUB_NI_AGE_IO_PIO_CONGESTION_INPLACE         (HUB_NI_AGE_IO_PIO_CONGESTION_MASK << HUB_NI_AGE_IO_PIO_CONGESTION_SHIFT)
#define HUB_NI_AGE_IO_PIO_AGE_SHIFT                  0 /* established */
#define HUB_NI_AGE_IO_PIO_AGE_MASK                   0xffull
#define HUB_NI_AGE_IO_PIO_AGE_INPLACE                (HUB_NI_AGE_IO_PIO_AGE_MASK << HUB_NI_AGE_IO_PIO_AGE_SHIFT)

/*
 * Port parameters, named NI_PORT_PARMS in the header. Offset and name are from the header. The fields are graded on their own. The IRIX register table confirms the access.
 */
/* ni_port_parms: rw64, reset 0x1bf0; public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) */
#define HUB_NI_PORT_PARMS_OFFSET                     0x608000u /* established */
#define HUB_NI_PORT_PARMS_NULL_TIMEOUT_SHIFT         10 /* established */
#define HUB_NI_PORT_PARMS_NULL_TIMEOUT_MASK          0x3full
#define HUB_NI_PORT_PARMS_NULL_TIMEOUT_INPLACE       (HUB_NI_PORT_PARMS_NULL_TIMEOUT_MASK << HUB_NI_PORT_PARMS_NULL_TIMEOUT_SHIFT)
#define HUB_NI_PORT_PARMS_MAX_BURST_SHIFT            0 /* established */
#define HUB_NI_PORT_PARMS_MAX_BURST_MASK             0x3ffull
#define HUB_NI_PORT_PARMS_MAX_BURST_INPLACE          (HUB_NI_PORT_PARMS_MAX_BURST_MASK << HUB_NI_PORT_PARMS_MAX_BURST_SHIFT)

/*
 * Layout of the port error register, ni_port_error, and of its clearing alias, ni_port_error_clear. Bit 32 is outside the header's error mask and has no name. The rsvd mask is the header structure's unused members: bits 63:38 and bit 32. NPE_MASK, 0x3effffffff, is the header's own mask of defined bits and agrees.
 */
/* ni_port_error: r64, reset unknown; census: 4 sites, 4 routines (r); census: 1 sites, 1 routines (r, indexed) */
#define HUB_NI_PORT_ERROR_OFFSET                     0x608008u /* established */
#define HUB_NI_PORT_ERROR_LINK_RESET_SHIFT           37 /* established */
#define HUB_NI_PORT_ERROR_LINK_RESET_MASK            0x1ull
#define HUB_NI_PORT_ERROR_LINK_RESET_INPLACE         (HUB_NI_PORT_ERROR_LINK_RESET_MASK << HUB_NI_PORT_ERROR_LINK_RESET_SHIFT)
#define HUB_NI_PORT_ERROR_INTERNAL_ERROR_SHIFT       36 /* established */
#define HUB_NI_PORT_ERROR_INTERNAL_ERROR_MASK        0x1ull
#define HUB_NI_PORT_ERROR_INTERNAL_ERROR_INPLACE     (HUB_NI_PORT_ERROR_INTERNAL_ERROR_MASK << HUB_NI_PORT_ERROR_INTERNAL_ERROR_SHIFT)
#define HUB_NI_PORT_ERROR_BAD_MESSAGE_SHIFT          35 /* established */
#define HUB_NI_PORT_ERROR_BAD_MESSAGE_MASK           0x1ull
#define HUB_NI_PORT_ERROR_BAD_MESSAGE_INPLACE        (HUB_NI_PORT_ERROR_BAD_MESSAGE_MASK << HUB_NI_PORT_ERROR_BAD_MESSAGE_SHIFT)
#define HUB_NI_PORT_ERROR_BAD_DESTINATION_SHIFT      34 /* established */
#define HUB_NI_PORT_ERROR_BAD_DESTINATION_MASK       0x1ull
#define HUB_NI_PORT_ERROR_BAD_DESTINATION_INPLACE    (HUB_NI_PORT_ERROR_BAD_DESTINATION_MASK << HUB_NI_PORT_ERROR_BAD_DESTINATION_SHIFT)
#define HUB_NI_PORT_ERROR_QUEUE_OVERFLOW_SHIFT       33 /* established */
#define HUB_NI_PORT_ERROR_QUEUE_OVERFLOW_MASK        0x1ull
#define HUB_NI_PORT_ERROR_QUEUE_OVERFLOW_INPLACE     (HUB_NI_PORT_ERROR_QUEUE_OVERFLOW_MASK << HUB_NI_PORT_ERROR_QUEUE_OVERFLOW_SHIFT)
#define HUB_NI_PORT_ERROR_CREDIT_TIMEOUT_COUNT_SHIFT 28 /* established */
#define HUB_NI_PORT_ERROR_CREDIT_TIMEOUT_COUNT_MASK  0xfull
#define HUB_NI_PORT_ERROR_CREDIT_TIMEOUT_COUNT_INPLACE (HUB_NI_PORT_ERROR_CREDIT_TIMEOUT_COUNT_MASK << HUB_NI_PORT_ERROR_CREDIT_TIMEOUT_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_TAIL_TIMEOUT_COUNT_SHIFT   24 /* established */
#define HUB_NI_PORT_ERROR_TAIL_TIMEOUT_COUNT_MASK    0xfull
#define HUB_NI_PORT_ERROR_TAIL_TIMEOUT_COUNT_INPLACE (HUB_NI_PORT_ERROR_TAIL_TIMEOUT_COUNT_MASK << HUB_NI_PORT_ERROR_TAIL_TIMEOUT_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_RETRY_COUNT_SHIFT          16 /* established */
#define HUB_NI_PORT_ERROR_RETRY_COUNT_MASK           0xffull
#define HUB_NI_PORT_ERROR_RETRY_COUNT_INPLACE        (HUB_NI_PORT_ERROR_RETRY_COUNT_MASK << HUB_NI_PORT_ERROR_RETRY_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_CHECK_BIT_ERROR_COUNT_SHIFT 8 /* established */
#define HUB_NI_PORT_ERROR_CHECK_BIT_ERROR_COUNT_MASK 0xffull
#define HUB_NI_PORT_ERROR_CHECK_BIT_ERROR_COUNT_INPLACE (HUB_NI_PORT_ERROR_CHECK_BIT_ERROR_COUNT_MASK << HUB_NI_PORT_ERROR_CHECK_BIT_ERROR_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_SEQUENCE_ERROR_COUNT_SHIFT 0 /* established */
#define HUB_NI_PORT_ERROR_SEQUENCE_ERROR_COUNT_MASK  0xffull
#define HUB_NI_PORT_ERROR_SEQUENCE_ERROR_COUNT_INPLACE (HUB_NI_PORT_ERROR_SEQUENCE_ERROR_COUNT_MASK << HUB_NI_PORT_ERROR_SEQUENCE_ERROR_COUNT_SHIFT)

/*
 * Layout of the port error register, ni_port_error, and of its clearing alias, ni_port_error_clear. Bit 32 is outside the header's error mask and has no name.
 */
/* ni_port_error_clear: r64, reset unknown; census: 10 sites, 4 routines (r); census: 3 sites, 3 routines (r, indexed) */
#define HUB_NI_PORT_ERROR_CLEAR_OFFSET               0x608088u /* established */
#define HUB_NI_PORT_ERROR_CLEAR_LINK_RESET_SHIFT     37 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_LINK_RESET_MASK      0x1ull
#define HUB_NI_PORT_ERROR_CLEAR_LINK_RESET_INPLACE   (HUB_NI_PORT_ERROR_CLEAR_LINK_RESET_MASK << HUB_NI_PORT_ERROR_CLEAR_LINK_RESET_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_INTERNAL_ERROR_SHIFT 36 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_INTERNAL_ERROR_MASK  0x1ull
#define HUB_NI_PORT_ERROR_CLEAR_INTERNAL_ERROR_INPLACE (HUB_NI_PORT_ERROR_CLEAR_INTERNAL_ERROR_MASK << HUB_NI_PORT_ERROR_CLEAR_INTERNAL_ERROR_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_BAD_MESSAGE_SHIFT    35 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_BAD_MESSAGE_MASK     0x1ull
#define HUB_NI_PORT_ERROR_CLEAR_BAD_MESSAGE_INPLACE  (HUB_NI_PORT_ERROR_CLEAR_BAD_MESSAGE_MASK << HUB_NI_PORT_ERROR_CLEAR_BAD_MESSAGE_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_BAD_DESTINATION_SHIFT 34 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_BAD_DESTINATION_MASK 0x1ull
#define HUB_NI_PORT_ERROR_CLEAR_BAD_DESTINATION_INPLACE (HUB_NI_PORT_ERROR_CLEAR_BAD_DESTINATION_MASK << HUB_NI_PORT_ERROR_CLEAR_BAD_DESTINATION_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_QUEUE_OVERFLOW_SHIFT 33 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_QUEUE_OVERFLOW_MASK  0x1ull
#define HUB_NI_PORT_ERROR_CLEAR_QUEUE_OVERFLOW_INPLACE (HUB_NI_PORT_ERROR_CLEAR_QUEUE_OVERFLOW_MASK << HUB_NI_PORT_ERROR_CLEAR_QUEUE_OVERFLOW_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_CREDIT_TIMEOUT_COUNT_SHIFT 28 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_CREDIT_TIMEOUT_COUNT_MASK 0xfull
#define HUB_NI_PORT_ERROR_CLEAR_CREDIT_TIMEOUT_COUNT_INPLACE (HUB_NI_PORT_ERROR_CLEAR_CREDIT_TIMEOUT_COUNT_MASK << HUB_NI_PORT_ERROR_CLEAR_CREDIT_TIMEOUT_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_TAIL_TIMEOUT_COUNT_SHIFT 24 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_TAIL_TIMEOUT_COUNT_MASK 0xfull
#define HUB_NI_PORT_ERROR_CLEAR_TAIL_TIMEOUT_COUNT_INPLACE (HUB_NI_PORT_ERROR_CLEAR_TAIL_TIMEOUT_COUNT_MASK << HUB_NI_PORT_ERROR_CLEAR_TAIL_TIMEOUT_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_RETRY_COUNT_SHIFT    16 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_RETRY_COUNT_MASK     0xffull
#define HUB_NI_PORT_ERROR_CLEAR_RETRY_COUNT_INPLACE  (HUB_NI_PORT_ERROR_CLEAR_RETRY_COUNT_MASK << HUB_NI_PORT_ERROR_CLEAR_RETRY_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_CHECK_BIT_ERROR_COUNT_SHIFT 8 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_CHECK_BIT_ERROR_COUNT_MASK 0xffull
#define HUB_NI_PORT_ERROR_CLEAR_CHECK_BIT_ERROR_COUNT_INPLACE (HUB_NI_PORT_ERROR_CLEAR_CHECK_BIT_ERROR_COUNT_MASK << HUB_NI_PORT_ERROR_CLEAR_CHECK_BIT_ERROR_COUNT_SHIFT)
#define HUB_NI_PORT_ERROR_CLEAR_SEQUENCE_ERROR_COUNT_SHIFT 0 /* established */
#define HUB_NI_PORT_ERROR_CLEAR_SEQUENCE_ERROR_COUNT_MASK 0xffull
#define HUB_NI_PORT_ERROR_CLEAR_SEQUENCE_ERROR_COUNT_INPLACE (HUB_NI_PORT_ERROR_CLEAR_SEQUENCE_ERROR_COUNT_MASK << HUB_NI_PORT_ERROR_CLEAR_SEQUENCE_ERROR_COUNT_SHIFT)

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

#define HUB_NI_BASE                                  0x600000u /* established */
#define HUB_NI_BASE_TABLES                           0x630000u /* established */
#define HUB_NI_LOCAL_ENTRIES                         0x10u /* established */
#define HUB_NI_META_ENTRIES                          0x20u /* established */
#define HUB_NI_NASID_TO_COARSEREG_SHIFT              0x3u /* established */
#define HUB_NI_NASID_TO_FINEREG_SHIFT                0x0u /* established */
#define HUB_NI_PORT_ERROR_COUNT_MAX                  0xffu /* established */
#define HUB_NI_PORT_PARMS_DEFAULTS                   0x1bf0u /* established */
#define HUB_NI_PORT_PARMS_HUB20_DEFAULTS             0x7f0u /* established */

#endif /* HUB_GEN_H */
