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

- **Bus number** at `0x44`. The NT HAL *writes* this word (second reading: [nt-hal.md](../../software/visws/nt-hal.md#pci-numbering-and-resource-assignment)): when the byte at window `+0x08` is above zero, the low byte gets the HAL's bus number for the bridge and the next byte the highest bus behind it, and the status halfword at `+0x06` is cleared with `0xf800`; when that byte is zero the bus number goes in the top byte of `+0x40` instead. So the number is the OS's to set; the HAL gives bridge B (window `0xfd000000`) bus 0 and bridge A bus 1 (established for the NT HAL). The low byte is the bus the kernel scans for this bridge. The code reads only the low
  byte. The 2.4 scan reads bridge B's value and scans bus 0 and that bus; the 2.6 scan reads both and scans both. The
  two disagree about which bridge is bus 0: 2.6 treats bridge B's number as the PIIX4's bus and bridge A's as the other,
  and 2.4 prints B's number as the second bus. A post by an SGI engineer says "the second PCI bus, normally bus one". So
  most likely B is bus 0 and A bus 1 (inferred), but **the number on a real machine is unknown** and the 2.4 reading
  scans the same bus twice if B is 0.
- **Interrupt enable** at `0x46`: eight bits, five for the INTA of each of the five device numbers and one each for the
  shared INTB, INTC and INTD. Linux enables them all on both bridges once at start-up (the 2.2 kernel writes sixteen
  ones, later kernels eight) and calls this a blind enable. Reset state and whether firmware leaves it masked are
  unknown.

**Configuration cycles, two ways.** Linux uses plain PC type 1 configuration through ports `0xcf8` and `0xcfc` with the bus
numbers above, and sets its PCI probing to that mechanism alone (BIOS and type 2 excluded). How that mechanism is split
across two host bridges (does it decode the bus number to pick a bridge?) is not described by any Linux code. This is
Linux's expectation only (inferred).

SGI's NT 4.0 HAL does not use the ports. Its PCI accessors (`HalpPCISynchronizeTypeBorg`, the `HalpPCIRead` and `HalpPCIWrite` routines with the `TypeBorg` suffix, and `HalpPCIConfig`, in `halborg.dll` 1.3; established, read in full) reach a device through the window of the bridge that owns its bus: the address
register is the 32-bit word at window `+0xf8` and the data is the word at `+0xfc`, with the byte or halfword lane picked by
the low address bits. The address word has bit 31 set, the bridge's bus number in bits 23:16 (taken from the
bus handler's number, not from the `+0x44` word), the device number in bits 15:11, the function in bits 10:8 and the
dword-aligned register in bits 7:2. Each access raises the processor to the highest priority level and takes a spin
lock (skipped while writing a crash dump). After a configuration access the HAL writes `0x2000` to the bridge's own
status halfword at window `+0x06`, which on a standard PCI header clears "received master abort" (the bit is
write-one-to-clear in a standard header; inferred that it behaves so here). A read from a slot the HAL has judged absent
returns all ones without touching the bus: the check accepts a device number below the handler's slot count, and a nonzero
function only after a read of function 0's header-type byte (the exact test is not clear in the decompiled form; inferred
that it is the multifunction bit). So the two bridges decode type 1 cycles
themselves, each for its own bus, and the HAL needs no mechanism-1 port at all. Whether the ports also work on the real
machine is unknown. The PIIX4 power-off special cycle that Linux writes through `0xcfc` is Linux's own.

The windows give the bridge's own registers as well. The shipped USB driver (`sgiusb00.sys`, boot-time keyboard and mouse
support) maps bridge B's window (`0xfd000000`, `0x70` bytes) and writes all ones to the word at `+0x48`, and its
watchdog prints "PCI Error Status" and "PCI Error Status Address"; the word at `+0x48` is therefore an error-status
register that software clears by writing ones (inferred from the write and the messages; neither Linux nor the HAL
touches it). Its position next to the interrupt enable at `+0x46` and its address companion are unread.

PCI device numbers: five devices per bridge are described by the interrupt enable bits and the interrupt map (devices 0
to 4). The kernel does not say which are physical slots. Known occupants: Ethernet (Intel 82557, per the 2.2 header)
at device 3 on bridge A; the PIIX4 at device 4 on bridge B, with its IDE and USB functions. The rest of the slots (the
320 had two PCI slots on separate buses per owner posts; the 540 more) are inferred only.

