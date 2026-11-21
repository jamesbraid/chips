/* generated from devices/aic7880/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 ac8f8281afc714636b4ace8e210fce455439bfb20a364794f5b732f8998e4655 */
/* Adaptec AIC-7880 SCSI controller on the O2: host DMA and SCB register contract */
#ifndef AIC7880_GEN_H
#define AIC7880_GEN_H

#include <stdint.h>


/*
 * SCSI sequence control. Each bit enables one hardware selection or reselection sequence, or drives SCSI RESET#. A SCSI bus reset clears every bit except SCSIRSTO. The register reads back, so software can set and clear bits without a scratch copy.
 */
/* scsiseq: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 72-73 (printed 4-3 and 4-4); sibling */
#define AIC7880_SCSISEQ_OFFSET                       0x0u /* inferred */
#define AIC7880_SCSISEQ_TEMODEO_SHIFT                7 /* inferred */
#define AIC7880_SCSISEQ_TEMODEO_MASK                 0x1u
#define AIC7880_SCSISEQ_TEMODEO_INPLACE              (AIC7880_SCSISEQ_TEMODEO_MASK << AIC7880_SCSISEQ_TEMODEO_SHIFT)
#define AIC7880_SCSISEQ_ENSELO_SHIFT                 6 /* inferred */
#define AIC7880_SCSISEQ_ENSELO_MASK                  0x1u
#define AIC7880_SCSISEQ_ENSELO_INPLACE               (AIC7880_SCSISEQ_ENSELO_MASK << AIC7880_SCSISEQ_ENSELO_SHIFT)
#define AIC7880_SCSISEQ_ENSELI_SHIFT                 5 /* inferred */
#define AIC7880_SCSISEQ_ENSELI_MASK                  0x1u
#define AIC7880_SCSISEQ_ENSELI_INPLACE               (AIC7880_SCSISEQ_ENSELI_MASK << AIC7880_SCSISEQ_ENSELI_SHIFT)
#define AIC7880_SCSISEQ_ENRSELI_SHIFT                4 /* inferred */
#define AIC7880_SCSISEQ_ENRSELI_MASK                 0x1u
#define AIC7880_SCSISEQ_ENRSELI_INPLACE              (AIC7880_SCSISEQ_ENRSELI_MASK << AIC7880_SCSISEQ_ENRSELI_SHIFT)
#define AIC7880_SCSISEQ_ENAUTOATNO_SHIFT             3 /* inferred */
#define AIC7880_SCSISEQ_ENAUTOATNO_MASK              0x1u
#define AIC7880_SCSISEQ_ENAUTOATNO_INPLACE           (AIC7880_SCSISEQ_ENAUTOATNO_MASK << AIC7880_SCSISEQ_ENAUTOATNO_SHIFT)
#define AIC7880_SCSISEQ_ENAUTOATNI_SHIFT             2 /* inferred */
#define AIC7880_SCSISEQ_ENAUTOATNI_MASK              0x1u
#define AIC7880_SCSISEQ_ENAUTOATNI_INPLACE           (AIC7880_SCSISEQ_ENAUTOATNI_MASK << AIC7880_SCSISEQ_ENAUTOATNI_SHIFT)
#define AIC7880_SCSISEQ_ENAUTOATNP_SHIFT             1 /* inferred */
#define AIC7880_SCSISEQ_ENAUTOATNP_MASK              0x1u
#define AIC7880_SCSISEQ_ENAUTOATNP_INPLACE           (AIC7880_SCSISEQ_ENAUTOATNP_MASK << AIC7880_SCSISEQ_ENAUTOATNP_SHIFT)
#define AIC7880_SCSISEQ_SCSIRSTO_SHIFT               0 /* inferred */
#define AIC7880_SCSISEQ_SCSIRSTO_MASK                0x1u
#define AIC7880_SCSISEQ_SCSIRSTO_INPLACE             (AIC7880_SCSISEQ_SCSIRSTO_MASK << AIC7880_SCSISEQ_SCSIRSTO_SHIFT)

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
 * SCSI transfer control 1. Holds the bit-bucket and wrap controls, the parity check enable, the selection timer and its interval, active negation and the termination power enable. Every bit reads zero after reset.
 */
