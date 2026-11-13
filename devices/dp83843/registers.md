<!-- generated from devices/dp83843/registers.toml by defs-gen - do not edit, change the source -->

# National DP83843 PHYTER 10/100 Mb/s transceiver, MII registers (Origin 300 IO-8)

The MII management registers of the DP83843 transceiver on the Origin 300 IO-8 board. The IOC3 Ethernet controller reaches the part through its MII port, so only the registers a guest can read or write through that port are here. Offsets are MII register numbers, one per 16-bit register. The registers below are the ones the DP83843 datasheet, revision B, describes with bit meanings or reset values; the rest of the register map is not transcribed. The DP83840A that the Origin 200 carries is a different part with its own bit meanings for registers 0x17 and 0x18, and it is not described by this unit. Grades say how each item was derived from the datasheet; none of it was measured on a board, and reset values are unknown unless stated.

Unit `dp83843`, macro prefix `DP83843`.
Default source: DP83843 revision B datasheet.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| mii | register index | MII management registers, addressed by register number through the controller's MII port. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `bmcr` | 0x0 | rw | 16 |  | mii | unknown | inferred | DP83843 revision B datasheet, basic mode control register; register number from the clause 22 numbering, not re-read against the PDF |
| `bmsr` | 0x1 | r | 16 |  | mii | 0x7849 | inferred | DP83843 revision B datasheet, basic mode status register; register number from the clause 22 numbering, not re-read against the PDF |
| `aner` | 0x6 | r | 16 |  | mii | 0x4 | inferred | DP83843 revision B datasheet, autonegotiation expansion register; register number from the clause 22 numbering, not re-read against the PDF |
| `lbr` | 0x17 | rw | 16 |  | mii | 0x0 | established | DP83843 revision B datasheet, loopback register, PDF pp. 59-62 (printed pp. 58-61), Table 21 |
| `btscr` | 0x18 | rw | 16 |  | mii | 0x0 | established | DP83843 revision B datasheet, 10BASE-T status and control register, PDF pp. 59-62 (printed pp. 58-61), Table 21 |

### Register `bmcr`

Basic mode control. Reset value not stated by the datasheet text consulted.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 14 | `loopback` | established |  | DP83843 revision B datasheet, PDF p. 48 (printed p. 47), Table 6 | Loopback. Setting it also sets LBR bits 5 and 4 (see the lbr register). What clearing it does to those LBR bits is not stated. |
| 13 | `speed_100` | established |  | DP83843 revision B datasheet, PDF pp. 47-48 (printed pp. 46-47), Table 6 | Forced speed select, used only when autonegotiation is disabled: one for 100 Mb/s, zero for 10 Mb/s. |
| 12 | `an_enable` | established |  | DP83843 revision B datasheet, PDF pp. 47-48 (printed pp. 46-47), Table 6 | Autonegotiation enable. Clearing it makes bits 13 and 8 select the forced speed and duplex. |
| 11 | `power_down` | established |  | DP83843 revision B datasheet, PDF p. 47 (printed p. 46), Table 6 | Power down. Minimum-power mode: the part cannot transmit or receive on an active network, does not do Wake-on-LAN, and does not react to received data while set. Reset default zero. |
| 10 | `isolate` | established |  | DP83843 revision B datasheet, PDF p. 48 (printed p. 47), Table 6, and section 3.9, PDF p. 34 (printed p. 33) | Isolate from the MII. While set the part ignores TXD, TX_EN and TX_ER, and its MII outputs (TX_CLK, RX_CLK, RX_DV, RX_ER, RXD, COL, CRS) are high impedance. Serial management still answers, and the TD outputs keep sourcing idles or link pulses. Reset default is one only when the PHY address latches 00000, otherwise zero; the datasheet gives no other reset rule. After reset only software changes it. |
| 9 | `restart_an` | established |  | DP83843 revision B datasheet, PDF p. 48 (printed p. 47), Table 6 | Restart autonegotiation. Read and write; it reads one until the PHY initiates autonegotiation and then clears, and clearing it by software does not stop that negotiation. With autonegotiation disabled (bit 12 clear) it has no function and should be cleared. The datasheet does not state the time of that clear relative to the break-link interval, which is an open question on the chip page. |
| 8 | `duplex` | established |  | DP83843 revision B datasheet, PDF pp. 47-48 (printed pp. 46-47), Table 6 | Forced duplex, used only when autonegotiation is disabled: one for full duplex, zero for half. |
| 7 | `collision_test` | established |  | DP83843 revision B datasheet, PDF p. 48 (printed p. 47), Table 6 | Collision test. When set, COL asserts within 512 bit times of TX_EN asserting and deasserts within 4 bit times after TX_EN deasserts. Reset default zero. |

### Register `bmsr`

Basic mode status, read only. The reset value is the one the datasheet gives with no link and no completed autonegotiation, not a value read from a running part.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `preamble_suppression` | established |  | DP83843 revision B datasheet, PDF pp. 48-49 (printed pp. 47-48), Table 7 | Preamble suppression capability. Permanently one. |
| 5 | `an_complete` | established |  | DP83843 revision B datasheet, PDF pp. 49 (printed p. 48), Table 7 | Autonegotiation complete. Reports a finished negotiation. It is separate from link status: a forced-mode link can be up with this bit clear. |
| 2 | `link_status` | established |  | DP83843 revision B datasheet, PDF pp. 49 (printed p. 48), Table 7 | Link status, meaning a valid 10 or 100 Mb/s link. It latches low on a link loss and stays low until software reads the register. The datasheet leaves the link-validity criteria to the implementation. |

### Register `aner`

Autonegotiation expansion, read only. The reset value is the datasheet's value with no completed negotiation.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `next_page_able` | established |  | DP83843 revision B datasheet, PDF p. 53 (printed p. 52) | Next-page capability. Permanently one. |

### Register `lbr`

Loopback register. Reset zero is the value in the nominal table for copper, nibble-mode straps. Bits 13 to 7 are bypass bits that the datasheet marks strap-dependent, so the reset of those bits on a board depends on its straps; the board's straps are unverified. Bit 6 is a digital loopback selection that the register table marks reserved and read only, which conflicts with a prose section on the same bit; it has no field here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9:7 | `data_path_100` | established |  | DP83843 revision B datasheet, PDF p. 34 (printed p. 33) | 100 Mb/s data-path selection. Within the strap-dependent range 13 to 7. The datasheet says writing BMCR loopback returns this field to normal operation. |
| 5 | `tw_loopback` | established |  | DP83843 revision B datasheet, PDF pp. 59-62 (printed pp. 58-61), Table 21 | Twisted-pair (Twister) loopback enable. The datasheet says BMCR loopback sets it automatically. |
| 4 | `endec_10_loopback` | established |  | DP83843 revision B datasheet, PDF pp. 59-62 (printed pp. 58-61), Table 21 | 10 Mb/s ENDEC loopback enable. The datasheet says BMCR loopback sets it automatically. |

### Register `btscr`

10BASE-T status and control. Reset zero is the nominal-table value for copper, nibble-mode straps, with the strap-dependent serial bits 12 and 11 left out.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `full_duplex_or_repeater_readback` | established |  | DP83843 revision B datasheet, PDF pp. 59-62 (printed pp. 58-61), Table 21 | Reads as one in full-duplex or repeater mode, per the datasheet. The datasheet text consulted does not give its value in other modes. |