The error behaviour is mostly **unknown**: no Linux code reads an error register, handles a master abort or enables parity; the shipped HAL clears the master-abort status bit after each configuration access and the USB driver clears an error word at `+0x48` (above). The
`pci_sanity_check` of the 2.2 PCI code is bypassed on this machine with the comment "Lithium PCI Bridges are
non-standard", so a probe of bus 0 for a host bridge class does not find a standard one.

## Audio engine (the Linux driver; the NT driver is checked below)

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

### What SGI's NT audio driver confirms (sgisound.sys 5.2.2)

Read in Ghidra for its hardware access only ([driver inventory](../../software/visws/nt-drivers.md)). Established:

- It maps the same three pages (`0xff001000`, `0xff010000`, `0xff00f000`, `0x1000` bytes each), so the page addresses are
  not Linux's invention.
- Codec access is by 16-bit accesses to the command word at `+0x18` and the data word at `+0x1c`: the register number goes in
  the low bits, `0x80` marks a read, and bit 15 of the command word is the busy flag, polled in 10-microsecond steps up to
  36,000 times (about 0.36 s). The same driver writes `+0x00` with `0x8000`, then `0`, then `0x4000` to bring the link up:
  reset, release, link enable, which agrees with the Linux register layout.
- A ring base is written as the physical address shifted right 8 with bit 29 (`0x20000000`) set.
- The silence value goes to a word at `0xff00f000 + 0x500`: `0x80808080` for 8-bit samples, `0` for 16-bit, which is the
  "zero-sample value" Linux names. The words at `0xff010000 + 0x98` and `+0x9c` are zeroed when output starts or stops.
- It never connects an interrupt (the driver imports no connect-interrupt call): it uses a timer and a deferred call, so
  NT does not depend on Cobalt entry 22 for audio. Whether entry 22 is the audio line is therefore still Linux's word only.

### The DMA engine as the NT driver programs it (second reading)

Read in Ghidra with SGI's debug symbols (`sgisound.sys` 5.2.2, build time 2001-10-29: `sndStartDMA` at `0x113f2`, `sndStopDMA`,
`sndLoadDMABuffer`, `sndIoctlGetPosition`, `HwAssignDmaOffsets`, `HwInitializeCodec`, `GetLiUstMscPair`). All register access goes
through two small routines, `READ_LITHIUM` and `WRITE_LITHIUM` (offset, width 1, 2 or 4, in the first mapped page). Established:

- **Seven channel register sets, two used.** `HwAssignDmaOffsets` copies one row of a seven-row table into the channel state: base, control,
  configuration, time stamp, counter, and the byte offsets of the read and write pointers. Rows: base `0x100 + 0xc * n`, control `+4`,
  configuration `+8`, time stamp `0x300 + 8 * n`, counter `+4` after it, for n = 0 to 6 (so `0x100` to `0x150` and `0x300` to `0x334`); the
  read-pointer byte is control `+1` and the write-pointer byte control `+0`. The driver gives input row 0 and output row 1, the same as
  Linux's two channels. That rows 2 to 6 exist in the silicon is inferred from the table only.
- **Start (`sndStartDMA`).** Output only first clears the enable bit and writes the control word, and zeroes the two words at `+0x98` and
  `+0x9c` of the second page (`0xff010000`); both directions then write the ring base (physical address shifted right 8, bit 29
  set), the configuration word (format `0` for 8-bit and `1` for 16-bit in bits 1:0, stereo in bit 2, output in bit 3; other bits as the
  shadow copy holds them), then the control word with the size code in bits 30:28 (7 for the default 8 KiB ring, 6 otherwise) and, last,
  the enable bit 27 set. The silence word (`0x80808080` for 8-bit, `0` for 16-bit) is written to `0xff00f000 + 0x500` before the
  enable. The driver keeps a shadow copy of every register it writes and ORs bits into the shadow, so it never reads configuration
  or control back.
- **Pointers.** Rings are 8 KiB (4 KiB for the other size code) of contiguous memory aligned to 256 bytes, in 32-byte steps. The driver
  writes the software pointer as a single byte (`(write position - base) >> 5` for output, read position for input) and reads the
  hardware pointer as a single byte (control `+1` for output, `+0` for input), always as one-byte accesses.
- **Counters.** `GetLiUstMscPair` forms a 64-bit time stamp from the time-stamp word of the channel and the global `ust_high` (`+0x204`), re-reading `ust_high` until
  it is stable, and returns the channel's counter beside it. The driver zeroes the output counter at start when the pair is unset
  (and the input counter on input), so both counters are writable.
