#include <iostream>
#include <iomanip>

using namespace std;

int**& ArrCreate(const int n)
{
	int **A = new int*[n];
	for (int i(0); i < n; i++)
		A[i] = new int[n];
	return A;
}

void ArrDelete(int**& A, const int n)
{
	for (int i(0); i < n; i++)
		delete[] A[i];
	delete[] A;
}

void ArrInput(int**& A, const int n)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			cout << " >  ";
			cin >> A[i][j];
		}
		cout << "==============" << endl;
	}
	system("cls");
}

void ArrOutput(int** A, const int n)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
			cout << setw(5) << A[i][j] << "   |";
		cout << endl;
	}
}

int RowSum(int** A, const int n, const int i)
{
	int sum = 0;
	for (int j(0); j < n; j++)
		sum += A[i][j];
	return sum;
}

int ColumSum(int** A, const int n, const int j)
{
	int sum = 0;
	for (int i(0); i < n; i++)
		sum += A[i][j];
	return sum;
}

void CheckSum(int** A, const int n)
{
	bool found = false;
	for(int i(0); i < n; i++)
		for (int j(0); j < n; j++)
		{
			if (RowSum(A, n, i) == ColumSum(A, n, j))
			{
				found = true;
				cout << "The sum of elements row " << i + 1 << " = " << "sum of elements colum " << j + 1 << endl;
			}
		}
	if (!found)
		cout << "These elements not found" << endl;
}

void RowSumNotZero(int** A, const int n)
{
	bool found = false;
	for (int i(0); i < n; i++)
	{
		int sum = 0, notZero = 0;
		for (int j(0); j < n; j++)
		{
			sum += A[i][j];
			if(A[i][j] != 0)
				notZero++;
		}
		if (notZero >= 2)
		{
			found = true;
			cout << "\t Row " << i + 1 << ": " << sum << endl;
		}
	}
	if(!found)
		cout << "These elements not found" << endl;
}

int main()
{
	int n;
	cout << "Enter size matrix (n, n): ";
	cin >> n;
	int** arr = ArrCreate(n);
	ArrInput(arr, n);

	ArrOutput(arr, n);
	cout << endl << "The sum of elements row = sum elements colum: " << endl;
	CheckSum(arr, n);
	
	cout << endl << "The sum of elements rows:" << endl;
	RowSumNotZero(arr, n);

	ArrDelete(arr, n);
	system("pause");
	return NULL;
}