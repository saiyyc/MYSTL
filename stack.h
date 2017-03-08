#include"list.h"

template <class T, class Sequence = List<T> >
class stack
{
protected:
	Sequence c;   // ����
	
public:
	T front() { return c.front(); }
	// �ж�stack�Ƿ�Ϊ��
	bool empty()  { return c.empty(); }
	// stack��Ԫ�ظ���
	int size()  { return c.size(); }

	// ����ջ��Ԫ��, ע�����ﷵ�ص�������!!!
	T top() { return c.back(); }
	
	// ��ջ��׷����Ԫ��
	void push(const T& x) { c.push_back(x); }

	// �Ƴ�ջ��Ԫ��, ע�ⲻ����Ԫ�ص�����,
	void pop() { c.pop_back(); }

	void clear(){
		c.clear();
	}

    // �ж�����stack�Ƿ����
/*	bool operator== (const stack& x)
	{	
		T first1 = front();
		T first2 = x.front();
		T last = x.top();
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
		if (*first1 == top())
			return true;
		else
			return false;
	}*/
};



