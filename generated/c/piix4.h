/* generated from devices/piix4/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 3 */
/* input sha256 9419598440ab2c5e0a78081f4f4024eecd7686d44a9b3e8d221f0b1de5cd234d */
/* Intel 82371AB PIIX4 (PCI-to-ISA bridge, IDE, USB, power management and SMBus)
 * as wired in the Visual Workstation 320 and 540 */
#ifndef PIIX4_GEN_H
#define PIIX4_GEN_H

#include <stdint.h>


/*
 * Bus-master IDE command, primary channel; the secondary channel's is at +8
 * (bm_cmd_sec).
 */
/* bm_cmd: rw8, space piix4_bm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.99 */
#define PIIX4_BM_CMD_OFFSET                          0x0u /* established */
#define PIIX4_BM_CMD_RW_SHIFT                        3 /* established */
#define PIIX4_BM_CMD_RW_MASK                         0x1u
#define PIIX4_BM_CMD_RW_INPLACE (PIIX4_BM_CMD_RW_MASK << PIIX4_BM_CMD_RW_SHIFT)
#define PIIX4_BM_CMD_START_SHIFT                     0 /* established */
#define PIIX4_BM_CMD_START_MASK                      0x1u
#define PIIX4_BM_CMD_START_INPLACE (PIIX4_BM_CMD_START_MASK << PIIX4_BM_CMD_START_SHIFT)

/*
 * Bus-master IDE status, primary channel; secondary channel's copy is at offset
 * 0x0a.
 */
/* bm_status: rw8, space piix4_bm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.100 */
#define PIIX4_BM_STATUS_OFFSET                       0x2u /* established */
#define PIIX4_BM_STATUS_DMA1_CAP_SHIFT               6 /* established */
#define PIIX4_BM_STATUS_DMA1_CAP_MASK                0x1u
#define PIIX4_BM_STATUS_DMA1_CAP_INPLACE (PIIX4_BM_STATUS_DMA1_CAP_MASK << PIIX4_BM_STATUS_DMA1_CAP_SHIFT)
#define PIIX4_BM_STATUS_DMA0_CAP_SHIFT               5 /* established */
#define PIIX4_BM_STATUS_DMA0_CAP_MASK                0x1u
#define PIIX4_BM_STATUS_DMA0_CAP_INPLACE (PIIX4_BM_STATUS_DMA0_CAP_MASK << PIIX4_BM_STATUS_DMA0_CAP_SHIFT)
#define PIIX4_BM_STATUS_IRQ_SHIFT                    2 /* established */
#define PIIX4_BM_STATUS_IRQ_MASK                     0x1u
#define PIIX4_BM_STATUS_IRQ_INPLACE (PIIX4_BM_STATUS_IRQ_MASK << PIIX4_BM_STATUS_IRQ_SHIFT)
#define PIIX4_BM_STATUS_ERROR_SHIFT                  1 /* established */
#define PIIX4_BM_STATUS_ERROR_MASK                   0x1u
#define PIIX4_BM_STATUS_ERROR_INPLACE (PIIX4_BM_STATUS_ERROR_MASK << PIIX4_BM_STATUS_ERROR_SHIFT)
#define PIIX4_BM_STATUS_ACTIVE_SHIFT                 0 /* established */
#define PIIX4_BM_STATUS_ACTIVE_MASK                  0x1u
#define PIIX4_BM_STATUS_ACTIVE_INPLACE (PIIX4_BM_STATUS_ACTIVE_MASK << PIIX4_BM_STATUS_ACTIVE_SHIFT)

/*
 * Descriptor table pointer, primary channel; secondary channel's copy is at
 * offset 0x0c.
 */
/* bm_prd: rw32, space piix4_bm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.101 */
#define PIIX4_BM_PRD_OFFSET                          0x4u /* established */

/*
 * Bus-master IDE command, secondary channel.
 */
/* bm_cmd_sec: rw8, space piix4_bm, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.99 */
#define PIIX4_BM_CMD_SEC_OFFSET                      0x8u /* established */
#define PIIX4_BM_CMD_SEC_RW_SHIFT                    3 /* established */
#define PIIX4_BM_CMD_SEC_RW_MASK                     0x1u
#define PIIX4_BM_CMD_SEC_RW_INPLACE (PIIX4_BM_CMD_SEC_RW_MASK << PIIX4_BM_CMD_SEC_RW_SHIFT)
#define PIIX4_BM_CMD_SEC_START_SHIFT                 0 /* established */
#define PIIX4_BM_CMD_SEC_START_MASK                  0x1u
#define PIIX4_BM_CMD_SEC_START_INPLACE (PIIX4_BM_CMD_SEC_START_MASK << PIIX4_BM_CMD_SEC_START_SHIFT)

/*
 * Bus-master IDE status, secondary channel.
 */
/* bm_status_sec: rw8, space piix4_bm, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.100 */
#define PIIX4_BM_STATUS_SEC_OFFSET                   0xau /* established */
#define PIIX4_BM_STATUS_SEC_DMA1_CAP_SHIFT           6 /* established */
#define PIIX4_BM_STATUS_SEC_DMA1_CAP_MASK            0x1u
#define PIIX4_BM_STATUS_SEC_DMA1_CAP_INPLACE (PIIX4_BM_STATUS_SEC_DMA1_CAP_MASK << PIIX4_BM_STATUS_SEC_DMA1_CAP_SHIFT)
#define PIIX4_BM_STATUS_SEC_DMA0_CAP_SHIFT           5 /* established */
#define PIIX4_BM_STATUS_SEC_DMA0_CAP_MASK            0x1u
#define PIIX4_BM_STATUS_SEC_DMA0_CAP_INPLACE (PIIX4_BM_STATUS_SEC_DMA0_CAP_MASK << PIIX4_BM_STATUS_SEC_DMA0_CAP_SHIFT)
#define PIIX4_BM_STATUS_SEC_IRQ_SHIFT                2 /* established */
#define PIIX4_BM_STATUS_SEC_IRQ_MASK                 0x1u
#define PIIX4_BM_STATUS_SEC_IRQ_INPLACE (PIIX4_BM_STATUS_SEC_IRQ_MASK << PIIX4_BM_STATUS_SEC_IRQ_SHIFT)
#define PIIX4_BM_STATUS_SEC_ERROR_SHIFT              1 /* established */
#define PIIX4_BM_STATUS_SEC_ERROR_MASK               0x1u
#define PIIX4_BM_STATUS_SEC_ERROR_INPLACE (PIIX4_BM_STATUS_SEC_ERROR_MASK << PIIX4_BM_STATUS_SEC_ERROR_SHIFT)
#define PIIX4_BM_STATUS_SEC_ACTIVE_SHIFT             0 /* established */
#define PIIX4_BM_STATUS_SEC_ACTIVE_MASK              0x1u
#define PIIX4_BM_STATUS_SEC_ACTIVE_INPLACE (PIIX4_BM_STATUS_SEC_ACTIVE_MASK << PIIX4_BM_STATUS_SEC_ACTIVE_SHIFT)

/*
 * Descriptor table pointer, secondary channel.
 */
/* bm_prd_sec: rw32, space piix4_bm, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.101 */
#define PIIX4_BM_PRD_SEC_OFFSET                      0xcu /* established */

/*
 * Vendor identification, Intel.
 */
/* f0_vid: r16, space piix4_f0, reset 0x8086; Intel 82371AB datasheet 290562-001
 * (April 1997) p.53 */
#define PIIX4_F0_VID_OFFSET                          0x0u /* established */

/*
 * Device identification of function 0. The firmware's self-test reads the
 * function 0 vendor and device words as one dword and expects 0x71108086.
 */
/* f0_did: r16, space piix4_f0, reset 0x7110; Intel 82371AB datasheet 290562-001
 * (April 1997) p.53 */
#define PIIX4_F0_DID_OFFSET                          0x2u /* established */

/*
 * PCI command. The firmware writes 0x0f once. Bits 2 to 0 are hardwired to 1
 * and the bits the datasheet marks not implemented read 0, so the write leaves
 * special cycle enable (bit 3) and SERR enable unchanged except bit 3 set; the
 * special cycle enable is what lets the chip see the shutdown special cycle
 * that Linux sends before powering off. The read-only mask lists the hardwired
 * and reserved bits; only the fields shown are writable.
 */
/* f0_pcicmd: rw16, space piix4_f0, reset 0x7; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.54 */
#define PIIX4_F0_PCICMD_OFFSET                       0x4u /* established */
#define PIIX4_F0_PCICMD_SERRE_SHIFT                  8 /* established */
#define PIIX4_F0_PCICMD_SERRE_MASK                   0x1u
#define PIIX4_F0_PCICMD_SERRE_INPLACE (PIIX4_F0_PCICMD_SERRE_MASK << PIIX4_F0_PCICMD_SERRE_SHIFT)
#define PIIX4_F0_PCICMD_SCE_SHIFT                    3 /* established */
#define PIIX4_F0_PCICMD_SCE_MASK                     0x1u
#define PIIX4_F0_PCICMD_SCE_INPLACE (PIIX4_F0_PCICMD_SCE_MASK << PIIX4_F0_PCICMD_SCE_SHIFT)
#define PIIX4_F0_PCICMD_BUS_MASTER_SHIFT             2 /* established */
#define PIIX4_F0_PCICMD_BUS_MASTER_MASK              0x1u
#define PIIX4_F0_PCICMD_BUS_MASTER_INPLACE (PIIX4_F0_PCICMD_BUS_MASTER_MASK << PIIX4_F0_PCICMD_BUS_MASTER_SHIFT)
#define PIIX4_F0_PCICMD_MEMORY_SHIFT                 1 /* established */
#define PIIX4_F0_PCICMD_MEMORY_MASK                  0x1u
#define PIIX4_F0_PCICMD_MEMORY_INPLACE (PIIX4_F0_PCICMD_MEMORY_MASK << PIIX4_F0_PCICMD_MEMORY_SHIFT)
#define PIIX4_F0_PCICMD_IO_SPACE_SHIFT               0 /* established */
#define PIIX4_F0_PCICMD_IO_SPACE_MASK                0x1u
#define PIIX4_F0_PCICMD_IO_SPACE_INPLACE (PIIX4_F0_PCICMD_IO_SPACE_MASK << PIIX4_F0_PCICMD_IO_SPACE_SHIFT)

/*
 * PCI status. Bits 14 to 11 are write-1-to-clear; DEVSEL# timing is medium
 * (01).
 */
/* f0_pcists: rw16, space piix4_f0, reset 0x280; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.55 */
#define PIIX4_F0_PCISTS_OFFSET                       0x6u /* established */
#define PIIX4_F0_PCISTS_SIG_SERR_SHIFT               14 /* established */
#define PIIX4_F0_PCISTS_SIG_SERR_MASK                0x1u
#define PIIX4_F0_PCISTS_SIG_SERR_INPLACE (PIIX4_F0_PCISTS_SIG_SERR_MASK << PIIX4_F0_PCISTS_SIG_SERR_SHIFT)
#define PIIX4_F0_PCISTS_MASTER_ABORT_SHIFT           13 /* established */
#define PIIX4_F0_PCISTS_MASTER_ABORT_MASK            0x1u
#define PIIX4_F0_PCISTS_MASTER_ABORT_INPLACE (PIIX4_F0_PCISTS_MASTER_ABORT_MASK << PIIX4_F0_PCISTS_MASTER_ABORT_SHIFT)
#define PIIX4_F0_PCISTS_RCV_TARGET_ABORT_SHIFT       12 /* established */
#define PIIX4_F0_PCISTS_RCV_TARGET_ABORT_MASK        0x1u
#define PIIX4_F0_PCISTS_RCV_TARGET_ABORT_INPLACE (PIIX4_F0_PCISTS_RCV_TARGET_ABORT_MASK << PIIX4_F0_PCISTS_RCV_TARGET_ABORT_SHIFT)
#define PIIX4_F0_PCISTS_SIG_TARGET_ABORT_SHIFT       11 /* established */
#define PIIX4_F0_PCISTS_SIG_TARGET_ABORT_MASK        0x1u
#define PIIX4_F0_PCISTS_SIG_TARGET_ABORT_INPLACE (PIIX4_F0_PCISTS_SIG_TARGET_ABORT_MASK << PIIX4_F0_PCISTS_SIG_TARGET_ABORT_SHIFT)
#define PIIX4_F0_PCISTS_DEVSEL_SHIFT                 9 /* established */
#define PIIX4_F0_PCISTS_DEVSEL_MASK                  0x3u
#define PIIX4_F0_PCISTS_DEVSEL_INPLACE (PIIX4_F0_PCISTS_DEVSEL_MASK << PIIX4_F0_PCISTS_DEVSEL_SHIFT)
#define PIIX4_F0_PCISTS_FAST_B2B_SHIFT               7 /* established */
#define PIIX4_F0_PCISTS_FAST_B2B_MASK                0x1u
#define PIIX4_F0_PCISTS_FAST_B2B_INPLACE (PIIX4_F0_PCISTS_FAST_B2B_MASK << PIIX4_F0_PCISTS_FAST_B2B_SHIFT)

/*
 * Revision. Stepping 00h initially; the specification update lists later
 * values. Which stepping the board carries is not known.
 */
/* f0_rid: r8, space piix4_f0, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.55 */
#define PIIX4_F0_RID_OFFSET                          0x8u /* established */

/*
 * Class code, programming interface byte, 0x00. The PROM's register walk reads
 * this dword once and discards the result.
 */
/* f0_classc_pi: r8, space piix4_f0, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.56 */
#define PIIX4_F0_CLASSC_PI_OFFSET                    0x9u /* established */

/*
 * Class code, sub-class byte: 0x01 (PCI-to-ISA bridge) while GENCFG bit 1
 * selects subtractive decode, 0x80 (other bridge) when it selects positive
 * decode.
 */
/* f0_classc_scc: r8, space piix4_f0, reset 0x1; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.56 */
#define PIIX4_F0_CLASSC_SCC_OFFSET                   0xau /* established */

/*
 * Class code, base class byte, 0x06 (bridge).
 */
/* f0_classc_basec: r8, space piix4_f0, reset 0x6; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.56 */
#define PIIX4_F0_CLASSC_BASEC_OFFSET                 0xbu /* established */

/*
 * Header type, 0x80: a multifunction device. Functions 1 to 3 read their own
 * header type as 0.
 */
/* f0_hedt: r8, space piix4_f0, reset 0x80; Intel 82371AB datasheet 290562-001
 * (April 1997) p.56 */
#define PIIX4_F0_HEDT_OFFSET                         0xeu /* established */

/*
 * ISA I/O recovery timer. Reset enables 8-bit and 16-bit recovery with one
 * SYSCLK added to the 3.5 SYSCLK minimum. Not written by any held software.
 */
/* f0_iort: rw8, space piix4_f0, reset 0x4d; Intel 82371AB datasheet 290562-001
 * (April 1997) p.57 */
#define PIIX4_F0_IORT_OFFSET                         0x4cu /* established */
#define PIIX4_F0_IORT_DMAAC_SHIFT                    7 /* established */
#define PIIX4_F0_IORT_DMAAC_MASK                     0x1u
#define PIIX4_F0_IORT_DMAAC_INPLACE (PIIX4_F0_IORT_DMAAC_MASK << PIIX4_F0_IORT_DMAAC_SHIFT)
#define PIIX4_F0_IORT_REC8_EN_SHIFT                  6 /* established */
#define PIIX4_F0_IORT_REC8_EN_MASK                   0x1u
#define PIIX4_F0_IORT_REC8_EN_INPLACE (PIIX4_F0_IORT_REC8_EN_MASK << PIIX4_F0_IORT_REC8_EN_SHIFT)
#define PIIX4_F0_IORT_REC8_SHIFT                     3 /* established */
#define PIIX4_F0_IORT_REC8_MASK                      0x7u
#define PIIX4_F0_IORT_REC8_INPLACE (PIIX4_F0_IORT_REC8_MASK << PIIX4_F0_IORT_REC8_SHIFT)
#define PIIX4_F0_IORT_REC16_EN_SHIFT                 2 /* established */
#define PIIX4_F0_IORT_REC16_EN_MASK                  0x1u
#define PIIX4_F0_IORT_REC16_EN_INPLACE (PIIX4_F0_IORT_REC16_EN_MASK << PIIX4_F0_IORT_REC16_EN_SHIFT)
#define PIIX4_F0_IORT_REC16_SHIFT                    0 /* established */
#define PIIX4_F0_IORT_REC16_MASK                     0x3u
#define PIIX4_F0_IORT_REC16_INPLACE (PIIX4_F0_IORT_REC16_MASK << PIIX4_F0_IORT_REC16_SHIFT)

