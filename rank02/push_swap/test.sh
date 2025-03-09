#!/bin/bash
for i in {1..100}
do
	random_numbers=$(seq -500 500 | shuf -n 100)
	./push_swap $random_numbers | wc -l
done