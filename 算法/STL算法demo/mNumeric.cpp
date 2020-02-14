/*
������	:	XTT
����	:	�������������㷨
			#include <numeric>

			-------------------------------------------------------------
			accumulate		-- ��������Ԫ���ۼ��ܺ�
			fill			-- �����������Ԫ��
			-------------------------------------------------------------
			accumulate(iterator beg, iterator end, value);
			��������Ԫ���ۼ��ܺ�
			beg ��ʼ������
			end ����������
			value ��ʼֵ
			-------------------------------------------------------------
			fill(iterator beg, iterator end, value);
			�����������Ԫ��
			beg ��ʼ������
			end ����������
			value ����ֵ
			-------------------------------------------------------------
ʱ��	:	2020/01/08
*/

#define CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#include <iostream>
#include <numeric>
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
	vector<int> v;
	v.resize(20);
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << "sum =" << sum << endl;
	fill(v.begin(),v.end(),2);
	for (auto& s: v)
	{
		cout << s << ends;
	}
}