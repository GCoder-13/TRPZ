#pragma once
#define _VECTOR_H_

namespace vec
{
	struct Vector
	{
		int x, y;
	};
	void Add(Vector &var, const int num);
	void Invert(Vector &var);
	int Sum(const Vector var);
	Vector Add(const Vector vec1, const Vector vec2);
	int Multiplication(const Vector vec1, const Vector vec2);
	void Output(const Vector var);

}

#if !defined(_VECTOR_H_)
#include "vector.h"
#endif