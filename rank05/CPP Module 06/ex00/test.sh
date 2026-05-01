#!/bin/bash
# ============================================================================
# ScalarConverter (ex00) test runner
#
# Usage:
#   ./test.sh           # run all tests
#   ./test.sh -v        # verbose: show expected vs actual side-by-side
#   ./test.sh -s        # strict: fail on any mismatch
#
# Notes:
#   - The "expected" outputs follow the subject PDF examples and the most
#     common interpretation of edge cases. Some cases (especially overflow
#     boundaries and non-displayable chars) are intentionally not strict.
#   - Run from inside ex00/ directory.
# ============================================================================

set -u

# --- options ----------------------------------------------------------------
VERBOSE=0
STRICT=0
for arg in "$@"; do
    case "$arg" in
        -v|--verbose) VERBOSE=1 ;;
        -s|--strict)  STRICT=1 ;;
        *) echo "unknown option: $arg" >&2; exit 1 ;;
    esac
done

# --- colors -----------------------------------------------------------------
if [ -t 1 ]; then
    RED=$'\033[0;31m'
    GREEN=$'\033[0;32m'
    YELLOW=$'\033[0;33m'
    BLUE=$'\033[0;34m'
    BOLD=$'\033[1m'
    RESET=$'\033[0m'
else
    RED=""; GREEN=""; YELLOW=""; BLUE=""; BOLD=""; RESET=""
fi

# --- build ------------------------------------------------------------------
cd "$(dirname "$0")"
echo "${BOLD}[build]${RESET} make re"
if ! make re > /tmp/scalarconv_build.log 2>&1; then
    echo "${RED}build failed:${RESET}"
    cat /tmp/scalarconv_build.log
    exit 1
fi

BIN=./convert
if [ ! -x "$BIN" ]; then
    echo "${RED}binary $BIN not found after build${RESET}"
    exit 1
fi

# --- counters ---------------------------------------------------------------
PASS=0
FAIL=0
SKIP=0
FAILED_CASES=()

# --- helpers ----------------------------------------------------------------
# run_case <label> <input> <expected_or_-->
#   expected="--" means "no strict check, just show output"
run_case() {
    local label="$1"
    local input="$2"
    local expected="$3"

    local actual
    actual=$("$BIN" "$input" 2>&1)

    if [ "$expected" = "--" ]; then
        SKIP=$((SKIP + 1))
        printf "${YELLOW}[SHOW]${RESET} %-32s input=%q\n" "$label" "$input"
        echo "$actual" | sed 's/^/        /'
        return
    fi

    if [ "$actual" = "$expected" ]; then
        PASS=$((PASS + 1))
        printf "${GREEN}[PASS]${RESET} %-32s input=%q\n" "$label" "$input"
        if [ "$VERBOSE" = "1" ]; then
            echo "$actual" | sed 's/^/        /'
        fi
    else
        FAIL=$((FAIL + 1))
        FAILED_CASES+=("$label")
        printf "${RED}[FAIL]${RESET} %-32s input=%q\n" "$label" "$input"
        echo "        ${BOLD}expected:${RESET}"
        echo "$expected" | sed 's/^/          /'
        echo "        ${BOLD}actual:${RESET}"
        echo "$actual" | sed 's/^/          /'
    fi
}

# run_argc <label> <args...> -- runs with specified argc, shows output only
run_argc() {
    local label="$1"; shift
    SKIP=$((SKIP + 1))
    printf "${YELLOW}[SHOW]${RESET} %-32s argv=(%s)\n" "$label" "$*"
    "$BIN" "$@" 2>&1 | sed 's/^/        /' || true
}

section() {
    echo ""
    echo "${BOLD}${BLUE}=== $1 ===${RESET}"
}

# ============================================================================
# Test cases
# ============================================================================

# ------------------- argc handling (no strict checks) -----------------------
section "argc handling"
run_argc "no argument"
run_argc "two arguments" "1" "2"

# ------------------- char literals ------------------------------------------
section "char literals (single non-digit char)"
run_case "lowercase letter 'a'" "a" "$(cat <<'EOF'
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOF
)"

run_case "uppercase letter 'Z'" "Z" "$(cat <<'EOF'
char: 'Z'
int: 90
float: 90.0f
double: 90.0
EOF
)"

run_case "symbol '*'" "*" "$(cat <<'EOF'
char: '*'
int: 42
float: 42.0f
double: 42.0
EOF
)"

# ------------------- int literals -------------------------------------------
section "int literals"
run_case "zero (subject example)" "0" "$(cat <<'EOF'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOF
)"

run_case "positive 42 -> '*'" "42" "$(cat <<'EOF'
char: '*'
int: 42
float: 42.0f
double: 42.0
EOF
)"