/* sxfrctl1: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 75-76 (printed 4-6 and 4-7); sibling */
#define AIC7880_SXFRCTL1_OFFSET                      0x2u /* inferred */
#define AIC7880_SXFRCTL1_BITBUCKET_SHIFT             7 /* inferred */
#define AIC7880_SXFRCTL1_BITBUCKET_MASK              0x1u
#define AIC7880_SXFRCTL1_BITBUCKET_INPLACE           (AIC7880_SXFRCTL1_BITBUCKET_MASK << AIC7880_SXFRCTL1_BITBUCKET_SHIFT)
#define AIC7880_SXFRCTL1_SWRAPEN_SHIFT               6 /* inferred */
#define AIC7880_SXFRCTL1_SWRAPEN_MASK                0x1u
#define AIC7880_SXFRCTL1_SWRAPEN_INPLACE             (AIC7880_SXFRCTL1_SWRAPEN_MASK << AIC7880_SXFRCTL1_SWRAPEN_SHIFT)
#define AIC7880_SXFRCTL1_ENSPCHK_SHIFT               5 /* inferred */
#define AIC7880_SXFRCTL1_ENSPCHK_MASK                0x1u
#define AIC7880_SXFRCTL1_ENSPCHK_INPLACE             (AIC7880_SXFRCTL1_ENSPCHK_MASK << AIC7880_SXFRCTL1_ENSPCHK_SHIFT)
#define AIC7880_SXFRCTL1_STIMESEL_SHIFT              3 /* inferred */
#define AIC7880_SXFRCTL1_STIMESEL_MASK               0x3u
#define AIC7880_SXFRCTL1_STIMESEL_INPLACE            (AIC7880_SXFRCTL1_STIMESEL_MASK << AIC7880_SXFRCTL1_STIMESEL_SHIFT)
#define AIC7880_SXFRCTL1_ENSTIMER_SHIFT              2 /* inferred */
#define AIC7880_SXFRCTL1_ENSTIMER_MASK               0x1u
#define AIC7880_SXFRCTL1_ENSTIMER_INPLACE            (AIC7880_SXFRCTL1_ENSTIMER_MASK << AIC7880_SXFRCTL1_ENSTIMER_SHIFT)
#define AIC7880_SXFRCTL1_ACTNEGEN_SHIFT              1 /* inferred */
#define AIC7880_SXFRCTL1_ACTNEGEN_MASK               0x1u
#define AIC7880_SXFRCTL1_ACTNEGEN_INPLACE            (AIC7880_SXFRCTL1_ACTNEGEN_MASK << AIC7880_SXFRCTL1_ACTNEGEN_SHIFT)
#define AIC7880_SXFRCTL1_STPWEN_SHIFT                0 /* inferred */
#define AIC7880_SXFRCTL1_STPWEN_MASK                 0x1u
#define AIC7880_SXFRCTL1_STPWEN_INPLACE              (AIC7880_SXFRCTL1_STPWEN_MASK << AIC7880_SXFRCTL1_STPWEN_SHIFT)

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
 * SCSI rate control for DATA. Wide DATA needs this register's WIDEXFER bit and the SBLKCTL SELWIDE bit both set. The sibling's page shows every bit of the register resetting to zero. Bits 6 to 4 select the synchronous transfer rate. Read-back is not stated.
 */
/* scsirate: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 79 and 97; sibling */
#define AIC7880_SCSIRATE_OFFSET                      0x4u /* inferred */
#define AIC7880_SCSIRATE_WIDE_SHIFT                  7 /* inferred */
#define AIC7880_SCSIRATE_WIDE_MASK                   0x1u
#define AIC7880_SCSIRATE_WIDE_INPLACE                (AIC7880_SCSIRATE_WIDE_MASK << AIC7880_SCSIRATE_WIDE_SHIFT)
#define AIC7880_SCSIRATE_SXFR_SHIFT                  4 /* inferred */
#define AIC7880_SCSIRATE_SXFR_MASK                   0x7u
#define AIC7880_SCSIRATE_SXFR_INPLACE                (AIC7880_SCSIRATE_SXFR_MASK << AIC7880_SCSIRATE_SXFR_SHIFT)
#define AIC7880_SCSIRATE_SOFS_SHIFT                  0 /* inferred */
#define AIC7880_SCSIRATE_SOFS_MASK                   0xfu
#define AIC7880_SCSIRATE_SOFS_INPLACE                (AIC7880_SCSIRATE_SOFS_MASK << AIC7880_SCSIRATE_SOFS_SHIFT)

/*
 * Target ID in bits 7:4 and own ID in bits 3:0. Both are four-bit fields, so the sibling addresses IDs 0 to 15 on the wide connection. Chip and PCI reset clear both nibbles. The own ID is the initiator's address during Selection Out. Public drivers commonly write own ID 7 after reset. That is software configuration, not a reset value.
 */
