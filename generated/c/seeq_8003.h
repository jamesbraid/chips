/* generated from devices/seeq_8003/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 46e4c83c2a7f9205b932e74d0bfe059d566640f9dd13045c1daa4fdc6db8b16f */
/* SEEQ 8003 and 80C03 Ethernet data link controller (Indy) */
#ifndef SEEQ_8003_GEN_H
#define SEEQ_8003_GEN_H

#include <stdint.h>


/* enum bank_select */
#define SEEQ_8003_BANK_SELECT_BANK0                  0 /* inferred */
#define SEEQ_8003_BANK_SELECT_BANK1                  1 /* inferred */
#define SEEQ_8003_BANK_SELECT_BANK2                  2 /* inferred */

/* enum receive_match */
#define SEEQ_8003_RECEIVE_MATCH_RECEIVER_OFF         0 /* established */
#define SEEQ_8003_RECEIVE_MATCH_ALL_FRAMES           1 /* established */
#define SEEQ_8003_RECEIVE_MATCH_STATION_AND_BROADCAST 2 /* established */
/* established */
#define SEEQ_8003_RECEIVE_MATCH_STATION_BROADCAST_AND_MULTICAST 3

/*
 * Station address bytes 0 to 5, one per register. Byte 0 bit 0 is the first bit
 * on the wire. The data sheet's reset list does not name the station address
 * registers, so their reset value is unknown.
 */
/* station_address: w8, space bank0, reset unknown; SEEQ 8003 EDLC data sheet,
 * MD400024/B, p. 4-5 */
#define SEEQ_8003_STATION_ADDRESS_OFFSET             0x0u /* established */
#define SEEQ_8003_STATION_ADDRESS_COUNT              6
#define SEEQ_8003_STATION_ADDRESS_STRIDE             1

/*
 * Multicast hash bytes 0 to 5, written with bank 1 selected. Used with the
 * multicast hash filter enable in the control register.
 */
/* multicast_hash_low: w8, space bank1, reset unknown; NetBSD SEEQ register
 * header (80C03 bank layout); Linux SEEQ driver header; IRIX driver use */
#define SEEQ_8003_MULTICAST_HASH_LOW_OFFSET          0x0u /* inferred */
#define SEEQ_8003_MULTICAST_HASH_LOW_COUNT           6
#define SEEQ_8003_MULTICAST_HASH_LOW_STRIDE          1

/*
 * Multicast hash bytes 6 and 7, written at bank 2 registers 0 and 1.
 */
/* multicast_hash_high: w8, space bank2, reset unknown; NetBSD SEEQ register
 * header (80C03 bank layout); Linux SEEQ driver header; IRIX driver use */
#define SEEQ_8003_MULTICAST_HASH_HIGH_OFFSET         0x0u /* inferred */
#define SEEQ_8003_MULTICAST_HASH_HIGH_COUNT          2
#define SEEQ_8003_MULTICAST_HASH_HIGH_STRIDE         1

/*
 * Inter-packet gap byte. HPC3 writes each transmit descriptor's gap here when
 * its write-control bit is set. The sources read it as the gap, but the
 * encoding of the byte is unknown. The IRIX driver computes it from a tunable,
 * Linux writes zero, and NetBSD's header calls the register reserved and writes
 * zero.
 */
/* inter_packet_gap: w8, space bank2, reset unknown; HPC3 Chip Specification,
 * revision 1.4, p. 14 (SEEQ extended register x02); IRIX driver use; Linux SEEQ
 * driver header; NetBSD SEEQ register header */
#define SEEQ_8003_INTER_PACKET_GAP_OFFSET            0x2u /* inferred */

/*
 * Counter, flag and filter control. Writing a zero and then a one to a counter
 * or flag enable clears the counter or flag. The sources do not give the
 * register's reset value.
 */
/* control: w8, space bank2, reset unknown; NetBSD SEEQ register header and
 * Linux SEEQ driver header, which agree on every bit */
