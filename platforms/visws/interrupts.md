# Visual Workstation interrupt routing, end to end

Question answered: how does an interrupt get from a device to a processor on a Visual Workstation 320 or 540, and what
must a model implement to make Linux 2.4 to 3.14 work? Source and grading as on the [platform page](README.md):
`established` is the kernel's behaviour, `inferred` is a reading, `unknown` names what would settle it.

## The path

```
 PCI device -> Lithium bridge (A or B) -> Cobalt interrupt controller (line n) -> processor's local APIC -> vector
 PIIX4 IDE channels, USB function, ----> Cobalt interrupt controller (own lines) ------------------------^
 PIIX4 8259 pair (serial, floppy, parallel, audio-in-8259 ...) -> one line (12) --^
 Cobalt timer, "cache" source ---------> line 28
 Lithium audio engine -----------------> line 22
 video in/out, other Cobalt sources ---> lines 16 to 19, 24, 25
```

- **There is no I/O APIC (established).** The kernel skips I/O-APIC detection and set-up on this machine. The Cobalt
  controller takes its place and the kernel names its chip type "Cobalt-APIC". Each of its thirty lines has a
  redirection entry holding a vector and a mask; delivery is to the processors' local APICs, which the kernel
  acknowledges with the local APIC end-of-interrupt register ([register detail](../../devices/cobalt/README.md)).
- **The Lithium has no interrupt controller of its own (inferred).** The only Lithium interrupt registers are one enable
  bitmap per bridge ([Lithium page](../../devices/lithium/README.md)) and the audio block's own status and mask. How the
  bridges present their pending state to Cobalt (wire per source or encoded) is not visible; the kernel needs only that
  each enabled source drives a fixed Cobalt line.
- **Level triggered, active low as seen by Cobalt (established for level; polarity from the 2.2 comment).** Every
  line the kernel enables is programmed level-triggered. The 2.2 code comment on 320 rev 5 states the PROM left the
  legacy devices configured "appropriate for the 8259" and the kernel must flip them to "level triggered, active lo as
  required by Lithium" for the direct route.

## Cobalt lines (established, from the header)

| Line | What | Notes |
|---|---|---|
| 0 to 4 | Lithium bridge A, INTA of device 0 to 4 | Ethernet at device 3 gives line 3 |
| 5, 6 | Lithium bridge A, the shared INTB/INTC/INTD | the header says "5 and 6" |
| 2 | Second IDE channel | 320 only. Shares the number with bridge A device 2's INTA; see the anomalies below |
| 4 | First IDE channel | 5 on a 320 revision 5 (2.6; the 2.2 tables put it on 5 for revision 5 and 4 for 6, 4 on the 540) |
| 7 | PIIX4 USB function | header: "this one is weird" |
| 8 to 12 | Lithium bridge B, INTA of device 0 to 4 | header says "8 and 9-12". Line 12 is also the 8259 line below |
| 12 | PIIX4 8259 pair (serial, floppy, parallel, others) | collides with bridge B device 4 INTA. Device 4 of B is the PIIX4, whose INTA is never mapped (below), so the collision is harmless in the kernel's map |
| 13 to 15 | Lithium bridge B, shared INTB/INTC/INTD | never used by any code |
| 16, 17 | Video output 0 and 1 | named only |
| 18, 19 | Video input 0 and 1 | named only |
| 22 | Lithium audio engine | the sound driver requests it |
| 24, 25 | `AS`, `RE` | named only; the names' meaning is unknown |
| 28 | Cobalt timer and "cache" interrupt | the system tick |
| 29 | `NMI` | named only |

Line 2 for IDE1 and line 4 for IDE0 coincide numerically with bridge A's per-slot lines for devices 2 and 4, and 5
coincides with the shared line. The kernel never has a device on both at once on the machine the code was written
for (A has one real device) so the clashes do not show. Whether a real board has such lines separately is **unknown**.

## Legacy devices behind the PIIX4

