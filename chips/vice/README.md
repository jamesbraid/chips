# VICE

Mode: **spec-backed** (see [docs/specs.md](../../docs/specs.md)).

O2 video and image compression engine; presence only. Spec: VICE Design Specification, 099-0123-003. Builds: IP32.

Status: coverage notes, not register entries: the kernel's presence probe, the identification values, the error path and the user library are graded in [docs/coverage-vice.md](../../docs/coverage-vice.md). Census config: [`tools/configs/vice.json`](../../tools/configs/vice.json); results land in `census/`.

Entries below carry a label (established, inferred, unknown) and a derivation, per AGENTS.md.
