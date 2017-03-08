
#include<iostream>
#include "list.h"
#include"stack.h"
#include"queue.h"
#include"Avltree.h"
#include"iterator.h"
#include"map.h"
#include"vector.h"
#include"set.h"
using namespace std;


void print_list(List<int> &list)
{
	List<int>::iterator it2 = list.begin();
	for (; it2 != list.end(); it2++)
		cout << (*it2) << ' ';
}


int main()
{
	List<int> l,h;
	cout << "l链表前插入元素1";
	l.push_front(1);
	cout << endl;
	cout << "l链表后插入元素2";
	l.push_back(2);
	cout << endl;
	cout << "l链表前插入元素6";
	l.push_front(6);
	cout << endl;
	cout << "l链表后插入元素4";
	l.push_back(4);
	cout << endl;
	cout << "l链表后插入元素9";
	l.push_back(9);
	cout << endl;
	cout << "l链表前插入元素3";
	l.push_front(3);
	cout << endl;
	cout << "l链表后插入元素0";
	l.push_back(0);
	cout << endl;
	cout << "l链表后插入元素7";
	l.push_back(7);
	cout << endl;
	cout << "h链表前插入元素1";
	h.push_front(1);
	cout << endl;
	cout << "h链表后插入元素2";
	h.push_back(2);
	cout << endl;
	cout << "h链表前插入元素6";
	h.push_front(6);
	cout << endl;
	cout << "h链表后插入元素4";
	h.push_back(4);
	cout << endl;
	cout << "h链表后插入元素9";
	h.push_back(9);
	cout << endl;
	cout << "h链表前插入元素3";
	h.push_front(3);
	cout << endl;
	cout << "h链表后插入元素0";
	h.push_back(0);
	cout << endl;
	cout << "h链表后插入元素7";
	l.push_back(7);
	cout << endl;
	if (l == h)
		cout << "两者相等!" << endl;
	else if (l != h)
		cout << "两者不相等!" << endl;
	cout << "打印链表:";
	print_list(l);
	cout << endl;

	List<int>::iterator it = l.begin();
	cout << "删除元素:";
	  it = l.erase(++it);
	  cout << endl;
	  cout << "在某元素后插入一个值3：";
	l.insert_after(it, 3);
	cout << endl;
	it++;
	cout << "在某元素前插入一个值5:";
	l.insert_before(it, 5);
	cout << endl;
	cout << "打印*it:";
	cout << (*it) << endl;
	cout << "输出链表l的长度:";
	cout << l.size() << endl;
	cout << "打印链表l:";
	print_list(l);
	cout << endl;

	cout << "定义链表m,复制链表l:";
	List<int> m(l);
	cout << "删除后一个元素:"<<endl;
	m.pop_back();
	cout << "删除前一个元素:"<<endl;
	m.pop_front();
	cout << "删除重复元素";
	m.unique();
	cout << endl;
	cout << "打印链表m:";
	print_list(m);
	cout << endl;

	cout << "定义链表n,复制链表m:";
	List<int> n = m;
	cout << "移除元素2:";
	n.remove(2);
	cout << endl;
	cout << "打印链表n:";
	print_list(n);
	cout << endl;
	l.clear();
	if (l.empty())
		cout << "已清空链表l"<<endl;
	h.clear();
	if (l.empty())
		cout << "已清空链表h" << endl;
	m.clear();
	if (l.empty())
		cout << "已清空链表m" << endl;
	n.clear();
	if (l.empty())
		cout << "已清空链表n" << endl;


	stack<int> p;
	stack<int> q;
	cout << "1 入栈" << endl;
	cout << "2 入栈" << endl;
	cout << "3 入栈" << endl;
	cout << "4 入栈" << endl;
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	cout << "栈的长度:";
	cout << p.size() << endl;
	cout << "从栈顶开始输出栈：" << endl;
	while (!p.empty())//判空
	{
		cout << p.top() << " 出栈" << endl;//输出栈顶
		q.push(p.top());
		p.pop();              //出栈;
	}
	cout << "栈的长度:";
	cout << p.size() << endl;
	cout << "判断栈是否为空：";
	if (p.empty())
		cout << "栈为空！" << endl;
	else
		cout << "栈不为空!" << endl;
	cout << "清空栈";
	p.clear();
	q.clear();
	cout << endl;
	queue<int> s;
	queue<int> t;
	cout << "1 入队列" << endl;
	cout << "2 入队列" << endl;
	cout << "3 入队列" << endl;
	cout << "4 入队列" << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "队列的长度：" << s.size() << endl;
	cout << "从队头输出队列：" << endl;
	while (!s.empty())
	{
		cout << s.front() << " 出队列" << endl;
		t.push(s.front());
		s.pop();
	}
	cout << "队列的长度：" << s.size() << endl;
	cout << "判断队列是否为空：";
	if (s.empty())
		cout << "队列为空！" << endl;
	else
		cout << "队列不为空!" << endl;
	cout << "清空队列";
	s.clear();
	t.clear();
	cout << endl;

	
		vector<int> g;
	int i;
	for (i = 0; i<10; i++) g.push_back(i);     //放入0-9的值
	g.push_back(10);                      //放入10
	g.pop_back();                         //提出10
	for (i = 0; i<g.size(); i++)
	{
		cout << g[i] << " ";                 //输出0 1 2 3 4 5 6 7 8 9
	}
	cout << endl;

	g.insert(g.begin() + 3, 10);               //在第4个位置插入10
	g.erase(g.begin() + 4);                   //删除第5个位置的值
	g.erase(g.begin() + 4, g.begin() + 6);       //删除5和6位置的值

	vector<int>::iterator it1;               //迭代器
	for (it1 = g.begin(); it1 != g.end(); it1++)       //输出0 1 2 10 6 7 8 9
	{
		cout << *it1 << " ";
	}
	cout << endl;
	g.clear();                         //清空a
	cout << g.size() << endl;      //输出0
	
set<int> r;        //定义一个set的s
	r.insert(10);      //插入10
	r.insert(14);
	r.insert(9);
	r.insert(13);
	r.insert(15);
	r.insert(12);
	r.insert(11);
	r.erase(11);      //删除11

	set<int>::iterator ir;     //定义一个ir的迭代器
	for (ir = r.begin(); ir != r.end(); ir++)   //输出set里所有的值
	{
		cout << *ir << " ";
	}
	cout << *ir << endl;
	//输出9 10 12 13 14 15
	r.erase(r.find(12));       //找到12的节点并删除

	cout << r.size() << endl;      //输出现在有多少个值 5
	r.clear();                  //清除set a；
	cout << r.size() << endl;      //现在有多少个值 0

	map<int, char> mp;
	pir<int, char> a(4, 'a');   //定义一个pir的a
	pir<int, char> b(8, 'c');
	pir<int, char> c(6, 'd');
	pir<int, char> d(5, 'e');
	mp.insert(a);              //把a放入mp
	mp.insert(b);
	mp.insert(c);
	mp.insert(d);
	mp.erase(a);               //把a提出
	map<int, char>::iterator ir1;     //map 的迭代器
	for (ir1 = mp.begin(); ir1 != mp.end(); ir1++)   //输出所有值
	{
		cout << (*ir1).first << " " << (*ir1).second << endl;;
	}
	cout << (*ir1).first << " " << (*ir1).second << endl;

	mp.erase(mp.find(d));         //找到d并把它删除

	cout << mp.size() << endl;       //输出还有几个元素 2
	mp.clear();                   //清除mp
	cout << mp.size() << endl;        //输出还有几个元素 0

	return 0;
}