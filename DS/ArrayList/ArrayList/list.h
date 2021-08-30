#pragma once

#include <iostream>

using namespace std;

template <class T>
class ArrayList
{
	T* elems;
	int capacity;
	int count;
	void expand();
public:
	ArrayList();
	ArrayList(const int capacity);
	int length();
	T& at(const int index);
	T& operator[](const int index);
	// expand Function
	void append(T val);
	void insertAt(const int index, T val);
	T popBack();
	void deletedAt(const int index);
	void clear();
	void print();
	~ArrayList();
};