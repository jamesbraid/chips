# Neterion Xframe 10-Gigabit Ethernet controller

The Neterion Xframe, formerly S2io, is a 10-gigabit Ethernet controller on PCI and PCI-X add-in cards. SGI sold one such card as its 10-Gigabit Ethernet Network Adapter. Its register and layout constants are in [devices/xframe/registers.md](registers.md), generated from [devices/xframe/registers.toml](registers.toml). Each item there carries its grade and its source.

This page holds what the constants table cannot: the product boundary, the interrupt chain, link state, the receive path, the byte-order rules, the watchdog the IRIX driver runs, and what is still unknown.

## What the contract rests on

- **Public Linux and OpenBSD drivers** for the register names, the descriptor layout, the interrupt masks and the link-state test. Anything taken only from these is a software expectation, graded inferred. The drivers show what software expects of the card. They do not prove what the silicon does.
- **The IRIX 6.5.30 xg driver object**, read by disassembly. It is the only Xframe driver in the IRIX 6.5.29 and 6.5.30 software sets examined here. Its install rule restricts it to the IP35 board class, and the IP27 kernel builds examined carry no Xframe driver. Its writes and its bring-up sequence are established. The watchdog and the interrupt acknowledgement it implies are graded inferred, because the held analysis describes them as behaviour rather than as a read of the whole code path.
- **The SGI 10-Gigabit Ethernet Network Adapter User's Guide**, 007-4669-003. Printed page 1 lists the supported systems and printed page 2 gives the feature list, including the DMA channel count. Its register layout is not held. The Neterion programming manual is not held either.

A software expectation is not a measurement. Where the held sources disagree, or stop short, this page says so and leaves the item unknown.

## Product and PCI

- The card is a PCI and PCI-X add-in card. The public drivers match it by device ID alone, with no platform check (inferred).
- The card is universal-voltage and PCI 2.3 compatible, so it can sit in a 5 V slot and negotiate conventional PCI (established for the universal 3.3 V and 5 V signalling and PCI 2.3 compliance by the guide, printed p. 2; the PCI-X negotiation is inferred from the drivers).
- The guide (007-4669-003, printed p. 1) lists these supported systems: Altix XE, Altix 4700, 450, 3000 and 350, Prism, Origin 350, Onyx 4 and 350, Origin 3000 with an IX or PX brick, Onyx 3000 and Tezro (established). Origin 200 and Origin 2000 are not on the list (established as an absence from that list).
- The SGI card's subsystem device ID is not established by any held source (unknown).
- The PCI vendor and device IDs are not carried by this import. The constants table has no entry for them.

## Interrupts

**Delivery.** The OpenBSD driver uses legacy PCI INTx, one line at attach (inferred). The Linux driver supports INTA, MSI and MSI-X and defaults to MSI-X. The `XMSI_ADDRESS` register and its swap-enable bits carry the MSI setup (inferred). Whether MSI reaches the CPU through the Bridge is unknown.

**Level or pulse, and the clear rule.** Whether each interrupt status is level or pulse, and what clears it, is unknown. The drivers write masks, and the timing is not in the held sources.

**The chain for the scheduled interrupt.** The IRIX driver arms a periodic timer, `SCHEDULED_INT_CTRL`, with its enable bit set. The timer raises an interrupt with no traffic and no link change. That interrupt reaches the processor through this chain (inferred):

1. The timer latches the source in the TXPIC leaf, `TXPIC_INT_REG`.
2. The TXPIC roll-up bit, `PIC_INT_TX`, reports it in the PIC interrupt status.
3. The general interrupt status bit `GEN_INTR_TXPIC` reports it to the host.

The driver unmasks the source by clearing the PIC mask and the TXPIC leaf mask. The public drivers enable a general mask word by writing zero to it. The bit number of `GEN_INTR_TXPIC` and the offset of the PIC status word are not in the held sources (unknown).

