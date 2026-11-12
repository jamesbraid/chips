# SGI Hollywood DSP audio block (HPC-attached 56000-family DSP)

Not the Sonic Solutions HDSP PCI audio card, which is a different product.

Scope: the audio subsystem of the first-generation Indigo workstations, a Motorola 56000-family DSP whose host interface, DMA engine,
interrupt logic and SRAM live inside the first-generation peripheral controller (HPC1 and HPC1.5), not behind a PCI or GIO device of
its own. This page records where the block sits, which registers the host uses, how the host and the DSP talk, and what is not known.
The software that drives it, its ioctl surface and ring-buffer protocol are in kudzu (`docs/hollywood-dsp-driver.md` there). Labels as in
[AGENTS.md](../../AGENTS.md): **established**, **inferred**, **unknown**.

## Evidence and its limits

- The driver object for this block is **not held** for any build (no `hdsp` object in the 6.5.22 `IP22` directory or any other; the
  `IP20` and `IP12` object directories are not held at all). The 6.5.22 configuration trees for IP27, IP30 and IP35 carry the
  `master.d/hdsp` entry, which says only: character device, prefix `hdsp`, major 53, comment "Hollywood DSP". **Established**
  (read in full).
- Every register fact below comes from three shipped developer headers (the IP20 board header, the controller header and the driver's
  private header) and one public emulator source file for the controller (cited below without the project name, as the repository rules
  require). No binary I hold touches these registers. By this repository's labels that makes the register facts **inferred**, not
  established: the shipped headers agree with each other, and with the emulator source where it overlaps, but nothing confirms them
  at an instruction address. The settling route is the driver object (open question 1).
- Published SGI owner and hardware guides: the document library was unreachable when this page was written (connection refused on all
  three search backends), so no guide was read. Open question 7.

## Which machines carry it

| Item | Finding | Label |
|---|---|---|
| Indigo, R3000 (board IP12) | A DSP56001 at 20 MHz, three 32K x 8 SRAM chips forming 32K x 24 bits, and the DSP register block at HPC0 offset `+0x180`, are present in a public emulator's model of the board. | **inferred** (third-party model, no binary) |
| Indigo, R4000/R4400 (board IP20) | The IP20 board header lists the DSP register addresses, its interrupt bit and vector, and the DSP-memory window. Boards with the VME option ("V50") have no audio hardware, per a comment in the same emulator's source. | **inferred** (header names the registers; V50 remark is the emulator's) |
| Inventory class | `hinv`'s audio class has type 0 for "Indigo DSP system"; `sbin/hinv` prints `Iris Audio Processor: revision %d` for it. | **established** (hinv binary, see [drivers.md](drivers.md); header comment for the product name) |
| Indy, Indigo2, Power Indigo2 (IP22, IP26, IP28) | The IP22 and IP26 board headers mention no DSP; these machines use the HAL2 audio chip (inventory type 3). | **inferred** (absence in headers; not proven by a binary) |
| Octane, O2, Origin, Onyx2, Origin 300 | None. Their audio drivers are RAD, A3 (MACE), MAD, USB, EMU; see [drivers.md](drivers.md). | **established** for the objects held |

Whether the 6.5.22 or 6.5.30 kernel ever ran this driver on IP12 or IP20 hardware is **unknown**: the master entry ships in the generic
trees, but no IP20 kernel object of either release is held. The emulator's source comments mention IRIX 4.0.5 and 5.3 as the releases
used on IP12.

## Where it sits

The DSP is a bus master and a slave of HPC0, the primary controller. HPC0 is at physical `0x1fb80000` (the IP20 header names the HPC ID
words for HPC0 to HPC3 at `0x1fb80000`, `0x1fb00000`, `0x1f980000`, `0x1f900000`); only HPC0 hosts the DSP. **Inferred** (header).

- Host registers: HPC0 `+0x180` to `+0x1b7`, 32-bit word slots with 16-bit or narrower data in the low bits. The interrupt controller
  (INT2) sits in the same HPC window at `+0x1c0` and the serial-memory and LED control at `+0x1bc`, so the DSP block is wedged between
  the SCSI/parallel blocks below it and INT2 above it. **Inferred.**
