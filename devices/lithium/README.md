# Lithium: the Visual Workstation I/O ASIC (two PCI bridges and the audio engine)

Mode: **no-spec**. The Lithium specification (the audio driver quotes "the Lithium spec, section 5.6.8, revision of
12/15/1998") is not held, and SGI said none was releasable ([sources](../../references/visws-sources.md)). Everything
here is from the Linux Visual Workstation code for the 320 and 540, kernel 2.2 to 3.14, and the SGI-written sound driver.
That code ranks as the vendor's software source: what it defines is **established**, as a software definition; what it
only implies is **inferred**; the rest is **unknown**. Registers: [registers.md](registers.md) (nineteen registers and constants). The
platform is in [platforms/visws](../../platforms/visws/README.md).

## What the chip is

- **The I/O ASIC (established).** The kernel's description: "Lithium is the SGI Visual Workstation I/O ASIC", and the
  Cobalt chip "interfaces ... the I/O system in the Lithium ASIC" ([cobalt](../cobalt/README.md)). A user in 1999
  compared it to the Octane's crossbar; no code supports that and it is not repeated as a fact.
- **Two PCI host bridges, A and B (established).** The kernel finds both by reading a standard PCI vendor and device
  identification from a fixed physical window each: vendor `0x10a9` (SGI), device `0x1002`. Bridge A's window is at
  `0xfc000000` and carries the Ethernet device (the header says "Enet is dev 3"). Bridge B's is at `0xfd000000` and has
  the PIIX4 behind it. Each is a PCI bus of its own, with a bus number the kernel reads from the bridge. The owner's guides say the machines' slots are 64-bit, 33 MHz; on the 540 slots 1 to 4 take 5 V and universal cards and
  slots 5 and 6 take 3.3 V and universal cards (guide 007-3882-001, table A-5); a 1999 post from SGI's Belgian office says
  the 320 needs 3.3 V or universal cards. Which slots hang off which bridge is unknown.
- **An audio DMA engine (established).** The same chip holds a serial link to an Analog Devices AD1843 codec and two DMA
  channels, at a third window, `0xff001000`, driven by SGI's own sound driver. The audio interrupt is Cobalt line 22.
- **Other functions are unknown.** The video input and output paths and the Arsenic link belong to the Cobalt
  graphics pages. Whether the Lithium has a memory path of its own is unknown; a 1999 post says "Lithium chipset", by
  context the I/O side.

## The bridge window (established)

Each bridge's window starts with a standard PCI configuration header (the kernel reads the vendor and device words at
0 and 2). Two bridge-specific registers are used, both 16 bits, both outside the standard header (the kernel's comment
is "Not a standard PCI?"):

- **Bus number** at `0x44`. The low byte is the bus the kernel scans for this bridge. The code reads only the low
  byte. The 2.4 scan reads bridge B's value and scans bus 0 and that bus; the 2.6 scan reads both and scans both. The
  two disagree about which bridge is bus 0: 2.6 treats bridge B's number as the PIIX4's bus and bridge A's as the other,
  and 2.4 prints B's number as the second bus. A post by an SGI engineer says "the second PCI bus, normally bus one". So
  most likely B is bus 0 and A bus 1 (inferred), but **the number on a real machine is unknown** and the 2.4 reading
  scans the same bus twice if B is 0.
- **Interrupt enable** at `0x46`: eight bits, five for the INTA of each of the five device numbers and one each for the
  shared INTB, INTC and INTD. Linux enables them all on both bridges once at start-up (the 2.2 kernel writes sixteen
  ones, later kernels eight) and calls this a blind enable. Reset state and whether firmware leaves it masked are
  unknown.

Configuration accesses to devices behind the bridges do **not** go through these windows. The kernel uses plain PC
type 1 configuration through ports `0xcf8` and `0xcfc` with the bus numbers above, and sets its PCI probing to that
mechanism alone (BIOS and type 2 excluded). The windows give only the bridge's own registers. How the type 1 mechanism
is split across two host bridges (does it decode the bus number to pick a bridge?) is not described by any code. **Unknown.**

