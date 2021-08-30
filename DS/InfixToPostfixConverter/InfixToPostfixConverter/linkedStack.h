#pragma once

template <class T>
class Node
{
public:
	Node<T>* next;
	T data;
	Node();
	Node(T data);
};

template <class T>
class Stack
{
	Node<T>* head;
	int count;
public:
	Stack();
	~Stack();
	int length();
	void clear();
	bool empty();
	T pop();
	void push(T val);
	T top();
	void print();
};