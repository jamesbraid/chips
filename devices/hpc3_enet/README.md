# HPC3 Ethernet DMA channels

The HPC3 is the peripheral controller on the Indy's GIO64 bus. Its Ethernet port moves frames between
main memory and an 8-bit SEEQ Ethernet controller through two DMA channels, one receive and one transmit.
Each channel is driven by a chain of descriptors in memory. The SEEQ is reached by programmed I/O through
the HPC3. The register offsets, widths, field bits and reset notes, each with its grade, are in
[`devices/hpc3_enet/registers.toml`](registers.toml); the generated reference is
`devices/hpc3_enet/registers.md`. This page holds what the unit does not carry.

Each fact carries one label. **Established** means the source states it: the HPC3 specification, a public
driver, or the shipped IRIX driver, read in full for that path. **Inferred** means a reasoned reading, and
the reasoning is given. **Unknown** means the sources do not settle it. No fact here was measured on a
board.

## Sources

- **HPC3 Chip Specification**, revision 1.4, 22 January 1993, 65 pages. Printed page numbers match the PDF
  page numbers. Cited as "HPC3 spec p. N".
- **Linux** mainline, commit `db2ddb871435`: `drivers/net/ethernet/seeq/sgiseeq.c` and `sgiseeq.h`,
  `arch/mips/include/asm/sgi/hpc3.h`, `ioc.h` and `ip22.h`.
- **NetBSD**, commit `07004b2a9dac`: `sys/arch/sgimips/hpc/if_sq.c`, `sqvar.h`, `hpcreg.h` and `hpc.c`;
  `sys/dev/ic/seeq8003reg.h`.
- **OpenBSD**, branch `origin/sgi-is-alive-at-7.9`, file blob `157006abbdf7`: `sys/arch/sgi/hpc/if_sq.c`.
- **IRIX 6.5 base release** (June 1998), the Ethernet driver object `usr/cpu/sysgen/IP22boot/if_ec2.o`
  (SHA-256 `990647b634644a4244a61d50a0b17ee99c48d826f3db6196f878de41d1d206a5`) and its tunables file
  `var/sysgen/mtune/if_ec2`. Called "the IRIX driver" below. The IRIX 6.5.22 driver, the last release for
  this machine, was not read.

## Interrupt (established, with two inferred points)

- The Ethernet channels have one interrupt output of their own. The other DMA channels share a separate
  pin (HPC3 spec p. 8, p. 56).
- On the Indy that output is local interrupt 0, bit 3 of the INT2 interrupt controller. The Linux `ioc.h`
  and `ip22.h` headers give the bit; the drivers rely on it.
- Sources: receive end of frame with the interrupt bit set; receive channel stopped at end of chain; receive
  buffer overflow; SEEQ receive FIFO overflow; transmit frame done with the interrupt bit set; late
  collision, sixteen collisions, and transmit underflow (HPC3 spec pp. 15-16, 41).
- HPC3 polls the SEEQ status when the SEEQ raises its own interrupt, and decides whether to interrupt the
  host (HPC3 spec pp. 15-16).
- HPC3 has no interrupt delay timer. The specification says it was removed (p. 16), so a receive interrupt
  follows each frame.
- Reading bit 1 of the reset register gives the interrupt state. Writing one there clears every source
  except receive buffer overflow (HPC3 spec p. 41).
- **Inferred:** the output is a level, held until cleared. The specification describes a status bit that
  stays readable until written, and every driver clears it at the top of its handler and then scans the
  rings instead of counting interrupts.
- **Inferred:** a completion that lands after the clear raises the interrupt again, even if the handler
  already reaped that frame. A completion that lands between the status read and the clear is cleared with
  the rest; every driver tolerates that, because it scans the rings after clearing.

Driver sequences (established):

| Driver | Sequence |
|---|---|
| IRIX | Read the reset register; if bit 1 is set, write 2; reap receive; restart receive if stopped; reclaim transmit. |
| Linux | Write 2 unconditionally; reap receive; restart if stopped; reclaim transmit. |
| NetBSD, OpenBSD | Read the reset register; if bit 1 is set, write back the value read with bit 1 set; then as Linux. |

## Reset (established)

- Bit 0 of the reset register resets both channels and the SEEQ, by driving the SEEQ reset pin. It is set
  at power-on (HPC3 spec p. 41).
