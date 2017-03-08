#include"list.h"
template <class T, class Sequence = List<T> >
class queue
{
protected:
	Sequence c;   
	friend bool operator== (const queue& x, const queue& y);
	/*bool operator== (const queue& x){
	return c == x.c;
}
	bool operator< (const queue& x){
	return c < x.c;
}
*/
public:
	bool empty()  { return c.empty(); }
	int size()  { return c.size(); }
	T front() { return c.front(); }
	T back() { return c.back(); }
	void push(const T& x) { c.push_back(x); }
	void pop() { c.pop_front(); }
	void clear(){ c.clear(); }
};

template <class T, class Sequence>
bool operator==(const queue<T, Sequence>& x, const queue<T, Sequence>& y)
{
	return x.c == y.c;
}