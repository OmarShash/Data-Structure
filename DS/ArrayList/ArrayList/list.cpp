#include "list.h"
#include <assert.h>

template <class T>
ArrayList<T>::ArrayList()
{
	capacity = 10;
	count = 0;
	elems = new T[capacity];
}

template <class T>
ArrayList<T>::ArrayList(const int capacity)
{
	this->capacity = capacity;
	count = 0;
	elems = new T[capacity];
}

template <class T>
int ArrayList<T>::length()
{
	return count;
}

template <class T>
T& ArrayList<T>::at(const int index)
{
	assert((index >= 0) && (index < count));
	return elems[index];
}

template <class T>
T& ArrayList<T>::operator[](const int index)
{
	assert((index >= 0) && (index < count));
	return elems[index];
}

template <class T>
void ArrayList<T>::expand()
{
	T* temp = new T[2 * capacity];
	for (int i = 0; i < capacity; i++)
		temp[i] = elems[i];
	delete[] elems;
	elems = temp;
}

template <class T>
void ArrayList<T>::append(T val)
{
	if (count == capacity)
		expand();
	elems[count++] = val;
}

template <class T>
void ArrayList<T>::insertAt(const int index, T val)
{
	assert(index == 0 || (index > 0 && index <= count));
	if (count == capacity)
		expand();
	for (int i = count - 1; i >= index; i--)
		elems[i + 1] = elems[i];
	elems[index] = val;
	count++;
}

template <class T>
T ArrayList<T>::popBack()
{
	return elems[--count];
}

template <class T>
void ArrayList<T>::deletedAt(const int index)
{
	assert((index >= 0) && (index < count));
	for (int i = index; i < count; i++)
		elems[i] = elems[i + 1];
	count--;
}

template <class T>
void ArrayList<T>::clear()
{
	count = 0;
}

template <class T>
void ArrayList<T>::print()
{
	for (int i = 0; i < count; i++)
		cout << elems[i] << " ";
	cout << "\n";
}

template <class T>
ArrayList<T>::~ArrayList()
{
	delete[] elems;
}