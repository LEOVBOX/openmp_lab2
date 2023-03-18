cmake_minimum_required(VERSION 3.24)
project(openmp_lab2 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-gcc-12")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -w")

add_executable(openmp_lab2 main.c matrix.c nonlinear_equation.c)
