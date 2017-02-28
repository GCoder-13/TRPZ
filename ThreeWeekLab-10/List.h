#pragma once
#define _LIST_H_

template<class TData>
class List
{
private:
	struct Node
	{
		TData cell;
		Node *next;
		Node() : cell(NULL), next(nullptr) {};
		Node(const TData el) : cell(el), next(nullptr) {};
		Node(const Node &copy) : cell(copy.cell), next(copy.next) {};
	};
	Node *head;
	Node *tail;
public:
	List() : head(nullptr), tail(nullptr) {};
	~List() {};
};

#if !defined(_LIST_H_)
#include "List.h"
#endif // !defined(_LIST_H_)