- DSP SRAM: physical `0x1fbe0000`, 24 bits by 32K words, each 24-bit word in its own 32-bit slot, so the window is 128 KB and ends where
  the boot PROM begins at `0x1fc00000`. A control bit selects 8K or 32K of SRAM (below). **Inferred** (header and emulator agree).
- DSP side: the DSP sees the same registers as memory-mapped words near the top of its Y space (table below), the SRAM at the upper half
  of its 64K-word space (the driver's private header gives the SRAM size as a 32768-word floor and a 65536-word ceiling in DSP words),
  and an on-chip serial port that the emulator source ties to the audio converters. **Inferred** for the layout; **unknown** for what is
  wired to the serial port, see open question 4.
- Peripheral bus: the DSP can also reach the HPC peripheral bus (20-bit address, 16-bit data), which holds the boot PROM, the serial
  controllers, the real-time clock and, per the emulator source, left and right headphone gain converters at HPC0 `+0xd30`. **Inferred**
  (single source for the converters).

## Host-side register table (HPC0 base `0x1fb80000`)

All offsets are from the HPC0 base; widths are the valid bits of the 32-bit slot. The names are the ones the shipped headers use.

| Offset | Name | Width | Meaning | Label |
|---|---|---|---|---|
| `+0x180` | DMA word count | 16 | Number of SRAM words to move in one DMA run. | inferred |
| `+0x184` | GIO address, low half | 16 | Low 16 bits of the main-memory-side address of the DMA. | inferred |
| `+0x188` | GIO address, high half | 16 | High 16 bits of the same address. | inferred |
| `+0x18c` | Peripheral-bus address | 16 | SRAM word address on the DSP side of the DMA. | inferred |
| `+0x190` | DMA control | 3 used | Bit 0 starts the run; bit 1 selects direction (0 is main memory to DSP); bit 2 selects folded mode (1) or normal mode (0). The header comment says "2 bit" but defines three bits: **conflict**, bit 2 is trusted because the driver's ring types use a folded mode. | inferred |
| `+0x194` | Counter | 24, read-only | A free counter; what it counts is not stated and the driver's register list omits it. | unknown |
| `+0x198` | Handshake transmit | 16 | The word the DSP writes for the host; a DSP write raises interrupt source 2. | inferred |
| `+0x19c` | Handshake receive | 16 | The word the host writes for the DSP; a DSP read of it raises interrupt source 4. | inferred |
| `+0x1a0` | CPU interrupt status | 3 | One bit per source: 1 end of DMA, 2 DSP wrote the transmit word, 4 DSP read the receive word. How a bit is cleared is not stated. | inferred (clear: unknown) |
| `+0x1a4` | CPU interrupt mask | 3 | Same three bits; 1 enables the source. | inferred |
| `+0x1b0` | Miscellaneous control and status | 8 | Bit 0 hard-resets the DSP; bit 1 forces the DSP's IRQA input at the polarity in bit 2 (1 is high); bit 3 selects 32K (1) or 8K (0) of SRAM; bits 6:4 select how a narrow peripheral-bus read is widened to 32 bits (`0x70` 8-bit signed, `0x60` 16-bit signed, `0x40` 24-bit signed, `0` unsigned). | inferred |
| `+0x1b4` | Burst control | 16 | The DMA "ballistics" register: burst length and spacing of the DMA on the GIO bus. Field layout not stated. | inferred (fields unknown) |

HPC0 also has a byte-wide endian register at `+0xc3` (big-endian CPU) with a DSP-little-endian bit (`0x10`) and a two-bit revision field in
bits 7:6, value 1 for the HPC1.5. **Inferred** (IP20 header). Whether the HPC1 (first generation, IP12) has the endian register at all is
**unknown**.

Agreement check, afterwards: the emulator source lists the same twelve host addresses with the same names, and in addition the DSP-side
mirror (Y-space words, 16 bits): `0xffe0` word count, `0xffe1`/`0xffe2` GIO address halves, `0xffe3` peripheral-bus address, `0xffe4` DMA
control, `0xffe6`/`0xffe7` handshake transmit and receive, `0xffe8` interrupt status, `0xffe9` interrupt mask, `0xffea` interrupt
configuration, `0xffeb` interrupt polarity, `0xffec` miscellaneous, `0xffed` burst control, and `0xfffc`/`0xfffd` the left and right headphone
converters. Only the DSP-side addresses are new information; they rest on one source and are **inferred**.

## DMA

- Direction and mode: one DMA engine, one run at a time, moving SRAM words between the DSP's SRAM and main memory over the GIO bus.
  Normal mode moves one 24-bit DSP word per 32-bit memory word; folded mode pairs two DSP words with one memory word (the driver's ring-buffer
  types are "folded" and "unfolded", with a separate sign-extension bit). **Inferred.** How two 24-bit words fold into 32 bits (which bits
  survive) is **unknown**; open question 3.
- Completion: the end-of-DMA interrupt source (bit 1 of status and mask). No chaining; each run is started by software. **Inferred**
  (no descriptor registers exist in the list).
- The driver treats the DMA registers as write-then-go: count, both address halves, SRAM address, then the control word. Order is **unknown**
  (no driver object).

## Interrupts

- The DSP block's three sources are merged by the HPC and arrive at INT2 as the "DSP interrupt" bit `0x10` of local-I/O status register 1
  (mask bit the same); the IP20 header gives it local vector slot 12. **Inferred.** Which CPU interrupt line register 1 feeds follows
  from the IP20 interrupt wiring, not covered here.
- The driver's private header defines the mask bits the driver programs: end of DMA, DSP wrote transmit, DSP read receive.
  **Inferred.**

## Host-to-DSP protocol (what the headers imply)

- Two mailbox words (handshake transmit and receive) carry commands and replies; the driver keeps two ring buffers in main memory for
  them, a command-in ring (from the DSP) and a command-out ring (to the DSP), of 300 and 20 locations in the header's limits (named
  command and reply buffer sizes). **Inferred** (header sizes only; which is which and how a word is framed is unknown).
