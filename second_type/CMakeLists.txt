cmake_minimum_required(VERSION 3.24)
project(openmp_lab2 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER gcc-12)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -Werror -Wall -O3 --std=c99 ")

add_executable(openmp_lab2 main.c matrix.c nonlinear_equation.c)
