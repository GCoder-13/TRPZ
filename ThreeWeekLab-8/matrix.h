#pragma once
#pragma once
#define _MATRIX_H

namespace matrix
{
	int* Create(const int n);
	int** Create(const int n, const int m);
	void Delete(int *&arr);
	void Delete(int **&arr, const int n);
	void Input(int *arr, const int n);
	void Input(int **arr, const int n, const int m);
	void Add(int *arr, const int n, const int elem);
	void Add(int **arr, const int n, const int m, const int elem);
	int** Transpose(const int **arr, const int n, const int m);
	int** Add(const int **arr1, const int **arr2, const int n, const int m);
	int** Multiplication(const int **arr1, const int row1, const int col1, const int **arr2, const int col2);
}

#if !defined(_MATRIX_H)
#include "vector.h"
#endif