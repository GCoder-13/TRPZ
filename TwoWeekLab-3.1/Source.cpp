#include <iostream>

using namespace std;

int ArrMin(const int* arr, const int n)
{
	int nMin = 0;
	for (int i(1); i < n; i++)
	{
		if (arr[nMin] > arr[i])
			nMin = i;
	}
	return nMin;
}

int main()
{
	int n;

	cout << "Enter the number of elements in the array: ";
	cin >> n;

	int *arr = new int[n];

	for (int i(0); i < n; i++)
	{
		cout << " >  ";
		cin >> arr[i];
	}

	int num, count = 0;
	cout << endl << "Enter number: ";
	cin >> num;

	for (int i(0); i < n; i++)
	{
		if (arr[i] > num)
			count++;
	}

	cout << count << " number of elements more than " << num << endl;

	int Dob = 1;
	for (int i(ArrMin(arr,n)); i < n; i++)
	{
		Dob *= arr[i];
	}

	cout << "Multiplication array: " << Dob << endl;

	delete[] arr;
	system("pause");
	return NULL;
}