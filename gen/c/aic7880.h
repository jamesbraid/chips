/* generated from defs/aic7880.toml by defs-gen - do not edit, change the source */
/* Adaptec AIC-7880 SCSI controller on the O2: host DMA and SCB register contract */
#ifndef AIC7880_GEN_H
#define AIC7880_GEN_H

#include <stdint.h>


/*
 * SCSI transfer control 0, the first of two transfer-control registers. Bits 5 and 0 are not used and read zero. The two self-clearing controls, CLRSTCNT and CLRCHN, read back as zero. The reset value is not stated in the cited pages.
 */
/* sxfrctl0: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 74-75 (printed 4-5 and 4-6); sibling */
#define AIC7880_SXFRCTL0_OFFSET                      0x1u /* inferred */
#define AIC7880_SXFRCTL0_DFON_SHIFT                  7 /* inferred */
#define AIC7880_SXFRCTL0_DFON_MASK                   0x1u
#define AIC7880_SXFRCTL0_DFON_INPLACE                (AIC7880_SXFRCTL0_DFON_MASK << AIC7880_SXFRCTL0_DFON_SHIFT)
#define AIC7880_SXFRCTL0_CLRSTCNT_SHIFT              4 /* inferred */
#define AIC7880_SXFRCTL0_CLRSTCNT_MASK               0x1u
#define AIC7880_SXFRCTL0_CLRSTCNT_INPLACE            (AIC7880_SXFRCTL0_CLRSTCNT_MASK << AIC7880_SXFRCTL0_CLRSTCNT_SHIFT)
#define AIC7880_SXFRCTL0_SPIOEN_SHIFT                3 /* inferred */
#define AIC7880_SXFRCTL0_SPIOEN_MASK                 0x1u
#define AIC7880_SXFRCTL0_SPIOEN_INPLACE              (AIC7880_SXFRCTL0_SPIOEN_MASK << AIC7880_SXFRCTL0_SPIOEN_SHIFT)
#define AIC7880_SXFRCTL0_CLRCHN_SHIFT                1 /* inferred */
#define AIC7880_SXFRCTL0_CLRCHN_MASK                 0x1u
#define AIC7880_SXFRCTL0_CLRCHN_INPLACE              (AIC7880_SXFRCTL0_CLRCHN_MASK << AIC7880_SXFRCTL0_CLRCHN_SHIFT)

/*
 * SCSI control signals. The read side returns the state of the bus control signals. The write side sets the initiator output levels, and its three upper bits are the phase the chip expects on the next REQ pulse. The two sides share one offset and the same bit positions. Every write-side bit is cleared by chip reset, by a SCSI bus reset and by Bus Free. The read side has no reset value in the cited pages. The book's own register description gives the read side as a stale copy of the bus, which reads as the bus state.
 */
/* scsisig: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 77-78 (printed 4-8 and 4.9); sibling */
#define AIC7880_SCSISIG_OFFSET                       0x3u /* inferred */
#define AIC7880_SCSISIG_CD_SHIFT                     7 /* inferred */
#define AIC7880_SCSISIG_CD_MASK                      0x1u
#define AIC7880_SCSISIG_CD_INPLACE                   (AIC7880_SCSISIG_CD_MASK << AIC7880_SCSISIG_CD_SHIFT)
#define AIC7880_SCSISIG_IO_SHIFT                     6 /* inferred */
#define AIC7880_SCSISIG_IO_MASK                      0x1u
#define AIC7880_SCSISIG_IO_INPLACE                   (AIC7880_SCSISIG_IO_MASK << AIC7880_SCSISIG_IO_SHIFT)
#define AIC7880_SCSISIG_MSG_SHIFT                    5 /* inferred */
#define AIC7880_SCSISIG_MSG_MASK                     0x1u
#define AIC7880_SCSISIG_MSG_INPLACE                  (AIC7880_SCSISIG_MSG_MASK << AIC7880_SCSISIG_MSG_SHIFT)
#define AIC7880_SCSISIG_ATN_SHIFT                    4 /* inferred */
#define AIC7880_SCSISIG_ATN_MASK                     0x1u
#define AIC7880_SCSISIG_ATN_INPLACE                  (AIC7880_SCSISIG_ATN_MASK << AIC7880_SCSISIG_ATN_SHIFT)
#define AIC7880_SCSISIG_SEL_SHIFT                    3 /* inferred */
#define AIC7880_SCSISIG_SEL_MASK                     0x1u
#define AIC7880_SCSISIG_SEL_INPLACE                  (AIC7880_SCSISIG_SEL_MASK << AIC7880_SCSISIG_SEL_SHIFT)
#define AIC7880_SCSISIG_BSY_SHIFT                    2 /* inferred */
#define AIC7880_SCSISIG_BSY_MASK                     0x1u
#define AIC7880_SCSISIG_BSY_INPLACE                  (AIC7880_SCSISIG_BSY_MASK << AIC7880_SCSISIG_BSY_SHIFT)
#define AIC7880_SCSISIG_REQ_SHIFT                    1 /* inferred */
#define AIC7880_SCSISIG_REQ_MASK                     0x1u
#define AIC7880_SCSISIG_REQ_INPLACE                  (AIC7880_SCSISIG_REQ_MASK << AIC7880_SCSISIG_REQ_SHIFT)
#define AIC7880_SCSISIG_ACK_SHIFT                    0 /* inferred */
#define AIC7880_SCSISIG_ACK_MASK                     0x1u
#define AIC7880_SCSISIG_ACK_INPLACE                  (AIC7880_SCSISIG_ACK_MASK << AIC7880_SCSISIG_ACK_SHIFT)

