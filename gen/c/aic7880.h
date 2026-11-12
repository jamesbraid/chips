/* generated from defs/aic7880.toml by defs-gen - do not edit, change the source */
/* Adaptec AIC-7880 SCSI controller on the O2: host DMA and SCB register contract */
#ifndef AIC7880_GEN_H
#define AIC7880_GEN_H

#include <stdint.h>


/*
 * Host PCI address for the host DMA transfer, four byte registers at 0x88 to 0x8b. Loading it also loads SHADDR. The byte significance across the four bytes is not in the cited extract and stays unknown. Read-back is not stated.
 */
/* lhaddr: rw32, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 139-140 (printed 4-70 to 4-71); sibling */
#define AIC7880_LHADDR_OFFSET                        0x88u /* inferred */

/*
 * 24-bit host transfer count in three byte registers at 0x8c to 0x8e. A zero count inhibits host PCI requests. Loading a nonzero count clears HDONE. The byte significance across the three bytes is not in the cited extract and stays unknown. Read-back is not stated.
 */
/* hcnt: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 139-140 (printed 4-70 to 4-71); sibling */
#define AIC7880_HCNT_OFFSET                          0x8cu /* inferred */
#define AIC7880_HCNT_COUNT                           3
#define AIC7880_HCNT_STRIDE                          1

/*
 * SCB page select latch. All eight bits read back as written, whether or not external SRAM is selected and however much of it is fitted, so a read-back of 0xff does not show that page 255 exists. Selects one 32-byte page for the SCB window and for SCBCNT-addressed accesses. Reset is zero as the cited book's reset description gives it, not a value read after initialisation.
 */
/* scbptr: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 53, 63-64, 153 and 180; sibling */
#define AIC7880_SCBPTR_OFFSET                        0x90u /* inferred */

/*
 * Data FIFO control. Bits 5 and 4 enable SCSI and SCSI-block DMA, bit 3 enables host DMA, bit 2 selects the direction, bit 1 flushes the FIFO and bit 0 resets it and self-clears. Cleared by PCI RST# and by the chip reset in HCNTRL. Read-back is not stated. The reset value is the cleared state the chip reset produces, not a value read after initialisation.
 */
/* dfcntrl: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 139, 145-148 (printed 4-70, 4-76 to 4-79); sibling */
#define AIC7880_DFCNTRL_OFFSET                       0x93u /* inferred */
#define AIC7880_DFCNTRL_SCSIEN_SHIFT                 5 /* inferred */
#define AIC7880_DFCNTRL_SCSIEN_MASK                  0x1u
#define AIC7880_DFCNTRL_SCSIEN_INPLACE               (AIC7880_DFCNTRL_SCSIEN_MASK << AIC7880_DFCNTRL_SCSIEN_SHIFT)
#define AIC7880_DFCNTRL_SDMAEN_SHIFT                 4 /* inferred */
#define AIC7880_DFCNTRL_SDMAEN_MASK                  0x1u
#define AIC7880_DFCNTRL_SDMAEN_INPLACE               (AIC7880_DFCNTRL_SDMAEN_MASK << AIC7880_DFCNTRL_SDMAEN_SHIFT)
#define AIC7880_DFCNTRL_HDMAEN_SHIFT                 3 /* inferred */
#define AIC7880_DFCNTRL_HDMAEN_MASK                  0x1u
#define AIC7880_DFCNTRL_HDMAEN_INPLACE               (AIC7880_DFCNTRL_HDMAEN_MASK << AIC7880_DFCNTRL_HDMAEN_SHIFT)
#define AIC7880_DFCNTRL_DIRECTION_SHIFT              2 /* inferred */
#define AIC7880_DFCNTRL_DIRECTION_MASK               0x1u
#define AIC7880_DFCNTRL_DIRECTION_INPLACE            (AIC7880_DFCNTRL_DIRECTION_MASK << AIC7880_DFCNTRL_DIRECTION_SHIFT)
#define AIC7880_DFCNTRL_FIFOFLUSH_SHIFT              1 /* inferred */
#define AIC7880_DFCNTRL_FIFOFLUSH_MASK               0x1u
#define AIC7880_DFCNTRL_FIFOFLUSH_INPLACE            (AIC7880_DFCNTRL_FIFOFLUSH_MASK << AIC7880_DFCNTRL_FIFOFLUSH_SHIFT)
#define AIC7880_DFCNTRL_FIFORESET_SHIFT              0 /* inferred */
#define AIC7880_DFCNTRL_FIFORESET_MASK               0x1u
#define AIC7880_DFCNTRL_FIFORESET_INPLACE            (AIC7880_DFCNTRL_FIFORESET_MASK << AIC7880_DFCNTRL_FIFORESET_SHIFT)

/*
 * Data FIFO status. Reports FIFOEMP, FIFOFULL, FIFOQWDEMP, MREQPEND and HDONE. The bit positions are not in the cited extract, so no field is listed here and they stay unknown. MREQPEND is a pending need, not a PCI request in flight.
 */
/* dfstatus: r8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 145-148 (printed 4-76 to 4-79); sibling */
#define AIC7880_DFSTATUS_OFFSET                      0x94u /* inferred */

/*
 * SCB byte counter. Bits 6:5 read zero. With SCBAUTO clear the window offset selects the byte and the counter is not used. With SCBAUTO set the counter replaces the window offset, advances once per completed logical SCB byte access and wraps within the 32-byte page. Reset is zero as the cited book's reset description gives it.
 */
/* scbcnt: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 63-64, 153-154, 176-177 and 180; sibling */
#define AIC7880_SCBCNT_OFFSET                        0x9au /* inferred */
#define AIC7880_SCBCNT_SCBAUTO_SHIFT                 7 /* inferred */
#define AIC7880_SCBCNT_SCBAUTO_MASK                  0x1u
#define AIC7880_SCBCNT_SCBAUTO_INPLACE               (AIC7880_SCBCNT_SCBAUTO_MASK << AIC7880_SCBCNT_SCBAUTO_SHIFT)
#define AIC7880_SCBCNT_SCBOFS_SHIFT                  0 /* inferred */
#define AIC7880_SCBCNT_SCBOFS_MASK                   0x1fu
#define AIC7880_SCBCNT_SCBOFS_INPLACE                (AIC7880_SCBCNT_SCBOFS_MASK << AIC7880_SCBCNT_SCBOFS_SHIFT)

/*
 * SCB window: 32 byte positions of the page that SCBPTR selects. Sequencer accesses are byte wide. Host reads are byte wide. Host writes are byte wide in either SCBAUTO mode, and a full four-byte write is accepted only with SCBAUTO set, filling four successive positions. Host access needs a paused sequencer or the automatic access pause. Byte order of the four data bytes against the CPU is not in the cited extract and stays unknown.
 */
/* scbwin: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 63-64, 153-154 and 176-177; sibling */
#define AIC7880_SCBWIN_OFFSET                        0xa0u /* inferred */
#define AIC7880_SCBWIN_COUNT                         32
#define AIC7880_SCBWIN_STRIDE                        1

#endif /* AIC7880_GEN_H */
