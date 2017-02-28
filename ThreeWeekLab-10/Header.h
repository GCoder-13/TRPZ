#pragma once
#define _HEADER_H_
#include <iostream>
#include <string>

using namespace std;

/* Тварини */
class Animalia
{
protected:
	string name;			// Ім'я
	int age;				// Вік
	double mass;			// Маса
public:
	Animalia();
	Animalia(const string _name, const int _age, const double _mass);
	Animalia(const Animalia &copy);
	virtual ~Animalia() {};
	virtual void Input();
	virtual void Show() const;
};

/* Ссавці */
class Mammalia : virtual public Animalia
{
protected:
	char gender;			// Стать
public:
	Mammalia();
	Mammalia(const string name, const int age, const double mass, const char _gender);
	Mammalia(const Mammalia &copy);
	~Mammalia() {};
	void Input();
	void Show() const;
};

/* Парнокопитні */
class Artiodactyla : public Mammalia
{
public:
	Artiodactyla(const string name, const int age, const double mass, const char gender);
	Artiodactyla(const Artiodactyla &copy);
	~Artiodactyla() {};
	void Input();
	void Show() const;
};

/* Птахи */
class Aves : public Animalia
{
private:
	char gender;			// Стать
public:
	Aves();
	Aves(const string name, const int age, const double mass, const char _gender);
	Aves(const Aves &copy);
	~Aves() {};
	void Input();
	void Show() const;
};

#if !defined(_HEADER_H_)
#include "Header.h"
#endif // !defined(_HEADER_H_)
