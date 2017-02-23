#pragma once
#define _VECTOR_H_

namespace vector
{
	int* Create(const int n);
	void Delete(int *&arr);
	void Input(int *arr, const int n);
	void Output(const int *arr, const int n);
	void Add(int *arr, const int n, const int elem);
	void Invert(int *arr, const int n);
	int Sum(const int *arr, const int n);
	int* Add(const int *arr1, const int *arr2, const int n);
	int Multiplication(const int *arr1, const int *arr2, const int n);
}
namespace vec = vector;

#if !defined(_VECTOR_H_)
#include "vector.h"
#endif