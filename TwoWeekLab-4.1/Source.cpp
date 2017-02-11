#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct ABITURIENT
{
	string NAME;	//прізвище, ініціали
	char GENDER;	//стать
	string SPEC;	//назва спеціальності;
	int EXAM[3];	//результати вступних іспитів з трьох предметів
};

void Input(ABITURIENT*& A, const int n)
{
	for (int i(0); i < n; i++)
	{
		cout << "Enter name: ";
		getline(cin, A[i].NAME);
		cout << "Enter gender (M or W): ";
		cin >> A[i].GENDER;
		cin.ignore();
		cout << "Enter ocupation: ";
		getline(cin, A[i].SPEC);
		cin.clear();
		cout << "Enter score for exams: " << endl;
		for (int j(0); j < 3; j++)
		{
			cout << " >  ";
			cin >> A[i].EXAM[j];
		}
		cin.ignore();
		cout << "-----------------------------------" << endl;
	}
	system("cls");
}

void Output(const ABITURIENT A)
{
	cout << setw(16) << A.NAME << setw(8) << A.GENDER << setw(20) << A.SPEC << '\t';
	for (int j = 0; j < 3; j++)
	{
		cout << setw(3) << A.EXAM[j] ;
	}
	cout << endl;
}

void Output(const ABITURIENT* A, const int n)
{
	cout << endl << setw(10) << "NAME" << setw(16) << "GENDER" << setw(16) << "OCUPATION" << setw(13) << "EXEM" << endl
		<< "------------------------------------------------------------------" << endl;
	for (int i(0); i < n; i++)
		Output(A[i]);
}

void Output(const ABITURIENT* A, const int n, const int rate)
{
	cout << endl << setw(10) << "NAME" << setw(16) << "GENDER" << setw(16) << "OCUPATION" << setw(13) << "EXEM" << endl
		<< "------------------------------------------------------------------" << endl;
	bool print = false;
	for (int i(0); i < n; i++)
	{
		bool sw = true;
		for (int j(2); j >= 0; j--)
		{
			if (A[i].EXAM[j] < rate)
			{
				sw = false;
				break;
			}
		}
		if (sw)
		{
			Output(A[i]);
			print = true;
		}
	}
	if (!print)
		cout << "\t\t These students not found" << endl;
}

void Sort(ABITURIENT*& A, const int n)
{
	for (int i(0); i < n; i++)
	{
		ABITURIENT temp = A[i];
		int j;
		for (j = i - 1; j >= 0 && A[j].NAME > temp.NAME; j--)
			A[j + 1] = A[j];
		A[j + 1] = temp;
	}
}

int main()
{
	const int N = 2;
	ABITURIENT* ABIT = new ABITURIENT[N];
	Input(ABIT, N);

	cout << "Sorting: ";
	Sort(ABIT, N);
	Output(ABIT, N);

	int rate;
	cout << endl << "Enter pass rate: ";
	cin >> rate;
	Output(ABIT, N, rate);
	
	system("pause");
	return NULL;
}