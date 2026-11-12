# Origin 2000 node board: processor, Hub and secondary-cache configuration

Each Origin 2000 node board takes its processor clock, Hub clock, machine type and
secondary-cache size from configuration data stored in the node board's boot flash.
This page covers the published configurations, the rules SGI gives for mixing and
copying node PROMs, and the layout of that configuration data in the shipped PROM
image. It holds no register contract: the Hub registers are in
[gen/docs/hub.md](../gen/docs/hub.md) and the PROM's own behaviour is in
[ip27-prom-node-numbering.md](ip27-prom-node-numbering.md).

Each fact carries its grade. The grades follow the repository's rules: established
means a published SGI manual states it, inferred means a reasoned reading or a
software expectation taken from a shipped binary.

## Published configurations

- **Established** (*Origin2000 and Onyx2 Diagnostic Roadmap*, SGI 108-0164-002,
  printed E-4, PDF page 108): the flash procedure names two configurations. The
  first is a 180 MHz CPU, a 90 MHz Hub and a 1 MB secondary cache per processor. The
  second is a 195 MHz CPU, a 97.5 MHz Hub and a 4 MB secondary cache.
- **Established** (same page): the flash procedure asks for CPU frequency, Hub
  frequency, machine type (0 for SN0, 1 for SN00) and cache size in megabytes. The
  prompts list the two machine types the manual names.

## Mixing node boards

- **Established** (same manual, printed E-4): a system functions best when all node
  boards, across every module and not only within one, share a PROM revision level.
  All node boards must run at the same clock speed, and each must be flashed with the
  correct user-entered values.
- **Established** (same page): the rule is about board speed, not about the processor
  part. The manual does not say whether a system may hold two processor types at
  once, so that question is unknown here.

## Reflashing node PROMs

- **Established** (same page): a PROM flash from the monitor or from IRIX updates the
  firmware and reuses the configuration values already stored in the PROM, unless the
  flash is told to change them. The option that changes them is `-f`. Leaving it out
  keeps the stored clock, cache and machine-type values.
- **Established** (*Origin200/2000 IP27 PROM Technical Reference Manual*, SGI
  108-0170-001, printed 4-34, PDF page 88): copying one node's PROM into another
  node by the PROM's flash command does not reconfigure the copy. The manual warns
  against copying a PROM to a node whose secondary-cache size or clock speed differs
  from the source node's.

## Boot-flash configuration block

The PROM image holds the configuration values in plain big-endian fields near the
start of the boot flash. Offsets below are payload offsets: the flash address
minus `0x1fc00000`. These values were read from the PROM 6.156 payload whose
SHA-256 is recorded in [ip27-prom-node-numbering.md](ip27-prom-node-numbering.md)
(the "IP27 CPU PROM, PROM 6.156" row). Only this image was read for this page.

| Payload offset | Width | Field | Value in PROM 6.156 | Grade |
|---|---|---|---|---|
| `0x64` | 32 bits | Processor mode word | `0x1211a785` | inferred |
| `0x70` | 64 bits | Processor clock, Hz | 180000000 | inferred |
| `0x78` | 64 bits | Hub clock, Hz | 90000000 | inferred |
| `0x80` | 64 bits | Real-time counter, Hz | 1250000 | inferred |
| `0x8c` | 32 bits | Flash read controller field | 8 | inferred |
| `0x90` | 32 bits | Machine type | 0 | inferred |
| `0x9c` | 32 bits | Flash write controller field | 1 | inferred |
| `0xa0` | 32 bits | Firmware version | 6 | inferred |
| `0xa4` | 32 bits | Firmware revision | 156 | inferred |

- **Inferred**: the clock, cache and machine-type fields agree with the 180 MHz,
  90 MHz Hub, 1 MB published configuration above. The real-time counter rate of
  1250000 Hz matches the rate the PROM uses for its microsecond timer.
