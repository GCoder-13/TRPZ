#include <iostream>
#include "matrix.h"
#include "vector.h"

using namespace std;

int main(int argc, char **argv)
{
	vec::Vector vec1;
	cout << "Enter vector vec1(x, y): ";
	cin >> vec1.x >> vec1.y;

	int num;
	cout << "Enter number: ";
	cin >> num;
	Add(vec1, num);
	cout << "vec1 + number = ";
	Output(vec1);
	cout << "Inver vector: ";
	Invert(vec1);
	cout << "Vector: ";
	Output(vec1);
	cout << "Sum elements vector: " << Sum(vec1) << endl;
	vec::Vector vec2;
	cout << "Enter vector vec2(x, y): ";
	cin >> vec2.x >> vec2.y;
	cout << "vec1 + vec2 =  ";
	Output(Add(vec1, vec2));
	cout << "vec1 * vec2 = " << Multiplication(vec1, vec2) << endl;



	system("pause");
	return 0;
}