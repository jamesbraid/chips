# Cobalt: the Visual Workstation system ASIC (CPU block, interrupt controller, timer)

Mode: **no-spec**. No Cobalt specification, BIOS or NT driver is held, and SGI said the hardware documentation does not
exist in a releasable form ([sources](../../references/visws-sources.md)). Everything here comes from SGI's Linux
platform code for the Visual Workstation 320 and 540 (kernel 2.2 to 3.14). For this machine that code ranks as the
vendor's software source: what it defines is **established**, as a software definition, never as a measurement. What
it only implies is **inferred**; the rest is **unknown**. The platform is in [platforms/visws](../../platforms/visws/README.md);
this page covers the system side of the chip. Registers: [registers.md](registers.md) (seven registers and constants).

The chip also holds the 3D rendering engine and the video-out DMA to the Arsenic chip; those are the graphics pages'
business and nothing below describes them beyond the interrupt lines they use.

## What the chip is

- **The system ASIC (established).** The kernel's own documentation says the Visual Workstations "are based around the
  Cobalt, Lithium, and Arsenic ASICs", and that Cobalt "interfaces the 1-4 IA32 cpus, the memory system, and the I/O
  system in the Lithium ASIC", and that it contains the 3D engine, which renders into main memory, part of which is the
  frame buffer. So Cobalt is the Pentium II/III front-side-bus bridge and memory controller, with the graphics engine
  inside it, in the O2's unified-memory style. A 1999 post by a user calls it "the memory/graphics unified memory
  architecture of the O2 sitting on top of the crossbar switch of the Octane/Origin (Lithium)" (inferred: not an SGI
  statement, and the crossbar claim has no support in any code).
- **Four processors at most (established, software).** The kernel accepts a count up to `CO_CPU_MAX`, 4, from a table the
  firmware leaves at low memory (see below). The shipped machines had one or two slots (inferred, posts by owners).
- **It is not behind the processors' own interrupt wiring.** The standard PC interrupt path (8259 into the processor's
  local APIC) is bypassed: nearly every interrupt goes to the Cobalt interrupt controller, which delivers to the
  processors' local APICs (next section).

## Where it lives (established)

| What | Physical address | Source of the address |
|---|---|---|
| CPU block (timer, revision) | `0xc2000000` | `CO_CPU_PHYS`, mapped through the kernel's fixed map |
| Interrupt controller | `0xc4000000` | `CO_APIC_PHYS` |
| Processor count and table | `0x1e00`, table at `0x1e02` | `CO_CPU_NUM_PHYS`, `CO_CPU_TAB_PHYS`; written by firmware |
| Local APIC of each processor | `0xfee00000` (the Intel default) | `APIC_DEFAULT_PHYS_BASE`, used as is |

The kernel maps each block with one fixed page, so the extents are unknown. The interrupt controller's identification
register is at offset `0xffc` of its block, so that block is at least 4 KiB. Registers are accessed as 32-bit words
only; nothing in the code uses a narrower access.

## CPU block: revision and system timer (established)

Four registers (see [registers.md](registers.md)):

- **Revision** at `0x08`, read only. The kernel prints it. In the 2.4 interrupt path it is read once after a driver's
  handler returns "to sync driver ack to its h/w", that is as a read that forces earlier posted writes to complete before
  the end-of-interrupt.
- **Control** at `0x10`: bit 2 runs the timer, bit 3 masks its interrupt (0 is unmasked).
- **Status** at `0x20`: bit 1 is the timer interrupt pending bit, read as 1 when pending, cleared by writing 0 to it. The
  2.2 and 2.4 handlers clear it on every tick. **The 2.5 to 3.14 code never does** (read in full: the start-up routine
  and the interrupt chip methods never touch the register). Either hardware drops the pending bit by itself when the line
  is acknowledged, or those kernels never ran correctly on the machine; the code was marked unmaintained from 2001 and
  a later maintainer converted it for 2.5 (a name appears in the file header), which suggests it ran. **Unknown.**
  An emulation should clear the pending state on a write of 0 and also deassert the line when the mask bit is set, which
  satisfies both kernels.
- **Time value** at `0x30`: the kernel writes `100,000,000 / HZ` (so 1,000,000 at HZ 100) as a "countdown value", sets
  the run bit, then clears the mask bit. The comment calls the number the Cobalt core rate divided by the tick, so the
  core clock is 100 MHz (established). The register is used as the periodic tick, with no reload ever written, so the
  count reloads itself (inferred). Whether it counts down by core clocks exactly, and what a read returns, is unknown.
