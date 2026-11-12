# TI TSB12LV22 PCI-to-IEEE 1394 link controller

The TSB12LV22 is Texas Instruments' PCI-to-1394 link controller. It implements the IEEE 1394 OHCI 1.00 register interface and carries PCI identity `104c:8009`, revision `01`. On the Origin 3000 and Onyx 3000 I-brick it sits on the IO7 board's head F as PCI device 6. Its register and identity constants are in [gen/docs/tsb12lv22.md](../gen/docs/tsb12lv22.md), generated from [defs/tsb12lv22.toml](../defs/tsb12lv22.toml). Each item there carries its grade and its source.

This page holds what the register table cannot: the product boundary, PCI configuration, reset rules, interrupt rules, what the datasheet leaves open, and what the shipped I-brick PROM and IRIX driver expect of the part.

## What the contract rests on

The main source is the TI datasheet *TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller*, SLLS290, July 1998. Page references below are to that publication. This import did not re-read the datasheet PDF; the page numbers and facts come from the earlier review of it, so each fact carries the reviewed page reference.

The IEEE 1394 Open Host Controller Interface Specification, Release 1.1 (6 January 2000) is cited only where it says something about OHCI in general. Its 1.1-only requirements do not fill a 1.00 gap, so each such fact is marked inferred for this part.

Shipped code is cited as software expectation only. That means the I-brick PROM 1394 probe and the IRIX 1394 driver, read from disassembly. A driver's expectation is not a measurement of the part.

The Linux `drivers/firewire` code corroborates the software interface and the GUID reset behaviour.

## Product boundary

The part is a PCI-to-1394 link controller. It supports 100, 200 and 400 Mbit/s. It needs a separate PHY, which supplies the 49.152 MHz clock and takes part in PHY and link ownership, register transfers and bus initialization (established, TI pp. 1, 6).

The registers are memory mapped and nonprefetchable (established, TI p. 1). The serial ROM is optional. The SDA pin is held low to show that no ROM is fitted (established, TI p. 6). An optional external 8 kHz input controls cycle synchronization (established, TI p. 6).

No PHY, port count, cable topology, GUID, subsystem identity or EEPROM image is fixed by the datasheet. A test configuration has to state those choices. A full controller also needs a PHY and bus contract and working DMA. Register probe values alone do not establish a working controller.

On the I-brick, the PHY part is unknown. Neither the PROM nor IRIX reads a PHY identity register, and no source held here names the part. A TI TSB41LV0x-series PHY is plausible on vendor grounds, but nothing here supports it (unknown).

## PCI configuration

BAR 1 is at configuration offset `0x14`. The datasheet says it is the base of memory-mapped TI extension registers and takes its field details from BAR 0 (established, TI p. 11). No extension register is documented, and the size of 2 KiB is inferred from a cross-reference. Its contents are unknown.

The BAR sizing text on TI p. 11 calls bits 31:11 "upper 20 bits". That range has 21 bits. The mask and the range agree with each other, so the mask is taken as the coherent address representation. The conflict is an editorial error in the datasheet and stays visible in review.

The datasheet's PCI table does not define the byte-level behaviour of the reserved configuration range `4c` to `f2`. Treatment of the bytes between named fields, and of PCI byte enables, needs the original interface specifications. A writable mask here does not establish an access-width rule.

For 1394a acceleration, the datasheet requires both enab_accel (PCI configuration `f4` bit 1) and aPhyEnhanceEnable (HCControl bit 22) to be set (established, TI p. 15). A serial EEPROM can preset `f4`. Whether an I-brick board uses that is unknown.

## Reset

The reset domains, as the datasheet gives them. `X` in a published reset diagram is an unspecified value, not a physical zero.

| Reset domain | Established effect | Still open | TI pages |
|---|---|---|---|
| Hardware and PCI reset | The published reset diagrams apply. An optional serial ROM loads the identity and bus-information fields it specifies | Exact timing, and which externally sampled inputs change at each reset | 6–7, 11–12, 20, 23 |
| Controller SoftReset | Flushes FIFOs, resets controller state and OHCI registers to hardware values unless an exception applies. PCI registers are not affected. HCControl bit 16 stays set during reset and clears on completion | Completion latency, reset of fields the datasheet leaves undefined, and persistence exceptions | 25, table 30 |
| SoftReset exception | BusOptions max_rec survives. Its hardware default is 2048 bytes (max_rec 10) | Other BusOptions fields have unspecified reset bits. Bit 27 is writable and resets to zero | 22–23, table 26 |
| D3hot to D0 | An internally generated reset leaves PM control and status unaffected | Remaining scope and timing of this reset, and the effect of writes to unsupported power states | 14 |
| 1394 bus reset | Clears NodeID validity and updates the self-ID generation. Sets the bus-reset event and turns off self-ID-complete | The PHY and bus state machine, and every field they affect, need the PHY and 1.00 contracts | 26, 28, 32 |

The datasheet's PM control and status bits 1:0 are read and write, and the datasheet does not say what a write does beyond that (unknown). Cycle timer, posted-write error address, NodeID validity and self-ID count are read and updated by the controller. Their update conditions in response to bus events are not specified here.

