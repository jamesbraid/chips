/* generated from devices/ics1890/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 2677952e5dcb35c5d7263390a75249ba01d1e1a2864c98a6cfa1dfe1b408648f */
/* ICS1890 10Base-T/100Base-TX PHYceiver, MII management registers (Octane base I/O) */
#ifndef ICS1890_GEN_H
#define ICS1890_GEN_H

#include <stdint.h>


/* enum model */
#define ICS1890_MODEL_ICS1889                        1 /* established */
#define ICS1890_MODEL_ICS1890                        2 /* established */

/* enum revision */
#define ICS1890_REVISION_INTERNAL                    0 /* established */
#define ICS1890_REVISION_ALPHA                       1 /* established */
#define ICS1890_REVISION_GENERAL                     2 /* established */
#define ICS1890_REVISION_J_OR_LATER                  3 /* established */

/*
 * PHY identifier, first word: the low 16 bits of the 24-bit OUI. The part resets to the Integrated Circuit Systems OUI. Writes take effect only after the command override bit of register 16 is set, so each write needs that bit set first.
 */
/* phy_id1: rw16, space mii, reset 0x15; ICS1890 revision G datasheet, PHY identifier register (register 2), PDF p. 23 (printed p. 23) */
#define ICS1890_PHY_ID1_OFFSET                       0x2u /* established */
#define ICS1890_PHY_ID1_OUI_LOW_SHIFT                0 /* established */
#define ICS1890_PHY_ID1_OUI_LOW_MASK                 0xffffu
#define ICS1890_PHY_ID1_OUI_LOW_INPLACE              (ICS1890_PHY_ID1_OUI_LOW_MASK << ICS1890_PHY_ID1_OUI_LOW_SHIFT)

/*
 * PHY identifier, second word: OUI bits 19 to 24, the model number and the revision number. Reset value is the ICS1890 identity. Writes need the command override bit of register 16, as for register 2.
 */
/* phy_id2: rw16, space mii, reset 0xf423; ICS1890 revision G datasheet, PHY identifier register (register 3), PDF p. 24 (printed p. 24) */
#define ICS1890_PHY_ID2_OFFSET                       0x3u /* established */
#define ICS1890_PHY_ID2_OUI_HIGH_SHIFT               10 /* established */
#define ICS1890_PHY_ID2_OUI_HIGH_MASK                0x3fu
#define ICS1890_PHY_ID2_OUI_HIGH_INPLACE             (ICS1890_PHY_ID2_OUI_HIGH_MASK << ICS1890_PHY_ID2_OUI_HIGH_SHIFT)
#define ICS1890_PHY_ID2_MODEL_SHIFT                  4 /* established */
#define ICS1890_PHY_ID2_MODEL_MASK                   0x3fu
#define ICS1890_PHY_ID2_MODEL_INPLACE                (ICS1890_PHY_ID2_MODEL_MASK << ICS1890_PHY_ID2_MODEL_SHIFT)
#define ICS1890_PHY_ID2_REVISION_SHIFT               0 /* established */
#define ICS1890_PHY_ID2_REVISION_MASK                0xfu
#define ICS1890_PHY_ID2_REVISION_INPLACE             (ICS1890_PHY_ID2_REVISION_MASK << ICS1890_PHY_ID2_REVISION_SHIFT)

/*
 * Extended control. Pre-programs the part; reset loads the defaults from the datasheet's table. Only the bits below are transcribed here. Other bits (for example the stream cipher and scrambler controls) are in the datasheet's full table and are not part of this unit yet, so the reset value of the whole register is unknown here.
 */
/* ext_ctrl: rw16, space mii, reset unknown; ICS1890 revision G datasheet, extended control register (register 16), PDF p. 29 (printed p. 29) */
#define ICS1890_EXT_CTRL_OFFSET                      0x10u /* established */
#define ICS1890_EXT_CTRL_COMMAND_OVERRIDE_SHIFT      15 /* established */
#define ICS1890_EXT_CTRL_COMMAND_OVERRIDE_MASK       0x1u
#define ICS1890_EXT_CTRL_COMMAND_OVERRIDE_INPLACE    (ICS1890_EXT_CTRL_COMMAND_OVERRIDE_MASK << ICS1890_EXT_CTRL_COMMAND_OVERRIDE_SHIFT)
#define ICS1890_EXT_CTRL_PHY_ADDRESS_SHIFT           6 /* established */
#define ICS1890_EXT_CTRL_PHY_ADDRESS_MASK            0x1fu
#define ICS1890_EXT_CTRL_PHY_ADDRESS_INPLACE         (ICS1890_EXT_CTRL_PHY_ADDRESS_MASK << ICS1890_EXT_CTRL_PHY_ADDRESS_SHIFT)
#define ICS1890_EXT_CTRL_RESERVED_ICS_4_SHIFT        4 /* established */
#define ICS1890_EXT_CTRL_RESERVED_ICS_4_MASK         0x1u
#define ICS1890_EXT_CTRL_RESERVED_ICS_4_INPLACE      (ICS1890_EXT_CTRL_RESERVED_ICS_4_MASK << ICS1890_EXT_CTRL_RESERVED_ICS_4_SHIFT)

#endif /* ICS1890_GEN_H */
