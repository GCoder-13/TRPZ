#include <iostream>

using namespace std;

int main()
{
	int num, i = 0, w = 0;;
	cout << "Enter number: ";
	cin >> num;
	cout << endl;

	while (i <= 1000)
	{
		if (!(i % num))
		{
			w++;
			cout << "\t" << i;
			if (w == 3)
			{
				w = 0;
				cout << endl;
			}
		}
		i++;
	}
	cout << endl;

	system("pause");
	return NULL;
}