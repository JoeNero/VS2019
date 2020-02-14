/*
������	:	XTT
����	:	�㷨
			#include <algorithm>
			-------------------------------------------------------------
			����
			for_each(iterator beg, iterator end,_func)

			-------------------------------------------------------------
			������������һ��������
			transform(iterator beg1, iterator end1, iterator beg2, _func);

			beg1 Դ������ʼ������
			end1 Դ��������������
			beg2 Ŀ��������ʼ������
			_func �������ߺ�������
			-------------------------------------------------------------
			����
			find(iterator beg, iterator end, value);

			��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
			beg ��ʼ������
			end ����������
			value ���ҵ�Ԫ��
			-------------------------------------------------------------
			find_if(iterator beg, iterator end, _Pred);

			��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
			beg ��ʼ������
			end ����������
			_Pred ��������ν�ʣ�����bool���͵ķº�����
			-------------------------------------------------------------
			adjacent_find(iterator beg, iterator end);

			���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ�����
			beg ��ʼ������
			end ����������
			-------------------------------------------------------------
			bool binary_search(iterator beg, iterator end, value);

			����ָ����Ԫ�أ��鵽 ����true ����false
			ע��: �����������в�����
			beg ��ʼ������
			end ����������
			value ���ҵ�Ԫ��
			-------------------------------------------------------------
			count(iterator beg, iterator end, value);
			ͳ��Ԫ�س��ִ���

			count_if(iterator beg, iterator end, _Pred);
			������ͳ��Ԫ�س��ִ���
			
			beg ��ʼ������
			end ����������
			value ͳ�Ƶ�Ԫ��
			-------------------------------------------------------------
ʱ��	:	2020/01/08
*/

#define CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

void test01();				// int
void test02();				// Person
void test03();				// ��������Ԫ��
void test04();				// ���ַ�����

void print1(int val)
{
	cout << val << " ";
}

class Person
{
public:
	Person(char name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	char m_Name;
	int m_Age;
};

class print2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
	void operator()(Person& p)
	{
		cout << "��ʶ��:" << p.m_Name << " ";
		cout << "����:" << p.m_Age << endl;
	}
};

class TransForm
{
public:
	int operator()(int val)
	{
		return val;
	}
};


class Greater
{
public :
	bool operator()(int val)
	{
		return val > 20;
	}
	bool operator()(Person& p)
	{
		return p.m_Age > 20;
	}
};


bool MyCompare(int v1, int v2)
{
	return v1 > v2;
};

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

/*
����: 	- 
		@param
����	:
ʾ��	:
*/
void test01()
{
	vector<int> v;
	srand((unsigned)time(NULL));
	for (size_t i = 0 ; i < 10 ; i++)
	{
		int temp = rand() % 100;
		v.push_back(temp);
	}
	for_each(v.begin(), v.end(), print1);
	cout << endl;
	for_each(v.begin(), v.end(), print2());
	cout << endl;

	vector<int> v1;
	v1.resize(v.size());		//Ŀ��������Ҫ��ǰ���ٿռ���

	transform(v.begin(),v.end(),v1.begin(), TransForm());

	for_each(v1.begin(),v1.end(),print1);
	vector<int>::iterator it = find_if(v.begin(), v.end(), Greater());
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "����5������:" << *it << endl;
	}
}

/*
����: 	- 
		@param
����	:
ʾ��	:
*/
void test02()
{
	vector<Person> v;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		size_t age = rand() % 40;
		char name = age+ '0';
		Person p(name, age);
		v.push_back(p);
	}
	for_each(v.begin(), v.end(), print2());
	cout << endl;

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater());
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "����20:" << it->m_Name << " " << it->m_Age << endl;
	}
}

/*
����: 	- ��������Ԫ��
		@param
����	:
ʾ��	:
*/
void test03()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	//���������ظ�Ԫ��
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) 
	{
		cout << "�Ҳ���!" << endl;
	} 
	else
	{
	cout << "�ҵ������ظ�Ԫ��Ϊ:" << *it << endl;
	}
}

/*
����: 	- ���ַ�����Ԫ��
		@param
����	:
ʾ��	:
*/
void test04()
{
	vector<int> v;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 100;
		v.push_back(temp);
	}
	bool ret = binary_search(v.begin(),v.end(),3);
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

void printVector(vector<int>& v)
{
	if (v.empty())
	{
		cout << "��ӡ����������Ϊ��" << endl;
		return;
	}
	else
	{
		for (vector<int>::const_iterator it = v.begin();it!=v.end();it++)
		{
			cout << *it << " ";
		}
		cout << v.size() << endl;
	}
}