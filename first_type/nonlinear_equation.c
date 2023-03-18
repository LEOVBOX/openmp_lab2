#include "matrix.h"
#include "math.h"
#include "constants.h"

void init_default_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 2;
			}
			else
				matrix[i][j] = 1;
		}
	}
}

void init_vector_b(double* vector, int n)
{
	for (int i = 0; i < n; i++)
	{
		vector[i] = n + 1;
	}
}

void init_vector_x(double* vector, int n)
{

	for (int i = 0; i < n; i++)
	{
		vector[i] = 0.0;
	}
}


void calc_iteration(double* resBuffer, double** matrix, double* vectorX, const double* vectorB, int n)
{
	double resultNum;
	#pragma omp parallel default(none) shared(resBuffer, matrix, vectorX, vectorB, n) private(resultNum)
	{
		#pragma omp for
		for (int row = 0; row < n; row++)
		{
			// Ax
			resultNum = mult_vectors(vectorX, matrix[row], n);
			// (Ax-b)
			resultNum = resultNum - vectorB[0];
			resBuffer[row] = resultNum;
		}
	}

}

double euclidean_norm(double const* vector, int n)
{
	double result = 0;
	int i;
	#pragma omp parallel default(none) shared(n, i, result, vector)
	{
		#pragma omp for
		for (i = 0; i < n; i++)
		{
			result += vector[i] * vector[i];
		}
	}
	result = sqrt(result);
	return result;
}

int calc_criterion(double const* denominator, double b_norm, int n)
{
	// Norm(Ax - b)
	double denominator_norm = euclidean_norm(denominator, n);
	double crit = (denominator_norm / b_norm);
	if (crit < EPSILON)
		return 1;
	return 0;
}
