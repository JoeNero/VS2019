/*
������	:	XTT
����	:	list����
			STL�е�������һ��˫��ѭ������
			�ж��Ƿ�Ϊ��--empty
			�ж�Ԫ�ظ���--size
			����ָ������--resize

			β�� --- push_back
			βɾ --- pop_back
			ͷ�� --- push_front
			ͷɾ --- pop_front
			���� --- insert
			ɾ�� --- erase
			�Ƴ� --- remove
			��� --- clear

			front(); ���ص�һ��Ԫ�ء�
			back();  �������һ��Ԫ�ء�

			reverse();	��ת����
			sort();		��������



ʱ��	:	2020/01/08
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <ctime>

//	mode 1   ����������
//  mode 0	 ���������
//			 �����Զ����������ͣ�����Ҫָ��������򣬷����������֪����ν�������
//			 �߼�����ֻ��������������ٽ���һ���߼������ƶ�����������
#define mode 1

using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
public:
	string m_Name;		//����
	int m_Age;			//����
	int m_Height;		//���
};
bool cmp(int, int);
bool ComparePerson(Person&, Person&);

void test01();
void test02();
void test03();

void printList(const list<int>&);			//��ӡ
void printList(const list<Person>&);			//��ӡ

int main()
{

//	test01();
//	test02();
	test03();
	system("pause");
	return 0;
}

/*
����: 	- list����
		@param
����	:
ʾ��	:
*/
void test01()
{
	list<int> L1;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		L1.push_back(rand() % 100);
	}
	cout << "L1 = " << endl;
	printList(L1);

	list<int> L2(L1.begin(), L1.end());
	cout << "L2 = " << endl;
	printList(L2);

	list<int> L3(L2);
	cout << "L3 = " << endl;
	printList(L3);

	cout << "L4 = " << endl;
	list<int> L4(6, 11);
	printList(L4);

	L1.swap(L4);
	cout << "����" << endl;
	cout << "L1 = " << endl;
	printList(L1);
	cout << "L4 = " << endl;
	printList(L4);
	L4.reverse();
	cout << "��ת";
	cout << "L4 = " << endl;
	printList(L4);
	cout << "����";
	cout << "L4 = " << endl;
	L4.sort();
	printList(L4);
	cout << "����";
	L4.sort(cmp);
	cout << "L4 = " << endl;
	printList(L4);
}

/*
����: 	- test02()
		@param
����	:
ʾ��	:
*/
void test02()
{
	list<Person> L;
	Person p1("P1", 35, 175);
	Person p2("P2", 45, 180);
	Person p3("P3", 40, 170);
	Person p4("P4", 25, 190);
	Person p5("P5", 35, 160);
	Person p6("P6", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	printList(L);
	cout << "---------------------------------" << endl;

	if (mode)
	{
		cout << "��������" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}

	L.sort(ComparePerson);
	printList(L);

}

void test03()
{
	list<int> L1;
	list<int> L2;
	srand((unsigned int)time(NULL));
	int* num = new int[5];
	//��ʼ��L1
	for (int i = 0; i < 5; i++)
	{
		num[i] = rand() % 100;
		L1.push_back(i);
		//L1.push_back(num[i]);
	}
	
	cout << "��ʼ�� L1 =" << endl;
	printList(L1);

	//��ʼ��L2
	for (int i = 0; i < 5; i++)
	{
		L2.push_front(num[i]);
	}

	cout << "��ʼ�� L2 =" << endl;
	printList(L2);

	cout << "βɾ L1" << endl;
	L1.pop_back();
	printList(L1);
	cout << "ͷɾ" << endl;
	L2.pop_front();
	printList(L2);

	list<int>::iterator it = L1.begin();
	//ע�� list �������ʲ����� ���� it + 10 ��Υ����
	// list ��˫��ѭ������ ��ס������
	L1.insert(++it, 2);
	cout << "begin+1 λ�ò���2" << endl;
	printList(L1);
	//ʵ����it�Ѿ����ʵ�begin + 2 ��λ����
	L1.erase(it);
	cout << "����begin + 2λ��" << endl;
	printList(L1);
	//�Ƴ�Ԫ��Ϊ  1  ��ֵ
	L1.remove(2);
	cout << "�Ƴ�Ԫ��Ϊ2��ֵ:" << endl;
	printList(L1);
	L1.clear();
	printList(L1);

	cout << "L2��ͷԪ�� " << L2.front() << endl;
	cout << "L2��βԪ�� " << L2.back()	<< endl;
	
	L2.reverse();
	cout << "L2 ��ת����" << endl;
	printList(L2);

	L2.sort();
	cout << "L2 ����" << endl;
	printList(L2);
	L2.sort(cmp);
	cout << "L2 ����" << endl;
	printList(L2);
}

bool cmp(int a, int b)
{
	return a > b;
}

bool ComparePerson(Person& p1, Person& p2)
{
	//��������
#if mode
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
#else
	//�������
	if (p1.m_Height == p2.m_Height) {
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Height < p2.m_Height;
	}
#endif
}

/*
����: 	- ��ӡlist����
		@const list<int>& L
		@param
		@param
����	:
ʾ��	:	printList(L4);
*/
void printList(const list<int>& L)
{
	if (L.empty())
	{
		cout << "��ӡ����Ϊ��" << endl;
		return;
	}
	else
	{
		for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
		{
			cout << *it << " ";
		}
		cout << "��С" << L.size() << endl;
	}

	cout << endl;
}

void printList(const list<Person>& L)			//��ӡ
{
	if (L.empty())
	{
		cout << "��ӡ����Ϊ��" << endl;
		return;
	}
	else
	{
		for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
		{
			cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
				<< " ��ߣ� " << it->m_Height << endl;
		}
		cout << "��С" << L.size() << endl;
	}
}