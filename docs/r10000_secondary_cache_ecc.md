# R10000 family secondary-cache error detection and delivery

This page covers how the R10000 detects errors in its secondary cache and what it does when one is found: the check matrix for the secondary data array, how a syndrome is classified, the correction and delivery rules, and the CP0 CacheErr fields that describe the error. The constants for the CacheErr fields are in [devices/r10000_secondary_cache_ecc/registers.toml](../devices/r10000_secondary_cache_ecc/registers.toml), generated to [devices/r10000_secondary_cache_ecc/registers.md](../devices/r10000_secondary_cache_ecc/registers.md). Nothing here was read from silicon or from a running machine.

The O2 cache page, [docs/o2-cpu-cache.md](o2-cpu-cache.md), already covers which operations write check bits, the SCCorEn read rule, and the Status.DE suppression. This page does not repeat those rules.

## Source and grades

- MIPS, *R10000 Microprocessor User's Manual*, version 2.0, 29 January 1997, publication 007-2490-001. Printed pages 171–172, 176–179, 201–202 and 274–276 are cited below. The matrix is on printed page 178 (Table 9-5). The page numbers are the printed numbers, not the PDF page indexes.

Established means the manual states the fact. Inferred means a reasoned reading of the manual that the manual does not state in those words. Unknown items are listed at the end with what would settle them.

## Check bits for the secondary data array

- The secondary data array stores 128 data bits with nine check bits, ECC[8:0], and an even-parity bit, ECC[9]. Established (printed p. 178).
- For a 128-bit data word `d`, each check bit is the parity of `d` ANDed with a 128-bit mask. The mask for each ECC bit is below. Bit 127 is at the left of each mask. Established (printed p. 178, Table 9-5).
- ECC[9] is the even parity of the 128 data bits. Established (printed p. 178).

| ECC bit | 128-bit data mask | Data ones |
| ---: | --- | ---: |
| 8 | `ff03ffe306ff072162d0b0d000202080` | 53 |
| 7 | `ffff030fff0703b2100848c802909020` | 52 |
| 6 | `83ffff030503ff5c808404c438484850` | 53 |
| 5 | `42808012fcfbfc3ffd6202228504c408` | 52 |
| 4 | `214043ff808084ffff210101ffc20284` | 52 |
| 3 | `10232081444046bffc3fdf3f4c010142` | 52 |
| 2 | `0a12121823202100baffc0a0d0ffffc1` | 53 |
| 1 | `04090944131210084dc0e0ffe0c0ffff` | 52 |
| 0 | `010404200b0d0b4704e0ff60c3ffc0ff` | 53 |

The data-ones column counts the mask alone. The check-bit identity column adds one more, so the manual's printed row totals are 54 or 53. Each of the 128 data columns, read down the nine masks, has three or five ones: 84 columns have three and 44 have five. Established (printed p. 178).

The matrix does not establish the guest's byte order for a 128-bit quadword. It also does not establish the hardware's syndrome decoder.

The tag array has seven check bits. Its matrix is on printed page 179 and is not imported here. See the unknowns.

## Syndrome classification

- For a read quadword, XOR its stored ECC[8:0] with the nine parities from the masks above. The result is a nine-bit syndrome. Inferred from the matrix.
- The 128 data columns and the nine identity columns are 137 distinct nonzero values. None of the data columns is a single one-bit value. Inferred from the matrix.
- A syndrome equal to one of the 128 data columns names that data bit. A syndrome equal to one identity column names that check bit. Inferred from the matrix, for one bad protected bit.
- Any two bad bits give a nonzero syndrome of even weight. Every single-bit column has odd weight, so two bad bits cannot match a single-bit class. Inferred from the matrix, for two bad bits.
- Three bad bits can match a single-bit column. The manual does not publish the full decoder, so no classification is established beyond one or two bad bits.
- A parity-bit error alone gives a zero nine-bit syndrome. The manual does not say what signal results. See the unknowns.

