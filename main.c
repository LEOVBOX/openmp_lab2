#include <stdio.h>
#include "matrix.h"
#include "mm_malloc.h"
#include "nonlinear_equation.h"
#include "constants.h"

#pragma omp parallel

int main()
{

	double* vectorB = (double*)malloc(sizeof(double) * N_NUM);
	initVectorB(vectorB, N_NUM);

	double* vectorX = (double*)malloc(sizeof(double) * N_NUM);
	initVectorX(vectorX, N_NUM);

	double** matrix = mallocMatrix(N_NUM);
	initDefaultMatrix(matrix, N_NUM);

	// Вектор для хранения результата (Ax - b)
	double* result = (double*)malloc(sizeof(double) * N_NUM);

	int crit = 0;
	while (crit == 0)
	{

		calcIteration(result, matrix, vectorX, vectorB, N_NUM);
		crit = calcCriterion(result, vectorB, N_NUM);

		for (int i = 0; i < N_NUM; ++i)
		{
			result[i] *= TAU;
			vectorX[i] -= result[i];
		}
	}

	printArray(result, N_NUM);

	free(result);
	for (int i = 0; i < N_NUM; i++)
		free(matrix[i]);
	free(matrix);

	free(vectorX);
	free(vectorB);
	return 0;
}
