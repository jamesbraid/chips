/* generated from devices/shub/registers.toml by defs-gen - do not edit, change the source */
/* SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs */
#ifndef SHUB_GEN_H
#define SHUB_GEN_H

#include <stdint.h>


/*
 * Chip identification word at node offset 0x1_0000_0000 (memory and directory block by address); the name is ours. The PROM reads it through the node's global window at node start and stores bits 27:12 as the node's part number and bits 31:28 as its revision. It then offers the part number to four method tables in turn, each of which accepts one value (0x4363, 0x3017, 0x239, 0x4422), and keeps the first match; a part number outside the four stores a null table that two later callers call through without a test. Established covers the access and that chain, read in full; that the field is a part number is inferred, and which chips the other three values belong to is unknown. A bounded read that returns 0x4363 selects the first table.
 */
/* chip_id: r64, reset unknown; SAL 5.04 PROM site 0xffa0be1c (read), 0xffa0f8c0 (storage of the fields), 0xffa0f7e0 (table walk), 0xffa959a6 (compare against 17251) */
#define SHUB_CHIP_ID                                 0x100000000 /* established */
#define SHUB_CHIP_ID_REVISION_SHIFT                  28 /* inferred */
#define SHUB_CHIP_ID_REVISION_MASK                   0xfull
#define SHUB_CHIP_ID_REVISION_INPLACE                (SHUB_CHIP_ID_REVISION_MASK << SHUB_CHIP_ID_REVISION_SHIFT)
#define SHUB_CHIP_ID_PART_NUMBER_SHIFT               12 /* established */
#define SHUB_CHIP_ID_PART_NUMBER_MASK                0xffffull
#define SHUB_CHIP_ID_PART_NUMBER_INPLACE             (SHUB_CHIP_ID_PART_NUMBER_MASK << SHUB_CHIP_ID_PART_NUMBER_SHIFT)

/*
 * Memory test engine status; the name is ours. Written 0 before every engine start. Bit 36 is read after each operation 16 poll (site 0xffa702c0, inside the compare wrapper) and treated as failure when set, so it must read 0 on a passing run; the failure report reads it again; with bit 36 set it runs a diagnosis (site 0xffa708e0) that reads bit 36 once more, with bit 36 clear it reads md_mbist_err. Operation 48, the directory write and the DRAM commands never read it. Bits 32:0 are read in the failure report as the failing address in 8-byte units. Plain storage satisfies the PROM. The flag name (compare error) is inferred. See memory-init.md.
 */
/* md_mbist_status: rw64, reset unknown; SAL 5.04 PROM site 0xffa6fbac (written 0 at engine start); bit 36 read at site 0xffa702c0 and 0xffa72500; no Linux v5.3 name */
#define SHUB_MD_MBIST_STATUS                         0x100000080 /* established */
#define SHUB_MD_MBIST_STATUS_CMP_ERR_SHIFT           36 /* inferred */
#define SHUB_MD_MBIST_STATUS_CMP_ERR_MASK            0x1ull
#define SHUB_MD_MBIST_STATUS_CMP_ERR_INPLACE         (SHUB_MD_MBIST_STATUS_CMP_ERR_MASK << SHUB_MD_MBIST_STATUS_CMP_ERR_SHIFT)
#define SHUB_MD_MBIST_STATUS_FAIL_ADDR_SHIFT         0 /* inferred */
#define SHUB_MD_MBIST_STATUS_FAIL_ADDR_MASK          0x1ffffffffull
#define SHUB_MD_MBIST_STATUS_FAIL_ADDR_INPLACE       (SHUB_MD_MBIST_STATUS_FAIL_ADDR_MASK << SHUB_MD_MBIST_STATUS_FAIL_ADDR_SHIFT)

/*
 * Memory test engine other-error value; the name is ours. Read only in the failure report, and only when bit 36 of md_mbist_status is found clear (the report then prints that the failure was not a compare error); not read on a passing run, so it needs no particular value. Its layout is unknown.
 */
/* md_mbist_err: r64, reset unknown; SAL 5.04 PROM site 0xffa725f6 (read in the failure report); no Linux v5.3 name */
#define SHUB_MD_MBIST_ERR                            0x1000000b8 /* established */

/*
 * Memory test engine mask; the name is ours (inferred from the all-ones write only). Written with all ones each time the engine starts; never read. Must return: plain storage.
 */
/* md_mbist_mask: w64, reset unknown; SAL 5.04 PROM site 0xffa6fbdc (written all ones at engine start); no Linux v5.3 name */
#define SHUB_MD_MBIST_MASK                           0x1000000c0 /* established */

/*
 * Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with the same 64-bit word, built by merging fields into the old value of _0008 (bits it does not deposit keep their old value): a timing index in bits 35:32 and one byte per bank at bit 8k with the density index, rank code and a two-bit field. For a 2 GiB node (one bank, density 3, rank 0) the low byte is 0x03 and banks 1 to 3 read 0x27, 0x47, 0x67 (density 7). This one is never read; accept the store. See memory-init.md.
 */
/* md_bank_cfg0: w64, reset unknown; SAL 5.04 PROM site 0xffa7701c (write); no Linux v5.3 name */
#define SHUB_MD_BANK_CFG0                            0x100010000 /* established */
#define SHUB_MD_BANK_CFG0_TIMING_IDX_SHIFT           32 /* inferred */
#define SHUB_MD_BANK_CFG0_TIMING_IDX_MASK            0xfull
#define SHUB_MD_BANK_CFG0_TIMING_IDX_INPLACE         (SHUB_MD_BANK_CFG0_TIMING_IDX_MASK << SHUB_MD_BANK_CFG0_TIMING_IDX_SHIFT)
#define SHUB_MD_BANK_CFG0_B3_FIELD_SHIFT             29 /* established */
#define SHUB_MD_BANK_CFG0_B3_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG0_B3_FIELD_INPLACE           (SHUB_MD_BANK_CFG0_B3_FIELD_MASK << SHUB_MD_BANK_CFG0_B3_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG0_B3_RANK_SHIFT              27 /* inferred */
#define SHUB_MD_BANK_CFG0_B3_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG0_B3_RANK_INPLACE            (SHUB_MD_BANK_CFG0_B3_RANK_MASK << SHUB_MD_BANK_CFG0_B3_RANK_SHIFT)
#define SHUB_MD_BANK_CFG0_B3_DENSITY_SHIFT           24 /* inferred */
#define SHUB_MD_BANK_CFG0_B3_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG0_B3_DENSITY_INPLACE         (SHUB_MD_BANK_CFG0_B3_DENSITY_MASK << SHUB_MD_BANK_CFG0_B3_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG0_B2_FIELD_SHIFT             21 /* established */
#define SHUB_MD_BANK_CFG0_B2_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG0_B2_FIELD_INPLACE           (SHUB_MD_BANK_CFG0_B2_FIELD_MASK << SHUB_MD_BANK_CFG0_B2_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG0_B2_RANK_SHIFT              19 /* inferred */
#define SHUB_MD_BANK_CFG0_B2_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG0_B2_RANK_INPLACE            (SHUB_MD_BANK_CFG0_B2_RANK_MASK << SHUB_MD_BANK_CFG0_B2_RANK_SHIFT)
#define SHUB_MD_BANK_CFG0_B2_DENSITY_SHIFT           16 /* inferred */
#define SHUB_MD_BANK_CFG0_B2_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG0_B2_DENSITY_INPLACE         (SHUB_MD_BANK_CFG0_B2_DENSITY_MASK << SHUB_MD_BANK_CFG0_B2_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG0_B1_FIELD_SHIFT             13 /* established */
#define SHUB_MD_BANK_CFG0_B1_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG0_B1_FIELD_INPLACE           (SHUB_MD_BANK_CFG0_B1_FIELD_MASK << SHUB_MD_BANK_CFG0_B1_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG0_B1_RANK_SHIFT              11 /* inferred */
#define SHUB_MD_BANK_CFG0_B1_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG0_B1_RANK_INPLACE            (SHUB_MD_BANK_CFG0_B1_RANK_MASK << SHUB_MD_BANK_CFG0_B1_RANK_SHIFT)
#define SHUB_MD_BANK_CFG0_B1_DENSITY_SHIFT           8 /* inferred */
#define SHUB_MD_BANK_CFG0_B1_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG0_B1_DENSITY_INPLACE         (SHUB_MD_BANK_CFG0_B1_DENSITY_MASK << SHUB_MD_BANK_CFG0_B1_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG0_B0_FIELD_SHIFT             5 /* established */
#define SHUB_MD_BANK_CFG0_B0_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG0_B0_FIELD_INPLACE           (SHUB_MD_BANK_CFG0_B0_FIELD_MASK << SHUB_MD_BANK_CFG0_B0_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG0_B0_RANK_SHIFT              3 /* inferred */
#define SHUB_MD_BANK_CFG0_B0_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG0_B0_RANK_INPLACE            (SHUB_MD_BANK_CFG0_B0_RANK_MASK << SHUB_MD_BANK_CFG0_B0_RANK_SHIFT)
#define SHUB_MD_BANK_CFG0_B0_DENSITY_SHIFT           0 /* inferred */
#define SHUB_MD_BANK_CFG0_B0_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG0_B0_DENSITY_INPLACE         (SHUB_MD_BANK_CFG0_B0_DENSITY_MASK << SHUB_MD_BANK_CFG0_B0_DENSITY_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with the same 64-bit word, built by merging fields into the old value of _0008 (bits it does not deposit keep their old value): a timing index in bits 35:32 and one byte per bank at bit 8k with the density index, rank code and a two-bit field. For a 2 GiB node (one bank, density 3, rank 0) the low byte is 0x03 and banks 1 to 3 read 0x27, 0x47, 0x67 (density 7). Read first by the set-up, then by the memory test and the credit routine to find each bank's size: it must read back what was written. See memory-init.md.
 */
/* md_bank_cfg1: rw64, reset unknown; SAL 5.04 PROM site 0xffa76c3c (read), 0xffa7704c (write), 0xffa6dedc and 0xffa7ab9c (reads for the bank size); no Linux v5.3 name */
#define SHUB_MD_BANK_CFG1                            0x100010008 /* established */
#define SHUB_MD_BANK_CFG1_TIMING_IDX_SHIFT           32 /* inferred */
#define SHUB_MD_BANK_CFG1_TIMING_IDX_MASK            0xfull
#define SHUB_MD_BANK_CFG1_TIMING_IDX_INPLACE         (SHUB_MD_BANK_CFG1_TIMING_IDX_MASK << SHUB_MD_BANK_CFG1_TIMING_IDX_SHIFT)
#define SHUB_MD_BANK_CFG1_B3_FIELD_SHIFT             29 /* established */
#define SHUB_MD_BANK_CFG1_B3_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG1_B3_FIELD_INPLACE           (SHUB_MD_BANK_CFG1_B3_FIELD_MASK << SHUB_MD_BANK_CFG1_B3_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG1_B3_RANK_SHIFT              27 /* inferred */
#define SHUB_MD_BANK_CFG1_B3_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG1_B3_RANK_INPLACE            (SHUB_MD_BANK_CFG1_B3_RANK_MASK << SHUB_MD_BANK_CFG1_B3_RANK_SHIFT)
#define SHUB_MD_BANK_CFG1_B3_DENSITY_SHIFT           24 /* inferred */
#define SHUB_MD_BANK_CFG1_B3_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG1_B3_DENSITY_INPLACE         (SHUB_MD_BANK_CFG1_B3_DENSITY_MASK << SHUB_MD_BANK_CFG1_B3_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG1_B2_FIELD_SHIFT             21 /* established */
#define SHUB_MD_BANK_CFG1_B2_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG1_B2_FIELD_INPLACE           (SHUB_MD_BANK_CFG1_B2_FIELD_MASK << SHUB_MD_BANK_CFG1_B2_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG1_B2_RANK_SHIFT              19 /* inferred */
#define SHUB_MD_BANK_CFG1_B2_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG1_B2_RANK_INPLACE            (SHUB_MD_BANK_CFG1_B2_RANK_MASK << SHUB_MD_BANK_CFG1_B2_RANK_SHIFT)
#define SHUB_MD_BANK_CFG1_B2_DENSITY_SHIFT           16 /* inferred */
#define SHUB_MD_BANK_CFG1_B2_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG1_B2_DENSITY_INPLACE         (SHUB_MD_BANK_CFG1_B2_DENSITY_MASK << SHUB_MD_BANK_CFG1_B2_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG1_B1_FIELD_SHIFT             13 /* established */
#define SHUB_MD_BANK_CFG1_B1_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG1_B1_FIELD_INPLACE           (SHUB_MD_BANK_CFG1_B1_FIELD_MASK << SHUB_MD_BANK_CFG1_B1_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG1_B1_RANK_SHIFT              11 /* inferred */
#define SHUB_MD_BANK_CFG1_B1_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG1_B1_RANK_INPLACE            (SHUB_MD_BANK_CFG1_B1_RANK_MASK << SHUB_MD_BANK_CFG1_B1_RANK_SHIFT)
#define SHUB_MD_BANK_CFG1_B1_DENSITY_SHIFT           8 /* inferred */
#define SHUB_MD_BANK_CFG1_B1_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG1_B1_DENSITY_INPLACE         (SHUB_MD_BANK_CFG1_B1_DENSITY_MASK << SHUB_MD_BANK_CFG1_B1_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG1_B0_FIELD_SHIFT             5 /* established */
#define SHUB_MD_BANK_CFG1_B0_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG1_B0_FIELD_INPLACE           (SHUB_MD_BANK_CFG1_B0_FIELD_MASK << SHUB_MD_BANK_CFG1_B0_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG1_B0_RANK_SHIFT              3 /* inferred */
#define SHUB_MD_BANK_CFG1_B0_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG1_B0_RANK_INPLACE            (SHUB_MD_BANK_CFG1_B0_RANK_MASK << SHUB_MD_BANK_CFG1_B0_RANK_SHIFT)
#define SHUB_MD_BANK_CFG1_B0_DENSITY_SHIFT           0 /* inferred */
#define SHUB_MD_BANK_CFG1_B0_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG1_B0_DENSITY_INPLACE         (SHUB_MD_BANK_CFG1_B0_DENSITY_MASK << SHUB_MD_BANK_CFG1_B0_DENSITY_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with the same 64-bit word, built by merging fields into the old value of _0008 (bits it does not deposit keep their old value): a timing index in bits 35:32 and one byte per bank at bit 8k with the density index, rank code and a two-bit field. For a 2 GiB node (one bank, density 3, rank 0) the low byte is 0x03 and banks 1 to 3 read 0x27, 0x47, 0x67 (density 7). The memory test driver reads it to skip banks whose density index is 7, and the size sum reads it too: it must read back what was written. See memory-init.md.
 */
/* md_bank_cfg2: rw64, reset unknown; SAL 5.04 PROM site 0xffa7707c (write), 0xffa6f2fc and 0xffa7838c (reads); no Linux v5.3 name */
#define SHUB_MD_BANK_CFG2                            0x100010010 /* established */
#define SHUB_MD_BANK_CFG2_TIMING_IDX_SHIFT           32 /* inferred */
#define SHUB_MD_BANK_CFG2_TIMING_IDX_MASK            0xfull
#define SHUB_MD_BANK_CFG2_TIMING_IDX_INPLACE         (SHUB_MD_BANK_CFG2_TIMING_IDX_MASK << SHUB_MD_BANK_CFG2_TIMING_IDX_SHIFT)
#define SHUB_MD_BANK_CFG2_B3_FIELD_SHIFT             29 /* established */
#define SHUB_MD_BANK_CFG2_B3_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG2_B3_FIELD_INPLACE           (SHUB_MD_BANK_CFG2_B3_FIELD_MASK << SHUB_MD_BANK_CFG2_B3_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG2_B3_RANK_SHIFT              27 /* inferred */
#define SHUB_MD_BANK_CFG2_B3_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG2_B3_RANK_INPLACE            (SHUB_MD_BANK_CFG2_B3_RANK_MASK << SHUB_MD_BANK_CFG2_B3_RANK_SHIFT)
#define SHUB_MD_BANK_CFG2_B3_DENSITY_SHIFT           24 /* inferred */
#define SHUB_MD_BANK_CFG2_B3_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG2_B3_DENSITY_INPLACE         (SHUB_MD_BANK_CFG2_B3_DENSITY_MASK << SHUB_MD_BANK_CFG2_B3_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG2_B2_FIELD_SHIFT             21 /* established */
#define SHUB_MD_BANK_CFG2_B2_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG2_B2_FIELD_INPLACE           (SHUB_MD_BANK_CFG2_B2_FIELD_MASK << SHUB_MD_BANK_CFG2_B2_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG2_B2_RANK_SHIFT              19 /* inferred */
#define SHUB_MD_BANK_CFG2_B2_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG2_B2_RANK_INPLACE            (SHUB_MD_BANK_CFG2_B2_RANK_MASK << SHUB_MD_BANK_CFG2_B2_RANK_SHIFT)
#define SHUB_MD_BANK_CFG2_B2_DENSITY_SHIFT           16 /* inferred */
#define SHUB_MD_BANK_CFG2_B2_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG2_B2_DENSITY_INPLACE         (SHUB_MD_BANK_CFG2_B2_DENSITY_MASK << SHUB_MD_BANK_CFG2_B2_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG2_B1_FIELD_SHIFT             13 /* established */
#define SHUB_MD_BANK_CFG2_B1_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG2_B1_FIELD_INPLACE           (SHUB_MD_BANK_CFG2_B1_FIELD_MASK << SHUB_MD_BANK_CFG2_B1_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG2_B1_RANK_SHIFT              11 /* inferred */
#define SHUB_MD_BANK_CFG2_B1_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG2_B1_RANK_INPLACE            (SHUB_MD_BANK_CFG2_B1_RANK_MASK << SHUB_MD_BANK_CFG2_B1_RANK_SHIFT)
#define SHUB_MD_BANK_CFG2_B1_DENSITY_SHIFT           8 /* inferred */
#define SHUB_MD_BANK_CFG2_B1_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG2_B1_DENSITY_INPLACE         (SHUB_MD_BANK_CFG2_B1_DENSITY_MASK << SHUB_MD_BANK_CFG2_B1_DENSITY_SHIFT)
#define SHUB_MD_BANK_CFG2_B0_FIELD_SHIFT             5 /* established */
#define SHUB_MD_BANK_CFG2_B0_FIELD_MASK              0x3ull
#define SHUB_MD_BANK_CFG2_B0_FIELD_INPLACE           (SHUB_MD_BANK_CFG2_B0_FIELD_MASK << SHUB_MD_BANK_CFG2_B0_FIELD_SHIFT)
#define SHUB_MD_BANK_CFG2_B0_RANK_SHIFT              3 /* inferred */
#define SHUB_MD_BANK_CFG2_B0_RANK_MASK               0x1ull
#define SHUB_MD_BANK_CFG2_B0_RANK_INPLACE            (SHUB_MD_BANK_CFG2_B0_RANK_MASK << SHUB_MD_BANK_CFG2_B0_RANK_SHIFT)
#define SHUB_MD_BANK_CFG2_B0_DENSITY_SHIFT           0 /* inferred */
#define SHUB_MD_BANK_CFG2_B0_DENSITY_MASK            0x7ull
#define SHUB_MD_BANK_CFG2_B0_DENSITY_INPLACE         (SHUB_MD_BANK_CFG2_B0_DENSITY_MASK << SHUB_MD_BANK_CFG2_B0_DENSITY_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. Timing word built from a 32-byte row of the timing table at flash site 0xffbe0650 (row = the timing index). One of two registers (offsets _0020 and _0040) that carry the same word; bits 63:40 and 7:0 of the old value of _0040 are merged in (read at site 0xffa76c9c). Never read. Must return: plain storage. See memory-init.md.
 */