## Interrupts

The defined interrupt event bits are 26 to 19, 17 to 16 and 9 to 0. Bit 30 is vendor-defined and its meaning is not given (unknown). Bits 7 and 6 are derived summaries, not independent latches (established, TI pp. 27–29, tables 34–35):

- Bit 7 is the OR of the isochronous receive event and mask.
- Bit 6 is the OR of the isochronous transmit event and mask.
- Software writes to the summary positions have no effect.

The other named events are latched. Source edges and software writes to IntEventSet can set them.

- Reads of IntEventClear return IntEvent AND IntMask. Reads of either mask address return IntMask (established, TI pp. 27–29).
- Mask bit 31 enables external interrupt delivery on INTA, together with the enabled pending sources. INTA follows the pin table (established, TI pp. 12, 28–29).
- Pending event state stays separate from the mask. The interrupt output must be recomputed when the mask changes (established, TI pp. 17, 27–30).
- A bus reset sets busReset and turns off self-ID-complete at the same time (established, TI p. 28).
- A fatal context error sets unrecoverableError. Normal interrupts for the responsible contexts are blocked while that event stays set (established, TI p. 27).
- A cycle-too-long event clears cycleMaster, and cycleMaster cannot be set again until the event is cleared (established, TI pp. 27, 31).

The datasheet says in one place that event bits clear only by software. That conflicts with its explicit bus-reset effect. The specific effect is recorded above, and the general statement is not used.

The bit numbers for busReset (17), selfIDComplete (16) and the PHY-register-received event (19) come from the shipped PROM and IRIX code. They are inferred. Bit 18 is undefined for OHCI 1.00 and must read as zero, which the IRIX driver checks (inferred). The bit numbers for unrecoverableError and cycle-too-long are not given in the datasheet summary held here (unknown).

## Link and PHY rules

LPS (HCControl bit 19) must be set before any PHY or link communication (established, TI p. 25). Clearing linkEnable disconnects the controller at once: no packet is received, processed or sent. Software sets linkEnable when it is ready and then forces a bus reset (established, TI p. 25). Write-posting enable can change only while linkEnable is zero (established, TI p. 25).

PHY read and PHY write commands are mutually exclusive. Receiving a PHY transfer sets rdDone and raises the PHY-register-received event (established, TI pp. 27, 32). Timing, and the behaviour with no PHY attached, are unknown.

PHY completion, node-ID validity and self-ID-complete depend on PHY and bus operation that this unit does not describe. Their register values are not evidence of a live bus.

## Not in the datasheet

These are unknown and block any claim beyond the register stage:

- DMA. The datasheet summary has no descriptor formats, command or event encodings, branching rules, transfer status, residual counts, completion timing, data ordering, bus retry behaviour or PCI error mapping. The context register offsets are not in the summary either. No DMA or completion behaviour is established here.
- Isochronous receive context count. The defined event and mask bits are 3 to 0, so four contexts are inferred, not stated.
- Cycle scheduling, channel and tag matching, and bus operation.
- SBP-2. The datasheet does not specify it. A storage target needs its own public contract for discovery, login, request chains, status and reset.
- Attached PHY behaviour, EEPROM contents and the I-brick's interrupt wiring.

## Shipped software expectations

This section records what the shipped I-brick PROM 1394 probe and the IRIX 1394 driver do with the controller. The probe and driver code was read from disassembly. Under the rule for shipped code, these readings are software expectations, so they are graded inferred. The disassembly image addresses for these readings are not recorded in this import, so the citations are incomplete until they are added.

### PROM probe

The probe runs without interrupts. It never sets masterIntEnable and polls the masked event view instead.

Its register writes, in order:

1. HCControlSet `0x00080000` (LPS). Then BusOptions `0xe064a002`, the self-ID buffer pointer, LinkControlSet `0x00100600` (cycle timer enable, receive self-ID, receive PHY packets), and HCControlSet `0x400e0000` (no byte swap of data, LPS, posted-write enable, linkEnable). It writes the configuration ROM header and map, builds descriptor rings for two asynchronous receive contexts, writes their command pointers and sets run. It writes no programPhyEnable or PHY-enhancement bit.
2. IntMaskSet `0x03aa03f3`. The mask includes busReset. It does not include selfIDComplete or masterIntEnable.
3. It reads GUID high and low and prints a banner.
4. It fills the 2 KiB self-ID buffer with the pattern `0xdeadbeef`, to tell a fresh write from stale data.
5. It starts a bus reset with one PHY write, PhyControl `0x0000417f` (write register 1, data `0x7f`: initiate bus reset, gap count 63). It polls wrReg until it clears, ten polls in all. On timeout it logs a message and carries on.
6. It polls the masked event view until the attach finishes or a bound expires. While the masked view reads nonzero it writes IntEventClear with the bits it saw, except busReset and selfIDComplete, which their own handlers clear.

It reads no PHY register. Its only PhyControl write is the register 1 write above.

The waits, with their bounds:

