/*
������	:	XTT
����	:	queue����
			�Ƚ��ȳ�,��������
			�������������һ������Ԫ�أ�����һ���Ƴ�Ԫ��
			������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶��в������б�����Ϊ
			�����н����ݳ�Ϊ --- ��� push
			�����г����ݳ�Ϊ --- ���� pop

ʱ��	:	2020/01/08
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	~Person() {};

	string m_Name;
	int m_Age;
};


void test01();

int main()
{

	test01();
	system("pause");
	return 0;
}

/*
����: 	- stack��
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test01()
{
	//����
	queue<Person> q;

	//׼������
	Person p1("��ɮ", 30);
	Person p2("�����", 1000);
	Person p3("��˽�", 900);
	Person p4("ɳɮ", 800);

	//����������Ԫ�� ���в���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//���в��ṩ������,����֧���������
	while (!q.empty())
	{
		//�����ͷԪ��
		cout << "��ͷԪ��--����:" << q.front().m_Name
			<< "����:" << q.front().m_Age << endl;
		//�����βԪ��
		cout << "��βԪ��--����:" << q.back().m_Name
			<< "����:" << q.back().m_Age << endl;
		cout << endl;
		//������ͷ
		q.pop();
	}
	cout << "���д�С:" << q.size() << endl;
}
