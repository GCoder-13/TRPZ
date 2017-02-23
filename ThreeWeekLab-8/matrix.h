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
	void Transpon(int *arr, const int n);
	void Transpon(int **arr, const int n, const int m);
}

#if !defined(_MATRIX_H)
#include "vector.h"
#endif