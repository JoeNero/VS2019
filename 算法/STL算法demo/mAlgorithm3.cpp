/*
������	:	XTT
����	:	�������滻�㷨
			#include <algorithm>
			-------------------------------------------------------------
			copy		-- ������ָ����Χ��Ԫ�ؿ�������һ������
			replace		-- ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
			replace_if	-- ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
			swap		-- ��������������Ԫ��(��С���Բ�һ��)
			-------------------------------------------------------------
			Ŀ��������Ҫ��ǰ���ٿռ�
			copy(iterator beg, iterator end, iterator dest);
			��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
			beg ��ʼ������
			end ����������
			dest Ŀ����ʼ������

			-------------------------------------------------------------
			replace(iterator beg, iterator end, oldvalue, newvalue);
			�������ھ�Ԫ�� �滻�� ��Ԫ��
			beg ��ʼ������
			end ����������
			oldvalue ��Ԫ��
			newvalue ��Ԫ��

			-------------------------------------------------------------
			replace_if(iterator beg, iterator end, _pred, newvalue);
			�������滻Ԫ�أ������������滻��ָ��Ԫ��
			beg ��ʼ������
			end ����������
			_pred ν��
			newvalue �滻����Ԫ��
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

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};

void copyTest(vector<int>&);
void replaceTest(vector<int>&);
void swapTest(vector<int>&, vector<int>&);

int main()
{
	vector<int> v1;
	vector<int> v2;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 40 + 1;
		//int temp = rand() % 10 + 1;
		v1.push_back(temp);
	}
	for (size_t i = 0; i < 20; i++)
	{
		int temp = rand() % 40 + 1;
		//int temp = rand() % 10 + 1;
		v2.push_back(100 - temp);
	}
	
	for (auto&s:v1)
	{
		cout << s << " ";
	}
	cout << endl;
	//copyTest(v1);
	//replaceTest(v1);
	swapTest(v1,v2);
}

void copyTest(vector<int>& v)
{
	vector<int> vT;
	vT.resize(v.size());
	copy(v.begin(),v.end(),vT.begin());
	for_each(vT.begin(),vT.end(), print);
}

void replaceTest(vector<int>& v)
{
	cout << "�滻ǰ" << endl;
	for (auto& s : v)
	{
		cout << s << " ";
	}
	cout << endl;
	cout << "�滻ǰ" << endl;
	replace(v.begin(),v.end(),2,20);
	for (auto& s : v)
	{
		cout << s << " ";
	}
	cout << endl;
	cout << "����_�滻" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 1000);
	for (auto& s : v)
	{
		cout << s << " ";
	}
}
void swapTest(vector<int>& v1, vector<int>& v2)
{
	swap(v1, v2);
	cout << "v1 = " << endl;
	for (auto& s: v1)
	{
		cout << s << " ";
	}
	cout << endl << v1.size() << endl;
	cout << "v2 = " << endl;
	for (auto& s : v2)
	{
		cout << s << " ";
	}
	cout << endl << v2.size() << endl;
}