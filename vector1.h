#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
using namespace std;

//块中元素数目（线性增长）
#define BLOCKSIZE 512

template<typename T>
class Block
{
public:
	Block<T> *last;//用于连接前一个段
	T *now;//连接数组
	Block<T> *next;//用于连接下一个段
	int blocksize;
};

template<typename T>
class Vector
{
public:
	Vector();
	~Vector();
	void push_back(T data);
	void pop_back();
	int size();
	bool empty();
	T at(int index);
	void clear();
	void error(string e);
	void erase(int pos);
	void erase(int beg, int end);
	int capacity();
	void reserve(int size);

private:
	Block<T> data;
	Block<T> *cBlock;
	int top;
	int amount;
	int capacity_size;
};

//初始化一个段，大小为BLOCKSIZE
template<typename T>
Vector<T>::Vector()
{
	data.last = NULL;
	data.now = new T[BLOCKSIZE];
	data.next = NULL;
	data.blocksize = BLOCKSIZE;
	cBlock = &data;
	top = 0;
	amount = 0;
	capacity_size = BLOCKSIZE;
}

template<typename T>
Vector<T>::~Vector()
{
	while (amount > 0) pop_back();
}

template<typename T>
void Vector<T>::push_back(T data)
{
	if (top == cBlock->blocksize)
	{
		//之后没有段
		if (cBlock->next == NULL)
		{
			//创建一个新段，默认大小为BLOCKSIZE
			Block<T> *newBlock = new Block<T>;
			newBlock->now = new T[BLOCKSIZE];
			newBlock->blocksize = BLOCKSIZE;
			capacity_size = capacity_size + BLOCKSIZE;

			//建立当前段与新段的联系
			cBlock->next = newBlock;
			newBlock->last = cBlock;
			newBlock->next = NULL;
		}

		//将组合式栈顶指针移至新段开头
		cBlock = cBlock->next;
		top = 0;
	}

	//压入新元素
	*(cBlock->now + top) = data;

	//将组合式栈顶指针移至当前段的下一位
	top++;

	//元素个数加一
	amount++;
}

template<typename T>
void Vector<T>::pop_back()
{
	Block<T> *p;

	//如果栈为空，就报错
	if (size == 0) error("栈为空，没有元素可以出栈!");

	if (top == 0)
	{
		//将组合式栈顶指针移至上一段的结尾
		p = cBlock->next;
		cBlock = cBlock->last;
		delete cBlock->next;
		cBlock->next = p;
		top = cBlock->blocksize;
		capacity_size = capacity_size - cBlock->blocksize;
	}

	//如果栈不为空，就将组合式栈顶指针移至当前段的上一位
	top--;

	//元素个数减一
	amount--;
}

template<typename T>
int Vector<T>::size()
{
	return amount;
}

template<typename T>
bool Vector<T>::empty()
{
	if (amount == 0) return true; else return false;
}

template<typename T>
T Vector<T>::at(int index)
{
	if (index < 0) error("下标超界!");

	Block<T> *current = &data;

	while (index / current->blocksize > 0)
	{
		index = index - current->blocksize;
		current = current->next;
		if (current == NULL) error("下标超界!");
	}

	return *(current->now + index);
}

template<typename T>
void Vector<T>::clear()
{
	while (amount > 0) pop_back();
}


template<typename T>
void Vector<T>::error(string e)
{
	cout << e << endl;
	exit(0);
}

template<typename T>
void Vector<T>::erase(int pos)
{
	erase(pos, pos);
}

template<typename T>
void Vector<T>::erase(int beg, int end)
{
	Vector p;
	int i, size;

	size = this->amount;
	if ((beg < 0) || (beg >= this->amount)) error("元素不存在");
	if ((end < 0) || (end >= this->amount)) error("元素不存在");
	if (beg > end) error("格式错误");

	//拷贝end之后的所有元素
	for (i = end + 1; i<size; i++) p.push_back(this->at(i));
	//删除beg后的所有元素
	for (i = size - 1; i >= beg; i--) this->pop_back();
	//将end之后的元素拷贝回来
	size = p.amount;
	for (i = 0; i<size; i++) this->push_back(p.at(i));
}

template<typename T>
int Vector<T>::capacity()
{
	return capacity_size;
}

template<typename T>
void Vector<T>::reserve(int size)
{
	if (size < 0) error("预留空间不能小于0");

	Vector p;

	//把数据交给p
	this->swap(&p);
	//释放初始化的空间
	delete this->data.now;
	//申请size大小的空间
	this->data.now = new T[size];
	this->data.blocksize = size;
	this->cBlock = &this->data;
	this->capacity_size = size;

	//拷贝原来的数据，舍弃size以外的
	int i, max;
	if (p.amount < size) max = p.amount; else max = size;
	for (i = 0; i<max; i++) this->push_back(p.at(i));

	//释放p
	p.clear();
}

#endif
