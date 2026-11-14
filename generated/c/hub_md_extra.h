/* generated from devices/hub_md/registers-extra.toml by defs-gen - do not edit, change the source */
/* Hub memory and directory register layouts and constants outside the census */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/*
 * Memory DIMM mode initialisation. Layout in the MD_DIMM_INIT_FORMAT word. The header gives no access type, so rw is assumed.
 */
/* md_mem_dimm_init: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_MEM_DIMM_INIT (offset and name) */
#define HUB_MD_MEM_DIMM_INIT_OFFSET                  0x200090u /* inferred */

/*
 * Directory DIMM mode initialisation. Same layout as the memory register. The header gives no access type, so rw is assumed.
 */
/* md_dir_dimm_init: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_DIR_DIMM_INIT (offset and name) */
#define HUB_MD_DIR_DIMM_INIT_OFFSET                  0x200098u /* inferred */

/*
 * Eight-bit LED of the second processor, the twin of md_led0 in the census. The header gives no access type; write-only is carried over from md_led0 and is inferred.
 */
/* md_led1: w64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_LED1 (offset, name and the description eight-bit LED for the second processor) */
#define HUB_MD_LED1_OFFSET                           0x220058u /* inferred */

/*
 * Microcontroller and UART 1 register 1 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_1: rw64, reset 0x0; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_1 (offset and name) */
#define HUB_MD_UREG1_1_OFFSET                        0x220088u /* inferred */

/*
 * Microcontroller and UART 1 register 2 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_2: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_2 (offset and name) */
#define HUB_MD_UREG1_2_OFFSET                        0x220090u /* inferred */

/*
 * Microcontroller and UART 1 register 3 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_3: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_3 (offset and name) */
#define HUB_MD_UREG1_3_OFFSET                        0x220098u /* inferred */

/*
 * Microcontroller and UART 1 register 4 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_4: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_4 (offset and name) */
#define HUB_MD_UREG1_4_OFFSET                        0x2200a0u /* inferred */

/*
 * Microcontroller and UART 1 register 5 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_5: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_5 (offset and name) */
#define HUB_MD_UREG1_5_OFFSET                        0x2200a8u /* inferred */

/*
 * Microcontroller and UART 1 register 6 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_6: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_6 (offset and name) */
#define HUB_MD_UREG1_6_OFFSET                        0x2200b0u /* inferred */

/*
 * Microcontroller and UART 1 register 7 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_7: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_7 (offset and name) */
#define HUB_MD_UREG1_7_OFFSET                        0x2200b8u /* inferred */

/*
 * Microcontroller and UART 1 register 8 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_8: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_8 (offset and name) */
#define HUB_MD_UREG1_8_OFFSET                        0x2200c0u /* inferred */

/*
 * Microcontroller and UART 1 register 9 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_9: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_9 (offset and name) */
#define HUB_MD_UREG1_9_OFFSET                        0x2200c8u /* inferred */

/*
 * Microcontroller and UART 1 register 10 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_10: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_10 (offset and name) */
#define HUB_MD_UREG1_10_OFFSET                       0x2200d0u /* inferred */

/*
 * Microcontroller and UART 1 register 11 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_11: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_11 (offset and name) */
#define HUB_MD_UREG1_11_OFFSET                       0x2200d8u /* inferred */

/*
 * Microcontroller and UART 1 register 12 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_12: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_12 (offset and name) */
#define HUB_MD_UREG1_12_OFFSET                       0x2200e0u /* inferred */

/*
 * Microcontroller and UART 1 register 13 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_13: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_13 (offset and name) */
#define HUB_MD_UREG1_13_OFFSET                       0x2200e8u /* inferred */

/*
 * Microcontroller and UART 1 register 14 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_14: rw64, reset unknown; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_14 (offset and name) */
#define HUB_MD_UREG1_14_OFFSET                       0x2200f0u /* inferred */

/*
 * Microcontroller and UART 1 register 15 of 16; the census has register 0. The header gives no access type, so rw is assumed.
 */
/* md_ureg1_15: rw64, reset 0x0; public Linux SN0 Hub memory/directory header, pinned linux tree: MD_UREG1_15 (offset and name) */
#define HUB_MD_UREG1_15_OFFSET                       0x2200f8u /* inferred */

/*
 * Layout of the memory and directory DIMM mode initialisation registers. Both registers share this layout.
 */
