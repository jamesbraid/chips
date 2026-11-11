# Bridge, Xbridge and PIC as Crosstalk widgets

Three different SGI ASICs turn a Crosstalk (XIO) widget port into PCI. They share a programming model, a driver and
most of a register map, which is why they get confused. They are not one chip at three revisions:

| chip | what it is | machines | widget part / manufacturer |
|---|---|---|---|
| **Bridge** | one PCI (or GIO) bus, 8 device slots, one widget | Octane (IP30); Origin 200 (IP29 board); Origin 2000 and Onyx2 XIO boards (BaseIO, IO6 family); GIGAchannel and Crosstalk PCI option boards | `0xc002`, manufacturer 54 (`0x36`) |
| **Xbridge** | Origin 300 I/O bridge; one chip with two Bridge-like PCI sections and a crossbar section inside | Origin 300 and Onyx 300 (IP45 board); Origin 3000 P-brick and X-brick (SGI's L1 text also names the I-brick as carrying one); not shown here: OpenBSD says later Origin 200/2000 boards used it too (I, no capture) and calls Fuel "Origin 300 like", but Fuel is a different board (IP34) and no Xbridge capture of it is recorded. The list is what the manuals and captures show, not a proven-complete census | `0xd002`, manufacturer 36 (`0x24`) |
| **PIC** (PCI interface chip) | PCI-X bridge, two PCI-X buses (heads), 4 device slots each | Origin 350 / Onyx 350 / Tezro (IP53 class); IX-brick and PX-brick | `0xd102` (head 0) and `0xd112` (head 1's register set), manufacturer 36 (`0x24`) |

Names, with where each comes from (the naming audit is [interconnect-naming.md](interconnect-naming.md)):

- **Bridge**: SGI hardware term. *Origin and Onyx2 Theory of Operations* (007-3439-002), printed p86, "Bridge ASIC": it
  converts the XIO link to the PCI bus protocol and adds address mapping, interrupt control, read prefetching and
  write-gathering; peak 800 MB/s on the XIO link and 266 MB/s on PCI; one on every I/O widget board.
- **Xbridge**: SGI hardware term, spelled "Xbridge" in the *SGI Origin 300 Server* guide (007-4365-002), printed p10
  ("the interface between the Bedrock ASIC and the PCI slots"), and in the *Origin 3000 Series* guide (007-4240-002),
  printed p140 ("Three Xbridge ASICs interface between two Crosstown2 ports and the PCI cards", P-brick).
- **PIC**: SGI hardware term, "PCI interface chip", in 007-4377-001: printed p67 for the IX-brick, p78 for the PX-brick. Both bricks carry three PICs, which together give two
  Xtown2 XIO ports (800 or 1200 MB/s) and six PCI-X buses of two slots each. SGI's Origin 300 guides call the Origin
  300 chip Xbridge, so "PIC" does not mean "Xbridge".
- Part-number tables in the public drivers call the three `BRIDGE` (`0xc002`), `XBRIDGE` (`0xd002`) and `PIC`
  (`0xd102`): OpenBSD `sys/arch/sgi/xbow/xbowdevs`. Mainline Linux (`arch/mips/include/asm/pci/bridge.h` and
  `xtalk/xwidget.h`) lists only `0xc002` and `0xd002`. The out-of-tree IP35 Linux tree
  (`arch/mips/sgi-ip35/ip35-xtalk.c`) defines `0xd102` as `PIC_BRIDGE_WIDGET_PART_NUM` with the comment "Xbridge(?)", so
  its author guessed Xbridge. OpenBSD's `xbowdevs` comment is the better statement: PIC is one chip with two widget
  register sets, and the second set reports `0xd112`.

Grades: **E** established (code read in full, a published manual page, or a captured value), **I** inferred, **U**
unknown. Every unknown names the test that would settle it.

## Sources used

- IRIX 6.5.30 kernel objects (the shipped `unix` for IP27 and IP30 and the IP35 bridge-driver objects), the
  IP27, IP30 and IP35 PROMs: read through the chips repo's per-chip pages, [chips/bridge/README.md](../chips/bridge/README.md)
  and [chips/pic/README.md](../chips/pic/README.md), and the routine notes
  [ip27-kernel-bridge-routines.md](ip27-kernel-bridge-routines.md) and
  [ip30-kernel-bridge-routines.md](ip30-kernel-bridge-routines.md). Binary offsets below are those pages'.
  The IRIX source tree was not read for this page. This page names registers and fields only in its own words or with
  a name that a manual or a public Linux or OpenBSD driver also uses; kernel symbol and PROM string names are not
  reproduced.
- Public drivers: Linux `arch/mips/include/asm/pci/bridge.h`, `arch/mips/pci/pci-xtalk-bridge.c`,
  `arch/mips/include/asm/xtalk/xwidget.h`, and the IP35 tree (`arch/mips/include/asm/sn/pic.h`,
  `arch/ia64/include/asm/sn/pic.h`, `pcibr_provider.h`, `arch/ia64/sn/pci/pcibr/`); OpenBSD
  `sys/arch/sgi/xbow/xbridgereg.h` and `xbridge.c`.
- SGI manuals: 007-3439-002 p86; 007-4365-002 p10; 007-4240-002 p140; 007-4377-001 p67 and p78.
- Project datasheets (cleared reviews and captures): bridge, xbridge, pic. They carry the Bridge, Xbridge and PIC
  specification page citations; the specifications are marked proprietary and their clearance is under audit, so a
  claim below that rests only on them says so.
- Public `hinv` captures (project boot-log archive and the datasheets' captured-population tables) for revisions.

## Common to all three: a Crosstalk widget

Each chip presents the standard Crosstalk widget register block at the bottom of its 16 MB register face, then its own
registers, then the PCI windows. The common block is described once in [crosstalk-link.md](crosstalk-link.md); the
facts that matter for these chips:

- **Identification word (E).** Revision in bits 31:28, part number 27:12, manufacturer 11:1, bit 0 reads 1 on the
  parts whose specification states it (Xbridge; PIC inferred, see below). Linux `xwidget.h`: `WIDGET_REV_NUM`
  `0xf0000000`, `WIDGET_PART_NUM` `0x0ffff000`. The IRIX accessors read the word at offset 4 (the low word of the
  big-endian doubleword) and isolate those fields. Decoded words (computed from the fields, Bridge rev 4 shown): Bridge
  `0x4c00206d`; Xbridge rev 2 `0x2d002049`; PIC rev 3 `0x3d102049`. Bit 0 for PIC is **I**: the IP35 PROM refuses a
  word with bit 0 clear, and real machines pass, but no document states the physical value.
- **Machine placement.** The widget number is a machine property, not a chip property (E from `hinv` captures): Octane
  Bridge at widget 15 (HEART is widget 8; an optional PCI module carries a second Bridge on Crossbow port 13);
  Origin 200 Bridge at widget 8 with the Hub as master (widget `0xa`); Origin 300 Xbridge heads at widgets 14 and 15;
  Origin 350 PIC at widget 15 (a four-processor Tezro also at 11).
- **Registers shared by the three** (offsets are 8-byte slots; widths differ, see below). Roles are from the accessor
  and field names of the IRIX driver plus the public headers.

| slot | name (public / kernel accessor) | notes | grade |
|---|---|---|---|
| `0x00` | widget identification | above | E |
| `0x08` | widget status | Bridge: bit 5 set means PCI mode (IRIX refuses a Bridge part that reports GIO), bit 6 flash select, bits 4:0 pending reads. Xbridge: bits 15:12 and 11:8 credits, 7:0 input pins. PIC: PCI-X mode bit 33, PCI-X speed bits 35:34 (OpenBSD). | E for each chip's fields where named; the fields move between chips |
| `0x10` / `0x18` | widget error address, upper / lower | 48-bit crosstalk address of the first error; PIC reads as one 64-bit register | I |
| `0x20` | widget control | page size bit 21 (4 KB vs 16 KB translation pages), flash write enable bit 31, PCI reset pins 27:24, SSRAM size 18:17 (Bridge only); I/O and memory byte-swap bits 23 and 22 (OpenBSD); a crossbar credit field 15:12 and an outstanding-transaction limit 8:4 (PROM field table, Bridge specification transcription). Bits 5:4 are the PCI speed on Xbridge and on PIC outside PCI-X mode (OpenBSD); on Bridge they fall inside the transaction-limit field, so they are not a speed field there. PIC adds no-snoop bit 62 and relaxed-ordering bit 61 and fields at 55:48 and 47:40 (IRIX attach writes a caller-supplied value into 55:48 after clearing both; roles U). | E for the bits named; reset values U |
| `0x28` | request timeout | IRIX writes `0x750` on PIC revision 1 only | E (that write), I (role) |
| `0x30` / `0x38` | interrupt destination, upper / lower | target widget plus address of the chip's own error interrupt, see interrupts | E |
| `0x40` | error command word | decoded by the PROM into destination and source identifiers, packet type, transaction number and attribute and error flags | I |
| `0x48` | LLP configuration | link-level protocol configuration | I |
| `0x50` | target flush | read after posted register writes to force them out | E (use), I (name) |
| `0x58` | auxiliary error command word | link-side error | I |
| `0x60` / `0x68` | response buffer error, upper / lower | device number 22:20, buffer number 19:16, address | E |
| `0x70` | test pin control | no shipped software touches it | U |
| `0x78` | link-side error address | PIC (read-only by accessor); the IP35 PROM diagnostic, which runs one sequence for PIC and Bridge, writes the word at `0x7c` | I |

The device-side registers (`0x80` direct map, `0x90` map fault or SSRAM parity, `0xa0` arbitration, `0xb0` Number In A
Can, `0xc0` bus timeout, `0xc8` type-1 configuration counter, `0xd0`/`0xd8` PCI error address, `0x100` to `0x1c8`
interrupt block, `0x200`+8n device, `0x240`+8n write-buffer flush, `0x280`/`0x288` response buffers, `0x290`/`0x298`
response status and clear) exist at the same offsets in all three chips. The row-by-row grades are in the two
chips pages and the generated headers [include/bridge.h](../include/bridge.h), [include/xbridge.h](../include/xbridge.h)
and [include/pic.h](../include/pic.h).

## How software tells them apart

IRIX serves all three with one set of register accessor routines. A caller passes either a pointer into the 64-bit
uncached window (the routine reads the identification word and chooses by part and manufacturer) or the driver's
per-chip record, which holds a chip-type value that separates Bridge, Xbridge, PIC and a fourth part (identification
`0xe000`/`0xe010`) that is outside this page. E, from the IP27 `unix` and the IP35 PIC attach code, which records the
PIC type after it accepts `0xd102`/`0xd112`.

What the attach routines record about each chip (E, from the IP27 `unix` and the IP35 PIC attach code):

| | Bridge | Xbridge | PIC |
|---|---|---|---|
| internal translation entries | 128 | 1024 | 1024 |
| external translation RAM | probed (sizes of 8192, 16384 or 65536 entries) | none | none |
| revision gates in attach | `0xc0022`/`0xc0023`/`0xc0024` (revisions 2, 3, 4) | none (every Xbridge compares above all three) | revision 1 special-cased; accepted `0xd102`/`0xd112` at revisions 1, 2, 3 |
| register access | one 32-bit word at slot +4 | same | 64-bit at the slot address |

IRIX registers its Bridge-family driver for both `0xd002` (manufacturer 36) and `0xc002` (manufacturer 54); the PIC
driver registers for `0xd102` with manufacturer 36 only (E, driver initialisation in the IP27 and IP35 objects).
Octane, Origin 200 and Origin 2000 run the first; the Origin 350 runs the second.

## Bridge

- **What.** A Crosstalk widget with one PCI bus of 8 device slots, eight interrupt pins, a 128-entry internal address
  translation RAM, an optional external SSRAM translation RAM (up to 64 K entries, sized by an IRIX probe, E), and a
  one-wire Number In A Can at `0xb0`. The same die can run the bus in GIO mode (status bit 5 clear); IRIX refuses that
  (E). It is the chip of the Octane, the Origin 200 IP29 board and the Origin 2000 / Onyx2 XIO I/O boards.
- **Revisions (E for the numbers; letters I).** Linux `bridge.h` names revisions A to D as 1 to 4
  (`BRIDGE_REV_A`..`BRIDGE_REV_D`). IRIX tests `revision | part << 4` against `0xc0022`, `0xc0023` and `0xc0024`.
  Captured `hinv` lines (public captures, listed in the project bridge datasheet): Octane Bridge rev 3 at widget 15,
  Origin 200 Bridge rev 4 at widget 8, other Origin 200/2000 boards rev 2 to 4.
  - Below rev 4 the PCI I/O space window is unusable (OpenBSD `xbridge.c`: a hardware issue in the byte-swap logic).
  - Attach clears the PCI retry count field of the bus-timeout register (bits 9:0) below rev 4 (E).
  - Below rev 3 interrupt-enable bit 28 is left clear; on exactly rev 2 the receiver check-bit error (bit 20) is armed
    and further bits are left disabled (I: the revision gates and the retry-count clear were read in full, the exact bit
    list for revision 2 was not re-checked; the reasons are U, probably errata, test below).
- **Register block.** 32-bit words at slot +4 (E: Linux `bridge_t` places each register at slot +4; every IRIX
  routine uses `lw`/`sw`; only the two translation arrays use 64-bit accesses).
- **PCI side.** Type-0 configuration at `0x20000` (4 KB per device, 256 B per function), type-1 at `0x28000`,
  interrupt acknowledge at `0x30000` (8 bytes, no shipped driver uses it, I), external translation RAM at `0x80000`,
  per-device windows from `0x200000` (devices 0 and 1: 2 MB each; devices 2 to 7: 1 MB each, steps of 1 MB), external
  flash at `0xc00000`. PCI memory space reaches 1 GB at crosstalk offset `0x4000_0000`; PCI I/O at `0x1_0000_0000` (OpenBSD
  `xbridgereg.h`).
- **Device register** (`0x200`+8n): write gathering for translated and direct DMA, DMA byte swap for each, prefetch,
  precise, coherent, barrier, PIO swap, I/O-versus-memory select, and a 12-bit window base in bits 11:0, in units of 1 MB (the window address is the field shifted left 20, OpenBSD
  `BRIDGE_DEVICE_BASE_SHIFT`). The Bridge byte-swap for translated DMA is a per-device bit.

## Xbridge

- **What.** The Origin 300 / Origin 3000 successor. One chip contains two Bridge-style PCI sections (one PCI bus each) and
  a Crossbow-style crossbar section, so an Origin 300 has no separate Crossbow chip (the project xbridge datasheet and
  component taxonomy; I for the exact internal topology, the specification is under audit). OpenBSD `xbowdevs` lists
  the crossbar family as `XXBOW` (part `0xd000`); IRIX widget zero on an Origin 300 reports
  revision 2 (E, captures).
- **Placement.** Heads at widgets 14 and 15 on an Origin 300 (E, `hinv` "ASIC BRIDGE Rev 2" at both; the PROM prints
  "BRIDGE" for the Xbridge head, so that string does not distinguish the chip). Origin 3000 P-brick: three Xbridges
  between two Crosstown2 ports and twelve PCI slots (007-4240-002 p140, E). The X-brick midplane carries one Xbridge
  (007-4240-002 p150 and p152, E).
- **Differences from Bridge** (E where the IRIX code or OpenBSD header shows them):
  - 1024 internal translation entries instead of 128; no external SSRAM.
  - Force-interrupt registers `0x180`+8n (force always) and `0x1c0`+8n (force with pin) exist; the IRIX accessor
    panics for a Bridge. Interrupt view `0x170` and multiple `0x178` likewise.
  - Translated DMA byte swap is selected by PCI address bit 29 (OpenBSD `XBRIDGE_DMA_TRANSLATED_SWAP
    0x20000000`), not by a per-device bit. The translation entry also has a swap bit 5 (`ATE_BSWAP`, marked XB in
    OpenBSD). How the two interact on revision 2 silicon is an approximation in the project sheet: **U**; test below.
  - Status register fields move (see table above) and bit 5 is an input pin, not a mode flag; IRIX tests the Bridge
    part only for the GIO check.
  - Control bits 5:4 hold the PCI speed (E for OpenBSD, which reads them only when the chip is an Xbridge or PIC;
    for a plain Bridge it assumes 33 MHz because those bits belong to the transaction limit). Whether IRIX reads them
    was not shown.
  - Map-fault address register at `0x90` replaces the Bridge's SSRAM parity register (E for the name pairing; layout U).
  - Interrupt reset (`0x110`) bit 6 clears the error-interrupt view and bit 1 clears the page-map fault (project xbridge
    datasheet, specification-sourced, I).
- **Translation RAM by revision.** The Origin 300 carries revision 2 (`hinv`). The Xbridge specification describes
  revision A as 512 entries at `0x1_0000`; OpenBSD describes 1024 internal entries and the Linux IP35 PIC header places a second
  view at `0x1_2000` (manual parity generation, for PIC); SGI's board diagnostic reads that view on an Origin 300. Whether revision 2 maps all 1024 entries
  for DMA is **U**.

## PIC

- **What.** One ASIC, two PCI-X buses ("heads"), four device slots each (OpenBSD `PIC_NBUSES` 2, `PIC_NSLOTS` 4;
  Linux `pic.h` comment). Three PICs make up an IX-brick or PX-brick, which together have two Xtown2 XIO ports
  (007-4377-001 p67 and p78; which PICs carry the ports was not checked in the figure). It is the Origin 350 / Onyx 350 / Tezro part.
- **Identity (E).** Part `0xd102`, manufacturer 36. `0xd112` is the product id that the second head's register set
  reports (I, two independent sources: the OpenBSD `xbowdevs` comment "the second widget register set uses 0xd112",
  and the IRIX IP35 PIC attach code, which takes the bus number and compares the identification word against
  `0xd1021`/`0xd1121` at revision 1, `0xd1022`/`0xd1122` at revision 2 and `0xd1023`/`0xd1123` at revision 3: each
  pair is one revision of head 0 and head 1). Any other value is not rejected (only the debug name changes). Whether a
  shipped system exposes head 1 as a separately walkable widget with that id is **U**.
  Observed population: revision 3 on Origin 350 (project PIC datasheet). Revision names A, B, C for 1, 2, 3 are
  **I** from debug strings.
- **Head layout (I).** Head 0 at the widget base, head 1 at +`0x800000` in the same widget window (OpenBSD
  `BRIDGE_BUS_OFFSET`; the IRIX bridge-pointer helper adds `0x800000` for its second argument). OpenBSD's prose
  comment says "two contiguous widgets" and its `xbowdevs` comment says two widget register sets; its code uses the
  offset, which is what drives the machine. These describe the same layout loosely rather than contradict each
  other. Each head presents
  its own copy of the registers.
- **Register access (E).** Every register is a 64-bit doubleword at the slot address. Linux records a hardware
  erratum for the PIC ("PIC WAR PV#854697": a write that covers only bits 31:0 of a 64-bit register is not accepted;
  always write all 64 bits), and OpenBSD says the same. The IP35 PROM bridge diagnostic still does 32-bit accesses at
  slot +4 on a PIC (E for the instructions; what the PIC does is **U**, test below).
- **Register layout differences from Bridge/Xbridge** (E from the IRIX accessors unless noted):
  - Widget control gains no-snoop (62), relaxed-ordering (61), and the 55:48 field; widget status carries the PCI-X
    mode and speed (above).
  - Interrupt destination (`0x38`): target widget in bits 51:48, 48-bit address below. The upper register (`0x30`) is
    hardwired to zero and ignores writes (OpenBSD comment).
  - Per-pin interrupt address (`0x130`+8n): the vector is in bits 55:48 and the whole 48-bit host address sits in the same
    register; Bridge/Xbridge split it between this register (bits 17:8) and the destination registers.
  - PCI-X error registers `0x600` to `0x630` (bus error address, attribute, data; PIO split address and attribute;
    request error attribute and address). Names from accessor symbols (I for roles).
  - Interrupt status/enable has PCI-X error bits 32 to 45 above the Bridge-family bits 8 to 31
    (OpenBSD `BRIDGE_ISR_*`; `PIC_ISR_ERRMASK 0x00003fff7ffffe00` against `BRIDGE_ISR_ERRMASK 0xfffffe00`). The reset
    register is not grouped: IRIX writes back the status value it read.
  - Three 256-doubleword banks at `0x18000`, `0x18800` and `0x19000` (write request memory: lower, upper, parity).
    Software only zeroes them (E); their meaning is U.
  - The device registers (`0x200`+8n, four used) exist (IRIX accessors, OpenBSD `PIC_DEVIO_OFFS`), although a Linux
    comment says PIC "removed the device registers and windows". Treat the Linux comment as wrong or describing the
    PCI-X standard rather than silicon: **U**, test below.
  - Response buffer fields use a different packing: valid bit 3, virtual channel bits 2:1, device pair bit 0 (slots
    0 to 3 only), against Bridge/Xbridge valid bit 3, virtual channel bit 2, device pair bits 1:0. E, IRIX response-buffer allocation code.
  - Configuration: device 0 of the type-0 window is the PIC itself; the four slots sit at windows 1 to 4 (Linux `pic.h`
    table; OpenBSD `xbridge.c`: "device slots are offset by one"). The other slot-indexed registers are not offset.
  - No direct I/O window (OpenBSD `XF_NO_DIRECT_IO`).
- **Revision 1 workarounds (reasons U).** Only the request-timeout write of `0x750` was disassembled and confirmed
  (E); the rest are I, read from IRIX code but not re-disassembled when this page was last audited. Request timeout `0x750`; interrupt-enable bits 39 and 9 cleared;
  response-buffer registers set to `0x000f000f`; a force-interrupt programmed-I/O flush for certain
  devices; arbitration bits 23:20 set after an arbitration error. OpenBSD adds a PCI interrupt wrapper for revision 1.

## PCI and PCI-X side

| item | Bridge | Xbridge | PIC | grade |
|---|---|---|---|---|
| buses | 1 | 2 (one per head) | 2 (one per head) | E |
| device slots per bus | 8 | 8 | 4 (config windows 1 to 4) | E |
| PCI-X | no | no | yes; mode and speed from widget status | E |
| interrupt pins | 8 | 8 | 8 | E |
| speed read | not read from control (bits 5:4 are part of the transaction limit; OpenBSD assumes 33 MHz) | PCI 33/66 per control bits 5:4 | status bits 35:34 in PCI-X mode, else control 5:4 | E (OpenBSD) |
| PCI memory window | 1 GB at `0x4000_0000` | same | same | E for Bridge/Xbridge (OpenBSD), I for PIC |
| PCI I/O window | `0x1_0000_0000`, rev 4+ only | `0x1_0000_0000`, no revision gate (OpenBSD gates only Bridge; the captured Xbridge is rev 2) | not available | E (OpenBSD) |
| configuration windows | `0x20000`, 8 devices | same | same, off by one | E |

Interrupt line routing (which board trace feeds which pin) is a board property, not a chip property. See the board pages.

## Interrupt delivery as Crosstalk writes

All three chips deliver a device interrupt as a posted Crosstalk write to a programmed address, not as a wire:

1. IRIX picks a Hub interrupt-modify target address, writing it to the chip: the target widget goes in the destination
   register (`0x30` bits 19:16 on Bridge/Xbridge; `0x38` bits 51:48 on PIC) and address bits 47:32 / 31:0 below it
   (E, IRIX interrupt-target setup code). On an IP27 machine the address is the target node (`nasid << 38`) plus
   the Hub's processor-interface interrupt-modify register at `0x0180_0090`, and the interrupt vector is the bit number
   (I: from the IRIX allocation code and the project Bridge datasheet, not re-derived). The widget is the *master Hub* of the Bridge, one fixed
   Hub per Bridge, chosen at attach (E).
2. Per pin n (0 to 7): the vector goes in bits 7:0 of `0x130`+8n and, on Bridge/Xbridge, address bits 47:38 in bits
   17:8 (E; Linux and OpenBSD agree). On PIC the vector is in bits 55:48 and the full address is
   in the register (E; OpenBSD).
3. Enable the pin in `0x108` (interrupt enable), set the pin's mode bit in `0x118` (so the chip sends an interrupt
   clear packet when the pin falls, which saves a software clear; Linux and OpenBSD both comment this) and write the
   device number for the pin into `0x120` in 3-bit fields (E, IRIX interrupt allocation code). Read the target flush register `0x50`
   to push the posted writes (E).
4. When the pin goes active the chip sends a write whose data carries the vector, with a set operation, and on the falling
   edge a clear operation if the mode bit is set. The two-packet set/clear encoding is I: the IRIX code programs the
   registers; the packet payload layout is from the Xbridge specification (set packet: bit 8 plus the low eight bits of
   the host-error field for the chip's own errors).
5. The chip's own errors use the destination registers plus the host-error field at `0x128` (vector in its low byte)
   instead of a per-pin address (E, IRIX interrupt-target setup code). Error interrupt status is `0x100` bits 31:8 on Bridge and
   Xbridge, bits 45:8 on PIC; the low eight bits are the pin inputs. Clear: Bridge/Xbridge write `0x7f` groups to `0x110`
   at attach (E), PIC writes the status it read back (E).
6. `0x180`+8n (force always) and `0x1c0`+8n (force with pin) force an interrupt from software: Xbridge and PIC only (E);
   IRIX uses them for the PIC programmed-I/O flush.
7. Octane exception (E, OpenBSD): interrupt pin 6 on the Octane Bridge is the power-switch signal and is wired to a HEART
   interrupt register bit; the Bridge does not deliver it as a Crosstalk packet, but its enable bit must stay set.

On Octane the target is HEART (widget 8) rather than a Hub; the register encodings are unchanged (OpenBSD `xbridge.c`
writes `IP30_HEART_WIDGET << 48` into the destination).

## DMA windows

All three chips present the same three PCI-visible DMA views (E: Linux `bridge.h` `BRIDGE_DMA_*`, OpenBSD
`xbridgereg.h`, Linux IP35 `pcibr_provider.h`):

| PCI address | view | how it reaches Crosstalk |
|---|---|---|
| `0x4000_0000` to `0x7fff_ffff` (1 GB) | **translated** (page-mapped) | On Bridge, PCI bits 29:12 (4 KB pages) or 29:14 (16 KB pages, control bit 21) select an entry in the translation RAM. On Xbridge and PIC bit 29 is the byte-swap select, so the index is bits 28:12 or 28:14; the entry gives target widget (bits 11:8), address bits 47:12, valid (0), coherent (1, PIC: `CO`), precise (2), prefetch (3), barrier (4); Xbridge adds swap (5) |
| `0x8000_0000` to `0xffff_ffff` (2 GB) | **direct** | one fixed window: the direct-map register (`0x80`) holds the target widget (bits 23:20), a 17-bit offset in 2 GB units (bits 16:0) and an add-512-MB bit (17) |
| 64-bit PCI address | **64-bit direct** | the address itself carries the target widget (bits 63:60), and attribute bits: prefetch 59, precise 58, virtual channel 57, barrier 56 (`BAR`), swap 55, second virtual channel 54 (Linux IP35 `pcibr_provider.h`; Linux MIPS sets `masterwid << 60 | bit 56`); the low 48 bits are the crosstalk address |

- IRIX sets the direct map to the master Hub's widget and the node of memory it is asked about; add-512-MB is cleared
  unless the translated address is exactly `0x2000_0000` (E, IRIX direct-map setup code). A PROM variant on the IP27 sets
  widget from a slot-code table and offset zero (E).
- Page-mapped target widget comes from the entry's bits 11:8; what value IRIX writes there was not read: **U**.
- Byte swap: Bridge selects swapping per device in the device register (DMA direct and DMA mapped bits), Xbridge and PIC
  encode it in the PCI address (bit 29 for translated; bit 55 for 64-bit) and Xbridge also in the entry. Which DMA
  address bit means swap, and the default state of the swap controls, are **U** for the chip reset state (no shipped code
  reads a reset value).
- The Bridge Linux driver clears the I/O and memory swap bits in control at probe; IRIX does not touch them (E).
  Reset values of those bits are **U**.
- DMA reaches memory through Crosstalk without translation by Crossbow (I, project xbow datasheet statement; the Hub
  translates widget-relative addresses).
- PIC 64-bit direct DMA in PCI mode uses virtual channel 0 for function 0 and channel 1 for other functions (Linux IP35,
  E for the driver, I for hardware).

## Differences, in one place

| | Bridge | Xbridge | PIC |
|---|---|---|---|
| part / manufacturer | `0xc002` / 54 | `0xd002` / 36 | `0xd102` (`0xd112`) / 36 |
| revisions seen | 2, 3, 4 (A to D = 1 to 4) | 2 (B) | 3 (1 to 3 accepted by IRIX) |
| buses and slots | 1 x 8 | 2 x 8 | 2 x 4 |
| bus type | PCI or GIO | PCI | PCI and PCI-X |
| register width | 32-bit at slot +4 | 32-bit at slot +4 | 64-bit at slot address, writes must be full width |
| internal / external ATEs | 128 / up to 64 K (SSRAM) | 1024 / none | 1024 / none |
| force-interrupt regs | no | yes | yes |
| interrupt address | split across `0x130` and `0x30`/`0x38` | same | whole in `0x130`+8n and `0x38` |
| error status bits | 8 to 31 | 8 to 31 | 8 to 45 |
| translated DMA swap | per-device bit | address bit 29 and entry bit 5 | address bit 29 |
| PCI I/O window | rev 4 and later | yes (no revision gate) | no |
| one-wire at `0xb0` | Number In A Can | not used in Xbridge mode, pin reached through the internal crossbar's widget 0 NIC register at offset `0x70` (E: Xbridge ASIC specification rev 0.5, 10/1/98, sections 3.2 and 6.5 and its register map; in Super Bridge mode, where the internal crossbar is disabled, the bridge on the port that powers up as 0xf uses its own `0xb0` register) | parity-error register in the IRIX accessor |
| crossbar inside | no (needs an external Crossbow or a Hub) | yes (`XXBOW`) | no (external widget-0 crossbar, `PXBOW`, part `0xd100`) |

The PIC `0xb0` row is U: the IRIX parity-error accessor reads `0xb0` on a PIC, and Linux IP35 comments it
"Number In A Can or ATE Parity Error". Which of the two applies to which PIC revision is not settled.

## Unknowns and their tests

| unknown | why it matters | settled by |
|---|---|---|
| Reset value of any register (none are read by software before write) | a reset state cannot be modelled from software | a register dump on an Origin 200, Origin 300 and Origin 350 immediately after reset |
| Whether head 1 of a PIC is separately walkable as a widget reporting `0xd112` | the part itself is explained (head 1's register set); the widget-table presentation is not | walk the widget table on an Origin 350, IX-brick, PX-brick or Tezro |
| 32-bit write to a PIC register (PROM diagnostic) | contradicts the "64-bit only" erratum | the PROM diagnostic against a PIC with the low-word write logged, or a capture of its output |
| PIC `0x7c` write (diagnostic) | same | read `0x78` before and after the write |
| Whether Xbridge revision 2 maps entries 512 to 1023 for DMA | 16 KB-page addressing range | write distinct values to entries 0 and 512 on an Origin 300 and DMA through each |
| Xbridge swap: address bit 29 versus entry bit 5, together | DMA byte order in a diagnostic | a DMA with each, and both, set, on an Origin 300 |
| Bridge rev 2 enable-mask workaround reasons | error behaviour | the errata sheet for revision B, or a rev 2 capture with bit 20 set |
| PIC `0xb0` parity or one-wire | register meaning | read `0xb0` twice on a PIC with an ATE parity error forced and not forced |
| PIC device registers and windows | Linux comment contradicts the IRIX accessor and OpenBSD | read `0x200` and `0x240` on a PIC |
| Address `0x30000` (interrupt acknowledge) read or write | undocumented use | read the word on an Origin 300 or Octane |
| Whether the second PIC head is a separate widget or an offset in the same widget | OpenBSD's prose and code describe it loosely | walk the widget table on an Origin 350 |
| Registers between `0x2a0` and `0x10000` on Xbridge | specification and software silent | read the range; expected only address-error behaviour |
| Interrupt packet payload encoding | model needs exact bits | a bus capture of one interrupt write |

## Open items outside this page

PXBOW (`0xd100`, the Origin 350 widget-zero crossbar) and the fourth part (`0xe000`/`0xe010`, Altix-class, called
TIOCP in the Linux IP35 tree) are other chips; PXBOW has a project experiment page. The Octane's PCI expansion Bridge
(Crossbow port 13) is a second instance of the Bridge; its stock-PROM dependence is U.

## Corrections (2026-11-10)

An audit against the manuals, the public Linux and OpenBSD trees and the shipped IRIX objects changed the following.

- Xbridge machines: Fuel removed from the IP45 row (Fuel is IP34; OpenBSD only calls it Origin 300 like). Added the
  Origin 3000 X-brick (007-4240-002 p150, p152) and noted the L1 text naming the I-brick. Noted that OpenBSD says later
  Origin 200/2000 boards used Xbridge; nothing here captures that, so the Bridge-only machine claim for those
  systems rests on the Origin 200 rev 4 capture alone.
- PIC part `0xd112` was graded unknown. It is the product id of head 1's register set: OpenBSD `xbowdevs` says so, and
  the IRIX IP35 attach code compares the identification word against head 0 and head 1 pairs at revisions 1, 2 and 3
  (offsets 0x908 to 0x918, 0x105c, 0x1064 and 0x11d4 of the shipped PIC driver object). Now I with two sources. The
  "contradiction in OpenBSD" wording about head layout was softened: the prose and code are loose, not opposed.
- Widget control speed: bits 5:4 overlap the transaction-limit field on Bridge, and OpenBSD reads them as speed only
  for Xbridge and PIC. The Bridge cell in the PCI-side table was wrong and is fixed; the claim that IRIX reads them is
  dropped as not shown.
- PCI I/O window: Xbridge has no revision gate in OpenBSD (the gate is Bridge only), and the two tables now agree.
- Translated DMA index: on Xbridge and PIC bit 29 is the swap select, so the entry index is bits 28:12 or 28:14. Bridge
  keeps 29:12 or 29:14.
- Linux part-number attribution: the out-of-tree IP35 tree labels `0xd102` "Xbridge(?)" (a guess, not "unknown"); mainline
  Linux has no `0xd102`. `XXBOW` and `PXBOW` are credited to OpenBSD `xbowdevs`, not to an SGI header. The "SGI SN1
  header" attribution for the Xbridge translation views was removed; the `0x1_2000` view is publicly described only for
  PIC.
- Removed identifiers that appear in no public tree: IRIX driver function and accessor names, the PROM error-word
  field names, two PROM field names in the widget-control row, the per-chip record offset and chip-type values, driver
  object file names, and a kernel code address. The facts remain, stated in plain words.
- Regraded: the PIC revision 1 workaround list other than the `0x750` write, the Hub interrupt-modify address
  composition and the Bridge revision 2 enable-mask bit list are now I (not re-disassembled). The claim that two of the
  three PICs carry the Xtown2 ports was weakened to what the manual text says.
- Not re-verified in this audit: widget placements (Origin 350 widget 15, Tezro widget 11, Octane PCI module on
  Crossbow port 13, Origin 200 master widget `0xa`), the `0xb0` meanings, the PCI-X error registers `0x600` to `0x630`,
  Xbridge translation RAM detail, the PIC response-buffer packing, bit 0 of the identification word, and the per-chip
  `0x78`, `0x7c`, `0x40` and `0x58` roles.
