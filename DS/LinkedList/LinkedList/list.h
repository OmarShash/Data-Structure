#pragma once

#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node();
	Node(T data);
};

template <class T>
class LinkedList
{
	int count;
	Node<T> *head, *tail;
public:
	LinkedList();
	int length();
	bool empty();
	void append(T data);
	T& at(int pos);
	void insertAt(int pos, T data);
	void deletedAt(int pos);
	void display();
	void clear();
	~LinkedList();
};
