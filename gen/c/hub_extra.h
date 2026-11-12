/* generated from defs/hub_extra.toml by defs-gen - do not edit, change the source */
/* Hub block transfer engine registers and control bits outside the census */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/*
 * Notification address of engine 0, the twin of the engine 1 slot in the census. Offset and name are from the public header. The header gives no access type, so rw is assumed.
 */
/* iio_ibna_0: rw64, reset unknown */
#define HUB_IIO_IBNA_0                               0x410020 /* inferred */

/*
 * Interrupt address of engine 0. Offset and name are from the public header. The header gives no access type, so rw is assumed.
 */
/* iio_ibia_0: rw64, reset unknown */
#define HUB_IIO_IBIA_0                               0x410028 /* inferred */
#define HUB_IIO_IBIA_0_LEVEL_SHIFT                   16 /* established */
#define HUB_IIO_IBIA_0_LEVEL_MASK                    0x7full
#define HUB_IIO_IBIA_0_LEVEL_INPLACE                 (HUB_IIO_IBIA_0_LEVEL_MASK << HUB_IIO_IBIA_0_LEVEL_SHIFT)
#define HUB_IIO_IBIA_0_NODE_SHIFT                    0 /* established */
#define HUB_IIO_IBIA_0_NODE_MASK                     0x1ffull
#define HUB_IIO_IBIA_0_NODE_INPLACE                  (HUB_IIO_IBIA_0_NODE_MASK << HUB_IIO_IBIA_0_NODE_SHIFT)

/*
 * Interrupt address of engine 1. Offset and name are from the public header. The header gives no access type, so rw is assumed.
 */
/* iio_ibia_1: rw64, reset unknown */
#define HUB_IIO_IBIA_1                               0x420028 /* inferred */
#define HUB_IIO_IBIA_1_LEVEL_SHIFT                   16 /* established */
#define HUB_IIO_IBIA_1_LEVEL_MASK                    0x7full
#define HUB_IIO_IBIA_1_LEVEL_INPLACE                 (HUB_IIO_IBIA_1_LEVEL_MASK << HUB_IIO_IBIA_1_LEVEL_SHIFT)
#define HUB_IIO_IBIA_1_NODE_SHIFT                    0 /* established */
#define HUB_IIO_IBIA_1_NODE_MASK                     0x1ffull
#define HUB_IIO_IBIA_1_NODE_INPLACE                  (HUB_IIO_IBIA_1_NODE_MASK << HUB_IIO_IBIA_1_NODE_SHIFT)

#define HUB_IIO_IBCT_NOTIFY                          0x10u /* established */
#define HUB_IIO_IBCT_POISON                          0x100u /* established */
#define HUB_IIO_IBCT_ZFIL_MODE                       0x1u /* established */
#define HUB_IIO_IBLS_BUSY                            0x100000u /* established */
#define HUB_IIO_IECLR_BTE0                           0x20000u /* inferred */
#define HUB_IIO_IECLR_BTE1                           0x40000u /* inferred */

#endif /* HUB_GEN_H */