/*
 * X-bus chip select. The PROM writes the byte 0xf4: that sets the extended
 * BIOS, lower BIOS, BIOSCS# write enable, coprocessor error and mouse functions
 * and clears bits 1 and 0, the external keyboard and RTC chip selects (a
 * software expectation). Clearing them while the Super I/O keyboard controller
 * decodes its own ports is consistent with the board using the Super I/O's
 * keyboard controller (inferred). Bit 9 and bit 7 forward the flash regions
 * 0xfff00000 to 0xfff7ffff and 0xfff80000 to 0xfffdffff to the BIOS chip
 * select; the top 64 KiB is always decoded. Which chip select the flash sits on
 * is not stated by any source.
 */
/* f0_xbcs: rw16, space piix4_f0, reset 0x3; Intel 82371AB datasheet 290562-001
 * (April 1997) p.57-58 */
#define PIIX4_F0_XBCS_OFFSET                         0x4eu /* established */
#define PIIX4_F0_XBCS_MC_LOC_SHIFT                   10 /* established */
#define PIIX4_F0_XBCS_MC_LOC_MASK                    0x1u
#define PIIX4_F0_XBCS_MC_LOC_INPLACE (PIIX4_F0_XBCS_MC_LOC_MASK << PIIX4_F0_XBCS_MC_LOC_SHIFT)
#define PIIX4_F0_XBCS_BIOS_1MEG_SHIFT                9 /* established */
#define PIIX4_F0_XBCS_BIOS_1MEG_MASK                 0x1u
#define PIIX4_F0_XBCS_BIOS_1MEG_INPLACE (PIIX4_F0_XBCS_BIOS_1MEG_MASK << PIIX4_F0_XBCS_BIOS_1MEG_SHIFT)
#define PIIX4_F0_XBCS_APIC_CS_SHIFT                  8 /* established */
#define PIIX4_F0_XBCS_APIC_CS_MASK                   0x1u
#define PIIX4_F0_XBCS_APIC_CS_INPLACE (PIIX4_F0_XBCS_APIC_CS_MASK << PIIX4_F0_XBCS_APIC_CS_SHIFT)
#define PIIX4_F0_XBCS_EXT_BIOS_SHIFT                 7 /* established */
#define PIIX4_F0_XBCS_EXT_BIOS_MASK                  0x1u
#define PIIX4_F0_XBCS_EXT_BIOS_INPLACE (PIIX4_F0_XBCS_EXT_BIOS_MASK << PIIX4_F0_XBCS_EXT_BIOS_SHIFT)
#define PIIX4_F0_XBCS_LOWER_BIOS_SHIFT               6 /* established */
#define PIIX4_F0_XBCS_LOWER_BIOS_MASK                0x1u
#define PIIX4_F0_XBCS_LOWER_BIOS_INPLACE (PIIX4_F0_XBCS_LOWER_BIOS_MASK << PIIX4_F0_XBCS_LOWER_BIOS_SHIFT)
#define PIIX4_F0_XBCS_COPROC_ERR_SHIFT               5 /* established */
#define PIIX4_F0_XBCS_COPROC_ERR_MASK                0x1u
#define PIIX4_F0_XBCS_COPROC_ERR_INPLACE (PIIX4_F0_XBCS_COPROC_ERR_MASK << PIIX4_F0_XBCS_COPROC_ERR_SHIFT)
#define PIIX4_F0_XBCS_MOUSE_SHIFT                    4 /* established */
#define PIIX4_F0_XBCS_MOUSE_MASK                     0x1u
#define PIIX4_F0_XBCS_MOUSE_INPLACE (PIIX4_F0_XBCS_MOUSE_MASK << PIIX4_F0_XBCS_MOUSE_SHIFT)
#define PIIX4_F0_XBCS_PORT61_ALIAS_SHIFT             3 /* established */
#define PIIX4_F0_XBCS_PORT61_ALIAS_MASK              0x1u
#define PIIX4_F0_XBCS_PORT61_ALIAS_INPLACE (PIIX4_F0_XBCS_PORT61_ALIAS_MASK << PIIX4_F0_XBCS_PORT61_ALIAS_SHIFT)
#define PIIX4_F0_XBCS_BIOSCS_WP_SHIFT                2 /* established */
#define PIIX4_F0_XBCS_BIOSCS_WP_MASK                 0x1u
#define PIIX4_F0_XBCS_BIOSCS_WP_INPLACE (PIIX4_F0_XBCS_BIOSCS_WP_MASK << PIIX4_F0_XBCS_BIOSCS_WP_SHIFT)
#define PIIX4_F0_XBCS_KBCCS_EN_SHIFT                 1 /* established */
#define PIIX4_F0_XBCS_KBCCS_EN_MASK                  0x1u
#define PIIX4_F0_XBCS_KBCCS_EN_INPLACE (PIIX4_F0_XBCS_KBCCS_EN_MASK << PIIX4_F0_XBCS_KBCCS_EN_SHIFT)
#define PIIX4_F0_XBCS_RTCCS_EN_SHIFT                 0 /* established */
#define PIIX4_F0_XBCS_RTCCS_EN_MASK                  0x1u
#define PIIX4_F0_XBCS_RTCCS_EN_INPLACE (PIIX4_F0_XBCS_RTCCS_EN_MASK << PIIX4_F0_XBCS_RTCCS_EN_SHIFT)

/*
 * PIRQ[A:D]# route control, one byte each at 0x60 to 0x63. The PROM writes 0x09
 * to the first (route PIRQA# to IRQ9). The routed IRQ must be level sensitive.
 */
/* f0_pirqrc: rw8, space piix4_f0, reset 0x80; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.59 */
#define PIIX4_F0_PIRQRC_OFFSET                       0x60u /* established */
#define PIIX4_F0_PIRQRC_COUNT                        4
#define PIIX4_F0_PIRQRC_STRIDE                       1
#define PIIX4_F0_PIRQRC_ROUTE_OFF_SHIFT              7 /* established */
#define PIIX4_F0_PIRQRC_ROUTE_OFF_MASK               0x1u
#define PIIX4_F0_PIRQRC_ROUTE_OFF_INPLACE (PIIX4_F0_PIRQRC_ROUTE_OFF_MASK << PIIX4_F0_PIRQRC_ROUTE_OFF_SHIFT)
#define PIIX4_F0_PIRQRC_IRQ_SHIFT                    0 /* established */
#define PIIX4_F0_PIRQRC_IRQ_MASK                     0xfu
#define PIIX4_F0_PIRQRC_IRQ_INPLACE (PIIX4_F0_PIRQRC_IRQ_MASK << PIIX4_F0_PIRQRC_IRQ_SHIFT)
#define PIIX4_F0_PIRQRC_IRQ_IRQ3                     3 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ4                     4 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ5                     5 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ6                     6 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ7                     7 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ9                     9 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ10                    10 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ11                    11 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ12                    12 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ14                    14 /* established */
#define PIIX4_F0_PIRQRC_IRQ_IRQ15                    15 /* established */

/*
 * Serial IRQ control. Not written by the PROM; GENCFG bit 16 must also select
 * SERIRQ for it to take effect.
 */
/* f0_serirqc: rw8, space piix4_f0, reset 0x10; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.59 */
#define PIIX4_F0_SERIRQC_OFFSET                      0x64u /* established */
#define PIIX4_F0_SERIRQC_ENABLE_SHIFT                7 /* established */
#define PIIX4_F0_SERIRQC_ENABLE_MASK                 0x1u
#define PIIX4_F0_SERIRQC_ENABLE_INPLACE (PIIX4_F0_SERIRQC_ENABLE_MASK << PIIX4_F0_SERIRQC_ENABLE_SHIFT)
#define PIIX4_F0_SERIRQC_CONTINUOUS_SHIFT            6 /* established */
#define PIIX4_F0_SERIRQC_CONTINUOUS_MASK             0x1u
#define PIIX4_F0_SERIRQC_CONTINUOUS_INPLACE (PIIX4_F0_SERIRQC_CONTINUOUS_MASK << PIIX4_F0_SERIRQC_CONTINUOUS_SHIFT)
#define PIIX4_F0_SERIRQC_FRAME_SIZE_SHIFT            2 /* established */
#define PIIX4_F0_SERIRQC_FRAME_SIZE_MASK             0xfu
#define PIIX4_F0_SERIRQC_FRAME_SIZE_INPLACE (PIIX4_F0_SERIRQC_FRAME_SIZE_MASK << PIIX4_F0_SERIRQC_FRAME_SIZE_SHIFT)
#define PIIX4_F0_SERIRQC_START_WIDTH_SHIFT           0 /* established */
#define PIIX4_F0_SERIRQC_START_WIDTH_MASK            0x3u
#define PIIX4_F0_SERIRQC_START_WIDTH_INPLACE (PIIX4_F0_SERIRQC_START_WIDTH_MASK << PIIX4_F0_SERIRQC_START_WIDTH_SHIFT)

/*
 * Top of memory and ISA/DMA forwarding. The PROM writes 0xf2: top of memory 16
 * MB and the 512-640 KB region forwarded to PCI.
 */
/* f0_tom: rw8, space piix4_f0, reset 0x2; Intel 82371AB datasheet 290562-001
 * (April 1997) p.60 */
#define PIIX4_F0_TOM_OFFSET                          0x69u /* established */
#define PIIX4_F0_TOM_TOP_SHIFT                       4 /* established */
#define PIIX4_F0_TOM_TOP_MASK                        0xfu
#define PIIX4_F0_TOM_TOP_INPLACE (PIIX4_F0_TOM_TOP_MASK << PIIX4_F0_TOM_TOP_SHIFT)
#define PIIX4_F0_TOM_LOWER_BIOS_FWD_SHIFT            3 /* established */
#define PIIX4_F0_TOM_LOWER_BIOS_FWD_MASK             0x1u
#define PIIX4_F0_TOM_LOWER_BIOS_FWD_INPLACE (PIIX4_F0_TOM_LOWER_BIOS_FWD_MASK << PIIX4_F0_TOM_LOWER_BIOS_FWD_SHIFT)
#define PIIX4_F0_TOM_A0000_EN_SHIFT                  2 /* established */
#define PIIX4_F0_TOM_A0000_EN_MASK                   0x1u
#define PIIX4_F0_TOM_A0000_EN_INPLACE (PIIX4_F0_TOM_A0000_EN_MASK << PIIX4_F0_TOM_A0000_EN_SHIFT)
#define PIIX4_F0_TOM_LOW512_FWD_SHIFT                1 /* established */
#define PIIX4_F0_TOM_LOW512_FWD_MASK                 0x1u
#define PIIX4_F0_TOM_LOW512_FWD_INPLACE (PIIX4_F0_TOM_LOW512_FWD_MASK << PIIX4_F0_TOM_LOW512_FWD_SHIFT)

/*
 * Miscellaneous status.
 */
/* f0_mstat: rw16, space piix4_f0, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.61 */
#define PIIX4_F0_MSTAT_OFFSET                        0x6au /* established */
#define PIIX4_F0_MSTAT_SERR_DTT_SHIFT                15 /* established */
#define PIIX4_F0_MSTAT_SERR_DTT_MASK                 0x1u
#define PIIX4_F0_MSTAT_SERR_DTT_INPLACE (PIIX4_F0_MSTAT_SERR_DTT_MASK << PIIX4_F0_MSTAT_SERR_DTT_SHIFT)
#define PIIX4_F0_MSTAT_HOST_RETRY_SHIFT              7 /* established */
#define PIIX4_F0_MSTAT_HOST_RETRY_MASK               0x1u
#define PIIX4_F0_MSTAT_HOST_RETRY_INPLACE (PIIX4_F0_MSTAT_HOST_RETRY_MASK << PIIX4_F0_MSTAT_HOST_RETRY_SHIFT)

/*
 * Motherboard device DMA control, 0x76 and 0x77. The PROM writes 0x0c to both,
 * which is the disabled channel (100) with the bit the datasheet says reads 1.
 * The datasheet gives the default as 04h while saying bit 3 reads as 1; the two
 * do not agree.
 */
/* f0_mbdma: rw8, space piix4_f0, reset 0x4; Intel 82371AB datasheet 290562-001
 * (April 1997) p.61 */
#define PIIX4_F0_MBDMA_OFFSET                        0x76u /* established */
#define PIIX4_F0_MBDMA_COUNT                         2
#define PIIX4_F0_MBDMA_STRIDE                        1
#define PIIX4_F0_MBDMA_FAST_SHIFT                    7 /* established */
#define PIIX4_F0_MBDMA_FAST_MASK                     0x1u
#define PIIX4_F0_MBDMA_FAST_INPLACE (PIIX4_F0_MBDMA_FAST_MASK << PIIX4_F0_MBDMA_FAST_SHIFT)
#define PIIX4_F0_MBDMA_ONE_SHIFT                     3 /* established */
#define PIIX4_F0_MBDMA_ONE_MASK                      0x1u
#define PIIX4_F0_MBDMA_ONE_INPLACE (PIIX4_F0_MBDMA_ONE_MASK << PIIX4_F0_MBDMA_ONE_SHIFT)
#define PIIX4_F0_MBDMA_CHNL_SHIFT                    0 /* established */
#define PIIX4_F0_MBDMA_CHNL_MASK                     0x7u
#define PIIX4_F0_MBDMA_CHNL_INPLACE (PIIX4_F0_MBDMA_CHNL_MASK << PIIX4_F0_MBDMA_CHNL_SHIFT)

/*
 * APIC base address relocation (the I/O APIC window follows the Intel 0xfec0
 * base). Not written by held software.
 */
/* f0_apicbase: rw8, space piix4_f0, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.62 */
#define PIIX4_F0_APICBASE_OFFSET                     0x80u /* established */

/*
 * Deterministic latency control: delayed transaction, passive release and SERR#
 * generation enables. Not written by held software.
 */
/* f0_dlc: rw8, space piix4_f0, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.62-63 */
#define PIIX4_F0_DLC_OFFSET                          0x82u /* established */
#define PIIX4_F0_DLC_SERR_EN_SHIFT                   3 /* established */
#define PIIX4_F0_DLC_SERR_EN_MASK                    0x1u
#define PIIX4_F0_DLC_SERR_EN_INPLACE (PIIX4_F0_DLC_SERR_EN_MASK << PIIX4_F0_DLC_SERR_EN_SHIFT)
#define PIIX4_F0_DLC_USB_PR_SHIFT                    2 /* established */
#define PIIX4_F0_DLC_USB_PR_MASK                     0x1u
#define PIIX4_F0_DLC_USB_PR_INPLACE (PIIX4_F0_DLC_USB_PR_MASK << PIIX4_F0_DLC_USB_PR_SHIFT)
#define PIIX4_F0_DLC_PASSIVE_RELEASE_SHIFT           1 /* established */
#define PIIX4_F0_DLC_PASSIVE_RELEASE_MASK            0x1u
#define PIIX4_F0_DLC_PASSIVE_RELEASE_INPLACE (PIIX4_F0_DLC_PASSIVE_RELEASE_MASK << PIIX4_F0_DLC_PASSIVE_RELEASE_SHIFT)
#define PIIX4_F0_DLC_DELAYED_TXN_SHIFT               0 /* established */
#define PIIX4_F0_DLC_DELAYED_TXN_MASK                0x1u
#define PIIX4_F0_DLC_DELAYED_TXN_INPLACE (PIIX4_F0_DLC_DELAYED_TXN_MASK << PIIX4_F0_DLC_DELAYED_TXN_SHIFT)

/*
 * PCI DMA configuration: the DMA type of each channel. Channel 4 is the cascade
 * and has no field. The PROM bit-walks the byte at 0x90 and the one at 0x95
 * (high byte of the channel 5 to 7 pointer) in its function 0 register test,
 * and the walked bytes hold every pattern on the real board.
 */
