# SEEQ 8003 and 80C03 Ethernet controller

The SEEQ 8003 is an 8-bit Ethernet data link controller. The Indy's HPC3 moves its frames to and from main
memory, and the SEEQ is reached by programmed I/O through the HPC3. The Indy carries an 80C03-compatible part (inferred; see below).
The register offsets, widths, field bits, reset values and grades are in
[`devices/seeq_8003/registers.toml`](registers.toml); the generated reference is `devices/seeq_8003/registers.md`. The DMA
channels and the descriptor rules are in the [HPC3 Ethernet sheet](../hpc3_enet/README.md). This page holds what the
unit does not carry.

Each fact carries one label. **Established** means the SEEQ 8003 data sheet states it. **Inferred** means the
80C03 additions, which rest on public drivers because the 80C03 data sheet is not held, or a driver's use of a
register, or a reasoned reading that the text gives. **Unknown** means the sources do not settle it. Nothing
here was measured on a board.

## Which part

**Inferred.** IRIX and Linux both read register 0 after reset and treat a low byte of zero as the 80C03.
NetBSD's `sq(4)` manual lists the 8003 and the "80c03 (aka SGI EDLC)" across the SGI machines. Reading the part
marking on an Indy board photograph would settle it. Unknown until then.

## Sources

- **SEEQ 8003 EDLC Ethernet Data Link Controller** data sheet, document MD400024/B, November 1989, printed pages
  4-1 to 4-8, in the *1990 SEEQ Data Book*. Revision MD400024/C (May 1991) was compared on its first page.
  Cited as "8003 data sheet p. 4-N".
- **80C03** data sheet: not held. NetBSD's register header cites an LSI Logic 80c03 data sheet, and the archive and aggregator copies tried were not retrievable. Facts about the 80C03-only registers therefore rest on public driver headers and are
  inferred.
- **HPC3 Chip Specification**, revision 1.4, pp. 13 to 16, as used in the HPC3 sheet.
- **Linux** `drivers/net/ethernet/seeq/sgiseeq.c` and `sgiseeq.h` at the `references/code/linux` pin (`c339f4010dea`).
- **NetBSD** `sys/dev/ic/seeq8003reg.h` and `sys/arch/sgimips/hpc/if_sq.c` at the `references/code/netbsd` pin (`0747dc050541`).
- **OpenBSD** `sys/arch/sgi/hpc/if_sq.c` at the `references/code/openbsd` pin (`7011342f6a72`).
The commits named in earlier versions of this page were not submodules here and were not checked.
- **IRIX 6.5 base release**, IP22 Ethernet driver object, as in the HPC3 sheet. The IRIX 6.5.22 driver was not
  read.

## Register window

Eight byte-wide registers, selected by A2 to A0. Behind HPC3, register *n* is at `0x1fbd4000 + 4n` (established,
HPC3 spec p. 33), with the data in the low byte.

## Registers by direction

**Established** (8003 data sheet p. 4-5). Reads and writes of the same offset mean different things.

| Reg | Read | Write |
|---|---|---|
| 0 to 5 | 8003: no read. 80C03: counters and flags, below | Station address bytes 0 to 5 in bank 0. Byte 0 bit 0 goes on the wire first |
| 6 | Receive status | Receive command |
| 7 | Transmit status | Transmit command |

On the plain 8003 every write to registers 0 to 5 goes to the station address, because the part has no banks.

## 80C03 additions

**Inferred**, from the NetBSD header (which says it follows the 80C03 data sheet), the Linux driver header, the
OpenBSD driver and the IRIX driver's use.

Transmit command bits 6:5 select the bank for writes to registers 0 to 5: bank 0 is the station address, bank 1
the multicast hash bytes 0 to 5, and bank 2 the registers below. Value 3 is not described. IRIX and Linux read registers 0 to 5 with bank 2 selected, so driver use does not depend on the bank; whether the bank changes those reads is unknown.