- Setting it also clears the active bit of both channels (pp. 14-15). Power-on reset clears the receive
  active bit.
- The driver reset sequence is the same in each source: clear both active bits, write 3 (reset and clear
  interrupt), wait, then write 0. IRIX waits 10 microseconds; Linux and the BSDs wait 20.
- NetBSD's register header names bit 3 "clear RBO condition" with a question mark. No other source uses it.
  Unknown; see below.

## Access to the descriptor pointers (established)

Reading a descriptor pointer needs a dummy read of the PIO configuration register first. The HPC3
specification's errata section gives this as the work-around (p. 59). The IRIX driver does it before it
reads the receive current descriptor pointer.

## Descriptors (established, with one inferred bit)

- Three 32-bit words, quadword aligned, not crossing a page: word 0 is the buffer physical address, word 1
  is the count and flags, word 2 is the next descriptor's physical address (HPC3 spec pp. 6-7).
- A global descriptor endian bit sits outside the Ethernet block (p. 37).
- Word 1 layouts are in the defs unit (`RX_DESC_CTL` and `TX_DESC_CTL`).
- **Inferred:** bit 14 of a receive descriptor is an ownership flag in all four drivers, though the
  specification reserves it. The driver sets it when arming the descriptor and treats a clear bit as
  filled. HPC3 does not check it. See the ownership entry in the defs unit.

## Receive channel

### Filling a descriptor (established unless marked)

HPC3 spec pp. 13-16.

1. Software writes the first descriptor's address to the receive next descriptor pointer and sets the
   channel active. HPC3 resets its FIFO pointers and fetches the descriptor.
2. HPC3 writes two pad bytes, then the frame from the destination address to the last data byte (the SEEQ
   strips the preamble and CRC), then one status byte, which is the SEEQ receive status for that frame. The
   buffer starts on a doubleword boundary.
3. After the last byte is in memory, HPC3 writes word 1 back so that bits 13 to 0 hold the programmed count
   minus the frame bytes minus 3. The frame length is the programmed count minus the bytes left minus 3.
   The specification says "the first word of the DMA descriptor" for this write-back, but its own
   descriptor figure (p. 6) and every driver put the count in word 1. The count is word 1.
4. If the interrupt bit and end-of-packet are both set, HPC3 raises the Ethernet interrupt once the frame is
   in memory (p. 16).
5. If end of chain is clear, HPC3 follows word 2 to the next descriptor. If end of chain is set, HPC3 clears
   the active bit "upon completion of the transfer associated with that descriptor" and raises the interrupt
   (pp. 15-16).

Unknown: whether the write-back stores the whole of word 1 or only its low half. No driver depends on it.
IRIX and the BSDs rewrite the whole word when they re-arm and keep the high flags from their own copy.

### End of ring: stop, not wrap (established)

The channel stops at a descriptor with end of chain set, and clears the active bit (p. 15). It wraps only by
following word 2 of a descriptor whose end-of-chain bit is clear. All four drivers link their descriptors in
a closed ring and keep end of chain on the last descriptor they have re-armed, moving it forward as they
re-arm it. The specification's sentence that the end-of-chain flag "should never be encountered" (p. 14)
describes a ring that software keeps ahead of the wire, not a wrap.

### Order of write-back and active clear (inferred)

For the end-of-chain descriptor, the frame and status byte are written, then word 1 is written back, then the
active bit clears, then the interrupt is raised. The specification gives the first two in that order (pp.
14-15). The IRIX driver reads bit 14 to reap and reads the active bit afterwards. If the order were reversed,
IRIX could see the channel stopped while the end-of-chain descriptor still looked unfilled, then restart
from that descriptor's next pointer and skip it. The converse race is benign: a frame that completes between
IRIX's bit-14 read and its active-bit read is reaped on the next interrupt.

### The receive current descriptor pointer (not in the specification)

The IRIX driver writes the receive current descriptor pointer at initialisation, with the descriptor it marks
end-of-chain, before it writes the next descriptor pointer. Later, when it finds the channel stopped, it
compares this register with the descriptor it recorded as last, and treats equal values as the plain "ran out
of descriptors" case (established, IRIX driver).

