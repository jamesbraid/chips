# SGI system ASICs: register-level reverse engineering

What each system ASIC of the SGI Origin, Onyx, Octane, Fuel, Tezro and O2 machines does, read from the shipped IRIX 6.5.30
kernels, drivers, diagnostics and PROM images, checked against the published specifications and the public
Linux and OpenBSD drivers. Software only: no hardware is needed or assumed.

Chips covered (one page each in [chips/](chips/)): Hub (PI, MD, IO, NI), Bedrock, HEART, Xbow,
Bridge and XBridge, PIC, TIOCP (only if a product carries it), IOC3, IOC4, CRIME, MACE, GBE, VICE (presence).
Builds are named by board, never by product: IP27, IP30, IP32, IP35.

The layout and working style follow Dominik Behr's
[gr2](https://github.com/techomancer/gr2) and
[gr4](https://github.com/techomancer/gr4), as do the sibling graphics workspaces.
Proprietary IRIX binaries are not tracked; copy them from your own IRIX install into the
ignored `root/` directory as [IRIX_FILES.md](IRIX_FILES.md) describes.

- [AGENTS.md](AGENTS.md): the rules, the labels, the working procedure and the rules for reading MIPS code.
- [HAIKU-BRIEF.md](HAIKU-BRIEF.md): how to run a census and write entries, for a cheap worker.
- [IRIX_FILES.md](IRIX_FILES.md): the shipped files the repository reads (not committed).
- [docs/specs.md](docs/specs.md): the published specifications held here, with coverage.
- [docs/published-sources.md](docs/published-sources.md): public drivers and other sources.
- [docs/coverage.md](docs/coverage.md) and [docs/inventory/](docs/inventory/): measured coverage.
- [docs/open-questions.md](docs/open-questions.md): what is not settled and the next route.
- [chips/*/census/](chips/*/census/): register-access censuses per chip, produced by [tools/](tools/).

## Layout

    AGENTS.md  HAIKU-BRIEF.md  IRIX_FILES.md  LICENSE  README.md
    chips/<chip>/      one directory per chip: README.md (the page), census/ (machine-made tables),
                       notes/ (working notes). Chips: hub bedrock heart xbow bridge pic tiocp ioc3 ioc4
                       crime mace gbe vice. bridge/ also holds the XBridge census.
    include/<chip>.h   generated register headers (tools/gen_headers.py); chips_check.c compiles them together
    ip27/ ip30/ ip32/ ip35/   per board: relative symlinks into root/ (boot objects, members, kernel,
                       PROM, ide, symmon, sash)
    docs/              specs.md, published-sources.md, open-questions.md, coverage.md, inventory/ (tables),
                       sources/specs/ (committed spec PDFs)
    scripts/           inventory.py (shared with the graphics workspaces, byte for byte), populate-root,
                       map_binaries.py, disasm_kernel.py, resolve_got.py, clean_asm.py, mips_shim.py,
                       run_routine.py, check-leaks.sh, inventory-config.json
    tools/             the census scanner (scan, ref, join, fields, entries, gen_headers) and configs/
    ghidra/            headless scripts for IRIX code (shared with the graphics workspaces)
    m2c spimdisasm linux netbsd openbsd   public submodules (pinned; init only what you need)
    root/              the filled IRIX tree and spec text; ignored, never committed

Graphics inputs (libGLcore, X modules, OpenGL sources) and graphics-only tables are not part of this
repository; the graphics workspaces own them.

## Clone and query

    git clone <forge-url>/chips.git
    ln -s /path/to/filled/root chips/root          # see IRIX_FILES.md; root/ is never committed
    cd chips && scripts/populate-root --check
    # tools run in a container that has MIPS binutils, pyelftools and unicorn:
    RR=/path/to/rr-chips.sh tools/disasm.sh tools/configs/pic.json
    python3 tools/scan.py tools/configs/bridge.json --base "$PWD" --out work/bridge

Questions are answered from `chips/<chip>/census/` (the TSV tables), `chips/<chip>/README.md` (entries with
labels) and `grep -r` over `root/spec/*.txt` (text of the specifications, not committed).

Licence: BSD-3-Clause, see [LICENSE](LICENSE). The scripts descend from gr4's
and keep its notice in [scripts/LICENSE-gr4](scripts/LICENSE-gr4).
