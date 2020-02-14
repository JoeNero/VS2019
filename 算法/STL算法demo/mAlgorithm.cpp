/*
创建者	:	XTT
功能	:	算法
			#include <algorithm>
			-------------------------------------------------------------
			遍历
			for_each(iterator beg, iterator end,_func)

			-------------------------------------------------------------
			搬运容器到另一个容器中
			transform(iterator beg1, iterator end1, iterator beg2, _func);

			beg1 源容器开始迭代器
			end1 源容器结束迭代器
			beg2 目标容器开始迭代器
			_func 函数或者函数对象
			-------------------------------------------------------------
			查找
			find(iterator beg, iterator end, value);

			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			value 查找的元素
			-------------------------------------------------------------
			find_if(iterator beg, iterator end, _Pred);

			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			_Pred 函数或者谓词（返回bool类型的仿函数）
			-------------------------------------------------------------
			adjacent_find(iterator beg, iterator end);

			查找相邻重复元素,返回相邻元素的第一个位置的迭代器
			beg 开始迭代器
			end 结束迭代器
			-------------------------------------------------------------
			bool binary_search(iterator beg, iterator end, value);

			查找指定的元素，查到 返回true 否则false
			注意: 在无序序列中不可用
			beg 开始迭代器
			end 结束迭代器
			value 查找的元素
			-------------------------------------------------------------
			count(iterator beg, iterator end, value);
			统计元素出现次数

			count_if(iterator beg, iterator end, _Pred);
			按条件统计元素出现次数
			
			beg 开始迭代器
			end 结束迭代器
			value 统计的元素
			-------------------------------------------------------------
时间	:	2020/01/08
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
void test03();				// 查找相邻元素
void test04();				// 二分法查找

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
		cout << "标识符:" << p.m_Name << " ";
		cout << "年龄:" << p.m_Age << endl;
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
功能: 	- 
		@param
描述	:
示例	:
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
	v1.resize(v.size());		//目标容器需要提前开辟空间呢

	transform(v.begin(),v.end(),v1.begin(), TransForm());

	for_each(v1.begin(),v1.end(),print1);
	vector<int>::iterator it = find_if(v.begin(), v.end(), Greater());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "大于5的数字:" << *it << endl;
	}
}

/*
功能: 	- 
		@param
描述	:
示例	:
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
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "大于20:" << it->m_Name << " " << it->m_Age << endl;
	}
}

/*
功能: 	- 查找相邻元素
		@param
描述	:
示例	:
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
	//查找相邻重复元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) 
	{
		cout << "找不到!" << endl;
	} 
	else
	{
	cout << "找到相邻重复元素为:" << *it << endl;
	}
}

/*
功能: 	- 二分法查找元素
		@param
描述	:
示例	:
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
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

void printVector(vector<int>& v)
{
	if (v.empty())
	{
		cout << "打印的向量容器为空" << endl;
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