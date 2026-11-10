# VICE coverage

The VICE is the O2's video imaging and compression engine, a processor-and-DMA part on the CRIME's system bus. The chip
page held no entries ("presence only"). This page records what the shipped software and the published design specification
settle. Labels follow [AGENTS.md](../AGENTS.md): **established**, **inferred**, **unknown**.

Sources: IRIX 6.5.30 IP32 `kernel.o` (`add_ioboard` body at `0x8168`, `vice_err`, the error decode strings; all read in
full where cited), `usr/lib32/internal/libvice.so` (the user library, not stripped, `.text` of `0x20b0` bytes, read in
full for the routines cited), the VICE Design Specification 099-0123-003 (17 April 1997, [docs/specs.md](specs.md)) and the CRIME 1.5
specification ([docs/specs.md](specs.md)) for the CRIME interrupt status bit. Spec page numbers are the printed ones.

## Where it sits (established by agreement)

The window is physical `0x17000000` to `0x1700ffff` (VICE specification Table 2, p. 24). The kernel reaches it through the
uncached segment at `0xb7000000`, which agrees. Registers are 64-bit slots; the IRIX code
accesses them as 32-bit words at slot +4 (the low word of a big-endian doubleword), the same convention as CRIME's own
registers.

## The kernel's presence probe (established)

The body that follows the 8-byte `add_ioboard` symbol in IP32 `kernel.o` (`0x8168` to `0x81dc`, read in full; the
symbol's own body is a bare return) performs, in order:

1. Store 4 to `0x1700e014` (slot `0xe010`, the interrupt enable register, low word): enable bit 2, "MSP software interrupt
   to the Unix processor" (spec Table 12, p. 47). Wait 10 microseconds.
2. Store 0 to `0x170001bc` (slot `0x1b8`, the MSP software interrupt register, low word). The register is write-only; any
   write sets bit 2 of the interrupt status register (spec section 2.9.7). Wait 10 microseconds.
3. Read CRIME's interrupt status (`0xb4000010`) and test bit 31, the VICE interrupt (CRIME 1.5 specification Table 5-10).
   If clear, stop: no VICE.
4. If set: read the VICE interrupt status low word (`0x17000164`, slot `0x160`) and store it to the interrupt reset
   register (`0x1700e00c`, slot `0xe008`): write-one-to-clear (spec Table 10), so this acknowledges whatever is pending.
   Then register the part in the hardware inventory with class 15 (compression), type 3 (VICE), controller 0, unit 0, and
   the low word of slot `0x008` (the chip ID register, `0x1700000c`) as the state value.

So the probe is a loopback: arm an interrupt the part can raise by software, raise it, check that CRIME saw it. Every
register offset and bit agrees with the published specification (a match between a driver reading and a published page:
established for the offsets and bit positions). That the interrupt enable stays at 4 afterwards and where it is routed is
**unknown**: the routine does not clear it and no other held kernel routine touches the VICE window.

## Identification (established)

- The ID register at slot `0x008` is read-only and its reset value is `0xE1` (spec Table 6, p. 40). Bits 3:0 are the
  revision (1 = Vice-A, 2 = Vice-B "DX", 3 = Vice-C "TRE"), bits 7:4 the ID value `0xE` (spec Table 8, p. 44).
- `vice_file` (`libvice.so` `0xd002404`, read in full) chooses the directory the microcode is read from by the chip ID the
  driver returns: `0xe1` selects the first directory, `0xe2` a second whose name ends in "dx", anything else a third whose
  name ends in "tre". The three names line up with the specification's three revision names. That the driver's chip ID is
  the register value is **inferred**: the library's request for it is a driver ioctl (`0x76782000`), and the kernel's
  inventory state is that same register.
- The library refuses to run when the upper half of the driver's version (ioctl `0x7678001f`) is not `0x6b7a`.

## Error reporting (established)

CRIME's CPU error status (`0x48`) carries a VICE group. In the three-bit layout bit 1 is "Write parity error"; in the
ten-bit layout (CRIME revision 0 only) bits 8:5 are illegal instruction, SysAD parity error, SysCMD parity error and
invalid address ([CRIME page](../chips/crime/README.md#error-registers-established-decode)). The VICE error address
register at CRIME `0x58` is saved by the bus-error path and passed to `vice_err`. In this build `vice_err`
(`kernel.o` `0x1d554`, two instructions) is a return of 0: **the 6.5.30 IP32 kernel does nothing with a VICE error beyond
printing it.** Established (the whole routine is read).

## What the user library tells us (established unless marked)

`libvice.so` is generic: it holds no VICE register offsets. Its register access (`vice_pior`, `vice_piow`, `0xd001f18` and
`0xd001e54`) is a byte, halfword, word or doubleword load or store at a caller-supplied offset from a per-unit base, so the
chip is driven by code in the image-converter plugins, not by this library. The library:

- opens a per-unit device, queries the driver version and the chip ID, then maps **`0x14000` bytes** of the unit
  (`mmap` length `0x14000`, read-write, shared). The specification's chip window is `0x10000` bytes; the extra `0x4000` is
  not described. **Unknown** whether it is hardware (a second region) or a driver construct.
- sets the chip's 64-entry translation table through the driver (ioctl `0x76780004`, `vice_settlb`; the table is at
  slot `0xf000`, spec Table 2) and updates it through a further ioctl; locks the unit through `0x76780006`.
- loads microcode for the two processors (`vice_load_msp_code`, `vice_load_bsp_code`, `vice_load_bsp_table`) from files:
  the instruction memories are at `0x2000` (MSP) and `0x4000` (BSP), the BSP table memory at `0x5000` (spec Table 2). The
  load routines were not read: the load order and the reset sequence around them are **unknown**.
- builds DMA buffers and an event path (`vice_dmbuf_*`, `vice_event_*`) over the system's media buffer library; not read.

## Still open

| item | route | discriminating test |
|---|---|---|
| The kernel VICE driver (ioctl handlers, interrupt routing, the extra `0x4000` of the mapping) | none held: no IP32 kernel object other than the probe above touches the window | trace a user-library open on a model and log the window accesses |
| MSP and BSP reset and microcode load sequence | read `vice_load_msp_code`, `vice_mload_msp_code`, `vice_load_bsp_code` and the converter plugins | write a known program and read back the program counter registers `0x50` and `0x140` |
| Whether the probe's interrupt enable is cleared later | search the converter plugins | read `0xe010` after the probe |
| Register fields beyond those in the specification | none; the specification is the only source | none needed until a supported guest uses them |