run_case "negative -42" "-42" "$(cat <<'EOF'
char: impossible
int: -42
float: -42.0f
double: -42.0
EOF
)"

# 65 -> 'A' (displayable)
run_case "65 -> 'A'" "65" "$(cat <<'EOF'
char: 'A'
int: 65
float: 65.0f
double: 65.0
EOF
)"

# 127 is DEL, not displayable in most impls (isprint(127) == false)
run_case "127 (DEL, non-displayable)" "127" "$(cat <<'EOF'
char: Non displayable
int: 127
float: 127.0f
double: 127.0
EOF
)"

# 128 doesn't fit in signed char -> char impossible
run_case "128 (out of char range)" "128" "$(cat <<'EOF'
char: impossible
int: 128
float: 128.0f
double: 128.0
EOF
)"

# ------------------- int overflow (loose: just show) ------------------------
section "int overflow (loose check — verify by eye)"
run_case "INT_MAX 2147483647" "2147483647" "--"
run_case "INT_MAX+1 2147483648" "2147483648" "--"
run_case "INT_MIN -2147483648" "-2147483648" "--"
run_case "INT_MIN-1 -2147483649" "-2147483649" "--"

# ------------------- float literals -----------------------------------------
section "float literals"
run_case "0.0f (subject example)" "0.0f" "$(cat <<'EOF'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOF
)"

run_case "42.0f (subject example)" "42.0f" "$(cat <<'EOF'
char: '*'
int: 42
float: 42.0f
double: 42.0
EOF
)"

run_case "-4.2f" "-4.2f" "$(cat <<'EOF'
char: impossible
int: -4
float: -4.2f
double: -4.2
EOF
)"

run_case "4.2f" "4.2f" "$(cat <<'EOF'
char: Non displayable
int: 4
float: 4.2f
double: 4.2
EOF
)"

# ------------------- double literals ----------------------------------------
section "double literals"
run_case "0.0" "0.0" "$(cat <<'EOF'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOF
)"

run_case "-4.2" "-4.2" "$(cat <<'EOF'
char: impossible
int: -4
float: -4.2f
double: -4.2
EOF
)"

run_case "4.2" "4.2" "$(cat <<'EOF'
char: Non displayable
int: 4
float: 4.2f
double: 4.2
EOF
)"

# ------------------- pseudo literals (inf / nan) ----------------------------
section "pseudo literals (inf / nan)"
run_case "nan (subject example)" "nan" "$(cat <<'EOF'
char: impossible
int: impossible
float: nanf
double: nan
EOF
)"

run_case "nanf" "nanf" "$(cat <<'EOF'
char: impossible
int: impossible
float: nanf
double: nan
EOF
)"

run_case "+inf" "+inf" "$(cat <<'EOF'
char: impossible
int: impossible
float: +inff
double: +inf
EOF
)"

run_case "-inf" "-inf" "$(cat <<'EOF'
char: impossible
int: impossible
float: -inff
double: -inf
EOF
)"

run_case "+inff" "+inff" "$(cat <<'EOF'
char: impossible
int: impossible
float: +inff
double: +inf
EOF
)"

run_case "-inff" "-inff" "$(cat <<'EOF'
char: impossible
int: impossible
float: -inff
double: -inf
EOF
)"

# ------------------- precision edge cases (loose) ---------------------------
section "precision / formatting (loose check — design choice)"
run_case "1.234567f" "1.234567f" "--"
run_case "0.1" "0.1" "--"
run_case "1e10" "1e10" "--"
run_case "1e100" "1e100" "--"

# ------------------- float / double overflow --------------------------------
section "float / double overflow (loose)"
run_case "FLT_MAX-ish 3.4e38f" "3.4e38f" "--"
run_case "above FLT_MAX 1e40f" "1e40f" "--"
run_case "above DBL_MAX 1e400" "1e400" "--"

# ------------------- garbage input ------------------------------------------
section "garbage / impossible inputs"
run_case "empty string" "" "--"
run_case "two letters 'ab'" "ab" "--"
run_case "trailing junk '42abc'" "42abc" "--"
run_case "trailing junk '4.2x'" "4.2x" "--"
run_case "lone 'f'" "f" "--"
run_case "lone '.'" "." "--"
run_case "lone '-'" "-" "--"
run_case "spaces ' 42 '" " 42 " "--"

# ------------------- summary ------------------------------------------------
section "summary"
TOTAL=$((PASS + FAIL))
echo "${GREEN}passed:${RESET} $PASS / $TOTAL    ${RED}failed:${RESET} $FAIL    ${YELLOW}show-only:${RESET} $SKIP"
if [ "$FAIL" -gt 0 ]; then
    echo "${RED}failed cases:${RESET}"
    for c in "${FAILED_CASES[@]}"; do
        echo "  - $c"
    done
    [ "$STRICT" = "1" ] && exit 1
fi
exit 0
