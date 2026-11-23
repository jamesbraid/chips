<!-- generated from devices/r10000_cp0/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 ac3e03c75ed94daca87b077b35f60770d6347248765e51833d4b0943ef3eb864 -->

# R10000 CP0 Count and Compare timer interrupt and TLB geometry

Coprocessor 0 register numbers of the Count and Compare timer, the Cause bit that carries its interrupt, and the TLB geometry the shipped IRIX kernel assumes.

Unit `r10000_cp0`, macro prefix `R10KCP0`.
Default source: published R10000 user's manual (the source reading gives no document number).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `CAUSE_TIMER` | 32 | established | published R10000 user's manual (the source reading gives no document number) |

### Word `CAUSE_TIMER`

The Cause register bit that carries the Count and Compare timer interrupt.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `ip7` | established |  | published R10000 user's manual (the source reading gives no document number) |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R10K_CP0_COMPARE` | 0xb | established | published R10000 user's manual (the source reading gives no document number) | Compare register number in coprocessor 0 |
| `R10K_CP0_COUNT` | 0x9 | established | published R10000 user's manual (the source reading gives no document number) | Count register number in coprocessor 0 |
| `R10K_TLB_ASID_BITS` | 0x8 | inferred | IRIX kernel translation-handling reading, one release outside the shipped-binary inventory; the R10000 geometry was not checked against the published manual | Width of the ASID field in the TLB entry high word |
| `R10K_TLB_ENTRIES` | 0x40 | inferred | IRIX kernel translation-handling reading, one release outside the shipped-binary inventory; the R10000 geometry was not checked against the published manual | Dual TLB entries, each holding two pages |
