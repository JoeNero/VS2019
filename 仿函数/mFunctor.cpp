/*
������	:	XTT
����	:	�º���
			��������(�º���)��һ���࣬����һ������



ʱ��	:	2020/01/08
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

void test01();
void test02();
void test03();

//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class MyAdd
{
public:
	int operator()(int v1, int v2)const
	{
		return v1 + v2;
	}
};

//2����������������Լ���״̬
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
		count++; //ͳ��ʹ�ô���
	}
	int count; //�ڲ��Լ���״̬
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
����: 	- test01()
		@param
����	:
ʾ��	:
*/
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

/*
����: 	-
		@param
����	:
ʾ��	:
*/
void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint���ô���Ϊ�� " << myPrint.count << endl;
}

/*
����: 	-
		@param
����	:
ʾ��	:
*/
void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

//3���������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}