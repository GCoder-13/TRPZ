#pragma once
#define _HEADER_H_
#include <iostream>
#include <string>

using namespace std;

/* ������� */
class Animalia
{
protected:
	string name;			// ��'�
	int age;				// ³�
	double mass;			// ����
public:
	Animalia();
	Animalia(const string _name, const int _age, const double _mass);
	Animalia(const Animalia &copy);
	virtual ~Animalia() {};
	virtual void Input();
	virtual void Show() const;
};

/* ������ */
class Mammalia : virtual public Animalia
{
protected:
	char gender;			// �����
public:
	Mammalia();
	Mammalia(const string name, const int age, const double mass, const char _gender);
	Mammalia(const Mammalia &copy);
	~Mammalia() {};
	void Input();
	void Show() const;
};

/* ����������� */
class Artiodactyla : public Mammalia
{
public:
	Artiodactyla(const string name, const int age, const double mass, const char gender);
	Artiodactyla(const Artiodactyla &copy);
	~Artiodactyla() {};
	void Input();
	void Show() const;
};

/* ����� */
class Aves : public Animalia
{
private:
	char gender;			// �����
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
