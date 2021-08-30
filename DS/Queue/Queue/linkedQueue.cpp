#include "linkedQueue.h"

#include <assert.h>

template <class T>
Node<T>::Node()
{
	next = NULL;
}

template <class T>
Node<T>::Node(T data)
{
	next = NULL;
	this->data = data;
}

template <class T>
Queue<T>::Queue()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class T>
Queue<T>::~Queue()
{
	clear();
}

template <class T>
void Queue<T>::clear()
{
	while (!empty())
		deQueue();
}

template <class T>
int Queue<T>::length()
{
	return count;
}

template <class T>
bool Queue<T>::empty()
{
	return (head == NULL);
}

template <class T>
T Queue<T>::front()
{
	return head->data;
}

template <class T>
T Queue<T>::back()
{
	return tail->data;
}

template <class T>
T Queue<T>::deQueue()
{
	assert(!empty());
	T val = head->data;
	Node<T>* del = head;
	head = head->next;
	delete del;
	count--;
	if (empty())
		tail = NULL;
	return val;
}

template <class T>
void Queue<T>::enQueue(T val)
{
	Node<T>* inserted = new Node<T>(val);
	if(!empty())
	{
		tail->next = inserted;
		tail = inserted;
	}
	else
	{
		tail = inserted;
		head = inserted;
	}
	count++;
}