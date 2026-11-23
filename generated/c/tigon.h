/* generated from devices/tigon/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 4 */
/* input sha256 94c049da8c3025db0a794be8a9ac86283932e63a700df777a6180f810e530ea9 */
/* Alteon Tigon PCI/Gigabit Ethernet controller (SGI IRIS Gigabit Ethernet
 * board) */
#ifndef TIGON_GEN_H
#define TIGON_GEN_H

#include <stdint.h>


/*
 * Miscellaneous Host Control. The read-write bits sit in the low byte, so a
 * host that writes a byte-wide No Swap value can copy that byte into every
 * lane. The manual gives no reset value for this register.
 */
/* misc_host_ctl: rw32, reset unknown */
#define TIGON_MISC_HOST_CTL_OFFSET                   0x40u /* established */
#define TIGON_MISC_HOST_CTL_GATE_ARRAY_REVISION_SHIFT 28 /* established */
#define TIGON_MISC_HOST_CTL_GATE_ARRAY_REVISION_MASK 0xfu
#define TIGON_MISC_HOST_CTL_GATE_ARRAY_REVISION_INPLACE (TIGON_MISC_HOST_CTL_GATE_ARRAY_REVISION_MASK << TIGON_MISC_HOST_CTL_GATE_ARRAY_REVISION_SHIFT)
#define TIGON_MISC_HOST_CTL_MASK_PCI_INTERRUPT_SHIFT 6 /* established */
#define TIGON_MISC_HOST_CTL_MASK_PCI_INTERRUPT_MASK  0x1u
#define TIGON_MISC_HOST_CTL_MASK_PCI_INTERRUPT_INPLACE (TIGON_MISC_HOST_CTL_MASK_PCI_INTERRUPT_MASK << TIGON_MISC_HOST_CTL_MASK_PCI_INTERRUPT_SHIFT)
#define TIGON_MISC_HOST_CTL_ENDIAN_WORD_SWAP_SHIFT   5 /* established */
#define TIGON_MISC_HOST_CTL_ENDIAN_WORD_SWAP_MASK    0x1u
#define TIGON_MISC_HOST_CTL_ENDIAN_WORD_SWAP_INPLACE (TIGON_MISC_HOST_CTL_ENDIAN_WORD_SWAP_MASK << TIGON_MISC_HOST_CTL_ENDIAN_WORD_SWAP_SHIFT)
#define TIGON_MISC_HOST_CTL_ENDIAN_BYTE_SWAP_SHIFT   4 /* established */
#define TIGON_MISC_HOST_CTL_ENDIAN_BYTE_SWAP_MASK    0x1u
#define TIGON_MISC_HOST_CTL_ENDIAN_BYTE_SWAP_INPLACE (TIGON_MISC_HOST_CTL_ENDIAN_BYTE_SWAP_MASK << TIGON_MISC_HOST_CTL_ENDIAN_BYTE_SWAP_SHIFT)
#define TIGON_MISC_HOST_CTL_HARD_RESET_SHIFT         3 /* established */
#define TIGON_MISC_HOST_CTL_HARD_RESET_MASK          0x1u
#define TIGON_MISC_HOST_CTL_HARD_RESET_INPLACE (TIGON_MISC_HOST_CTL_HARD_RESET_MASK << TIGON_MISC_HOST_CTL_HARD_RESET_SHIFT)
#define TIGON_MISC_HOST_CTL_CLEAR_INTERRUPT_SHIFT    1 /* established */
#define TIGON_MISC_HOST_CTL_CLEAR_INTERRUPT_MASK     0x1u
#define TIGON_MISC_HOST_CTL_CLEAR_INTERRUPT_INPLACE (TIGON_MISC_HOST_CTL_CLEAR_INTERRUPT_MASK << TIGON_MISC_HOST_CTL_CLEAR_INTERRUPT_SHIFT)
#define TIGON_MISC_HOST_CTL_INTERRUPT_STATE_SHIFT    0 /* established */
#define TIGON_MISC_HOST_CTL_INTERRUPT_STATE_MASK     0x1u
#define TIGON_MISC_HOST_CTL_INTERRUPT_STATE_INPLACE (TIGON_MISC_HOST_CTL_INTERRUPT_STATE_MASK << TIGON_MISC_HOST_CTL_INTERRUPT_STATE_SHIFT)

/*
 * PCI State. All bits are zero at reset. The Miscellaneous Host Control reset
 * does not change this register. Bit 20 and the bits under it are the ones the
 * host-bus rules turn on.
 */