/* word MD_DIMM_INIT_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MDI_* masks */
#define HUB_MD_DIMM_INIT_FORMAT_WIDTH                64 /* established */
#define HUB_MD_DIMM_INIT_FORMAT_SELECT_SHIFT         32 /* established */
#define HUB_MD_DIMM_INIT_FORMAT_SELECT_MASK          0xfull
#define HUB_MD_DIMM_INIT_FORMAT_SELECT_INPLACE       (HUB_MD_DIMM_INIT_FORMAT_SELECT_MASK << HUB_MD_DIMM_INIT_FORMAT_SELECT_SHIFT)
#define HUB_MD_DIMM_INIT_FORMAT_MODE_SHIFT           0 /* established */
#define HUB_MD_DIMM_INIT_FORMAT_MODE_MASK            0xfffull
#define HUB_MD_DIMM_INIT_FORMAT_MODE_INPLACE         (HUB_MD_DIMM_INIT_FORMAT_MODE_MASK << HUB_MD_DIMM_INIT_FORMAT_MODE_SHIFT)

/*
 * Layout of the directory error latch, from the header's structure. The header lists the fields from the most significant bit down and gives a comment for each range. Bit positions here follow those comments.
 */
/* word MD_DIR_ERROR_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: dir_error_reg structure */
#define HUB_MD_DIR_ERROR_FORMAT_WIDTH                64 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_UCE_VLD_SHIFT        63 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_UCE_VLD_MASK         0x1ull
#define HUB_MD_DIR_ERROR_FORMAT_UCE_VLD_INPLACE      (HUB_MD_DIR_ERROR_FORMAT_UCE_VLD_MASK << HUB_MD_DIR_ERROR_FORMAT_UCE_VLD_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_AE_VLD_SHIFT         62 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_AE_VLD_MASK          0x1ull
#define HUB_MD_DIR_ERROR_FORMAT_AE_VLD_INPLACE       (HUB_MD_DIR_ERROR_FORMAT_AE_VLD_MASK << HUB_MD_DIR_ERROR_FORMAT_AE_VLD_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_CE_VLD_SHIFT         61 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_CE_VLD_MASK          0x1ull
#define HUB_MD_DIR_ERROR_FORMAT_CE_VLD_INPLACE       (HUB_MD_DIR_ERROR_FORMAT_CE_VLD_MASK << HUB_MD_DIR_ERROR_FORMAT_CE_VLD_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_BAD_PROT_SHIFT       39 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_BAD_PROT_MASK        0x7ull
#define HUB_MD_DIR_ERROR_FORMAT_BAD_PROT_INPLACE     (HUB_MD_DIR_ERROR_FORMAT_BAD_PROT_MASK << HUB_MD_DIR_ERROR_FORMAT_BAD_PROT_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_BAD_SYN_SHIFT        32 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_BAD_SYN_MASK         0x7full
#define HUB_MD_DIR_ERROR_FORMAT_BAD_SYN_INPLACE      (HUB_MD_DIR_ERROR_FORMAT_BAD_SYN_MASK << HUB_MD_DIR_ERROR_FORMAT_BAD_SYN_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_HSPEC_ADDR_SHIFT     3 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_HSPEC_ADDR_MASK      0x7ffffffull
#define HUB_MD_DIR_ERROR_FORMAT_HSPEC_ADDR_INPLACE   (HUB_MD_DIR_ERROR_FORMAT_HSPEC_ADDR_MASK << HUB_MD_DIR_ERROR_FORMAT_HSPEC_ADDR_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_UCE_OVR_SHIFT        2 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_UCE_OVR_MASK         0x1ull
#define HUB_MD_DIR_ERROR_FORMAT_UCE_OVR_INPLACE      (HUB_MD_DIR_ERROR_FORMAT_UCE_OVR_MASK << HUB_MD_DIR_ERROR_FORMAT_UCE_OVR_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_AE_OVR_SHIFT         1 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_AE_OVR_MASK          0x1ull
#define HUB_MD_DIR_ERROR_FORMAT_AE_OVR_INPLACE       (HUB_MD_DIR_ERROR_FORMAT_AE_OVR_MASK << HUB_MD_DIR_ERROR_FORMAT_AE_OVR_SHIFT)
#define HUB_MD_DIR_ERROR_FORMAT_CE_OVR_SHIFT         0 /* established */
#define HUB_MD_DIR_ERROR_FORMAT_CE_OVR_MASK          0x1ull
#define HUB_MD_DIR_ERROR_FORMAT_CE_OVR_INPLACE       (HUB_MD_DIR_ERROR_FORMAT_CE_OVR_MASK << HUB_MD_DIR_ERROR_FORMAT_CE_OVR_SHIFT)

/*
 * Layout of the memory configuration register. Bank descriptors take bits 23:0, three bits each. The timing fields and the bank-size codes are named by the header, and their meaning is only partly stated there.
 */
