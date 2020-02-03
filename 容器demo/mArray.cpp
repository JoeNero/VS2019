/*
������	:	XTT
����	:	array����
			array�ǹ̶���С����������������ɾ�����ֻ�ܸ���
			array�洢�̶���С��Ԫ���������ľ�ȷ�������С�

			operator[]		:Access element (public member function )
			front()			:����ͷԪ��
			back()			:����βԪ��
			data			:��ȡָ�����ݵ�ָ���ȡָ�����ݵ�ָ��
			at(index)		:����index ��Ԫ��

			fill(element)	:���Ԫ��
			max_size		:����С
			size			:��С
			swap			:�������ȱ������


ʱ��	:	2020/01/08
*/
#include <iostream>
#include <algorithm>
#include <array>
#include <ctime>

using namespace std;

bool cmp(int x1, int x2)
{
	return x1 > x2;
}
void test();

int main()
{
	test();
	system("pause");
	return 0;
}
/*
����: 	- array����
		@param
����	:
ʾ��	:
*/
void test()
{
	srand((unsigned)time(NULL));
	array<int, 6> a1{ 1,2,3 };
	array<int, 6> a2;				//�������벻Ϊ��
	cout << "a1�Ƿ�Ϊ��" << a1.empty() << endl;
	cout << "a2�Ƿ�Ϊ��" << a2.empty() << endl;
	cout << "a1.size = " << a1.size() << endl;
	cout << "a2.size = " << a2.size() << endl;
	cout << "a1.max_size = " << a1.max_size() << endl;
	//����a�е�Ԫ�ش�ǰ����ö�ٳ���
	for (auto& s : a1)
	{
		cout << s << ends;
	}
	cout << endl;
	cout << "a1.front =" << a1.front() << endl;
	cout << "a1.back = " << a1.back() << endl;
	cout << "a1.data =" << a1.data() << endl;

	cout << "&a1.at[0] = " << &a1.at(0) << endl;
	cout << "a1.at[0] = " << a1.at(0) << endl;

	for (size_t i = 0; i < 6; i++)
	{
		a2[i] = rand() % 100;
		cout << a2[i] << ' ';
	}
	a1.fill(1);
	for (auto& s : a1)
	{
		cout << s << ends;
	}
	cout << endl << "����:" << endl;

	//�����ĳ��ȱ������
	a1.swap(a2);
	cout << "a1:" << endl;
	for (auto& s : a1)
	{
		cout << s << ends;
	}
	cout << endl << "a2:" << endl;
	for (auto& s : a2)
	{
		cout << s << ends;
	}

	//����
	sort(a1.begin(), a1.end());
	cout << endl << "a1�����" << endl;
	for (auto& s : a1)
	{
		cout << s << ends;
	}

	sort(a1.begin(), a1.end(),cmp);
	cout << endl << "a1�����" << endl;
	for (auto& s : a1)
	{
		cout << s << ends;
	}
}
