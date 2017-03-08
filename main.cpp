
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
	cout << "l����ǰ����Ԫ��1";
	l.push_front(1);
	cout << endl;
	cout << "l��������Ԫ��2";
	l.push_back(2);
	cout << endl;
	cout << "l����ǰ����Ԫ��6";
	l.push_front(6);
	cout << endl;
	cout << "l��������Ԫ��4";
	l.push_back(4);
	cout << endl;
	cout << "l��������Ԫ��9";
	l.push_back(9);
	cout << endl;
	cout << "l����ǰ����Ԫ��3";
	l.push_front(3);
	cout << endl;
	cout << "l��������Ԫ��0";
	l.push_back(0);
	cout << endl;
	cout << "l��������Ԫ��7";
	l.push_back(7);
	cout << endl;
	cout << "h����ǰ����Ԫ��1";
	h.push_front(1);
	cout << endl;
	cout << "h��������Ԫ��2";
	h.push_back(2);
	cout << endl;
	cout << "h����ǰ����Ԫ��6";
	h.push_front(6);
	cout << endl;
	cout << "h��������Ԫ��4";
	h.push_back(4);
	cout << endl;
	cout << "h��������Ԫ��9";
	h.push_back(9);
	cout << endl;
	cout << "h����ǰ����Ԫ��3";
	h.push_front(3);
	cout << endl;
	cout << "h��������Ԫ��0";
	h.push_back(0);
	cout << endl;
	cout << "h��������Ԫ��7";
	l.push_back(7);
	cout << endl;
	if (l == h)
		cout << "�������!" << endl;
	else if (l != h)
		cout << "���߲����!" << endl;
	cout << "��ӡ����:";
	print_list(l);
	cout << endl;

	List<int>::iterator it = l.begin();
	cout << "ɾ��Ԫ��:";
	  it = l.erase(++it);
	  cout << endl;
	  cout << "��ĳԪ�غ����һ��ֵ3��";
	l.insert_after(it, 3);
	cout << endl;
	it++;
	cout << "��ĳԪ��ǰ����һ��ֵ5:";
	l.insert_before(it, 5);
	cout << endl;
	cout << "��ӡ*it:";
	cout << (*it) << endl;
	cout << "�������l�ĳ���:";
	cout << l.size() << endl;
	cout << "��ӡ����l:";
	print_list(l);
	cout << endl;

	cout << "��������m,��������l:";
	List<int> m(l);
	cout << "ɾ����һ��Ԫ��:"<<endl;
	m.pop_back();
	cout << "ɾ��ǰһ��Ԫ��:"<<endl;
	m.pop_front();
	cout << "ɾ���ظ�Ԫ��";
	m.unique();
	cout << endl;
	cout << "��ӡ����m:";
	print_list(m);
	cout << endl;

	cout << "��������n,��������m:";
	List<int> n = m;
	cout << "�Ƴ�Ԫ��2:";
	n.remove(2);
	cout << endl;
	cout << "��ӡ����n:";
	print_list(n);
	cout << endl;
	l.clear();
	if (l.empty())
		cout << "���������l"<<endl;
	h.clear();
	if (l.empty())
		cout << "���������h" << endl;
	m.clear();
	if (l.empty())
		cout << "���������m" << endl;
	n.clear();
	if (l.empty())
		cout << "���������n" << endl;


	stack<int> p;
	stack<int> q;
	cout << "1 ��ջ" << endl;
	cout << "2 ��ջ" << endl;
	cout << "3 ��ջ" << endl;
	cout << "4 ��ջ" << endl;
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	cout << "ջ�ĳ���:";
	cout << p.size() << endl;
	cout << "��ջ����ʼ���ջ��" << endl;
	while (!p.empty())//�п�
	{
		cout << p.top() << " ��ջ" << endl;//���ջ��
		q.push(p.top());
		p.pop();              //��ջ;
	}
	cout << "ջ�ĳ���:";
	cout << p.size() << endl;
	cout << "�ж�ջ�Ƿ�Ϊ�գ�";
	if (p.empty())
		cout << "ջΪ�գ�" << endl;
	else
		cout << "ջ��Ϊ��!" << endl;
	cout << "���ջ";
	p.clear();
	q.clear();
	cout << endl;
	queue<int> s;
	queue<int> t;
	cout << "1 �����" << endl;
	cout << "2 �����" << endl;
	cout << "3 �����" << endl;
	cout << "4 �����" << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "���еĳ��ȣ�" << s.size() << endl;
	cout << "�Ӷ�ͷ������У�" << endl;
	while (!s.empty())
	{
		cout << s.front() << " ������" << endl;
		t.push(s.front());
		s.pop();
	}
	cout << "���еĳ��ȣ�" << s.size() << endl;
	cout << "�ж϶����Ƿ�Ϊ�գ�";
	if (s.empty())
		cout << "����Ϊ�գ�" << endl;
	else
		cout << "���в�Ϊ��!" << endl;
	cout << "��ն���";
	s.clear();
	t.clear();
	cout << endl;

	
		vector<int> g;
	int i;
	for (i = 0; i<10; i++) g.push_back(i);     //����0-9��ֵ
	g.push_back(10);                      //����10
	g.pop_back();                         //���10
	for (i = 0; i<g.size(); i++)
	{
		cout << g[i] << " ";                 //���0 1 2 3 4 5 6 7 8 9
	}
	cout << endl;

	g.insert(g.begin() + 3, 10);               //�ڵ�4��λ�ò���10
	g.erase(g.begin() + 4);                   //ɾ����5��λ�õ�ֵ
	g.erase(g.begin() + 4, g.begin() + 6);       //ɾ��5��6λ�õ�ֵ

	vector<int>::iterator it1;               //������
	for (it1 = g.begin(); it1 != g.end(); it1++)       //���0 1 2 10 6 7 8 9
	{
		cout << *it1 << " ";
	}
	cout << endl;
	g.clear();                         //���a
	cout << g.size() << endl;      //���0
	
