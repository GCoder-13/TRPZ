#pragma once
#define _HEADER_H_
#include <iostream>
#include <string>

using namespace std;

/* Тварини */
class Animalia
{
protected:
	const string name;	// Ім'я
	unsigned int age;	// Вік
	double mass;	// Маса
	const enum Infratyp	{ Vertebrates, Invertebrates } group;	// Інфратип (хребетні, безхребетні)
public:
	Animalia(const string _name, const unsigned int _age, const Infratyp _group);
	virtual void Show() = 0;
};

/* Ссавці */
class Mammalia : virtual public Animalia
{
	char gender;
protected:

public:
};

/* Парнокопитні */
class Artiodactyla : public Mammalia
{
private:

public:
};

/* Птахи */
class Aves : public Animalia
{
private:

public:
};

#if !defined(_HEADER_H_)
#include "Header.h"
#endif // !defined(_HEADER_H_)
