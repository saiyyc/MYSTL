#ifndef __LIST_H
#define __LIST_H


#include <iostream>
#include <assert.h>
using namespace std;

template<class T> class List;
template<class T>
class List_node {
	friend class List<T>;
public:
	List_node(){}
	List_node(const T& da) :data(da), next(0), prev(0){}

	T data;
	List_node *next;
	List_node *prev;
};

//链表类
template<class T>
class List
{
public:
	class iterator{
	public:
		iterator() :ptr(0){}
		iterator(List_node<T> *node) :ptr(node){}
		iterator(const iterator& copy) :ptr(copy.ptr){}
		iterator& operator = (const iterator &other)
		{
			if (&other == this)
				return *this;
			ptr = other.ptr;
		}

		iterator& operator ++()
		{
			ptr = ptr->next;
			return *this;
		}

		iterator& operator --()
		{
			ptr = ptr->prev;
			return *this;
		}

		iterator operator --(int)
		{
			iterator temp = *this;
			ptr = ptr->prev;
			return temp;
		}

		iterator operator ++(int)
		{
			iterator temp = *this;
			ptr = ptr->next;
			return temp;
		}
		//重载==
		bool operator == (const iterator& it)
		{
			return ptr == it.ptr;
		}
		//重载!=
		bool operator != (const iterator& it)
		{
			return ptr != it.ptr;
		}
		//重载*
		T operator * ()  
		{
			return ptr->data;
		}
		//重载->
		T *operator ->()
		{
			return &ptr->data;
		}

		List_node<T> *ptr;
	};
public:
	List();
	List(List<T>& list);
	~List();
	List& operator = (List& list);

	void clear();

	//删除元素
	iterator erase(iterator &it)
	{
		if (it == end()){
			cout << "Cannot delete end node, it is a false node\n";
			return it;
		}
		iterator returniter(it);
		returniter++;
		it.ptr->next->prev = it.ptr->prev;
		it.ptr->prev->next = it.ptr->next;
		delete it.ptr;
		it.ptr = 0;
		count--;
		return returniter;
	}
	void push_back(const T &da); //向后插入

	void push_front(const T &da); //向前插入

	void pop_back();   //向后删除

	void pop_front();   //向前删除

//	friend bool operator==(const List<T>& x, const List<T>& y);

	//重载== 判断两个链表是否相等
	bool operator== (List<T>& x)
	{
		iterator first1 = begin();
		iterator first2 = x.begin();
		iterator last = end();
		if (size() != x.size()) 
			return false;
		else
		{
			while (first1 != last){
				if (*first1 != *first2)
					break;
				first1++;
				first2++;
			}
		}
		if (first1 == end())
			return true;
		else
			return false;
	}
	//重载!= 判断两个链表是否不等
	bool operator!= (List<T>& x)
	{
		iterator first1 = begin();
		iterator first2 = x.begin();
		iterator last = end();
		if (size() != x.size())
			return true;
		else
		{
			while (first1 != last){
				if (*first1 != *first2)
					break;
				first1++;
				first2++;
			}
		}
		if (first1 != end())
			return true;
		else
			return false;
	}
	T front()
	{
		return *begin();
	}
	T back(){
		return *(--end());
	}
	int size(){ return count; }    //大小

	bool empty(){ return count == 0; }//判空

	iterator begin(){ return iterator(last->next); }//获取链表开始元素

	iterator end(){ return iterator(last); }//获取链表末尾元素

	void insert_before(iterator &it, const T& da);//向前插入

	void insert_after(iterator &it, const T& da);//向后插入

//	void transfer(iterator position, iterator first, iterator last);
	
	void unique();//删除重复元素
	
	void remove(const T &value);// 移除与某值相同的元素
	
	void merge(List&);//有序归并
	void reverse();
	void sort();
	void swap(List&, List&);

private:

	List_node<T> *last;
	int count;
	List_node<T> *Malloc(const T& da);
	void deMalloc(List_node<T> *node);
};

template<class T>
List_node<T> *List<T>::Malloc(const T& da)//分配动态空间
{
	List_node<T> *node = new List_node<T>(da);
	assert(node != 0);
	return node;
}

template<class T>
void List<T>::deMalloc(List_node<T> *node)//删除动态空间
{
	if (node)
		delete node;
}

template<class T>
List<T>::List() :count(0)
{
	List_node<T> *node = Malloc(0);
	node->next = node->prev = node;

	last = node;
}

template<class T>
List<T>& List<T>::operator = (List<T>& list)
{
	if (&list == this)
		return *this;

	clear();
	iterator it = list.begin();
	iterator it_end = list.end();
	for (; it != it_end; it++)
		push_back(*it);

	return *this;
}

template<class T>
List<T>::List(List<T>& list) :count(0)
{
	List_node<T> *node = Malloc(0);
	node->next = node->prev = node;

	last = node;
	iterator it = list.begin();
	iterator it_end = list.end();
	for (; it != it_end; it++)
		push_back(*it);
}

template<class T>
void List<T>::remove(const T &value)
{
	iterator first = begin();
	iterator last = end();
	while (first != last)
	{
		iterator next = first;
		++next;
		if (*first == value)
			erase(first);
		first = next;
	}
}

template<class T>
void List<T>::unique()
{
	iterator first = begin();
	iterator last = end();
	if (first == last) return;
	iterator next = first;
	while (++next != last)
	{
		if (*first == *next)
			erase(next);
		else
			first = next;
		next = first;
	}
}
template<class T>
void List<T>::pop_front() { erase(begin()); }
template<class T>
// 删除链表最后一个结点
void List<T>::pop_back()
{
	iterator tmp = end();
	erase(--tmp);
}
template<class T>
void List<T>::clear()
{
	List_node<T>* first = last->next;
	while (first != last)
	{
		List_node<T>* temp = first;
		first = first->next;
		delete temp;
	}
	last->next = last;
	last->prev = last;
	count = 0;
}

template<class T>
List<T>::~List()
{
	clear();
	deMalloc(last);
}


template<class T>
void List<T>::push_front(const T& da)
{
	List_node<T> *node = Malloc(da);

	last->next->prev = node;
	node->prev = last;
	node->next = last->next;
	last->next = node;
	count++;
}

template<class T>
void List<T>::push_back(const T& da)
{
	List_node<T> *node = Malloc(da);
	last->prev->next = node;
	node->prev = last->prev;
	last->prev = node;
	node->next = last;

	count++;
}


template<class T>
void List<T>::insert_before(iterator &it, const T& da)
{
	List_node<T> *node = Malloc(da);
	it.ptr->prev->next = node;
	node->prev = it.ptr->prev;
	node->next = it.ptr;
	it.ptr->prev = node;
	count++;
}

template<class T>
void List<T>::insert_after(iterator &it, const T& da)
{
	List_node<T> *node = Malloc(da);

	it.ptr->next->prev = node;
	node->next = it.ptr->next;
	it.ptr->next = node;
	node->prev = it.ptr;
	count++;
}

template <class T>
void swap(List<T>& x, List<T>& y) {
	x.swap(y);
}


#endif
