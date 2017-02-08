#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int word = 0, nStr = 0;

	cout << "Enter string:" << endl << " >  ";
	getline(cin, str);
	cout << endl;

	for (int i(1); i < str.length(); i++)
	{
		if (i - 1 == 0 && str[i - 1] != ' ' && str[i] == ' ')
			word++;
		else if ((str[i] == ' ' && str[i - 1] == ' ') || str[i] == ',' || str[i] == ';' || str[i] == ':')
			continue;
		else if (str[i] == ' ')
			word++;
		else if (j == str.length()-1 && str[j] != ' ')
			word++;

	/*	if (str[i] == '.' || str[i] == '?' || str[i] == '!' || i == str.length()-1)
		{
			nStr++;
			
			cout << "String " << nStr << ": " << word << " words" << endl;
			word = 0;
		}
	*/
	}
	
	system("pause");
	return NULL;
}