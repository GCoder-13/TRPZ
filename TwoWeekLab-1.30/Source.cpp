#include <iostream>

using namespace std;

int main()
{
	int num, i;
	cout << "Enter number: ";
	cin >> num;
	if (!num)
	{
		cout << "Divide by zero!" << endl;
		system("pause");
		return NULL;
	}
	if (num < 0)
		num = -num;
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