**Inferred, weak:** the hardware updates the pointer to each descriptor it fetches. After a stop at end of
chain it then names that descriptor, and after a stop for another reason it names an earlier one. This is
the reading under which IRIX's comparison does what its two messages say. The initialisation write does not
contradict it, but is not explained by it either. Unknown until a hardware read after a stop at end of chain
and after a SEEQ overflow stop settles it.

### No descriptor available

- **Established:** after filling the end-of-chain descriptor, the channel is inactive and raises the Ethernet
  interrupt (p. 16).
- **Established:** a SEEQ receive FIFO overflow also stops the channel. It stops at whatever descriptor is
  current, not at end of chain (p. 16). IRIX enables the SEEQ overflow interrupt, so this case is reachable
  on IRIX.
- **Established:** a frame longer than its buffer sets receive buffer overflow and stops the channel with an
  interrupt (p. 16).
- **Inferred, strong:** frames that arrive while the channel is inactive are lost, not held. The SEEQ receive FIFO must be read about every 800 ns on average (its data sheet gives the service rate, not the FIFO
  depth). HPC3 resets its own FIFO pointers when
  the channel is set active (p. 13), so nothing buffered before the restart reaches memory. The wire is not
  back-pressured.
- **Unknown:** whether HPC3 keeps reading the SEEQ FIFO while the channel is inactive, draining and discarding,
  or leaves it to overflow. That decides whether each lost frame produces SEEQ overflow status and an
  interrupt. HPC3 keeps processing SEEQ interrupts while inactive (p. 16), so a lost frame may raise an
  interrupt with overflow status in the receive control bits 5 to 0. The active state does not change in
  either case.

### Receive recovery in the IRIX driver (established, from the driver's interrupt handler)

1. Read the reset register. If bit 1 is set, write 2.
2. Reap: from the oldest armed descriptor, while bit 14 of word 1 is clear and armed descriptors remain, take
   the frame, count it in the interface's input counter, and pass it up. There is no per-interrupt limit below
   the ring size.
3. Read the receive control register. If the active bit is clear, read the receive current descriptor pointer
   (after the dummy read above) and keep, as the comparison target, the descriptor that carried end of chain
   before this pass.
4. Re-arm each empty slot up to the ring size. Set end of chain on the new last descriptor, then clear it on the
   old last, and record the new last descriptor.
5. If the active bit was set at step 3, read the receive control register again. If it is now clear, read the
   pointer and take as the comparison target the new last descriptor from step 4. If it is still set, go on to
   transmit.
6. With the channel stopped, if the pointer equals the comparison target, write the next pointer from that
   descriptor's word 2 and restart the channel. Otherwise run the full reinitialisation: both channels stopped,
   the reset register set to 3, about 10 microseconds, cleared, every descriptor re-armed, the SEEQ
   reprogrammed, and both chains restarted.

Linux and the BSDs recover differently. They do not read the current descriptor pointer. They restart at their
next unreaped descriptor whenever the active bit is clear after a reap (established, from their drivers). Both
styles recover from a channel that stops at end of chain. Only the IRIX style also needs the current descriptor
pointer.

Reachability on hardware:

- **Established reachable:** a SEEQ FIFO overflow stops the channel at a descriptor that is not the last one.
  Under the inferred update rule the pointer then names that descriptor, and IRIX resets the interface.
- **Inferred:** the channel stops at end of chain during one pass of the handler, after step 3 and before step
  5, and that pass re-armed at least one descriptor. The comparison target is then the new last descriptor,
  which the pointer cannot name, so IRIX resets even for a plain end-of-chain stop. The window is one handler
  pass.

## Transmit channel

HPC3 spec pp. 13-14, 16. Established unless marked.

- HPC3 fetches up to 80 bytes at a time into an 80-byte FIFO. It moves to the next descriptor when the count
  reaches zero and end of chain is clear. A frame may span descriptors. End of packet marks its last buffer,
  and HPC3 signals end of frame to the SEEQ with the last byte.
- When the SEEQ reports a frame sent, HPC3 writes the done bit (bit 15) into word 1 of that frame's first
  descriptor. The same write clears bits 14 to 0, and it is a bus write (p. 13). If the frame's last
  descriptor has the interrupt bit set, HPC3 then interrupts the host, after the frame has gone without a
  collision (p. 16). Once it has the acknowledgement for every frame up to an end-of-chain descriptor, it clears
  the active bit (p. 13).