- **The two 8259s are cascaded in the usual way, but their combined output goes to Cobalt line 12, not to the processor
  (established).** The kernel installs a handler on that line (the "master" interrupt, kernel irq 28 in 2.6, since the
  irq number is 16 plus the line). The 8259 pair itself is programmed in 2.2 with the standard sequence: ICW1 `0x11` to
  `0x20` and `0xa0`; vector bases `0x08` and `0x70`; cascade `0x04` (master, slave on input 2) and `0x02`; 8086 mode
  `0x01`; then all inputs masked (`0xff`). In 2.6 the stock 8259 initialisation call is used.
- **Dispatch is by polling (established).** The master handler writes the poll command `0x0c` to `0x20`, reads `0x20`;
  bit 7 clear means spurious. Otherwise the low three bits are the input. If the input is 2 (the cascade), it polls the
  slave the same way through `0xa0` and adds 8. It masks the input, acknowledges with a specific end-of-interrupt (`0x60`
  plus the input, and on the master `0x62` for a slave source), invokes the handler registered for that legacy irq
  (1 to 15, the ordinary ISA numbers) and unmasks it again. So the 8259 must implement poll mode, specific EOI and
  masking as an ordinary 8259 does. The Linux irq numbers for those devices are the usual ones: 3 and 4 serial, 6 floppy,
  7 parallel, and so on.
- **Line 12 is acknowledged like any Cobalt line** by masking it at the controller and writing the local APIC EOI, and
  restored by the end method, which re-enables it without checking; the 8259 handler restores it as its last step.
- **The two IDE channels do not use the 8259 (established).** The IDE interrupt numbers are the conventional 14 and 15 but
  they are Cobalt lines (4 and 2; 5 for 320 revision 5). The PIIX4's IDE function therefore drives Cobalt lines directly.
- **The PIIX4's USB function has a line of its own (7).** PCI-wise it is device 4 function 2 on the bridge B bus, pin D
  (the kernel's map below).
- **The Super I/O's UARTs** are legacy devices through the 8259 in 2.6. On the **320 revision 5** the 2.2 kernel instead
  found the legacy devices wired "directly to Lithium from the 307" ("Rev 005 motherboards"), set UART 1's interrupt
  destination to 0 ("no interrupt propagated", register `0x70` of logical device 6) and printed "SGI 320 rev 5:
  disabling 307 uart1 interrupt". The 2.2 table of rev 5 direct wiring: parallel line 4, floppy 6, serial 13 with the
  comment "not really... h/w bug!", IDE 5. The 2.6 code has dropped the direct route and the UART disable, so
  how rev 5 works in 2.6 (does it use the 8259 or lose its serial port) is **unknown**.
- **The 307's interrupt registers** (logical device select `0x07`; destination `0x70`, type `0x71` with bit 0 level and bit
  1 active-high; floppy is logical device 3, parallel 4, UART 2 is 5 and not wired, UART 1 is 6 and is the serial port)
  are the only access the kernel makes to them for interrupts, and only on that one board.

## The 2.2 per-revision tables (established as the 2.2 code; mostly superseded)

| Board | IDE | Notes |
|---|---|---|
| 320 revision 5 | lines 5 and 2 | legacy devices direct (see above): serial 13, parallel 4, floppy 6 |
| 320 revision 6 | lines 4 and 2 | USB on line 7 |
| 540 revision 2 | line 4 | one channel |

The 2.2 start-up code wires the timer, the Ethernet (line 3), the 8259 and IDE only; other devices were not set up there.
Revision 4 boards have no entry in the 2.2 start-up code (it falls through without wiring IDE).

## Linux interrupt numbers, 2.5 to 3.14 (established)

Irq 0 is the timer, on line 28. Irq 1 to 15 are legacy; 14 and 15 are the IDE channels on Cobalt lines (above) and the
others are the PIIX4's virtual interrupts. Irq `16 + n` is Cobalt line `n`. The vector delivered is irq plus `0x20`. Irq
numbers below 16 other than 0, 14 and 15 are "virtual": no vector exists for them, they are found by the 8259 poll.
In 2.2 and 2.4 the numbering was different (the legacy irq number plus `0x20` for every cookie), and 2.2 gave the
Ethernet irq 3 and the timer irq 0.