/* f0_pdmacfg: rw16, space piix4_f0, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.63-64 */
#define PIIX4_F0_PDMACFG_OFFSET                      0x90u /* established */
#define PIIX4_F0_PDMACFG_CH7_SHIFT                   14 /* established */
#define PIIX4_F0_PDMACFG_CH7_MASK                    0x3u
#define PIIX4_F0_PDMACFG_CH7_INPLACE (PIIX4_F0_PDMACFG_CH7_MASK << PIIX4_F0_PDMACFG_CH7_SHIFT)
#define PIIX4_F0_PDMACFG_CH7_NORMAL_ISA              0 /* established */
#define PIIX4_F0_PDMACFG_CH7_PC_PCI                  1 /* established */
#define PIIX4_F0_PDMACFG_CH7_DISTRIBUTED             2 /* established */
#define PIIX4_F0_PDMACFG_CH6_SHIFT                   12 /* established */
#define PIIX4_F0_PDMACFG_CH6_MASK                    0x3u
#define PIIX4_F0_PDMACFG_CH6_INPLACE (PIIX4_F0_PDMACFG_CH6_MASK << PIIX4_F0_PDMACFG_CH6_SHIFT)
#define PIIX4_F0_PDMACFG_CH6_NORMAL_ISA              0 /* established */
#define PIIX4_F0_PDMACFG_CH6_PC_PCI                  1 /* established */
#define PIIX4_F0_PDMACFG_CH6_DISTRIBUTED             2 /* established */
#define PIIX4_F0_PDMACFG_CH5_SHIFT                   10 /* established */
#define PIIX4_F0_PDMACFG_CH5_MASK                    0x3u
#define PIIX4_F0_PDMACFG_CH5_INPLACE (PIIX4_F0_PDMACFG_CH5_MASK << PIIX4_F0_PDMACFG_CH5_SHIFT)
#define PIIX4_F0_PDMACFG_CH5_NORMAL_ISA              0 /* established */
#define PIIX4_F0_PDMACFG_CH5_PC_PCI                  1 /* established */
#define PIIX4_F0_PDMACFG_CH5_DISTRIBUTED             2 /* established */
#define PIIX4_F0_PDMACFG_CH3_SHIFT                   6 /* established */
#define PIIX4_F0_PDMACFG_CH3_MASK                    0x3u
#define PIIX4_F0_PDMACFG_CH3_INPLACE (PIIX4_F0_PDMACFG_CH3_MASK << PIIX4_F0_PDMACFG_CH3_SHIFT)
#define PIIX4_F0_PDMACFG_CH3_NORMAL_ISA              0 /* established */
#define PIIX4_F0_PDMACFG_CH3_PC_PCI                  1 /* established */
#define PIIX4_F0_PDMACFG_CH3_DISTRIBUTED             2 /* established */
#define PIIX4_F0_PDMACFG_CH2_SHIFT                   4 /* established */
#define PIIX4_F0_PDMACFG_CH2_MASK                    0x3u
#define PIIX4_F0_PDMACFG_CH2_INPLACE (PIIX4_F0_PDMACFG_CH2_MASK << PIIX4_F0_PDMACFG_CH2_SHIFT)
#define PIIX4_F0_PDMACFG_CH2_NORMAL_ISA              0 /* established */
#define PIIX4_F0_PDMACFG_CH2_PC_PCI                  1 /* established */
#define PIIX4_F0_PDMACFG_CH2_DISTRIBUTED             2 /* established */
#define PIIX4_F0_PDMACFG_CH1_SHIFT                   2 /* established */
#define PIIX4_F0_PDMACFG_CH1_MASK                    0x3u
#define PIIX4_F0_PDMACFG_CH1_INPLACE (PIIX4_F0_PDMACFG_CH1_MASK << PIIX4_F0_PDMACFG_CH1_SHIFT)
#define PIIX4_F0_PDMACFG_CH1_NORMAL_ISA              0 /* established */
#define PIIX4_F0_PDMACFG_CH1_PC_PCI                  1 /* established */
#define PIIX4_F0_PDMACFG_CH1_DISTRIBUTED             2 /* established */
#define PIIX4_F0_PDMACFG_CH0_SHIFT                   0 /* established */
#define PIIX4_F0_PDMACFG_CH0_MASK                    0x3u
#define PIIX4_F0_PDMACFG_CH0_INPLACE (PIIX4_F0_PDMACFG_CH0_MASK << PIIX4_F0_PDMACFG_CH0_SHIFT)
#define PIIX4_F0_PDMACFG_CH0_NORMAL_ISA              0 /* established */
#define PIIX4_F0_PDMACFG_CH0_PC_PCI                  1 /* established */
#define PIIX4_F0_PDMACFG_CH0_DISTRIBUTED             2 /* established */

/*
 * Distributed DMA slave base pointers: 0x92 for channels 0 to 3, 0x94 for
 * channels 5 to 7; bits 15:6 are I/O address bits. The PROM bit-walks bytes
 * 0x93 and 0x95 of these.
 */
/* f0_ddmabp: rw16, space piix4_f0, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.64 */
#define PIIX4_F0_DDMABP_OFFSET                       0x92u /* established */
#define PIIX4_F0_DDMABP_COUNT                        2
#define PIIX4_F0_DDMABP_STRIDE                       2
#define PIIX4_F0_DDMABP_BASE_SHIFT                   6 /* established */
#define PIIX4_F0_DDMABP_BASE_MASK                    0x3ffu
#define PIIX4_F0_DDMABP_BASE_INPLACE (PIIX4_F0_DDMABP_BASE_MASK << PIIX4_F0_DDMABP_BASE_SHIFT)

/*
 * General configuration: pin function selects and bus mode. The PROM writes the
 * bytes 0x4d (register 0xb0) and 0x60 (register 0xb3). 0x4d sets bit 0 (ISA
 * mode, so the pins carry IOCHK# and LA[23:17] and are not GPI0 and GPO[7:1]),
 * bit 6 (positive decode of the Plug and Play ports 0x279 and 0xa79) and the
 * read-only bits 2 and 3, which stay as the straps set them. 0x60 sets bits 30
 * and 29, turning the RTCALE and RTCCS# pins into outputs GPO25 and GPO24. Bit
 * 29 is printed as 'GPO2' in the datasheet and is GPO24 in its GPO table (a
 * datasheet inconsistency). Tables 1 and 2 label the register 'PCI Function 1'
 * but it is a function 0 register.
 */
/* f0_gencfg: rw32, space piix4_f0, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.65-67 */
#define PIIX4_F0_GENCFG_OFFSET                       0xb0u /* established */
#define PIIX4_F0_GENCFG_KBCCS_GPO26_SHIFT            31 /* established */
#define PIIX4_F0_GENCFG_KBCCS_GPO26_MASK             0x1u
#define PIIX4_F0_GENCFG_KBCCS_GPO26_INPLACE (PIIX4_F0_GENCFG_KBCCS_GPO26_MASK << PIIX4_F0_GENCFG_KBCCS_GPO26_SHIFT)
#define PIIX4_F0_GENCFG_RTCALE_GPO25_SHIFT           30 /* established */
#define PIIX4_F0_GENCFG_RTCALE_GPO25_MASK            0x1u
#define PIIX4_F0_GENCFG_RTCALE_GPO25_INPLACE (PIIX4_F0_GENCFG_RTCALE_GPO25_MASK << PIIX4_F0_GENCFG_RTCALE_GPO25_SHIFT)
#define PIIX4_F0_GENCFG_RTCCS_GPO24_SHIFT            29 /* established */
#define PIIX4_F0_GENCFG_RTCCS_GPO24_MASK             0x1u
#define PIIX4_F0_GENCFG_RTCCS_GPO24_INPLACE (PIIX4_F0_GENCFG_RTCCS_GPO24_MASK << PIIX4_F0_GENCFG_RTCCS_GPO24_SHIFT)
#define PIIX4_F0_GENCFG_XOE_GPO_SHIFT                28 /* established */
#define PIIX4_F0_GENCFG_XOE_GPO_MASK                 0x1u
#define PIIX4_F0_GENCFG_XOE_GPO_INPLACE (PIIX4_F0_GENCFG_XOE_GPO_MASK << PIIX4_F0_GENCFG_XOE_GPO_SHIFT)
#define PIIX4_F0_GENCFG_RI_GPI12_SHIFT               27 /* established */
#define PIIX4_F0_GENCFG_RI_GPI12_MASK                0x1u
#define PIIX4_F0_GENCFG_RI_GPI12_INPLACE (PIIX4_F0_GENCFG_RI_GPI12_MASK << PIIX4_F0_GENCFG_RI_GPI12_SHIFT)
#define PIIX4_F0_GENCFG_LID_GPI10_SHIFT              25 /* established */
#define PIIX4_F0_GENCFG_LID_GPI10_MASK               0x1u
#define PIIX4_F0_GENCFG_LID_GPI10_INPLACE (PIIX4_F0_GENCFG_LID_GPI10_MASK << PIIX4_F0_GENCFG_LID_GPI10_SHIFT)
#define PIIX4_F0_GENCFG_BATLOW_GPI9_SHIFT            24 /* established */
#define PIIX4_F0_GENCFG_BATLOW_GPI9_MASK             0x1u
#define PIIX4_F0_GENCFG_BATLOW_GPI9_INPLACE (PIIX4_F0_GENCFG_BATLOW_GPI9_MASK << PIIX4_F0_GENCFG_BATLOW_GPI9_SHIFT)
#define PIIX4_F0_GENCFG_THRM_GPI8_SHIFT              23 /* established */
#define PIIX4_F0_GENCFG_THRM_GPI8_MASK               0x1u
#define PIIX4_F0_GENCFG_THRM_GPI8_INPLACE (PIIX4_F0_GENCFG_THRM_GPI8_MASK << PIIX4_F0_GENCFG_THRM_GPI8_SHIFT)
#define PIIX4_F0_GENCFG_SUSSTAT2_GPO_SHIFT           22 /* established */
#define PIIX4_F0_GENCFG_SUSSTAT2_GPO_MASK            0x1u
#define PIIX4_F0_GENCFG_SUSSTAT2_GPO_INPLACE (PIIX4_F0_GENCFG_SUSSTAT2_GPO_MASK << PIIX4_F0_GENCFG_SUSSTAT2_GPO_SHIFT)
#define PIIX4_F0_GENCFG_SUSSTAT1_GPO_SHIFT           21 /* established */
#define PIIX4_F0_GENCFG_SUSSTAT1_GPO_MASK            0x1u
#define PIIX4_F0_GENCFG_SUSSTAT1_GPO_INPLACE (PIIX4_F0_GENCFG_SUSSTAT1_GPO_MASK << PIIX4_F0_GENCFG_SUSSTAT1_GPO_SHIFT)
#define PIIX4_F0_GENCFG_ZZ_GPO_SHIFT                 20 /* established */
#define PIIX4_F0_GENCFG_ZZ_GPO_MASK                  0x1u
#define PIIX4_F0_GENCFG_ZZ_GPO_INPLACE (PIIX4_F0_GENCFG_ZZ_GPO_MASK << PIIX4_F0_GENCFG_ZZ_GPO_SHIFT)
#define PIIX4_F0_GENCFG_PCISTP_GPO_SHIFT             19 /* established */
#define PIIX4_F0_GENCFG_PCISTP_GPO_MASK              0x1u
#define PIIX4_F0_GENCFG_PCISTP_GPO_INPLACE (PIIX4_F0_GENCFG_PCISTP_GPO_MASK << PIIX4_F0_GENCFG_PCISTP_GPO_SHIFT)
#define PIIX4_F0_GENCFG_CPUSTP_GPO_SHIFT             18 /* established */
#define PIIX4_F0_GENCFG_CPUSTP_GPO_MASK              0x1u
#define PIIX4_F0_GENCFG_CPUSTP_GPO_INPLACE (PIIX4_F0_GENCFG_CPUSTP_GPO_MASK << PIIX4_F0_GENCFG_CPUSTP_GPO_SHIFT)
#define PIIX4_F0_GENCFG_SUSBC_GPO_SHIFT              17 /* established */
#define PIIX4_F0_GENCFG_SUSBC_GPO_MASK               0x1u
#define PIIX4_F0_GENCFG_SUSBC_GPO_INPLACE (PIIX4_F0_GENCFG_SUSBC_GPO_MASK << PIIX4_F0_GENCFG_SUSBC_GPO_SHIFT)
#define PIIX4_F0_GENCFG_SERIRQ_SEL_SHIFT             16 /* established */
#define PIIX4_F0_GENCFG_SERIRQ_SEL_MASK              0x1u
#define PIIX4_F0_GENCFG_SERIRQ_SEL_INPLACE (PIIX4_F0_GENCFG_SERIRQ_SEL_MASK << PIIX4_F0_GENCFG_SERIRQ_SEL_SHIFT)
#define PIIX4_F0_GENCFG_SMBALERT_SEL_SHIFT           15 /* established */
#define PIIX4_F0_GENCFG_SMBALERT_SEL_MASK            0x1u
#define PIIX4_F0_GENCFG_SMBALERT_SEL_INPLACE (PIIX4_F0_GENCFG_SMBALERT_SEL_MASK << PIIX4_F0_GENCFG_SMBALERT_SEL_SHIFT)
#define PIIX4_F0_GENCFG_IRQ8_SEL_SHIFT               14 /* established */
#define PIIX4_F0_GENCFG_IRQ8_SEL_MASK                0x1u
#define PIIX4_F0_GENCFG_IRQ8_SEL_INPLACE (PIIX4_F0_GENCFG_IRQ8_SEL_MASK << PIIX4_F0_GENCFG_IRQ8_SEL_SHIFT)
#define PIIX4_F0_GENCFG_SEC_IDE_TRISTATE_SHIFT       12 /* established */
#define PIIX4_F0_GENCFG_SEC_IDE_TRISTATE_MASK        0x1u
#define PIIX4_F0_GENCFG_SEC_IDE_TRISTATE_INPLACE (PIIX4_F0_GENCFG_SEC_IDE_TRISTATE_MASK << PIIX4_F0_GENCFG_SEC_IDE_TRISTATE_SHIFT)
#define PIIX4_F0_GENCFG_PRI_IDE_TRISTATE_SHIFT       11 /* established */
#define PIIX4_F0_GENCFG_PRI_IDE_TRISTATE_MASK        0x1u
#define PIIX4_F0_GENCFG_PRI_IDE_TRISTATE_INPLACE (PIIX4_F0_GENCFG_PRI_IDE_TRISTATE_MASK << PIIX4_F0_GENCFG_PRI_IDE_TRISTATE_SHIFT)
#define PIIX4_F0_GENCFG_REQC_SEL_SHIFT               10 /* established */
#define PIIX4_F0_GENCFG_REQC_SEL_MASK                0x1u
#define PIIX4_F0_GENCFG_REQC_SEL_INPLACE (PIIX4_F0_GENCFG_REQC_SEL_MASK << PIIX4_F0_GENCFG_REQC_SEL_SHIFT)
#define PIIX4_F0_GENCFG_REQB_SEL_SHIFT               9 /* established */
#define PIIX4_F0_GENCFG_REQB_SEL_MASK                0x1u
#define PIIX4_F0_GENCFG_REQB_SEL_INPLACE (PIIX4_F0_GENCFG_REQB_SEL_MASK << PIIX4_F0_GENCFG_REQB_SEL_SHIFT)
#define PIIX4_F0_GENCFG_REQA_SEL_SHIFT               8 /* established */
#define PIIX4_F0_GENCFG_REQA_SEL_MASK                0x1u
#define PIIX4_F0_GENCFG_REQA_SEL_INPLACE (PIIX4_F0_GENCFG_REQA_SEL_MASK << PIIX4_F0_GENCFG_REQA_SEL_SHIFT)
#define PIIX4_F0_GENCFG_PNP_DECODE_SHIFT             6 /* established */
#define PIIX4_F0_GENCFG_PNP_DECODE_MASK              0x1u
#define PIIX4_F0_GENCFG_PNP_DECODE_INPLACE (PIIX4_F0_GENCFG_PNP_DECODE_MASK << PIIX4_F0_GENCFG_PNP_DECODE_SHIFT)
#define PIIX4_F0_GENCFG_ALT_ACCESS_SHIFT             5 /* established */
#define PIIX4_F0_GENCFG_ALT_ACCESS_MASK              0x1u
#define PIIX4_F0_GENCFG_ALT_ACCESS_INPLACE (PIIX4_F0_GENCFG_ALT_ACCESS_MASK << PIIX4_F0_GENCFG_ALT_ACCESS_SHIFT)
#define PIIX4_F0_GENCFG_IDE_SPLIT_SHIFT              4 /* established */
#define PIIX4_F0_GENCFG_IDE_SPLIT_MASK               0x1u
#define PIIX4_F0_GENCFG_IDE_SPLIT_INPLACE (PIIX4_F0_GENCFG_IDE_SPLIT_MASK << PIIX4_F0_GENCFG_IDE_SPLIT_SHIFT)
#define PIIX4_F0_GENCFG_CONFIG2_SHIFT                3 /* established */
#define PIIX4_F0_GENCFG_CONFIG2_MASK                 0x1u
#define PIIX4_F0_GENCFG_CONFIG2_INPLACE (PIIX4_F0_GENCFG_CONFIG2_MASK << PIIX4_F0_GENCFG_CONFIG2_SHIFT)
#define PIIX4_F0_GENCFG_CONFIG1_SHIFT                2 /* established */
#define PIIX4_F0_GENCFG_CONFIG1_MASK                 0x1u
#define PIIX4_F0_GENCFG_CONFIG1_INPLACE (PIIX4_F0_GENCFG_CONFIG1_MASK << PIIX4_F0_GENCFG_CONFIG1_SHIFT)
#define PIIX4_F0_GENCFG_POS_DECODE_SHIFT             1 /* established */
#define PIIX4_F0_GENCFG_POS_DECODE_MASK              0x1u
#define PIIX4_F0_GENCFG_POS_DECODE_INPLACE (PIIX4_F0_GENCFG_POS_DECODE_MASK << PIIX4_F0_GENCFG_POS_DECODE_SHIFT)
#define PIIX4_F0_GENCFG_ISA_MODE_SHIFT               0 /* established */
#define PIIX4_F0_GENCFG_ISA_MODE_MASK                0x1u
#define PIIX4_F0_GENCFG_ISA_MODE_INPLACE (PIIX4_F0_GENCFG_ISA_MODE_MASK << PIIX4_F0_GENCFG_ISA_MODE_SHIFT)

