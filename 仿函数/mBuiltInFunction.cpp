/*
������	:	XTT
����	:	�ڽ�����
			STL �ڽ���һЩ��������

			����:
			�����º���
			��ϵ�º���
			�߼��º���

			ʹ���ڽ�����������Ҫ����ͷ�ļ�#include <functional>

			�����º���:
			template<class T> T plus<T>			//�ӷ��º���
			template<class T> T minus<T>		//�����º���
			template<class T> T multiplies<T>	//�˷��º���
			template<class T> T divides<T>		//�����º���
			template<class T> T modulus<T>		//ȡģ�º���
			template<class T> T negate<T>		//ȡ���º���

			��ϵ�º���:
			template<class T> bool equal_to<T>			//����
			template<class T> bool not_equal_to<T>		//������
			template<class T> bool greater<T>			//����
			template<class T> bool greater_equal<T>		//���ڵ���
			template<class T> bool less<T>				//С��
			template<class T> bool less_equal<T>		//С�ڵ���

			�߼��º���
			template<class T> bool logical_and<T> //�߼���
			template<class T> bool logical_or<T> //�߼���
			template<class T> bool logical_not<T> //�߼���

ʱ��	:	2020/01/08
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

void test01();				// �����º���
void test02();				// ��ϵ�º���
void test03();				// �߼��º���

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
����: 	- �����º���
		@param
����	:
ʾ��	:
*/
void test01()
{
	negate<int> n;	//ȡ��
	cout << n(50) << endl;			
	plus<int> p;	//�˷�
	cout << p(10, 20) << endl;
}

/*
����: 	- ��ϵ�º���demo
		@param
����	:
ʾ��	:
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
	//STL �ڽ��º��� ���ڷº���
	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
}

/*
����: 	- �߼��º���demo
		@param
����	:
ʾ��	:
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
		cout << "��ӡ����������Ϊ��" << endl;
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