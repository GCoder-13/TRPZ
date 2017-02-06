#include <iostream>

using namespace std;

int main()
{
	int num, i;
	cout << "Enter number: ";
	cin >> num;
	i = num;

	while (i >= -num)
	{
		if (i != 0 && !(num%i))
			cout << i << "\t";
		i--;
	}

	cout << endl;
	system("pause");
	return NULL;
}