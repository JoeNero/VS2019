/*
������	:	XTT
����	:	set����
			set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

			set���������������ظ���Ԫ��
			multiset�������������ظ���Ԫ��

			set������������ʱ��insert
			set�����������ݵ����ݻ��Զ�����

			size();		--����������Ԫ�ص���Ŀ
			empty();	--�ж������Ƿ�Ϊ��
			swap();		--����������������

			find(key);  --����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
			count(key); --ͳ��key��Ԫ�ظ���
			erase(key)	--����keyԪ��

ʱ��	:	2020/01/08
*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <set>
using namespace std;

void test01();
void test02();

void printSet(set<int>&);
void printMultiset(multiset<int>&);

int main()
{

	//test01();
	test02();
	system("pause");
	return 0;
}

/*
����: 	- test01()
		@param
����	:	set����demo
ʾ��	: 
*/
void test01()
{
	set<int> s1;
	s1.insert(40);
	s1.insert(20);
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(30);
	printSet(s1);
	
	//��������
	set<int> s2(s1);
	printSet(s2);

	s1.erase(1);

	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "��Ԫ��pos=" << *pos << "��ַ ��" << &pos << endl;
	}
	else
	{
		cout << "δ�и�Ԫ��" << endl;
	}
	cout << "count(2) = " << s1.count(2) << endl;
	s1.swap(s2);
	cout << "����s1��s2" << endl;
	cout << "s1:" << endl;
	printSet(s1);
	cout << "s1:" << endl;
	printSet(s2);

}

/*
����: 	- test02()
		@param
����	:	multiset����demo
ʾ��	:
*/
void test02()
{
	multiset<int> s1;
	s1.insert(40);
	s1.insert(20);
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(3);
	printMultiset(s1);

	//��������
	multiset<int> s2(s1);
	printMultiset(s2);

	s1.erase(1);

	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "��Ԫ��pos=" << *pos << "��ַ ��" << &pos << endl;
	}
	else
	{
		cout << "δ�и�Ԫ��" << endl;
	}
	cout << "count(2) = " << s1.count(2) << endl;
	s1.swap(s2);
	cout << "����s1��s2" << endl;
	cout << "s1:" << endl;
	printMultiset(s1);
	cout << "s1:" << endl;
	printMultiset(s2);
}
/*
����: 	- ��ӡ����
		@set<int>& s
����	:
ʾ��	:	printSet(s);
*/
void printSet(set<int>& s)
{
	if (s.empty())
	{
		cout << "��ӡset����Ϊ��";
		return;
	}
	else
	{
		for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		{
			cout << *it << " ";
		}
		cout << "size = " << s.size();
	}
	cout << endl;
}

void printMultiset(multiset<int>& s)
{
	if (s.empty())
	{
		cout << "��ӡset����Ϊ��";
		return;
	}
	else
	{
		for (multiset<int>::iterator it = s.begin(); it != s.end(); it++)
		{
			cout << *it << " ";
		}
		cout << "size = " << s.size();
	}
	cout << endl;
}