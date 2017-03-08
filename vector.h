#ifndef  _my_
#define _my_

#include<iostream>
using namespace std;

template <class T>
class vector
{
public:
	typedef T* iterator;
	iterator start;
	iterator finish;
	static int i;
	T* a;
	int size_;
	vector();
	~vector();
	int size();
	bool empty();
	void push_back(T);
	void pop_back();
	T& operator[](int);
	iterator begin();
	iterator end();
	void insert(T*, T);
	void erase(T*);
	void erase(T*, T*);
	void clear();
};

template <class T>
int vector<T>::i = -1;

template <class T>
vector<T>::vector()
{
	size_ = 10;
	a = new T[size_];
	start = finish = a;
}

template <class T>
vector<T>::~vector()
{
	size_ = 0;
	start = finish = a;
}

template <class T>
int vector<T>::size()
{
	return i + 1;
}

template <class T>
bool vector<T>::empty()
{
	if (i == -1)return 1;
	return 0;
}

template <class T>
void vector<T>::push_back(T x)
{
	if (i == size_)
	{
		int j;
		T* b = new T[size_];
		for (j = 0; j<size_; j++) b[j] = a[j];
		T* a = new T[size_ + 10];
		for (j = 0; j<size_; j++) a[j] = b[j];
		size_ += 10;
		delete[] b;
	}
	i++;
	a[i] = x;
	start = a;
	finish = a + i + 1;
}

template <class T>
void vector<T>::pop_back()
{
	i--;
	finish--;
}

template <class T>
T& vector<T>::operator[](int j)
{
	return a[j];
}

template <class T>
T* vector<T>::begin()
{
	return start;
}

template <class T>
T* vector<T>::end()
{
	return finish;
}

template <class T>
void vector<T>::insert(T* w, T x)
{
	if (i == size_)
	{
		int j;
		T* b = new T[size_];
		for (j = 0; j<size_; j++) b[j] = a[j];
		T* a = new T[size_ + 10];
		for (j = 0; j<size_; j++) a[j] = b[j];
		size_ += 10;
		delete[] b;
	}
	T* it;
	i++;
	start = a;
	finish = a + i + 1;
	for (it = finish - 1; it != w; it--)
		*it = *(it - 1);
	*it = x;
}

template <class T>
void vector<T>::erase(T* w)
{
	i--;
	finish--;
	T* it;
	for (it = w; it<finish; it++)
	{
		*it = *(it + 1);
	}
}

template <class T>
void vector<T>::erase(T* b, T* e)
{
	int n = e - b;
	i -= (n);
	finish -= (n);
	T* it;
	for (it = b; it<finish; it++)
	{
		*it = *(it + n);
	}
}

template <class T>
void vector<T>::clear()
{
	erase(begin(), end());
}


#endif