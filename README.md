# SGI system ASICs: register-level reverse engineering

What each system ASIC of the SGI Origin, Onyx, Octane, Fuel, Tezro and O2 machines does, read from the shipped IRIX 6.5.30
kernels, drivers, diagnostics and PROM images, checked against the published specifications and the public
Linux and OpenBSD drivers. Software only: no hardware is needed or assumed.

Chips covered (one page each in [chips/](chips/)): Hub (PI, MD, IO, NI), Bedrock, HEART, Xbow,
Bridge and XBridge, PIC, TIOCP (only if a product carries it), the network router, the router scan-chain tunnel, the L1 and ELSC system
controllers (host-visible side), IOC3, IOC4, CRIME, MACE, GBE, VICE (presence), and the audio parts of the DMediaPro DM8
(ICE1724 and its converters, [docs/audio/dm8.md](docs/audio/dm8.md)), with stubs for the RAD and EMU10K2 audio
controllers and a [survey of the audio options](docs/audio/survey.md) of the Fuel, Tezro and Octane.
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
- [docs/sources/INDEX.md](docs/sources/INDEX.md): every public source with its pin and URL: the Linux, OpenBSD, NetBSD, GXemul and MAME
  submodules, older Linux trees for SN1, SN2 and IP27, the IP30 port and the sources recorded by URL only.
- [docs/coverage.md](docs/coverage.md) and [docs/inventory/](docs/inventory/): measured coverage.
- [docs/open-questions.md](docs/open-questions.md): what is not settled and the next route.
- [docs/xio-fibre-channel.md](docs/xio-fibre-channel.md): the XIO Fibre Channel board (AIC-1160) and its `fcadp` driver contract.
- `chips/<chip>/census/`: register-access censuses per chip, produced by [tools/](tools/).

### Every document under docs/

Generated tables under `docs/inventory/` and the generated block of `docs/coverage.md` are listed above, not here.

Audio:

- [docs/audio/dm8.md](docs/audio/dm8.md): DMediaPro DM8 PCI audio option, not an SGI ASIC board.
- [docs/audio/drivers.md](docs/audio/drivers.md): Audio driver objects and config lines in IRIX 6.5.30 and 6.5.22.
- [docs/audio/survey.md](docs/audio/survey.md): Audio options of the Fuel, Tezro and Octane.

Kernel object scope:

- [docs/binaries-scope-chip-drivers.md](docs/binaries-scope-chip-drivers.md): Chip driver objects in the IP27, IP30, IP32 and IP35 kernel builds.
- [docs/binaries-scope-filesystem.md](docs/binaries-scope-filesystem.md): File-system objects in the kernel builds.
- [docs/binaries-scope-kernel-objects.md](docs/binaries-scope-kernel-objects.md): Excluded kernel objects of the IP27 build.

Crosstalk, XIO and interconnect:

- [docs/bridge-family.md](docs/bridge-family.md): Bridge, Xbridge and PIC as Crosstalk widgets.
- [docs/crosstalk-host-ends.md](docs/crosstalk-host-ends.md): Crosstalk host ends: HEART, Hub and Bedrock.
- [docs/crosstalk-link.md](docs/crosstalk-link.md): Crosstalk (XIO): the link, its widgets and its host ends.
- [docs/crosstalk-packets.md](docs/crosstalk-packets.md): Crosstalk packets and the link under them.
- [docs/crosstown-ktown.md](docs/crosstown-ktown.md): Crosstown, KTOWN, Ktown2 and Xtown2: the XIO-over-cable conversion boards.
- [docs/interconnect-naming.md](docs/interconnect-naming.md): SGI interconnect naming: every name, from the deepest source.
- [docs/xbow-family.md](docs/xbow-family.md): Crossbow (XBOW), XXBOW and PXBOW: the XIO switch family.

Chip coverage pages:

- [docs/coverage-bedrock.md](docs/coverage-bedrock.md): Bedrock coverage: processor-interface error clear semantics.
- [docs/coverage-crime.md](docs/coverage-crime.md): CRIME coverage: two coverage questions graded beyond the chip page.
- [docs/coverage-ioc3.md](docs/coverage-ioc3.md): IOC3 coverage: what the shipped software and public drivers settle.
- [docs/coverage-ioc4.md](docs/coverage-ioc4.md): IOC4 coverage: what shipped software and public drivers settle.
- [docs/coverage-mace.md](docs/coverage-mace.md): MACE coverage: what software, specification and drivers settle.
- [docs/coverage-tiocp.md](docs/coverage-tiocp.md): TIOCP coverage: what the shipped software and drivers settle.
- [docs/coverage-vice.md](docs/coverage-vice.md): VICE coverage: the O2's video imaging and compression engine.

Routine readings from the kernels and PROMs:

