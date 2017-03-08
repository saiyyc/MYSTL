#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
using namespace std;

//����Ԫ����Ŀ������������
#define BLOCKSIZE 512

template<typename T>
class Block
{
public:
	Block<T> *last;//��������ǰһ����
	T *now;//��������
	Block<T> *next;//����������һ����
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

//��ʼ��һ���Σ���СΪBLOCKSIZE
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
		//֮��û�ж�
		if (cBlock->next == NULL)
		{
			//����һ���¶Σ�Ĭ�ϴ�СΪBLOCKSIZE
			Block<T> *newBlock = new Block<T>;
			newBlock->now = new T[BLOCKSIZE];
			newBlock->blocksize = BLOCKSIZE;
			capacity_size = capacity_size + BLOCKSIZE;

			//������ǰ�����¶ε���ϵ
			cBlock->next = newBlock;
			newBlock->last = cBlock;
			newBlock->next = NULL;
		}

		//�����ʽջ��ָ�������¶ο�ͷ
		cBlock = cBlock->next;
		top = 0;
	}

	//ѹ����Ԫ��
	*(cBlock->now + top) = data;

	//�����ʽջ��ָ��������ǰ�ε���һλ
	top++;

	//Ԫ�ظ�����һ
	amount++;
}

template<typename T>
void Vector<T>::pop_back()
{
	Block<T> *p;

	//���ջΪ�գ��ͱ���
	if (size == 0) error("ջΪ�գ�û��Ԫ�ؿ��Գ�ջ!");

	if (top == 0)
	{
		//�����ʽջ��ָ��������һ�εĽ�β
		p = cBlock->next;
		cBlock = cBlock->last;
		delete cBlock->next;
		cBlock->next = p;
		top = cBlock->blocksize;
		capacity_size = capacity_size - cBlock->blocksize;
	}

	//���ջ��Ϊ�գ��ͽ����ʽջ��ָ��������ǰ�ε���һλ
	top--;

	//Ԫ�ظ�����һ
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
	if (index < 0) error("�±곬��!");

	Block<T> *current = &data;

	while (index / current->blocksize > 0)
	{
		index = index - current->blocksize;
		current = current->next;
		if (current == NULL) error("�±곬��!");
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
	if ((beg < 0) || (beg >= this->amount)) error("Ԫ�ز�����");
	if ((end < 0) || (end >= this->amount)) error("Ԫ�ز�����");
	if (beg > end) error("��ʽ����");

	//����end֮�������Ԫ��
	for (i = end + 1; i<size; i++) p.push_back(this->at(i));
	//ɾ��beg�������Ԫ��
	for (i = size - 1; i >= beg; i--) this->pop_back();
	//��end֮���Ԫ�ؿ�������
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
	if (size < 0) error("Ԥ���ռ䲻��С��0");

	Vector p;

	//�����ݽ���p
	this->swap(&p);
	//�ͷų�ʼ���Ŀռ�
	delete this->data.now;
	//����size��С�Ŀռ�
	this->data.now = new T[size];
	this->data.blocksize = size;
	this->cBlock = &this->data;
	this->capacity_size = size;

	//����ԭ�������ݣ�����size�����
	int i, max;
	if (p.amount < size) max = p.amount; else max = size;
	for (i = 0; i<max; i++) this->push_back(p.at(i));

	//�ͷ�p
	p.clear();
}

#endif