#define SEEQ_8003_CONTROL_OFFSET                     0x3u /* inferred */
#define SEEQ_8003_CONTROL_NO_CARRIER_FLAG_ENABLE_SHIFT 5 /* inferred */
#define SEEQ_8003_CONTROL_NO_CARRIER_FLAG_ENABLE_MASK 0x1u
#define SEEQ_8003_CONTROL_NO_CARRIER_FLAG_ENABLE_INPLACE (SEEQ_8003_CONTROL_NO_CARRIER_FLAG_ENABLE_MASK << SEEQ_8003_CONTROL_NO_CARRIER_FLAG_ENABLE_SHIFT)
#define SEEQ_8003_CONTROL_RECEIVE_SHORT_FRAMES_SHIFT 4 /* inferred */
#define SEEQ_8003_CONTROL_RECEIVE_SHORT_FRAMES_MASK  0x1u
#define SEEQ_8003_CONTROL_RECEIVE_SHORT_FRAMES_INPLACE (SEEQ_8003_CONTROL_RECEIVE_SHORT_FRAMES_MASK << SEEQ_8003_CONTROL_RECEIVE_SHORT_FRAMES_SHIFT)
#define SEEQ_8003_CONTROL_MULTICAST_HASH_ENABLE_SHIFT 3 /* inferred */
#define SEEQ_8003_CONTROL_MULTICAST_HASH_ENABLE_MASK 0x1u
#define SEEQ_8003_CONTROL_MULTICAST_HASH_ENABLE_INPLACE (SEEQ_8003_CONTROL_MULTICAST_HASH_ENABLE_MASK << SEEQ_8003_CONTROL_MULTICAST_HASH_ENABLE_SHIFT)
#define SEEQ_8003_CONTROL_SQE_FLAG_ENABLE_SHIFT      2 /* inferred */
#define SEEQ_8003_CONTROL_SQE_FLAG_ENABLE_MASK       0x1u
#define SEEQ_8003_CONTROL_SQE_FLAG_ENABLE_INPLACE (SEEQ_8003_CONTROL_SQE_FLAG_ENABLE_MASK << SEEQ_8003_CONTROL_SQE_FLAG_ENABLE_SHIFT)
#define SEEQ_8003_CONTROL_TOTAL_COLLISION_COUNT_ENABLE_SHIFT 1 /* inferred */
#define SEEQ_8003_CONTROL_TOTAL_COLLISION_COUNT_ENABLE_MASK 0x1u
#define SEEQ_8003_CONTROL_TOTAL_COLLISION_COUNT_ENABLE_INPLACE (SEEQ_8003_CONTROL_TOTAL_COLLISION_COUNT_ENABLE_MASK << SEEQ_8003_CONTROL_TOTAL_COLLISION_COUNT_ENABLE_SHIFT)
#define SEEQ_8003_CONTROL_TX_COLLISION_COUNT_ENABLE_SHIFT 0 /* inferred */
#define SEEQ_8003_CONTROL_TX_COLLISION_COUNT_ENABLE_MASK 0x1u
#define SEEQ_8003_CONTROL_TX_COLLISION_COUNT_ENABLE_INPLACE (SEEQ_8003_CONTROL_TX_COLLISION_COUNT_ENABLE_MASK << SEEQ_8003_CONTROL_TX_COLLISION_COUNT_ENABLE_SHIFT)

/*
 * 80C03 configuration: auto-pad, no preamble, do not receive own frames, no
 * CRC, AutoDUPLEX, CRC to FIFO and fast discard, as NetBSD's header names them.
 * The bit positions are not stated in the sources. No Indy driver writes it;
 * OpenBSD's write is compiled out.
 */
/* configuration: w8, space bank2, reset unknown; NetBSD SEEQ register header
 * only */
#define SEEQ_8003_CONFIGURATION_OFFSET               0x4u /* inferred */

/*
 * Receive command. Reset clears it. Bits 5 to 0 enable interrupts for each
 * receive condition. Bit 0 also makes overflow frames frames of interest. Bits
 * 7 and 6 set the match mode.
 */
/* rx_command: w8, space cmd, reset 0x0; SEEQ 8003 EDLC data sheet, MD400024/B,
 * pp. 4-6, 4-7 */
