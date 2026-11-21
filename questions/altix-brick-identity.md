# Altix brick identity: type characters, EEPROM and KLCONFIG contents

Route tag: `software now` for the first and third items (SN2 PROM images are in `root/sn2/`), `missing binary` for the
EEPROM and L1 records.

**Question.** What does an Altix 3000 C-brick, a Bx2 CR-brick and an Altix 350 module report as its brick type character,
what do the 350's serial ID EEPROMs hold, and what exactly does the PROM write into the KLCONFIG board list and each
`hubdev_info` geoid?

**Settled** ([brick-identity.md](../platforms/sn2/brick-identity.md)): the module-id layout, the L1 type codes in Linux
v5.3, the KLCONFIG structure and what Linux reads from it, the geoid fields and the location-string format.

**Open**
1. The CR-brick, Altix 350 module and Altix 3000 C-brick type characters (`c` or the board-name codes `4` and `5`).
2. Whether the PROM stores the raw or the folded character in the module id.
3. Which board kinds the PROM puts in each brick's KLCONFIG list, and the geoid values it writes for a C-brick, CR-brick
   and 350 module. Needs the PROM's list builder and `SN_SAL_IOIF_GET_HUBDEV_INFO` handler read in Ghidra.
4. The IP57 and interface-board EEPROM layouts (not printed in any guide read).
5. The router-to-node link map of the CR-brick and the meaning of the Altix 350 rear labels IS1, IS2 and REPEAT.

**Routes tried.** Linux v5.3 and v2.6.12 headers and the files that use them; the three guides; a search of held sources for an
M-brick (found only two comments).
**Next route.** Read the `snprom` SAL handlers in Ghidra (`retools/tools/re-run --ghidra-export --sn2-prom`) for the
KLCONFIG builder; a captured `config` line or `/proc/sgi_sn/sn_topology` from real hardware, if any is published.

## Altix 3000 C-brick: SHub generation and board code (2026-11-21)

Settled: the 3300 and 3700 C-brick are SHub 1 ([altix-3000.md](../platforms/sn2/altix-3000.md#shub-generation)). Still
unknown: which L1 type (`C (IP37)`, `C (IP41)` or `C (IP45)`, strings in `l1-1.62.1.bin`) is the 3000 C-brick, the SHub 1
stepping on it, and whether the Bx2 is SHub 1 or 2 (`README.snprom` lists it for the SHub 1 image). Route: an EEPROM
info area or `/proc/sgi_sn/sn_topology` capture from a 3300 or 3700; the SAL 5.04 board-identity code in Ghidra.