Reads of registers 0 to 5:

- 0 and 1: transmit collision counter. Low byte in 0; bits 2:0 of 1 are bits 10:8. 11 bits in all.
- 2 and 3: total collision counter, low byte and high bits. The width is not stated.
- 4: test register; do not use.
- 5: bit 0 SQE flag, bit 1 no-carrier flag.

Writes in bank 2:

- 0 and 1: multicast hash bytes 6 and 7.
- 2: inter-packet gap. HPC3 writes each frame's gap here when its write-control bit is set (HPC3 spec p. 14). The
  byte encoding is unknown. IRIX computes it from a tunable, Linux writes zero and NetBSD calls it reserved.
- 3: control. Bit 0 enables and clears the transmit collision counter, bit 1 the total counter, bit 2 the SQE
  flag, bit 3 the multicast hash filter, bit 4 receives short frames, bit 5 enables and clears the no-carrier
  flag. Linux and NetBSD agree on every bit. Writing 0 and then 1 to an enable bit clears the counter or flag.
- 4: configuration: auto-pad, no preamble, do not receive own frames, no CRC, AutoDUPLEX, CRC to FIFO and fast
  discard, as NetBSD's header names them. No bit positions are given, and no Indy driver writes it.

## Identification

**Inferred** from each driver. IRIX resets the interface and then reads register 0; Linux reads register 0. Both treat a low byte of zero as the 80C03. NetBSD and OpenBSD write `0xa5` to register 0 in bank 0 and read it back. Zero means the 80C03,
because the read returns the collision counter. The plain 8003 has no register 0 read, so its result there is
undefined.

## Receive

**Established** (8003 data sheet pp. 4-3, 4-4, 4-7, 4-8). The receive FIFO must be serviced every 800 ns on
average to avoid overflow. The data sheet does not state the FIFO depth: an earlier version of this page said 16
bytes and derived 12.8 µs from it, and no page of the data sheet or of the public drivers gives that figure, so
both are dropped (**unknown**, route: the 80C03 data sheet). The frame passes without preamble and FCS. At the end of a frame the status is loaded, subject to
the old/new rule, and an interrupt is raised if its condition is enabled.

Receive status (register 6, read) has bits 5 to 0 for overflow, CRC error, dribble error, short frame, end of
frame and good frame, and bit 7 for old/new. Reading it clears the receive interrupt. Old/new is set on a read or
on reset and cleared only when status is loaded for a frame of interest, one whose condition is enabled in bits
5 to 0. While it is zero the register is write-protected. A frame received before the status is read is discarded
and its status is not loaded.

**RxDC** (receive discard) is asserted, and the FIFO cleared, for an overflow, CRC error, short frame, address
mismatch or lost status when the matching interrupt enable is clear. When the enable is set, the frame is passed
with an end-of-frame marker, so errored frames can be received.

HPC3 turns these into its own late-discard rules (HPC3 spec p. 15); see the [HPC3 sheet](../hpc3_enet/README.md).

**Inferred:** with the IRIX enables (bits 5 to 1 and bit 0 all set), only address mismatches and lost status
cause RxDC. Overflowed frames are passed and marked.

Receive command (register 6, write) bits 5 to 0 enable the interrupts named above, and bits 7:6 set the match
mode: 00 receiver off, 01 all frames, 10 station and broadcast, 11 station, broadcast and all multicast
(**established**, 8003 data sheet pp. 4-6, 4-7). The IRIX driver ends with bit 0 set too, so the overflow
interrupt is enabled in practice.

## Transmit

**Established** (8003 data sheet pp. 4-3, 4-4, 4-8). The transmit FIFO needs a byte every 800 ns on average. On a
collision the chip sends jam, asserts TxRET, which clears its FIFO, and backs off by a truncated binary
exponential of up to 2^10 slot times of 51.2 µs. After 16 collisions it sets the 16-collision and collision
bits. On underflow it stops and sets the underflow bit. Status is loaded after every attempt.