#define SEEQ_8003_RX_COMMAND_OFFSET                  0x6u /* established */
#define SEEQ_8003_RX_COMMAND_MATCH_MODE_SHIFT        6 /* established */
#define SEEQ_8003_RX_COMMAND_MATCH_MODE_MASK         0x3u
#define SEEQ_8003_RX_COMMAND_MATCH_MODE_INPLACE (SEEQ_8003_RX_COMMAND_MATCH_MODE_MASK << SEEQ_8003_RX_COMMAND_MATCH_MODE_SHIFT)
#define SEEQ_8003_RX_COMMAND_INT_GOOD_FRAME_SHIFT    5 /* established */
#define SEEQ_8003_RX_COMMAND_INT_GOOD_FRAME_MASK     0x1u
#define SEEQ_8003_RX_COMMAND_INT_GOOD_FRAME_INPLACE (SEEQ_8003_RX_COMMAND_INT_GOOD_FRAME_MASK << SEEQ_8003_RX_COMMAND_INT_GOOD_FRAME_SHIFT)
#define SEEQ_8003_RX_COMMAND_INT_END_OF_FRAME_SHIFT  4 /* established */
#define SEEQ_8003_RX_COMMAND_INT_END_OF_FRAME_MASK   0x1u
#define SEEQ_8003_RX_COMMAND_INT_END_OF_FRAME_INPLACE (SEEQ_8003_RX_COMMAND_INT_END_OF_FRAME_MASK << SEEQ_8003_RX_COMMAND_INT_END_OF_FRAME_SHIFT)
#define SEEQ_8003_RX_COMMAND_INT_SHORT_FRAME_SHIFT   3 /* established */
#define SEEQ_8003_RX_COMMAND_INT_SHORT_FRAME_MASK    0x1u
#define SEEQ_8003_RX_COMMAND_INT_SHORT_FRAME_INPLACE (SEEQ_8003_RX_COMMAND_INT_SHORT_FRAME_MASK << SEEQ_8003_RX_COMMAND_INT_SHORT_FRAME_SHIFT)
#define SEEQ_8003_RX_COMMAND_INT_DRIBBLE_ERROR_SHIFT 2 /* established */
#define SEEQ_8003_RX_COMMAND_INT_DRIBBLE_ERROR_MASK  0x1u
#define SEEQ_8003_RX_COMMAND_INT_DRIBBLE_ERROR_INPLACE (SEEQ_8003_RX_COMMAND_INT_DRIBBLE_ERROR_MASK << SEEQ_8003_RX_COMMAND_INT_DRIBBLE_ERROR_SHIFT)
#define SEEQ_8003_RX_COMMAND_INT_CRC_ERROR_SHIFT     1 /* established */
#define SEEQ_8003_RX_COMMAND_INT_CRC_ERROR_MASK      0x1u
#define SEEQ_8003_RX_COMMAND_INT_CRC_ERROR_INPLACE (SEEQ_8003_RX_COMMAND_INT_CRC_ERROR_MASK << SEEQ_8003_RX_COMMAND_INT_CRC_ERROR_SHIFT)
#define SEEQ_8003_RX_COMMAND_INT_OVERFLOW_SHIFT      0 /* established */
#define SEEQ_8003_RX_COMMAND_INT_OVERFLOW_MASK       0x1u
#define SEEQ_8003_RX_COMMAND_INT_OVERFLOW_INPLACE (SEEQ_8003_RX_COMMAND_INT_OVERFLOW_MASK << SEEQ_8003_RX_COMMAND_INT_OVERFLOW_SHIFT)

/*
 * Transmit command. Reset clears it. Bits 3 to 0 enable interrupts for each
 * transmit condition. Bits 6 and 5 select the register bank for writes to
 * registers 0 to 5 on the 80C03.
 */
/* tx_command: w8, space cmd, reset 0x0; SEEQ 8003 EDLC data sheet, MD400024/B,
 * pp. 4-5, 4-6; bank bits from the 80C03 additions */
