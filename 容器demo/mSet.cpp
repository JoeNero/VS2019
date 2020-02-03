/*
创建者	:	XTT
功能	:	set容器
			set/multiset属于关联式容器，底层结构是用二叉树实现

			set不允许容器中有重复的元素
			multiset允许容器中有重复的元素

			set容器插入数据时用insert
			set容器插入数据的数据会自动排序

			size();		--返回容器中元素的数目
			empty();	--判断容器是否为空
			swap();		--交换两个集合容器

			find(key);  --查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
			count(key); --统计key的元素个数
			erase(key)	--擦除key元素

时间	:	2020/01/08
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
功能: 	- test01()
		@param
描述	:	set容器demo
示例	: 
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
	
	//拷贝构造
	set<int> s2(s1);
	printSet(s2);

	s1.erase(1);

	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "该元素pos=" << *pos << "地址 ：" << &pos << endl;
	}
	else
	{
		cout << "未有该元素" << endl;
	}
	cout << "count(2) = " << s1.count(2) << endl;
	s1.swap(s2);
	cout << "交换s1，s2" << endl;
	cout << "s1:" << endl;
	printSet(s1);
	cout << "s1:" << endl;
	printSet(s2);

}

/*
功能: 	- test02()
		@param
描述	:	multiset容器demo
示例	:
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

	//拷贝构造
	multiset<int> s2(s1);
	printMultiset(s2);

	s1.erase(1);

	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "该元素pos=" << *pos << "地址 ：" << &pos << endl;
	}
	else
	{
		cout << "未有该元素" << endl;
	}
	cout << "count(2) = " << s1.count(2) << endl;
	s1.swap(s2);
	cout << "交换s1，s2" << endl;
	cout << "s1:" << endl;
	printMultiset(s1);
	cout << "s1:" << endl;
	printMultiset(s2);
}
/*
功能: 	- 打印函数
		@set<int>& s
描述	:
示例	:	printSet(s);
*/
void printSet(set<int>& s)
{
	if (s.empty())
	{
		cout << "打印set容器为空";
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
		cout << "打印set容器为空";
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