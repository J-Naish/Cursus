#!/bin/bash
random_numbers=$(seq -500 500 | shuf -n 500)
echo "$random_numbers"
./push_swap $random_numbers