PCI device numbers: five devices per bridge are described by the interrupt enable bits and the interrupt map (devices 0
to 4). The kernel does not say which are physical slots. Known occupants: Ethernet (Intel 82557, per the 2.2 header)
at device 3 on bridge A; the PIIX4 at device 4 on bridge B, with its IDE and USB functions. The rest of the slots (the
320 had two PCI slots on separate buses per owner posts; the 540 more) are inferred only.

The error behaviour is **unknown**: no code reads an error register, handles a master abort or enables parity. The
`pci_sanity_check` of the 2.2 PCI code is bypassed on this machine with the comment "Lithium PCI Bridges are
non-standard", so a probe of bus 0 for a host bridge class does not find a standard one.

## Audio engine (established, from the driver)

### Codec access

The AD1843's 16-bit registers are reached through a command and a data word: write the data, then the command with
the register number in the low seven bits and the direction in bit 7; wait for the busy bit. The driver waits two
ticks. A read writes the command, waits, then reads the data word. The codec link is brought up by writing the reset
bit, a microsecond later the link-enable bit alone. Nothing else of the link is programmed.

### DMA

- Two channels: channel 1 input, channel 2 output. Each has a base register (physical address shifted right 8, with
  bit 29 set for coherence), a control register carrying the pointers and the size, and a configuration register (rate
  is the codec's, set separately). The ring is up to 8 KiB, physically contiguous, in 32-byte steps. The pointers are
  eight bits, so a ring has at most 256 steps.
- Direction of each pointer: for input the engine advances the write pointer and software the read pointer; for
  output the reverse. Software writes its pointer as a single byte, the hardware pointer is read as a byte.
- The trigger pointer and mask raise an interrupt when the hardware pointer matches the trigger pointer on the bits the
  mask keeps; a mask value of 0 means the whole ring is one section, 7 gives interrupts every 2 steps. The status
  register reports trigger, overflow and underflow separately.
- Formats: 16-bit two's complement (copied unchanged) and 8-bit unsigned (each byte xored with 0x80 on the way), mono or
  stereo. The codec's mu-law and A-law are the codec's, not the engine's.
- **Quirks the driver works round (established as the driver's text):** the input channel must be given a base
  address even for output-only use; when output stops the driver zeroes three words in the second and third register
  pages (the zero-sample value and copies of the DMA pointers) that the hardware does not clear. The driver says all
  three are undocumented and unsupported and "I expect this to break in a future rev of Lithium".
- A 64-bit microsecond counter and per-channel time stamp and sample counters give audio and system time pairs. The
  counter's units and base are the driver's comment, not measured.

### Interrupt

One shared line to the Cobalt interrupt controller (line 22, kernel interrupt 38). The handler reads the status
register, clears all pending bits by writing ones, and masks the result with the enabled set.

## Interrupts from PCI devices (established, with a caveat)

The two bridges drive the Cobalt interrupt controller directly; the Lithium has no 8259. How each of the eight enable
bits is turned into controller lines is in the [interrupt page](../../platforms/visws/interrupts.md). The map the
2.6 code carries is not self-consistent; that page lists the cases.

## Unknown, and what would settle it

| Unknown | Route |
|---|---|
| Which bridge has bus 0; the actual bus numbers | A boot log of Linux 2.6 on a real machine (the kernel prints both); a PROM |
| Type 1 decode across two bridges; memory and I/O window routing | PROM, NT HAL, the Lithium specification |
| Error reporting, parity, master abort | Same |
| Reset state of the interrupt enables and the bridge header | Same |
| Meaning of the undocumented audio words; the rest of the audio register file | The NT audio driver, the specification |
| Other functions of the chip, including any memory or video role | Same |
