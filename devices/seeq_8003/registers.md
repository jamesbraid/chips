<!-- generated from devices/seeq_8003/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 46e4c83c2a7f9205b932e74d0bfe059d566640f9dd13045c1daa4fdc6db8b16f -->

# SEEQ 8003 and 80C03 Ethernet data link controller (Indy)

The SEEQ EDLC behind the Indy's HPC3: its eight byte-wide registers, the bank-selected writes and the collision counters of the 80C03 additions, and the receive and transmit command and status bytes. Offsets are byte offsets within the chip, selected by A2 to A0; behind HPC3, register n sits at 4n from the SEEQ window. Grades say how each item was derived: established means read in the SEEQ 8003 data sheet; inferred means the 80C03 additions, which rest on public drivers because the 80C03 data sheet is not held, or a driver's use of a register; unknown means the sources do not settle it. Nothing here was measured on a board. The receive and transmit DMA channels are in the HPC3 unit, and the prose is in devices/seeq_8003/README.md.

Unit `seeq_8003`, macro prefix `SEEQ_8003`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| bank0 | byte | Writes to registers 0 to 5 in bank 0, which hold the station address. The plain 8003 has no banks and always writes here. |
| bank1 | byte | Writes to registers 0 to 5 while transmit command bits 6:5 select bank 1 (80C03). |
| bank2 | byte | Writes to registers 0 to 4 while transmit command bits 6:5 select bank 2 (80C03). |
| cmd | byte | Writes to registers 6 and 7: the receive and transmit command bytes. These are not banked. |
| rd | byte | Reads. Registers 6 and 7 are the receive and transmit status. Registers 0 to 5 read back the 80C03 counters and flags; the plain 8003 has no read there. Whether bank selection changes these reads is unknown. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `station_address` | 0x0 | w | 8 | 6 | bank0 | unknown | established | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-5 |
| `multicast_hash_low` | 0x0 | w | 8 | 6 | bank1 | unknown | inferred | NetBSD SEEQ register header (80C03 bank layout); Linux SEEQ driver header; IRIX driver use |
| `multicast_hash_high` | 0x0 | w | 8 | 2 | bank2 | unknown | inferred | NetBSD SEEQ register header (80C03 bank layout); Linux SEEQ driver header; IRIX driver use |
| `inter_packet_gap` | 0x2 | w | 8 |  | bank2 | unknown | inferred | HPC3 Chip Specification, revision 1.4, p. 14 (SEEQ extended register x02); IRIX driver use; Linux SEEQ driver header; NetBSD SEEQ register header |
| `control` | 0x3 | w | 8 |  | bank2 | unknown | inferred | NetBSD SEEQ register header and Linux SEEQ driver header, which agree on every bit |
| `configuration` | 0x4 | w | 8 |  | bank2 | unknown | inferred | NetBSD SEEQ register header only |
| `rx_command` | 0x6 | w | 8 |  | cmd | 0x0 (SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7) | established | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 |
| `tx_command` | 0x7 | w | 8 |  | cmd | 0x0 (SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6; bank bits from the 80C03 additions) | established | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6; bank bits from the 80C03 additions |
| `tx_collisions_low` | 0x0 | r | 8 |  | rd | 0x0 | inferred | NetBSD SEEQ register header, Linux SEEQ driver header, OpenBSD sq driver, IRIX driver use |
| `tx_collisions_high` | 0x1 | r | 8 |  | rd | 0x0 | inferred | NetBSD SEEQ register header, Linux SEEQ driver header, IRIX driver use |
| `total_collisions_low` | 0x2 | r | 8 |  | rd | 0x0 | inferred | NetBSD SEEQ register header, Linux SEEQ driver header, OpenBSD sq driver |
| `total_collisions_high` | 0x3 | r | 8 |  | rd | 0x0 | inferred | NetBSD SEEQ register header, Linux SEEQ driver header, OpenBSD sq driver |
| `test_read` | 0x4 | r | 8 |  | rd | unknown | inferred | NetBSD SEEQ register header (80C03 read table) |
| `sqe_and_carrier` | 0x5 | r | 8 |  | rd | unknown | inferred | NetBSD SEEQ register header (80C03 read table); Linux SEEQ driver header |
| `rx_status` | 0x6 | r | 8 |  | rd | 0x80 (SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7) | established | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 |
| `tx_status` | 0x7 | r | 8 |  | rd | 0x80 (SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6) | established | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6 |

