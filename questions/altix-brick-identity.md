# Altix brick identity: type characters, EEPROM and KLCONFIG contents

Route tag: `software now` for the first and third items (SN2 PROM images are in `root/sn2/`), `missing binary` for the
EEPROM and L1 records.

**Question.** What does an Altix 3000 C-brick, a Bx2 CR-brick and an Altix 350 module report as its brick type character,
what do the 350's serial ID EEPROMs hold, and what exactly does the PROM write into the KLCONFIG board list and each
`hubdev_info` geoid?

**Settled** ([brick-identity.md](../platforms/sn2/brick-identity.md)): the module-id layout, the L1 type codes in Linux
v5.3, the KLCONFIG structure and what Linux reads from it, the geoid fields and the location-string format.

**Open**
1. The Altix 350 module type character. The Altix 3000 C-brick is settled: its L1
   reports `5` (IP41) and the PROM folds it to `c` (see the 2026-11-21 section below). The CR-brick: its L1 reports `@` (inferred, the ARM `Vortix`
   family, four IP57 nodes and two NL4 routers; sysco `arm-brick-identity-1.62.1.md`) and the PROM folds it to `c`. Still open: a real brick's board record.
2. ~~Whether the PROM stores the raw or the folded character in the module id.~~ Folded: `0xffa7d510` turns `5`, `o`, `m` and `@` into
   `c` before packing the word ([l1-requests.md](../software/firmware/snprom/l1-requests.md)). Which character a 350 L1 sends stays open.
3. Which board kinds the PROM puts in each brick's KLCONFIG list, and the geoid values it writes for a C-brick, CR-brick
   and 350 module. Needs the PROM's list builder and `SN_SAL_IOIF_GET_HUBDEV_INFO` handler read in Ghidra.
4. The IP57 and interface-board EEPROM layouts (not printed in any guide read).
5. The router-to-node link map of the CR-brick and the meaning of the Altix 350 rear labels IS1, IS2 and REPEAT.

**Routes tried.** Linux v5.3 and v2.6.12 headers and the files that use them; the three guides; a search of held sources for an
M-brick (found only two comments).
**Next route.** Read the `snprom` SAL handlers in Ghidra (`retools/tools/re-run --ghidra-export --sn2-prom`) for the
KLCONFIG builder; a captured `config` line or `/proc/sgi_sn/sn_topology` from real hardware, if any is published.

## Altix 3000 C-brick: SHub generation and board code (2026-11-21)

Settled: the 3300 and 3700 C-brick are SHub 1 ([altix-3000.md](../platforms/sn2/altix-3000.md#shub-generation)).

Established for the L1 and PROM logic (L1 1.62.1 `2MB image` and SAL 5.04, [altix-3000.md](../platforms/sn2/altix-3000.md)), inferred
for a real brick's record: the C-brick is `C (IP41)`, type character `5`. The L1 picks it from the product name of its board record `0xfe`; its `0x0003` reply is `rack << 6 | bay`
then `0x35`; the PROM folds `5` to `c`. An emulated 3300 C-brick L1 therefore answers `0x0003` with `0x35` (or `C`, which lands
on the same `c`) and keeps the board name `IP41`. `IP45` is the Origin 300 board and `IP37` has no identity route.

Still unknown: the contents of a real C-brick's record `0xfe` EEPROM (the L1 compares only the first four characters of its
product name), the SHub 1 stepping on the brick, (the Bx2 is SHub 1.2 per its guide's figure, see the Bx2 page). Route: an EEPROM info area or `/proc/sgi_sn/sn_topology` capture from a 3300 or 3700.
