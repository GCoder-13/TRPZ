#pragma once
#define _MATRIX_H_

namespace matrix
{
	int** Create(const int n, const int m);
	void Delete(int **&arr, const int n);
	void Input(int **arr, const int n, const int m);
	void Output(int **arr, const int n, const int m);
	void Add(int **arr, const int n, const int m, const int elem);
	int** Transpose(int **arr, const int n, const int m);
	int Sum(int **arr, const int n, const int m);
	int** Add(int **arr1, int **arr2, const int n, const int m);
	int** Multiplication(int **arr1, const int row1, const int col1, int **arr2, const int col2);
	int* Multiplication(int *vec, int **arr, const int n, const int m);
}

#if !defined(_MATRIX_H_)
#include "vector.h"
#endif