# Census tools

Static register-access census from MIPS binaries. One config per chip in `configs/`, marked `mode`
spec-backed or no-spec.

The tools below are in the retools submodule, under `retools/tools/chips/`; run them from the repository
root (`retools/tools/chips/scan.py tools/configs/bridge.json ...`). The configs stay here in `configs/`.

| Stage | Tool | Output (work/) |
|---|---|---|
| 1 disassemble (container) | `disasm.sh CONFIG` | `dis/*.s`, `.nm`, literal pools; PROM containers unpacked by `promgen64.py` |
| 2 scan | `scan.py CONFIG --base . --out work/CHIP` | `sites.tsv`, `unresolved.tsv`, `suspects.tsv`, `scope.tsv`, `accessor-calls.tsv`, `scan-stats.json` |
| 3 reference | `ref.py` | `ref.json` (datasheet, specification, model entries), spec-backed only |
| 4 join | `join.py` | `CHIP-census.tsv`, `-census-sites.tsv`, `-census-windows.tsv` |
| 4b fields | `fields.py` | `CHIP-fields.tsv`, `CHIP-context.tsv` |
| 5 report | `report.py` | `chips/*/census/CHIP/census.md` |

`run.sh CONFIG DATASHEET_REPO MODEL_CHECKOUT [REF]` runs all of it (the comparison needs the emulator's
datasheets and model source; without them run stages 1, 2 and 4b by hand). `setup-clone.sh` prepares a clone and `re-run` runs a command in the toolchain container
(see the README).

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
Drivers that keep the window pointer in a per-device record (`configs/ioc3.json`, `configs/ioc4.json`): seed the record
as a base at an offset above every register, add a `field_rules` entry for each pointer field the attach routine stores,
and set `record_skip_above` to that offset so the record's own fields are not reported as registers. A `seeds.returns`
entry may carry `arg` (a register number) and `equals`, so a mapping call returns a window pointer only for one space
selector (configuration space and a base-address window share one callee).

A chip with no memory window (the network router, reached by vector packets) has no sites for the scan to follow.
`callargs.py CONFIG --base . --out DIR` reads the constants a driver passes to the chip's accessor routines instead (the
config's `call_census` section: callee, argument register, direction, optional names and hand-read rows) and writes the
same `census.tsv` and `census-sites.tsv` shape as the scan, plus `call-sites.tsv`, `values.tsv`, `census-symbolic.tsv` and
`unresolved.tsv`. `configs/router.json`, `configs/l1-commands.json` and `configs/l1-tasks.json` use it. A config key
`or_is_add` (scan.py) makes an `ori` on a window pointer add the constant; it is for a register block reached as a window
constant plus an or-ed offset (`configs/l1.json`) and is off by default.

`retools/tools/mips_shim.py` is a unicorn harness for running a shipped routine over chosen inputs (see
`retools/tools/test_mips_shim.py` for the pattern).
