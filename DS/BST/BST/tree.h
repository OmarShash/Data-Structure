#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

#define InOrder 1
#define PreOrder 2
#define PostOrder 3

template <class T>
class Node
{
public:
	T data;
	Node<T> *left, * right;
	Node();
	Node(T);
};

template <class T>
class BST
{
	Node<T>* root;
public:
	BST();
	~BST();
	void destroy();
	void insert(T);
	T remove(T);
	bool find(T);
	void print(int);
private:
	void destroyNode(Node<T>*);
	Node<T>* findNode(T);
	Node<T>* findParent(T);
	void printInOrder(Node<T>*);
	void printPreOrder(Node<T>*);
	void printPostOrder(Node<T>*);
	bool isLeaf(Node<T>*);
	bool isParentWithOneChild(Node<T>*);
	Node<T>* getRightMostNode(Node<T>*);
};