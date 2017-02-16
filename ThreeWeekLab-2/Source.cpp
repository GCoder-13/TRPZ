#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* Функція обчислення суми елементів діапазону[a, b]. */
int Sum(int a, int b)
{
	int sum = 0;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i(a); i <= b; i++)
	{
		sum += i;
	}
	return sum;
}

/* Функція обчислення добутку елементів діапазону [a,b]. */
double Dobut(double a, double b)
{
	int dob = 1;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i(a); i <= b; i++)
	{
		dob *= i;
	}
	return dob;
}

typedef unsigned long long ull;
/* Функція обчислення факторіалу числа. */
ull Factorial(long n)
{
	if (n >= 0)
	{
		if (n == 0)
			return 1;
		return n*Factorial(n - 1);
	}
	else return NULL;
}

/* Функція знаходження мінімального елементу ряду */
int Min(int* arr, const int n)
{
	int min = 0;
	for (int i(1); i < n; i++)
	{
		if (arr[min] > arr[i])
			min = i;
	}
	return min;
}

/* Функція обчислення суми послідовності: y = 0.01*exp(-0.5*x) + 0.05*x^3 при x = (-10..20); y < 0 || y > 90 */
double SumOrder(const int st = -10, const int fn = 20)
{
	double y, sum = 0;
	for (int x(st); x <= fn; x++)
	{
		y = 0.01 * exp(-0.5 * x) + 0.05*pow(x, 3);
		if (y < 0 || y > 90)
			sum += y;
	}
	return sum;
}

/* Реалізувати макровизначення та застосувати їх у програмі для визначення операцій. */
#define PLUS +
#define MINUS -
#define STAR *
#define SLASH /
#define RIGHT >>
#define AMP &
#define RATE %
#define Addition(a, b) (a PLUS b)
#define Subtraction(a, b) (a MINUS b)
#define Multiplication(a, b) (a STAR b)
#define Division(a, b) (a SLASH b)
#define LandslideRight(a, b) (a RIGHT b)
#define BinMultiplication(a, b) (a AMP b)
#define BalanceDivision(a, b) (a RATE b)

int MyFunction(int var, ...)
{
	va_list ptr;
	int rez = 0;
	__crt_va_start(ptr, var);
	char temp = __crt_va_arg(ptr, char);
	for (; var; var = __crt_va_arg(ptr, char))
	{
		if (var == '+')

			temp = var;
	}
	__crt_va_end(ptr);
	return rez;
}

int main(int argc, char** argv)
{
#define CHECK 1
	int a, b;
	cout << "Enter a, b: ";
	cin >> a >> b;

	cout << endl << MyFunction(5, '+', 2, '+', 3) << endl;

#if CHECK
	cout << "a + b = " << Addition(a, b) << endl;
	cout << "a - b = " << Subtraction(a, b) << endl;
	cout << "a * b = " << Multiplication(a, b) << endl;
	cout << "a / b = " << Division(a, b) << endl;
	cout << "Division[a, b]: " << Dobut(a, b) << endl;
	cout << "Sum Order: " << SumOrder() << endl;
#else
	const int n = 5;
	int arr[n] = { 1,2,-3,4,5 };
	cout << "Min element array: " << Min(arr, n) << endl;
	cout << "Sum[a, b]: " << Sum(a, b) << endl;
	cout << "a!: " << Factorial(a) << endl;
	cout << "a >> 1 = " << LandslideRight(a, 1) << endl;
	cout << "a & b = " << BinMultiplication(a, b) << endl;
	cout << "a % b = " << BalanceDivision(a, b) << endl;
#endif
	system("pause");
	return NULL;
}