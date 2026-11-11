# BCM5701 on the IO9: how long from the transmit doorbell to a receive completion

Question. After software rings the transmit mailbox of the Broadcom BCM5701 gigabit controller on an IO9 board, how
long does it take before the receive return ring and status block show a frame that came back (a MAC loopback frame, or
a reply from the network)? Which parts of that time are fixed by the chip, which by the link and the peer, and what do the
public driver and the IRIX driver assume?

Sources. Broadcom *BCM57XX Programmer's Guide*, 57XX-PG105-R, dated 2008-01-29 (printed page numbers below); Linux mainline
v7.2-rc7 (db2ddb87143) `drivers/net/ethernet/broadcom/tg3.c` and `tg3.h`; IEEE 802.3 framing; the IRIX 6.5.30 IP35 boot object
`if_tg.o` (sha256 0dec82e929558ac27fa2a9fdc826db90f6dabd4142fa07dd8a7bc95233d92bce), read with the retools Capstone decoder, as
recorded in the kudzu repository's `docs/ip35-tg-driver.md`. Nothing was run.

## Answer

1. **The chip has no published doorbell-to-completion latency. Unknown.**
   The Programmer's Guide gives structure and counters, not a latency; the only sizes it gives for the DMA path are FIFO depths
   (the PCI read DMA FIFO holds 512 bytes). No Bedrock, PIC or PCI-X figure for the IO9 path was found either. What can be
   stated is a sum of terms, below, of which only the DMA terms are unknown.

2. **When a received frame is reported. Established (PG105 printed pages 62 to 63, 453 to 454, 296).**
   A status-block update (and, if enabled, the interrupt) occurs when the number of receive return BDs filled since the last update
   reaches the Receive Max Coalesced BD register (0x3c10), or when the receive tick timer (0x3c08, units of 1 microsecond) has
   expired and a frame has been DMA'd to the host since the last update. The timer reloads and counts down after **every** status-block
   update whatever its cause, not after a frame; with the register at zero only the count triggers; with the count register
   at zero only the timer does. In the "clear ticks on BD events" mode (bits in HOSTCC_MODE at 0x3c00; page 296) the receive
   counter instead starts after a receive BD event, the send counter after a send BD event. So on an idle ring, where the timer expired
   long ago, a lone frame is reported as soon as its DMA completes; a frame arriving within the tick period of the last update waits out the remainder.
   A send consumer index advances when the frame's data has crossed the PCI bus, not when it has left on the wire (page 453).

3. **What the IRIX driver programs. Established (code), see kudzu `docs/ip35-tg-driver.md`.**
   HOSTCC_MODE 0x402 (enable and clear ticks on send BD events only), the during-interrupt registers 0x3c18 to 0x3c24 zero, receive ticks
   starting at 28 (adaptive, first step 14, bounds 28 to 896), receive max frames 2 on the path read. So the coalescing wait after a
   quiet period is at most 28 microseconds, rising under load (first step to 42; later steps not worked out).

4. **What the Linux driver assumes. Established (tg3.c v7.2-rc7).**
   The MAC-loopback self test (`tg3_run_loopback`, line 13494) rings the send mailbox (line 13616), waits 10 microseconds, then
   up to 35 times forces a coalescing update and waits 10 microseconds, testing the send consumer and receive producer indices
   (lines 13621 to 13632). The comment gives 350 microseconds as the allowance "on some 10/100 Mbps devices"; a gigabit
   loopback frame is expected within the first passes (inferred from the comment's wording). Its default coalescing (line 17650
   onward, constants in `tg3.h` lines 1234 to 1264) is receive 50 microseconds and 5 frames, send 150 microseconds and 53 frames for every
   part; the Programmer's Guide's own initialisation list recommends 150 microseconds and 10 frames.

5. **Wire time. Established arithmetic (IEEE 802.3: 8-byte preamble, 12-byte gap).**
   t_wire = 8 x (frame bytes + 20) / rate: 0.67 us for a 64-byte frame at 1 Gb/s, 6.72 us at 100 Mb/s; 12.3 us for a 1518-byte
   frame at 1 Gb/s, 123 us at 100 Mb/s. A MAC loopback frame passes the MAC at line rate (inferred); a frame answered by a peer adds the peer's
   turnaround and a second wire time, neither of which is the chip's.

6. **Sum. Inferred shape, unknown DMA terms.**
   completion = send-BD and frame DMA read + t_wire(out) + (peer, if any) + t_wire(in) + receive DMA write + return BD and status
   DMA + coalescing wait (item 2). The DMA terms are unknown; the other terms are established. For a lone frame on an idle ring the wait is zero; for a
   frame inside the tick period it is up to 28 microseconds under IRIX's initial setting.

## What would settle it

The DMA terms: a timestamp of the transmit mailbox write against the status-block index change, taken on a real IO9
BCM5701 from software that reads the processor interface's real-time counter on both sides of a MAC-loopback frame. Not
required for the wire and coalescing terms, which dominate for frames of 64 bytes or more at 100 Mb/s and below.
