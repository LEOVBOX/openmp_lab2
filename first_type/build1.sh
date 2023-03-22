#!/bin/bash
set -x

gcc -std=gnu99 -O3 -Wpedantic -Wall -Werror -fopenmp -o prog1 main.c nonlinear_equation.c matrix.c -lm
