#include "vector.h"
#include <iostream>
#include <iomanip>

using namespace std;

int * vector::Create(const int n)
{
	int *arr = new int[n];
	return arr;
}

void vector::Delete(int *& arr)
{
	delete[] arr;
}

void vector::Input(int * arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " >  ";
		cin >> arr[i];
	}
}

void vector::Output(const int *arr, const int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << arr[i];
	cout << endl;
}

void vector::Add(int * arr, const int n, const int elem)
{
	for (int i = 0; i < n; i++)
		arr[i] += elem;
}

void vector::Invert(int * arr, const int n)
{
	int temp;
	for (int i = 0; i < n/2; i++)
	{
		temp = arr[n - i - 1];
		arr[n - i - 1] = arr[i];
		arr[i] = temp;
	}
}

int vector::Sum(const int * arr, const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

int * vector::Add(const int * arr1, const int * arr2, const int n)
{
	int *res = Create(n);
	for (int i = 0; i < n; i++)
		res[i] = arr1[i] + arr2[i];
	return res;
}

int vector::Multiplication(const int *arr1, const int *arr2, const int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res += arr1[i] * arr2[i];
	return res;
}
