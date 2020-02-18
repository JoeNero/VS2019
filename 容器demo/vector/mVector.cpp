/*
创建者	:	XTT
功能	:	vector容器操作

时间	:	2020/01/07
*/

#include <iostream>
#include <vector>
#include "MyDebug.h"
#include <time.h>

using namespace std;

struct MyInt
{
	string name;
	int Int;
};

void test01();						    //vector类构造demo
void test02();							//vector类容量大小demo
void test03();							//vector类插入删除demo
void test04();							//vector类互换容器demo
void test05();							//vector类预留空间demo

void printVector(vector<MyInt>&);


int main()
{

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	system("pause");
	return 0;
}

/*
功能: 	- vector类构造demo
		@param
描述	:
示例	:
*/
void test01()
{
	vector<MyInt> v1; //无参构造
	MyInt* myInt = new MyInt[10];
	for (int i = 0; i < 10; i++)
	{
		myInt[i].name = '0' + i;
		myInt[i].Int = i;
		v1.push_back(myInt[i]);
	}
	printVector(v1);
	vector<MyInt> v2(v1.begin(), v1.end());
	printVector(v2);
	vector<MyInt>::iterator it = v1.begin();
	vector<MyInt> v3(it + 1, v1.end());
	printVector(v3);
	v3.assign(v1.begin(), v1.end());
	printVector(v3);
	v3.assign(2, myInt[2]);
	printVector(v3);
	delete[] myInt;
}

/*
功能: 	- vector类容量demo
		@param
描述	:
示例	:
*/
void test02()
{
	vector<MyInt> v1; //无参构造
	MyInt* myInt = new MyInt[10];
	for (int i = 0; i < 10; i++)
	{
		myInt[i].name = '0' + i;
		myInt[i].Int = i;
		v1.push_back(myInt[i]);
	}
	cout << "v1真实的大小 = " << v1.capacity() << endl;		//真实的大小
	cout << "v1的大小 = " << v1.size() << endl;
	cout << "v1最大容量 = " << v1.max_size() << endl;
	v1.resize(12, myInt[2]);
	printVector(v1);
	v1.resize(2);
	printVector(v1);
	delete[] myInt;
}

/*
功能: 	- vector类插入删除demo
		@param

描述	:
示例	:
*/
void test03()
{
	vector<MyInt> v1; //无参构造
	MyInt* myInt = new MyInt[3];
	for (int i = 0; i < 3; i++)
	{
		myInt[i].name = '0' + i;
		myInt[i].Int = i;
		v1.push_back(myInt[i]);
	}
	printVector(v1);
	//尾删
	cout << "尾删" << endl;
	v1.pop_back();
	printVector(v1);
	//插入
	vector<MyInt>::iterator it = v1.begin();
	cout << "插begin+1位置数据[1]" << endl;
	v1.insert(it + 1, myInt[1]);
	printVector(v1);
	cout << "插begin位置2个数据[1]" << endl;
	v1.insert(v1.begin(), 2, myInt[2]);
	printVector(v1);
	////删除
	v1.erase(v1.begin());
	cout << "擦除头:" << endl;
	printVector(v1);
	////清空
	//v1.erase(v1.begin(), v1.end());
	//printVector(v1);
	v1.clear();
	printVector(v1);
	cout << endl;
	cout << "clear后的size" << v1.size() << endl;
	delete[] myInt;

}

/*
功能: 	- vector类互换容器demo
		@param
描述	:
示例	:
*/
void test04()
{
	vector<MyInt> v1;
	vector<MyInt> v2;
	MyInt* myInt = new MyInt[3];
	MyInt* myInt2 = new MyInt[7];
	for (int i = 0; i < 3; i++)
	{
		myInt[i].name = '0' + i;
		myInt[i].Int = i;
		v1.push_back(myInt[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		myInt[i].name = '0' + i;
		myInt[i].Int = 3 - i;
		v2.push_back(myInt[i]);
	}
	cout << " v1 =" << endl;
	printVector(v1);
	cout << " v2 =" << endl;
	printVector(v2);
	//互换容器
	cout << "互换后" << endl;
	v1.swap(v2);
	cout << " v1 =" << endl;
	printVector(v1);
	cout << " v2 =" << endl;
	printVector(v2);

	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	//收缩内存
	vector<int>(v).swap(v); //匿名对象
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	delete[] myInt;
	delete[] myInt2;
}

/*
功能: 	- vector类预留空间demo
		@param
描述	:
示例	:
*/
void test05()
{
	vector<int> v;
	//预留空间
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	cout << "num:" << num << endl;
}

/*
功能: 	- vector类打印
		@param
描述	:
示例	:
*/
void printVector(vector<MyInt>& v)
{
	if (v.empty())
	{
		cout << "打印Vector为空";
		return;
	}
	else
	{
		for (vector<MyInt>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << "标识符为:" << it->name << " ";
			cout << "数据为:" << it->Int << endl;
		}
	}
	cout << endl;
}