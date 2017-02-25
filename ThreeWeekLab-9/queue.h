#pragma once
#define _QUEUE_H_
#include <iostream>
#include <iomanip>

template <class TData>
class Queue
{
private:
	struct Data
	{
		TData cell;
		Data *next;
		Data() : cell(NULL), next(nullptr) {};
		Data(const TData el) : cell(el), next(nullptr) {};
	} *node;
	mutable Data *head;
	mutable Data *tail;
	void Delete();
public:
	Queue() : head(nullptr), tail(nullptr) {};
	Queue(const TData elem) : node->Data(elem), head(nullptr), tail(nullptr) {};
	Queue(const Queue<TData> &copy) : node(copy.node), head(copy.head), tail(copy.tail) {};
	~Queue();
	void put(const TData el);
	TData get();
	int Amount() const;
	void Output() const;
	bool Empty() const;
};

template<class TData>
inline void Queue<TData>::Delete()
{
	if (head)
	{
		Data *temp = head->next;
		delete head;
		head = temp;
	}
}

template<class TData>
Queue<TData>::~Queue()
{
	if(!Empty())
	std::cout << "\t Queue cleared" << endl;
	while (head)
		Delete();
}

template<class TData>
void Queue<TData>::put(const TData el)
{
	Data *elem = new Data(el);
	if (head)
	{
		tail->next = elem;
		tail = elem;
	}
	else head = tail = node = elem;
}

template<class TData>
inline TData Queue<TData>::get()
{
	if (head)
		std::cout << "Element: " << head->cell << std::endl;
	else
	{
		std::cout << "\t Queue is empty" << std::endl;
		return NULL;
	}
	TData temp = head->cell;
	Delete();
	return temp;
}

/* Отримання кількості елементів які зберігаються в класі */
template<class TData>
int Queue<TData>::Amount() const
{
	if (Empty())
		return NULL;
	int i = 0;
	Data *temp = head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

template<class TData>
void Queue<TData>::Output() const
{
	if (Empty())
		return;
	Data *temp = head;
	while (temp)
	{
		std::cout << setw(3) << temp->cell << std::endl;
		temp = temp->next;
	}
}

template<class TData>
inline bool Queue<TData>::Empty() const
{
	if (head)
		return false;
	else std::cout << "\t Queue is empty" << std::endl;
	return true;
}

#if !defined(_QUEUE_H_)
#include "queue.h"
#endif