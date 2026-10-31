#!/bin/sh
# Pre-push check: no forbidden names or private paths in tracked files, no trailers in commit messages.
# Exit 1 on any hit. Run from the repository root.
set -u
pat='origami|qemu|jamesb|hinv-archive|/storage/|/scratch/|/home/|refs/irix|irix-source|irix-657|docs/library|\.codex|emdash|Co-Authored|Generated with|claude|anthropic|pet.?name'
bad=0
git ls-files -z | xargs -0 grep -I -n -i -E "$pat" -- 2>/dev/null | grep -v -E '^(scripts/check-leaks.sh|scripts/inventory.py|scripts/LICENSE-gr4|LICENSE|ghidra/)' && bad=1
git log --format=%B | grep -i -E 'Co-Authored|Generated with|Signed-off' && bad=1
exit $bad