/* md_timing_0: w64, reset unknown; SAL 5.04 PROM site 0xffa7710c (write); no Linux v5.3 name */
#define SHUB_MD_TIMING_0                             0x100010020 /* established */
#define SHUB_MD_TIMING_0_TRCD4_SHIFT                 54 /* inferred */
#define SHUB_MD_TIMING_0_TRCD4_MASK                  0x1ull
#define SHUB_MD_TIMING_0_TRCD4_INPLACE               (SHUB_MD_TIMING_0_TRCD4_MASK << SHUB_MD_TIMING_0_TRCD4_SHIFT)
#define SHUB_MD_TIMING_0_TRCD2_SHIFT                 53 /* inferred */
#define SHUB_MD_TIMING_0_TRCD2_MASK                  0x1ull
#define SHUB_MD_TIMING_0_TRCD2_INPLACE               (SHUB_MD_TIMING_0_TRCD2_MASK << SHUB_MD_TIMING_0_TRCD2_SHIFT)
#define SHUB_MD_TIMING_0_TRCD3_SHIFT                 52 /* inferred */
#define SHUB_MD_TIMING_0_TRCD3_MASK                  0x1ull
#define SHUB_MD_TIMING_0_TRCD3_INPLACE               (SHUB_MD_TIMING_0_TRCD3_MASK << SHUB_MD_TIMING_0_TRCD3_SHIFT)
#define SHUB_MD_TIMING_0_ROW_C_SHIFT                 48 /* established */
#define SHUB_MD_TIMING_0_ROW_C_MASK                  0xfull
#define SHUB_MD_TIMING_0_ROW_C_INPLACE               (SHUB_MD_TIMING_0_ROW_C_MASK << SHUB_MD_TIMING_0_ROW_C_SHIFT)
#define SHUB_MD_TIMING_0_ROW_B_SHIFT                 44 /* established */
#define SHUB_MD_TIMING_0_ROW_B_MASK                  0xfull
#define SHUB_MD_TIMING_0_ROW_B_INPLACE               (SHUB_MD_TIMING_0_ROW_B_MASK << SHUB_MD_TIMING_0_ROW_B_SHIFT)
#define SHUB_MD_TIMING_0_ROW_A_SHIFT                 40 /* established */
#define SHUB_MD_TIMING_0_ROW_A_MASK                  0xfull
#define SHUB_MD_TIMING_0_ROW_A_INPLACE               (SHUB_MD_TIMING_0_ROW_A_MASK << SHUB_MD_TIMING_0_ROW_A_SHIFT)
#define SHUB_MD_TIMING_0_ROW_LO_SHIFT                8 /* established */
#define SHUB_MD_TIMING_0_ROW_LO_MASK                 0xffffffffull
#define SHUB_MD_TIMING_0_ROW_LO_INPLACE              (SHUB_MD_TIMING_0_ROW_LO_MASK << SHUB_MD_TIMING_0_ROW_LO_SHIFT)
#define SHUB_MD_TIMING_0_CONST_LO_SHIFT              1 /* established */
#define SHUB_MD_TIMING_0_CONST_LO_MASK               0x7full
#define SHUB_MD_TIMING_0_CONST_LO_INPLACE            (SHUB_MD_TIMING_0_CONST_LO_MASK << SHUB_MD_TIMING_0_CONST_LO_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. Six 4-bit timing fields from the 16-bit values at offsets 14, 16, 18, 20, 22 and 24 of the timing-table row; the other bits keep the old value read from _0048 (site 0xffa76c6c). One of two registers (_0028 and _0048) that carry the same word. Never read. Must return: plain storage. See memory-init.md.
 */
/* md_timing_1: w64, reset unknown; SAL 5.04 PROM site 0xffa770ac (write); no Linux v5.3 name */
#define SHUB_MD_TIMING_1                             0x100010028 /* established */
#define SHUB_MD_TIMING_1_U5_SHIFT                    20 /* established */
#define SHUB_MD_TIMING_1_U5_MASK                     0xfull
#define SHUB_MD_TIMING_1_U5_INPLACE                  (SHUB_MD_TIMING_1_U5_MASK << SHUB_MD_TIMING_1_U5_SHIFT)
#define SHUB_MD_TIMING_1_U4_SHIFT                    16 /* established */
#define SHUB_MD_TIMING_1_U4_MASK                     0xfull
#define SHUB_MD_TIMING_1_U4_INPLACE                  (SHUB_MD_TIMING_1_U4_MASK << SHUB_MD_TIMING_1_U4_SHIFT)
#define SHUB_MD_TIMING_1_U3_SHIFT                    12 /* established */
#define SHUB_MD_TIMING_1_U3_MASK                     0xfull
#define SHUB_MD_TIMING_1_U3_INPLACE                  (SHUB_MD_TIMING_1_U3_MASK << SHUB_MD_TIMING_1_U3_SHIFT)
#define SHUB_MD_TIMING_1_U2_SHIFT                    8 /* established */
#define SHUB_MD_TIMING_1_U2_MASK                     0xfull
#define SHUB_MD_TIMING_1_U2_INPLACE                  (SHUB_MD_TIMING_1_U2_MASK << SHUB_MD_TIMING_1_U2_SHIFT)
#define SHUB_MD_TIMING_1_U1_SHIFT                    4 /* established */
#define SHUB_MD_TIMING_1_U1_MASK                     0xfull
#define SHUB_MD_TIMING_1_U1_INPLACE                  (SHUB_MD_TIMING_1_U1_MASK << SHUB_MD_TIMING_1_U1_SHIFT)
#define SHUB_MD_TIMING_1_U0_SHIFT                    0 /* established */
#define SHUB_MD_TIMING_1_U0_MASK                     0xfull
#define SHUB_MD_TIMING_1_U0_INPLACE                  (SHUB_MD_TIMING_1_U0_MASK << SHUB_MD_TIMING_1_U0_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. One word is written to both _0030 and _0050, once, after the eight DRAM initialisation runs: it starts as the old value of _0050 with bit 23 cleared and these fields deposited. Never read. See memory-init.md.
 */
/* md_refresh_0: w64, reset unknown; SAL 5.04 PROM site 0xffa77adc (write); no Linux v5.3 name */
#define SHUB_MD_REFRESH_0                            0x100010030 /* established */
#define SHUB_MD_REFRESH_0_BANK_SMALL_SHIFT           24 /* established */
#define SHUB_MD_REFRESH_0_BANK_SMALL_MASK            0xfull
#define SHUB_MD_REFRESH_0_BANK_SMALL_INPLACE         (SHUB_MD_REFRESH_0_BANK_SMALL_MASK << SHUB_MD_REFRESH_0_BANK_SMALL_SHIFT)
#define SHUB_MD_REFRESH_0_TRFC_SHIFT                 17 /* inferred */
#define SHUB_MD_REFRESH_0_TRFC_MASK                  0x3full
#define SHUB_MD_REFRESH_0_TRFC_INPLACE               (SHUB_MD_REFRESH_0_TRFC_MASK << SHUB_MD_REFRESH_0_TRFC_SHIFT)
#define SHUB_MD_REFRESH_0_INTERVAL_SHIFT             8 /* inferred */
#define SHUB_MD_REFRESH_0_INTERVAL_MASK              0x1ffull
#define SHUB_MD_REFRESH_0_INTERVAL_INPLACE           (SHUB_MD_REFRESH_0_INTERVAL_MASK << SHUB_MD_REFRESH_0_INTERVAL_SHIFT)
#define SHUB_MD_REFRESH_0_CS_ENABLE_SHIFT            0 /* inferred */
#define SHUB_MD_REFRESH_0_CS_ENABLE_MASK             0xffull
#define SHUB_MD_REFRESH_0_CS_ENABLE_INPLACE          (SHUB_MD_REFRESH_0_CS_ENABLE_MASK << SHUB_MD_REFRESH_0_CS_ENABLE_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. Timing word built from a 32-byte row of the timing table at flash site 0xffbe0650 (row = the timing index). One of two registers (offsets _0020 and _0040) that carry the same word; bits 63:40 and 7:0 of the old value of _0040 are merged in (read at site 0xffa76c9c). Read once before the write, so any value is accepted before the first write. See memory-init.md.
 */
/* md_timing_2: rw64, reset unknown; SAL 5.04 PROM site 0xffa76c9c (read), 0xffa7713c (write); no Linux v5.3 name */
#define SHUB_MD_TIMING_2                             0x100010040 /* established */
#define SHUB_MD_TIMING_2_TRCD4_SHIFT                 54 /* inferred */
#define SHUB_MD_TIMING_2_TRCD4_MASK                  0x1ull
#define SHUB_MD_TIMING_2_TRCD4_INPLACE               (SHUB_MD_TIMING_2_TRCD4_MASK << SHUB_MD_TIMING_2_TRCD4_SHIFT)
#define SHUB_MD_TIMING_2_TRCD2_SHIFT                 53 /* inferred */
#define SHUB_MD_TIMING_2_TRCD2_MASK                  0x1ull
#define SHUB_MD_TIMING_2_TRCD2_INPLACE               (SHUB_MD_TIMING_2_TRCD2_MASK << SHUB_MD_TIMING_2_TRCD2_SHIFT)
#define SHUB_MD_TIMING_2_TRCD3_SHIFT                 52 /* inferred */
#define SHUB_MD_TIMING_2_TRCD3_MASK                  0x1ull
#define SHUB_MD_TIMING_2_TRCD3_INPLACE               (SHUB_MD_TIMING_2_TRCD3_MASK << SHUB_MD_TIMING_2_TRCD3_SHIFT)
#define SHUB_MD_TIMING_2_ROW_C_SHIFT                 48 /* established */
#define SHUB_MD_TIMING_2_ROW_C_MASK                  0xfull
#define SHUB_MD_TIMING_2_ROW_C_INPLACE               (SHUB_MD_TIMING_2_ROW_C_MASK << SHUB_MD_TIMING_2_ROW_C_SHIFT)
#define SHUB_MD_TIMING_2_ROW_B_SHIFT                 44 /* established */
#define SHUB_MD_TIMING_2_ROW_B_MASK                  0xfull
#define SHUB_MD_TIMING_2_ROW_B_INPLACE               (SHUB_MD_TIMING_2_ROW_B_MASK << SHUB_MD_TIMING_2_ROW_B_SHIFT)
#define SHUB_MD_TIMING_2_ROW_A_SHIFT                 40 /* established */
#define SHUB_MD_TIMING_2_ROW_A_MASK                  0xfull
#define SHUB_MD_TIMING_2_ROW_A_INPLACE               (SHUB_MD_TIMING_2_ROW_A_MASK << SHUB_MD_TIMING_2_ROW_A_SHIFT)
#define SHUB_MD_TIMING_2_ROW_LO_SHIFT                8 /* established */
#define SHUB_MD_TIMING_2_ROW_LO_MASK                 0xffffffffull
#define SHUB_MD_TIMING_2_ROW_LO_INPLACE              (SHUB_MD_TIMING_2_ROW_LO_MASK << SHUB_MD_TIMING_2_ROW_LO_SHIFT)
#define SHUB_MD_TIMING_2_CONST_LO_SHIFT              1 /* established */
#define SHUB_MD_TIMING_2_CONST_LO_MASK               0x7full
#define SHUB_MD_TIMING_2_CONST_LO_INPLACE            (SHUB_MD_TIMING_2_CONST_LO_MASK << SHUB_MD_TIMING_2_CONST_LO_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. Six 4-bit timing fields from the 16-bit values at offsets 14, 16, 18, 20, 22 and 24 of the timing-table row; the other bits keep the old value read from _0048 (site 0xffa76c6c). One of two registers (_0028 and _0048) that carry the same word. Read once before the write, so any value is accepted before the first write. See memory-init.md.
 */
/* md_timing_3: rw64, reset unknown; SAL 5.04 PROM site 0xffa76c6c (read), 0xffa770dc (write); no Linux v5.3 name */
#define SHUB_MD_TIMING_3                             0x100010048 /* established */
#define SHUB_MD_TIMING_3_U5_SHIFT                    20 /* established */
#define SHUB_MD_TIMING_3_U5_MASK                     0xfull
#define SHUB_MD_TIMING_3_U5_INPLACE                  (SHUB_MD_TIMING_3_U5_MASK << SHUB_MD_TIMING_3_U5_SHIFT)
#define SHUB_MD_TIMING_3_U4_SHIFT                    16 /* established */
#define SHUB_MD_TIMING_3_U4_MASK                     0xfull
#define SHUB_MD_TIMING_3_U4_INPLACE                  (SHUB_MD_TIMING_3_U4_MASK << SHUB_MD_TIMING_3_U4_SHIFT)
#define SHUB_MD_TIMING_3_U3_SHIFT                    12 /* established */
#define SHUB_MD_TIMING_3_U3_MASK                     0xfull
#define SHUB_MD_TIMING_3_U3_INPLACE                  (SHUB_MD_TIMING_3_U3_MASK << SHUB_MD_TIMING_3_U3_SHIFT)
#define SHUB_MD_TIMING_3_U2_SHIFT                    8 /* established */
#define SHUB_MD_TIMING_3_U2_MASK                     0xfull
#define SHUB_MD_TIMING_3_U2_INPLACE                  (SHUB_MD_TIMING_3_U2_MASK << SHUB_MD_TIMING_3_U2_SHIFT)
#define SHUB_MD_TIMING_3_U1_SHIFT                    4 /* established */
#define SHUB_MD_TIMING_3_U1_MASK                     0xfull
#define SHUB_MD_TIMING_3_U1_INPLACE                  (SHUB_MD_TIMING_3_U1_MASK << SHUB_MD_TIMING_3_U1_SHIFT)
#define SHUB_MD_TIMING_3_U0_SHIFT                    0 /* established */
#define SHUB_MD_TIMING_3_U0_MASK                     0xfull
#define SHUB_MD_TIMING_3_U0_INPLACE                  (SHUB_MD_TIMING_3_U0_MASK << SHUB_MD_TIMING_3_U0_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. One word is written to both _0030 and _0050, once, after the eight DRAM initialisation runs: it starts as the old value of _0050 with bit 23 cleared and these fields deposited. Read once, before the write; keep what was written. See memory-init.md.
 */
/* md_refresh_1: rw64, reset unknown; SAL 5.04 PROM site 0xffa7761c (read), 0xffa77b0c (write); no Linux v5.3 name */
#define SHUB_MD_REFRESH_1                            0x100010050 /* established */
#define SHUB_MD_REFRESH_1_BANK_SMALL_SHIFT           24 /* established */
#define SHUB_MD_REFRESH_1_BANK_SMALL_MASK            0xfull
#define SHUB_MD_REFRESH_1_BANK_SMALL_INPLACE         (SHUB_MD_REFRESH_1_BANK_SMALL_MASK << SHUB_MD_REFRESH_1_BANK_SMALL_SHIFT)
#define SHUB_MD_REFRESH_1_TRFC_SHIFT                 17 /* inferred */
#define SHUB_MD_REFRESH_1_TRFC_MASK                  0x3full
#define SHUB_MD_REFRESH_1_TRFC_INPLACE               (SHUB_MD_REFRESH_1_TRFC_MASK << SHUB_MD_REFRESH_1_TRFC_SHIFT)
#define SHUB_MD_REFRESH_1_INTERVAL_SHIFT             8 /* inferred */
#define SHUB_MD_REFRESH_1_INTERVAL_MASK              0x1ffull
#define SHUB_MD_REFRESH_1_INTERVAL_INPLACE           (SHUB_MD_REFRESH_1_INTERVAL_MASK << SHUB_MD_REFRESH_1_INTERVAL_SHIFT)
#define SHUB_MD_REFRESH_1_CS_ENABLE_SHIFT            0 /* inferred */
#define SHUB_MD_REFRESH_1_CS_ENABLE_MASK             0xffull
#define SHUB_MD_REFRESH_1_CS_ENABLE_INPLACE          (SHUB_MD_REFRESH_1_CS_ENABLE_MASK << SHUB_MD_REFRESH_1_CS_ENABLE_SHIFT)

/*
 * Memory controller register, unnamed; the name is ours. Written once with the constant 0x4004e20; never read. Role unknown. See memory-init.md.
 */
/* md_const_58: w64, reset unknown; SAL 5.04 PROM site 0xffa7745c (write); no Linux v5.3 name */
#define SHUB_MD_CONST_58                             0x100010058 /* established */

/*
 * Memory controller register, unnamed; the name is ours. Written 0x4047 when the SHub ID revision (bits 31:28 of 0x1_1006_0580) is above 2 and 0x4045 otherwise; never read. Role unknown. See memory-init.md.
 */
/* md_ctl_60: w64, reset unknown; SAL 5.04 PROM site 0xffa773cc (write), 0xffa7738c (revision read); no Linux v5.3 name */
#define SHUB_MD_CTL_60                               0x100010060 /* established */

/*
 * Memory controller register, unnamed; the name is ours. The credit routine (site 0xffa7a960) reads it for the first flagged bank, reads md_bank_cfg1, and compares the 32-bit value with its argument, 4 when called from the memory test and 2 from Initializing memory (which always runs). Equal: nothing. Value below the argument: zero-fills the last 1/32 of the bank with engine operation 48, then writes the argument back (sign-extended from 32 bits), then zero-fills with the block transfer engine (IBLS0 written 0x100000 plus twice the difference, polled for bit 20 to clear; a timeout prints a message and returns). Value above: writes the argument back and zero-fills (value minus argument) times 32 8-byte words at the bank base with operation 48. The routine returns at once, touching nothing, when cpuid[2] equals 0xaeeeeeee8badbeef or no bank is flagged present. The register must read back what was written; the role of the value is unknown (a credit-like count, inferred from the comparison). See memory-init.md.
 */
/* md_reg_0001_0068: rw64, reset unknown; SAL 5.04 PROM site 0xffa7ab6c (read), 0xffa7acdc and 0xffa7ad9c (writes) */
#define SHUB_MD_REG_0001_0068                        0x100010068 /* established */

/*
 * Memory controller register, unnamed; the name is ours. Written once with the constant 0x24; never read. Role unknown. See memory-init.md.
 */
