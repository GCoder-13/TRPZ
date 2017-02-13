#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	const int a = 10;
	int b = 4;
	const float Pi = 3.13159;
	const char* ch = "Hello World!!!";
	bool sw = true;
	
	cout << "a = " << a << ",\t b = " << b << endl;
	cout << "Rezulp (b+a): " << b + a << endl;					//14
	cout << "Rezulp (b-a): " << b - a << endl;					//-6
	cout << "Rezulp (b / Pi): " << b / Pi << endl;				//1.27324
	cout << "Rezulp (b * Pi): " << b * Pi << endl;				//12.56636
	cout << "Rezulp (b % 2): " << b % 2 << endl;				//0
	cout << "Rezulp (++b): " << ++b << endl;					//5
	cout << "Rezulp (--b): " << --b << endl;					//4
	cout << "Rezulp (b << 1): " << (b << 1) << endl;			//8 (bin = 1000)
	cout << "Rezulp (b >> 2): " << (b >> 2) << endl;			//1 (bin = 1)
	cout << "Rezulp (b > a): " << ((b > a) ? b : a) << endl;	//10
	cout << "Rezulp (b += a): " << (b += a) << endl;			//14
	cout << "Rezulp (b -= a): " << (b -= a) << endl;			//4
	cout << "Rezulp (b &= a): " << (b &= a) << endl;			//0 (0100 & 1010 = 0)
	cout << "Rezulp (b |= a): " << (b |= a) << endl;			//10 (0 | 1010 = 1010)
	cout << "Rezulp (b ^= a): " << (b ^= a) << endl;			//0 (1010 ^ 1010 = 0)
	cout << "Rezulp (sizeof(b)): " << sizeof(b) << endl;		//4 byte

	double y, sum = 0;
	for (int x(-20); x <= 10; x++)
	{
		y = pow(x, 4) - 10.2*pow(x, 3) - pow(x, 2) + 2.1*x + 37.7;
		if (y < 2 * x)
			sum += y;
	}

	cout << endl << "Sum = " << sum << endl;

	system("pause");
	return NULL;
}