- [docs/hw-explanations-chips-w1.md](docs/hw-explanations-chips-w1.md): Hardware-facing routine explanations, CRIME and the IP32 kernel, wave 1.
- [docs/ip27-kernel-bridge-routines.md](docs/ip27-kernel-bridge-routines.md): Routines of the IP27 kernel that serve the Bridge family.
- [docs/ip27-kernel-entropy-readers.md](docs/ip27-kernel-entropy-readers.md): Kernel routines that read the Hub real-time counter for entropy (IP27 build).
- [docs/ip27-xconn.md](docs/ip27-xconn.md): The xconn.o pairing driver of the IP27 build.
- [docs/ip30-kernel-bridge-routines.md](docs/ip30-kernel-bridge-routines.md): Bridge-family accessors and attach routines of the IP30 kernel.
- [docs/ip30-kernel-heart-routines.md](docs/ip30-kernel-heart-routines.md): HEART error, timer and reset routines of the IP30 kernel.
- [docs/ip30-kernel-odyssey-routines.md](docs/ip30-kernel-odyssey-routines.md): Odyssey graphics routines of the IP30 kernel.
- [docs/ip30-kernel-support-routines.md](docs/ip30-kernel-support-routines.md): Machine-independent kernel routines of the IP30 build read for completeness.
- [docs/ip30-kernel-xbow-routines.md](docs/ip30-kernel-xbow-routines.md): Xbow routines of the IP30 kernel.
- [docs/instruction-readings-chips-g1.md](docs/instruction-readings-chips-g1.md), [g2](docs/instruction-readings-chips-g2.md) and [g3](docs/instruction-readings-chips-g3.md): instruction readings from hostfacts, one group, not listed entry by entry.

Open questions, one page each:

- [docs/questions/ip35-board-class-and-flash-record.md](docs/questions/ip35-board-class-and-flash-record.md): IP35 PROM: board class of IP53 and IP59 node boards, flash record.
- [docs/questions/ip35-board-word-and-config-block.md](docs/questions/ip35-board-word-and-config-block.md): IP35 PROM: board-identification word and config block.
- [docs/questions/ip35-io9-pci-wiring.md](docs/questions/ip35-io9-pci-wiring.md): IP35 base I/O board: which PCI devices sit where.
- [docs/questions/ip35-prom-cache-staging.md](docs/questions/ip35-prom-cache-staging.md): IP35 PROM cache staging: do later cached fetches hit staged lines?
- [docs/questions/ip35-prom-cpu-config-table.md](docs/questions/ip35-prom-cpu-config-table.md): IP35 PROM: the processor speed table and what feeds it.
- [docs/questions/ip35-prom-l1-brick-class.md](docs/questions/ip35-prom-l1-brick-class.md): IP35 PROM: use of the brick type and known board names.
- [docs/questions/ip35-prom-memory-bank-config.md](docs/questions/ip35-prom-memory-bank-config.md): IP35 PROM: how the memory bank configuration word is read and sized.
- [docs/questions/ip35-prom-mp-presence-poll.md](docs/questions/ip35-prom-mp-presence-poll.md): IP35 PROM: how processors publish presence and end their waits.
- [docs/questions/ip35-prom-reset-barrier.md](docs/questions/ip35-prom-reset-barrier.md): IP35 PROM: reset barrier, boot-master election and progress registers.
- [docs/questions/ip35-reset-window.md](docs/questions/ip35-reset-window.md): IP35 reset window: how the boot PROM runs at 0x1fc0_0000.
- [docs/questions/tezro-io-topology.md](docs/questions/tezro-io-topology.md): Tezro: widget population, per-head PCI devices and second PROM build.
- [docs/questions/tezro-v12-placement.md](docs/questions/tezro-v12-placement.md): Tezro: where the V12 sits and what differs on one-processor boards.
- [docs/questions/tezro-widget-11.md](docs/questions/tezro-widget-11.md): Tezro: how the PROM discovers the second PIC at widget 0xb.

Published sources and specifications:

- [docs/sources/README.md](docs/sources/README.md): Published sources held in this repository.
- [docs/sources/specs/crime-1.5-specification-rev0.3.registers.md](docs/sources/specs/crime-1.5-specification-rev0.3.registers.md): CRIME 1.5 specification rev 0.3: CPU interface register map.
- [docs/sources/specs/crossbow-asic-specification-rev12.0.registers.md](docs/sources/specs/crossbow-asic-specification-rev12.0.registers.md): Crossbow ASIC Specification, revision 12.0: register map.
- [docs/sources/specs/mace-specification.registers.md](docs/sources/specs/mace-specification.registers.md): MACE I/O ASIC Specification, chip revision 2.0: register map.
- The spec PDFs in `docs/sources/specs/` are listed in [docs/specs.md](docs/specs.md), not here.

