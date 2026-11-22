#!/bin/sh
# Rebuild the halborg exports for every build in builds.tsv.
#
#   VISWS_HOLDINGS=DIR tools/visws-hal/build.sh [OUTDIR]
#
# VISWS_HOLDINGS is any directory tree that holds the files; each is found by size and SHA-256 from
# builds.tsv, so file names do not matter. OUTDIR is inside the repository (the container sees only
# it) and defaults to .cache/visws-hal. Run from the
# repository root. Each build is staged under root/visws/ (ignored by git), run through
# `re-run --ghidra-export --decompile-all` (with --dbg where a symbol file is listed), and the
# export is copied to OUTDIR/LABEL/. stats.py then writes OUTDIR/LABEL/stats.json.
# VISWS_ONLY="LABEL ..." limits the run to those builds.
# scan.py then writes facts.json, hw.json and fp.json per build. Stock Microsoft HALs for
# comparison: set VISWS_RECOVERY_ISO (Recovery CD-1 v1.1) and VISWS_W2K_ISO (Windows 2000 SP4 5-in-1) and pass --stock (SP4
# HAL.DLL, HALAPIC.DLL and HALMPS.DLL from the first, the same three from the second; needs
# isoinfo on the host), which exports them too and writes vs-stock.json per build.
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

tail -n +2 "$here/builds.tsv" > "$out/builds.rows"
while IFS="	" read -r label sha size ssha ssize; do
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
    retools/tools/re-run --ghidra-export "$stage/$label.dll" $dbg --decompile-all --timeout 3000 \
        < /dev/null > "$out/$label.log" 2>&1 || { echo "export failed for $label, see $out/$label.log" >&2; exit 1; }
    dir=$(grep '^\.cache/.*/decompile\.json$' "$out/$label.log" | tail -n 1 | xargs dirname)
    rm -rf "$out/$label"; mkdir -p "$out/$label"
    cp -r "$dir/." "$out/$label/"
    retools/tools/re-run python3 -I "$here/stats.py" "$stage/$label.dll" "$out/$label/decompile.json" \
        < /dev/null > "$out/$label/stats.json"
    echo "$label: $(grep -h 'exported' "$out/$label.log")"
done < "$out/builds.rows"

S() { retools/tools/re-run python3 -I "$here/scan.py" "$@" < /dev/null; }
for label in $(cut -f1 "$out/builds.rows"); do
    [ -f "$out/$label/decompile.json" ] || continue
    S facts "$stage/$label.dll" "$out/$label/decompile.json" > "$out/$label/facts.json"
    S hw "$stage/$label.dll" "$out/$label/decompile.json" > "$out/$label/hw.json"
    S fp "$stage/$label.dll" "$out/$label/decompile.json" "$out/$label/fp.json" > /dev/null
done

if [ "$stock" = 1 ]; then
    : "${VISWS_RECOVERY_ISO:?}" "${VISWS_W2K_ISO:?}"
    mkdir -p "$stage/stock"
    for f in HAL HALAPIC HALMPS; do
        isoinfo -J -i "$VISWS_RECOVERY_ISO" -x "/SP4/I386/$f.DLL;1" > "$stage/stock/nt4sp4-$f.dll"
        isoinfo -i "$VISWS_W2K_ISO" -x "/ROOT/WRKS/I386/$f.DL_" > "$stage/stock/w2ksp4-$f.DL_"
        retools/tools/re-run sh -c "cd $stage/stock && mkdir -p x && cabextract -q -d x w2ksp4-$f.DL_ && mv x/*.dll w2ksp4-$f.dll && rmdir x" < /dev/null
    done
    for n in nt4sp4-HAL nt4sp4-HALAPIC nt4sp4-HALMPS w2ksp4-HAL w2ksp4-HALAPIC w2ksp4-HALMPS; do
        img="$stage/stock/$n.dll"; [ -f "$img" ] || img=$(ls "$stage/stock/$n".* 2>/dev/null | grep -i '\.dll$' | head -1)
        retools/tools/re-run --ghidra-export "$img" --decompile-all --timeout 3000 < /dev/null > "$out/stock-$n.log" 2>&1
        dir=$(grep '^\.cache/.*/decompile\.json$' "$out/stock-$n.log" | tail -n 1 | xargs dirname)
        mkdir -p "$out/stock-$n"; cp -r "$dir/." "$out/stock-$n/"
        S fp "$img" "$out/stock-$n/decompile.json" "$out/stock-$n/fp.json" > /dev/null
    done
    # one merged fingerprint file per era; cabextract keeps the cabinet's lower-case name, so match case-blind
    retools/tools/re-run python3 -I -c "
import json,glob
for era,pre in (('nt4','nt4sp4'),('w2k','w2ksp4')):
    rows=[]
    for d in sorted(glob.glob('$out/stock-'+pre+'-*/fp.json')):
        for r in json.load(open(d)): r['name']=d.split('/')[-2]+':'+r['name']; rows.append(r)
    json.dump(rows,open('$out/stock-'+era+'-all.fp.json','w'))
" < /dev/null
    for label in $(cut -f1 "$out/builds.rows"); do
        [ -f "$out/$label/fp.json" ] || continue
        era=${label%%-*}; [ "$era" = nt4 ] || era=w2k
        S match "$out/$label/fp.json" "$out/stock-$era-all.fp.json" > "$out/$label/vs-stock.json"
    done
fi
