/*
������	:	XTT
����	:	�㷨
			#include <algorithm>
			-------------------------------------------------------------
			���������㷨
			sort			-- ��������Ԫ�ؽ�������
			random_shuffle  -- ϴ�� ָ����Χ�ڵ�Ԫ�������������
			merge			-- ����Ԫ�غϲ������洢����һ������
			reverse			-- ��תָ����Χ��Ԫ��
			-------------------------------------------------------------
			sort(iterator beg, iterator end, _Pred);
			��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
			beg ��ʼ������
			end ����������
			_Pred ν��
			-------------------------------------------------------------
			random_shuffle(iterator beg, iterator end);
			ָ����Χ�ڵ�Ԫ�������������
			beg ��ʼ������
			end ����������
			-------------------------------------------------------------
			merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			����Ԫ�غϲ������洢����һ������

			!!!ע��: �������������������,����������߽���

			beg1 ����1��ʼ������ // end1 ����1���������� // beg2 ����2��ʼ������ // end2 ����2���������� //
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

void sortTest(vector<int>&);
void randomShuffle(vector<int>&);
void mergeTest(vector<int>&, vector<int>&);

int main()
{
	vector<int> v;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 40 + 1;
		v.push_back(temp);
	}

	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 40 + 1;
		v1.push_back(temp);
	}

	//sortTest(v);
	//randomShuffle(v);
	mergeTest(v, v1);
}

void sortTest(vector<int>& v)
{
	//Ĭ������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	//����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), print);
	cout << endl;
}

void randomShuffle(vector<int>& v)
{
	//Ĭ������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	//����˳��
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
}

void mergeTest(vector<int>& v1, vector<int>& v2)
{
	//Ĭ������
	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;

	//Ĭ������
	sort(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), print);
	cout << endl;
	vector<int> v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto& v : v3)
	{
		cout << v << " ";
	}
	cout << endl;
	reverse(v3.begin(),v3.end());
	for (auto& v : v3)
	{
		cout << v << " ";
	}
	cout << endl;
}