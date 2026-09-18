#!/bin/bash

# -----------------------------------------------------------------------------
# Sync a file across all local Git branches
#
# WHAT IT DOES:
# Copies the current version of a file from the current branch to every other
# local branch, committing the change only when the file is different.
#
# HOW TO USE:
# 1. Change FILE below to the file you want to synchronize:
#
#       FILE="Makefile"
#       FILE="src/config.h"
#       FILE=".clang-format"
#
# 2. Make sure the file is committed on the current branch.
# 3. Run the script from anywhere inside the repository.
#
# The script only synchronizes local branches.
# It does not modify remote branches.
# -----------------------------------------------------------------------------

FILE=".clang-format"

SOURCE_BRANCH=$(git branch --show-current)

if [ -z "$SOURCE_BRANCH" ]; then
    echo "Error: not on a branch."
    exit 1
fi

# Make sure the file has no uncommitted changes.
if ! git diff --quiet -- "$FILE" || ! git diff --cached --quiet -- "$FILE"; then
    echo "Error: $FILE has uncommitted changes."
    exit 1
fi

# Save the current version of the file.
TEMP_FILE=$(mktemp)
git show "$SOURCE_BRANCH:$FILE" > "$TEMP_FILE" || {
    echo "Error: could not read $FILE from $SOURCE_BRANCH."
    rm -f "$TEMP_FILE"
    exit 1
}

ORIGINAL_BRANCH="$SOURCE_BRANCH"

for BRANCH in $(git for-each-ref --format='%(refname:short)' refs/heads/); do

    if [ "$BRANCH" = "$SOURCE_BRANCH" ]; then
        continue
    fi

    echo "→ Syncing $BRANCH"

    git switch "$BRANCH" || {
        echo "Error: could not switch to $BRANCH."
        rm -f "$TEMP_FILE"
        git switch "$ORIGINAL_BRANCH"
        exit 1
    }

    cp "$TEMP_FILE" "$FILE"

    if git diff --quiet -- "$FILE"; then
        echo "  ✓ Already identical"
    else
        git add "$FILE"
        git commit -m "Sync $FILE with $SOURCE_BRANCH" || {
            echo "Error: could not commit on $BRANCH."
            rm -f "$TEMP_FILE"
            git switch "$ORIGINAL_BRANCH"
            exit 1
        }

        echo "  ✓ Updated"
    fi
done

# Return to the original branch.
git switch "$ORIGINAL_BRANCH"

rm -f "$TEMP_FILE"

echo "Done."