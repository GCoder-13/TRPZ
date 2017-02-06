#include <iostream>

using namespace std;

int main()
{
	int a, max, min;
	bool check = true;

	while ((cout << " >  ", cin >> a) && (a != 0))
	{
		if (check)
		{
			max = a;
			min = a;
			check = false;
			continue;
		}
		max = (a >= max) ? a : max;
		min = (a <= min) ? a : min;
	}

	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;

	system("pause");
	return NULL;
}