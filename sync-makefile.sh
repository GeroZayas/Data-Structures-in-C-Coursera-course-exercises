#!/bin/bash

# -----------------------------------------------------------------------------
# Sync a file across all local Git branches
#
# WHAT IT DOES:
# Copies the current version of a file from the current branch to every other
# local branch, committing the change only when the file is different.
# Uses Git worktrees, so the current working tree/branch is not changed.
#
# HOW TO USE:
# 1. Change FILE below to the file you want to synchronize:
#
#       FILE="Makefile"
#
#    Examples:
#
#       FILE="Makefile"
#       FILE="src/config.h"
#       FILE=".clang-format"
#
# 2. Make sure the file's current version is committed on the current branch.
# 3. Run the script from anywhere inside the repository.
#
# The script only synchronizes local branches. It does not modify remote
# branches.
# -----------------------------------------------------------------------------

FILE="Makefile"
SOURCE_BRANCH=$(git branch --show-current)

if [ -z "$SOURCE_BRANCH" ]; then
    echo "Error: no estás en una branch."
    exit 1
fi

# Asegúrate de que el Makefile actual esté commiteado
if ! git diff --quiet -- "$FILE" || ! git diff --cached --quiet -- "$FILE"; then
    echo "Error: tienes cambios sin commit en $FILE"
    exit 1
fi

SOURCE_FILE=$(git rev-parse --show-toplevel)/"$FILE"

for BRANCH in $(git for-each-ref --format='%(refname:short)' refs/heads/); do

    if [ "$BRANCH" = "$SOURCE_BRANCH" ]; then
        continue
    fi

    echo "→ Syncing $BRANCH"

    WORKTREE=$(mktemp -d)

    git worktree add --quiet "$WORKTREE" "$BRANCH" || {
        rm -rf "$WORKTREE"
        exit 1
    }

    cp "$SOURCE_FILE" "$WORKTREE/$FILE"

    cd "$WORKTREE" || exit 1

    if git diff --quiet -- "$FILE"; then
        echo "  ✓ Already identical"
    else
        git add "$FILE"
        git commit -m "Sync Makefile with $SOURCE_BRANCH"
        echo "  ✓ Updated"
    fi

    cd - > /dev/null

    git worktree remove --quiet "$WORKTREE"
done

echo "Done."