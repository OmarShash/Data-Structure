#include "tree.h"

template <class T>
Node<T>::Node()
{
	left = right = NULL;
}

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	left = right = NULL;
}

template <class T>
BST<T>::BST()
{
	root = NULL;
}

template <class T>
BST<T>::~BST()
{
	destroy();
}

template <class T>
void BST<T>::destroy()
{
	destroyNode(root);
	root = NULL;
}

template <class T>
void BST<T>::destroyNode(Node<T>* node)
{
	if (node == NULL)
		return;

	destroyNode(node->left);
	destroyNode(node->right);
	delete node;
}

template <class T>
bool BST<T>::find(T val)
{
	return findNode(val) != NULL;
}

template <class T>
Node<T>* BST<T>::findNode(T val)
{
	Node<T>* temp = root;
	while (temp != NULL && temp->data != val)
	{
		if (val < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

template <class T>
Node<T>* BST<T>::findParent(T val)
{
	Node<T>* cur = root;
	Node<T>* parent = NULL;
	while (cur != NULL && cur->data != val)
	{
		parent = cur;
		if (val < cur->data)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return parent;
}

template <class T>
void BST<T>::insert(T val)
{
	Node<T>* cur = findNode(val);
	if (cur != NULL)
		return;
	Node<T>* inserted = new Node<T>(val);
	Node<T>* parent = findParent(val);
	if (parent == NULL)
	{
		root = inserted;
		return;
	}
	if (val < parent->data)
		parent->left = inserted;
	else if (val > parent->data)
		parent->right = inserted;
}

template <class T>
bool BST<T>::isLeaf(Node<T>* node)
{
	return node->left == NULL && node->right == NULL;
}

template <class T>
bool BST<T>::isParentWithOneChild(Node<T>* node)
{
	return (node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL);
}

template <class T>
Node<T>* BST<T>::getRightMostNode(Node<T>* node)
{
	Node<T>* cur = node;
	while (cur->right != NULL)
		cur = cur->right;
	return cur;
}

template <class T>
T BST<T>::remove(T val)
{
	Node<T>* del = findNode(val);
	if (del == NULL)
		assert(0);
	Node<T>* parent = findParent(val);
	if (isLeaf(del))
	{
		if (del == root)
			root = NULL;
		else
		{
			if (parent->right == del)
				parent->right = NULL;
			else
				parent->left = NULL;
		}
		delete del;
	}
	else if (isParentWithOneChild(del))
	{
		if (parent->right == del)
		{
			if (del->right != NULL)
				parent->right = del->right;
			else
				parent->right = del->left;
		}
		else
		{
			if (del->right != NULL)
				parent->left = del->right;
			else
				parent->left = del->left;
		}
		delete del;
	}
	else
	{
		Node<T>* highstLeftNode = getRightMostNode(del->left);
		del->data = remove(highstLeftNode->data);
	}
	return val;
}

template <class T>
void BST<T>::print(int order)
{
	switch (order)
	{
	case InOrder:
		printInOrder(root);
			break;
	case PreOrder:
		printPreOrder(root);
			break;
	case PostOrder:
		printPostOrder(root);
		break;
	default: 
		break;
	}
	cout << endl;
}

template <class T>
void BST<T>::printInOrder(Node<T>* node)
{
	if (node == NULL)
		return;
	printInOrder(node->left);
	cout << node->data << " ";
	printInOrder(node->right);
}

template <class T>
void BST<T>::printPreOrder(Node<T>* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	printPreOrder(node->left);
	printPreOrder(node->right);
}

template <class T>
void BST<T>::printPostOrder(Node<T>* node)
{
	if (node == NULL)
		return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	cout << node->data << " ";
}