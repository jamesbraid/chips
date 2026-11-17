# Rules for working on this repository

The goal is a register-level account of each SGI system ASIC: every register offset software touches, its fields, reset
expectations and access sequences, each fact labelled. An emulator or FPGA author should not need the binaries.

## Labels

- **established**: read in full from a shipped binary (the whole function, table or code path), a published
  specification page, a public driver file or the public IRIX source tree. Cite the build, function and address, the
  document, revision and page, or the file and version.
- **inferred**: a reasoned reading. A reading built from call lists, store summaries, a name, a sibling chip or a
  sibling build is inferred. Give the reasoning.
- **unknown**: not settled. Say what route would settle it and list it in questions/README.md. Anything unlabelled is
  unknown. "No shipped software or published source depends on it" is a valid end state; list the routes tried.

Never reword an entry to change its label. A sibling chip is a neighbouring row, not evidence: a hypothesis from a
related chip (PIC from Bridge and XBridge) is stated as a hypothesis, inferred at best, and never fills a field.

## Sources

Allowed: shipped IRIX binaries and PROM images; the public IRIX source tree (by path); published specifications (title,
number, revision); public Linux, OpenBSD and NetBSD drivers (file and version); published patents; published `hinv` and
PROM-console captures, described generically; Usenet posts by message-id.

Not allowed in any file, commit message or entry: vendor source text or internal identifiers beyond the function,
symbol and string names the shipped binaries carry; paths into any private store or document library; names of the
emulator projects or people who work with this repository; machine nicknames from private archives. Write findings in
your own words. Proprietary binaries live in `root/` (ignored) and are never committed.

## Evidence order

For a register or behaviour fact, take it from the highest source that states it and grade it by that source:

