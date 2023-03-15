//
// Created by Леонид Шайхутдинов on 25.02.2023.
//

#ifndef OPENMP_LAB2_NONLINEAR_EQUATION_H
#define OPENMP_LAB2_NONLINEAR_EQUATION_H

#include <stdio.h>

// Инициализирует матрицу с главной диагональю равной 2. Остальные значения равны 1.
void initDefaultMatrix(double** matrix, int n);
void initVectorX(double *vector, int n);
void initVectorB(double *vector, int n);
void calcIteration(double* resBuffer, double** matrix, double* vectorX, const double* vectorB, int n);
int calcCriterion(double const* denominator, double const* vectorB, int n);
double euclideanNorm(double const* vector, int n);

#endif