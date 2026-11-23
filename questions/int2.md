# INT2 (Indigo interrupt controller): open questions

1. **Port register bit 4 and the power-off path.** *[route: software now for the R4000 kernel's power-off routine, which this page did not find; then the Indigo
   Owner's Guide for the polarity]* No shipped object or PROM routine clears bit 4 of `0x1fb801df`. Which polarity requests power off, and whether the front
   panel uses a different path, is unknown.
2. **Port register LED bits.** *[route: the HP-1 schematic, which was not read for this page]* Bits 1 to 3 are named LEDs by the header but used as serial select
   and the retrace latch by drivers. Which role each bit plays on the R4000 board and the LED polarity are unknown.
3. **What the PROM's three writes to `+0x30` do.** *[route: a Ghidra pass over `0xbfc008f8`..`0xbfc0096c` and the 8254 data sheet, which is not held]* The
   values `0x02`, `0x42`, `0x42` go to lane 0 of counter 0, before any control word. Whether the part ignores the lower address bits is unknown.
4. **The 8254 master clock.** *[route: the HP-1 schematic or a board photograph of the oscillator]* 1 MHz is inferred from kernel and PROM constants and the
   public drivers' statements; no document states the crystal divider.
5. **Edge or level latch of the timer interrupts, and read of the acknowledge register.** *[route: the 8254 data sheet and the HP-1 schematic]* Unknown.
6. **The R3000 board mapping and the case-interlock bit.** *[route: an IRIX 5.3 or earlier IP12 kernel object]* The CPU-line mapping rests on NetBSD only; local 1 bit 1
   (case interlock on IP12) has no handler in the IP20 kernel.
7. **The 4.0.5G PROM.** *[route: software now]* Not compared with 4.0.5D for INT2 behaviour.
8. **VME status bits 1 to 7 and local 0 bit 7 behaviour.** *[route: an IP20 board with a VME option, or the V30/35 guide]* No IP20 code reads `0x13` for VME.
