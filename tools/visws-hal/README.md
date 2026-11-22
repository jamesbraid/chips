# Visual Workstation HAL builds: rebuild recipe

Rebuilds the Ghidra exports and the scan results behind [software/visws/hal-builds.md](../../software/visws/hal-builds.md) from the
holdings, by SHA-256. It adds no launcher: every export is `retools/tools/re-run --ghidra-export ... --decompile-all` (with `--dbg` for the NT 4.0
images, which have `.dbg` files). No PDB is held, so `--pdb` is not used.

| File | What |
|---|---|
| `builds.tsv` | label, SHA-256 and size of each image, and of its symbol file (`-` for none); the last two rows are the two discs the stock HALs and Microsoft symbols come from |
| `build.sh` | stages each image under `root/` (ignored by git), runs the export, then `stats.py` and `scan.py`; with `--stock` also the comparisons |
| `stats.py` | export table, version, function and name counts of one build (runs in the toolchain image) |
| `scan.py` | `facts`, `hw`, `fp`, `match`, `names`, `ties` (below) |

```sh
VISWS_HOLDINGS=DIR tools/visws-hal/build.sh [OUTDIR]          # the six builds
VISWS_HOLDINGS=DIR tools/visws-hal/build.sh --stock [OUTDIR]  # and the stock HALs and comparisons
```

`VISWS_HOLDINGS` is any directory tree holding the images, `.dbg` files and the two discs; files are found by size and hash, so names do not matter. `--stock` needs
`isoinfo` on the host. Output goes under `.cache/visws-hal/` (ignored by git); it holds decompiled C, which is never committed. The export tool deletes its Ghidra
project, so the JSON is the durable product. A full `--stock` run takes about half an hour.

What `scan.py` does (all from the image bytes with capstone; decompiler text is never read except for function bounds and names):

- `facts IMAGE decompile.json`: `fs:` offsets, the fixed-address PCR use, registers loaded from `fs:[0x1c]` and `fs:[0x20]` and the offsets used through them, stores of code addresses into
  the two dispatch tables, and the same `fs:` scan over every executable range no function covers (`fs_swept`, `tagged_swept`; offsets of `0x400` and above there are mis-decoded data).
- `hw IMAGE decompile.json`: functions that use the Cobalt block addresses, the Lithium windows or the power-management ports.
- `fp` and `match`: function shape fingerprints and matching between two images (exact shape, mnemonic-trigram near match of 0.80 or more, string-use match).
- `names decompile.json vs-stock.json HAL.dbg HALAPIC.dbg HALMPS.dbg` (NT 4.0): the name test against the Microsoft symbol files; writes the counts and the SGI-specific candidates (`names.json`).
- `ties vs-stock.json vs-nt4.json names.json` (Windows 2000): the stock body test and how many functions tie to an NT 4.0 SGI-specific name (`ties.json`).

`build.sh --stock` runs these in order and writes, per build, `vs-stock.json`, `names.json` or `ties.json`, and the build-against-build matches (`vs-up`, `vs-mp`, `vs-rc3`, `vs-rtm`, `vs-beta`, `vs-sp4`, `vs-nt4`).