set<int> r;        //����һ��set��s
	r.insert(10);      //����10
	r.insert(14);
	r.insert(9);
	r.insert(13);
	r.insert(15);
	r.insert(12);
	r.insert(11);
	r.erase(11);      //ɾ��11

	set<int>::iterator ir;     //����һ��ir�ĵ�����
	for (ir = r.begin(); ir != r.end(); ir++)   //���set�����е�ֵ
	{
		cout << *ir << " ";
	}
	cout << *ir << endl;
	//���9 10 12 13 14 15
	r.erase(r.find(12));       //�ҵ�12�Ľڵ㲢ɾ��

	cout << r.size() << endl;      //��������ж��ٸ�ֵ 5
	r.clear();                  //���set a��
	cout << r.size() << endl;      //�����ж��ٸ�ֵ 0

	map<int, char> mp;
	pir<int, char> a(4, 'a');   //����һ��pir��a
	pir<int, char> b(8, 'c');
	pir<int, char> c(6, 'd');
	pir<int, char> d(5, 'e');
	mp.insert(a);              //��a����mp
	mp.insert(b);
	mp.insert(c);
	mp.insert(d);
	mp.erase(a);               //��a���
	map<int, char>::iterator ir1;     //map �ĵ�����
	for (ir1 = mp.begin(); ir1 != mp.end(); ir1++)   //�������ֵ
	{
		cout << (*ir1).first << " " << (*ir1).second << endl;;
	}
	cout << (*ir1).first << " " << (*ir1).second << endl;

	mp.erase(mp.find(d));         //�ҵ�d������ɾ��

	cout << mp.size() << endl;       //������м���Ԫ�� 2
	mp.clear();                   //���mp
	cout << mp.size() << endl;        //������м���Ԫ�� 0

	return 0;
}