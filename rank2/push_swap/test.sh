#!/bin/bash
random_numbers=$(seq -500 500 | shuf -n 500)
./push_swap $random_numbers
