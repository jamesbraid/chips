# O2 system ROM: decode, flash aliasing and reset fetch

This page covers the O2's system ROM window as CRIME and MACE expose it, the external flash that MACE drives,
and the R10000 reset vector that lands in that window. It holds prose facts only. The MACE control bits are in
[devices/mace/registers-extra.toml](../../devices/mace/registers-extra.toml), and the flash part's command protocol is in
[at29c040a.md](../../devices/at29c040a/README.md).

Sources:

- SGI, *CRIME 1.5 Specification*, revision 0.3 (2 June 1997), Table 3-1 on printed page 3-4. Read from the
  [retained copy](../../references/documents/specs/crime-1.5-specification-rev0.3.pdf).
- SGI, *MACE I/O ASIC Specification*, chip revision 2.0 (July 16, 1996), section 5.5 on printed page 133. Read from the
  [retained copy](../../references/documents/specs/mace-specification.pdf).
- MIPS, *R10000 Microprocessor User's Manual*, version 2.0 (October 10, 1996), printed pages 323, 332 and 336. The
  manual is not retained in this repository. These entries are transcribed and not yet checked against the PDF.
- Atmel, *AT29C040A* datasheet, revision `0333I-FLASH-05/02`. Used for the photographed parts below. See
  [at29c040a.md](../../devices/at29c040a/README.md) for its status.

## Decode (established, CRIME p. 3-4, MACE p. 133)

- The 4 MB region at physical `0x1fc00000` is the system ROM, and CRIME assigns it to MACE (CRIME Table 3-1).
- MACE drives an external ISA flash of 512 KB to 2 MB. A smaller device is aliased to fill the whole 4 MB region
  (MACE section 5.5).
- A 512 KB device therefore appears eight times in the region, a 1 MB device four times and a 2 MB device twice.
  These counts are arithmetic on the aliasing rule.

## Flash access (established, MACE p. 133)

- The external flash interface accepts only single-byte writes. Software writes one byte at a time.
- Reads may be one to eight bytes wide.
- Software must set the flash write enable in the MACE control register before writing, and the spec advises
  leaving it clear otherwise. The bit's reset value and its effect on writes are in
  [devices/mace/registers-extra.toml](../../devices/mace/registers-extra.toml) (`ISA_MISC_FLASH_WRITE_ENABLE`, established).

## Reset fetch (established for the manual text, transcribed)

- The Cold Reset vector is virtual `0xbfc00000` in 32-bit mode and `0xffffffffbfc00000` in 64-bit mode
  (R10000 manual, printed pp. 332 and 336).
- In the uncached kseg1 segment that address maps to physical `0x1fc00000` (printed p. 323), the first byte of the
  ROM window above.
- The manual does not say which byte a given O2 board's processor fetches first. That needs an execution
  observation on a machine with that processor.

## Photographed flash parts (inferred)

- Two published board photographs show a socketed AT29C040A at U203. One is a `030-1227-001` board with an
  `AT29C040A 12TC` marking, and the other a `030-1038-000 REV A` board with an `AT29C040A 15TC` marking. The
  marking is read from a photograph, so each identity is inferred until a board is read directly. The `-12TC`
  and `-15TC` suffixes are the 120 ns and 150 ns commercial TSOP parts in the Atmel ordering table.
- The photographs do not show whether U203's address, chip-enable, output-enable or write-enable pins reach
  MACE's flash interface. That connection is inferred and needs a schematic or a continuity record for the board
  revision.
- The BaseIO board's AM29LV800B in [baseio.md](../../devices/baseio/README.md) is a different board and is not this part.
- Other O2 revisions, the fitted parts' initial protection and boot-block lock states, and the offset of a
  programmed image are unknown. They are listed in [open-questions.md](../../questions/README.md).
