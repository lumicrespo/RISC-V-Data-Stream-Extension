#!/bin/bash

DIR=$(dirname "$(realpath "$0")")

CYAN="\e[96m"
GREEN="\e[32m"
RED="\e[91m"
RESET="\e[0m"

FAILED=0
SUCCEEDED=0

cd "llvm-project"
git reset --hard HEAD
git clean -fd

# Verify we are inside an LLVM repository
if [ ! -d ".git" ]; then
    echo -e "${RED}Error:${RESET} This script must be run from the root of an LLVM repository."
    exit 1
fi

for patch in "$DIR"/patch/*.patch; do
    [ -f "$patch" ] || continue

    echo -e "${GREEN}-----=======   Applying patch: ${CYAN}$(basename "$patch")${GREEN} ======-----${RESET}"

    if git apply "$patch"; then
        echo -e "${GREEN}++++++++   Success   ++++++++${RESET}\n"
        ((SUCCEEDED++))
    else
        echo -e "${RED}!!!!!!!!   FAILED   !!!!!!!!${RESET}\n"
        ((FAILED++))
    fi
done

echo
echo -e "Applied $CYAN$((SUCCEEDED + FAILED))$RESET patches."
echo -e "Succeeded: $GREEN$SUCCEEDED$RESET"
echo -e "Failed:    $RED$FAILED$RESET"

if [ "$FAILED" -ne 0 ]; then
    exit 1
fi