#define SEEQ_8003_TX_COMMAND_OFFSET                  0x7u /* established */
#define SEEQ_8003_TX_COMMAND_BANK_SHIFT              5 /* inferred */
#define SEEQ_8003_TX_COMMAND_BANK_MASK               0x3u
#define SEEQ_8003_TX_COMMAND_BANK_INPLACE (SEEQ_8003_TX_COMMAND_BANK_MASK << SEEQ_8003_TX_COMMAND_BANK_SHIFT)
#define SEEQ_8003_TX_COMMAND_INT_SUCCESS_SHIFT       3 /* established */
#define SEEQ_8003_TX_COMMAND_INT_SUCCESS_MASK        0x1u
#define SEEQ_8003_TX_COMMAND_INT_SUCCESS_INPLACE (SEEQ_8003_TX_COMMAND_INT_SUCCESS_MASK << SEEQ_8003_TX_COMMAND_INT_SUCCESS_SHIFT)
#define SEEQ_8003_TX_COMMAND_INT_SIXTEEN_COLLISIONS_SHIFT 2 /* established */
#define SEEQ_8003_TX_COMMAND_INT_SIXTEEN_COLLISIONS_MASK 0x1u
#define SEEQ_8003_TX_COMMAND_INT_SIXTEEN_COLLISIONS_INPLACE (SEEQ_8003_TX_COMMAND_INT_SIXTEEN_COLLISIONS_MASK << SEEQ_8003_TX_COMMAND_INT_SIXTEEN_COLLISIONS_SHIFT)
#define SEEQ_8003_TX_COMMAND_INT_COLLISION_SHIFT     1 /* established */
#define SEEQ_8003_TX_COMMAND_INT_COLLISION_MASK      0x1u
#define SEEQ_8003_TX_COMMAND_INT_COLLISION_INPLACE (SEEQ_8003_TX_COMMAND_INT_COLLISION_MASK << SEEQ_8003_TX_COMMAND_INT_COLLISION_SHIFT)
#define SEEQ_8003_TX_COMMAND_INT_UNDERFLOW_SHIFT     0 /* established */
#define SEEQ_8003_TX_COMMAND_INT_UNDERFLOW_MASK      0x1u
#define SEEQ_8003_TX_COMMAND_INT_UNDERFLOW_INPLACE (SEEQ_8003_TX_COMMAND_INT_UNDERFLOW_MASK << SEEQ_8003_TX_COMMAND_INT_UNDERFLOW_SHIFT)

/*
 * Transmit collision counter, low byte. With bits 2 to 0 of register 1 it forms
 * an 11-bit count. Reading it after reset with no frames sent gives zero, which
 * the drivers use to tell the 80C03 from the 8003.
 */
/* tx_collisions_low: r8, space rd, reset 0x0; NetBSD SEEQ register header,
 * Linux SEEQ driver header, OpenBSD sq driver, IRIX driver use */
#define SEEQ_8003_TX_COLLISIONS_LOW_OFFSET           0x0u /* inferred */

/*
 * Transmit collision counter, high bits. Only bits 2 to 0 are described; the
 * other bits are unknown.
 */
/* tx_collisions_high: r8, space rd, reset 0x0; NetBSD SEEQ register header,
 * Linux SEEQ driver header, IRIX driver use */
#define SEEQ_8003_TX_COLLISIONS_HIGH_OFFSET          0x1u /* inferred */
#define SEEQ_8003_TX_COLLISIONS_HIGH_COUNT_BITS_10_8_SHIFT 0 /* inferred */
#define SEEQ_8003_TX_COLLISIONS_HIGH_COUNT_BITS_10_8_MASK 0x7u
#define SEEQ_8003_TX_COLLISIONS_HIGH_COUNT_BITS_10_8_INPLACE (SEEQ_8003_TX_COLLISIONS_HIGH_COUNT_BITS_10_8_MASK << SEEQ_8003_TX_COLLISIONS_HIGH_COUNT_BITS_10_8_SHIFT)

/*
 * Total collision counter, low byte. The sources do not give the counter's full
 * width.
 */
/* total_collisions_low: r8, space rd, reset 0x0; NetBSD SEEQ register header,
 * Linux SEEQ driver header, OpenBSD sq driver */
#define SEEQ_8003_TOTAL_COLLISIONS_LOW_OFFSET        0x2u /* inferred */

/*
 * Total collision counter, high bits. The width and bit layout are not stated:
 * unknown.
 */
/* total_collisions_high: r8, space rd, reset 0x0; NetBSD SEEQ register header,
 * Linux SEEQ driver header, OpenBSD sq driver */