/* word MD_MEMORY_CONFIG_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) */
#define HUB_MD_MEMORY_CONFIG_FORMAT_WIDTH            64 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_CYC_SHIFT  49 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_CYC_MASK   0x1full
#define HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_CYC_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_CYC_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_CYC_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_WR_SHIFT   44 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_WR_MASK    0x1full
#define HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_WR_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_WR_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_FPROM_WR_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_CYC_SHIFT  39 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_CYC_MASK   0x1full
#define HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_CYC_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_CYC_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_CYC_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_WR_SHIFT   34 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_WR_MASK    0x1full
#define HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_WR_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_WR_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_UCTLR_WR_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_DIMM0_SEL_SHIFT  32 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_DIMM0_SEL_MASK   0x3ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_DIMM0_SEL_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_DIMM0_SEL_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_DIMM0_SEL_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_IO_PROT_EN_SHIFT 31 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_IO_PROT_EN_MASK  0x1ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_IO_PROT_EN_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_IO_PROT_EN_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_IO_PROT_EN_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_ARB_MLSS_SHIFT   30 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_ARB_MLSS_MASK    0x1ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_ARB_MLSS_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_ARB_MLSS_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_ARB_MLSS_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_IGNORE_ECC_SHIFT 29 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_IGNORE_ECC_MASK  0x1ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_IGNORE_ECC_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_IGNORE_ECC_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_IGNORE_ECC_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_DIR_PREMIUM_SHIFT 28 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_DIR_PREMIUM_MASK 0x1ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_DIR_PREMIUM_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_DIR_PREMIUM_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_DIR_PREMIUM_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_REPLY_GUAR_SHIFT 24 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_REPLY_GUAR_MASK  0xfull
#define HUB_MD_MEMORY_CONFIG_FORMAT_REPLY_GUAR_INPLACE (HUB_MD_MEMORY_CONFIG_FORMAT_REPLY_GUAR_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_REPLY_GUAR_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK7_SHIFT      21 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK7_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK7_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK7_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK7_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK6_SHIFT      18 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK6_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK6_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK6_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK6_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK5_SHIFT      15 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK5_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK5_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK5_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK5_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK4_SHIFT      12 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK4_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK4_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK4_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK4_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK3_SHIFT      9 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK3_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK3_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK3_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK3_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK2_SHIFT      6 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK2_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK2_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK2_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK2_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK1_SHIFT      3 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK1_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK1_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK1_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK1_SHIFT)
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK0_SHIFT      0 /* established */
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK0_MASK       0x7ull
#define HUB_MD_MEMORY_CONFIG_FORMAT_BANK0_INPLACE    (HUB_MD_MEMORY_CONFIG_FORMAT_BANK0_MASK << HUB_MD_MEMORY_CONFIG_FORMAT_BANK0_SHIFT)

/*
 * Layout of the memory error latch, from the header's structure.
 */
/* word MD_MEM_ERROR_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: mem_error_reg structure */
#define HUB_MD_MEM_ERROR_FORMAT_WIDTH                64 /* established */
#define HUB_MD_MEM_ERROR_FORMAT_UCE_VLD_SHIFT        63 /* established */
#define HUB_MD_MEM_ERROR_FORMAT_UCE_VLD_MASK         0x1ull
#define HUB_MD_MEM_ERROR_FORMAT_UCE_VLD_INPLACE      (HUB_MD_MEM_ERROR_FORMAT_UCE_VLD_MASK << HUB_MD_MEM_ERROR_FORMAT_UCE_VLD_SHIFT)
#define HUB_MD_MEM_ERROR_FORMAT_CE_VLD_SHIFT         62 /* established */
#define HUB_MD_MEM_ERROR_FORMAT_CE_VLD_MASK          0x1ull
#define HUB_MD_MEM_ERROR_FORMAT_CE_VLD_INPLACE       (HUB_MD_MEM_ERROR_FORMAT_CE_VLD_MASK << HUB_MD_MEM_ERROR_FORMAT_CE_VLD_SHIFT)
#define HUB_MD_MEM_ERROR_FORMAT_BAD_SYN_SHIFT        32 /* established */
#define HUB_MD_MEM_ERROR_FORMAT_BAD_SYN_MASK         0xffull
#define HUB_MD_MEM_ERROR_FORMAT_BAD_SYN_INPLACE      (HUB_MD_MEM_ERROR_FORMAT_BAD_SYN_MASK << HUB_MD_MEM_ERROR_FORMAT_BAD_SYN_SHIFT)
#define HUB_MD_MEM_ERROR_FORMAT_ADDRESS_SHIFT        3 /* established */
#define HUB_MD_MEM_ERROR_FORMAT_ADDRESS_MASK         0x1fffffffull
#define HUB_MD_MEM_ERROR_FORMAT_ADDRESS_INPLACE      (HUB_MD_MEM_ERROR_FORMAT_ADDRESS_MASK << HUB_MD_MEM_ERROR_FORMAT_ADDRESS_SHIFT)
#define HUB_MD_MEM_ERROR_FORMAT_UCE_OVR_SHIFT        1 /* established */
#define HUB_MD_MEM_ERROR_FORMAT_UCE_OVR_MASK         0x1ull
#define HUB_MD_MEM_ERROR_FORMAT_UCE_OVR_INPLACE      (HUB_MD_MEM_ERROR_FORMAT_UCE_OVR_MASK << HUB_MD_MEM_ERROR_FORMAT_UCE_OVR_SHIFT)
#define HUB_MD_MEM_ERROR_FORMAT_CE_OVR_SHIFT         0 /* established */
#define HUB_MD_MEM_ERROR_FORMAT_CE_OVR_MASK          0x1ull
#define HUB_MD_MEM_ERROR_FORMAT_CE_OVR_INPLACE       (HUB_MD_MEM_ERROR_FORMAT_CE_OVR_MASK << HUB_MD_MEM_ERROR_FORMAT_CE_OVR_SHIFT)

