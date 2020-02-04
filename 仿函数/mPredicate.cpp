/*
������	:	XTT
����	:	ν��

			����bool���͵ķº�����Ϊν��
			���operator()����һ����������ô����һԪν��
			���operator()����������������ô������Ԫν��



ʱ��	:	2020/01/08
*/
#define CRTDBG_MAP_ALLOC  

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <crtdbg.h> 
#include <vector>

using namespace std;

//1.һԪν��
struct GreateFive
{
	bool operator()(int val)
	{
		return val > 5;
	}
};
//2/��Ԫν��
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2 ;		// > ����  <����
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
����: 	- һԪν��demo
		@param
		@param
		@param
����	:
ʾ��	:
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
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << *it << endl;
	}
}

/*
����: 	- ��Ԫν��
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test02()
{
	vector<int> v;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%100);
	}
	//Ĭ�ϴ�С����
	sort(v.begin(),v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "-------------------------------" << endl;

	//ʹ�ú�������ı��㷨���ԣ�����Ӵ�С
	sort(v.begin(),v.end(),MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}