#define SEEQ_8003_TOTAL_COLLISIONS_HIGH_OFFSET       0x3u /* inferred */

/*
 * Test register. The sources say do not use it.
 */
/* test_read: r8, space rd, reset unknown; NetBSD SEEQ register header (80C03
 * read table) */
#define SEEQ_8003_TEST_READ_OFFSET                   0x4u /* inferred */

/*
 * Collision-test and carrier flags.
 */
/* sqe_and_carrier: r8, space rd, reset unknown; NetBSD SEEQ register header
 * (80C03 read table); Linux SEEQ driver header */
#define SEEQ_8003_SQE_AND_CARRIER_OFFSET             0x5u /* inferred */
#define SEEQ_8003_SQE_AND_CARRIER_NO_CARRIER_FLAG_SHIFT 1 /* inferred */
#define SEEQ_8003_SQE_AND_CARRIER_NO_CARRIER_FLAG_MASK 0x1u
#define SEEQ_8003_SQE_AND_CARRIER_NO_CARRIER_FLAG_INPLACE (SEEQ_8003_SQE_AND_CARRIER_NO_CARRIER_FLAG_MASK << SEEQ_8003_SQE_AND_CARRIER_NO_CARRIER_FLAG_SHIFT)
#define SEEQ_8003_SQE_AND_CARRIER_SQE_FLAG_SHIFT     0 /* inferred */
#define SEEQ_8003_SQE_AND_CARRIER_SQE_FLAG_MASK      0x1u
#define SEEQ_8003_SQE_AND_CARRIER_SQE_FLAG_INPLACE (SEEQ_8003_SQE_AND_CARRIER_SQE_FLAG_MASK << SEEQ_8003_SQE_AND_CARRIER_SQE_FLAG_SHIFT)

/*
 * Receive status for the frame of interest. Reading it clears the receive
 * interrupt. Bit 7 is old/new. Old/new is set on a read or on reset, and
 * cleared when status is loaded for a frame of interest. While it is zero the
 * register is write-protected, and a frame that arrives before it is read is
 * discarded and its status is not loaded.
 */
/* rx_status: r8, space rd, reset 0x80; SEEQ 8003 EDLC data sheet, MD400024/B,
 * p. 4-7 */
#define SEEQ_8003_RX_STATUS_OFFSET                   0x6u /* established */
#define SEEQ_8003_RX_STATUS_OLD_NEW_SHIFT            7 /* established */
#define SEEQ_8003_RX_STATUS_OLD_NEW_MASK             0x1u
#define SEEQ_8003_RX_STATUS_OLD_NEW_INPLACE (SEEQ_8003_RX_STATUS_OLD_NEW_MASK << SEEQ_8003_RX_STATUS_OLD_NEW_SHIFT)
#define SEEQ_8003_RX_STATUS_GOOD_FRAME_SHIFT         5 /* established */
#define SEEQ_8003_RX_STATUS_GOOD_FRAME_MASK          0x1u
#define SEEQ_8003_RX_STATUS_GOOD_FRAME_INPLACE (SEEQ_8003_RX_STATUS_GOOD_FRAME_MASK << SEEQ_8003_RX_STATUS_GOOD_FRAME_SHIFT)
#define SEEQ_8003_RX_STATUS_END_OF_FRAME_SHIFT       4 /* established */
#define SEEQ_8003_RX_STATUS_END_OF_FRAME_MASK        0x1u
#define SEEQ_8003_RX_STATUS_END_OF_FRAME_INPLACE (SEEQ_8003_RX_STATUS_END_OF_FRAME_MASK << SEEQ_8003_RX_STATUS_END_OF_FRAME_SHIFT)
#define SEEQ_8003_RX_STATUS_SHORT_FRAME_SHIFT        3 /* established */
#define SEEQ_8003_RX_STATUS_SHORT_FRAME_MASK         0x1u
#define SEEQ_8003_RX_STATUS_SHORT_FRAME_INPLACE (SEEQ_8003_RX_STATUS_SHORT_FRAME_MASK << SEEQ_8003_RX_STATUS_SHORT_FRAME_SHIFT)
#define SEEQ_8003_RX_STATUS_DRIBBLE_ERROR_SHIFT      2 /* established */
#define SEEQ_8003_RX_STATUS_DRIBBLE_ERROR_MASK       0x1u
#define SEEQ_8003_RX_STATUS_DRIBBLE_ERROR_INPLACE (SEEQ_8003_RX_STATUS_DRIBBLE_ERROR_MASK << SEEQ_8003_RX_STATUS_DRIBBLE_ERROR_SHIFT)
#define SEEQ_8003_RX_STATUS_CRC_ERROR_SHIFT          1 /* established */
#define SEEQ_8003_RX_STATUS_CRC_ERROR_MASK           0x1u
#define SEEQ_8003_RX_STATUS_CRC_ERROR_INPLACE (SEEQ_8003_RX_STATUS_CRC_ERROR_MASK << SEEQ_8003_RX_STATUS_CRC_ERROR_SHIFT)
#define SEEQ_8003_RX_STATUS_OVERFLOW_SHIFT           0 /* established */
#define SEEQ_8003_RX_STATUS_OVERFLOW_MASK            0x1u
#define SEEQ_8003_RX_STATUS_OVERFLOW_INPLACE (SEEQ_8003_RX_STATUS_OVERFLOW_MASK << SEEQ_8003_RX_STATUS_OVERFLOW_SHIFT)

