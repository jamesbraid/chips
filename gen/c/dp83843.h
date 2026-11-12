/* generated from defs/dp83843.toml by defs-gen - do not edit, change the source */
/* National DP83843 PHYTER 10/100 Mb/s transceiver, MII registers (Origin 300 IO-8) */
#ifndef DP83843_GEN_H
#define DP83843_GEN_H

#include <stdint.h>


/*
 * Basic mode control. Reset value not stated by the datasheet text consulted.
 */
/* bmcr: rw16, space mii, reset unknown; DP83843 revision B datasheet, basic mode control register; register number from the clause 22 numbering, not re-read against the PDF */
#define DP83843_BMCR_OFFSET                          0x0u /* inferred */
#define DP83843_BMCR_LOOPBACK_SHIFT                  14 /* established */
#define DP83843_BMCR_LOOPBACK_MASK                   0x1u
#define DP83843_BMCR_LOOPBACK_INPLACE                (DP83843_BMCR_LOOPBACK_MASK << DP83843_BMCR_LOOPBACK_SHIFT)
#define DP83843_BMCR_SPEED_100_SHIFT                 13 /* established */
#define DP83843_BMCR_SPEED_100_MASK                  0x1u
#define DP83843_BMCR_SPEED_100_INPLACE               (DP83843_BMCR_SPEED_100_MASK << DP83843_BMCR_SPEED_100_SHIFT)
#define DP83843_BMCR_AN_ENABLE_SHIFT                 12 /* established */
#define DP83843_BMCR_AN_ENABLE_MASK                  0x1u
#define DP83843_BMCR_AN_ENABLE_INPLACE               (DP83843_BMCR_AN_ENABLE_MASK << DP83843_BMCR_AN_ENABLE_SHIFT)
#define DP83843_BMCR_POWER_DOWN_SHIFT                11 /* established */
#define DP83843_BMCR_POWER_DOWN_MASK                 0x1u
#define DP83843_BMCR_POWER_DOWN_INPLACE              (DP83843_BMCR_POWER_DOWN_MASK << DP83843_BMCR_POWER_DOWN_SHIFT)
#define DP83843_BMCR_ISOLATE_SHIFT                   10 /* established */
#define DP83843_BMCR_ISOLATE_MASK                    0x1u
#define DP83843_BMCR_ISOLATE_INPLACE                 (DP83843_BMCR_ISOLATE_MASK << DP83843_BMCR_ISOLATE_SHIFT)
#define DP83843_BMCR_RESTART_AN_SHIFT                9 /* established */
#define DP83843_BMCR_RESTART_AN_MASK                 0x1u
#define DP83843_BMCR_RESTART_AN_INPLACE              (DP83843_BMCR_RESTART_AN_MASK << DP83843_BMCR_RESTART_AN_SHIFT)
#define DP83843_BMCR_DUPLEX_SHIFT                    8 /* established */
#define DP83843_BMCR_DUPLEX_MASK                     0x1u
#define DP83843_BMCR_DUPLEX_INPLACE                  (DP83843_BMCR_DUPLEX_MASK << DP83843_BMCR_DUPLEX_SHIFT)
#define DP83843_BMCR_COLLISION_TEST_SHIFT            7 /* established */
#define DP83843_BMCR_COLLISION_TEST_MASK             0x1u
#define DP83843_BMCR_COLLISION_TEST_INPLACE          (DP83843_BMCR_COLLISION_TEST_MASK << DP83843_BMCR_COLLISION_TEST_SHIFT)

/*
 * Basic mode status, read only. The reset value is the one the datasheet gives with no link and no completed autonegotiation, not a value read from a running part.
 */
