/*
创建者	:	XTT
功能	:	谓词

			返回bool类型的仿函数称为谓词
			如果operator()接受一个参数，那么叫做一元谓词
			如果operator()接受两个参数，那么叫做二元谓词



时间	:	2020/01/08
*/
#define CRTDBG_MAP_ALLOC  

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <crtdbg.h> 
#include <vector>

using namespace std;

//1.一元谓词
struct GreateFive
{
	bool operator()(int val)
	{
		return val > 5;
	}
};
//2/二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2 ;		// > 降序  <升序
	}
};

void test01();
void test02();

int main()
{
//	test01();
	test02();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

/*
功能: 	- 一元谓词demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreateFive());
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
	}
}

/*
功能: 	- 二元谓词
		@param
		@param
		@param
描述	:
示例	:
*/
void test02()
{
	vector<int> v;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%100);
	}
	//默认从小到大
	sort(v.begin(),v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "-------------------------------" << endl;

	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(),v.end(),MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}