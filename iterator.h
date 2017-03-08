#ifndef _myiterator_
#define _myiterator_
#include"Avltree.h"
template <class T>
class iter
{
public:
	AvlTreeNode<T>* node;
	iter(){};
	iter(AvlTreeNode<T>* x) :node(x){};
	bool operator == (iter x){ return node == x.node; }
	bool operator != (iter x){ return node != x.node; }
	T operator * (){ return node->date; }
	AvlTreeNode<T>* operator -> (){ return &(operator*()); }
	iter<T>& operator ++ ();
	iter<T> operator ++ (int);
	iter<T>& operator -- ();
	iter<T> operator -- (int);
};

template <class T>
iter<T>& iter<T>::operator++()
{
	if (node->right != NULL)
	{
		node = node->right;
		while (node->left != NULL) node = node->left;
	}
	else
	{
		AvlTreeNode<T>* y = node->parent;
		while (node == y->right)
		{
			node = y;
			y = y->parent;
		}
		if (node->right != y) node = y;
	}
	return *this;
}

template <class T>
iter<T> iter<T>::operator ++ (int)
{
	iter<T> tmp = *this;
	++*this;
	return tmp;
}

template <class T>
iter<T>& iter<T>::operator--()
{
	if (node->parent->parent == node) node = node->right;
	else if (node->left != NULL)
	{
		AvlTreeNode<T>* y = node->left;
		while (y->right != NULL) y = y->right;
		node = y;
	}
	else
	{
		AvlTreeNode<T>* y = node->parent;
		while (node == y->left)
		{
			node = y;
			y = y->parent;
		}
		node = y;
	}
}

template <class T>
iter<T> iter<T>::operator -- (int)
{
	iterator<T> tmp = *this;
	--*this;
	return tmp;
}

#endif