- **Inferred:** the done bit is written before the interrupt for the same frame, because every driver's
  interrupt handler reads it to decide what completed.
- **Inferred:** bits 31 to 16 of word 1 survive that write. Linux relies on it, and the specification says only
  bits 14 to 0 are cleared. Whether the write is a 16-bit store or a read-modify-write is unknown.
- A collision before the first 80 bytes leave the FIFO is retried from the FIFO. A later collision, sixteen
  failed attempts, or an underflow stops the channel, sets the status bits and raises the interrupt (pp. 14, 16).
- The end-of-chain sample bit in the transmit count register shows whether HPC3 has already sampled end of chain
  for the frame in progress (p. 43). NetBSD and OpenBSD append to an active chain by clearing end of chain on the
  old last descriptor, and rely on the completion interrupt to restart the channel if they lost the race.
- With the write-control bit set, HPC3 writes the descriptor's inter-packet gap byte into SEEQ extended register 2
  after 80 bytes, or after a whole shorter frame, has gone to the SEEQ (p. 14).
- The transmit pointers at offsets `0x1a000` and `0x1a004` are not in the specification. The IRIX driver reads
  them in its transmit path and interrupt handler: the first descriptor of the packet in progress, and the first
  descriptor of the previous packet, which its reclaim walks. Their update rules are unknown.

## Register window of the SEEQ (established)

The SEEQ registers sit in a window of HPC3 at offset `0x54000`, up to `0x544ff`. SEEQ register n is at the window
base plus 4n, and the SEEQ data is in the low byte of each word. The Linux driver lays them out as 32-bit words, and
the IRIX driver uses the same stride (HPC3 spec p. 33 for the address map; the public drivers for the layout).

## Address map notes (established)

- The specification's address map (p. 33) assigns the 64 KiB block from offset `0x10000` to `0x1ffff` to the HD0,
  HD1 and Ethernet DMA channel registers. It does not list the two extra registers at offsets `0x18000` and
  `0x1a000`. The IRIX receive recovery depends on the first of them, so a decoder must cover it.
- The FIFO RAM windows at offsets `0x2c000` and `0x2e000` are diagnostic. The sources give no extent for them, and
  no driver uses them in normal operation.

## Out of scope

- The FIFO RAM contents and the FIFO RAM test mode (diagnostic; no supported software uses them).
- GIO64 parity and bus-error reporting.
- The SCSI and PBUS channels of the same HPC3.
- The second HPC3 of the Challenge M and Indigo2 expansion, and the HPC1-based GIO card that the same drivers handle at
  other offsets.
- The SEEQ Ethernet controller itself. Its registers, banks and transmit and receive rules are in the [SEEQ sheet](../seeq_8003/README.md).

## Unknowns

Each item says what would settle it. Also listed in [open questions](../../questions/README.md).

- **Receive write-back width.** Whether the write-back stores the whole of word 1 or only its low half. Route: a
  hardware read of a descriptor after a frame is stored, with its high bits compared before and after.
- **Receive current descriptor pointer update rule**, and why IRIX writes it at initialisation. Route: a hardware
  read of it after a stop at end of chain and after a SEEQ overflow stop.
- **Transmit pointers at offsets `0x1a000` and `0x1a004`**, and what updates them. Route: a hardware read during
  and after a transmit of two frames.
- **Lost-frame status** while the receive channel is stopped. Route: a hardware read of the receive control register
  after flooding a stopped channel.
- **Which descriptor an overflow stop leaves current**, and whether that descriptor is written back. Route: the same
  overflow capture as above, read against the descriptor memory.
- **Receive buffer overflow clearing.** The specification says it is cleared by writing one (p. 16) and by a read of
  the control register (p. 41). NetBSD names reset bit 3 for it with a question mark, and no driver clears it. Route:
  a hardware test of each method on a frame longer than its buffer.
- **Width of the transmit done-bit write.** Whether the write is a 16-bit store or a read-modify-write. Route: a
  hardware read of bits 31 to 16 after a transmit completes.
- **IRIX 6.5.22 driver.** Only the base 6.5 driver was read. Route: extract the Ethernet driver object from the 6.5.22
  overlays and compare its interrupt handler with the base release.
