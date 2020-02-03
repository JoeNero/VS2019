/*
创建者	:	XTT
功能	:	deque类操作
			deque没有容量的概念

时间	:	2020/01/07
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

void test01();						//deque类构造demo
void test02();						//deque类插入demo
void test03();						//deque类删除demo
void test04();						//排序

bool cmp(int x, int y);

void printDeque(deque<int>&);


int main()
{
	//test01();
	//test02();
	test03();
	//test04();
	system("pause");
	return 0;
}

/*
功能: 	- deque类构造demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test01()
{
	deque<int> d1;			//无参数构造
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int> d3(10, 100);
	printDeque(d3);

	deque<int> d4 = d3;
	printDeque(d4);
}

/*
功能: 	- deque类插入demo
		@param
描述	:
示例	:
*/
void test02()
{
	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	//尾删
	d.pop_back();
	//头删
	d.pop_front();

	printDeque(d);

	d.insert(d.begin(), 1000);
	printDeque(d);

	d.insert(d.begin(), 2, 1000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);
}

/*
功能: 	- deque类删除demo
		@param
描述	:
示例	:
*/
void test03()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(100);
	d.push_back(200);
	for (auto&s:d)
	{
		cout << s << ends;
	}
	cout << endl;
	cout << "d.size() = "  << d.size()  << endl;
	cout << "d.front() = " << d.front() << endl;
	cout << "d.back() = "  << d.back()  << endl;
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	//printDeque(d);

	d.erase(d.begin());
	printDeque(d);

	d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}

/*
功能: 	- 排序demo
		@param
描述	:
示例	:
*/
void test04()
{
	deque<int> d;
	srand((unsigned int)time(NULL));							//时间种子					 	
	for (int i = 0; i < 10; i++)
	{
		d.push_back(rand() % 100);				//   数值范围(0-99）
	}
	cout << "原队列" << endl;
	printDeque(d);
	cout << "升序" << endl;
	sort(d.begin(), d.end());
	printDeque(d);
	cout << "降序" << endl;
	sort(d.begin(), d.end(), cmp);
	printDeque(d);
}

bool cmp(int x, int y)
{
	return x > y;
}

/*
功能: 	- 打印deque类
		@deque<int>& d
描述	:
示例	: printDeque(d1);
*/
void printDeque(deque<int>& d)
{
	if (d.empty())
	{
		cout << "打印队列为空" << endl;
		return;
	}
	else
	{
		for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
		{
			cout << *it << " ";
		}
		cout << " 大小为=" << d.size();
	}
	cout << endl;

}