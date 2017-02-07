#include <iostream>

using namespace std;

int**& ArrCreate(const int n, const int m)
{
	int **A = new int*[n];
	for (int i(0); i < n; i++)
		A[i] = new int[m];
	return A;
}

void ArrDelete(int**& A, const int n, const int m)
{
	for (int i(0); i < n; i++)
		delete[] A[i];
	delete[] A;
}

void ArrInput(int**& A, const int n, const int m)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			cout << " >  ";
			cin >> A[i][j];
		}
		cout << "==============" << endl;
	}
}

void ArrOutput(const int** A, const int n, const int m)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			cout << A[i][j] << '\t';
		}
		cout << endl;
	}
}

void CountNegativeStrZero(int** A, const int n, const int m)
{
	for (int i(0); i < n; i++)
		for (int j(0); j < m; j++)
		{
			int count = 0;
			if (A[i][j] == 0)
			{
				cout << "String " << i + 1 << ": ";
				for (int q(0); q < m; q++)
					if (A[i][q] < 0)
						count++;
				cout << count << endl;
			}
		}
}

int main()
{
	int n, m;
	cout << "Enter size matrix (n, m): ";
	cin >> n >> m;
	int** arr = ArrCreate(n, m);
	ArrInput(arr, n, m);
	
	cout << "Number of negative elements:" << endl;
	CountNegativeStrZero(arr, n, m);
	cout << endl;

	ArrDelete(arr, n, m);
	system("pause");
	return NULL;
}