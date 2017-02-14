#include <iostream>
#include <string>

using namespace std;

void StrAndWord(string& str)
{
	int word = 1, nStr = 0;
	if (str[str.length() - 1] == ' ')
		str[str.length() - 1] = '\0';
	else if (str[str.length() - 1] != ' ' && (str[str.length() - 1] != '.' || str[str.length() - 1] != '!' || str[str.length() - 1] != '?'))
		str += '.';

	for (int i(1); i < str.length(); i++)
	{
		if (i - 1 == 0 && str[i - 1] != ' ' && str[i] == ' ')
			word++;
		else if ((str[i] == ' ' && str[i - 1] == ' ') || str[i] == ',' || str[i] == ';' || str[i] == ':')
			continue;
		else if (str[i] == ' ')
			word++;

		if (str[i] == '.' || str[i] == '!' || str[i] == '?' || i == str.length() - 1)
		{
			if (str[i - 1] == ' ' || str[i - 1] == '.' || str[i - 1] == '!' || str[i - 1] == '?')
				word--;

			nStr++;
			if (word != 0)
				cout << "String " << nStr << ": " << word << " words" << endl;
			else nStr--;

			if (str[i + 1] != ' ')
				word = 1;
			else word = 0;
		}
	}
}

void StringLength(string& str)
{
	int st = 0, fn, len = 0;

	for (int i(st); str[i] == ' ' || str[i] == '.' || str[i] == '!' || str[i] == '?'; )
		st = ++i;

	int temp = st;
	for (int i(st); i < str.length(); i++)
	{
		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
		{
			if (len == i - temp)
			{
				for (int j(st); j <= fn; j++)
					cout << str[j];
				cout << endl;
				st = temp;
				fn = i;
			}
			else if (len <= i - temp)
			{
				len = i - temp;
				st = temp;
				fn = i;
			}
			

			while(str[i] == ' ' || str[i] == '.' || str[i] == '!' || str[i] == '?')
				temp = ++i;
		}
	}
	for (int i(st); i <= fn; i++)
		cout << str[i];
}

void WordDelete(string& str)
{
	int st = 0, fn;
	for (int i(st); i < str.length(); i++)
	{

	}
}

int main()
{
	string str;

	cout << "Enter string:" << endl << " >  ";
	getline(cin, str);
	cout << endl;

	if (str.empty())
	{
		cout << "You do not enter string!" << endl;
		system("pause");
		return NULL;
	}

	StrAndWord(str);
	cout << endl << "The shortest sentence:" << endl;
	StringLength(str);
	cout << endl;
	
	system("pause");
	return NULL;
}