/*
 * Layout of the page migration candidate. The header's initiator and node-number masks overlap at bits 28:20, so only the single-bit fields are imported here. The shipped IRIX kernel reads only the read-to-clear alias (md_mig_candidate_clr), in a loop until the valid bit is clear, and takes the node and page fields below from it. That a read consumes the candidate is inferred from the register name and the loop. Nothing in the kernel accesses the candidate register itself, which sits one doubleword below the alias.
 */
/* word MD_MIG_CANDIDATE_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MD_MIG_CANDIDATE masks */
#define HUB_MD_MIG_CANDIDATE_FORMAT_WIDTH            64 /* established */
#define HUB_MD_MIG_CANDIDATE_FORMAT_VALID_SHIFT      63 /* established */
#define HUB_MD_MIG_CANDIDATE_FORMAT_VALID_MASK       0x1ull
#define HUB_MD_MIG_CANDIDATE_FORMAT_VALID_INPLACE    (HUB_MD_MIG_CANDIDATE_FORMAT_VALID_MASK << HUB_MD_MIG_CANDIDATE_FORMAT_VALID_SHIFT)
#define HUB_MD_MIG_CANDIDATE_FORMAT_TYPE_SHIFT       30 /* established */
#define HUB_MD_MIG_CANDIDATE_FORMAT_TYPE_MASK        0x1ull
#define HUB_MD_MIG_CANDIDATE_FORMAT_TYPE_INPLACE     (HUB_MD_MIG_CANDIDATE_FORMAT_TYPE_MASK << HUB_MD_MIG_CANDIDATE_FORMAT_TYPE_SHIFT)
#define HUB_MD_MIG_CANDIDATE_FORMAT_OVERRUN_SHIFT    29 /* established */
#define HUB_MD_MIG_CANDIDATE_FORMAT_OVERRUN_MASK     0x1ull
#define HUB_MD_MIG_CANDIDATE_FORMAT_OVERRUN_INPLACE  (HUB_MD_MIG_CANDIDATE_FORMAT_OVERRUN_MASK << HUB_MD_MIG_CANDIDATE_FORMAT_OVERRUN_SHIFT)
#define HUB_MD_MIG_CANDIDATE_FORMAT_NODE_SHIFT       20 /* inferred */
#define HUB_MD_MIG_CANDIDATE_FORMAT_NODE_MASK        0x1ffull
#define HUB_MD_MIG_CANDIDATE_FORMAT_NODE_INPLACE     (HUB_MD_MIG_CANDIDATE_FORMAT_NODE_MASK << HUB_MD_MIG_CANDIDATE_FORMAT_NODE_SHIFT)
#define HUB_MD_MIG_CANDIDATE_FORMAT_PAGE_SHIFT       0 /* inferred */
#define HUB_MD_MIG_CANDIDATE_FORMAT_PAGE_MASK        0x3ffffull
#define HUB_MD_MIG_CANDIDATE_FORMAT_PAGE_INPLACE     (HUB_MD_MIG_CANDIDATE_FORMAT_PAGE_MASK << HUB_MD_MIG_CANDIDATE_FORMAT_PAGE_SHIFT)

/*
 * Layout of the page migration difference and value thresholds. The two registers share this layout. The shipped IRIX kernel arms a threshold by setting the valid bit (bit 63) and clears the bit to disarm it while a candidate is handled.
 */
/* word MD_MIG_THRESH_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MD_MIG_DIFF_THRES and MD_MIG_VALUE_THRES masks */
#define HUB_MD_MIG_THRESH_FORMAT_WIDTH               64 /* established */
#define HUB_MD_MIG_THRESH_FORMAT_VALID_SHIFT         63 /* established */
#define HUB_MD_MIG_THRESH_FORMAT_VALID_MASK          0x1ull
#define HUB_MD_MIG_THRESH_FORMAT_VALID_INPLACE       (HUB_MD_MIG_THRESH_FORMAT_VALID_MASK << HUB_MD_MIG_THRESH_FORMAT_VALID_SHIFT)
#define HUB_MD_MIG_THRESH_FORMAT_VALUE_SHIFT         0 /* established */
#define HUB_MD_MIG_THRESH_FORMAT_VALUE_MASK          0xfffffull
#define HUB_MD_MIG_THRESH_FORMAT_VALUE_INPLACE       (HUB_MD_MIG_THRESH_FORMAT_VALUE_MASK << HUB_MD_MIG_THRESH_FORMAT_VALUE_SHIFT)

