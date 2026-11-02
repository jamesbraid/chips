#!/bin/sh
# Prepare a fresh clone of this repository to run its tools: fetch the shared tooling (the
# retools submodule), then run its setup-clone.sh with the same arguments. `retools/tools/
# setup-clone.sh --help` lists them. This stub is the only copy of the shared tooling kept
# in the workspace, because the rest is unreachable until the submodule is checked out.
set -eu
cd "$(dirname "$0")/.."
git submodule update -q --init retools
exec retools/tools/setup-clone.sh "$@"