/* scsiid: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF p. 80; sibling */
#define AIC7880_SCSIID_OFFSET                        0x5u /* inferred */
#define AIC7880_SCSIID_TID_SHIFT                     4 /* inferred */
#define AIC7880_SCSIID_TID_MASK                      0xfu
#define AIC7880_SCSIID_TID_INPLACE                   (AIC7880_SCSIID_TID_MASK << AIC7880_SCSIID_TID_SHIFT)
#define AIC7880_SCSIID_OID_SHIFT                     0 /* inferred */
#define AIC7880_SCSIID_OID_MASK                      0xfu
#define AIC7880_SCSIID_OID_INPLACE                   (AIC7880_SCSIID_OID_MASK << AIC7880_SCSIID_OID_SHIFT)

/*
 * SCSI data latch used for automatic and manual PIO, one byte per access. The book says an access drives the SCSI ACK (as initiator) or REQ (as target) active as it happens. The value after chip reset is unknown, and valid data loads after the first REQ and ACK. The high byte in 16-bit mode is a separate register and is not described here.
 */
/* scsidatl: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 81 (printed 4-12); sibling */
#define AIC7880_SCSIDATL_OFFSET                      0x6u /* inferred */

/*
 * Write-only SCSI interrupt clears. Only CLRATNO, bit 6, is listed here; the bit positions of the other clears (CLRREQINIT, CLRPHASECHG, CLRBUSFREE) are not in the cited extract. Writing one to CLRATNO clears the initiator ATN output set through SCSISIGO. Read-back is not stated.
 */
/* clrsint1: w8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 78 and 86; sibling; Linux aic7xxx.reg (db2ddb87143519e20a95aa36c60b36107b736a58) */
#define AIC7880_CLRSINT1_OFFSET                      0xcu /* inferred */
#define AIC7880_CLRSINT1_CLRATNO_SHIFT               6 /* inferred */
#define AIC7880_CLRSINT1_CLRATNO_MASK                0x1u
#define AIC7880_CLRSINT1_CLRATNO_INPLACE             (AIC7880_CLRSINT1_CLRATNO_MASK << AIC7880_CLRSINT1_CLRATNO_SHIFT)

/*
 * SCSI interrupt mask 0. Setting a bit enables the matching SSTAT0 status to assert the SCSI interrupt. Only the bit this unit uses is listed here.
 */
/* simode0: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 91 (printed 4-22); sibling */
#define AIC7880_SIMODE0_OFFSET                       0x10u /* inferred */
#define AIC7880_SIMODE0_ENSPIORDY_SHIFT              1 /* inferred */
#define AIC7880_SIMODE0_ENSPIORDY_MASK               0x1u
#define AIC7880_SIMODE0_ENSPIORDY_INPLACE            (AIC7880_SIMODE0_ENSPIORDY_MASK << AIC7880_SIMODE0_ENSPIORDY_SHIFT)

/*
 * SCSI interrupt mask 1. Each set bit lets the matching SSTAT1 status assert SCSIINT on IRQA#.
 */
