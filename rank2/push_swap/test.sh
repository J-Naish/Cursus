#!/bin/bash
random_numbers=$(seq -500 500 | shuf -n 5)
./push_swap $random_numbers
