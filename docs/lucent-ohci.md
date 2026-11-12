# AT&T/Lucent 11C1:5802 two-port OHCI USB host controller

The part is a two-port USB host controller with an OpenHCI register interface, PCI vendor `0x11c1`, device `0x5802`.
The public IRIX hardware inventory of an Origin 300 IO-8 lists it at PCI device 5 and names its interface as OHCI.
Its register and identity constants are in [gen/docs/lucent_ohci.md](../gen/docs/lucent_ohci.md), generated from
[defs/lucent_ohci.toml](../defs/lucent_ohci.toml). Each item there carries its grade and its source.

## What the contract rests on

Three kinds of source are held. The OpenHCI 1.0a specification gives the driver-visible behaviour and the reset values the
specification states. The Lucent USS-312 datasheet gives the PCI configuration values and the low-speed threshold reset.
The IO-8 board test in the stock PROM diagnostics gives what the board's own check requires of the registers. The board
test is a software expectation. It shows what the diagnostic demands, not what the part does, so every fact taken only
from it is inferred.

The OpenHCI register offsets used here are the word indexes the board test names in its messages, multiplied by four.
This import did not re-read the OpenHCI register-map page itself. The offsets are therefore graded inferred.

## Identity and PCI configuration

The vendor and device IDs come from the public hinv capture. The subsystem vendor and ID, Min_Gnt and Max_Lat come from
the USS-312 datasheet. The datasheet makes the subsystem fields read-only unless system firmware opens them through
configuration register `0x4C`. Whether the IO-8 firmware does so is unknown, so the fitted part's subsystem identity is
not confirmed. The same applies to the BAR size as reported by this function, which no source held here states.

The exact reset word of the PCI Command and Status registers is unknown. No source held here records it. A raw
configuration-space read of the function just after PCI reset would settle it.

## Operational registers

- **Interrupt enable.** The IO-8 board test requires it to read zero after a host-controller reset issued through the
  command register. That is a software expectation. The test's mask table narrows the masks of four fields, and which
  bits the part keeps there is unknown.
- **Frame interval.** The specification gives the frame interval field and the toggle the reset values `0x2edf` and zero.
  It marks the largest data packet size field TBD, leaving it to the part. The board test requires that field to read
  zero after a reset, so the whole word's reset is not established.
- **Frame number.** The specification makes this register read-only to the driver, written only by the controller, with
  reset zero. The board test writes `0xffff` to it while the controller is not operational and again during a USB reset,
  and requires the read-back under mask `0x0000ffff`. The board test's register table gives the full 16-bit field that
  mask. Neither the specification nor the test says what a driver write does. Whether the part keeps a driver write
  while not operational is therefore an inference from the test, and what the part does with a write while operational
  is unknown.
- **Root hub descriptor A.** The specification makes the power-switching and over-current fields, and the
  power-on-to-power-good time, driver-written. The board test writes zero and reads them back under mask `0x03001b00`.
  The power-on value is in the USS-312 datasheet; it is not copied into this import.
- **Root hub descriptor B.** The device-removable and port-power-control fields are driver-written, one bit per port
  starting at bit 1 of each half. A hardware reset does not reset the root hub, per the specification. The board
  test's USBRESET check requires the port bits to survive a USBRESET followed by a controller reset. The specification's
  prose points the other way for USBRESET, though its reset column permits keeping the fields. Survival through USBRESET
  is therefore inferred from the test alone.

## Root-hub port power

After a USBRESET, a controller reset and a move to USBOPERATIONAL, the board test waits 20 ms and requires both port
status registers to read zero. It then writes `0x00060000` to root hub descriptor B, which masks both ports for per-port
power control, and `0x00000100` to root hub descriptor A, which selects per-port power switching. It switches each port
off and on with clear and set port power commands 400 ms apart and checks each one powered and the other not. It ends
with a USBRESET and a controller reset and requires both ports unpowered. This sequence is read from the disassembly
of the board test, not traced. Every step is inferred as a software expectation.

## Published diagnostics

The Online Diagnostics manual, document 108-0286-007, describes the `olusb` host-controller test for IP45. Its default
check runs register read and write tests and prints `RSLT olusb PASS` or `FAIL`. The optional inventory probe enumerates
attached devices and reports nonresponsive devices and hub ports that supply no power. The manual does not name every
register it tests, so the register set is not confirmed by it.

The IO-8 board test manual, which the source material refers to without a document number, selects sections for the PCI
configuration and reset checks, the USB section and a concurrent run of all IO-8 activity. Its device mask selects USB as
device 5. A skipped section, a timeout or a missing attachment is not a pass. The USB section's expected values are not in
any published document, so they are held here only as the inferred expectations above.

## Not known

- The reset word of the PCI Command and Status registers.
- Whether the IO-8 firmware writes the subsystem identity fields, and the subsystem values a fitted part reports.
- The BAR size this function reports.
- The reset value of the largest data packet field in the frame interval register.
- What a driver write to the frame number register does while the controller is operational.
- Which bits of the four fields the board test's narrower masks cover the part keeps.
- Whether USBRESET keeps the root hub descriptor B port bits, which the specification's prose argues against.
- The power-on value of root hub descriptor A.
- Whether the Fuel system board carries this part too, as one source states. No capture held here shows it.
- Whether the two-port count holds on every board that carries the part.
