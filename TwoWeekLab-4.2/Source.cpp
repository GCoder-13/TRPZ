#include <iostream>

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
}

int main()
{
	int n;
	cout << "Enter size matrix (n, m): ";
	cin >> n;
	int** arr = ArrCreate(n);
	ArrInput(arr, n);

	

	ArrDelete(arr, n, m);
	system("pause");
	return NULL;
}