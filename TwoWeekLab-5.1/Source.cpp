#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Copy(const ifstream& fin, ofstream& fout)
{
	fout << fin.rdbuf() << endl;
}

void Print(ifstream& fin, ofstream& fout)
{
	char temp;
	bool check = false;
	fout << "------------------------------------------------------------" << endl;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == ':' && !check)
			check = true;
		else if (check && temp>0)
		{
			cout << temp;
			fout << temp;
		}
	}
	cout << endl;
	fout << endl;
}

int StringOddWords(ifstream& fin, ofstream& fout)
{
	string word;
	int w = 0;
	int nStr = 0;
	bool sw = false;
	while (fin.good())
	{
		fin >> word;
		w++;
		if (word.at(word.length() - 1) == '.' || word.at(word.length() - 1) == '!' || word.at(word.length() - 1) == '?')
		{
			if (w & 1)
				nStr++;
			w = 0;
		}
	}
	return nStr;
}

void WordDelete(ifstream& fin, ofstream& fout)
{
	char temp;
	bool check = true;
	fout << "------------------------------------------------------------" << endl;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == '.')
			check = true;
		if (temp != ',' && check && temp > 0)
		{
			cout << temp;
			fout << temp;
		}
		else if (temp == ',')
			check = false;
	}
}

int main()
{
	ifstream fin;
	ofstream fout;

	fout.open("Files\\output.txt", ios_base::out | ios_base::trunc);

	fin.open("Files\\input.txt", ios_base::in);
	Copy(fin, fout);
	fin.close();

	fin.open("Files\\input.txt", ios_base::in);
	Print(fin, fout);
	fin.close();

	fin.open("Files\\input.txt", ios_base::in);
	fout << "------------------------------------------------------------" << endl;
	cout << endl << "The number of sentences that contain an odd number of words: " << StringOddWords(fin, fout) << endl << endl;
	fin.close();

	fin.open("Files\\input.txt", ios_base::in);
	fout << "The number of sentences that contain an odd number of words: " << StringOddWords(fin, fout) << endl;
	fin.close();

	fin.open("Files\\input.txt", ios_base::in);
	WordDelete(fin, fout);
	fin.close();

	cout << endl;

	fout.close();
	system("pause");
	return NULL;
}