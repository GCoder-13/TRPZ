#include <iostream>

using namespace std;

int main()
{
	int i = 0, a, max;

	while ((cout << " >  ", cin >> a) && (a != 0))
	{
		if (!i)
		{
			max = a;
			continue;
		}
		else max = (a > max) ? a : max;
	}

	cout << "Max = " << max << endl;

	system("pause");
	return NULL;
}