/*
 * Real-time clock configuration. The PROM writes 0x25 (positive decode, upper
 * bank enable, RTC enable). The HAL sets bit 2 by read-modify-write before
 * using the extended clock RAM at ports 0x72 and 0x73. The PROM's self-test
 * clears and sets bit 0 around its clock RAM probe. The lock bits are
 * write-once until a hardware reset. With bit 2 clear the datasheet says the
 * access is forwarded to ISA (RTCCFG text) and also lists ports 0x72 to 0x77 as
 * aliases of the index and data ports (Table 5); the two statements conflict.
 */
/* f0_rtccfg: rw8, space piix4_f0, reset 0x21; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.67-68 */
#define PIIX4_F0_RTCCFG_OFFSET                       0xcbu /* established */
#define PIIX4_F0_RTCCFG_POS_DECODE_SHIFT             5 /* established */
#define PIIX4_F0_RTCCFG_POS_DECODE_MASK              0x1u
#define PIIX4_F0_RTCCFG_POS_DECODE_INPLACE (PIIX4_F0_RTCCFG_POS_DECODE_MASK << PIIX4_F0_RTCCFG_POS_DECODE_SHIFT)
#define PIIX4_F0_RTCCFG_LOCK_UPPER_SHIFT             4 /* established */
#define PIIX4_F0_RTCCFG_LOCK_UPPER_MASK              0x1u
#define PIIX4_F0_RTCCFG_LOCK_UPPER_INPLACE (PIIX4_F0_RTCCFG_LOCK_UPPER_MASK << PIIX4_F0_RTCCFG_LOCK_UPPER_SHIFT)
#define PIIX4_F0_RTCCFG_LOCK_LOWER_SHIFT             3 /* established */
#define PIIX4_F0_RTCCFG_LOCK_LOWER_MASK              0x1u
#define PIIX4_F0_RTCCFG_LOCK_LOWER_INPLACE (PIIX4_F0_RTCCFG_LOCK_LOWER_MASK << PIIX4_F0_RTCCFG_LOCK_LOWER_SHIFT)
#define PIIX4_F0_RTCCFG_UPPER_EN_SHIFT               2 /* established */
#define PIIX4_F0_RTCCFG_UPPER_EN_MASK                0x1u
#define PIIX4_F0_RTCCFG_UPPER_EN_INPLACE (PIIX4_F0_RTCCFG_UPPER_EN_MASK << PIIX4_F0_RTCCFG_UPPER_EN_SHIFT)
#define PIIX4_F0_RTCCFG_RTC_EN_SHIFT                 0 /* established */
#define PIIX4_F0_RTCCFG_RTC_EN_MASK                  0x1u
#define PIIX4_F0_RTCCFG_RTC_EN_INPLACE (PIIX4_F0_RTCCFG_RTC_EN_MASK << PIIX4_F0_RTCCFG_RTC_EN_SHIFT)

/*
 * Vendor identification, Intel.
 */
/* f1_vid: r16, space piix4_f1, reset 0x8086; Intel 82371AB datasheet 290562-001
 * (April 1997) p.89 */
#define PIIX4_F1_VID_OFFSET                          0x0u /* established */

/*
 * Device identification of function 1.
 */
/* f1_did: r16, space piix4_f1, reset 0x7111; Intel 82371AB datasheet 290562-001
 * (April 1997) p.89 */
#define PIIX4_F1_DID_OFFSET                          0x2u /* established */

/*
 * PCI command. The PROM's IDE attach writes 5 (I/O space and bus master
 * enable). The read-only mask lists the hardwired and reserved bits; only the
 * fields shown are writable.
 */
/* f1_pcicmd: rw16, space piix4_f1, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.89-90 */
#define PIIX4_F1_PCICMD_OFFSET                       0x4u /* established */
#define PIIX4_F1_PCICMD_BME_SHIFT                    2 /* established */
#define PIIX4_F1_PCICMD_BME_MASK                     0x1u
#define PIIX4_F1_PCICMD_BME_INPLACE (PIIX4_F1_PCICMD_BME_MASK << PIIX4_F1_PCICMD_BME_SHIFT)
#define PIIX4_F1_PCICMD_IOSE_SHIFT                   0 /* established */
#define PIIX4_F1_PCICMD_IOSE_MASK                    0x1u
#define PIIX4_F1_PCICMD_IOSE_INPLACE (PIIX4_F1_PCICMD_IOSE_MASK << PIIX4_F1_PCICMD_IOSE_SHIFT)

/*
 * PCI status.
 */
/* f1_pcists: rw16, space piix4_f1, reset 0x280; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.90 */
#define PIIX4_F1_PCISTS_OFFSET                       0x6u /* established */

/*
 * Revision.
 */
/* f1_rid: r8, space piix4_f1, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.91 */
#define PIIX4_F1_RID_OFFSET                          0x8u /* established */

/*
 * Class code, programming interface (bus master capable, both channels legacy
 * mode).
 */
/* f1_classc_pi: r8, space piix4_f1, reset 0x80; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.91 */
#define PIIX4_F1_CLASSC_PI_OFFSET                    0x9u /* established */

/*
 * Class code, sub-class: IDE.
 */
/* f1_classc_scc: r8, space piix4_f1, reset 0x1; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.91 */
#define PIIX4_F1_CLASSC_SCC_OFFSET                   0xau /* established */

/*
 * Class code, base class: mass storage.
 */
/* f1_classc_basec: r8, space piix4_f1, reset 0x1; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.91 */
#define PIIX4_F1_CLASSC_BASEC_OFFSET                 0xbu /* established */

/*
 * Master latency timer. The PROM's IDE attach writes 0x80.
 */
/* f1_mlt: rw8, space piix4_f1, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.91 */
#define PIIX4_F1_MLT_OFFSET                          0xdu /* established */

/*
 * Header type, 0: single function (multifunction is reported by function 0).
 */
/* f1_hedt: r8, space piix4_f1, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.92 */
#define PIIX4_F1_HEDT_OFFSET                         0xeu /* established */

/*
 * Bus-master interface base address: I/O space, bits 15:4 are address bits, bit
 * 0 hardwired 1.
 */
/* f1_bmiba: rw32, space piix4_f1, reset 0x1; Intel 82371AB datasheet 290562-001
 * (April 1997) p.92 */
#define PIIX4_F1_BMIBA_OFFSET                        0x20u /* established */
#define PIIX4_F1_BMIBA_BASE_SHIFT                    4 /* established */
#define PIIX4_F1_BMIBA_BASE_MASK                     0xfffu
#define PIIX4_F1_BMIBA_BASE_INPLACE (PIIX4_F1_BMIBA_BASE_MASK << PIIX4_F1_BMIBA_BASE_SHIFT)
#define PIIX4_F1_BMIBA_RTE_SHIFT                     0 /* established */
#define PIIX4_F1_BMIBA_RTE_MASK                      0x1u
#define PIIX4_F1_BMIBA_RTE_INPLACE (PIIX4_F1_BMIBA_RTE_MASK << PIIX4_F1_BMIBA_RTE_SHIFT)

/*
 * IDE timing: 0x40 primary channel, 0x42 secondary. The PROM's IDE attach
 * writes the dword 0xc077c077 (both channels: decode enabled, slave timing
 * register enabled, fast timing with prefetch and IORDY sampling on both
 * drives, ISP 5 clocks, RTC 4 clocks) and, on board type 1 (the 540, which has
 * one IDE channel), writes the byte 0x40 to 0x43, which leaves only the slave
 * timing enable set for the secondary channel and its decode disabled.
 */
/* f1_idetim: rw16, space piix4_f1, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.93-94 */
#define PIIX4_F1_IDETIM_OFFSET                       0x40u /* established */
#define PIIX4_F1_IDETIM_COUNT                        2
#define PIIX4_F1_IDETIM_STRIDE                       2
#define PIIX4_F1_IDETIM_IDE_EN_SHIFT                 15 /* established */
#define PIIX4_F1_IDETIM_IDE_EN_MASK                  0x1u
#define PIIX4_F1_IDETIM_IDE_EN_INPLACE (PIIX4_F1_IDETIM_IDE_EN_MASK << PIIX4_F1_IDETIM_IDE_EN_SHIFT)
#define PIIX4_F1_IDETIM_SITRE_SHIFT                  14 /* established */
#define PIIX4_F1_IDETIM_SITRE_MASK                   0x1u
#define PIIX4_F1_IDETIM_SITRE_INPLACE (PIIX4_F1_IDETIM_SITRE_MASK << PIIX4_F1_IDETIM_SITRE_SHIFT)
#define PIIX4_F1_IDETIM_ISP_SHIFT                    12 /* established */
#define PIIX4_F1_IDETIM_ISP_MASK                     0x3u
#define PIIX4_F1_IDETIM_ISP_INPLACE (PIIX4_F1_IDETIM_ISP_MASK << PIIX4_F1_IDETIM_ISP_SHIFT)
#define PIIX4_F1_IDETIM_RTC_SHIFT                    8 /* established */
#define PIIX4_F1_IDETIM_RTC_MASK                     0x3u
#define PIIX4_F1_IDETIM_RTC_INPLACE (PIIX4_F1_IDETIM_RTC_MASK << PIIX4_F1_IDETIM_RTC_SHIFT)
#define PIIX4_F1_IDETIM_DTE1_SHIFT                   7 /* established */
#define PIIX4_F1_IDETIM_DTE1_MASK                    0x1u
#define PIIX4_F1_IDETIM_DTE1_INPLACE (PIIX4_F1_IDETIM_DTE1_MASK << PIIX4_F1_IDETIM_DTE1_SHIFT)
#define PIIX4_F1_IDETIM_PPE1_SHIFT                   6 /* established */
#define PIIX4_F1_IDETIM_PPE1_MASK                    0x1u
#define PIIX4_F1_IDETIM_PPE1_INPLACE (PIIX4_F1_IDETIM_PPE1_MASK << PIIX4_F1_IDETIM_PPE1_SHIFT)
#define PIIX4_F1_IDETIM_IE1_SHIFT                    5 /* established */
#define PIIX4_F1_IDETIM_IE1_MASK                     0x1u
#define PIIX4_F1_IDETIM_IE1_INPLACE (PIIX4_F1_IDETIM_IE1_MASK << PIIX4_F1_IDETIM_IE1_SHIFT)
#define PIIX4_F1_IDETIM_TIME1_SHIFT                  4 /* established */
#define PIIX4_F1_IDETIM_TIME1_MASK                   0x1u
#define PIIX4_F1_IDETIM_TIME1_INPLACE (PIIX4_F1_IDETIM_TIME1_MASK << PIIX4_F1_IDETIM_TIME1_SHIFT)
#define PIIX4_F1_IDETIM_DTE0_SHIFT                   3 /* established */
#define PIIX4_F1_IDETIM_DTE0_MASK                    0x1u
#define PIIX4_F1_IDETIM_DTE0_INPLACE (PIIX4_F1_IDETIM_DTE0_MASK << PIIX4_F1_IDETIM_DTE0_SHIFT)
#define PIIX4_F1_IDETIM_PPE0_SHIFT                   2 /* established */
#define PIIX4_F1_IDETIM_PPE0_MASK                    0x1u
#define PIIX4_F1_IDETIM_PPE0_INPLACE (PIIX4_F1_IDETIM_PPE0_MASK << PIIX4_F1_IDETIM_PPE0_SHIFT)
#define PIIX4_F1_IDETIM_IE0_SHIFT                    1 /* established */
#define PIIX4_F1_IDETIM_IE0_MASK                     0x1u
#define PIIX4_F1_IDETIM_IE0_INPLACE (PIIX4_F1_IDETIM_IE0_MASK << PIIX4_F1_IDETIM_IE0_SHIFT)
#define PIIX4_F1_IDETIM_TIME0_SHIFT                  0 /* established */
#define PIIX4_F1_IDETIM_TIME0_MASK                   0x1u
#define PIIX4_F1_IDETIM_TIME0_INPLACE (PIIX4_F1_IDETIM_TIME0_MASK << PIIX4_F1_IDETIM_TIME0_SHIFT)

/*
 * Slave IDE timing (drive 1 of each channel) when IDETIM bit 14 is set. The
 * PROM writes 0.
 */
/* f1_sidetim: rw8, space piix4_f1, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.95 */
#define PIIX4_F1_SIDETIM_OFFSET                      0x44u /* established */

/*
 * Ultra DMA/33 enable per drive.
 */
/* f1_udmactl: rw8, space piix4_f1, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.96 */
#define PIIX4_F1_UDMACTL_OFFSET                      0x48u /* established */
#define PIIX4_F1_UDMACTL_SSDE1_SHIFT                 3 /* established */
#define PIIX4_F1_UDMACTL_SSDE1_MASK                  0x1u
#define PIIX4_F1_UDMACTL_SSDE1_INPLACE (PIIX4_F1_UDMACTL_SSDE1_MASK << PIIX4_F1_UDMACTL_SSDE1_SHIFT)
#define PIIX4_F1_UDMACTL_SSDE0_SHIFT                 2 /* established */
#define PIIX4_F1_UDMACTL_SSDE0_MASK                  0x1u
#define PIIX4_F1_UDMACTL_SSDE0_INPLACE (PIIX4_F1_UDMACTL_SSDE0_MASK << PIIX4_F1_UDMACTL_SSDE0_SHIFT)
#define PIIX4_F1_UDMACTL_PSDE1_SHIFT                 1 /* established */
#define PIIX4_F1_UDMACTL_PSDE1_MASK                  0x1u
#define PIIX4_F1_UDMACTL_PSDE1_INPLACE (PIIX4_F1_UDMACTL_PSDE1_MASK << PIIX4_F1_UDMACTL_PSDE1_SHIFT)
#define PIIX4_F1_UDMACTL_PSDE0_SHIFT                 0 /* established */
#define PIIX4_F1_UDMACTL_PSDE0_MASK                  0x1u
#define PIIX4_F1_UDMACTL_PSDE0_INPLACE (PIIX4_F1_UDMACTL_PSDE0_MASK << PIIX4_F1_UDMACTL_PSDE0_SHIFT)

/*
 * Ultra DMA/33 cycle times, two bits per drive (00 CT 4 and RP 6 PCI clocks, 01
 * 3 and 5, 10 2 and 4).
 */