## Layout

    AGENTS.md  HAIKU-BRIEF.md  IRIX_FILES.md  LICENSE  README.md
    chips/<chip>/      one directory per chip: README.md (the page), census/ (machine-made tables),
                       notes/ (working notes). Chips: hub bedrock heart xbow bridge pic tiocp router scan l1
                       ioc3 ioc4 crime mace gbe vice. bridge/ also holds the XBridge census; router/ is a
                       call-argument census (retools/tools/chips/callargs.py): the router has no memory window.
    include/<chip>.h   generated register headers (retools/tools/chips/gen_headers.py); chips_check.c compiles them together
    include/*_extra.h, l1_requests.h   hand-written companions for established facts the census cannot reach
                       (PROM stores, specification pages, request codes); gen_headers.py never writes them
    ip27/ ip30/ ip32/ ip35/   per board: relative symlinks into root/ (boot objects, members, kernel,
                       PROM, ide, symmon, sash)
    docs/              specs.md, published-sources.md, open-questions.md, coverage.md, inventory/ (tables),
                       sources/specs/ (committed spec PDFs)
    scripts/           inventory-config.json, inventory-siblings.json, inventory-root.sha256 and the
                       allow-lists the inventory reads; no scripts of its own
    tools/             configs/ (one census config per chip) and setup-clone.sh, the bootstrap stub
    retools/           submodule (sgi-retools): the shared tools in retools/tools/, the census tools in
                       retools/tools/chips/, the Ghidra scripts in retools/ghidra/
    ghidra/            this workspace's Ghidra processors, import and type scripts
    m2c spimdisasm linux linux-ia64 linux-2.5.40 linux-2.4.37 linux-ip30 netbsd openbsd gxemul mame arcboot
                       public submodules, pinned and shallow (init only what you need; docs/sources/INDEX.md)
    root/              the filled IRIX tree and spec text; ignored, never committed

Graphics inputs (libGLcore, X modules, OpenGL sources) and graphics-only tables are not part of this
repository; the graphics workspaces own them.

## Running the tools and reproducing a result

The host needs Podman, git and python3. Everything else runs in a container built from
[retools/tools/Containerfile](retools/tools/Containerfile): MIPS binutils, dwarfdump, pyelftools, capstone, unicorn,
numpy, pycparser and spimdisasm, at pinned versions on a pinned Debian base.

    tools/setup-clone.sh --root /path/to/filled/root   # siblings at their pins, submodules, root/
    retools/tools/re-run python3 retools/tools/inventory.py          # the first run builds the image

`retools/tools/re-run COMMAND` runs `COMMAND` in the image with this repository mounted at `/work`, `root/`
included; with no command it opens a shell. `root/` is your own copy of the IRIX 6.5.30 files listed in
[IRIX_FILES.md](IRIX_FILES.md); they are never committed. Fill it from your install or media, then unpack and
link the archives by hand as IRIX_FILES.md describes; retools no longer ships a script for that.

To reproduce a cited result:

- Generated tables under `docs/inventory/` come from `retools/tools/re-run python3 retools/tools/inventory.py`.
  `git status --short docs` shows nothing afterwards when your `root/` matches `scripts/inventory-root.sha256`.
- A claim an entry marks as established by execution is reproduced by the script in `scripts/` that
  the entry names; its docstring says what it reproduces and how to run it, always as
  `retools/tools/re-run python3 retools/tools/NAME.py ...` from the repository root.
- The shared tooling (container definitions, wrappers, Ghidra scripts, the inventory, fact sheet and claim checker, and the device extractors) is the `retools/` submodule (sgi-retools). Run its tools by their submodule path from the repository root (`retools/tools/NAME`, device tools under `retools/tools/chips/`); they find this workspace from the current directory. There are no local links into it, so a change to a shared tool is made in retools and the pin here moves with a commit. The optional Ghidra image is built from `retools/tools/Containerfile.ghidra` by
  `retools/tools/re-run --ghidra COMMAND`, and `retools/tools/re-run --ghidra-export OBJECT` writes decompiled C and
  function-similarity output as JSON (see `ghidra/README.md`); nothing else needs it. `retools/tools/README-analysis.md`
  describes the `.mdebug` importer and the kernel table extractors.

## Clone and query

    git clone https://github.com/jamesbraid/chips.git && cd chips
    tools/setup-clone.sh --root /path/to/filled/root
    retools/tools/chips/disasm.sh tools/configs/pic.json             # stage 1, in the container
    python3 retools/tools/chips/scan.py tools/configs/bridge.json --base "$PWD" --out work/bridge

Questions are answered from `chips/<chip>/census/` (the TSV tables), `chips/<chip>/README.md` (entries with
labels) and `grep -r` over `root/spec/*.txt` (text of the specifications, not committed).

Licence: BSD-3-Clause, see [LICENSE](LICENSE). The scripts descend from gr4's
and keep its notice in [retools/tools/LICENSE-gr4](retools/tools/LICENSE-gr4).
