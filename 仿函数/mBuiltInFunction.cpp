/*
创建者	:	XTT
功能	:	内建函数
			STL 内建了一些函数对象

			分类:
			算术仿函数
			关系仿函数
			逻辑仿函数

			使用内建函数对象，需要引入头文件#include <functional>

			算术仿函数:
			template<class T> T plus<T>			//加法仿函数
			template<class T> T minus<T>		//减法仿函数
			template<class T> T multiplies<T>	//乘法仿函数
			template<class T> T divides<T>		//除法仿函数
			template<class T> T modulus<T>		//取模仿函数
			template<class T> T negate<T>		//取反仿函数

			关系仿函数:
			template<class T> bool equal_to<T>			//等于
			template<class T> bool not_equal_to<T>		//不等于
			template<class T> bool greater<T>			//大于
			template<class T> bool greater_equal<T>		//大于等于
			template<class T> bool less<T>				//小于
			template<class T> bool less_equal<T>		//小于等于

			逻辑仿函数
			template<class T> bool logical_and<T> //逻辑与
			template<class T> bool logical_or<T> //逻辑或
			template<class T> bool logical_not<T> //逻辑非

时间	:	2020/01/08
*/

#define CRTDBG_MAP_ALLOC  

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <crtdbg.h> 
#include <vector>
#include <functional>

using namespace std;

void test01();				// 算术仿函数
void test02();				// 关系仿函数
void test03();				// 逻辑仿函数

void printVector(vector<int> &);			

bool MyCompare(int v1, int v2)
{
	return v1 > v2;
};

int main()
{
	//test01();
	//test02();
	test03();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

/*
功能: 	- 算术仿函数
		@param
描述	:
示例	:
*/
void test01()
{
	negate<int> n;	//取反
	cout << n(50) << endl;			
	plus<int> p;	//乘法
	cout << p(10, 20) << endl;
}

/*
功能: 	- 关系仿函数demo
		@param
描述	:
示例	:
*/
void test02()
{
	vector<int> v;
	for (size_t i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	printVector(v);
	//sort(v.begin(),v.end(),MyCompare);
	//STL 内建仿函数 大于仿函数
	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
}

/*
功能: 	- 逻辑仿函数demo
		@param
描述	:
示例	:
*/
void test03()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
	for (vector<bool>::const_iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
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
		cout << endl;
	}
}