/* md_const_78: w64, reset unknown; SAL 5.04 PROM site 0xffa7748c (write); no Linux v5.3 name */
#define SHUB_MD_CONST_78                             0x100010078 /* established */

/*
 * Memory test and DRAM initialisation engine, command or address word; the name is ours. Written with the caller's 64-bit word before the status and control writes of every engine start: for operations 48 and 16 the byte address within the node where the pass starts (bank << 34, plus 32 times the pass number for operation 16), for operation 64 the directory address, for the DRAM initialisation commands (operations 7, 2, 1, 0) a command word. Never read in the passing path. Must return: plain storage. See memory-init.md.
 */
/* md_mbist_cmd: w64, reset unknown; SAL 5.04 PROM site 0xffa6fb7c (written first when the engine starts); no Linux v5.3 name */
#define SHUB_MD_MBIST_CMD                            0x100020080 /* established */

/*
 * Memory test and DRAM initialisation engine control; the name is ours. The PROM starts the engine by writing md_mbist_cmd, then 0 to md_mbist_status and all ones to md_mbist_mask, then this register with go set, an operation code in bits 38:32 and a 31-bit value. It then polls, keeping bits 41:40: it leaves the loop when they are not 01 (go set, fail clear), so 00 is done, 10 is done and failed, 11 is failed with go still set (the PROM then stores the value it read back with bit 40 cleared and polls bit 40 to clear), 01 is busy. The deadline is 20,000,000 microseconds, scaled from the real-time clock by the period in rtc_ctl. An expiry returns -3 (printed as MBIST TIMEOUT). Callers test bit 41 afterwards. Bits 38:0 are never read. A model where go clears at once and fail never sets satisfies the code. See memory-init.md.
 */
/* md_mbist_ctl: rw64, reset unknown; SAL 5.04 PROM site 0xffa6fc3c (start), 0xffa6fd3c and 0xffa6fddc (poll), 0xffa6b1dc (failure test); no Linux v5.3 name */
#define SHUB_MD_MBIST_CTL                            0x100020088 /* established */
#define SHUB_MD_MBIST_CTL_FAIL_SHIFT                 41 /* established */
#define SHUB_MD_MBIST_CTL_FAIL_MASK                  0x1ull
#define SHUB_MD_MBIST_CTL_FAIL_INPLACE               (SHUB_MD_MBIST_CTL_FAIL_MASK << SHUB_MD_MBIST_CTL_FAIL_SHIFT)
#define SHUB_MD_MBIST_CTL_GO_SHIFT                   40 /* established */
#define SHUB_MD_MBIST_CTL_GO_MASK                    0x1ull
#define SHUB_MD_MBIST_CTL_GO_INPLACE                 (SHUB_MD_MBIST_CTL_GO_MASK << SHUB_MD_MBIST_CTL_GO_SHIFT)
#define SHUB_MD_MBIST_CTL_OP_SHIFT                   32 /* established */
#define SHUB_MD_MBIST_CTL_OP_MASK                    0x7full
#define SHUB_MD_MBIST_CTL_OP_INPLACE                 (SHUB_MD_MBIST_CTL_OP_MASK << SHUB_MD_MBIST_CTL_OP_SHIFT)
#define SHUB_MD_MBIST_CTL_VALUE_SHIFT                0 /* established */
#define SHUB_MD_MBIST_CTL_VALUE_MASK                 0x7fffffffull
#define SHUB_MD_MBIST_CTL_VALUE_INPLACE              (SHUB_MD_MBIST_CTL_VALUE_MASK << SHUB_MD_MBIST_CTL_VALUE_SHIFT)

/*
 * MD block register, unnamed; the name is ours. Initializing memory (site 0xffa782c0, which always runs) reads it, sets bit 3 and writes the result to this register and to md_reg_0005_0000. A routine reached only through a function-descriptor table (site 0xffa733d0) writes a size class from 0 to 4 into bits 2:0 of both; another (site 0xffa78f70) reads bits 2:0 plus one as a shift. Whether the table path runs on a single node was not traced. Must return the stored value. The 2.4 header names this offset SH_MD_DQLP_MMR_DIR_CONFIG (mask 0x1f, INIT 0x10): bits 2:0 SYS_SIZE (system size code), bit 3 EN_DIRECC (enable directory ECC correction), bit 4 EN_DIRPOIS.
 */
/* md_reg_0003_0000: rw64, reset unknown; SAL 5.04 PROM sites 0xffa785cc (read) and 0xffa785ec (write); no Linux v5.3 name */
#define SHUB_MD_REG_0003_0000                        0x100030000 /* established */

/*
 * Directory presence vector words 0 to 3 of the left directory queue port. The PROM writes the bit mask of present nodes: for each present NASID n in block A's node table it sets one bit (word and bit from n, the mode in SHUB_ID bits 45:44 and the node's position); for NASID 0 alone word 0 is 1 and words 1 to 3 are 0 in every mode. The same four values go to md_dqrp_dir_presvec and shubs_present. Never read back. The header says: node [63:0] presence bits, 1 = present (INIT 0). The loop includes a node other than the local one only when 0xffa129f0 returns 0 for it.
 */
/* md_dqlp_dir_presvec: w64, reset unknown; SAL 5.04 PROM site 0xffa79310 (stores after the node-table loop; names SH_MD_DQLP_MMR_DIR_PRESVEC0 to 3 in the PROM table) */
#define SHUB_MD_DQLP_DIR_PRESVEC                     0x100030100 /* established */
#define SHUB_MD_DQLP_DIR_PRESVEC_COUNT               4
#define SHUB_MD_DQLP_DIR_PRESVEC_STRIDE              16

/*
 * MD block registers, unnamed; the name is ours. Eight words at stride 0x10 that the memory set-up fills with all ones, once each, through the global window. Never read. The PROM table names them SH_MD_DQLP_MMR_DIR_LOCVEC0 to 7 (right port: DQRP). The node memory set-up (site 0xffa78f60, slot 97 of the class-0 methods) writes all eight again with the node mask, one bit per group of present nodes (1 for NASID 0 alone). See memory-init.md.
 */
/* md_reg_0003_0200: w64, reset unknown; SAL 5.04 PROM site 0xffa7729c (write loop); no Linux v5.3 name */
#define SHUB_MD_REG_0003_0200                        0x100030200 /* established */
#define SHUB_MD_REG_0003_0200_COUNT                  8
#define SHUB_MD_REG_0003_0200_STRIDE                 16

/*
 * Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege vector for acc=0'). Defined by the header; no use in any kernel file read. Layout and role unknown.
 */
/* md_dqlp_dir_privilege_vector: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_DQLP_DIR_PRIVILEGE_VECTOR            0x100030300 /* established */

/*
 * Privilege vectors 1 to 7 of the left directory queue port (vector 0 is md_dqlp_dir_privilege_vector at 0x1_0003_0300). The PROM writes constants, the same pair of values to the left and right ports: vec 0 0x4bfff, 1 0xc96f25b, 2 0xfffffff, 3 0x96ffff, 4 0, 5 0, 6 0x4803f, 7 0x48000 (the list is vec 0 to 7 at 0x1_0003_0300 to 0x370). Never read back. The header (SH_MD_DQLP_MMR_DIR_PRIVEC1..7, mask 0xfffffff, INIT 0) splits each word into IN, bits 13:0, in-partition privileges for locvec bit = 1, and OUT, bits 27:14, out-of-partition privileges for locvec bit = 0; one vector per access class.
 */
/* md_dqlp_dir_privec: w64, reset unknown; SAL 5.04 PROM site 0xffa79960 (constants), names SH_MD_DQLP_MMR_DIR_PRIVEC1 to 7 in the PROM table */
#define SHUB_MD_DQLP_DIR_PRIVEC                      0x100030310 /* established */
#define SHUB_MD_DQLP_DIR_PRIVEC_COUNT                7
#define SHUB_MD_DQLP_DIR_PRIVEC_STRIDE               16

/*
 * Memory and directory block register, unnamed; the name is ours. The memory controller set-up writes 0x1000 (bit 12) to it through the global window, between the control register md_ctl_60 and md_const_58. It is 0x100 above SH1_MD_DQLP_MMR_DIR_PRIVEC0 (md_dqlp_dir_privilege_vector); that it is the next privilege vector is not shown. Never read. A write-accepting register satisfies the PROM; the role is unknown.
 */
/* md_reg_0003_0400: w64, reset unknown; SAL 5.04 PROM site 0xffa773fc (write); the only reference to the address in SAL_A and SAL_B */
#define SHUB_MD_REG_0003_0400                        0x100030400 /* established */

/*
 * Directory memory initial-value write, left queue port block (the block is the one the Linux header calls SH1_MD_DQLP_MMR_DIR_PRIVEC0 at the 0x300 offset; the left reading is inferred from that name); the name is ours. The PROM stores the value shifted left 55 here and to md_dir_access_rp, then runs the engine with operation code 64. No separate initialise register for directory ECC was seen. The routine fails on a -3 timeout or bit 41 of md_mbist_ctl and does not test bit 36 of md_mbist_status. Never read; plain storage satisfies the PROM. Callers pass the value 7 for the first 64 KiB of node 0 and 6 for the 6 MiB PROM image copy (argument positions inferred). See memory-init.md.
 */
/* md_dir_access_lp: w64, reset unknown; SAL 5.04 PROM site 0xffa6b10c (memctl_write_dir_access, the string the routine prints); no Linux v5.3 name */
#define SHUB_MD_DIR_ACCESS_LP                        0x100031000 /* established */
#define SHUB_MD_DIR_ACCESS_LP_VALUE_SHIFT            55 /* inferred */
#define SHUB_MD_DIR_ACCESS_LP_VALUE_MASK             0x1ffull
#define SHUB_MD_DIR_ACCESS_LP_VALUE_INPLACE          (SHUB_MD_DIR_ACCESS_LP_VALUE_MASK << SHUB_MD_DIR_ACCESS_LP_VALUE_SHIFT)

/*
 * Memory test data pattern word (first A word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.
 */
/* md_bist_data_a0: w64, reset unknown; SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name */
#define SHUB_MD_BIST_DATA_A0                         0x100038000 /* established */
#define SHUB_MD_BIST_DATA_A0_COUNT                   4
#define SHUB_MD_BIST_DATA_A0_STRIDE                  65536

/*
 * Memory test data pattern word (first B word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.
 */
/* md_bist_data_b0: w64, reset unknown; SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name */
#define SHUB_MD_BIST_DATA_B0                         0x100038010 /* established */
#define SHUB_MD_BIST_DATA_B0_COUNT                   4
#define SHUB_MD_BIST_DATA_B0_STRIDE                  65536

/*
 * Memory test data pattern word (second A word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.
 */
/* md_bist_data_a1: w64, reset unknown; SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name */
#define SHUB_MD_BIST_DATA_A1                         0x100038800 /* established */
#define SHUB_MD_BIST_DATA_A1_COUNT                   4
#define SHUB_MD_BIST_DATA_A1_STRIDE                  65536

/*
 * Memory test data pattern word (second B word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.
 */
/* md_bist_data_b1: w64, reset unknown; SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name */
#define SHUB_MD_BIST_DATA_B1                         0x100038810 /* established */
#define SHUB_MD_BIST_DATA_B1_COUNT                   4
#define SHUB_MD_BIST_DATA_B1_STRIDE                  65536

/*
 * As md_reg_0003_0000 for the right queue port block; the PROM only writes it, with the value it read from md_reg_0003_0000 with bit 3 set. The name is ours.
 */
/* md_reg_0005_0000: w64, reset unknown; SAL 5.04 PROM site 0xffa7861c (write); no Linux v5.3 name */
#define SHUB_MD_REG_0005_0000                        0x100050000 /* established */

/*
 * Presence vector words 0 to 3 of the right directory queue port: the same values as md_dqlp_dir_presvec, written beside them. Never read back. Header title: node [63:0] presence bits, 1 = present; INIT 0.
 */
/* md_dqrp_dir_presvec: w64, reset unknown; SAL 5.04 PROM site 0xffa79310 (names SH_MD_DQRP_MMR_DIR_PRESVEC0 to 3 in the PROM table) */
#define SHUB_MD_DQRP_DIR_PRESVEC                     0x100050100 /* established */
#define SHUB_MD_DQRP_DIR_PRESVEC_COUNT               4
#define SHUB_MD_DQRP_DIR_PRESVEC_STRIDE              16

/*
 * As md_reg_0003_0200 for the right queue port block. The name is ours.
 */
/* md_reg_0005_0200: w64, reset unknown; SAL 5.04 PROM site 0xffa7732c (write loop); no Linux v5.3 name */
#define SHUB_MD_REG_0005_0200                        0x100050200 /* established */
#define SHUB_MD_REG_0005_0200_COUNT                  8
#define SHUB_MD_REG_0005_0200_STRIDE                 16

/*
 * Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names.
 */
/* md_dqrp_dir_privilege_vector: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_DQRP_DIR_PRIVILEGE_VECTOR            0x100050300 /* established */

/*
 * Privilege vectors 1 to 7 of the right directory queue port: the same constants as md_dqlp_dir_privec, written right after each left word.
 */
/* md_dqrp_dir_privec: w64, reset unknown; SAL 5.04 PROM site 0xffa79960, names SH_MD_DQRP_MMR_DIR_PRIVEC1 to 7 in the PROM table */
#define SHUB_MD_DQRP_DIR_PRIVEC                      0x100050310 /* established */
#define SHUB_MD_DQRP_DIR_PRIVEC_COUNT                7
#define SHUB_MD_DQRP_DIR_PRIVEC_STRIDE               16

/*
 * Same as md_reg_0003_0400 for the right queue port block, 0x100 above SH1_MD_DQRP_MMR_DIR_PRIVEC0 (md_dqrp_dir_privilege_vector). The same routine writes 0x1000 to it straight after md_reg_0003_0400. The name is ours; the role is unknown.
 */
/* md_reg_0005_0400: w64, reset unknown; SAL 5.04 PROM site 0xffa7742c (write); the only reference to the address in SAL_A and SAL_B */
#define SHUB_MD_REG_0005_0400                        0x100050400 /* established */

/*
 * As md_dir_access_lp for the right queue port block (SH1_MD_DQRP_MMR_DIR_PRIVEC0's block); the name is ours.
 */
/* md_dir_access_rp: w64, reset unknown; SAL 5.04 PROM site 0xffa6b14c; no Linux v5.3 name */
#define SHUB_MD_DIR_ACCESS_RP                        0x100051000 /* established */
#define SHUB_MD_DIR_ACCESS_RP_VALUE_SHIFT            55 /* inferred */
#define SHUB_MD_DIR_ACCESS_RP_VALUE_MASK             0x1ffull
#define SHUB_MD_DIR_ACCESS_RP_VALUE_INPLACE          (SHUB_MD_DIR_ACCESS_RP_VALUE_MASK << SHUB_MD_DIR_ACCESS_RP_VALUE_SHIFT)

/*
 * I/O interface interrupt 0 and 1 (SH_II_INT0, SH_II_INT1): the register a PIC's interrupt write lands on, through the Crosstalk address nasid << 36 | 1 << 47 | offset. Bits 7:0 are the processor vector, bit 8 sends it to the processor interface (header: a pulse). The data a PIC writes is inferred to be 0x100 | vector. Not accessed by the PROM.
 */
/* ii_int: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_II_INT                                  0x110000000 /* established */
#define SHUB_II_INT_COUNT                            2
#define SHUB_II_INT_STRIDE                           256
#define SHUB_II_INT_SEND_SHIFT                       8 /* established */
#define SHUB_II_INT_SEND_MASK                        0x1ull
#define SHUB_II_INT_SEND_INPLACE                     (SHUB_II_INT_SEND_MASK << SHUB_II_INT_SEND_SHIFT)
#define SHUB_II_INT_IDX_SHIFT                        0 /* established */
#define SHUB_II_INT_IDX_MASK                         0xffull
#define SHUB_II_INT_IDX_INPLACE                      (SHUB_II_INT_IDX_MASK << SHUB_II_INT_IDX_SHIFT)

/*
 * Destination of the I/O interface interrupt n (SH_II_INTn_CONFIG): delivery type, target processor id and optional vector base, the ipi_int layout without send or vector. The PROM writes the processor id of slice 0 to n = 0 and of slice 2 to n = 1 and never reads them.
 */
/* ii_int_config: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_II_INT_CONFIG                           0x110000080 /* established */
#define SHUB_II_INT_CONFIG_COUNT                     2
#define SHUB_II_INT_CONFIG_STRIDE                    256
#define SHUB_II_INT_CONFIG_BASE_SHIFT                21 /* established */
#define SHUB_II_INT_CONFIG_BASE_MASK                 0x1fffffffull
#define SHUB_II_INT_CONFIG_BASE_INPLACE              (SHUB_II_INT_CONFIG_BASE_MASK << SHUB_II_INT_CONFIG_BASE_SHIFT)
#define SHUB_II_INT_CONFIG_PID_SHIFT                 4 /* established */
#define SHUB_II_INT_CONFIG_PID_MASK                  0xffffull
#define SHUB_II_INT_CONFIG_PID_INPLACE               (SHUB_II_INT_CONFIG_PID_MASK << SHUB_II_INT_CONFIG_PID_SHIFT)
#define SHUB_II_INT_CONFIG_AGENT_SHIFT               3 /* established */
#define SHUB_II_INT_CONFIG_AGENT_MASK                0x1ull
#define SHUB_II_INT_CONFIG_AGENT_INPLACE             (SHUB_II_INT_CONFIG_AGENT_MASK << SHUB_II_INT_CONFIG_AGENT_SHIFT)
#define SHUB_II_INT_CONFIG_TYPE_SHIFT                0 /* established */
#define SHUB_II_INT_CONFIG_TYPE_MASK                 0x7ull
#define SHUB_II_INT_CONFIG_TYPE_INPLACE              (SHUB_II_INT_CONFIG_TYPE_MASK << SHUB_II_INT_CONFIG_TYPE_SHIFT)

/*
 * Bit 0 enables the I/O interface interrupt n. The PROM writes 1 to both and never reads them.
 */
/* ii_int_enable: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_II_INT_ENABLE                           0x110000200 /* established */
#define SHUB_II_INT_ENABLE_COUNT                     2
#define SHUB_II_INT_ENABLE_STRIDE                    128
#define SHUB_II_INT_ENABLE_ENABLE_SHIFT              0 /* established */
#define SHUB_II_INT_ENABLE_ENABLE_MASK               0x1ull
#define SHUB_II_INT_ENABLE_ENABLE_INPLACE            (SHUB_II_INT_ENABLE_ENABLE_MASK << SHUB_II_INT_ENABLE_ENABLE_SHIFT)

/*
 * Selects the node whose processors take this node's interrupts when it has none of its own (the PROM's table names it SH_INT_NODE_ID_CONFIG). Role inferred.
 */
/* int_node_id_config: rw64, reset unknown; SAL 5.04 PROM site 0xffb73d76 and 0xffa23b16 (0x800 plus the target NASID in bits 10:0) */
#define SHUB_INT_NODE_ID_CONFIG                      0x110000300 /* established */

