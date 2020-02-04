/*
创建者	:	XTT
功能	:	仿函数
			函数对象(仿函数)是一个类，不是一个函数



时间	:	2020/01/08
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

void test01();
void test02();
void test03();

//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd
{
public:
	int operator()(int v1, int v2)const
	{
		return v1 + v2;
	}
};

//2、函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++; //统计使用次数
	}
	int count; //内部自己的状态
};

void doPrint(MyPrint& mp, string test);

int main()
{
	//	test01();
	//	test02();
		test03();
	system("pause");
	return 0;
}

/*
功能: 	- test01()
		@param
描述	:
示例	:
*/
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

/*
功能: 	-
		@param
描述	:
示例	:
*/
void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint调用次数为： " << myPrint.count << endl;
}

/*
功能: 	-
		@param
描述	:
示例	:
*/
void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

//3、函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}