## Reset input SCCorEn

- The reset-mode input SysAD[14] is SCCorEn. A value of one sends every secondary data read through the corrector. A value of zero checks the data parity first and sends the read through the corrector only after a parity error. Established (printed pp. 171–172, 201–202).
- With SCCorEn clear, two bad data bits leave the parity even. The parity check does not fire, so the corrector's reread does not run for that error. Inferred from the parity rule above.
- Whether the input is wired on any particular system board, and at what value, is not in the manual. See the unknowns.

## Correction and delivery

- In correction mode, a correctable secondary data error is repaired inline. The processor signals the external agent for one SysClk cycle. Established (printed pp. 171–172).
- An uncorrectable secondary data error posts a Cache Error. It records the data-error field and the secondary index in the local CacheErr. Established (printed pp. 171–172).
- When the error is posted, the processor copies the local CacheErr to CP0 CacheErr, sets Status.ERL, records the next ungraduated instruction in ErrorEPC and enters the uncached Cache Error vector. The vector is chosen by Status.BEV. Established (printed pp. 274–276).
- Status.DE stops future posting and local CacheErr updates. Covered on the O2 cache page.
- While Status.ERL is set, a nested Cache Error delivery is ignored. The processor still detects errors and may post more of them. Established (printed pp. 274–276).
- Index Load Tag and Index Store Tag, like Index Load Data and Index Store Data, suppress uncorrectable-error protection during the diagnostic operation itself. Established (printed pp. 274–276). A test that wants detection must follow the operation with an ordinary cached access. Inferred from the suppression rule.
- A single bad bit is not a valid test for an exception without first classifying its syndrome. Inferred from the classification above.

## CP0 CacheErr for a secondary error

- Bits 31:30 are the unit select. For a secondary-cache error they are binary `10`. Established (printed pp. 274–276).
- Bits 27:26 are the D field. It identifies an uncorrectable secondary data error by way. Established (printed pp. 274–276). The value encoding of D is not in the source. See the unknowns.
- Bits 25:24 are the TA field. It identifies a secondary tag error. Established (printed pp. 274–276). The value encoding of TA is not in the source.
- Bits 22:6 are the secondary block index, SIdx. Its source is PA[22:6] for a 64-byte secondary block or PA[22:7] for a 128-byte block. Established (printed pp. 274–276). The block size of the fitted secondary cache must be known before a test can assert an index value.

The constants for these fields are in [devices/r10000_secondary_cache_ecc/registers.toml](../devices/r10000_secondary_cache_ecc/registers.toml).

## Unknown, and what would settle it

- **Full syndrome decoder.** The manual gives the matrix and not the decoder, so classification is only established for one or two bad bits. Settled by a decoder published for the part, or a fault-injection capture on a real processor under a stated plan.
- **Parity-bit-only error.** The manual does not say which signal results when only ECC[9] is wrong and the nine-bit syndrome is zero. Settled by the manual's signal description or a capture.
- **SCCorEn on a given system.** Whether SysAD[14] is wired, and to which value, on any particular processor module. Settled by the module's schematic or its reset capture.
- **Secondary block size.** The block size of the fitted secondary cache sets which index width the SIdx field carries. Settled by the cache size and line configuration of the system.
- **D and TA encodings.** The manual gives the meaning of the D and TA fields and not the value for each way or tag condition. Settled by a capture of CacheErr after a known fault.
- **Tag matrix.** The seven-bit tag matrix on printed page 179 is not imported here. Settled by importing that matrix from the same page, with its own check against the printed counts.
- **R12000.** Whether the R12000 uses the same matrix, delivery rule and CacheErr layout. Settled by the R12000 processor manual or a capture from an R12000 part.
- **Physical capture.** No CacheErr capture from a real part for a secondary error exists in this repository. The manual states the rules, and a capture would show what a part does under a known fault.
