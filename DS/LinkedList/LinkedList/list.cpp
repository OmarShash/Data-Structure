#include "list.h"
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
LinkedList<T>::LinkedList()
{
	count = 0;
	head = tail = NULL;
}

template <class T>
int LinkedList<T>::length()
{
	return count;
}

template <class T>
bool LinkedList<T>::empty()
{
	return (count == 0);
}

template <class T>
void LinkedList<T>::append(T data)
{
	Node<T>* inserted = new Node<T>(data);
	if (empty())
	{
		head = tail = inserted;
	}
	else
	{
		tail->next = inserted;
		tail = inserted;
	}
	count++;
}

template <class T>
T& LinkedList<T>::at(int pos)
{
	assert((pos >= 0) && (pos < count));
	Node<T>* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp->data;
}

template <class T>
void LinkedList<T>::insertAt(int pos, T data)
{
	assert((pos >= 0) && (pos < count));
	Node<T>* inserted = new Node<T>(data);
	if (pos == 0)
	{
		if (empty())
		{
			head = tail = inserted;
		}
		else
		{
			inserted->next = head;
			head = inserted;
		}
	}
	else
	{
		Node<T>* temp = head;
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;

		inserted->next = temp->next;
		temp->next = inserted;
	}
	count++;
}

template <class T>
void LinkedList<T>::deletedAt(int pos)
{
	assert((pos >= 0) && (pos < count));
	Node<T>* deleted;
	if (pos == 0)
	{
		deleted = head;
		head = head->next;
	}
	else
	{
		Node<T>* temp = head;
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;

		deleted = temp->next;
		temp->next = deleted->next;
		if (pos = count - 1)
			tail = temp;
	}

	delete deleted;

	count--;

}

template <class T>
void LinkedList<T>::display()
{
	for (int i = 0; i < count; i++)
		cout << at(i) << " ";
	cout << "\n";
}

template <class T>
void LinkedList<T>::clear()
{
	while (!empty())
		deletedAt(0);
}

template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}