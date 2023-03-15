
#include "matrix.h"
#include "math.h"
#include "constants.h"

void initDefaultMatrix(double** matrix, int n)
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

void initVectorB(double* vector, int n)
{
	for (int i = 0; i < n; i++)
	{
		vector[i] = n + 1;
	}
}

void initVectorX(double* vector, int n)
{
	for (int i = 0; i < n; i++)
	{
		vector[i] = 0.0;
	}
}


void calcIteration(double* resBuffer, double** matrix, double* vectorX, const double* vectorB, int n)
{
	double resultNum;
	for (int row = 0; row < n; row ++)
	{
		// Ax
		resultNum = multVectors(vectorX, matrix[row], n);
		// (Ax-b)
		resultNum = resultNum - vectorB[0];
		resBuffer[row] = resultNum;
	}

}

double euclideanNorm(double const* vector, int n)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += vector[i] * vector[i];
	}
	result = sqrt(result);
	return result;
}

int calcCriterion(double const* denominator, double const* vectorB, int n)
{
	double vectorBNorm = euclideanNorm(vectorB, n);
	double denominatorNorm = euclideanNorm(denominator, n);
	double crit = (denominatorNorm / vectorBNorm);
	//printf("Root: crit = %f , epsilon = %f\n", crit, EPSILON);
	if (crit < EPSILON)
		return 1;
	return 0;
}
