#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void ArrOutput(const int *arr, const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << setw(6);
}

/* Копіювання елементів першого масиву до другого у зворотному порядку */
void ArrBackCopy(const int* arr1, int* arr2, const int n)
{
	for (int i = n - 1, j = 0; i >= 0 && j < n; i--, j++)
		arr2[j] = arr1[i];
}

/* Знайти номер та значення максимального елементу масиву */
void ArrMaxElem(const int *arr, const int n)
{
	int indexMax = 0;
	for (int i = 0; i < n; i++)
		if (arr[indexMax] < arr[i])
			indexMax = i;
	cout << "Max = Element[" << indexMax << "] = " << arr[indexMax] << endl;
}

/* Визначити суму елементів з непарними номерами */
int ArrSumOddElem(const int *arr, const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (i & 1)
			sum += arr[i];
	return sum;
}

int**& ArrCreate(const int n, const int m)
{
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	return arr;
}

void ArrDelete(int **&arr,const int n)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}

void ArrRecordRand(int **arr, const int n, const int m)
{
	random_device random;
	uniform_int_distribution<int> rd(-10, 10);
	for(int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rd(random);
}

void ArrOutput(int **arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << '\t';
		ArrOutput(arr[i], m);
		cout << endl;
	}
}

/* Заповнити матрицю нулями над головною діагоналлю */
bool ArrZeroOverDiagonal(int **arr, const int n, const int m)
{
	int indexZero = 0;
	if (n != m)
		return false;
	for (int i = 0; i < n; i++)
		for (int j = ++indexZero; j < m; j++)
			arr[i][j] = 0;
	return true;
}

/* Обчислити суми елементів в стовпчиках */
void ArrSumCol(int **arr, const int n, const int m)
{
	int sum = 0;
	for(int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
			sum += arr[i][j];
		cout << "Sum elements " << j + 1 << " column: " << sum << endl;
		sum = 0;
	}
}

int main()
{
	const int arr1[] = { 1, 2, 3, 4, 9, 6, 7, 8, 5 };
	const int N = 9;
	int arr2[N];

	cout << "Array 2:  ";
	ArrBackCopy(arr1, arr2, N);
	ArrOutput(arr2, N);

	cout << endl << endl;
	ArrMaxElem(arr2, N);

	cout << endl << "Sum odd elements array: " << ArrSumOddElem(arr2, N) << endl << endl
		<< "-----------------------------------------------------------" << endl << endl;

	int n, m;
	cout << "Enter size array [n, m]: ";
	cin >> n >> m;
	int **arr3 = ArrCreate(n, m);
	
	ArrRecordRand(arr3, n, m);
	cout << endl << "Array Rand:" << endl;
	ArrOutput(arr3, n, m);

	cout << endl << "Array zero over diagonal:" << endl;
	if (!ArrZeroOverDiagonal(arr3, n, m))
		cout << "Matrix is not square" << endl;
	else ArrOutput(arr3, n, m);

	cout << endl << "Sum columns:" << endl;
	ArrSumCol(arr3, n, m);

	ArrDelete(arr3, n);
	system("pause");
    return 0;
}