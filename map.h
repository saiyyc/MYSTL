#ifndef _map_
#define _map_

#include"iterator.h"
template <class T1, class T2>
class pir
{
public:
	T1 first;
	T2 second;
	pir() :first(T1()), second(T2()){}
	pir(const T1& a, const T2& b) :first(a), second(b){}
	bool operator < (pir<T1, T2>);
	bool operator > (pir<T1, T2>);
	void operator = (pir<T1, T2>);
	bool operator != (pir<T1, T2>);
	bool operator == (pir<T1, T2>);
};

template <class T1, class T2>
bool pir<T1, T2>::operator<(pir<T1, T2> x)
{
	return first<x.first;
}

template <class T1, class T2>
bool pir<T1, T2>::operator>(pir<T1, T2> x)
{
	return first>x.first;
}

template <class T1, class T2>
void pir<T1, T2>::operator=(pir<T1, T2> x)
{
	first = x.first;
	second = x.second;
}

template <class T1, class T2>
bool pir<T1, T2>::operator==(pir<T1, T2> x)
{
	if (first != x.first || second != x.second) return 0;
	else return 1;
}

template <class T1, class T2>
bool pir<T1, T2>::operator!=(pir<T1, T2> x)
{
	if (first != x.first || second != x.second) return 1;
	else return 0;
}

template <class T1, class T2>
class map
{
public:
	typedef pir<T1, T2> T;
	AvlTree<T>* t;
	typedef iter<T> iterator;
	map();
	void insert(T);
	int size();
	void clear();
	void erase(AvlTreeNode<T>*);
	AvlTreeNode<T>* erase(T item)
	{
		AvlTreeNode<T>* x = t->Search(item);
		t->Delete(item);
		return x;
	}
	AvlTreeNode<T>* find(T item)
	{
		AvlTreeNode<T>* x = t->Search(item);
		return x;
	}
	AvlTreeNode<T>* begin()
	{
		return t->mostLeft();
	}

	AvlTreeNode<T>* end()
	{
		return t->mostRight();
	}
};

template <class T1, class T2>
map<T1, T2>::map()
{
	t = new AvlTree<T>();
}

template <class T1, class T2>
void map<T1, T2>::insert(T x)
{
	t->insert(x);
}

template <class T1, class T2>
int map<T1, T2>::size()
{
	return t->size;
}

template <class T1, class T2>
void map<T1, T2>::clear()
{
	t->Destory(t->root);
	t->size = 0;
}

template <class T1, class T2>
void map<T1, T2>::erase(AvlTreeNode<T>* item)
{
	t->Delete(item->date);
}

#endif