/* simode1: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF p. 92 (printed 4-23); sibling */
#define AIC7880_SIMODE1_OFFSET                       0x11u /* inferred */
#define AIC7880_SIMODE1_ENSELTIMO_SHIFT              7 /* inferred */
#define AIC7880_SIMODE1_ENSELTIMO_MASK               0x1u
#define AIC7880_SIMODE1_ENSELTIMO_INPLACE            (AIC7880_SIMODE1_ENSELTIMO_MASK << AIC7880_SIMODE1_ENSELTIMO_SHIFT)
#define AIC7880_SIMODE1_ENATNTARG_SHIFT              6 /* inferred */
#define AIC7880_SIMODE1_ENATNTARG_MASK               0x1u
#define AIC7880_SIMODE1_ENATNTARG_INPLACE            (AIC7880_SIMODE1_ENATNTARG_MASK << AIC7880_SIMODE1_ENATNTARG_SHIFT)
#define AIC7880_SIMODE1_ENSCSIRST_SHIFT              5 /* inferred */
#define AIC7880_SIMODE1_ENSCSIRST_MASK               0x1u
#define AIC7880_SIMODE1_ENSCSIRST_INPLACE            (AIC7880_SIMODE1_ENSCSIRST_MASK << AIC7880_SIMODE1_ENSCSIRST_SHIFT)
#define AIC7880_SIMODE1_ENPHASEMIS_SHIFT             4 /* inferred */
#define AIC7880_SIMODE1_ENPHASEMIS_MASK              0x1u
#define AIC7880_SIMODE1_ENPHASEMIS_INPLACE           (AIC7880_SIMODE1_ENPHASEMIS_MASK << AIC7880_SIMODE1_ENPHASEMIS_SHIFT)
#define AIC7880_SIMODE1_ENBUSFREE_SHIFT              3 /* inferred */
#define AIC7880_SIMODE1_ENBUSFREE_MASK               0x1u
#define AIC7880_SIMODE1_ENBUSFREE_INPLACE            (AIC7880_SIMODE1_ENBUSFREE_MASK << AIC7880_SIMODE1_ENBUSFREE_SHIFT)
#define AIC7880_SIMODE1_ENSCSIPERR_SHIFT             2 /* inferred */
#define AIC7880_SIMODE1_ENSCSIPERR_MASK              0x1u
#define AIC7880_SIMODE1_ENSCSIPERR_INPLACE           (AIC7880_SIMODE1_ENSCSIPERR_MASK << AIC7880_SIMODE1_ENSCSIPERR_SHIFT)
#define AIC7880_SIMODE1_ENPHASECHG_SHIFT             1 /* inferred */
#define AIC7880_SIMODE1_ENPHASECHG_MASK              0x1u
#define AIC7880_SIMODE1_ENPHASECHG_INPLACE           (AIC7880_SIMODE1_ENPHASECHG_MASK << AIC7880_SIMODE1_ENPHASECHG_SHIFT)
#define AIC7880_SIMODE1_ENREQINIT_SHIFT              0 /* inferred */
#define AIC7880_SIMODE1_ENREQINIT_MASK               0x1u
#define AIC7880_SIMODE1_ENREQINIT_INPLACE            (AIC7880_SIMODE1_ENREQINIT_MASK << AIC7880_SIMODE1_ENREQINIT_SHIFT)

/*
 * SCSI data bus, read directly. The book says the data is gated from the bus to the internal data bus and is not latched in the SCSI module. A read therefore sees the byte on the bus without taking the latch. Nothing in the cited pages says it acknowledges the byte, and the book ties the ACK drive to SCSIDATL accesses, so this read is taken not to acknowledge (inferred from the book's wording, not stated).
 */
/* scsibusl: r8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 93 (printed 4-24); sibling */
#define AIC7880_SCSIBUSL_OFFSET                      0x12u /* inferred */

/*
 * SCSI-side host address, four bytes at 0x14 to 0x17, least significant byte first, so byte n holds address bits 8n+7 to 8n. Loaded when the host address at 0x88 to 0x8b is written and HADDLDSEL is 0. Counts up while STCNT counts down. Saved by the Save Data Pointers message. Zero after reset.
 */
/* shaddr: r8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 58-59 and 93 (printed 4-24); sibling */
#define AIC7880_SHADDR_OFFSET                        0x14u /* inferred */
#define AIC7880_SHADDR_COUNT                         4
#define AIC7880_SHADDR_STRIDE                        1

/*
 * Selection and reselection ID. Holds the ID of the device that selected or reselected this controller on the last such phase.
 */
/* selid: r8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 59 and 95 (printed 4-26); sibling */
#define AIC7880_SELID_OFFSET                         0x19u /* inferred */
#define AIC7880_SELID_SELID_SHIFT                    4 /* inferred */
#define AIC7880_SELID_SELID_MASK                     0xfu
#define AIC7880_SELID_SELID_INPLACE                  (AIC7880_SELID_SELID_MASK << AIC7880_SELID_SELID_SHIFT)
#define AIC7880_SELID_ONEBIT_SHIFT                   3 /* inferred */
#define AIC7880_SELID_ONEBIT_MASK                    0x1u
#define AIC7880_SELID_ONEBIT_INPLACE                 (AIC7880_SELID_ONEBIT_MASK << AIC7880_SELID_ONEBIT_SHIFT)

/*
 * Block control. The SELWIDE bit selects the physical SCSI connection width. Its reset value follows the wide-select pin WIDEPS# sampled at reset, and the O2's strap state is unknown, so the register has no reset value here. Bits 7 and 6 reset to one, bit 5 resets to zero, and bits 4, 3, 2 and 0 read zero.
 */