/* pci_state: rw32, reset 0x0 */
#define TIGON_PCI_STATE_OFFSET                       0x5cu /* established */
#define TIGON_PCI_STATE_DEFAULT_PCI_WRITE_COMMAND_SHIFT 28 /* established */
#define TIGON_PCI_STATE_DEFAULT_PCI_WRITE_COMMAND_MASK 0xfu
#define TIGON_PCI_STATE_DEFAULT_PCI_WRITE_COMMAND_INPLACE (TIGON_PCI_STATE_DEFAULT_PCI_WRITE_COMMAND_MASK << TIGON_PCI_STATE_DEFAULT_PCI_WRITE_COMMAND_SHIFT)
#define TIGON_PCI_STATE_DEFAULT_PCI_READ_COMMAND_SHIFT 24 /* established */
#define TIGON_PCI_STATE_DEFAULT_PCI_READ_COMMAND_MASK 0xfu
#define TIGON_PCI_STATE_DEFAULT_PCI_READ_COMMAND_INPLACE (TIGON_PCI_STATE_DEFAULT_PCI_READ_COMMAND_MASK << TIGON_PCI_STATE_DEFAULT_PCI_READ_COMMAND_SHIFT)
#define TIGON_PCI_STATE_ASSERT_ALL_PBE_ON_WRITES_SHIFT 23 /* established */
#define TIGON_PCI_STATE_ASSERT_ALL_PBE_ON_WRITES_MASK 0x1u
#define TIGON_PCI_STATE_ASSERT_ALL_PBE_ON_WRITES_INPLACE (TIGON_PCI_STATE_ASSERT_ALL_PBE_ON_WRITES_MASK << TIGON_PCI_STATE_ASSERT_ALL_PBE_ON_WRITES_SHIFT)
#define TIGON_PCI_STATE_PCI_ROM_RETRY_SHIFT          22 /* established */
#define TIGON_PCI_STATE_PCI_ROM_RETRY_MASK           0x1u
#define TIGON_PCI_STATE_PCI_ROM_RETRY_INPLACE (TIGON_PCI_STATE_PCI_ROM_RETRY_MASK << TIGON_PCI_STATE_PCI_ROM_RETRY_SHIFT)
#define TIGON_PCI_STATE_PCI_ROM_DESIRED_SHIFT        21 /* established */
#define TIGON_PCI_STATE_PCI_ROM_DESIRED_MASK         0x1u
#define TIGON_PCI_STATE_PCI_ROM_DESIRED_INPLACE (TIGON_PCI_STATE_PCI_ROM_DESIRED_MASK << TIGON_PCI_STATE_PCI_ROM_DESIRED_SHIFT)
#define TIGON_PCI_STATE_BUS_32BIT_SHIFT              20 /* established */
#define TIGON_PCI_STATE_BUS_32BIT_MASK               0x1u
#define TIGON_PCI_STATE_BUS_32BIT_INPLACE (TIGON_PCI_STATE_BUS_32BIT_MASK << TIGON_PCI_STATE_BUS_32BIT_SHIFT)
#define TIGON_PCI_STATE_PCI_66MHZ_BUS_SHIFT          19 /* established */
#define TIGON_PCI_STATE_PCI_66MHZ_BUS_MASK           0x1u
#define TIGON_PCI_STATE_PCI_66MHZ_BUS_INPLACE (TIGON_PCI_STATE_PCI_66MHZ_BUS_MASK << TIGON_PCI_STATE_PCI_66MHZ_BUS_SHIFT)
#define TIGON_PCI_STATE_NO_WORD_SWAP_DMA_SHIFT       18 /* established */
#define TIGON_PCI_STATE_NO_WORD_SWAP_DMA_MASK        0x1u
#define TIGON_PCI_STATE_NO_WORD_SWAP_DMA_INPLACE (TIGON_PCI_STATE_NO_WORD_SWAP_DMA_MASK << TIGON_PCI_STATE_NO_WORD_SWAP_DMA_SHIFT)
#define TIGON_PCI_STATE_USE_MEM_READ_MULTIPLE_SHIFT  17 /* established */
#define TIGON_PCI_STATE_USE_MEM_READ_MULTIPLE_MASK   0x1u
#define TIGON_PCI_STATE_USE_MEM_READ_MULTIPLE_INPLACE (TIGON_PCI_STATE_USE_MEM_READ_MULTIPLE_MASK << TIGON_PCI_STATE_USE_MEM_READ_MULTIPLE_SHIFT)
#define TIGON_PCI_STATE_DMA_WRITE_MAX_SHIFT          5 /* established */
#define TIGON_PCI_STATE_DMA_WRITE_MAX_MASK           0x7u
#define TIGON_PCI_STATE_DMA_WRITE_MAX_INPLACE (TIGON_PCI_STATE_DMA_WRITE_MAX_MASK << TIGON_PCI_STATE_DMA_WRITE_MAX_SHIFT)
#define TIGON_PCI_STATE_DMA_READ_MAX_SHIFT           2 /* established */
#define TIGON_PCI_STATE_DMA_READ_MAX_MASK            0x7u
#define TIGON_PCI_STATE_DMA_READ_MAX_INPLACE (TIGON_PCI_STATE_DMA_READ_MAX_MASK << TIGON_PCI_STATE_DMA_READ_MAX_SHIFT)
#define TIGON_PCI_STATE_FORCE_RESET_SHIFT            0 /* established */
#define TIGON_PCI_STATE_FORCE_RESET_MASK             0x1u
#define TIGON_PCI_STATE_FORCE_RESET_INPLACE (TIGON_PCI_STATE_FORCE_RESET_MASK << TIGON_PCI_STATE_FORCE_RESET_SHIFT)