/* bmsr: r16, space mii, reset 0x7849; DP83843 revision B datasheet, basic mode status register; register number from the clause 22 numbering, not re-read against the PDF */
#define DP83843_BMSR_OFFSET                          0x1u /* inferred */
#define DP83843_BMSR_PREAMBLE_SUPPRESSION_SHIFT      6 /* established */
#define DP83843_BMSR_PREAMBLE_SUPPRESSION_MASK       0x1u
#define DP83843_BMSR_PREAMBLE_SUPPRESSION_INPLACE    (DP83843_BMSR_PREAMBLE_SUPPRESSION_MASK << DP83843_BMSR_PREAMBLE_SUPPRESSION_SHIFT)
#define DP83843_BMSR_AN_COMPLETE_SHIFT               5 /* established */
#define DP83843_BMSR_AN_COMPLETE_MASK                0x1u
#define DP83843_BMSR_AN_COMPLETE_INPLACE             (DP83843_BMSR_AN_COMPLETE_MASK << DP83843_BMSR_AN_COMPLETE_SHIFT)
#define DP83843_BMSR_LINK_STATUS_SHIFT               2 /* established */
#define DP83843_BMSR_LINK_STATUS_MASK                0x1u
#define DP83843_BMSR_LINK_STATUS_INPLACE             (DP83843_BMSR_LINK_STATUS_MASK << DP83843_BMSR_LINK_STATUS_SHIFT)

/*
 * Autonegotiation expansion, read only. The reset value is the datasheet's value with no completed negotiation.
 */
/* aner: r16, space mii, reset 0x4; DP83843 revision B datasheet, autonegotiation expansion register; register number from the clause 22 numbering, not re-read against the PDF */
#define DP83843_ANER_OFFSET                          0x6u /* inferred */
#define DP83843_ANER_NEXT_PAGE_ABLE_SHIFT            2 /* established */
#define DP83843_ANER_NEXT_PAGE_ABLE_MASK             0x1u
#define DP83843_ANER_NEXT_PAGE_ABLE_INPLACE          (DP83843_ANER_NEXT_PAGE_ABLE_MASK << DP83843_ANER_NEXT_PAGE_ABLE_SHIFT)

/*
 * Loopback register. Reset zero is the value in the nominal table for copper, nibble-mode straps. Bits 13 to 7 are bypass bits that the datasheet marks strap-dependent, so the reset of those bits on a board depends on its straps; the board's straps are unverified. Bit 6 is a digital loopback selection that the register table marks reserved and read only, which conflicts with a prose section on the same bit; it has no field here.
 */
/* lbr: rw16, space mii, reset 0x0; DP83843 revision B datasheet, loopback register, PDF pp. 59-62 (printed pp. 58-61), Table 21 */
#define DP83843_LBR_OFFSET                           0x17u /* established */
#define DP83843_LBR_DATA_PATH_100_SHIFT              7 /* established */
#define DP83843_LBR_DATA_PATH_100_MASK               0x7u
#define DP83843_LBR_DATA_PATH_100_INPLACE            (DP83843_LBR_DATA_PATH_100_MASK << DP83843_LBR_DATA_PATH_100_SHIFT)
#define DP83843_LBR_TW_LOOPBACK_SHIFT                5 /* established */
#define DP83843_LBR_TW_LOOPBACK_MASK                 0x1u
#define DP83843_LBR_TW_LOOPBACK_INPLACE              (DP83843_LBR_TW_LOOPBACK_MASK << DP83843_LBR_TW_LOOPBACK_SHIFT)
#define DP83843_LBR_ENDEC_10_LOOPBACK_SHIFT          4 /* established */
#define DP83843_LBR_ENDEC_10_LOOPBACK_MASK           0x1u
#define DP83843_LBR_ENDEC_10_LOOPBACK_INPLACE        (DP83843_LBR_ENDEC_10_LOOPBACK_MASK << DP83843_LBR_ENDEC_10_LOOPBACK_SHIFT)

/*
 * 10BASE-T status and control. Reset zero is the nominal-table value for copper, nibble-mode straps, with the strap-dependent serial bits 12 and 11 left out.
 */
/* btscr: rw16, space mii, reset 0x0; DP83843 revision B datasheet, 10BASE-T status and control register, PDF pp. 59-62 (printed pp. 58-61), Table 21 */
#define DP83843_BTSCR_OFFSET                         0x18u /* established */
#define DP83843_BTSCR_FULL_DUPLEX_OR_REPEATER_READBACK_SHIFT 7 /* established */
#define DP83843_BTSCR_FULL_DUPLEX_OR_REPEATER_READBACK_MASK 0x1u
#define DP83843_BTSCR_FULL_DUPLEX_OR_REPEATER_READBACK_INPLACE (DP83843_BTSCR_FULL_DUPLEX_OR_REPEATER_READBACK_MASK << DP83843_BTSCR_FULL_DUPLEX_OR_REPEATER_READBACK_SHIFT)

#endif /* DP83843_GEN_H */