/*
 * Layout of the miscellaneous error latch. The header's valid mask covers bits 9:0. Its long-pack mask is written with a misspelt shift macro, so only the other masks are imported as stated.
 */
/* word MD_MISC_ERROR_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MMCE_* masks */
#define HUB_MD_MISC_ERROR_FORMAT_WIDTH               64 /* established */
#define HUB_MD_MISC_ERROR_FORMAT_ILL_MSG_SHIFT       8 /* established */
#define HUB_MD_MISC_ERROR_FORMAT_ILL_MSG_MASK        0x3ull
#define HUB_MD_MISC_ERROR_FORMAT_ILL_MSG_INPLACE     (HUB_MD_MISC_ERROR_FORMAT_ILL_MSG_MASK << HUB_MD_MISC_ERROR_FORMAT_ILL_MSG_SHIFT)
#define HUB_MD_MISC_ERROR_FORMAT_ILL_REV_SHIFT       6 /* established */
#define HUB_MD_MISC_ERROR_FORMAT_ILL_REV_MASK        0x3ull
#define HUB_MD_MISC_ERROR_FORMAT_ILL_REV_INPLACE     (HUB_MD_MISC_ERROR_FORMAT_ILL_REV_MASK << HUB_MD_MISC_ERROR_FORMAT_ILL_REV_SHIFT)
#define HUB_MD_MISC_ERROR_FORMAT_LONG_PACK_SHIFT     4 /* established */
#define HUB_MD_MISC_ERROR_FORMAT_LONG_PACK_MASK      0x3ull
#define HUB_MD_MISC_ERROR_FORMAT_LONG_PACK_INPLACE   (HUB_MD_MISC_ERROR_FORMAT_LONG_PACK_MASK << HUB_MD_MISC_ERROR_FORMAT_LONG_PACK_SHIFT)
#define HUB_MD_MISC_ERROR_FORMAT_SHORT_PACK_SHIFT    2 /* established */
#define HUB_MD_MISC_ERROR_FORMAT_SHORT_PACK_MASK     0x3ull
#define HUB_MD_MISC_ERROR_FORMAT_SHORT_PACK_INPLACE  (HUB_MD_MISC_ERROR_FORMAT_SHORT_PACK_MASK << HUB_MD_MISC_ERROR_FORMAT_SHORT_PACK_SHIFT)
#define HUB_MD_MISC_ERROR_FORMAT_BAD_DATA_SHIFT      0 /* established */
#define HUB_MD_MISC_ERROR_FORMAT_BAD_DATA_MASK       0x3ull
#define HUB_MD_MISC_ERROR_FORMAT_BAD_DATA_INPLACE    (HUB_MD_MISC_ERROR_FORMAT_BAD_DATA_MASK << HUB_MD_MISC_ERROR_FORMAT_BAD_DATA_SHIFT)

/*
 * Layout of the one-wire (Microlan) control register.
 */
/* word MD_MLAN_CTL_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MD_MLAN_CTL fields (MLAN_*) */
#define HUB_MD_MLAN_CTL_FORMAT_WIDTH                 64 /* established */
#define HUB_MD_MLAN_CTL_FORMAT_PHI1_SHIFT            27 /* established */
#define HUB_MD_MLAN_CTL_FORMAT_PHI1_MASK             0x7full
#define HUB_MD_MLAN_CTL_FORMAT_PHI1_INPLACE          (HUB_MD_MLAN_CTL_FORMAT_PHI1_MASK << HUB_MD_MLAN_CTL_FORMAT_PHI1_SHIFT)
#define HUB_MD_MLAN_CTL_FORMAT_PHI0_SHIFT            20 /* inferred */
#define HUB_MD_MLAN_CTL_FORMAT_PHI0_MASK             0x7full
#define HUB_MD_MLAN_CTL_FORMAT_PHI0_INPLACE          (HUB_MD_MLAN_CTL_FORMAT_PHI0_MASK << HUB_MD_MLAN_CTL_FORMAT_PHI0_SHIFT)
#define HUB_MD_MLAN_CTL_FORMAT_PULSE_SHIFT           10 /* established */
#define HUB_MD_MLAN_CTL_FORMAT_PULSE_MASK            0x3ffull
#define HUB_MD_MLAN_CTL_FORMAT_PULSE_INPLACE         (HUB_MD_MLAN_CTL_FORMAT_PULSE_MASK << HUB_MD_MLAN_CTL_FORMAT_PULSE_SHIFT)
#define HUB_MD_MLAN_CTL_FORMAT_SAMPLE_SHIFT          2 /* established */
#define HUB_MD_MLAN_CTL_FORMAT_SAMPLE_MASK           0xffull
#define HUB_MD_MLAN_CTL_FORMAT_SAMPLE_INPLACE        (HUB_MD_MLAN_CTL_FORMAT_SAMPLE_MASK << HUB_MD_MLAN_CTL_FORMAT_SAMPLE_SHIFT)
#define HUB_MD_MLAN_CTL_FORMAT_DONE_SHIFT            1 /* established */
#define HUB_MD_MLAN_CTL_FORMAT_DONE_MASK             0x1ull
#define HUB_MD_MLAN_CTL_FORMAT_DONE_INPLACE          (HUB_MD_MLAN_CTL_FORMAT_DONE_MASK << HUB_MD_MLAN_CTL_FORMAT_DONE_SHIFT)
#define HUB_MD_MLAN_CTL_FORMAT_RD_DATA_SHIFT         0 /* established */
#define HUB_MD_MLAN_CTL_FORMAT_RD_DATA_MASK          0x1ull
#define HUB_MD_MLAN_CTL_FORMAT_RD_DATA_INPLACE       (HUB_MD_MLAN_CTL_FORMAT_RD_DATA_MASK << HUB_MD_MLAN_CTL_FORMAT_RD_DATA_SHIFT)

