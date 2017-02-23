#include "matrix.h"
#include <iostream>

using namespace std;

int * matrix::Create(const int n)
{
	int *arr = new int[n];
	return arr;
}

int ** matrix::Create(const int n, const int m)
{
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = Create(m);
	return arr;
}

void matrix::Delete(int *& arr)
{
	delete[] arr;
}

void matrix::Delete(int **& arr, const int n)
{
	for (int i = 0; i < n; i++)
		Delete(arr[i]);
	Delete(*arr);
}

void matrix::Input(int * arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " >  ";
		cin >> arr[i];
	}
}

void matrix::Input(int ** arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			Input(arr[i], m);
		cout << endl << "------------------------------" << endl << endl;
	}
}

void matrix::Add(int * arr, const int n, const int elem)
{
	for (int i = 0; i < n; i++)
		arr[i] += elem;
}

void matrix::Add(int ** arr, const int n, const int m, const int elem)
{
	for (int i = 0; i < n; i++)
		Add(arr[i], m, elem);
}