/*
 * Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR window with send set, the target's physical processor id, a delivery type, a vector and a fixed base. The kernel stores through uncached physical mode with release ordering, after a memory barrier. On a SHub 1 revision 2 or lower it holds a global lock around the store and waits for the PIO write status to drain.
 */
/* ipi_int: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IPI_INT                                 0x110000380 /* established */
#define SHUB_IPI_INT_SEND_SHIFT                      63 /* established */
#define SHUB_IPI_INT_SEND_MASK                       0x1ull
#define SHUB_IPI_INT_SEND_INPLACE                    (SHUB_IPI_INT_SEND_MASK << SHUB_IPI_INT_SEND_SHIFT)
#define SHUB_IPI_INT_IDX_SHIFT                       52 /* established */
#define SHUB_IPI_INT_IDX_MASK                        0xffull
#define SHUB_IPI_INT_IDX_INPLACE                     (SHUB_IPI_INT_IDX_MASK << SHUB_IPI_INT_IDX_SHIFT)
#define SHUB_IPI_INT_BASE_SHIFT                      21 /* established */
#define SHUB_IPI_INT_BASE_MASK                       0x1fffffffull
#define SHUB_IPI_INT_BASE_INPLACE                    (SHUB_IPI_INT_BASE_MASK << SHUB_IPI_INT_BASE_SHIFT)
#define SHUB_IPI_INT_PID_SHIFT                       4 /* established */
#define SHUB_IPI_INT_PID_MASK                        0xffffull
#define SHUB_IPI_INT_PID_INPLACE                     (SHUB_IPI_INT_PID_MASK << SHUB_IPI_INT_PID_SHIFT)
#define SHUB_IPI_INT_AGENT_SHIFT                     3 /* established */
#define SHUB_IPI_INT_AGENT_MASK                      0x1ull
#define SHUB_IPI_INT_AGENT_INPLACE                   (SHUB_IPI_INT_AGENT_MASK << SHUB_IPI_INT_AGENT_SHIFT)
#define SHUB_IPI_INT_TYPE_SHIFT                      0 /* established */
#define SHUB_IPI_INT_TYPE_MASK                       0x7ull
#define SHUB_IPI_INT_TYPE_INPLACE                    (SHUB_IPI_INT_TYPE_MASK << SHUB_IPI_INT_TYPE_SHIFT)

/*
 * Enable for ipi_int delivery (the PROM's table names it SH_IPI_INT_ENABLE). The PROM writes 1 before it sends wake-up messages and never reads it. That delivery depends on it is inferred.
 */
/* ipi_int_enable: rw64, reset unknown; SAL 5.04 PROM site 0xffa11056 (wake-up of the other processors) and 0xffa314a6; runtime cpu_launch_slave_threads */
#define SHUB_IPI_INT_ENABLE                          0x110000400 /* established */

/*
 * Destination of local interrupt n (0 to 5): the ipi_int message layout without the send bit. The PROM writes type 2 (PMI) vector 1 to interrupts 0 and 1 (slice pairs 0/1 and 2/3), type 5 (INIT) to interrupts 2 and 3 (slices 0 and 2) and vector 0xe9 (Linux SGI_UART_VECTOR) to interrupt 5. Never read. The pairing of these offsets with the PROM's SH_LOCAL_INTn_CONFIG names is by table order (inferred).
 */
/* local_int_config: rw64, reset unknown; SAL 5.04 PROM sites 0xffa23a20 (interrupts 0 and 1, PMI vector 1), 0xffa31290 (interrupts 2 and 3, INIT), 0xffb73b86 (interrupt 5, vector 0xe9) */
#define SHUB_LOCAL_INT_CONFIG                        0x110000480 /* established */
#define SHUB_LOCAL_INT_CONFIG_COUNT                  6
#define SHUB_LOCAL_INT_CONFIG_STRIDE                 256
#define SHUB_LOCAL_INT_CONFIG_IDX_SHIFT              52 /* established */
#define SHUB_LOCAL_INT_CONFIG_IDX_MASK               0xffull
#define SHUB_LOCAL_INT_CONFIG_IDX_INPLACE            (SHUB_LOCAL_INT_CONFIG_IDX_MASK << SHUB_LOCAL_INT_CONFIG_IDX_SHIFT)
#define SHUB_LOCAL_INT_CONFIG_BASE_SHIFT             21 /* established */
#define SHUB_LOCAL_INT_CONFIG_BASE_MASK              0x1fffffffull
#define SHUB_LOCAL_INT_CONFIG_BASE_INPLACE           (SHUB_LOCAL_INT_CONFIG_BASE_MASK << SHUB_LOCAL_INT_CONFIG_BASE_SHIFT)
#define SHUB_LOCAL_INT_CONFIG_PID_SHIFT              4 /* established */
#define SHUB_LOCAL_INT_CONFIG_PID_MASK               0xffffull
#define SHUB_LOCAL_INT_CONFIG_PID_INPLACE            (SHUB_LOCAL_INT_CONFIG_PID_MASK << SHUB_LOCAL_INT_CONFIG_PID_SHIFT)
#define SHUB_LOCAL_INT_CONFIG_AGENT_SHIFT            3 /* established */
#define SHUB_LOCAL_INT_CONFIG_AGENT_MASK             0x1ull
#define SHUB_LOCAL_INT_CONFIG_AGENT_INPLACE          (SHUB_LOCAL_INT_CONFIG_AGENT_MASK << SHUB_LOCAL_INT_CONFIG_AGENT_SHIFT)
#define SHUB_LOCAL_INT_CONFIG_TYPE_SHIFT             0 /* established */
#define SHUB_LOCAL_INT_CONFIG_TYPE_MASK              0x7ull
#define SHUB_LOCAL_INT_CONFIG_TYPE_INPLACE           (SHUB_LOCAL_INT_CONFIG_TYPE_MASK << SHUB_LOCAL_INT_CONFIG_TYPE_SHIFT)

/*
 * Mask of event sources that raise local interrupt n. The PROM writes 0x7ef (the bits it treats as error events), 0x4000 and 0x2000. How a mask bit maps to an event_occurred bit is unknown. Never read.
 */
/* local_int_enable: rw64, reset unknown; SAL 5.04 PROM sites 0xffa23a20 (0x7ef to interrupts 0 and 1), 0xffa31290 (0x4000 to interrupts 2 and 3), 0xffb73bc6 (0x2000 to interrupt 5) */
#define SHUB_LOCAL_INT_ENABLE                        0x110000500 /* established */
#define SHUB_LOCAL_INT_ENABLE_COUNT                  6
#define SHUB_LOCAL_INT_ENABLE_STRIDE                 256

/*
 * Destination of comparator RTC0's interrupt, which the SAL keeps for a delayed bus-error assertion (Linux mmtimer: RTC0 is used by SAL). Layout as rtc_int_config. Never read.
 */
/* rtc0_int_config: rw64, reset unknown; SAL 5.04 PROM site 0xffa31966 (pid << 4 plus 8: agent bit set, type 0, vector 0); runtime plat_assert_berr */
#define SHUB_RTC0_INT_CONFIG                         0x110001380 /* established */

/*
 * Enable for comparator RTC0; written after the compare value, cleared first on undo. Never read.
 */
/* rtc0_int_enable: rw64, reset unknown; SAL 5.04 PROM site 0xffa31a06 (write 1), 0xffa31d76 (write 0) */
#define SHUB_RTC0_INT_ENABLE                         0x110001400 /* established */

/*
 * Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and processor id fields and leaves type, agent and base zero. The register has the same layout as the IPI message, without the send bit. A fourth comparator (RTC 0) exists; the driver comment says firmware uses it, and the header defines nothing for it.
 */
/* rtc_int_config: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC_INT_CONFIG                          0x110001480 /* established */
#define SHUB_RTC_INT_CONFIG_COUNT                    3
#define SHUB_RTC_INT_CONFIG_STRIDE                   256
#define SHUB_RTC_INT_CONFIG_IDX_SHIFT                52 /* established */
#define SHUB_RTC_INT_CONFIG_IDX_MASK                 0xffull
#define SHUB_RTC_INT_CONFIG_IDX_INPLACE              (SHUB_RTC_INT_CONFIG_IDX_MASK << SHUB_RTC_INT_CONFIG_IDX_SHIFT)
#define SHUB_RTC_INT_CONFIG_BASE_SHIFT               21 /* established */
#define SHUB_RTC_INT_CONFIG_BASE_MASK                0x1fffffffull
#define SHUB_RTC_INT_CONFIG_BASE_INPLACE             (SHUB_RTC_INT_CONFIG_BASE_MASK << SHUB_RTC_INT_CONFIG_BASE_SHIFT)
#define SHUB_RTC_INT_CONFIG_PID_SHIFT                4 /* established */
#define SHUB_RTC_INT_CONFIG_PID_MASK                 0xffffull
#define SHUB_RTC_INT_CONFIG_PID_INPLACE              (SHUB_RTC_INT_CONFIG_PID_MASK << SHUB_RTC_INT_CONFIG_PID_SHIFT)
#define SHUB_RTC_INT_CONFIG_AGENT_SHIFT              3 /* established */
#define SHUB_RTC_INT_CONFIG_AGENT_MASK               0x1ull
#define SHUB_RTC_INT_CONFIG_AGENT_INPLACE            (SHUB_RTC_INT_CONFIG_AGENT_MASK << SHUB_RTC_INT_CONFIG_AGENT_SHIFT)
#define SHUB_RTC_INT_CONFIG_TYPE_SHIFT               0 /* established */
#define SHUB_RTC_INT_CONFIG_TYPE_MASK                0x7ull
#define SHUB_RTC_INT_CONFIG_TYPE_INPLACE             (SHUB_RTC_INT_CONFIG_TYPE_MASK << SHUB_RTC_INT_CONFIG_TYPE_SHIFT)

/*
 * Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes the configuration, enables, and only then writes the real expiry, in that order.
 */
/* rtc_int_enable: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC_INT_ENABLE                          0x110001500 /* established */
#define SHUB_RTC_INT_ENABLE_COUNT                    3
#define SHUB_RTC_INT_ENABLE_STRIDE                   256
#define SHUB_RTC_INT_ENABLE_ENABLE_SHIFT             0 /* established */
#define SHUB_RTC_INT_ENABLE_ENABLE_MASK              0x1ull
#define SHUB_RTC_INT_ENABLE_ENABLE_INPLACE           (SHUB_RTC_INT_ENABLE_ENABLE_MASK << SHUB_RTC_INT_ENABLE_ENABLE_SHIFT)

/*
 * Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them; Linux only reads it. Bits the header names are established. SAL 5.04 reads it for the error bits (mask 0x7ef, sites 0xffa239a0 and 0xffa23fd6) and for bit 21 (site 0xffa31506), and writes bits 5 and 8 to this register itself (sites 0xffa32816 and 0xffa32996); a model should OR written bits in (inferred). Zero from reset is tolerated; the reset value is unknown. Bit 21 must read 0 for the PROM's INIT handling. See interrupts.md.
 */
/* event_occurred: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_EVENT_OCCURRED                          0x110010000 /* established */
#define SHUB_EVENT_OCCURRED_II_INT1_SHIFT            30 /* established */
#define SHUB_EVENT_OCCURRED_II_INT1_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_II_INT1_INPLACE          (SHUB_EVENT_OCCURRED_II_INT1_MASK << SHUB_EVENT_OCCURRED_II_INT1_SHIFT)
#define SHUB_EVENT_OCCURRED_II_INT0_SHIFT            29 /* established */
#define SHUB_EVENT_OCCURRED_II_INT0_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_II_INT0_INPLACE          (SHUB_EVENT_OCCURRED_II_INT0_MASK << SHUB_EVENT_OCCURRED_II_INT0_SHIFT)
#define SHUB_EVENT_OCCURRED_IPI_INT_SHIFT            28 /* established */
#define SHUB_EVENT_OCCURRED_IPI_INT_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_IPI_INT_INPLACE          (SHUB_EVENT_OCCURRED_IPI_INT_MASK << SHUB_EVENT_OCCURRED_IPI_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC3_INT_SHIFT           26 /* established */
#define SHUB_EVENT_OCCURRED_RTC3_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC3_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC3_INT_MASK << SHUB_EVENT_OCCURRED_RTC3_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC2_INT_SHIFT           25 /* established */
#define SHUB_EVENT_OCCURRED_RTC2_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC2_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC2_INT_MASK << SHUB_EVENT_OCCURRED_RTC2_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC1_INT_SHIFT           24 /* established */
#define SHUB_EVENT_OCCURRED_RTC1_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC1_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC1_INT_MASK << SHUB_EVENT_OCCURRED_RTC1_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC0_INT_SHIFT           23 /* inferred */
#define SHUB_EVENT_OCCURRED_RTC0_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC0_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC0_INT_MASK << SHUB_EVENT_OCCURRED_RTC0_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_BIT21_SHIFT              21 /* inferred */
#define SHUB_EVENT_OCCURRED_BIT21_MASK               0x1ull
#define SHUB_EVENT_OCCURRED_BIT21_INPLACE            (SHUB_EVENT_OCCURRED_BIT21_MASK << SHUB_EVENT_OCCURRED_BIT21_SHIFT)
#define SHUB_EVENT_OCCURRED_UART_INT_SHIFT           20 /* established */
#define SHUB_EVENT_OCCURRED_UART_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_UART_INT_INPLACE         (SHUB_EVENT_OCCURRED_UART_INT_MASK << SHUB_EVENT_OCCURRED_UART_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_BIT8_SHIFT               8 /* inferred */
#define SHUB_EVENT_OCCURRED_BIT8_MASK                0x1ull
#define SHUB_EVENT_OCCURRED_BIT8_INPLACE             (SHUB_EVENT_OCCURRED_BIT8_MASK << SHUB_EVENT_OCCURRED_BIT8_SHIFT)
#define SHUB_EVENT_OCCURRED_BIT5_SHIFT               5 /* inferred */
#define SHUB_EVENT_OCCURRED_BIT5_MASK                0x1ull
#define SHUB_EVENT_OCCURRED_BIT5_INPLACE             (SHUB_EVENT_OCCURRED_BIT5_MASK << SHUB_EVENT_OCCURRED_BIT5_SHIFT)
#define SHUB_EVENT_OCCURRED_BIT3_SHIFT               3 /* inferred */
#define SHUB_EVENT_OCCURRED_BIT3_MASK                0x1ull
#define SHUB_EVENT_OCCURRED_BIT3_INPLACE             (SHUB_EVENT_OCCURRED_BIT3_MASK << SHUB_EVENT_OCCURRED_BIT3_SHIFT)

/*
 * Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.
 */
/* event_occurred_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_EVENT_OCCURRED_ALIAS                    0x110010008 /* established */

/*
 * Second event word next to event_occurred; only its alias is written by the PROM.
 */
/* event_overflow: rw64, reset unknown; SAL 5.04 PROM register-name table (SH_EVENT_OVERFLOW, pairing by table order); the PROM never accesses it */
#define SHUB_EVENT_OVERFLOW                          0x110010080 /* inferred */

/*
 * Clear alias of event_overflow. The PROM writes 8 together with the same write to event_occurred_alias. Accepting the write is enough.
 */
/* event_overflow_alias: w64, reset unknown; SAL 5.04 PROM site 0xffa0bb46 (write 8) */
#define SHUB_EVENT_OVERFLOW_ALIAS                    0x110010088 /* established */

/*
 * Local block register, unnamed; the name is ours (address). SAL_A writes 0x15031010 to it on each of its two entries (reason 3 and reason 0). The image holds no other reference to the address, so it is never read back. The meaning of the value is unknown; a plain write-accepting register satisfies the PROM.
 */
/* lb_reg_1002_0000: w64, reset unknown; SAL 5.04 PROM site 0xffc4e7f0 (offset and use); no Linux v5.3 name */
#define SHUB_LB_REG_1002_0000                        0x110020000 /* established */

/*
 * Per-slice local block record, 128 bytes apart (index = slice & 3); the name is ours. SAL_B reads the running processor's entry in the lock routine and writes its low byte as a progress code, so any value is accepted; SAL_A reads it into r31 for reasons 1 and 2 and for a reason above 3, not for reason 0 (or 3). The meaning of the value is unknown.
 */
/* lb_slice_rec: r64, reset unknown; SAL 5.04 PROM site 0xffa0e020 (read of the running processor's entry), 0xffc4e570 (not reached for reason 0) */
#define SHUB_LB_SLICE_REC                            0x110030000 /* established */
#define SHUB_LB_SLICE_REC_COUNT                      4
#define SHUB_LB_SLICE_REC_STRIDE                     128

/*
 * Local block LIQ control: request control in bits 4:0, reply control in bits 11:8 and three force-credit bits. The node set-up method (slot 34 of the chip-object table, site 0xffa95c20) reads it once, ORs bit 18 and writes the same value back 63 times in a row; nothing tests the value read. If each write adds one credit to the LINVV credit counter (6 bits wide in lb_credit_status in the header), 63 writes fill it; that role is inferred.
 */
/* lb_liq_ctl: rw64, reset 0x0; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_LB_LIQ_CTL, 'Local Block LIQ Control' (name, offset, mask 0x70f1f, fields); the PROM's register-name table carries the name (SAL 5.04 image, record 132 of the table from 0xffbfabb0); SAL 5.04 PROM site 0xffa95ccc (read), 0xffa95cfc (write) */
#define SHUB_LB_LIQ_CTL                              0x110040000 /* established */
#define SHUB_LB_LIQ_CTL_FORCE_LINVV_CREDIT_SHIFT     18 /* established */
#define SHUB_LB_LIQ_CTL_FORCE_LINVV_CREDIT_MASK      0x1ull
#define SHUB_LB_LIQ_CTL_FORCE_LINVV_CREDIT_INPLACE   (SHUB_LB_LIQ_CTL_FORCE_LINVV_CREDIT_MASK << SHUB_LB_LIQ_CTL_FORCE_LINVV_CREDIT_SHIFT)
#define SHUB_LB_LIQ_CTL_FORCE_RP_CREDIT_SHIFT        17 /* established */
#define SHUB_LB_LIQ_CTL_FORCE_RP_CREDIT_MASK         0x1ull
#define SHUB_LB_LIQ_CTL_FORCE_RP_CREDIT_INPLACE      (SHUB_LB_LIQ_CTL_FORCE_RP_CREDIT_MASK << SHUB_LB_LIQ_CTL_FORCE_RP_CREDIT_SHIFT)
#define SHUB_LB_LIQ_CTL_FORCE_RQ_CREDIT_SHIFT        16 /* established */
#define SHUB_LB_LIQ_CTL_FORCE_RQ_CREDIT_MASK         0x1ull
#define SHUB_LB_LIQ_CTL_FORCE_RQ_CREDIT_INPLACE      (SHUB_LB_LIQ_CTL_FORCE_RQ_CREDIT_MASK << SHUB_LB_LIQ_CTL_FORCE_RQ_CREDIT_SHIFT)
#define SHUB_LB_LIQ_CTL_LIQ_RPL_CTL_SHIFT            8 /* established */
#define SHUB_LB_LIQ_CTL_LIQ_RPL_CTL_MASK             0xfull
#define SHUB_LB_LIQ_CTL_LIQ_RPL_CTL_INPLACE          (SHUB_LB_LIQ_CTL_LIQ_RPL_CTL_MASK << SHUB_LB_LIQ_CTL_LIQ_RPL_CTL_SHIFT)
#define SHUB_LB_LIQ_CTL_LIQ_REQ_CTL_SHIFT            0 /* established */
#define SHUB_LB_LIQ_CTL_LIQ_REQ_CTL_MASK             0x1full
#define SHUB_LB_LIQ_CTL_LIQ_REQ_CTL_INPLACE          (SHUB_LB_LIQ_CTL_LIQ_REQ_CTL_MASK << SHUB_LB_LIQ_CTL_LIQ_REQ_CTL_SHIFT)

