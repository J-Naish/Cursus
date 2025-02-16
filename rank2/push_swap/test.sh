#!/bin/bash
random_numbers=$(seq -500 500 | shuf -n 10)
./push_swap $random_numbers
