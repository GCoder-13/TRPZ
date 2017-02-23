#include "matrix.h"
#include "vector.h"
#include <iostream>

using namespace std;

int ** matrix::Create(const int n, const int m)
{
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = vec::Create(m);
	return arr;
}

void matrix::Delete(int **& arr, const int n)
{
	for (int i = 0; i < n; i++)
		vec::Delete(arr[i]);
	delete[] arr;
}

void matrix::Input(int ** arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			vec::Input(arr[i], m);
		cout << endl << "------------------------------" << endl << endl;
	}
}

void matrix::Output(const int ** arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
		vec::Output(arr[i], m);
}

void matrix::Add(int ** arr, const int n, const int m, const int elem)
{
	for (int i = 0; i < n; i++)
		vec::Add(arr[i], m, elem);
}

int ** matrix::Transpose(const int ** arr, const int n, const int m)
{
	int **tr = Create(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tr[i][j] = arr[j][i];
	return tr;
}

int** matrix::Add(const int **arr1, const int **arr2, const int n, const int m)
{
	int **res = Create(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = arr1[i][j] + arr2[i][j];
	return res;
}

int ** matrix::Multiplication(const int ** arr1, const int row1, const int col1, const int ** arr2, const int col2)
{
	int **res = Create(row1, col2);
	for (int i = 0; i < row1; i++)
		for (int j = 0; j < col2; j++)
			for (int z; z < row1; z++)
				res[i][j] += arr1[i][z] * arr2[z][j];
	return res;
}
