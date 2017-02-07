#include <iostream>
#include <cmath>

using namespace std;

void ArrInput(int*& A, const int n)
{
	for (int i(0); i < n; i++)
	{
		cout << " >  ";
		cin >> A[i];
	}
}

int CountMore(const int* A, const int n, const int num)
{
	int count = 0;

	for (int i(0); i < n; i++)
	{
		if (A[i] > num)
			count++;
	}

	return count;
}

int ArrMinN(const int* A, const int n)
{
	int nMin = 0;
	for (int i(1); i < n; i++)
	{
		if (A[nMin] > A[i])
			nMin = i;
	}
	return nMin;
}

int ArrDobutNMin(const int* A, const int n, const int NMin)
{
	int Dob = 1;
	for (int i(NMin + 1); i < n; i++)
	{
		Dob *= A[i];
	}

	if (NMin + 1 == n)
		return NULL;

	return Dob;
}

void ArrSort(int*& A, const int n)
{
	for (int i(0); i < n; i++)
	{
		int temp = A[i], j;
		for (j=i - 1; j >= 0 && abs(A[j]) > abs(temp); j--)
			A[j + 1] = A[j];
		A[j+1] = temp;
	}
}

void ArrOutput(const int* A, const int n)
{
	for (int i(0); i < n; i++)
		cout << A[i] << '\t';
}

int main()
{
	int n;
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	if (n == 0)
	{
		cout << "Error! " << endl << "Incorrect input." << endl;
		system("pause");
		return NULL;
	}

	int *arr = new int[n];
	ArrInput(*&arr, n);

	int num;
	cout << endl << "Enter number: ";
	cin >> num;

	if (!CountMore(arr,n,num))
		cout << "This elements do not search." << endl;
	else cout << CountMore(arr, n, num) << " elements more than " << num << endl;

	if (ArrDobutNMin(arr, n, ArrMinN(arr, n)))
		cout << "Multiplication elements if then min: " << ArrDobutNMin(arr, n, ArrMinN(arr, n)) << endl;
	else cout << "Min element is end." << endl;

	cout << endl << "Sort array:" << endl;
	ArrSort(arr, n);
	ArrOutput(arr, n);
	cout << endl;

	delete[] arr;
	system("pause");
	return NULL;
}