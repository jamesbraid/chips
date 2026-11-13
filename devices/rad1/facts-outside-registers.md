# RAD1 audio ASIC: facts outside the register file

The register contract is [devices/rad1/registers.toml](registers.toml), published as
[devices/rad1/registers.md](registers.md), with each entry graded. This page keeps
the facts that are not register entries: where the part sits, what its PCI
configuration shows, how software reaches it, and what differs on the PCI
audio board (revision `0xd0`, board 13).

## Placement

- On Octane and Octane2 the onboard RAD is PCI `10a9:0005` at device 3,
  function 0, behind the onboard Bridge, with revision `0xc0` (board 12).
  **Established**, from a published OpenBSD/sgi boot transcript of an Octane,
  which prints the RAD1 line. That transcript shows no status or configuration
  words.
- The *OCTANE Technical Report* places built-in audio behind the Bridge. It says
  the baseline audio generates the shared media timeline clock and that RAD
  associates UST with media sample counts (PDF pages 58 to 60 and 65 to 66,
  printed pages 3-3 to 3-5 and 3-10 to 3-11). **Established** as to what the
  report says. The report gives neither the tick period nor any register
  behaviour.
- The PCI audio board is the same ASIC family on an add-in card. Where it sits
  is in the [board 13 section](#pci-digital-audio-board-revision-0xd0-board-13).

## PCI configuration

- The class code (config offset `0x08`, bits 31:8) reads zero. See
  `PCI_CLASS_OCTANE` in the register file. **Established**, from one public
  Linux `lspci` dump of the onboard RAD (linux-pci-list message
  `20170213224512.GA8080@bhelgaas-glaptop.roam.corp.google.com`, 2017-02-13).
- The same dump's Status word has FastB2B (bit 7) and DEVSEL slow (bits 10:9,
  value `10b`) set, and target abort signalled (bit 11). SERR, PERR and INTx are
  clear. **Established** for those bits in that dump. Bit 11 is a
  write-one-to-clear error bit, so the dump records a target abort that had
  happened, not a reset value. No public source gives a reset value or a
  post-firmware Status value for board 12. Both are **unknown**.

## Access and byte order

- The IP30 driver reads and writes the registers it uses (the counter at `0x30`
  and the enable stores at `0x40`, among others) with ordinary aligned 32-bit
  loads and stores, and does no byte swap of its own. **Established** from the
  IP30 `rad_dd.o` object.
- OpenBSD's Bridge code gives `10a9:0005` the native, non-swapping bus space tag,
  and its resource setup keeps the programmed-I/O swap bit the PROM left in
  place while it changes the DMA swap bits. **Established** as a public driver's
  choice (`sys/arch/sgi/xbow/xbridge.c` on the `sgi-is-alive-at-7.9` branch,
  lines 1138 to 1150 and 2445 to 2509). OpenBSD attaches no audio driver on the
  captured Octane, so the tag is a driver choice and not a read of the chip.
- The Bridge's rule for narrow and aligned accesses through a device window is in
  [bridge-family.md](../bridge/family.md). Whether the RAD itself maps each PCI
  byte to the same register byte is **unknown**.

## DMA request

- The IP30 driver's memory-to-PCI helper (`Mem_to_PCI_DMA`, `.text` `0x7268` to
  `0x72ac`) takes a physical buffer address, asks the PCI I/O layer for a DMA
  translation with flags `0x50`, and writes the returned PCI address into the
  descriptor's low and high words. **Established** from the IP30 `rad_dd.o`
  object. The Bridge decides the translation that actually applies (direct,
  ATE-translated or 64-bit), as [bridge-family.md](../bridge/family.md) describes.

## PCI Digital Audio Board (revision `0xd0`, board 13)

This is the add-in card the Tezro, Origin 350, Onyx 350, Onyx4 and O2 captures
report as `RAD revision 13.0`. It is a digital card: ADAT and AES3 in and out.
The register file covers the chip; the rows below are what differs for this card
or what the card's documents add.

### Identity and configuration

| Item | Value | Grade |
|---|---|---|
| PCI vendor and device | `10a9:0005` | **established** (driver registration, same as the other boards) |
| Revision byte | `0xd0`: board 13, chip revision 0 | **inferred** from the `13.0` hinv line; no capture shows the raw byte |
| hinv line | `Iris Audio Processor: version RAD revision 13.0, number 1` | **established** (captures) |
| Number with several cards | `number 2` and so on, by attach order; the audio panel names them `RAD 1`, `RAD 2` (board guide, pp. 11 and 14) | **inferred** |
| Driver class and type | inventory class 10, type 5 | **established** |
| Part numbers that report 13 | not recorded. The board guide covers 030-0950-001, 030-0950-002, 030-1649-001 and 030-1441-001 (Table 1-2, p. 8); no capture names its part | **unknown** |
| Class code | not recorded for the card. Do not carry the Octane's zero over as the card's value | **unknown** |
| Subsystem vendor and device | not recorded; `hinv` prints vendor and device only | **unknown** |
| Config Status half (bits 31:16) | not read on any board-13 card. The board-12 value `0x0480` is not this card's | **unknown** |
| BAR0 | 32-bit memory, at least `0x2000` bytes mapped by the driver (`BAR0_SIZE`); no other BAR, expansion ROM or capability is known | **inferred** size, **unknown** other BARs |
| Interrupt pin | not recorded | **unknown** |
| PCI priority and read-response buffers | priority 1 and two read-response buffers requested (board 12: priority 2 and three buffers) | **established** (driver) |