/*
 * SCSI data latch used for automatic and manual PIO, one byte per access. The book says an access drives the SCSI ACK (as initiator) or REQ (as target) active as it happens. The value after chip reset is unknown, and valid data loads after the first REQ and ACK. The high byte in 16-bit mode is a separate register and is not described here.
 */
/* scsidatl: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 81 (printed 4-12); sibling */
#define AIC7880_SCSIDATL_OFFSET                      0x6u /* inferred */

/*
 * SCSI interrupt mask 0. Setting a bit enables the matching SSTAT0 status to assert the SCSI interrupt. Only the bit this unit uses is listed here.
 */
/* simode0: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 91 (printed 4-22); sibling */
#define AIC7880_SIMODE0_OFFSET                       0x10u /* inferred */
#define AIC7880_SIMODE0_ENSPIORDY_SHIFT              1 /* inferred */
#define AIC7880_SIMODE0_ENSPIORDY_MASK               0x1u
#define AIC7880_SIMODE0_ENSPIORDY_INPLACE            (AIC7880_SIMODE0_ENSPIORDY_MASK << AIC7880_SIMODE0_ENSPIORDY_SHIFT)

/*
 * SCSI data bus, read directly. The book says the data is gated from the bus to the internal data bus and is not latched in the SCSI module. A read therefore sees the byte on the bus without taking the latch. Nothing in the cited pages says it acknowledges the byte, and the book ties the ACK drive to SCSIDATL accesses, so this read is taken not to acknowledge (inferred from the book's wording, not stated).
 */
/* scsibusl: r8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 93 (printed 4-24); sibling */
#define AIC7880_SCSIBUSL_OFFSET                      0x12u /* inferred */

/*
 * Sequencer control. Bit 4 selects the sequencer clock divider, bit 2 requests one single step, bit 1 resets the sequencer RAM address pointer and bit 0 gives the host access to sequencer RAM. Bit 6 disables the host pause request. Bits 7, 5 and 3 (PERRORDIS, FAILDIS and BRKADRINTEN) are in the book but are not described on this unit. The reset value is the one the book's bit table gives in parentheses, not a value read after initialisation.
 */
