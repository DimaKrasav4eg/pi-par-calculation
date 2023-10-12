#!/bin/bash

readonly total_points=100000

gcc -fopenmp -o pi_calc_lin.out pi_calc_lin.c
./pi_calc_lin.out $total_points

gcc -fopenmp -o pi_calc.out pi_calc.c
./pi_calc.out $total_points

python3 draw.py