- **The timer's interrupt** is interrupt line 28 of the controller (`CO_APIC_CPU`, "Timer and Cache interrupt") and
  appears to the kernel as interrupt 0, so the PIT is not used on this machine. The header's phrase "and Cache interrupt"
  means a second source shares line 28; no code handles one. **Unknown.**
- Processors other than the first take their ticks from the local APIC timer, not from Cobalt (the SMP code is the
  stock one). Only the boot processor needs Cobalt's timer. Inferred from the absence of any other write to these
  registers.

## Interrupt controller (the "Cobalt APIC")

### Registers (established unless stated)

- Thirty entries, 0 to 29, one per input line. Entry `n` is two words: the low word at `0x10 * n` and the high word at
  `0x10 * n + 4`. The low word holds the vector in its low byte (inferred width), the level-trigger flag in bit 15 and the
  mask in bit 16 (0 enables). Every entry the kernel enables is level-triggered. The high word is written zero and never
  read; by the layout it is the destination (inferred).
- The identification register at `0xffc`. Bit 8 enables the whole controller; the kernel sets it by read-modify-write and
  comments that the identification must not change. Where the identification field is, its value and the controller's
  reset state (enabled or not) are unknown.
- The vector the kernel writes is its irq number plus `0x20` (`FIRST_EXTERNAL_VECTOR`), not the line number. Interrupt
  numbering in the 2.5 and later code is: 0 for line 28, 14 and 15 for the two IDE lines, `16 + n` for line `n` (`CO_IRQ`)
  for everything else, and 1 to 15 for the "virtual" interrupts behind the PIIX4's 8259 pair (see the platform page).
  The older 2.2 and 2.4 code used the legacy numbers as vector offsets directly (`0x20 + irq`); the delivered vectors
  differ between kernel versions because the numbering scheme did, not because the hardware did.

### Sequence (established, from the 2.6.33 interrupt-chip methods)

1. Start-up of a line: write the low word (level flag plus vector), then the high word (zero).
2. Acknowledge (on delivery): write the low word with only the mask bit, read it back (a flush), then write the local
   APIC's end-of-interrupt register.
3. End (after the handler): rewrite the low word with level and vector if the line is neither disabled nor in progress.
4. Disable: same as acknowledge's mask step.

