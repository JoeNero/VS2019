/*
������	:	XTT
����	:	map����
			map�е�����Ԫ�ض���pair
			pair�еĵ�һ��Ԫ����key(��ֵ),�ڶ���Ԫ��Ϊ:value(ʵֵ)
			map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

			map���������������ظ���Ԫ��
			multimap�������������ظ���Ԫ��

			map������������ʱ��insert
			map�����������ݵ����ݻ��Զ�����,Ĭ������

			size();		--����������Ԫ�ص���Ŀ
			empty();	--�ж������Ƿ�Ϊ��
			swap();		--����������������

			find(key);  --����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
			count(key); --ͳ��key��Ԫ�ظ���
			erase(key)	--����keyԪ��
			clear()		--���

ʱ��	:	2020/01/08
*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <map>
using namespace std;

void test01();
void test02();
void test03();

void printMap(map<int,int>&);
void printMultimap(multimap<int,int>&);

//һ��Ҫ�ں����const
class MyCompare
{
public:
	bool operator()(int v1,int v2) const
	{
		return v1 > v2;
	}
};
int main()
{

	//test01();
	//test02();
	test03();
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
	map<int,int> m1;
	//��һ�ֲ��뷽ʽ
	m1.insert(pair<int, int>(1, 10));
	//�ڶ��ֲ��뷽ʽ
	m1.insert(make_pair(2, 10));
	//�����ֲ��뷽ʽ
	m1.insert(map<int, int>::value_type(3, 30));
	m1[4] = 40;

	printMap(m1);
	
	//��������
	map<int,int> m2(m1);
	printMap(m2);

	m1.erase(1);

	map<int, int>::iterator pos = m1.find(2);
	if (pos != m1.end())
	{
		cout << "��Ԫ��pos->first=" << pos->first  << " "
			 << "��Ԫ��pos->first=" << pos->second <<" "
			 <<"��ַ ��" << &pos << endl;
	}
	else
	{
		cout << "δ�и�Ԫ��" << endl;
	}
	cout << "count(2) = " << m1.count(2) << endl;
	m1.swap(m2);
	cout << "����s1��s2" << endl;
	cout << "m1:" << endl;
	printMap(m1);
	cout << "m2:" << endl;
	printMap(m2);

}

/*
����: 	- test02()
		@param
����	:	multiset����demo
ʾ��	:
*/
void test02()
{
	multimap<int, int> m1;
	//��һ�ֲ��뷽ʽ
	m1.insert(pair<int, int>(1, 10));
	//�ڶ��ֲ��뷽ʽ
	m1.insert(make_pair(2, 10));
	//�����ֲ��뷽ʽ
	m1.insert(multimap<int, int>::value_type(3, 30));
	printMultimap(m1);

	//��������
	multimap<int, int> m2(m1);
	printMultimap(m2);

	m1.erase(1);

	multimap<int, int>::iterator pos = m1.find(2);
	if (pos != m1.end())
	{
		cout << "��Ԫ��pos->first=" << pos->first << " "
			<< "��Ԫ��pos->first=" << pos->second << " "
			<< "��ַ ��" << &pos << endl;
	}
	else
	{
		cout << "δ�и�Ԫ��" << endl;
	}
	cout << "count(2) = " << m1.count(2) << endl;
	m1.swap(m2);
	cout << "����s1��s2" << endl;
	cout << "m1:" << endl;
	printMultimap(m1);
	cout << "m2:" << endl;
	printMultimap(m2);
}

void test03()
{
	map<int, int, MyCompare> m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(3, 50));
	m1.insert(make_pair(2, 30));
	m1.insert(make_pair(5, 20));

	for (map<int, int, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "first:" << it->first << " ";
		cout << "secend:" << it->second << endl;
	}
}

/*
����: 	- ��ӡ����
		@set<int>& s
����	:
ʾ��	:	printSet(s);
*/
void printMap(map<int,int>& m)
{
	if (m.empty())
	{
		cout << "��ӡmap����Ϊ��";
		return;
	}
	else
	{
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			cout << "first:" << it->first  << " ";
			cout << "secend:"<< it->second << endl;
		}
		cout << "size = " << m.size();
	}
	cout << endl;
}

void printMultimap(multimap<int,int>& m)
{
	if (m.empty())
	{
		cout << "��ӡmultimap����Ϊ��";
		return;
	}
	else
	{
		for (multimap<int,int>::iterator it = m.begin(); it != m.end(); it++)
		{
			cout << "first:" << it->first << " ";
			cout << "secend:" << it->second << endl;
		}
		cout << "size = " << m.size();
	}
	cout << endl;
}