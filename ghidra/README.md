# Ghidra tooling

Everything that runs inside Ghidra lives here. A component has its own
acceptance test, run from the repository root inside the Ghidra image with
`root/` populated. No component has landed yet; the empty directories (each
holds a `.gitkeep`) fix the layout.

```
ghidra/
  processors/<name>/   one Ghidra processor extension per directory
                       (extension.properties, data/languages/*.slaspec,
                       tests/, tools/)
  import/<name>/       loader and import scripts for firmware images
  types/<name>/        data-type scripts
  scripts/             the shared IRIX scripts (IrixGp, IrixJumpTables,
                       FindWindowStores, ...), byte-identical across workspaces
```

## Build and run

Run a component's `tests/run-ghidra.sh` in the Ghidra image, then its
`tests/check.py` on the dump directory it writes:

```sh
tools/re-run --ghidra -- ghidra/processors/NAME/tests/run-ghidra.sh .cache/NAME
tools/re-run python3 ghidra/processors/NAME/tests/check.py .cache/NAME
```

(`tools/re-run` mounts the workspace at `/work`, the Ghidra image with `--ghidra` and
the toolchain image without.)

## Components

| Path | What it is |
|---|---|
| none yet | |

## Decompiled C as JSON, typed structures and function similarity

`re-run --ghidra-export OBJECT` runs Ghidra over one object under `root/` and
writes the result outside the workspace, printing where. It writes nothing into
the repository, so there is nothing to commit by accident.

```sh
# decompiled C per function, as JSON with the decompiler's warnings
re-run --workspace . --ghidra-export root/IP30/unix \
    --decompile-symbol NAME --decompile-symbol 'prefix_*' --decompile-symbol @0xADDRESS
# the same, with named structure fields
re-run --workspace . --ghidra-export root/IP30/unix \
    --decompile-symbol NAME --types ghidra/types/context.types.json
# every function, or a list file (one name, glob or @address per line)
re-run --workspace . --ghidra-export OBJECT --decompile-all
re-run --workspace . --ghidra-export OBJECT --decompile-list names.txt
# function similarity: one object per run, each matched against those before it
re-run --workspace . --ghidra-export OBJECT --bsim-db kernels --bsim-label board-name
```

`--types` takes a JSON file kept in the repository, with `structs`
(`name`, `size`, `fields` of `offset`, `name`, `type`, optional `comment`),
`functions` (`match`: a name, a glob or `@0xADDRESS`; `params` with `type` and
`name`; optional `returns`) and optional `globals` (`address`, `type`, `name`).
Types are `u8 s8 u16 s16 u32 s32 u64 s64 f32 f64`, a struct name, a trailing `*`
or `[N]`. Set `pointer_bytes` (8 for a 64-bit kernel, 4 for o32 and N32 objects): a spec for one
pointer width is skipped on the other, since the offsets differ. Only fields
with a source belong in a spec; an unnamed gap stays `field_0x..` in the output.

Decompiler output and
similarity scores are navigation, not evidence. The decompiler folds stores,
misses switches and invents parameters; a typed field name only says that a
definition was applied; BSim says two bodies look alike and does not say they are
the same routine, and it cannot say anything about routines under about 64 bytes.
Kernels and PROM payloads work the same way as libraries. A committed claim still rests on the disassembly and the fact sheets. Quote the
instruction, not the C.
Kernels and PROM payloads go through the same commands as libraries.
