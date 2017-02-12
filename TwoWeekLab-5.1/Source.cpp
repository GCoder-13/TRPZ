#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Copy(const ifstream& fin, ofstream& fout)
{
	fout << fin.rdbuf();
}

void Print(ifstream& fin)
{
	char temp;
	bool check = false;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == ':' && !check)
			check = true;
		else if (check)
			cout << temp;
	}
	cout << endl;
}

int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("Files\\input.txt", ios_base::in);
	fout.open("Files\\output.txt", ios_base::out | ios_base::trunc);

	if (!fin.is_open())
	{
		cerr << "ERROR" << endl;
		system("pause");
		return NULL;
	}

	Copy(fin, fout);
	Print(fin);

	fin.close();
	fout.close();
	system("pause");
	return NULL;
}