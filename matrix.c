//
// Created by Леонид Шайхутдинов on 16.02.2023.
//

#include <stdio.h>
#include <stdlib.h>


void print_array(double *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%f\n", array[i]);
	}
	printf("\n");
}

void fprint_array(char* file_path, double *array, int n)
{
	FILE* file = fopen(file_path, "w+");
	if (file == NULL)
	{
		printf("Cannot open file %s\n", file_path);
		exit(2);
	}

	for (int i = 0; i < n; i++)
	{
		fprintf(file, "%f\n", array[i]);
	}
}

void printMatrix(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		print_array(matrix[i], n);
	}
}

double mult_vectors(double *row, double *column, int n)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += (row[i] * column[i]);
	}
	return result;
}

double **malloc_matrix(int n)
{
	double** matrix = (double**)malloc(sizeof(double*) * n);
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (double*)malloc(sizeof(double) * n);
	}
	return matrix;
}



//double* paralleMultlMatrixByVector()