So a masked line with its source still asserted re-delivers when unmasked, as a level input does. The EOI goes to the
processor's local APIC, not to Cobalt, as the kernel treats the controller as a source that behaves like an I/O APIC.
Whether Cobalt itself tracks an in-service state (the I/O APIC's remote IRR) is **unknown**: the kernel masks before the
EOI and unmasks afterwards, which hides the difference. A model that implements mask, level-follow and a per-entry
vector, and raises the local APIC input, matches everything the kernel does.

### Line assignments (established, from the header)

See [the interrupt page](../../platforms/visws/interrupts.md) for the table, the board-revision exceptions and the PCI
routing.

### As the NT HAL drives it (established, `halborg.dll` 1.3)

Full detail and addresses are in [hal-hot-path.md](../../software/visws/hal-hot-path.md) and
[nt-hal.md](../../software/visws/nt-hal.md#interrupt-delivery-in-the-hal); the register fields are in
[registers.md](registers.md).

- **Entry format.** Low word: vector in bits 7:0, delivery mode in 10:8 (0 fixed for devices, 4 NMI for entry 29), destination
  mode in bit 11 (physical 0, logical 1), remote-IRR style bit 14, level bit 15, mask bit 16, and a bit 17 that the HAL
  treats as "not supported" if it reads set after writing the NMI entry (meaning unknown). High word: destination in bits 31:24.
- **Start-up.** All 30 entries are written with low word `0x10000` (masked), high word 0. Then the id register (`+0xffc`) is
  read; if bits 27:24 are zero the HAL writes 4 into them (with the enable bit clear), then sets the enable bit (bit 8).
- **Vector programming and unmask.** `HalEnableSystemInterrupt` keeps a use count per entry. The first user of an entry
  below 16 first sets the entry's bit in the owning Lithium bridge's 16-bit enable at window `+0x46` (entries 0 to 7 in
  bridge A, 8 to 15 in bridge B, read-modify-write under a lock), then writes the entry's low word as `vector | 0x8000`
  (level, unmasked, fixed, physical) and then the high word as 0. The vector comes from one of three 30-entry tables chosen by
  board generation (decoded from the image; entries 12 and 22 are `0xb9` and `0xb2` in all three, the clock entry's own vector
  `0xd1` is not taken from the table).
- **Mask.** The last user to disable an entry reads the low word and writes it back with bit 16 set; the high word is
  rewritten unchanged. The bridge's enable bit is never cleared again.
- **Destination and CPU choice.** Every device entry and the clock get destination 0 (physical): the HAL has no per-CPU
  steering. Its `INTAFFINITY` boot option sets a flag that nothing in the image reads. Only the NMI entry is logical: low
  word `0x8ff`, high word one bit per processor id, `1 << processor number` of the processor that sets it (the bootstrap
  processor), then delivery mode NMI added. The local APICs use the flat model with logical id `1 << processor number`
  (destination format register `0xf0000000`). Whether processor id 0 is the bootstrap processor on a real 540 is not
  shown (the table the firmware leaves says which entries exist; see the questions page).
- **Acknowledge.** None: the HAL writes nothing to the controller on delivery or at the end of an interrupt (the local APIC
  EOI only), unlike Linux 2.6, which masks the entry first and rewrites it at the end.
- **Line 22.** The HAL's vector for entry 22 (Linux's audio line) is `0xb2` in all three tables. The NT audio driver connects
  no interrupt and polls instead ([devices/lithium](../lithium/README.md)).

## CPU-block status and the memory-controller block (established for what the HAL touches)

CPU status `+0x20` bit 0 is a cache-operation interrupt (unexpected; cleared by writing all ones but bit 0) and bit 1 the timer.
CPU `+0x18` bit 0 resets the machine on early boards; `+0x38` is the timer's current value, counting down. The memory block at
`0xc6000000` holds, for the HAL, `+0x00` (bit 0 ECC enable), `+0x18` (error status), `+0x28` (error address) and `+0x30`
(syndrome): see [registers.md](registers.md).

## Memory controller (unknown)

No Linux code programs the memory controller: the memory size is handed over by the loader (see
[boot and detection](../../platforms/visws/boot-and-detection.md)) and the kernel never sees a bank register, ECC
status or refresh setting. Facts about the memory itself, from users' posts only (inferred): 100 MHz SDRAM, 256 bits wide
plus ECC, in banks of six non-standard DIMMs; the 320 had two banks of 128, 256 or 512 MB (1 GB maximum), the 540 had
four banks (2 GB maximum), the first bank always populated. Nothing says how the controller decodes banks, interleaves
or reports ECC errors. The shipped NT HAL does touch the block, but only the ECC enable bit (register `+0x00`), the error status, address and syndrome (`+0x18`, `+0x28`, `+0x30`) and the clear-by-zero of the status ([nt-hal.md](../../software/visws/nt-hal.md#cobalt-registers-the-hal-programs), established); it reads no bank register, and the firmware writes the bank registers ([boot-path.md](../../software/visws/boot-path.md#memory-controller-and-graphics-memory)). Bank decoding and the register reset values stay unknown. **What would settle it:** the Cobalt specification, or a read of a real machine.

The frame buffer is the top 8 MB of memory that the kernel reserves from its own memory map; see the platform page.

## Unknown, and what would settle it

| Unknown | Route |
|---|---|
| Interrupt controller reset state and enable default | The HAL does not depend on it (it masks all 30 entries at start-up); a boot log line `Cobalt APIC enabled: ID reg` on a real machine, or the specification |
| Meaning of the identification field | The HAL and the firmware both write 4 into bits 27:24 when they read zero, and the HAL's NMI entry uses logical destination mode with a processor bit in the high word (established for the HAL); what the field means is unknown: the specification or a boot log |
| Whether the timer's pending bit self-clears | A real machine running 2.6 with a status read in the handler |
| Bus-error and cache interrupt sources on line 28 | The HAL's timer handler treats status bit 0 as an unexpected cache-operation interrupt and bit 1 as the timer; further sources: the specification |
| Revision register values and meaning | Boot logs from real boxes (the kernel prints the value) |
| Anything the graphics engine does through this block | The graphics pages |