- Five DSP commands are numbered: create a host ring buffer (1), acquire a sample ring buffer (4), free it (5), change a sample ring
  buffer (6), change the audio parameters (7). Numbers 2 and 3 are unused in the header. **Inferred** (header only; wire format **unknown**).
- Shared SRAM words the host reads or writes at fixed word offsets: a monitor pass-through enable at 24, error flags at 28 (per-ring),
  error types at 32, error lengths at 36, error locations at 40, and left and right monitor attenuation at 48 and 49. Units are
  presumably DSP words. **Inferred.**
- DSP state machine in the driver: reset with no microcode, initialising (microcode loading), running. How the microcode reaches the DSP is
  **unknown**: the register set offers two routes, a DMA into SRAM followed by a hard-reset release, or word-by-word access through the
  SRAM window; neither is shown by any binary I hold. The microcode image itself, its name and its location are **unknown**.

## What the DSP does for audio (inferred)

The driver's old-style parameter table (recovered in kudzu's page from the shared audio object, which kept the old table) lists what the
host can set: input source (line, microphone, digital), left and right input attenuation, input and output sample rate (48000 Hz
default), left and right output gain, monitor control, speaker mute, a system channel mode, a microphone mode, and a digital-input rate.
That is the user-visible hardware: stereo line and microphone in, digital in (S/PDIF-class, rate read from the stream), stereo out, a
headphone/speaker mute and gain. The converters themselves, the digital receiver and how the DSP feeds them are **unknown**.

## Open questions

Recorded in [open-questions.md](../open-questions.md) as "Hollywood DSP audio block".

## Sources

- Shipped developer headers: the IP20 board header (HPC IDs, DSP register addresses and bits, interrupt bit and vector, DSP memory window),
  the HPC1 controller header (HPC1 numbering, SCSI only), the driver's two headers, and the inventory header (type 0). 6.5.22 developer
  sysroot.
- 6.5.22 `var/sysgen.IP27`, `IP30`, `IP35` `master.d/hdsp` and `master.d/kdsp` (read in full).
- Public emulator source for the HPC1 controller and the IP12 and IP20 boards, master branch as fetched 2026-11-11: register addresses,
  DSP-side addresses, SRAM chips, DSP part and clock, V50 remark. Third-party; used only to report agreement and for the facts marked
  single-source.
- Not read: the HPC1 and HPC1.5 specifications, the Indigo owner and hardware guides (library unreachable), Linux and NetBSD trees
  (neither supports the Indigo's audio; the checkouts were not initialised, so this is from general knowledge and **unverified**).