/* sblkctl: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 80 and 96-97; sibling */
#define AIC7880_SBLKCTL_OFFSET                       0x1fu /* inferred */
#define AIC7880_SBLKCTL_DIAGLED_SHIFT                6 /* inferred */
#define AIC7880_SBLKCTL_DIAGLED_MASK                 0x3u
#define AIC7880_SBLKCTL_DIAGLED_INPLACE              (AIC7880_SBLKCTL_DIAGLED_MASK << AIC7880_SBLKCTL_DIAGLED_SHIFT)
#define AIC7880_SBLKCTL_AUTOFLUSHDIS_SHIFT           5 /* inferred */
#define AIC7880_SBLKCTL_AUTOFLUSHDIS_MASK            0x1u
#define AIC7880_SBLKCTL_AUTOFLUSHDIS_INPLACE         (AIC7880_SBLKCTL_AUTOFLUSHDIS_MASK << AIC7880_SBLKCTL_AUTOFLUSHDIS_SHIFT)
#define AIC7880_SBLKCTL_SELBUSB_SHIFT                3 /* inferred */
#define AIC7880_SBLKCTL_SELBUSB_MASK                 0x1u
#define AIC7880_SBLKCTL_SELBUSB_INPLACE              (AIC7880_SBLKCTL_SELBUSB_MASK << AIC7880_SBLKCTL_SELBUSB_SHIFT)
#define AIC7880_SBLKCTL_SELWIDE_SHIFT                1 /* inferred */
#define AIC7880_SBLKCTL_SELWIDE_MASK                 0x1u
#define AIC7880_SBLKCTL_SELWIDE_INPLACE              (AIC7880_SBLKCTL_SELWIDE_MASK << AIC7880_SBLKCTL_SELWIDE_SHIFT)

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
 * Accumulator: temporary holding place for sequencer ALU operations.
 */
/* accum: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 60 and 100 (printed 4-31); sibling */
#define AIC7880_ACCUM_OFFSET                         0x64u /* inferred */

/*
 * Source index: a temporary value, or the address that the sequencer's indirect source port SINDIR reads. The sequencer increments it after each indirect transfer.
 */
/* sindex: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 60 and 100; sibling */
#define AIC7880_SINDEX_OFFSET                        0x65u /* inferred */

/*
 * Destination index: a temporary value, or the address that the sequencer's indirect destination port DINDIR writes. The sequencer increments it after each indirect transfer.
 */
/* dindex: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 60 and 101; sibling */
#define AIC7880_DINDEX_OFFSET                        0x66u /* inferred */

/*
 * Low eight bits of the sequencer breakpoint address. Cleared to zero by reset.
 */
/* brkaddr0: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 60 and 101; sibling */
#define AIC7880_BRKADDR0_OFFSET                      0x67u /* inferred */

/*
 * Breakpoint disable and the top address bit. Reset to 0x80, which leaves the breakpoint disabled.
 */
/* brkaddr1: rw8, reset 0x80; Adaptec AIC-7870 Data Book, PDF pp. 60 and 102 (printed 4-33); sibling */
#define AIC7880_BRKADDR1_OFFSET                      0x68u /* inferred */
#define AIC7880_BRKADDR1_BRKDIS_SHIFT                7 /* inferred */
#define AIC7880_BRKADDR1_BRKDIS_MASK                 0x1u
#define AIC7880_BRKADDR1_BRKDIS_INPLACE              (AIC7880_BRKADDR1_BRKDIS_MASK << AIC7880_BRKADDR1_BRKDIS_SHIFT)
#define AIC7880_BRKADDR1_BRKADDR8_SHIFT              0 /* inferred */
#define AIC7880_BRKADDR1_BRKADDR8_MASK               0x1u
#define AIC7880_BRKADDR1_BRKADDR8_INPLACE            (AIC7880_BRKADDR1_BRKADDR8_MASK << AIC7880_BRKADDR1_BRKADDR8_SHIFT)

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
 * Sequencer flags, read only.
 */
/* flags: r8, reset 0x0; Adaptec AIC-7870 Data Book, PDF p. 103 (printed 4-34); sibling */
#define AIC7880_FLAGS_OFFSET                         0x6bu /* inferred */
#define AIC7880_FLAGS_ZERO_SHIFT                     1 /* inferred */
#define AIC7880_FLAGS_ZERO_MASK                      0x1u
#define AIC7880_FLAGS_ZERO_INPLACE                   (AIC7880_FLAGS_ZERO_MASK << AIC7880_FLAGS_ZERO_SHIFT)
#define AIC7880_FLAGS_CARRY_SHIFT                    0 /* inferred */
#define AIC7880_FLAGS_CARRY_MASK                     0x1u
#define AIC7880_FLAGS_CARRY_INPLACE                  (AIC7880_FLAGS_CARRY_MASK << AIC7880_FLAGS_CARRY_SHIFT)