/*
 * Layout of the outgoing queue size register.
 */
/* word MD_MOQ_SIZE_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MD_MOQ_SIZE fields (MMS_*) */
#define HUB_MD_MOQ_SIZE_FORMAT_WIDTH                 64 /* established */
#define HUB_MD_MOQ_SIZE_FORMAT_RP_SIZE_SHIFT         8 /* established */
#define HUB_MD_MOQ_SIZE_FORMAT_RP_SIZE_MASK          0x3full
#define HUB_MD_MOQ_SIZE_FORMAT_RP_SIZE_INPLACE       (HUB_MD_MOQ_SIZE_FORMAT_RP_SIZE_MASK << HUB_MD_MOQ_SIZE_FORMAT_RP_SIZE_SHIFT)
#define HUB_MD_MOQ_SIZE_FORMAT_RQ_SIZE_SHIFT         0 /* established */
#define HUB_MD_MOQ_SIZE_FORMAT_RQ_SIZE_MASK          0x1full
#define HUB_MD_MOQ_SIZE_FORMAT_RQ_SIZE_INPLACE       (HUB_MD_MOQ_SIZE_FORMAT_RQ_SIZE_MASK << HUB_MD_MOQ_SIZE_FORMAT_RQ_SIZE_SHIFT)

/*
 * Layout of performance counters 0 to 5. Bit positions come from the header's structure, read in the same order as the select register and so inferred.
 */
/* word MD_PERF_CNT_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: md_perf_cnt_t structure */
#define HUB_MD_PERF_CNT_FORMAT_WIDTH                 64 /* inferred */
#define HUB_MD_PERF_CNT_FORMAT_PERF_CNT_SHIFT        0 /* inferred */
#define HUB_MD_PERF_CNT_FORMAT_PERF_CNT_MASK         0xfffffull
#define HUB_MD_PERF_CNT_FORMAT_PERF_CNT_INPLACE      (HUB_MD_PERF_CNT_FORMAT_PERF_CNT_MASK << HUB_MD_PERF_CNT_FORMAT_PERF_CNT_SHIFT)

/*
 * Layout of the performance counter select register. Bit positions come from the header's structure, which lists the fields from the most significant bit down. The order is taken as written there and is inferred.
 */
/* word MD_PERF_SEL_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: md_perf_sel_t structure */
#define HUB_MD_PERF_SEL_FORMAT_WIDTH                 64 /* inferred */
#define HUB_MD_PERF_SEL_FORMAT_PERF_EN_SHIFT         3 /* inferred */
#define HUB_MD_PERF_SEL_FORMAT_PERF_EN_MASK          0x1ull
#define HUB_MD_PERF_SEL_FORMAT_PERF_EN_INPLACE       (HUB_MD_PERF_SEL_FORMAT_PERF_EN_MASK << HUB_MD_PERF_SEL_FORMAT_PERF_EN_SHIFT)
#define HUB_MD_PERF_SEL_FORMAT_PERF_SEL_SHIFT        0 /* inferred */
#define HUB_MD_PERF_SEL_FORMAT_PERF_SEL_MASK         0x7ull
#define HUB_MD_PERF_SEL_FORMAT_PERF_SEL_INPLACE      (HUB_MD_PERF_SEL_FORMAT_PERF_SEL_MASK << HUB_MD_PERF_SEL_FORMAT_PERF_SEL_SHIFT)

/*
 * Layout of the protocol error latch, from the header's structure.
 */
