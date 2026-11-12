# Neterion Xframe 10-Gigabit Ethernet controller (SGI 10-Gigabit Ethernet card), the offsets, bits and layouts the held sources establish

<!-- generated from defs/xframe.toml by defs-gen - do not edit, change the source -->

The Neterion (formerly S2io) Xframe 10-gigabit Ethernet controller on the SGI 10-Gigabit Ethernet card. Grades say how each item was derived: established means the IRIX xg driver object states it on disassembly, or the card manual gives it; inferred means a software expectation taken from a public Linux or OpenBSD driver, from the IRIX driver's behaviour, or from a card manual value the manual does not put in a register table; unknown means no held source settles the value. The offsets here are the register names the public drivers use, so they are software expectations of the card, not measured silicon behaviour. Reset values are not held anywhere in these sources, so each register's reset is unknown. The prose page holds the interrupt chain, link state, receive path and open questions.

Unit `xframe`, macro prefix `XFRAME`.
Default source: Linux s2io driver.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ADAPTER_STATUS_RMAC_LOCAL_FAULT` | 0x100000000000000 | inferred | OpenBSD xge driver (RMAC_LOCAL_FAULT); Linux s2io driver (s2BIT(7)) | Local-fault bit of the adapter status word, bit 56. The link is up when this bit and the remote-fault bit are both clear. |
| `ADAPTER_STATUS_RMAC_REMOTE_FAULT` | 0x200000000000000 | inferred | OpenBSD xge driver (RMAC_REMOTE_FAULT); Linux s2io driver (s2BIT(6)) | Remote-fault bit of the adapter status word, bit 57. The link is up when this bit and the local-fault bit are both clear. |
| `DESCRIPTOR_PAGE_BYTES` | 0x1000 | inferred | Linux s2io driver (descriptor pages) | Size of one descriptor page. Pages chain to the next page by a physical pointer. |
| `DMA_CHANNELS` | 0x10 | inferred | SGI 10-Gigabit Ethernet card manual, rev 003 (document number not recorded in the held source) | Total DMA channels the card manual gives. How the channels split between transmit and receive is unknown. |
| `GENERAL_INT_MASK_ENABLE` | 0x0 | inferred | Linux s2io driver (general interrupt mask enable value) | Value that enables a GENERAL interrupt mask word. The public driver writes zero to enable. The offset of the general mask is not in the held sources. |
| `MAC_RMAC_ERR_REG_OFFSET` | 0x2028 | inferred | OpenBSD xge driver (MAC error register and its acknowledgement) | Offset of the MAC-block error register. Bit 32 is the link-state-change latch. |
| `MAC_RMAC_LINK_STATE_CHANGE` | 0x100000000 | inferred | OpenBSD xge driver (MAC error register and its acknowledgement) | Link-state-change latch, bit 32 of the MAC error register. The OpenBSD driver acknowledges it by writing one to the bit. |
| `PIC_INT_MASK_OFFSET` | 0x808 | inferred | Linux s2io driver; IRIX xg driver object (disassembly) | Offset of the PIC interrupt mask. Clearing the TXPIC roll-up bit unmasks the scheduled-interrupt source. |
| `PIC_INT_TX` | 0x8000000000000000 | inferred | Linux s2io driver (PIC_INT_TX) | TXPIC roll-up bit in the PIC interrupt status and mask words, bit 63 (s2BIT(0)). The offset of the status word is not in the held sources. |
| `RING_MODE_1` | 0x0 | inferred | Linux s2io driver (ring mode values) | Ring-mode field value for one-buffer receive descriptors in the receive ring control register. |
| `RING_MODE_3` | 0x1 | inferred | Linux s2io driver (ring mode values) | Ring-mode field value for the three-buffer receive descriptor form. The IRIX driver does not select it for jumbo frames. |
| `RING_MODE_5` | 0x2 | inferred | Linux s2io driver (ring mode values) | Ring-mode field value for five-buffer receive descriptors. The IRIX driver selects it when the MTU is set to jumbo size. |
| `RXD_FIVE_BUFFER_BYTES` | 0x40 | inferred | Linux s2io driver (receive descriptor layout) | Size in bytes of a five-buffer receive descriptor. |
| `RXD_FIVE_BUFFER_CONTROL_WORDS` | 0x3 | inferred | Linux s2io driver (receive descriptor layout) | Control words in a five-buffer receive descriptor. |
| `RXD_FIVE_BUFFER_POINTERS` | 0x5 | inferred | Linux s2io driver (receive descriptor layout) | Buffer pointers in a five-buffer receive descriptor. |
| `SCHEDULED_INT_CTRL_OFFSET` | 0x918 | inferred | Linux s2io driver (scheduled_int_ctrl); IRIX xg driver object (disassembly) | Offset of the scheduled-interrupt timer control. The IRIX driver arms it during card initialization, and the public driver names it the same way. |
| `SCHED_INT_CTRL_TIMER_EN` | 0x8000000000000000 | inferred | Linux s2io driver (SCHED_INT_CTRL_TIMER_EN) | Timer enable. Bit 63, which the public header writes as s2BIT(0). The header's own s2BIT numbering puts bit n at 1 << (63 - n), which the OpenBSD fault-bit values below confirm. |
| `SWAPPER_CTRL_HIGH_OFFSET` | 0x90c | established | IRIX xg driver object (disassembly) | Offset of the high word of the byte-swapper control that the IRIX driver writes at bring-up. |
| `SWAPPER_CTRL_HIGH_VALUE` | 0xffffeaff | established | IRIX xg driver object (disassembly) | Value the IRIX driver writes to the high word of the byte-swapper control. |
| `SWAPPER_CTRL_LOW_OFFSET` | 0x908 | established | IRIX xg driver object (disassembly) | Offset of the low word of the byte-swapper control that the IRIX driver writes at bring-up. The held sources do not say whether this offset is relative to the card's register base or absolute. |
| `SWAPPER_CTRL_LOW_VALUE` | 0xabffbfff | established | IRIX xg driver object (disassembly) | Value the IRIX driver writes to the low word of the byte-swapper control after first writing all ones to both halves. |
| `TXD_WORDS` | 0x4 | inferred | Linux s2io driver (transmit descriptor layout) | 64-bit words in a transmit descriptor: control word 1 (which holds the ownership bit), control word 2, the buffer address, and the host control word. |
| `TXPIC_INT_MASK_OFFSET` | 0x818 | inferred | Linux s2io driver; IRIX xg driver object (disassembly) | Offset of the TXPIC leaf mask. The IRIX driver clears it at bring-up to unmask the scheduled-interrupt source. |
| `TXPIC_INT_REG_OFFSET` | 0x810 | inferred | Linux s2io driver; OpenBSD xge driver; IRIX xg driver object (disassembly) | Offset of the TXPIC leaf status. The scheduled-interrupt source is reported here. The public drivers read it to acknowledge the source, and the IRIX driver writes it instead. The device's own acknowledgement rule is open; see the prose page. |
| `WATCHDOG_CHECK_SECONDS` | 0x1 | inferred | IRIX xg driver object (disassembly) | Interval at which the IRIX driver's watchdog checks the idle count. |
| `WATCHDOG_RESET_COUNT` | 0xf | inferred | IRIX xg driver object (disassembly) | Idle count at which the IRIX driver resets the card. The driver clears the count on every interrupt entry, so the reset fires after about fifteen seconds with no interrupt of any kind. |