- PHY write: wrReg reads zero. Ten polls, then it logs and continues.
- Event drain: no bound. A masked event that stays set holds the probe in this loop.
- busReset clear after writing `0x00020000` to IntEventClear, and selfIDComplete clear after writing `0x00010000`: each waits on the raw bit with no bound. A raw bit that stays set after the write holds the probe forever.
- Self-ID data valid: the error bit clear, the generation in the buffer header matching SelfIDCount, the last buffer quadlet no longer `0xdeadbeef`, and busReset not set again. Up to about 16 reads, then another bus reset, at most four retries.
- Self-ID packets: each packet has bits 31:30 as `10`, and each inverse XORs to all ones. Port connections form a tree. If the root bit is set, the last packet's PHY ID equals the node number.
- Attach phases: 15 time-of-day seconds per phase, or 60 when a driver variable equals 10 (meaning unknown).

A timeout is the expected end state for a link with no PHY. The PROM logs a failure and returns success, so boot continues.

The bus-reset handler reads NodeID first, taking the root bit and the node number. It does not test idValid. It then writes LinkControlSet cycleMaster if the node is root, otherwise LinkControlClear for that bit.

With two or more nodes, phase 2 reads remote configuration ROMs, which requires asynchronous transmit and receive. That path was not read in full (inferred).

### Time-of-day clock

Both attach bounds, and the 5-second self-ID wait, count seconds from a time-of-day clock, not from the hub counter. The clock is on the IOC3 external bus. The layout that applies on an I-brick is part of the IOC3 and PROM clock reader, and is outside this page.

### BAR placement

The CPU PROM sets up each device window. For the TSB12LV22's PCI identity it writes the window base into both BAR0 and BAR1 without sizing either one (established, CPU PROM code read in full for this path). The I/O PROM 1394 code then reaches the OHCI registers at offset 0 of the device window and never reads either BAR (established for the attach path).

On a real I-brick the OHCI registers are expected to answer at the shared base. That follows from the shipped PROM driving the controller only there, and from published inventories that show the controller working under IRIX (inferred). The PCI rule for overlapping BARs gives undefined results, and nothing here says which decoder answers. The datasheet's extension decode is not documented, so this stays open until a datasheet or a PROM console that shows a 1394 probe succeeding on an I-brick settles it.

### Byte order of the self-ID buffer

OHCI 1.1 says the noByteSwapData control does not swap self-ID quadlets, because PHY packet data is not byte-swapped (1.1 sections 1.6 and 5.7.1). That is established for 1.1 only. For the 1.00 part it is inferred. Linux reads the self-ID buffer as little-endian quadlets, and the controller writes each quadlet as one 32-bit PCI value (inferred).

The PROM sets noByteSwapData, copies the buffer with a plain byte copy and reads each quadlet as a big-endian 32-bit value. Its checks pass only if each quadlet reaches memory as its numeric value. Whether the direct-DMA swap bit on the device register is set for device 6 is unknown.

### IRIX 1394 driver

The IRIX driver is interrupt driven. Its mask is the PROM's mask plus masterIntEnable (`0x83aa03f3`). It needs INTA to reach the CPU.

For this PCI identity it starts a bus reset at once with PhyControl `0x000041ff` (write register 1, data `0xff`: force root, initiate reset, gap count 63). It first checks that IntEvent bit 18 is clear, and fails the write if it is set. Bit 18 is undefined for this part, so it must read zero (inferred).

It then reads PHY register 1 back. It clears IntEvent bit 19, writes PhyControl `0x00008100` (read register 1), and within ten clock ticks needs rdReg clear, bit 18 still clear, and rdDone set with rdAddr equal to 1. It takes rdData from the register and clears bit 19. A timeout fails the attach with a bus-reset error.

So IRIX needs PHY register read completion, which the PROM does not. Whether IRIX tests the returned value is unknown. Its wait loops use a kernel timeout per wait, 250 ticks with at most six waits (inferred from the loop shape).

The driver writes only PHY register 1. Register 1 has the root-holdoff bit (bit 7), the initiate-bus-reset bit (bit 6) and the gap count (bits 5:0). Bit names follow the Linux `core.h` definitions (inferred).

### hinv inventory line

IRIX prints `Version 0 0` for this controller. The driver adds an inventory record for the IEEE 1394 class with type 0, unit 0, and a state equal to the PCI revision byte. The `%s` in the printed line is a fixed `0` whenever the state is nonzero. The revision here is `01`, so the printed line is `Version 0 0`. The source's hinv string-selection rule for state 1 is ambiguous, so this mechanism is inferred, not established. Neither the Version register nor the GUID ROM produces the line.

## Unknown

- The PHY part on the I-brick, and whether the board uses 1394a acceleration.
- Reset values of most registers, which the datasheet leaves unspecified.
- DMA, cycle scheduling, SBP-2 and every PHY or bus behaviour beyond the register stage.
- The I-brick's topology beyond what the inventories show: the controller and an internal CD-ROM, but no PHY.
- The image addresses for the PROM and IRIX readings above, which are needed to complete their citations.
