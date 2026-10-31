# Brief for a census worker

You produce register-access evidence for one chip from the shipped IRIX binaries, then write entries from it.
Read AGENTS.md first: the labels and the reading rules there are the contract. Run commands from the
repository root, inside the container wrapper (`rr.sh`, or `RR=...` for `tools/disasm.sh`). Do not read any
IRIX source tree and do not open any document store other than this repository and the paths named here.

## Two modes

**Spec-backed** (Bridge, XBridge, Xbow, CRIME, MACE, GBE, VICE). The chip has a published specification
(docs/specs.md). The census lists every offset the code touches, then compares it with the specification's
register map, with the emulator's datasheet if you were given one, and with the emulator's model if you were
given one. Output classes per register: in the spec / absent from it / the spec contradicts the datasheet;
modelled and specified / modelled but guessed or deferred / unmodelled. Your job is the task list: registers
touched but missing from the datasheet or the model, and datasheet entries the spec contradicts.

**No-spec** (Hub PI/MD/IO/NI, Bedrock blocks, HEART, PIC, TIOCP, IOC3, IOC4). There is no specification, so
the binaries are the evidence. The census gives the register inventory (`census.tsv`), per-register bit-field
evidence (`fields.tsv`: the masks and shifts the code applies after a read, the constants it stores or
passes) and the instructions around each access (`context.tsv`). Your job is to turn that into entries:
register, width, access sequence (init, error, interrupt), what each field is used for, what the code expects
after reset, each labelled. Naming a field from a function's name is "inferred". A related chip's layout is
a hypothesis, stated as such, never evidence.

## Steps

1. `tools/disasm.sh tools/configs/<chip>.json` (writes `work/dis/`; unpacks PROM containers).
2. Edit the config if the seeds are empty (stub configs): find the accessor functions by name in
   `work/dis/<image>.nm` (symbols such as the chip's name, `_get`/`_set` suffixes), list them in
   `seeds.args` with the register that holds the window pointer on entry (`$4` = 4), and read two accessors
   by hand to confirm the offsets before trusting the scan. Where a function receives the pointer from a
   caller, add the caller's call to `seeds.calls` or let `probe` find it (an identification-register probe).
3. `python3 tools/scan.py tools/configs/<chip>.json --base "$PWD" --out work/<chip>`; read `scan-stats.json`,
   `unresolved.tsv` (window pointers passed to unseeded callees) and `suspects.tsv` (memory accesses with a
   register-like displacement through an unresolved base). Each is a to-do, not an error.
4. Spec-backed only: `tools/ref.py` and `tools/join.py` (or `tools/run.sh`) for the comparison.
5. `python3 tools/fields.py ...` for field evidence. Then write entries (AGENTS.md labels) in
   `chips/<chip>/README.md`, one heading per register with the offset in backticks, and regenerate the
   inventory.

## Good fits for a cheap worker

- Running the pipeline, reading `census.md`, listing gaps and writing the task list (spec-backed mode).
- Reading one accessor function in full and recording its offsets, widths and chip branches.
- Copying register maps from a specification page into a table with page numbers (read digits from the page
  image; the text extraction of a scan is unreliable).
- Counting call sites per register and listing the callers of an accessor with the constants they pass.

## Poor fits (escalate)

- Deciding what a bit means from call-site context alone. Take the evidence, label inferred, and mark the
  question open.
- Anything that needs a branch through a jump table, an indirect call whose target is not in a symbol table,
  or code a PROM copies to RAM before running. List the site as unresolved.
- Reset values nothing reads, ordering requirements between chips, anything where the specification and the
  binary disagree. Record both and stop.
- Writing a chip's layout by analogy with another chip.

## Audit procedure

An auditor who did not write the entries draws a random sample of rows graded `understood` (at least 12 per
table with that many) and, for each, re-derives the claim from the binary or the cited page without reading
the entry's derivation first. Verdict per row: `real` (holds up), `shallow` (true but taken from a name or
credited without behaviour), `wrong` (contradicted). Append one row per table to `docs/inventory/audits.tsv`
(columns as in that file's header) and say in the commit which rows were wrong and what was fixed. Entries
found wrong are corrected before any new work in that area.
