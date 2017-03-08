#include"list.h"

template <class T, class Sequence = List<T> >
class stack
{
protected:
	Sequence c;   // 容器
	
public:
	T front() { return c.front(); }
	// 判断stack是否为空
	bool empty()  { return c.empty(); }
	// stack中元素个数
	int size()  { return c.size(); }

	// 返回栈顶元素, 注意这里返回的是引用!!!
	T top() { return c.back(); }
	
	// 在栈顶追加新元素
	void push(const T& x) { c.push_back(x); }

	// 移除栈顶元素, 注意不返回元素的引用,
	void pop() { c.pop_back(); }

	void clear(){
		c.clear();
	}

    // 判断两个stack是否相等
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



