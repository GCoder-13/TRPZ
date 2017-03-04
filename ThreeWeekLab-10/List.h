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
		Node() : next(nullptr) {};
		Node(TData el) : cell(el), next(nullptr) {};
		Node(const Node &copy) : cell(copy.cell), next(copy.next) {};
	};
	Node *head;
	Node *tail;
public:
	List() : head(nullptr), tail(nullptr) {};
	List(const List &copy) : Node(copy), head(copy.head), tail(copy.tail) {};
	~List();
	void Add(TData elem);
	void Print() const;
	bool Empty() const;
};

template<class TData>
List<TData>::~List()
{
	while (head)
	{
		Node *temp = head->next;
		delete head;
		head = temp;
	}
}

template<class TData>
void List<TData>::Add(TData el)
{
	Node *elem = new Node(el);
	if (head)
	{
		tail->next = elem;
		tail = elem;
	}
	else head = tail = elem;
}

template<class TData>
void List<TData>::Print() const
{
	Node *temp = head;
	while (temp)
	{
		temp->cell->Show();
		std::cout << std::endl;
		temp = temp->next;
	}
}

template<class TData>
inline bool List<TData>::Empty() const
{
	if(head)
		return false;
	else return true;
}

#if !defined(_LIST_H_)
#include "List.h"
#endif // !defined(_LIST_H_)