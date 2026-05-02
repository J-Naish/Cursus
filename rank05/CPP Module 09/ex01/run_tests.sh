#!/bin/bash

set -u

cd "$(dirname "$0")"

if [ ! -x ./RPN ] || [ Makefile -nt ./RPN ]; then
    echo "=== building ==="
    make || { echo "build failed"; exit 1; }
    echo
fi

BOLD="\033[1m"
DIM="\033[2m"
RESET="\033[0m"

run() {
    local label="$1"
    local expected="$2"
    shift 2
    local out
    out=$("$@" 2>&1)
    local rc=$?

    if [ "$expected" = "$out" ]; then
        echo -e "${BOLD}[PASS]${RESET} $label"
    else
        echo -e "${BOLD}[FAIL]${RESET} $label"
        echo -e "  ${DIM}cmd:      $* ${RESET}"
        echo -e "  ${DIM}expected: $expected${RESET}"
        echo -e "  ${DIM}got:      $out${RESET} (rc=$rc)"
    fi
}

# subject examples
run "subject ex 1: 8 9 * 9 - 9 - 9 - 4 - 1 +"  "42"     ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
run "subject ex 2: 7 7 * 7 -"              "42"     ./RPN "7 7 * 7 -"
run "subject ex 3: 1 2 * 2 / 2 * 2 4 - +"  "0"      ./RPN "1 2 * 2 / 2 * 2 4 - +"
run "subject ex 4: (1 + 1)"                "Error"  ./RPN "(1 + 1)"

# basic arithmetic
run "addition"                "5"      ./RPN "2 3 +"
run "subtraction"             "1"      ./RPN "3 2 -"
run "multiplication"          "12"     ./RPN "3 4 *"
run "division"                "3"      ./RPN "9 3 /"
run "single number"           "5"      ./RPN "5"

# results outside single-digit range
run "result > 10"             "63"     ./RPN "9 7 *"
run "result negative"         "-1"     ./RPN "2 3 -"
run "result zero"             "0"      ./RPN "5 5 -"

# argument errors
run "no argument"             "Error"  ./RPN
run "empty string"            "Error"  ./RPN ""
run "two arguments"           "Error"  ./RPN "1" "2"
run "whitespace only"         "Error"  ./RPN "   "

# token errors
run "non-digit non-op token"  "Error"  ./RPN "a b +"
run "two-digit number"        "Error"  ./RPN "10 5 +"
run "decimal number"          "Error"  ./RPN "1.5 2 +"
run "parenthesis"             "Error"  ./RPN "( 1 1 + )"
run "unknown operator"        "Error"  ./RPN "1 2 %"

# stack errors
run "operator first"          "Error"  ./RPN "+"
run "single operand op"       "Error"  ./RPN "3 +"
run "trailing operand"        "Error"  ./RPN "3 4"
run "many trailing operands"  "Error"  ./RPN "1 2 3"

# division by zero
run "div by zero"             "Error"  ./RPN "5 0 /"
run "div by zero chained"     "Error"  ./RPN "1 2 + 0 /"
run "zero div by nonzero"     "0"      ./RPN "0 5 /"

# expressions involving zero
run "zero plus"               "5"      ./RPN "0 5 +"
run "zero times"              "0"      ./RPN "0 5 *"

# complex expressions
run "deep nesting"            "20"     ./RPN "2 3 + 4 *"
run "left-heavy"              "10"     ./RPN "1 2 + 3 + 4 +"

echo
echo "=== done ==="
