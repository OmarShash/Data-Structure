#pragma once

#include <iostream>

using namespace std;

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
class Queue
{
	Node<T> *head, *tail;
	int count;
public:
	Queue();
	~Queue();
	int length();
	bool empty();
	void clear();
	T deQueue();
	void enQueue(T val);
	T front();
	T back();
};