/* f1_udmatim: rw16, space piix4_f1, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.96-97 */
#define PIIX4_F1_UDMATIM_OFFSET                      0x4au /* established */
#define PIIX4_F1_UDMATIM_SCT1_SHIFT                  12 /* established */
#define PIIX4_F1_UDMATIM_SCT1_MASK                   0x3u
#define PIIX4_F1_UDMATIM_SCT1_INPLACE (PIIX4_F1_UDMATIM_SCT1_MASK << PIIX4_F1_UDMATIM_SCT1_SHIFT)
#define PIIX4_F1_UDMATIM_SCT0_SHIFT                  8 /* established */
#define PIIX4_F1_UDMATIM_SCT0_MASK                   0x3u
#define PIIX4_F1_UDMATIM_SCT0_INPLACE (PIIX4_F1_UDMATIM_SCT0_MASK << PIIX4_F1_UDMATIM_SCT0_SHIFT)
#define PIIX4_F1_UDMATIM_PCT1_SHIFT                  4 /* established */
#define PIIX4_F1_UDMATIM_PCT1_MASK                   0x3u
#define PIIX4_F1_UDMATIM_PCT1_INPLACE (PIIX4_F1_UDMATIM_PCT1_MASK << PIIX4_F1_UDMATIM_PCT1_SHIFT)
#define PIIX4_F1_UDMATIM_PCT0_SHIFT                  0 /* established */
#define PIIX4_F1_UDMATIM_PCT0_MASK                   0x3u
#define PIIX4_F1_UDMATIM_PCT0_INPLACE (PIIX4_F1_UDMATIM_PCT0_MASK << PIIX4_F1_UDMATIM_PCT0_SHIFT)

/*
 * Vendor identification, Intel.
 */
/* f2_vid: r16, space piix4_f2, reset 0x8086; Intel 82371AB datasheet 290562-001
 * (April 1997) p.102 */
#define PIIX4_F2_VID_OFFSET                          0x0u /* established */

/*
 * Device identification of function 2.
 */
/* f2_did: r16, space piix4_f2, reset 0x7112; Intel 82371AB datasheet 290562-001
 * (April 1997) p.102 */
#define PIIX4_F2_DID_OFFSET                          0x2u /* established */

/*
 * PCI command. The read-only mask lists the hardwired and reserved bits; only
 * the fields shown are writable.
 */
/* f2_pcicmd: rw16, space piix4_f2, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.103 */
#define PIIX4_F2_PCICMD_OFFSET                       0x4u /* established */

/*
 * PCI status.
 */
/* f2_pcists: rw16, space piix4_f2, reset 0x280; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.103-104 */
#define PIIX4_F2_PCISTS_OFFSET                       0x6u /* established */

/*
 * Revision.
 */
/* f2_rid: r8, space piix4_f2, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.104 */
#define PIIX4_F2_RID_OFFSET                          0x8u /* established */

/*
 * Class code, programming interface: OpenHCI-style USB host controller.
 */
/* f2_classc_pi: r8, space piix4_f2, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.104 */
#define PIIX4_F2_CLASSC_PI_OFFSET                    0x9u /* established */

/*
 * Class code, sub-class: USB.
 */
/* f2_classc_scc: r8, space piix4_f2, reset 0x3; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.104 */
#define PIIX4_F2_CLASSC_SCC_OFFSET                   0xau /* established */

/*
 * Class code, base class: serial bus.
 */
/* f2_classc_basec: r8, space piix4_f2, reset 0xc; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.104 */
#define PIIX4_F2_CLASSC_BASEC_OFFSET                 0xbu /* established */

/*
 * Master latency timer.
 */
/* f2_mlt: rw8, space piix4_f2, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.105 */
#define PIIX4_F2_MLT_OFFSET                          0xdu /* established */

/*
 * Header type, 0.
 */
/* f2_hedt: r8, space piix4_f2, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.105 */
#define PIIX4_F2_HEDT_OFFSET                         0xeu /* established */

/*
 * USB I/O space base address: bits 15:5, bit 0 hardwired 1. The datasheet's
 * default of 00h disagrees with bit 0 being hardwired to 1; the reset here is 1
 * (inferred).
 */
/* f2_usbba: rw32, space piix4_f2, reset 0x1; Intel 82371AB datasheet 290562-001
 * (April 1997) p.108 */
#define PIIX4_F2_USBBA_OFFSET                        0x20u /* established */
#define PIIX4_F2_USBBA_BASE_SHIFT                    5 /* established */
#define PIIX4_F2_USBBA_BASE_MASK                     0x7ffu
#define PIIX4_F2_USBBA_BASE_INPLACE (PIIX4_F2_USBBA_BASE_MASK << PIIX4_F2_USBBA_BASE_SHIFT)
#define PIIX4_F2_USBBA_RTE_SHIFT                     0 /* established */
#define PIIX4_F2_USBBA_RTE_MASK                      0x1u
#define PIIX4_F2_USBBA_RTE_INPLACE (PIIX4_F2_USBBA_RTE_MASK << PIIX4_F2_USBBA_RTE_SHIFT)

/*
 * Interrupt line; no effect on the hardware.
 */
/* f2_intln: rw8, space piix4_f2, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.105 */
#define PIIX4_F2_INTLN_OFFSET                        0x3cu /* established */

/*
 * Interrupt pin, hardwired 4 (INTD#). The datasheet says the USB interrupt is
 * also ORed to PIRQD#; the board wires only this pin to its own interrupt
 * entry, never through the 8259.
 */
/* f2_intpn: r8, space piix4_f2, reset 0x4; Intel 82371AB datasheet 290562-001
 * (April 1997) p.106 */
#define PIIX4_F2_INTPN_OFFSET                        0x3du /* established */

/*
 * Serial bus release number, 0x10 (USB 1.0).
 */
/* f2_sbrnum: r8, space piix4_f2, reset 0x10; Intel 82371AB datasheet 290562-001
 * (April 1997) p.106 */
#define PIIX4_F2_SBRNUM_OFFSET                       0x60u /* established */

/*
 * Legacy keyboard and mouse support: trap and SMI enables and status. Not
 * written by held software.
 */
/* f2_legsup: rw16, space piix4_f2, reset 0x2000; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.107-108 */
#define PIIX4_F2_LEGSUP_OFFSET                       0xc0u /* established */
#define PIIX4_F2_LEGSUP_USBPIRQDEN_SHIFT             13 /* established */
#define PIIX4_F2_LEGSUP_USBPIRQDEN_MASK              0x1u
#define PIIX4_F2_LEGSUP_USBPIRQDEN_INPLACE (PIIX4_F2_LEGSUP_USBPIRQDEN_MASK << PIIX4_F2_LEGSUP_USBPIRQDEN_SHIFT)

/*
 * Miscellaneous support: bit 4 lets a read of port 0x70 return the RTC index.
 * Byte accesses only.
 */
/* f2_miscsup: rw8, space piix4_f2, reset unknown; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.109 */
#define PIIX4_F2_MISCSUP_OFFSET                      0xffu /* established */
#define PIIX4_F2_MISCSUP_RTCIREN_SHIFT               4 /* established */
#define PIIX4_F2_MISCSUP_RTCIREN_MASK                0x1u
#define PIIX4_F2_MISCSUP_RTCIREN_INPLACE (PIIX4_F2_MISCSUP_RTCIREN_MASK << PIIX4_F2_MISCSUP_RTCIREN_SHIFT)

/*
 * Vendor identification, Intel.
 */
/* f3_vid: r16, space piix4_f3, reset 0x8086; Intel 82371AB datasheet 290562-001
 * (April 1997) p.117 */
#define PIIX4_F3_VID_OFFSET                          0x0u /* established */

/*
 * Device identification of function 3.
 */
/* f3_did: r16, space piix4_f3, reset 0x7113; Intel 82371AB datasheet 290562-001
 * (April 1997) p.117 */
#define PIIX4_F3_DID_OFFSET                          0x2u /* established */

/*
 * PCI command. Bit 0 enables the SMBus I/O block and works independently of
 * PMREGMISC bit 0. The PROM's function 3 attach sets it after writing the SMBus
 * base. The read-only mask lists the hardwired and reserved bits; only the
 * fields shown are writable.
 */
/* f3_pcicmd: rw16, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.117-118 */
#define PIIX4_F3_PCICMD_OFFSET                       0x4u /* established */
#define PIIX4_F3_PCICMD_IOSE_SHIFT                   0 /* established */
#define PIIX4_F3_PCICMD_IOSE_MASK                    0x1u
#define PIIX4_F3_PCICMD_IOSE_INPLACE (PIIX4_F3_PCICMD_IOSE_MASK << PIIX4_F3_PCICMD_IOSE_SHIFT)

/*
 * PCI status; the PROM's attach clears it by writing 0x3800.
 */
/* f3_pcists: rw16, space piix4_f3, reset 0x280; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.118 */
#define PIIX4_F3_PCISTS_OFFSET                       0x6u /* established */

/*
 * Revision.
 */
/* f3_rid: r8, space piix4_f3, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.119 */
#define PIIX4_F3_RID_OFFSET                          0x8u /* established */

/*
 * Class code, programming interface.
 */
/* f3_classc_pi: r8, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.119 */
#define PIIX4_F3_CLASSC_PI_OFFSET                    0x9u /* established */

/*
 * Class code, sub-class: other bridge.
 */
/* f3_classc_scc: r8, space piix4_f3, reset 0x80; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.119 */
#define PIIX4_F3_CLASSC_SCC_OFFSET                   0xau /* established */

/*
 * Class code, base class: bridge.
 */
/* f3_classc_basec: r8, space piix4_f3, reset 0x6; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.119 */
#define PIIX4_F3_CLASSC_BASEC_OFFSET                 0xbu /* established */

/*
 * Header type, 0.
 */
/* f3_hedt: r8, space piix4_f3, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.119 */
#define PIIX4_F3_HEDT_OFFSET                         0xeu /* established */

/*
 * Interrupt line. The datasheet (p.120) says it has no effect on the hardware.
 * Specification update spec change 9 (p.15) says the register 'is not
 * implemented and is RESERVED'.
 */
/* f3_intln: rw8, space piix4_f3, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.120 */
#define PIIX4_F3_INTLN_OFFSET                        0x3cu /* established */

/*
 * Interrupt pin: not implemented. The datasheet (p.120) says it is read only,
 * default 01h, and that PIRQA# is used for the power management module.
 * Specification update spec change 1 (p.13) retitles it 'INTPN Register Not
 * Implemented' and says: 'the INTPN register indicates the PCI interrupt pin
 * PIRQA# is used for routing Serial Interrupts. However, Serial Interrupts are
 * hardwired to IRQ9. This register is not implemented.' It lists bits 7:0 as
 * Not Implemented with default 00h. The datasheet's pin A is superseded. The
 * update says 'Serial Interrupts'; that this means the power management and
 * SMBus interrupts is our reading (inferred). What a read returns is taken as 0
 * from the update's default.
 */
/* f3_intpn: r8, space piix4_f3, reset 0x0; Intel 82371AB specification update
 * 297738-017 (January 2002) p.13 */
#define PIIX4_F3_INTPN_OFFSET                        0x3du /* established */

/*
 * Power management base address. Bits 15:6 hold the I/O base, bit 0 is
 * hardwired 1, bits 31:16 are hardwired 0. The PROM writes 0x0f80 and the
 * register then reads 0x0f81; the base 0xf80 is what Linux and the HAL assume.
 * The HAL never programs it.
 */
/* f3_pmba: rw32, space piix4_f3, reset 0x1; Intel 82371AB datasheet 290562-001
 * (April 1997) p.120 */
#define PIIX4_F3_PMBA_OFFSET                         0x40u /* established */
#define PIIX4_F3_PMBA_BASE_SHIFT                     6 /* established */
#define PIIX4_F3_PMBA_BASE_MASK                      0x3ffu
#define PIIX4_F3_PMBA_BASE_INPLACE (PIIX4_F3_PMBA_BASE_MASK << PIIX4_F3_PMBA_BASE_SHIFT)
#define PIIX4_F3_PMBA_RTE_SHIFT                      0 /* established */
#define PIIX4_F3_PMBA_RTE_MASK                       0x1u
#define PIIX4_F3_PMBA_RTE_INPLACE (PIIX4_F3_PMBA_RTE_MASK << PIIX4_F3_PMBA_RTE_SHIFT)

/*
 * Idle timer counts and resolutions for the device monitors and the slow burst
 * count. Not written by held software.
 */
/* f3_cnta: rw32, space piix4_f3, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.121 */
#define PIIX4_F3_CNTA_OFFSET                         0x44u /* established */

/*
 * Fast burst timer count, CPU select, thermal duty and video status. The
 * specification update (spec change 5) corrects bit 5 to 8 microsecond
 * granularity. Not written by held software.
 */
/* f3_cntb: rw32, space piix4_f3, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.121-122 */
#define PIIX4_F3_CNTB_OFFSET                         0x48u /* established */

/*
 * General purpose input control: enable, polarity and edge for the
 * device-monitor GPI inputs (Table 17 maps GPI18 to GPI21 to device monitors 10
 * to 13). Not written by held software.
 */
/* f3_gpictl: rw32, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.123 */
#define PIIX4_F3_GPICTL_OFFSET                       0x4cu /* established */

/*
 * Miscellaneous power management. The PROM writes 1 after the base. When the
 * bit is clear every access to the power management block goes unclaimed.
 */
/* f3_pmregmisc: rw8, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.134 */
#define PIIX4_F3_PMREGMISC_OFFSET                    0x80u /* established */
#define PIIX4_F3_PMREGMISC_PMIOSE_SHIFT              0 /* established */
#define PIIX4_F3_PMREGMISC_PMIOSE_MASK               0x1u
#define PIIX4_F3_PMREGMISC_PMIOSE_INPLACE (PIIX4_F3_PMREGMISC_PMIOSE_MASK << PIIX4_F3_PMREGMISC_PMIOSE_SHIFT)

/*
 * SMBus base address: bits 15:4, bit 0 hardwired 1. The PROM's function 3
 * attach writes 0x0fd0, so the register reads 0x00000fd1 (not read back by any
 * held software); neither HAL build touches it.
 */
/* f3_smbba: rw32, space piix4_f3, reset 0x1; Intel 82371AB datasheet 290562-001
 * (April 1997) p.135 */
#define PIIX4_F3_SMBBA_OFFSET                        0x90u /* established */
#define PIIX4_F3_SMBBA_BASE_SHIFT                    4 /* established */
#define PIIX4_F3_SMBBA_BASE_MASK                     0xfffu
#define PIIX4_F3_SMBBA_BASE_INPLACE (PIIX4_F3_SMBBA_BASE_MASK << PIIX4_F3_SMBBA_BASE_SHIFT)
#define PIIX4_F3_SMBBA_RTE_SHIFT                     0 /* established */
#define PIIX4_F3_SMBBA_RTE_MASK                      0x1u
#define PIIX4_F3_SMBBA_RTE_INPLACE (PIIX4_F3_SMBBA_RTE_MASK << PIIX4_F3_SMBBA_RTE_SHIFT)

/*
 * SMBus host configuration. The PROM writes 0x09: host interface enabled and
 * the interrupt routed to IRQ9.
 */
/* f3_smbhstcfg: rw8, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.135 */
#define PIIX4_F3_SMBHSTCFG_OFFSET                    0xd2u /* established */
#define PIIX4_F3_SMBHSTCFG_INTRSEL_SHIFT             1 /* established */
#define PIIX4_F3_SMBHSTCFG_INTRSEL_MASK              0x7u
#define PIIX4_F3_SMBHSTCFG_INTRSEL_INPLACE (PIIX4_F3_SMBHSTCFG_INTRSEL_MASK << PIIX4_F3_SMBHSTCFG_INTRSEL_SHIFT)
#define PIIX4_F3_SMBHSTCFG_HOST_EN_SHIFT             0 /* established */
#define PIIX4_F3_SMBHSTCFG_HOST_EN_MASK              0x1u
#define PIIX4_F3_SMBHSTCFG_HOST_EN_INPLACE (PIIX4_F3_SMBHSTCFG_HOST_EN_MASK << PIIX4_F3_SMBHSTCFG_HOST_EN_SHIFT)

/*
 * SMBus slave command match value.
 */
/* f3_smbslvc: rw8, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.135 */
#define PIIX4_F3_SMBSLVC_OFFSET                      0xd3u /* established */

/*
 * SMBus slave shadow port 1.
 */
/* f3_smbshdw1: rw8, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.136 */
#define PIIX4_F3_SMBSHDW1_OFFSET                     0xd4u /* established */

/*
 * SMBus slave shadow port 2.
 */
/* f3_smbshdw2: rw8, space piix4_f3, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.136 */
#define PIIX4_F3_SMBSHDW2_OFFSET                     0xd5u /* established */