### Register `station_address`

Station address bytes 0 to 5, one per register. Byte 0 bit 0 is the first bit on the wire. The data sheet's reset list does not name the station address registers, so their reset value is unknown.

Array of 6 registers, stride 1.

### Register `multicast_hash_low`

Multicast hash bytes 0 to 5, written with bank 1 selected. Used with the multicast hash filter enable in the control register.

Array of 6 registers, stride 1.

### Register `multicast_hash_high`

Multicast hash bytes 6 and 7, written at bank 2 registers 0 and 1.

Array of 2 registers, stride 1.

### Register `inter_packet_gap`

Inter-packet gap byte. HPC3 writes each transmit descriptor's gap here when its write-control bit is set. The sources read it as the gap, but the encoding of the byte is unknown. The IRIX driver computes it from a tunable, Linux writes zero, and NetBSD's header calls the register reserved and writes zero.

### Register `control`

Counter, flag and filter control. Writing a zero and then a one to a counter or flag enable clears the counter or flag. The sources do not give the register's reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `no_carrier_flag_enable` | inferred |  | NetBSD SEEQ register header and Linux SEEQ driver header, which agree on every bit | Enables and, on the 0 to 1 edge, clears the no-carrier flag. |
| 4 | `receive_short_frames` | inferred |  | NetBSD SEEQ register header and Linux SEEQ driver header, which agree on every bit | Receives short frames. |
| 3 | `multicast_hash_enable` | inferred |  | NetBSD SEEQ register header and Linux SEEQ driver header, which agree on every bit | Enables the multicast hash filter. |
| 2 | `sqe_flag_enable` | inferred |  | NetBSD SEEQ register header and Linux SEEQ driver header, which agree on every bit | Enables and, on the 0 to 1 edge, clears the SQE flag. |
| 1 | `total_collision_count_enable` | inferred |  | NetBSD SEEQ register header and Linux SEEQ driver header, which agree on every bit | Enables and, on the 0 to 1 edge, clears the total collision counter. |
| 0 | `tx_collision_count_enable` | inferred |  | NetBSD SEEQ register header and Linux SEEQ driver header, which agree on every bit | Enables and, on the 0 to 1 edge, clears the transmit collision counter. |

### Register `configuration`

80C03 configuration: auto-pad, no preamble, do not receive own frames, no CRC, AutoDUPLEX, CRC to FIFO and fast discard, as NetBSD's header names them. The bit positions are not stated in the sources. No Indy driver writes it; OpenBSD's write is compiled out.

### Register `rx_command`

Receive command. Reset clears it. Bits 5 to 0 enable interrupts for each receive condition. Bit 0 also makes overflow frames frames of interest. Bits 7 and 6 set the match mode.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `match_mode` | established | receive_match (receiver_off=0, all_frames=1, station_and_broadcast=2, station_broadcast_and_multicast=3) | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 | Address match mode. |
| 5 | `int_good_frame` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 | Interrupt on good frame. |
| 4 | `int_end_of_frame` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 | Interrupt on end of frame, for any frame except overflow. |
| 3 | `int_short_frame` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 | Interrupt on short frame. |
| 2 | `int_dribble_error` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 | Interrupt on dribble error. |
| 1 | `int_crc_error` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 | Interrupt on CRC error. |
| 0 | `int_overflow` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-6, 4-7 | Interrupt on overflow; makes overflow frames frames of interest. |

### Register `tx_command`

