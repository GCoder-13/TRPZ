#include "Header.h"
#include "List.h"

int main()
{
	Animalia *animals;
	animals = new Mammalia;
	animals->Input();
	cout << endl << endl;
	animals->Show();

	delete animals;
	animals = new Aves;
	animals->Input();
	cout << endl << endl;
	animals->Show();

	system("pause");
	return 0;
}