/*
 * SMBus revision.
 */
/* f3_smbrev: r8, space piix4_f3, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.136 */
#define PIIX4_F3_SMBREV_OFFSET                       0xd6u /* established */

/*
 * Reset X-bus IRQ12/M and IRQ1: a read clears the latched mouse and keyboard
 * interrupts; the read value has no defined pattern. Reads and writes are also
 * sent to ISA.
 */
/* rirq: r8, space piix4_isa, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.86 */
#define PIIX4_RIRQ_OFFSET                            0x60u /* established */

/*
 * NMI status and control. Bits 7:4 are read-only status (SERR# NMI source,
 * IOCHK# NMI source, counter 2 output, refresh toggle) and must be written as
 * 0.
 */
/* nmisc: rw8, space piix4_isa, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.83 */
#define PIIX4_NMISC_OFFSET                           0x61u /* established */
#define PIIX4_NMISC_SERR_STATUS_SHIFT                7 /* established */
#define PIIX4_NMISC_SERR_STATUS_MASK                 0x1u
#define PIIX4_NMISC_SERR_STATUS_INPLACE (PIIX4_NMISC_SERR_STATUS_MASK << PIIX4_NMISC_SERR_STATUS_SHIFT)
#define PIIX4_NMISC_IOCHK_STATUS_SHIFT               6 /* established */
#define PIIX4_NMISC_IOCHK_STATUS_MASK                0x1u
#define PIIX4_NMISC_IOCHK_STATUS_INPLACE (PIIX4_NMISC_IOCHK_STATUS_MASK << PIIX4_NMISC_IOCHK_STATUS_SHIFT)
#define PIIX4_NMISC_TIMER2_OUT_SHIFT                 5 /* established */
#define PIIX4_NMISC_TIMER2_OUT_MASK                  0x1u
#define PIIX4_NMISC_TIMER2_OUT_INPLACE (PIIX4_NMISC_TIMER2_OUT_MASK << PIIX4_NMISC_TIMER2_OUT_SHIFT)
#define PIIX4_NMISC_REFRESH_SHIFT                    4 /* established */
#define PIIX4_NMISC_REFRESH_MASK                     0x1u
#define PIIX4_NMISC_REFRESH_INPLACE (PIIX4_NMISC_REFRESH_MASK << PIIX4_NMISC_REFRESH_SHIFT)
#define PIIX4_NMISC_IOCHK_DIS_SHIFT                  3 /* established */
#define PIIX4_NMISC_IOCHK_DIS_MASK                   0x1u
#define PIIX4_NMISC_IOCHK_DIS_INPLACE (PIIX4_NMISC_IOCHK_DIS_MASK << PIIX4_NMISC_IOCHK_DIS_SHIFT)
#define PIIX4_NMISC_SERR_DIS_SHIFT                   2 /* established */
#define PIIX4_NMISC_SERR_DIS_MASK                    0x1u
#define PIIX4_NMISC_SERR_DIS_INPLACE (PIIX4_NMISC_SERR_DIS_MASK << PIIX4_NMISC_SERR_DIS_SHIFT)
#define PIIX4_NMISC_SPKR_EN_SHIFT                    1 /* established */
#define PIIX4_NMISC_SPKR_EN_MASK                     0x1u
#define PIIX4_NMISC_SPKR_EN_INPLACE (PIIX4_NMISC_SPKR_EN_MASK << PIIX4_NMISC_SPKR_EN_SHIFT)
#define PIIX4_NMISC_TIMER2_EN_SHIFT                  0 /* established */
#define PIIX4_NMISC_TIMER2_EN_MASK                   0x1u
#define PIIX4_NMISC_TIMER2_EN_INPLACE (PIIX4_NMISC_TIMER2_EN_MASK << PIIX4_NMISC_TIMER2_EN_SHIFT)

/*
 * RTC index and NMI enable, shared. Bits 6:0 index the lower RTC bank and are
 * undefined at reset (the datasheet gives only 'Bit[6:0]=undefined; Bit 7=1',
 * p.84); bit 7 set disables NMI. Write only. The PROM and the HAL reach the
 * clock through ports 0x70 and 0x71.
 */
/* rtci: w8, space piix4_isa, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.84-85 */
#define PIIX4_RTCI_OFFSET                            0x70u /* established */
#define PIIX4_RTCI_NMI_DIS_SHIFT                     7 /* established */
#define PIIX4_RTCI_NMI_DIS_MASK                      0x1u
#define PIIX4_RTCI_NMI_DIS_INPLACE (PIIX4_RTCI_NMI_DIS_MASK << PIIX4_RTCI_NMI_DIS_SHIFT)
#define PIIX4_RTCI_ADDR_SHIFT                        0 /* established */
#define PIIX4_RTCI_ADDR_MASK                         0x7fu
#define PIIX4_RTCI_ADDR_INPLACE (PIIX4_RTCI_ADDR_MASK << PIIX4_RTCI_ADDR_SHIFT)

/*
 * RTC data, lower 128-byte bank.
 */
/* rtcd: rw8, space piix4_isa, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.85 */
#define PIIX4_RTCD_OFFSET                            0x71u /* established */

/*
 * RTC extended index: bits 6:0 address the upper bank (the datasheet lists it
 * write only in its register page and read/write in Table 5). Bit 7 is the
 * aliased NMI enable according to specification update spec change 2 (p.13);
 * the datasheet calls it reserved. The upper bank is reached only with RTCCFG
 * bit 2 set.
 */
/* rtcei: w8, space piix4_isa, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.85 */
#define PIIX4_RTCEI_OFFSET                           0x72u /* established */
#define PIIX4_RTCEI_NMI_DIS_SHIFT                    7 /* established */
#define PIIX4_RTCEI_NMI_DIS_MASK                     0x1u
#define PIIX4_RTCEI_NMI_DIS_INPLACE (PIIX4_RTCEI_NMI_DIS_MASK << PIIX4_RTCEI_NMI_DIS_SHIFT)
#define PIIX4_RTCEI_ADDR_SHIFT                       0 /* established */
#define PIIX4_RTCEI_ADDR_MASK                        0x7fu
#define PIIX4_RTCEI_ADDR_INPLACE (PIIX4_RTCEI_ADDR_MASK << PIIX4_RTCEI_ADDR_SHIFT)

/*
 * RTC extended data, upper 128-byte bank (battery-backed RAM).
 */
/* rtced: rw8, space piix4_isa, reset unknown; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.85 */
#define PIIX4_RTCED_OFFSET                           0x73u /* established */

/*
 * Port 92. The PROM never writes it; the application processors set bit 1. The
 * datasheet text says FAST_A20 set asserts A20M# low but its own table and
 * specification update documentation change 11 (p.54) say a 1 deasserts A20M#.
 */
/* p92: rw8, space piix4_isa, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.87 */
#define PIIX4_P92_OFFSET                             0x92u /* established */
#define PIIX4_P92_FAST_A20_SHIFT                     1 /* established */
#define PIIX4_P92_FAST_A20_MASK                      0x1u
#define PIIX4_P92_FAST_A20_INPLACE (PIIX4_P92_FAST_A20_MASK << PIIX4_P92_FAST_A20_SHIFT)
#define PIIX4_P92_FAST_INIT_SHIFT                    0 /* established */
#define PIIX4_P92_FAST_INIT_MASK                     0x1u
#define PIIX4_P92_FAST_INIT_INPLACE (PIIX4_P92_FAST_INIT_MASK << PIIX4_P92_FAST_INIT_SHIFT)

/*
 * APM control port; a write can raise an SMI#.
 */
/* apmc: rw8, space piix4_isa, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.86 */
#define PIIX4_APMC_OFFSET                            0xb2u /* established */

/*
 * APM status port.
 */
/* apms: rw8, space piix4_isa, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.86 */
#define PIIX4_APMS_OFFSET                            0xb3u /* established */

/*
 * Coprocessor error: a write asserts IGNNE# if FERR# is asserted and negates
 * internal IRQ13; any value. Reads and writes flow through to ISA.
 */
/* cerr: w8, space piix4_isa, reset unknown; Intel 82371AB datasheet 290562-001
 * (April 1997) p.87 */
#define PIIX4_CERR_OFFSET                            0xf0u /* established */

/*
 * Reset control. Linux restarts the board by writing 0x06 (reset CPU with
 * system reset set); the HAL does the same on all but the earliest boards. Bit
 * 2 going 0 to 1 starts the reset; bit 1 chooses a hard reset (1) or a soft
 * INIT-only reset (0).
 */
/* rc: rw8, space piix4_isa, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.88 */
#define PIIX4_RC_OFFSET                              0xcf9u /* established */
#define PIIX4_RC_RCPU_SHIFT                          2 /* established */
#define PIIX4_RC_RCPU_MASK                           0x1u
#define PIIX4_RC_RCPU_INPLACE (PIIX4_RC_RCPU_MASK << PIIX4_RC_RCPU_SHIFT)
#define PIIX4_RC_SRST_SHIFT                          1 /* established */
#define PIIX4_RC_SRST_MASK                           0x1u
#define PIIX4_RC_SRST_INPLACE (PIIX4_RC_SRST_MASK << PIIX4_RC_SRST_SHIFT)

/*
 * Power management status. The HAL clears it and reads bit 8 for the power
 * button; the PROM reads it for wake-up state and writes it back to clear.
 */
/* pmsts: rw16, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.137 */
#define PIIX4_PMSTS_OFFSET                           0x0u /* established */
#define PIIX4_PMSTS_RSM_STS_SHIFT                    15 /* established */
#define PIIX4_PMSTS_RSM_STS_MASK                     0x1u
#define PIIX4_PMSTS_RSM_STS_INPLACE (PIIX4_PMSTS_RSM_STS_MASK << PIIX4_PMSTS_RSM_STS_SHIFT)
#define PIIX4_PMSTS_PWRBTNOR_STS_SHIFT               11 /* established */
#define PIIX4_PMSTS_PWRBTNOR_STS_MASK                0x1u
#define PIIX4_PMSTS_PWRBTNOR_STS_INPLACE (PIIX4_PMSTS_PWRBTNOR_STS_MASK << PIIX4_PMSTS_PWRBTNOR_STS_SHIFT)
#define PIIX4_PMSTS_RTC_STS_SHIFT                    10 /* established */
#define PIIX4_PMSTS_RTC_STS_MASK                     0x1u
#define PIIX4_PMSTS_RTC_STS_INPLACE (PIIX4_PMSTS_RTC_STS_MASK << PIIX4_PMSTS_RTC_STS_SHIFT)
#define PIIX4_PMSTS_PWRBTN_STS_SHIFT                 8 /* established */
#define PIIX4_PMSTS_PWRBTN_STS_MASK                  0x1u
#define PIIX4_PMSTS_PWRBTN_STS_INPLACE (PIIX4_PMSTS_PWRBTN_STS_MASK << PIIX4_PMSTS_PWRBTN_STS_SHIFT)
#define PIIX4_PMSTS_GBL_STS_SHIFT                    5 /* established */
#define PIIX4_PMSTS_GBL_STS_MASK                     0x1u
#define PIIX4_PMSTS_GBL_STS_INPLACE (PIIX4_PMSTS_GBL_STS_MASK << PIIX4_PMSTS_GBL_STS_SHIFT)
#define PIIX4_PMSTS_BM_STS_SHIFT                     4 /* established */
#define PIIX4_PMSTS_BM_STS_MASK                      0x1u
#define PIIX4_PMSTS_BM_STS_INPLACE (PIIX4_PMSTS_BM_STS_MASK << PIIX4_PMSTS_BM_STS_SHIFT)
#define PIIX4_PMSTS_TMROF_STS_SHIFT                  0 /* established */
#define PIIX4_PMSTS_TMROF_STS_MASK                   0x1u
#define PIIX4_PMSTS_TMROF_STS_INPLACE (PIIX4_PMSTS_TMROF_STS_MASK << PIIX4_PMSTS_TMROF_STS_SHIFT)

/*
 * Power management resume enable. The PROM and the HAL write 0x0100 (power
 * button).
 */
/* pmen: rw16, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.138 */
#define PIIX4_PMEN_OFFSET                            0x2u /* established */
#define PIIX4_PMEN_RTC_EN_SHIFT                      10 /* established */
#define PIIX4_PMEN_RTC_EN_MASK                       0x1u
#define PIIX4_PMEN_RTC_EN_INPLACE (PIIX4_PMEN_RTC_EN_MASK << PIIX4_PMEN_RTC_EN_SHIFT)
#define PIIX4_PMEN_PWRBTN_EN_SHIFT                   8 /* established */
#define PIIX4_PMEN_PWRBTN_EN_MASK                    0x1u
#define PIIX4_PMEN_PWRBTN_EN_INPLACE (PIIX4_PMEN_PWRBTN_EN_MASK << PIIX4_PMEN_PWRBTN_EN_SHIFT)
#define PIIX4_PMEN_GBL_EN_SHIFT                      5 /* established */
#define PIIX4_PMEN_GBL_EN_MASK                       0x1u
#define PIIX4_PMEN_GBL_EN_INPLACE (PIIX4_PMEN_GBL_EN_MASK << PIIX4_PMEN_GBL_EN_SHIFT)
#define PIIX4_PMEN_TMROF_EN_SHIFT                    0 /* established */
#define PIIX4_PMEN_TMROF_EN_MASK                     0x1u
#define PIIX4_PMEN_TMROF_EN_INPLACE (PIIX4_PMEN_TMROF_EN_MASK << PIIX4_PMEN_TMROF_EN_SHIFT)

/*
 * Power management control. Linux powers off, and the HAL suspends, by writing
 * 0x2000 (suspend enable with type 0, soft off). The PROM writes 0x1401
 * (working type, SCI enabled) at attach and 0x2000 to power down.
 */
/* pmcntrl: rw16, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.138-139 */
#define PIIX4_PMCNTRL_OFFSET                         0x4u /* established */
#define PIIX4_PMCNTRL_SUS_EN_SHIFT                   13 /* established */
#define PIIX4_PMCNTRL_SUS_EN_MASK                    0x1u
#define PIIX4_PMCNTRL_SUS_EN_INPLACE (PIIX4_PMCNTRL_SUS_EN_MASK << PIIX4_PMCNTRL_SUS_EN_SHIFT)
#define PIIX4_PMCNTRL_SUS_TYP_SHIFT                  10 /* established */
#define PIIX4_PMCNTRL_SUS_TYP_MASK                   0x7u
#define PIIX4_PMCNTRL_SUS_TYP_INPLACE (PIIX4_PMCNTRL_SUS_TYP_MASK << PIIX4_PMCNTRL_SUS_TYP_SHIFT)
#define PIIX4_PMCNTRL_SUS_TYP_SOFF                   0 /* established */
#define PIIX4_PMCNTRL_SUS_TYP_STR                    1 /* established */
#define PIIX4_PMCNTRL_SUS_TYP_POSCL                  2 /* established */
#define PIIX4_PMCNTRL_SUS_TYP_POSCCL                 3 /* established */
#define PIIX4_PMCNTRL_SUS_TYP_POS                    4 /* established */
#define PIIX4_PMCNTRL_SUS_TYP_WORKING                5 /* established */
#define PIIX4_PMCNTRL_GBL_RLS_SHIFT                  2 /* established */
#define PIIX4_PMCNTRL_GBL_RLS_MASK                   0x1u
#define PIIX4_PMCNTRL_GBL_RLS_INPLACE (PIIX4_PMCNTRL_GBL_RLS_MASK << PIIX4_PMCNTRL_GBL_RLS_SHIFT)
#define PIIX4_PMCNTRL_BRLD_EN_BM_SHIFT               1 /* established */
#define PIIX4_PMCNTRL_BRLD_EN_BM_MASK                0x1u
#define PIIX4_PMCNTRL_BRLD_EN_BM_INPLACE (PIIX4_PMCNTRL_BRLD_EN_BM_MASK << PIIX4_PMCNTRL_BRLD_EN_BM_SHIFT)
#define PIIX4_PMCNTRL_SCI_EN_SHIFT                   0 /* established */
#define PIIX4_PMCNTRL_SCI_EN_MASK                    0x1u
#define PIIX4_PMCNTRL_SCI_EN_INPLACE (PIIX4_PMCNTRL_SCI_EN_MASK << PIIX4_PMCNTRL_SCI_EN_SHIFT)

