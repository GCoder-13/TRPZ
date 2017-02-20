#include <iostream>
#include <string>
#include <random>

using namespace std;

enum days_of_week { Mon, Tue, Wed, Thu, Fri, Sat, Sun};
union MyUnion
{
	char Ch;
	int Int;
	unsigned int UInt;
	short Short;
	float Float;
	long Long;
	string* String;
};

int main()
{
	days_of_week day1, day2;
	day1 = Mon;
	day2 = Thu;
	int diff = day2 - day1;
	cout << "day1: Mon\tday2: Thu" << endl;
	cout << "The difference in days: " << diff << endl;
	if (day1 < day2)
		cout << "\tday1 < day2" << endl;
	else cout << "\tday1 > day2" << endl;
	cout << endl << "-------------------------------------------" << endl << endl;

	const int MAX = 15;
	MyUnion myTypes[MAX];
	random_device random;
	long long llInt = 0;
	unsigned long long ullInt = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (i == 0 || i % 3 == 0)
		{
			uniform_int_distribution<int> rd(0, 255);
			myTypes[i].Ch = rd(random);
			cout << "Char: " << myTypes[i].Ch << endl;
		}
		else if (i == 1 || ((i - 1) % 3) == 0)
		{
			uniform_int_distribution<int> rd(-2147483647, 2147483647);
			myTypes[i].Int = rd(random);
			cout << "Int: " << myTypes[i].Int << endl;
			llInt += myTypes[i].Int;
		}
		else if (i == 2 || ((i - 2) % 3) == 0)
		{
			uniform_int_distribution<unsigned int> rd(0, 4294967295);
			myTypes[i].UInt = rd(random);
			cout << "Unsigned int: " << myTypes[i].UInt << endl;
			ullInt += myTypes[i].UInt;
		}
		if (i!= 0 && (i+1) % 3 == 0)
			cout << endl;
	}

	cout << "Sum Int: " << llInt << endl
		<< "Sum Unsigned int: " << ullInt << endl << endl;

	myTypes->Short = random();
	cout << "Short: " << myTypes->Short << endl;
	myTypes->Float = random();
	cout << "Float: " << myTypes->Float << endl;
	myTypes->Long = random();
	cout << "Long: " << myTypes->Long << endl;
	myTypes->String = new string;
	*myTypes->String = "My name is Andriy.";
	cout << "String: " << *myTypes->String << endl;

	system("pause");
	return 0;
}