/*
 * Maximum number of reply credits from the crossbar. The node set-up method (site 0xffa95c20) reads it, deposits 12 into bits 4:0 and writes it back, once, after the CRB set-up.
 */
/* lb_max_rep_credit_cnt: rw64, reset 0x1f; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_LB_MAX_REP_CREDIT_CNT (name, offset, mask 0x1f, field); the PROM's register-name table carries the name (record 134); SAL 5.04 PROM site 0xffa95f3c (read), 0xffa95f6c (write) */
#define SHUB_LB_MAX_REP_CREDIT_CNT                   0x110040100 /* established */
#define SHUB_LB_MAX_REP_CREDIT_CNT_MAX_CNT_SHIFT     0 /* established */
#define SHUB_LB_MAX_REP_CREDIT_CNT_MAX_CNT_MASK      0x1full
#define SHUB_LB_MAX_REP_CREDIT_CNT_MAX_CNT_INPLACE   (SHUB_LB_MAX_REP_CREDIT_CNT_MAX_CNT_MASK << SHUB_LB_MAX_REP_CREDIT_CNT_MAX_CNT_SHIFT)

/*
 * Maximum number of request credits from the crossbar. The node set-up method (site 0xffa95c20) reads it, deposits 12 into bits 4:0 and writes it back, once.
 */
/* lb_max_req_credit_cnt: rw64, reset 0x1f; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_LB_MAX_REQ_CREDIT_CNT (name, offset, mask 0x1f, field); the PROM's register-name table carries the name (record 135); SAL 5.04 PROM site 0xffa95f7c (read), 0xffa95fbc (write) */
#define SHUB_LB_MAX_REQ_CREDIT_CNT                   0x110040180 /* established */
#define SHUB_LB_MAX_REQ_CREDIT_CNT_MAX_CNT_SHIFT     0 /* established */
#define SHUB_LB_MAX_REQ_CREDIT_CNT_MAX_CNT_MASK      0x1full
#define SHUB_LB_MAX_REQ_CREDIT_CNT_MAX_CNT_INPLACE   (SHUB_LB_MAX_REQ_CREDIT_CNT_MAX_CNT_MASK << SHUB_LB_MAX_REQ_CREDIT_CNT_MAX_CNT_SHIFT)

/*
 * Local block conveyor belt time-out. The node set-up method (site 0xffa95c20) reads it last and writes it back with 0x3e8 (1000) in bits 11:0, the field the header gives.
 */
/* conveyor_belt_time_out: rw64, reset 0x0; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CONVEYOR_BELT_TIME_OUT (name, offset, mask 0xfff, field); the PROM's register-name table carries the name (record 138); SAL 5.04 PROM site 0xffa9613c (read), 0xffa9615c (write) */
#define SHUB_CONVEYOR_BELT_TIME_OUT                  0x110040300 /* established */
#define SHUB_CONVEYOR_BELT_TIME_OUT_VALUE_SHIFT      0 /* established */
#define SHUB_CONVEYOR_BELT_TIME_OUT_VALUE_MASK       0xfffull
#define SHUB_CONVEYOR_BELT_TIME_OUT_VALUE_INPLACE    (SHUB_CONVEYOR_BELT_TIME_OUT_VALUE_MASK << SHUB_CONVEYOR_BELT_TIME_OUT_VALUE_SHIFT)

/*
 * Local block error detail words 1 to 5. A vector read that ends in an error leaves 0xe9 in the low byte of detail 1 (a write 0xea); the PROM then writes 0 to all five and to 0x1_1007_1100, and goes on. Never read otherwise. A plain read/write register that reads 0 satisfies it.
 */
/* lb_error_detail: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_LB_ERROR_DETAIL                         0x110050200 /* established */
#define SHUB_LB_ERROR_DETAIL_COUNT                   5
#define SHUB_LB_ERROR_DETAIL_STRIDE                  128

/*
 * Local block error summary. The PROM tests bit 16 only: set before a vector request means an old error (it writes the alias at +8 and the mask at 0x1_1005_0508 with 0x10000, clears the detail registers and retries); set while waiting for a reply means the reply status is not examined that pass. A model returns 0.
 */
/* lb_error_summary: r64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_LB_ERROR_SUMMARY                        0x110050580 /* established */

/*
 * CPU MMR access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a cleared bit blocks are not in any source read. The SHub 1 node permission set-up (site 0xffa97960): the PROM writes the node mask (one bit per group of nodes, see prom-reset.md); for NASID 0 alone, 1; no read-back.
 */
/* cpu_perm: rw64, reset 0xffffffffffffffff; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CPU_PERM (name, offset, mask 0xffffffffffffffff, field ACCESS_BITS, INIT 0xffffffffffffffff); the PROM's register-name table carries the name (SAL 5.04 image, record 529 of the table from 0xffbfabb0); SAL 5.04 PROM site 0xffa97bbc (write) */
#define SHUB_CPU_PERM                                0x110060000 /* established */

/*
 * External I/O MMR access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a cleared bit blocks are not in any source read. The SHub 1 node permission set-up (site 0xffa97960): the PROM writes 0; no read-back.
 */
/* ext_io_perm: rw64, reset 0x0; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_EXT_IO_PERM (name, offset, mask 0xffffffffffffffff, field ACCESS_BITS, INIT 0); the PROM's register-name table carries the name (SAL 5.04 image, record 531 of the table from 0xffbfabb0); SAL 5.04 PROM site 0xffa97cac (write) */
#define SHUB_EXT_IO_PERM                             0x110060100 /* established */

/*
 * External I/O interrupt access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a cleared bit blocks are not in any source read. The SHub 1 node permission set-up (site 0xffa97960): the PROM writes the node mask (one bit per group of nodes, see prom-reset.md); for NASID 0 alone, 1; no read-back.
 */
/* ext_ioi_access: rw64, reset 0xffffffffffffffff; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_EXT_IOI_ACCESS (name, offset, mask 0xffffffffffffffff, field ACCESS_BITS, INIT 0xffffffffffffffff); the PROM's register-name table carries the name (SAL 5.04 image, record 532 of the table from 0xffbfabb0); SAL 5.04 PROM site 0xffa97c1c (write) */
#define SHUB_EXT_IOI_ACCESS                          0x110060180 /* established */

/*
 * Real-time clock control; the name is ours. The PROM writes 0x100000000, then writes 0 to rtc, then writes 0x100000041, all at the SAL_B reset entry, before any read. The tick period in nanoseconds is 10 times (the period field + 1); with the PROM's write the field is 4, 50 ns, 20 MHz, which is also what SAL_FREQ_BASE for the real-time clock returns (1,000,000,000 divided by the period). The reset value never reaches the PROM. The PROM's own name table and the 2.4 header call this offset SH_GC_SRC_CTRL ('SHub Global Clock Control', mask 0x313ff3ff1, INIT 0x100000000: enable counter bit 0, max count bits 13:4, counter 25:16, toggle bit 28, source select 33:32); the 0x100000041 write is enable plus max count 4. Roles of the other bits are inferred only. If a read returned 0 the PROM would assume a 10 ns period (100 MHz); every PROM deadline is in microseconds scaled by this period, so the counter must tick at the rate the field gives.
 */
/* rtc_ctl: rw64, reset unknown; SAL 5.04 PROM site 0xffa94d06, 0xffa94d26 (writes), 0xffa0da00 (read of the period); the SAL runtime component's chipset_rtc_period reads the same field */
#define SHUB_RTC_CTL                                 0x110060280 /* established */
#define SHUB_RTC_CTL_MODE_SHIFT                      32 /* inferred */
#define SHUB_RTC_CTL_MODE_MASK                       0x3ull
#define SHUB_RTC_CTL_MODE_INPLACE                    (SHUB_RTC_CTL_MODE_MASK << SHUB_RTC_CTL_MODE_SHIFT)
#define SHUB_RTC_CTL_PERIOD_SHIFT                    4 /* inferred */
#define SHUB_RTC_CTL_PERIOD_MASK                     0x3ffull
#define SHUB_RTC_CTL_PERIOD_INPLACE                  (SHUB_RTC_CTL_PERIOD_MASK << SHUB_RTC_CTL_PERIOD_SHIFT)
#define SHUB_RTC_CTL_RUN_SHIFT                       0 /* inferred */
#define SHUB_RTC_CTL_RUN_MASK                        0x1ull
#define SHUB_RTC_CTL_RUN_INPLACE                     (SHUB_RTC_CTL_RUN_MASK << SHUB_RTC_CTL_RUN_SHIFT)

/*
 * I/O interface (II) MMR access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a cleared bit blocks are not in any source read. The SHub 1 node permission set-up (site 0xffa97960): the PROM writes the node mask (one bit per group of nodes, see prom-reset.md); for NASID 0 alone, 1; no read-back.
 */
/* io_perm: rw64, reset 0x0; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_IO_PERM (name, offset, mask 0xffffffffffffffff, field ACCESS_BITS, INIT 0); the PROM's register-name table carries the name (SAL 5.04 image, record 536 of the table from 0xffbfabb0); SAL 5.04 PROM site 0xffa97c4c (write) */
#define SHUB_IO_PERM                                 0x110060380 /* established */

/*
 * I/O interface (II) interrupt access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a cleared bit blocks are not in any source read. The SHub 1 node permission set-up (site 0xffa97960): the PROM writes the node mask (one bit per group of nodes, see prom-reset.md); for NASID 0 alone, 1; no read-back.
 */
/* ioi_access: rw64, reset 0xffffffffffffffff; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_IOI_ACCESS (name, offset, mask 0xffffffffffffffff, field ACCESS_BITS, INIT 0xffffffffffffffff); the PROM's register-name table carries the name (SAL 5.04 image, record 537 of the table from 0xffbfabb0); SAL 5.04 PROM site 0xffa97bec (write) */
#define SHUB_IOI_ACCESS                              0x110060400 /* established */

/*
 * Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross-partition driver reading it as the target of a protected remote read; the driver comment says there is no special reason for that choice. So the register can be read without harm; its bit layout and write behaviour are unknown. The SHub 1 PROM writes 1 here once, as the winner of the node election in SAL_A (SAL 5.04 PROM site 0xffc4ea40); the meaning of 1 is unknown. The node set-up (site 0xffa97c7c) later writes the node mask of the permission registers here too (see prom-reset.md); the header gives INIT 0xffffffffffffffff and a 64-bit ACCESS_BITS field.
 */
/* ipi_access: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IPI_ACCESS                              0x110060480 /* established */

/*
 * DRAM bus clock select; the name is ours. The memory-controller set-up reads it and uses bits 1:0 as an index into a four-entry table held in flash (200, 160, 133 and 100 MHz for 0 to 3, table read). The chosen clock and the DIMM's CAS latency must be a pair the PROM supports or it prints that the memory bus speed is not supported and goes on with unusable timing values. Never written by the PROM. Must return: any value whose bits 1:0 give a supported pair; zero (200 MHz) is the simplest. In the local block by address. Linux does not define it: the position and use are as observed in the PROM, the meaning (bus clock select) is inferred. See memory-init.md.
 */
/* md_clk_sel: r64, reset unknown; SAL 5.04 PROM site 0xffa77e0c (read through the node's global window), 0xffa77e20 (mask); no Linux v5.3 name */
#define SHUB_MD_CLK_SEL                              0x110060500 /* inferred */
#define SHUB_MD_CLK_SEL_SEL_SHIFT                    0 /* inferred */
#define SHUB_MD_CLK_SEL_SEL_MASK                     0x3ull
#define SHUB_MD_CLK_SEL_SEL_INPLACE                  (SHUB_MD_CLK_SEL_SEL_MASK << SHUB_MD_CLK_SEL_SEL_SHIFT)

/*
 * SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in the fallback for an old PROM the nodes-per-bit field, which it reports as the region size. SHub 2's counterpart is not named in the header. The SHub 1 PROM also writes it (SAL 5.04 PROM site 0xffa95a30, reached from 0xffa5f84c): it reads the word, replaces bits 42:32 with the node id, bits 45:44 with a size code and bits 52:48 with a nodes-per-bit code, and writes the word back; the other bits are stored as read, so they may be read only. After the write the three fields must read back as written. The first read, at main start, needs any node id in bits 42:32; the reset value is unknown. See prom-reset.md.
 */
/* shub_id: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_SHUB_ID                                 0x110060580 /* established */
#define SHUB_SHUB_ID_NODES_PER_BIT_SHIFT             48 /* established */
#define SHUB_SHUB_ID_NODES_PER_BIT_MASK              0x1full
#define SHUB_SHUB_ID_NODES_PER_BIT_INPLACE           (SHUB_SHUB_ID_NODES_PER_BIT_MASK << SHUB_SHUB_ID_NODES_PER_BIT_SHIFT)
#define SHUB_SHUB_ID_SIZE_CODE_SHIFT                 44 /* inferred */
#define SHUB_SHUB_ID_SIZE_CODE_MASK                  0x3ull
#define SHUB_SHUB_ID_SIZE_CODE_INPLACE               (SHUB_SHUB_ID_SIZE_CODE_MASK << SHUB_SHUB_ID_SIZE_CODE_SHIFT)
#define SHUB_SHUB_ID_NASID_SHIFT                     32 /* inferred */
#define SHUB_SHUB_ID_NASID_MASK                      0x7ffull
#define SHUB_SHUB_ID_NASID_INPLACE                   (SHUB_SHUB_ID_NASID_MASK << SHUB_SHUB_ID_NASID_SHIFT)
#define SHUB_SHUB_ID_REVISION_SHIFT                  28 /* established */
#define SHUB_SHUB_ID_REVISION_MASK                   0xfull
#define SHUB_SHUB_ID_REVISION_INPLACE                (SHUB_SHUB_ID_REVISION_MASK << SHUB_SHUB_ID_REVISION_SHIFT)

/*
 * Present-SHub vector words 0 to 3 in the processor interface block: the same values as md_dqlp_dir_presvec, written third in each group. Never read back. Header title: Shubs 0 - 63 Present, used for invalidate generation; header INIT 0xffffffffffffffff (macro only, no power-on claim).
 */
/* shubs_present: w64, reset unknown; SAL 5.04 PROM site 0xffa79310 (names SH_SHUBS_PRESENT0 to 3 in the PROM table) */
#define SHUB_SHUBS_PRESENT                           0x110060600 /* established */
#define SHUB_SHUBS_PRESENT_COUNT                     4
#define SHUB_SHUBS_PRESENT_STRIDE                    128

/*
 * Data word of a vector request message. The PROM stores the value to write, or 0xdeadbeefdeadbeef for a read, before arming SH_VEC_PARMS. Not read back. Used only for a record that has a route (a remote node); the local node is reached through its own global window instead.
 */
/* vec_data: w64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_VEC_DATA                                0x110066000 /* established */

/*
 * Vector request parameters and the start/busy handshake. TYPE bit 0 (0 read, 1 write), NI_PORT bit 1, ADDRESS bits 34:3 (the register offset bits 34:3), PIO_ID bits 45:35, START bit 62, BUSY bit 63 (header). The PROM first polls bit 63 until clear (at most 1024 reads), then writes (hops - 1) * 2 | offset AND 0x7fffffff8 | 0x40000e4000000000 for a read (PIO_ID 0x1c8) or | 0x400003d800000001 for a write (PIO_ID 0x7b); START (bit 62) launches the message. The PROM never reads BUSY again after the write; completion is read from SH_VEC_STATUS.
 */
/* vec_parms: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_VEC_PARMS                               0x110066080 /* established */

/*
 * Route of a vector request: the 16-nibble route word shifted down 4 bits (the first nibble goes to SH_VEC_PARMS NI_PORT instead). When the record has no remaining hops the PROM stores 0xf00000000 (a 0xf in nibble 8). Not read back.
 */
/* vec_route: w64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_VEC_ROUTE                               0x110066100 /* established */

/*
 * Data of a vector reply. Read once, after SH_VEC_STATUS shows a valid reply for a read request, and stored as the result.
 */
/* vec_rddata: r64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_VEC_RDDATA                              0x110074000 /* established */

/*
 * Vector reply status. TYPE bits 2:0, ADDRESS bits 34:3, PIO_ID bits 45:35, SOURCE bits 59:46 (header), OVERRUN bit 62, STATUS_VALID bit 63. The PROM writes 0 before each request and reads it: bit 63 already set at that point makes the request fail with -1. After the request it polls (100 microseconds apart, at most 1024 times) until bit 63 is set. The reply is a success only when OVERRUN is clear, TYPE is 0 for a read or 1 for a write, PIO_ID is 0x1c8 (read) or 0x7b (write) and ADDRESS equals the request address bits; OVERRUN gives -2, TYPE 4, 5 or 6 give -4, -5, -6, anything else -3. Writing 0 must clear bit 63.
 */
/* vec_status: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_VEC_STATUS                              0x110074100 /* established */

/*
 * Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel writes the two registers of that node's global window back to back with interrupts and interruption collection off, the first with a type bit, the page-size exponent, the region id and a start bit, the second with the virtual address and a start bit; both stores are in one atomic assembly sequence. It does this once per page of the range, after taking a global lock, for every node that has the mm's processors, except the local node which uses the processor's own global purge instruction instead. Entry 0 is the control word and entry 1 the address word. After a batch of nodes it waits on the PIO write status.
 */
/* ptc: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PTC                                     0x1101a0000 /* established */
#define SHUB_PTC_COUNT                               2
#define SHUB_PTC_STRIDE                              128
#define SHUB_PTC_START_SHIFT                         63 /* established */
#define SHUB_PTC_START_MASK                          0x1ull
#define SHUB_PTC_START_INPLACE                       (SHUB_PTC_START_MASK << SHUB_PTC_START_SHIFT)
#define SHUB_PTC_RID_SHIFT                           8 /* inferred */
#define SHUB_PTC_RID_MASK                            0x7fffffffffffffull
#define SHUB_PTC_RID_INPLACE                         (SHUB_PTC_RID_MASK << SHUB_PTC_RID_SHIFT)
#define SHUB_PTC_PS_SHIFT                            2 /* inferred */
#define SHUB_PTC_PS_MASK                             0x3full
#define SHUB_PTC_PS_INPLACE                          (SHUB_PTC_PS_MASK << SHUB_PTC_PS_SHIFT)
#define SHUB_PTC_TYPE_BIT_SHIFT                      0 /* inferred */
#define SHUB_PTC_TYPE_BIT_MASK                       0x1ull
#define SHUB_PTC_TYPE_BIT_INPLACE                    (SHUB_PTC_TYPE_BIT_MASK << SHUB_PTC_TYPE_BIT_SHIFT)

