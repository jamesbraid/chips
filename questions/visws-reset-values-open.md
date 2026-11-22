# SGI Visual Workstation 320 and 540: reset values and register extents

Open points left after reading the shipped firmware and HAL accesses to every Cobalt and Lithium register for a reset value
([Cobalt](../devices/cobalt/README.md#reset-values-extents-and-widths-what-the-shipped-code-settles),
[Lithium](../devices/lithium/README.md#reset-values-and-the-bridge-words-nobody-documents-what-the-shipped-code-settles)).
Each entry: question, routes tried, what would settle it.

## Reset value of any Cobalt or Lithium register

[missing source] No shipped code reads these registers before writing them, except the Cobalt revision and the two Lithium bridge
identification words, which are read-only. Tried: both PROM modules, the boot block, the self-test and the NT HAL, by
disassembly; Linux; two other HAL builds. Not tried: Windows 2000's HAL accesses, the NT Ethernet, USB and SCSI drivers, and the
Linux driver for any later chip revision. Settles it: the Cobalt and Lithium specifications. For the registers firmware never writes, a read-only sample taken from the PROM
monitor (its `dump`, `get` and `ioread` commands), after power-on and before any operating system has run, would be a reset
value: the Cobalt CPU block's `+0x10`, `+0x20`, `+0x30`, `+0x38`; the thirty interrupt entries; the bridges' `+0x04`, `+0x06`,
`+0x40` and `+0x46`. Smallest test: those words, 32-bit reads, on one machine; the status and current-count words are plain
reads in every code path read, but whether any word is read-to-clear is unknown, so the bridge offsets other than the four named
are excluded. It needs the owner's approval and a named machine; it has not been run. Registers the PROM writes (the id word,
bridge `+0x44`, `+0x48`, `+0x58`, `+0x60` to `+0x70`, the memory controller) cannot be sampled this way.

## Extents of the three Cobalt blocks and the two bridge windows

[missing source] Software maps one page and uses offsets up to `0xffc`. Settles it: the specification, or the PROM's address decode
table if one is ever found.

## Timer: does a write while running reload the count

[missing source] The HAL's calibration needs it to; the hardware behaviour is inferred. Settles it: the specification, or a real
machine's calibration result (the HAL prints none).

## Lithium `+0x40`, `+0x48`, `+0x58`, `+0x60` to `+0xdc`: bit meanings

[missing source] Only the firmware's two setting names give any, and the ISP2100 adapter's bits 9:8. Settles it: the Lithium specification; a driver that reads
`+0x48` after an error (the USB driver prints it but nothing was found that reads it before the clear); Windows 2000 HAL.

## Lithium interrupt enable: bits 15:14

[missing source] The self-test shows bits 13:8 settable, nothing shows 15:14. Settles it: the specification or an extended read
by the self-test of a real machine.
