/*
������	:	XTT
����	:	deque�����
			dequeû�������ĸ���

ʱ��	:	2020/01/07
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

void test01();						//deque�๹��demo
void test02();						//deque�����demo
void test03();						//deque��ɾ��demo
void test04();						//����

bool cmp(int x, int y);

void printDeque(deque<int>&);


int main()
{
	//test01();
	//test02();
	test03();
	//test04();
	system("pause");
	return 0;
}

/*
����: 	- deque�๹��demo
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test01()
{
	deque<int> d1;			//�޲�������
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int> d3(10, 100);
	printDeque(d3);

	deque<int> d4 = d3;
	printDeque(d4);
}

/*
����: 	- deque�����demo
		@param
����	:
ʾ��	:
*/
void test02()
{
	deque<int> d;
	//β��
	d.push_back(10);
	d.push_back(20);
	//ͷ��
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	//βɾ
	d.pop_back();
	//ͷɾ
	d.pop_front();

	printDeque(d);

	d.insert(d.begin(), 1000);
	printDeque(d);

	d.insert(d.begin(), 2, 1000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);
}

/*
����: 	- deque��ɾ��demo
		@param
����	:
ʾ��	:
*/
void test03()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(100);
	d.push_back(200);
	for (auto&s:d)
	{
		cout << s << ends;
	}
	cout << endl;
	cout << "d.size() = "  << d.size()  << endl;
	cout << "d.front() = " << d.front() << endl;
	cout << "d.back() = "  << d.back()  << endl;
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	//printDeque(d);

	d.erase(d.begin());
	printDeque(d);

	d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}

/*
����: 	- ����demo
		@param
����	:
ʾ��	:
*/
void test04()
{
	deque<int> d;
	srand((unsigned int)time(NULL));							//ʱ������					 	
	for (int i = 0; i < 10; i++)
	{
		d.push_back(rand() % 100);				//   ��ֵ��Χ(0-99��
	}
	cout << "ԭ����" << endl;
	printDeque(d);
	cout << "����" << endl;
	sort(d.begin(), d.end());
	printDeque(d);
	cout << "����" << endl;
	sort(d.begin(), d.end(), cmp);
	printDeque(d);
}

bool cmp(int x, int y)
{
	return x > y;
}

/*
����: 	- ��ӡdeque��
		@deque<int>& d
����	:
ʾ��	: printDeque(d1);
*/
void printDeque(deque<int>& d)
{
	if (d.empty())
	{
		cout << "��ӡ����Ϊ��" << endl;
		return;
	}
	else
	{
		for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
		{
			cout << *it << " ";
		}
		cout << " ��СΪ=" << d.size();
	}
	cout << endl;

}