/*
 * Sequencer-only indirect source port. A read returns the byte SINDEX addresses, then SINDEX increments. The host cannot reach this port.
 */
/* sindir: r8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 103 (printed 4-34); sibling */
#define AIC7880_SINDIR_OFFSET                        0x6cu /* inferred */

/*
 * Sequencer-only indirect destination port. A write stores the byte at the address DINDEX holds, then DINDEX increments. The host cannot reach this port.
 */
/* dindir: w8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 104 (printed 4-35); sibling */
#define AIC7880_DINDIR_OFFSET                        0x6du /* inferred */

/*
 * A write stores the byte. Bits 6:4 form an octal value, and a read returns the one-hot byte with bit N set, where N is that value. The book does not define the meaning of bits 7 and 3:0, whether a write keeps them, or the reset value. Those stay unknown.
 */
/* function1: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 104 (printed 4-35); sibling */
#define AIC7880_FUNCTION1_OFFSET                     0x6eu /* inferred */
#define AIC7880_FUNCTION1_SELECT_SHIFT               4 /* inferred */
#define AIC7880_FUNCTION1_SELECT_MASK                0x7u
#define AIC7880_FUNCTION1_SELECT_INPLACE             (AIC7880_FUNCTION1_SELECT_MASK << AIC7880_FUNCTION1_SELECT_SHIFT)

/*
 * Read-only return-stack port. Four return entries, newest first, are read one byte at a time: the low byte of an entry, then its high byte, which carries the high address bit. Each high-byte read advances the read pointer to the next entry, so eight byte reads bring the pointer back to its start. The read value after initialisation is zero. The reset values of the individual backing words are not specified in the cited pages. The book gives no write function, so a write is outside the published interface and its effect stays unknown.
 */
/* stack: r8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 60 (printed 3-6) and 105 (printed 4-36); sibling */
#define AIC7880_STACK_OFFSET                         0x6fu /* inferred */

/*
 * Data FIFO threshold select, with a read-only view of six PCI status bits. Power-on reset forces the threshold select to zero. Writes change only bits 7 and 6.
 */
/* dspcistatus: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 61 and 136 (printed 4-67); sibling */
#define AIC7880_DSPCISTATUS_OFFSET                   0x86u /* inferred */
#define AIC7880_DSPCISTATUS_DFTHRSH_SHIFT            6 /* inferred */
#define AIC7880_DSPCISTATUS_DFTHRSH_MASK             0x3u
#define AIC7880_DSPCISTATUS_DFTHRSH_INPLACE          (AIC7880_DSPCISTATUS_DFTHRSH_MASK << AIC7880_DSPCISTATUS_DFTHRSH_SHIFT)
#define AIC7880_DSPCISTATUS_PCISTATUS_SHIFT          0 /* inferred */
#define AIC7880_DSPCISTATUS_PCISTATUS_MASK           0x3fu
#define AIC7880_DSPCISTATUS_PCISTATUS_INPLACE        (AIC7880_DSPCISTATUS_PCISTATUS_MASK << AIC7880_DSPCISTATUS_PCISTATUS_SHIFT)

/*
 * Host control. RST# or a CHIPRST write sets it to 0x05: the sequencer is requested paused and chip reset is acknowledged. A write that changes PAUSE is not complete until a read returns the written value.
 */
