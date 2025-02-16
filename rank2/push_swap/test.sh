#!/bin/bash
random_numbers=$(seq -500 500 | shuf -n 100)
./push_swap $random_numbers
