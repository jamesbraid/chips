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
  reading ties the field to the cache size. The manual does not give the encoding,
  so the meaning of the other mode-word bits is unknown.
- **Unknown**: the mode-word encoding of the 195 MHz, 4 MB configuration. This page
  derives no value for it.
- **Unknown**: the node count, processor population, assembly suffix and silicon
  stepping of any board. The configuration block does not carry them.

## Sources

- SGI 108-0164-002, *Origin2000 and Onyx2 Diagnostic Roadmap*, printed E-4, PDF page 108.
- SGI 108-0170-001, *Origin200/2000 IP27 PROM Technical Reference Manual*, printed 4-34,
  PDF page 88.
- The PROM 6.156 payload, SHA-256 `c2c69bf33c375b43ec7ac511fab41ddf595be1b6838ae717e58a9a1273437fdd`,
  bytes `0x60` to `0xa7` read for the fields above. Only those bytes were read; no
  instruction was decoded.
