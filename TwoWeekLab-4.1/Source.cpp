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
		cout << "Enter score for exams: " << endl;
		for (int j(0); j < 3; j++)
		{
			cout << " >  ";
			cin >> A[i].EXAM[j];
		}
		cin.ignore();
	}
}

void Output(const ABITURIENT* A, const int n)
{
	cout << setw(10) << "NAME" << setw(16) << "GENDER" << setw(16) << "OCUPATION" << setw(13) << "EXEM" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(16) << A[i].NAME << setw(8) << A[i].GENDER << setw(20) << A[i].SPEC << '\t';
		for (int j = 0; j < 3; j++)
		{
			cout << setw(3) << A[i].EXAM[j] ;
		}
		cout << endl;
	}
	cout << endl;
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
	const int N = 1;
	ABITURIENT* ABIT = new ABITURIENT[N];
	Input(ABIT, N);
	Sort(ABIT, N);

	cout << endl << endl;

	Output(ABIT, N);

	system("pause");
	return NULL;
}