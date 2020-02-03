/*
创建者	:	XTT
功能	:	list容器
			STL中的链表是一个双向循环链表
			判断是否为空--empty
			判断元素个数--size
			重新指定个数--resize

			尾插 --- push_back
			尾删 --- pop_back
			头插 --- push_front
			头删 --- pop_front
			插入 --- insert
			删除 --- erase
			移除 --- remove
			清空 --- clear

			front(); 返回第一个元素。
			back();  返回最后一个元素。

			reverse();	反转链表
			sort();		链表排序



时间	:	2020/01/08
*/

#include <iostream>
#include <algorithm>
#include <list>
#include <ctime>

//	mode 1   按年龄排序
//  mode 0	 按身高排序
//			 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
//			 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
#define mode 1

using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
public:
	string m_Name;		//姓名
	int m_Age;			//年龄
	int m_Height;		//身高
};
bool cmp(int, int);
bool ComparePerson(Person&, Person&);

void test01();
void test02();

void printList(const list<int>&);			//打印
void printList(const list<Person>&);			//打印



int main()
{

	test01();
	test02();
	system("pause");
	return 0;
}

/*
功能: 	- list容器
		@param
		@param
		@param
描述	:
示例	:
*/
void test01()
{
	list<int> L1;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		L1.push_back(rand() % 100);
	}
	printList(L1);

	list<int> L2(L1.begin(), L1.end());
	printList(L2);

	list<int> L3(L2);
	printList(L3);

	list<int> L4(6, 11);
	printList(L4);

	L1.swap(L4);
	cout << "交换" << endl;
	printList(L1);
	printList(L4);
	L4.reverse();
	cout << "反转";
	printList(L4);
	cout << "排序";
	L4.sort();
	printList(L4);
	cout << "降序";
	L4.sort(cmp);
	printList(L4);


}



bool cmp(int a, int b)
{
	return a > b;
}

/*
功能: 	- test02()
		@param
		@param
		@param
描述	:
示例	:
*/
void test02()
{
	list<Person> L;
	Person p1("P1", 35, 175);
	Person p2("P2", 45, 180);
	Person p3("P3", 40, 170);
	Person p4("P4", 25, 190);
	Person p5("P5", 35, 160);
	Person p6("P6", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	printList(L);
	cout << "---------------------------------" << endl;

	if (mode)
	{
		cout << "年龄排序" << endl;
	}
	else
	{
		cout << "身高排序" << endl;
	}

	L.sort(ComparePerson);
	printList(L);

}

bool ComparePerson(Person& p1, Person& p2)
{
	//年龄排序
#if mode
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
#else
	//身高排序
	if (p1.m_Height == p2.m_Height) {
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Height < p2.m_Height;
	}
#endif
}

/*
功能: 	- 打印list容器
		@const list<int>& L
		@param
		@param
描述	:
示例	:	printList(L4);
*/
void printList(const list<int>& L)
{
	if (L.empty())
	{
		cout << "打印链表为空" << endl;
		return;
	}
	else
	{
		for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
		{
			cout << *it << " ";
		}
		cout << "大小" << L.size() << endl;
	}

	cout << endl;
}

void printList(const list<Person>& L)			//打印
{
	if (L.empty())
	{
		cout << "打印链表为空" << endl;
		return;
	}
	else
	{
		for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
		{
			cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
				<< " 身高： " << it->m_Height << endl;
		}
		cout << "大小" << L.size() << endl;
	}
}