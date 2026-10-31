#!/bin/sh
# Pre-push check: no forbidden names or private paths in tracked files, no trailers in commit messages.
# Exit 1 on any hit. Run from the repository root.
set -u
pat='origami|qemu|jamesb|hinv-archive|/storage/(nvme|software)|/scratch/|/home/|refs/irix|irix-source|irix-657|docs/library|\.codex|emdash|Co-Authored|Generated with \[?Claude|claude|anthropic|pet.?name'
bad=0
# The public irix-657m-src submodule may be declared in .gitmodules and named in AGENTS.md.
git ls-files -z | xargs -0 grep -I -n -i -E "$pat" -- 2>/dev/null | grep -v -E '^(scripts/check-leaks.sh|scripts/inventory.py|scripts/LICENSE-gr4|LICENSE|ghidra/)' |
    grep -v -E '^(\.gitmodules|AGENTS\.md):[0-9]+:.*irix-657m-src' && bad=1
git log --format=%B | grep -i -E 'Co-Authored|Generated with \[?Claude|Signed-off' && bad=1
exit $bad