/* seqctl: rw8, reset 0x90; Adaptec AIC-7870 Data Book, PDF p. 98 (printed 4-29); sibling */
#define AIC7880_SEQCTL_OFFSET                        0x60u /* inferred */
#define AIC7880_SEQCTL_PAUSEDIS_SHIFT                6 /* inferred */
#define AIC7880_SEQCTL_PAUSEDIS_MASK                 0x1u
#define AIC7880_SEQCTL_PAUSEDIS_INPLACE              (AIC7880_SEQCTL_PAUSEDIS_MASK << AIC7880_SEQCTL_PAUSEDIS_SHIFT)
#define AIC7880_SEQCTL_FASTMODE_SHIFT                4 /* inferred */
#define AIC7880_SEQCTL_FASTMODE_MASK                 0x1u
#define AIC7880_SEQCTL_FASTMODE_INPLACE              (AIC7880_SEQCTL_FASTMODE_MASK << AIC7880_SEQCTL_FASTMODE_SHIFT)
#define AIC7880_SEQCTL_STEP_SHIFT                    2 /* inferred */
#define AIC7880_SEQCTL_STEP_MASK                     0x1u
#define AIC7880_SEQCTL_STEP_INPLACE                  (AIC7880_SEQCTL_STEP_MASK << AIC7880_SEQCTL_STEP_SHIFT)
#define AIC7880_SEQCTL_SEQRESET_SHIFT                1 /* inferred */
#define AIC7880_SEQCTL_SEQRESET_MASK                 0x1u
#define AIC7880_SEQCTL_SEQRESET_INPLACE              (AIC7880_SEQCTL_SEQRESET_MASK << AIC7880_SEQCTL_SEQRESET_SHIFT)
#define AIC7880_SEQCTL_LOADRAM_SHIFT                 0 /* inferred */
#define AIC7880_SEQCTL_LOADRAM_MASK                  0x1u
#define AIC7880_SEQCTL_LOADRAM_INPLACE               (AIC7880_SEQCTL_LOADRAM_MASK << AIC7880_SEQCTL_LOADRAM_SHIFT)

/*
 * Low eight bits of the sequencer RAM address that executes on the next clock edge. The driver writes it while the sequencer is paused to change where execution resumes, and uses it as the start address when loading sequencer RAM. While loading, the address steps up after every fourth byte. A write to SEQADDR[1:0] clears that byte index. RST# and CHIPRST clear the address to zero.
 */
/* seqaddr0: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF p. 99 (printed 4-30); sibling */
#define AIC7880_SEQADDR0_OFFSET                      0x62u /* inferred */

/*
 * Bit 0 is bit 8 of the sequencer RAM address, which covers the 512 instruction words. Bits 7 to 1 are reserved in the book, and their read-back is not stated. RST# and CHIPRST clear the register.
 */
/* seqaddr1: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF p. 99 (printed 4-30); sibling */
#define AIC7880_SEQADDR1_OFFSET                      0x63u /* inferred */
#define AIC7880_SEQADDR1_ADDR8_SHIFT                 0 /* inferred */
#define AIC7880_SEQADDR1_ADDR8_MASK                  0x1u
#define AIC7880_SEQADDR1_ADDR8_INPLACE               (AIC7880_SEQADDR1_ADDR8_MASK << AIC7880_SEQADDR1_ADDR8_SHIFT)

/*
 * Read-only port that returns 0xff to the host and to the sequencer. It is a source for logical and arithmetic functions. The book gives no write function, so a write is outside the published interface and its effect stays unknown.
 */
/* allones: r8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 102 (printed 4-33); sibling */
#define AIC7880_ALLONES_OFFSET                       0x69u /* inferred */

/*
 * Read returns 0x00 and does not return an earlier write. Written as the destination NONE, the byte is discarded and no location changes. Both directions share the offset, so the write side is described here rather than as a separate register.
 */
/* allzeros: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 102-103 (printed 4-33 to 4-34); sibling */
#define AIC7880_ALLZEROS_OFFSET                      0x6au /* inferred */

/*
 * A write stores the byte. Bits 6:4 form an octal value, and a read returns the one-hot byte with bit N set, where N is that value. The book does not define the meaning of bits 7 and 3:0, whether a write keeps them, or the reset value. Those stay unknown.
 */
/* function1: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 104 (printed 4-35); sibling */
#define AIC7880_FUNCTION1_OFFSET                     0x6eu /* inferred */
#define AIC7880_FUNCTION1_SELECT_SHIFT               4 /* inferred */
#define AIC7880_FUNCTION1_SELECT_MASK                0x7u
#define AIC7880_FUNCTION1_SELECT_INPLACE             (AIC7880_FUNCTION1_SELECT_MASK << AIC7880_FUNCTION1_SELECT_SHIFT)

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
#define AIC7880_DFCNTRL_WIDEODD_SHIFT                6 /* inferred */
#define AIC7880_DFCNTRL_WIDEODD_MASK                 0x1u
#define AIC7880_DFCNTRL_WIDEODD_INPLACE              (AIC7880_DFCNTRL_WIDEODD_MASK << AIC7880_DFCNTRL_WIDEODD_SHIFT)
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