/*
 * Purge translation cache parameters, next to SH1_PTC_0 and SH1_PTC_1. The PROM writes a value built from a value it read and the constant 0x23c34600 (used when bit 31 of a call result is set) and reads it back; the packing and meaning (a timeout) are not decoded. Neither the PROM nor the runtime stores to ptc itself.
 */
/* ptc_parms: rw64, reset unknown; SAL 5.04 PROM site 0xffa960a6 (write, then read back); the PROM's table lists it as SH_PTC_PARMS */
#define SHUB_PTC_PARMS                               0x1101a0100 /* inferred */

/*
 * Compare value of RTC0 (55 bits). Never read. Whether a value already below the counter fires is unknown.
 */
/* int_cmpa: rw64, reset unknown; SAL 5.04 PROM site 0xffa319e6 (the counter plus the delay in ticks) */
#define SHUB_INT_CMPA                                0x1101b0000 /* established */

/*
 * Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).
 */
/* int_cmp: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_INT_CMP                                 0x1101b0080 /* established */
#define SHUB_INT_CMP_COUNT                           3
#define SHUB_INT_CMP_STRIDE                          128
#define SHUB_INT_CMP_COMPARE_SHIFT                   0 /* established */
#define SHUB_INT_CMP_COMPARE_MASK                    0x7fffffffffffffull
#define SHUB_INT_CMP_COMPARE_INPLACE                 (SHUB_INT_CMP_COMPARE_MASK << SHUB_INT_CMP_COMPARE_SHIFT)

/*
 * Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only. The SHub 1 PROM (SAL 5.04) writes 0 to it at the SAL_B reset entry (0xffa94d20) and again to a node's counter in the interconnect phase, then reads it on every delay and timeout, so it must advance. Its tick period comes from rtc_ctl (SHub 1: 10 ns times the field plus one, 50 ns after the PROM's own write). See prom-reset.md.
 */
/* rtc: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC                                     0x1101c0000 /* established */
#define SHUB_RTC_COUNTER_SHIFT                       0 /* established */
#define SHUB_RTC_COUNTER_MASK                        0x7fffffffffffffull
#define SHUB_RTC_COUNTER_INPLACE                     (SHUB_RTC_COUNTER_MASK << SHUB_RTC_COUNTER_SHIFT)

/*
 * Node election word; the name is ours. SAL_A stores slice + 1 to lb_elect_set and reads this register: the 64-bit value must equal exactly what was written, twice (site 0xffc4e9b0 and 0xffc4e766). Equal means this processor is the node's winner. Later code ORs bits 39 to 41 into it (set bit 41 when no other processor position is flagged; bit 40 set across nodes; bit 39 on a remote node) as firmware state. The relation to lb_elect_set is unknown: a write to the offset 8 above may alias, latch (first writer wins) or store into this word; the code reads the same register for all three.
 */
/* lb_elect: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e9b0, 0xffc4e766 (election reads), 0xffc4e246, 0xffa0b0f0 (bit updates); no Linux v5.3 name */
#define SHUB_LB_ELECT                                0x1101d0080 /* established */

/*
 * Election write register; the name is ours. SAL_A stores slice + 1 here and reads lb_elect. Whether it aliases lb_elect, latches the first writer or something else is unknown. A model that returns the written value at lb_elect satisfies every access read.
 */
/* lb_elect_set: w64, reset unknown; SAL 5.04 PROM site 0xffc4e9a6 (release store of slice + 1); no Linux v5.3 name */
#define SHUB_LB_ELECT_SET                            0x1101d0088 /* established */

/*
 * L1 link state word in the local block; the name is ours. SAL_A's election winner sets bits 41:39 to 7 by read-modify-write, keeping the other bits. An earlier reading says the L1 start checks bits 41:39 for 7; a later review found no reader that does, so that requirement is unconfirmed and plain storage satisfies the write. Other bits are used by the L1 transport and are not decoded here. The PROM's node-object builder (site 0xffa8b5d0, run for the local node by main, slot 95 and slot 81) tests bits 41:39 for 7 and, if so, clears them, saves bits 49:42 from the register, rewrites bits 49:42 incremented modulo 256, then clears bit 63; so the second run finds 0 in bits 41:39 (review of the node set-up traces).
 */
/* lb_l1_state: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e790 and 0xffc4e7a0 (read-modify-write); the PROM's runtime also names the word sc_shub_state_reg and sc_shub_pushed_data_reg */
#define SHUB_LB_L1_STATE                             0x1101d0100 /* established */
#define SHUB_LB_L1_STATE_LINK_SHIFT                  39 /* inferred */
#define SHUB_LB_L1_STATE_LINK_MASK                   0x7ull
#define SHUB_LB_L1_STATE_LINK_INPLACE                (SHUB_LB_L1_STATE_LINK_MASK << SHUB_LB_L1_STATE_LINK_SHIFT)

/*
 * Second firmware lock pair, release side; the name is ours. The methods of the chip object take it around read-modify-writes of fw_word_1540 by the same routines that take lb_lock (site 0xffa0ed30 on this node, 0xffa0ee90 on another): poll lb_lock2_status, do the work, write 0 here. On this node a status that does not read 0 within 1,000,000 microseconds makes the PROM write 0 here and keep polling; the other-node form gives up after its deadline and returns -9 without writing. Whether a read of the status takes the lock in hardware is unknown; a plain register pair where the status always reads 0 satisfies every access read. Linux v5.3 does not define the lock; the behaviour is as observed at the access and the meaning is inferred.
 */
/* lb_lock2: w64, reset unknown; SAL 5.04 PROM site 0xffa0ee40 (release, shared with lb_lock), 0xffa0ed30 (forced release on timeout), 0xffa0eee0 (release on another node), 0xffa0f046 and 0xffa0f5a6 (callers) */
#define SHUB_LB_LOCK2                                0x1101d0180 /* inferred */

/*
 * Second firmware lock status; the name is ours. This-node polls proceed when the whole 64-bit value reads 0 (the same routine as lb_lock_status). The other-node routine, reading it through the node-object read, proceeds when bit 0 reads 0 and ignores the other bits, so a model must keep bit 0 at 0 when the lock is free. A status that never reads 0 times out after 1,000,000 microseconds (forced release on this node, error -9 on another). A read side effect is unknown. Linux v5.3 does not define the lock; the meaning is inferred.
 */
/* lb_lock2_status: r64, reset unknown; SAL 5.04 PROM site 0xffa0ed30 (this-node poll), 0xffa0ad80 (other-node poll), 0xffa0ef40 (descriptor entry), 0xffa0f056 and 0xffa0f5b6 (callers) */
#define SHUB_LB_LOCK2_STATUS                         0x1101d0188 /* inferred */

/*
 * Firmware lock pair, release side; the name is ours. The PROM takes the lock by polling lb_lock_status until it reads 0, does a read-modify-write of cpu_bits, then writes 0 here. If the status does not read 0 within 1,000,000 microseconds it writes 0 here and polls again. Whether a read of lb_lock_status takes the lock in hardware is unknown; a plain register pair where the status always reads 0 satisfies every access read. The same lock guards the field setter of fw_debug_word (site 0xffa974d0). Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.
 */
/* lb_lock: rw64, reset unknown; SAL 5.04 PROM site 0xffa0ed30 (take), 0xffa0ee40 (release), 0xffa0e730 (user) */
#define SHUB_LB_LOCK                                 0x1101d0200 /* inferred */

/*
 * Firmware lock status; the name is ours. The PROM polls it with a short delay until it reads 0; any non-zero value keeps it waiting until the 1,000,000 microsecond deadline, then it writes 0 to lb_lock and keeps polling, so a status that never reads 0 hangs the PROM. A read side effect is unknown. Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.
 */
/* lb_lock_status: r64, reset unknown; SAL 5.04 PROM site 0xffa0ed30 (the poll); the offset-form variant site 0xffa0e880 reads 0x1101d0208 on a remote node */
#define SHUB_LB_LOCK_STATUS                          0x1101d0208 /* inferred */

/*
 * SHub 1 coherent request buffer message control: coherence and speculation enables, mismatch checks and the invalidate-acknowledge (IVACK) throttle. A SAL_B routine sets bit 24 of pi_reg_2001_0100, reads this register, ORs in 0x3b03f7 when the SHub ID revision (bits 31:28 of shub_id) is above 2 and 0x3f1 otherwise, writes it, then writes the saved value back with bit 24 cleared; 0x3f1 sets bits 0 and 9:4, and the 0x3b0000 half of the other value sets bits 21, 20, 19, 17 and 16, which the 2.4 header lists as reserved (the PROM table names fields the header lacks: SYSTEM_FLUSH_DURATION, SYSTEM_FLUSH_INTERVAL, ENABLE_PIPE_SNOOP_ERRORS; their positions are not decoded). SAL_A's error path stores 0x1_0001_0000_0000 here with a plain 64-bit store, and the SAL_B park path passes the same address and value to a write helper (not read): the value clears bits 11:0 (system coherence included) and sets IVACK stall count 1 and throttle control 1. Nothing in the header makes a bit of this register reset the node (inferred).
 */
/* crb_message_control: rw64, reset 0x6; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_MESSAGE_CONTROL, 'Coherent Request Buffer Message Control' (name, offset, bits 11:0 and 63:32); the PROM's own register-name table carries the same name (SAL 5.04 image, table site 0xffbfd280, followed by NACK_LIMIT and TIMEOUT_PRESCALE in the header's order); SAL 5.04 PROM site 0xffa97796 to 0xffa97916 (read, OR, write) and site 0xffc4e276 (SAL_A error path). Linux v5.3 dropped the register */
#define SHUB_CRB_MESSAGE_CONTROL                     0x120000000 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_IVACK_THROTTLE_CONTROL_SHIFT 48 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_IVACK_THROTTLE_CONTROL_MASK 0xffffull
#define SHUB_CRB_MESSAGE_CONTROL_IVACK_THROTTLE_CONTROL_INPLACE (SHUB_CRB_MESSAGE_CONTROL_IVACK_THROTTLE_CONTROL_MASK << SHUB_CRB_MESSAGE_CONTROL_IVACK_THROTTLE_CONTROL_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_IVACK_STALL_COUNT_SHIFT 32 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_IVACK_STALL_COUNT_MASK 0xffffull
#define SHUB_CRB_MESSAGE_CONTROL_IVACK_STALL_COUNT_INPLACE (SHUB_CRB_MESSAGE_CONTROL_IVACK_STALL_COUNT_MASK << SHUB_CRB_MESSAGE_CONTROL_IVACK_STALL_COUNT_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_ENABLE_IVACK_CONSOLIDATION_SHIFT 11 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_ENABLE_IVACK_CONSOLIDATION_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_ENABLE_IVACK_CONSOLIDATION_INPLACE (SHUB_CRB_MESSAGE_CONTROL_ENABLE_IVACK_CONSOLIDATION_MASK << SHUB_CRB_MESSAGE_CONTROL_ENABLE_IVACK_CONSOLIDATION_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_SUPPRESS_BOGUS_WRITES_SHIFT 10 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_SUPPRESS_BOGUS_WRITES_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_SUPPRESS_BOGUS_WRITES_INPLACE (SHUB_CRB_MESSAGE_CONTROL_SUPPRESS_BOGUS_WRITES_MASK << SHUB_CRB_MESSAGE_CONTROL_SUPPRESS_BOGUS_WRITES_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_XB_ENABLE_SHIFT 9 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_XB_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_XB_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_XB_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_XB_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_XB_ENABLE_SHIFT 8 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_XB_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_XB_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_XB_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_XB_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_IRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_SHIFT 7 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_IRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_IRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_IRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_IRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_SHIFT 6 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_WRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_SHIFT 5 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_RRB_ATTRIBUTE_MISMATCH_FSB_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_ENABLE_SHIFT 4 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_SHIFT 3 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_MASK  0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_INPLACE (SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_MASK << SHUB_CRB_MESSAGE_CONTROL_MESSAGE_COLOR_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_REMOTE_SPECULATIVE_MESSAGE_ENABLE_SHIFT 2 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_REMOTE_SPECULATIVE_MESSAGE_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_REMOTE_SPECULATIVE_MESSAGE_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_REMOTE_SPECULATIVE_MESSAGE_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_REMOTE_SPECULATIVE_MESSAGE_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_LOCAL_SPECULATIVE_MESSAGE_ENABLE_SHIFT 1 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_LOCAL_SPECULATIVE_MESSAGE_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_LOCAL_SPECULATIVE_MESSAGE_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_LOCAL_SPECULATIVE_MESSAGE_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_LOCAL_SPECULATIVE_MESSAGE_ENABLE_SHIFT)
#define SHUB_CRB_MESSAGE_CONTROL_SYSTEM_COHERENCE_ENABLE_SHIFT 0 /* established */
#define SHUB_CRB_MESSAGE_CONTROL_SYSTEM_COHERENCE_ENABLE_MASK 0x1ull
#define SHUB_CRB_MESSAGE_CONTROL_SYSTEM_COHERENCE_ENABLE_INPLACE (SHUB_CRB_MESSAGE_CONTROL_SYSTEM_COHERENCE_ENABLE_MASK << SHUB_CRB_MESSAGE_CONTROL_SYSTEM_COHERENCE_ENABLE_SHIFT)

/*
 * Coherent request buffer NACK limit: a 12-bit count limit, a 4-bit frequency for the priority count and an enable in bit 63. The node set-up method (slot 34 of the chip-object table, site 0xffa95c20) reads it (site 0xffa95fcc) and writes it back (0xffa9601c) with bit 63 cleared and bits 15:0 set to 0xffff: a 0xfff limit and a 0xf frequency, enable off.
 */
/* crb_nack_limit: rw64, reset 0x0; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_NACK_LIMIT (name, offset, fields); the PROM's register-name table carries the name at the next entry after SH_CRB_MESSAGE_CONTROL */
#define SHUB_CRB_NACK_LIMIT                          0x120000080 /* established */
#define SHUB_CRB_NACK_LIMIT_ENABLE_SHIFT             63 /* established */
#define SHUB_CRB_NACK_LIMIT_ENABLE_MASK              0x1ull
#define SHUB_CRB_NACK_LIMIT_ENABLE_INPLACE           (SHUB_CRB_NACK_LIMIT_ENABLE_MASK << SHUB_CRB_NACK_LIMIT_ENABLE_SHIFT)
#define SHUB_CRB_NACK_LIMIT_PRI_FREQ_SHIFT           12 /* established */
#define SHUB_CRB_NACK_LIMIT_PRI_FREQ_MASK            0xfull
#define SHUB_CRB_NACK_LIMIT_PRI_FREQ_INPLACE         (SHUB_CRB_NACK_LIMIT_PRI_FREQ_MASK << SHUB_CRB_NACK_LIMIT_PRI_FREQ_SHIFT)
#define SHUB_CRB_NACK_LIMIT_LIMIT_SHIFT              0 /* established */
#define SHUB_CRB_NACK_LIMIT_LIMIT_MASK               0xfffull
#define SHUB_CRB_NACK_LIMIT_LIMIT_INPLACE            (SHUB_CRB_NACK_LIMIT_LIMIT_MASK << SHUB_CRB_NACK_LIMIT_LIMIT_SHIFT)

/*
 * Coherent request buffer timeout prescale: one 32-bit scaling factor in bits 31:0. The node set-up method (site 0xffa95c20) reads it (site 0xffa9608c) and rewrites bits 31:0 (store site 0xffa960cc, a mix4.l keeping bits 63:32): 0x23c34600 (600,000,000) unless the environment attribute NoTimeouts is found, in which case 0. The attribute lookup call is site 0xffa9605c.
 */
/* crb_timeout_prescale: rw64, reset 0x0; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_TIMEOUT_PRESCALE (name, offset, field); the PROM's register-name table carries the name two entries after SH_CRB_MESSAGE_CONTROL */
#define SHUB_CRB_TIMEOUT_PRESCALE                    0x120000100 /* established */
#define SHUB_CRB_TIMEOUT_PRESCALE_SCALING_FACTOR_SHIFT 0 /* established */
#define SHUB_CRB_TIMEOUT_PRESCALE_SCALING_FACTOR_MASK 0xffffffffull
#define SHUB_CRB_TIMEOUT_PRESCALE_SCALING_FACTOR_INPLACE (SHUB_CRB_TIMEOUT_PRESCALE_SCALING_FACTOR_MASK << SHUB_CRB_TIMEOUT_PRESCALE_SCALING_FACTOR_SHIFT)

/*
 * Coherent request buffer timeout skid limit: a 6-bit skid in bits 5:0 and a reset-skid-counter bit in bit 63. A routine reached through a table that also writes pi_cam_control reads this register and writes it back with bit 63 set. The node set-up method (site 0xffa95c20) (read 0xffa95d4c, write 0xffa95dcc) also clears bits 63 and 62, sets bits 11:8 and deposits 2 into bits 5:0; the 2.4 header's mask 0x800000000000003f has no bits 11:8 or 62, so those writes are outside the header's layout.
 */
/* crb_timeout_skid: rw64, reset 0x7; SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_TIMEOUT_SKID (name, offset, fields); SAL 5.04 PROM site 0xffa2459c to 0xffa245cc (read, OR bit 63, write); other sites site 0xffae3696 */
#define SHUB_CRB_TIMEOUT_SKID                        0x120000180 /* established */
#define SHUB_CRB_TIMEOUT_SKID_RESET_SKID_COUNT_SHIFT 63 /* established */
#define SHUB_CRB_TIMEOUT_SKID_RESET_SKID_COUNT_MASK  0x1ull
#define SHUB_CRB_TIMEOUT_SKID_RESET_SKID_COUNT_INPLACE (SHUB_CRB_TIMEOUT_SKID_RESET_SKID_COUNT_MASK << SHUB_CRB_TIMEOUT_SKID_RESET_SKID_COUNT_SHIFT)
#define SHUB_CRB_TIMEOUT_SKID_SKID_SHIFT             0 /* established */
#define SHUB_CRB_TIMEOUT_SKID_SKID_MASK              0x3full
#define SHUB_CRB_TIMEOUT_SKID_SKID_INPLACE           (SHUB_CRB_TIMEOUT_SKID_SKID_MASK << SHUB_CRB_TIMEOUT_SKID_SKID_SHIFT)