Transmit command. Reset clears it. Bits 3 to 0 enable interrupts for each transmit condition. Bits 6 and 5 select the register bank for writes to registers 0 to 5 on the 80C03.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:5 | `bank` | inferred | bank_select (bank0=0, bank1=1, bank2=2) | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6; bank bits from the 80C03 additions | Register bank for writes to registers 0 to 5 (80C03). The value 3 is not described: unknown. |
| 3 | `int_success` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6; bank bits from the 80C03 additions | Interrupt on successful transmit. |
| 2 | `int_sixteen_collisions` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6; bank bits from the 80C03 additions | Interrupt on sixteen collisions. |
| 1 | `int_collision` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6; bank bits from the 80C03 additions | Interrupt on collision. |
| 0 | `int_underflow` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6; bank bits from the 80C03 additions | Interrupt on underflow. |

### Register `tx_collisions_low`

Transmit collision counter, low byte. With bits 2 to 0 of register 1 it forms an 11-bit count. Reading it after reset with no frames sent gives zero, which the drivers use to tell the 80C03 from the 8003.

### Register `tx_collisions_high`

Transmit collision counter, high bits. Only bits 2 to 0 are described; the other bits are unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2:0 | `count_bits_10_8` | inferred |  | NetBSD SEEQ register header, Linux SEEQ driver header, IRIX driver use | Bits 10 to 8 of the transmit collision counter. |

### Register `total_collisions_low`

Total collision counter, low byte. The sources do not give the counter's full width.

### Register `total_collisions_high`

Total collision counter, high bits. The width and bit layout are not stated: unknown.

### Register `test_read`

Test register. The sources say do not use it.

### Register `sqe_and_carrier`

Collision-test and carrier flags.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `no_carrier_flag` | inferred |  | NetBSD SEEQ register header (80C03 read table); Linux SEEQ driver header | No-carrier flag. |
| 0 | `sqe_flag` | inferred |  | NetBSD SEEQ register header (80C03 read table); Linux SEEQ driver header | SQE flag. |

### Register `rx_status`

Receive status for the frame of interest. Reading it clears the receive interrupt. Bit 7 is old/new. Old/new is set on a read or on reset, and cleared when status is loaded for a frame of interest. While it is zero the register is write-protected, and a frame that arrives before it is read is discarded and its status is not loaded.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `old_new` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 | Old/new: one when the status is new and may be read, zero while it is write-protected. |
| 5 | `good_frame` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 | Good frame. |
| 4 | `end_of_frame` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 | End of frame. Set for any frame type except overflow. |
| 3 | `short_frame` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 | Short frame. |
| 2 | `dribble_error` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 | Dribble error. |
| 1 | `crc_error` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 | CRC error. |
| 0 | `overflow` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, p. 4-7 | Receive FIFO overflow. |

### Register `tx_status`

Transmit status. Reading it clears the transmit interrupt. Bit 7 is old/new: set on each read and on reset, and cleared when new status is loaded at the end of each transmission or retransmission attempt.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `old_new` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6 | Old/new, as above. |
| 3 | `success` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6 | Transmitted without error. |
| 2 | `sixteen_collisions` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6 | Sixteen collisions in a row; the frame was given up. |
| 1 | `collision` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6 | Collision. |
| 0 | `underflow` | established |  | SEEQ 8003 EDLC data sheet, MD400024/B, pp. 4-5, 4-6 | Underflow: the transmit stopped on an empty FIFO. |

## Enums

### Enum `bank_select`

| Label | Value | Grade | Source |
|---|---|---|---|
| `bank0` | 0 | inferred |  |
| `bank1` | 1 | inferred |  |
| `bank2` | 2 | inferred |  |

### Enum `receive_match`

| Label | Value | Grade | Source |
|---|---|---|---|
| `receiver_off` | 0 | established |  |
| `all_frames` | 1 | established |  |
| `station_and_broadcast` | 2 | established |  |
| `station_broadcast_and_multicast` | 3 | established |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `SERVICE_INTERVAL_NS` | 0x320 | established |  |  |
