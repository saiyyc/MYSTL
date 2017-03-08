#ifndef _set_
#define _set_

#include"iterator.h"
template <class T>
class set
{
public:
	typedef iter<T> iterator;
	AvlTree<T>* t;
	set();
	void insert(T);
	int size();
	void clear();
	void erase(AvlTreeNode<T>*);
	AvlTreeNode<T>* erase(T);
	AvlTreeNode<T>* find(T);
	AvlTreeNode<T>* begin();
	AvlTreeNode<T>* end();
};

template<class T>
set<T>::set()
{
	t = new AvlTree<T>();
}

template <class T>
void set<T>::insert(T item)
{
	t->insert(item);
}

template <class T>
int set<T>::size()
{
	return t->size;
}

template <class T>
void set<T>::clear()
{
	t->Destory(t->root);
	t->size = 0;
}

template <class T>
void set<T>::erase(AvlTreeNode<T>* item)
{
	t->Delete(item->date);
}

template <class T>
AvlTreeNode<T>* set<T>::erase(T item)
{
	AvlTreeNode<T>* x = t->Search(item);
	t->Delete(item);
	return x;
}

template <class T>
AvlTreeNode<T>* set<T>::find(T item)
{
	AvlTreeNode<T>* x = t->Search(item);
	return x;
}

template <class T>
AvlTreeNode<T>* set<T>::begin()
{
	return t->mostLeft();
}

template <class T>
AvlTreeNode<T>* set<T>::end()
{
	return t->mostRight();
}
#endif