/*
 * DMA Write State, the state of the write channel that moves data from the card
 * to the host. The manual gives no reset value.
 */
/* dma_write_state: rw32, reset unknown */
#define TIGON_DMA_WRITE_STATE_OFFSET                 0xa0u /* established */
#define TIGON_DMA_WRITE_STATE_FORCE_32BIT_PCI_SHIFT  3 /* established */
#define TIGON_DMA_WRITE_STATE_FORCE_32BIT_PCI_MASK   0x1u
#define TIGON_DMA_WRITE_STATE_FORCE_32BIT_PCI_INPLACE (TIGON_DMA_WRITE_STATE_FORCE_32BIT_PCI_MASK << TIGON_DMA_WRITE_STATE_FORCE_32BIT_PCI_SHIFT)
#define TIGON_DMA_WRITE_STATE_DMA_ACTIVE_SHIFT       2 /* established */
#define TIGON_DMA_WRITE_STATE_DMA_ACTIVE_MASK        0x1u
#define TIGON_DMA_WRITE_STATE_DMA_ACTIVE_INPLACE (TIGON_DMA_WRITE_STATE_DMA_ACTIVE_MASK << TIGON_DMA_WRITE_STATE_DMA_ACTIVE_SHIFT)
#define TIGON_DMA_WRITE_STATE_DMA_NO_SWAP_SHIFT      1 /* established */
#define TIGON_DMA_WRITE_STATE_DMA_NO_SWAP_MASK       0x1u
#define TIGON_DMA_WRITE_STATE_DMA_NO_SWAP_INPLACE (TIGON_DMA_WRITE_STATE_DMA_NO_SWAP_MASK << TIGON_DMA_WRITE_STATE_DMA_NO_SWAP_SHIFT)
#define TIGON_DMA_WRITE_STATE_DMA_RESET_SHIFT        0 /* established */
#define TIGON_DMA_WRITE_STATE_DMA_RESET_MASK         0x1u
#define TIGON_DMA_WRITE_STATE_DMA_RESET_INPLACE (TIGON_DMA_WRITE_STATE_DMA_RESET_MASK << TIGON_DMA_WRITE_STATE_DMA_RESET_SHIFT)

/*
 * DMA Read State, the state of the read channel that moves data from the host
 * to the card. The manual gives no reset value.
 */
/* dma_read_state: rw32, reset unknown */
#define TIGON_DMA_READ_STATE_OFFSET                  0xb0u /* established */
#define TIGON_DMA_READ_STATE_FORCE_32BIT_PCI_SHIFT   3 /* established */
#define TIGON_DMA_READ_STATE_FORCE_32BIT_PCI_MASK    0x1u
#define TIGON_DMA_READ_STATE_FORCE_32BIT_PCI_INPLACE (TIGON_DMA_READ_STATE_FORCE_32BIT_PCI_MASK << TIGON_DMA_READ_STATE_FORCE_32BIT_PCI_SHIFT)
#define TIGON_DMA_READ_STATE_DMA_ACTIVE_SHIFT        2 /* established */
#define TIGON_DMA_READ_STATE_DMA_ACTIVE_MASK         0x1u
#define TIGON_DMA_READ_STATE_DMA_ACTIVE_INPLACE (TIGON_DMA_READ_STATE_DMA_ACTIVE_MASK << TIGON_DMA_READ_STATE_DMA_ACTIVE_SHIFT)
#define TIGON_DMA_READ_STATE_DMA_NO_SWAP_SHIFT       1 /* established */
#define TIGON_DMA_READ_STATE_DMA_NO_SWAP_MASK        0x1u
#define TIGON_DMA_READ_STATE_DMA_NO_SWAP_INPLACE (TIGON_DMA_READ_STATE_DMA_NO_SWAP_MASK << TIGON_DMA_READ_STATE_DMA_NO_SWAP_SHIFT)
#define TIGON_DMA_READ_STATE_DMA_RESET_SHIFT         0 /* established */
#define TIGON_DMA_READ_STATE_DMA_RESET_MASK          0x1u
#define TIGON_DMA_READ_STATE_DMA_RESET_INPLACE (TIGON_DMA_READ_STATE_DMA_RESET_MASK << TIGON_DMA_READ_STATE_DMA_RESET_SHIFT)

/*
 * Word of mailbox 0 that raises the mailbox event, read as the least
 * significant word at the higher address. Inferred: the manual contradicts
 * itself. Section 2.7 says a write to the upper half of one of the 32
 * eight-byte locations raises the event, and section 9.12.3 says a write to the
 * least significant word does and a write to the most significant word does
 * not. The Linux driver writes its producer indexes to the words at offset 4 of
 * each location, which matches 9.12.3 if the least significant word sits at the
 * higher address. Writing mailbox 0 also deasserts the PCI interrupt pin at
 * once, so a host can clear the interrupt and pass a message in one write. The
 * manual says a mailbox may be read back as often as needed. The same word of
 * mailbox n is eight bytes after that of mailbox n minus one.
 */
/* mailbox_0_low: rw32, reset unknown */
#define TIGON_MAILBOX_0_LOW_OFFSET                   0x504u /* inferred */

#endif /* TIGON_GEN_H */
