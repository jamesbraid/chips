#!/bin/sh
# Rebuild the halborg exports and the comparisons for every build in builds.tsv.
#
#   VISWS_HOLDINGS=DIR tools/visws-hal/build.sh [--stock] [OUTDIR]
#
# VISWS_HOLDINGS is any directory tree that holds the files; each is found by size and SHA-256 from
# builds.tsv (images, symbol files, and the two discs the stock HALs come from), so file names do not
# matter. OUTDIR is inside the repository (the container sees only it) and defaults to .cache/visws-hal.
# Run from anywhere. Each build is staged under root/visws/ (ignored by git), run through
# `re-run --ghidra-export --decompile-all` (with --dbg where a symbol file is listed), and the export is
# copied to OUTDIR/LABEL/. Then stats.py writes stats.json and scan.py writes facts.json (fs: and PCR/PRCB
# offsets, dispatch-table stores, and the same scan over code no function covers), hw.json and fp.json.
# VISWS_ONLY="LABEL ..." limits the run to those builds.
#
# --stock also extracts SP4 HAL.DLL, HALAPIC.DLL and HALMPS.DLL from the Recovery CD-1 disc (NT 4.0) and the
# Windows 2000 SP4 5-in-1 disc, and the Microsoft HAL, HALAPIC and HALMPS symbol files from the Recovery CD-1
# (needs isoinfo on the host), exports them, and writes per build: vs-stock.json (body match), names.json (NT 4.0
# name test and SGI-specific candidates), ties.json (Windows 2000 body test and ties to NT 4.0), and the
# build-against-build matches vs-*.json (up, mp, rc3, rtm, beta, sp4, nt4).
set -eu
cd "$(dirname "$0")/../.."
: "${VISWS_HOLDINGS:?set VISWS_HOLDINGS to a directory holding the build files}"
stock=0
[ "${1:-}" = --stock ] && { stock=1; shift; }
out=${1:-.cache/visws-hal}
here=tools/visws-hal
stage=root/visws
mkdir -p "$stage" "$out"

find_by_hash() { # sha size -> path on stdout
    find "$VISWS_HOLDINGS" -type f -size "$2"c | while read -r f; do
        [ "$(sha256sum "$f" | cut -d' ' -f1)" = "$1" ] && { echo "$f"; break; }
    done
}
S() { retools/tools/re-run python3 -I "$here/scan.py" "$@" < /dev/null; }
export_one() { # image outdir name [re-run options]
    img=$1; od=$2; name=$3; shift 3
    retools/tools/re-run --ghidra-export "$img" "$@" --decompile-all --timeout 3000 \
        < /dev/null > "$out/$name.log" 2>&1 || { echo "export failed for $name, see $out/$name.log" >&2; exit 1; }
    dir=$(grep '^\.cache/.*/decompile\.json$' "$out/$name.log" | tail -n 1 | xargs dirname)
    rm -rf "$od"; mkdir -p "$od"; cp -r "$dir/." "$od/"
}

grep -v '^label' "$here/builds.tsv" > "$out/builds.rows"
while IFS="	" read -r label sha size ssha ssize; do
    case "$label" in iso-*) continue ;; esac
    case " ${VISWS_ONLY:-$label} " in *" $label "*) ;; *) continue ;; esac
    src=$(find_by_hash "$sha" "$size")
    [ -n "$src" ] || { echo "missing $label ($sha)" >&2; exit 1; }
    cp "$src" "$stage/$label.dll"
    dbg=
    if [ "$ssha" != - ]; then
        ssrc=$(find_by_hash "$ssha" "$ssize")
        [ -n "$ssrc" ] || { echo "missing symbols for $label ($ssha)" >&2; exit 1; }
        cp "$ssrc" "$stage/$label.dbg"
        dbg="--dbg $stage/$label.dbg"
    fi
    # shellcheck disable=SC2086
    export_one "$stage/$label.dll" "$out/$label" "$label" $dbg
    retools/tools/re-run python3 -I "$here/stats.py" "$stage/$label.dll" "$out/$label/decompile.json" \
        < /dev/null > "$out/$label/stats.json"
    S facts "$stage/$label.dll" "$out/$label/decompile.json" > "$out/$label/facts.json"
    S hw "$stage/$label.dll" "$out/$label/decompile.json" > "$out/$label/hw.json"
    S fp "$stage/$label.dll" "$out/$label/decompile.json" "$out/$label/fp.json" > /dev/null
    echo "$label: $(grep -h 'exported' "$out/$label.log")"
