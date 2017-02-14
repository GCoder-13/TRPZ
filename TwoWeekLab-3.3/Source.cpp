#include <iostream>
#include <string>

using namespace std;

void StrAndWord(string& str)
{
	int word = 1, nStr = 0;

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

			while (str[i] == ' ' || str[i] == '.' || str[i] == '!' || str[i] == '?')
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
		while (str[st] == ' ' || str[st] == '.' || str[st] == '!' || str[st] == '?')
			i = ++st;

		if (str[i] == ' ' || str[i] == '.' || str[i] == '!' || str[i] == '?')
		{
			fn = i - 1;
			while (str[fn] == ' ' || str[fn] == '.' || str[fn] == '!' || str[fn] == '?')
				fn--;

			if (str[fn - 1] == 'a' || str[fn - 1] == 'A' || str[fn - 1] == 'e' || str[fn - 1] == 'E' || str[fn - 1] == 'i' ||
				str[fn - 1] == 'I' || str[fn - 1] == 'o' || str[fn - 1] == 'O' || str[fn - 1] == 'u' || str[fn - 1] == 'U')
			{
				str.erase(st, (fn - st + 1));
				i = st;
			}
			else st = i + 1;
		}
	}
}

int main()
{
	string str;

	cout << "Enter string:" << endl << " >  ";
	getline(cin, str);

	if (str[str.length() - 1] == ' ')
		str[str.length() - 1] = '\0';
	else if (str[str.length() - 1] != '.' && str[str.length() - 1] != '!' && str[str.length() - 1] != '?')
		str.append(1, '.');

	StrAndWord(str);
	cout << endl << "The shortest sentence:" << endl;
	StringLength(str);

	cout << endl << endl << "Delete words:" << endl;
	WordDelete(str);
	if (str.empty())
		cout << "All the words removed" << endl;
	else cout << str << endl;

	system("pause");
	return NULL;
}