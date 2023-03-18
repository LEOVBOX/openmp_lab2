#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include "matrix.h"
#include "nonlinear_equation.h"
#include "constants.h"


int main()
{
	double start_time = omp_get_wtime();

	double* vector_b = (double*)malloc(sizeof(double) * N_NUM);
	init_vector_b(vector_b, N_NUM);

	double* vector_x = (double*)malloc(sizeof(double) * N_NUM);
	init_vector_x(vector_x, N_NUM);

	double** matrix = malloc_matrix(N_NUM);
	init_default_matrix(matrix, N_NUM);

	// Вектор для хранения результата (Ax - b)
	double* result = (double*)malloc(sizeof(double) * N_NUM);

	double b_norm = euclidean_norm(vector_b, N_NUM);


	int crit = 0;
	while (crit == 0)
	{
		#pragma omp parallel default(none) shared(result, matrix, vector_x, vector_b, b_norm, crit)
		{
			calc_iteration(result, matrix, vector_x, vector_b, N_NUM);
			crit = calc_criterion(result, b_norm, N_NUM);
			for (int i = 0; i < N_NUM; i++)
			{
				result[i] *= TAU;
				vector_x[i] -= result[i];
			}
		}

	}

	//print_array(result, N_NUM);
	fprint_array("./result.txt", result, N_NUM);

	free(result);

	for (int i = 0; i < N_NUM; i++)
		free(matrix[i]);
	free(matrix);

	free(vector_x);
	free(vector_b);

	double end_time = omp_get_wtime();

	printf("Time: %f\n", end_time - start_time);
	return 0;
}
