#include <iostream>
#include <fstream>

using namespace std;

void Copy(const ifstream& fin, ofstream& fout)
{
	fout << fin.rdbuf() << endl;
}

void Print(ifstream& fin, ofstream& fout)
{
	char temp;
	bool check = false;
	fout << "--------------------------------------------------" << endl;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == ':' && !check)
			check = true;
		else if (check)
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
	char temp;
	int word = 0;
	int str = 0;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == ' ' || temp == '.')
			word++;
		if (temp == '.' && (word & 1))
		{
			str++;
			word = 0;
		}
	}
	return str;
}

void WordDelete(ifstream& fin, ofstream& fout)
{
	char temp;
	bool check = true;
	fout << "--------------------------------------------------" << endl;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == '.')
			check = true;
		if (temp != ',' && check)
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
	fout << "--------------------------------------------------" << endl;
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