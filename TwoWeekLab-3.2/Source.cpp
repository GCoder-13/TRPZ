#include <iostream>
#include <cmath>

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

void CountNegativeStrZero(int** A, const int n, const int m)
{
	bool check = false;
	for (int i(0); i < n; i++)
		for (int j(0); j < m; j++)
		{
			if (A[i][j] == 0)
			{
				check = true;
				int count = 0;
				cout << "String " << i + 1 << ": ";
				for (int q(0); q < m; q++)
					if (A[i][q] < 0)
						count++;
				cout << count << endl;
				break;
			}
		}
	if (!check)
		cout << "Such elements are missing." << endl;	// елементи (A[i][j] == 0) відсутні 
}

int ArrSumPluss(int** A, const int n, const int m)
{
	int sum = 0;
	bool sw = false;
	for (int i(0); i < n; i++)
		for (int j(0); j < m; j++)
		{
			if (A[i][j] > 0 && !sw)
			{
				sw = true;
			}
			else if (sw)
				sum += abs(A[i][j]);
		}
	return sum;
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

	cout << endl << "Sum array: " << ArrSumPluss(arr, n, m) << endl;

	ArrDelete(arr, n, m);
	system("pause");
	return NULL;
}