/* word MD_PROTOCOL_ERROR_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: proto_error_reg structure */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_WIDTH           64 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_VALID_SHIFT     63 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_VALID_MASK      0x1ull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_VALID_INPLACE   (HUB_MD_PROTOCOL_ERROR_FORMAT_VALID_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_VALID_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_INITIATOR_SHIFT 50 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_INITIATOR_MASK  0x7ffull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_INITIATOR_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_INITIATOR_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_INITIATOR_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_BACKOFF_SHIFT   48 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_BACKOFF_MASK    0x3ull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_BACKOFF_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_BACKOFF_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_BACKOFF_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_MSG_TYPE_SHIFT  40 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_MSG_TYPE_MASK   0xffull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_MSG_TYPE_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_MSG_TYPE_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_MSG_TYPE_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_ACCESS_SHIFT    38 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_ACCESS_MASK     0x3ull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_ACCESS_INPLACE  (HUB_MD_PROTOCOL_ERROR_FORMAT_ACCESS_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_ACCESS_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_PRIORITY_SHIFT  37 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_PRIORITY_MASK   0x1ull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_PRIORITY_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_PRIORITY_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_PRIORITY_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_DIR_STATE_SHIFT 33 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_DIR_STATE_MASK  0xfull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_DIR_STATE_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_DIR_STATE_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_DIR_STATE_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_POINTER_ME_SHIFT 32 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_POINTER_ME_MASK 0x1ull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_POINTER_ME_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_POINTER_ME_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_POINTER_ME_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_ADDRESS_SHIFT   3 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_ADDRESS_MASK    0x1fffffffull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_ADDRESS_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_ADDRESS_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_ADDRESS_SHIFT)
#define HUB_MD_PROTOCOL_ERROR_FORMAT_OVERRUN_SHIFT   0 /* established */
#define HUB_MD_PROTOCOL_ERROR_FORMAT_OVERRUN_MASK    0x1ull
#define HUB_MD_PROTOCOL_ERROR_FORMAT_OVERRUN_INPLACE (HUB_MD_PROTOCOL_ERROR_FORMAT_OVERRUN_MASK << HUB_MD_PROTOCOL_ERROR_FORMAT_OVERRUN_SHIFT)

/*
 * Layout of the refresh control register.
 */
/* word MD_REFRESH_CONTROL_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MD_REFRESH_CONTROL fields (MRC_*) */
#define HUB_MD_REFRESH_CONTROL_FORMAT_WIDTH          64 /* established */
#define HUB_MD_REFRESH_CONTROL_FORMAT_ENABLE_SHIFT   63 /* established */
#define HUB_MD_REFRESH_CONTROL_FORMAT_ENABLE_MASK    0x1ull
#define HUB_MD_REFRESH_CONTROL_FORMAT_ENABLE_INPLACE (HUB_MD_REFRESH_CONTROL_FORMAT_ENABLE_MASK << HUB_MD_REFRESH_CONTROL_FORMAT_ENABLE_SHIFT)
#define HUB_MD_REFRESH_CONTROL_FORMAT_COUNTER_SHIFT  12 /* established */
#define HUB_MD_REFRESH_CONTROL_FORMAT_COUNTER_MASK   0xfffull
#define HUB_MD_REFRESH_CONTROL_FORMAT_COUNTER_INPLACE (HUB_MD_REFRESH_CONTROL_FORMAT_COUNTER_MASK << HUB_MD_REFRESH_CONTROL_FORMAT_COUNTER_SHIFT)
#define HUB_MD_REFRESH_CONTROL_FORMAT_THRESHOLD_SHIFT 0 /* established */
#define HUB_MD_REFRESH_CONTROL_FORMAT_THRESHOLD_MASK 0xfffull
#define HUB_MD_REFRESH_CONTROL_FORMAT_THRESHOLD_INPLACE (HUB_MD_REFRESH_CONTROL_FORMAT_THRESHOLD_MASK << HUB_MD_REFRESH_CONTROL_FORMAT_THRESHOLD_SHIFT)

/*
 * Layout of the slot identity and status register. The header also defines an SN00 slot bit at bit 7 and a PIMM field at 7:4. Both overlap bits named here, so they are left out.
 */
/* word MD_SLOTID_USTAT_FORMAT: 64 bits; public Linux SN0 Hub memory/directory header: MD_SLOTID_USTAT fields (MSU_*) */
#define HUB_MD_SLOTID_USTAT_FORMAT_WIDTH             64 /* established */
#define HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_TEST_SHIFT 7 /* established */
#define HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_TEST_MASK 0x1ull
#define HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_TEST_INPLACE (HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_TEST_MASK << HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_TEST_SHIFT)
#define HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_SHIFT    6 /* established */
#define HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_MASK     0x1ull
#define HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_INPLACE  (HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_MASK << HUB_MD_SLOTID_USTAT_FORMAT_CORE_CLK_SHIFT)
#define HUB_MD_SLOTID_USTAT_FORMAT_NET_SYNC_SHIFT    5 /* established */
#define HUB_MD_SLOTID_USTAT_FORMAT_NET_SYNC_MASK     0x1ull
#define HUB_MD_SLOTID_USTAT_FORMAT_NET_SYNC_INPLACE  (HUB_MD_SLOTID_USTAT_FORMAT_NET_SYNC_MASK << HUB_MD_SLOTID_USTAT_FORMAT_NET_SYNC_SHIFT)
#define HUB_MD_SLOTID_USTAT_FORMAT_FPROM_READY_SHIFT 4 /* established */
#define HUB_MD_SLOTID_USTAT_FORMAT_FPROM_READY_MASK  0x1ull
#define HUB_MD_SLOTID_USTAT_FORMAT_FPROM_READY_INPLACE (HUB_MD_SLOTID_USTAT_FORMAT_FPROM_READY_MASK << HUB_MD_SLOTID_USTAT_FORMAT_FPROM_READY_SHIFT)
#define HUB_MD_SLOTID_USTAT_FORMAT_I2C_INTR_SHIFT    3 /* established */
#define HUB_MD_SLOTID_USTAT_FORMAT_I2C_INTR_MASK     0x1ull
#define HUB_MD_SLOTID_USTAT_FORMAT_I2C_INTR_INPLACE  (HUB_MD_SLOTID_USTAT_FORMAT_I2C_INTR_MASK << HUB_MD_SLOTID_USTAT_FORMAT_I2C_INTR_SHIFT)
#define HUB_MD_SLOTID_USTAT_FORMAT_SN0_SLOT_ID_SHIFT 0 /* established */
#define HUB_MD_SLOTID_USTAT_FORMAT_SN0_SLOT_ID_MASK  0x7ull
#define HUB_MD_SLOTID_USTAT_FORMAT_SN0_SLOT_ID_INPLACE (HUB_MD_SLOTID_USTAT_FORMAT_SN0_SLOT_ID_MASK << HUB_MD_SLOTID_USTAT_FORMAT_SN0_SLOT_ID_SHIFT)

#define HUB_HUB_MD_BANK_MASK                         0xe0000000u /* established */
#define HUB_HUB_MD_BANK_SHIFT                        0x1du /* established */
#define HUB_HUB_MD_DIRTYPE_PREMIUM                   0x1u /* established */
#define HUB_HUB_MD_DIRTYPE_STANDARD                  0x0u /* established */
#define HUB_HUB_MD_DIR_BUSY_EXCL                     0x4u /* established */
#define HUB_HUB_MD_DIR_BUSY_SHARED                   0x3u /* established */
#define HUB_HUB_MD_DIR_EXCLUSIVE                     0x2u /* established */
#define HUB_HUB_MD_DIR_POISONED                      0x1u /* established */
#define HUB_HUB_MD_DIR_SHARED                        0x0u /* established */
#define HUB_HUB_MD_DIR_UNOWNED                       0x7u /* established */
#define HUB_HUB_MD_DIR_WAIT                          0x5u /* established */
#define HUB_HUB_MD_MEMORY_CONFIG_RESET_DEFAULTS      0x1e7fbc3fffffffull /* inferred */
#define HUB_HUB_MD_MEM_BANKS_M_MODE                  0x8u /* established */
#define HUB_HUB_MD_MEM_BANKS_N_MODE                  0x4u /* established */
#define HUB_HUB_MD_MLAN_CTL_ACCESS_BYTES             0x8u /* established */
#define HUB_HUB_MD_MLAN_CTL_RESET_DEFAULTS           0x18b100000ull /* inferred */
#define HUB_HUB_MD_MOQ_SIZE_RESET_DEFAULTS           0x3212u /* inferred */
#define HUB_HUB_MD_REFCNT_COUNT_MASK_PREMIUM         0x7ffffu /* established */
#define HUB_HUB_MD_REFCNT_COUNT_MASK_STANDARD        0x7ffu /* established */
#define HUB_HUB_MD_REFCNT_COUNT_SHIFT                0x5u /* established */
#define HUB_HUB_MD_REFRESH_CONTROL_RESET_DEFAULTS    0x400u /* inferred */
#define HUB_HUB_MD_SIZE_128MB                        0x5u /* established */
#define HUB_HUB_MD_SIZE_16MB                         0x2u /* established */
#define HUB_HUB_MD_SIZE_1GB                          0x8u /* established */
#define HUB_HUB_MD_SIZE_256MB                        0x6u /* established */
#define HUB_HUB_MD_SIZE_2GB                          0x9u /* established */
#define HUB_HUB_MD_SIZE_32MB                         0x3u /* established */
#define HUB_HUB_MD_SIZE_4GB                          0xau /* established */
#define HUB_HUB_MD_SIZE_512MB                        0x7u /* established */
#define HUB_HUB_MD_SIZE_64MB                         0x4u /* established */
#define HUB_HUB_MD_SIZE_8MB                          0x1u /* established */
#define HUB_HUB_MD_SIZE_EMPTY                        0x0u /* established */

#endif /* HUB_GEN_H */
