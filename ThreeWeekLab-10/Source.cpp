#include "Header.h"
#include "List.h"

inline void OutputMenu()
{
	cout << "\t Select an action" << endl
		<< "1 - Add element;" << endl
		<< "2 - Print list;" << endl
		<< "3 - Clear list;" << endl;
}

bool SwitchType(Animalia *&type)
{
	system("cls");
	cout << "\t Type element" << endl
		<< "1 - Animalia;" << endl
		<< "2 - Mammalia;" << endl
		<< "3 - Artiodactyla;" << endl
		<< "4 - Aves." << endl << endl
		<< "Select an type element:  ";
	int sw;
	cin >> sw;
	switch (sw)
	{
	case 1:
		type = new Animalia;
		break;
	case 2:
		type = new Mammalia;
		break;
	case 3:
		type = new Artiodactyla;
		break;
	case 4:
		type = new Aves;
		break;
	default:
		cerr << "\t Incorrect input" << endl;
		return false;
	}
	return true;
}

void SwitchMenu(List<Animalia*> &list)
{
	int action;
	while (true)
	{
		OutputMenu();
		cout << endl << "Select an action: ";
		cin >> action;

		switch (action)
		{
		case 1:
			Animalia *animals;
			if (SwitchType(animals))
			{
				system("cls");
				animals->Input();
				list.Add(animals);
			}
			break;
		case 2:
			system("cls");
			cout << "\t List" << endl;
			if (!list.Empty())
				list.Print();
			else cout << "\t List is empty" << endl;
			break;
		case 3:
			if (!list.Empty())
			{
				list.~List();
				cout << "\t List is clear" << endl;
			}
			else cout << "\t List is empty" << endl;
			break;
		case 0: return;
		default:
			cerr << "\t Incorrect input" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

int main()
{
	List<Animalia*> list;
	SwitchMenu(list);

	return 0;
}