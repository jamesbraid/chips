/*
 * bridge_extra.h - Bridge-family registers and bits outside the census
 *
 * Written by hand, not generated: the census names a register only where a routine in the scanned objects reaches it, and
 * the device-register bits below are built from flag masks rather than named per bit. Same label convention as the generated
 * headers: [E] established, [I] inferred, [U] unknown. Offsets are the register-block offsets used in bridge.h (32-bit
 * words at slot+4 on the Bridge and Xbridge).
 * Sources: the published Bridge ASIC specification (rev 4.0, 3/27/97) and the published Xbridge ASIC specification
 * (rev 0.5) for the test-pin register; the Origin 2000 and Origin 3000 generation kernels' device-flag routines for the
 * device-register bits, with the public Linux Bridge header's names as agreement ([I] for the hardware meaning).
 */
#ifndef BRIDGE_EXTRA_H
#define BRIDGE_EXTRA_H

/* Test pin control. No shipped routine touches it. Layout [E] from the two published specifications; use [U]. */
#define BRIDGE_TEST_PIN_CONTROL              0x000070   /* [E] access rw; resets to 0 in the specification */
#define BRIDGE_TEST_PIN_CONTROL_DATA_OUT     0x00000f00 /* [E] Bridge: bits 11:8, test data out */
#define BRIDGE_TEST_PIN_CONTROL_SELECT0      0x00000003 /* [E] Bridge: bits 1:0, pin-function select, two bits */
#define BRIDGE_TEST_PIN_CONTROL_SELECT1      0x0000000c /* [E] Bridge: bits 3:2 */
#define BRIDGE_TEST_PIN_CONTROL_SELECT2      0x00000030 /* [E] Bridge: bits 5:4 */
#define BRIDGE_TEST_PIN_CONTROL_SELECT3      0x000000c0 /* [E] Bridge: bits 7:6 */
#define XBRIDGE_TEST_PIN_CONTROL_DATA_OUT    0x00ff0000 /* [E] Xbridge: bits 23:16, an 8-bit data field; the Xbridge specification also widens the selects to eight, whose positions this header does not give ([U]) */

/* Device register bits (BRIDGE_DEVICE, 0x200 + 8n) that the Bridge-family flag routines set or clear. The mapping from flag bits to
 * register bits is [E] (the routines read in full in both kernels); the hardware meaning of each bit is [I], from the
 * public Linux header's names. */
#define BRIDGE_DEVICE_WRITE_GATHER_EN        0x01800000 /* [E] bits 24 and 23 together: PMU and direct write-gather enables; one flag pair controls both */
#define BRIDGE_DEVICE_PREFETCH               0x00040000 /* [E] bit 18; meaning [I] */
#define BRIDGE_DEVICE_PRECISE                0x00020000 /* [E] bit 17, precise exception; meaning [I] */
#define BRIDGE_DEVICE_BARRIER                0x00008000 /* [E] bit 15; meaning [I] */
#define BRIDGE_DEVICE_SIZE_64                0x00400000 /* [E] bit 22, 64-bit device size; dropped from the set mask when the chip is the PIC; meaning [I] */
#define BRIDGE_DEVICE_REALTIME               0x00200000 /* [E] bit 21, written only on a revision 2 Bridge by the priority routine; meaning [I] */
#define BRIDGE_DEVICE_SWAP_PAIR              0x00180000 /* [E] bits 20:19, the PMU and direct byte-swap bits, cleared when the two endian arguments are equal and set otherwise; meaning [I] */

#endif /* BRIDGE_EXTRA_H */
