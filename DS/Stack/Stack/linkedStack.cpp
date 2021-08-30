#include "linkedStack.h"

template <class T>
Node<T>::Node()
{
	next = NULL;
}

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	next = NULL;
}

template <class T>
Stack<T>::Stack()
{
	head = NULL;
	count = 0;
}

template <class T>
Stack<T>::~Stack()
{
	clear();
}

template <class T>
void Stack<T>::clear()
{
	while (!empty())
		pop();
}

template <class T>
bool Stack<T>::empty()
{
	return (head == NULL);
}

template <class T>
int Stack<T>::length()
{
	return count;
}

template <class T>
T Stack<T>::top()
{
	return head->data;
}

template <class T>
T Stack<T>::pop()
{
	Node<T>* del = head;
	T delVal = del->data;
	head = head->next;
	delete del;
	count--;
	return delVal;
}

template <class T>
void Stack<T>::push(T val)
{
	Node<T>* insetred = new Node<T>(val);
	insetred->next = head;
	head = insetred;
	count++;
}