- **Link check.** `HwCheckLink` reads the halfword at offset 0 and says the link is good when bit 2 is clear.
- **What the NT driver never touches.** The interrupt status and mask words at `+0x10` and `+0x14`, any trigger pointer or trigger mask, the
  channel reset bit, and the configuration slot and lock bits. Those stay Linux-only (`inferred`). The driver runs off a timer and a
  deferred procedure (`SoundOutTransferDpc`, `SoundInTransferDpc`), polling the pointers.

### Window offsets beyond the audio file (sgilivid.sys 5.2.2)

The NT video capture driver pairs each of four video channel windows (`0xf8000000` to `0xfb000000`) with an eight-byte control
pair in the audio window's page at `0xff001340`, `0xff001348`, `0xff001350` and `0xff001358` (the whole page is at
`0xff001000`; Linux names nothing above `+0x30c`). Established as mappings. The driver uses each pair the way the audio engine's
time-stamp and counter pairs are used: word 0 is a time stamp read against `ust_high` (the driver's `ReadUst`), word 1 a media stream counter
whose bit 0 is a flag and bits 31:1 a count (`ReadMsc`), both zeroed when a channel starts; software expectation from the driver's
names and use. Which pair belongs to which channel was re-checked in the 5.2.2 build: `0xff001350` goes with the window `0xf8000000`
(`sgilivideoout1`), `0xff001358` with `0xf9000000` (`out2`), `0xff001340` with `0xfa000000` (`in1`) and `0xff001348` with `0xfb000000` (`in2`).
[Details](../../software/visws/nt-drivers.md).

## Interrupts from PCI devices (established, with a caveat)

The two bridges drive the Cobalt interrupt controller directly; the Lithium has no 8259. How each of the eight enable
bits is turned into controller lines is in the [interrupt page](../../platforms/visws/interrupts.md). The map the
2.6 code carries is not self-consistent; that page lists the cases.

## Unknown, and what would settle it

| Unknown | Route |
|---|---|
| What bus numbers a boot leaves in the bridge words under Linux or a firmware that numbers them itself | A boot log of Linux 2.6 on a real machine (the kernel prints both); a PROM. (The NT HAL numbers B as 0 and A as 1 and writes them itself.) |
| Type 1 decode across two bridges; memory and I/O window routing | PROM, NT HAL, the Lithium specification |
| Error reporting, parity, master abort | Same |
| Reset state of the interrupt enables and the bridge header | Same |
| Meaning of the undocumented audio words; the rest of the audio register file | The NT audio driver, the specification |
| Other functions of the chip, including any memory or video role | Same |

## Review

Independent review of the audio DMA section (chips commits 7990dc9..7a40091) read the 1999 `sgisound.sys` and its symbol file from the SGI 320 NT 4.0
install CD (Disk 2), because the 5.2.2 build the section cites sits in an InstallShield cabinet that could not be unpacked then. In the 1999 build the
seven-row register table, `sndStartDMA`, `HwCheckLink`, `GetLiUstMscPair` and the counter zeroing all matched the text; the driver imports
no interrupt-connect call. The vendor and device id constants appear in no Windows binary read, so their `inferred` grade stands.

The 5.2.2 build (build time 2001-10-29, from the Digital Media 5.2.2 pack, unpacked with an InstallShield extractor) was then read directly, with
its symbols, and the same items checked: the three page addresses; the codec command and data words and the busy loop (36,000 stalls of
10 microseconds); the seven-row table (the table's bytes were dumped: base `0x100 + 0xc * n`, control `+4`, configuration `+8`, time stamp
`0x300 + 8 * n`, counter `+4`, pointer bytes at control `+1` and `+0`); `sndStartDMA`'s order and bit values (base `address >> 8` with bit 29,
configuration bits 1:0, 2 and 3, size code 7 or 6, silence word, enable bit 27 last, the output-only zeroing of `+0x98` and `+0x9c`);
the byte-wide pointers; `HwCheckLink` (bit 2 clear); `GetLiUstMscPair` (high word at `+0x204`, counters at `+0x304` and `+0x30c`); and the absence
of any interrupt connection. No difference from the text was found. The two builds' register table is the same table. The
`sgilivid.sys` and `sgiust.sys` windows and addresses in the section above were re-read the same way.
