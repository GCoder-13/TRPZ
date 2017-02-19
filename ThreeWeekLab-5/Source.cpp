#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const int MAX = 50;
	char str1[MAX], str2[MAX];
	cout << "Enter two strings:" << endl;

	cout << "str1 >  ";
	cin.get(str1, MAX);
	cin.ignore(MAX,'\n');
	cin.clear();

	cout << "str2 >  ";
	cin.get(str2, MAX);
	cin.ignore();
	cin.clear();

	cout << endl << "--------------------------------------------" << endl;

	char str3[MAX];
	strcpy_s(str3, str1);
	cout << endl << "str3 = str1:  " << str3 << endl;

	int num;
	cout << endl << "Enter number of letter for copy (str2 in str3): ";
	cin >> num;
	strncpy_s(str3, str2, num);
	cout << "str3 = str2(n):  " << str3 << endl;

	strcat_s(str1, str2);
	cout << endl << "str1 = str1 + str2:  " << str1 << endl;

	cout << endl << "Enter number of letter for addition (str1 in str3): ";
	cin >> num;
	strncat_s(str3, str1, num);
	cout << "str3 = str3 + str1(n):  " << str3 << endl;

	cout << endl << "Comparison str1, str2:  ";
	if (strcmp(str1, str2) < 0)
		cout << "str1 > str2" << endl;
	else if(strcmp(str1, str2) > 0)
		cout << "str1 < str2" << endl;
	else cout << "str1 == str2" << endl;

	cout << endl << "Enter number of letter for check (str1 == str3(n)): ";
	cin >> num;
	cout << endl << "Comparison str1, str3(n):  ";
	if (strncmp(str1, str3, num) < 0)
		cout << "str1 > str3(n)" << endl;
	else if (strncmp(str1, str3, num) > 0)
		cout << "str1 < str3(n)" << endl;
	else cout << "str1 == str3(n)" << endl;

	char let;
	cout << endl << "Enter letter for search (str2): ";
	cin >> let;
	cout << "Index letter: " << strchr(str2, let) - str2 << endl;


	system("pause");
	return 0;
}