1. IRIX source (public `irix-657m-src` tree): read it, write the fact in your own words, never copy source text, cite the path in the tree. A fact it defines is `established`.
2. Shipped binaries (PROMs, kernels, libraries): confirm the source matches what shipped, and the release differences (6.5.7 source, 6.5.22 and 6.5.30 binaries).
3. Public Linux, OpenBSD and NetBSD headers and drivers: `established` once the IRIX source confirms them.
4. Published SGI and vendor manuals.
5. Notes from other projects (other projects' datasheets, manual pages and emulator code): may confirm or contradict, never supply a fact. A fact resting only on one stays `unknown`, with the note named.

Reset values: `established` when the source states a power-on default or PROM code relies on a reset state; `inferred` when the PROM depends on a value before its first write (cite the PROM address); a read after firmware initialisation is not a reset value and can only rule values out; otherwise `unknown`. A physical hardware read is a last resort, needs the repository owner's approval, and counts as a reset value only for a register firmware provably never writes. Emulator runs are model behaviour, never hardware evidence.

Full text and the checks that enforce it: `retools/tools/README-analysis.md#evidence-order`.

## Where things go

- `devices/<chip>/README.md`: one page per chip, register entries with labels. `devices/<chip>/census/`: machine-made
  census tables; never edit by hand, fix the tool or config and rerun.
- `devices/<unit>/registers.toml` and `formats/<name>/format.toml`: the source of hardware facts (format and tools:
  `retools/tools/defs/README.md`). Census units are written by `retools/tools/chips/gen_headers.py`: never edit them.
  Hand-written units (`registers-extra.toml`, `l1_requests`, `xio_fc`, `ice1724`) name their source in `from`. Give every
  item a grade. `tools/config/defs-check.toml` holds the check settings.
- `generated/` and `devices/<unit>/registers.md`: written by `retools/tools/defs/defs-gen`, never edited (CI fails on a
  stale tree). `registers.md` is the published reference page for each unit; consumers include `generated/c/<unit>.h`. After any register map change run `defs-gen`, then `defs-check --build`.
- `platforms/<board>/`: topology, address map, boot and PROM of one machine; bricks in `platforms/bricks/`.
  `software/kernel/`: how IRIX drives a part. `questions/`: one page per open question. `references/`: the lists of what we hold, the
  specification index (`documents/`) and the public source trees (`code/`, submodules).
- `generated/inventory/`, `COVERAGE.md`: written by `retools/tools/inventory.py`; never edit by hand.
  `tools/configs/`: one census config per chip, marked spec-backed or no-spec. `tools/config/`: inventory settings,
  pinned manifests and the allow-lists the checks read. `tools/setup-clone.sh` is the bootstrap stub.
- Commit small. Subjects are lowercase, component-prefixed imperatives (`docs: ...`, `tools: ...`); the body says why.
  No trailers of any kind.

## Where new work goes

There is no `evidence/` directory. File each page by what it is about:

- `devices/<chip>/`, `platforms/<board>/`, `formats/<name>/`, `software/<area>/`: a note about one device, platform,
  format or software component.
- `<subject>/readings/<binary>.md`: per-routine readings of one binary, filed under the subject it explains (a driver
  object under its chip, a kernel object under `software/kernel/<platform>/`). `retools/tools/reading_round.py` files
  its entries there; `tools/config/readings-subjects.json` says which subject a binary belongs to.
- `references/`: what we hold and cite: binary, PROM and firmware lists with checksums, scope lists, source lists.
  Code submodules stay under `references/code/`.
- `generated/`: tool output that is regenerated and never hand-edited (`generated/inventory/`, diff tables, symbol
  tables, register output). Hand-kept audit tables sit in `generated/inventory/audits.tsv` by exception.
- `COVERAGE.md` at the root: progress tallies. The inventory block in it is rewritten by `retools/tools/inventory.py`.
- `questions/`: open questions.

`retools/tools/defs/ci-check` fails when an `evidence/` directory comes back.

## Done

A chip row is done when every inventory row in its area is `understood` (label, role and hardware effect, a derivation
specific to the item) or `no-software-dependency`. `generated/inventory/README.md` has the grading rules. An independent
audit re-derives a sample of `understood` rows from the binaries and records the result in `generated/inventory/audits.tsv`
(procedure: tools/reading-brief.md).

## Reading MIPS code from the shipped binaries

- A branch's delay slot runs before the transfer; read it with the branch. On a branch-likely (`beql`, `bnel`) it runs
  only when the branch is taken. A load in a delay slot is a call argument.
- o32 passes four arguments in `$4` to `$7`; n32 and 64-bit objects pass eight, `$4` to `$11`, so a callee that uses
  `$8` to `$11` is not o32. Results are in `$2`, `$3`.
  Record a negative constant stored to `$2` as the number, not a guessed name.
- `ld $reg,-N($28)` reads a GOT slot (`retools/tools/resolve_got.py`), or a literal pool entry in a relocatable kernel
  object (`retools/tools/chips/scan.py` reads those literals; `literals` and `gp` in an image's config entry). Disassemble
  with relocations (`objdump -r`) and name a call from its relocation: an unrelocated `jal` shows a zero target, and in a
  linked image the listing label can be a neighbouring function if the callee has no symbol.
- Dump the table behind a `jr` through a `.rodata` register (entries are code addresses or offsets from the table base)
  before claiming what a function does; otherwise inferred.
- Store order is part of the hardware contract: record sequences as the code issues them, with the width of each access
  (`lb/sb` 1, `lh/sh` 2, `lw/sw` 4, `ld/sd` 8; `lwl/lwr/swl/swr` are partial words).
- `lui` plus `ori`/`addiu`, or `dli`, builds a constant; resolve a 64-bit window address before naming a register. An
  indexed family is recorded at its base with an index flag, its extent from a bound in the code or the specification.
- Shared accessors branch on a type field or part number: record each branch's offsets under its own chip. A site whose
  path names no chip, or whose offset cannot be derived, is listed as unresolved. Unresolved is a result. Never guess an offset.

## Procedure for a chip

1. Fill `root/` (references/irix-files.md) and run `retools/tools/inventory.py` to see the rows.
2. Write `tools/configs/<chip>.json`: the images, the seeds, the chip-type compares and the literal-pool settings.
3. Run `retools/tools/chips/run.sh tools/configs/<chip>.json` (tools/README.md); read `devices/<chip>/census/census.md`.
4. Turn each register into an entry in `devices/<chip>/README.md`; read the function in full before labelling it established.
5. Regenerate the inventory in the same commit as the finding.
