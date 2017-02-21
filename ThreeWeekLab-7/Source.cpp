#include <iostream>
#include <random>

using namespace std;

struct Item
{
	int data;
	Item *back, *next;
};

void InputData(int &var)
{
	cout << "Enter number: ";
	cin >> var;
}

void OutputDate(const Item *ptr)
{
	cout << ptr->data << endl;
}

inline bool EmptyListInfo(const Item *list)
{
	if (list != NULL)
		return false;
	cout << "\t List empty" << endl;
	return true;
}

Item* CreateItem()
{
	Item *ptr = new Item;
	InputData(ptr->data);
	ptr->back = NULL;
	ptr->next = NULL;
	return ptr;
}

/* Очищення списку */
void DeleteList(Item *&ptr)
{
	if (EmptyListInfo(ptr))
		return;
	else cout << "\t List cleaned" << endl;
	Item *del;
	while(ptr != NULL)
	{
		del = ptr->next;
		delete ptr;
		ptr = del;
	}
}

/* Додавання елементу в кінець списку */
void AddToTheEnd(Item *ptr)
{
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = CreateItem();
	ptr->next->back = ptr;
	cout << "\t New items added to the list" << endl;
}

/* Отримання покажчика на i–й елемент списку */
/* Отримання номеру елементу списку за покажчиком на елемент */
/* Видалення елементів списку починаючи з елементу a по елемент b */
/* Вставка елемента в список перед визначеним елементом */

/* Друк вмісту елементів списку на екран */
void OutputList(Item *list)
{
	int i = 1;
	while (list != NULL)
	{
		cout << "Element " << i++ << ": ";
		OutputDate(list);
		list = list->next;
	}
}

inline void OutputMenu()
{
	cout << "\t Select an action" << endl
		<< "1 - Clean the list;" << endl
		<< "2 - Adding an element to the end of the list;" << endl
		<< "4 - Getting a pointer to the i-th element of the list;" << endl
		<< "5 - Get list item number for the pointer to an item;" << endl
		<< "7 - Remove items from a list on the b;" << endl
		<< "9 - Insert item in the list before the specified element;" << endl
		<< "10 - Print the list;" << endl
		<< "0 - Exit." << endl;
}

void SwichMenu(Item *&list)
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
			DeleteList(list);
			break;
		case 2:
			if (list == NULL)
				list = CreateItem();
			else AddToTheEnd(list);
			break;
		case 4: break;
		case 5: break;
		case 7: break;
		case 9: break;
		case 10:
			if(!EmptyListInfo(list))
				OutputList(list);
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

/*//////////////////////////////// Array \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
void ArrRand(int *arr, const int n)
{
	random_device random;
	uniform_int<int> rd(-10, 10);
	for (int i = 0; i < n; i++)
		arr[i] = rd(random);
}

int ArrSum(const int *arr, const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

void ArrOutput(const int *arr, const int n)
{
	for (int i = 0; i < n; i++)
		cout << "  " << arr[i];
}
/*//////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

int main(int argc, char **argv)
{
	int n;
	cout << "Enter size array: ";
	cin >> n;
	int *arr = new int[n];
	ArrRand(arr, n);
	cout << "Array: ";
	ArrOutput(arr, n);
	cout << endl << "Sum array: " << ArrSum(arr, n) << endl;
	delete[] arr;
	system("pause");
	system("cls");

	Item *list = NULL;
	SwichMenu(list);

	return 0;
}