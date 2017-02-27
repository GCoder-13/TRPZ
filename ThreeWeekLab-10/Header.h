#pragma once
#define _HEADER_H_
#include <iostream>
#include <string>

using namespace std;

/* ������� */
class Animalia
{
protected:
	const string name;	// ��'�
	unsigned int age;	// ³�
	double mass;	// ����
	const enum Infratyp	{ Vertebrates, Invertebrates } group;	// �������� (�������, ����������)
public:
	Animalia(const string _name, const unsigned int _age, const Infratyp _group);
	virtual void Show() = 0;
};

/* ������ */
class Mammalia : virtual public Animalia
{
	char gender;
protected:

public:
};

/* ����������� */
class Artiodactyla : public Mammalia
{
private:

public:
};

/* ����� */
class Aves : public Animalia
{
private:

public:
};

#if !defined(_HEADER_H_)
#include "Header.h"
#endif // !defined(_HEADER_H_)