/*
 * Power management timer: a free-running 24-bit counter at 3.579545 MHz; bit 23
 * toggling sets TMROF_STS. The register summary table (p.51) lists the register
 * as R/W while its description (p.139) says read only; this unit takes read
 * only.
 */
/* pmtmr: r32, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.139 */
#define PIIX4_PMTMR_OFFSET                           0x8u /* established */
#define PIIX4_PMTMR_TMR_VAL_SHIFT                    0 /* established */
#define PIIX4_PMTMR_TMR_VAL_MASK                     0xffffffu
#define PIIX4_PMTMR_TMR_VAL_INPLACE (PIIX4_PMTMR_TMR_VAL_MASK << PIIX4_PMTMR_TMR_VAL_SHIFT)

/*
 * General purpose status. The PROM reads it (0xf8c) for wake-up and power-fail
 * state.
 */
/* gpsts: rw16, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.139-140 */
#define PIIX4_GPSTS_OFFSET                           0xcu /* established */
#define PIIX4_GPSTS_LID_STS_SHIFT                    11 /* established */
#define PIIX4_GPSTS_LID_STS_MASK                     0x1u
#define PIIX4_GPSTS_LID_STS_INPLACE (PIIX4_GPSTS_LID_STS_MASK << PIIX4_GPSTS_LID_STS_SHIFT)
#define PIIX4_GPSTS_RI_STS_SHIFT                     10 /* established */
#define PIIX4_GPSTS_RI_STS_MASK                      0x1u
#define PIIX4_GPSTS_RI_STS_INPLACE (PIIX4_GPSTS_RI_STS_MASK << PIIX4_GPSTS_RI_STS_SHIFT)
#define PIIX4_GPSTS_GPI_STS_SHIFT                    9 /* established */
#define PIIX4_GPSTS_GPI_STS_MASK                     0x1u
#define PIIX4_GPSTS_GPI_STS_INPLACE (PIIX4_GPSTS_GPI_STS_MASK << PIIX4_GPSTS_GPI_STS_SHIFT)
#define PIIX4_GPSTS_USB_STS_SHIFT                    8 /* established */
#define PIIX4_GPSTS_USB_STS_MASK                     0x1u
#define PIIX4_GPSTS_USB_STS_INPLACE (PIIX4_GPSTS_USB_STS_MASK << PIIX4_GPSTS_USB_STS_SHIFT)
#define PIIX4_GPSTS_THRMOR_STS_SHIFT                 7 /* established */
#define PIIX4_GPSTS_THRMOR_STS_MASK                  0x1u
#define PIIX4_GPSTS_THRMOR_STS_INPLACE (PIIX4_GPSTS_THRMOR_STS_MASK << PIIX4_GPSTS_THRMOR_STS_SHIFT)
#define PIIX4_GPSTS_THRM_STS_SHIFT                   0 /* established */
#define PIIX4_GPSTS_THRM_STS_MASK                    0x1u
#define PIIX4_GPSTS_THRM_STS_INPLACE (PIIX4_GPSTS_THRM_STS_MASK << PIIX4_GPSTS_THRM_STS_SHIFT)

/*
 * General purpose enable. The PROM's function 3 attach writes 0 (0xf8e).
 */
/* gpen: rw16, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.140 */
#define PIIX4_GPEN_OFFSET                            0xeu /* established */
#define PIIX4_GPEN_LID_EN_SHIFT                      11 /* established */
#define PIIX4_GPEN_LID_EN_MASK                       0x1u
#define PIIX4_GPEN_LID_EN_INPLACE (PIIX4_GPEN_LID_EN_MASK << PIIX4_GPEN_LID_EN_SHIFT)
#define PIIX4_GPEN_RI_EN_SHIFT                       10 /* established */
#define PIIX4_GPEN_RI_EN_MASK                        0x1u
#define PIIX4_GPEN_RI_EN_INPLACE (PIIX4_GPEN_RI_EN_MASK << PIIX4_GPEN_RI_EN_SHIFT)
#define PIIX4_GPEN_GPI_EN_SHIFT                      9 /* established */
#define PIIX4_GPEN_GPI_EN_MASK                       0x1u
#define PIIX4_GPEN_GPI_EN_INPLACE (PIIX4_GPEN_GPI_EN_MASK << PIIX4_GPEN_GPI_EN_SHIFT)
#define PIIX4_GPEN_USB_EN_SHIFT                      8 /* established */
#define PIIX4_GPEN_USB_EN_MASK                       0x1u
#define PIIX4_GPEN_USB_EN_INPLACE (PIIX4_GPEN_USB_EN_MASK << PIIX4_GPEN_USB_EN_SHIFT)
#define PIIX4_GPEN_THRM_EN_SHIFT                     0 /* established */
#define PIIX4_GPEN_THRM_EN_MASK                      0x1u
#define PIIX4_GPEN_THRM_EN_INPLACE (PIIX4_GPEN_THRM_EN_MASK << PIIX4_GPEN_THRM_EN_SHIFT)

/*
 * Processor control: throttling, clock control and PCI clock run enables. Not
 * written by held software.
 */
/* pcntrl: rw32, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.141 */
#define PIIX4_PCNTRL_OFFSET                          0x10u /* established */

/*
 * Processor level 2: a read enters stop grant or quick start.
 */
/* plvl2: r8, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.142 */
#define PIIX4_PLVL2_OFFSET                           0x14u /* established */

/*
 * Processor level 3: a read enters stop clock, sleep or deep sleep.
 */
/* plvl3: r8, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.142 */
#define PIIX4_PLVL3_OFFSET                           0x15u /* established */

/*
 * Global status. Bits 10, 8, 5, 2, 1 and 0 are write-1-to-clear; bits 7, 6 and
 * 4 are read only summaries. Bit 11 is labelled R/W in the datasheet but also
 * 'can only be reset by writing a 1', so it is not in the write-1-to-clear mask
 * here (p.143).
 */
/* glbsts: rw16, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.143 */
#define PIIX4_GLBSTS_OFFSET                          0x18u /* established */

/*
 * Device status: idle and trap status of the device monitors.
 */
/* devsts: rw32, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.144 */
#define PIIX4_DEVSTS_OFFSET                          0x1cu /* established */

/*
 * Global enable.
 */
/* glben: rw16, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.144 */
#define PIIX4_GLBEN_OFFSET                           0x20u /* established */

/*
 * Global control: SMI enable, end of SMI, BIOS release, global standby timer.
 */
/* glbctl: rw32, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.145 */
#define PIIX4_GLBCTL_OFFSET                          0x28u /* established */

/*
 * Device control: trap and idle enables of the device monitors.
 */
/* devctl: rw32, space piix4_pm, reset 0x0; Intel 82371AB datasheet 290562-001
 * (April 1997) p.146-147 */
#define PIIX4_DEVCTL_OFFSET                          0x2cu /* established */

/*
 * General purpose input, byte reads only (offsets 0x30 to 0x32; the byte at
 * 0x33 is not listed). Bits 21:0 are the logical value on pins GPI21 to GPI0;
 * GPI13 to GPI21 and GPI1 are not multiplexed, the others need their select
 * bit. A bit that is not configured as an input reads indeterminate. The
 * register is not reset; it follows the pins. Port 0xfb2 is byte 2.
 */
/* gpireg: r32, space piix4_pm, reset unknown; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.147 */
#define PIIX4_GPIREG_OFFSET                          0x30u /* established */
#define PIIX4_GPIREG_BOARD_ID_SHIFT                  18 /* inferred */
#define PIIX4_GPIREG_BOARD_ID_MASK                   0xfu
#define PIIX4_GPIREG_BOARD_ID_INPLACE (PIIX4_GPIREG_BOARD_ID_MASK << PIIX4_GPIREG_BOARD_ID_SHIFT)
#define PIIX4_GPIREG_GPI17_SHIFT                     17 /* established */
#define PIIX4_GPIREG_GPI17_MASK                      0x1u
#define PIIX4_GPIREG_GPI17_INPLACE (PIIX4_GPIREG_GPI17_MASK << PIIX4_GPIREG_GPI17_SHIFT)
#define PIIX4_GPIREG_GPI16_SHIFT                     16 /* established */
#define PIIX4_GPIREG_GPI16_MASK                      0x1u
#define PIIX4_GPIREG_GPI16_INPLACE (PIIX4_GPIREG_GPI16_MASK << PIIX4_GPIREG_GPI16_SHIFT)
#define PIIX4_GPIREG_GPI15_SHIFT                     15 /* established */
#define PIIX4_GPIREG_GPI15_MASK                      0x1u
#define PIIX4_GPIREG_GPI15_INPLACE (PIIX4_GPIREG_GPI15_MASK << PIIX4_GPIREG_GPI15_SHIFT)
#define PIIX4_GPIREG_GPI14_SHIFT                     14 /* established */
#define PIIX4_GPIREG_GPI14_MASK                      0x1u
#define PIIX4_GPIREG_GPI14_INPLACE (PIIX4_GPIREG_GPI14_MASK << PIIX4_GPIREG_GPI14_SHIFT)
#define PIIX4_GPIREG_GPI13_SHIFT                     13 /* established */
#define PIIX4_GPIREG_GPI13_MASK                      0x1u
#define PIIX4_GPIREG_GPI13_INPLACE (PIIX4_GPIREG_GPI13_MASK << PIIX4_GPIREG_GPI13_SHIFT)
#define PIIX4_GPIREG_GPI12_SHIFT                     12 /* established */
#define PIIX4_GPIREG_GPI12_MASK                      0x1u
#define PIIX4_GPIREG_GPI12_INPLACE (PIIX4_GPIREG_GPI12_MASK << PIIX4_GPIREG_GPI12_SHIFT)
#define PIIX4_GPIREG_GPI11_SHIFT                     11 /* established */
#define PIIX4_GPIREG_GPI11_MASK                      0x1u
#define PIIX4_GPIREG_GPI11_INPLACE (PIIX4_GPIREG_GPI11_MASK << PIIX4_GPIREG_GPI11_SHIFT)
#define PIIX4_GPIREG_GPI10_SHIFT                     10 /* established */
#define PIIX4_GPIREG_GPI10_MASK                      0x1u
#define PIIX4_GPIREG_GPI10_INPLACE (PIIX4_GPIREG_GPI10_MASK << PIIX4_GPIREG_GPI10_SHIFT)
#define PIIX4_GPIREG_GPI9_SHIFT                      9 /* established */
#define PIIX4_GPIREG_GPI9_MASK                       0x1u
#define PIIX4_GPIREG_GPI9_INPLACE (PIIX4_GPIREG_GPI9_MASK << PIIX4_GPIREG_GPI9_SHIFT)
#define PIIX4_GPIREG_GPI8_SHIFT                      8 /* established */
#define PIIX4_GPIREG_GPI8_MASK                       0x1u
#define PIIX4_GPIREG_GPI8_INPLACE (PIIX4_GPIREG_GPI8_MASK << PIIX4_GPIREG_GPI8_SHIFT)
#define PIIX4_GPIREG_GPI7_SHIFT                      7 /* established */
#define PIIX4_GPIREG_GPI7_MASK                       0x1u
#define PIIX4_GPIREG_GPI7_INPLACE (PIIX4_GPIREG_GPI7_MASK << PIIX4_GPIREG_GPI7_SHIFT)
#define PIIX4_GPIREG_GPI6_SHIFT                      6 /* established */
#define PIIX4_GPIREG_GPI6_MASK                       0x1u
#define PIIX4_GPIREG_GPI6_INPLACE (PIIX4_GPIREG_GPI6_MASK << PIIX4_GPIREG_GPI6_SHIFT)
#define PIIX4_GPIREG_GPI5_SHIFT                      5 /* established */
#define PIIX4_GPIREG_GPI5_MASK                       0x1u
#define PIIX4_GPIREG_GPI5_INPLACE (PIIX4_GPIREG_GPI5_MASK << PIIX4_GPIREG_GPI5_SHIFT)
#define PIIX4_GPIREG_GPI4_SHIFT                      4 /* established */
#define PIIX4_GPIREG_GPI4_MASK                       0x1u
#define PIIX4_GPIREG_GPI4_INPLACE (PIIX4_GPIREG_GPI4_MASK << PIIX4_GPIREG_GPI4_SHIFT)
#define PIIX4_GPIREG_GPI3_SHIFT                      3 /* established */
#define PIIX4_GPIREG_GPI3_MASK                       0x1u
#define PIIX4_GPIREG_GPI3_INPLACE (PIIX4_GPIREG_GPI3_MASK << PIIX4_GPIREG_GPI3_SHIFT)
#define PIIX4_GPIREG_GPI2_SHIFT                      2 /* established */
#define PIIX4_GPIREG_GPI2_MASK                       0x1u
#define PIIX4_GPIREG_GPI2_INPLACE (PIIX4_GPIREG_GPI2_MASK << PIIX4_GPIREG_GPI2_SHIFT)
#define PIIX4_GPIREG_GPI1_SHIFT                      1 /* established */
#define PIIX4_GPIREG_GPI1_MASK                       0x1u
#define PIIX4_GPIREG_GPI1_INPLACE (PIIX4_GPIREG_GPI1_MASK << PIIX4_GPIREG_GPI1_SHIFT)
#define PIIX4_GPIREG_GPI0_SHIFT                      0 /* established */
#define PIIX4_GPIREG_GPI0_MASK                       0x1u
#define PIIX4_GPIREG_GPI0_INPLACE (PIIX4_GPIREG_GPI0_MASK << PIIX4_GPIREG_GPI0_SHIFT)

/*
 * General purpose output, byte accesses only (ports 0xfb4 to 0xfb7). Bits 30:0
 * drive GPO30 to GPO0 and read back the last value written; a pin shared with
 * another function follows that function until GENCFG or XBCS selects the
 * output. The reset value 0x7fffbfff is the datasheet's default (p.148) and the
 * specification update's erratum 3 (p.23) gives the actual value per bit: bit
 * 31 has no output, bits 30:15 and 13:0 reset to 1 and bit 14 to 0. Port 0xfb5
 * therefore resets to 0xbf.
 */
/* gporeg: rw32, space piix4_pm, reset 0x7fffbfff; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017
 * (January 2002) p.23 */
