/*
创建者	:	XTT
功能	:	map容器
			map中的所有元素都是pair
			pair中的第一个元素是key(键值),第二个元素为:value(实值)
			map/multimap属于关联式容器，底层结构是用二叉树实现

			map不允许容器中有重复的元素
			multimap允许容器中有重复的元素

			map容器插入数据时用insert
			map容器插入数据的数据会自动排序,默认升序

			size();		--返回容器中元素的数目
			empty();	--判断容器是否为空
			swap();		--交换两个集合容器

			find(key);  --查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
			count(key); --统计key的元素个数
			erase(key)	--擦除key元素
			clear()		--清空

时间	:	2020/01/08
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

//一定要在后面加const
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
功能: 	- test01()
		@param
描述	:	set容器demo
示例	: 
*/
void test01()
{
	map<int,int> m1;
	//第一种插入方式
	m1.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m1.insert(make_pair(2, 10));
	//第三种插入方式
	m1.insert(map<int, int>::value_type(3, 30));
	m1[4] = 40;

	printMap(m1);
	
	//拷贝构造
	map<int,int> m2(m1);
	printMap(m2);

	m1.erase(1);

	map<int, int>::iterator pos = m1.find(2);
	if (pos != m1.end())
	{
		cout << "该元素pos->first=" << pos->first  << " "
			 << "该元素pos->first=" << pos->second <<" "
			 <<"地址 ：" << &pos << endl;
	}
	else
	{
		cout << "未有该元素" << endl;
	}
	cout << "count(2) = " << m1.count(2) << endl;
	m1.swap(m2);
	cout << "交换s1，s2" << endl;
	cout << "m1:" << endl;
	printMap(m1);
	cout << "m2:" << endl;
	printMap(m2);

}

/*
功能: 	- test02()
		@param
描述	:	multiset容器demo
示例	:
*/
void test02()
{
	multimap<int, int> m1;
	//第一种插入方式
	m1.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m1.insert(make_pair(2, 10));
	//第三种插入方式
	m1.insert(multimap<int, int>::value_type(3, 30));
	printMultimap(m1);

	//拷贝构造
	multimap<int, int> m2(m1);
	printMultimap(m2);

	m1.erase(1);

	multimap<int, int>::iterator pos = m1.find(2);
	if (pos != m1.end())
	{
		cout << "该元素pos->first=" << pos->first << " "
			<< "该元素pos->first=" << pos->second << " "
			<< "地址 ：" << &pos << endl;
	}
	else
	{
		cout << "未有该元素" << endl;
	}
	cout << "count(2) = " << m1.count(2) << endl;
	m1.swap(m2);
	cout << "交换s1，s2" << endl;
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
功能: 	- 打印函数
		@set<int>& s
描述	:
示例	:	printSet(s);
*/
void printMap(map<int,int>& m)
{
	if (m.empty())
	{
		cout << "打印map容器为空";
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
		cout << "打印multimap容器为空";
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