/*
 * Processor interface register, unnamed (the block is inferred from the neighbouring SH1_PI_CAM_CONTROL and SH1_PIO_WRITE_STATUS_0); the name is ours. SAL_A reads it and writes it back with bit 24 set, using the read value for nothing else. The PROM later brackets writes to the register site 0x120000000 with bit 24 set then cleared, which suggests a write enable (inferred). Any reset value is tolerated; bit 24 must be settable and read back as written.
 */
/* pi_reg_2001_0100: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e800 and 0xffc4e816 (read-modify-write); Linux v5.3 defines no name */
#define SHUB_PI_REG_2001_0100                        0x120010100 /* established */
#define SHUB_PI_REG_2001_0100_BIT24_SHIFT            24 /* inferred */
#define SHUB_PI_REG_2001_0100_BIT24_MASK             0x1ull
#define SHUB_PI_REG_2001_0100_BIT24_INPLACE          (SHUB_PI_REG_2001_0100_BIT24_MASK << SHUB_PI_REG_2001_0100_BIT24_SHIFT)
#define SHUB_PI_REG_2001_0100_BIT17_SHIFT            17 /* inferred */
#define SHUB_PI_REG_2001_0100_BIT17_MASK             0x1ull
#define SHUB_PI_REG_2001_0100_BIT17_INPLACE          (SHUB_PI_REG_2001_0100_BIT17_MASK << SHUB_PI_REG_2001_0100_BIT17_SHIFT)
#define SHUB_PI_REG_2001_0100_BIT3_SHIFT             3 /* inferred */
#define SHUB_PI_REG_2001_0100_BIT3_MASK              0x1ull
#define SHUB_PI_REG_2001_0100_BIT3_INPLACE           (SHUB_PI_REG_2001_0100_BIT3_MASK << SHUB_PI_REG_2001_0100_BIT3_SHIFT)

/*
 * Per-slice flags in the processor interface; the name is ours. The local-master arbitration reads it for slices 0 and 1 other than the running one and tests bit slice; a set bit makes the PROM count that processor present and wait for it (up to 5,000,000 microseconds). On a one-processor node the bit for every other slice must read 0. The meaning (processor present) is inferred from that use. Later CPU-enumeration callers of the same word read bits 0 and 1 (first processor of slices 0 and 1) and bits 4 and 5 (second processor); the own-slice bit they expect was not traced, so a model should set it.
 */
/* pi_slice_present: r64, reset unknown; SAL 5.04 PROM site 0xffa115ac (read through the global window of the node), 0xffa99e2c (caller) */
#define SHUB_PI_SLICE_PRESENT                        0x120020080 /* established */
#define SHUB_PI_SLICE_PRESENT_PRESENT2_SHIFT         4 /* inferred */
#define SHUB_PI_SLICE_PRESENT_PRESENT2_MASK          0x3ull
#define SHUB_PI_SLICE_PRESENT_PRESENT2_INPLACE       (SHUB_PI_SLICE_PRESENT_PRESENT2_MASK << SHUB_PI_SLICE_PRESENT_PRESENT2_SHIFT)
#define SHUB_PI_SLICE_PRESENT_PRESENT_SHIFT          0 /* inferred */
#define SHUB_PI_SLICE_PRESENT_PRESENT_MASK           0x3ull
#define SHUB_PI_SLICE_PRESENT_PRESENT_INPLACE        (SHUB_PI_SLICE_PRESENT_PRESENT_MASK << SHUB_PI_SLICE_PRESENT_PRESENT_SHIFT)

/*
 * Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the kernel writes 0x8000000000000010 here on every timer tick, through the address of its own node. What the value does is unknown. The SHub 1 PROM (SAL 5.04) also writes it, from two routines reached through tables (site 0xffa24510 and 0xffa245f0, order not located): the low 7 bits of an argument with bit 63 set, plus bit 8 (and bit 9 when bit 5 of the argument is set) in the first, and with bits 9:8 clear in the second; the second then reads pi_reg_2006_0100, pi_reg_2006_0180 and pi_reg_2006_0200. Meaning of the fields is unknown.
 */
/* pi_cam_control: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PI_CAM_CONTROL                          0x120050300 /* established */

/*
 * Processor interface register, unnamed; the name is ours. Read once, with pi_reg_2006_0180 and pi_reg_2006_0200, right after the second pi_cam_control write; the value is stored for a later report. Any value is tolerated (inferred; the consumer was not traced).
 */
/* pi_reg_2006_0100: r64, reset unknown; SAL 5.04 PROM site 0xffa246a6 (read after the pi_cam_control write); no Linux v5.3 name */
#define SHUB_PI_REG_2006_0100                        0x120060100 /* inferred */

/*
 * Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100.
 */
/* pi_reg_2006_0180: r64, reset unknown; SAL 5.04 PROM site 0xffa246d6; no Linux v5.3 name */
#define SHUB_PI_REG_2006_0180                        0x120060180 /* inferred */

/*
 * Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100.
 */
/* pi_reg_2006_0200: r64, reset unknown; SAL 5.04 PROM site 0xffa246f6; no Linux v5.3 name */
#define SHUB_PI_REG_2006_0200                        0x120060200 /* inferred */

/*
 * PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O write barrier spins until the pending write count shows idle. The kernel stores the address of the instance for its slice (the slice is the processor's position within the node) in its per-processor data.
 */
/* pio_write_status: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PIO_WRITE_STATUS                        0x120070200 /* established */
#define SHUB_PIO_WRITE_STATUS_COUNT                  2
#define SHUB_PIO_WRITE_STATUS_STRIDE                 128
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT 56 /* established */
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK 0x3full
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_INPLACE (SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK << SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT)
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT   1 /* established */
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK    0x1ull
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_INPLACE (SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK << SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT)

/*
 * Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.
 */
/* pio_write_status_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PIO_WRITE_STATUS_ALIAS                  0x120070208 /* inferred */
#define SHUB_PIO_WRITE_STATUS_ALIAS_COUNT            2
#define SHUB_PIO_WRITE_STATUS_ALIAS_STRIDE           128

/*
 * Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). Network interface link state. The PROM reads it once per port in its link probe and compares the low nibble with 9, nothing else. 9 is taken as link up (inferred from the use: the probe then checks the link credit words and reports success). Any other value is a link that is not up; no PROM code separates a link that is down from a port with no cable. The INIT of zero is a not-up value, so a node with no NUMAlink cable keeps the hardware path.
 */
/* ni_llp_stat: r64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI_LLP_STAT                             0x150000000 /* established */
#define SHUB_NI_LLP_STAT_COUNT                       2
#define SHUB_NI_LLP_STAT_STRIDE                      8192
#define SHUB_NI_LLP_STAT_LINK_RESET_STATE_SHIFT      0 /* established */
#define SHUB_NI_LLP_STAT_LINK_RESET_STATE_MASK       0xfull
#define SHUB_NI_LLP_STAT_LINK_RESET_STATE_INPLACE    (SHUB_NI_LLP_STAT_LINK_RESET_STATE_MASK << SHUB_NI_LLP_STAT_LINK_RESET_STATE_SHIFT)

/*
 * Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). Writing issues a reset to the network interface; the header says bits generate pulses. The PROM writes 1 (link reset) to each port whose probe says not up, up to three times with delays of 100, 200 and 400 microseconds. A write must not make link_reset_state read 9. Never read.
 */
/* ni_llp_reset: w64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI_LLP_RESET                            0x150000008 /* established */
#define SHUB_NI_LLP_RESET_COUNT                      2
#define SHUB_NI_LLP_RESET_STRIDE                     8192
#define SHUB_NI_LLP_RESET_WARM_SHIFT                 1 /* established */
#define SHUB_NI_LLP_RESET_WARM_MASK                  0x1ull
#define SHUB_NI_LLP_RESET_WARM_INPLACE               (SHUB_NI_LLP_RESET_WARM_MASK << SHUB_NI_LLP_RESET_WARM_SHIFT)
#define SHUB_NI_LLP_RESET_LINK_SHIFT                 0 /* established */
#define SHUB_NI_LLP_RESET_LINK_MASK                  0x1ull
#define SHUB_NI_LLP_RESET_LINK_INPLACE               (SHUB_NI_LLP_RESET_LINK_MASK << SHUB_NI_LLP_RESET_LINK_SHIFT)

/*
 * Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). Signalling mode of the LLP channel. The PROM reads it once per port and tests bit 0 (32-bit phits): clear selects test-control mode 3 and the link-retry loop, set selects mode 0 and no loop. The INIT of zero takes the loop. Never written.
 */
/* ni_llp_chan_mode: r64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI_LLP_CHAN_MODE                        0x150000018 /* established */
#define SHUB_NI_LLP_CHAN_MODE_COUNT                  2
#define SHUB_NI_LLP_CHAN_MODE_STRIDE                 8192
#define SHUB_NI_LLP_CHAN_MODE_BITMODE32_SHIFT        0 /* established */
#define SHUB_NI_LLP_CHAN_MODE_BITMODE32_MASK         0x1ull
#define SHUB_NI_LLP_CHAN_MODE_BITMODE32_INPLACE      (SHUB_NI_LLP_CHAN_MODE_BITMODE32_MASK << SHUB_NI_LLP_CHAN_MODE_BITMODE32_SHIFT)

/*
 * Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). LLP and channel configuration. The PROM reads it and writes it straight back with MAXBURST set to 400; no other bit changes and the value read is never tested, so a plain read/write register satisfies it. This is the read that stops a model at 0x1_5000_0020.
 */
/* ni_llp_config: rw64, reset 0x7fc6ffd00; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI_LLP_CONFIG                           0x150000020 /* established */
#define SHUB_NI_LLP_CONFIG_COUNT                     2
#define SHUB_NI_LLP_CONFIG_STRIDE                    8192
#define SHUB_NI_LLP_CONFIG_FTU_TIME_SHIFT            26 /* established */
#define SHUB_NI_LLP_CONFIG_FTU_TIME_MASK             0x3ffull
#define SHUB_NI_LLP_CONFIG_FTU_TIME_INPLACE          (SHUB_NI_LLP_CONFIG_FTU_TIME_MASK << SHUB_NI_LLP_CONFIG_FTU_TIME_SHIFT)
#define SHUB_NI_LLP_CONFIG_NULLTIMEOUT_SHIFT         20 /* established */
#define SHUB_NI_LLP_CONFIG_NULLTIMEOUT_MASK          0x3full
#define SHUB_NI_LLP_CONFIG_NULLTIMEOUT_INPLACE       (SHUB_NI_LLP_CONFIG_NULLTIMEOUT_MASK << SHUB_NI_LLP_CONFIG_NULLTIMEOUT_SHIFT)
#define SHUB_NI_LLP_CONFIG_MAXRETRY_SHIFT            10 /* established */
#define SHUB_NI_LLP_CONFIG_MAXRETRY_MASK             0x3ffull
#define SHUB_NI_LLP_CONFIG_MAXRETRY_INPLACE          (SHUB_NI_LLP_CONFIG_MAXRETRY_MASK << SHUB_NI_LLP_CONFIG_MAXRETRY_SHIFT)
#define SHUB_NI_LLP_CONFIG_MAXBURST_SHIFT            0 /* established */
#define SHUB_NI_LLP_CONFIG_MAXBURST_MASK             0x3ffull
#define SHUB_NI_LLP_CONFIG_MAXBURST_INPLACE          (SHUB_NI_LLP_CONFIG_MAXBURST_MASK << SHUB_NI_LLP_CONFIG_MAXBURST_SHIFT)

/*
 * Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). LLP test control. The PROM reads it, clears bits 41:40 when a link retry is needed, and finally writes bits 41:40 to the mode chosen from chan_mode.bitmode32 (3 when that bit is clear, which is the INIT). Bits 41:40 are the header field SEND_TEST_MODE; why the PROM sets 3 on a link with no test running is unknown. A plain read/write register satisfies it.
 */
/* ni_llp_test_ctl: rw64, reset 0xa5fffff; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI_LLP_TEST_CTL                         0x150000028 /* established */
#define SHUB_NI_LLP_TEST_CTL_COUNT                   2
#define SHUB_NI_LLP_TEST_CTL_STRIDE                  8192
#define SHUB_NI_LLP_TEST_CTL_SEND_TEST_MODE_SHIFT    40 /* established */
#define SHUB_NI_LLP_TEST_CTL_SEND_TEST_MODE_MASK     0x3ull
#define SHUB_NI_LLP_TEST_CTL_SEND_TEST_MODE_INPLACE  (SHUB_NI_LLP_TEST_CTL_SEND_TEST_MODE_MASK << SHUB_NI_LLP_TEST_CTL_SEND_TEST_MODE_SHIFT)

/*
 * Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). LLP error status. The PROM reads it; if bit 27 (the power_OK loss trap) is set it writes the word back with that bit clear and reads again; a bit still set makes the probe return 0 and the port counts as not ready. A model returns 0 and the probe goes on to the link state.
 */
/* ni_llp_err: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI_LLP_ERR                              0x150000048 /* established */
#define SHUB_NI_LLP_ERR_COUNT                        2
#define SHUB_NI_LLP_ERR_STRIDE                       8192
#define SHUB_NI_LLP_ERR_POWER_NOT_OK_SHIFT           27 /* established */
#define SHUB_NI_LLP_ERR_POWER_NOT_OK_MASK            0x1ull
#define SHUB_NI_LLP_ERR_POWER_NOT_OK_INPLACE         (SHUB_NI_LLP_ERR_POWER_NOT_OK_MASK << SHUB_NI_LLP_ERR_POWER_NOT_OK_SHIFT)

/*
 * Link flow words 0 to 3 of NI port 0. The PROM reads them only when ni_llp_stat reads 9 (and the CPU is not the simulator id), each up to 128 times until bits 22:16 (the dynamic vc0 credit, header CREDIT_VC0_DYN) are non-zero, and returns link-down if 128 reads do not. Not reached when the link state is not 9.
 */
/* xnni0_link_flow: r64, reset 0x1800; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI0_LINK_FLOW                         0x150001040 /* established */
#define SHUB_XNNI0_LINK_FLOW_COUNT                   4
#define SHUB_XNNI0_LINK_FLOW_STRIDE                  16

/*
 * Link flow words 0 to 3 of NI port 1. The PROM reads them only when ni_llp_stat reads 9 (and the CPU is not the simulator id), each up to 128 times until bits 22:16 (the dynamic vc0 credit, header CREDIT_VC0_DYN) are non-zero, and returns link-down if 128 reads do not. Not reached when the link state is not 9.
 */
/* xnni1_link_flow: r64, reset 0x1800; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI1_LINK_FLOW                         0x150003040 /* established */
#define SHUB_XNNI1_LINK_FLOW_COUNT                   4
#define SHUB_XNNI1_LINK_FLOW_STRIDE                  16

/*
 * Local routing table of the I/O-interface side local block: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction for the next chip), V0 bit 4, NI_SEL0 bit 5, VALID bit 63 (header). The PROM writes entry i as a direction nibble taken from its route table (0xf means no route) with bit 63 set for entry 0, for the entry equal to the node's own NASID modulo 128 and for any entry whose nibble is not 0xf; the tables written to IILB, PI and MD also carry a second direction in bits 13:8 (bit 13 = 0x20 when the second port has a route), which the header mask does not include. Plain storage for the PROM: it writes every entry and reads one back only when the record is flagged for read-and-compare (not the lone-node path). Entry contents for NASID 0 alone are unknown (they come from the PROM route calculation, which is not traced).
 */
/* iilb_local_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IILB_LOCAL_TABLE                        0x150020000 /* established */
#define SHUB_IILB_LOCAL_TABLE_COUNT                  128
#define SHUB_IILB_LOCAL_TABLE_STRIDE                 8

/*
 * Global routing table of the I/O-interface side local block: 16 doublewords, same entry layout as iilb_local_table, indexed by the high NASID bits (the PROM loops 0 to 15). Written with the same rule as the local table. Plain storage for the PROM.
 */
/* iilb_global_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IILB_GLOBAL_TABLE                       0x150020400 /* established */
#define SHUB_IILB_GLOBAL_TABLE_COUNT                 16
#define SHUB_IILB_GLOBAL_TABLE_STRIDE                8

/*
 * Route override entry of the I/O-interface side local block; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header INIT is 0x8000000000000000 (enabled). The PROM writes 0 to disable it, once per walk after the tables. Plain storage.
 */
/* iilb_over_ride_table: rw64, reset 0x8000000000000000; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IILB_OVER_RIDE_TABLE                    0x150020480 /* established */

/*
 * Local routing table of the processor interface: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction for the next chip), V0 bit 4, NI_SEL0 bit 5, VALID bit 63 (header). The PROM writes entry i as a direction nibble taken from its route table (0xf means no route) with bit 63 set for entry 0, for the entry equal to the node's own NASID modulo 128 and for any entry whose nibble is not 0xf; the tables written to IILB, PI and MD also carry a second direction in bits 13:8 (bit 13 = 0x20 when the second port has a route), which the header mask does not include. Plain storage for the PROM: it writes every entry and reads one back only when the record is flagged for read-and-compare (not the lone-node path). Entry contents for NASID 0 alone are unknown (they come from the PROM route calculation, which is not traced).
 */
/* pi_local_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PI_LOCAL_TABLE                          0x150021000 /* established */
#define SHUB_PI_LOCAL_TABLE_COUNT                    128
#define SHUB_PI_LOCAL_TABLE_STRIDE                   8

/*
 * Global routing table of the processor interface: 16 doublewords, same entry layout as pi_local_table, indexed by the high NASID bits (the PROM loops 0 to 15). Written with the same rule as the local table. Plain storage for the PROM.
 */
/* pi_global_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PI_GLOBAL_TABLE                         0x150021400 /* established */
#define SHUB_PI_GLOBAL_TABLE_COUNT                   16
#define SHUB_PI_GLOBAL_TABLE_STRIDE                  8

/*
 * Route override entry of the processor interface; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header INIT is 0x8000000000000000 (enabled). The PROM writes 0 to disable it, once per walk after the tables. Plain storage.
 */
/* pi_over_ride_table: rw64, reset 0x8000000000000000; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PI_OVER_RIDE_TABLE                      0x150021480 /* established */

/*
 * Local routing table of network interface port 0: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction for the next chip), V0 bit 4, NI_SEL0 bit 5, VALID bit 63 (header). The PROM writes entry i as a direction nibble taken from its route table (0xf means no route) with bit 63 set for entry 0, for the entry equal to the node's own NASID modulo 128 and for any entry whose nibble is not 0xf; the tables written to IILB, PI and MD also carry a second direction in bits 13:8 (bit 13 = 0x20 when the second port has a route), which the header mask does not include. Plain storage for the PROM: it writes every entry and reads one back only when the record is flagged for read-and-compare (not the lone-node path). Entry contents for NASID 0 alone are unknown (they come from the PROM route calculation, which is not traced).
 */
/* ni0_local_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI0_LOCAL_TABLE                         0x150022000 /* established */
#define SHUB_NI0_LOCAL_TABLE_COUNT                   128
#define SHUB_NI0_LOCAL_TABLE_STRIDE                  8

