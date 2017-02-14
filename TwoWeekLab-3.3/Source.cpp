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
	int length = 0;
	for (int i(0); i < str.length(); i++)
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

	
	system("pause");
	return NULL;
}