/* hcntrl: rw8, reset 0x5; Adaptec AIC-7870 Data Book, PDF pp. 61 and 137-138 (printed 4-68 and 4-69); sibling */
#define AIC7880_HCNTRL_OFFSET                        0x87u /* inferred */
#define AIC7880_HCNTRL_POWRDN_SHIFT                  6 /* inferred */
#define AIC7880_HCNTRL_POWRDN_MASK                   0x1u
#define AIC7880_HCNTRL_POWRDN_INPLACE                (AIC7880_HCNTRL_POWRDN_MASK << AIC7880_HCNTRL_POWRDN_SHIFT)
#define AIC7880_HCNTRL_SWINT_SHIFT                   4 /* inferred */
#define AIC7880_HCNTRL_SWINT_MASK                    0x1u
#define AIC7880_HCNTRL_SWINT_INPLACE                 (AIC7880_HCNTRL_SWINT_MASK << AIC7880_HCNTRL_SWINT_SHIFT)
#define AIC7880_HCNTRL_HCNTRL3_SHIFT                 3 /* inferred */
#define AIC7880_HCNTRL_HCNTRL3_MASK                  0x1u
#define AIC7880_HCNTRL_HCNTRL3_INPLACE               (AIC7880_HCNTRL_HCNTRL3_MASK << AIC7880_HCNTRL_HCNTRL3_SHIFT)
#define AIC7880_HCNTRL_PAUSE_SHIFT                   2 /* inferred */
#define AIC7880_HCNTRL_PAUSE_MASK                    0x1u
#define AIC7880_HCNTRL_PAUSE_INPLACE                 (AIC7880_HCNTRL_PAUSE_MASK << AIC7880_HCNTRL_PAUSE_SHIFT)
#define AIC7880_HCNTRL_INTEN_SHIFT                   1 /* inferred */
#define AIC7880_HCNTRL_INTEN_MASK                    0x1u
#define AIC7880_HCNTRL_INTEN_INPLACE                 (AIC7880_HCNTRL_INTEN_MASK << AIC7880_HCNTRL_INTEN_SHIFT)
#define AIC7880_HCNTRL_CHIPRST_SHIFT                 0 /* inferred */
#define AIC7880_HCNTRL_CHIPRST_MASK                  0x1u
#define AIC7880_HCNTRL_CHIPRST_INPLACE               (AIC7880_HCNTRL_CHIPRST_MASK << AIC7880_HCNTRL_CHIPRST_SHIFT)

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
 * Interrupt status. The sequencer writes these causes, and the host reads them without pausing the sequencer. SEQINT, SCSIINT and BRKADRINT pause the sequencer at once; CMDCMPLT does not. Bits 3 to 0 clear individually through CLRINT.
 */
/* intstat: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 141-142 (printed 4-72 and 4-73); sibling */
#define AIC7880_INTSTAT_OFFSET                       0x91u /* inferred */
#define AIC7880_INTSTAT_INTCODE_SHIFT                4 /* inferred */
#define AIC7880_INTSTAT_INTCODE_MASK                 0xfu
#define AIC7880_INTSTAT_INTCODE_INPLACE              (AIC7880_INTSTAT_INTCODE_MASK << AIC7880_INTSTAT_INTCODE_SHIFT)
#define AIC7880_INTSTAT_BRKADRINT_SHIFT              3 /* inferred */
#define AIC7880_INTSTAT_BRKADRINT_MASK               0x1u
#define AIC7880_INTSTAT_BRKADRINT_INPLACE            (AIC7880_INTSTAT_BRKADRINT_MASK << AIC7880_INTSTAT_BRKADRINT_SHIFT)
#define AIC7880_INTSTAT_SCSIINT_SHIFT                2 /* inferred */
#define AIC7880_INTSTAT_SCSIINT_MASK                 0x1u
#define AIC7880_INTSTAT_SCSIINT_INPLACE              (AIC7880_INTSTAT_SCSIINT_MASK << AIC7880_INTSTAT_SCSIINT_SHIFT)
#define AIC7880_INTSTAT_CMDCMPLT_SHIFT               1 /* inferred */
#define AIC7880_INTSTAT_CMDCMPLT_MASK                0x1u
#define AIC7880_INTSTAT_CMDCMPLT_INPLACE             (AIC7880_INTSTAT_CMDCMPLT_MASK << AIC7880_INTSTAT_CMDCMPLT_SHIFT)
#define AIC7880_INTSTAT_SEQINT_SHIFT                 0 /* inferred */
#define AIC7880_INTSTAT_SEQINT_MASK                  0x1u
#define AIC7880_INTSTAT_SEQINT_INPLACE               (AIC7880_INTSTAT_SEQINT_MASK << AIC7880_INTSTAT_SEQINT_SHIFT)

/*
 * Clear interrupt, the write side of offset 0x92. A one written to a bit clears the matching INTSTAT cause; the bits self-clear, and the sequencer cannot write this register. The read side at the same offset is the ERROR register, whose causes (PCIERRSTAT, MPARERR, DPARERR, SQPARERR, ILLOPCODE) are described in the prose page.
 */
