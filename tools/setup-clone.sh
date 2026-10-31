#!/bin/sh
# setup-clone.sh DIR : fresh clone of this repository with root/ linked and a container wrapper.
#   REMOTE=URL  where to clone from        ROOT=PATH  a filled root/ (IRIX_FILES.md)
#   REENV=PATH  the build-container tool (re-run) that takes --workspace DIR -- COMMAND
# Writes DIR/rr.sh: run any command in the toolchain container with DIR as the workspace.
set -e
d=${1:?usage: setup-clone.sh DIR}
git clone -q "${REMOTE:?set REMOTE}" "$d"
cd "$d"
ln -s "${ROOT:?set ROOT}" root
mkdir -p .cache/siblings
jq -r 'to_entries[]|"\(.key) \(.value)"' scripts/inventory-siblings.json | while read -r fam sha; do
  git clone -q "$SIBLING_BASE/$fam.git" ".cache/siblings/$fam"
  git -C ".cache/siblings/$fam" checkout -q "$sha"
done
if [ -f .gitmodules ] && grep -q ogl-sample .gitmodules; then git submodule update -q --init --depth 1 ogl-sample; fi
printf '#!/bin/sh\nexport UV_CACHE_DIR=${UV_CACHE_DIR:-$HOME/.cache/uv}\nexec %s --workspace %s -- "$@"\n' "${REENV:?set REENV}" "$PWD" > rr.sh
chmod +x rr.sh
echo "ready $PWD (wrapper rr.sh; run RR=$PWD/rr.sh tools/disasm.sh tools/configs/bridge.json)"
