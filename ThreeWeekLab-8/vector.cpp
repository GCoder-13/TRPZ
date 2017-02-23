#include "vector.h"
#include <iostream>

using namespace std;

void vec::Add(Vector &var, const int num)
{
	var.x += num;
	var.y += num;
}

void vec::Invert(Vector &var)
{
	int temp = var.y;
	var.y = var.x;
	var.x = temp;
}

int vec::Sum(const Vector var)
{
	return (var.x + var.y);
}

vec::Vector vec::Add(const Vector vec1, const Vector vec2)
{
	int x = vec1.x + vec2.x;
	int y = vec1.y + vec2.y;
	return { x, y };
}

int vec::Multiplication(const Vector vec1, const Vector vec2)
{
	return (vec1.x * vec2.x + vec1.y + vec2.y);
}

void vec::Output(const Vector var)
{
	cout << '(' << var.x << ", " << var.y << ')' << endl;
}
