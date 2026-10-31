#!/bin/sh
# Whole census for one ASIC.
#   tools/run.sh configs/ASIC.json DATASHEET_REPO MODEL_CHECKOUT [MODEL_REF]
# The comparison needs the emulator's datasheet checkout and model source; without them use stages 1-2 and tools/fields.py only.
# Needs python3 on the host; the only container step is tools/disasm.sh.
# SPEC_DIR=dir holds the register-map transcriptions named by a config's spec entries.
# SKIP_DISASM=1 reuses work/dis. NOTES=file appends hand-written findings to the report.
# Output lands in work/ASIC/ and is copied to docs/census/ASIC/.
set -eu
cd "$(dirname "$0")/.."
CONFIG=${1:?config}; REPO=${2:?datasheet repo}; model=${3:?model checkout}; REF=${4:-HEAD}
ASIC=$(python3 -c "import json,sys;print(json.load(open(sys.argv[1]))['asic'])" "$CONFIG")
mkdir -p "work/$ASIC"
[ -n "${SKIP_DISASM:-}" ] || tools/disasm.sh "$CONFIG"
tools/export-model.sh "$CONFIG" "$model" "$REF"
python3 tools/scan.py "$CONFIG" --base "$PWD" --out "work/$ASIC"
python3 tools/ref.py "$CONFIG" --repo "$REPO" --model work/model ${SPEC_DIR:+--spec-dir "$SPEC_DIR"} --out "work/$ASIC/ref.json"
python3 tools/join.py "$CONFIG" --sites "work/$ASIC/sites.tsv" --ref "work/$ASIC/ref.json" --out "work/$ASIC/$ASIC"
mkdir -p "docs/census/$ASIC"
python3 tools/report.py "$CONFIG" --dir "work/$ASIC" --repo "$REPO" --out "docs/census/$ASIC/census.md" ${NOTES:+--notes "$NOTES"}
python3 tools/fields.py "$CONFIG" --sites "work/$ASIC/sites.tsv" --calls "work/$ASIC/accessor-calls.tsv" --out "work/$ASIC/$ASIC"
for f in census census-sites census-windows; do cp "work/$ASIC/$ASIC-$f.tsv" "docs/census/$ASIC/$f.tsv"; done
cp "work/$ASIC/$ASIC-fields.tsv" "docs/census/$ASIC/fields.tsv"
cp "work/$ASIC/$ASIC-context.tsv" "docs/census/$ASIC/context.tsv"