Transmit command (register 7, write) bits 3 to 0 enable interrupts on underflow, collision, 16 collisions and
success, in the order the data sheet lists them. Transmit status (register 7, read) reports the same four
bits, with old/new in bit 7: set on each read and on reset, cleared when new status is loaded at the end of
every attempt. Reading it clears the transmit interrupt (**established**, pp. 4-5, 4-6).

HPC3 restarts a frame from its 80-byte buffer on an early collision and treats a later one as a late collision
(HPC3 spec p. 14).

## Interrupt

**Established:** INT is asserted while any enabled transmit or receive condition is pending, and it is cleared
when the status register holding the cause is read (8003 data sheet pp. 4-6, 4-8).

**Inferred:** behind HPC3 the host never sees INT. HPC3 reads both status registers when INT asserts, copies them
into its own control registers and decides whether to interrupt the host (HPC3 spec p. 15). A host read of the
SEEQ status registers through programmed I/O also clears INT.

## Reset

**Established** (8003 data sheet p. 4-8): reset clears both command registers, the transmit status register and
receive status bits 0 to 5, and sets the old/new bits. Station address registers are not listed as cleared.
**Inferred:** the 80C03's collision counters are zero after reset, because three drivers detect the part by
reading zero there.

## How the drivers program it

**Inferred** for every row. Each driver's use is a software expectation, not a statement of the hardware, so
these rows say what the drivers do and the register table above says what the chip does.

| Step | IRIX | Linux | NetBSD / OpenBSD |
|---|---|---|---|
| Reset | HPC3 reset register set to 3, a wait, then 0 | same | same |
| Station address | TX command 0 (bank 0), registers 0 to 5 | same | TX command 0 (OpenBSD writes `0xf0` first), registers 0 to 5 |
| Multicast | bank 1 registers 0 to 5, bank 2 registers 0 and 1, control bit 3 | not used | not used |
| TX command | `0x4f` on 80C03, `0x0f` on 8003 | same | `0x0f` |
| Control (bank 2 register 3) | IRIX's own byte (not decoded) | `0x37` | OpenBSD `0x24` after a zero write; NetBSD none |
| Gap (bank 2 register 2) | computed from a tunable | 0 | none |
| RX command | mode, `0x3e`, start HPC3 receive, then mode `0x3f` | mode, `0x3e`, then start | mode, `0x3e`, then start |

Mode is `0x80` normally, `0xc0` with multicast and `0x40` promiscuous, in all drivers. `0x4f` selects bank 2 and
sets all four transmit interrupt enables. The IRIX receive sequence departs from the HPC3 recommendation (receive
bits 5 to 1, transmit bits 3 to 0; HPC3 spec p. 15), by enabling the overflow interrupt too.

## Out of scope

- Encoder and decoder pins and collision timing.
- The 80C03 configuration register, which no Indy driver uses.

## Unknowns

These are also listed in [open questions](../../questions/README.md).

- **The 80C03 data sheet.** It is not held. Route: a copy of the data sheet, or a board's part marking.
- **Bank 2 register 2 encoding.** Route: a capture of the IRIX driver writing it with a known gap tunable, read
  against the frame spacing on a wire.
- **Whether `0xf0` in the transmit command is needed for any feature.** The OpenBSD driver writes it, and its
  next write overwrites it, so its sequence does not need it. Route: a board test of a feature that a driver
  enables only after writing `0xf0`.
- **Bank selection and reads of registers 0 to 5.** Route: a read of registers 0 to 5 with bank 0 and with bank 2
  selected, after frames with collisions.
- **Reset values** of the control register and the station address registers.
- **Width of the total collision counter**, and the bits of its high register above bit 0.
- **Bit positions of the configuration register.** Route: a copy of the 80C03 data sheet.
