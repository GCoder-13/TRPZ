#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <stdio.h>

using namespace std;

int main()
{
	char ch;
	int integer;
	unsigned int intPluss;
	short intSmall;
	float fl;
	long ln;
	string str;
	ofstream fout;
	ifstream fin;

	/* Вивести на екран ПІБ, назву групи та номер варіанту */
	cout << "Khomutovskiy Andrey Anatolievich, P-31, V-14." << endl << endl;
	
	fout.open("Text.txt", ios_base::out | ios_base::trunc);
	/* Зчитати значення з клавіатури вказані у варіантах до роботи */
	cout << "Char: ";
	cin >> ch;
	fout << ch << endl;
	cout << "Int: ";
	cin >> integer;
	fout << integer << endl;
	cout << "Unsigned int: ";
	cin >> intPluss;
	fout << intPluss << endl;
	cout << "Short: ";
	cin >> intSmall;
	fout << intSmall << endl;
	cout << "Float: ";
	cin >> fl;
	fout << fl << endl;
	cout << "Long: ";
	cin >> ln;
	fout << ln << endl;
	cout << "String: ";
	cin >> str;
	fout << str << endl;
	fout << endl << "----------------------------------" << endl << endl;
	fout.close();

	fout.open("Text.txt", ios_base::out | ios_base::app);
	/* Вивести всі зчитані дані у текстовий рядок за допомогою функції sprintf */
	cout << endl << "\t Output" << endl;
	char buf[50];
	sprintf_s(buf, "Char: %c", ch);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Int: %d", integer);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Unsigned int: %u", intPluss);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Short: %hd", intSmall);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Float: %.3f", fl);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Long: %ld", ln);
	printf_s("%s\n", buf);
	fout << buf << endl;
	cout << "String: " << str << endl;
	fout << "String: " << str << endl;
	fout.close();

	/* Вивести сформований рядок на екран обов’язково використовуючи восьмеричне та шіснадцятеричне представлення 
	для цілих чисел та різні формати для дійсних значень */
	cout << endl << "\t Different number system" << endl;
	sprintf_s(buf, "Char(16): %x", ch);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Int(8): %o", integer);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Int(16): %x", integer);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Unsigned int(8): %o", intPluss);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Unsigned int(16): %x", intPluss);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Short(8): %ho", intSmall);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Short(16): %hx", intSmall);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Float(exp): %.3e", fl);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Long(8): %lo", ln);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Long(16): %lx", ln);
	printf_s("%s\n", buf);

	/* Виконати пункт № 6 першої лабораторної роботи з виведенням на екран всіх значень послідовності та результату обчислень */
	cout << endl << "\t Item 6" << endl;
	double y, sum = 0;
	for (int x(-20); x <= 10; x++)
	{
		y = pow(x, 4) - 10.2*pow(x, 3) - pow(x, 2) + 2.1*x + 37.7;
		cout << '\t' << y << endl;
		if (y < 2 * x)
			sum += y;
	}
	cout << "Sum = " << sum << endl;

	/* Записати до файлу рядок сформований в пункті 4, та зчитати його з файлу в інший рядок */
	string strFile;
	fin.open("Text.txt", ios_base::in);
	int i = 0;
	while (fin.good())
	{
		fin.getline(buf, 50);
		if (i++ > 9)
		{
			strFile += buf;
			strFile += '\n';
		}
	}
	fin.close();
	cout << endl << "\t Read file" << endl << strFile << endl;

	/* Записати до файлу значення змінних зчитані при виконанні пункту 3, та зчитати їх з файлу в інші змінні */
	fin.open("Text.txt", ios_base::in);
	char _ch;
	fin.get(_ch);
	int _integer;
	fin >> _integer;
	unsigned int _intPluss;
	fin >> _intPluss;
	short _intSmall;
	fin >> _intSmall;
	float _fl;
	fin >> _fl;
	long _ln;
	fin >> _ln;
	string _str;
	fin >> _str;
	fin.close();

	cout << "\t New var"
		<< "Char: " << _ch << endl
		<< "Int: " << _integer << endl
		<< "Unsigned int: " << _intPluss << endl
		<< "Short: " << _intSmall << endl
		<< "Float: " << _fl << endl
		<< "Long: " << _ln << endl
		<< "String: " << _str << endl;

	system("pause");
	return 0;
}