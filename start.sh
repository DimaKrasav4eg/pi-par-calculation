#!/bin/bash

total_points=100000
draw=0
while [[ "$#" -gt 0 ]]; do
    case "$1" in
        -d|--draw)
            draw=1
            shift
            ;;
        -p|--points)
			if [[ -n "$2" ]]; then
                echo "Error: number of points not specified!"
                exit 1
            fi
			total_points=$2
			shift
			;;
        *) 
            echo "Invalid argument: $1"
            exit 1
            ;;
    esac
    shift
done


gcc -fopenmp -o pi_calc_lin.out pi_calc_lin.c
./pi_calc_lin.out $total_points

gcc -fopenmp -o pi_calc.out pi_calc.c
./pi_calc.out $total_points

if [ $draw -eq 1 ]; then
    python3 draw.py
fi