- **Inferred**: the mode word's cache field is `1` for the 1 MB configuration. That
  reading ties the field to the cache size. The R10000 manual gives the encoding
  (see [Processor reset mode](#processor-reset-mode)) and confirms it.
- **Unknown**: the rest of the mode word for the 195 MHz, 4 MB configuration. Its
  cache field is three (see the same section); no other bit of that word is derived here.
- **Unknown**: the node count, processor population, assembly suffix and silicon
  stepping of any board. The configuration block does not carry them.

## Processor reset mode

The processor takes its reset mode from the system data bus, not from the boot flash.
The stock PROM compares that mode with the flash mode word at offset `0x64` (see the
cold-start check below), so the two must agree for boot to continue.

- **Established** (*MIPS R10000 Microprocessor User's Manual*, version 2.0, printed
  pp. 160–165 and 256): the processor loads its reset mode from the system data bus
  during power-on or cold reset. The low 25 bits of that mode become CP0 Config bits
  24:0. A soft reset preserves the mode bits.
- **Established** (same pages): the primary-cache size fields of Config are hardwired.
  A mode word cannot change them. Bits 31:25 of the 32-bit word are not loaded into Config.
- **Established** (same manual, printed p. 165): Config bits 18:16 give the secondary-cache size, with value one for 1 MB and value three for 4 MB.
- **Established** (*Hardware Quick-reference Booklet (Origin and Onyx2 Series)*,
  HMQ-380-C, printed p. 93): the IP27 node-board assemblies are a 1 MB assembly with a
  180 MHz processor and a 4 MB assembly with a 195 MHz processor. The booklet does not
  document a 195 MHz board with 1 MB, or a 180 MHz board with 4 MB.

## Cold-start mode-word check

The stock PROM checks the flash mode word against the processor's Config register
early in the cold start. This is a software expectation read from the PROM 6.11 image,
SHA-256 `14e0d0a77b92154e3b33573f30608f241ded249db6060fba9f97bfd00b2145b2`.
The reading comes from static decoding of payload offsets `0xc00` to `0xe3f`. It shows
which accesses and comparisons the code makes. It does not show which branch a given
boot took, so the grades below are inferred.

- **Inferred**: on the cold-start path, before I2C initialisation, module discovery
  and console setup, each processor reads the mode word from flash offset `0x64`
  (node-local address `0x10000064`; reset-window alias `0x1fc00064`). It also records
  its progress in the Hub real-time compare register for its slice (`0x01000108 + 8 × slice`).
- **Inferred**: the processor writes the word into CP0 Config, reads Config back, and
  compares bits 15:0 with the word. It then rereads the flash word, reads Config again,
  and compares bits 24:16. Both halves must agree under mask `0x01ffffff`. Bits 31:25
  are not compared. The check does not copy the whole word into an ordinary writable
  register, because reset-configuration and hardwired Config fields keep their meanings.
- **Inferred**: a mismatch in either half enters a failure path. That path writes `0xb4`
  to the slice's progress location, reads the machine-type word at `0x10000090`, and
  writes `0xb4` to an LED location chosen by that type: `0x01220050 + 8 × slice` for
  machine type zero, and `0x01220080 + 32 × slice` for any nonzero type in this image.
  It then calls the PROM's processor-stop routine.
- **Inferred**: a match in both halves continues to the first normal I2C access, a
  64-bit write at `0x01220008`. The check therefore gates everything after it. A
  mismatch is reported only through the LED value, because the console is not yet set up.

## Sources

- SGI 108-0164-002, *Origin2000 and Onyx2 Diagnostic Roadmap*, printed E-4, PDF page 108.
- SGI 108-0170-001, *Origin200/2000 IP27 PROM Technical Reference Manual*, printed 4-34,
  PDF page 88.
- The PROM 6.156 payload, SHA-256 `c2c69bf33c375b43ec7ac511fab41ddf595be1b6838ae717e58a9a1273437fdd`,
  bytes `0x60` to `0xa7` read for the fields above. Only those bytes were read; no
  instruction was decoded.
- MIPS, *R10000 Microprocessor User's Manual*, version 2.0, 10 October 1996, printed
  pp. 160–165 and 256 (reset mode, Config fields), and printed p. 165 (secondary-cache
  size encoding).
- SGI, *Hardware Quick-reference Booklet (Origin and Onyx2 Series)*, HMQ-380-C, printed p. 93.
- The PROM 6.11 payload, SHA-256 `14e0d0a77b92154e3b33573f30608f241ded249db6060fba9f97bfd00b2145b2`,
  payload offsets `0xc00` to `0xe3f`, statically decoded for the cold-start check. No guest was run.