/*
 * Global routing table of network interface port 0: 16 doublewords, same entry layout as ni0_local_table, indexed by the high NASID bits (the PROM loops 0 to 15). Written with the same rule as the local table. Plain storage for the PROM.
 */
/* ni0_global_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI0_GLOBAL_TABLE                        0x150022400 /* established */
#define SHUB_NI0_GLOBAL_TABLE_COUNT                  16
#define SHUB_NI0_GLOBAL_TABLE_STRIDE                 8

/*
 * Route override entry of network interface port 0; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header INIT is 0x8000000000000000 (enabled). The PROM writes 0 to disable it, once per walk after the tables. Plain storage.
 */
/* ni0_over_ride_table: rw64, reset 0x8000000000000000; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI0_OVER_RIDE_TABLE                     0x150022480 /* established */

/*
 * Local routing table of network interface port 1: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction for the next chip), V0 bit 4, NI_SEL0 bit 5, VALID bit 63 (header). The PROM writes entry i as a direction nibble taken from its route table (0xf means no route) with bit 63 set for entry 0, for the entry equal to the node's own NASID modulo 128 and for any entry whose nibble is not 0xf; the tables written to IILB, PI and MD also carry a second direction in bits 13:8 (bit 13 = 0x20 when the second port has a route), which the header mask does not include. Plain storage for the PROM: it writes every entry and reads one back only when the record is flagged for read-and-compare (not the lone-node path). Entry contents for NASID 0 alone are unknown (they come from the PROM route calculation, which is not traced).
 */
/* ni1_local_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI1_LOCAL_TABLE                         0x150023000 /* established */
#define SHUB_NI1_LOCAL_TABLE_COUNT                   128
#define SHUB_NI1_LOCAL_TABLE_STRIDE                  8

/*
 * Global routing table of network interface port 1: 16 doublewords, same entry layout as ni1_local_table, indexed by the high NASID bits (the PROM loops 0 to 15). Written with the same rule as the local table. Plain storage for the PROM.
 */
/* ni1_global_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI1_GLOBAL_TABLE                        0x150023400 /* established */
#define SHUB_NI1_GLOBAL_TABLE_COUNT                  16
#define SHUB_NI1_GLOBAL_TABLE_STRIDE                 8

/*
 * Route override entry of network interface port 1; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header INIT is 0x8000000000000000 (enabled). The PROM writes 0 to disable it, once per walk after the tables. Plain storage.
 */
/* ni1_over_ride_table: rw64, reset 0x8000000000000000; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_NI1_OVER_RIDE_TABLE                     0x150023480 /* established */

/*
 * Local routing table of the memory and directory unit: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction for the next chip), V0 bit 4, NI_SEL0 bit 5, VALID bit 63 (header). The PROM writes entry i as a direction nibble taken from its route table (0xf means no route) with bit 63 set for entry 0, for the entry equal to the node's own NASID modulo 128 and for any entry whose nibble is not 0xf; the tables written to IILB, PI and MD also carry a second direction in bits 13:8 (bit 13 = 0x20 when the second port has a route), which the header mask does not include. Plain storage for the PROM: it writes every entry and reads one back only when the record is flagged for read-and-compare (not the lone-node path). Entry contents for NASID 0 alone are unknown (they come from the PROM route calculation, which is not traced).
 */
/* md_local_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_LOCAL_TABLE                          0x150024000 /* established */
#define SHUB_MD_LOCAL_TABLE_COUNT                    128
#define SHUB_MD_LOCAL_TABLE_STRIDE                   8

/*
 * Global routing table of the memory and directory unit: 16 doublewords, same entry layout as md_local_table, indexed by the high NASID bits (the PROM loops 0 to 15). Written with the same rule as the local table. Plain storage for the PROM.
 */
/* md_global_table: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_GLOBAL_TABLE                         0x150024400 /* established */
#define SHUB_MD_GLOBAL_TABLE_COUNT                   16
#define SHUB_MD_GLOBAL_TABLE_STRIDE                  8

/*
 * Route override entry of the memory and directory unit; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header INIT is 0x8000000000000000 (enabled). The PROM writes 0 to disable it, once per walk after the tables. Plain storage.
 */
/* md_over_ride_table: rw64, reset 0x8000000000000000; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_OVER_RIDE_TABLE                      0x150024480 /* established */

/*
 * NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*; the PROM addresses it as base + port * 0x200). Virtual-channel switch control of the crossbar-to-NI path: bit 0 NI_VCFIFO_DATELINE_SWITCH, bit 8 PI_VCFIFO_SWITCH, bit 16 MD_VCFIFO_SWITCH, bit 24 IILB_VCFIFO_SWITCH (each swaps VC0/2 with VC1/3), bits 34:32 sync-bypass and async-fifo controls (header). 0xffa5c900 reads it and writes it back with bit 24 inverted, runs the neighbour loop, and inverts it again (on a lone node the loop does nothing, so the register ends where it began). Slot 59 reads it and ORs 0x100 (0x101 when the port record has flag 0x20 set). A plain read/write register satisfies both.
 */
/* xnni_vcswitch_flow: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI_VCSWITCH_FLOW                      0x1500303a0 /* established */
#define SHUB_XNNI_VCSWITCH_FLOW_COUNT                2
#define SHUB_XNNI_VCSWITCH_FLOW_STRIDE               512

/*
 * NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). FIFO 0/2 flow limits of the crossbar-to-NI path (vc limit, dynamic and captured counters; a zero limit disables the check, header). The PROM reads it and writes it back ANDed with 0xfffffffff0fffff0, which clears the limit fields (and the vc counters shown in the same nibbles). A plain read/write register satisfies it.
 */
/* xnni_fifo02_flow: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI_FIFO02_FLOW                        0x1500303c0 /* established */
#define SHUB_XNNI_FIFO02_FLOW_COUNT                  2
#define SHUB_XNNI_FIFO02_FLOW_STRIDE                 512

/*
 * NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). FIFO 1/3 flow limits of the crossbar-to-NI path (vc limit, dynamic and captured counters; a zero limit disables the check, header). The PROM reads it and writes it back ANDed with 0xfffffffff0fffff0, which clears the limit fields (and the vc counters shown in the same nibbles). A plain read/write register satisfies it.
 */
/* xnni_fifo13_flow: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI_FIFO13_FLOW                        0x1500303d0 /* established */
#define SHUB_XNNI_FIFO13_FLOW_COUNT                  2
#define SHUB_XNNI_FIFO13_FLOW_STRIDE                 512

/*
 * NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). NI flow limits of the crossbar-to-NI path (vc limit, dynamic and captured counters; a zero limit disables the check, header). The PROM reads it and writes it back ANDed with 0xfff0fff0fff0fff0, which clears the limit fields (and the vc counters shown in the same nibbles). A plain read/write register satisfies it. Only touched when the environment variable NoTimeouts is set.
 */
/* xnni_ni_flow: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI_NI_FLOW                            0x1500303e0 /* established */
#define SHUB_XNNI_NI_FLOW_COUNT                      2
#define SHUB_XNNI_NI_FLOW_STRIDE                     512

/*
 * NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). dead-lock flow limits of the crossbar-to-NI path (vc limit, dynamic and captured counters; a zero limit disables the check, header). The PROM reads it and writes it back ANDed with 0xfff0fff0fff0fff0, which clears the limit fields (and the vc counters shown in the same nibbles). A plain read/write register satisfies it.
 */
/* xnni_dead_flow: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI_DEAD_FLOW                          0x1500303f0 /* established */
#define SHUB_XNNI_DEAD_FLOW_COUNT                    2
#define SHUB_XNNI_DEAD_FLOW_STRIDE                   512

/*
 * NI port 0 at this offset, port 1 is 0x200 higher. Age value stamped on outgoing packets: REQUEST_INJECT bits 7:0, REPLY_INJECT bits 15:8 (header). Slot 59 reads it and writes it back with bits 15:8 set to 0xc0 (value AND 0xffffffffffff00ff OR 0xc000), only when the node has no NUMAlink 4 router entry (count 0), which is the case for a lone node. A plain read/write register satisfies it.
 */
/* xnni_inject_age: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XNNI_INJECT_AGE                         0x150030400 /* established */
#define SHUB_XNNI_INJECT_AGE_COUNT                   2
#define SHUB_XNNI_INJECT_AGE_STRIDE                  512

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_lb_cmp_exp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_LB_CMP_EXP_DATA1                0x150031110 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_lb_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_LB_CMP_ENABLE0                  0x150031120 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_lb_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_LB_CMP_ENABLE1                  0x150031130 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ii_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_II_CMP_EXP_DATA0                0x150031140 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ii_cmp_exp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_II_CMP_EXP_DATA1                0x150031150 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ii_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_II_CMP_ENABLE0                  0x150031160 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ii_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_II_CMP_ENABLE1                  0x150031170 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_md_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_MD_CMP_EXP_DATA0                0x150031180 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_md_cmp_exp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_MD_CMP_EXP_DATA1                0x150031190 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_md_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_MD_CMP_ENABLE0                  0x1500311a0 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_md_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_MD_CMP_ENABLE1                  0x1500311b0 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_pi_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_PI_CMP_EXP_DATA0                0x1500311c0 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_pi_cmp_exp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_PI_CMP_EXP_DATA1                0x1500311d0 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_pi_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_PI_CMP_ENABLE0                  0x1500311e0 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_pi_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_PI_CMP_ENABLE1                  0x1500311f0 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ni0_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_NI0_CMP_EXP_DATA0               0x150031200 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ni0_cmp_exp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_NI0_CMP_EXP_DATA1               0x150031210 /* established */

/*
 * A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ni0_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_NI0_CMP_ENABLE0                 0x150031220 /* established */

/*
 * A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ni0_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_NI0_CMP_ENABLE1                 0x150031230 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ni1_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_NI1_CMP_EXP_DATA0               0x150031240 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ni1_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_NI1_CMP_ENABLE0                 0x150031260 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it twice per node (first and last of the five lists), as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_iilb_ni1_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_IILB_NI1_CMP_ENABLE1                 0x150031270 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_iilb_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_IILB_CMP_EXP_DATA0                0x150031300 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_iilb_cmp_exp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_IILB_CMP_EXP_DATA1                0x150031310 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_iilb_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_IILB_CMP_ENABLE0                  0x150031320 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_iilb_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_IILB_CMP_ENABLE1                  0x150031330 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_ni0_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_NI0_CMP_EXP_DATA0                 0x150031340 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 as a test-and-set flag word (bits 0x20, 0x40, 0x80, 0x100, 0x400), 1360 as a write-if-zero word and 1370 as an OR-accumulating word. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_ni0_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_NI0_CMP_ENABLE0                   0x150031360 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 as a test-and-set flag word (bits 0x20, 0x40, 0x80, 0x100, 0x400), 1360 as a write-if-zero word and 1370 as an OR-accumulating word. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_ni0_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_NI0_CMP_ENABLE1                   0x150031370 /* established */

/*
 * A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_sic_cmp_exp_hdr0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_SIC_CMP_EXP_HDR0                  0x1500313c0 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM zeroes once per node; no reader was found. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_sic_cmp_exp_hdr1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_SIC_CMP_EXP_HDR1                  0x1500313d0 /* established */

/*
 * A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_sic_cmp_hdr_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_SIC_CMP_HDR_ENABLE0               0x1500313e0 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM zeroes once per node; no reader was found. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_pi_sic_cmp_hdr_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_PI_SIC_CMP_HDR_ENABLE1               0x1500313f0 /* established */

/*
 * Progress history of processor slice n (n = cr.lid bits 26:23, 0 to 3), 16 bytes apart; the name is ours. Every progress code is written as: read the word, shift it left 8, put the code in the low byte, write it back. The code is never read for a decision; any reset value is tolerated and the register must return what was last written. SAL_A also reads slice 1 and slice 3 words (0x150031510, 0x150031530) and copies them, ORed with 0x60, to LED registers. The block is the network interface's by address; the PROM uses it as plain storage (inferred). The SGI 2.4 SN2 header names this offset SH_XN_MD_IILB_CMP_EXP_DATA0 at 0x1_5003_1500, SH_XN_MD_IILB_CMP_EXP_DATA1 at 1510, SH_XN_MD_IILB_CMP_ENABLE0 at 1520 and SH_XN_MD_IILB_CMP_ENABLE1 at 1530: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.
 */
/* cpu_hist: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e5c6 and 0xffc4e5e0 (progress write), 0xffa0ddb0; no Linux v5.3 name; SGI 2.4 SN2 header (linux-mips linux-2.4 8ef7d46c94d5) names the offset */
#define SHUB_CPU_HIST                                0x150031500 /* established */
#define SHUB_CPU_HIST_COUNT                          4
#define SHUB_CPU_HIST_STRIDE                         16

/*
 * Firmware flag word; the name is ours. SAL_A's election winner writes 0 to it, and a later routine writes 0 to it on another node through the node-object write (site 0xffa5d48c). No read exists on the direct-call reset path. The method tables reached through the chip object hold methods that treat it as a set of flags indexed by a bit number: claim bit n (wait until it reads clear, set it, with an optional deadline in microseconds; returns -1 on timeout), test bit n, and clear bit n, each as a read-modify-write under the lock pair lb_lock2 and lb_lock2_status, on this node (site 0xffa0efd0, 0xffa0f580) or through the global window of another (site 0xffa0f1a0, 0xffa0f3a0, 0xffa0f430, 0xffa0f650). That the flags are claims is inferred from the sequence; which bit numbers callers use was not traced, and whether any of these methods runs before the console start is unknown. The word must read back what was written. The SGI 2.4 SN2 header names this offset SH_XN_MD_NI0_CMP_EXP_DATA0: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.
 */
/* fw_word_1540: rw64, reset unknown; SAL 5.04 PROM site 0xffc4ea06 (zeroed by the election winner), 0xffa0efd0 to 0xffa0f640 (bit methods), 0xffa5d48c (zeroed on another node); no Linux v5.3 name; SGI 2.4 SN2 header (linux-mips linux-2.4 8ef7d46c94d5) names the offset */
#define SHUB_FW_WORD_1540                            0x150031540 /* inferred */

/*
 * Firmware per-processor state word; the name is ours. The winner of the SAL_A election zeroes it. Bits the PROM uses: 21 + slice (tested in 0xffa1d430, set in the SAL_B reset entry), 26 + slice (set by the local-master arbitration, polled until the other present processors have set theirs), 30 + slice and bit 34 (a second barrier), 35 + slice (set in the SAL_B reset entry), and a 3-bit count at bit 47 (even slice) or bit 50 (odd slice) that each present slice publishes from a PAL call and the master waits for as that many ready bits among 29:26 (inferred). Bits are set and cleared by read-modify-write under the lock pair lb_lock and lb_lock_status. The SAL_A error path clears bits 29:26. The meanings are inferred from use; the word must read back what was written. The SGI 2.4 SN2 header names this offset SH_XN_MD_NI0_CMP_EXP_DATA1: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.
 */
/* cpu_bits: rw64, reset unknown; SAL 5.04 PROM site 0xffc4ea00 (zeroed), 0xffa0e730 (set and clear a bit under the lock), 0xffa1d430 (test), 0xffa99cf0 and 0xffa9a130 (arbitration); no Linux v5.3 name; SGI 2.4 SN2 header (linux-mips linux-2.4 8ef7d46c94d5) names the offset */
#define SHUB_CPU_BITS                                0x150031550 /* established */

/*
 * Firmware debug-switch word; the name is ours. SAL_A's election winner zeroes it; the PROM later stores the L1's reply to request 0x0001 and tests bits of it (bit 11 selects the single-node route, bit 14 skips I/O initialisation). A field setter (site 0xffa974d0, call sites 0xffa1a51c and 0xffa1a58c, both with a width of 16) replaces a bit field of it with a 16-bit value under the lb_lock and lb_lock_status lock: take the lock, read the word, clear the field, OR in the value, write, release. Plain storage. The SGI 2.4 SN2 header names this offset SH_XN_MD_NI0_CMP_ENABLE0: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.
 */
/* fw_debug_word: rw64, reset unknown; SAL 5.04 PROM site 0xffc4ea10 (zeroed in SAL_A), 0xffa19e50 (loaded from the L1 reply in phase 0xe), 0xffa975e0 (bit test), 0xffa974d0 (field setter) */
#define SHUB_FW_DEBUG_WORD                           0x150031560 /* inferred */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM loads, stores and zeroes; the values it keeps are not decoded. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_ni0_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_NI0_CMP_ENABLE1                   0x150031570 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM uses as a counter, loading it and storing the value plus one. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_ni1_cmp_exp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_NI1_CMP_EXP_DATA0                 0x150031580 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM sets to 0xff00000000 and reads back per slice. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_ni1_cmp_exp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_NI1_CMP_EXP_DATA1                 0x150031590 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 as a test-and-set flag word (bits 0x20, 0x40, 0x80, 0x100, 0x400), 1360 as a write-if-zero word and 1370 as an OR-accumulating word. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_ni1_cmp_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_NI1_CMP_ENABLE0                   0x1500315a0 /* established */

/*
 * A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_ni1_cmp_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_NI1_CMP_ENABLE1                   0x1500315b0 /* established */

/*
 * A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_exp_hdr0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_EXP_HDR0                  0x1500315c0 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM sets to 0xff00000000 and reads back per slice. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_hdr_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_HDR_ENABLE0               0x1500315e0 /* established */

/*
 * A debug-compare word of the node crossbar that the PROM uses as plain storage: a word the PROM only reads, through the global window of a NASID it is given; the value is not decoded. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA0                     0x150031600 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA1                     0x150031610 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data2: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA2                     0x150031620 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data3: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA3                     0x150031630 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data_enable0: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA_ENABLE0              0x150031640 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data_enable1: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA_ENABLE1              0x150031650 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data_enable2: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA_ENABLE2              0x150031660 /* established */

/*
 * A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.
 */
/* xn_md_sic_cmp_data_enable3: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_XN_MD_SIC_CMP_DATA_ENABLE3              0x150031670 /* established */

/*
 * Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.
 */
/* junk_bus_led: w16, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_JUNK_BUS_LED                            0x7fed00000 /* established */
#define SHUB_JUNK_BUS_LED_COUNT                      4
#define SHUB_JUNK_BUS_LED_STRIDE                     65536

#define SHUB_IPI_BASE_VALUE                          0xfeeu /* established */
#define SHUB_PIO_WRITE_STATUS_ALIAS_CLEAR            0x7u /* established */
#define SHUB_PIO_WRITE_STATUS_IDLE                   0x3f00000000000000ull /* established */
#define SHUB_PI_CAM_WAR_VALUE                        0x8000000000000010ull /* established */
#define SHUB_RTC_CONFIG_MASK                         0xff3ffffffefffffull /* established */
#define SHUB_RTC_ENABLE_MASK                         0x1u /* established */
#define SHUB_RTC_MASK                                0x7fffffffffffffull /* established */
#define SHUB_SHUB_1_1_MAX_REVISION                   0x2u /* established */

#endif /* SHUB_GEN_H */
