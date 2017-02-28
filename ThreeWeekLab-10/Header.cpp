#include "Header.h"

Animalia::Animalia() : age(NULL), mass(NULL) {}

Animalia::Animalia(const string _name, const int _age, const double _mass) : 
	name(_name), age(_age), mass(_mass) {}

Animalia::Animalia(const Animalia & copy) : name(copy.name), age(copy.age), mass(copy.mass) {}

void Animalia::Input()
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter mass: ";
	cin >> mass;
}

void Animalia::Show() const
{
	cout << "Name: " << name << endl
		<< "Age: " << age << endl
		<< "Mass: " << mass << endl;
}

Mammalia::Mammalia() : gender(NULL) {}

Mammalia::Mammalia(const string name, const int age, const double mass,const char _gender) : 
	Animalia(name, age, mass), gender(_gender) {}

Mammalia::Mammalia(const Mammalia & copy) : Animalia(copy), gender(copy.gender) {}

void Mammalia::Input()
{
	Animalia::Input();
	cout << "Enter gender (F, M): ";
	cin >> gender;
}

void Mammalia::Show() const
{
	Animalia::Show();
	cout << "Gender: " << gender << endl;
}

Artiodactyla::Artiodactyla(const string name, const int age, const double mass, const char gender) : 
	Mammalia(name, age, mass, gender) {}

Artiodactyla::Artiodactyla(const Artiodactyla & copy) : Mammalia(copy) {}

void Artiodactyla::Input()
{
	Animalia::Input();
}

void Artiodactyla::Show() const
{
	Mammalia::Show();
}

Aves::Aves() : gender(NULL) {}

Aves::Aves(const string name, const int age, const double mass, const char _gender) :
	Animalia(name, age, mass), gender(_gender) {}

Aves::Aves(const Aves & copy) : Animalia(copy), gender(copy.gender) {}

void Aves::Input()
{
	Animalia::Input();
	cout << "Enter gender (F, M): ";
	cin >> gender;
}

void Aves::Show() const
{
	Animalia::Show();
	cout << "Gender: " << gender << endl;
}