The scheduled source does not touch the GPIO link source or the MAC link latch (inferred, from the IRIX driver's behaviour). It therefore keeps the watchdog fed without a carrier change.

**The period.** The IRIX driver computes the timer period at run time from the PCI bus speed. The public header marks the period as to-be-determined. The held sources do not give a value (unknown). The driver needs only an interrupt more often than its watchdog interval (inferred).

**Acknowledgement.** The public drivers read `TXPIC_INT_REG` to acknowledge the scheduled source. The IRIX driver reads `GENERAL_INT_STATUS`, then writes `TXPIC_INT_REG` without a read of that register in between (inferred, from the IRIX driver's behaviour). Whether the latch clears on a read, on a write, or on both is the device's contract, and it is unknown from these sources.

## Watchdog in the IRIX driver

The IRIX driver keeps a software idle counter. Each interrupt entry clears it. A watchdog that re-arms every second adds to it, and when it reaches 15 the driver resets the card (inferred). An interface that is up but idle therefore needs an interrupt about every fifteen seconds, from any source. The driver does not unmask the TX and RX traffic interrupt sources, `TX_TRAFFIC_MASK` and `RX_TRAFFIC_MASK`, and their reset is all ones (inferred). The timer, not traffic, is the source that keeps the counter cleared.

## Link state

**The link-up test.** The link is up when the two adapter-status fault bits are both clear: remote fault, bit 57, and local fault, bit 56 (inferred). The OpenBSD driver marks the media active on this test. Its link-state interrupt re-enables the adapter only when the link is restored, on the same test. The Linux `LINK_IS_UP` macro is the same mask (inferred). The offset of the adapter-status word is not in the held sources.

**The GPIO link source.** The public Linux driver has link-up and link-down bits in the GPIO interrupt status. It writes that status when it sees both bits set (inferred). Whether a write clears those bits is not established. Which source carries link indication to the IRIX driver is not identified (unknown). The raw latch behaviour, whether status is kept while masked, and the GPIO acknowledgement rule are open (unknown).

**The MAC latch.** Bit 32 of the MAC error register, `MAC_RMAC_ERR_REG`, latches a link-state change. The OpenBSD driver acknowledges it by writing one to the bit. When that interrupt source is unmasked, the driver's read is non-destructive (inferred).

**Re-writing the enable.** The IRIX driver may write `ADAPTER_EN` again while it is already set. It also reads the link latches during its periodic service (inferred, from the IRIX driver's behaviour). Neither action changes the link state by itself.

## Receive path

**Interrupt coalescing.** The public Neterion driver picks a frame-count band from a bandwidth sample (inferred). The lowest band interrupts once per frame. The coalescing setting is a ceiling on how long a receive interrupt may wait. It does not impose a minimum delay (inferred). The register that holds the band values is not named in the held sources.

**Ring refill.** Both public drivers refill a live receive ring by setting the descriptor's ownership bit in host memory. Neither writes a register to do it. Both acknowledge the receive traffic interrupt before the refill (inferred). How the card notices a refilled descriptor is not described in the held sources (unknown).

**Descriptors.** A transmit descriptor is four 64-bit words: control word 1, which holds the ownership bit, control word 2, the buffer address, and the host control word (inferred, from the public driver's layout). The Linux driver sets the ownership bit once on the first descriptor of a gather list, not on each one (inferred). A receive descriptor comes in one-, three- and five-buffer forms. Descriptor pages are 4 KB and chain to the next page by a physical pointer (inferred).

**DMA channels.** The guide says the card has 16 DMA channels, 8 for reading and 8 for writing (established, 007-4669-003 printed p. 2). The held sources do not say how reading and writing map onto the transmit and receive paths (unknown).

**Five-buffer mode.** The IRIX driver selects ring mode 2, `RING_MODE_5`, when the MTU is set to jumbo size (inferred). A five-buffer descriptor is 64 bytes, with three control words and five buffer pointers (inferred, from the public driver's layout). The public driver supports the general rule that the card splits a frame by protocol layer, and that the payload may run on across the last three buffers (inferred). The exact buffer placement is not corroborated by any held public source, so it is unknown. Ring mode 0 is the one-buffer form. Ring mode 1 is the three-buffer form, which the IRIX driver does not select (inferred).

Two placements are unknown. The first is how the card classifies and places the first fragment of a datagram. The second is where a VLAN-tagged frame's header goes. The public driver shows a VLAN tag bit, but the held sources do not say whether the card's layer split moves an 18-byte header into the 14-byte first buffer (unknown).

## Multicast

For a receive match entry, a mask bit that is clear means the bit must match, and a bit that is set means the bit is not checked (inferred). The public Linux driver uses this reading. It writes mask zero for an exact-match entry and a group-bit mask for all-multicast.

The OpenBSD driver writes masks the other way around. Under the polarity above, its exact-match masks (all ones) match every frame, and its all-multicast sentinels do not reduce to "any multicast" under either polarity. Which driver is right is not settled by the held sources. The vendor programming manual would settle it, and it is not held (unknown). This import records the disagreement and does not pick a side.

## Byte order and DMA

**What the IRIX driver asks for.** It makes one DMA mapping with byte-stream, 64-bit, data and fixed flags, and takes every ring, descriptor, statistics and frame address from it (established, from the driver object's disassembly). Descriptors and frames both ask for byte-stream order. On a PIC or XBridge the byte-stream flag is bit 55 of the 64-bit address. On a Bridge it is bit 19 of the slot (established, from the same disassembly). The Bridge's own per-device swap control is in [the DMA windows section of the bridge family page](../bridge/family.md#dma-windows).

The driver writes receive and transmit descriptors as big-endian 64-bit words (established, from the same disassembly).

**Byte-swapper control.** The driver writes all ones to both halves of the byte-swapper control. It then writes `0xabffbfff` to the low word at offset `0x908` and `0xffffeaff` to the high word at offset `0x90c` (established, from disassembly). It checks the byte-swapper diagnostic against `0x0123456789abcdef` (established, from disassembly).

Read as one 64-bit value, the written words give `0xffffeaff_abffbfff` (inferred, from the driver's convention). With the OpenBSD driver's bit names (a cross-check, not IRIX evidence), every flip-enable bit is set, and the swap-enable bits `PIF_R_SE`, `PIF_W_SE`, `TxP_SE` and `XMSI_SE` are set. The swap-enable bits `TxD_R_SE`, `TxD_W_SE`, `TxF_R_SE`, `RxD_R_SE`, `RxD_W_SE`, `RxF_W_SE` and `STATS_SE` are clear (inferred).

Under the IRIX value the card's descriptor and frame swap enables are clear, and the Bridge supplies a byte stream. Which 32-bit cycle the card treats as the high half is unknown. The card's own placement of bytes under this value is unknown too. The public Linux driver says the card reads descriptors as big-endian by default, and that is the basis for the statement that it reads big-endian descriptors and byte-ordered frames (inferred). No held hardware document confirms it.

**Statistics.** The statistics block layout and its byte order are not in the held sources. The Neterion programming manual would settle them, and it is not held (unknown).

## What is unknown

- The subsystem device ID of the SGI card.
- The level or pulse behaviour of each interrupt status, and the clear rule for each.
- The offsets of `GEN_INTR_TXPIC`'s status word, the PIC status word and the general mask, and the bit number of `GEN_INTR_TXPIC`.
- The scheduled-timer period.
- Whether the latch that drives the scheduled source clears on a read, a write, or both.
- The GPIO latch behaviour, its acknowledgement rule, and which source carries link indication to the IRIX driver.
- Whether MSI reaches the CPU through the Bridge.
- The split of the 16 DMA channels between transmit and receive.
- Exact five-buffer placement, first-fragment classification and VLAN-tagged frame placement.
- How the card notices a refilled receive descriptor.
- The multicast mask polarity, given that the OpenBSD and Linux drivers disagree.
- The statistics block layout and byte order.
- The card's own placement of bytes under the IRIX byte-swapper value.
