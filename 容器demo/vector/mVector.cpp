/*
������	:	XTT
����	:	vector��������

ʱ��	:	2020/01/07
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

void test01();						    //vector�๹��demo
void test02();							//vector��������Сdemo
void test03();							//vector�����ɾ��demo
void test04();							//vector�໥������demo
void test05();							//vector��Ԥ���ռ�demo

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
����: 	- vector�๹��demo
		@param
����	:
ʾ��	:
*/
void test01()
{
	vector<MyInt> v1; //�޲ι���
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
����: 	- vector������demo
		@param
����	:
ʾ��	:
*/
void test02()
{
	vector<MyInt> v1; //�޲ι���
	MyInt* myInt = new MyInt[10];
	for (int i = 0; i < 10; i++)
	{
		myInt[i].name = '0' + i;
		myInt[i].Int = i;
		v1.push_back(myInt[i]);
	}
	cout << "v1��ʵ�Ĵ�С = " << v1.capacity() << endl;		//��ʵ�Ĵ�С
	cout << "v1�Ĵ�С = " << v1.size() << endl;
	cout << "v1������� = " << v1.max_size() << endl;
	v1.resize(12, myInt[2]);
	printVector(v1);
	v1.resize(2);
	printVector(v1);
	delete[] myInt;
}

/*
����: 	- vector�����ɾ��demo
		@param

����	:
ʾ��	:
*/
void test03()
{
	vector<MyInt> v1; //�޲ι���
	MyInt* myInt = new MyInt[3];
	for (int i = 0; i < 3; i++)
	{
		myInt[i].name = '0' + i;
		myInt[i].Int = i;
		v1.push_back(myInt[i]);
	}
	printVector(v1);
	//βɾ
	cout << "βɾ" << endl;
	v1.pop_back();
	printVector(v1);
	//����
	vector<MyInt>::iterator it = v1.begin();
	cout << "��begin+1λ������[1]" << endl;
	v1.insert(it + 1, myInt[1]);
	printVector(v1);
	cout << "��beginλ��2������[1]" << endl;
	v1.insert(v1.begin(), 2, myInt[2]);
	printVector(v1);
	////ɾ��
	v1.erase(v1.begin());
	cout << "����ͷ:" << endl;
	printVector(v1);
	////���
	//v1.erase(v1.begin(), v1.end());
	//printVector(v1);
	v1.clear();
	printVector(v1);
	cout << endl;
	cout << "clear���size" << v1.size() << endl;
	delete[] myInt;

}

/*
����: 	- vector�໥������demo
		@param
����	:
ʾ��	:
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
	//��������
	cout << "������" << endl;
	v1.swap(v2);
	cout << " v1 =" << endl;
	printVector(v1);
	cout << " v2 =" << endl;
	printVector(v2);

	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
	v.resize(3);
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
	//�����ڴ�
	vector<int>(v).swap(v); //��������
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	delete[] myInt;
	delete[] myInt2;
}

/*
����: 	- vector��Ԥ���ռ�demo
		@param
����	:
ʾ��	:
*/
void test05()
{
	vector<int> v;
	//Ԥ���ռ�
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
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
	cout << "num:" << num << endl;
}

/*
����: 	- vector���ӡ
		@param
����	:
ʾ��	:
*/
void printVector(vector<MyInt>& v)
{
	if (v.empty())
	{
		cout << "��ӡVectorΪ��";
		return;
	}
	else
	{
		for (vector<MyInt>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << "��ʶ��Ϊ:" << it->name << " ";
			cout << "����Ϊ:" << it->Int << endl;
		}
	}
	cout << endl;
}