/* clrint: w8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 143-144 (printed 4-74 and 4-75); sibling */
#define AIC7880_CLRINT_OFFSET                        0x92u /* inferred */
#define AIC7880_CLRINT_CLRPARERR_SHIFT               4 /* inferred */
#define AIC7880_CLRINT_CLRPARERR_MASK                0x1u
#define AIC7880_CLRINT_CLRPARERR_INPLACE             (AIC7880_CLRINT_CLRPARERR_MASK << AIC7880_CLRINT_CLRPARERR_SHIFT)
#define AIC7880_CLRINT_CLRBRKADRINT_SHIFT            3 /* inferred */
#define AIC7880_CLRINT_CLRBRKADRINT_MASK             0x1u
#define AIC7880_CLRINT_CLRBRKADRINT_INPLACE          (AIC7880_CLRINT_CLRBRKADRINT_MASK << AIC7880_CLRINT_CLRBRKADRINT_SHIFT)
#define AIC7880_CLRINT_CLRSCSIINT_SHIFT              2 /* inferred */
#define AIC7880_CLRINT_CLRSCSIINT_MASK               0x1u
#define AIC7880_CLRINT_CLRSCSIINT_INPLACE            (AIC7880_CLRINT_CLRSCSIINT_MASK << AIC7880_CLRINT_CLRSCSIINT_SHIFT)
#define AIC7880_CLRINT_CLRCMDINT_SHIFT               1 /* inferred */
#define AIC7880_CLRINT_CLRCMDINT_MASK                0x1u
#define AIC7880_CLRINT_CLRCMDINT_INPLACE             (AIC7880_CLRINT_CLRCMDINT_MASK << AIC7880_CLRINT_CLRCMDINT_SHIFT)
#define AIC7880_CLRINT_CLRSEQINT_SHIFT               0 /* inferred */
#define AIC7880_CLRINT_CLRSEQINT_MASK                0x1u
#define AIC7880_CLRINT_CLRSEQINT_INPLACE             (AIC7880_CLRINT_CLRSEQINT_MASK << AIC7880_CLRINT_CLRSEQINT_SHIFT)

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
 * Data FIFO status. Reports FIFOEMP, FIFOFULL, FIFOQWDEMP, MREQPEND and HDONE. Only DFTHRSH, bit 2, has a listed position here; the other bit positions are not in the cited extract and stay unknown. MREQPEND is a pending need, not a PCI request in flight.
 */
/* dfstatus: r8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 145-148 (printed 4-76 to 4-79); sibling */
#define AIC7880_DFSTATUS_OFFSET                      0x94u /* inferred */
#define AIC7880_DFSTATUS_DFTHRSH_SHIFT               2 /* inferred */
#define AIC7880_DFSTATUS_DFTHRSH_MASK                0x1u
#define AIC7880_DFSTATUS_DFTHRSH_INPLACE             (AIC7880_DFSTATUS_DFTHRSH_MASK << AIC7880_DFSTATUS_DFTHRSH_SHIFT)

/*
 * Data FIFO port, one byte per access. A read takes one valid byte from the FIFO and a write supplies one. The book gives no reset value (init xx).
 */
/* dfdat: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF p. 63; sibling */
#define AIC7880_DFDAT_OFFSET                         0x99u /* inferred */

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
 * Queue-in FIFO. The host writes SCB IDs and the sequencer removes them. The address follows the SCB device-register layout on PDF p. 69; the register table on PDF p. 63 prints it as 0x98.
 */
/* qinfifo: rw8, reset 0x0; Adaptec AIC-7870 Data Book, PDF p. 69 (layout), p. 63 (lists it at M98, which the layout does not match); sibling */
#define AIC7880_QINFIFO_OFFSET                       0x9bu /* inferred */

/*
 * Queue-in count: entries waiting in the queue-in FIFO. Zero when empty.
 */
/* qincnt: r8, reset 0x0; Adaptec AIC-7870 Data Book, PDF pp. 63 and 69; sibling */
#define AIC7880_QINCNT_OFFSET                        0x9cu /* inferred */

/*
 * Queue-out count, read by the host only. Zero when empty.
 */
/* qoutcnt: r8, reset 0x0; Adaptec AIC-7870 Data Book, PDF p. 61; sibling */
#define AIC7880_QOUTCNT_OFFSET                       0x9eu /* inferred */

/*
 * SCB window: 32 byte positions of the page that SCBPTR selects. Sequencer accesses are byte wide. Host reads are byte wide. Host writes are byte wide in either SCBAUTO mode, and a full four-byte write is accepted only with SCBAUTO set, filling four successive positions. Host access needs a paused sequencer or the automatic access pause. Byte order of the four data bytes against the CPU is not in the cited extract and stays unknown.
 */
/* scbwin: rw8, reset unknown; Adaptec AIC-7870 Data Book, PDF pp. 63-64, 153-154 and 176-177; sibling */
#define AIC7880_SCBWIN_OFFSET                        0xa0u /* inferred */
#define AIC7880_SCBWIN_COUNT                         32
#define AIC7880_SCBWIN_STRIDE                        1

#endif /* AIC7880_GEN_H */
