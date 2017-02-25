#include <iostream>
#include "queue.h"

using namespace std;

typedef int Int;

inline void OutputMenu()
{
	cout << "\t Select an action" << endl
		<< "1 - Put element;" << endl
		<< "2 - Get element;" << endl
		<< "3 - Clear queue;" << endl
		<< "4 - Get the number of elements;" << endl
		<< "5 - Show queue;" << endl
		<< "0 - Exit." << endl;
}

void SwitchMenu(Queue<Int>& queue)
{
	int action;
	while (true)
	{
		OutputMenu();
		cout << endl << "Select an action: ";
		cin >> action;

		Int elem;
		int length = 0;
		switch (action)
		{
		case 1:
			cout << "Enter element: ";
			cin >> elem;
			queue.put(elem);
			break;
		case 2:
			queue.get();
			break;
		case 3:
			queue.~Queue();
			break;
		case 4:
			length = queue.Amount();
			if (length)
				cout << "The length of the queue: " << length << endl;
			break;
		case 5:
			cout << "Queue:";
			queue.Output();
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

int main(int argc, char **argv)
{
	Queue<Int> list;
	SwitchMenu(list);

	return 0;
}