### Startup writes that differ from board 12

The register file lists every start value with its board. The writes that differ
for board 13 are:

- `0x4c` starts at `0x05000000` (board 12: `0x03000000`).
- `0x54` starts at `0` (board 12: `0x40000000`).
- `0x50` starts at `0x20000000` (board 12: `0x60000000`). The IP30 reading
  leaves this value unknown; see Not settled.
- `0x84`, `0x88`, `0x8c` and `0x90` are written `0` at start. Board 12 writes
  `0x8c` = 2, `0x90` = 2 and `0x88` = 3 at the end of start, and does not write
  `0x84`.
- No `0x40` write follows enable on board 13 in the IP27 and IP35 objects; see
  Not settled for the one conflicting reading.

**Established** from the driver objects. Almost none of these registers are read
back by the driver, so their readback behaviour is **unknown**.

### Analog and digital I/O

| Question | Answer | Grade |
|---|---|---|
| Connectors on the card | ADAT optical in and out; a DB15 breakout with AES-3id coaxial in and out and two video reference BNC loops; a feature connector that only Origin 200 servers use. No analog connector appears in the drawing, the specification table or the pinout table | **established** (board guide, pp. 2, 18, 19) |
| Analog interfaces on board 13 | the driver creates no analog input or analog output interface on board mode 13. The board-13 branch skips both, in the IP27 object and in the IP35 interface-creation routine | **established** |
| Analog channel registers on the die | types 0 and 1 have register blocks in the file. The ASIC is shared with the analog boards, so the registers are present on the die; the card has no analog circuit to drive | **inferred** |
| Digital-only card | consistent with the connectors and with the missing analog interfaces. The board guide cannot tie this to board 13 directly: its own hinv example (p. 11) reads 12.0 | **inferred** |
| Video reference and genlock | two BNC loops on the card; the driver measures video-field events through status slot bits | **established** (guide, driver) |

### Status DMA and descriptors

The status ring and the descriptor rules are the same on every board. Two
board-13 points the driver shows:

- After a one-shot start, the driver polls the completion word up to 100 times
  with 5 microsecond delays (`STATUS_ONESHOT_POLLS`, `STATUS_ONESHOT_POLL_US`).
  **Established**.
- The driver reads the other words of a status slot after it sees bit 31 of
  `+0x7c`, so the slot must be complete before that bit is visible. **Inferred**
  from the read order.
- Each status slot carries the current byte pointer of each channel at a fixed
  offset (`status_pointer_slot`: ADAT input `+0x00`, AES3 input `+0x08`, analog
  input `+0x10`, ADAT input subcode `+0x18`, AES3 input subcode `+0x20`, ADAT
  output `+0x28`, AES3 output `+0x30`, analog output `+0x38`). **Established**.
- The driver never stores a 64-bit field in DMA memory. A descriptor address is
  two 32-bit register writes. **Established** for the code the driver reaches.

### UST on board 13

- At load the driver does one 64-bit read of the Bedrock real-time clock control
  register (`0x604200` in the local block). It keeps a flag that is set when
  `(value & 0xf000) == 0x4000` (`UST_BEDROCK_FLAG_MASK`, `UST_BEDROCK_FLAG_VALUE`).
  **Established**. Bit 14 is undefined in the local block
  ([bedrock-local-block.md](../bedrock_lb/README.md)).
- The board-13 reset routine raises the interrupt level, then writes `0x40` with
  `6` and then `2` when the flag is set or the brick type is 55, 56, 57, 69 or 81.
  Otherwise it writes `4` and then `0`. It then stores a software UST offset.
  **Established**. The board-12 reset routine returns without a write.
- The tick period is set only in that reset routine. It is either 960 ns
  (`UST_TICK_NS_FIXED`) or `((register >> 4) & 0x3ff) * 10 + 10` from the Bedrock
  register; a field of 79 gives 800 ns. **Established** for both values. The
  condition that picks one is **unknown**.
- The position read path depends on the same flag and brick type. If the flag is
  set or the brick type is 55, 56, 69 or 81, the driver reads the 32-bit position
  register directly at `BAR0 + index*4 - 0x40`. Otherwise it uses the status-slot
  copy. **Established**. Which path a Fuel or Tezro takes is **unknown**.
- The driver derives a node and widget number from the BAR0 PIO address and calls
  an I/O-brick type lookup. What a Fuel or Tezro returns from that lookup, and what
  they hold at `0x604200`, is **unknown**.

### Interrupts and DMA

