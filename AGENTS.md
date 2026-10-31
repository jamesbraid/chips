# Rules for working on this repository

The goal is a register-level account of each SGI system ASIC: every register offset software touches, its fields,
reset expectations and access sequences, each fact labelled by how well it is known. Written so an emulator
author or FPGA builder never needs to read the binaries.

## Labels

- **established**: read in full from the shipped binary (the whole function, table or code path), or from a
  published specification page, or from a public driver file. Cite the build, function and address, or the
  document, revision and page, or the file and version.
- **inferred**: a reasoned reading. A reading built from call lists, store summaries, a name, a sibling chip or
  a sibling build is inferred. Give the reasoning.
- **unknown**: not settled. Say what route would settle it and put it in docs/open-questions.md. Anything
  unlabelled is unknown. "Unknown: no shipped software or published source depends on it" is a valid end state
  for a fact (such as the reset value of a register no code reads); list the routes tried.

Never reword an entry to change its label. A sibling chip is a neighbouring row, not evidence: a hypothesis
from a related chip (for example PIC from Bridge and XBridge) is stated as a hypothesis, labelled inferred at
best, and never fills a field.

## Sources

Allowed: shipped IRIX binaries and PROM images; published specifications (cited by title, document number and
revision); public Linux, OpenBSD and NetBSD drivers (by file and version); published patents; published `hinv`
and PROM-console captures, described generically with counts; Usenet posts by message-id.

Not allowed in this repository, in any file, commit message or entry: vendor source text or internal
identifiers beyond the function, symbol and string names the shipped binaries themselves carry; paths into
any private store or document library; names of the emulator projects or people who work with this
repository; machine nicknames from private archives. Findings are written in your own words. Proprietary
binaries live in `root/` (ignored) and are never committed.

Facts come from reading the binaries. A datasheet or note from another project may be used afterwards, to
report agreement or disagreement, never to supply a fact.

## Where things go

- `chips/<chip>/README.md`: one page per chip. Register entries with labels. Chips with no entry yet say so.
- `chips/<chip>/census/`: machine-made census tables (`census.tsv`, `fields.tsv`, `context.tsv`, `census-sites.tsv`).
  Never edit by hand; fix the tool or the config and rerun.
- `docs/inventory/` and `docs/coverage.md`: written by `scripts/inventory.py`. Never edit by hand.
- `tools/`: the census scanner and its configs (one per chip, marked spec-backed or no-spec); `scripts/`: the
  inventory, disassembly helpers and the unicorn run harness (`mips_shim.py`).
- Commit small. Subjects are lowercase, component-prefixed imperatives (`docs: ...`, `scripts: ...`,
  `tools: ...`); the body says why. No trailers of any kind.

## Done

A chip row is done when every inventory row in its area is `understood` (label, role and hardware effect,
a derivation specific to the item) or `no-software-dependency`. `docs/inventory/README.md` has the exact
grading rules, including the template cap, the scope filter and the unverified label. An independent audit
samples `understood` rows and re-derives them from the binaries; the result goes in
`docs/inventory/audits.tsv` (written by hand; the audit procedure is in HAIKU-BRIEF.md).

## Reading MIPS code from the shipped binaries

- **Delay slots.** The instruction after a branch or jump runs before the transfer. Read it as part of the
  branch. A load in a delay slot is the argument of a call.
- **Branch-likely** (`beql`, `bnel`, `bgezl`, ...): the delay slot runs only when the branch is taken. On the
  fall-through path it is annulled.
- **Argument registers.** o32 passes the first four arguments in `$4` to `$7`; n32 and 64-bit objects pass eight,
  `$4` to `$11`. A callee that uses `$8` to `$11` as arguments is not o32.
- **Return values** are in `$2` (and `$3`). A negative constant stored to `$2` before a return is an error code;
  record the number, not a guess at its name.
- **GOT and gp-relative loads.** In position-independent code a load `ld $reg,-N($28)` reads a global-offset
  table slot at `$gp - N`; the slot holds the address of a symbol (resolve it with the relocation or the table
  in the object). `scripts/resolve_got.py` does this for objects with a table. In a relocatable kernel object
  the same load reads a literal pool entry (`.lit8`, `.srdata`) at `gp + offset`; `tools/scan.py` reads those
  literals from the object (`literals` and `gp` in an image's config entry).
- **Call-label hazard.** In a relocatable object an unrelocated `jal` shows a target of zero or the next
  instruction. Disassemble with relocations (`objdump -r`) and name the call from the relocation. In a linked
  image the label in the listing is the symbol at that address, which can be a neighbouring function if the
  callee has no symbol.
- **Jump tables.** A `jr` through a register loaded from a table in `.rodata` is a switch. Dump the table
  (entries are code addresses, or offsets from the table base) before claiming a function's behaviour; a
  function read without its switch arms is "inferred".
- **Store order matters.** For a device the order of stores is part of the hardware contract (write the
  address, then the command). Record sequences in the order the code issues them, not sorted by offset.
- **Widths.** `lb/sb` 1, `lh/sh` 2, `lw/sw` 4, `ld/sd` 8 bytes; `lwl/lwr/swl/swr` are partial words and show a
  misaligned or byte-lane access. Record the width with every access.
- **Constants.** `lui` + `ori`/`addiu`, or `dli`, build a constant. A `lui` of `0x9200`-style upper halves
  followed by shifts builds a 64-bit physical window address; resolve it before naming a register.
- **Indexed families.** A register family reached through an index (`slot*8 + base`) is recorded at its base
  with an index flag; its extent comes from a bound the code checks or from the specification, not from the
  scan.
- **Dispatch on chip type.** Shared accessors compare a type field or the part number of the identification
  word with constants and branch to the offsets of that chip. Record each branch's offsets under that chip.
  A site whose path names no chip is recorded as unresolved, not assigned to one.
- **Unresolved is a result.** An access whose offset cannot be derived statically is listed with its site
  and left unresolved. Never guess an offset.

## Procedure for a chip

1. Fill `root/` (IRIX_FILES.md) and run `scripts/inventory.py` to see the rows.
2. Write the chip's census config (`tools/configs/<chip>.json`): the images, the seeds that tell the scanner
   which functions receive the chip's window pointer, the chip-type compares, and the literal-pool settings.
3. `tools/run.sh tools/configs/<chip>.json` (see tools/README.md) and read `chips/<chip>/census/census.md`.
4. Take each register to an entry in `chips/<chip>/README.md` using `fields.tsv` and `context.tsv` as the
   starting evidence, then read the function in full before labelling anything established.
5. Regenerate the inventory in the same commit as the finding.