done < "$out/builds.rows"

[ "$stock" = 1 ] || exit 0

iso() { # label -> path of the disc, found by hash
    set -- $(grep "^$1	" "$here/builds.tsv" | cut -f2,3)
    p=$(find_by_hash "$1" "$2"); [ -n "$p" ] || { echo "missing disc $1" >&2; exit 1; }; echo "$p"
}
rec=$(iso iso-recovery-cd1); w2k=$(iso iso-w2k-sp4-5in1)
mkdir -p "$stage/stock" "$stage/msdbg"
for f in HAL HALAPIC HALMPS; do
    isoinfo -J -i "$rec" -x "/SP4/I386/$f.DLL;1" > "$stage/stock/nt4sp4-$f.dll"
    isoinfo -J -i "$rec" -x "/SUPPORT/DEBUG/I386/SYMBOLS/MS/SP1/DLL/$f.DBG;1" > "$stage/msdbg/$f.dbg"
    isoinfo -i "$w2k" -x "/ROOT/WRKS/I386/$f.DL_" > "$stage/stock/w2ksp4-$f.DL_"
    retools/tools/re-run sh -c "cd $stage/stock && rm -rf x && mkdir x && cabextract -q -d x w2ksp4-$f.DL_ && mv x/*.dll w2ksp4-$f.dll && rmdir x" < /dev/null
done
for n in nt4sp4-HAL nt4sp4-HALAPIC nt4sp4-HALMPS w2ksp4-HAL w2ksp4-HALAPIC w2ksp4-HALMPS; do
    export_one "$stage/stock/$n.dll" "$out/stock-$n" "stock-$n"
    S fp "$stage/stock/$n.dll" "$out/stock-$n/decompile.json" "$out/stock-$n/fp.json" > /dev/null
done
# one merged fingerprint file per era
retools/tools/re-run python3 -I -c "
import json
for era, pre in (('nt4', 'nt4sp4'), ('w2k', 'w2ksp4')):
    rows = []
    for n in ('HAL', 'HALAPIC', 'HALMPS'):
        d = '$out/stock-%s-%s' % (pre, n)
        for r in json.load(open(d + '/fp.json')):
            r['name'] = d.split('/')[-1] + ':' + r['name']; rows.append(r)
    json.dump(rows, open('$out/stock-%s-all.fp.json' % era, 'w'))
" < /dev/null
M() { S match "$out/$1/fp.json" "$2" > "$out/$1/$3.json"; }
for label in nt4-halborg nt4-halbrgup; do
    M $label "$out/stock-nt4-all.fp.json" vs-stock
    S names "$out/$label/decompile.json" "$out/$label/vs-stock.json" "$stage/msdbg/HAL.dbg" "$stage/msdbg/HALAPIC.dbg" "$stage/msdbg/HALMPS.dbg" > "$out/$label/names.json"
done
for label in w2k-rc3-halborg w2k-rtm-halborg w2k-sp4beta-halborg w2k-sp4-halborg; do
    M $label "$out/stock-w2k-all.fp.json" vs-stock
    M $label "$out/nt4-halborg/fp.json" vs-nt4
    S ties "$out/$label/vs-stock.json" "$out/$label/vs-nt4.json" "$out/nt4-halborg/names.json" > "$out/$label/ties.json"
done
M nt4-halborg "$out/nt4-halbrgup/fp.json" vs-up
M nt4-halbrgup "$out/nt4-halborg/fp.json" vs-mp
M w2k-rtm-halborg "$out/w2k-rc3-halborg/fp.json" vs-rc3
M w2k-sp4beta-halborg "$out/w2k-rtm-halborg/fp.json" vs-rtm
M w2k-sp4-halborg "$out/w2k-sp4beta-halborg/fp.json" vs-beta
M w2k-sp4beta-halborg "$out/w2k-sp4-halborg/fp.json" vs-sp4
