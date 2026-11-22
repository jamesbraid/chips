# Visual Workstation HAL builds: rebuild recipe

Rebuilds the Ghidra exports and the scan results behind [software/visws/hal-builds.md](../../software/visws/hal-builds.md) from the
holdings, by SHA-256. It adds no launcher: every export is `retools/tools/re-run --ghidra-export ... --decompile-all` (with `--dbg` for the NT 4.0
images, which have `.dbg` files). No PDB is held, so `--pdb` is not used.

| File | What |
|---|---|
| `builds.tsv` | label, image SHA-256 and size, symbol file SHA-256 and size (`-` for none) for each build |
| `build.sh` | stages each image under `root/` (ignored by git), runs the export, then `scan.py` |
| `stats.py` | export table, version, function and name counts of one build (runs in the toolchain image) |
| `scan.py` | `facts` (`fs:` and PCR/PRCB offsets, dispatch-table stores), `hw` (board addresses and ports), `fp` and `match` (function shapes and matching against another image) |

```sh
VISWS_HOLDINGS=DIR tools/visws-hal/build.sh [OUTDIR]
VISWS_HOLDINGS=DIR VISWS_RECOVERY_ISO=ISO VISWS_W2K_ISO=ISO tools/visws-hal/build.sh --stock
```

`VISWS_HOLDINGS` is any directory tree holding the images and `.dbg` files; files are found by size and hash. `--stock` also exports the SP4 `HAL.DLL`,
`HALAPIC.DLL` and `HALMPS.DLL` of NT 4.0 (Recovery CD-1 v1.1) and Windows 2000 (SP4 5-in-1 disc) and writes `vs-stock.json` for each build.
Output goes under `.cache/visws-hal/` (ignored by git). It holds decompiled C, which is never committed. The export tool deletes its Ghidra project, so the JSON is the durable product;
a build takes about a minute and a half.