- The driver registers no interrupt. It imports PIO windows, DMA address
  translation and a PCI error handler. Completion and position are polled.
  **Established**.
- Unknown on this card: the byte order of sample words in memory, whether the
  card negotiates 64-bit data phases, and whether it drives dual-address cycles.
  The driver gives it two 32-bit address halves and nothing else about width.
- The driver polls the status word in memory and does not flush the bridge until
  stop. A status write therefore has to be visible without a flush.
  **Inferred** from the polling loop.

### Where the card sits

| Machine | Evidence | Grade |
|---|---|---|
| Tezro | `RAD revision 13.0` in 5 of 17 captures, each with a `MAD revision 1, number 1` line for the tower's onboard audio. The RAD is listed with the option-card buses, on the second PIC bus, not the IO9 bus | **established** (captures) |
| Origin 350, Onyx 350, Onyx4 | `RAD revision 13.0` in 3 of 12, 5 of 10 and 2 of 3 captures | **established** (captures) |
| Onyx 3000 | the system ships with one PCI Digital Audio Board in the I-Brick. The board guide (p. 8) excludes 030-0950-001 and 030-0950-002 from it | **established** (guide) |
| O2 | `RAD revision 13.0` as a PCI card in slot 3. Its analog audio is the onboard part, `A3 revision 0` | **established** (capture) |
| Origin 2000 | one capture with `RAD revision 13.0, number 2` in a PCI slot | **established** (capture) |
| Fuel | no RAD in any of 36 captures. 13 show a MAD (DM8) board | **established** (captures); whether a RAD works in a Fuel slot is **unknown** |

Analog RAD exists only as the Octane and Octane2 onboard part (board 12) and the
Onyx2 and Origin 2000 MediaIO daughtercard (board 7). A RAD on a Tezro, Origin 350
or Onyx 350 therefore never plays analog.

### Correction: the Tezro tower's onboard audio

[drivers.md](../../software/kernel/audio-drivers.md) and [survey.md](../../evidence/audio-survey.md) said the Tezro
tower's onboard audio was probably a RAD at board 13. That is withdrawn. Review of
the published Tezro hinv records (11 single-module records from 10 captures that
list adapter IDs and carry an IO9) finds the tower's onboard audio is the ICE1724
(`1412:1724`, see [dm8.md](../dm8/README.md)). It sits behind a TI PCI2050 bridge
(`104c:ac28`) with the IO9 bus devices, and `hinv` prints `MAD revision 1, number 1`
for it. The RAD 13.0 seen on Tezro is an optional PCI card. The ICE1724's place
behind the bridge is **inferred** from listing order alone. The raw captures were
not re-read for this update, so the ICE1724 placement stays **inferred** until a
capture settles it.

## Not settled

- **The `0x40` writes on board 13.** The IP30 object's board 7 and board 13 `4`
  then `0` writes are attributed to the enable routine in the register file,
  `rad_enable_ust`. A second reading of the same object places them in the reset
  routine instead, and says the board 12 reset routine writes nothing to `0x40`.
  A second reading of the IP35 object agrees on the reset routine and gives the
  flag and brick-type conditions above, and it finds no `0x40` write on board 13
  enable. That is a different build, so the attribution in `devices/rad1/registers.toml` stays
  until the IP30 routines are read again. The IP35 reading was taken from an
  earlier record and was not re-read for this page.
- **The `0x50` start value on board 13.** The register file says the driver leaves
  an unknown earlier value. The second reading of the IP27 and IP35 objects finds
  `0x20000000` written. Whether the IP30 object differs or the two readings disagree
  on the same routine has not been settled.
- **Halt on board 13.** The second reading of the IP27 object finds no write to
  `0x70` or `0x88` at halt on board 13. The IP35 reading is inferred to match. The
  halt writes in the register file are not qualified by board, so they conflict
  for board 13.
- Which part numbers report board 13.
- The Status half of config `0x04` on any board-13 card.
- The condition that chooses the 960 ns or the computed tick period, and what
  `0x604200` holds on a Fuel or Tezro.
- Bit 14 of the Bedrock register, and the meaning of the bits written to `0x40`.
- Byte order, data-phase width and dual-address cycles on the card's DMA side.
- The PCI class code, subsystem IDs and interrupt pin of the card.
- Whether a RAD runs in a Fuel.

Settling any of these needs a card document, a PCI-side capture on a machine that
carries the card, or a read of the IP30 routines named above. A register capture
from a running IP35 machine is a physical test and needs agreement first.

## Sources

- IRIX 6.5.30 IP35 `rad_dd.o`, SHA-256
  `e19248075cd2bb245f722f6b10792db5629f199eb71b7276eae87ecaec5438fc`. The board-13
  rows above come from an earlier record of this object. They were not re-read
  for this page, and the routine offsets are not repeated here.
- SGI, *PCI Digital Audio Board Installation Guide*, 007-3502-003 (2000). Page
  numbers are printed pages.
- Published hinv captures, counted in [drivers.md](../../software/kernel/audio-drivers.md).
