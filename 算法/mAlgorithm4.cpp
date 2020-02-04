/*
������	:	XTT
����	:	���ü����㷨
			#include <algorithm>
			-------------------------------------------------------------
			set_intersection // �����������Ľ���
			set_union // �����������Ĳ���
			set_difference // �����������Ĳ
			-------------------------------------------------------------
			set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			���������ϵĽ���
			ע��:�������ϱ�������������
			beg1 ����1��ʼ������ 
			end1 ����1���������� 
			beg2 ����2��ʼ������ 
			end2 ����2���������� 
			dest Ŀ��������ʼ������
			-------------------------------------------------------------
			set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			���������ϵĲ���
			ע��:�������ϱ�������������
			beg1 ����1��ʼ������ 
			end1 ����1���������� 
			beg2 ����2��ʼ������ 
			end2 ����2���������� 
			dest Ŀ��������ʼ������
			-------------------------------------------------------------
ʱ��	:	2020/01/08
*/

#define CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

void print(int val)
{
	cout << val << " ";
}

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

int main()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> vT;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (size_t i = 0; i < 5; i++)
	{
		v2.push_back(i);
	}

	cout << "v1:" << endl;
	for (auto& s : v1)
	{
		cout << s << ends;
	}
	cout << endl;

	cout << "v2:" << endl;
	for (auto& s : v2)
	{
		cout << s << ends;
	}
	cout << endl;

	//ȡ�������������С��ֵ��Ŀ���������ٿռ�
	//�󽻼�
	cout << "�󽻼�" << endl;
	vT.resize(min(v1.size(),v2.size()));
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vT.begin());
	for (auto& s: vT)
	{
		cout << s << ends;
	}
	cout << endl;
	//�󲢼�
	cout << "�󲢼�" << endl;
	vT.resize(v1.size()+v2.size());
	vector<int>::iterator itEnd = 
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vT.begin());
	for_each(vT.begin(),itEnd,MyPrint());
	cout << endl;
}