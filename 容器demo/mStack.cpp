/*
������	:	XTT
����	:	stack�����
			�Ƚ����,ֻ��һ������,
			ջ��ֻ�ж���Ԫ�زſ��Ա����ʹ��
			��˲������б�����Ϊ
			ջ�н�������:--��ջ(push)
			ջ�е�������:--��ջ(pop)

ʱ��	:	2020/01/07
*/

#include <iostream>
#include <stack>

using namespace std;

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
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while (!s.empty())
	{
		//���ջ��Ԫ��
		cout << "ջ��Ԫ��" << s.top() << endl;
		//����ջ��Ԫ��
		s.pop();
	}
	cout << "ջ�Ĵ�СΪ:" << s.size() << endl;
}
