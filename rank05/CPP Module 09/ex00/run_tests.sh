#!/bin/bash

set -u

cd "$(dirname "$0")"


if [ ! -x ./btc ] || [ Makefile -nt ./btc ]; then
    echo "=== building ==="
    make || { echo "build failed"; exit 1; }
    echo
fi

BOLD="\033[1m"
DIM="\033[2m"
RESET="\033[0m"

run() {
    local label="$1"
    shift
    echo -e "${BOLD}=== $label ===${RESET}"
    echo -e "${DIM}\$ $*${RESET}"
    "$@"
    echo
}

run "no argument"           ./btc
run "nonexistent file"      ./btc tests/__no_such_file__.txt

for f in tests/*.txt; do
    [ -f "$f" ] || continue
    run "$(basename "$f")" ./btc "$f"
done

echo "=== done ==="
