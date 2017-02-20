#include <iostream>
#include <cstring>

using namespace std;

/* Замінити символи одного рядка заданою кількістю символів іншого рядка, починаючи із заданої позиції */
void ChangeStrStrN(char *str1, const char* str2, int st, const int n)
{
	st--;
	if (st < 0)
		st = 0;
	else if (st > strlen(str1))
		st = strlen(str1);
	if (st + n > sizeof(str1))
		str1[st + n] = '\0';
	for (int i = st, j = 0; j < n; i++, j++)
		str1[i] = str2[j];
}

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
		cout << "str1 < str2" << endl;
	else if(strcmp(str1, str2) > 0)
		cout << "str1 > str2" << endl;
	else cout << "str1 == str2" << endl;
	int temp;
	cout << endl << "Enter number of letter for check (str3, str1(n)): ";
	cin >> num;
	cout << endl << "Comparison str3(n), str1(n):  ";
	if (temp = strncmp(str3, str1, num) < 0)
		cout << "str3(n) < str1(n)" << endl;
	else if (temp = strncmp(str3, str1, num) > 0)
		cout << "str3(n) > str1(n)" << endl;
	else cout << "str3(n) == str1(n)" << endl;

	char let;
	cout << endl << "Enter letter for search (str2): ";
	cin >> let;
	cin.ignore();
	cin.clear();
	cout << "Index letter: ";
	if(strchr(str2, let) != NULL)
		cout << strchr(str2, let) - str2 << endl;
	else cerr << "Letter don\'t found" << endl; 

	char str4[MAX];
	cout << endl << "Enter string for search (str1): ";
	cin.get(str4, MAX);
	cin.ignore();
	cin.clear();
	cout << "Index string: ";
	if(strstr(str1, str4) != NULL)
		cout << strstr(str1, str4) - str1 << endl;
	else cerr << "String don\'t found" << endl;

	cout << endl << "------------------------------------------------------" << endl;
	cout << endl << "Enter two string:" << endl;

	cout << "str1 >  ";
	cin.get(str1, MAX);
	cin.ignore(MAX, '\n');
	cin.clear();

	cout << "str2 >  ";
	cin.get(str2, MAX);
	cin.ignore();
	cin.clear();
	int st;
	cout << "Enter starn and number letter (str2):";
	cin >> st >> num;
	ChangeStrStrN(str1, str2, st, num);
	cout << endl << "Str1:  " << str1 << endl;

	system("pause");
	return 0;
}