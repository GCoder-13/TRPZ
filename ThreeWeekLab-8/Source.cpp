#include <iostream>
#include "matrix.h"
#include "vector.h"

using namespace std;
using namespace vec;
using namespace matrix;

int main(int argc, char **argv)
{
	int n, num;
/*//////////////////////////////////////// VECTOR \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	cout << "Enter size vector: ";
	cin >> n;
	int *vec1 = Create(n);
	Input(vec1, n);

	cout << endl << "Enter number for adding in vector: ";
	cin >> num;
	cout << "Sum vector and numver: ";
	Add(vec1, n, num);
	Output(vec1, n);

	cout << "Invert vector: ";
	Invert(vec1, n);
	Output(vec1, n);

	cout << "Sum elements vector: " << Sum(vec1, n) << endl;
	
	cout << "Enter new vector: " << endl;
	int *vec2 = Create(n);
	Input(vec2, n);

	int *vecRes = Add(vec1, vec2, n);
	cout << "Sum vectors: ";
	Output(vecRes, n);
	Delete(vecRes);

	cout << "Multiplication vectors: " << Multiplication(vec1, vec2, n) << endl;
	Delete(vec1);
	Delete(vec2);

	system("pause");
	system("cls");
/*//////////////////////////////////////////////////////////////////////////////////////////////*/

/*/////////////////////////////////////////// MATRIX \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	using matrix::Output;
	int m;
	cout << "Enter size matrix(n, m): ";
	cin >> n >> m;
	int **arr1 = Create(n, m);
	Input(arr1, n, m);

	cout << "Enter number for adding in matrix: ";
	cin >> num;
	cout << "Matrix:" << endl;
	Add(arr1, n, m, num);
	Output(arr1, n, m);

	cout << "Transpouse matrix:" << endl;
	int **arr1T = Transpose(arr1, n, m);
	Output(arr1T, m, n);

	cout << "Sum elements matrix: " << matrix::Sum(arr1, n, m) << endl;

	int **arr2 = Create(n, m);
	cout << "Enter new matrix:" << endl;
	Input(arr2, n, m);

	cout << "Adding matrix:" << endl;
	int **arrRes = Add(arr1, arr2, n, m);
	Output(arrRes, n, m);
	Delete(arrRes, n);

	cout << "Multiplication matrix: " << endl;
	matrix::Multiplication(arr1T, m, n, arr2, m);
	Delete(arr1T, n);
	Delete(arr2, n);

	cout << "Multiplication matrix on vector: " << endl;
	cout << "Enter vector: " << endl;
	vec1 = Create(m);
	Input(vec1, m);
	vec2 = Multiplication(vec1, arr1, n, m);
	cout << "Multiplication: ";
	vec::Output(vec2, n);
	Delete(vec1);
	Delete(vec2);
	Delete(arr1, n);

	system("pause");
	return 0;
}