## PCI interrupt routing (established as the code's table; the table itself is questionable)

Inputs: bus (A or B), device number 0 to 4, pin (A to D, after the kernel's usual bridge swizzle for devices behind a
bridge). Output: a Cobalt line. The 2.6 code (`visws_map_irq`):

1. Bus B (the PIIX4's), device 4, pin A: no interrupt.
2. Bus B, device 4, pin D: line 7 (the PIIX4's USB).
3. Pin A, anywhere else: line `device` on bus A, `8 + device` on bus B.
4. Pins B to D on bus A: line `5 + ((device + pin - 1) mod 2)` with the pin index counted from B as 1, so lines 5 and 6.
5. Pins B to D on bus B: line `5 + ((3 - device) + ((pin - 1) mod 3))`, with device 0 treated as 3 and the same pin
   index. The precedence of the two terms as the code writes them is as given here.

Resulting table, bus A (pins A B C D) and bus B (the same, from running the code's formulae):

| Device | Bus A | Bus B |
|---|---|---|
| 0 | 0 5 6 5 | 8 5 6 7 |
| 1 | 1 6 5 6 | 9 7 8 9 |
| 2 | 2 5 6 5 | 10 6 7 8 |
| 3 | 3 6 5 6 | 11 5 6 7 |
| 4 | 4 5 6 5 | none 4 5 7 |

Problems (inferred from reading): for bus B the code uses the bridge A base (5), not bridge B's declared base 13, so the
shared lines of B land on 4 to 9; two of them (device 1 pin D and device 1 pin A) both give 9, device 4 pin B gives line
4, which is the first IDE channel; and line 7 (USB) is also given to pin D of devices 0 and 3. A comment in the header lists
13 to 15 as B's shared lines, which nothing uses. Either the table is wrong, or the hardware really wires B's shared
pins over lines 4 to 9, or the machines never put option cards on bus B. The owner's guides do not settle it: the 320 guide shows one bus with
three slots and the PIIX4, the 540 guide shows two buses of four and two slots, and neither says which Lithium bridge
each is. An SGI engineer's 1999 post calls the option slots "the second PCI bus, normally bus one" (inferred). The 2.4 kernel's version of the map
(`pcibios_fixup_irqs` calling a helper that is not in the files read) is **not in any tree held**.

The same engineer says, for a USB keyboard failure with a PCI capture card: "the USB is implemented as a normal PCI
device ... which has its D interrupt line tied to one of the Cobalt chipset APIC interrupt lines. None of the PCI slot
interrupt lines are tied to that line", and that an option-card BIOS emulation mode routes the second bus's INTA to INTD
through "an 8259 interrupt controller". That emulation is a firmware matter (unknown) for option-card BIOSes only.

## What a model must do

- Thirty-entry Cobalt interrupt controller with the mask, level and vector fields, an enable bit, and one output to
  the local APICs; lines driven by the sources above.
- The Lithium bridges with an interrupt enable word each; a PCI device's INTx on each bridge reaches the line the
  table gives, gated by the enable bit (inferred that the gating is per bit, as the register's layout suggests).
- An ordinary 8259 pair behind the PIIX4 with poll and specific EOI, its output on line 12. IDE and USB on their own
  lines.
- The local APIC EOI is the only acknowledgment the controller needs; masking is by the entry.

## Unknown, and what would settle it

| Unknown | Route |
|---|---|
| Whether Cobalt tracks an in-service state per line | A boot log is no help; a PROM or HAL read, or the specification |
| The real wiring of bus B's shared pins and bridge B's lines 13 to 15 | The NT HAL's interrupt table (it routes them) |
| How 320 revision 5 services the 307 devices in 2.6 | A boot of 2.6 on a rev 5 board; the 2.4 map code |
| Lines 24 and 25, and the second source on line 28 | PROM, HAL |
| Who programs which entries at reset | PROM |
