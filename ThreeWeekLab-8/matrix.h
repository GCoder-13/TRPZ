#pragma once
#pragma once
#define _MATRIX_H_

namespace matrix
{
	int** Create(const int n, const int m);
	void Delete(int **&arr, const int n);
	void Input(int **arr, const int n, const int m);
	void Output(const int **arr, const int n, const int m);
	void Add(int **arr, const int n, const int m, const int elem);
	int** Transpose(const int **arr, const int n, const int m);
	int** Add(const int **arr1, const int **arr2, const int n, const int m);
	int** Multiplication(const int **arr1, const int row1, const int col1, const int **arr2, const int col2);
}

#if !defined(_MATRIX_H_)
#include "vector.h"
#endif