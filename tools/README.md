# Census tools

Static register-access census from MIPS binaries. One config per chip in `configs/`, marked `mode`
spec-backed or no-spec.

| Stage | Tool | Output (work/) |
|---|---|---|
| 1 disassemble (container) | `disasm.sh CONFIG` | `dis/*.s`, `.nm`, literal pools; PROM containers unpacked by `promgen64.py` |
| 2 scan | `scan.py CONFIG --base . --out work/CHIP` | `sites.tsv`, `unresolved.tsv`, `suspects.tsv`, `scope.tsv`, `accessor-calls.tsv`, `scan-stats.json` |
| 3 reference | `ref.py` | `ref.json` (datasheet, specification, model entries), spec-backed only |
| 4 join | `join.py` | `CHIP-census.tsv`, `-census-sites.tsv`, `-census-windows.tsv` |
| 4b fields | `fields.py` | `CHIP-fields.tsv`, `CHIP-context.tsv` |
| 5 report | `report.py` | `docs/census/CHIP/census.md` |

`run.sh CONFIG DATASHEET_REPO MODEL_CHECKOUT [REF]` runs all of it (the comparison needs the emulator's
datasheets and model source; without them run stages 1, 2 and 4b by hand). `setup-clone.sh` makes a clone with a
container wrapper.

How the scan works: a forward data-flow over each function's basic blocks, keeping the distinct states that
reach a block (path-sensitive, capped), tracking constants, window pointers (plus an index flag), the chip-type
discriminator and the identification-word part number. A compare of either against a constant names the chip
for the path. A load or store through a window pointer is one site. Window pointers handed to a callee that is
not seeded, loads and stores through an unresolved base with a register-like displacement, and basic blocks
the flow never reached are all reported, never guessed.

Known limits: index registers are not followed (families are recorded at their base); jump tables are not
followed; PROM images have no symbols and are split into pseudo-functions after each `jr $31`; a PROM's window base
built at run time is found only through an identification-register probe.
Seeds, field-rule and variant syntax: see `configs/bridge.json` (worked example) and `configs/bedrock.json`
(literal-pool windows).

`scripts/mips_shim.py` is a unicorn harness for running a shipped routine over chosen inputs (see
`scripts/test_mips_shim.py` for the pattern); `scripts/check-leaks.sh` is the pre-push check.
