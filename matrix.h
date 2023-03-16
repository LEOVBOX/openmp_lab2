//
// Created by Леонид Шайхутдинов on 22.02.2023.
//

#ifndef MPI_LAB1_MATRIX_H
#define MPI_LAB1_MATRIX_H

void scanf_array(double *array, int *n);
void scanfMatrix(double **matrix, int *n);
void print_array(double *array, int n);
void fprint_array(char* file_path, double *array, int n);
void printMatrix(double **matrix, int n);
double mult_vectors(double *row, double *column, int n);
double* multMatrixByVector(double **matrix, double *vector, double *result, int *n);
double* vectorSub(double *vector1, double const *vector2, int const *n);
double** malloc_matrix(int n);

#endif //MPI_LAB1_MATRIX_H