#define PIIX4_GPOREG_OFFSET                          0x34u /* established */
#define PIIX4_GPOREG_GPO30_SHIFT                     30 /* established */
#define PIIX4_GPOREG_GPO30_MASK                      0x1u
#define PIIX4_GPOREG_GPO30_INPLACE (PIIX4_GPOREG_GPO30_MASK << PIIX4_GPOREG_GPO30_SHIFT)
#define PIIX4_GPOREG_GPO29_SHIFT                     29 /* established */
#define PIIX4_GPOREG_GPO29_MASK                      0x1u
#define PIIX4_GPOREG_GPO29_INPLACE (PIIX4_GPOREG_GPO29_MASK << PIIX4_GPOREG_GPO29_SHIFT)
#define PIIX4_GPOREG_GPO28_SHIFT                     28 /* inferred */
#define PIIX4_GPOREG_GPO28_MASK                      0x1u
#define PIIX4_GPOREG_GPO28_INPLACE (PIIX4_GPOREG_GPO28_MASK << PIIX4_GPOREG_GPO28_SHIFT)
#define PIIX4_GPOREG_GPO27_SHIFT                     27 /* established */
#define PIIX4_GPOREG_GPO27_MASK                      0x1u
#define PIIX4_GPOREG_GPO27_INPLACE (PIIX4_GPOREG_GPO27_MASK << PIIX4_GPOREG_GPO27_SHIFT)
#define PIIX4_GPOREG_GPO26_SHIFT                     26 /* established */
#define PIIX4_GPOREG_GPO26_MASK                      0x1u
#define PIIX4_GPOREG_GPO26_INPLACE (PIIX4_GPOREG_GPO26_MASK << PIIX4_GPOREG_GPO26_SHIFT)
#define PIIX4_GPOREG_GPO25_SHIFT                     25 /* established */
#define PIIX4_GPOREG_GPO25_MASK                      0x1u
#define PIIX4_GPOREG_GPO25_INPLACE (PIIX4_GPOREG_GPO25_MASK << PIIX4_GPOREG_GPO25_SHIFT)
#define PIIX4_GPOREG_GPO24_SHIFT                     24 /* established */
#define PIIX4_GPOREG_GPO24_MASK                      0x1u
#define PIIX4_GPOREG_GPO24_INPLACE (PIIX4_GPOREG_GPO24_MASK << PIIX4_GPOREG_GPO24_SHIFT)
#define PIIX4_GPOREG_GPO23_SHIFT                     23 /* established */
#define PIIX4_GPOREG_GPO23_MASK                      0x1u
#define PIIX4_GPOREG_GPO23_INPLACE (PIIX4_GPOREG_GPO23_MASK << PIIX4_GPOREG_GPO23_SHIFT)
#define PIIX4_GPOREG_GPO22_SHIFT                     22 /* established */
#define PIIX4_GPOREG_GPO22_MASK                      0x1u
#define PIIX4_GPOREG_GPO22_INPLACE (PIIX4_GPOREG_GPO22_MASK << PIIX4_GPOREG_GPO22_SHIFT)
#define PIIX4_GPOREG_GPO21_SHIFT                     21 /* established */
#define PIIX4_GPOREG_GPO21_MASK                      0x1u
#define PIIX4_GPOREG_GPO21_INPLACE (PIIX4_GPOREG_GPO21_MASK << PIIX4_GPOREG_GPO21_SHIFT)
#define PIIX4_GPOREG_GPO20_SHIFT                     20 /* established */
#define PIIX4_GPOREG_GPO20_MASK                      0x1u
#define PIIX4_GPOREG_GPO20_INPLACE (PIIX4_GPOREG_GPO20_MASK << PIIX4_GPOREG_GPO20_SHIFT)
#define PIIX4_GPOREG_GPO19_SHIFT                     19 /* established */
#define PIIX4_GPOREG_GPO19_MASK                      0x1u
#define PIIX4_GPOREG_GPO19_INPLACE (PIIX4_GPOREG_GPO19_MASK << PIIX4_GPOREG_GPO19_SHIFT)
#define PIIX4_GPOREG_GPO18_SHIFT                     18 /* established */
#define PIIX4_GPOREG_GPO18_MASK                      0x1u
#define PIIX4_GPOREG_GPO18_INPLACE (PIIX4_GPOREG_GPO18_MASK << PIIX4_GPOREG_GPO18_SHIFT)
#define PIIX4_GPOREG_GPO17_SHIFT                     17 /* established */
#define PIIX4_GPOREG_GPO17_MASK                      0x1u
#define PIIX4_GPOREG_GPO17_INPLACE (PIIX4_GPOREG_GPO17_MASK << PIIX4_GPOREG_GPO17_SHIFT)
#define PIIX4_GPOREG_GPO16_SHIFT                     16 /* established */
#define PIIX4_GPOREG_GPO16_MASK                      0x1u
#define PIIX4_GPOREG_GPO16_INPLACE (PIIX4_GPOREG_GPO16_MASK << PIIX4_GPOREG_GPO16_SHIFT)
#define PIIX4_GPOREG_GPO15_SHIFT                     15 /* established */
#define PIIX4_GPOREG_GPO15_MASK                      0x1u
#define PIIX4_GPOREG_GPO15_INPLACE (PIIX4_GPOREG_GPO15_MASK << PIIX4_GPOREG_GPO15_SHIFT)
#define PIIX4_GPOREG_GPO14_SHIFT                     14 /* established */
#define PIIX4_GPOREG_GPO14_MASK                      0x1u
#define PIIX4_GPOREG_GPO14_INPLACE (PIIX4_GPOREG_GPO14_MASK << PIIX4_GPOREG_GPO14_SHIFT)
#define PIIX4_GPOREG_GPO13_SHIFT                     13 /* established */
#define PIIX4_GPOREG_GPO13_MASK                      0x1u
#define PIIX4_GPOREG_GPO13_INPLACE (PIIX4_GPOREG_GPO13_MASK << PIIX4_GPOREG_GPO13_SHIFT)
#define PIIX4_GPOREG_GPO12_SHIFT                     12 /* established */
#define PIIX4_GPOREG_GPO12_MASK                      0x1u
#define PIIX4_GPOREG_GPO12_INPLACE (PIIX4_GPOREG_GPO12_MASK << PIIX4_GPOREG_GPO12_SHIFT)
#define PIIX4_GPOREG_GPO11_SHIFT                     11 /* established */
#define PIIX4_GPOREG_GPO11_MASK                      0x1u
#define PIIX4_GPOREG_GPO11_INPLACE (PIIX4_GPOREG_GPO11_MASK << PIIX4_GPOREG_GPO11_SHIFT)
#define PIIX4_GPOREG_GPO10_SHIFT                     10 /* established */
#define PIIX4_GPOREG_GPO10_MASK                      0x1u
#define PIIX4_GPOREG_GPO10_INPLACE (PIIX4_GPOREG_GPO10_MASK << PIIX4_GPOREG_GPO10_SHIFT)
#define PIIX4_GPOREG_GPO9_SHIFT                      9 /* established */
#define PIIX4_GPOREG_GPO9_MASK                       0x1u
#define PIIX4_GPOREG_GPO9_INPLACE (PIIX4_GPOREG_GPO9_MASK << PIIX4_GPOREG_GPO9_SHIFT)
#define PIIX4_GPOREG_GPO8_SHIFT                      8 /* established */
#define PIIX4_GPOREG_GPO8_MASK                       0x1u
#define PIIX4_GPOREG_GPO8_INPLACE (PIIX4_GPOREG_GPO8_MASK << PIIX4_GPOREG_GPO8_SHIFT)
#define PIIX4_GPOREG_GPO7_SHIFT                      7 /* established */
#define PIIX4_GPOREG_GPO7_MASK                       0x1u
#define PIIX4_GPOREG_GPO7_INPLACE (PIIX4_GPOREG_GPO7_MASK << PIIX4_GPOREG_GPO7_SHIFT)
#define PIIX4_GPOREG_GPO6_SHIFT                      6 /* established */
#define PIIX4_GPOREG_GPO6_MASK                       0x1u
#define PIIX4_GPOREG_GPO6_INPLACE (PIIX4_GPOREG_GPO6_MASK << PIIX4_GPOREG_GPO6_SHIFT)
#define PIIX4_GPOREG_GPO5_SHIFT                      5 /* established */
#define PIIX4_GPOREG_GPO5_MASK                       0x1u
#define PIIX4_GPOREG_GPO5_INPLACE (PIIX4_GPOREG_GPO5_MASK << PIIX4_GPOREG_GPO5_SHIFT)
#define PIIX4_GPOREG_GPO4_SHIFT                      4 /* established */
#define PIIX4_GPOREG_GPO4_MASK                       0x1u
#define PIIX4_GPOREG_GPO4_INPLACE (PIIX4_GPOREG_GPO4_MASK << PIIX4_GPOREG_GPO4_SHIFT)
#define PIIX4_GPOREG_GPO3_SHIFT                      3 /* established */
#define PIIX4_GPOREG_GPO3_MASK                       0x1u
#define PIIX4_GPOREG_GPO3_INPLACE (PIIX4_GPOREG_GPO3_MASK << PIIX4_GPOREG_GPO3_SHIFT)
#define PIIX4_GPOREG_GPO2_SHIFT                      2 /* established */
#define PIIX4_GPOREG_GPO2_MASK                       0x1u
#define PIIX4_GPOREG_GPO2_INPLACE (PIIX4_GPOREG_GPO2_MASK << PIIX4_GPOREG_GPO2_SHIFT)
#define PIIX4_GPOREG_GPO1_SHIFT                      1 /* established */
#define PIIX4_GPOREG_GPO1_MASK                       0x1u
#define PIIX4_GPOREG_GPO1_INPLACE (PIIX4_GPOREG_GPO1_MASK << PIIX4_GPOREG_GPO1_SHIFT)
#define PIIX4_GPOREG_GPO0_SHIFT                      0 /* established */
#define PIIX4_GPOREG_GPO0_MASK                       0x1u
#define PIIX4_GPOREG_GPO0_INPLACE (PIIX4_GPOREG_GPO0_MASK << PIIX4_GPOREG_GPO0_SHIFT)

/*
 * SMBus host status: failed, bus collision, device error, interrupt (all write
 * 1 to clear) and host busy. The PROM clears it by writing before its one
 * transaction.
 */
/* smbhststs: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.148-149 */
#define PIIX4_SMBHSTSTS_OFFSET                       0x0u /* established */
#define PIIX4_SMBHSTSTS_FAILED_SHIFT                 4 /* established */
#define PIIX4_SMBHSTSTS_FAILED_MASK                  0x1u
#define PIIX4_SMBHSTSTS_FAILED_INPLACE (PIIX4_SMBHSTSTS_FAILED_MASK << PIIX4_SMBHSTSTS_FAILED_SHIFT)
#define PIIX4_SMBHSTSTS_BUS_ERR_SHIFT                3 /* established */
#define PIIX4_SMBHSTSTS_BUS_ERR_MASK                 0x1u
#define PIIX4_SMBHSTSTS_BUS_ERR_INPLACE (PIIX4_SMBHSTSTS_BUS_ERR_MASK << PIIX4_SMBHSTSTS_BUS_ERR_SHIFT)
#define PIIX4_SMBHSTSTS_DEV_ERR_SHIFT                2 /* established */
#define PIIX4_SMBHSTSTS_DEV_ERR_MASK                 0x1u
#define PIIX4_SMBHSTSTS_DEV_ERR_INPLACE (PIIX4_SMBHSTSTS_DEV_ERR_MASK << PIIX4_SMBHSTSTS_DEV_ERR_SHIFT)
#define PIIX4_SMBHSTSTS_INTER_SHIFT                  1 /* established */
#define PIIX4_SMBHSTSTS_INTER_MASK                   0x1u
#define PIIX4_SMBHSTSTS_INTER_INPLACE (PIIX4_SMBHSTSTS_INTER_MASK << PIIX4_SMBHSTSTS_INTER_SHIFT)
#define PIIX4_SMBHSTSTS_HOST_BUSY_SHIFT              0 /* established */
#define PIIX4_SMBHSTSTS_HOST_BUSY_MASK               0x1u
#define PIIX4_SMBHSTSTS_HOST_BUSY_INPLACE (PIIX4_SMBHSTSTS_HOST_BUSY_MASK << PIIX4_SMBHSTSTS_HOST_BUSY_SHIFT)

/*
 * SMBus slave status.
 */
/* smbslvsts: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.149 */
#define PIIX4_SMBSLVSTS_OFFSET                       0x1u /* established */

/*
 * SMBus host control. The PROM's single transaction writes 0x54 (start, block
 * protocol); reading the register resets the block data index.
 */
/* smbhstcnt: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.150 */
#define PIIX4_SMBHSTCNT_OFFSET                       0x2u /* established */
#define PIIX4_SMBHSTCNT_START_SHIFT                  6 /* established */
#define PIIX4_SMBHSTCNT_START_MASK                   0x1u
#define PIIX4_SMBHSTCNT_START_INPLACE (PIIX4_SMBHSTCNT_START_MASK << PIIX4_SMBHSTCNT_START_SHIFT)
#define PIIX4_SMBHSTCNT_CMD_PROT_SHIFT               2 /* established */
#define PIIX4_SMBHSTCNT_CMD_PROT_MASK                0x7u
#define PIIX4_SMBHSTCNT_CMD_PROT_INPLACE (PIIX4_SMBHSTCNT_CMD_PROT_MASK << PIIX4_SMBHSTCNT_CMD_PROT_SHIFT)
#define PIIX4_SMBHSTCNT_CMD_PROT_QUICK               0 /* established */
#define PIIX4_SMBHSTCNT_CMD_PROT_BYTE                1 /* established */
#define PIIX4_SMBHSTCNT_CMD_PROT_BYTE_DATA           2 /* established */
#define PIIX4_SMBHSTCNT_CMD_PROT_WORD_DATA           3 /* established */
#define PIIX4_SMBHSTCNT_CMD_PROT_BLOCK               5 /* established */
#define PIIX4_SMBHSTCNT_KILL_SHIFT                   1 /* established */
#define PIIX4_SMBHSTCNT_KILL_MASK                    0x1u
#define PIIX4_SMBHSTCNT_KILL_INPLACE (PIIX4_SMBHSTCNT_KILL_MASK << PIIX4_SMBHSTCNT_KILL_SHIFT)
#define PIIX4_SMBHSTCNT_INTEREN_SHIFT                0 /* established */
#define PIIX4_SMBHSTCNT_INTEREN_MASK                 0x1u
#define PIIX4_SMBHSTCNT_INTEREN_INPLACE (PIIX4_SMBHSTCNT_INTEREN_MASK << PIIX4_SMBHSTCNT_INTEREN_SHIFT)

/*
 * SMBus host command field.
 */
/* smbhstcmd: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.150 */
#define PIIX4_SMBHSTCMD_OFFSET                       0x3u /* established */

/*
 * SMBus host address: bits 7:1 slave address, bit 0 read (1) or write (0).
 */
/* smbhstadd: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.151 */
#define PIIX4_SMBHSTADD_OFFSET                       0x4u /* established */

/*
 * SMBus host data 0 (byte count for block transfers).
 */
/* smbhstdat0: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.151 */
#define PIIX4_SMBHSTDAT0_OFFSET                      0x5u /* established */

/*
 * SMBus host data 1.
 */
/* smbhstdat1: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.151 */
#define PIIX4_SMBHSTDAT1_OFFSET                      0x6u /* established */

/*
 * SMBus block data port.
 */
/* smbblkdat: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.152 */
#define PIIX4_SMBBLKDAT_OFFSET                       0x7u /* established */

/*
 * SMBus slave control.
 */
/* smbslvcnt: rw8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.152 */
#define PIIX4_SMBSLVCNT_OFFSET                       0x8u /* established */
#define PIIX4_SMBSLVCNT_ALERT_EN_SHIFT               3 /* established */
#define PIIX4_SMBSLVCNT_ALERT_EN_MASK                0x1u
#define PIIX4_SMBSLVCNT_ALERT_EN_INPLACE (PIIX4_SMBSLVCNT_ALERT_EN_MASK << PIIX4_SMBSLVCNT_ALERT_EN_SHIFT)
#define PIIX4_SMBSLVCNT_SHDW2_EN_SHIFT               2 /* established */
#define PIIX4_SMBSLVCNT_SHDW2_EN_MASK                0x1u
#define PIIX4_SMBSLVCNT_SHDW2_EN_INPLACE (PIIX4_SMBSLVCNT_SHDW2_EN_MASK << PIIX4_SMBSLVCNT_SHDW2_EN_SHIFT)
#define PIIX4_SMBSLVCNT_SHDW1_EN_SHIFT               1 /* established */
#define PIIX4_SMBSLVCNT_SHDW1_EN_MASK                0x1u
#define PIIX4_SMBSLVCNT_SHDW1_EN_INPLACE (PIIX4_SMBSLVCNT_SHDW1_EN_MASK << PIIX4_SMBSLVCNT_SHDW1_EN_SHIFT)
#define PIIX4_SMBSLVCNT_SLV_EN_SHIFT                 0 /* established */
#define PIIX4_SMBSLVCNT_SLV_EN_MASK                  0x1u
#define PIIX4_SMBSLVCNT_SLV_EN_INPLACE (PIIX4_SMBSLVCNT_SLV_EN_MASK << PIIX4_SMBSLVCNT_SLV_EN_SHIFT)

/*
 * SMBus shadow command: command received by an external master access to the
 * slave or shadow ports.
 */
/* smbshdwcmd: r8, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.153 */
#define PIIX4_SMBSHDWCMD_OFFSET                      0x9u /* established */

/*
 * SMBus slave event: data bits compared with incoming slave data.
 */
/* smbslvevt: rw16, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.153 */
#define PIIX4_SMBSLVEVT_OFFSET                       0xau /* established */

/*
 * SMBus slave data: data received by an external master access to the slave or
 * shadow ports.
 */
/* smbslvdat: r16, space piix4_smb, reset 0x0; Intel 82371AB datasheet
 * 290562-001 (April 1997) p.153 */
#define PIIX4_SMBSLVDAT_OFFSET                       0xcu /* established */

#define PIIX4_BOARD_ID_SHIFT                         0x2u /* inferred */
/* established */
#define PIIX4_IDETIM_PROM_VALUE                      0xc077c077u
#define PIIX4_PM_BASE                                0xf80u /* established */
#define PIIX4_RC_PORT                                0xcf9u /* established */
#define PIIX4_SMB_BASE                               0xfd0u /* established */

#endif /* PIIX4_GEN_H */
