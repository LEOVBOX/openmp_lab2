//
// Created by Леонид Шайхутдинов on 25.02.2023.
//

#ifndef OPENMP_LAB2_NONLINEAR_EQUATION_H
#define OPENMP_LAB2_NONLINEAR_EQUATION_H

#include <stdio.h>

// Инициализирует матрицу с главной диагональю равной 2. Остальные значения равны 1.
void init_default_matrix(double** matrix, int n);
void init_vector_x(double *vector, int n);
void init_vector_b(double *vector, int n);
void calc_iteration(double* resBuffer, double** matrix, double* vectorX, const double* vectorB, int n);
int calc_criterion(double const* denominator, double b_norm, int n);
double euclidean_norm(double const* vector, int n);

#endif