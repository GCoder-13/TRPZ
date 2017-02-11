#include <iostream>
#include <cmath>
#include <iomanip>

#define PAUSE system("pause")

using namespace std;

int main()
{
	int a, b, c;
	double F, step, start, finish;
	cout << "Enter a, b, c: ";
	cin >> a >> b >> c;
	cout << "Enter start and finish: ";
	cin >> start >> finish;
	cout << "Enter step: ";
	cin >> step;
	if (start >= finish || step == 0)
	{
		cout << "Error! " << endl << "Finish <= Start or Step == 0" << endl;
		PAUSE;
		return NULL;
	}
	
	cout << endl << setw(7) << "X" << setw(7) << '|' << setw(7) << "F" << endl;
	cout << "---------------------------" << endl;
	for (double x = start; x <= finish; x += step)
	{
		if (x + c < 0 && a != 0)
			F = -a*pow(x, 3) - b;
		else if (x + c > 0 && a == 0)
			if (x - c == 0)
			{
				cout << setw(9) << x << setw(5) << '|' << setw(10) << " ---- " << endl;
				continue;
			}
			else F = (x - a) / (x - c);
		else if (x == 0)
		{
			cout << setw(9) << x << setw(5) << '|' << setw(10) << " ---- " << endl;
			continue;
		}
		else F = x / c + c / x;

		if (a + b != 0 || a + c != 0)
			cout << setw(9) << setprecision(3) << x << setw(5) << '|' << setw(12) << F << endl;
		else cout << setw(9) << setprecision(3) << x << setw(5) << '|' << setw(12) << setprecision(0) << F << endl;
	}

	PAUSE;
	return NULL;
}