/*
 * Transmit status. Reading it clears the transmit interrupt. Bit 7 is old/new:
 * set on each read and on reset, and cleared when new status is loaded at the
 * end of each transmission or retransmission attempt.
 */
/* tx_status: r8, space rd, reset 0x80; SEEQ 8003 EDLC data sheet, MD400024/B,
 * pp. 4-5, 4-6 */
#define SEEQ_8003_TX_STATUS_OFFSET                   0x7u /* established */
#define SEEQ_8003_TX_STATUS_OLD_NEW_SHIFT            7 /* established */
#define SEEQ_8003_TX_STATUS_OLD_NEW_MASK             0x1u
#define SEEQ_8003_TX_STATUS_OLD_NEW_INPLACE (SEEQ_8003_TX_STATUS_OLD_NEW_MASK << SEEQ_8003_TX_STATUS_OLD_NEW_SHIFT)
#define SEEQ_8003_TX_STATUS_SUCCESS_SHIFT            3 /* established */
#define SEEQ_8003_TX_STATUS_SUCCESS_MASK             0x1u
#define SEEQ_8003_TX_STATUS_SUCCESS_INPLACE (SEEQ_8003_TX_STATUS_SUCCESS_MASK << SEEQ_8003_TX_STATUS_SUCCESS_SHIFT)
#define SEEQ_8003_TX_STATUS_SIXTEEN_COLLISIONS_SHIFT 2 /* established */
#define SEEQ_8003_TX_STATUS_SIXTEEN_COLLISIONS_MASK  0x1u
#define SEEQ_8003_TX_STATUS_SIXTEEN_COLLISIONS_INPLACE (SEEQ_8003_TX_STATUS_SIXTEEN_COLLISIONS_MASK << SEEQ_8003_TX_STATUS_SIXTEEN_COLLISIONS_SHIFT)
#define SEEQ_8003_TX_STATUS_COLLISION_SHIFT          1 /* established */
#define SEEQ_8003_TX_STATUS_COLLISION_MASK           0x1u
#define SEEQ_8003_TX_STATUS_COLLISION_INPLACE (SEEQ_8003_TX_STATUS_COLLISION_MASK << SEEQ_8003_TX_STATUS_COLLISION_SHIFT)
#define SEEQ_8003_TX_STATUS_UNDERFLOW_SHIFT          0 /* established */
#define SEEQ_8003_TX_STATUS_UNDERFLOW_MASK           0x1u
#define SEEQ_8003_TX_STATUS_UNDERFLOW_INPLACE (SEEQ_8003_TX_STATUS_UNDERFLOW_MASK << SEEQ_8003_TX_STATUS_UNDERFLOW_SHIFT)

#define SEEQ_8003_SERVICE_INTERVAL_NS                0x320u /* established */

#endif /* SEEQ_8003_GEN_H */
